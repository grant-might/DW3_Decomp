#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };

/* Creates the event object of story progress 0xD or 0x23 that applies */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress == 0xD && FLAGS_00.checkCondition(FLAG(0x1C, 0xD), 1)) {
            children[0] = FIELDSTG_startEvent(0x160);
        } else if (GAME.progress == 0x23 && FLAGS_00.checkCondition(FLAG(0x40, 0x5B), 1)) {
            children[0] = FIELDSTG_startEvent(0x38F);
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

void func_800A4DC0(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x5B), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

/* Sets the story progress to 36 and flag 0x8019 */
void func_800A4E0C(void) {
    GAME.progress = 36;
    FLAGS_00.applyAction(ITEM(0, 0x19), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6C6
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6D5
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x1B000, 0x34100};
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

s16 script910[] = {
    0x102, 2, 0x40A, 0xAD, 5,
    0x100, 0xD2, 0x42A, 0x9D,
    0x101, 0xD2, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 3,
    0x101, 2, 1, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0,
};
s16 script911[] = {
    0x100, 2, 0x40A, 0xAD,
    0x101, 2, 1, 5,
    0x100, 0x13C, 0x42A, 0x9D,
    0x101, 0x13C, 1, 5,
    0x300, 0x78,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x422, 0xA1, 5,
    0x302, 2,
    0x300, 0x1E,
    0x100, 0x13C, 0, 0,
    0x101, 0x13C, 1, 5,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x3DA, 0xC5, 1,
    0x300, 6,
    0x304, 0x2D6, 0x78, 0x21C, 5,
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
Battle area3Battle0 = { 26, 18, MUSIC(0x23, 0) };
Battle area3Battle1 = { 308, 18, MUSIC(0x23, 0) };
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
    { 153, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1A8, 0x1C3, 0x1A0, 0xC3, 0x140, 0x1FE },
    { 0x180, 0x100, 0x180, 0x1CF, 0x100, 0xCF, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1B4, 0x100, 0x1D0, 0, 0x170, 0x1FE },
    { 0x180, 0x100, 0x190, 0x1AF, 0x140, 0xAF, 0x150, 0x1FD },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x160, 0x1FD },
    { 0x180, 0x100, 0x198, 0x1AF, 0x160, 0xAF, 0x170, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x1BB, 0x1C0, 0xBB, 0x140, 0x1FC },
    { 0x180, 0x100, 0x1A0, 0x1C3, 0x180, 0xC3, 0x150, 0x1FC },
    { 0x140, 0x100, 0x16C, 0x1A3, 0xB0, 0xA3, 0x160, 0x1FC },
};
u16 actor0Talk0Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor0Talk1Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor0Talk2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor3Talk0Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor3Talk1Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor3Talk2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, NULL, 0x1DA },
    { actor0Talk1Conditions, NULL, 0x1DB },
    { actor0Talk2Conditions, NULL, 0x1DC },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x1DD },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x1DE },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { actor3Talk0Conditions, NULL, 0x1DF },
    { actor3Talk1Conditions, NULL, 0x1E0 },
    { actor3Talk2Conditions, NULL, 0x1E1 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x1E2 },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x1E3 },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x1E9 },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x1E8 },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { NULL, NULL, 0x1E7 },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { NULL, NULL, 0x1E4 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, NULL, 0x1E4 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, NULL, 0x1E5 },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { NULL, NULL, 0x1E5 },
    { NULL, NULL, 0 },
};
FieldTalk actor13Talks[] = {
    { NULL, NULL, 0x1E6 },
    { NULL, NULL, 0 },
};
FieldTalk actor14Talks[] = {
    { NULL, NULL, 0x1E6 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { SPECIAL(0x1E), 1, CODES_END };
u16 actor1Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor3Conditions[] = { SPECIAL(0x1E), 1, CODES_END };
u16 actor4Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x23), 1, CODES_END };
u16 actor7Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor8Conditions[] = { FLAG(0x40, 0x5B), 0, PROGRESS(0x24), 0, SPECIAL(0x1D), 1, CODES_END };
u16 actor9Conditions[] = { SPECIAL(0x1E), 1, SPECIAL(0x21), 0, CODES_END };
u16 actor10Conditions[] = { PROGRESS(0x22), 1, CODES_END };
u16 actor11Conditions[] = { SPECIAL(0x1E), 1, SPECIAL(0x21), 0, CODES_END };
u16 actor12Conditions[] = { PROGRESS(0x22), 1, CODES_END };
u16 actor13Conditions[] = { SPECIAL(0x1E), 1, SPECIAL(0x21), 0, CODES_END };
u16 actor14Conditions[] = { PROGRESS(0x22), 1, CODES_END };
u16 actor15Conditions[] = { PROGRESS(0x23), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x22, 4, 641, 449, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x22, 4, 641, 449, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x22, 4, 641, 449, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x23, 5, 929, 593, 1 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x23, 5, 929, 593, 1 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x23, 5, 929, 593, 1 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x74, 6, 559, 776, 1 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x92, 7, 1066, 157, 1 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0xD2, 8, 1066, 157, 1 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x12B, 9, 520, 757, 1 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x12B, 9, 520, 757, 1 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x12F, 0xA, 544, 769, 1 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x12F, 0xA, 544, 769, 1 };
FieldActorEntry actor13 = { actor13Conditions, actor13Talks, 0x130, 0xB, 568, 781, 1 };
FieldActorEntry actor14 = { actor14Conditions, actor14Talks, 0x130, 0xB, 568, 781, 1 };
FieldActorEntry actor15 = { actor15Conditions, NULL, 0x13C, 0xC, 0, 0, 1 };
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 1087, 451, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 0, 0, 0, 0, 0, 1022, 436, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x39, 4, 0, 672, 291, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x41, 4, 0, 700, 302, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x45, 4, 0, 696, 569, 0, 0 },
    { 1, 0x64, 0x40, 6, 6, 0, 0, 0, 0, 0, 1035, 452, 0, 0 },
    { 1, 0x65, 0x40, 6, 7, 0, 0, 0, 0, 0, 843, 356, 0, 0 },
    { 1, 0x66, 0x40, 6, 8, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x40, 6, 9, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x40, 6, 0xA, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x40, 6, 0xB, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x40, 6, 0xC, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 821, 545, 623, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1055, 451, 505, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 864, 348, 412, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 783, 246, 264, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 785, 410, 448, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 715, 589, 612, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 912, 533, 559, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 896, 539, 580, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 908, 539, 574, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2CC, 0x508, 0x6C, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2D6, 0x78, 0x21C, 5, 0x65, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2D6, 0x398, 0x3AC, 5, 0x64, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2D6, 0x1F0, 0x358, 5, 0x66, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 7, 0x328, 0x108, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 7, 0x318, 0x180, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 7, 0x3D8, 0xC0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 7, 0x3C8, 0x138, 0, 0, 0, 0 },
    { { { PROGRESS(0x23), 1 }, { FLAG(0x40, 0x5B), 0 } }, 8, 0x38E, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 910, script910, EVENT_TEXT(0x12), NULL, func_800A4DC0 },
    { 911, script911, EVENT_TEXT(0x13), NULL, func_800A4E0C },
    { -1, NULL, 0, NULL, NULL },
};
