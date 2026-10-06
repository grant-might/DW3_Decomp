#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x4D4
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x4E4
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x12100, 0x17D00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4EEC[];
extern u16 D_800A4EF4[];
extern FieldTalk D_800A4EFC[];
extern FieldTalk D_800A4F14[];
extern u16 D_800A4F8C[];
extern FieldTalk D_800A4F2C[];
extern u16 D_800A4F98[];
extern FieldTalk D_800A4F44[];
extern u16 D_800A4FA0[];
extern FieldTalk D_800A4F5C[];
extern u16 D_800A4FA8[];
extern FieldTalk D_800A4F74[];
extern FieldActorEntry D_800A4FB4;
extern FieldActorEntry D_800A4FC8;
extern FieldActorEntry D_800A4FDC;
extern FieldActorEntry D_800A4FF0;
extern FieldActorEntry D_800A5004;
extern FieldActorEntry D_800A5018;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x158, 0x1C8, 0x60, 0xC8, 0x140, 0x1FE },
    { 0x180, 0x100, 0x180, 0x100, 0x100, 0, 0x150, 0x1FE },
    { 0x140, 0x100, 0x178, 0x1D8, 0xE0, 0xD8, 0x160, 0x1FE },
    { 0x180, 0x100, 0x18A, 0x100, 0x128, 0, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1A6, 0x100, 0x198, 0, 0x140, 0x1FD },
    { 0x180, 0x100, 0x1AE, 0x100, 0x1B8, 0, 0x150, 0x1FD },
};
u16 D_800A4EEC[] = { 0x7A13, 1, 0xFFFF };
u16 D_800A4EF4[] = { 0x7A12, 1, 0xFFFF };
FieldTalk D_800A4EFC[] = {
    { NULL, D_800A4EEC, 0x1A9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F14[] = {
    { NULL, D_800A4EF4, 0x1AA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F2C[] = {
    { NULL, NULL, 0x73 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F44[] = {
    { NULL, NULL, 0x75 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F5C[] = {
    { NULL, NULL, 0x76 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F74[] = {
    { NULL, NULL, 0x74 },
    { NULL, NULL, 0 },
};
u16 D_800A4F8C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A4F98[] = { 0x602B, 1, 0xFFFF };
u16 D_800A4FA0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A4FA8[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
FieldActorEntry D_800A4FB4 = { NULL, D_800A4EFC, 0x16, 4, 451, 178, 7 };
FieldActorEntry D_800A4FC8 = { NULL, D_800A4F14, 0x17, 5, 382, 331, 1 };
FieldActorEntry D_800A4FDC = { D_800A4F8C, D_800A4F2C, 0x2D, 6, 533, 171, 5 };
FieldActorEntry D_800A4FF0 = { D_800A4F98, D_800A4F44, 0x36, 7, 533, 171, 5 };
FieldActorEntry D_800A5004 = { D_800A4FA0, D_800A4F5C, 0x39, 8, 195, 402, 1 };
FieldActorEntry D_800A5018 = { D_800A4FA8, D_800A4F74, 0x3A, 9, 195, 402, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A4FB4,
    &D_800A4FC8,
    &D_800A4FDC,
    &D_800A4FF0,
    &D_800A5004,
    &D_800A5018,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x3D, 4, 0, 224, 268, 0, 0 },
    { 1, 0, 0x40, 6, 0x4D, 1, 0x4D, 0x50, 8, 0, 73, 439, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 1, 0x51, 0x60, 0xA, 0, 90, 278, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 1, 0x51, 0x60, 0xA, 0, 133, 435, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x48, 0xA, 0, 67, 338, 0, 0 },
    { 1, 0, 0x40, 6, 0, 0, 0, 0, 0, 0, 314, 248, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27C, 0x150, 0x98, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27C, 0x60, 0x150, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
