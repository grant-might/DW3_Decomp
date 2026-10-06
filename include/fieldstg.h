#ifndef FIELDSTG_H
#define FIELDSTG_H

/*
 * FIELDSTG.PRO: the field mode, where the player walks around the map.
 *
 * The stage overlays (AAA/PRO/WSTAG###.PRO, see stage.h) load on top of it
 * at 0x800A4CA4 and call into it.
 */

#include "game.h"
#include "field_map.h"

typedef struct Point {
    s32 x;
    s32 y;
} Point;

/* A step of FIELDSTG_playBattleTransition's spiral: one coordinate of a tile moves by dir
 * until it passes limit */
typedef struct TileMove {
    /* 0x0 */ s32 *value;
    /* 0x4 */ s32 dir; /* 1, -1, or 0 at the end */
    /* 0x8 */ s32 limit;
} TileMove;

/*
 * A character on the field (FIELDSTG_createActor): the player (kind 0) and the
 * other characters. Registered with id 5, key1 = character, key2 = kind.
 * x and y are in 1/256 tile units.
 */
typedef struct Actor {
    TASK_HEADER(Actor);
    /* 0x050 */ Vec2 pos;
    /* 0x058 */ Point tile;
    /* 0x060 */ s32 dir;
    /* 0x064 */ s32 z; /* how high it is off the ground, in 1/256 pixels (drawn that much higher) */
    /* 0x068 */ s32 speed; /* 0x400, 0x4CC in PAL's 50 Hz */
    /* 0x06C */ struct ActorImage *image;
    /* 0x070 */ struct FieldImage *fieldImage; /* the field's image, for the shadow */
    /* 0x074 */ s32 hasShadow; /* drawn with a shadow */
    /* 0x078 */ s32 depth; /* the layer's ordering table entry */
    /* 0x07C */ struct FieldActorEntry *entry; /* what created it, or NULL */
    /* 0x080 */ s32 halfWidth; /* half its width (FIELDSTG_actorWidths): its box's half width, and half that its half height */
    /* 0x084 */ s32 flying; /* the flying player (FIELDSTG_controlFlight) */
    /* 0x088 */ struct Actor *talkPartner; /* the actor that talks to it */
    /* 0x08C */ s32 climbSide; /* a climb shifts it a tile right (1) or left (0) */
    /* 0x090 */ s32 climbHeight; /* how high it has climbed, in 1/256 pixels (its shadow stays below) */
    /* 0x094 */ s32 wallHeight; /* the top of the climb */
    /* 0x098 */ s32 unk98;
    /* 0x09C */ s32 animFile; /* its animations' file and index (FIELDSTG_fileEntries), or 0 */
    /* 0x0A0 */ s32 animSet; /* the animation set it plays (setAnim) */
    /* 0x0A4 */ s32 loadedSet; /* the set setAnims was loaded for */
    /* 0x0A8 */ s32 setAnims[5]; /* the set's animations, for the directions 0 to 4 */
    /* 0x0BC */ s32 walks; /* the pad walks it (substate 2) instead of running (3) */
    /* 0x0C0 */ s32 reloadImage; /* set to reload the frame's image */
    /* 0x0C4 */ s32 zSpeed; /* added to z each frame */
    /* 0x0C8 */ s16 voice; /* a sound voice, or -1 */
    /* 0x0CA */ s16 unkCA;
    /* 0x0CC */ s32 animPos; /* the next word of the direction's frames */
    /* 0x0D0 */ s32 animTime; /* the frame's time left */
    /* 0x0D4 */ s32 frame[4]; /* the frame's image, the one loaded, and two values */
    /* 0x0E4 */ s16 frameWidth; /* the loaded image's width in pixels */
    /* 0x0E6 */ s16 frameHeight; /* and its height */
    /* 0x0E8 */ s32 animDone; /* the animation ended (isAnimDone) */
    /* 0x0EC */ s32 walking; /* walking to the goal (setGoal, FIELDSTG_walkToGoal) */
    /* 0x0F0 */ s32 goalX; /* the tile it walks to */
    /* 0x0F4 */ s32 goalY;
    /* 0x0F8 */ s32 goalDir; /* the direction it then faces */
    /* 0x0FC */ s32 talkActions; /* the talk's flag actions (u16 *), applied when it ends */
    /* 0x100 */ s32 isLarge; /* one of the large characters */
    /* 0x104 */ struct Trail *trail; /* a follower's: the leader's steps */
    /* 0x108 */ void (*control)(struct Actor *); /* its update by kind, or NULL (resetControl) */
    /* 0x10C */ s32 unk10C;
    /* 0x110 */ void (*walkInDir)(struct Actor *, s32 dir);
    /* 0x114 */ void (*climbUp)();
    /* 0x118 */ void (*climbDown)();
    /* 0x11C */ void (*dropDown)();
    /* 0x120 */ void (*playGauge)();
    /* 0x124 */ void (*warp)();
    /* 0x128 */ void (*unk128)();
    /* 0x12C */ void (*startWalk)(struct Actor *);
    /* 0x130 */ void (*resetControl)(struct Actor *);
    /* 0x134 */ void (*setDir)(struct Actor *, s32 dir);
    /* 0x138 */ s32 (*isAnimDone)(struct Actor *);
    /* 0x13C */ void (*setGoal)(struct Actor *, s32, s32, s32);
    /* 0x140 */ s32 (*isWalking)(struct Actor *);
    /* 0x144 */ void (*setAnim)(struct Actor *, s32);
    /* 0x148 */ void (*setPose)(struct Actor *, s32, s32 dir);
    /* 0x14C */ void (*getFacingTile)(struct Actor *, Point *out);
    /* 0x150 */ void (*startSlide)(struct Actor *, s32 dir);
    /* 0x154 */ void (*stopSlide)(struct Actor *);
    /* 0x158 */ void (*launch)();
} Actor;

