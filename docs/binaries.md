# Binaries and versions

## The game's binaries

The executable, `SLES_039.36` in the European release and `SLUS_014.36` in
the USA one, holds the engine and the PsyQ libraries. The rest of the game
is in overlays, `AAA/PRO/*.PRO` on the disc, which load right after the
executable's `.bss`. Every engine module is a
global struct holding its state and a table of methods (`GFX`, `HEAP`,
`FILE_CACHE`, `PAD`, `SOUND`, `GAME`...), and every game object is a task
(`createTask`, `include/dw3/task.h`); the overlays reach the engine through
those tables. Each overlay has its own splat config, source folder and symbol
prefix (`CNTY_SEL_`, `STDWTITL_`...):

| Overlay | Loads at (us) | Functions in C (us) | What it runs |
|---|---|---|---|
| `CARDGAME` | `0x80082448` | 306 / 306 | the card battle (mode `0x700`): the decks, the cards in play and the battle screen |
| `CNTY_SEL` | `0x80082448` | 26 / 26 | the country select screen |
| `FIELDSTG` | `0x80082448` | 222 / 222 | the field mode, where the player walks around the map; the stages load on top of it |
| `FIGHTSTG` | `0x80082448` | 297 / 297 | the battle: the fight stage and its lights, the fighters' models, faces and cameras, the battle camera and windows, the queue of battle events and the stat, hit and status checks |
| `SHOCKTST` | `0x80082448` | 17 / 17 | the debug vibration test |
| `SOUNDTST` | `0x80082448` | 8 / 8 | the debug sound test |
| `STAGSLCT` | `0x80082448` | 8 / 8 | the debug stage select, a menu of every scene of the game |
| `STCRDABM` | `0x80082448` | 29 / 29 | the card album |
| `STCRDDEK` | `0x80082448` | 55 / 55 | the decks, which it names with the on-screen keyboard (`include/name_entry.h`) |
| `STCRDSHP` | `0x80082448` | 45 / 45 | the card packs (mode 0x1300): opening a pack uses it up and draws six cards, one from each slot's list in `STCRDSHP_packs` |
| `STDGNAME` | `0x80082448` | 32 / 32 | a name entry screen, a keyboard of character pages |
| `STDWTITL` | `0x80082448` | 91 / 91 | the title screen, the opening movies and a notice screen |
| `STFGTREP` | `0x80082448` | 36 / 36 | the report after a battle (mode 0x1400), which `WFIGHTMN` requests: the partners that went up a level |
| `STGDGLAB` | `0x80082448` | 70 / 70 | the partners' digivolutions, it seems: a menu of three screens that checks the recipes of `STGDGLAB_data` against a partner's entries and sets its three slots |
| `STGMCARD` | `0x80082448` | 45 / 45 | the memory card screen (mode 0xC00): the saves of a card, their details, and saving and loading |
| `STGTRAIN` | `0x80082448` | 94 / 94 | the gyms: a partner trains a stat, gaining some and losing others, with its sprites and the result windows |
| `STITSHOP` | `0x80082448` | 69 / 69 | the item shop, where the player buys and sells items and equips what was bought on a partner |
| `STPLNMET` | `0x80082448` | 53 / 53 | the player's name entry (mode 0x500), with a copy of `STDGNAME`'s keyboard |
| `STSTATUS` | `0x80082448` | 123 / 123 | the screens the field menu opens (`STSTATUS_screens`), such as the item list and the equipment |
| `WFIGHTMN` | `0x800A4CA4` | 42 / 42 | the battle's sub-overlay, which `FIGHTSTG` loads (file 0x1FA) for a normal battle: it checks the party and its equipment and ends the battle |
| `WFIGHTTS` | `0x800A4CA4` | 14 / 14 | the debug battle test, which `FIGHTSTG` loads (file 0x1FB) in place of `WFIGHTMN`: lists of fighters, motions, effects and stages |
| `WSTAG###` (238) | `0x800A4CA4` | 1,369 / 1,369 | the stages: small programs that load on top of `FIELDSTG` and call into it |

`SMDLDATA`, `SDIGIEDT` and `SFSTDATA` hold no code and aren't built.
`WSTAG260` has no code either, only the story events' scripts that
`FIELDSTG` runs, and builds from its C data. The disc's `AAA/DAT`, `AAA/PRO` and `AAA/STR` directories are only
reachable through the ISO 9660 path table, which is why
`tools/extract_disc.py` is needed: dumpsxiso doesn't see them.

The executable's game code is split at its original object boundaries and
named by subsystem:

| File | Contents | Address (us) |
|---|---|---|
| `asm/<version>/main/crt0.s` | PsyQ startup (`2MBYTE.OBJ`), splat's disassembly | `0x80010EBC`-`0x80010F80` |
| `src/main/inn.c` | the inn and the full-screen fade | `0x80010F80`-`0x800120B8` |
| `src/main/system.c` | field menu, CD reader, file cache, task creation and `main` | `0x800120B8`-`0x80014884` |
| `src/main/memcard.c` | memory card saves | `0x80014884`-`0x800154F8` |
| `src/main/game3.c` | game state: flags, event conditions, modes, party and stats | `0x800154F8`-`0x800172E8` |
| `src/main/game3_2.c` | partner data, heap and task registry | `0x800172E8`-`0x80017FAC` |
| `src/main/pad.c` | controllers and random numbers | `0x80017FAC`-`0x80018FEC` |
| `src/main/text_window.c` | text windows, font, cursor and message boxes | `0x80018FEC`-`0x8001D070` |
| `src/main/graphics.c` | display, drawing layers, sprite/TIM/card drawers | `0x8001D070`-`0x8001FC68` |
| `src/main/sound.c` | sound banks | `0x8001FC68`-`0x80020764` |
| `src/main/overlay.c` | the mode overlays' loader and the task that runs a mode | `0x80020764`-`0x80020998` |
| `asm/<version>/main/psyq/` | the PsyQ libraries, splat's disassembly, one file per library object | `0x80020998`-`0x8003E9D8` |

