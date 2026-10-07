# TODO

Both versions build byte for byte, and everything the game itself is built
from is matched C: the executable's game code and data, the 21 overlays, and
all 293 stages - the 238 the USA version has and the 55 the European version
has of its own. No function is still assembly (`INCLUDE_ASM` appears nowhere
under `src/`), and there are no fake matches: the 189 hacks the badge counts
are 182 form-dependent matches, 6 unused frame locals and one BEC form, each
with a comment saying what is forced (see
`docs/status.md#fake-matches-and-hacks`). The PsyQ 4.7 libraries, and
`libpress` in `STDWTITL`, are Sony's code rather than the game's: the build
takes those from the original as splat's disassembly and the progress leaves
them out.

The European version, *Digimon World 2003*, is the main one: the build's
default. It has every overlay and stage
the USA version has plus 55 stages of its own, and builds all of them from the
same C.

What is left is **not matching work**. It is names (many overlay and stage
functions still carry splat's `func_` and `D_` names, and 405 struct fields are
`unk`), types for the stage data that is still splat's words, and the tooling
and docs notes further down. The counts below were taken from the source and
from the `us` and `eu` builds at commit `45827a6`.

## The European version

`make VERSION=eu compare` is OK for `SLES_039.36`, its 21 overlays and its 293
stages. The executable and the overlays are split into the USA version's
files (`tools/split_version.py`), so their asm lands at the USA paths, and
their functions carry the USA names (`tools/match_versions.py --seed`). The
European C is the executable's game code and data, the
overlay functions the USA version has in C and every stage's C: the 238 USA
stages are built from the USA version's C, the 55 European ones from their
own.

- [x] Pair the European functions with the USA ones
  (`tools/match_versions.py`, which writes `build/eu/version_pairs.txt`):
  910 of the executable's 913 functions, 1,680 of the overlays' 1,689 and
  1,358 of the stages' 1,595 pair with confidence. The USA version's
  functions are 99.9 %, 99.7 % and 98.8 % paired; what is left of the
  European stages is mostly `WSTAG920`-`974`.
- [x] Split the European executable into the USA version's files (`crt0`,
  `inn`, `system`, ..., the PsyQ objects and the data files) and each
  overlay the same way (`STDWTITL` into `stdwtitl`, `stdwtitl_2` and
  `libpress`, `STDGNAME` into `stdgname` and `stdgname_2`), so that the
  report has the USA units.
- [x] Seed `config/eu/symbols.txt` and `config/eu/symbols_<overlay>.txt` with
  the USA names of the paired functions and data: 1,064 of the USA
  version's 1,091 names are in the European files.
- [x] Build the USA files that match unchanged: `game3_2` and `SOUNDTST`
  (`tools/version_symbols.py` names what they use).
- [x] 17 PsyQ files (`libsnd_vm_init`, `libspu_s_sav`, `libmcrd_libmcrd`...)
  used a `D_` name of the USA version that the European asm has at another
  address: those data have real names now (`_spu_rev_startaddr`,
  `_spu_RQ`, `PAD_SIO_REGS`, `MCRD_READ_RETRIES`...).
- [x] Build the executable's game code and data for `eu` too, with
  `#if VERSION_EU` blocks where they differ: the language (`LANGUAGE`, set
  by `CNTY_SEL`) picks the text files (`TEXT_FILE()`), the save file name and
  whether the buttons swap; 50 Hz (`NTSC_MODE`) changes the clocks, the
  sound's tick and fades and the video mode; the disc's files are numbered
  differently (`FILE_MENU_SPRITES`, `FILE_FONT`); `GAME` has 8 more bytes of
  flags. Its data is `data_to_c.py`'s output for `asm/eu/` where it differs.
  The European executable's game code is the USA one's 346 functions.
- [x] Build every overlay's USA C for the European version too, functions
  and data, with `#if VERSION_US`/`#elif VERSION_EU` where the discs
  differ: file numbers (`SHOCKTST` loads `0xBE` for `0xC5`), the language
  tables of `STDWTITL`, `STCRDDEK` and `CNTY_SEL`, data of other lengths,
  and `FIGHTSTG`'s 4 functions of its own.
