#ifndef FIGHTSTG_H
#define FIGHTSTG_H

/* FIGHTSTG.PRO: the battle. It loads WFIGHTMN (file 0x1FA) for a normal
   battle, or WFIGHTTS (file 0x1FB) for the battle test, at STAGE_VRAM. */

#include "game.h"
#include <libgs.h>
#include "dw3/menus.h"
#include "dw3/files.h"

extern MATRIX IDENTITY_MATRIX; /* the root bone's parent (src/main/data/matrices.c) */

/* The sub-overlays (FIGHTSTG_updateRoot) and their entry points */
#if VERSION_US
#define FILE_WFIGHTMN 0x1FA
#define FILE_WFIGHTTS 0x1FB
#elif VERSION_EU
#define FILE_WFIGHTMN 0x208
#define FILE_WFIGHTTS 0x209
#endif
Task *WFIGHTMN_start(void);
Task *WFIGHTTS_start(void);
/* WFIGHTMN's functions FIGHTSTG calls */
struct BattleScript *WFIGHTMN_startTech(u8 actor, s32 id);
void WFIGHTMN_checkEquip(s32 fighter);
void WFIGHTMN_chargeGauge(u8 side, s32 damage);
s32 WFIGHTMN_setIdleMotion(u8 id, s32 damage);
void WFIGHTMN_countHit(u8 side, s32 damage);
void WFIGHTMN_endWeakness(u8 side);
s32 WFIGHTMN_limitDamage(u8 side, s32 damage, s32 hits);

/* The ids that the battle's tasks register with, for the others to find them
   (TASK_REGISTRY.funcs.find) */
#define BATTLE_TASK_MENU 0xC /* WFIGHTMN's battle menu */
#define BATTLE_TASK_PLAYER_TURN 0xE
#define BATTLE_TASK_MODEL 0x11 /* a model (FIGHTSTG_updateModel) */
#define BATTLE_TASK_CAMERA 0x12
#define BATTLE_TASK_LIGHTS 0x13
#define BATTLE_TASK_MODELS 0x14 /* the fighters' */
#define BATTLE_TASK_STAGE 0x15

/* The images of a Digimon's change (FIGHTSTG_updateDigimonChange): entry 5 */
#if VERSION_EU
#define FILE_CHANGE 0x8A2
#elif VERSION_US
#define FILE_CHANGE 0x891
#endif

/* What fighter 0x1D2's entrance (FIGHTSTG_updateEntrance) loads */
#if VERSION_EU
#define FILE_ENTRANCE_1D2 0x6E2
#elif VERSION_US
#define FILE_ENTRANCE_1D2 0x6D3
#endif

/* Draws one bone of a Model (FIGHTSTG_createMesh), from the parts of an archive */
typedef struct Mesh {
    TASK_HEADER(Mesh);
    /* 0x50 */ s32 noBoundsCheck;
    /* 0x54 */ s32 colorMode; /* Model.setColor's */
    /* 0x58 */ CVECTOR color;
    /* 0x5C */ s32 archive;
    /* 0x60 */ u8 *vertices; /* a count, then ShortVec3s */
    /* 0x64 */ u8 *normals; /* a count, then ShortVec3s */
    /* 0x68 */ u8 *commands; /* see MeshDrawState */
    /* 0x6C */ u8 *bounds; /* 9 ShortVec3 points (FIGHTSTG_isMeshOnScreen) */
    /* 0x70 */ Vec2 texPos;
    /* 0x78 */ s32 *screen; /* where its vertices land on screen */
    /* 0x7C */ s32 *depth; /* and their depths in the ordering table */
    /* 0x80 */ CVECTOR *colors; /* its normals' colors under the lights */
    /* 0x84 */ MATRIX matrix;
    /* 0xA4 */ void (*draw)(struct Mesh *mesh, s32 layerId, MATRIX *matrix);
    /* 0xA8 */ void (*drawAlt)(struct Mesh *mesh, s32 layerId, MATRIX *matrix);
} Mesh;

/* A Mesh's drawing state while its drawer (FIGHTSTG_drawMesh) walks its command
   bytes: a high nibble of 8 to 14 sets one of the flags, a low nibble of 1
   the texture page and CLUT, 2 to 5 one of the flat colors, and 0 starts a
   run of polygons, each a 0 byte then its vertices' indices, its normals'
   indices when lit and its UVs when textured. 0xFF ends the commands. */
typedef struct MeshDrawState {
    /* 0x00 */ s32 textured;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 quad;
    /* 0x10 */ s32 lit;
    /* 0x14 */ s32 gouraud;
    /* 0x18 */ s32 abr; /* the semi-transparency mode + 1, 0 for opaque */
    /* 0x1C */ u8 *cmd;
    /* 0x20 */ s32 *screen;
    /* 0x24 */ s32 *depth;
    /* 0x28 */ u_long *otBase;
    /* 0x2C */ CVECTOR *normalColors;
    /* 0x30 */ Vec2 texPos;
    /* 0x38 */ s32 u;
    /* 0x3C */ s32 v;
    /* 0x40 */ u16 tpage;
    /* 0x42 */ u16 clut;
    /* 0x44 */ CVECTOR color[4];
    /* 0x54 */ union {
        void *ptr;
        POLY_FT3 *ft3;
        POLY_FT4 *ft4;
        POLY_GT3 *gt3;
        POLY_GT4 *gt4;
        LINE_F2 *lineF2;
        LINE_F4 *lineF4;
    } prim;
    /* 0x58 */ s32 sxy[4]; /* the polygon's screen points */
    /* 0x68 */ u_long *ot;
    /* 0x6C */ u8 uv[4][2];
    /* 0x74 */ CVECTOR colors[4]; /* the polygon's vertex colors */
    /* 0x84 */ s32 unk84;
} MeshDrawState;

/* One part of a Model: a mesh (Mesh) placed by a matrix relative to its
   parent's */
typedef struct ModelBone {
    /* 0x00 */ s32 parent;
    /* 0x04 */ s32 file; /* the mesh's file and index */
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 visible; /* 0 while its scale is tiny */
    /* 0x10 */ SVECTOR pos;
    /* 0x18 */ SVECTOR rot;
    /* 0x20 */ SVECTOR scale;
    /* 0x28 */ MATRIX local;
    /* 0x48 */ MATRIX *parentMatrix;
    /* 0x4C */ MATRIX world;
    /* 0x6C */ SVECTOR prevPos; /* the pose the motion blends from */
    /* 0x74 */ SVECTOR prevRot;
    /* 0x7C */ SVECTOR prevScale;
} ModelBone;

/* A position or rotation, without the SVECTOR pad */
typedef struct ShortVec3 {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} ShortVec3;

/* What drives a Model, owned by whoever created it */
typedef struct ModelControl {
    /* 0x00 */ s32 active; /* in the Models task's list */
    /* 0x04 */ s32 id; /* the Models task's */
    /* 0x08 */ s32 motion; /* the motion to play */
    /* 0x0C */ s32 restart; /* play it again from the start */
    /* 0x10 */ s32 motionDone;
    /* 0x14 */ s32 fighter; /* the Models task's */
    /* 0x18 */ s32 idleMotion;
    /* 0x1C */ ShortVec3 pos;
    /* 0x22 */ ShortVec3 rot;
    /* 0x28 */ ShortVec3 homePos;
    /* 0x2E */ ShortVec3 homeRot;
    /* 0x34 */ struct {
        s32 enabled;
        s32 arg;
        s32 alt;
    } unk34[2];
} ModelControl;

/* A motion in the motions' archive: its keyframes, step by step */
typedef struct MotionStep {
    /* 0x0 */ s16 index; /* 0x7FFF ends them */
    /* 0x2 */ s16 count; /* frames, 0 for the last one */
    /* 0x4 */ s16 frame;
    /* 0x6 */ s16 unk6; /* 0: blend to the next one */
} MotionStep;

/*
 * A 3D model (FIGHTSTG_createModel), registered with id 0x11: a tree of bones,
 * each drawn by a Mesh child (children[i] for bone i, children[0] the
 * model's face, FIGHTSTG_createFace), and the motion it plays, from the
 * archive of motions in motionFile.
 */
typedef struct Model {
    TASK_HEADER(Model);
    /* 0x0050 */ s32 boneCount;
    /* 0x0054 */ ModelBone *bones;
    /* 0x0058 */ SVECTOR move; /* moves the root bone, along its rotation */
    /* 0x0060 */ s32 hasIdle; /* it goes back to its idle motion */
    /* 0x0064 */ ModelControl *control;
    /* 0x0068 */ Vec2 texPos; /* where its textures go in VRAM */
    /* 0x0070 */ s32 texFile;
    /* 0x0074 */ s32 motionFile;
    /* 0x0078 */ s32 motion;
    /* 0x007C */ s32 motionDone;
    /* 0x0080 */ s32 keyframe;
    /* 0x0084 */ s32 frame; /* the pose's */
    /* 0x0088 */ s32 idleFrames[2]; /* where the two idle motions start */
    /* 0x0090 */ s32 blendTarget; /* the frame it blends into, 0 for none */
    /* 0x0094 */ s32 blending;
    /* 0x0098 */ s32 blend; /* how far, in 4096ths */
    /* 0x009C */ s32 toIdle; /* the motion ends in the idle motion */
    /* 0x00A0 */ s32 keyframeCount;
    /* 0x00A4 */ u16 keyframes[0x640];
    /* 0x0D24 */ u16 unkD24[0x640];
    /* 0x19A4 */ u16 unk19A4[0x640];
    /* 0x2624 */ void (*setMotion)(struct Model *model, s32 motion, s32 restart);
    /* 0x2628 */ s32 (*isMotionDone)(struct Model *model);
    /* 0x262C */ void (*setColor)(); /* (model, mode, color): its meshes' */
    /* 0x2630 */ void (*setBoneNoBoundsCheck)();
} Model;

/* A battle effect that is a model (FIGHTSTG_startEffectModel): FIGHTSTG_effectModels lists
   them, ending with id 0 */
typedef struct EffectModelEntry {
    /* 0x0 */ s32 id;
    /* 0x4 */ s32 file; /* the model's file and index */
    /* 0x8 */ s32 motionFile;
} EffectModelEntry;

/* Shows an effect's model at a place until its motion ends
   (FIGHTSTG_startEffectModel) */
typedef struct EffectModel {
    TASK_HEADER(EffectModel);
    /* 0x50 */ s32 effect; /* 0 if it has no entry */
    /* 0x54 */ s32 file;
    /* 0x58 */ s32 motionFile;
    /* 0x5C */ SVECTOR pos;
    /* 0x64 */ SVECTOR rot;
    /* 0x6C */ Vec2 texPos;
    /* 0x74 */ ModelControl control;
} EffectModel;

/* The fight stages, the battle's backgrounds: WFIGHTTS lists them as
   MFSTG001-027 */
#if VERSION_US
#define FILE_FIGHT_STAGES 0x1BD
#elif VERSION_EU
#define FILE_FIGHT_STAGES 0x1CB
#endif

/* A table of 0x46-byte entries that start with an s16 id, 0 after the
   last (FIGHTSTG_findBattleTableIndex) */
