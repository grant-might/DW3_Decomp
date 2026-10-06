#ifndef FIELD_MAP_H
#define FIELD_MAP_H

/*
 * FIELDSTG's map and the functions that read it, which the stages call too,
 * and the records of the tables that each stage gives FIELDSTG.
 * The map is a tree of cells: a grid of 128-pixel cells, then levels of 64,
 * 32, 16 and 8 pixels, each cell four of the next level's, then a byte for
 * each pixel of the 8x8 blocks.
 */

#include "game.h"

struct Point; /* fieldstg.h */

typedef struct FieldMap {
    /* 0x00 */ s32 files[8]; /* the file entry of each map, set by setFile */
    /* 0x20 */ s32 width; /* of the grid, in cells */
    /* 0x24 */ s32 height;
    /* 0x28 */ u8 *grid;
    /* 0x2C */ u8 *cells64;
    /* 0x30 */ s16 *cells32;
    /* 0x34 */ s16 *cells16;
    /* 0x38 */ s16 *cells8;
    /* 0x3C */ u8 *pixels;
    /* 0x40 */ void (*setFile)(s32 index, s32 file); /* func_80091B78 */
    /* 0x44 */ s32 (*getCell)(s32 index, struct Point *pos); /* func_80091BC0 */
    /* 0x48 */ void (*unk48)(struct Point *pos, s32 scale, s32 index, struct Point *out);
    /* 0x4C */ void (*unk4C)(struct Point *pos, s32 scale, s32 index, struct Point *out);
    /* 0x50 */ void (*unk50)(s32 arg0); /* func_80091B90: sets GAME.unk26D8 if GAME.clearTempFlags */
    /* 0x54 */ void (*unk54)(s32 arg0); /* func_80091BB4: sets GAME.unk26D8 */
    /* 0x58 */ s32 (*unk58)(struct Point *pos); /* FIELDSTG_isTileFree: 0 where a character or an object stands */
} FieldMap;

extern FieldMap D_8009A70C;

/* Where an actor's frames go in VRAM: one of the records after the
   FieldImage (Actor.image) */
typedef struct ActorImage {
    /* 0x0 */ s16 x; /* the texture page */
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 imageX; /* where FIELDSTG_animateActor loads each frame */
    /* 0x6 */ s16 imageY;
    /* 0x8 */ s16 u;
    /* 0xA */ s16 v;
    /* 0xC */ s16 clutX;
    /* 0xE */ s16 clutY;
} ActorImage;

/* The image of the field's effects (FieldState.images),
   then the actors' ActorImages */
typedef struct FieldImage {
    /* 0x00 */ ActorImage shadow; /* the actors' shadow (FIELDSTG_drawActor) */
    /* 0x10 */ s16 x; /* in VRAM */
    /* 0x12 */ s16 y;
    /* 0x14 */ s16 w;
    /* 0x16 */ s16 h;
    /* 0x18 */ s16 u;
    /* 0x1A */ s16 v;
    /* 0x1C */ s16 clutX;
    /* 0x1E */ s16 clutY;
} FieldImage;

/* An event of the table FieldState.events, up to
   the first id -1, which FIELDSTG_startEvent starts */
typedef struct FieldEvent {
    /* 0x00 */ s32 id;
    /* 0x04 */ s16 *script; /* FIELDSTG_runEvent's, or NULL */
    /* 0x08 */ s32 text; /* a file and index, the file counted from
                            TEXT_FILE(1); or 0 */
    /* 0x0C */ void *(*start)(void); /* without a script: the task it starts, or NULL */
    /* 0x10 */ void (*end)(void); /* or NULL */
} FieldEvent;

/* What a character says (FIELDSTG_runActorAction): the first whose conditions hold,
   or the last, which has none */
typedef struct FieldTalk {
    /* 0x0 */ u16 *conditions; /* FLAGS_00.checkConditions's */
    /* 0x4 */ u16 *actions; /* FLAGS_00.applyActions's when it ends, or NULL */
    /* 0x8 */ s32 unk8; /* FIELDSTG_createTalk's */
} FieldTalk;