/* The last 64 steps of the actor that another one follows (Actor.trail) */
typedef struct TrailStep {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ s32 dir;
} TrailStep;

typedef struct Trail {
    /* 0x000 */ Actor *leader;
    /* 0x004 */ s32 head;
    /* 0x008 */ s32 tail;
    /* 0x00C */ TrailStep steps[64];
} Trail;

/* A sprite of a StreamTask's frame */
typedef struct StreamSprite {
    /* 0x00 */ s32 visible;
    /* 0x04 */ s32 x;
    /* 0x08 */ s32 y;
    /* 0x0C */ s32 u;
    /* 0x10 */ s32 v;
    /* 0x14 */ s32 w;
    /* 0x18 */ s32 h;
} StreamSprite;

/* A task that reads the frames of a file from the disc (func_80086B54) */
typedef struct StreamTask {
    TASK_HEADER(StreamTask);
    /* 0x050 */ s32 time;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 frame;
    /* 0x05C */ s32 sector;
    /* 0x060 */ s32 file;
    /* 0x064 */ s32 frameSectors;
    /* 0x068 */ void *buffer;
    /* 0x06C */ s32 loaded;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 imageX;
    /* 0x078 */ s32 imageY;
    /* 0x07C */ s32 clutX;
    /* 0x080 */ s32 clutY;
    /* 0x084 */ StreamSprite sprites[3][5];
    /* 0x228 */ s32 slot;
    /* 0x22C */ Decompressor *source; /* what it reads its sprites from (func_80086858) */
    /* 0x230 */ s32 *unk230;
    /* 0x234 */ void (*seek)(struct StreamTask *task, s32 frame, s32 size);
    /* 0x238 */ s32 (*isLoaded)(struct StreamTask *task);
    /* 0x23C */ void (*draw)(struct StreamTask *task, Layer *layer, s32 x, s32 y);
    /* 0x240 */ void (*setSource)(struct StreamTask *task, s32 slot, Decompressor *source);
    /* 0x244 */ s32 (*getFrame)(struct StreamTask *task);
    /* 0x248 */ s32 (*unk248)(struct StreamTask *task);
    /* 0x24C */ void (*unk24C)(struct StreamTask *task);
    /* 0x250 */ void (*updateTime)(struct StreamTask *task);
} StreamTask;

/* The StreamTasks of a task's children (func_80085650) */
typedef struct StreamPool {
    /* 0x00 */ Decompressor *decompressor;
    /* 0x04 */ StreamTask *tasks[30];
} StreamPool;

/* Where a warp leads (FieldTask.unk7C, func_8008B398) */
typedef struct FieldWarp {
    /* 0x0 */ s16 mode;
    /* 0x2 */ s16 x; /* in pixels */
    /* 0x4 */ s16 y;
    /* 0x6 */ s16 dir;
    /* 0x8 */ u8 unk8[2];
    /* 0xA */ u16 unkA; /* copied to GAME.unk44 and unk46 */
    /* 0xC */ u16 unkC;
} FieldWarp;

/* The field's own image (FieldState.images) and its actors' after it */
typedef struct FieldImages {
    /* 0x00 */ FieldImage field;
    /* 0x20 */ ActorImage actors[20];
} FieldImages;

/* The field's main task (func_8008A154, id 7); its children follow */
typedef struct FieldTask {
    TASK_HEADER(FieldTask);
    /* 0x50 */ s32 fade; /* func_80086460's level */
    /* 0x54 */ s32 width; /* of the clip rectangle */
    /* 0x58 */ s32 height;
    /* 0x5C */ s32 nextMode; /* the mode it leaves for (FIELDSTG_leaveFieldAfter) */
    /* 0x60 */ s32 nextModeArg;
    /* 0x64 */ void *unk64; /* a buffer at the end of the heap */
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ Point unk74;
    /* 0x7C */ FieldWarp *unk7C;
} FieldTask;

/* An entry of the script command table FIELDSTG_scriptCommands (ids from 0x320) */
typedef struct ScriptCommand {
    /* 0x0 */ s32 id;
    /* 0x4 */ s32 (*create)(s32 arg);
    /* 0x8 */ void (*handle)(s32 arg0, s32 arg1, s32 arg2);
} ScriptCommand;

/* The name of a mode's area (func_80086D20), up to the first mode 0: the
   strings of the two windows, from text files 0xAA and 0xB8 */
typedef struct AreaName {
    /* 0x0 */ u8 area;
    /* 0x1 */ u8 place;
    /* 0x2 */ s16 mode;
} AreaName;

/* The windows of func_80086D20 */
typedef struct AreaNameWindows {
    /* 0x0 */ TextWindow *area;
    /* 0x4 */ TextWindow *place;
} AreaNameWindows;

/* An entry of the stage tables (FIELDSTG_pickStage): the stage overlay of a mode,
   up to the first mode 0 */
typedef struct StageEntry {
    /* 0x0 */ s32 mode;
    /* 0x4 */ s32 file;
    /* 0x8 */ struct Task *(*init)(void *owner);
} StageEntry;