- [x] The European files name everything the USA ones do, and
  `tools/check_names.py` passes. The executable has all of USA's names
  (the flag groups are `GAME`'s fields, `flags02`-`flags40`, at other
  offsets in each version). The data that differing
  code reads (`STDWTITL_movies`, `STAGSLCT_entryNames`, `SHOCKTST_menuRows`,
  ...) is named in each overlay's file and is C in both versions. No
  European overlay has an asm data segment, except `STDWTITL`'s
  `libpress` (PsyQ), which USA has too. `tools/match_versions.py` leaves
  the following without a confident pair:
  - `CARDGAME`'s `func_80085AA8` and `func_80091A94`: candidates by
    adjacency (0.65 and 0.82). They are named by their size and
    neighbours, and are C in both versions with `#if VERSION_EU` changes.
  - The executable's `setSaveFileName`: the European one is longer (it
    picks the save file by the language). It has USA's name and is C in
    both versions.
  - `STGDGLAB_moveRecipeCursor`, the recipe screen's cursor step.
    European only (a `version-only` name) and C.
  - `FIGHTSTG`'s `func_8008F5D4`, `func_800A1FE0` and `func_800A246C`
    (splat's names) and `FIGHTSTG_rollCounter`. European only and C.
- [x] The stages: 233 of the USA version's 238 are 8 bytes longer in the
  European version because each one's setup function adds the language
  (`LANGUAGE`, which `CNTY_SEL` sets) to the text file it loads; the
  other 5 also have longer functions (`WSTAG210`, `220`, `270`, `280`) or
  one more (`WSTAG780`). Each USA stage builds from its C file in both
  versions, its functions with the USA names
  (`config/eu/stages/<stage>.txt`): all 1,590 of the European stages'
  functions are C.
- [x] The setup functions (the one that fills `FIELDSTG_state` and loads the
  stage's text file) are C in both versions, from one C. The European
  scheduling needed the stores up to `0x1C` and the one to `0x44` to stay
  before the others while the constants rise to the top. The start
  position does it: written as a constructor, `unk2C = (Vec2){x, y}`, it
  makes GCC's `store_constructor` clobber the whole field (a `BLKmode`
  `MEM`, which conflicts with every access to `FIELDSTG_state`) before its two
  stores, so the stores stay on their side of it and the constants don't.
  It gives the USA order too. The text file is `STAGE_TEXT`, the file and
  archive numbers `STAGE_FILE` and `STAGE_ARCHIVE`, the stage's own
  defines; `unk7C` (`FIELDSTG`'s `FIELDSTG_findBattles`) finds a record of a list
  of 0x1C-byte records by its id.
- [x] The 8 functions that read `GAME` fields 8 bytes later in the European
  version (`countdown`, `unk26DC`, `unk26E8`) are C in both: `WSTAG745`/
  `746` `func_800A4CA4`, `WSTAG795` `func_800A50F8`/`func_800A5240`,
  `WSTAG800` `func_800A5404`/`func_800A554C`, `WSTAG810` `func_800A58F0`/
  `func_800A5954`, with `GAME.countdown` (`u8 [4]`, `0x26CC`) and the
  `StageInfo` fields `0x50`-`0x60`.
- [x] The 55 European stages, `WSTAG920`-`974`, have C files, their data
  too: all their functions are C.
- [x] Where the versions' code differs only in numbers, `include/stage.h`
  and the stages' own defines give them: the file numbers (`SPRITES`,
  `MENU_TEXT`...), `MENU_SPRITES` and `TEXT_ENTRY` (the European version
  adds the language to the text file).
- [x] `game3_2` is C in the European version, but its unit in the report is
  `game3`'s: it counts now that `game3.c` is built for `eu` too.

## The USA executable

- [x] The game code is all C: `spriteDrawerDraw` and `convertText`
  (`graphics.c`) were the last.
- [x] The executable's rodata is all C. `OVERLAY_ADDRESS` and
  `SUB_OVERLAY_ADDRESS` (`system/main.c`) are `const` pointers in
  `.rodata`, read with `lui`/`lw` although the module is built with `-G8`:
  the game's code is built with `-membedded-data`, which puts a small
  `const` in `.rodata` and changes nothing else. The text windows' strings
  and tables are C.
- [x] The executable's data is C. Each module holds its own (the field
  menu's tables, `DIGIMON_DATA`, the items, the techniques, `CD_READER`,
  `FILE_CACHE` and the file table, `GAME`, `FLAGS_00` and the game's
  tables, `HEAP`, `TASK_REGISTRY`, `PAD`, `RANDOM`, the text windows',
  the banks' files and `SOUND`, the mode tables and `OVERLAY_LOADER`,
  `GFX`, the font's maps and glyphs, `GFX_STARTED`); the rest is in
  `src/main/data/`: `matrices.c`, the other modules' small data in
  `game_3.c` and the `.bss` in `game_bss.c`.
- [ ] Move that data next to the code that uses it: `src/main/data/` is where
  the report keeps what has not moved yet.
  - The usable items' effects (`ITEM_EFFECT_2B`..., 4 bytes each) are
    the original `system`'s small data, in `game_3.c` among the other
    modules' until `.sdata` moves too.
- [x] `crt0` (`2MBYTE.OBJ`), PsyQ's startup, stays splat's disassembly (an
  `asm` segment, both versions). Its 8 bytes of `.bss`
  (`CRT0_SAVED_RA`) are in `data/game_bss.c`, which starts the `.bss`, so
  they stay in a report unit.

## PsyQ

The PsyQ libraries, and `libpress` in `STDWTITL`, are Sony's code, not the
game's: the build takes them from the original as splat's disassembly (`asm`,
`rodata` and `data` segments) and the progress leaves them out. The C
decompiled of them earlier, and the notes on its last functions and its
compilers, are in the history.

## Overlays

- [x] The overlays' functions are all C: 1,670 in the European version and
  1,665 in the USA one (`STDWTITL`'s `libpress`, PsyQ, is splat's
  disassembly, out of the count).
- [x] The overlays' last functions, each matched in a form `docs/status.md`
  lists: FIELDSTG's `FIELDSTG_selectMap` with its file check as an early exit in
  a `do`-`while (0)` with the file declared in it, FIGHTSTG's
  `func_8009C8EC` with a `const` pointer to the table of battle functions,
  STGDGLAB's `func_8008C234` with a BEC form (below), and FIELDSTG's
  `FIELDSTG_pickViewTiles` with the y offset written as `scrollY` less its tile's
  start: the two reads of `scrollY` rank its load ahead of the x test in
  local-alloc, which was all that was left of its 24 diffs. The notes on
  what was tried before are in the history.
- [ ] `fightstg_3.c`'s `func_80087304`
  returns its task, which `func_80091A58` stores, but is defined `void`
  (`fightstg_6.c` has a prototype of its own that returns the task).
- [x] The field menu's near miss. `STGDGLAB`'s `func_8008C234` matches in
  both versions with its `skillCount = 6` store alone in a `do { } while (0)`,
  a BEC form (`docs/status.md`): the loop notes keep sched1 and sched2 from moving the
  store after the argument moves of the call to
  `STGDGLAB_createSkillPanelWindows`. Without a barrier, the store ties with
  the two moves on priority, and its potential hazard (the memory unit's
  hazard times `unit_n_insns[0] - 1`, with 11 memory insns in the block)
  makes the scheduler pick it first from the end. Every natural form tried
  gives the same 4 diffs: other orders, variables, labels, inline helpers,
  casts of the callees, the permuter and 17 flag setups. The other shapes
  that match are forced as well: the store in both arms of a test of
  `getPartnerEntry`'s result, a dead local set under that test, a loop
  after the store that runs no iteration, or a `do`-`while (0)` whose only
  `break`, on a block-scoped load of `entry.id`, ends its body (`regpri9/`,
  `w_xj.c`, `w_dead.c`). A real conditional break can't be it: the
  original's case has no branch. Another matched decomp has the same block
  in its task-state init cases.
  None of the three objects (`fieldstg_3.c`, now `event.c` to `start.c`
  and `banner.c`'s first function, `fightstg_6.c` and `stgdglab_4.c`)
  builds with another compiler for the whole file (`fightstg/r37/cc.sh`,
  results in `r37/cx/cc_*.txt`): GCC 2.7.2 (patched, stock, with the
  second CSE pass), SN's 2.8.1, 2.95.2 and `-O1` leave
  1 to 42 of each file's functions matching, and `-G8` loses 2 to 33.
  GCC 2.8.0 and the other `maspsx` versions (2.56, 2.79, 2.84) keep every
  other function but give the three the same diffs as 2.8.1.
  The three originals show nothing cc1 doesn't emit (standard prologues,
  `addu` moves in delay slots, shared CSE bases such as
  `FIGHTSTG_battle + 0x70`), so there is no case for hand-written code. `STCRDSHP` is three objects, like
  `STSTATUS`'s ten: GCC aligns a jump table to 8 bytes, and the original's
  tables only line up at its object boundaries.
- [x] `STGTRAIN` is three objects (`stgtrain.c` to `stgtrain_3.c`): the
  jump tables at 0x8008251C and 0x800825E8 (USA) each start right where the
  one before ends, 4 bytes past a multiple of 8, so each one starts an
  object. Where each object's code starts is a guess between the function
  with the last table of the object before and the one with its first; the
  data is all in `stgtrain.c`.
- [ ] Check `STFGTREP`'s guess (the report after a battle) against its
  texts, and `STGDGLAB`'s (the partners' digivolutions) against its
  strings.
  `STAGSLCT`'s menu of every scene of the game may help.
