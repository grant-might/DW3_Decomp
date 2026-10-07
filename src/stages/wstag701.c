#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x7C1B, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x65A
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x66A
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x14400, 0xF700};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 7;
    FIELDSTG_state.music = MUSIC(7, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1464[] = {
    0x102, 2, 0x13B, 0x10B, 3,
    0x100, 0x15, 0x11B, 0xFB,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x24,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC19, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x12B, 0, 0x2B, 0x150, 0x1FF },
    { 0x140, 0x100, 0x160, 0x123, 0x80, 0x23, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x123, 0xB0, 0x23, 0x170, 0x1FF },
    { 0x140, 0x100, 0x174, 0x123, 0xD0, 0x23, 0x150, 0x1FE },
    { 0x140, 0x100, 0x148, 0x12B, 0x20, 0x2B, 0x160, 0x1FE },
    { 0x140, 0x100, 0x150, 0x12B, 0x40, 0x2B, 0x170, 0x1FE },
};
u16 actor0Talk0Actions[] = { 0x7A2F, 1, CODES_END };
u16 actor1Talk0Actions[] = { START_EVENT(0x6A), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x2CE },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, actor1Talk0Actions, 0x2CF },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x1ED },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x1EB },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x1EC },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x1EC },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x1EE },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x1EE },
    { NULL, NULL, 0 },
};
u16 actor2Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor4Conditions[] = { SPECIAL(0x1E), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor5Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor6Conditions[] = { SPECIAL(0x1E), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor7Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
FieldActorEntry actor0 = { NULL, actor0Talks, 0x14, 4, 225, 289, 7 };
FieldActorEntry actor1 = { NULL, actor1Talks, 0x15, 5, 283, 251, 7 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x33, 6, 145, 297, 7 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x38, 7, 288, 209, 3 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x9D, 8, 288, 209, 3 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x9D, 8, 288, 209, 3 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x9E, 9, 145, 297, 7 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x9E, 9, 145, 297, 7 };
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
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 318, 111, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 383, 142, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 224, 235, 262, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 172, 267, 294, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2CA, 0x248, 0x18C, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1464, script1464, EVENT_TEXT(0x27), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