/* A linear 0-0x1000 tween (func_80091298, func_8009132C) */
typedef struct Tween {
    /* 0x0 */ s32 duration;
    /* 0x4 */ s32 step;
    /* 0x8 */ s32 value;
    /* 0xC */ s32 active;
} Tween;

/* A wait timer for the scripts (func_80091520) */
typedef struct ScriptTimer {
    /* 0x0 */ s32 time;
    /* 0x4 */ s32 active;
    /* 0x8 */ void (*reset)(void);
    /* 0xC */ Actor *(*findActor)(s32 id);
} ScriptTimer;

/* An encounter of FIELDSTG_encounters, which FIELDSTG_startEncounter starts: its enemies and
   the bytes it copies to BATTLE_SETUP.ambushChance on */
typedef struct Encounter {
    /* 0x00 */ BattleEnemy *enemies[3];
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 unkE[12];
    /* 0x1A */ u8 unk1A[2];
} Encounter;

/*
 * An event (FIELDSTG_runEvent, made by FIELDSTG_startEvent): it runs a script
 * of 16-bit words, each command a word of its kind << 8 | its variant followed
 * by its arguments, until a command waits; or, without a script, a task of
 * its own (start) until it ends.
 */
typedef struct EventTask {
    TASK_HEADER(EventTask);
    /* 0x050 */ s32 event; /* its id */
    /* 0x054 */ s16 *pc;
    /* 0x058 */ void *(*start)(void);
    /* 0x05C */ void (*end)(void);
    /* 0x060 */ s32 wait; /* frames left of a wait command */
    /* 0x064 */ struct {
        s32 id; /* 0 ends the list */
        struct Actor *actor;
    } entries[30]; /* the characters, held while the event runs */
} EventTask;

/* The children of an EventTask */
typedef struct EventChildren {
    /* 0x00 */ struct Task *task; /* start's */
    /* 0x04 */ struct Speech *boxes[3]; /* the script's message boxes */
    /* 0x10 */ s32 scripts[10]; /* func_80091730's tasks */
} EventChildren;

/* The children of the field's main task (FieldTask, func_8008A154) */
typedef struct FieldChildren {
    /* 0x00 */ struct FieldEffect *effect; /* FIELDSTG_createEffect's */
    /* 0x04 */ ScreenFade *fade;
    /* 0x08 */ struct CutsceneAnim *cutscene; /* FIELDSTG_createCutsceneAnim's */
    /* 0x0C */ EventTask *event;
    /* 0x10 */ Task *unk10; /* the inn (createInn), or FIELDSTG_createFileLoader's */
    /* 0x14 */ Task *banner; /* FIELDSTG_createBanner's */
    /* 0x18 */ struct Actor *actors[4]; /* the player and the partners */
    /* 0x28 */ struct Camera *camera;
    /* 0x2C */ struct Actor *npcs[15]; /* FieldState.actors's other characters */
    /* 0x68 */ struct Triggers *triggers; /* FIELDSTG_createTriggers's */
    /* 0x6C */ Task *stage; /* FieldState.stageInit's */
    /* 0x70 */ struct MapStreamer *mapStreamer; /* FIELDSTG_createMapStreamer's */
    /* 0x74 */ FieldMenu *menu; /* createFieldMenu's */
    /* 0x78 */ struct MapObjects *mapObjects; /* FIELDSTG_createMapObjects's */
} FieldChildren;

/* A tile of the map that MapStreamer streams */
typedef struct MapTile {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
} MapTile;

/*
 * The task that streams the map's tiles from the CD around the view
 * (FIELDSTG_runMapStreamer, id 4, created by FIELDSTG_createMapStreamer)
 */
typedef struct MapStreamer {
    TASK_HEADER(MapStreamer);
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 *unk54;
    /* 0x058 */ Point scroll;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 file; /* the map's tiles, read from the CD (FieldState.mapFile) */
    /* 0x068 */ s32 width; /* in 128-pixel tiles */
    /* 0x06C */ s32 height;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
    } unk74[12];
    /* 0x104 */ MapTile *unk104;
    /* 0x108 */ u8 unk108[30]; /* by the slots around the view, their tiles */
    /* 0x126 */ u8 unk126[2];
    /* 0x128 */ s32 unk128; /* the tile column of the slots' left edge */
    /* 0x12C */ s32 unk12C; /* their top row */
    /* 0x130 */ Point *(*getSize)(struct MapStreamer *); /* in pixels (FIELDSTG_getMapSize) */
} MapStreamer;

/* A cutscene's animation over the field (FIELDSTG_createCutsceneAnim) */
typedef struct CutsceneAnim {
    TASK_HEADER(CutsceneAnim);
    /* 0x50 */ s32 kind; /* 0: file 0x88C (0x87B in the USA), 1: file 0x88D (0x87C) */
    /* 0x54 */ s32 frame;
    /* 0x58 */ s32 index; /* into the animation */
    /* 0x5C */ s32 timer;
    /* 0x60 */ s32 frame2; /* kind 1's second animation */
    /* 0x64 */ s32 index2;
    /* 0x68 */ s32 timer2;
} CutsceneAnim;

/* An animation of an FieldEffect (FIELDSTG_stepEffectAnim) */
typedef struct EffectAnim {
    /* 0x0 */ s32 active;
    /* 0x4 */ AnimState anim;
} EffectAnim;

