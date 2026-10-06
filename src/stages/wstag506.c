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
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x27400, 0x1A400};
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

extern u16 D_800A4F6C[];
extern u16 D_800A4F74[];
extern FieldTalk D_800A4F7C[];
extern FieldTalk D_800A4F94[];
extern u16 D_800A503C[];
extern FieldTalk D_800A4FAC[];
extern u16 D_800A5048[];
extern FieldTalk D_800A4FC4[];
extern u16 D_800A5054[];
extern FieldTalk D_800A4FDC[];
extern u16 D_800A5060[];
extern FieldTalk D_800A4FF4[];
extern u16 D_800A5068[];
extern FieldTalk D_800A500C[];
extern u16 D_800A5074[];
extern FieldTalk D_800A5024[];
extern FieldActorEntry D_800A507C;
extern FieldActorEntry D_800A5090;
extern FieldActorEntry D_800A50A4;
extern FieldActorEntry D_800A50B8;
extern FieldActorEntry D_800A50CC;
extern FieldActorEntry D_800A50E0;
extern FieldActorEntry D_800A50F4;
extern FieldActorEntry D_800A5108;
extern s16 D_800A4E38[];

s16 D_800A4E38[] = {
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
u16 D_800A4F6C[] = { 0x7A2C, 1, 0xFFFF };
u16 D_800A4F74[] = { 0x9010, 1, 0xFFFF };
FieldTalk D_800A4F7C[] = {
    { NULL, D_800A4F6C, 0x1A3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F94[] = {
    { NULL, D_800A4F74, 0x1A2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FAC[] = {
    { NULL, NULL, 0x11B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FC4[] = {
    { NULL, NULL, 0x118 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FDC[] = {
    { NULL, NULL, 0x117 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FF4[] = {
    { NULL, NULL, 0x119 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A500C[] = {
    { NULL, NULL, 0x11A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5024[] = {
    { NULL, NULL, 0x11C },
    { NULL, NULL, 0 },
};
u16 D_800A503C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5048[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5054[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5060[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5068[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5074[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A507C = { NULL, D_800A4F7C, 0x14, 4, 673, 370, 1 };
FieldActorEntry D_800A5090 = { NULL, D_800A4F94, 0x15, 5, 752, 401, 1 };
FieldActorEntry D_800A50A4 = { D_800A503C, D_800A4FAC, 0x30, 6, 273, 217, 1 };
FieldActorEntry D_800A50B8 = { D_800A5048, D_800A4FC4, 0x35, 7, 550, 222, 5 };
FieldActorEntry D_800A50CC = { D_800A5054, D_800A4FDC, 0x9D, 8, 550, 222, 5 };
FieldActorEntry D_800A50E0 = { D_800A5060, D_800A4FF4, 0x9D, 8, 550, 222, 5 };
FieldActorEntry D_800A50F4 = { D_800A5068, D_800A500C, 0x9E, 9, 273, 217, 1 };
FieldActorEntry D_800A5108 = { D_800A5074, D_800A5024, 0x9E, 9, 273, 217, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A507C,
    &D_800A5090,
    &D_800A50A4,
    &D_800A50B8,
    &D_800A50CC,
    &D_800A50E0,
    &D_800A50F4,
    &D_800A5108,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2AB, 0xE8, 0x17C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1221, D_800A4E38, EVENT_TEXT(9), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