#if VERSION_US
#define FILE_BATTLE_TABLE 0xBE
#elif VERSION_EU
#define FILE_BATTLE_TABLE 0x1CF
#endif

/* What an enemy does: its target (FIGHTSTG_getEnemyAction) when the condition holds */
typedef struct BattleTableAction {
    /* 0x0 */ u8 target;
    /* 0x1 */ u8 condition;
    /* 0x2 */ s16 conditionArg;
} BattleTableAction;

typedef struct BattleTableEntry {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 item; /* what the enemy may leave */
    /* 0x04 */ s16 itemChance; /* in 1024ths, less one */
    /* 0x06 */ s16 nameId; /* string in file 0x4F */
    /* 0x08 */ s16 unk8[3];
    /* 0x0E */ s16 stats[5]; /* scaled by the enemy's unkA / 16 */
    /* 0x18 */ s16 resist[12];
    /* 0x30 */ u8 unk30;
    /* 0x31 */ u8 unk31;
    /* 0x32 */ BattleTableAction actions[3]; /* the first whose condition holds (FIGHTSTG_testEnemyCondition) */
    /* 0x3E */ u8 unk3E[4];
    /* 0x42 */ BattleTableAction counter; /* its counterattack (FIGHTSTG_updateCounterattack) */
} BattleTableEntry;

/* The fighters' file, which FIGHTSTG_fighterCache.funcs reads */
#if VERSION_US
#define FILE_FIGHTERS 0x1BE
#elif VERSION_EU
#define FILE_FIGHTERS 0x1CC
#endif

/* A fight stage's lights: three flat lights and the ambient colour */
typedef struct LightSet {
    /* 0x00 */ GsF_LIGHT lights[3];
    /* 0x30 */ s32 ambient[3];
} LightSet;

/* A fight stage, in FILE_FIGHT_STAGES */
typedef struct FightStageInfo {
    /* 0x00 */ s32 model; /* file << 16 | index */
    /* 0x04 */ s32 motions;
    /* 0x08 */ s32 music; /* an index in FIGHTSTG_stageMusic, or -1 */
    /* 0x0C */ u8 bgColor[3];
    /* 0x0F */ u8 unkF;
    /* 0x10 */ u8 unk10[8]; /* bones given to the model's setBoneNoBoundsCheck, up to a 0 */
    /* 0x18 */ LightSet lights;
    /* 0x54 */ s32 unk54;
} FightStageInfo;

/* The fight stage (FIGHTSTG_createStage), registered as BATTLE_TASK_STAGE: its model,
   which fades in from black, and its music. setStage fades it out and
   the new one in. */
typedef struct FightStage {
    TASK_HEADER(FightStage);
    /* 0x50 */ s32 stage;
    /* 0x54 */ s32 prevStage;
    /* 0x58 */ ModelControl control;
    /* 0xA4 */ s32 fade; /* 0-0x1000 */
    /* 0xA8 */ s32 fadeStep;
    /* 0xAC */ s32 fadeInTime;
    /* 0xB0 */ s32 fadeOutTime;
    /* 0xB4 */ SVECTOR colorFrom; /* the model's */
    /* 0xBC */ SVECTOR colorTo;
    /* 0xC4 */ SVECTOR color;
    /* 0xCC */ SVECTOR bgFrom; /* layer 0x1000's background */
    /* 0xD4 */ SVECTOR bgTo;
    /* 0xDC */ SVECTOR bg;
    /* 0xE4 */ s16 voice; /* the music's */
    /* 0xE8 */ void (*setStage)(struct FightStage *task, s32 stage, s32 fadeOutTime, s32 fadeInTime);
} FightStage;

/* FIGHTSTG_interp: the functions that go between values */
typedef struct InterpFuncs {
    /* 0x0 */ void (*unk0)();
    /* 0x4 */ void (*lerp)(SVECTOR *from, SVECTOR *to, s32 t, SVECTOR *out); /* t: 0-0x1000 */
    /* 0x8 */ s32 (*ease)(s32 curve, s32 t, s32 value); /* value scaled by a curve of t */
} InterpFuncs;

/* The stage lights (FIGHTSTG_createLights), registered as BATTLE_TASK_LIGHTS: set puts a
   light set, fade goes from one to another in time frames */
typedef struct Lights {
    TASK_HEADER(Lights);
    /* 0x050 */ s32 layerId;
    /* 0x054 */ LightSet current;
    /* 0x090 */ LightSet to;
    /* 0x0CC */ LightSet from;
    /* 0x108 */ s32 t; /* 0-0x1000 */
    /* 0x10C */ s32 tStep; /* per frame */
    /* 0x110 */ void (*set)(struct Lights *task, LightSet *set);
    /* 0x114 */ void (*fade)(struct Lights *task, LightSet *from, LightSet *to, s32 time); /* from: NULL for the current */
    /* 0x118 */ LightSet *(*getStageLights)(struct Lights *task, s32 stage);
} Lights;

/* FIGHTSTG_startMove's task: moves a ModelControl to a position */
typedef struct MoveTask {
    TASK_HEADER(MoveTask);
    /* 0x50 */ ModelControl *control;
    /* 0x54 */ ShortVec3 from;
    /* 0x5A */ ShortVec3 to;
    /* 0x60 */ s32 t; /* 0-0x1000 */
    /* 0x64 */ s32 tStep;
} MoveTask;

/* An entry of the fighters' file's list */
typedef struct FighterEntry {
    /* 0x0 */ s16 id;
    /* 0x2 */ u8 index; /* in the partners' or the enemies' table */
    /* 0x3 */ u8 kind; /* 0x3A and up: an enemy */
} FighterEntry;

/* The fighters' file: offsets from its start */
typedef struct FightersFile {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 entries; /* FighterEntry, up to an id 0 */
    /* 0x8 */ s32 partners; /* 0xC4 bytes each */
    /* 0xC */ s32 enemies; /* 0x48 bytes each */
} FightersFile;

/* A fighter's entry in its file, from FIGHTSTG_fighterCache.funcs.getInfo */
typedef struct FighterInfo {
    /* 0x00 */ s32 model;
    /* 0x04 */ s32 motions;
    /* 0x08 */ s32 effects; /* its effect scripts' archive */
    /* 0x0C */ s32 face; /* its FaceRects: an offset in the fighters' file */
    /* 0x10 */ s16 unk10; /* its distance from the middle, past 0x1400 */
    /* 0x12 */ u8 unk12[6];
    /* 0x18 */ s16 height;
    /* 0x1A */ ShortVec3 camPos[12]; /* the cameras that look at it; an enemy
                                        has 3 of each and then their count */
    /* 0x62 */ ShortVec3 camRef[12];
    /* 0xAA */ s16 camProj[12];
} FighterInfo;

/* An enemy's FighterInfo: it has 3 cameras where a partner has 12 */
typedef struct FighterInfoEnemy {
    /* 0x00 */ u8 unk0[0x1A];
    /* 0x1A */ ShortVec3 camPos[3];
    /* 0x2C */ ShortVec3 camRef[3];
    /* 0x3E */ s16 camProj[3];
    /* 0x44 */ s16 cameraCount;
} FighterInfoEnemy;

/* The fighters' file (FIGHTSTG_fighterCache.funcs) */
typedef struct FighterInfoFuncs {
    /* 0x0 */ FighterInfo *(*getInfo)(s32 id);
    /* 0x4 */ void (*cacheEntry)(s32 index); /* FIGHTSTG_cacheFighter: the list's entry at index */
    /* 0x8 */ void (*getRange)(u32 enemy, s32 *min, s32 *max); /* the indices of the partners or the enemies */
} FighterInfoFuncs;

/* FIGHTSTG_fighterCache: the last fighter getInfo found, and the fighters'
   file's functions */
typedef struct FighterCache {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 isEnemy; /* the kind is 0x3A or more */
    /* 0x08 */ s32 index; /* in the partners' or the enemies' table */
    /* 0x0C */ s32 kind;
    /* 0x10 */ FighterInfo *partnerInfo; /* both hold the info found, read by isEnemy */
    /* 0x14 */ FighterInfo *enemyInfo;
    /* 0x18 */ FighterInfoFuncs funcs;
    /* 0x24 */ struct FaceRect *(*getFace)(s32 fighter); /* up to an x of 0xFF */
} FighterCache;

/* The Models task's children: a removed model stays until it is gone */
typedef struct ModelsChildren {
    /* 0x00 */ Model *models[4];
    /* 0x10 */ Model *dying[4];
} ModelsChildren;

/* The fighters' models (FIGHTSTG_createModels), registered as BATTLE_TASK_MODELS: up to four,
   each one with its ModelControl, found by an id */
typedef struct Models {
    TASK_HEADER(Models);
    /* 0x050 */ ModelControl controls[4];
    /* 0x180 */ void (*remove)(struct Models *task, s32 id);
    /* 0x184 */ void (*add)(struct Models *task, s32 id, s32 fighter, s32 visible);
    /* 0x188 */ ModelControl *(*get)(struct Models *task, s32 id);
    /* 0x18C */ void (*setId)(struct Models *task, s32 id, s32 newId);
    /* 0x190 */ s32 (*getFighter)(struct Models *task, s32 id);
    /* 0x194 */ void (*face)(struct Models *task, s32 id); /* ids under 0x10 are one side */
    /* 0x198 */ void (*setIdleMotion)(struct Models *task, s32 id, s32 motion);
} Models;

/* A part of a fighter's face (its eyes, then up to 14 more) and where its
   three frames are in its texture: copied into place by a DR_MOVE */
typedef struct FaceRect {
    /* 0x0 */ u8 x;
    /* 0x1 */ u8 y;
    /* 0x2 */ u8 w; /* 0: unused */
    /* 0x3 */ u8 h;
    /* 0x4 */ u8 frames[3][2];
} FaceRect;

typedef struct FacePart {
    /* 0x00 */ s32 used;
    /* 0x04 */ s32 frame; /* the one drawn */
    /* 0x08 */ FaceRect rect;
} FacePart;

/* A model's face (FIGHTSTG_createFace, the model's first child): the eyes
   blink (or close for some motions) and the other parts loop their frames */
typedef struct Face {
    TASK_HEADER(Face);
    /* 0x050 */ Model *model;
    /* 0x054 */ Vec2 texPos; /* the model's */
    /* 0x05C */ s32 partCount;
    /* 0x060 */ FacePart parts[16];
    /* 0x1A0 */ s32 blinkTimer;
    /* 0x1A4 */ s32 time;
} Face;

/* A fighter's camera (FIGHTSTG_createCamera) on layer 0x1009, from its
   FighterInfo; frames counts the frames it still has to be set */
typedef struct FighterCamera {
    TASK_HEADER(FighterCamera);
    /* 0x50 */ s32 fighter;
    /* 0x54 */ ModelControl *control;
    /* 0x58 */ GsRVIEW2 view;
    /* 0x78 */ s32 proj; /* the projection distance */
    /* 0x7C */ GsCOORDINATE2 coord; /* the view's */
    /* 0xCC */ SVECTOR rot;
    /* 0xD4 */ VECTOR trans;
    /* 0xE4 */ s32 frames;
} FighterCamera;

