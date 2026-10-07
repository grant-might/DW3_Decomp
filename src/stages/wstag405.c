#include "common.h"
#include "stage.h"
extern AnimFrame D_800A52A8[];

#include "common/step_looping_animation.inc.c"

/* Sets the frame of the map objects with animation 1 */
void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A52A8[0].duration;
        break;
    case TASK_RUN:
        for (tile = FIELDSTG_state.objects; tile->unk2 != 0; tile++) {
            if (tile->anim == 1) {
                tile->frame = stepLoopingAnimation(&task->anims[0], D_800A52A8, 0);
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *createTileAnims(void) {
    return createTask(updateTileAnims, 0x54, 0);
}

/* Creates the event object of progress 4 when flag 0x400F is set and 0x4010 is not, and the stage helper task */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 4 && FLAGS_00.checkCondition(FLAG(0x40, 0xF), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x10), 0)) {
            children[0] = FIELDSTG_startEvent(0x3D);
        }
        children[1] = createTileAnims();
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x8
#include "common/start_stage.inc.c"

void func_800A4FB8(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xF), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A5004(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x10), 1);
    FLAGS_00.applyAction(ITEM(3, 0x99), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x248
#define STAGE_ARCHIVE 0x3C9
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x257
#define STAGE_ARCHIVE 0x3D9
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_ARCHIVE;
    FIELDSTG_state.start = (Vec2){0x16B00, 0x44400};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x2F;
    FIELDSTG_state.music = MUSIC(0x2F, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script60[] = {
    0x600, 1, 2,
    0x102, 2, 0x37C, 0x153, 5,
    0x100, 0x5A, 0x39C, 0x143,
    0x101, 0x5A, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0x5A, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x5A, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x1B6\n");
#endif
s16 script61[] = {
    0x600, 1, 2,
    0x100, 2, 0x37C, 0x153,
    0x101, 2, 1, 5,
    0x100, 0x5A, 0x39C, 0x143,
    0x101, 0x5A, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x5A, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x5A, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x5A, 0,
    0x301,
    0x300, 0x3C,
    0,
};
AnimFrame D_800A52A8[] = {
    { 50, 8 }, { 51, 4 }, { 52, 8 }, { 53, 4 },
    { 54, 8 }, { 55, 4 }, { 56, 8 }, { 57, 16 },
    { 58, 4 }, { 59, 8 }, { 60, 4 }, { 61, 8 },
    { 62, 8 }, { 63, 12 }, { 64, 20 }, { 65, 4 },
    { 66, 8 }, { 67, 4 }, { 68, 8 }, { 69, 8 },
    { 70, 8 }, { 71, 8 }, { 72, 8 }, { 73, 4 },
    { 74, 8 }, { 75, 4 }, { 76, 8 }, { 77, 8 },
    { 78, 8 }, { 79, 8 }, { 80, 8 }, { 81, 12 },
    { 82, 8 }, { 83, 30 }, { 255, 0 },
};
Battle area0Battle0 = { 50, 4, MUSIC(2, 0) };
Battle area0Battle1 = { 50, 4, MUSIC(2, 0) };
Battle area0Battle2 = { 50, 4, MUSIC(2, 0) };
Battle area0Battle3 = { 51, 4, MUSIC(2, 0) };
Battle area0Battle4 = { 51, 4, MUSIC(2, 0) };
Battle area0Battle5 = { 51, 4, MUSIC(2, 0) };
Battle area0Battle6 = { 52, 4, MUSIC(2, 0) };
Battle area0Battle7 = { 52, 4, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 51, 4, MUSIC(2, 0) };
Battle area1Battle1 = { 51, 4, MUSIC(2, 0) };
Battle area1Battle2 = { 51, 4, MUSIC(2, 0) };
Battle area1Battle3 = { 51, 4, MUSIC(2, 0) };
Battle area1Battle4 = { 51, 4, MUSIC(2, 0) };
Battle area1Battle5 = { 51, 4, MUSIC(2, 0) };
Battle area1Battle6 = { 51, 4, MUSIC(2, 0) };
Battle area1Battle7 = { 51, 4, MUSIC(2, 0) };
BattleList area1Battles = {
    5,
    { &area1Battle0, &area1Battle1, &area1Battle2, &area1Battle3,
      &area1Battle4, &area1Battle5, &area1Battle6, &area1Battle7 },
};
Battle area2Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area2Battles = {
    0,
    { &area2Battle0, &area2Battle1, &area2Battle2, &area2Battle3,
      &area2Battle4, &area2Battle5, &area2Battle6, &area2Battle7 },
};
Battle area3Battle0 = { 2, 19, MUSIC(0x22, 0) };
Battle area3Battle1 = { 310, 19, MUSIC(0x22, 0) };
Battle area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 12, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B4, 0x120, 0x1D0, 0x20, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1A0, 0x120, 0x180, 0x20, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1AA, 0x148, 0x1A8, 0x48, 0x160, 0x1FE },
};
u16 actor0Talk0Conditions[] = { FLAG(0x1A, 0x2D), 0, CODES_END };
u16 actor0Talk0Actions[] = { FLAG(0x1A, 0x2D), 1, CODES_END };
u16 actor0Talk1Conditions[] = { FLAG(0x1A, 0x2D), 1, SPECIAL(0x2A), 0, CODES_END };
u16 actor0Talk2Conditions[] = {
    SPECIAL(0x25), 0,
    FLAG(0x1A, 0x2D), 1,
    SPECIAL(0x2A), 1,
    CODES_END,
};
u16 actor0Talk3Conditions[] = {
    SPECIAL(0x25), 1,
    SPECIAL(0x27), 0,
    FLAG(0x1A, 0x2D), 1,
    SPECIAL(0x2A), 1,
    CODES_END,
};
u16 actor0Talk3Actions[] = { FLAG(6, 0), 1, CODES_END };
u16 actor0Talk4Conditions[] = {
    SPECIAL(0x25), 1,
    SPECIAL(0x27), 1,
    FLAG(0x1A, 0x2D), 1,
    SPECIAL(0x2A), 1,
    CODES_END,
};
u16 actor1Talk0Conditions[] = { SPECIAL(0xB), 0, CODES_END };
u16 actor1Talk0Actions[] = { SPECIAL(0x31), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor1Talk1Conditions[] = { SPECIAL(0xB), 1, CODES_END };
u16 actor2Talk0Conditions[] = { FLAG(0x1A, 0x2D), 0, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(0x1A, 0x2D), 1, CODES_END };
u16 actor2Talk1Conditions[] = { FLAG(0x1A, 0x2D), 1, SPECIAL(0x2A), 0, CODES_END };
u16 actor2Talk2Conditions[] = {
    FLAG(0x1A, 0x2D), 1,
    SPECIAL(0x2A), 1,
    SPECIAL(0x25), 0,
    CODES_END,
};
u16 actor2Talk3Conditions[] = {
    FLAG(0x1A, 0x2D), 1,
    SPECIAL(0x2A), 1,
    SPECIAL(0x25), 1,
    SPECIAL(0x27), 0,
    CODES_END,
};
u16 actor2Talk3Actions[] = { FLAG(6, 0), 1, CODES_END };
u16 actor2Talk4Conditions[] = {
    FLAG(0x1A, 0x2D), 1,
    SPECIAL(0x2A), 1,
    SPECIAL(0x25), 1,
    SPECIAL(0x27), 1,
    CODES_END,
};
u16 actor3Talk0Conditions[] = { SPECIAL(0xB), 0, CODES_END };
u16 actor3Talk0Actions[] = { SPECIAL(0x31), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor3Talk1Conditions[] = { SPECIAL(0xB), 1, CODES_END };
u16 actor4Talk0Conditions[] = { FLAG(0x1C, 0x10), 0, CODES_END };
u16 actor4Talk1Conditions[] = { FLAG(0x1C, 0x10), 1, FLAG(0x1C, 0x11), 0, CODES_END };
u16 actor4Talk1Actions[] = {
    START_EVENT(0x2F), 1,
    FLAG(0x1C, 0x11), 1,
    FLAG(0xA, 1), 1,
    CODES_END,
};
u16 actor4Talk2Conditions[] = { FLAG(0x1C, 0x10), 1, FLAG(0x1C, 0x11), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, actor0Talk0Actions, 0x2B2 },
    { actor0Talk1Conditions, NULL, 0x2B7 },
    { actor0Talk2Conditions, NULL, 0x2B8 },
    { actor0Talk3Conditions, actor0Talk3Actions, 0x2B3 },
    { actor0Talk4Conditions, NULL, 0x2BC },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x2B4 },
    { actor1Talk1Conditions, NULL, 0x2B6 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, actor2Talk0Actions, 0x2B2 },
    { actor2Talk1Conditions, NULL, 0x2B7 },
    { actor2Talk2Conditions, NULL, 0x2B8 },
    { actor2Talk3Conditions, actor2Talk3Actions, 0x2B3 },
    { actor2Talk4Conditions, NULL, 0x2BC },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { actor3Talk0Conditions, actor3Talk0Actions, 0x2B4 },
    { actor3Talk1Conditions, NULL, 0x2B6 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { actor4Talk0Conditions, NULL, 0xF1 },
    { actor4Talk1Conditions, actor4Talk1Actions, 0x2DD },
    { actor4Talk2Conditions, NULL, 0x2DE },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x2E9 },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x2F6 },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x2F4 },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { NULL, NULL, 0x2EF },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { NULL, NULL, 0x2F1 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, NULL, 0x2F2 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, NULL, 0x2F7 },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { NULL, NULL, 0x2F5 },
    { NULL, NULL, 0 },
};
FieldTalk actor13Talks[] = {
    { NULL, NULL, 0x2F3 },
    { NULL, NULL, 0 },
};
FieldTalk actor14Talks[] = {
    { NULL, NULL, 0x2F0 },
    { NULL, NULL, 0 },
};
FieldTalk actor15Talks[] = {
    { NULL, NULL, 0x2B5 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { PROGRESS(4), 0, ITEM(0, 6), 0, SPECIAL(0x22), 1, CODES_END };
u16 actor1Conditions[] = { SPECIAL(0x22), 1, PROGRESS(4), 0, ITEM(0, 6), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x2B), 1, ITEM(0, 6), 0, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x2B), 1, ITEM(0, 6), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(4), 1, CODES_END };
u16 actor5Conditions[] = { SPECIAL(0x15), 1, CODES_END };
u16 actor6Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor7Conditions[] = { SPECIAL(0x19), 1, CODES_END };
u16 actor8Conditions[] = { PROGRESS(0xC), 1, CODES_END };
u16 actor9Conditions[] = { SPECIAL(0x16), 1, CODES_END };
u16 actor10Conditions[] = { SPECIAL(0x17), 1, CODES_END };
u16 actor11Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor12Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor13Conditions[] = { SPECIAL(0x18), 1, CODES_END };
u16 actor14Conditions[] = { PROGRESS(0xE), 1, CODES_END };
u16 actor15Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x2B, 4, 764, 1138, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x2B, 4, 764, 1138, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x2B, 4, 764, 1138, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x2B, 4, 764, 1138, 1 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor13 = { actor13Conditions, actor13Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor14 = { actor14Conditions, actor14Talks, 0x5A, 5, 924, 323, 1 };
FieldActorEntry actor15 = { actor15Conditions, actor15Talks, 0x9D, 6, 764, 1138, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    &actor5,
    &actor6,
    &actor7,
    &actor8,
    &actor9,
    &actor10,
    &actor11,
    &actor12,
    &actor13,
    &actor14,
    &actor15,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 1, 0xE6, 2, 0x32, 0, 0, 0, 0, 0, 966, 364, 0, 0 },
    { 1, 0, 0x40, 2, 0x54, 2, 0, 2, 6, 0, 931, 293, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 179, 400, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 602, 1071, 0, 0 },
    { 1, 0, 0xC8, 6, 7, 0, 0, 0, 0, 0, 745, 598, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 298, 442, 505, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x22A, 0x648, 0xD0, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 8, 0xF0, 0x4D8, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 8, 0x100, 0x450, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 9, 0x102, 0x420, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 9, 0xF2, 0x388, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 6, 0x1D2, 0x4C8, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 6, 0x1C2, 0x460, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 0xF, 0x1AF, 0x428, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 0xF, 0x1BF, 0x330, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 0x16, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 9, 0x330, 0x208, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 9, 0x340, 0x170, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 60, script60, EVENT_TEXT(0), NULL, func_800A4FB8 },
    { 61, script61, EVENT_TEXT(1), NULL, func_800A5004 },
    { -1, NULL, 0, NULL, NULL },
};