- [ ] Name the overlays' functions: only `CNTY_SEL`, `SHOCKTST`,
  `SOUNDTST`, `STAGSLCT`, `STCRDABM`, `STCRDDEK`, `STCRDSHP`, `STDGNAME`,
  `STDWTITL`, `STFGTREP`, `STITSHOP`, `STPLNMET`, `STSTATUS` and `WFIGHTTS`
  have names (and `FIGHTSTG` its event queue, fighters' file and battle
  table; `STGDGLAB` and `STGMCARD` their helpers and tasks; `WFIGHTMN` all
  but the turn states 6, 17 and 26 and the six helpers FIGHTSTG calls); the other
  overlays' symbol files are empty or hold a few `D_` entries, so `FIELDSTG`
  and `STGTRAIN`, much of which is C, are still `func_`.
- [x] Overlay data: all of it is C in both versions, the last being
  `stgdglab_4`'s 340 bytes of rodata, whose jump table came from
  `func_8008C234`'s asm until it matched.
  `WFIGHTTS`'s strings are a `const char` array whose padding after each
  table's last string is what the assembler left there, in both versions,
  and so are the cursors, `"＞"`, of `SOUNDTST` and the European
  `STAGSLCT`, which the European overlays pad with 0x2D and 0x39 where GCC
  would put 0. The European `CNTY_SEL` file ends 3 bytes into its last
  word, which spimdisasm leaves out of splat's data: the report gives the
  target those bytes from the file (`complete_tail`). splat named
  `CARDGAME_showTargetSlots`'s jump table `D_80082C94` (the function reads
  it through a saved pointer), so it is `type:jtbl` in both versions'
  symbols.