/* An effect of up to four animations at a spot (FIELDSTG_createEffect) */
typedef struct FieldEffect {
    TASK_HEADER(FieldEffect);
    /* 0x50 */ s32 x;
    /* 0x54 */ s32 y;
    /* 0x58 */ s16 set; /* the row of FIELDSTG_effectAnims */
    /* 0x5A */ u8 unk5A[2];
    /* 0x5C */ EffectAnim anims[4];
} FieldEffect;

/* The field's effect sprites (FIELDSTG_drawSpotEffect): the discs number their files
   differently */
#if VERSION_US
#define FIELD_SPRITES_FILE 0x152
#elif VERSION_EU
#define FIELD_SPRITES_FILE 0x160
#endif

/* The files of the exits' effects (FIELDSTG_requestSlotFiles): the discs number their
   files differently */
#if VERSION_US
#define FIELD_EXIT_FILES 0x3B9
#elif VERSION_EU
#define FIELD_EXIT_FILES 0x3C9
#endif

/* The two animations of FIELDSTG_playCutsceneAnim, kind 0's file and kind 1's after it:
   the discs number their files differently */
#if VERSION_US
#define FIELD_ANIM_FILE 0x87B
#elif VERSION_EU
#define FIELD_ANIM_FILE 0x88C
#endif

/* The map's triggers (FIELDSTG_createTriggers): on a trigger's cell (layer
   7: index and direction) the player sets it off at once or, with a balloon,
   on the action button */
typedef struct Triggers {
    TASK_HEADER(Triggers);
    /* 0x50 */ s32 unk50;
    /* 0x54 */ StageSlot *entries; /* FieldState.slots */
    /* 0x58 */ Actor *actor; /* the player */
    /* 0x5C */ s32 index; /* the trigger under it */
    /* 0x60 */ s32 dir; /* the trigger's direction */
    /* 0x64 */ StageSlot *entry;
} Triggers;

/* The children of an Triggers */
typedef struct TriggerChildren {
    /* 0x0 */ struct Balloon *balloon;
    /* 0x4 */ EventTask *script;
} TriggerChildren;

/* A rectangle, edges included */
typedef struct Box {
    /* 0x0 */ s32 left;
    /* 0x4 */ s32 right;
    /* 0x8 */ s32 top;
    /* 0xC */ s32 bottom;
} Box;

/* Animates and draws the map's objects (FIELDSTG_createMapObjects) */
typedef struct MapObjects {
    TASK_HEADER(MapObjects);
    /* 0x50 */ s32 sprites; /* their sprite file and entry */
    /* 0x54 */ struct StageTile *objects;
} MapObjects;

/* The player's icon (id 0x16, FIELDSTG_createActorIcon): the event commands and a
   special condition set its substate, the animation it plays */
typedef struct ActorIcon {
    TASK_HEADER(ActorIcon);
    /* 0x50 */ Actor *actor;
    /* 0x54 */ s32 frame;
    /* 0x58 */ s32 animStep;
    /* 0x5C */ s32 animTime;
    /* 0x60 */ u8 (*anim)[2]; /* (frame, time) pairs; 0xFF loops to a step */
} ActorIcon;

/* A balloon over an actor's head (FIELDSTG_createBalloon): it pops up, plays its
   FIELDSTG_triggerAnims row (key2) and pops down when closed */
typedef struct Balloon {
    TASK_HEADER(Balloon);
    /* 0x50 */ Actor *actor; /* the player when NULL */
    /* 0x54 */ s32 popStart; /* the pop-up's sprites, times 4: it opens from here */
    /* 0x58 */ s32 popOpen; /* to here */
    /* 0x5C */ s32 popEnd; /* and closes to here */
    /* 0x60 */ s32 pop; /* the pop-up's sprite, times 4 */
    /* 0x64 */ s32 frame; /* into its FIELDSTG_triggerAnims row */
    /* 0x68 */ s32 time;
} Balloon;

/* A message box, or a talk box that follows an actor (FIELDSTG_createSpeech,
   FIELDSTG_createTalk) */
typedef struct Speech {
    TASK_HEADER(Speech);
    /* 0x50 */ Actor *actor;
    /* 0x54 */ s32 entry; /* the text's entry */
    /* 0x58 */ s32 type; /* the talk box's (createTalkBox), its corner */
    /* 0x5C */ s32 isMessage; /* a message box */
    /* 0x60 */ s32 text; /* FILE_CACHE.getEntry */
} Speech;

/* The children of an actor (FIELDSTG_updateActor) */
typedef struct ActorChildren {
    /* 0x0 */ ActorIcon *icon; /* FIELDSTG_createActorIcon's */
    /* 0x4 */ Balloon *balloon; /* FIELDSTG_createBalloon's */
    /* 0x8 */ void *action; /* a gauge game or a launch */
    /* 0xC */ Speech *speech; /* FIELDSTG_createTalk's */
} ActorChildren;

/* Launches an actor, spinning, from the nearest launcher (a task with id
   0x17) to a tile (FIELDSTG_createLaunch, Actor.launch) */
typedef struct Launch {
    TASK_HEADER(Launch);
    /* 0x50 */ Actor *actor;
    /* 0x54 */ s16 *dest; /* the tile it lands on, at [1] and [2] */
    /* 0x58 */ Task *from; /* the nearest task with id 0x17 */
    /* 0x5C */ Point start;
    /* 0x64 */ Point dist;
    /* 0x6C */ s32 negX;
    /* 0x70 */ s32 negY;
} Launch;

/* The hint of a hidden spot that held nothing (FIELDSTG_createSpotHint): its sprite
   and its palette cycle tell how far the prize is */
