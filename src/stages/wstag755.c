#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };

/* Creates the event object of story progress 0x1E once flag 0x4001 is set */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress == 0x1E && FLAGS_00.checkCondition(FLAG(0x40, 1), 1)) {
            children[0] = FIELDSTG_startEvent(0x30D);
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

void func_800A4D8C(void) {
    FLAGS_00.applyAction(FLAG(0x40, 1), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

/* Sets the progress to 31 and applies flag action 0x800C */
void func_800A4DD8(void) {
    GAME.progress = 31;
    FLAGS_00.applyAction(ITEM(0, 0xC), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6C3
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6D2
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x19200, 0x34F00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x2F;
    FIELDSTG_state.music = MUSIC(0x2F, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
}

s16 script780[] = {
    0x102, 2, 0x40A, 0xAD, 5,
    0x100, 0x8E, 0x42A, 0x9D,
    0x101, 0x8E, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 0x8E, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x8E, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0,
};
s16 script781[] = {
    0x100, 2, 0x40A, 0xAD,
    0x101, 2, 1, 5,
    0x100, 0x8E, 0x42A, 0x9D,
    0x101, 0x8E, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0x8E, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x8E, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 5, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 6, 0x8E, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x3DA, 0xC5, 1,
    0x300, 6,
    0x304, 0x26F, 0x78, 0x21C, 5,
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
Battle area3Battle0 = { 18, 18, MUSIC(0x23, 0) };
Battle area3Battle1 = { 304, 18, MUSIC(0x23, 0) };
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
    { 167, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B4, 0x100, 0x1D0, 0, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1B4, 0x120, 0x1D0, 0x20, 0x140, 0x1FE },
    { 0x140, 0x100, 0x174, 0x120, 0xD0, 0x20, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1B0, 0x193, 0x1C0, 0x93, 0x160, 0x1FE },
};
u16 actor11Talk0Conditions[] = { PROGRESS(0x20), 0, PROGRESS(0x21), 0, FLAG(0, 5), 0, CODES_END };
u16 actor11Talk0Actions[] = { FLAG(0, 5), 1, CODES_END };
u16 actor11Talk1Conditions[] = { PROGRESS(0x20), 0, PROGRESS(0x21), 0, FLAG(0, 5), 1, CODES_END };
u16 actor11Talk2Conditions[] = { PROGRESS(0x20), 1, CODES_END };
u16 actor11Talk3Conditions[] = { PROGRESS(0x21), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, NULL, 0x169 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x168 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x167 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x166 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x165 },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x163 },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x162 },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x164 },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { NULL, NULL, 0x161 },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { NULL, NULL, 0x15F },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, NULL, 0x15E },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { actor11Talk0Conditions, actor11Talk0Actions, 0x15E },
    { actor11Talk1Conditions, NULL, 8 },
    { actor11Talk2Conditions, NULL, 0x15E },
    { actor11Talk3Conditions, NULL, 0x15E },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { NULL, NULL, 0x160 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor1Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor3Conditions[] = { SPECIAL(0x19), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor6Conditions[] = { SPECIAL(0x19), 1, CODES_END };
u16 actor7Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor8Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor9Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor10Conditions[] = { SPECIAL(0x19), 1, SPECIAL(0x20), 0, CODES_END };
u16 actor11Conditions[] = { SPECIAL(0x20), 1, CODES_END };
u16 actor12Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x40, 4, 641, 449, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x40, 4, 641, 449, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x40, 4, 641, 449, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x40, 4, 641, 449, 1 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x41, 5, 929, 593, 1 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x41, 5, 929, 593, 1 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x41, 5, 929, 593, 1 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x41, 5, 929, 593, 1 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x8E, 6, 1066, 157, 1 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x8E, 6, 1066, 157, 1 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x8E, 6, 1066, 157, 1 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x8E, 6, 1066, 157, 1 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x9D, 7, 1066, 157, 1 };
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x44, 2, 0xC, 0, 0, 0, 0, 0, 1087, 451, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 1022, 436, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x39, 4, 0, 672, 291, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x41, 4, 0, 700, 302, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x45, 4, 0, 696, 569, 0, 0 },
    { 1, 0x64, 0x40, 6, 5, 0, 0, 0, 0, 0, 1035, 452, 0, 0 },
    { 1, 0x65, 0x40, 6, 6, 0, 0, 0, 0, 0, 843, 356, 0, 0 },
    { 1, 0x66, 0x48, 6, 7, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x48, 6, 8, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x48, 6, 9, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x48, 6, 0xA, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x48, 6, 0xB, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 1, 0, 0x4F, 4, 0, 0, 0, 0, 0, 0, 821, 545, 623, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1055, 451, 505, 0 },
    { 1, 0, 0x41, 4, 2, 0, 0, 0, 0, 0, 864, 348, 412, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 783, 246, 264, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 785, 410, 448, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 715, 589, 612, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 912, 533, 559, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 896, 539, 580, 0 },
    { 1, 0, 0x40, 4, 0x12, 0, 0, 0, 0, 0, 908, 539, 574, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x264, 0x508, 0x6C, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x26F, 0x78, 0x21C, 5, 0x65, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x26F, 0x398, 0x3AC, 5, 0x64, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x26F, 0x1F0, 0x358, 5, 0x66, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 7, 0x328, 0x108, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 7, 0x318, 0x180, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 7, 0x3D8, 0xC0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 7, 0x3C8, 0x138, 0, 0, 0, 0 },
    { { { PROGRESS(0x1E), 1 }, { FLAG(0x40, 1), 0 } }, 8, 0x30C, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 780, script780, EVENT_TEXT(0x10), NULL, func_800A4D8C },
    { 781, script781, EVENT_TEXT(0x11), NULL, func_800A4DD8 },
    { -1, NULL, 0, NULL, NULL },
};
