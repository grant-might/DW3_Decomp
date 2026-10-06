#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

/* Event: sets flag 0x7C0D */
void func_800A5E84(void) {
    FLAGS_00.applyAction(0x7C0D, 1);
}

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x21E;
    D_800990B4.sheetEntry = 0x9130000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x912;
    D_800990B4.start = (Vec2){0x19300, 0x14800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, 0x9130001);
    D_8009A70C.setFile(7, 0x9130002);
    D_8009A70C.unk50(0);
}

void func_800A5E84();
extern u16 D_800A6058[];
extern u16 D_800A6060[];
extern FieldTalk D_800A6068[];
extern FieldTalk D_800A6080[];
extern FieldTalk D_800A6098[];
extern FieldActorEntry D_800A60B0;
extern FieldActorEntry D_800A60C4;
extern FieldActorEntry D_800A60D8;
extern FieldActorEntry D_800A60EC;
extern FieldActorEntry D_800A6100;
extern s16 D_800A63EC[];

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x166, 0, 0x66, 0x150, 0x1FB },
    { 0x140, 0x100, 0x170, 0x100, 0xC0, 0, 0x160, 0x1FB },
    { 0x140, 0x100, 0x168, 0x169, 0xA0, 0x69, 0x170, 0x1FB },
    { 0x140, 0x100, 0x15A, 0x16C, 0x68, 0x6C, 0x140, 0x1FA },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A6058[] = { 0x7A29, 1, 0xFFFF };
u16 D_800A6060[] = { 0x907A, 1, 0xFFFF };
FieldTalk D_800A6068[] = {
    { NULL, D_800A6058, 0x2B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6080[] = {
    { NULL, D_800A6060, 0x2C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6098[] = {
    { NULL, NULL, 0x6F },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A60B0 = { NULL, D_800A6068, 0x14, 4, 345, 308, 7 };
FieldActorEntry D_800A60C4 = { NULL, D_800A6080, 0x15, 5, 121, 165, 7 };
FieldActorEntry D_800A60D8 = { NULL, D_800A6098, 0x3A, 6, 177, 153, 3 };
FieldActorEntry D_800A60EC = { NULL, NULL, 0x78, 7, 374, 268, 5 };
FieldActorEntry D_800A6100 = { NULL, NULL, 0xDB, 8, 346, 325, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A60B0,
    &D_800A60C4,
    &D_800A60D8,
    &D_800A60EC,
    &D_800A6100,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 484, 223, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 57, 39, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 89, 23, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 203, 224, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 272, 360, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 292, 139, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 305, 376, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 337, 393, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 467, 220, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 4, 0, 344, 109, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 3, 4, 0, 321, 107, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 370, 108, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 289, 326, 340, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 294, 310, 332, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 322, 310, 325, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 337, 303, 317, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 351, 282, 309, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 375, 277, 301, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 383, 270, 293, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 400, 271, 285, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 415, 270, 282, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 77, 127, 175, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 109, 113, 158, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 141, 97, 142, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 174, 81, 127, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 257, 176, 209, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 255, 245, 263, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 239, 252, 272, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 420, 237, 278, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x291, 0x80, 0x31C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x293, 0x8C, 0xC2, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0xFA, 0x126, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x10B, 0x188, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
#define EVENT_TEXT_FILE 0x158
FieldEvent stageEvents[] = {
    { 1648, D_800A63EC, EVENT_TEXT(0x10), NULL, func_800A5E84 },
    { -1, NULL, 0, NULL, NULL },
};
s16 D_800A63EC[] = {
    0x102, 2, 0x99, 0xB5, 3,
    0x100, 0x15, 0x79, 0xA5,
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
    0x304, 0xC0B, 0, 0, 0,
    0,
};
