#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x607
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x617
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x21C00, 0x18300};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x15;
    D_800990B4.music = 0x60540000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F2C[];
extern u16 D_800A4F34[];
extern u16 D_800A4F3C[];
extern u16 D_800A4F44[];
extern u16 D_800A4F4C[];
extern u16 D_800A4F54[];
extern u16 D_800A4F5C[];
extern u16 D_800A4F64[];
extern u16 D_800A4F6C[];
extern u16 D_800A4F74[];
extern u16 D_800A4F7C[];
extern u16 D_800A4F88[];
extern u16 D_800A4F90[];
extern u16 D_800A4FA0[];
extern u16 D_800A4FB0[];
extern u16 D_800A50D8[];
extern FieldTalk D_800A4FC4[];
extern u16 D_800A50E0[];
extern FieldTalk D_800A4FF4[];
extern u16 D_800A50E8[];
extern FieldTalk D_800A5024[];
extern u16 D_800A50F0[];
extern FieldTalk D_800A5054[];
extern u16 D_800A50F8[];
extern FieldTalk D_800A506C[];
extern u16 D_800A5100[];
extern FieldTalk D_800A5084[];
extern u16 D_800A5108[];
extern FieldTalk D_800A509C[];
extern FieldActorEntry D_800A511C;
extern FieldActorEntry D_800A5130;
extern FieldActorEntry D_800A5144;
extern FieldActorEntry D_800A5158;
extern FieldActorEntry D_800A516C;
extern FieldActorEntry D_800A5180;
extern FieldActorEntry D_800A5194;
extern FieldActorEntry D_800A51A8;
extern FieldActorEntry D_800A51BC;
extern FieldActorEntry D_800A51D0;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x150, 0xD0, 0x50, 0x160, 0x1F6 },
    { 0x140, 0x100, 0x14C, 0x178, 0x30, 0x78, 0x160, 0x1F5 },
    { 0x140, 0x100, 0x154, 0x178, 0x50, 0x78, 0x170, 0x1F5 },
    { 0x140, 0x100, 0x16C, 0x190, 0xB0, 0x90, 0x140, 0x1F4 },
    { 0x140, 0x100, 0x140, 0x198, 0, 0x98, 0x160, 0x1F4 },
    { 0x140, 0x100, 0x174, 0x198, 0xD0, 0x98, 0x170, 0x1F4 },
    { 0x140, 0x100, 0x148, 0x1A0, 0x20, 0xA0, 0x140, 0x1F3 },
    { 0x140, 0x100, 0x150, 0x1A0, 0x40, 0xA0, 0x150, 0x1F3 },
    { 0x140, 0x100, 0x158, 0x1A0, 0x60, 0xA0, 0x160, 0x1F3 },
    { 0x140, 0x100, 0x15C, 0x178, 0x70, 0x78, 0x170, 0x1F3 },
};
u16 D_800A4F2C[] = { 0x701D, 1, 0xFFFF };
u16 D_800A4F34[] = { 0x6025, 1, 0xFFFF };
u16 D_800A4F3C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A4F44[] = { 0x701D, 1, 0xFFFF };
u16 D_800A4F4C[] = { 0x6025, 1, 0xFFFF };
u16 D_800A4F54[] = { 0x6026, 1, 0xFFFF };
u16 D_800A4F5C[] = { 0x701D, 1, 0xFFFF };
u16 D_800A4F64[] = { 0x6025, 1, 0xFFFF };
u16 D_800A4F6C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A4F74[] = { 0x8668, 1, 0xFFFF };
u16 D_800A4F7C[] = { 0x8668, 0, 0, 0, 0xFFFF };
u16 D_800A4F88[] = { 0, 1, 0xFFFF };
u16 D_800A4F90[] = { 0x8668, 0, 0, 1, 0x8464, 0, 0xFFFF };
u16 D_800A4FA0[] = { 0x8668, 0, 0, 1, 0x8464, 1, 0xFFFF };
u16 D_800A4FB0[] = { 0x8668, 1, 0x8667, 0, 0x8464, 0, 0x7013, 1, 0xFFFF };
FieldTalk D_800A4FC4[] = {
    { D_800A4F2C, NULL, 0x11F },
    { D_800A4F34, NULL, 0x120 },
    { D_800A4F3C, NULL, 0x127 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FF4[] = {
    { D_800A4F44, NULL, 0x122 },
    { D_800A4F4C, NULL, 0x123 },
    { D_800A4F54, NULL, 0x128 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5024[] = {
    { D_800A4F5C, NULL, 0x125 },
    { D_800A4F64, NULL, 0x126 },
    { D_800A4F6C, NULL, 0x129 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5054[] = {
    { NULL, NULL, 0x11E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A506C[] = {
    { NULL, NULL, 0x121 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5084[] = {
    { NULL, NULL, 0x124 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A509C[] = {
    { D_800A4F74, NULL, 0x2FE },
    { D_800A4F7C, D_800A4F88, 0x2FF },
    { D_800A4F90, NULL, 0x300 },
    { D_800A4FA0, D_800A4FB0, 0x301 },
    { NULL, NULL, 0 },
};
u16 D_800A50D8[] = { 0x701E, 1, 0xFFFF };
u16 D_800A50E0[] = { 0x701E, 1, 0xFFFF };
u16 D_800A50E8[] = { 0x701E, 1, 0xFFFF };
u16 D_800A50F0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A50F8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5100[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5108[] = { 0x7042, 1, 0x704A, 1, 0x8667, 1, 0x8668, 0, 0xFFFF };
FieldActorEntry D_800A511C = { D_800A50D8, D_800A4FC4, 0x20, 4, 385, 417, 3 };
FieldActorEntry D_800A5130 = { D_800A50E0, D_800A4FF4, 0x24, 5, 449, 360, 5 };
FieldActorEntry D_800A5144 = { D_800A50E8, D_800A5024, 0x59, 6, 515, 414, 7 };
FieldActorEntry D_800A5158 = { NULL, NULL, 0x9A, 7, 641, 350, 0 };
FieldActorEntry D_800A516C = { NULL, NULL, 0x9B, 8, 593, 325, 1 };
FieldActorEntry D_800A5180 = { NULL, NULL, 0x9C, 9, 545, 301, 2 };
FieldActorEntry D_800A5194 = { D_800A50F0, D_800A5054, 0x9D, 0xA, 385, 417, 3 };
FieldActorEntry D_800A51A8 = { D_800A50F8, D_800A506C, 0x9E, 0xB, 449, 360, 5 };
FieldActorEntry D_800A51BC = { D_800A5100, D_800A5084, 0x9F, 0xC, 515, 414, 7 };
FieldActorEntry D_800A51D0 = { D_800A5108, D_800A509C, 0xAC, 0xD, 400, 232, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A511C,
    &D_800A5130,
    &D_800A5144,
    &D_800A5158,
    &D_800A516C,
    &D_800A5180,
    &D_800A5194,
    &D_800A51A8,
    &D_800A51BC,
    &D_800A51D0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x40, 2, 0, 3, 6, 0, 521, 212, 0, 0 },
    { 1, 0, 0x40, 2, 0x40, 2, 0, 3, 6, 0, 569, 236, 0, 0 },
    { 1, 0, 0x40, 2, 0x41, 2, 0, 3, 6, 0, 617, 260, 0, 0 },
    { 1, 0, 0x40, 2, 0x43, 2, 0, 5, 6, 0, 392, 163, 0, 0 },
    { 1, 0, 0x40, 2, 0x44, 2, 0, 5, 6, 0, 369, 205, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 3, 6, 0, 360, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 2, 0, 5, 6, 0, 361, 186, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 377, 371, 399, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2BE, 0x2D4, 0xC4, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x1D0, 0xF8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x1E0, 0x150, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
