#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    FIELDSTG_state.textFile = LANGUAGE + 0xFD;
    FIELDSTG_state.mapFile = 0x2B7;
    FIELDSTG_state.sheetEntry = 0x8F10000;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = 0x8F0;
    FIELDSTG_state.start = (Vec2){0x5900, 0x12C00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.soundBank = 4;
    FIELDSTG_state.music = MUSIC(4, 0);
    FIELDSTG_map.setFile(0, 0x8F10001);
    FIELDSTG_map.setFile(7, 0x8F10002);
    FIELDSTG_map.setFirstMap(0);
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
    { 1, 0, 0x40, 2, 0x32, 2, 0, 1, 6, 0, 261, 137, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 53, 223, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 173, 179, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 325, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 435, 83, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 523, 127, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 555, 239, 0, 0 },
    { 1, 0x64, 0x40, 6, 1, 0, 0, 0, 0, 0, 286, 127, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 224, 144, 184, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x271, 0xF0, 0x108, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x28A, 0x138, 0x64, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x279, 0xA7, 0x153, 3, 0x64, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 6, 0x203, 0xC2, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 6, 0x212, 0x128, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