/* The jump heights and speeds (t per frame) of the Jump kinds 1-6 */
typedef struct JumpParams {
    /* 0x0 */ s32 height;
    /* 0x4 */ s32 speed;
} JumpParams;

/* A ModelControl's jump (FIGHTSTG_startJump): up and down from its y, or
   for kinds 4 and 5 also forwards from or back to its home */
typedef struct Jump {
    TASK_HEADER(Jump);
    /* 0x50 */ s32 kind;
    /* 0x54 */ s32 distance; /* kind 4: past 0x2800 */
    /* 0x58 */ s32 dist;
    /* 0x5C */ ModelControl *control;
    /* 0x60 */ s32 height;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 speed;
    /* 0x6C */ s32 t; /* 0-0x1000 */
} Jump;

/* A battle sound (FIGHTSTG_playBattleSound) that is keyed off after time */
typedef struct BattleSound {
    TASK_HEADER(BattleSound);
    /* 0x50 */ s32 sound;
    /* 0x54 */ s32 voice;
    /* 0x58 */ s32 time;
} BattleSound;

/* A sprite sheet for the battle's 2D effects: an archive of animations,
   the sheet and where its texture goes in VRAM */
typedef struct EffectSheet {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 sheet;
    /* 0x8 */ Vec2 texPos;
} EffectSheet;

/* A 2D effect: its sheet in FIGHTSTG_effectSheets and its animations, an
   archive of SpriteAnim data; the list (FIGHTSTG_spriteEffects) ends with an
   id of -1 */
typedef struct SpriteEffectEntry {
    /* 0x0 */ s16 id;
    /* 0x2 */ s16 sheet;
    /* 0x4 */ s32 file;
} SpriteEffectEntry;

/* A 2D effect (FIGHTSTG_startSpriteEffect): a SpriteAnim per animation, killed
   when they all are */
typedef struct SpriteEffect {
    TASK_HEADER(SpriteEffect);
    /* 0x50 */ s32 effect; /* -1: not found */
    /* 0x54 */ s32 sheet;
    /* 0x58 */ s32 file;
    /* 0x5C */ SVECTOR pos;
    /* 0x64 */ s32 count;
} SpriteEffect;

/* One animation of a 2D effect (FIGHTSTG_createSpriteAnim), drawn by a layer
   callback. Its data: flags, stride and duration, the 9 values of the first
   frame, then per frame the values whose bit is set in flags. */
typedef struct SpriteAnim {
    TASK_HEADER(SpriteAnim);
    /* 0x50 */ s16 *data;
    /* 0x54 */ SVECTOR pos; /* vz 0x7FFF: on screen in front, -1: on screen */
    /* 0x5C */ s32 sheet;
    /* 0x60 */ Vec2 texPos;
    /* 0x68 */ s32 layerId;
    /* 0x6C */ s32 time;
    /* 0x70 */ s32 flags;
    /* 0x74 */ s32 stride; /* of a frame's values */
    /* 0x78 */ s32 duration;
    /* 0x7C */ s16 frame;
    /* 0x7E */ s16 clutRow;
    /* 0x80 */ s16 x;
    /* 0x82 */ s16 y;
    /* 0x84 */ union {
        s16 v[2]; /* x, y; 0x1000 = 1.0 */
        s32 both; /* to test the two at once */
    } scale;
    /* 0x88 */ union {
        s16 v[2]; /* x, y */
        s32 both;
    } rot;
    /* 0x8C */ s16 rotZ;
} SpriteAnim;

/* Tasks whose update is still asm, named after it, with the fields their
   creators set */
/* FIGHTSTG_startHitEffect's task: the enemy's view, effect 0x33 on the
   player's fighter, then the script of a hit or a knockout */
typedef struct HitEffect {
    TASK_HEADER(HitEffect);
    /* 0x50 */ struct Models *models;
    /* 0x54 */ struct BattleCamera *camera;
    /* 0x58 */ s32 result; /* 1 a hit, 2 a knockout: the script is result + 1 */
    /* 0x5C */ s32 unk5C; /* the script's unk74 */
    /* 0x60 */ s32 effectImages; /* FIGHTSTG_findEffectSheet's */
    /* 0x64 */ s32 sheet; /* its file in the high half */
    /* 0x68 */ Vec2 texPos;
} HitEffect;

/* FIGHTSTG_updateFirstTech's task (FIGHTSTG_startFirstTech): a side's first technique */
typedef struct FirstTech {
    TASK_HEADER(FirstTech);
    /* 0x50 */ u8 side; /* the side that uses it, 0 or 0x10 */
    /* 0x54 */ s32 tech;
    /* 0x58 */ s32 damage;
    /* 0x5C */ s32 asleep; /* whether the other side's fighter was asleep */
    /* 0x60 */ s32 lines[8]; /* FIGHTSTG_updateMessage's */
} FirstTech;

/* FIGHTSTG_updateItem's task: an item used in battle, FIGHTSTG_runItemScript its script */
typedef struct BattleItem {
    TASK_HEADER(BattleItem);
    /* 0x50 */ s32 lines[8]; /* FIGHTSTG_updateMessage's, 0 ends them */
    /* 0x70 */ s32 item; /* the item */
    /* 0x74 */ s32 element; /* item 0x54's element, 2-8 */
    /* 0x78 */ s32 damage; /* the damage */
    /* 0x7C */ s32 lowered; /* item 0x58's: 1 it lowered the enemy's first stat, 2 its second */
} BattleItem;

/* An item's script settings (FIGHTSTG_itemScripts, ended by -1) */
typedef struct ItemScript {
    /* 0x0 */ s16 item;
    /* 0x2 */ s16 unk6C; /* BattleScript's */
    /* 0x4 */ s16 sound;
} ItemScript;

/* A technique's boost (FIGHTSTG_techBoosts and FIGHTSTG_sideBoosts, each
   ended by -1) */
typedef struct TechBoost {
    /* 0x0 */ s16 tech;
    /* 0x2 */ s16 amount; /* times the technique's unkC, below 0 for the other side */
    /* 0x4 */ s16 stat;
    /* 0x6 */ s16 line; /* the message */
} TechBoost;

extern TechBoost FIGHTSTG_techBoosts[];
extern TechBoost FIGHTSTG_sideBoosts[];

/* What an item cures (FIGHTSTG_itemCures, items 0x42-0x45) */
typedef struct StatusCure {
    /* 0x0 */ s16 message;
    /* 0x2 */ s16 flag; /* in BattleFighter.flags */
    /* 0x4 */ s32 item; /* FIGHTSTG_events.funcs.useItem's */
} StatusCure;

extern StatusCure FIGHTSTG_itemCures[4];
extern ItemScript FIGHTSTG_itemScripts[];
extern u8 FIGHTSTG_statusTechFlags[];
extern s32 FIGHTSTG_statusTechArgs[];
extern s32 FIGHTSTG_statusTechLines[];
#if VERSION_EU
extern s32 FIGHTSTG_clearIds[]; /* the six event types FIGHTSTG_reviveFighter clears */
#endif

typedef struct TechAction {
    TASK_HEADER(TechAction);
    /* 0x50 */ u8 side; /* the side that uses it, 0 or 0x10 */
    /* 0x54 */ s32 tech; /* the technique or item */
    /* 0x58 */ s32 damage;
    /* 0x5C */ s32 heal; /* the HP an item heals */
    /* 0x60 */ s32 asleep; /* whether the other side's fighter was asleep */
    /* 0x64 */ s32 lines[8]; /* FIGHTSTG_updateMessage's */
} TechAction;

/* FIGHTSTG_updateEnemyAttack's task (FIGHTSTG_startEnemyAttack): an attack
   on the player's active fighter, as state kind + 1 */
typedef struct EnemyAttack {
    TASK_HEADER(EnemyAttack);
    /* 0x50 */ s32 lines[4]; /* FIGHTSTG_updateMessage's */
    /* 0x60 */ s32 unk60; /* call WFIGHTMN_setIdleMotion once the motion starts */
    /* 0x64 */ u8 unk64[0xC];
    /* 0x70 */ s32 tech; /* the technique */
    /* 0x74 */ s32 kind; /* 0 the enemy's technique, 1 another attack */
    /* 0x78 */ s32 noKnockout; /* don't knock the fighter out at 0 HP */
    /* 0x7C */ s32 asleep; /* the fighter was asleep */
} EnemyAttack;

/* FIGHTSTG_updateActionEvents's task (FIGHTSTG_startActionEvents) */
typedef struct ActionEvents {
    TASK_HEADER(ActionEvents);
    /* 0x50 */ u8 side; /* 0 or 0x10 */
    /* 0x54 */ s32 args[3];
    /* 0x60 */ u8 unk60[0x14];
} ActionEvents;

/* The white flash (FIGHTSTG_startWhiteFlash): fades the screen to white,
   and back once ended */
typedef struct WhiteFlash {
    TASK_HEADER(WhiteFlash);
    /* 0x50 */ s32 speed; /* 0xFF / the frames */
    /* 0x54 */ s32 level; /* added to the screen (white), 0-0xFF */
} WhiteFlash;

/* A number that eases from one value to another (FIGHTSTG_stepHpTween) */
typedef struct HpTween {
    /* 0x00 */ s32 from;
    /* 0x04 */ s32 to;
    /* 0x08 */ s32 value; /* the one shown */
    /* 0x0C */ s16 active;
    /* 0x0E */ s16 fighter; /* whose hp it is */
    /* 0x10 */ s16 time;
    /* 0x12 */ s16 duration;
} HpTween;

/* FIGHTSTG_createHud's task: the names and the hp of the fighters out */
typedef struct HpDisplay {
    TASK_HEADER(HpDisplay);
    /* 0x50 */ s32 shown[2]; /* the fighters the names are of */
    /* 0x58 */ HpTween hp[2]; /* each side's */
    /* 0x80 */ s32 timer;
    /* 0x84 */ s32 interval; /* how often the hp is checked */
} HpDisplay;

/* The player's turn (FIGHTSTG_updatePlayerTurn, BATTLE_TASK_PLAYER_TURN): the battle menu, then the
   menus of its commands */
typedef struct PlayerTurn {
    TASK_HEADER(PlayerTurn);
    /* 0x50 */ s32 command; /* the command menu's choice, a BATTLE_COMMAND_* */
    /* 0x54 */ s32 unk54; /* FIGHTSTG_createSwitchMenu's line */
    /* 0x58 */ s32 result; /* the open menu's, -1 until it is done and -2 to go back */
    /* 0x5C */ s32 action; /* what the turn does */
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 digimon; /* the Digimon a partner changes into, or the one it switches to */
    /* 0x68 */ s32 unk68; /* FIGHTSTG_createPairSwitchMenu's technique */
} PlayerTurn;

/* The menu of the Digimon the active partner can digivolve into
   (FIGHTSTG_createDigivolveMenu), with the PartnerInfo of the one under the
   cursor */
typedef struct DigivolveMenu {
    TASK_HEADER(DigivolveMenu);
    /* 0x50 */ s32 *result; /* -1 until it is done, then the Digimon or -2 */
    /* 0x54 */ s32 partner; /* *result when it was made */
    /* 0x58 */ s32 page; /* the PartnerInfo page, 0-2 */
    /* 0x5C */ s32 sel; /* the cursor's line last frame */
    /* 0x60 */ s16 ids[4]; /* the partner, then its digivolutions (slots of 3 or more) */
    /* 0x68 */ s32 count;
    /* 0x6C */ s16 slots[4]; /* GAME.funcs.getPartnerSlots's */
} DigivolveMenu;

