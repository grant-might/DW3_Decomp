#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x282
#define STAGE_ARCHIVE 0x3C1
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x291
#define STAGE_ARCHIVE 0x3D1
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16 | 1;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0xFB00, 0x13500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 8;
    D_800990B4.music = 0x60200000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A5168[];
extern FieldTalk D_800A4F88[];
extern u16 D_800A5174[];
extern FieldTalk D_800A4FA0[];
extern u16 D_800A517C[];
extern FieldTalk D_800A4FB8[];
extern u16 D_800A5188[];
extern FieldTalk D_800A4FD0[];
extern u16 D_800A5190[];
extern FieldTalk D_800A4FE8[];
extern u16 D_800A519C[];
extern FieldTalk D_800A5000[];
extern u16 D_800A51A8[];
extern FieldTalk D_800A5018[];
extern u16 D_800A51B0[];
extern FieldTalk D_800A5030[];
extern u16 D_800A51BC[];
extern FieldTalk D_800A5048[];
extern u16 D_800A51C4[];
extern FieldTalk D_800A5060[];
extern u16 D_800A51CC[];
extern u16 D_800A51D8[];
extern u16 D_800A51E0[];
extern FieldTalk D_800A5078[];
extern u16 D_800A51EC[];
extern FieldTalk D_800A5090[];
extern u16 D_800A51F4[];
extern FieldTalk D_800A50A8[];
extern u16 D_800A5200[];
extern FieldTalk D_800A50C0[];
extern u16 D_800A5208[];
extern u16 D_800A5214[];
extern u16 D_800A521C[];
extern FieldTalk D_800A50D8[];
extern u16 D_800A5228[];
extern FieldTalk D_800A50F0[];
extern u16 D_800A5230[];
extern FieldTalk D_800A5108[];
extern u16 D_800A523C[];
extern FieldTalk D_800A5120[];
extern u16 D_800A5244[];
extern FieldTalk D_800A5138[];
extern u16 D_800A5250[];
extern FieldTalk D_800A5150[];
extern u16 D_800A5258[];
extern u16 D_800A5264[];
extern u16 D_800A526C[];
extern u16 D_800A5274[];
extern FieldActorEntry D_800A5280;
extern FieldActorEntry D_800A5294;
extern FieldActorEntry D_800A52A8;
extern FieldActorEntry D_800A52BC;
extern FieldActorEntry D_800A52D0;
extern FieldActorEntry D_800A52E4;
extern FieldActorEntry D_800A52F8;
extern FieldActorEntry D_800A530C;
extern FieldActorEntry D_800A5320;
extern FieldActorEntry D_800A5334;
extern FieldActorEntry D_800A5348;
extern FieldActorEntry D_800A535C;
extern FieldActorEntry D_800A5370;
extern FieldActorEntry D_800A5384;
extern FieldActorEntry D_800A5398;
extern FieldActorEntry D_800A53AC;
extern FieldActorEntry D_800A53C0;
extern FieldActorEntry D_800A53D4;
extern FieldActorEntry D_800A53E8;
extern FieldActorEntry D_800A53FC;
extern FieldActorEntry D_800A5410;
extern FieldActorEntry D_800A5424;
extern FieldActorEntry D_800A5438;
extern FieldActorEntry D_800A544C;
extern FieldActorEntry D_800A5460;
extern FieldActorEntry D_800A5474;
extern FieldActorEntry D_800A5488;
extern FieldActorEntry D_800A549C;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16A, 0x162, 0xA8, 0x62, 0x150, 0x1FF },
    { 0x140, 0x100, 0x140, 0x15A, 0, 0x5A, 0x160, 0x1FF },
    { 0x140, 0x100, 0x154, 0x172, 0x50, 0x72, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15C, 0x180, 0x70, 0x80, 0x150, 0x1FE },
    { 0x140, 0x100, 0x140, 0x182, 0, 0x82, 0x160, 0x1FE },
    { 0x140, 0x100, 0x164, 0x18A, 0x90, 0x8A, 0x170, 0x1FE },
    { 0x140, 0x100, 0x148, 0x193, 0x20, 0x93, 0x150, 0x1FD },
    { 0x140, 0x100, 0x172, 0x160, 0xC8, 0x60, 0x160, 0x1FD },
    { 0x140, 0x100, 0x150, 0x19A, 0x40, 0x9A, 0x170, 0x1FD },
    { 0x140, 0x100, 0x158, 0x1A8, 0x60, 0xA8, 0x140, 0x1FC },
    { 0x140, 0x100, 0x140, 0x1AA, 0, 0xAA, 0x150, 0x1FC },
    { 0x140, 0x100, 0x160, 0x1AA, 0x80, 0xAA, 0x160, 0x1FC },
    { 0x140, 0x100, 0x168, 0x1AA, 0xA0, 0xAA, 0x170, 0x1FC },
    { 0x140, 0x100, 0x170, 0x1AA, 0xC0, 0xAA, 0x140, 0x1FB },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
