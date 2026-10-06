#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x1B0;
    D_800990B4.sheetEntry = 0x8FF0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x8FE;
    D_800990B4.start = (Vec2){0xFD00, 0x1CD00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2C;
    D_800990B4.music = 0x60B00000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.spriteColor = stageColor;
    D_8009A70C.setFile(0, 0x8FF0001);
    D_8009A70C.setFile(7, 0x8FF0002);
    D_8009A70C.unk50(0);
}

extern u16 D_800A5FFC[];
extern u16 D_800A6004[];
extern u16 D_800A6010[];
extern u16 D_800A6018[];
extern u16 D_800A6028[];
extern u16 D_800A6030[];
extern u16 D_800A6044[];
extern u16 D_800A604C[];
extern u16 D_800A6064[];
extern u16 D_800A606C[];
extern u16 D_800A6088[];
extern u16 D_800A6090[];
extern u16 D_800A60AC[];
extern FieldTalk D_800A60BC[];
extern FieldActorEntry D_800A611C;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A5FFC[] = { 0x1806, 1, 0xFFFF };
u16 D_800A6004[] = { 0x1806, 0, 0, 0, 0xFFFF };
u16 D_800A6010[] = { 0, 1, 0xFFFF };
u16 D_800A6018[] = { 0x1806, 0, 0, 1, 1, 0, 0xFFFF };
u16 D_800A6028[] = { 1, 1, 0xFFFF };
u16 D_800A6030[] = { 0x1806, 0, 0, 1, 1, 1, 2, 0, 0xFFFF };
u16 D_800A6044[] = { 2, 1, 0xFFFF };
u16 D_800A604C[] = {
    0x1806, 0, 0, 1, 1, 1, 2, 1,
    3, 0, 0xFFFF,
};
u16 D_800A6064[] = { 3, 1, 0xFFFF };
u16 D_800A606C[] = {
    0x1806, 0, 0, 1, 1, 1, 2, 1,
    4, 0, 3, 1, 0xFFFF,
};
u16 D_800A6088[] = { 4, 1, 0xFFFF };
u16 D_800A6090[] = {
    0x1806, 0, 0, 1, 1, 1, 2, 1,
    3, 1, 4, 1, 0xFFFF,
};
u16 D_800A60AC[] = { 0x1806, 1, 0x8025, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A60BC[] = {
    { D_800A5FFC, NULL, 0x58 },
    { D_800A6004, D_800A6010, 0x55 },
    { D_800A6018, D_800A6028, 0x56 },
    { D_800A6030, D_800A6044, 0x56 },
    { D_800A604C, D_800A6064, 0x56 },
    { D_800A606C, D_800A6088, 0x56 },
    { D_800A6090, D_800A60AC, 0x57 },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A611C = { NULL, D_800A60BC, 0x3F, 4, 175, 408, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A611C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x9F, 2, 0x37, 1, 0x37, 0x39, 6, 0, 450, 296, 0, 0 },
    { 1, 0, 0xBE, 2, 0x3A, 1, 0x3A, 0x3C, 6, 0, 560, 270, 0, 0 },
    { 1, 0, 0x8F, 2, 0x1D, 1, 0x1D, 0x31, 8, 0, 584, 352, 0, 0 },
    { 1, 0, 0xB6, 2, 6, 1, 6, 0x1C, 8, 0, 471, 277, 0, 0 },
    { 1, 0, 0xB6, 2, 6, 1, 6, 0x1C, 8, 0, 535, 294, 0, 0 },
    { 1, 0, 0x70, 2, 4, 0, 0, 0, 0, 0, 374, 310, 0, 0 },
    { 1, 0, 0xD0, 2, 5, 0, 0, 0, 0, 0, 438, 232, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 609, 253, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 4, 0, 633, 246, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 4, 0, 640, 242, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 1, 4, 0, 652, 281, 0, 0 },
    { 1, 0, 0x9F, 6, 0x37, 1, 0x37, 0x39, 6, 0, 366, 170, 0, 0 },
    { 1, 0, 0x67, 6, 0x3D, 1, 0x3D, 0x52, 8, 0, 507, 185, 0, 0 },
    { 1, 0, 0xB6, 6, 6, 1, 6, 0x1C, 8, 0, 421, 106, 0, 0 },
    { 1, 0x64, 0x40, 6, 2, 0, 0, 0, 0, 0, 91, 362, 0, 0 },
    { 1, 0x65, 0x40, 6, 3, 0, 0, 0, 0, 0, 770, 115, 0, 0 },
    { 1, 0, 0x90, 4, 0, 0, 0, 0, 0, 0, 0, 256, 410, 0 },
    { 1, 0, 0xB0, 4, 1, 0, 0, 0, 0, 0, 768, 0, 165, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x282, 0x13A, 0x144, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27F, 0xE8, 0x1A2, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
