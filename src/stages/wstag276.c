#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x51F
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x52F
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x10100, 0x1C800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2C;
    D_800990B4.music = 0x60B00000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.spriteColor = stageColor;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F14[];
extern FieldTalk D_800A4ECC[];
extern u16 D_800A4F20[];
extern FieldTalk D_800A4EE4[];
extern u16 D_800A4F2C[];
extern FieldTalk D_800A4EFC[];
extern FieldActorEntry D_800A4F34;
extern FieldActorEntry D_800A4F48;
extern FieldActorEntry D_800A4F5C;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x198, 0x128, 0x160, 0x28, 0x160, 0x1FD },
    { 0x180, 0x100, 0x1A0, 0x128, 0x180, 0x28, 0x170, 0x1FD },
};
FieldTalk D_800A4ECC[] = {
    { NULL, NULL, 0x8C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4EE4[] = {
    { NULL, NULL, 0x8B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4EFC[] = {
    { NULL, NULL, 0x8D },
    { NULL, NULL, 0 },
};
u16 D_800A4F14[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A4F20[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A4F2C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A4F34 = { D_800A4F14, D_800A4ECC, 0x33, 4, 256, 443, 7 };
FieldActorEntry D_800A4F48 = { D_800A4F20, D_800A4EE4, 0x9D, 5, 256, 443, 7 };
FieldActorEntry D_800A4F5C = { D_800A4F2C, D_800A4EFC, 0x9D, 5, 256, 443, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A4F34,
    &D_800A4F48,
    &D_800A4F5C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x9F, 2, 0x37, 1, 0x37, 0x39, 6, 0, 450, 296, 0, 0 },
    { 1, 0, 0xBE, 2, 0x3A, 1, 0x3A, 0x3C, 6, 0, 560, 270, 0, 0 },
    { 1, 0, 0x8F, 2, 0x1D, 1, 0x1D, 0x31, 8, 0, 584, 352, 0, 0 },
    { 1, 0, 0xB6, 2, 6, 1, 6, 0x1C, 8, 0, 471, 277, 0, 0 },
    { 1, 0, 0xB6, 2, 6, 1, 6, 0x1C, 8, 0, 535, 294, 0, 0 },
    { 1, 0, 0x40, 2, 0x53, 0, 0, 0, 0, 0, 90, 366, 0, 0 },
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
    { 1, 0, 0x40, 6, 0, 0, 0, 0, 0, 0, 403, 378, 0, 0 },
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