FieldTalk D_800A4F88[] = {
    { NULL, NULL, 0x78 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FA0[] = {
    { NULL, NULL, 0x7A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FB8[] = {
    { NULL, NULL, 0x7C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FD0[] = {
    { NULL, NULL, 0x7E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FE8[] = {
    { NULL, NULL, 0x84 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5000[] = {
    { NULL, NULL, 0x80 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5018[] = {
    { NULL, NULL, 0x82 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5030[] = {
    { NULL, NULL, 0x87 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5048[] = {
    { NULL, NULL, 0x8A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5060[] = {
    { NULL, NULL, 0x89 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5078[] = {
    { NULL, NULL, 0x77 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5090[] = {
    { NULL, NULL, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50A8[] = {
    { NULL, NULL, 0x7B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50C0[] = {
    { NULL, NULL, 0x7D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50D8[] = {
    { NULL, NULL, 0x86 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50F0[] = {
    { NULL, NULL, 0x88 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5108[] = {
    { NULL, NULL, 0x83 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5120[] = {
    { NULL, NULL, 0x85 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5138[] = {
    { NULL, NULL, 0x7F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5150[] = {
    { NULL, NULL, 0x81 },
    { NULL, NULL, 0 },
};
u16 D_800A5168[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5174[] = { 0x602B, 1, 0xFFFF };
u16 D_800A517C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5188[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5190[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A519C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51A8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A51B0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51BC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A51C4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A51CC[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A51D8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A51E0[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51EC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A51F4[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5200[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5208[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5214[] = { 0x701A, 1, 0xFFFF };
u16 D_800A521C[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5228[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5230[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A523C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5244[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5250[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5258[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5264[] = { 0x602B, 1, 0xFFFF };
u16 D_800A526C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5274[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
FieldActorEntry D_800A5280 = { D_800A5168, D_800A4F88, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A5294 = { D_800A5174, D_800A4FA0, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A52A8 = { D_800A517C, D_800A4FB8, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A52BC = { D_800A5188, D_800A4FD0, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A52D0 = { D_800A5190, D_800A4FE8, 0x35, 6, 101, 203, 5 };
FieldActorEntry D_800A52E4 = { D_800A519C, D_800A5000, 0x36, 7, 133, 187, 1 };
FieldActorEntry D_800A52F8 = { D_800A51A8, D_800A5018, 0x36, 7, 217, 257, 5 };
FieldActorEntry D_800A530C = { D_800A51B0, D_800A5030, 0x38, 8, 217, 257, 5 };
FieldActorEntry D_800A5320 = { D_800A51BC, D_800A5048, 0x39, 9, 101, 203, 5 };
FieldActorEntry D_800A5334 = { D_800A51C4, D_800A5060, 0x3A, 0xA, 133, 187, 1 };
FieldActorEntry D_800A5348 = { D_800A51CC, NULL, 0x44, 0xB, 307, 240, 5 };
FieldActorEntry D_800A535C = { D_800A51D8, NULL, 0x44, 0xB, 307, 240, 5 };
FieldActorEntry D_800A5370 = { D_800A51E0, D_800A5078, 0x9D, 0xC, 275, 255, 1 };
FieldActorEntry D_800A5384 = { D_800A51EC, D_800A5090, 0x9D, 0xC, 275, 255, 1 };
FieldActorEntry D_800A5398 = { D_800A51F4, D_800A50A8, 0x9E, 0xD, 256, 321, 1 };
FieldActorEntry D_800A53AC = { D_800A5200, D_800A50C0, 0x9E, 0xD, 256, 321, 1 };
FieldActorEntry D_800A53C0 = { D_800A5208, NULL, 0x9F, 0xE, 307, 240, 5 };
FieldActorEntry D_800A53D4 = { D_800A5214, NULL, 0x9F, 0xE, 307, 240, 5 };
FieldActorEntry D_800A53E8 = { D_800A521C, D_800A50D8, 0xA0, 0xF, 217, 257, 5 };
FieldActorEntry D_800A53FC = { D_800A5228, D_800A50F0, 0xA0, 0xF, 217, 257, 5 };
FieldActorEntry D_800A5410 = { D_800A5230, D_800A5108, 0xA1, 0x10, 101, 203, 5 };
FieldActorEntry D_800A5424 = { D_800A523C, D_800A5120, 0xA1, 0x10, 101, 203, 5 };
FieldActorEntry D_800A5438 = { D_800A5244, D_800A5138, 0xA2, 0x11, 133, 187, 1 };
FieldActorEntry D_800A544C = { D_800A5250, D_800A5150, 0xA2, 0x11, 133, 187, 1 };
FieldActorEntry D_800A5460 = { D_800A5258, NULL, 0xE0, 0x12, 267, 266, 1 };
FieldActorEntry D_800A5474 = { D_800A5264, NULL, 0xE0, 0x12, 267, 266, 1 };
FieldActorEntry D_800A5488 = { D_800A526C, NULL, 0x10E, 0x13, 267, 266, 1 };
FieldActorEntry D_800A549C = { D_800A5274, NULL, 0x10E, 0x13, 267, 266, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5280,
    &D_800A5294,
    &D_800A52A8,
    &D_800A52BC,
    &D_800A52D0,
    &D_800A52E4,
    &D_800A52F8,
    &D_800A530C,
    &D_800A5320,
    &D_800A5334,
    &D_800A5348,
    &D_800A535C,
    &D_800A5370,
    &D_800A5384,
    &D_800A5398,
    &D_800A53AC,
    &D_800A53C0,
    &D_800A53D4,
    &D_800A53E8,
    &D_800A53FC,
    &D_800A5410,
    &D_800A5424,
    &D_800A5438,
    &D_800A544C,
    &D_800A5460,
    &D_800A5474,
    &D_800A5488,
    &D_800A549C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 115, 131, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 163, 107, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 227, 75, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 280, 73, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 328, 97, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 376, 121, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 2, 0, 2, 4, 0, 117, 147, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 2, 0, 2, 4, 0, 165, 124, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 2, 0, 2, 4, 0, 229, 92, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 2, 0, 2, 4, 0, 259, 90, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 2, 0, 2, 4, 0, 307, 115, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 2, 0, 2, 4, 0, 355, 139, 0, 0 },
    { 1, 0x64, 0x40, 6, 0xF, 0, 0, 0, 0, 0, 350, 125, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 192, 271, 301, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 184, 263, 288, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 178, 254, 277, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 152, 216, 233, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 280, 256, 280, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 264, 248, 271, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 248, 240, 264, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 232, 232, 256, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 217, 222, 248, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 312, 231, 263, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 332, 222, 253, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x112, 0x220, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x279, 0x68, 0x15A, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
