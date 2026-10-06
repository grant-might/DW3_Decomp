# Status

The status table is in the [README](../README.md#status); this page has the
details of each part, how the progress is measured, and the workarounds the
matched C needs.

## The parts

- The executable's game code is all C, and its rodata. Its data is C too:
  each module holds its own, and `src/main/data/` the rest (`matrices.c`,
  `game_3.c` and the `.bss`, `game_bss.c`) until it moves next to the code
  that uses it.
- The PsyQ 4.7 libraries linked into the executable, and `libpress` in
  `STDWTITL`, are Sony's code, not the game's: like other PSX decomps, the
  build takes them from the original as splat's disassembly and the progress
  leaves them out. The C decompiled of them earlier is in the history.
- The 21 overlays are all C.
- The stages are all C, the 238 USA ones and the 55 of the European version
  alone. Many stages share functions built from the same source, so one
  match often repeats across stages: those have the same name in every
  stage, and the copies that are the same C are one file in
  `src/stages/common/` that the stages include. The stages' data is
  C too, as splat's words, at the end of each stage's C file.
- The European version is the main one: the build's default. It is split
  into the USA version's files, with the
  USA names, and builds all of them from the same C: the executable's game
  code and data (the same 346 functions as the USA version), the overlays,
  the 238 stages the USA version has (1,370 functions and their data), and
  the 220 functions and the data of its 55 own stages. Only the PsyQ
  libraries are splat's disassembly.

## Progress

Progress is measured by [objdiff](https://github.com/encounter/objdiff), with
one unit per C file.

```
# Write objdiff.json and the target objects in expected/<version>/
make VERSION=eu objdiff

# Write build/<version>/report.json
make VERSION=eu report
```

After `make objdiff`, open the repository in the
[objdiff](https://github.com/encounter/objdiff) GUI to see each unit's
functions and data against the original. `tools/objdiff_generate.py` makes one
unit per C file (`main/system`, `cnty_sel/cnty_sel`, `stages/wstag200`...); a
file `X_2.c`, the second half of one original object, is reported together
with `X.c`. The units go into the category `game` (the executable), one
category per overlay, and `stages` for all the stages. The executable's data
is one unit, `main/game_data`. The PsyQ libraries get no unit. A file the
version being reported doesn't build from C, but has split at the same path
(`asm/<version>/<binary>/<file>.s`), is its unit with no base object, from
that code and the module's rodata, data and bss segments, so the report
counts all of it as still to do; a binary with no such file is one unit of
splat's code and data. Both versions build every file from C today, so
neither has such a unit. `objdiff.json` is for the version it was last
written for.

Code and data that the build still takes from asm never count as
progress: a function behind `INCLUDE_ASM` keeps splat's `.NON_MATCHING`
label, which objdiff leaves out of the count, and a splat `asm` or `data`
segment has no C object to match.

objdiff counts a unit's `.rodata` or `.data` as matched only when all of the
section is the original's, bytes and relocations. The report compares copies
of the objects (`build/<version>/report/`, `expected/<version>/report/`) made
to write the same data the same way: the base gets the target's names for the
rodata GCC emits without one (string literals, jump tables), pointers are
written as section plus offset on both sides, and the rodata still included
from asm (`INCLUDE_RODATA`, the jump tables of functions behind `INCLUDE_ASM`)
gets one byte changed, so its section only counts once all of it is C. Data
that splat still has in its own segments (`data` in a config rather than
`.data`) isn't in the C object, so it counts as still to do.

`make report` writes each version's progress to `build/<version>/report.json`,
which is where the table above comes from. The checks that read only the source
and the configs run first: `tools/check_names.py` and `tools/hacks.py`. The
build then runs `make compare`, the shift checks
(`tools/shiftcheck.py --strict`, `make padcheck`) and `make lint` for both
versions.

## Fake matches and hacks

The matched C is meant to read as natural C, but some spots only match
through a form that natural C wouldn't take for granted. Each one carries a
comment that says so, in one of four standard forms
([CONTRIBUTING.md](../CONTRIBUTING.md#matching) has the rules), and the
README's badge counts them: fake matches, then the other kinds together.

| Kind | Count | Marker |
|---|---|---|
| Fake matches | 0 | a comment that starts with `/* fake match:` and says what is forced and why |
| BEC forms | 1 | a comment that starts with `/* BEC form:` and names a function elsewhere with the same form |
| Unused frame locals | 6 | `/* unused, but it is in the original stack frame */` |
| Form-dependent matches | 184 | a comment that says the `match depends on` the form |
| Functions still in assembly | 0 | `INCLUDE_ASM` |

- A fake match is the last resort: a form forced only for the code it makes,
  such as an empty `do {} while (0)` that ends a CSE block or a variable
  that exists only to shape the code. There are none so far.
- A BEC form is a form the rules take nowhere else, allowed as a one-off
  exception because another matched decomp, built with the same GCC 2.8.1 at
  `-O2`, has it. The one so far is STGDGLAB's `func_8008C234`, whose
  `skillCount = 6` store is alone in a `do { } while (0)`: its loop notes keep
  the store before the call's arguments through both schedulers, as that
  decomp's stage update functions do in theirs. Its comment starts with
  `/* BEC form:`.
- An unused frame local is a local that the code never touches, kept because
  the original's stack frame has room for it: without it, the frame is
  smaller than the original's. One is in the game's `drawTalkBoxArrow`, one in STSTATUS's `STSTATUS_runStatusChoice`,
  one in FIGHTSTG's `func_8008CFFC` and three in WFIGHTTS.
- A form-dependent match is C that matches in one of several equivalent
  forms only: an extra block, an `if` without braces, a copy of a variable, a
  type, or one version's own form of a loop. The hundred and eighty-four so far are a copy
  of a variable in `drawTalkBoxArrow`, an unsigned compare in STGMCARD's
  `func_80082E28`, a variable that holds two values in STCRDDEK's
  `STCRDDEK_drawDeckCards`, a counter set before a call in
  `STCRDDEK_drawEditor`, the rows' y offset held in a variable in
  `STCRDDEK_createScreenWindows`, a `u32` copy of a character in the keyboards of
  STCRDDEK and STDGNAME (`STCRDDEK_updateKeyboard`, `STDGNAME_updateKeyboard`),
  a `* 4` written as a statement of its own in FIELDSTG's `func_80091BC0`,
  variables local to a case or a block in its `func_80086E64` and
  `func_80091D3C`, an empty case in its `func_800870D4`, two variables for one
  character and an `s16` in its `func_80084654`, calls in an `if`/`else`
  and a `case 0` next to `default` in its `func_80084D0C`, the button's shift and mask as two statements in its `func_8008D710`, a gauge cell read and shifted as two statements in its `func_8008C59C`, an `s16` shadow offset in its `func_8008E7E0`, a distance written twice in its `func_8008B450`, the kind reused for the mode in its `func_80090450`, a loop with both of its tests at its top and steps added as a choice in its `func_8008F184`, the registry held in a variable in its `func_8008D4C4`, a counter for each loop in its `func_80085650`, the start position set with a `(Vec2){x, y}` constructor in its `func_80091124`, the leader read into a variable before the trail in its `func_8008DFE0`, the tile move written as an early exit in a `do`-`while (0)` with the move declared in it in its `func_800896C0`, the object's case written as an early exit, a `do`-`while (0)` with a `break`, in its `func_8008DB60` (its loop notes weigh the references and stop the schedulers), the file's pick and the frames' step written as early exits in `do`-`while (0)`s, a flag read twice, a width cast to `s16` and the flag cleared last in its `func_8008EC74`, the map's file check written as an early exit in a `do`-`while (0)` with the file declared in it in its `func_80091AA8`, the y offset written as `scrollY` less its tile's start, `x` holding the flip before the column and a counter shared by two loops in its `func_80085EEC`, a -1 held in a variable in STGTRAIN's `func_800874A0`, stats read through two inline functions in its `func_800867A0`, a variable for each loop and each cursor's last value in its `func_80087E34`, the column set in each branch of an `if` in its `func_80085AF8`, the magic number read into a variable before the image pointer is copied, and the image set before the source moves on, in its `func_8008B35C`, the position pointer set after two calls and a 1 stored as the result in its `func_80088CFC`,
  stats read as `*(totals.stats + i)` in its `func_80083ADC`, `s16` copies
  of two stats in its `func_80085E30`, a counter that
  holds an icon too in its `func_800878C0`, a frame pointer that holds the
  animation first in its `func_800828E8`, the same `u32` copy in STPLNMET's
  `STPLNMET_updateKeyboard`, twenty-seven spots in STSTATUS and three in STCRDSHP (a
  copy, a cast, a temporary, a pointer, a pointer sum, `for` initializers, a
  variable of its own for a loop or a case, a counter shared by three
  loops, a statement written in both
  branches, a list indexed rather than walked, the order of a sum's terms, a
  test of another field, two calls in place of a conditional argument or a
  variable that holds the remainder first), a `cards++` written in the `for`
  in STCRDSHP's `STCRDSHP_createGrid` and `STCRDSHP_drawCards` (which also
  writes its digits' x as `dx + 0x27 + x`), four spots in STGDGLAB and four
  in STITSHOP (loops with counters of their own, a column counter apart
  from the loop's, a reused variable,
  range tests written out, a function of its own
  or a copy), six spots in STFGTREP and twelve
  in WFIGHTMN (a variable, a case or a statement of its own, a pointer sum,
  a statement written in both branches, a counter set before a call, a
  variable reused, a pointer, an offset from a pointer, a `while (1)` or a
  helper that stores through pointers), five in WFIGHTTS (the loop around
  the pad handling in its four lists, a call in each branch in its
  `WFIGHTTS_battleTest`, and in its fighter list a counter for each list and the
  blinking cursor's test split in two, with the fighter's load in both branches),
  sixty-three spots in FIGHTSTG (cases that do nothing, a case next to
  `default`, a menu's result switched with case -1 first, variables
  declared in an `if`, a test written the other way round, a value read
  after a change, a percentage
  written as `* 20 / 100`, a table walked by index, an ending written out
  in each case or branch, a flag cleared in each branch, a step advanced in each case, a row pointer, a
  variable reused, shared by cases or of its own, a counter set
  in a loop's init, an index from a later member, a pointer sum, pointers and
  blocks of their own, a task taken as `void *`, a value read first, a row's offset added as an int, a value written as a sum and one more, a return in each case, a division written in each branch, a value doubled and scaled in each branch, a counter for each loop, a `u8` team, a constant set apart, a `goto`
  into a branch, an `if`/`else`, an order of stores or of chained stores, a pointer passed on as
  `++mode`, children taken as a `void *` and copied, a `* 32` for a shift, an
  early exit written as a `do`-`while (0)` with `break`s as the stages' event
  code writes it (in the mesh drawer, around each polygon's checks and
  drawing, where its loop notes weigh the references), a choice written in both branches or a `?:`, a pointer to
  a bone's slot, sums kept in variables so gcc doesn't fold their constants,
  a primitive tag's word set in two steps, a `(Vec2){x, y}`
  constructor, one pointer walking three arrays, a field read through a pointer to the array before it or a
  vsync callback's `s32` argument cast to its task, or a
  `const` pointer to the table of battle functions), twelve spots
  in CARDGAME (a loop or state variable of its
  own, an empty case, a statement written twice, or a copy of an argument), a reset written in both
  branches in SHOCKTST's `SHOCKTST_playAllPatterns`, a times pointer that
  holds the file's start until the cursors are copied from it and the
  powers cursor stepped before the times one in its `SHOCKTST_convertText`,
  a variable that keeps
  the old top too in STAGSLCT's `STAGSLCT_updateStageSelect` and an exit
  written as a `do`-`while (0)` with `break`s, with the codes kept in an
  `int` as two-byte character constants, in its `STAGSLCT_showBiosVersion`, the do-while of
  `COUNTDOWN_BORROW`, the statement macro of the timed stages' countdown,
  and the start position that every stage's setup function sets as a
  `(Vec2){x, y}` constructor (both in `include/stage.h`).
- The functions still in assembly are not in the badge: they would be the
  work left, and there are none.

`tools/hacks.py --list` lists every one with its file, line and function, and
also what is assembly without being a hack: the rodata still behind
`INCLUDE_RODATA`, data written as a top-level `__asm__`, and the macros that
wrap the inline asm C can't say. The CI fails on what the source must never
have: `NON_MATCHING` code, `#if 0` blocks, and inline asm in place of C.
`tools/hacks.py --check README.md docs/status.md` checks that the README's
badge and the table above are up to date.
