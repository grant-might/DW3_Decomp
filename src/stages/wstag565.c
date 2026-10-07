#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x29), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x2A), 0)) {
            children[0] = FIELDSTG_startEvent(0x4F8);
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
    FLAGS_00.applyAction(FLAG(0x40, 0x29), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A4DEC(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x2A), 1);
    FLAGS_00.applyAction(ITEM(0, 0x26), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x50B
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x51B
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0xC700, 0x1E500};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x14;
    FIELDSTG_state.music = MUSIC(0x14, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        FIELDSTG_state.soundBank = 0x1F;
        FIELDSTG_state.music = MUSIC(0x1F, 0);
    }
}

s16 script1271[] = {
    0x600, 1, 2,
    0x102, 2, 0x3F9, 0x3B5, 7,
    0x100, 0x7D, 0x419, 0x3C5,
    0x101, 0x7D, 1, 3,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 7,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 2, 0x7D, 2,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x325\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x800A\n");
#endif
s16 script1272[] = {
    0x600, 1, 2,
    0x100, 2, 0x3F9, 0x3B5,
    0x101, 2, 1, 7,
    0x100, 0x7D, 0x419, 0x3C5,
    0x101, 0x7D, 1, 3,
    0x300, 0x78,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 2, 0x7D, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x3C,
    0,
};
Battle area0Battle0 = { 149, 3, MUSIC(2, 0) };
Battle area0Battle1 = { 149, 3, MUSIC(2, 0) };
Battle area0Battle2 = { 149, 3, MUSIC(2, 0) };
Battle area0Battle3 = { 70, 3, MUSIC(2, 0) };
Battle area0Battle4 = { 70, 3, MUSIC(2, 0) };
Battle area0Battle5 = { 70, 3, MUSIC(2, 0) };
Battle area0Battle6 = { 67, 3, MUSIC(2, 0) };
Battle area0Battle7 = { 67, 3, MUSIC(2, 0) };
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
Battle area3Battle0 = { 267, 3, MUSIC(0x22, 0) };
Battle area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle3 = { 329, 3, MUSIC(2, 0) };
Battle area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle6 = { 156, 3, MUSIC(2, 0) };
Battle area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 34, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x176, 0x120, 0xD8, 0x20, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x172, 0xB8, 0x72, 0x170, 0x1FF },
    { 0x140, 0x100, 0x162, 0x172, 0x88, 0x72, 0x150, 0x1FE },
};
u16 actor0Talk0Actions[] = { FLAG(2, 9), 1, ITEM(1, 0x2B), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(2, 0xA), 1, SPECIAL(0x8B), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(2, 0xB), 1, ITEM(1, 0x45), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor3Talk0Conditions[] = { FLAG(0x1C, 0x15), 0, CODES_END };
u16 actor3Talk0Actions[] = { START_EVENT(0x28), 1, FLAG(0x1C, 0x15), 1, CODES_END };
u16 actor3Talk1Conditions[] = { FLAG(0x1C, 0x15), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x16D },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, actor1Talk0Actions, 0x16C },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, actor2Talk0Actions, 0x254 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { actor3Talk0Conditions, actor3Talk0Actions, 0x2C3 },
    { actor3Talk1Conditions, NULL, 0x2C4 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { FLAG(2, 9), 0, CODES_END };
u16 actor1Conditions[] = { FLAG(2, 0xA), 0, CODES_END };
u16 actor2Conditions[] = { FLAG(2, 0xB), 0, CODES_END };
u16 actor3Conditions[] = { FLAG(6, 3), 1, ITEM(0, 0x26), 0, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x21, 4, 256, 561, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x4D, 5, 784, 393, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x4E, 6, 593, 793, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x7D, 7, 1049, 965, 7 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 1234, 165, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 1279, 187, 0, 0 },
    { 1, 0, 0x40, 6, 3, 1, 3, 8, 4, 0, 125, 286, 0, 0 },
    { 1, 0, 0x40, 6, 3, 1, 3, 8, 4, 0, 1409, 823, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 1497, 247, 283, 0 },
    { 1, 0, 0x6C, 4, 1, 0, 0, 0, 0, 0, 920, 640, 699, 0 },
    { 1, 0, 0x57, 4, 2, 0, 0, 0, 0, 0, 1040, 220, 285, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 512, 512, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 432, 320, 320, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 496, 336, 336, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 720, 584, 584, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 936, 900, 900, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1136, 168, 168, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1328, 896, 896, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1568, 479, 479, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x249, 0x294, 0x1F0, 3, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x24C, 0xA8, 0x3FC, 5, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x24B, 0x90, 0xD0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { SPECIAL(0x94), 1 }, { CODES_END, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 2, 3 },
    { { { SPECIAL(0x94), 1 }, { CODES_END, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 4, 1 },
    { { { SPECIAL(0x94), 1 }, { CODES_END, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 0x1E, 1 },
    { { { SPECIAL(0x94), 1 }, { CODES_END, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 8, 1 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1271, script1271, EVENT_TEXT(0x10), NULL, func_800A4DA0 },
    { 1272, script1272, EVENT_TEXT(0x11), NULL, func_800A4DEC },
    { -1, NULL, 0, NULL, NULL },
};
