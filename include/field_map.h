#ifndef FIELD_MAP_H
#define FIELD_MAP_H

/*
 * What the stage overlays and the executable use of FIELDSTG (fieldstg.h has
 * the rest): its layers and task ids, the map and the functions that read
 * it, the records of the tables that each stage gives FIELDSTG, the field's
 * state, and the functions the stages and the executable call.
 * The map is a tree of cells: a grid of 128-pixel cells, then levels of 64,
 * 32, 16 and 8 pixels, each cell four of the next level's, then a byte for
 * each pixel of the 8x8 blocks.
 */

#include "game.h"

struct Point; /* fieldstg.h */

/* The field's drawing layers, by their ids (GFX.funcs.createLayer), as
   FIELDSTG_updateField creates them */
#define FIELD_LAYER_BACK 0x1000 /* the background's color */
#define FIELD_LAYER_COVER 0x1001 /* the cover that fades the screen (FIELDSTG_drawCover) */
#define FIELD_LAYER_MAP 0x1002 /* the map, its objects and characters, and the menus */
#define FIELD_LAYER_BANNER 0x1003 /* the area name banner */
#define FIELD_LAYER_TEXT 0x1004 /* the message and talk boxes */

/* The ids of the field's tasks (createTaskWithId, TASK_REGISTRY.funcs.find) */
#define FIELD_TASK_MAP 4 /* FIELDSTG_createMapStreamer's */
#define FIELD_TASK_ACTOR 5 /* every character (FIELDSTG_createActor) */
#define FIELD_TASK_FIELD 7 /* the field's main task (FIELDSTG_createField) */
#define FIELD_TASK_BANNER 9 /* the area name banner */
#define FIELD_TASK_HIDDEN_SPOTS 0xB
#define FIELD_TASK_CAMERA 0x10
#define FIELD_TASK_ICON 0x16 /* the icon over the player's head */
#define FIELD_TASK_LAUNCHER 0x17 /* a stage's launchers (FIELDSTG_runLaunch) */
#define FIELD_TASK_COMMANDS 0x32D /* script command 813 (FIELDSTG_startCommandTask): the field commands */

/*
 * The field commands, which an event script hands FIELD_TASK_COMMANDS as the
 * first argument of a pose command (FIELDSTG_handleFieldCommand). The
 * PLAY_ commands play the sound of their SOUNDTST name; a STOP_ command
 * keys off the sound its PLAY_ command holds.
 */
#define FIELD_COMMAND_HALT_PARTNERS 0x337 /* the partners stop following */
#define FIELD_COMMAND_ICON1 0x338 /* the player icon's substate 1, with ITEM_GET */
#define FIELD_COMMAND_ICON2 0x339 /* its substate 2 */
#define FIELD_COMMAND_ICON3 0x34A /* its substate 3, with ITEM_GET */
#define FIELD_COMMAND_HIDE_OBJECTS(n) (0x34D + (n)) /* hides the map objects of group n */
#define FIELD_COMMAND_SHOW_OBJECTS(n) (0x353 + (n)) /* shows them */
#define FIELD_OBJECT_GROUPS 6
#define FIELD_OBJECT_GROUP_ANIM 100 /* the StageTile.anim of group 0; group n has 100 + n */
#define FIELD_COMMAND_PLAY_INFO_SIG 0x365
#define FIELD_COMMAND_PLAY_GAYALOOP 0x366
#define FIELD_COMMAND_STOP_GAYALOOP 0x367
#define FIELD_COMMAND_PLAY_WEAR_OFF 0x368
#define FIELD_COMMAND_PLAY_DEMO_BGM 0x369
#define FIELD_COMMAND_PLAY_SE000002 0x36A
#define FIELD_COMMAND_PLAY_BEAM_SHT 0x36B
#define FIELD_COMMAND_PLAY_SWITCH02 0x36C
#define FIELD_COMMAND_PLAY_MASK_SET 0x36D
#define FIELD_COMMAND_PLAY_BM_ERASE 0x36E
#define FIELD_COMMAND_PLAY_LD_ERASE 0x36F
#define FIELD_COMMAND_PLAY_PLAYER11 0x370
#define FIELD_COMMAND_STOP_PLAYER11 0x371
#define FIELD_COMMAND_SHAKE_CAMERA 0x372
#define FIELD_COMMAND_STOP_CAMERA_SHAKE 0x373
#define FIELD_COMMAND_PLAY_TRAP_OFF 0x374
#define FIELD_COMMAND_PLAY_SAVEDEMO 0x375
#define FIELD_COMMAND_SEARCH_EVENT_SPOT 0x376 /* FIELDSTG_searchEventSpot */
#define FIELD_COMMAND_PLAY_SWITCH03 0x377
#define FIELD_COMMAND_PLAY_SN_ENTRY 0x378
#define FIELD_COMMAND_PLAY_SN_ERASE 0x379
#define FIELD_COMMAND_PLAY_TELEPORT 0x37A
#define FIELD_COMMAND_PLAY_BULB_003 0x37C
#define FIELD_COMMAND_PLAY_GONDRA_S 0x37D
#define FIELD_COMMAND_PLAY_PIYOPIYO 0x37E
#define FIELD_COMMAND_PLAY_COMCD103 0x37F
#define FIELD_COMMAND_PLAY_COMCD201 0x380
#define FIELD_COMMAND_PLAY_COMCD111 0x381
#define FIELD_COMMAND_PLAY_BEAM_HIT 0x382
#define FIELD_COMMAND_PLAY_SWITCH01 0x383
#define FIELD_COMMAND_PLAY_COMCD115 0x384
#define FIELD_COMMAND_STOP_COMCD115 0x385
#define FIELD_COMMAND_STOP_BEAM_HIT 0x386