/* FIGHTSTG_updateDigivolveMenu's children */
typedef struct DigivolveMenuWindows {
    /* 0x00 */ struct MenuCursor *cursor;
    /* 0x04 */ TextWindow *names[4];
    /* 0x14 */ struct PartnerInfo *info[2]; /* shown and hiding, in turns */
} DigivolveMenuWindows;

/* A partner's entry in its slot, as GAME.funcs.getPartnerEntry gives it */
typedef struct BattlePartnerEntry {
    /* 0x0 */ s16 id;
    /* 0x2 */ s8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ s16 unk4[2];
    /* 0x8 */ s16 techs[6]; /* the low 13 bits, 0x4000 for one it can pass on */
} BattlePartnerEntry;

/* The lines of a page of the technique menu */
#define TECH_MENU_LINES 6

/* FIGHTSTG_createTechMenu's task: a menu of techniques, six a page */
typedef struct TechMenu {
    TASK_HEADER(TechMenu);
    /* 0x50 */ s32 *result; /* -1 until it is done */
    /* 0x54 */ s32 sel; /* the cursor's line last frame */
    /* 0x58 */ s16 slots[4]; /* GAME.funcs.getPartnerSlots's */
    /* 0x60 */ BattlePartnerEntry entries[3];
    /* 0x9C */ s32 techs[12]; /* ids in the low 13 bits, from 1 */
    /* 0xCC */ s32 count;
    /* 0xD0 */ s32 page;
    /* 0xD4 */ s32 pageCount;
} TechMenu;

/* The lines of a page of the item menu */
#define ITEM_MENU_LINES 7

/* The battle's item menu (FIGHTSTG_updateItemMenu): the usable items, seven a page */
typedef struct ItemMenu {
    TASK_HEADER(ItemMenu);
    /* 0x050 */ s32 *result; /* -1 until it is done, then the item or -2 */
    /* 0x054 */ s32 sel; /* the cursor's line last frame */
    /* 0x058 */ s16 items[0x194]; /* ITEM_FUNCS->list's */
    /* 0x380 */ s16 *usable; /* the items with flag 2 */
    /* 0x384 */ s32 count;
    /* 0x388 */ s32 page;
    /* 0x38C */ s32 pageCount;
} ItemMenu;

/* FIGHTSTG_updateItemMenu's children */
typedef struct ItemMenuWindows {
    /* 0x00 */ struct MenuCursor *cursor;
    /* 0x04 */ TextWindow *prevButton; /* the page buttons, texts 0x11 and 0x12 */
    /* 0x08 */ TextWindow *nextButton;
    /* 0x0C */ TextWindow *countLabel; /* text 0xC */
    /* 0x10 */ TextWindow *count; /* how many of the item */
    /* 0x14 */ TextWindow *message; /* its description */
    /* 0x18 */ TextWindow *names[ITEM_MENU_LINES];
} ItemMenuWindows;

/* The menu after the switch menu (FIGHTSTG_createSwitchInMenu): which of the
   incoming partner's Digimon comes in, then whether it just switches in or
   does the pair technique with the active fighter (only with
   FIGHTSTG_createPairSwitchMenu's techResult) */
typedef struct SwitchInMenu {
    TASK_HEADER(SwitchInMenu);
    /* 0x50 */ s32 *result; /* -1 until it is done, then the Digimon << 4 | 0 to switch or 1 for the pair technique, or -2 */
    /* 0x54 */ s32 page; /* the PartnerInfo page, 0-2 */
    /* 0x58 */ s32 shownPage;
    /* 0x5C */ s32 fighter; /* the incoming one, *result when it was made */
    /* 0x60 */ s32 partner; /* its party member */
    /* 0x64 */ s32 digimon; /* the line of ids picked */
    /* 0x68 */ s16 ids[4]; /* the partner, then its digivolutions (slots of 3 or more) */
    /* 0x70 */ s32 count;
    /* 0x74 */ s16 slots[4]; /* GAME.funcs.getPartnerSlots's */
    /* 0x7C */ s32 tech; /* the pair technique, from 1, 0 for none */
    /* 0x80 */ s32 *techResult; /* gets the technique picked */
} SwitchInMenu;

/* FIGHTSTG_updateSwitchInMenu's children */
typedef struct SwitchInMenuWindows {
    /* 0x00 */ struct MenuCursor *cursor;
    /* 0x04 */ struct MenuCursor *techCursor;
    /* 0x08 */ struct PartnerInfo *info[2]; /* shown and hiding, in turns */
    /* 0x10 */ TextWindow *names[4];
    /* 0x20 */ TextWindow *choices[5]; /* switching (text 0x1B), the pair technique (0x1C), "MP", its MP and the Digimon's name */
    /* 0x34 */ TextWindow *mp[4]; /* "MP", the active fighter's, "/", its max */
} SwitchInMenuWindows;

/* The command menu's lines, PlayerTurn.command */
#define BATTLE_COMMAND_ATTACK 0
#define BATTLE_COMMAND_TECH 1
#define BATTLE_COMMAND_DIGIVOLVE 2
#define BATTLE_COMMAND_SWITCH 3
#define BATTLE_COMMAND_ITEM 4
#define BATTLE_COMMAND_RUN 5
#define BATTLE_COMMAND_COUNT 6

/* The battle's command menu (FIGHTSTG_createCommandMenu) */
typedef struct CommandMenu {
    TASK_HEADER(CommandMenu);
    /* 0x50 */ s32 start; /* the line the cursor starts on */
    /* 0x54 */ s32 *result; /* -1 until it is done */
} CommandMenu;

/* FIGHTSTG_updateCommandMenu's children: a cursor over six lines */
typedef struct CommandMenuWindows {
    /* 0x00 */ struct MenuCursor *cursor;
    /* 0x04 */ TextWindow *lines[BATTLE_COMMAND_COUNT];
} CommandMenuWindows;

/* Shows the partner's model on layer 0x1009 (FIGHTSTG_createPartnerView), through
   the two FighterCamera children, a new one each time it is set up */
typedef struct PartnerView {
    TASK_HEADER(PartnerView);
    /* 0x50 */ Layer *layer;
    /* 0x54 */ s32 unk54;
} PartnerView;

/* A counterattack (FIGHTSTG_startCounterattack) */
typedef struct Counterattack {
    TASK_HEADER(Counterattack);
    /* 0x50 */ s32 lines[8]; /* FIGHTSTG_updateMessage's */
    /* 0x70 */ u8 side; /* the side that counters, 0 or 0x10 */
    /* 0x74 */ s32 received; /* the damage it answers, 0 for none */
    /* 0x78 */ s32 tech;
    /* 0x7C */ s32 hit; /* whether the technique hits (FIGHTSTG_battleFuncs.rollHit) */
    /* 0x80 */ s32 damage;
    /* 0x84 */ s32 noKnockOutEvent; /* a knockout doesn't call FIGHTSTG_queueKnockOut */
    /* 0x88 */ s32 unk88;
} Counterattack;

/* FIGHTSTG_startEnemyTurn's task */
typedef struct EnemyTurn {
    TASK_HEADER(EnemyTurn);
    /* 0x50 */ s32 lines[10]; /* FIGHTSTG_updateMessage's, 0 ends them */
    /* 0x78 */ s32 target; /* -2 to -4 for an enemy, else any but the active one */
    /* 0x7C */ s32 unk7C;
} EnemyTurn;

/* A battle message box (FIGHTSTG_createMessage): shows its messages a line
   at a time, each until cross, then ends */
typedef struct BattleMessageBox {
    TASK_HEADER(BattleMessageBox);
    /* 0x50 */ s32 queue[9]; /* message types for show, some with args after them; 0 ends them */
    /* 0x74 */ s32 started; /* set by show */
    /* 0x78 */ s32 shown; /* the window being shown */
    /* 0x7C */ s32 count; /* how many */
    /* 0x80 */ s32 interval; /* the time between them */
    /* 0x84 */ s32 shownTime;
    /* 0x88 */ s32 next; /* in queue */
    /* 0x8C */ s32 unk8C;
    /* 0x90 */ s32 arrowPalette; /* the arrow's palette, 0-4 */
    /* 0x94 */ s32 arrowTime; /* when it last changed */
    /* 0x98 */ s32 showArrow; /* show the arrow */
    /* 0x9C */ s32 found[3]; /* the fighters FIGHTSTG_findFighters found */
    /* 0xA8 */ s32 foundCount;
    /* 0xAC */ void (*show)(); /* FIGHTSTG_showMessage: (task, type, data) */
    /* 0xB0 */ void (*finish)(struct BattleMessageBox *task); /* FIGHTSTG_finishMessage: closes after 0x14 ticks or Cross */
} BattleMessageBox;

/* FIGHTSTG_startOneHpTurn's task, BATTLE_KIND_FINAL_SECOND's enemy turn:
   the enemy's second technique (WFIGHTMN_startTech), which leaves the
   player's fighter at 1 HP, each with its message, then the battle goes on
   (FIGHTSTG_queueEnemyTurn and FIGHTSTG_queueLastEnemy) */
typedef struct OneHpTurn {
    TASK_HEADER(OneHpTurn);
    /* 0x50 */ s32 lines[8]; /* FIGHTSTG_updateMessage's, 0 ends them */
} OneHpTurn;

/* FIGHTSTG_updateMessage's children: the lines it shows one by one */
typedef struct BattleMessageBoxWindows {
    /* 0x0 */ TextWindow *lines[2];
} BattleMessageBoxWindows;

/* What FIGHTSTG_updateMessage's messages say, for some of their types */
typedef struct BattleMessage {
    /* 0x0 */ u8 side;
    /* 0x4 */ s32 kind;
    /* 0x8 */ s32 value;
} BattleMessage;

/* A partner Digimon's change (FIGHTSTG_startDigimonChange): key1 the new Digimon, key2 the
   side. The stage and two clipped layers wipe the scene away and back. */
typedef struct DigimonChange {
    TASK_HEADER(DigimonChange);
    /* 0x50 */ struct Models *models;
    /* 0x54 */ struct BattleCamera *camera;
    /* 0x58 */ struct FightStage *stage;
    /* 0x5C */ s32 idleMotion; /* the old Digimon's */
    /* 0x60 */ RECT clip0; /* layer 0x1004's */
    /* 0x68 */ RECT clip1; /* layer 0x1003's */
    /* 0x70 */ s32 file; /* the new Digimon's model's */
} DigimonChange;

typedef struct DigimonChangeChildren {
    /* 0x00 */ struct WhiteFlash *fade;
    /* 0x04 */ Task *unk4;
    /* 0x08 */ struct SpriteEffect *effects[4];
} DigimonChangeChildren;

/* A shot of FIGHTSTG_updateShotCamera's camera */
typedef struct CameraShot {
    /* 0x0 */ s16 time; /* -1 ends the list */
    /* 0x2 */ s16 substate;
} CameraShot;

