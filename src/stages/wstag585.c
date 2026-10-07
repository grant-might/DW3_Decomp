#include "common.h"
#include "stage.h"

/* Creates the event object of flags 0x4033 and 0x1C20 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x33), 0) && FLAGS_00.checkCondition(FLAG(0x1C, 0x20), 1)) {
            children[0] = FIELDSTG_startEvent(0x1CC);
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
    FLAGS_00.applyAction(FLAG(0x40, 0x33), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x4F5
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x505
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x13200, 0x15B00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x39;
    FIELDSTG_state.music = MUSIC(0x39, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script460[] = {
    0x600, 1, 2,
    0x100, 2, 0xEF, 0x180,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x115, 0x16E, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x3C,
    0x101, 2, 1, 3,
    0x300, 0x3C,
    0x101, 2, 1, 5,
    0x300, 0x3C,
    0x200, 0, 1, 2, 2,
    0x301,
    0x600, 0, 2,
    0x300, 0x3C,
    0,
};
Battle area0Battle0 = { 75, 12, MUSIC(2, 0) };
Battle area0Battle1 = { 75, 12, MUSIC(2, 0) };
Battle area0Battle2 = { 75, 12, MUSIC(2, 0) };
Battle area0Battle3 = { 75, 12, MUSIC(2, 0) };
Battle area0Battle4 = { 75, 12, MUSIC(2, 0) };
Battle area0Battle5 = { 75, 12, MUSIC(2, 0) };
Battle area0Battle6 = { 75, 12, MUSIC(2, 0) };
Battle area0Battle7 = { 75, 12, MUSIC(2, 0) };
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
Battle area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle1 = { 0, 0, MUSIC(1, 0) };
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
    { 42, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x150, 0x1FF },
};
u16 actor0Talk0Actions[] = { FLAG(2, 0xD), 1, ITEM(1, 0x2F), 1, SPECIAL(0x13), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x256 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { FLAG(2, 0xD), 0, FLAG(0x1C, 0x20), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x21, 4, 379, 318, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 6, 0, 277, 252, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 405, 317, 0, 0 },
    { 1, 0, 0x40, 6, 0, 1, 0, 0xB, 4, 0, 214, 250, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x24D, 0x358, 0x37C, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 460, script460, EVENT_TEXT(7), NULL, func_800A4DA8 },
    { -1, NULL, 0, NULL, NULL },
};
