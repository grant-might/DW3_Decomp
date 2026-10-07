# Toolchain, layout and tools

## Toolchain

| | |
|---|---|
| Game code | GCC 2.8.1 (`-O2 -G0`; `-G8` for the executable's modules cut from the original's `inn`, `system`, `memcard`, `game3`, `game3_2`, `graphics`, `sound` and `overlay`, `G8_SRC` in the Makefile) + ASPSX 2.86, emulated with [maspsx](https://github.com/mkst/maspsx) |
| Splitting | [splat](https://github.com/ethteck/splat) 0.50.0 |
| Diffing | [objdiff](https://github.com/encounter/objdiff) 3.8.1 |

- The compiler was identified by running m2c over every game function and
  building the output with several GCC versions: GCC 2.8.x `-O2` matches 82 of
  342 functions untouched, 2.7.2 matches 49 and 2.91.66 matches 46. GCC 2.8.0
  and 2.8.1 give the same results, and so do ASPSX 2.56 to 2.86.
- The game's divisions carry no divide-by-zero check, so maspsx runs without
  `--expand-div`.
- The modules cut from the original's `system` and `graphics` read their
  small variables through `$gp` (`ROOT_TASK` and `BOOT_IMAGE_RECT` in
  `system/main.c`, `CD_MODE` in `file/cd_reader.c`; `FLIP_PENDING` in
  `gfx/display.c`, the drawers and `TEXT_TOOLS` in theirs), so they are
  built with `-G8` in both GCC and maspsx (`SDATA_LIMIT` in the Makefile).
  Those variables are declared `static` in the C; maspsx emits them as
  common symbols that resolve to their definitions.
- `game3_2`'s and `overlay`'s modules read nothing through `$gp`, but match
  only at `-G8` too: GCC then leaves the address of a small extern
  (`GET_DIGIMON` in `game/partner.c`) to the assembler's macro, which loads
  it again for every read, and that changes the scheduling and the
  registers. `inn`'s, `memcard`'s and `game3`'s need it for the same reason
  in the European version only, for `LANGUAGE`. `sound/sound.c` is built
  with `-G8` as well, but its code is the same at `-G0`. Every module cut
  from a `-G8` object keeps it; the rest of the game uses `-G0`.
- The C includes the PsyQ 4.7 headers from
  [psyq_headers](https://github.com/jype0/psyq_headers). `libgte.h` names
  some parameters `$2`, hence `-fdollars-in-identifiers`. The game uses
  signed `char` (`-fsigned-char`).
- Most global function pointers live in tables (the heap, `HEAP`, holds
  `free`, `alloc` and `zero`, for example) and must be called through a struct.
  GCC 2.8 assumes a struct field and a scalar global never alias, so with a
  scalar `extern` it moves stores to struct fields past the load of the
  function pointer. A store through a pointer to a field
  isn't a struct access to it: `WFIGHTMN_setStat` keeps the load of
  `FIGHTSTG_battleTableFunc` after the stores that way.

To use a different binutils or objdiff, create `local.mk`:
```
TOOLCHAIN := /path/to/mipsel-linux-gnu-
OBJDIFF := /path/to/objdiff-cli
```

## Declaration check

GCC 2.8.1 builds a call to an undeclared function, or a pointer of the
wrong type, with at most a warning. `make lint` (`tools/lint.py`) has a
modern GCC (`LINT_CC`, `mipsel-linux-gnu-gcc` by default) parse every C file
the version builds, with the build's preprocessor flags, and fails on any
such diagnostic that `config/<version>/lint.txt` doesn't list. It only
parses (`-fsyntax-only`), so it never affects the match. As with
`shiftcheck.txt`, the CI runs it with `--strict --base HEAD^`, so the list
may only get shorter:
```
make VERSION=eu lint
# Write what it finds as the list, once it is shorter
make VERSION=eu lint LINT_ARGS=--update
```

## Docker

The `Dockerfile` has the CI's build environment: Ubuntu 24.04 with the MIPS
binutils, Python with `requirements.txt`, and the compiler and tools that
`tools/dl_deps.sh` downloads. It holds no game data. `tools/docker.sh` builds
the image and runs a command in it, with the repository (`disks/` and
`external/` included) mounted at `/dw3`, as your own user. `VERSION` is passed
on when it is set; without a command it opens a shell. No `bin/` or `.venv`
is needed on the host: `BIN_DIR` points at the image's tools.
The prebuilt tools are x86 Linux binaries, so the image is `linux/amd64`.

## Layout

| Path | Contents |
|---|---|
| `src/main/<module>/` | the executable's game code, one folder per module, cut from the original objects in their link order (see [binaries.md](binaries.md#the-games-binaries)) |
| `src/main/data/` | the executable's data as C, until it moves next to the code that uses it |
| `src/<overlay>/` | each overlay's C; `<overlay>_2.c` is the second half of an object split in two. `src/fieldstg/` has a file per module instead, more than the original's five objects, split only where each jump table keeps its place, and its data in `data/fieldstg.c` |
| `src/stages/` | one C file per stage, `wstag###.c` |
| `include/game.h`, `include/dw3/` | types and declarations of the game code, one header per module of `src/main/` (`task.h`, `heap.h`, `gfx.h`, `file.h`, `pad.h`, `random.h`, `sound.h`, `overlay.h`, `text.h`, `game_state.h`, `memcard.h`, `menu.h`) |
| `include/<overlay>.h`, `include/stage.h` | the overlays' types and declarations, and the stages' |
| `include/` | `common.h`, `version.h`, `include_asm.h` and the assembler macros |
| `config/<version>/` | the version's splat configs, symbols, stage list and checksums |
| `mk/version/` | each version's settings for the Makefile and the tools |
| `docs/` | the status, the binaries and versions, the toolchain and the shiftable build |
| `tools/` | build helpers, matching helpers and the report generator (see [Tools](#tools)) |
| `external/` | submodules: maspsx, m2c, decomp-permuter, psyq_headers |
| `Dockerfile`, `tools/docker.sh` | the build environment as a Docker image, and the script that runs a command in it |
| `asm/<version>/`, `build/<version>/`, `expected/<version>/`, `assets/<version>/` | generated; not in git |
| `disks/<version>/` | the extracted disc; not in git |

## Tools

| Tool | What it does |
|---|---|
| `tools/dl_deps.sh` | downloads the PSX GCC, objdiff-cli and mkpsxiso into `bin/` |
| `tools/extract_disc.py` | extracts a disc image, `AAA/` included |
| `tools/stage_yaml.py` | writes a stage's splat config from `config/<version>/stages.txt` |
| `tools/stage_externs.py` | drops the declarations of a stage's own data and functions that are defined before every use |
| `tools/name_stage_data.py` | names the stages' data by its place in the stage's tables, in the C and every version's symbol files (then `make regenerate`) |
| `tools/stage_constants.py` | writes the stages' music, sound ids and flag codes with the names of `include/dw3/sound.h`, `include/stage.h` and `include/dw3/game_state.h` |
| `tools/stage_common.py` | includes a `src/stages/common/` file in place of a stage's copy of its code |
| `tools/try_match.py` | compiles a draft and compares each of its functions with the original |
| `tools/permuter_import.py` | sets up a [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) directory for one function |
| `tools/data_to_c.py` | turns a splat data file into C definitions that reproduce its bytes |
| `tools/objdiff_generate.py` | writes `objdiff.json` (`make objdiff`) |
| `tools/data_sizes.py` | gives compiled data symbols their ELF size, for objdiff (part of the build) |
| `tools/comm_align.py` | gives common symbols larger than a word a word's alignment, as their definitions have (part of the build) |
| `tools/hacks.py` | counts the fake matches and hacks (`--list`, `--check README.md docs/status.md`) and fails on `NON_MATCHING` code, `#if 0` and inline asm in place of C |
| `tools/check_names.py` | checks that every version's symbol files use the USA version's names |
| `tools/match_versions.py` | pairs a version's functions with the USA ones (`build/<version>/version_pairs.txt`) and, with `--seed`, writes their USA names into the version's symbol files |
| `tools/split_version.py` | splits a version's executable and overlays into the USA version's files, from the pairs |
| `tools/version_symbols.py` | names, at a version's addresses, what a USA C file uses, so that the version can build it |
| `tools/rename.py` | renames a symbol in every version's symbol files, `src/` and `include/` |
| `tools/rename_field.py` | renames a struct field in its definition and wherever the code uses it, from the command line or a spec file |
| `tools/docker.sh` | runs a command in the Docker build environment |
| `tools/version.py` | the version being worked on and its paths, for the other tools |
| `tools/shiftcheck.py` | finds the addresses in the code and data that aren't symbols (`make shiftcheck`) |
| `tools/link_imports.py` | writes what a binary links with from the binaries that load after it (part of the build) |
| `tools/padcheck.py` | checks a padding build: only the words with a relocation may change (`make padcheck`) |
| `tools/inputcheck.py` | checks that a link took in only the binary's objects and no blob (part of the build) |
| `tools/lint.py` | parses the game C with a modern GCC for undeclared functions and mismatched pointers (`make lint`) |