/* A camera (FIGHTSTG_createShotCamera) that goes through lists of shots
   (FIGHTSTG_cameraShots), the next list picked at random
   (FIGHTSTG_nextShotLists) */
typedef struct ShotCamera {
    TASK_HEADER(ShotCamera);
    /* 0x50 */ struct BattleCamera *camera;
    /* 0x54 */ struct CameraView *view;
    /* 0x58 */ struct Models *models;
    /* 0x5C */ s16 list;
    /* 0x5E */ s16 shot;
    /* 0x60 */ s16 ry; /* where the turn of substate 1 is */
    /* 0x62 */ s16 turned;
    /* 0x64 */ s32 time;
    /* 0x68 */ s32 speed;
} ShotCamera;

/* A fighter's entrance (FIGHTSTG_startEntrance): key1 its Digimon, key2 its side */
typedef struct Entrance {
    TASK_HEADER(Entrance);
    /* 0x50 */ s32 done;
    /* 0x54 */ struct Models *models;
    /* 0x58 */ struct BattleCamera *camera;
    /* 0x5C */ struct FightStage *stage;
    /* 0x60 */ s32 file; /* its model's */
    /* 0x64 */ s32 unk64;
} Entrance;

/* A page about a partner in one of its Digimon (FIGHTSTG_createPartnerInfo):
   its stats, its techniques, or the techniques its other Digimon can pass on */
typedef struct PartnerInfo {
    TASK_HEADER(PartnerInfo);
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 partner;
    /* 0x58 */ s32 page; /* what it shows: 0 the stats, 1 and 2 techniques */
    /* 0x5C */ s32 slot; /* from 1, or 0 for the partner itself */
    /* 0x60 */ s32 unk60; /* shown as a number, or text 0x1A when negative */
    /* 0x64 */ s16 stats[0x16]; /* the 22 of a PartnerTotals computeStats fills, shown up to 999 */
    /* 0x90 */ s16 slots[4]; /* GAME.funcs.getPartnerSlots's */
    /* 0x98 */ BattlePartnerEntry entries[3];
    /* 0xD4 */ s32 techs[6]; /* a technique in the low 13 bits */
} PartnerInfo;

/* A line of FIGHTSTG_showStats's stat list (FIGHTSTG_statLines): where its
   number goes and the stat it shows */
typedef struct StatLine {
    /* 0x0 */ u8 x;
    /* 0x1 */ u8 y;
    /* 0x2 */ u8 stat; /* of PartnerInfo.stats */
} StatLine;

/* The battle's switch menu (FIGHTSTG_createSwitchMenu): the player's other
   fighters, with their HP and MP, to bring in for the active one; a message
   when there are none */
typedef struct SwitchMenu {
    TASK_HEADER(SwitchMenu);
    /* 0x50 */ s32 *result; /* -1 until it is done, then the fighter or -2 */
    /* 0x54 */ s32 *line; /* the cursor's line, kept for the next time */
    /* 0x58 */ s32 canCancel; /* triangle goes back (not after a knockout) */
    /* 0x5C */ s32 others[2]; /* the other fighters of the player's side */
    /* 0x64 */ s32 count;
    /* 0x68 */ s32 arrowShown; /* the message's arrow, from its second frame */
    /* 0x6C */ s32 arrowTime;
    /* 0x70 */ s32 arrowPalette;
    /* 0x74 */ s32 pairs[2]; /* FIGHTSTG_getPairDigimon's, marked with an icon */
    /* 0x7C */ s16 slots[6]; /* GAME.funcs.getPartnerSlots's */
} SwitchMenu;

/* FIGHTSTG_updateSwitchMenu's children: two of each window, one per fighter */
typedef struct SwitchMenuWindows {
    /* 0x00 */ struct MenuCursor *cursor;
    /* 0x04 */ TextWindow *hpLabel[2];
    /* 0x0C */ TextWindow *hp[2];
    /* 0x14 */ TextWindow *hpSlash[2];
    /* 0x1C */ TextWindow *maxHp[2];
    /* 0x24 */ TextWindow *mpLabel[2];
    /* 0x2C */ TextWindow *mp[2];
    /* 0x34 */ TextWindow *mpSlash[2];
    /* 0x3C */ TextWindow *maxMp[2];
    /* 0x44 */ TextWindow *name[2];
    /* 0x4C */ TextWindow *message;
} SwitchMenuWindows;

/* A confused partner's command menu (FIGHTSTG_createConfusedMenu): a cursor
   over six of the shuffled lines; unless the fighter shakes off the
   confusion, the message of the one picked, shown like a
   BattleMessageBox's */
typedef struct ConfusedMenu {
    TASK_HEADER(ConfusedMenu);
    /* 0x50 */ s32 firstLine; /* the cursor's first line */
    /* 0x54 */ s32 picked;
    /* 0x58 */ s32 *result; /* -1 until it is done */
    /* 0x5C */ Task *partnerView; /* the PartnerView, stopped with shotCamera on a pick */
    /* 0x60 */ Task *shotCamera;
    /* 0x64 */ s32 queue[9]; /* like BattleMessageBox's: the message picked, then 0 */
    /* 0x88 */ s32 started; /* set by FIGHTSTG_showConfusedMessage */
    /* 0x8C */ s32 line; /* the window being shown */
    /* 0x90 */ s32 lineCount;
    /* 0x94 */ s32 delay; /* the time between them */
    /* 0x98 */ s32 time;
    /* 0x9C */ s32 next; /* in queue */
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ s32 arrowPalette; /* 0-4 */
    /* 0xA8 */ s32 arrowTime; /* when it last changed */
    /* 0xAC */ s32 showArrow;
    /* 0xB0 */ s32 unkB0[4];
    /* 0xC0 */ void (*show)(); /* like BattleMessageBox's, but never set: the queue ends first */
} ConfusedMenu;

/* Its children: the cursor, then its six lines; the first two are the
   message's after a pick */
typedef struct ConfusedMenuWindows {
    /* 0x00 */ struct MenuCursor *cursor;
    /* 0x04 */ TextWindow *lines[6];
} ConfusedMenuWindows;

/* Where the battle camera looks from and to, as a GsRVIEW2 with the
   transform of its coordinate system */
typedef struct CameraView {
    /* 0x00 */ s32 vpx;
    /* 0x04 */ s32 vpy;
    /* 0x08 */ s32 vpz;
    /* 0x0C */ s32 vrx;
    /* 0x10 */ s32 vry;
    /* 0x14 */ s32 vrz;
    /* 0x18 */ s32 tx;
    /* 0x1C */ s32 ty;
    /* 0x20 */ s32 tz;
    /* 0x24 */ SVECTOR rot;
    /* 0x2C */ s32 rz; /* the roll, in degrees */
    /* 0x30 */ s32 proj; /* the projection distance */
} CameraView;

/* The battle camera (FIGHTSTG_createBattleCamera), registered as BATTLE_TASK_CAMERA on
   a layer: set puts a view, fade goes from one to another in time frames */
typedef struct BattleCamera {
    TASK_HEADER(BattleCamera);
    /* 0x050 */ s32 layerId;
    /* 0x054 */ CameraView current;
    /* 0x088 */ CameraView to;
    /* 0x0BC */ CameraView from;
    /* 0x0F0 */ s32 t; /* 0-0x1000 */
    /* 0x0F4 */ s32 tStep; /* per frame, << 8 */
    /* 0x0F8 */ void (*set)(struct BattleCamera *task, CameraView *view);
    /* 0x0FC */ void (*fade)(struct BattleCamera *task, CameraView *from, CameraView *to, s32 time); /* from: NULL for the current */
    /* 0x100 */ CameraView *(*getEnemyView)(struct BattleCamera *task);
    /* 0x104 */ CameraView *(*getFighterView)(struct BattleCamera *task, s32 id, s32 camera);
} BattleCamera;

BattleCamera *FIGHTSTG_createBattleCamera(s32 layerId);

/* The European version's camera (FIGHTSTG_startCameraShots): one of three lists of shots
   (FIGHTSTG_euCameraShots) picked at random, then back to the enemy's view */
typedef struct CameraShots {
    TASK_HEADER(CameraShots);
    /* 0x50 */ struct BattleCamera *camera;
    /* 0x54 */ struct CameraView *view;
    /* 0x58 */ struct Models *models;
    /* 0x5C */ s16 list;
    /* 0x5E */ s16 shot;
    /* 0x60 */ s16 ry; /* where the turn of substate 6 starts */
    /* 0x62 */ s16 rx;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 time;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ struct CameraView to; /* where substates 4 and 5 fade to */
} CameraShots;

/* The camera's turn around the fighters when the player loses
   (FIGHTSTG_updateCameraTurn) */
typedef struct CameraTurn {
    TASK_HEADER(CameraTurn);
    /* 0x50 */ BattleCamera *camera;
} CameraTurn;

/* A menu cursor's layout, which FIGHTSTG_createCursor copies into its task: a
   highlight bar over count lines, and a sprite per line (sprite -1: none) */
typedef struct CursorLayout {
    /* 0x00 */ s32 count;
    /* 0x04 */ s32 x;
    /* 0x08 */ s32 y;
    /* 0x0C */ s32 step;
    /* 0x10 */ s32 sprite;
    /* 0x14 */ s32 spriteX;
    /* 0x18 */ s32 spriteY;
    /* 0x1C */ s32 spriteStep;
} CursorLayout;

/* A menu cursor (FIGHTSTG_createCursor): up and down move it, its bar is
   drawn by FIGHTSTG_drawCursorBar at vsync and each line's sprite blinks
   while it is picked */
typedef struct MenuCursor {
    TASK_HEADER(MenuCursor);
    /* 0x50 */ s32 sel;
    /* 0x54 */ s32 locked;
    /* 0x58 */ CursorLayout params;
    /* 0x78 */ s32 prevSel; /* where the bar was drawn last */
    /* 0x7C */ s32 frame; /* of the bar, 0-11 */
    /* 0x80 */ s32 blink[6]; /* the time of each line's sprite */
    /* 0x98 */ u8 unk98[0x10];
} MenuCursor;

/* One of FIGHTSTG_updateTechMenu's children: the cursor first, then the text windows */
typedef union TechMenuChild {
    MenuCursor *cursor;
    TextWindow *window;
} TechMenuChild;

/* Which fighters FIGHTSTG_findFighters looks for */
typedef struct FighterFilter {
    /* 0x0 */ s32 side;
    /* 0x4 */ s32 type;
} FighterFilter;

/* The battle script's task (FIGHTSTG_updateBattleScript) */
/* A fighter's battle script (FIGHTSTG_updateBattleScript): a list
   of s16 commands in an archive entry of the fighter's file, which play its
   motions, effects, sounds and camera moves */