typedef struct SpotHint {
    TASK_HEADER(SpotHint);
    /* 0x50 */ s32 time;
    /* 0x54 */ s32 speed; /* frames per palette step */
    /* 0x58 */ s32 frame;
    /* 0x5C */ Point from;
    /* 0x64 */ Point to;
} SpotHint;

/* A hidden spot: a map object with anim 0xFF */
typedef struct HiddenSpot {
    /* 0x00 */ s32 frame; /* its object's */
    /* 0x04 */ s32 object; /* its index in FieldState.objects */
    /* 0x08 */ Point pos;
    /* 0x10 */ s32 hasPrize; /* the one picked at random (GAME.unk26E4) */
} HiddenSpot;

/* The map's hidden spots (id 0xB, FIELDSTG_createHiddenSpots): one of them, picked at
   random, holds the prize */
typedef struct HiddenSpots {
    TASK_HEADER(HiddenSpots);
    /* 0x50 */ s32 count;
    /* 0x54 */ HiddenSpot *entries;
    /* 0x58 */ s32 selected; /* the spot searched */
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ Point pos; /* the prize's */
} HiddenSpots;

/* The children of an HiddenSpots */
typedef struct HiddenSpotsChildren {
    /* 0x0 */ struct SpotEffect *effect;
    /* 0x4 */ struct SpotHint *hint;
} HiddenSpotsChildren;

/* The effect of searching a hidden spot, in front of the actor that searches
   (FIELDSTG_createSpotEffect) */
typedef struct SpotEffect {
    TASK_HEADER(SpotEffect);
    /* 0x50 */ s32 x;
    /* 0x54 */ s32 y;
    /* 0x58 */ s32 dir;
    /* 0x5C */ s32 frame;
    /* 0x60 */ u8 *anim;
} SpotEffect;

/* A gauge game (FIELDSTG_createGauge) */
typedef struct GaugeGame {
    TASK_HEADER(GaugeGame);
    /* 0x50 */ Point pos;
    /* 0x58 */ s32 row; /* of FIELDSTG_gaugeRows */
    /* 0x5C */ s32 cursor; /* along the row, 0-0x3000 */
    /* 0x60 */ s32 speed;
    /* 0x64 */ s32 back; /* the cursor goes back */
} GaugeGame;

/* The camera (id 0x10, FIELDSTG_createCamera): it centers the field's layer
   on an actor or a spot, panning there unless it snaps, and shakes */
typedef struct Camera {
    TASK_HEADER(Camera);
    /* 0x50 */ Actor *target; /* the actor it follows (substate 0) */
    /* 0x54 */ Point center; /* where it looks */
    /* 0x5C */ s32 shaking;
    /* 0x60 */ s32 shake; /* the step of the shake, 0-3 */
    /* 0x64 */ s16 voice; /* of the shaking sound, or -1 */
    /* 0x66 */ u8 unk66[2];
    /* 0x68 */ Point pan; /* where it looks while it pans to center */
    /* 0x70 */ s32 hasBounds;
    /* 0x74 */ Point bounds; /* the map's size */
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ s32 snap; /* goes to center at once instead of panning */
    /* 0x84 */ s32 targetId; /* the target's character (Actor.key1) */
    /* 0x88 */ s32 spotX; /* the spot it looks at (substate 1) */
    /* 0x8C */ s32 spotY;
} Camera;

/* A lift of the map objects 2 and 3 (FIELDSTG_createLift) */
typedef struct Lift {
    TASK_HEADER(Lift);
    /* 0x50 */ struct StageTile *left; /* the map object 3 */
    /* 0x54 */ struct StageTile *right; /* the map object 2 */
    /* 0x58 */ s16 raised; /* the objects and the player are 0x7F lower */
    /* 0x5A */ s16 time;
    /* 0x5C */ s16 shake; /* the index into FIELDSTG_liftShake */
    /* 0x5E */ s16 unk5E;
    /* 0x60 */ s16 leftY; /* the positions when the move started */
    /* 0x62 */ s16 rightY;
    /* 0x64 */ s32 playerY;
    /* 0x68 */ s16 leftBaseY; /* the objects' positions on the map */
    /* 0x6A */ s16 rightBaseY;
} Lift;

/* The story events of the field (FIELDSTG_createStoryEvents) */
typedef struct StoryEvents {
    TASK_HEADER(StoryEvents);
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 script; /* the script to run next, or 0 */
} StoryEvents;

typedef struct StoryEventsChildren {
    /* 0x0 */ Lift *lift;
    /* 0x4 */ EventTask *script;
} StoryEventsChildren;

/* A story event (FIELDSTG_progressEvents): at a progress, while a flag is clear and a
   condition holds, a script runs, and then another one */
typedef struct ProgressEvent {
    /* 0x0 */ s32 progress; /* -1 ends the list */
    /* 0x4 */ s32 flag;
    /* 0x8 */ s32 condition;
    /* 0xC */ s16 script;
    /* 0xE */ s16 nextScript;
} ProgressEvent;

/* A rectangle of an AreaBanner, which can stretch to a new range */
typedef struct BannerBox {
    /* 0x00 */ s32 visible;
    /* 0x04 */ DVECTOR pos;
    /* 0x08 */ DVECTOR size;
    /* 0x0C */ s32 color;
    /* 0x10 */ s32 stretch; /* 1: horizontally, 2: vertically */
    /* 0x14 */ s32 from;
    /* 0x18 */ s32 to;
    /* 0x1C */ s32 speed;
    /* 0x20 */ s32 unk20;
} BannerBox;