/* Some of FieldMap's maps (files): those of the floors the player walks on
   come first, and GAME.mapIndex picks one (FieldMap.setMap, SLOT_MAP) */
#define FIELD_MAP_FLOOR0 0
#define FIELD_MAP_FLOOR1 1
#define FIELD_MAP_AREAS 4 /* a cell's value: its battle area (FieldBattles), or 0 */
#define FIELD_MAP_TRIGGERS 7 /* a cell's value: a direction (3 bits) and a StageSlot (5) */

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
    /* 0x40 */ void (*setFile)(s32 index, s32 file); /* FIELDSTG_setMapFile */
    /* 0x44 */ s32 (*getCell)(s32 index, struct Point *pos); /* FIELDSTG_getMapCell */
    /* 0x48 */ void (*getWalkStep)(struct Point *pos, s32 scale, s32 dir, struct Point *out); /* FIELDSTG_getWalkStep */
    /* 0x4C */ void (*getFlyStep)(struct Point *pos, s32 scale, s32 dir, struct Point *out); /* FIELDSTG_getFlyStep */
    /* 0x50 */ void (*setFirstMap)(s32 index); /* FIELDSTG_setFirstMap: the map the player starts on
                                                  (GAME.mapIndex), when the mode is new */
    /* 0x54 */ void (*setMap)(s32 index); /* FIELDSTG_setMap: the map the player is on */
    /* 0x58 */ s32 (*isTileFree)(struct Point *pos); /* FIELDSTG_isTileFree: 0 where a character or an object stands */
} FieldMap;

extern FieldMap FIELDSTG_map;

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

/* The characters (Actor.key1, FieldActorEntry.id) that FIELDSTG_updateField
   creates for the party. A field can list one of the player's other
   characters, 1, 0x6A, 0x146 or 0x147, to lead instead, without partners. */
#define FIELD_CHARACTER_PLAYER 2
#define FIELD_CHARACTER_PARTNERS 3 /* + the partner (GAME.funcs.getPartyPartner) */

/* The FLAGS_00 flag that every encounter sets (FIELDSTG_startEncounter);
   until it is set, the stages' slots run an event before the first battle */
#define FIELD_FLAG_ENCOUNTERED 0xF

/* A character of the field (FieldState.actors, a list of pointers up to NULL), which FIELDSTG_updateField creates
   unless its conditions fail; the player's other characters (FIELD_CHARACTER_PLAYER) lead the party instead. */
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
                           the field commands' groups, FIELD_OBJECT_GROUP_ANIM
                           on) and draws 0xFF from its effect sprites */
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

/* The kinds of StageSlot (type). SLOT_DEPTH, SLOT_MAP, SLOT_EVENT, the slides
   and SLOT_LAUNCH act as the player steps on them; the others show a balloon
   and wait for cross, and those up to SLOT_GAUGE only while the player faces
   them (FIELDSTG_findTrigger) */
