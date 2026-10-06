#!/usr/bin/env python3
"""Checks what a link took in: the binary's objects, and no blob but those allowed.

    inputcheck.py MAP OBJ... [--blobs OBJ...]

The linker scripts come from splat's configs and name the objects by path,
so a link takes whatever is there: an object whose source is gone but that
is still in build/, or one that the config names and the Makefile doesn't
build. MAP is the link's map: each object it loaded must be one of the OBJ
that the Makefile built for the binary.
A blob, an object made from a binary file (a .bin, or assembly that
.incbin's one), has no relocations, so an address in it wouldn't move with
the code: only those in --blobs may be linked.
"""
import argparse
import pathlib
import re
import sys


def loaded(map_path):
    """The files the link loaded, in its map's LOAD lines."""
    return [m.group(1) for m in re.finditer(r"^LOAD (\S+)$", pathlib.Path(map_path).read_text(), re.M)]


def source(obj):
    """The file an object of build/<version>/ is built from."""
    return pathlib.Path(*pathlib.Path(obj).parts[2:]).with_suffix("")


def is_blob(obj):
    src = source(obj)
    return src.suffix == ".bin" or (src.suffix == ".s" and src.exists()
                                    and re.search(r"^\s*\.incbin\b", src.read_text(errors="replace"), re.M))


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("map")
    ap.add_argument("objs", nargs="+")
    ap.add_argument("--blobs", nargs="*", default=[], help="the blobs the binary may link")
    args = ap.parse_args()
    objs = set(args.objs)
    inputs = loaded(args.map)
    problems = ["%s: not one of the binary's objects" % f for f in inputs if f not in objs]
    problems += ["%s: a blob, from %s" % (f, source(f)) for f in inputs
                 if f in objs and f not in args.blobs and is_blob(f)]
    for problem in problems:
        print("%s: %s" % (args.map, problem), file=sys.stderr)
    sys.exit(1 if problems else 0)


if __name__ == "__main__":
    main()