/* A character of the field (FieldState.actors, a list of pointers up to NULL), which func_8008A154 creates
   unless its conditions fail. Ids 1, 0x6A, 0x146 and 0x147 are the player's. */
typedef struct FieldActorEntry {
    /* 0x00 */ u16 *conditions; /* FLAGS_00.checkConditions's, or NULL */
    /* 0x04 */ struct FieldTalk *talks; /* up to the first without conditions */
    /* 0x08 */ s16 id;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 x; /* in pixels */
    /* 0x0E */ s16 y;
    /* 0x10 */ s16 dir;
} FieldActorEntry;

/*
 * An object of a map, which FIELDSTG draws: a record of the table at
 * FieldState.objects, which ends with unk2 = 0
 */
typedef struct StageTile {
    /* 0x00 */ u8 visible;
    /* 0x01 */ u8 anim; /* which of a stage's animations sets frame (1-3);
                           FIELDSTG finds objects by it (its lift, 2 and 3,
                           its commands, 100-105) and draws 0xFF from its
                           effect sprites */
    /* 0x02 */ u8 unk2; /* how far off the view it is still drawn; 0 ends the table */
    /* 0x03 */ u8 depth;
    /* 0x04 */ u8 frame;
    /* 0x05 */ u8 cycle; /* 1 cycles the frame, 2 the CLUT row, 3 the row back and forth */
    /* 0x06 */ u8 cycleFirst;
    /* 0x07 */ u8 cycleLast;
    /* 0x08 */ u8 cycleDelay;
    /* 0x09 */ u8 clutRow;
    /* 0x0A */ s16 x;
    /* 0x0C */ s16 y;
    /* 0x0E */ s16 unkE; /* drawn sorted at this depth, or 0 */
    /* 0x10 */ s16 cycleTime; /* in 1/256 frames; bit 15: going back */
} StageTile;

/*
 * What the player can trigger on a map (FIELDSTG_updateTriggers): a record
 * of the table at FieldState.slots, which ends with type 0,
 * where the points are copied to
 */
typedef struct StageSlot {
    /* 0x00 */ u16 conditions[2][2]; /* flag code and value, or code 0xFFFF */
    /* 0x08 */ u16 type;
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12; /* the id of the map objects to clear, or 0 */
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
} StageSlot;

/* A battle that can start on the field (see FIELDSTG_startEncounter) */
typedef struct Battle {
    /* 0x0 */ s32 unk0; /* the encounter, of FIELDSTG_encounters */
    /* 0x4 */ s32 unk4; /* the fight stage, for BATTLE_SETUP.stage */
    /* 0x8 */ s32 unk8; /* the music, for BATTLE_SETUP.music */
} Battle;

/* The battles of an area of the map (its cells' value at FieldMap.files[4]),
   one picked at random */
typedef struct BattleList {
    /* 0x0 */ s32 count; /* how often they come: an index of FIELDSTG_battleRates */
    /* 0x4 */ Battle *battles[8];
} BattleList;

/*
 * The battles of a place (FieldState.battles), by
 * area of the map: the fourth area's are also the ones that events start
 * (func_8008B258, FIELDSTG_startEventBattle). A stage with several places has a list of
 * them, which FieldState.findBattles searches for the id.
 */
typedef struct FieldBattles {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 id; /* the place, GAME.unk44 */
    /* 0x08 */ s32 unk8;
    /* 0x0C */ BattleList *battles[4];
} FieldBattles;

/*
 * The field's state (D_800990B4): what a stage tells FIELDSTG about itself,
 * filled by its setup function (stageFuncs[0], FIELDSTG_setupField for the
 * field's own), then what FIELDSTG keeps of the field. The first 0x64 bytes
 * are cleared by FIELDSTG_pickStage, which also picks the stage overlay for
 * the current mode.
 *
 * The setup functions set start with a constructor, (Vec2){x, y}: GCC
 * clobbers the whole field before its two stores, which keeps the stores to
 * D_800990B4 on either side of it but lets the constants rise above it. The
 * match depends on that form: two stores of their own schedule otherwise.
 */
