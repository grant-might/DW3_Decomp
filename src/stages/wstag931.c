#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x1A6;
    D_800990B4.sheetEntry = 0x8F50000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x8F4;
    D_800990B4.start = (Vec2){0x15A00, 0x18E00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, 0x8F50001);
    D_8009A70C.setFile(7, 0x8F50002);
    D_8009A70C.unk50(0);
}

extern u16 D_800A602C[];
extern u16 D_800A6034[];
extern u16 D_800A603C[];
extern u16 D_800A6044[];
extern u16 D_800A604C[];
extern u16 D_800A6058[];
extern u16 D_800A6064[];
extern FieldTalk D_800A6070[];
extern FieldTalk D_800A6088[];
extern FieldTalk D_800A60A0[];
extern FieldTalk D_800A60B8[];
extern u16 D_800A6118[];
extern FieldTalk D_800A60D0[];
extern u16 D_800A6120[];
extern FieldTalk D_800A6100[];
extern FieldActorEntry D_800A6128;
extern FieldActorEntry D_800A613C;
extern FieldActorEntry D_800A6150;
extern FieldActorEntry D_800A6164;
extern FieldActorEntry D_800A6178;
extern FieldActorEntry D_800A618C;
extern s16 D_800A637C[];

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1F4, 0x140, 0x2D0, 0x40, 0x150, 0x1FF },
    { 0x140, 0x100, 0x162, 0x1DC, 0x88, 0xDC, 0x160, 0x1FF },
    { 0x1C0, 0x100, 0x1CE, 0x1A4, 0x238, 0xA4, 0x170, 0x1FF },
    { 0x140, 0x100, 0x174, 0x1DC, 0xD0, 0xDC, 0x150, 0x1FE },
    { 0x1C0, 0x100, 0x1D6, 0x1A9, 0x258, 0xA9, 0x160, 0x1FE },
};
u16 D_800A602C[] = { 0x7A11, 1, 0xFFFF };
u16 D_800A6034[] = { 0x7A0F, 1, 0xFFFF };
u16 D_800A603C[] = { 0x7A10, 1, 0xFFFF };
u16 D_800A6044[] = { 0x8025, 0, 0xFFFF };
u16 D_800A604C[] = { 0x8025, 1, 0x1807, 0, 0xFFFF };
u16 D_800A6058[] = { 0x9071, 1, 0x1807, 1, 0xFFFF };
u16 D_800A6064[] = { 0x8025, 1, 0x1807, 1, 0xFFFF };
FieldTalk D_800A6070[] = {
    { NULL, D_800A602C, 0x33 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6088[] = {
    { NULL, D_800A6034, 0x32 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60A0[] = {
    { NULL, NULL, 0x86 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60B8[] = {
    { NULL, D_800A603C, 0x34 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60D0[] = {
    { D_800A6044, NULL, 0x83 },
    { D_800A604C, D_800A6058, 0x84 },
    { D_800A6064, NULL, 0x85 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6100[] = {
    { NULL, NULL, 0x85 },
    { NULL, NULL, 0 },
};
u16 D_800A6118[] = { 0x1807, 0, 0xFFFF };
u16 D_800A6120[] = { 0x1807, 1, 0xFFFF };
FieldActorEntry D_800A6128 = { NULL, D_800A6070, 0x16, 4, 449, 281, 7 };
FieldActorEntry D_800A613C = { NULL, D_800A6088, 0x17, 5, 304, 369, 7 };
FieldActorEntry D_800A6150 = { NULL, D_800A60A0, 0x34, 6, 287, 432, 3 };
FieldActorEntry D_800A6164 = { NULL, D_800A60B8, 0xB7, 7, 359, 308, 7 };
FieldActorEntry D_800A6178 = { D_800A6118, D_800A60D0, 0xFF, 8, 152, 397, 7 };
FieldActorEntry D_800A618C = { D_800A6120, D_800A6100, 0xFF, 8, 144, 352, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6128,
    &D_800A613C,
    &D_800A6150,
    &D_800A6164,
    &D_800A6178,
    &D_800A618C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x11, 2, 0, 1, 4, 0, 384, 79, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 2, 0, 1, 4, 0, 492, 137, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 2, 0, 1, 4, 0, 548, 165, 0, 0 },
    { 1, 0, 0x40, 6, 3, 1, 3, 8, 4, 0, 485, 145, 0, 0 },
    { 1, 0, 0x40, 6, 9, 1, 9, 0xE, 4, 0, 541, 172, 0, 0 },
    { 1, 0x64, 0x40, 6, 0x12, 0, 0, 0, 0, 0, 304, 99, 0, 0 },
    { 1, 0x65, 0x40, 6, 0x13, 0, 0, 0, 0, 0, 64, 285, 0, 0 },
    { 1, 0, 0xA0, 4, 0, 0, 0, 0, 0, 0, 144, 257, 380, 0 },
    { 1, 0, 0xA0, 4, 1, 0, 0, 0, 0, 0, 256, 257, 337, 0 },
    { 1, 0, 0xA0, 4, 2, 0, 0, 0, 0, 0, 384, 261, 287, 0 },
    { 1, 0, 0x60, 4, 0xF, 0, 0, 0, 0, 0, 240, 73, 150, 0 },
    { 1, 0, 0x60, 4, 0x10, 0, 0, 0, 0, 0, 0, 255, 335, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x1E0, 0x1DA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x240, 0x1AA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27D, 0x218, 0xE4, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27D, 0x128, 0x19C, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x11F, 0xBA, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x110, 0xFE, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
#define EVENT_TEXT_FILE 0x158
FieldEvent stageEvents[] = {
    { 1614, D_800A637C, EVENT_TEXT(7), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
s16 D_800A637C[] = {
    0x600, 1, 2,
    0x102, 2, 0xB0, 0x198, 3,
    0x100, 0xFF, 0x98, 0x18D,
    0x101, 0xFF, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0xFF,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0xFF,
    0x300, 0x1E,
    0x200, 0, 1, 0xFF, 2,
    0x301,
    0x300, 0x1E,
    0x102, 0xFF, 0x68, 0x174, 3,
    0x302, 0xFF,
    0x102, 0xFF, 0x90, 0x160, 5,
    0x302, 0xFF,
    0x101, 0xFF, 1, 1,
    0x300, 0x1E,
    0,
};