typedef struct BattleScript {
    TASK_HEADER(BattleScript);
    /* 0x50 */ s32 unk50; /* the enemy's */
    /* 0x54 */ s32 index; /* the script, in the fighter's archive */
    /* 0x58 */ s32 hits[4]; /* 0 a hit, 3 a miss; [3] how it ended */
    /* 0x68 */ s32 stage; /* what the stage command's 0x38 stands for */
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 sound; /* what the sound commands' 0x62 and 0x63 stand for on a hit */
    /* 0x74 */ s32 unk74;
    /* 0x78 */ s32 fighter;
    /* 0x7C */ s32 model; /* the Models task's id */
    /* 0x80 */ s32 archive;
    /* 0x84 */ s32 unk84;
    /* 0x88 */ Models *models;
    /* 0x8C */ s16 *pc;
    /* 0x90 */ s32 scripts; /* how many hits command 5 has played */
    /* 0x94 */ s32 sounds; /* and the sound commands */
    /* 0x98 */ s32 waiting;
    /* 0x9C */ s32 wait; /* the time left */
    /* 0xA0 */ s32 loadStep; /* FIGHTSTG_runScriptEffect's, loading a 2D effect */
    /* 0xA4 */ s32 effectImages; /* FIGHTSTG_findEffectSheet's */
    /* 0xA8 */ s32 effectSheet;
    /* 0xAC */ Vec2 effectTexPos;
} BattleScript;

/* A turn's or a counterattack's one child, and what WFIGHTMN's battle menu
   waits for (NULL when it is done): a message box, or what plays an action */
typedef union BattleChild {
    Task *task;
    BattleMessageBox *message; /* FIGHTSTG_createMessage */
    BattleScript *script; /* a technique's (FIGHTSTG_createBattleScript) */
    Entrance *entrance; /* a fighter's (FIGHTSTG_startEntrance) */
    DigimonChange *change; /* a partner's Digimon change (FIGHTSTG_startDigimonChange) */
    FirstTech *attack; /* FIGHTSTG_startFirstTech */
    TechAction *tech; /* a technique or an item (FIGHTSTG_startTechAction) */
    BattleItem *item; /* FIGHTSTG_startItem */
    EnemyAttack *enemyAttack; /* an attack on the player's fighter (FIGHTSTG_startEnemyAttack) */
    HitEffect *hitEffect; /* effect 0x33, then a script (FIGHTSTG_startHitEffect) */
    EnemyTurn *enemyTurn; /* FIGHTSTG_startEnemyTurn */
    OneHpTurn *oneHpTurn; /* BATTLE_KIND_FINAL_SECOND's enemy turn (FIGHTSTG_startOneHpTurn) */
    CameraTurn *cameraTurn; /* when the player loses (FIGHTSTG_startCameraTurn) */
    CameraShots *cameraShots; /* the European version's (FIGHTSTG_startCameraShots) */
    ScreenFade *fade; /* FIGHTSTG_createScreenFade */
    struct Counterattack *counter; /* a counterattack (FIGHTSTG_startCounterattack) */
    struct ActionEvents *events; /* the queued events (FIGHTSTG_startActionEvents) */
} BattleChild;

/* The tasks FIGHTSTG starts for WFIGHTMN and WFIGHTTS */
FightStage *FIGHTSTG_createStage(s32 id, s32 fadeInTime);
Entrance *FIGHTSTG_startEntrance(s32 id, s32 side, s32 arg2);
Models *FIGHTSTG_createModels(void);
/* WFIGHTMN passes the damage as a third argument, which it doesn't read; its
   code loads it, so no parameter list */
HitEffect *FIGHTSTG_startHitEffect();
/* WFIGHTMN passes them the battle, which they don't read; its code loads
   it, so no parameter list */
EnemyTurn *FIGHTSTG_startEnemyTurn();
OneHpTurn *FIGHTSTG_startOneHpTurn();
DigimonChange *FIGHTSTG_startDigimonChange(s32 key1, s32 key2);
ScreenFade *FIGHTSTG_createScreenFade(void);
BattleScript *FIGHTSTG_createBattleScript(void);
FirstTech *FIGHTSTG_startFirstTech(s32 side);
BattleItem *FIGHTSTG_startItem(s32 item);
TechAction *FIGHTSTG_startTechAction(s32 side, s32 tech);
EnemyAttack *FIGHTSTG_startEnemyAttack(s32 kind, s32 noKnockout);
PlayerTurn *FIGHTSTG_startPlayerTurn(void);
BattleMessageBox *FIGHTSTG_createMessage(void);
CameraTurn *FIGHTSTG_startCameraTurn(void);
CameraShots *FIGHTSTG_startCameraShots(void);
Lights *FIGHTSTG_createLights(s32 layerId);
/* The events they queue for WFIGHTMN, and its turn's substate */
void FIGHTSTG_setPlayerTurnStep(s32 substate);
s32 FIGHTSTG_isPlayerChoosing(void);
void FIGHTSTG_queuePlayerTurn(s32 delay);
void FIGHTSTG_queueEnemyTurn(s32 delay);
void FIGHTSTG_endBattle(s32 result);
void FIGHTSTG_queueRunAway(u8 side);
void FIGHTSTG_queueRecovery(u8 side, s32 fighter, s32 big);
void FIGHTSTG_queueKnockOut(u8 side);
void FIGHTSTG_queueBlast(void);
void FIGHTSTG_queueBlastEnd(s32 kind);
void FIGHTSTG_queueSpecialEnd(void);
void FIGHTSTG_weakenEnemy(void);
void FIGHTSTG_endEnemyWeakness(void);

/* The battle script's children */
typedef struct BattleScriptChildren {
    /* 0x00 */ WhiteFlash *fade;
    /* 0x04 */ Task *unk4;
    /* 0x08 */ Task *unk8;
    /* 0x0C */ BattleSound *sound;
    /* 0x10 */ Task *unk10[8];
    /* 0x30 */ EffectModel *effects[3];
    /* 0x3C */ BattleScript *script; /* one it plays */
} BattleScriptChildren;


/* The types of the battle's events: WFIGHTMN runs a state for each
   (WFIGHTMN_runTurn) */
#define EVENT_END_BATTLE 1 /* FIGHTSTG_endBattle */
#define EVENT_PLAYER_TURN 2
#define EVENT_ENEMY_TURN 3
#define EVENT_RUN_AWAY 4
#define EVENT_AUTO_RECOVER_END 5
#define EVENT_RECOVERY 6
#define EVENT_CLEAR_FIELD 7
#define EVENT_PARTNER_TECH 8 /* a technique of the partner's, run as its command */
#define EVENT_STATUS_DAMAGE 9 /* the damage of a poisoned fighter (FIGHTER_POISONED) */
#define EVENT_STATUS_END 10 /* 10-12: the end of FIGHTER_PARALYZED, FIGHTER_CONFUSED or FIGHTER_ASLEEP */
#define EVENT_BOOST_END 13 /* 13-15: the end of a boost, by the stat */
#define EVENT_RESTRICTION_END 16 /* 16-17: the end of a restriction (flag 0x10 or 0x20) */
#define EVENT_BLAST 18 /* the partner's digivolution for the battle */
#define EVENT_BLAST_END 19
#define EVENT_KNOCK_OUT 20
#define EVENT_SPECIAL_END 21 /* the end of the partner's special state */
#define EVENT_DIGIDEVOLVE 22
#define EVENT_LAST_ENEMY 23 /* the last battle's third enemy comes in */
#define EVENT_WEAKNESS_END 24 /* the end of the enemy's weakness (BATTLE_KIND_FINAL_LAST) */

/* An event of the battle, as it is queued (FIGHTSTG_pushEvent) */
typedef struct BattleEvent {
    /* 0x00 */ s32 type; /* EVENT_END_BATTLE... */
    /* 0x04 */ s32 delay;
    /* 0x08 */ s32 args[6];
} BattleEvent;

/* A queued event: its time counts down to when it runs */
typedef struct QueuedEvent {
    /* 0x00 */ s16 type; /* 0 for a free entry */
    /* 0x02 */ s16 time;
    /* 0x04 */ s32 args[6];
} QueuedEvent;

/* What FIGHTSTG_removeEvents removes the events of */
typedef struct EventKey {
    /* 0x0 */ u8 unk0;
    /* 0x4 */ s32 unk4;
} EventKey;

/* The kinds of battle (Battle.kind), which WFIGHTMN picks by the battle and
   the mode it came from */
#define BATTLE_KIND_NORMAL 0
#define BATTLE_KIND_ESCAPE 1 /* the enemy runs away under a tenth of its HP */
#define BATTLE_KIND_UNK2 2 /* the enemy keeps an eleventh of its HP */
#define BATTLE_KIND_NO_DAMAGE 3 /* the partner's hits do no damage */
#define BATTLE_KIND_FINAL 4 /* battle 0x144, the last one: its first enemy */
#define BATTLE_KIND_FINAL_SECOND 5 /* its second enemy */
#define BATTLE_KIND_FINAL_LAST 6 /* its third enemy; winning plays the ending */

/* How a battle ends (FIGHTSTG_endBattle) */
#define BATTLE_FLED 0 /* a side ran away */
#define BATTLE_WON 1
#define BATTLE_LOST 2

/* The event queue's functions (FIGHTSTG_events.funcs) */
typedef struct EventQueueFuncs {
    /* 0x00 */ u8 result; /* the battle's, for WFIGHTMN (BATTLE_FLED...) */
    /* 0x01 */ u8 unk1;
    /* 0x04 */ void (*push)(BattleEvent *event);
    /* 0x08 */ void (*pushFirst)(BattleEvent *event); /* before all the others */
    /* 0x0C */ s32 (*pop)(void); /* the next event due */
    /* 0x10 */ s32 (*first)(s32 type);
    /* 0x14 */ s32 (*next)(void);
    /* 0x18 */ s32 (*find)(s32 type, u8 side, s32 fighter);
    /* 0x1C */ void (*remove)(EventKey *key); /* the events whose first two args are its */
    /* 0x20 */ s32 (*getDelay)(u8 side, s32 kind); /* FIGHTSTG_getEventDelay: when an event of side's runs */
    /* 0x24 */ void (*useItem)(u8 side, s32 fighter, s32 item); /* FIGHTSTG_cureStatus: an item's cure */
} EventQueueFuncs;

/* An event kind's delay range (FIGHTSTG_eventDelays, by kind): FIGHTSTG_getEventDelay
   adds a random part below div, and clamps to min and max where they are
   not 0 */
typedef struct EventDelay {
    /* 0x0 */ s16 div;
    /* 0x2 */ s16 min;
    /* 0x4 */ s16 max;
} EventDelay;

extern EventDelay FIGHTSTG_eventDelays[];

/* The battle's events (FIGHTSTG_events) */
typedef struct EventQueue {
    /* 0x000 */ QueuedEvent events[99];
    /* 0xAD4 */ u8 unkAD4[0x1C];
    /* 0xAF0 */ s8 curType; /* the type of the event popped last */
    /* 0xAF1 */ s8 curIndex; /* and where it is */
    /* 0xAF2 */ s8 findType; /* what first and next look for, 1-24 */
    /* 0xAF3 */ s8 found; /* the event they found, or -1 */
    /* 0xAF4 */ EventQueueFuncs funcs;
} EventQueue;

/* BattleFighter.flags: the statuses, which the techniques give
   (FIGHTSTG_inflict*) and events of type EVENT_STATUS_END + n end */
#define FIGHTER_POISONED 1 /* takes damage (EVENT_STATUS_DAMAGE) */
#define FIGHTER_PARALYZED 2 /* loses turns at random (FIGHTSTG_battleFuncs.testParalysis) */
#define FIGHTER_CONFUSED 4
#define FIGHTER_ASLEEP 8 /* can't act or run away; a hit may wake it up */

