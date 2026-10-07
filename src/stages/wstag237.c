#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    GAME.progress = 13;
}

#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x2A9
#define STAGE_ARCHIVE 0x330
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x2B8
#define STAGE_ARCHIVE 0x33F
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_ARCHIVE;
    FIELDSTG_state.start = (Vec2){0x5900, 0x12C00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 4;
    FIELDSTG_state.music = MUSIC(4, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
}

s16 script300[] = {
    0x600, 1, 2,
    0x102, 2, 0x17C, 0xA1, 5,
    0x100, 0xB, 0x1A1, 0x91,
    0x101, 0xB, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 0xB, 2,
    0x101, 0xB, 7, 1,
    0x301,
    0x101, 0xB, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0xB, 2,
    0x101, 0xB, 7, 1,
    0x301,
    0x101, 0xB, 1, 1,
    0x300, 0x1E,
    0x304, 0x203, 0x60, 0x190, 5,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x148, 0x130, 0x20, 0x30, 0x170, 0x1FF },
};
u16 actor0Talk0Actions[] = { START_EVENT(0x2D), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x58 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { PROGRESS(0xC), 1, ITEM(0, 0xF), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0xB, 4, 417, 145, 7 };
FieldActorEntry *stageActors[] = {
    &actor0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 1, 6, 0, 261, 137, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 53, 223, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 173, 179, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 325, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 435, 83, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 523, 127, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 555, 239, 0, 0 },
    { 1, 0x64, 0x40, 6, 1, 0, 0, 0, 0, 0, 286, 127, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 224, 144, 184, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x201, 0xF0, 0x108, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x21B, 0x138, 0x64, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x20A, 0xA7, 0x153, 3, 0x64, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 6, 0x203, 0xC2, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 6, 0x212, 0x128, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 300, script300, EVENT_TEXT(0x1B), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
