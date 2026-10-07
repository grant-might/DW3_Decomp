#include "common.h"
#include "stage.h"
extern AnimFrame D_800A5294[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A5294[0].duration;
        break;
    case TASK_RUN:
        for (tile = FIELDSTG_state.objects; tile->unk2 != 0; tile++) {
            if (tile->anim == 1) {
                tile->frame = stepLoopingAnimation(&task->anims[0], D_800A5294, 0);
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

/* Creates the stage helper task, and the event object when flag 0x407A is set and 0x407B is not */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = createTileAnims();
        task->nextState(task);
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x7A), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x7B), 0)) {
            children[1] = FIELDSTG_startEvent(0x506);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x8
#include "common/start_stage.inc.c"

void func_800A4FA4(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x7A), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A4FF0(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x7B), 1);
    FLAGS_00.applyAction(ITEM(5, 0xF5), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xE9
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x734
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x744
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x17A00, 0x44500};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x2F;
    FIELDSTG_state.music = MUSIC(0x2F, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1285[] = {
    0x600, 1, 2,
    0x102, 2, 0x37B, 0x153, 5,
    0x100, 0x108, 0x39B, 0x13D,
    0x101, 0x108, 1, 1,
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
    0x200, 0, 2, 0x108, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x108, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x800A\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x2\n");
#endif
s16 script1286[] = {
    0x600, 1, 2,
    0x100, 2, 0x37B, 0x153,
    0x101, 2, 1, 5,
    0x100, 0x108, 0x39B, 0x13D,
    0x101, 0x108, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x108, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x108, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x108, 0,
    0x301,
    0x300, 0x3C,
    0,
};
AnimFrame D_800A5294[] = {
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
Battle area0Battle0 = { 100, 4, MUSIC(2, 0) };
Battle area0Battle1 = { 100, 4, MUSIC(2, 0) };
Battle area0Battle2 = { 100, 4, MUSIC(2, 0) };
Battle area0Battle3 = { 100, 4, MUSIC(2, 0) };
Battle area0Battle4 = { 101, 4, MUSIC(2, 0) };
Battle area0Battle5 = { 101, 4, MUSIC(2, 0) };
Battle area0Battle6 = { 101, 4, MUSIC(2, 0) };
Battle area0Battle7 = { 101, 4, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 101, 4, MUSIC(2, 0) };
Battle area1Battle1 = { 101, 4, MUSIC(2, 0) };
Battle area1Battle2 = { 101, 4, MUSIC(2, 0) };
Battle area1Battle3 = { 101, 4, MUSIC(2, 0) };
Battle area1Battle4 = { 101, 4, MUSIC(2, 0) };
Battle area1Battle5 = { 101, 4, MUSIC(2, 0) };
Battle area1Battle6 = { 101, 4, MUSIC(2, 0) };
Battle area1Battle7 = { 101, 4, MUSIC(2, 0) };
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
Battle area3Battle0 = { 15, 19, MUSIC(0x22, 0) };
Battle area3Battle1 = { 317, 19, MUSIC(0x22, 0) };
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
    { 69, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16A, 0x100, 0xA8, 0, 0x170, 0x1FF },
};
u16 actor0Talk0Conditions[] = { FLAG(0xA, 9), 0, CODES_END };
u16 actor0Talk0Actions[] = { FLAG(0xA, 9), 1, START_EVENT(0x3A), 1, CODES_END };
u16 actor0Talk1Conditions[] = { FLAG(0xA, 9), 1, CODES_END };
u16 actor1Talk0Conditions[] = { FLAG(0xA, 9), 0, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(0xA, 9), 1, START_EVENT(0x3A), 1, CODES_END };
u16 actor1Talk1Conditions[] = { FLAG(0xA, 9), 1, CODES_END };
u16 actor2Talk0Conditions[] = { FLAG(0xA, 9), 0, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(0xA, 9), 1, START_EVENT(0x3A), 1, CODES_END };
u16 actor2Talk1Conditions[] = { FLAG(0xA, 9), 1, CODES_END };
u16 actor3Talk0Conditions[] = { FLAG(0xA, 9), 0, CODES_END };
u16 actor3Talk0Actions[] = { FLAG(0xA, 9), 1, START_EVENT(0x3A), 1, CODES_END };
u16 actor3Talk1Conditions[] = { FLAG(0xA, 9), 1, CODES_END };
u16 actor4Talk0Conditions[] = { FLAG(0xA, 9), 0, CODES_END };
u16 actor4Talk0Actions[] = { FLAG(0xA, 9), 1, START_EVENT(0x3A), 1, CODES_END };
u16 actor4Talk1Conditions[] = { FLAG(0xA, 9), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, actor0Talk0Actions, 0x2D3 },
    { actor0Talk1Conditions, NULL, 0x99 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x2D3 },
    { actor1Talk1Conditions, NULL, 0x9A },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, actor2Talk0Actions, 0x2D3 },
    { actor2Talk1Conditions, NULL, 0x9B },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { actor3Talk0Conditions, actor3Talk0Actions, 0x2D3 },
    { actor3Talk1Conditions, NULL, 0x9C },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { actor4Talk0Conditions, actor4Talk0Actions, 0x2D3 },
    { actor4Talk1Conditions, NULL, 0x9D },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor3Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x108, 4, 923, 317, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x108, 4, 923, 317, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x108, 4, 923, 317, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x108, 4, 923, 317, 1 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x108, 4, 923, 317, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 1, 0xE6, 2, 0x32, 0, 0, 0, 0, 0, 966, 364, 0, 0 },
    { 1, 0, 0x40, 2, 0x54, 2, 0, 2, 6, 0, 931, 293, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 176, 403, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 600, 1073, 0, 0 },
    { 1, 0, 0x78, 6, 7, 0, 0, 0, 0, 0, 745, 598, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 298, 442, 505, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x299, 0x648, 0xD0, 1, 0, 0, 0 },
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
    { 1285, script1285, EVENT_TEXT(0x1B), NULL, func_800A4FA4 },
    { 1286, script1286, EVENT_TEXT(0x1C), NULL, func_800A4FF0 },
    { -1, NULL, 0, NULL, NULL },
};