/* One of the battle's fighters, three on each side (WFIGHTMN's BattleUnit):
   a partner's HP and MP go back to the party when the battle ends */
typedef struct BattleFighter {
    /* 0x00 */ s16 id; /* the Digimon (DIGIMON_DATA) */
    /* 0x02 */ s16 prevId; /* its own id while id is a temporary one */
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 maxHp;
    /* 0x08 */ s16 hp;
    /* 0x0A */ s16 maxMp;
    /* 0x0C */ s16 mp;
    /* 0x0E */ s16 unkE; /* FIGHTSTG_computeStats reads its low byte */
    /* 0x10 */ s16 boosts[4]; /* added to the stats FIGHTSTG_boostStats picks */
    /* 0x18 */ s16 item; /* an enemy's */
    /* 0x1A */ u8 temporary; /* id is a temporary Digimon */
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ u8 flags; /* FIGHTER_*; 0x10 and 0x20 the restrictions */
    /* 0x1D */ u8 paralysis; /* FIGHTER_PARALYZED's strength */
    /* 0x1E */ u8 sleep; /* FIGHTER_ASLEEP's */
    /* 0x1F */ u8 confusion; /* FIGHTER_CONFUSED's */
} BattleFighter;

/* How the battle's frames go by (func_8009D648 sets it) */
typedef struct BattleSpeed {
    /* 0x0 */ s32 mode; /* 1: stopped, 2: slowed (a frame per 4 of time), 3: double */
    /* 0x4 */ s32 rest; /* the time mode 2 hasn't counted yet */
} BattleSpeed;

/* FIGHTSTG_battle: the battle */
typedef struct Battle {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 frames; /* since the last update */
    /* 0x08 */ s32 active[2]; /* each side's fighter */
    /* 0x10 */ BattleFighter fighters[2][3];
    /* 0xD0 */ s16 boostElement; /* an element func_8009E74C boosts, under 2 for none */
    /* 0xD2 */ s16 boostAmount; /* and how much, in 128ths */
    /* 0xD4 */ s16 unkD4;
    /* 0xD6 */ s16 kind; /* the kind of battle */
    /* 0xD8 */ s16 tech; /* a technique id, set by WFIGHTMN */
    /* 0xDA */ s8 hitCount; /* BATTLE_KIND_FINAL_LAST: the partner's hits that did damage */
    /* 0xDB */ u8 weakened; /* BATTLE_KIND_FINAL_LAST: the enemy is weakened (FIGHTSTG_weakenEnemy) */
    /* 0xDC */ BattleSpeed speed;
    /* 0xE4 */ void (*unkE4)(void); /* func_8009D560 */
    /* 0xE8 */ void (*setSpeed)(s32 mode); /* func_8009D648 */
    /* 0xEC */ void (*project)(Layer *layer, SVECTOR *pos, ShortVec3 *out); /* FIGHTSTG_projectPoint */
    /* 0xF0 */ void (*unkF0)(s32 layer, s32 arg1, DVECTOR *points, CVECTOR *colors); /* func_8009DA88 */
    /* 0xF4 */ void (*unkF4)(s32 layer, s32 arg1, DVECTOR *points, CVECTOR *colors); /* func_8009DAA8 */
} Battle;

/* FIGHTSTG_action: the command being carried out (?) */
typedef struct BattleAction {
    /* 0x00 */ s16 unk0[0xE];
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 unk1D[3];
    /* 0x20 */ u8 side; /* the acting side: 0 the player, 0x10 the enemy */
    /* 0x24 */ s32 tech; /* the technique */
    /* 0x28 */ s32 damage; /* per hit */
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 hits[4]; /* whether each hit lands */
    /* 0x34 */ s16 unk34;
    /* 0x36 */ s16 unk36;
    /* 0x38 */ u8 unk38[0x28]; /* by the technique's unkA */
    /* 0x60 */ s32 unk60[2];
    /* 0x68 */ void (*start)(u8 side, s32 tech); /* func_8009D204 */
} BattleAction;

/* A side's stats as FIGHTSTG_computeStats works them out */
typedef struct BattleStats {
    /* 0x00 */ s16 level;
    /* 0x02 */ s16 stats[5]; /* with the fighter's boosts */
    /* 0x0C */ s16 resist[12];
    /* 0x24 */ u8 flags; /* the fighter's */
    /* 0x25 */ u8 unk25;
    /* 0x26 */ u8 unk26; /* the fighter's unkE */
    /* 0x27 */ u8 unk27;
    /* 0x28 */ u8 unk28[3]; /* from the equipment, as are the ones after */
    /* 0x2B */ u8 unk2B;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 unk30[0x10];
} BattleStats;

/* FIGHTSTG_battleFuncs */
typedef struct BattleFuncs {
    /* 0x00 */ BattleStats stats[2]; /* the player's, then the enemy's */
    /* 0x80 */ BattleStats *(*computeStats)(u8 side, s32 which, s32 index); /* FIGHTSTG_computeStats */
    /* 0x84 */ s32 (*computeDamage)(u8 side, s32 tech); /* of each hit */
    /* 0x88 */ s32 (*unk88)(u8 side, s32 id);
    /* 0x8C */ s32 (*getDamage)(s32 *args); /* of the event whose args these are */
    /* 0x90 */ s32 (*unk90)(u8 side, s32 id, s32 value);
    /* 0x94 */ s32 (*unk94)(u8 side, s32 id);
    /* 0x98 */ s32 (*getHeal)(u8 side, s32 index, s32 big); /* a part of its max HP */
    /* 0x9C */ s32 (*rollHit)(u8 side, s32 tech); /* whether a hit lands */
    /* 0xA0 */ s32 (*unkA0)(u8 side, s32 id);
    /* 0xA4 */ s32 (*unkA4)(u8 side, s32 id);
    /* 0xA8 */ s32 (*unkA8)(u8 side, s32 id);
    /* 0xAC */ s32 (*unkAC)(u8 side, s32 id);
    /* 0xB0 */ s32 (*unkB0)(u8 side, s32 id);
    /* 0xB4 */ s32 (*unkB4)(u8 side, s32 id);
    /* 0xB8 */ s32 (*unkB8)(u8 side, s32 id);
    /* 0xBC */ s32 (*unkBC)(u8 side, s32 id);
    /* 0xC0 */ s32 (*unkC0)(s32 actor, s32 id);
    /* 0xC4 */ s32 (*unkC4)(s32 actor, s32 id);
    /* 0xC8 */ s32 (*unkC8)(s32 actor, s32 id);
    /* 0xCC */ s32 (*unkCC)(s32 actor, s32 id);
#if VERSION_EU
    /* 0xD0 */ s32 (*unkEU)(s32 arg0, s32 arg1); /* func_800A15A8 */
#endif
    /* the European version's offsets are 4 more from here */
    /* 0xD0 */ s32 (*testRunAway)(u8 side);
    /* 0xD4 */ s32 (*testWakeUp)(u8 side, s32 value);
    /* 0xD8 */ s32 (*testConfusion)(u8 side);
    /* 0xDC */ s32 (*testParalysis)(u8 side); /* whether side's paralysis costs it the turn */
    /* 0xE0 */ void (*unkE0)(u8 side, s32 index, s32 stat, s32 percent); /* func_800A0B10: changes a fighter's stat boost */
    /* 0xE4 */ s32 (*unkE4)(s32 damage); /* from the partner's damage, up to 1000 */
    /* 0xE8 */ s32 (*unkE8)(u8 side, s32 id);
} BattleFuncs;

/* Shared between the overlay's objects */
extern Battle FIGHTSTG_battle;
extern BattleAction FIGHTSTG_action;
extern FighterCache FIGHTSTG_fighterCache;
extern BattleFuncs FIGHTSTG_battleFuncs;
extern s16 FIGHTSTG_boostStats[];
extern s32 FIGHTSTG_stageMusic[];
extern InterpFuncs FIGHTSTG_interp;
void FIGHTSTG_setMotion(Model *model, s32 motion, s32 restart);
void FIGHTSTG_updateModel(Model *model, Mesh **children);
Mesh *FIGHTSTG_createMesh(s32 archive, Vec2 texPos);
void FIGHTSTG_setModelColor(Model *model, s32 mode, CVECTOR *color);
void FIGHTSTG_setBoneNoBoundsCheck();
s32 FIGHTSTG_isMotionDone(Model *model);
Model *FIGHTSTG_createPlainModel(s32 file, s32 motionFile, Vec2 texPos, ModelControl *control);
void FIGHTSTG_drawMesh();
void FIGHTSTG_drawMeshWireframe();
void FIGHTSTG_updateStage(FightStage *task, Model **children);
void FIGHTSTG_updateLights(Lights *task);
void FIGHTSTG_setLights(Lights *task, LightSet *set);
void FIGHTSTG_fadeLights(Lights *task, LightSet *from, LightSet *to, s32 time);
LightSet *FIGHTSTG_getStageLights(Lights *task, s32 stage);
void FIGHTSTG_updateMove(MoveTask *task);
FighterInfo *FIGHTSTG_getFighterInfo(s32 id);
void FIGHTSTG_cacheFighter(s32 index);
void FIGHTSTG_getFighterRange(u32 enemy, s32 *min, s32 *max);
extern Vec2 FIGHTSTG_fighterTexPos[];
extern EventQueue FIGHTSTG_events;
extern u8 FIGHTSTG_statusEvents[]; /* FIGHTSTG_cureStatus's event types */
extern u8 FIGHTSTG_statusFlags[]; /* and the status flags they clear */
extern RECT FIGHTSTG_fighterCameraRect; /* FIGHTSTG_updatePartnerView's layer */
extern BattleEvent FIGHTSTG_newEvent;
extern BattleTableEntry *(*FIGHTSTG_battleTableFunc)(s32 id);
void FIGHTSTG_pushEvent(BattleEvent *event);
void FIGHTSTG_pushEventFirst(BattleEvent *event);
s32 FIGHTSTG_popEvent(void);
s32 FIGHTSTG_findEventFrom(s32 start);
s32 FIGHTSTG_findFirstEvent(s32 type);
s32 FIGHTSTG_findNextEvent(void);
s32 FIGHTSTG_findEvent(s32 type, u8 side, s32 fighter);
void FIGHTSTG_removeEvents(EventKey *key);

