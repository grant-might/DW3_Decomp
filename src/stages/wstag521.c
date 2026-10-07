#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 28 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0x1C && FLAGS_00.checkCondition(FLAG(0x40, 0x52), 1)) {
            children[0] = FIELDSTG_startEvent(0x2EF);
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

void func_800A4D94(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x52), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

/* Sets the story progress to 29 and flag 0x8017 */
void func_800A4DE0(void) {
    GAME.progress = 29;
    FLAGS_00.applyAction(ITEM(0, 0x17), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x5BA
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x5CA
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x14600, 0xEA00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x12;
    FIELDSTG_state.music = MUSIC(0x12, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
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

s16 script750[] = {
    0x102, 2, 0x1B9, 0xD5, 3,
    0x100, 0xD2, 0x1A1, 0xC9,
    0x101, 0xD2, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 8, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 script751[] = {
    0x100, 2, 0x1B9, 0xD5,
    0x101, 2, 1, 3,
    0x100, 0x13C, 0x1A1, 0xC9,
    0x101, 0x13C, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 2, 0,
    0x301,
    0x300, 0x1E,
    0x300, 0x3C,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x1A9, 0xCD, 3,
    0x302, 2,
    0x300, 0x1E,
    0x100, 0x13C, 0, 0,
    0x101, 0x13C, 1, 7,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x301,
    0x102, 2, 0x1D1, 0xE1, 7,
    0x300, 0x1E,
    0x304, 0x2AB, 0x238, 0x8C, 1,
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
Battle area3Battle0 = { 16, 18, MUSIC(0x23, 0) };
Battle area3Battle1 = { 306, 18, MUSIC(0x23, 0) };
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
    { 151, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x19D, 0xC0, 0x9D, 0x160, 0x1FF },
    { 0x140, 0x100, 0x174, 0x175, 0xD0, 0x75, 0x170, 0x1FF },
    { 0x140, 0x100, 0x140, 0x19E, 0, 0x9E, 0x160, 0x1FE },
    { 0x140, 0x100, 0x156, 0x1A6, 0x58, 0xA6, 0x170, 0x1FE },
    { 0x140, 0x100, 0x15E, 0x1A6, 0x78, 0xA6, 0x150, 0x1FD },
    { 0x140, 0x100, 0x148, 0x1B2, 0x20, 0xB2, 0x160, 0x1FD },
    { 0x140, 0x100, 0x16A, 0x175, 0xA8, 0x75, 0x170, 0x1FD },
    { 0x140, 0x100, 0x158, 0x17E, 0x60, 0x7E, 0x150, 0x1FC },
    { 0x140, 0x100, 0x160, 0x17E, 0x80, 0x7E, 0x160, 0x1FC },
    { 0x140, 0x100, 0x14E, 0x18A, 0x38, 0x8A, 0x170, 0x1FC },
    { 0x140, 0x100, 0x166, 0x1BD, 0x98, 0xBD, 0x150, 0x1FB },
    { 0x140, 0x100, 0x16E, 0x1BD, 0xB8, 0xBD, 0x160, 0x1FB },
    { 0x140, 0x100, 0x176, 0x1BD, 0xD8, 0xBD, 0x170, 0x1FB },
    { 0x140, 0x100, 0x14E, 0x15A, 0x38, 0x5A, 0x150, 0x1FA },
    { 0x140, 0x100, 0x140, 0x1BE, 0, 0xBE, 0x160, 0x1FA },
    { 0x140, 0x100, 0x17A, 0x100, 0xE8, 0, 0x170, 0x1FA },
};
u16 actor16Talk0Actions[] = { START_EVENT(0x49), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, NULL, 0x11F },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x125 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x122 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x12A },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x128 },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x129 },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x127 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, NULL, 0x121 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, NULL, 0x123 },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { NULL, NULL, 0x124 },
    { NULL, NULL, 0 },
};
FieldTalk actor13Talks[] = {
    { NULL, NULL, 0x120 },
    { NULL, NULL, 0 },
};
FieldTalk actor14Talks[] = {
    { NULL, NULL, 0x11E },
    { NULL, NULL, 0 },
};
FieldTalk actor15Talks[] = {
    { NULL, NULL, 0x126 },
    { NULL, NULL, 0 },
};
FieldTalk actor16Talks[] = {
    { NULL, actor16Talk0Actions, 0x11D },
    { NULL, NULL, 0 },
};
FieldTalk actor17Talks[] = {
    { NULL, NULL, 0x200 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor10Conditions[] = { SPECIAL(0x1E), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor11Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor12Conditions[] = { SPECIAL(0x1E), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor13Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor14Conditions[] = { SPECIAL(0x3D), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor15Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor16Conditions[] = { FLAG(0x40, 0x52), 0, CODES_END };
u16 actor17Conditions[] = { PROGRESS(0x1C), 1, CODES_END };
u16 actor18Conditions[] = { PROGRESS(0x1C), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x2E, 4, 517, 289, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x31, 5, 321, 193, 3 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x39, 6, 241, 217, 3 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x40, 7, 241, 217, 3 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x41, 8, 517, 289, 3 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x42, 9, 321, 193, 3 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x90, 0xA, 417, 201, 3 };
FieldActorEntry actor7 = { NULL, NULL, 0x93, 0xB, 198, 184, 6 };
FieldActorEntry actor8 = { NULL, NULL, 0x94, 0xC, 223, 172, 7 };
FieldActorEntry actor9 = { NULL, NULL, 0x95, 0xD, 248, 160, 7 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x9D, 0xE, 241, 217, 3 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x9D, 0xE, 241, 217, 3 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x9E, 0xF, 321, 193, 3 };
FieldActorEntry actor13 = { actor13Conditions, actor13Talks, 0x9E, 0xF, 321, 193, 3 };
FieldActorEntry actor14 = { actor14Conditions, actor14Talks, 0x9F, 0x10, 517, 289, 1 };
FieldActorEntry actor15 = { actor15Conditions, actor15Talks, 0x9F, 0x10, 517, 289, 1 };
FieldActorEntry actor16 = { actor16Conditions, actor16Talks, 0xD2, 0x11, 417, 201, 3 };
FieldActorEntry actor17 = { actor17Conditions, actor17Talks, 0x119, 0x12, 520, 252, 3 };
FieldActorEntry actor18 = { actor18Conditions, NULL, 0x13C, 0x13, 0, 0, 1 };
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 323, 114, 0, 0 },
    { 1, 0, 0xA0, 6, 0xA, 0, 0, 0, 0, 0, 367, 110, 0, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 205, 181, 199, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 237, 165, 183, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 270, 149, 167, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 186, 161, 199, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 218, 145, 183, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 252, 129, 167, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 521, 189, 272, 0 },
    { 1, 0, 0xA0, 4, 1, 0, 0, 0, 0, 0, 367, 110, 256, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 230, 243, 272, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 259, 221, 255, 0 },
    { 1, 0, 0x58, 4, 4, 0, 0, 0, 0, 0, 171, 118, 198, 0 },
    { 1, 0, 0x55, 4, 5, 0, 0, 0, 0, 0, 138, 106, 182, 0 },
    { 1, 0, 0x5C, 4, 6, 0, 0, 0, 0, 0, 263, 68, 153, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2AB, 0x32A, 0x9C, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2AB, 0x238, 0x8C, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 4, 0x1CE, 0xE6, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 4, 0x1BE, 0x12E, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 6, 0x220, 0x150, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 6, 0x230, 0x1B8, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 750, script750, EVENT_TEXT(0x22), NULL, func_800A4D94 },
    { 751, script751, EVENT_TEXT(0x1E), NULL, func_800A4DE0 },
    { -1, NULL, 0, NULL, NULL },
};
