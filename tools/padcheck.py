#!/usr/bin/env python3
"""Checks a padding build: only the words with a relocation may change.

    padcheck.py [-v VERSION] PAD

`make PAD=<pad> links` links every binary again from the same objects, with
the memory map (EXE_VRAM, OVERLAY_VRAM, STAGE_VRAM) PAD bytes higher, into
build/<version>/pad<pad>/: as if the executable had grown by PAD bytes at its
start, everything after it moves by PAD. Each binary must keep its sections'
sizes, and a word may only differ from the build's (build/<version>/*.elf)
where the linker filled it in, at a relocation that --emit-relocs kept.
Anything else that changed is an address the build computes some other way
(a pad or an alignment that depends on where the code is), which a real
change of size would break in the same way. `make padcheck` runs it for
every PAD in the Makefile's PADS.
"""
import argparse
import bisect
import pathlib
import sys

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection


def loaded_sections(elf):
    """The sections with bytes in the binary, by name."""
    return {s.name: s for s in elf.iter_sections()
            if s["sh_flags"] & 2 and s["sh_type"] == "SHT_PROGBITS" and s["sh_size"]}


def relocated_words(elf):
    """The addresses of the words that have a relocation."""
    return {r["r_offset"] & ~3 for s in elf.iter_sections() if isinstance(s, RelocationSection)
            for r in s.iter_relocations()}


def labels(elf):
    """The binary's labels, sorted by address, for locations."""
    syms = sorted((s["st_value"], s.name) for s in elf.get_section_by_name(".symtab").iter_symbols()
                  if s.name and s["st_shndx"] != "SHN_ABS" and s["st_info"]["type"] != "STT_SECTION"
                  and not s.name.endswith(".NON_MATCHING") and s.name != "gcc2_compiled.")
    return [a for a, _ in syms], [n for _, n in syms]


def where(addrs, names, addr):
    i = bisect.bisect_right(addrs, addr) - 1
    return "%s+0x%X" % (names[i], addr - addrs[i]) if i >= 0 else "0x%08X" % addr


def check(base_path, padded_path, pad):
    """The problems of one binary's padding build."""
    with open(base_path, "rb") as fb, open(padded_path, "rb") as fp:
        base, padded = ELFFile(fb), ELFFile(fp)
        base_secs, padded_secs = loaded_sections(base), loaded_sections(padded)
        if base_secs.keys() != padded_secs.keys():
            return ["sections %s, padded %s" % (sorted(base_secs), sorted(padded_secs))], 0
        relocated = relocated_words(base)
        addrs, names = labels(base)
        problems, changed = [], 0
        for name, s in base_secs.items():
            p = padded_secs[name]
            # the executable's header is outside RAM and stays where it is
            moved = p["sh_addr"] - s["sh_addr"]
            if moved not in (0, pad) or (moved == 0 and s["sh_addr"] >= 0x80000000):
                problems.append("%s moved by 0x%X" % (name, moved))
                continue
            if s["sh_size"] != p["sh_size"]:
                problems.append("%s is 0x%X bytes, padded 0x%X" % (name, s["sh_size"], p["sh_size"]))
                continue
            a, b = s.data(), p.data()
            for off in range(0, len(a), 4):
                if a[off:off + 4] == b[off:off + 4]:
                    continue
                changed += 1
                addr = s["sh_addr"] + off
                if addr not in relocated:
                    problems.append("0x%08X %s: %s -> %s, without a relocation"
                                    % (addr, where(addrs, names, addr), a[off:off + 4][::-1].hex(), b[off:off + 4][::-1].hex()))
        return problems, changed


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("-v", "--version", default="eu")
    ap.add_argument("pad", help="the PAD of the padding build, such as 0x4")
    args = ap.parse_args()
    pad = int(args.pad, 0)
    build = pathlib.Path("build") / args.version
    padded_dir = build / ("pad" + args.pad)
    elfs = sorted(build.glob("*.elf"))
    if not elfs:
        sys.exit("no ELFs in %s: run make VERSION=%s" % (build, args.version))
    failed = changed = 0
    for elf in elfs:
        padded = padded_dir / elf.name
        if not padded.exists():
            sys.exit("%s is missing: run make VERSION=%s PAD=%s links" % (padded, args.version, args.pad))
        problems, n = check(elf, padded, pad)
        changed += n
        for problem in problems:
            print("%s: %s" % (elf.stem, problem))
        failed += bool(problems)
    print("%s +%s: %d binaries, %d words moved, %s"
          % (args.version, args.pad, len(elfs), changed, "%d binaries with problems" % failed if failed else "all at relocations"))
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
