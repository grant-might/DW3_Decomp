#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

/* Sets flag 0x7C0C */
void func_800A5E84(void) {
    FLAGS_00.applyAction(0x7C0C, 1);
}

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x1A2;
    D_800990B4.sheetEntry = 0x8EF0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x8EE;
    D_800990B4.start = (Vec2){0xBC00, 0xB600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, 0x8EF0001);
    D_8009A70C.setFile(7, 0x8EF0002);
    D_8009A70C.unk50(0);
}

void func_800A5E84();
extern u16 D_800A6040[];
extern u16 D_800A6048[];
extern u16 D_800A6050[];
extern u16 D_800A6058[];
extern u16 D_800A6064[];
extern u16 D_800A606C[];
extern u16 D_800A607C[];
extern u16 D_800A6084[];
extern u16 D_800A6098[];
extern u16 D_800A60A0[];
extern u16 D_800A60B8[];
extern u16 D_800A60C0[];
extern u16 D_800A60DC[];
extern u16 D_800A60E4[];
extern u16 D_800A6100[];
extern FieldTalk D_800A6110[];
extern FieldTalk D_800A6128[];
extern FieldTalk D_800A6140[];
extern FieldTalk D_800A61A0[];
extern FieldActorEntry D_800A61B8;
extern FieldActorEntry D_800A61CC;
extern FieldActorEntry D_800A61E0;
extern FieldActorEntry D_800A61F4;
extern s16 D_800A63EC[];

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14A, 0x18A, 0x28, 0x8A, 0x160, 0x1FF },
    { 0x140, 0x100, 0x152, 0x187, 0x48, 0x87, 0x170, 0x1FF },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x166, 0x18B, 0x98, 0x8B, 0x160, 0x1FE },
};
u16 D_800A6040[] = { 0x7A28, 1, 0xFFFF };
u16 D_800A6048[] = { 0x9070, 1, 0xFFFF };
u16 D_800A6050[] = { 0x1805, 1, 0xFFFF };
u16 D_800A6058[] = { 0x1805, 0, 0, 0, 0xFFFF };
u16 D_800A6064[] = { 0, 1, 0xFFFF };
u16 D_800A606C[] = { 0x1805, 0, 0, 1, 1, 0, 0xFFFF };
u16 D_800A607C[] = { 1, 1, 0xFFFF };
u16 D_800A6084[] = { 0x1805, 0, 0, 1, 1, 1, 2, 0, 0xFFFF };
u16 D_800A6098[] = { 2, 1, 0xFFFF };
u16 D_800A60A0[] = {
    0x1805, 0, 0, 1, 1, 1, 2, 1,
    3, 0, 0xFFFF,
};
u16 D_800A60B8[] = { 3, 1, 0xFFFF };
u16 D_800A60C0[] = {
    0x1805, 0, 0, 1, 1, 1, 2, 1,
    4, 0, 3, 1, 0xFFFF,
};
u16 D_800A60DC[] = { 4, 1, 0xFFFF };
u16 D_800A60E4[] = {
    3, 1, 0x1805, 0, 0, 1, 1, 1,
    2, 1, 4, 1, 0xFFFF,
};
u16 D_800A6100[] = { 0x7013, 1, 0x1805, 1, 0x7092, 1, 0xFFFF };
FieldTalk D_800A6110[] = {
    { NULL, D_800A6040, 0x2B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6128[] = {
    { NULL, D_800A6048, 0x2C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6140[] = {
    { D_800A6050, NULL, 0x31 },
    { D_800A6058, D_800A6064, 0x2E },
    { D_800A606C, D_800A607C, 0x30 },
    { D_800A6084, D_800A6098, 0x30 },
    { D_800A60A0, D_800A60B8, 0x30 },
    { D_800A60C0, D_800A60DC, 0x30 },
    { D_800A60E4, D_800A6100, 0x2F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61A0[] = {
    { NULL, NULL, 0x2D },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A61B8 = { NULL, D_800A6110, 0x14, 4, 188, 154, 7 };
FieldActorEntry D_800A61CC = { NULL, D_800A6128, 0x15, 5, 175, 192, 7 };
FieldActorEntry D_800A61E0 = { NULL, D_800A6140, 0x3F, 6, 145, 289, 7 };
FieldActorEntry D_800A61F4 = { NULL, D_800A61A0, 0x177, 7, 88, 332, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A61B8,
    &D_800A61CC,
    &D_800A61E0,
    &D_800A61F4,
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
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 215, 20, 86, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 144, 185, 200, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 125, 175, 194, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 148, 127, 167, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 240, 127, 162, 0 },
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
#define EVENT_TEXT_FILE 0x158
FieldEvent stageEvents[] = {
    { 1612, D_800A63EC, EVENT_TEXT(6), NULL, func_800A5E84 },
    { -1, NULL, 0, NULL, NULL },
};
s16 D_800A63EC[] = {
    0x102, 2, 0xCF, 0xD0, 3,
    0x100, 0x15, 0xAF, 0xC0,
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
    0x304, 0xC0A, 0, 0, 0,
    0,
};
