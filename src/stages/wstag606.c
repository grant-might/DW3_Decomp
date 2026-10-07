#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x7E), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x7F), 0)) {
            children[0] = FIELDSTG_startEvent(0x50A);
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

void func_800A4DA0(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x7E), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A4DEC(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x7F), 1);
    FLAGS_00.applyAction(ITEM(5, 0x10E), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x603
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x613
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x2C000, 0x25C00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x39;
    FIELDSTG_state.music = MUSIC(0x39, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1289[] = {
    0x600, 1, 2,
    0x102, 2, 0x275, 0xCE, 5,
    0x100, 0x109, 0x291, 0xB9,
    0x101, 0x109, 1, 1,
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
    0x200, 0, 2, 0x109, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x109, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x7\n");
#endif
s16 script1290[] = {
    0x600, 1, 2,
    0x100, 2, 0x275, 0xCE,
    0x101, 2, 1, 5,
    0x100, 0x109, 0x290, 0xBF,
    0x101, 0x109, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x109, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x109, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x109, 0,
    0x301,
    0x300, 0x3C,
    0,
};
Battle area0Battle0 = { 116, 12, MUSIC(2, 0) };
Battle area0Battle1 = { 116, 12, MUSIC(2, 0) };
Battle area0Battle2 = { 116, 12, MUSIC(2, 0) };
Battle area0Battle3 = { 116, 12, MUSIC(2, 0) };
Battle area0Battle4 = { 164, 12, MUSIC(2, 0) };
Battle area0Battle5 = { 164, 12, MUSIC(2, 0) };
Battle area0Battle6 = { 164, 12, MUSIC(2, 0) };
Battle area0Battle7 = { 164, 12, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
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
Battle area3Battle0 = { 23, 19, MUSIC(0x22, 0) };
Battle area3Battle1 = { 319, 19, MUSIC(0x22, 0) };
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
    { 111, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x15C, 0x100, 0x70, 0, 0x150, 0x1F9 },
};
u16 actor0Talk0Conditions[] = { FLAG(0xA, 0xB), 0, CODES_END };
u16 actor0Talk0Actions[] = { FLAG(0xA, 0xB), 1, START_EVENT(0x3C), 1, CODES_END };
u16 actor0Talk1Conditions[] = { FLAG(0xA, 0xB), 1, CODES_END };
u16 actor1Talk0Conditions[] = { FLAG(0xA, 0xB), 0, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(0xA, 0xB), 1, START_EVENT(0x3C), 1, CODES_END };
u16 actor1Talk1Conditions[] = { FLAG(0xA, 0xB), 1, CODES_END };
u16 actor2Talk0Conditions[] = { FLAG(0xA, 0xB), 0, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(0xA, 0xB), 1, START_EVENT(0x3C), 1, CODES_END };
u16 actor2Talk1Conditions[] = { FLAG(0xA, 0xB), 1, CODES_END };
u16 actor3Talk0Conditions[] = { FLAG(0xA, 0xB), 0, CODES_END };
u16 actor3Talk0Actions[] = { FLAG(0xA, 0xB), 1, START_EVENT(0x3C), 1, CODES_END };
u16 actor3Talk1Conditions[] = { FLAG(0xA, 0xB), 1, CODES_END };
u16 actor4Talk0Conditions[] = { FLAG(0xA, 0xB), 0, CODES_END };
u16 actor4Talk0Actions[] = { FLAG(0xA, 0xB), 1, START_EVENT(0x3C), 1, CODES_END };
u16 actor4Talk1Conditions[] = { FLAG(0xA, 0xB), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, actor0Talk0Actions, 0x2D5 },
    { actor0Talk1Conditions, NULL, 0x110 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x2D5 },
    { actor1Talk1Conditions, NULL, 0x113 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, actor2Talk0Actions, 0x2D5 },
    { actor2Talk1Conditions, NULL, 0x112 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { actor3Talk0Conditions, actor3Talk0Actions, 0x2D5 },
    { actor3Talk1Conditions, NULL, 0x111 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { actor4Talk0Conditions, actor4Talk0Actions, 0x2D5 },
    { actor4Talk1Conditions, NULL, 0x114 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor1Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x109, 4, 657, 185, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x109, 4, 657, 185, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x109, 4, 657, 185, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x109, 4, 657, 185, 1 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x109, 4, 657, 185, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 5, 8, 0, 639, 174, 0, 0 },
    { 1, 0, 0x40, 2, 0x3C, 2, 0, 5, 8, 0, 671, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 6, 0, 782, 501, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 800, 478, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 6, 0, 576, 480, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 6, 0, 609, 493, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 6, 0, 646, 507, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 0xB, 8, 0, 587, 71, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 0xB, 8, 0, 573, 142, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 0xB, 8, 0, 705, 96, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 2, 0, 0xB, 8, 0, 692, 116, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 5, 8, 0, 709, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 0xB, 8, 0, 743, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 5, 6, 0, 710, 359, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 5, 6, 0, 758, 383, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 5, 6, 0, 854, 431, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 5, 6, 0, 32, 447, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 5, 6, 0, 416, 255, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 5, 6, 0, 463, 231, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2B7, 0x110, 0x8C, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2B7, 0x3A8, 0xE4, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2B7, 0x468, 0xFC, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1289, script1289, EVENT_TEXT(8), NULL, func_800A4DA0 },
    { 1290, script1290, EVENT_TEXT(9), NULL, func_800A4DEC },
    { -1, NULL, 0, NULL, NULL },
};
