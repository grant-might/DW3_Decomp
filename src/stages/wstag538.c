#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x7C), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x7D), 0)) {
            children[0] = FIELDSTG_startEvent(0x508);
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
    FLAGS_00.applyAction(FLAG(0x40, 0x7C), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A4DEC(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x7D), 1);
    FLAGS_00.applyAction(ITEM(5, 0x100), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x5BE
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x5CE
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0xCE00, 0xA700};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x11;
    FIELDSTG_state.music = MUSIC(0x11, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1287[] = {
    0x600, 1, 2,
    0x102, 2, 0x361, 0x94, 5,
    0x100, 0x107, 0x377, 0x85,
    0x101, 0x107, 1, 1,
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
    0x200, 0, 2, 0x107, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x107, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x300\n");
#endif
s16 script1288[] = {
    0x600, 1, 2,
    0x100, 2, 0x361, 0x94,
    0x101, 2, 1, 5,
    0x100, 0x107, 0x377, 0x85,
    0x101, 0x107, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x107, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x107, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x107, 0,
    0x301,
    0x300, 0x3C,
    0,
};
Battle area0Battle0 = { 108, 6, MUSIC(2, 0) };
Battle area0Battle1 = { 108, 6, MUSIC(2, 0) };
Battle area0Battle2 = { 108, 6, MUSIC(2, 0) };
Battle area0Battle3 = { 108, 6, MUSIC(2, 0) };
Battle area0Battle4 = { 108, 6, MUSIC(2, 0) };
Battle area0Battle5 = { 108, 6, MUSIC(2, 0) };
Battle area0Battle6 = { 108, 6, MUSIC(2, 0) };
Battle area0Battle7 = { 108, 6, MUSIC(2, 0) };
BattleList area0Battles = {
    4,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 0, 6, MUSIC(2, 0) };
Battle area1Battle1 = { 0, 6, MUSIC(2, 0) };
Battle area1Battle2 = { 0, 6, MUSIC(2, 0) };
Battle area1Battle3 = { 0, 6, MUSIC(2, 0) };
Battle area1Battle4 = { 0, 6, MUSIC(2, 0) };
Battle area1Battle5 = { 0, 6, MUSIC(2, 0) };
Battle area1Battle6 = { 0, 6, MUSIC(2, 0) };
Battle area1Battle7 = { 0, 6, MUSIC(2, 0) };
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
Battle area3Battle0 = { 17, 19, MUSIC(0x22, 0) };
Battle area3Battle1 = { 318, 19, MUSIC(0x22, 0) };
Battle area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle5 = { 108, 6, MUSIC(2, 0) };
Battle area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 80, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x170, 0x1F5 },
    { 0x180, 0x100, 0x180, 0x100, 0x100, 0, 0x160, 0x1F4 },
};
u16 actor0Talk0Conditions[] = { ITEM(3, 0x75), 1, CODES_END };
u16 actor0Talk1Conditions[] = { ITEM(3, 0x75), 0, FLAG(0, 0), 0, CODES_END };
u16 actor0Talk1Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor0Talk2Conditions[] = { ITEM(3, 0x75), 0, FLAG(0, 0), 1, ITEM(2, 0x71), 0, CODES_END };
u16 actor0Talk3Conditions[] = { ITEM(3, 0x75), 0, FLAG(0, 0), 1, ITEM(2, 0x71), 1, CODES_END };
u16 actor0Talk3Actions[] = {
    ITEM(3, 0x75), 1,
    ITEM(3, 0x74), 0,
    ITEM(2, 0x71), 0,
    SPECIAL(0x13), 1,
    CODES_END,
};
u16 actor1Talk0Conditions[] = { FLAG(0xA, 0xA), 0, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(0xA, 0xA), 1, START_EVENT(0x3B), 1, CODES_END };
u16 actor1Talk1Conditions[] = { FLAG(0xA, 0xA), 1, CODES_END };
u16 actor2Talk0Conditions[] = { FLAG(0xA, 0xA), 0, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(0xA, 0xA), 1, START_EVENT(0x3B), 1, CODES_END };
u16 actor2Talk1Conditions[] = { FLAG(0xA, 0xA), 1, CODES_END };
u16 actor3Talk0Conditions[] = { FLAG(0xA, 0xA), 0, CODES_END };
u16 actor3Talk0Actions[] = { FLAG(0xA, 0xA), 1, START_EVENT(0x3B), 1, CODES_END };
u16 actor3Talk1Conditions[] = { FLAG(0xA, 0xA), 1, CODES_END };
u16 actor4Talk0Conditions[] = { FLAG(0xA, 0xA), 0, CODES_END };
u16 actor4Talk0Actions[] = { FLAG(0xA, 0xA), 1, START_EVENT(0x3B), 1, CODES_END };
u16 actor4Talk1Conditions[] = { FLAG(0xA, 0xA), 1, CODES_END };
u16 actor5Talk0Conditions[] = { FLAG(0xA, 0xA), 0, CODES_END };
u16 actor5Talk0Actions[] = { FLAG(0xA, 0xA), 1, START_EVENT(0x3B), 1, CODES_END };
u16 actor5Talk1Conditions[] = { FLAG(0xA, 0xA), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, NULL, 0x2E6 },
    { actor0Talk1Conditions, actor0Talk1Actions, 0x2E7 },
    { actor0Talk2Conditions, NULL, 0x2E8 },
    { actor0Talk3Conditions, actor0Talk3Actions, 0x2E9 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x2D4 },
    { actor1Talk1Conditions, NULL, 0xB5 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, actor2Talk0Actions, 0x2D4 },
    { actor2Talk1Conditions, NULL, 0xB9 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { actor3Talk0Conditions, actor3Talk0Actions, 0x2D4 },
    { actor3Talk1Conditions, NULL, 0xB8 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { actor4Talk0Conditions, actor4Talk0Actions, 0x2D4 },
    { actor4Talk1Conditions, NULL, 0xB7 },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { actor5Talk0Conditions, actor5Talk0Actions, 0x2D4 },
    { actor5Talk1Conditions, NULL, 0xB6 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = {
    SPECIAL(0x44), 1,
    SPECIAL(0x4C), 1,
    ITEM(3, 0x74), 1,
    ITEM(3, 0x75), 0,
    CODES_END,
};
u16 actor1Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor3Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x25), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0xAD, 4, 962, 353, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x107, 5, 887, 133, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x107, 5, 887, 133, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x107, 5, 887, 133, 1 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x107, 5, 887, 133, 1 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x107, 5, 887, 133, 1 };
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
    { 1, 0, 0x70, 2, 0x36, 1, 0x36, 0x3B, 6, 0, 949, 142, 0, 0 },
    { 1, 0, 0x70, 2, 0x3C, 1, 0x3C, 0x41, 6, 0, 941, 141, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 999, 304, 0, 0 },
    { 1, 0, 0x78, 6, 0x32, 2, 0, 0xD, 8, 0, 1000, 393, 0, 0 },
    { 1, 0, 0x78, 6, 0x33, 2, 0, 0xD, 8, 0, 993, 389, 0, 0 },
    { 1, 0, 0x70, 6, 0x34, 2, 0, 0xD, 8, 0, 642, 153, 0, 0 },
    { 1, 0, 0x70, 6, 0x35, 2, 0, 0xD, 8, 0, 634, 144, 0, 0 },
    { 1, 0, 0x70, 6, 0x42, 1, 0x42, 0x47, 6, 0, 955, 71, 0, 0 },
    { 1, 0, 0x70, 6, 0x48, 1, 0x48, 0x4D, 6, 0, 946, 71, 0, 0 },
    { 1, 0, 0x70, 6, 0x4E, 1, 0x4E, 0x53, 6, 0, 618, 227, 0, 0 },
    { 1, 0, 0x70, 6, 0x4E, 1, 0x4E, 0x53, 6, 0, 730, 171, 0, 0 },
    { 1, 0, 0x70, 6, 0x54, 2, 0, 3, 6, 0, 614, 232, 0, 0 },
    { 1, 0, 0x70, 6, 0x54, 2, 0, 3, 6, 0, 726, 176, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 258, 102, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 531, 190, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 758, 111, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 806, 87, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 827, 275, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 859, 292, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 1002, 301, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 266, 105, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 539, 193, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 766, 114, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 814, 90, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 835, 279, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 867, 295, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 1010, 304, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2AF, 0x3E0, 0x1B0, 3, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 5, 0x3A0, 0x190, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 5, 0x3B0, 0x1E8, 0, 0, 0, 0 },
    { { { FLAG(0, 0xF), 0 }, { CODES_END, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1287, script1287, EVENT_TEXT(0x14), NULL, func_800A4DA0 },
    { 1288, script1288, EVENT_TEXT(0x15), NULL, func_800A4DEC },
    { 9000, NULL, 0, FIELDSTG_startEventBattle5, NULL },
    { -1, NULL, 0, NULL, NULL },
};
