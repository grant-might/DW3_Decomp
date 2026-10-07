#include "common.h"
#include "stage.h"

/* Creates the event object of the story so far, the first that applies */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 8 && FLAGS_00.checkCondition(FLAG(0x1A, 0x17), 0) && FLAGS_00.checkCondition(FLAG(0x1C, 0x43), 1)) {
            children[0] = FIELDSTG_startEvent(0xB4);
        } else if (GAME.progress == 8 && FLAGS_00.checkCondition(FLAG(0x1C, 0x43), 0)) {
            children[0] = FIELDSTG_startEvent(0xB5);
        } else if (FLAGS_00.checkCondition(FLAG(0x1A, 0x17), 1) && FLAGS_00.checkCondition(FLAG(0x1A, 0x19), 0)) {
            children[0] = FIELDSTG_startEvent(0xBE);
        } else if (FLAGS_00.checkCondition(FLAG(0x1A, 0x17), 1) && FLAGS_00.checkCondition(FLAG(0x1A, 0x19), 1) &&
                   FLAGS_00.checkCondition(ITEM(0, 0x15), 0)) {
            children[0] = FIELDSTG_startEvent(0xC8);
        } else if (GAME.progress == 9 && FLAGS_00.checkCondition(ITEM(0, 0x15), 1)) {
            children[0] = FIELDSTG_startEvent(0xE6);
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

void func_800A4EA8(void) {
    FLAGS_00.applyAction(FLAG(0x1A, 0x17), 1);
}

/* Sets the progress to 10 and applies flag action 0x800D */
void func_800A4ED4(void) {
    GAME.progress = 10;
    FLAGS_00.applyAction(ITEM(0, 0xD), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x223
#define STAGE_ARCHIVE 0x3CA
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x232
#define STAGE_ARCHIVE 0x3DA
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_ARCHIVE;
    FIELDSTG_state.start = (Vec2){0x8E00, 0x10000};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0xF;
    FIELDSTG_state.music = MUSIC(0xF, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFirstMap(0);
}

s16 script160[] = {
    0x600, 1, 2,
    0x102, 2, 0xB6, 0x113, 3,
    0x100, 0xC5, 0x76, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 3,
    0x301,
    0x300, 0x1E,
    0x304, 0x237, 0x41E, 0x19E, 1,
    0,
};
s16 script180[] = {
    0x600, 1, 2,
    0x100, 2, 0x98, 0x13C,
    0x101, 2, 1, 5,
    0x100, 0xC5, 0x76, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 5,
    0x302, 2,
    0x102, 2, 0xAF, 0x10F, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xC5, 3,
    0x301,
    0x300, 0x3C,
    0x200, 0, 8, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0xC5, 3,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 6, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 7, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 0,
    0x304, 0x237, 0x41E, 0x19E, 1,
    0,
};
s16 script181[] = {
    0x600, 1, 2,
    0x100, 2, 0x98, 0x13C,
    0x101, 2, 1, 5,
    0x100, 0xC5, 0x67, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 5,
    0x302, 2,
    0x102, 2, 0xAF, 0x10F, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x301,
    0x304, 0x237, 0x41E, 0x19E, 1,
    0,
};
s16 script190[] = {
    0x600, 1, 2,
    0x100, 2, 0x98, 0x13C,
    0x101, 2, 1, 5,
    0x100, 0xC5, 0x76, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 5,
    0x302, 2,
    0x102, 2, 0xAF, 0x10F, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 0,
    0x304, 0x237, 0x41E, 0x19E, 1,
    0,
};
s16 script200[] = {
    0x600, 1, 2,
    0x100, 2, 0x98, 0x13C,
    0x101, 2, 1, 5,
    0x100, 0xC5, 0x76, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 5,
    0x101, 0x32D, 1, 0,
    0x302, 2,
    0x102, 2, 0xAF, 0x10F, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 0,
    0x304, 0x237, 0x41E, 0x19E, 1,
    0,
};
s16 script230[] = {
    0x600, 1, 2,
    0x100, 2, 0x98, 0x13C,
    0x101, 2, 1, 5,
    0x100, 0xC5, 0x67, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 5,
    0x302, 2,
    0x102, 2, 0xAF, 0x10F, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x301,
    0x100, 0x13F, 0x90, 0x101,
    0x101, 0x13F, 1, 7,
    0x300, 0x3C,
    0x200, 0, 2, 0xC5, 3,
    0x301,
    0x300, 0x5A,
    0x200, 0, 3, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 3,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x3C,
    0x100, 0xC5, 0x67, 0xED,
    0x101, 0xC5, 0x46, 7,
    0x303, 0xC5,
    0x101, 0xC5, 1, 7,
    0x300, 0x1E,
    0x200, 0, 0xD, 0xC5, 2,
    0x301,
    0x300, 0x1E,
    0x102, 0xC5, 0x88, 0xFD, 7,
    0x302, 0xC5,
    0x100, 0x84, 0x90, 0x101,
    0x101, 0x84, 1, 7,
    0x100, 0xC5, 0, 0,
    0x101, 0xC5, 1, 0,
    0x100, 0x13F, 0, 0,
    0x101, 0x13F, 1, 7,
    0x101, 0x32D, 0x36D, 2,
    0x300, 0x3C,
    0x200, 0, 7, 0x84, 0,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 8, 0x84, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 9, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xA, 0x84, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xB, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xC, 0x84, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x141, 0,
    0x300, 6,
    0x304, 0x237, 0x412, 0x1A4, 1,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14C, 0x100, 0x30, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15C, 0x100, 0x70, 0, 0x140, 0x1FE },
};
u16 actor0Talk0Conditions[] = { FLAG(0x1C, 0x35), 0, CODES_END };
u16 actor0Talk0Actions[] = { FLAG(0x1C, 0x35), 1, CODES_END };
u16 actor0Talk1Conditions[] = { FLAG(0x1C, 0x35), 1, CODES_END };
u16 actor0Talk1Actions[] = { 0x7C01, 1, CODES_END };
u16 actor8Talk0Conditions[] = { FLAG(0x1A, 0x2A), 0, CODES_END };
u16 actor8Talk1Conditions[] = { FLAG(0x1A, 0x2A), 1, ITEM(0, 0xE), 0, CODES_END };
u16 actor8Talk1Actions[] = { FLAG(0x1A, 0x2B), 1, CODES_END };
u16 actor8Talk2Conditions[] = { FLAG(0x1A, 0x2A), 1, ITEM(0, 0xE), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, actor0Talk0Actions, 0x30F },
    { actor0Talk1Conditions, actor0Talk1Actions, 0x35E },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x124 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x126 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x127 },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x129 },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x11F },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x120 },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { actor8Talk0Conditions, NULL, 0x121 },
    { actor8Talk1Conditions, actor8Talk1Actions, 0x2ED },
    { actor8Talk2Conditions, NULL, 0x2EE },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { NULL, NULL, 0x122 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, NULL, 0x123 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, NULL, 0x128 },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { NULL, NULL, 0x125 },
    { NULL, NULL, 0 },
};
FieldTalk actor13Talks[] = {
    { NULL, NULL, 0x125 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { SPECIAL(0x93), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(9), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0x18), 1, CODES_END };
u16 actor3Conditions[] = { SPECIAL(0x19), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor5Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0xA), 1, CODES_END };
u16 actor7Conditions[] = { PROGRESS(0xC), 1, CODES_END };
u16 actor8Conditions[] = { PROGRESS(0xE), 1, CODES_END };
u16 actor9Conditions[] = { SPECIAL(0x16), 1, CODES_END };
u16 actor10Conditions[] = { SPECIAL(0x17), 1, CODES_END };
u16 actor11Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor12Conditions[] = { PROGRESS(0x19), 1, CODES_END };
u16 actor13Conditions[] = { PROGRESS(0x1A), 1, CODES_END };
u16 actor14Conditions[] = { PROGRESS(8), 1, CODES_END };
u16 actor15Conditions[] = { PROGRESS(7), 1, CODES_END };
u16 actor16Conditions[] = { PROGRESS(9), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x3D, 4, 288, 296, 1 };
FieldActorEntry actor1 = { actor1Conditions, NULL, 0x84, 5, 0, 0, 7 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor13 = { actor13Conditions, actor13Talks, 0x84, 5, 144, 257, 7 };
FieldActorEntry actor14 = { actor14Conditions, NULL, 0xC5, 6, 0, 0, 1 };
FieldActorEntry actor15 = { actor15Conditions, NULL, 0xC5, 6, 0, 0, 1 };
FieldActorEntry actor16 = { actor16Conditions, NULL, 0xC5, 6, 0, 0, 1 };
FieldActorEntry actor17 = { NULL, NULL, 0x13F, 7, 0, 0, 1 };
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x37, 0xA, 0, 216, 262, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3D, 0xA, 0, 72, 170, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x43, 0xA, 0, 348, 225, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x43, 0xA, 0, 355, 229, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x237, 0x412, 0x1A4, 1, 0, 0, 0 },
    { { { PROGRESS(7), 1 }, { CODES_END, 0 } }, 8, 0xA0, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 160, script160, EVENT_TEXT(7), NULL, NULL },
    { 180, script180, EVENT_TEXT(0xA), NULL, func_800A4EA8 },
    { 181, script181, EVENT_TEXT(0xB), NULL, NULL },
    { 190, script190, EVENT_TEXT(0xC), NULL, NULL },
    { 200, script200, EVENT_TEXT(0xD), NULL, NULL },
    { 230, script230, EVENT_TEXT(0xE), NULL, func_800A4ED4 },
    { -1, NULL, 0, NULL, NULL },
};
