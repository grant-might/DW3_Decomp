#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x4C8
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x4D8
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x9200, 0x13C00};
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

extern u16 D_800A4F58[];
extern u16 D_800A4F60[];
extern FieldTalk D_800A4F68[];
extern FieldTalk D_800A4F80[];
extern u16 D_800A4FF8[];
extern FieldTalk D_800A4F98[];
extern u16 D_800A5000[];
extern FieldTalk D_800A4FB0[];
extern u16 D_800A500C[];
extern FieldTalk D_800A4FC8[];
extern u16 D_800A5018[];
extern FieldTalk D_800A4FE0[];
extern FieldActorEntry D_800A5020;
extern FieldActorEntry D_800A5034;
extern FieldActorEntry D_800A5048;
extern FieldActorEntry D_800A505C;
extern FieldActorEntry D_800A5070;
extern FieldActorEntry D_800A5084;
extern s16 D_800A4E34[];

s16 D_800A4E34[] = {
    0x102, 2, 0xCF, 0xD0, 3,
    0x100, 0x15, 0xAF, 0xC0,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC0A, 0, 0, 0,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x148, 0x16B, 0x20, 0x6B, 0x160, 0x1FF },
    { 0x140, 0x100, 0x173, 0x100, 0xCC, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x169, 0xB0, 0x69, 0x160, 0x1FE },
    { 0x140, 0x100, 0x150, 0x16B, 0x40, 0x6B, 0x170, 0x1FE },
    { 0x140, 0x100, 0x158, 0x16B, 0x60, 0x6B, 0x140, 0x1FD },
};
u16 D_800A4F58[] = { 0x7A28, 1, 0xFFFF };
u16 D_800A4F60[] = { 0x9002, 1, 0xFFFF };
FieldTalk D_800A4F68[] = {
    { NULL, D_800A4F58, 0x1A3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F80[] = {
    { NULL, D_800A4F60, 0x1A2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F98[] = {
    { NULL, NULL, 0x61 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FB0[] = {
    { NULL, NULL, 0x5F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FC8[] = {
    { NULL, NULL, 0x5E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FE0[] = {
    { NULL, NULL, 0x60 },
    { NULL, NULL, 0 },
};
u16 D_800A4FF8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5000[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A500C[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5018[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5020 = { NULL, D_800A4F68, 0x14, 4, 188, 154, 7 };
FieldActorEntry D_800A5034 = { NULL, D_800A4F80, 0x15, 5, 175, 192, 7 };
FieldActorEntry D_800A5048 = { D_800A4FF8, D_800A4F98, 0x30, 6, 88, 332, 7 };
FieldActorEntry D_800A505C = { D_800A5000, D_800A4FB0, 0x39, 7, 88, 332, 7 };
FieldActorEntry D_800A5070 = { D_800A500C, D_800A4FC8, 0x9D, 8, 88, 332, 7 };
FieldActorEntry D_800A5084 = { D_800A5018, D_800A4FE0, 0x9D, 8, 88, 332, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5020,
    &D_800A5034,
    &D_800A5048,
    &D_800A505C,
    &D_800A5070,
    &D_800A5084,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 78, 77, 0, 0 },
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 97, 115, 0, 0 },
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 135, 231, 0, 0 },
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 141, 44, 0, 0 },
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 261, 63, 0, 0 },
    { 1, 0, 0x40, 2, 6, 2, 0, 1, 4, 0, 326, 95, 0, 0 },
    { 1, 0, 0x40, 2, 7, 2, 0, 1, 4, 0, 165, 76, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 256, 151, 184, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 240, 127, 162, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 215, 20, 86, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 144, 185, 200, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 125, 175, 194, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 148, 127, 167, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27B, 0x96, 0x114, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x2A0, 0x17A, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27E, 0x15A, 0xBA, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27A, 0x146, 0xBA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0xC8, 0xEC, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xB8, 0x132, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1201, D_800A4E34, EVENT_TEXT(0x2B), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