typedef struct FieldState {
    /* 0x00 */ s32 stageFile; /* the stage overlay's file */
    /* 0x04 */ struct Task *(*stageInit)(void *owner); /* starts the stage's task */
    /* 0x08 */ s32 mapFile; /* the file of the map's tiles (FIELDSTG_createMapStreamer) */
    /* 0x0C */ s32 sheetEntry; /* the stage's sprite sheet, loaded before the field starts, or 0 */
    /* 0x10 */ StageTile *objects; /* the map objects, up to the first unk2 0 */
    /* 0x14 */ StageSlot *slots; /* up to the first type 0 */
    /* 0x18 */ s32 imageEntry; /* an image archive's file entry, loaded at (0x140, 0x100), or 0 */
    /* 0x1C */ s32 imageFile; /* or an image archive file, or 0 */
    /* 0x20 */ FieldBattles *battles;
    /* 0x24 */ FieldEvent *events; /* up to the first id -1 */
    /* 0x28 */ union {
        FieldImage *field; /* the field's image (the first two ActorImages) */
        ActorImage *actors; /* then the actors', from actors[2] */
    } images;
    /* 0x2C */ Vec2 start; /* where the player starts */
    /* 0x34 */ s32 startDir; /* and its direction */
    /* 0x38 */ CVECTOR spriteColor; /* the field's sprites' color, unless cd is 0 */
    /* 0x3C */ s32 soundBank; /* SOUND.loadBank's, or 0 */
    /* 0x40 */ s32 music; /* SOUND.playSound's, or 0 */
    /* 0x44 */ s32 textFile; /* the stage's text file, for the talks */
    /* 0x48 */ s32 eventText; /* the running event's text file and entry */
    /* 0x4C */ FieldActorEntry **actors; /* the characters, up to the first NULL */
    /* 0x50 */ s32 innOpen; /* the inn (FIELDSTG_openInn): the pad doesn't move the player */
    /* 0x54 */ s32 bannerShown; /* the area name banner (FIELDSTG_createBanner) */
    /* 0x58 */ s32 busy; /* an event, a warp, a launch or a battle has the player */
    /* 0x5C */ s32 battleStarting; /* an encounter started (FIELDSTG_startEncounter) */
    /* 0x60 */ s32 acting; /* the player talks, climbs, slides or searches */
    /* 0x64 */ Vec2 defaultStart; /* where the player starts without a mode argument */
    /* 0x6C */ s32 defaultStartDir; /* and its direction */
    /* 0x70 */ void (*init)(void); /* FIELDSTG_pickStage */
    /* 0x74 */ s32 (*getFileEntry)(s32 character); /* FIELDSTG_fileEntries's */
    /* 0x78 */ s32 (*getActorWidth)(s32 character); /* FIELDSTG_actorWidths's */
    /* 0x7C */ FieldBattles *(*findBattles)(FieldBattles *list, s32 id); /* the place of the list with that id */
} FieldState;

extern FieldState D_800990B4;

/* FIELDSTG functions the stages call */
struct EventTask *FIELDSTG_startEvent(s32 id); /* creates the task of an event object */
StageTile *FIELDSTG_findObject(s32 anim); /* the first map object with that animation */
StageTile *FIELDSTG_findNextObject(void); /* and the next, or NULL */
void *func_8008B258(void); /* starts a battle: the handler of the stages' events 9000 */

/* FIELDSTG's functions and data that the executable calls (game3.c), by
   these names in its link (config/eu/undefined_syms.txt) */
void func_8008AEB4(s32 mode, s32 arg, s32 x, s32 y, s32 dir); /* leaves the field for a mode */
void func_8008B2C4(s32 index); /* starts the event FIELDSTG_eventIds[index] */
void func_8008B320(void); /* opens the inn */
typedef struct FieldBattleFuncs {
    void (*startEventBattle)(s32 index); /* FIELDSTG_startEventBattle */
    void (*startAreaBattle)(void); /* FIELDSTG_startAreaBattle */
} FieldBattleFuncs;
extern FieldBattleFuncs FIELDSTG_battleFuncs;

#endif