/* The area name banner (id 9, FIELDSTG_createBanner) */
typedef struct AreaBanner {
    TASK_HEADER(AreaBanner);
    /* 0x050 */ BannerBox boxes[10];
    /* 0x1B8 */ RECT clip; /* the layer's, closing on state 2 */
} AreaBanner;

/* A yes/no question of the story (FIELDSTG_runChoice) */
typedef struct ChoiceTask {
    TASK_HEADER(ChoiceTask);
    /* 0x50 */ s32 type; /* FIELDSTG_choices's */
    /* 0x54 */ s32 selection;
    /* 0x58 */ Tween tween; /* the panel's width */
} ChoiceTask;

typedef struct ChoiceChildren {
    /* 0x00 */ TextWindow *title;
    /* 0x04 */ TextWindow *options[2];
    /* 0x0C */ Cursor *cursor;
    /* 0x10 */ EventTask *event;
} ChoiceChildren;

/* A question of a ChoiceTask */
typedef struct ChoiceText {
    /* 0x0 */ s32 text; /* the file counted from TEXT_FILE(1) << 16 | its
                           entry: the question, then the answers */
    /* 0x4 */ s16 events[2]; /* FIELDSTG_startEvent's, for each answer */
} ChoiceText;

void func_80082F1C(Task *task);
void FIELDSTG_runChoice();
void func_80086C4C(Task *task, Task **children);
Task *func_8008ADE8(void);
void func_8008A154();
void FIELDSTG_leaveFieldAfter(s32 mode, s32 arg, s32 x, s32 y, s32 dir, s32 delay);
void FIELDSTG_updateBalloon(Balloon *task);
void FIELDSTG_controlPlayer(Actor *);
void FIELDSTG_walkToGoal(Actor *);
Balloon *FIELDSTG_createBalloon(s32 kind, s32 anim, s32 id);
void FIELDSTG_haltPartners(void);
void FIELDSTG_resumePartners(void);
Actor *FIELDSTG_findActor(s32 id);
void FIELDSTG_setActorAnim(Actor *actor, s32 arg1);
void FIELDSTG_followLeader(Actor *);
void FIELDSTG_startEncounter(s32);
void FIELDSTG_runEvent(EventTask *task, EventChildren *children);
void FIELDSTG_drainTrail(Actor *);
s32 FIELDSTG_loadFieldFiles(Task *);
Launch *FIELDSTG_createLaunch(Actor *actor, s32 dest);
void func_8008B398(s32 arg0, Point *pos, FieldWarp *arg2);
ScriptCommand *func_800916E8(s32 id);
Task *FIELDSTG_createFileLoader(s32 arg0);
Task *FIELDSTG_createBanner(s32 arg0);
struct Actor *FIELDSTG_createActor(s32 id, s32 arg1, s32 arg2, FieldActorEntry *entry);
void FIELDSTG_playBattleTransition(FieldTask *task, FieldChildren *children);
MapObjects *FIELDSTG_createMapObjects(s32 sprites, StageTile *objects);
Triggers *FIELDSTG_createTriggers(s32 arg0, void *entries);
MapStreamer *FIELDSTG_createMapStreamer(s32 file);
FieldEffect *FIELDSTG_createEffect(s32 x, s32 y, s32 set);
CutsceneAnim *FIELDSTG_createCutsceneAnim(s32 kind);
Camera *FIELDSTG_createCamera(void);
Point *FIELDSTG_getMapSize(MapStreamer *);
void func_800868AC(StreamTask *task);
StreamTask *func_80086B54(s32 size, s32 file);
void func_80085EEC(MapStreamer *task);
void func_80085A78(MapStreamer *task, StreamPool *pool);
void func_80085650(MapStreamer *task, StreamPool *pool);
void func_80086D20(Task *task, AreaNameWindows *windows);
struct Speech *FIELDSTG_createSpeech(Actor *actor, s32 entry, s32 type, s32 isMessage);
void FIELDSTG_followWithCamera(s32 snap, s32 id);
void func_8008C23C(void);
void FIELDSTG_shakeCamera(s32 shaking);
void FIELDSTG_pointCamera(s32 snap, s32 x, s32 y);
StreamTask *func_800855E0(StreamPool *pool);
void func_800857DC(Layer *layer, s32 x, s32 y, s32 level);
void func_80086460(s32 id, s32 level);
void FIELDSTG_updateSpeech(Speech *task, void **box);
void FIELDSTG_runLaunch(Launch *task);
void FIELDSTG_moveByPad(Actor *actor, s32 pad);
Actor *FIELDSTG_findActorAt(Point *pos);
void FIELDSTG_updateHiddenSpots(HiddenSpots *task, HiddenSpotsChildren *children);
void FIELDSTG_drawActor(void *arg, void *arg2);
void FIELDSTG_animateActor(Actor *actor);
void FIELDSTG_controlFlight(Actor *actor);
struct HiddenSpots *FIELDSTG_createHiddenSpots(s32 count);
void FIELDSTG_runActorAction(Actor *actor, struct ActorChildren *children);
void FIELDSTG_hidePrize(HiddenSpots *task);
s32 func_8008D0C0(Actor *actor, s32 x, s32 y, Point offset);
s32 func_80091730(s32 id);
void func_80091774(s32 arg0, s32 id, s32 arg2, s32 arg3);
GaugeGame *FIELDSTG_createGauge(Point pos);
s32 FIELDSTG_stepEffectAnim(EffectAnim *anim, AnimFrame *frames, s32 depth);
void func_800865AC(StreamTask *task, Layer *layer, s32 x, s32 y);
void FIELDSTG_playCutsceneAnim();
void FIELDSTG_updateTriggers(Triggers *task, TriggerChildren *children);
s32 FIELDSTG_offerTrigger(Triggers *task, TriggerChildren *children);
void FIELDSTG_setOffTrigger(Triggers *task);
void FIELDSTG_runFileLoader();
void FIELDSTG_updateSpotEffect();
void FIELDSTG_updateCamera(Camera *task);
void FIELDSTG_runGauge(GaugeGame *task);
void FIELDSTG_runMapStreamer();
void FIELDSTG_updateBanner();
void FIELDSTG_updateMapObjects();
void FIELDSTG_updateEffect();
void FIELDSTG_updateActorIcon(ActorIcon *task);
void FIELDSTG_runStoryEvents(StoryEvents *task, StoryEventsChildren *children);
void FIELDSTG_showSpotHint(SpotHint *task);
void FIELDSTG_scrollCamera(Camera *task);
void FIELDSTG_updateLift();

