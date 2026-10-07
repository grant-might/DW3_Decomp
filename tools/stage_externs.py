#!/usr/bin/env python3
"""
Drops the declarations of a stage's own data and functions that nothing needs.

data_to_c.py writes an extern for every datum of a stage before its code, but
a datum or a function that is defined before every use of it needs no
declaration. This keeps an extern or a prototype only where something (a
function, or a table before the datum) uses the name before its definition,
and drops copies of the same declaration.
It changes no bytes, and can be run again at any time:

    tools/stage_externs.py [src/stages/wstag200.c ...]

With no files it goes through every src/stages/*.c.
"""
import argparse
import glob
import re
import sys

EXTERN = re.compile(r"^extern\s+[^;=(]*?\b(\w+)\s*((?:\[[^\]]*\])*)\s*;\s*$")
PROTOTYPE = re.compile(r"^(?:extern\s+)?(?!return\b)\w+[\w\s]*?[\s*]\**(\w+)\([^()]*\);\s*$")
TOKEN = re.compile(r"\b\w+\b")


def definition_line(lines, name):
    """The line where the file defines name (not an extern), or None"""
    pattern = re.compile(
        r"^(?!extern\b)(?:static\s+)?(?:const\s+)?\w+(?:\s+\w+)*[\s*]*\b"
        + re.escape(name)
        + r"\s*(?:\[[^\]]*\])*\s*(?:=|;)"
    )
    function = re.compile(
        r"^(?!extern\b)(?:static\s+)?\w+(?:\s+\w+)*[\s*]*\b" + re.escape(name) + r"\([^;]*$"
    )
    for i, line in enumerate(lines):
        if pattern.match(line) or function.match(line):
            return i
    return None


def prune(text):
    lines = text.split("\n")
    externs = {}
    for i, line in enumerate(lines):
        m = EXTERN.match(line) or PROTOTYPE.match(line)
        if m:
            externs.setdefault(m.group(1), []).append(i)
    if not externs:
        return text

    # Where each name is first used, other than in an extern of it or its definition
    first_use = {}
    definitions = {name: definition_line(lines, name) for name in externs}
    extern_lines = {i for idx in externs.values() for i in idx}
    for i, line in enumerate(lines):
        if i in extern_lines:
            continue
        for tok in TOKEN.findall(line):
            if tok in externs and tok not in first_use and definitions[tok] != i:
                first_use[tok] = i

    drop = set()
    for name, idx in externs.items():
        definition = definitions[name]
        if definition is None:
            # Defined elsewhere: keep the first declaration
            drop.update(idx[1:])
            continue
        use = first_use.get(name)
        if use is None or use > definition:
            drop.update(idx)
        else:
            drop.update(idx[1:])

    out = []
    for i, line in enumerate(lines):
        if i in drop:
            continue
        # A blank line left after a block of dropped externs goes with it
        if line == "" and out and out[-1] == "" and i - 1 in drop:
            continue
        out.append(line)
    return "\n".join(out)


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[1])
    parser.add_argument("files", nargs="*")
    args = parser.parse_args()
    files = args.files or sorted(glob.glob("src/stages/*.c"))
    changed = 0
    for path in files:
        with open(path) as f:
            text = f.read()
        new = prune(text)
        if new != text:
            with open(path, "w") as f:
                f.write(new)
            changed += 1
    print(f"{changed} files changed", file=sys.stderr)


if __name__ == "__main__":
    main()
