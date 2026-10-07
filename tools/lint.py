#!/usr/bin/env python3
"""Checks the game C's declarations with a modern compiler.

    lint.py [-v VERSION] [--update] [--strict] [--base REV] [FILE...]

GCC 2.8.1 accepts a call to an undeclared function and a pointer of the
wrong type with at most a warning that the build doesn't stop on. A modern
GCC (the Makefile's LINT_CC, mipsel-linux-gnu-gcc) parses every C file the
version builds (-fsyntax-only, nothing is written, so the match never
depends on it) with the build's own preprocessor flags, which `make lint`
gives in LINT_CPPFLAGS and the files in LINT_SRC, and reports:

  implicit-function-declaration   a call to a function with no declaration
  incompatible-pointer-types      a pointer of another type than the one
                                  declared (assigned, passed or returned)
  error                           what a modern GCC refuses outright

config/<version>/lint.txt lists what is known and left to fix, one line per
diagnostic: the file, the function and the message, without the line number,
which an edit elsewhere in the file would make stale. The script exits with
1 on anything it doesn't list, and warns about what it lists that is fixed
(fails, with --strict). --update rewrites it. The list may only get shorter:
--base fails on an entry that the list of the git revision REV doesn't have,
as tools/shiftcheck.py does. It compares the entries without their file, so
that a function moved to another file brings no new entry.
"""
import argparse
import collections
import concurrent.futures
import os
import pathlib
import re
import shlex
import subprocess
import sys

# GCC 2.8.1's dialect, the game's -fno-builtin (its memcpy and the like are
# the SDK's, not the compiler's), and the two warnings the check is about
LINT_FLAGS = ["-fsyntax-only", "-std=gnu89", "-fno-builtin", "-fdiagnostics-plain-output",
              "-Wimplicit-function-declaration", "-Wincompatible-pointer-types"]
CHECKED = {"implicit-function-declaration", "incompatible-pointer-types"}

DIAGNOSTIC = re.compile(r"^(?P<file>[^:\s]+):\d+:\d+: (?P<kind>warning|error): (?P<msg>.*?)(?: \[-W(?P<flag>[\w-]+)\])?$")
IN_FUNCTION = re.compile(r"^(?P<file>[^:\s]+): In function '(?P<func>\w+)':$")
FILE_SCOPE = re.compile(r"^(?P<file>[^:\s]+): At top level:$")


def lint_file(cc, cppflags, path):
    """The checked diagnostics of one file, as `file: function: [flag] message`
    keys. A header's (or an included .inc.c's) are reported with its path."""
    # C: plain quotes, which keeps the list the same in every locale
    env = dict(os.environ, LC_ALL="C")
    out = subprocess.run([cc] + cppflags + LINT_FLAGS + [path], capture_output=True, text=True, env=env)
    found = []
    func = {}
    for line in out.stderr.splitlines():
        m = IN_FUNCTION.match(line)
        if m:
            func[m["file"]] = m["func"]
            continue
        m = FILE_SCOPE.match(line)
        if m:
            func[m["file"]] = None
            continue
        m = DIAGNOSTIC.match(line)
        if not m:
            continue
        flag = "error" if m["kind"] == "error" else m["flag"]
        if flag not in CHECKED and flag != "error":
            continue
        where = m["file"] + ": " + (func.get(m["file"]) or "(file scope)")
        found.append("%s: [%s] %s" % (where, flag, m["msg"]))
    if out.returncode and not any("[error]" in f for f in found):
        # a failure with no diagnostic of its own (the compiler is missing...)
        sys.exit("%s failed on %s:\n%s" % (cc, path, out.stderr.strip()))
    return path, found


def lint(cc, cppflags, files):
    """Every file's diagnostics, counted: a file's own add up, and those of a
    header or an .inc.c that several files include count once, as many times
    as the file that has the most of them."""
    total = collections.Counter()
    shared = collections.Counter()
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count() or 1) as pool:
        for path, found in pool.map(lambda f: lint_file(cc, cppflags, f), files):
            mine = collections.Counter(found)
            for key, n in mine.items():
                if key.startswith(path + ":"):
                    total[key] += n
                else:
                    shared[key] = max(shared[key], n)
    return total + shared


def entries(text):
    return collections.Counter(l for l in text.splitlines() if l and not l.startswith("#"))


def without_file(counter):
    """The entries as "function: [warning] message", whatever file has them."""
    return collections.Counter(k.split(": ", 1)[1] for k in counter.elements())


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("-v", "--version", default=os.environ.get("VERSION", "eu"))
    ap.add_argument("--update", action="store_true", help="write what is found as the known list")
    ap.add_argument("--strict", action="store_true", help="also fail on what the known list has that is fixed")
    ap.add_argument("--base", metavar="REV", help="also fail on what the known list has that REV's doesn't")
    ap.add_argument("files", nargs="*", help="the files to check (default: LINT_SRC)")
    args = ap.parse_args()
    cc = os.environ.get("LINT_CC", "mipsel-linux-gnu-gcc")
    cppflags = shlex.split(os.environ.get("LINT_CPPFLAGS", ""))
    every = sorted(os.environ.get("LINT_SRC", "").split())
    files = args.files or every
    if not files or not cppflags:
        sys.exit("no files or flags: run it as make VERSION=%s lint" % args.version)
    known_path = pathlib.Path("config") / args.version / "lint.txt"

    found = lint(cc, cppflags, files)
    if args.update:
        lines = ["# Declaration problems a modern GCC finds in the C (tools/lint.py --update):",
                 "# the file, the function, the warning and its message, one per line"]
        lines += sorted(found.elements())
        known_path.write_text("\n".join(lines) + "\n")
        print("wrote %s: %d" % (known_path, sum(found.values())))
        return

    known = entries(known_path.read_text()) if known_path.exists() else collections.Counter()
    added = collections.Counter()
    if args.base:
        base = subprocess.run(["git", "show", "%s:%s" % (args.base, known_path.as_posix())],
                              capture_output=True, text=True)
        # a revision from before the list has nothing to compare
        if base.returncode == 0:
            added = without_file(known) - without_file(entries(base.stdout))
    # only a check of every file knows what is fixed
    new = found - known
    gone = known - found if not args.files else collections.Counter()
    per_flag = collections.Counter(re.search(r"\[([\w-]+)\]", k)[1] for k in found.elements())
    print("%s: %s" % (args.version, ", ".join("%s %d" % kv for kv in sorted(per_flag.items())) or "nothing found"))
    for k in sorted(new.elements()):
        print("new: %s" % k)
    for k in sorted(gone.elements()):
        print("fixed: %s" % k)
    for k in sorted(added.elements()):
        print("added since %s: %s" % (args.base, k))
    if added:
        print("error: %d added to %s since %s, which may only get shorter"
              % (sum(added.values()), known_path, args.base))
    if gone:
        print("%s: %d fixed, which tools/lint.py -v %s --update drops from %s"
              % ("error" if args.strict else "warning", sum(gone.values()), args.version, known_path))
    sys.exit(1 if new or added or (gone and args.strict) else 0)


if __name__ == "__main__":
    main()