s32 func_80091AA8(s32 index);
s32 func_80091BC0(s32, Point *);
SpotHint *FIELDSTG_createSpotHint(Point from, Point to);
SpotEffect *FIELDSTG_createSpotEffect(s32 arg0);

/* FIELDSTG's data (fieldstg.c), in its order */
extern Encounter FIELDSTG_encounters[];
extern s16 FIELDSTG_liftShake[]; /* FIELDSTG_updateLift's shakes, up to 1000 */
extern ChoiceText FIELDSTG_choices[16];
extern ProgressEvent FIELDSTG_progressEvents[];
extern AnimFrame FIELDSTG_cutsceneAnim[]; /* FIELDSTG_playCutsceneAnim's animations: kind 0's, */
extern AnimFrame FIELDSTG_cutsceneLoopAnim[]; /* and kind 1's two */
extern AnimFrame FIELDSTG_cutsceneLoopAnim2[];
extern AnimFrame *FIELDSTG_effectAnims[][4]; /* FIELDSTG_updateEffect's animations of each set */
extern u8 FIELDSTG_slotLayouts[][4][5][6]; /* func_80085EEC's slot layouts: [layout][quadrant][row][column] */
extern u8 FIELDSTG_dirLayouts[][2]; /* the layout and its flips for each direction */
extern u8 FIELDSTG_slotOffsets[][2][2]; /* the slots' offset in tiles: [quadrant][x, y][unflipped, flipped] */
extern s32 FIELDSTG_spriteDepths[]; /* depth of each layer of a StreamTask's sprites */
extern Point FIELDSTG_slotImages[]; /* VRAM position of each StreamTask slot's image */
extern AreaName FIELDSTG_areaNames[];
extern BannerBox FIELDSTG_bannerBoxes[10]; /* FIELDSTG_updateBanner's boxes */
extern u8 FIELDSTG_triggerAnims[][9]; /* FIELDSTG_stepBalloonAnim's animations: (frame, time) pairs up to 0xFF */
extern u8 FIELDSTG_nearDirs[][8]; /* whether two directions are at most 45 degrees apart */
extern s16 FIELDSTG_file5DModes[]; /* the modes that load the field file 0x5D (FIELDSTG_requestInnNames) */
extern u8 (*FIELDSTG_actorAnims[])[2]; /* FIELDSTG_updateActorIcon's animation of each substate */
extern s16 FIELDSTG_actorPath[][2]; /* offsets, up to (0, 0) */
extern s32 FIELDSTG_actorPathStep; /* the step in FIELDSTG_actorPath */
extern TileMove FIELDSTG_tileMoves[];
extern s16 FIELDSTG_eventIds[]; /* the events func_8008B2C4 starts */
extern u8 FIELDSTG_spotAnim[][2]; /* animation of FIELDSTG_updateHiddenSpots: (frame, time) pairs up to 0xFF */
extern u8 *FIELDSTG_dirAnims[]; /* FIELDSTG_updateSpotEffect's animation for each direction */
extern s32 FIELDSTG_dirDepths[]; /* and its depth offset */
extern u8 *FIELDSTG_gaugeRows[];
extern Point FIELDSTG_shakeOffsets[]; /* the camera's shake offsets */
extern u8 FIELDSTG_probes[][5]; /* the probes of each direction (func_8008D2A0) */
extern Point FIELDSTG_probePos[]; /* a probe's position */
extern u8 FIELDSTG_probeSteps[][2]; /* a probe's offset: bit 0 set, bit 7 negative */
extern s32 FIELDSTG_padDirs[]; /* the direction of each combination of the pad directions */
extern s16 FIELDSTG_standIns[][2]; /* the actors that stand for other actors: {key, key of the actor that answers} */
/* the partners' kinds (Actor.key2): the ones FIELDSTG_startActorGauge turns, FIELDSTG_haltPartners
   stops and FIELDSTG_resumePartners makes follow again */
