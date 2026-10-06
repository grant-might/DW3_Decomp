#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x7C17, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xDB
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x635
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x645
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x10000, 0x12500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F50[];
extern u16 D_800A4F58[];
extern FieldTalk D_800A4F60[];
extern FieldTalk D_800A4F78[];
extern FieldActorEntry D_800A4F90;
extern FieldActorEntry D_800A4FA4;
extern s16 D_800A4E60[];

s16 D_800A4E60[] = {
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
    0x304, 0xC15, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16C, 0x100, 0xB0, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x160, 0x100, 0x80, 0, 0x160, 0x1FF },
};
u16 D_800A4F50[] = { 0x7A25, 1, 0xFFFF };
u16 D_800A4F58[] = { 0x9066, 1, 0xFFFF };
FieldTalk D_800A4F60[] = {
    { NULL, D_800A4F50, 0x16B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F78[] = {
    { NULL, D_800A4F58, 0x168 },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A4F90 = { NULL, D_800A4F60, 0x14, 4, 225, 289, 7 };
FieldActorEntry D_800A4FA4 = { NULL, D_800A4F78, 0x15, 5, 283, 251, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A4F90,
    &D_800A4FA4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 318, 111, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 383, 142, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 172, 267, 294, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 224, 235, 262, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x262, 0x248, 0x18C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1460, D_800A4E60, EVENT_TEXT(0x26), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
