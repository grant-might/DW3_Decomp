#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 17 or 18, the first that applies */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        do {
            if (GAME.progress == 0x11 && FLAGS_00.checkCondition(FLAG(0x40, 0x3C), 0)) {
                children[0] = FIELDSTG_startEvent(0x1B8);
                break;
            }
            if (GAME.progress == 0x12 && FLAGS_00.checkCondition(FLAG(0x40, 0x38), 0)) {
                children[0] = FIELDSTG_startEvent(0x208);
                break;
            }
        } while (0);
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

void func_800A4DC8(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x3C), 1);
    FLAGS_00.applyAction(FLAG(0x1C, 0x1F), 1);
}

void func_800A4E14(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x21), 1);
    FLAGS_00.applyAction(FLAG(0x1C, 0x20), 1);
}

void func_800A4E60(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x34), 1);
    FLAGS_00.applyAction(FLAG(0x1C, 0x22), 1);
}

void func_800A4EAC(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x35), 1);
    FLAGS_00.applyAction(FLAG(0x1C, 0x23), 1);
}

void func_800A4EF8(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x36), 1);
    FLAGS_00.applyAction(FLAG(0x1C, 0x24), 1);
}

void func_800A4F44(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x37), 1);
    FLAGS_00.applyAction(FLAG(0x1C, 0x25), 1);
}

void func_800A4F90(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x38), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x771
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x780
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0xF600, 0x3B200};
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

