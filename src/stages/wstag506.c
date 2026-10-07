#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x5B2
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x5C2
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x27400, 0x1A400};
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

s16 script1221[] = {
    0x102, 2, 0x2D0, 0x1A0, 5,
    0x100, 0x15, 0x2F0, 0x191,
    0x101, 0x15, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 1,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 1,
    0x300, 0x5A,
    0x304, 0xC0D, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x125, 0xD8, 0x25, 0x140, 0x1FF },
    { 0x140, 0x100, 0x156, 0x143, 0x58, 0x43, 0x150, 0x1FF },
    { 0x140, 0x100, 0x140, 0x16F, 0, 0x6F, 0x160, 0x1FF },
    { 0x140, 0x100, 0x148, 0x16F, 0x20, 0x6F, 0x170, 0x1FF },
    { 0x140, 0x100, 0x150, 0x173, 0x40, 0x73, 0x140, 0x1FE },
    { 0x140, 0x100, 0x158, 0x173, 0x60, 0x73, 0x150, 0x1FE },
};
u16 actor0Talk0Actions[] = { 0x7A2C, 1, CODES_END };
u16 actor1Talk0Actions[] = { START_EVENT(0x10), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x1A3 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, actor1Talk0Actions, 0x1A2 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x11B },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x118 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x117 },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x119 },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x11A },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x11C },
    { NULL, NULL, 0 },
};
u16 actor2Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor4Conditions[] = { SPECIAL(0x1E), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor5Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor6Conditions[] = { SPECIAL(0x1E), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor7Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
FieldActorEntry actor0 = { NULL, actor0Talks, 0x14, 4, 673, 370, 1 };
FieldActorEntry actor1 = { NULL, actor1Talks, 0x15, 5, 752, 401, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x30, 6, 273, 217, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x35, 7, 550, 222, 5 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x9D, 8, 550, 222, 5 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x9D, 8, 550, 222, 5 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x9E, 9, 273, 217, 1 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x9E, 9, 273, 217, 1 };
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
    { 1, 0, 0x50, 4, 0, 0, 0, 0, 0, 0, 510, 318, 407, 0 },
    { 1, 0, 0x80, 4, 1, 0, 0, 0, 0, 0, 671, 351, 374, 0 },
    { 1, 0, 0x80, 4, 2, 0, 0, 0, 0, 0, 676, 315, 367, 0 },
    { 1, 0, 0xE0, 4, 3, 0, 0, 0, 0, 0, 608, 315, 374, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 175, 201, 239, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 207, 185, 224, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 237, 176, 208, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 632, 227, 236, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 615, 191, 229, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 575, 174, 212, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2AB, 0xE8, 0x17C, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1221, script1221, EVENT_TEXT(9), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
