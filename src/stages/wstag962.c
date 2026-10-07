#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
void setupStage(void) {
    FIELDSTG_state.textFile = LANGUAGE + 0x104;
    FIELDSTG_state.mapFile = 0x6E4;
    FIELDSTG_state.sheetEntry = 0x9330004;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = 0x932;
    FIELDSTG_state.start = (Vec2){0xC700, 0x16D00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x1D;
    FIELDSTG_state.music = MUSIC(0x1D, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.battles = FIELDSTG_state.findBattles(stageBattles, GAME.place);
    FIELDSTG_map.setFile(0, 0x9330006);
    FIELDSTG_map.setFile(7, 0x9330007);
    FIELDSTG_map.setFile(4, 0x9330005);
    FIELDSTG_map.setFirstMap(0);
}

StagePoint placePoints2_1Point1 = { 0x2E4, 2, 4, 192, 0x180, 5, NULL };
StagePoint placePoints2_1Point0 = { 0x28C, 0, 0, 0x328, 0x424, 0, &placePoints2_1Point1 };
StagePoints placePoints2_1 = { 2, 1, &placePoints2_1Point0 };
StagePoints *placePoints[] = {
    &placePoints2_1, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x152, 0x198, 0x48, 0x98, 0x160, 0x1FF },
};
FieldActorEntry actor0 = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &actor0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 254, 275, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 621, 244, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 852, 128, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 384, 171, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 689, 166, 0, 0 },
    { 1, 0, 0xFF, 2, 0x33, 2, 0, 7, 0x18, 0, 140, -36, 0, 0 },
    { 1, 0, 0x98, 2, 5, 0, 0, 0, 0, 0, 432, 254, 0, 0 },
    { 1, 0, 0x8A, 2, 6, 0, 0, 0, 0, 0, 408, 268, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 475, 113, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 169, 206, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 750, 142, 0, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 140, 92, 336, 0 },
    { 1, 0, 0x92, 4, 1, 0, 0, 0, 0, 0, 560, 179, 319, 0 },
    { 1, 0, 0x79, 4, 2, 0, 0, 0, 0, 0, 528, 198, 335, 0 },
    { 1, 0, 0x88, 4, 3, 0, 0, 0, 0, 0, 496, 216, 351, 0 },
    { 1, 0, 0x86, 4, 4, 0, 0, 0, 0, 0, 464, 232, 368, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2E2, 0xB0, 0x148, 4, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2E2, 0x330, 0xF8, 5, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle area0Battle0 = { 61, 11, MUSIC(2, 0) };
Battle area0Battle1 = { 61, 11, MUSIC(2, 0) };
Battle area0Battle2 = { 61, 11, MUSIC(2, 0) };
Battle area0Battle3 = { 61, 11, MUSIC(2, 0) };
Battle area0Battle4 = { 61, 11, MUSIC(2, 0) };
Battle area0Battle5 = { 61, 11, MUSIC(2, 0) };
Battle area0Battle6 = { 61, 11, MUSIC(2, 0) };
Battle area0Battle7 = { 61, 11, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area1Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area1Battles = {
    0,
    { &area1Battle0, &area1Battle1, &area1Battle2, &area1Battle3,
      &area1Battle4, &area1Battle5, &area1Battle6, &area1Battle7 },
};
Battle area2Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area2Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area2Battles = {
    0,
    { &area2Battle0, &area2Battle1, &area2Battle2, &area2Battle3,
      &area2Battle4, &area2Battle5, &area2Battle6, &area2Battle7 },
};
Battle area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 398, 2, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