s16 script440[] = {
    0x600, 1, 2,
    0x100, 2, 0x70, 0x400,
    0x101, 2, 1, 5,
    0x100, 0x11D, 0x1C7, 0x3BB,
    0x101, 0x11D, 1, 3,
    0x300, 0x1E,
    0x102, 2, 0xD5, 0x3CE, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0x101, 0x3B8,
    0x102, 0x11D, 0x160, 0x387, 3,
    0x302, 0x11D,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 5,
    0x101, 0x11D, 1, 3,
    0x301,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0x11D,
    0x300, 0x3C,
    0x101, 0x11D, 1, 1,
    0x101, 0x323, 0x326, 0x69,
    0x300, 0x1E,
    0x200, 0, 2, 0x11D, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x11D, 1,
    0x301,
    0x101, 0x11D, 1, 5,
    0x300, 0x1E,
    0x102, 0x11D, 0x1A7, 0x363, 5,
    0x302, 0x11D,
    0x200, 0, 5, 2, 0,
    0x101, 2, 7, 5,
    0x100, 0x11D, 0, 0,
    0x101, 0x11D, 1, 0,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x600, 0, 2,
    0x300, 0x3C,
    0,
};
s16 script450[] = {
    0x102, 2, 0x1F0, 0x2B0, 7,
    0x100, 0x69, 0x339, 0x36C,
    0x101, 0x69, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 2, 0x281, 0x2FA, 7,
    0x302, 2,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x601, 0, 0x2E0, 0x328,
    0x102, 0x69, 0x357, 0x37C, 7,
    0x302, 0x69,
    0x102, 0x69, 0x364, 0x376, 5,
    0x302, 0x69,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x34E, 2,
    0x300, 0x1E,
    0x102, 0x69, 0x394, 0x35E, 5,
    0x302, 0x69,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x101, 0x32D, 0x354, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x301,
    0x300, 0x1E,
    0x600, 0, 2,
    0x300, 0x3C,
    0,
};
s16 script470[] = {
    0x102, 2, 0x280, 0x148, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0x2D0, 0x120,
    0x300, 0x3C,
    0x100, 0x69, 0x33E, 0xD8,
    0x101, 0x69, 1, 1,
    0x101, 0x32D, 0x34F, 2,
    0x300, 0x3C,
    0x102, 0x69, 0x301, 0xF7, 1,
    0x302, 0x69,
    0x102, 0x69, 0x312, 0xFF, 7,
    0x302, 0x69,
    0x102, 0x69, 0x2F0, 0x110, 1,
    0x302, 0x69,
    0x200, 0, 1, 2, 2,
    0x101, 2, 7, 5,
    0x101, 0x69, 1, 1,
    0x301,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0x69,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x69,
    0x300, 0x1E,
    0x200, 0, 2, 0x69, 1,
    0x301,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x102, 0x69, 0x312, 0xFF, 5,
    0x302, 0x69,
    0x102, 0x69, 0x301, 0xF7, 3,
    0x302, 0x69,
    0x102, 0x69, 0x310, 0xF0, 5,
    0x302, 0x69,
    0x102, 0x69, 0x338, 0xDC, 5,
    0x302, 0x69,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x101, 0x32D, 0x355, 2,
    0x300, 0x3C,
    0x600, 0, 2,
    0x300, 0x3C,
    0,
};
s16 script480[] = {
    0x102, 2, 0x42F, 0x2B4, 6,
    0x100, 0x69, 0x4D9, 0x2C4,
    0x101, 0x69, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 6,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0x47E, 0x2B4,
    0x300, 0x78,
    0x102, 0x69, 0x4F1, 0x2D0, 7,
    0x302, 0x69,
    0x102, 0x69, 0x4F7, 0x2CC, 5,
    0x302, 0x69,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x352, 2,
    0x300, 0x1E,
    0x102, 0x69, 0x51F, 0x2B8, 5,
    0x302, 0x69,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x101, 0x32D, 0x358, 2,
    0x300, 0x3C,
    0x200, 0, 1, 2, 1,
    0x301,
    0x300, 0x1E,
    0x600, 0, 2,
    0x300, 0x5A,
    0,
};
s16 script490[] = {
    0x600, 0, 2,
    0x102, 2, 0x4BA, 0x1DB, 5,
    0x100, 0x69, 0x3CC, 0x1C1,
    0x101, 0x69, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 2, 1, 2,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0x460, 0x1C7,
    0x102, 0x69, 0x40F, 0x19F, 5,
    0x302, 0x69,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x350, 2,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x102, 0x69, 0x440, 0x187, 5,
    0x302, 0x69,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x101, 0x32D, 0x356, 2,
    0x300, 0x3C,
    0x200, 0, 1, 2, 1,
    0x301,
    0x300, 0x1E,
    0x600, 0, 2,
    0x300, 0x5A,
    0,
};
s16 script500[] = {
    0x102, 2, 0x27F, 0x1D9, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x102, 2, 0x311, 0x221, 7,
    0x101, 0x323, 0x326, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x18,
    0x102, 2, 0x39C, 0x1DB, 5,
    0x100, 0x69, 0x47E, 0x149,
    0x101, 0x69, 1, 3,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x601, 0, 0x3FF, 0x108,
    0x102, 0x69, 0x450, 0x10F, 3,
    0x302, 0x69,
    0x102, 0x69, 0x440, 0x108, 5,
    0x302, 0x69,
    0x102, 0x69, 0x460, 0xF7, 5,
    0x302, 0x69,
    0x101, 0x69, 1, 3,
    0x300, 6,
    0x600, 0, 2,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x300, 0x3C,
    0x300, 0x3C,
    0x200, 0, 1, 2, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 script520[] = {
    0x601, 1, 0x118, 0xA4,
    0x100, 2, 0xCF, 0x6D,
    0x101, 2, 1, 7,
    0x100, 0x69, 0xA9, 0x21B,
    0x101, 0x69, 1, 1,
    0x101, 0x32D, 0x34D, 2,
    0x300, 0x1E,
    0x102, 2, 0x105, 0x88, 7,
    0x302, 2,
    0x300, 0x1E,
    0x101, 0x32D, 0x353, 2,
    0x300, 0x1E,
    0x102, 2, 0x129, 0x9A, 1,
    0x302, 2,
    0x101, 2, 1, 1,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x3C,
    0x601, 0, 0xCF, 0x1E0,
    0x102, 0x69, 0x89, 0x22B, 1,
    0x302, 0x69,
    0x102, 0x69, 0x81, 0x227, 3,
    0x302, 0x69,
    0x101, 0x69, 1, 3,
    0x300, 0x1E,
    0x101, 0x32D, 0x351, 2,
    0x300, 0x1E,
    0x102, 0x69, 0x56, 0x213, 3,
    0x302, 0x69,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x101, 0x32D, 0x357, 2,
    0x300, 0x3C,
    0x600, 0, 2,
    0x300, 0x3C,
    0x200, 0, 1, 2, 2,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0,
};
Battle area0Battle0 = { 80, 12, MUSIC(2, 0) };
Battle area0Battle1 = { 80, 12, MUSIC(2, 0) };
Battle area0Battle2 = { 79, 12, MUSIC(2, 0) };
Battle area0Battle3 = { 79, 12, MUSIC(2, 0) };
Battle area0Battle4 = { 78, 12, MUSIC(2, 0) };
Battle area0Battle5 = { 78, 12, MUSIC(2, 0) };
Battle area0Battle6 = { 77, 12, MUSIC(2, 0) };
Battle area0Battle7 = { 77, 12, MUSIC(2, 0) };
BattleList area0Battles = {
    2,
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
    { 41, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x150, 0x1DB, 0x40, 0xDB, 0x160, 0x1FF },
    { 0x140, 0x100, 0x158, 0x1DB, 0x60, 0xDB, 0x170, 0x1FF },
};
u16 actor0Conditions[] = { PROGRESS(0), 1, FLAG(0x40, 0x21), 0, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0), 1, FLAG(2, 0xD), 1, FLAG(0x40, 0x34), 0, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0), 1, FLAG(2, 0xE), 1, FLAG(0x40, 0x35), 0, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0), 1, FLAG(2, 0xF), 1, FLAG(0x40, 0x36), 0, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0), 1, FLAG(2, 0x10), 1, FLAG(0x40, 0x37), 0, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x12), 1, FLAG(0x40, 0x38), 0, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x11), 1, CODES_END };
u16 actor7Conditions[] = { FLAG(0x40, 0x3C), 0, PROGRESS(0x11), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, NULL, 0x69, 4, 825, 876, 7 };
FieldActorEntry actor1 = { actor1Conditions, NULL, 0x69, 4, 830, 216, 1 };
FieldActorEntry actor2 = { actor2Conditions, NULL, 0x69, 4, 1241, 708, 7 };
FieldActorEntry actor3 = { actor3Conditions, NULL, 0x69, 4, 972, 449, 5 };
FieldActorEntry actor4 = { actor4Conditions, NULL, 0x69, 4, 1150, 329, 3 };
FieldActorEntry actor5 = { actor5Conditions, NULL, 0x69, 4, 169, 539, 1 };
FieldActorEntry actor6 = { actor6Conditions, NULL, 0x69, 4, 0, 0, 1 };
FieldActorEntry actor7 = { actor7Conditions, NULL, 0x11D, 5, 455, 955, 7 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    &actor5,
    &actor6,
    &actor7,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 249, 482, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 273, 494, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 720, 847, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 745, 378, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 769, 390, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 891, 346, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 913, 750, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 984, 754, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 1269, 276, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 889, 739, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 960, 766, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 1234, 293, 0, 0 },
    { 1, 0, 0x40, 2, 0x35, 2, 0, 1, 6, 0, 946, 161, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 787, 181, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 867, 829, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 1043, 353, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 1268, 657, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 1, 6, 0, 236, 78, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 1, 6, 0, 1092, 186, 0, 0 },
    { 1, 0, 0x47, 2, 0xE, 0, 0, 0, 0, 0, 799, 790, 0, 0 },
    { 1, 0, 0x41, 2, 0xF, 0, 0, 0, 0, 0, 727, 809, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 9, 4, 0, 696, 835, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 241, 879, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 305, 559, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 1025, 775, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 217, 891, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 281, 571, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 1001, 787, 0, 0 },
    { 1, 0x68, 0x40, 6, 7, 0, 0, 0, 0, 0, 93, 496, 0, 0 },
    { 1, 0x69, 0x40, 6, 8, 0, 0, 0, 0, 0, 1260, 665, 0, 0 },
    { 1, 0x67, 0x40, 6, 9, 0, 0, 0, 0, 0, 1036, 355, 0, 0 },
    { 1, 0x6B, 0x40, 6, 0xA, 0, 0, 0, 0, 0, 1086, 196, 0, 0 },
    { 1, 0x6A, 0x40, 6, 0xB, 0, 0, 0, 0, 0, 943, 171, 0, 0 },
    { 1, 0x66, 0x40, 6, 0xC, 0, 0, 0, 0, 0, 783, 191, 0, 0 },
    { 1, 0x65, 0x40, 6, 0x11, 0, 0, 0, 0, 0, 859, 837, 0, 0 },
    { 1, 0x64, 0x40, 6, 0xD, 0, 0, 0, 0, 0, 230, 86, 0, 0 },
    { 1, 0, 0x80, 6, 0x19, 0, 0, 0, 0, 0, 876, 192, 0, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 9, 4, 0, 401, 463, 491, 0 },
    { 1, 0, 0x40, 4, 0x34, 2, 0, 9, 4, 0, 377, 475, 497, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 64, 512, 552, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1071, 379, 415, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 1049, 211, 247, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 975, 187, 224, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 815, 207, 239, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 894, 347, 370, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 896, 855, 888, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 208, 103, 138, 0 },
    { 1, 0, 0x40, 4, 0x14, 0, 0, 0, 0, 0, 397, 464, 491, 0 },
    { 1, 0, 0x40, 4, 0x15, 0, 0, 0, 0, 0, 381, 476, 497, 0 },
    { 1, 0, 0x80, 4, 0x16, 0, 0, 0, 0, 0, 891, 116, 221, 0 },
    { 1, 0, 0x80, 4, 0x17, 0, 0, 0, 0, 0, 899, 112, 207, 0 },
    { 1, 0, 0x80, 4, 0x18, 0, 0, 0, 0, 0, 907, 108, 203, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x24C, 0x228, 0x94, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x24E, 0x108, 0x174, 5, 0x65, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x24F, 0x108, 0x174, 5, 0x69, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x252, 0x2F8, 0x264, 3, 0x6B, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x250, 0x108, 0x174, 5, 0x67, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x252, 0x258, 0x24C, 5, 0x6A, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x251, 0x108, 0x174, 5, 0x66, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x252, 0x68, 0x20C, 3, 0x64, 0, 0 },
    { { { SPECIAL(0x40), 1 }, { CODES_END, 0 } }, 1, 0x253, 0x278, 0xD4, 3, 0x68, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 6, 0x160, 0x80, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 6, 0x170, 0xE8, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 0xC, 0xDF, 0x142, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 0xC, 0xD2, 0x208, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 8, 0x2D0, 0x29A, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 8, 0x2C1, 0x322, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 8, 0x33E, 0x2D2, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 8, 0x330, 0x35A, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 8, 0x42E, 0x34A, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 8, 0x420, 0x3D2, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 5, 0x4B0, 0x25A, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 5, 0x4BE, 0x2AE, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 8, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { PROGRESS(0x11), 1 }, { FLAG(0x40, 0x21), 0 } }, 8, 0x1C2, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(2, 0xD), 1 }, { FLAG(0x40, 0x34), 0 } }, 8, 0x1D6, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(2, 0xE), 1 }, { FLAG(0x40, 0x35), 0 } }, 8, 0x1E0, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(2, 0xF), 1 }, { FLAG(0x40, 0x36), 0 } }, 8, 0x1EA, 0, 0, 0, 0, 0, 0 },
    { { { FLAG(2, 0x10), 1 }, { FLAG(0x40, 0x37), 0 } }, 8, 0x1F4, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 440, script440, EVENT_TEXT(6), NULL, func_800A4DC8 },
    { 450, script450, EVENT_TEXT(0x16), NULL, func_800A4E14 },
    { 470, script470, EVENT_TEXT(0x17), NULL, func_800A4E60 },
    { 480, script480, EVENT_TEXT(0x18), NULL, func_800A4EAC },
    { 490, script490, EVENT_TEXT(0x19), NULL, func_800A4EF8 },
    { 500, script500, EVENT_TEXT(0x1A), NULL, func_800A4F44 },
    { 520, script520, EVENT_TEXT(0x1B), NULL, func_800A4F90 },
    { -1, NULL, 0, NULL, NULL },
};
