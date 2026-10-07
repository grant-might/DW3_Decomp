#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x78), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x79), 0)) {
            children[0] = FIELDSTG_startEvent(0x504);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void func_800A4DA4(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x78), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(1), 1);
}

void func_800A4DF0(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x79), 1);
    FLAGS_00.applyAction(ITEM(5, 0xF2), 1);
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x579
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x589
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x11A00, 0x3AD00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0xB;
    FIELDSTG_state.music = MUSIC(0xB, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(1, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 4);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1283[] = {
    0x600, 1, 2,
    0x102, 2, 0x411, 0xA1, 5,
    0x100, 0x106, 0x431, 0x91,
    0x101, 0x106, 1, 1,
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
    0x200, 0, 2, 0x106, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x106, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 script1284[] = {
    0x600, 1, 2,
    0x100, 2, 0x411, 0xA1,
    0x101, 2, 1, 5,
    0x100, 0x106, 0x431, 0x91,
    0x101, 0x106, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x106, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x106, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x106, 0,
    0x301,
    0x300, 0x3C,
    0,
};
Battle area0Battle0 = { 96, 7, MUSIC(2, 0) };
Battle area0Battle1 = { 96, 7, MUSIC(2, 0) };
Battle area0Battle2 = { 96, 7, MUSIC(2, 0) };
Battle area0Battle3 = { 96, 7, MUSIC(2, 0) };
Battle area0Battle4 = { 97, 7, MUSIC(2, 0) };
Battle area0Battle5 = { 97, 7, MUSIC(2, 0) };
Battle area0Battle6 = { 97, 7, MUSIC(2, 0) };
Battle area0Battle7 = { 97, 7, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 0, 7, MUSIC(2, 0) };
Battle area1Battle1 = { 0, 7, MUSIC(2, 0) };
Battle area1Battle2 = { 0, 7, MUSIC(2, 0) };
Battle area1Battle3 = { 0, 7, MUSIC(2, 0) };
Battle area1Battle4 = { 0, 7, MUSIC(2, 0) };
Battle area1Battle5 = { 0, 7, MUSIC(2, 0) };
Battle area1Battle6 = { 0, 7, MUSIC(2, 0) };
Battle area1Battle7 = { 0, 7, MUSIC(2, 0) };
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
Battle area3Battle0 = { 13, 19, MUSIC(0x22, 0) };
Battle area3Battle1 = { 316, 19, MUSIC(0x22, 0) };
Battle area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle5 = { 97, 7, MUSIC(2, 0) };
Battle area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 68, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14E, 0x100, 0x38, 0, 0x140, 0x1FF },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x150, 0x1FF },
};
u16 actor0Talk0Conditions[] = { ITEM(3, 0x8E), 1, CODES_END };
u16 actor0Talk1Conditions[] = { ITEM(3, 0x8E), 0, FLAG(0, 0), 0, CODES_END };
u16 actor0Talk1Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor0Talk2Conditions[] = { ITEM(3, 0x8E), 0, FLAG(0, 0), 1, ITEM(2, 0x8A), 0, CODES_END };
u16 actor0Talk3Conditions[] = { ITEM(3, 0x8E), 0, FLAG(0, 0), 1, ITEM(2, 0x8A), 1, CODES_END };
u16 actor0Talk3Actions[] = {
    ITEM(3, 0x8E), 1,
    ITEM(3, 0x8D), 0,
    ITEM(2, 0x8A), 0,
    SPECIAL(0x13), 1,
    CODES_END,
};
u16 actor1Talk0Conditions[] = { FLAG(0xA, 7), 0, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(0xA, 7), 1, START_EVENT(0x39), 1, CODES_END };
u16 actor1Talk1Conditions[] = { FLAG(0xA, 7), 1, CODES_END };
u16 actor2Talk0Conditions[] = { FLAG(0xA, 7), 0, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(0xA, 7), 1, START_EVENT(0x39), 1, CODES_END };
u16 actor2Talk1Conditions[] = { FLAG(0xA, 7), 1, CODES_END };
u16 actor3Talk0Conditions[] = { FLAG(0xA, 7), 0, CODES_END };
u16 actor3Talk0Actions[] = { FLAG(0xA, 7), 1, START_EVENT(0x39), 1, CODES_END };
u16 actor3Talk1Conditions[] = { FLAG(0xA, 7), 1, CODES_END };
u16 actor4Talk0Conditions[] = { FLAG(0xA, 7), 0, CODES_END };
u16 actor4Talk0Actions[] = { FLAG(0xA, 7), 1, START_EVENT(0x39), 1, CODES_END };
u16 actor4Talk1Conditions[] = { FLAG(0xA, 7), 1, CODES_END };
u16 actor5Talk0Conditions[] = { FLAG(0xA, 7), 0, CODES_END };
u16 actor5Talk0Actions[] = { FLAG(0xA, 7), 1, START_EVENT(0x39), 1, CODES_END };
u16 actor5Talk1Conditions[] = { FLAG(0xA, 7), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, NULL, 0x2F6 },
    { actor0Talk1Conditions, actor0Talk1Actions, 0x2F7 },
    { actor0Talk2Conditions, NULL, 0x2F8 },
    { actor0Talk3Conditions, actor0Talk3Actions, 0x2F9 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x2D2 },
    { actor1Talk1Conditions, NULL, 0x49 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, actor2Talk0Actions, 0x2D2 },
    { actor2Talk1Conditions, NULL, 0x4C },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { actor3Talk0Conditions, actor3Talk0Actions, 0x2D2 },
    { actor3Talk1Conditions, NULL, 0x4A },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { actor4Talk0Conditions, actor4Talk0Actions, 0x2D2 },
    { actor4Talk1Conditions, NULL, 0x4B },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { actor5Talk0Conditions, actor5Talk0Actions, 0x2D2 },
    { actor5Talk1Conditions, NULL, 0x4D },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = {
    SPECIAL(0x48), 1,
    SPECIAL(0x50), 1,
    ITEM(3, 0x8D), 1,
    ITEM(3, 0x8E), 0,
    CODES_END,
};
u16 actor1Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor2Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x1C, 4, 97, 242, 7 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x106, 5, 1073, 145, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x106, 5, 1073, 145, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x106, 5, 1073, 145, 1 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x106, 5, 1073, 145, 1 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x106, 5, 1073, 145, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    &actor5,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x294, 0x510, 0x88, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 5, 8, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 5, 4, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 6, 1, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 6, 0, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 6, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 9, 0x7E, 0x1AF, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 9, 0x6D, 0x117, 0, 0, 0, 0 },
    { { { FLAG(0, 0xF), 0 }, { CODES_END, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1283, script1283, EVENT_TEXT(0x22), NULL, func_800A4DA4 },
    { 1284, script1284, EVENT_TEXT(0x23), NULL, func_800A4DF0 },
    { 9000, NULL, 0, FIELDSTG_startEventBattle5, NULL },
    { -1, NULL, 0, NULL, NULL },
};
