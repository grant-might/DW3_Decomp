#!/usr/bin/env python3
"""
Includes the stages' shared code from src/stages/common/ in place of copies of it.

A stage function written exactly as a src/stages/common/*.inc.c writes its
code (the file without its leading comment) becomes an #include of that
file, where the copy was. It changes no bytes, and can be run again at any
time:

    tools/stage_common.py [src/stages/wstag200.c ...]

With no files it goes through every src/stages/*.c.
"""
import argparse
import glob
import os
import re
import sys

COMMON = "src/stages/common"


def shared_code():
    """{include line: code} of the files in src/stages/common/"""
    out = {}
    for path in sorted(glob.glob(f"{COMMON}/*.inc.c")):
        text = open(path).read()
        code = re.sub(r"\A/\*.*?\*/\n", "", text, flags=re.S).strip("\n")
        out[f'#include "common/{os.path.basename(path)}"'] = code
    return out


def include_shared(text, shared):
    for include, code in shared.items():
        start = text.find("\n" + code + "\n")
        if start < 0 or include in text:
            continue
        text = text[: start + 1] + include + text[start + 1 + len(code) :]
    return text


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[1])
    parser.add_argument("files", nargs="*")
    args = parser.parse_args()
    files = args.files or sorted(glob.glob("src/stages/*.c"))
    shared = shared_code()
    changed = 0
    for path in files:
        text = open(path).read()
        new = include_shared(text, shared)
        if new != text:
            open(path, "w").write(new)
            changed += 1
    print(f"{changed} files changed", file=sys.stderr)


if __name__ == "__main__":
    main()
