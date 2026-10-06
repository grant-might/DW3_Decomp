#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x592
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x5A2
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1BA00, 0x17F00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4EDC[];
extern u16 D_800A4EE4[];
extern u16 D_800A4EEC[];
extern u16 D_800A4EF4[];
extern u16 D_800A4EFC[];
extern u16 D_800A4F04[];
extern u16 D_800A4F10[];
extern u16 D_800A4F18[];
extern u16 D_800A4F20[];
extern u16 D_800A4F28[];
extern u16 D_800A4F30[];
extern u16 D_800A4F38[];
extern u16 D_800A4F40[];
extern FieldTalk D_800A4F48[];
extern FieldTalk D_800A4F60[];
extern FieldTalk D_800A4F78[];
extern u16 D_800A4FF0[];
extern FieldTalk D_800A4F90[];
extern u16 D_800A4FF8[];
extern FieldTalk D_800A4FD8[];
extern FieldActorEntry D_800A5000;
extern FieldActorEntry D_800A5014;
extern FieldActorEntry D_800A5028;
extern FieldActorEntry D_800A503C;
extern FieldActorEntry D_800A5050;
extern FieldActorEntry D_800A5064;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x18A, 0x11A, 0x128, 0x1A, 0x140, 0x1FF },
    { 0x180, 0x100, 0x1B6, 0x117, 0x1D8, 0x17, 0x150, 0x1FF },
    { 0x180, 0x100, 0x180, 0x11A, 0x100, 0x1A, 0x160, 0x1FF },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x170, 0x1FF },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A4EDC[] = { 0x7A2A, 1, 0xFFFF };
u16 D_800A4EE4[] = { 0x7A15, 1, 0xFFFF };
u16 D_800A4EEC[] = { 0x7A14, 1, 0xFFFF };
u16 D_800A4EF4[] = { 0x7020, 1, 0xFFFF };
u16 D_800A4EFC[] = { 0x7A46, 1, 0xFFFF };
u16 D_800A4F04[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A4F10[] = { 0x7A46, 1, 0xFFFF };
u16 D_800A4F18[] = { 0x6026, 1, 0xFFFF };
u16 D_800A4F20[] = { 0x7A47, 1, 0xFFFF };
u16 D_800A4F28[] = { 0x701A, 1, 0xFFFF };
u16 D_800A4F30[] = { 0x7A47, 1, 0xFFFF };
u16 D_800A4F38[] = { 0x602B, 1, 0xFFFF };
u16 D_800A4F40[] = { 0x7A47, 1, 0xFFFF };
FieldTalk D_800A4F48[] = {
    { NULL, D_800A4EDC, 0x1A3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F60[] = {
    { NULL, D_800A4EE4, 0x1A8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F78[] = {
    { NULL, D_800A4EEC, 0x1A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F90[] = {
    { D_800A4EF4, D_800A4EFC, 0x1A7 },
    { D_800A4F04, D_800A4F10, 0x1A7 },
    { D_800A4F18, D_800A4F20, 0x1A7 },
    { D_800A4F28, D_800A4F30, 0x1A7 },
    { D_800A4F38, D_800A4F40, 0x1A7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FD8[] = {
    { NULL, NULL, 0x20D },
    { NULL, NULL, 0 },
};
u16 D_800A4FF0[] = { 0x8192, 1, 0xFFFF };
u16 D_800A4FF8[] = { 0x8192, 0, 0xFFFF };
FieldActorEntry D_800A5000 = { NULL, D_800A4F48, 0x14, 4, 345, 197, 7 };
FieldActorEntry D_800A5014 = { NULL, D_800A4F60, 0x16, 5, 408, 341, 7 };
FieldActorEntry D_800A5028 = { NULL, D_800A4F78, 0x17, 6, 330, 380, 7 };
FieldActorEntry D_800A503C = { D_800A4FF0, D_800A4F90, 0xCE, 7, 128, 201, 7 };
FieldActorEntry D_800A5050 = { D_800A4FF8, D_800A4FD8, 0xCE, 7, 128, 201, 7 };
FieldActorEntry D_800A5064 = { NULL, NULL, 0xDB, 8, 345, 213, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5000,
    &D_800A5014,
    &D_800A5028,
    &D_800A503C,
    &D_800A5050,
    &D_800A5064,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x64, 4, 0x14, 0, 0, 0, 0, 0, 448, 251, 310, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 304, 189, 222, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 290, 166, 222, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 328, 195, 215, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 336, 187, 207, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 352, 180, 199, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 367, 164, 199, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 472, 281, 331, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 496, 352, 399, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 271, 382, 399, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 289, 374, 391, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 336, 350, 367, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 353, 343, 358, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 366, 323, 351, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 416, 309, 326, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 435, 292, 319, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 176, 155, 211, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 160, 148, 199, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 144, 140, 191, 0 },
    { 1, 0, 0x40, 4, 0x12, 0, 0, 0, 0, 0, 128, 132, 184, 0 },
    { 1, 0, 0x40, 4, 0x13, 0, 0, 0, 0, 0, 118, 127, 179, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29C, 0x1E8, 0x1AC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x100, 0xB0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x10F, 0xF6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0xB0, 0xD8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xBF, 0x11E, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