void FIGHTSTG_updateModels(Models *task);
s32 FIGHTSTG_findModelSlot(Models *task, s32 id);
s32 FIGHTSTG_findFreeModelSlot(Models *task);
void FIGHTSTG_removeFighterModel(Models *task, s32 id);
void FIGHTSTG_addFighterModel(Models *task, s32 id, s32 fighter, s32 visible);
ModelControl *FIGHTSTG_getModelControl(Models *task, s32 id);
void FIGHTSTG_setModelId(Models *task, s32 id, s32 newId);
s32 FIGHTSTG_getModelFighter(Models *task, s32 id);
void FIGHTSTG_faceModel(Models *task, s32 id);
void FIGHTSTG_setModelIdleMotion(Models *task, s32 id, s32 motion);
Model *FIGHTSTG_createIdlingModel(s32 file, s32 motionFile, Vec2 texPos, ModelControl *control);
void FIGHTSTG_updateRoot(Task *task, Task **children);
s32 FIGHTSTG_randomStage(void);
void FIGHTSTG_updateShotCamera(ShotCamera *task);
void FIGHTSTG_updateEnemyTurn(EnemyTurn *task, BattleChild *children);
void FIGHTSTG_updateBattleScript();
void FIGHTSTG_updateOneHpTurn(OneHpTurn *task, union BattleChild *children);
void FIGHTSTG_queueLastEnemy(void);
s32 FIGHTSTG_testEnemyCondition(u8 condition, s16 arg);
s32 FIGHTSTG_getEnemyAction(u8 kind);
ShotCamera *FIGHTSTG_createShotCamera(void);
Counterattack *FIGHTSTG_startCounterattack(s32 side, s32 received, s32 noKnockOutEvent);
ActionEvents *FIGHTSTG_startActionEvents(s32 arg0);
Jump *FIGHTSTG_startJump(ModelControl *control, s32 kind, s32 distance);
MoveTask *FIGHTSTG_startMove(ModelControl *control, ShortVec3 *to, s32 time);
s32 FIGHTSTG_getEventDelay(u8 side, s32 kind);
void FIGHTSTG_cureStatus(u8 side, s32 fighter, s32 item);
void FIGHTSTG_updateHpTweens(HpDisplay *task, TextWindow **windows);
void FIGHTSTG_drawHud(HpDisplay *task, TextWindow **windows);
void FIGHTSTG_updateHud(HpDisplay *task, TextWindow **windows);
void FIGHTSTG_updatePartnerView(PartnerView *task, FighterCamera **cameras);
void FIGHTSTG_updateCameraTurn();
void FIGHTSTG_updateCameraShots();
void FIGHTSTG_updatePlayerTurn(PlayerTurn *task, Task **children);
void func_8009D8B4(s32 layerId, s32 depth, DVECTOR *xy, CVECTOR *colors, s32 semi);
void FIGHTSTG_updateSwitchInMenu();
void FIGHTSTG_updateHitEffect();
void FIGHTSTG_updateScreenFade(ScreenFade *task);
void FIGHTSTG_startScreenFade(ScreenFade *task, s32 fadeIn, s32 duration);
void FIGHTSTG_updateDigimonChange();
void FIGHTSTG_updateTechAction();
void FIGHTSTG_updateEnemyAttack();
void FIGHTSTG_updateCamera(FighterCamera *task);
void FIGHTSTG_drawWhiteFlash(WhiteFlash *task);
void FIGHTSTG_updateWhiteFlash(WhiteFlash *task);
void FIGHTSTG_updateDigivolveMenu();
void FIGHTSTG_updateFirstTech();
void FIGHTSTG_updateItem();
s32 FIGHTSTG_runItemScript(BattleItem *task, BattleScript **children);
void FIGHTSTG_updateActionEvents(ActionEvents *task, union BattleChild *children);
SwitchInMenu *FIGHTSTG_createSwitchInMenu(s32 *result);
void FIGHTSTG_updateItemMenu();
void FIGHTSTG_updateTechMenu(TechMenu *task, TechMenuChild *children);
void func_8009C294();
void func_8009C330();
void func_8009C418();
void func_8009C500();
void func_8009C764();
void func_8009C998();
void func_8009CA84();
void func_8009CB4C();
void func_8009CBEC();
void func_8009CCD4();
void func_8009CDCC();
void func_8009C8EC();
void FIGHTSTG_queueBoostEnd(u8 side, s32 fighter, s32 kind, s32 arg3);
void FIGHTSTG_drawMessageBox();
void FIGHTSTG_stepMessage();
void FIGHTSTG_showMessage();
void FIGHTSTG_updateCommandMenu();
void FIGHTSTG_updateCounterattack();
s32 FIGHTSTG_findBattleTableIndex(s32 id);
BattleTableEntry *FIGHTSTG_getBattleTableEntry(s32 id);
void FIGHTSTG_updatePartnerInfo();
void FIGHTSTG_updateSwitchMenu();
void FIGHTSTG_updateConfusedMenu();
void FIGHTSTG_updateBattleCamera(BattleCamera *task);
void FIGHTSTG_fadeBattleCamera(BattleCamera *task, CameraView *from, CameraView *to, s32 time);
CameraView *func_80091788(BattleCamera *task, s32 id, s32 camera);
CameraView *func_80091950(BattleCamera *task);
void FIGHTSTG_updateEntrance();
void FIGHTSTG_endWhiteFlash(WhiteFlash *task, s32 frames);
WhiteFlash *FIGHTSTG_startWhiteFlash(s32 frames);
void FIGHTSTG_updateCursor();
BattleStats *FIGHTSTG_computeStats(u8 side, s32 which, s32 index);
extern s32 FIGHTSTG_opposedElements[];
void FIGHTSTG_stepMotion(Model *model);
extern EffectModelEntry FIGHTSTG_effectModels[];
Face *FIGHTSTG_createFace(Model *model, s32 fighter);
void FIGHTSTG_projectPoint(Layer *layer, SVECTOR *pos, ShortVec3 *out);
void func_80029DB8(GsRVIEW2 *view); /* GsSetRefView2 */
extern JumpParams FIGHTSTG_jumps[];
extern s32 FIGHTSTG_battleSounds[]; /* sound ids */
extern EffectSheet FIGHTSTG_effectSheets[];
extern SpriteEffectEntry FIGHTSTG_spriteEffects[];
void FIGHTSTG_drawSpriteAnim(void *arg, Layer *layer);
extern CameraView FIGHTSTG_fighterView;
extern s32 FIGHTSTG_eventPopModes[]; /* per event type, FIGHTSTG_popEvent takes (1), peeks at (-1) or skips (0) it */
MenuCursor *FIGHTSTG_createCursor(CursorLayout *layout);
extern DVECTOR FIGHTSTG_hpBars[2][4]; /* FIGHTSTG_drawHud's HP bars */
extern CVECTOR FIGHTSTG_hpBarColors[4];
extern DVECTOR FIGHTSTG_techGauge[4]; /* and its technique gauge */
extern CVECTOR FIGHTSTG_techGaugeColors[4];
extern s16 FIGHTSTG_iconX[2][3];
extern CursorLayout FIGHTSTG_commandCursor; /* FIGHTSTG_updateCommandMenu's cursor */
extern CursorLayout FIGHTSTG_changeCursor; /* FIGHTSTG_updateDigivolveMenu's cursor */
extern CursorLayout FIGHTSTG_itemCursor; /* FIGHTSTG_updateItemMenu's cursor */
extern CursorLayout FIGHTSTG_techCursor; /* FIGHTSTG_updateTechMenu's cursor */
extern CursorLayout FIGHTSTG_switchCursor; /* FIGHTSTG_updateSwitchMenu's cursor */
extern CursorLayout FIGHTSTG_pairCursors[2]; /* FIGHTSTG_updateSwitchInMenu's cursors */
extern CursorLayout FIGHTSTG_confusedCursor; /* FIGHTSTG_updateConfusedMenu's */
extern StatLine FIGHTSTG_statLines[13];
extern s16 FIGHTSTG_confusedMessages[16][2]; /* FIGHTSTG_updateConfusedMenu's results: the message, its line */
extern s16 FIGHTSTG_confusedLines[8]; /* FIGHTSTG_updateConfusedMenu's lines, shuffled */
extern RECT FIGHTSTG_cursorBarRect; /* where FIGHTSTG_drawCursorBar's bar is in VRAM */
extern DR_MOVE FIGHTSTG_cursorBarMoves[4]; /* FIGHTSTG_drawCursorBar's bar */
extern u_long FIGHTSTG_cursorBarOt[2]; /* their OT */
PartnerInfo *FIGHTSTG_createPartnerInfo(s32 partner, s32 page, s32 slot);
HpDisplay *FIGHTSTG_createHud(void);
CommandMenu *FIGHTSTG_createCommandMenu(s32 start, s32 *result);
PartnerView *FIGHTSTG_createPartnerView(void);
DigivolveMenu *FIGHTSTG_createDigivolveMenu(s32 *result);
ItemMenu *FIGHTSTG_createItemMenu(s32 *result);
TechMenu *FIGHTSTG_createTechMenu(s32 *result);
SwitchMenu *FIGHTSTG_createSwitchMenu(s32 *result, s32 *line, s32 canCancel);
SwitchInMenu *FIGHTSTG_createPairSwitchMenu(s32 *result, s32 *techResult);
ConfusedMenu *FIGHTSTG_createConfusedMenu(s32 *result, Task *partnerView, Task *shotCamera);
s32 FIGHTSTG_getPairDigimon(SwitchMenu *task, s32 index, s32 member);
extern s32 FIGHTSTG_mpWindowX[4]; /* FIGHTSTG_createSwitchInWindows's MP windows' x */
extern CameraShot FIGHTSTG_cameraShots[4][6];
extern u8 FIGHTSTG_nextShotLists[8][3];
#if VERSION_EU
extern CameraShot FIGHTSTG_euCameraShots[3][3];
#endif
void FIGHTSTG_setMessageName(BattleMessageBox *task, BattleMessageBoxWindows *w, s32 side, s32 index);
void FIGHTSTG_showFightersMessage(BattleMessageBox *task, BattleMessageBoxWindows *w, BattleMessage *msg);
void FIGHTSTG_showConfusedCommands(ConfusedMenu *task);
void FIGHTSTG_drawConfusedMessageBox(ConfusedMenu *task);
void FIGHTSTG_stepConfusedMessage(ConfusedMenu *task, ConfusedMenuWindows *w);
void FIGHTSTG_setConfusedName(ConfusedMenu *task, ConfusedMenuWindows *windows, s32 arg2);
void FIGHTSTG_showConfusedMessage(ConfusedMenu *task, s32 index, s32 arg2);
void FIGHTSTG_drawCursorSprites(MenuCursor *task);
void FIGHTSTG_drawCursorBar(s32 arg);
s32 func_8009E74C(s32 value, s32 arg1);
s32 func_8009E7E4(u8 side, s32 id, s32 value);
s32 func_8009F36C(u8 side, s32 id);
s32 func_8009F5D4(u8 side, s32 id);
s32 FIGHTSTG_getStageMotionsFile(s32 id);
extern s32 FIGHTSTG_partnerIdleMotion;
s32 FIGHTSTG_getEffectModelFile(s32 id);
EffectModel *FIGHTSTG_startEffectModel(s32 id, SVECTOR *pos, SVECTOR *rot);
BattleSound *FIGHTSTG_playBattleSound(s32 index, s32 time);
s32 FIGHTSTG_findEffectSheet(s32 effect, s32 *images, s32 *sheet, Vec2 *texPos);
SpriteEffect *FIGHTSTG_startSpriteEffect(s32 effect, SVECTOR *pos);
extern s32 FIGHTSTG_boostEvents[]; /* FIGHTSTG_queueBoostEnd's event types */
extern s32 FIGHTSTG_techEvents[]; /* and of FIGHTSTG_startRestriction */
#endif /* FIGHTSTG_H */
