# Digimon World 3 / Digimon World 2003 matching decompilation

Preservation of DW3 decomp.

**Complete: 100.00% of the code and data, in both releases.**

C source that compiles back into byte-identical copies of the game's executable, its 21 overlays
and every one of its stages: the USA release, *Digimon World 3* (`SLUS_014.36`), and the European
release, *Digimon World 2003* (`SLES_039.36`).

`make compare` prints one `OK` per binary and every one of them says `OK`: 261 binaries for the
USA version, 316 for the European one, covering the executable, every overlay and every stage.
Nothing is left in assembly, and nothing matches by accident: the project counts zero fake
matches.

This repository holds no game data. You need your own copy of the game to build it.

| | |
|---|---|
| Platform | PlayStation |
| Versions | USA (`SLUS_014.36`), Europe (`SLES_039.36`) |
| Compiler | GCC 2.8.1 for the PSX |
| Progress | 100.00% code, 100.00% data, both versions |

![fake matches | hacks](https://img.shields.io/badge/fake%20matches%20%7C%20hacks-0%20%7C%20191-yellow)
![compiler](https://img.shields.io/badge/compiler-GCC%202.8.1-orange)
![platform](https://img.shields.io/badge/platform-PlayStation-003791)
![versions](https://img.shields.io/badge/versions-USA%20%7C%20Europe-blue)

## Progress

Measured with `make report` on both versions:

| Part | Version | Functions in C | Code | Data |
|---|---|---|---|---|
| Executable, game code | Europe | 346 / 346 | 100.00 % | 100.00 % |
| | USA | 346 / 346 | 100.00 % | 100.00 % |
| The 21 overlays | Europe | 1,670 / 1,670 | 100.00 % | 100.00 % |
| | USA | 1,665 / 1,665 | 100.00 % | 100.00 % |
| The stages (293 and 238) | Europe | 1,590 / 1,590 | 100.00 % | 100.00 % |
| | USA | 1,369 / 1,369 | 100.00 % | 100.00 % |
| **Total** | **Europe** | **3,606 / 3,606** | **100.00 %** | **100.00 %** |
| | **USA** | **3,380 / 3,380** | **100.00 %** | **100.00 %** |

- The game's code and data are all C in both versions: the executable, the 21 overlays and all
  the stages.
- The PsyQ libraries are Sony's code, not the game's: the build takes them from the original as
  splat's disassembly, and the progress leaves them out.
- [docs/status.md](docs/status.md) has each part in detail, how the progress is measured, and the
  fake matches and hacks the numbers above count.

## Requirements

On Debian or Ubuntu (the build is developed on Ubuntu 24.04 with Python 3.12):

```
binutils-mipsel-linux-gnu gcc-mipsel-linux-gnu git make python3 python3-venv unzip wget
```

Or build in Docker instead and skip all of it: see [Building with Docker](#building-with-docker).

Clone with the submodules (maspsx, m2c, decomp-permuter and the PsyQ headers), make a Python
environment, which has to be active whenever you run `make` or anything in `tools/`, and download
the prebuilt tools (GCC 2.8.1 for the PSX, objdiff-cli and mkpsxiso) into `bin/`, checked against
`tools/deps.sha256`:

```
git clone --recursive https://github.com/grant-might/DW3-DECOMP.git
cd DW3-DECOMP             # in an existing clone: git submodule update --init --recursive
python3 -m venv .venv
. .venv/bin/activate
pip3 install -r requirements.txt
tools/dl_deps.sh
```

## Getting the game files

Each disc goes in its own `disks/<version>/`. Extract it with `tools/extract_disc.py`, which also
reaches the `AAA/` directories, and check the executable:

```
python3 tools/extract_disc.py "/path/to/Digimon World 3 (USA).bin" disks/us
sha1sum disks/us/SLUS_014.36   # 444653259f78ddb483fd22af72cce9276f42f214

python3 tools/extract_disc.py "/path/to/Digimon World 2003 (Europe).bin" disks/eu
sha1sum disks/eu/SLES_039.36   # d1b7e4d646e3a9c2b88fdb25d20b5f7116bbb06d
```

Only `disks/<version>/<executable>` and `disks/<version>/AAA/PRO/` are needed, and only for the
versions you build. `config/<version>/` holds the SHA-1 of every original binary, which
`make compare` checks the build against: `<executable>.sha1`, `overlays.sha1` and `stages.sha1`.

## Build

The same steps build each version, with `VERSION` set to `eu` or `us` (`eu` when it is left out):

```
# Split the executable, the overlays and the stages with splat
# (asm/<version>/, build/<version>/generated/)
make VERSION=eu generate

# Build build/<version>/<executable> and build/<version>/AAA/PRO/*.PRO
make VERSION=eu -j$(nproc)

# Check the executable, every overlay and every stage against the originals
make VERSION=eu compare
```

`make VERSION=<version> regenerate` deletes `asm/<version>/`, `build/<version>/`,
`expected/<version>/` and `assets/<version>/`, and splits the binaries again. Run it after
changing a `config/<version>/*.yaml`, a symbol file or `stages.txt`, so that no stale files stay
behind in `asm/<version>/`.

## Building with Docker

`tools/docker.sh` builds the build environment from the `Dockerfile` (Ubuntu 24.04, the MIPS
binutils, Python and the prebuilt tools, no game data) and runs a command in it, as your own user;
without a command it opens a shell. No `bin/` or `.venv` is needed on the host. With the
submodules and the disc files in `disks/` as above:

```
tools/docker.sh make generate
tools/docker.sh sh -c 'make -j$(nproc)'
tools/docker.sh make compare
VERSION=us tools/docker.sh make generate
```

[docs/toolchain.md](docs/toolchain.md#docker) has the details.

## Checks

```
make VERSION=eu report        # build/<version>/report.json, the progress
make VERSION=eu shiftcheck    # every address in the code and data is a symbol
make VERSION=eu padcheck      # linked higher, words change only at relocations
make VERSION=eu lint          # a modern GCC checks the declarations
python3 tools/hacks.py --check README.md docs/status.md   # the hacks badge and table
python3 tools/check_names.py  # every version uses the USA version's names
```

[docs/shifting.md](docs/shifting.md) explains `shiftcheck` and `padcheck`,
[docs/toolchain.md](docs/toolchain.md#declaration-check) `lint`, and
[docs/status.md](docs/status.md#progress) the report.

## Layout

| Path | What it is |
|---|---|
| `src/` | the C: the executable's game code, the overlays and the stages, one file per unit |
| `include/` | the headers, the PsyQ ones among them |
| `config/<version>/` | splat's configuration, the symbol files and the SHA-1 of every original binary |
| `asm/<version>/` | splat's split of the originals, generated |
| `build/<version>/` | the built binaries, generated |
| `expected/<version>/` | the target objects objdiff compares against, generated |
| `disks/<version>/` | your own copy of the game's files, not committed |
| `tools/` | the scripts: the disc extractor, the matchers, the checks |
| `mk/` | the make fragments |
| `external/` | the submodules: maspsx, m2c, decomp-permuter, psyq_headers |
| `docs/` | the documentation listed below |

## Documentation

- [docs/status.md](docs/status.md): the status of each part, how the progress is measured, and
  the fake matches and hacks.
- [docs/binaries.md](docs/binaries.md): the game's executable, overlays and stages, their memory
  maps, and how the two versions are organised.
- [docs/toolchain.md](docs/toolchain.md): the compiler and its flags, the declaration check, the
  Docker image, the layout and the tools.
- [docs/shifting.md](docs/shifting.md): the shiftable build and the checks that keep it
  (`shiftcheck`, `padcheck`, `inputcheck`).
- [TODO.md](TODO.md): what is left to do.

## How it was matched

Every function started as an `INCLUDE_ASM` line in its file under `src/`. To turn one into
matching C: a first draft from m2c, then `tools/try_match.py` and objdiff to bring it down to a
difference in the generated assembly, and the permuter for a near miss that no readable form
fixes. What is left after that are the workarounds counted in
[docs/status.md](docs/status.md#fake-matches-and-hacks): forms the original compiler produced
that natural C would not, each one marked with a comment where it happens.

A function either matches as C or keeps its `INCLUDE_ASM`, so `src/` holds no `NON_MATCHING`
code, no `#if 0` blocks and no inline assembly standing in for C. `tools/hacks.py` fails on all
three.

The PsyQ functions are named after the
[PsyQ 4.7 signatures](https://github.com/lab313ru/psx_psyq_signatures).