#define SLOT_EXIT 1 /* leaves for mode unkA at (unkC, unkE), facing unk10 */
#define SLOT_CLIMB_UP 2
#define SLOT_CLIMB_DOWN 3
#define SLOT_DROP 4
#define SLOT_DEPTH 5 /* the player's depth, unkA */
#define SLOT_MAP 6 /* the map the player is on, unkA (FieldMap.setMap) */
#define SLOT_GAUGE 7 /* the gauge game */
#define SLOT_EVENT 8 /* starts the event unkA */
#define SLOT_WARP1 9 /* a warp (FieldWarp at unkA) with effect and cutscene 1 */
#define SLOT_WARP0 10 /* the same with effect and cutscene 0 */
#define SLOT_SLIDE 11
#define SLOT_STOP_SLIDE 12
#define SLOT_LAUNCH 13 /* sends the player flying (FIELDSTG_launchActor) */
#define SLOT_LAUNCH_OUT 14 /* the same, then leaves for mode unkA */

/*
 * What the player can trigger on a map (FIELDSTG_updateTriggers): a record
 * of the table at FieldState.slots, which ends with type 0,
 * where the points are copied to. The stages also fill unkA to unk16 by
 * name (copyPlacePoints, in src/stages/common), so those keep their offsets'
 * names until the stages are renamed with them.
 */
typedef struct StageSlot {
    /* 0x00 */ u16 conditions[2][2]; /* flag code and value, or code 0xFFFF */
    /* 0x08 */ u16 type; /* SLOT_EXIT... */
    /* 0x0A */ u16 unkA; /* by type: a mode, a depth, a map, an event or a height (in 16
                            pixels, plus 1 for a climb); a warp's FieldWarp starts here */
    /* 0x0C */ u16 unkC; /* x */
    /* 0x0E */ u16 unkE; /* y */
    /* 0x10 */ u16 unk10; /* the direction */
    /* 0x12 */ u16 unk12; /* the animation of the map objects to hide, or 0 */
    /* 0x14 */ u16 unk14; /* copied to GAME.place, the place (FieldBattles.id) */
    /* 0x16 */ u16 unk16; /* copied to GAME.placeArg */
} StageSlot;

/* A battle that can start on the field (see FIELDSTG_startEncounter) */
typedef struct Battle {
    /* 0x0 */ s32 encounter; /* of FIELDSTG_encounters */
    /* 0x4 */ s32 stage; /* the fight stage, for BATTLE_SETUP.stage */
    /* 0x8 */ s32 music; /* for BATTLE_SETUP.music */
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
 * (FIELDSTG_startEventBattle5, FIELDSTG_startEventBattle). A stage with several places has a list of
 * them, which FieldState.findBattles searches for the id.
 */
typedef struct FieldBattles {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 id; /* the place, GAME.place */
    /* 0x08 */ s32 unk8;
    /* 0x0C */ BattleList *battles[4];
} FieldBattles;

/*
 * The field's state (FIELDSTG_state): what a stage tells FIELDSTG about itself,
 * filled by its setup function (stageFuncs[0], FIELDSTG_setupField for the
 * field's own), then what FIELDSTG keeps of the field. The first 0x64 bytes
 * are cleared by FIELDSTG_pickStage, which also picks the stage overlay for
 * the current mode.
 *
 * The setup functions set start with a constructor, (Vec2){x, y}: GCC
 * clobbers the whole field before its two stores, which keeps the stores to
 * FIELDSTG_state on either side of it but lets the constants rise above it. The
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

extern FieldState FIELDSTG_state;

/* FIELDSTG functions the stages call */
struct EventTask *FIELDSTG_startEvent(s32 id); /* creates the task of an event object */
StageTile *FIELDSTG_findObject(s32 anim); /* the first map object with that animation */
StageTile *FIELDSTG_findNextObject(void); /* and the next, or NULL */
void *FIELDSTG_startEventBattle5(void); /* starts a battle: the handler of the stages' events 9000 */

/* FIELDSTG's functions and data that the executable calls (game/events.c, system/overlay.c), by
   these names in its link (config/eu/undefined_syms.txt) */
void FIELDSTG_leaveField(s32 mode, s32 arg, s32 x, s32 y, s32 dir); /* leaves the field for a mode */
void FIELDSTG_startListedEvent(s32 index); /* starts the event FIELDSTG_eventIds[index] */
void FIELDSTG_openInn(void); /* opens the inn */
typedef struct FieldBattleFuncs {
    void (*startEventBattle)(s32 index); /* FIELDSTG_startEventBattle */
    void (*startAreaBattle)(void); /* FIELDSTG_startAreaBattle */
} FieldBattleFuncs;
extern FieldBattleFuncs FIELDSTG_battleFuncs;

#endif
