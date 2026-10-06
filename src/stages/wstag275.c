#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF0
#define STAGE_FILE 0x1A3
#define STAGE_ARCHIVE 0x2C9
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define STAGE_FILE 0x1B1
#define STAGE_ARCHIVE 0x2D8
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0xFD00, 0x1CD00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2C;
    D_800990B4.startDir = 0;
    D_800990B4.music = 0x60B00000;
    D_800990B4.spriteColor = stageColor;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x213, 0x13A, 0x144, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x210, 0xE8, 0x1A2, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
