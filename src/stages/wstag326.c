#include "common.h"
#include "stage.h"

void func_800A4CA4(StageTask *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
        for (tile = FIELDSTG_state.objects; tile->unk2 != 0; tile++) {
            switch (tile->anim) {
            case 1:
                tile->visible = 1;
                break;
            case 2:
                tile->visible = 1;
                break;
            case 3:
                tile->visible = 0;
                break;
            case 4:
                tile->visible = 0;
                break;
            }
        }
        break;
    case TASK_DONE:
        for (tile = FIELDSTG_state.objects; tile->unk2 != 0; tile++) {
            switch (tile->anim) {
            case 1:
                tile->visible = 0;
                break;
            case 2:
                tile->visible = 0;
                break;
            case 3:
                tile->visible = 1;
                break;
            case 4:
                tile->visible = 1;
                break;
            }
        }
        break;
    case TASK_KILL:
        break;
    }
}

void *func_800A4E24(s32 arg) {
    return createTaskWithId(func_800A4CA4, 0x50, 0, arg);
}

void func_800A4E54(StageTask *task, s32 id) {
    if (task != NULL && id == 0x35A) {
        task->setState(task, TASK_DONE);
    }
}

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x76), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x77), 0)) {
            children[1] = FIELDSTG_startEvent(0x502);
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

void func_800A4F88(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x76), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A4FD4(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x77), 1);
    FLAGS_00.applyAction(ITEM(0, 0x2A), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x52A
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x53A
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0xF300, 0x17A00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x2B;
    FIELDSTG_state.music = MUSIC(0x2B, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1281[] = {
    0x600, 1, 2,
    0x102, 2, 0x18D, 0x10E, 5,
    0x100, 0x105, 0x1A9, 0x100,
    0x101, 0x105, 1, 1,
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
    0x200, 0, 2, 0x105, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x105, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x6004\n");
#endif
s16 script1282[] = {
    0x600, 1, 2,
    0x100, 2, 0x18D, 0x10E,
    0x101, 2, 1, 5,
    0x100, 0x105, 0x1A9, 0x100,
    0x101, 0x105, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x105, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x105, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x105, 0,
    0x301,
    0x300, 0x3C,
    0,
};
Battle area0Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area0Battles = {
    0,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area1Battles = {
    0,
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
Battle area3Battle0 = { 31, 19, MUSIC(0x22, 0) };
Battle area3Battle1 = { 321, 19, MUSIC(0x22, 0) };
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
    { 129, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x140, 0x1FB },
};
u16 actor0Talk0Conditions[] = { PROGRESS(0x25), 1, FLAG(0xA, 0xD), 0, CODES_END };
u16 actor0Talk0Actions[] = { FLAG(0xA, 0xD), 1, START_EVENT(0x38), 1, CODES_END };
u16 actor0Talk1Conditions[] = { FLAG(0xA, 0xD), 1, PROGRESS(0x25), 1, CODES_END };
u16 actor0Talk2Conditions[] = { PROGRESS(0x26), 1, FLAG(0xA, 0xD), 0, CODES_END };
u16 actor0Talk2Actions[] = { FLAG(0xA, 0xD), 1, START_EVENT(0x38), 1, CODES_END };
u16 actor0Talk3Conditions[] = { FLAG(0xA, 0xD), 1, PROGRESS(0x26), 1, CODES_END };
u16 actor1Talk0Conditions[] = { FLAG(0xA, 0xD), 0, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(0xA, 0xD), 1, START_EVENT(0x38), 1, CODES_END };
u16 actor1Talk1Conditions[] = { FLAG(0xA, 0xD), 1, CODES_END };
u16 actor2Talk0Conditions[] = { FLAG(0xA, 0xD), 0, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(0xA, 0xD), 1, START_EVENT(0x38), 1, CODES_END };
u16 actor2Talk1Conditions[] = { FLAG(0xA, 0xD), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, actor0Talk0Actions, 0x1AB },
    { actor0Talk1Conditions, NULL, 0xB1 },
    { actor0Talk2Conditions, actor0Talk2Actions, 0x1AB },
    { actor0Talk3Conditions, NULL, 0xB2 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x1AB },
    { actor1Talk1Conditions, NULL, 0xB3 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, actor2Talk0Actions, 0x1AB },
    { actor2Talk1Conditions, NULL, 0xB4 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { SPECIAL(0x1C), 1, CODES_END };
u16 actor1Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x105, 4, 425, 256, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x105, 4, 425, 256, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x105, 4, 425, 256, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 374, 301, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 390, 293, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 406, 285, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 422, 277, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 458, 262, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 2, 0, 2, 0x10, 0, 438, 220, 0, 0 },
    { 1, 3, 0x40, 6, 0x33, 2, 0, 1, 0x10, 0, 438, 220, 0, 0 },
    { 1, 4, 0x40, 6, 0x35, 2, 0, 3, 4, 0, 444, 202, 0, 0 },
    { 1, 2, 0x40, 6, 0x34, 2, 0, 3, 4, 0, 444, 202, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 294, 261, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 310, 253, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 326, 245, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 342, 237, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 374, 220, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 0, 0, 0, 0, 0, 448, 207, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x28A, 0x3F8, 0x2DC, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1281, script1281, EVENT_TEXT(0x20), NULL, func_800A4F88 },
    { 1282, script1282, EVENT_TEXT(0x21), NULL, func_800A4FD4 },
    { -1, NULL, 0, NULL, NULL },
};
