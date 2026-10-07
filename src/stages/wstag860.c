#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places_last.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x6E5
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x6F5
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0xEC00, 0x14D00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x1D;
    FIELDSTG_state.music = MUSIC(0x1D, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.battles = FIELDSTG_state.findBattles(stageBattles, GAME.place);
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

StagePoint D_800A4FAC = { 0x2E5, 1, 2, 224, 0x120, 5, NULL };
StagePoints placePoints1_1 = { 1, 1, &D_800A4FAC };
StagePoint placePoints6_1Point0 = { 0x2E4, 6, 1, 192, 0x180, 5, NULL };
StagePoints placePoints6_1 = { 6, 1, &placePoints6_1Point0 };
StagePoint placePoints11_1Point0 = { 0x2E5, 11, 2, 224, 0x120, 5, NULL };
StagePoints placePoints11_1 = { 11, 1, &placePoints11_1Point0 };
StagePoint placePoints16_1Point0 = { 0x2E4, 16, 1, 192, 0x180, 5, NULL };
StagePoints placePoints16_1 = { 16, 1, &placePoints16_1Point0 };
StagePoints placePoints0_0 = { 0, 0, &D_800A4FAC };
StagePoints *placePoints[] = {
    &placePoints1_1, &placePoints6_1, &placePoints11_1, &placePoints16_1,
    &placePoints0_0, NULL,
};
Battle place1Area0Battle0 = { 61, 11, MUSIC(2, 0) };
Battle place1Area0Battle1 = { 61, 11, MUSIC(2, 0) };
Battle place1Area0Battle2 = { 61, 11, MUSIC(2, 0) };
Battle place1Area0Battle3 = { 61, 11, MUSIC(2, 0) };
Battle place1Area0Battle4 = { 62, 11, MUSIC(2, 0) };
Battle place1Area0Battle5 = { 62, 11, MUSIC(2, 0) };
Battle place1Area0Battle6 = { 62, 11, MUSIC(2, 0) };
Battle place1Area0Battle7 = { 62, 11, MUSIC(2, 0) };
BattleList place1Area0Battles = {
    2,
    { &place1Area0Battle0, &place1Area0Battle1, &place1Area0Battle2, &place1Area0Battle3,
      &place1Area0Battle4, &place1Area0Battle5, &place1Area0Battle6, &place1Area0Battle7 },
};
Battle place1Area1Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place1Area1Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place1Area1Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place1Area1Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place1Area1Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place1Area1Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place1Area1Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place1Area1Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place1Area1Battles = {
    0,
    { &place1Area1Battle0, &place1Area1Battle1, &place1Area1Battle2, &place1Area1Battle3,
      &place1Area1Battle4, &place1Area1Battle5, &place1Area1Battle6, &place1Area1Battle7 },
};
Battle place1Area2Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place1Area2Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place1Area2Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place1Area2Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place1Area2Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place1Area2Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place1Area2Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place1Area2Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place1Area2Battles = {
    0,
    { &place1Area2Battle0, &place1Area2Battle1, &place1Area2Battle2, &place1Area2Battle3,
      &place1Area2Battle4, &place1Area2Battle5, &place1Area2Battle6, &place1Area2Battle7 },
};
Battle place1Area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place1Area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place1Area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place1Area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place1Area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place1Area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place1Area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place1Area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place1Area3Battles = {
    0,
    { &place1Area3Battle0, &place1Area3Battle1, &place1Area3Battle2, &place1Area3Battle3,
      &place1Area3Battle4, &place1Area3Battle5, &place1Area3Battle6, &place1Area3Battle7 },
};
Battle place6Area0Battle0 = { 63, 11, MUSIC(2, 0) };
Battle place6Area0Battle1 = { 63, 11, MUSIC(2, 0) };
Battle place6Area0Battle2 = { 63, 11, MUSIC(2, 0) };
Battle place6Area0Battle3 = { 63, 11, MUSIC(2, 0) };
Battle place6Area0Battle4 = { 63, 11, MUSIC(2, 0) };
Battle place6Area0Battle5 = { 63, 11, MUSIC(2, 0) };
Battle place6Area0Battle6 = { 63, 11, MUSIC(2, 0) };
Battle place6Area0Battle7 = { 63, 11, MUSIC(2, 0) };
BattleList place6Area0Battles = {
    5,
    { &place6Area0Battle0, &place6Area0Battle1, &place6Area0Battle2, &place6Area0Battle3,
      &place6Area0Battle4, &place6Area0Battle5, &place6Area0Battle6, &place6Area0Battle7 },
};
Battle place6Area1Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place6Area1Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place6Area1Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place6Area1Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place6Area1Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place6Area1Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place6Area1Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place6Area1Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place6Area1Battles = {
    0,
    { &place6Area1Battle0, &place6Area1Battle1, &place6Area1Battle2, &place6Area1Battle3,
      &place6Area1Battle4, &place6Area1Battle5, &place6Area1Battle6, &place6Area1Battle7 },
};
Battle place6Area2Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place6Area2Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place6Area2Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place6Area2Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place6Area2Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place6Area2Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place6Area2Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place6Area2Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place6Area2Battles = {
    0,
    { &place6Area2Battle0, &place6Area2Battle1, &place6Area2Battle2, &place6Area2Battle3,
      &place6Area2Battle4, &place6Area2Battle5, &place6Area2Battle6, &place6Area2Battle7 },
};
Battle place6Area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place6Area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place6Area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place6Area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place6Area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place6Area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place6Area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place6Area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place6Area3Battles = {
    0,
    { &place6Area3Battle0, &place6Area3Battle1, &place6Area3Battle2, &place6Area3Battle3,
      &place6Area3Battle4, &place6Area3Battle5, &place6Area3Battle6, &place6Area3Battle7 },
};
Battle place11Area0Battle0 = { 103, 11, MUSIC(2, 0) };
Battle place11Area0Battle1 = { 103, 11, MUSIC(2, 0) };
Battle place11Area0Battle2 = { 103, 11, MUSIC(2, 0) };
Battle place11Area0Battle3 = { 103, 11, MUSIC(2, 0) };
Battle place11Area0Battle4 = { 103, 11, MUSIC(2, 0) };
Battle place11Area0Battle5 = { 103, 11, MUSIC(2, 0) };
Battle place11Area0Battle6 = { 103, 11, MUSIC(2, 0) };
Battle place11Area0Battle7 = { 103, 11, MUSIC(2, 0) };
BattleList place11Area0Battles = {
    2,
    { &place11Area0Battle0, &place11Area0Battle1, &place11Area0Battle2, &place11Area0Battle3,
      &place11Area0Battle4, &place11Area0Battle5, &place11Area0Battle6, &place11Area0Battle7 },
};
Battle place11Area1Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place11Area1Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place11Area1Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place11Area1Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place11Area1Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place11Area1Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place11Area1Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place11Area1Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place11Area1Battles = {
    0,
    { &place11Area1Battle0, &place11Area1Battle1, &place11Area1Battle2, &place11Area1Battle3,
      &place11Area1Battle4, &place11Area1Battle5, &place11Area1Battle6, &place11Area1Battle7 },
};
Battle place11Area2Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place11Area2Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place11Area2Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place11Area2Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place11Area2Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place11Area2Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place11Area2Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place11Area2Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place11Area2Battles = {
    0,
    { &place11Area2Battle0, &place11Area2Battle1, &place11Area2Battle2, &place11Area2Battle3,
      &place11Area2Battle4, &place11Area2Battle5, &place11Area2Battle6, &place11Area2Battle7 },
};
Battle place11Area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place11Area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place11Area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place11Area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place11Area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place11Area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place11Area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place11Area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place11Area3Battles = {
    0,
    { &place11Area3Battle0, &place11Area3Battle1, &place11Area3Battle2, &place11Area3Battle3,
      &place11Area3Battle4, &place11Area3Battle5, &place11Area3Battle6, &place11Area3Battle7 },
};
Battle place16Area0Battle0 = { 178, 11, MUSIC(2, 0) };
Battle place16Area0Battle1 = { 178, 11, MUSIC(2, 0) };
Battle place16Area0Battle2 = { 178, 11, MUSIC(2, 0) };
Battle place16Area0Battle3 = { 178, 11, MUSIC(2, 0) };
Battle place16Area0Battle4 = { 178, 11, MUSIC(2, 0) };
Battle place16Area0Battle5 = { 178, 11, MUSIC(2, 0) };
Battle place16Area0Battle6 = { 178, 11, MUSIC(2, 0) };
Battle place16Area0Battle7 = { 178, 11, MUSIC(2, 0) };
BattleList place16Area0Battles = {
    5,
    { &place16Area0Battle0, &place16Area0Battle1, &place16Area0Battle2, &place16Area0Battle3,
      &place16Area0Battle4, &place16Area0Battle5, &place16Area0Battle6, &place16Area0Battle7 },
};
Battle place16Area1Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place16Area1Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place16Area1Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place16Area1Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place16Area1Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place16Area1Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place16Area1Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place16Area1Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place16Area1Battles = {
    0,
    { &place16Area1Battle0, &place16Area1Battle1, &place16Area1Battle2, &place16Area1Battle3,
      &place16Area1Battle4, &place16Area1Battle5, &place16Area1Battle6, &place16Area1Battle7 },
};
Battle place16Area2Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place16Area2Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place16Area2Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place16Area2Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place16Area2Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place16Area2Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place16Area2Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place16Area2Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place16Area2Battles = {
    0,
    { &place16Area2Battle0, &place16Area2Battle1, &place16Area2Battle2, &place16Area2Battle3,
      &place16Area2Battle4, &place16Area2Battle5, &place16Area2Battle6, &place16Area2Battle7 },
};
Battle place16Area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle place16Area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle place16Area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle place16Area3Battle3 = { 0, 0, MUSIC(1, 0) };
Battle place16Area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle place16Area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle place16Area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle place16Area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList place16Area3Battles = {
    0,
    { &place16Area3Battle0, &place16Area3Battle1, &place16Area3Battle2, &place16Area3Battle3,
      &place16Area3Battle4, &place16Area3Battle5, &place16Area3Battle6, &place16Area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 177, 1, 0, { &place1Area0Battles, &place1Area1Battles, &place1Area2Battles, &place1Area3Battles } },
    { 193, 6, 0, { &place6Area0Battles, &place6Area1Battles, &place6Area2Battles, &place6Area3Battles } },
    { 205, 11, 0, { &place11Area0Battles, &place11Area1Battles, &place11Area2Battles, &place11Area3Battles } },
    { 221, 16, 0, { &place16Area0Battles, &place16Area1Battles, &place16Area2Battles, &place16Area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x15F, 0xB8, 0x5F, 0x150, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x17F, 0xB8, 0x7F, 0x160, 0x1FF },
    { 0x140, 0x100, 0x160, 0x160, 0x80, 0x60, 0x170, 0x1FF },
};
u16 actor0Talk0Actions[] = { FLAG(2, 0x2C), 1, ITEM(1, 0x36), 1, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(2, 0x55), 1, ITEM(1, 0x40), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x34E },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, actor1Talk0Actions, 0x34F },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { WARP_ARG(5), 1, WARP_ARG(0x1E), 1, FLAG(2, 0x2C), 0, CODES_END };
u16 actor1Conditions[] = { WARP_ARG(0xF), 1, WARP_ARG(0x1E), 1, FLAG(2, 0x55), 0, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x21, 4, 192, 280, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x4D, 5, 192, 280, 1 };
FieldActorEntry actor2 = { NULL, NULL, 0x147, 6, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 360, 185, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 589, 120, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 268, 192, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 512, 122, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 110, 120, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 412, 114, 0, 0 },
    { 1, 0, 0x4A, 4, 0, 0, 0, 0, 0, 0, 416, 215, 288, 0 },
    { 1, 0, 0x61, 4, 1, 0, 0, 0, 0, 0, 384, 198, 288, 0 },
    { 1, 0, 0x5F, 4, 2, 0, 0, 0, 0, 0, 365, 191, 281, 0 },
    { 1, 0, 0x4F, 4, 3, 0, 0, 0, 0, 0, 592, 173, 251, 0 },
    { 1, 0, 0x63, 4, 4, 0, 0, 0, 0, 0, 560, 157, 247, 0 },
    { 1, 0, 0x60, 4, 5, 0, 0, 0, 0, 0, 541, 150, 240, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2E7, 0x250, 0xE8, 5, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
