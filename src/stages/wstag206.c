#include "common.h"
#include "stage.h"

/* Creates the event object of progress 0x24, which depends on flag 0x40CA */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        do {
            if (GAME.progress == 0x24 && FLAGS_00.checkCondition(FLAG(0x40, 0xCA), 0)) {
                children[0] = FIELDSTG_startEvent(0x399);
                break;
            }
            if (GAME.progress == 0x24 && FLAGS_00.checkCondition(FLAG(0x40, 0xCA), 1)) {
                children[0] = FIELDSTG_startEvent(0x39A);
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

void func_800A4DE0(void) {
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A4E0C(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0xCA), 1);
}

void func_800A4E38(void) {
    GAME.progress = 37;
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x49C
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x4AC
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x2E300, 0xEE00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 4;
    FIELDSTG_state.music = MUSIC(4, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(FLAG(0x1A, 0xA), 0) != 0) {
        FIELDSTG_state.soundBank = 0x1F;
        FIELDSTG_state.music = MUSIC(0x1F, 0);
    }
}

s16 script730[] = {
    0x102, 2, 0x1D0, 0x180, 5,
    0x101, 0x323, 0x325, 0xF3,
    0x101, 0x324, 0x325, 0xF4,
    0x101, 0x325, 0x325, 0xF5,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x3C,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x326, 0xF3,
    0x101, 0x324, 0x326, 0xF4,
    0x101, 0x325, 0x326, 0xF5,
    0x300, 0x1E,
    0x200, 0, 1, 0xF3, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0xF3, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 script921[] = {
    0x601, 1, 0x2DA, 0xEC,
    0x100, 2, 0x2F0, 0x10E,
    0x101, 2, 1, 4,
    0x100, 0x25, 0x288, 0x124,
    0x101, 0x25, 1, 5,
    0x100, 0x26, 0x250, 0x130,
    0x101, 0x26, 1, 5,
    0x100, 0x27, 0x261, 0x141,
    0x101, 0x27, 1, 5,
    0x100, 0x65, 0x2F0, 0xE8,
    0x101, 0x65, 1, 1,
    0x100, 0x66, 0x2E0, 0xE0,
    0x101, 0x66, 1, 1,
    0x100, 0x67, 0x300, 0xF0,
    0x101, 0x67, 1, 1,
    0x100, 0x6F, 0x248, 0x154,
    0x101, 0x6F, 1, 5,
    0x100, 0xB3, 0x340, 0x108,
    0x101, 0xB3, 1, 3,
    0x100, 0xE6, 0x226, 0x144,
    0x101, 0xE6, 1, 5,
    0x100, 0x186, 0x220, 0x168,
    0x101, 0x186, 1, 5,
    0x100, 0x187, 0x200, 0x158,
    0x101, 0x187, 1, 5,
    0x101, 0x32D, 0x34D, 2,
    0x300, 0x78,
    0x200, 0, 1, 0x65, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0x25, 2,
    0x101, 0x25, 1, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0x25, 1, 5,
    0x101, 0x65, 1, 5,
    0x101, 0x66, 1, 5,
    0x101, 0x67, 1, 5,
    0x300, 0x1E,
    0x102, 0x25, 0x380, 0xA8, 5,
    0x102, 0x26, 0x380, 0x98, 5,
    0x102, 0x27, 0x371, 0xA5, 5,
    0x102, 0x65, 0x3A0, 0x90, 5,
    0x102, 0x66, 0x390, 0x88, 5,
    0x102, 0x67, 0x3B0, 0x98, 5,
    0x102, 0x6F, 0x380, 0xB8, 5,
    0x102, 0xE6, 0x380, 0x98, 5,
    0x102, 0x186, 0x380, 0xB8, 5,
    0x102, 0x187, 0x380, 0x98, 5,
    0x300, 0x48,
    0x200, 0, 4, 0x27, 3,
    0x300, 0x48,
    0x200, 1, 3, 0x26, 2,
    0x300, 0x78,
    0x200, 1, 5, 0x187, 1,
    0x200, 0, 5, 0x187, 1,
    0x300, 0xCC,
    0x600, 0, 2,
    0x200, 1, 6, 0xB3, 1,
    0x200, 0, 6, 0xB3, 1,
    0x101, 0xB3, 1, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 0,
    0x101, 2, 7, 6,
    0x301,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x102, 0xB3, 0x320, 0xF8, 4,
    0x302, 0xB3,
    0x101, 0xB3, 1, 1,
    0x300, 0x1E,
    0x200, 0, 8, 0xB3, 0,
    0x301,
    0x300, 0x1E,
#if VERSION_US
    0x304, 0xE05, 0x2F0, 0x10E, 5,
#elif VERSION_EU
    0x304, 0xE06, 0x2F0, 0x10E, 5,
#endif
    0,
};
s16 script922[] = {
    0x100, 2, 0x2F0, 0x10E,
    0x101, 2, 1, 5,
    0x100, 0xB3, 0x320, 0xF8,
    0x101, 0xB3, 1, 1,
    0x101, 0x32D, 0x34D, 2,
    0x300, 0x78,
    0x200, 0, 1, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0xB3, 0,
    0x301,
    0x100, 0x67, 0x370, 0xB0,
    0x101, 0x67, 1, 1,
    0x300, 0x1E,
    0x102, 0x67, 0x316, 0xDC, 1,
    0x302, 0x67,
    0x600, 0, 0x67,
    0x101, 0x67, 1, 1,
    0x101, 0x323, 0x325, 0x67,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 0x67, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x101, 0x324, 0x325, 0xB3,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x101, 0x324, 0x326, 0xB3,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 4,
    0x101, 0xB3, 1, 4,
    0x301,
    0x102, 2, 0x2F0, 0xD8, 4,
    0x302, 2,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x200, 0, 5, 0xB3, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x67, 2,
    0x101, 0x67, 1, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 0,
    0x101, 2, 7, 6,
    0x301,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x200, 0, 8, 0x67, 2,
    0x101, 0x67, 1, 2,
    0x101, 0xB3, 1, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 2, 0,
    0x101, 2, 7, 6,
    0x301,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x200, 0, 0xA, 0x67, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xB, 2, 0,
    0x101, 2, 7, 6,
    0x301,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x200, 0, 0xC, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 0xD, 0xB3, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x308, 0xCC, 5,
    0x101, 0x67, 1, 3,
    0x101, 0xB3, 1, 4,
    0x302, 2,
    0x102, 2, 0x358, 0xA4, 5,
    0x101, 0x67, 1, 4,
    0x300, 0x5A,
    0x304, 0x270, 0x60, 0x31C, 5,
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
Battle area3Battle0 = { 30, 19, MUSIC(0x22, 0) };
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
    { 130, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B8, 0x19C, 0x1E0, 0x9C, 0x160, 0x1FF },
    { 0x180, 0x100, 0x198, 0x1C0, 0x160, 0xC0, 0x170, 0x1FF },
    { 0x180, 0x100, 0x190, 0x1C0, 0x140, 0xC0, 0x140, 0x1FE },
    { 0x180, 0x100, 0x1A0, 0x1C0, 0x180, 0xC0, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1A4, 0x180, 0x190, 0x80, 0x160, 0x1FE },
    { 0x180, 0x100, 0x1B8, 0x16C, 0x1E0, 0x6C, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1B0, 0x194, 0x1C0, 0x94, 0x140, 0x1FD },
    { 0x180, 0x100, 0x198, 0x100, 0x160, 0, 0x150, 0x1FD },
    { 0x180, 0x100, 0x188, 0x1C0, 0x120, 0xC0, 0x160, 0x1FD },
    { 0x180, 0x100, 0x180, 0x138, 0x100, 0x38, 0x170, 0x1FD },
    { 0x180, 0x100, 0x198, 0x138, 0x160, 0x38, 0x140, 0x1FC },
    { 0x180, 0x100, 0x1A4, 0x100, 0x190, 0, 0x150, 0x1FC },
    { 0x180, 0x100, 0x180, 0x100, 0x100, 0, 0x160, 0x1FC },
    { 0x180, 0x100, 0x18C, 0x100, 0x130, 0, 0x170, 0x1FC },
    { 0x180, 0x100, 0x1A4, 0x138, 0x190, 0x38, 0x140, 0x1FB },
    { 0x180, 0x100, 0x188, 0x138, 0x120, 0x38, 0x150, 0x1FB },
    { 0x180, 0x100, 0x190, 0x138, 0x140, 0x38, 0x160, 0x1FB },
};
u16 actor0Talk0Actions[] = { SPECIAL(0x8B), 1, FLAG(2, 0x5E), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor14Talk0Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor14Talk1Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor18Talk0Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor18Talk1Conditions[] = { PROGRESS(0x26), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x16C },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0xED },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0xEE },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { NULL, NULL, 0x1B5 },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { NULL, NULL, 0x1B4 },
    { NULL, NULL, 0 },
};
FieldTalk actor14Talks[] = {
    { actor14Talk0Conditions, NULL, 0xE7 },
    { actor14Talk1Conditions, NULL, 0xE8 },
    { NULL, NULL, 0 },
};
FieldTalk actor16Talks[] = {
    { NULL, NULL, 0xE9 },
    { NULL, NULL, 0 },
};
FieldTalk actor18Talks[] = {
    { actor18Talk0Conditions, NULL, 0xEA },
    { actor18Talk1Conditions, NULL, 0xEB },
    { NULL, NULL, 0 },
};
FieldTalk actor20Talks[] = {
    { NULL, NULL, 0xEC },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { FLAG(2, 0x5E), 0, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor7Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor8Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor9Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor10Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor11Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor12Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor13Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor14Conditions[] = { SPECIAL(0x1C), 1, CODES_END };
u16 actor15Conditions[] = { PROGRESS(0x24), 0, SPECIAL(0x1D), 1, CODES_END };
u16 actor16Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor17Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor18Conditions[] = { SPECIAL(0x1C), 1, CODES_END };
u16 actor19Conditions[] = { PROGRESS(0x24), 0, SPECIAL(0x1D), 1, CODES_END };
u16 actor20Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor21Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor22Conditions[] = { PROGRESS(0x24), 0, SPECIAL(0x1D), 1, CODES_END };
u16 actor23Conditions[] = { PROGRESS(0x24), 0, SPECIAL(0x1D), 1, CODES_END };
u16 actor24Conditions[] = { SPECIAL(0x1D), 1, PROGRESS(0x24), 0, CODES_END };
u16 actor25Conditions[] = { PROGRESS(0x24), 1, CODES_END };
u16 actor26Conditions[] = { PROGRESS(0x24), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x21, 4, 304, 160, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x25, 5, 736, 184, 1 };
FieldActorEntry actor2 = { actor2Conditions, NULL, 0x25, 5, 0, 0, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x26, 6, 848, 240, 1 };
FieldActorEntry actor4 = { actor4Conditions, NULL, 0x26, 6, 0, 0, 1 };
FieldActorEntry actor5 = { actor5Conditions, NULL, 0x27, 7, 0, 0, 1 };
FieldActorEntry actor6 = { actor6Conditions, NULL, 0x65, 8, 0, 0, 1 };
FieldActorEntry actor7 = { actor7Conditions, NULL, 0x66, 9, 0, 0, 1 };
FieldActorEntry actor8 = { actor8Conditions, NULL, 0x67, 0xA, 0, 0, 1 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x67, 0xA, 752, 216, 7 };
FieldActorEntry actor10 = { actor10Conditions, NULL, 0x6F, 0xB, 0, 0, 1 };
FieldActorEntry actor11 = { actor11Conditions, NULL, 0xB3, 0xC, 0, 0, 1 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0xB3, 0xC, 720, 232, 7 };
FieldActorEntry actor13 = { actor13Conditions, NULL, 0xE6, 0xD, 0, 0, 1 };
FieldActorEntry actor14 = { actor14Conditions, actor14Talks, 0xF3, 0xE, 736, 184, 1 };
FieldActorEntry actor15 = { actor15Conditions, NULL, 0xF3, 0xE, 488, 372, 1 };
FieldActorEntry actor16 = { actor16Conditions, actor16Talks, 0xF3, 0xE, 736, 184, 1 };
FieldActorEntry actor17 = { actor17Conditions, NULL, 0xF3, 0xE, 735, 192, 1 };
FieldActorEntry actor18 = { actor18Conditions, actor18Talks, 0xF4, 0xF, 848, 240, 1 };
FieldActorEntry actor19 = { actor19Conditions, NULL, 0xF4, 0xF, 512, 344, 1 };
FieldActorEntry actor20 = { actor20Conditions, actor20Talks, 0xF4, 0xF, 848, 240, 1 };
FieldActorEntry actor21 = { actor21Conditions, NULL, 0xF4, 0xF, 848, 240, 1 };
FieldActorEntry actor22 = { actor22Conditions, NULL, 0xF5, 0x10, 544, 360, 1 };
FieldActorEntry actor23 = { actor23Conditions, NULL, 0xF6, 0x11, 551, 325, 1 };
FieldActorEntry actor24 = { actor24Conditions, NULL, 0xF7, 0x12, 584, 341, 1 };
FieldActorEntry actor25 = { actor25Conditions, NULL, 0x186, 0x13, 0, 0, 1 };
FieldActorEntry actor26 = { actor26Conditions, NULL, 0x187, 0x14, 0, 0, 1 };
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
    &actor26,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x80, 2, 0, 0, 0, 0, 0, 0, 384, 384, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 128, 475, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 240, 499, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 252, 384, 0, 0 },
    { 1, 0, 0x80, 2, 4, 0, 0, 0, 0, 0, 512, 307, 0, 0 },
    { 1, 0, 0x40, 2, 5, 0, 0, 0, 0, 0, 496, 371, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 248, 352, 0, 0 },
    { 1, 0, 0x80, 2, 7, 0, 0, 0, 0, 0, 256, 384, 0, 0 },
    { 1, 0, 0x80, 2, 8, 0, 0, 0, 0, 0, 896, 128, 0, 0 },
    { 1, 0, 0x40, 2, 0x10, 0, 0, 0, 0, 0, 100, 512, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 414, 80, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 631, 406, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1257, 341, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 396, 323, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 805, 413, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 950, 554, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1127, 489, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 30, 340, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 70, 360, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 110, 380, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 150, 400, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 190, 420, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 470, 560, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 510, 580, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 1, 0x58, 0x5B, 4, 0, 585, 125, 0, 0 },
    { 1, 0, 0x40, 6, 0x5C, 1, 0x5C, 0x5F, 4, 0, 363, 49, 0, 0 },
    { 1, 0, 0x40, 6, 0x5C, 1, 0x5C, 0x5F, 4, 0, 433, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 1, 0x54, 0x57, 4, 0, 1009, 162, 0, 0 },
    { 1, 0x64, 0x80, 6, 9, 0, 0, 0, 0, 0, 758, 96, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 37, 267, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 77, 287, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 117, 307, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 157, 327, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 196, 347, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 236, 367, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 276, 387, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 477, 487, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 517, 507, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x50, 1, 0x50, 0x53, 4, 0, 230, 440, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x60, 1, 0x60, 0x63, 6, 0, 422, 110, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4C, 1, 0x4C, 0x4F, 6, 0, 942, 205, 0, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 224, 177, 200, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 600, 214, 273, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 1046, 371, 407, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 1062, 315, 337, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 902, 275, 295, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 846, 177, 226, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x270, 0x60, 0x31C, 5, 0x64, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x28C, 0x5E2, 0xE0, 1, 0, 0, 0 },
    { { { SPECIAL(0x93), 1 }, { CODES_END, 0 } }, 0xA, 0x2E1, 0x1D0, 0x154, 7, 0, 0xC, 1 },
    { { { SPECIAL(0x93), 1 }, { CODES_END, 0 } }, 0xA, 0x2E1, 0xE0, 0x110, 7, 0, 0xC, 1 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 3, 0x110, 0x100, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 3, 0x120, 0xC8, 0, 0, 0, 0 },
    { { { SPECIAL(0x1D), 1 }, { CODES_END, 0 } }, 8, 0x2DA, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 730, script730, EVENT_TEXT(0x23), NULL, func_800A4DE0 },
    { 921, script921, EVENT_TEXT(0x26), NULL, func_800A4E0C },
    { 922, script922, EVENT_TEXT(0x27), NULL, func_800A4E38 },
    { -1, NULL, 0, NULL, NULL },
};
