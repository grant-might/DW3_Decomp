#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x59E
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x5AE
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x24400, 0xB800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xE;
    D_800990B4.music = 0x60380000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.spriteColor = stageColor;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern u16 D_800A4FC0[];
extern FieldTalk D_800A4F30[];
extern u16 D_800A4FCC[];
extern FieldTalk D_800A4F48[];
extern u16 D_800A4FD8[];
extern FieldTalk D_800A4F60[];
extern u16 D_800A4FE4[];
extern FieldTalk D_800A4F78[];
extern u16 D_800A4FEC[];
extern FieldTalk D_800A4F90[];
extern u16 D_800A4FF8[];
extern FieldTalk D_800A4FA8[];
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
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x174, 0x128, 0xD0, 0x28, 0x160, 0x1FE },
    { 0x140, 0x100, 0x15C, 0x14F, 0x70, 0x4F, 0x170, 0x1FE },
    { 0x140, 0x100, 0x164, 0x14F, 0x90, 0x4F, 0x160, 0x1FD },
};
FieldTalk D_800A4F30[] = {
    { NULL, NULL, 0x52 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F48[] = {
    { NULL, NULL, 0x4F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F60[] = {
    { NULL, NULL, 0x4E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F78[] = {
    { NULL, NULL, 0x50 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F90[] = {
    { NULL, NULL, 0x51 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FA8[] = {
    { NULL, NULL, 0x53 },
    { NULL, NULL, 0 },
};
u16 D_800A4FC0[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A4FCC[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A4FD8[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A4FE4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A4FEC[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A4FF8[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5000 = { D_800A4FC0, D_800A4F30, 0x34, 4, 528, 209, 7 };
FieldActorEntry D_800A5014 = { D_800A4FCC, D_800A4F48, 0x37, 5, 592, 168, 1 };
FieldActorEntry D_800A5028 = { D_800A4FD8, D_800A4F60, 0x9D, 6, 592, 168, 1 };
FieldActorEntry D_800A503C = { D_800A4FE4, D_800A4F78, 0x9D, 6, 592, 168, 1 };
FieldActorEntry D_800A5050 = { D_800A4FEC, D_800A4F90, 0x9E, 7, 528, 209, 7 };
FieldActorEntry D_800A5064 = { D_800A4FF8, D_800A4FA8, 0x9E, 7, 528, 209, 7 };
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
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 6, 0, 429, 308, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 1, 0x34, 0x39, 4, 0, 776, 392, 0, 0 },
    { 1, 0, 0x68, 6, 0, 0, 0, 0, 0, 0, 218, 321, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x299, 0xD0, 0x2FC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
