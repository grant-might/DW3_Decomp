#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x39C;
    D_800990B4.sheetEntry = 0x9250000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x924;
    D_800990B4.start = (Vec2){0x26F00, 0xA800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xE;
    D_800990B4.music = 0x60380000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.spriteColor = stageColor;
    D_8009A70C.setFile(0, 0x9250001);
    D_8009A70C.setFile(7, 0x9250002);
    D_8009A70C.unk50(0);
}

extern u16 D_800A601C[];
extern u16 D_800A6028[];
extern u16 D_800A6034[];
extern u16 D_800A6040[];
extern u16 D_800A6050[];
extern u16 D_800A605C[];
extern u16 D_800A6064[];
extern u16 D_800A6070[];
extern FieldTalk D_800A6078[];
extern u16 D_800A60FC[];
extern FieldTalk D_800A6090[];
extern u16 D_800A6104[];
extern FieldTalk D_800A60A8[];
extern FieldTalk D_800A60E4[];
extern FieldActorEntry D_800A610C;
extern FieldActorEntry D_800A6120;
extern FieldActorEntry D_800A6134;
extern FieldActorEntry D_800A6148;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x174, 0x130, 0xD0, 0x30, 0x160, 0x1FE },
    { 0x140, 0x100, 0x16A, 0x14E, 0xA8, 0x4E, 0x170, 0x1FE },
};
u16 D_800A601C[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A6028[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6034[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6040[] = { 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A6050[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A605C[] = { 0, 1, 0xFFFF };
u16 D_800A6064[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A6070[] = { 0x7838, 1, 0xFFFF };
FieldTalk D_800A6078[] = {
    { NULL, NULL, 0x93 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6090[] = {
    { NULL, NULL, 0x4D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60A8[] = {
    { D_800A601C, D_800A6028, 0x4F },
    { D_800A6034, D_800A6040, 0x50 },
    { D_800A6050, D_800A605C, 0x4D },
    { D_800A6064, D_800A6070, 0x4E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60E4[] = {
    { NULL, NULL, 0x94 },
    { NULL, NULL, 0 },
};
u16 D_800A60FC[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6104[] = { 0x8192, 1, 0xFFFF };
FieldActorEntry D_800A610C = { NULL, D_800A6078, 0x25, 4, 479, 320, 1 };
FieldActorEntry D_800A6120 = { D_800A60FC, D_800A6090, 0x2E, 5, 624, 152, 7 };
FieldActorEntry D_800A6134 = { D_800A6104, D_800A60A8, 0x2E, 5, 624, 152, 7 };
FieldActorEntry D_800A6148 = { NULL, D_800A60E4, 0x16D, 6, 528, 209, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A610C,
    &D_800A6120,
    &D_800A6134,
    &D_800A6148,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x80, 2, 0, 0, 0, 0, 0, 0, 218, 322, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 6, 0, 429, 308, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 674, 320, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 1, 0x34, 0x39, 4, 0, 776, 392, 0, 0 },
    { 1, 0, 0x80, 6, 1, 0, 0, 0, 0, 0, 219, 367, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x299, 0xD0, 0x2FC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
