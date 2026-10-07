#include "common.h"
#include "stage.h"

/* Creates the event object of flags 0x40CB and 0x40CC */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (FLAGS_00.checkCondition(FLAG(0x40, 0xCB), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0xCC), 0)) {
            children[0] = FIELDSTG_startEvent(0x5B0);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void func_800A4DA8(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xB), 1);
}

void func_800A4DD4(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xCB), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A4E20(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xCC), 1);
    FLAGS_00.applyAction(ITEM(3, 0x66), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x544
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x554
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0xD400, 0xA700};
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

s16 script700[] = {
    0x101, 2, 1, 7,
    0x100, 0x8D, 0x374, 0x17A,
    0x101, 0x8D, 1, 7,
    0x101, 0x323, 0x325, 2,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 2, 0x354, 0x16A, 7,
    0x302, 2,
    0x101, 2, 1, 7,
    0x101, 0x323, 0x325, 0x8D,
    0x300, 0x3C,
    0x101, 0x8D, 1, 3,
    0x101, 0x323, 0x326, 0x8D,
    0x300, 0x1E,
    0x200, 0, 1, 0x8D, 3,
    0x301,
    0x101, 2, 1, 6,
    0x101, 0x8D, 1, 6,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x601, 0, 0x3D2, 0x1A2,
    0x101, 0x323, 0x326, 2,
    0x300, 0x3C,
    0x300, 0xB4,
    0x600, 0, 2,
    0x200, 0, 2, 2, 2,
    0x101, 2, 7, 6,
    0x301,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x200, 0, 3, 0x8D, 3,
    0x101, 2, 1, 7,
    0x101, 0x8D, 1, 3,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x37C, 2,
    0x300, 0x78,
    0x101, 2, 1, 6,
    0x101, 0x8D, 1, 6,
    0x101, 0x323, 0x325, 2,
    0x101, 0x324, 0x325, 0x8D,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x101, 0x324, 0x326, 0x8D,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xA, 2, 0,
    0x301,
    0x102, 2, 0x35C, 0x16E, 7,
    0x302, 2,
    0x101, 0x323, 0x325, 0x8D,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x8D,
    0x300, 0x1E,
    0x200, 0, 5, 0x8D, 3,
    0x101, 0x8D, 1, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 7, 0x8D, 3,
    0x301,
    0x101, 0x323, 0x327, 0x8D,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x8D,
    0x300, 0x1E,
    0x200, 0, 8, 0x8D, 3,
    0x301,
    0x300, 0x1E,
    0x102, 0x8D, 0x3B0, 0x15D, 5,
    0x302, 0x8D,
    0x102, 2, 0x374, 0x17A, 7,
    0x101, 0x8D, 1, 1,
    0x302, 2,
    0x200, 0, 0xB, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 0xC, 0x8D, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 2, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x394, 0x18A, 7,
    0x302, 2,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0,
};
s16 script1455[] = {
    0x600, 1, 2,
    0x102, 2, 0x357, 0x93, 5,
    0x100, 0x85, 0x377, 0x85,
    0x101, 0x85, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x24,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0x85, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x85, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 script1456[] = {
    0x600, 1, 2,
    0x100, 2, 0x357, 0x93,
    0x101, 2, 1, 5,
    0x100, 0x85, 0x377, 0x85,
    0x101, 0x85, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x85, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x85, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x3C,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x85, 0,
    0x301,
    0x300, 0x3C,
    0,
};
Battle area0Battle0 = { 91, 6, MUSIC(2, 0) };
Battle area0Battle1 = { 91, 6, MUSIC(2, 0) };
Battle area0Battle2 = { 91, 6, MUSIC(2, 0) };
Battle area0Battle3 = { 91, 6, MUSIC(2, 0) };
Battle area0Battle4 = { 91, 6, MUSIC(2, 0) };
Battle area0Battle5 = { 91, 6, MUSIC(2, 0) };
Battle area0Battle6 = { 91, 6, MUSIC(2, 0) };
Battle area0Battle7 = { 91, 6, MUSIC(2, 0) };
BattleList area0Battles = {
    4,
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
Battle area3Battle0 = { 11, 19, MUSIC(0x22, 0) };
Battle area3Battle1 = { 314, 19, MUSIC(0x22, 0) };
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
    { 126, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x170, 0x1FC },
    { 0x140, 0x100, 0x14E, 0x100, 0x38, 0, 0x140, 0x1FB },
};
u16 actor0Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor0Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor0Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor1Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor1Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor2Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x36), 1, CODES_END };
u16 actor2Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor3Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor3Talk0Actions[] = { START_EVENT(0x64), 1, FLAG(0xA, 2), 1, CODES_END };
u16 actor3Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor4Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor4Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor4Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor5Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor5Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor5Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor6Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor6Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor6Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor7Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor7Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor7Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor8Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor8Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor8Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor9Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor9Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor9Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor10Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor10Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor10Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor11Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor11Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor11Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor12Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor12Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor12Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor13Talk0Conditions[] = { FLAG(0xA, 2), 0, CODES_END };
u16 actor13Talk0Actions[] = { FLAG(0xA, 2), 1, START_EVENT(0x64), 1, CODES_END };
u16 actor13Talk1Conditions[] = { FLAG(0xA, 2), 1, CODES_END };
u16 actor14Talk0Conditions[] = { FLAG(0, 0), 0, CODES_END };
u16 actor14Talk0Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor14Talk1Conditions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor16Talk0Conditions[] = { FLAG(0, 0), 0, CODES_END };
u16 actor16Talk0Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor16Talk1Conditions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor18Talk0Conditions[] = { FLAG(0, 0), 0, CODES_END };
u16 actor18Talk0Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor18Talk1Conditions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor19Talk0Conditions[] = { FLAG(0, 0), 0, CODES_END };
u16 actor19Talk0Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor19Talk1Conditions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor20Talk0Conditions[] = { FLAG(0, 0), 0, CODES_END };
u16 actor20Talk0Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor20Talk1Conditions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor22Talk0Conditions[] = { FLAG(0, 0), 0, CODES_END };
u16 actor22Talk0Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor22Talk1Conditions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor25Talk0Conditions[] = { FLAG(0, 0), 0, CODES_END };
u16 actor25Talk0Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor25Talk1Conditions[] = { FLAG(0, 0), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, actor0Talk0Actions, 0x2F8 },
    { actor0Talk1Conditions, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x2F8 },
    { actor1Talk1Conditions, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, actor2Talk0Actions, 0x2F8 },
    { actor2Talk1Conditions, NULL, 0x1EF },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { actor3Talk0Conditions, actor3Talk0Actions, 0x2F8 },
    { actor3Talk1Conditions, NULL, 0x1EC },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { actor4Talk0Conditions, actor4Talk0Actions, 0x2F8 },
    { actor4Talk1Conditions, NULL, 0x1ED },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { actor5Talk0Conditions, actor5Talk0Actions, 0x2F8 },
    { actor5Talk1Conditions, NULL, 0x1EE },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { actor6Talk0Conditions, actor6Talk0Actions, 0x2F8 },
    { actor6Talk1Conditions, NULL, 0x1EB },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { actor7Talk0Conditions, actor7Talk0Actions, 0x2F8 },
    { actor7Talk1Conditions, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { actor8Talk0Conditions, actor8Talk0Actions, 0x2F8 },
    { actor8Talk1Conditions, NULL, 0x1EC },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { actor9Talk0Conditions, actor9Talk0Actions, 0x2F8 },
    { actor9Talk1Conditions, NULL, 0x1EC },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { actor10Talk0Conditions, actor10Talk0Actions, 0x2F8 },
    { actor10Talk1Conditions, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { actor11Talk0Conditions, actor11Talk0Actions, 0x2F8 },
    { actor11Talk1Conditions, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { actor12Talk0Conditions, actor12Talk0Actions, 0x2F8 },
    { actor12Talk1Conditions, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk actor13Talks[] = {
    { actor13Talk0Conditions, actor13Talk0Actions, 0x2F8 },
    { actor13Talk1Conditions, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk actor14Talks[] = {
    { actor14Talk0Conditions, actor14Talk0Actions, 0x1F2 },
    { actor14Talk1Conditions, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk actor15Talks[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk actor16Talks[] = {
    { actor16Talk0Conditions, actor16Talk0Actions, 0x1F2 },
    { actor16Talk1Conditions, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk actor17Talks[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk actor18Talks[] = {
    { actor18Talk0Conditions, actor18Talk0Actions, 0x1F2 },
    { actor18Talk1Conditions, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk actor19Talks[] = {
    { actor19Talk0Conditions, actor19Talk0Actions, 0x1F3 },
    { actor19Talk1Conditions, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk actor20Talks[] = {
    { actor20Talk0Conditions, actor20Talk0Actions, 0x1F3 },
    { actor20Talk1Conditions, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk actor21Talks[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk actor22Talks[] = {
    { actor22Talk0Conditions, actor22Talk0Actions, 0x1F1 },
    { actor22Talk1Conditions, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk actor23Talks[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk actor24Talks[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk actor25Talks[] = {
    { actor25Talk0Conditions, actor25Talk0Actions, 0x1F1 },
    { actor25Talk1Conditions, NULL, 1 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { PROGRESS(0x22), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x21), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x1B), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor5Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x1A), 1, CODES_END };
u16 actor7Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor8Conditions[] = { PROGRESS(0x1C), 1, CODES_END };
u16 actor9Conditions[] = { PROGRESS(0x1D), 1, CODES_END };
u16 actor10Conditions[] = { PROGRESS(0x1E), 1, CODES_END };
u16 actor11Conditions[] = { PROGRESS(0x1F), 1, CODES_END };
u16 actor12Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor13Conditions[] = { PROGRESS(0x23), 1, CODES_END };
u16 actor14Conditions[] = { PROGRESS(0x1B), 1, CODES_END };
u16 actor15Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor16Conditions[] = { PROGRESS(0x1C), 1, CODES_END };
u16 actor17Conditions[] = { PROGRESS(0x22), 1, CODES_END };
u16 actor18Conditions[] = { PROGRESS(0x1D), 1, CODES_END };
u16 actor19Conditions[] = { PROGRESS(0x1E), 1, CODES_END };
u16 actor20Conditions[] = { PROGRESS(0x1F), 1, CODES_END };
u16 actor21Conditions[] = { PROGRESS(0x21), 1, CODES_END };
u16 actor22Conditions[] = { PROGRESS(0x1A), 1, FLAG(0x40, 0xB), 0, CODES_END };
u16 actor23Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor24Conditions[] = { PROGRESS(0x23), 1, CODES_END };
u16 actor25Conditions[] = { PROGRESS(0x1A), 1, FLAG(0x40, 0xB), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor13 = { actor13Conditions, actor13Talks, 0x85, 4, 887, 133, 1 };
FieldActorEntry actor14 = { actor14Conditions, actor14Talks, 0x8D, 5, 962, 353, 1 };
FieldActorEntry actor15 = { actor15Conditions, actor15Talks, 0x8D, 5, 962, 353, 1 };
FieldActorEntry actor16 = { actor16Conditions, actor16Talks, 0x8D, 5, 962, 353, 1 };
FieldActorEntry actor17 = { actor17Conditions, actor17Talks, 0x8D, 5, 962, 353, 1 };
FieldActorEntry actor18 = { actor18Conditions, actor18Talks, 0x8D, 5, 962, 353, 1 };
FieldActorEntry actor19 = { actor19Conditions, actor19Talks, 0x8D, 5, 962, 353, 1 };
FieldActorEntry actor20 = { actor20Conditions, actor20Talks, 0x8D, 5, 962, 353, 1 };
FieldActorEntry actor21 = { actor21Conditions, actor21Talks, 0x8D, 5, 962, 353, 1 };
FieldActorEntry actor22 = { actor22Conditions, actor22Talks, 0x8D, 5, 884, 378, 7 };
FieldActorEntry actor23 = { actor23Conditions, actor23Talks, 0x8D, 5, 962, 353, 1 };
FieldActorEntry actor24 = { actor24Conditions, actor24Talks, 0x8D, 5, 962, 353, 1 };
FieldActorEntry actor25 = { actor25Conditions, actor25Talks, 0x8D, 5, 962, 353, 1 };
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
    &actor16,
    &actor17,
    &actor18,
    &actor19,
    &actor20,
    &actor21,
    &actor22,
    &actor23,
    &actor24,
    &actor25,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 999, 303, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 3, 6, 0, 613, 221, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 3, 6, 0, 725, 165, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 258, 102, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 531, 190, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 758, 111, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 806, 87, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 827, 275, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 859, 292, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 1002, 301, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 266, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 539, 193, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 621, 224, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 733, 168, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 766, 114, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 814, 90, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 835, 279, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 867, 295, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 1010, 304, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x242, 0x3E0, 0x1B0, 3, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x245, 0x78, 0x21C, 5, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 5, 0x3A0, 0x190, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 5, 0x3B0, 0x1E8, 0, 0, 0, 0 },
    { { { PROGRESS(0x1A), 1 }, { FLAG(0x40, 0xB), 0 } }, 8, 0x2BC, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 700, script700, EVENT_TEXT(0x1D), NULL, func_800A4DA8 },
    { 1455, script1455, EVENT_TEXT(0x24), NULL, func_800A4DD4 },
    { 1456, script1456, EVENT_TEXT(0x25), NULL, func_800A4E20 },
    { -1, NULL, 0, NULL, NULL },
};