- [x] `SOUNDTST`'s texts are string literals in its lists, which GCC puts
  in `.rodata` in reverse order of each list. The European file pads the
  last one, `"＞"`, with 0x2D instead of 0, so that one is a `const char`
  array with its padding (`SOUNDTST_STR_CURSOR`).

## Stages

- [x] The USA stages are all C: their 1,369 functions, the setup
  functions too (see the European stages above).
- [x] A stage's jump tables come from its C (`c-rodata` in `stages.txt`),
  and so does the color that 85 stages start with (a `const CVECTOR` that
  the setup function copies to `unk38`).
- [x] The stages' data and rodata are all C, in both versions (816,636
  bytes in the USA version's report, 950,503 in the European one's), as
  splat's words (`tools/data_to_c.py`) at the end of each stage's C file,
  with `#if VERSION_US` / `VERSION_EU` rows for the words that differ (file
  numbers, mostly) or that one version hasn't. `WSTAG331`'s data differs
  throughout between the versions (its event scripts), so some of its
  arrays have each version's whole definition. Seven European stage files
  end inside a word: their last bytes are C too, the end of an event script
  (`u16` rows) or `WSTAG925`'s `D_800A67C4` offsets, and their configs
  align nothing after the data (`tools/stage_yaml.py`).
- [x] `WSTAG924`'s color comes before its jump tables, which GCC would align
  to 8 bytes after it in the stage's C: `head-word` in `stages.txt` takes
  it from a C file of its own, `src/stages/wstag924_head.c`, linked first,
  and the report counts it with the stage (`tools/objdiff_generate.py`).