extern s32 FIELDSTG_turnedPartners[];
extern s32 FIELDSTG_haltedPartners[];
extern s32 FIELDSTG_followingPartners[];
extern Point FIELDSTG_dirSteps[]; /* tile offset of each direction */
/* the field's own stage (FIELDSTG_setupField) */
extern FieldImages FIELDSTG_images;
extern FieldActorEntry *FIELDSTG_actorList[];
extern StageTile FIELDSTG_mapObjects[];
extern StageSlot FIELDSTG_slots[];
extern void (*FIELDSTG_initFuncs[])(void);
extern void (*FIELDSTG_tweenStart)(Tween *tween, s32 in); /* func_80091298 */
extern s32 (*FIELDSTG_tweenUpdate)(Tween *tween); /* func_8009132C */
extern FieldEvent FIELDSTG_events[];
extern s32 FIELDSTG_fileEntries[]; /* by character (Actor.key1) */
extern u8 FIELDSTG_actorWidths[]; /* by character, in pixels (FieldState.getActorWidth) */
extern StageEntry FIELDSTG_stages[];
#if VERSION_EU
extern StageEntry FIELDSTG_euStages[]; /* the European version's, but at progress 0x2D */
#endif
extern ScriptTimer FIELDSTG_scriptTimer;
extern void (*FIELDSTG_scriptHelpers[])(); /* the script helpers (func_80091648...) */
extern ScriptCommand FIELDSTG_scriptCommands[];
extern void (*FIELDSTG_checkBattle)(); /* func_80091910 */
extern s32 FIELDSTG_battleRates[]; /* how much each area lowers GAME.unk30, the steps to the next battle */
extern s32 FIELDSTG_boxFrame; /* the frame FIELDSTG_boxes was filled in */
extern Point FIELDSTG_dirVectors[][8]; /* a direction's vector, scaled by 4096 */
extern u8 FIELDSTG_mirrorDirs[];
extern s16 FIELDSTG_heldVoice; /* the voice of func_80082F84's held sound */
extern Point FIELDSTG_mapSize; /* FIELDSTG_getMapSize's */
extern StageTile *FIELDSTG_objectCursor; /* FIELDSTG_findNextObject's search of the map objects */
extern s32 FIELDSTG_objectId; /* and the id it looks for */
extern Point FIELDSTG_tiles[5][6]; /* FIELDSTG_playBattleTransition's 64x40 tiles of the screen */
extern s32 FIELDSTG_tileRequests; /* FIELDSTG_playBattleTransition's file requests, 0 to 2 */
extern RECT FIELDSTG_screenRect;
extern Box FIELDSTG_boxes[20]; /* the characters' boxes (FIELDSTG_isTileFree) */
extern s32 FIELDSTG_boxCount; /* and their number */

/* The functions FIELDSTG's tables (fieldstg.c) point to */
void FIELDSTG_setupField(void);
void func_80091910(void);
s32 FIELDSTG_isTileFree(Point *pos);
void FIELDSTG_askChoice0(void), FIELDSTG_askChoice1(void), FIELDSTG_askChoice2(void), FIELDSTG_askChoice3(void);
void FIELDSTG_askChoice4(void), FIELDSTG_askChoice5(void), FIELDSTG_askChoice6(void), FIELDSTG_askChoice7(void);
void FIELDSTG_askChoice8(void), FIELDSTG_askChoice9(void), FIELDSTG_askChoice10(void), FIELDSTG_askChoice11(void);
void FIELDSTG_askChoice12(void), FIELDSTG_askChoice13(void), FIELDSTG_askChoice14(void), FIELDSTG_askChoice15(void);
void func_80090864(void), func_800908C4(void), func_800908F0(void), func_80090950(void);
void func_8009097C(void), func_800909DC(void), func_80090A08(void), func_80090A68(void);
void func_80090A94(void), func_80090AF4(void), func_80090B20(void), func_80090B80(void);
void func_80090BAC(void), func_80090C0C(void), func_80090C38(void), func_80090C98(void);
void func_80090CC4(void), func_80090D24(void), func_80090D50(void), func_80090DB0(void);
void func_80090DDC(void), func_80090E3C(void), func_80090E68(void), func_80090EC8(void);
void func_80090EF4(void), func_80090F54(void), func_80090F80(void), func_80090FE0(void);
void func_8009100C(void), func_8009106C(void), func_80091098(void), func_800910F8(void);
void FIELDSTG_pickStage(void), func_800914C0(void), func_800916B4(void), func_800917D8(void);
void FIELDSTG_startAreaBattle(void);
void FIELDSTG_moveLift(Lift *task, s32 arg1);
Lift *FIELDSTG_createLift(s32 id);
StoryEvents *FIELDSTG_createStoryEvents(s32 arg0);
void FIELDSTG_createPlayerBalloon(s32 id);
void FIELDSTG_balloonCommand(Balloon *task, s32 command, s32 id);
void func_80091298(Tween *tween, s32 in);
s32 func_8009132C(Tween *tween);
s32 FIELDSTG_getFileEntry(s32 index);
s32 FIELDSTG_getActorWidth(s32 index);
FieldBattles *FIELDSTG_findBattles(FieldBattles *list, s32 id);
void func_80091520(s32 time, s32 *pc);
void func_800915B0(s32 id, s32 *pc);
void func_800915FC(s32 id, s32 *pc);
void func_80091648(Point *pos);
void FIELDSTG_startEventBattle(s32 index);
void func_80091B78(s32 index, s32 value);
void func_80091B90(s32 arg0);
void func_80091BB4(s32 arg0);
void func_80091F4C(Point *pos, s32 scale, s32 index, Point *out);
void func_8009204C(Point *pos, s32 scale, s32 index, Point *out);

#endif /* FIELDSTG_H */