Memory maps (psylink puts `.rodata` in front of `.text`):

| | `us` (`SLUS_014.36`) | `eu` (`SLES_039.36`) |
|---|---|---|
| `.rodata` | `0x80010000`-`0x80010EBC` | `0x80010000`-`0x80010E88` |
| `.text` | `0x80010EBC`-`0x8003E9D8` | `0x80010E88`-`0x8003EDCC` |
| `.data` | `0x8003E9D8`-`0x8005C480` | `0x8003EDCC`-`0x8005CCE8` |
| `.bss` | `0x8005C480`-`0x80082448` | `0x8005CCE8`-`0x80082CB0` |
| `$gp` | `0x8005C2F8` | `0x8005CB50` |
| Overlays (`OVERLAY_VRAM`) | `0x80082448` | `0x80082CB0` |
| Stages, `WFIGHTMN`, `WFIGHTTS` (`STAGE_VRAM`) | `0x800A4CA4` | `0x800A5DE0` |

A 320x480 16-bit TIM image is loaded together with the program, so the
executable stores `.bss` and the gap after it as zeros; splat keeps that tail
as `assets/<version>/tail.bin`. `STAGE_VRAM` is right after `CARDGAME`, the
largest overlay.

## How the versions are organised

One source tree builds every version, one at a time, picked with `VERSION`
(`eu` by default):

| `VERSION` | Release | Executable (SHA-1) | Disc image (SHA-1) | Overlays | Stages | C |
|---|---|---|---|---|---|---|
| `us` | *Digimon World 3*, USA, SLUS-01436 | `SLUS_014.36` (`444653259f78ddb483fd22af72cce9276f42f214`) | `Digimon World 3 (USA).bin` (`f0b022f9be53cbce14640abd8f01beaadcb35208`) | 21 | 238 | yes |
| `eu` | *Digimon World 2003*, Europe, SLES-03936 | `SLES_039.36` (`d1b7e4d646e3a9c2b88fdb25d20b5f7116bbb06d`) | `Digimon World 2003 (Europe).bin` (`457cb233349ba841e03b33d8060f8fbcadd45cb3`) | 21 | 293 | the USA version's, and its own stages' |

- `mk/version/<version>.mk` has each version's settings: the release's name,
  the executable's name, the disc directory, the overlays, where they load
  (`OVERLAY_VRAM`, `STAGE_VRAM`) and the C files it builds (`C_SRC`). The
  Makefile builds nothing else. `tools/version.py` reads the same file, so
  every tool follows `VERSION` too.
- `config/<version>/` has its splat configs (`main.yaml`, `<overlay>.yaml`),
  symbols (`symbols.txt`, `symbols_<overlay>.txt`), the list of stages
  (`stages.txt`) and the checksums (`<executable>.sha1`, `overlays.sha1`,
  `stages.sha1`). The generated `asm/<version>/`, `build/<version>/`,
  `expected/<version>/` and `assets/<version>/` are kept apart too.
- The stages have no config file each: `config/<version>/stages.txt` lists
  them with the offsets where their code starts and ends, and
  `tools/stage_yaml.py` writes their splat configs into
  `build/<version>/generated/stages/`. A stage marked `asm` there keeps its
  code and data in asm segments until it has a C file in that version; one
  marked `asm-data` only its data; no stage is marked either today.
  `c-rodata` takes the bytes before the code, a color or jump tables, from
  the stage's C file too. `head-word` takes `WSTAG924`'s first word from a
  C file of its own, `src/stages/wstag924_head.c`, linked before the
  stage's jump tables (which GCC would align to 8 bytes after it). `data`
  marks the stage with no code, `WSTAG260`, all of it its C file's data.
- The C sees `VERSION_US` and `VERSION_EU`, each 0 or 1
  (`include/version.h`), and so does the assembly (`--defsym`). Code tests
  them with `#if VERSION_EU`, never `#ifdef`; CONTRIBUTING.md has the rules.
- `us` builds every C file under `src/`, and `eu` builds them all too
  (`C_SRC`), with `#if VERSION_EU` blocks where its code or data differ.
  Its executable and overlays are split into the USA version's files, so
  its asm lands at the same paths (`asm/eu/main/system.s` for
  `asm/us/main/system.s`). Its stages that the
  USA version has build from their C files (`config/eu/stages/<stage>.txt`
  gives their functions the USA names), and so do its own, whose functions
  are C where they are the code of a USA stage's C. The European release
  has the USA one's 21 overlays and 238 stages plus 55 stages of its own
  (`WSTAG920`-`974`).
- The versions share their names: the European symbol files hold the USA
  names of the functions and data paired between the two
  (`tools/match_versions.py`), and `tools/check_names.py` checks that they
  stay the same.