- [ ] Most of the stages' data is still splat's words: the point paths,
  animations and tile tables the C reads have types (`include/stage.h`),
  give the rest real ones (and names) as the code that reads it is
  understood. Every stage's tables at `StageInfo.unk10` (`StageTile`, the
  map objects), `unk14` (`StageSlot`, the triggers), `unk20`
  (`FieldBattles`, with their `BattleList`s and `Battle`s), `unk28`
  (`ActorImage`, the images), `events` (`FieldEvent`, with their scripts as
  `s16` commands) and `unk4C` (`FieldActorEntry`, with their `FieldTalk`s
  and `u16` condition and action lists) are records now, all their types
  shared with FIELDSTG through `field_map.h` (its own stage,
  `FIELDSTG_setupField`, has them as `FIELDSTG_mapObjects`, `FIELDSTG_slots`,
  `FIELDSTG_images`, `FIELDSTG_events` and `FIELDSTG_actors`). Where the
  original's padding after a script isn't zeros (39 scripts), a top-level
  asm writes it. Where the same address holds different things in each
  version (`WSTAG331`'s `D_800A5D2C`), each version has its own definition.
  Still words: what only a stage's own code reads.
- [x] Share the stage functions that are the same C: each one is a file in
  `src/stages/common/` that the stages include -
  `startStage` (285 stages), the `updateStage` that does nothing (167),
  `copyPlacePoints` (34), the `updateStage`s that only call it on their
  `placePoints` (32), `stepLoopingAnimation` (16), `stepAnimation` (12), `isOnScreen` (12)
  and the `StageEffect` functions, `createStageEffect`, `updateStageEffect`
  and `drawStageEffect` (10 or 11, on each stage's `effectFrames` and
  `effectClutFrames`), the menu stages' `startTween` and `updateTween`
  (9), and the `updateStage` that only creates the tile animation task (7;
  `createTileAnims` and `updateTileAnims` are named in 15 stages).
- [ ] Name those, and share what is left: the copies of
  `stepTileAnimation` (18) and `stepAnimationOnce` (12) are named but not
  shared, because their types differ or a stage has two of them; a stage's
  second copy of a function ends in 2, 3 and so on.
- [ ] Most stage functions still have splat's name. A stage's own symbol
  file, `config/<version>/stages/<stage>.txt`, is read by the Makefile and
  `tools/stage_yaml.py`; the European ones give the USA stages' functions
  their USA names. The functions every stage has are named in both
  versions' files: `startStage`, `updateStage`, `setupStage` and the table
  `stageFuncs` (`include/stage.h`).
- [ ] Find what each stage is (the map or event it runs).

## Names and types

- [ ] 405 `unk` struct fields in the headers, and 2,008 different `D_`
  symbols referenced from `src/` and `include/`.
- [x] The versions share their names, and `tools/check_names.py` fails the CI
  on a European name that isn't the USA one; `tools/rename.py` renames in
  every version's symbol files, `src/` and `include/` at once.

## Tooling and docs

- [ ] The README's status table and the overlay table in `docs/binaries.md`
  are written by hand from `make report`; `tools/hacks.py --check README.md
  docs/status.md` checks the hacks badge and table, but not them.
- [ ] `objdiff.json` holds one version at a time: the last one `make
  objdiff` was run for.
- [x] Some comments still described the USA version only:
  `tools/stage_yaml.py` spoke of "the 238 stage overlays", and
  `tools/objdiff_generate.py` of `config/main.yaml`.
