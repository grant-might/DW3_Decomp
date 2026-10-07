#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    FIELDSTG_state.textFile = LANGUAGE + 0x104;
    FIELDSTG_state.mapFile = 0x1BC;
    FIELDSTG_state.sheetEntry = 0x9170000;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = 0x916;
    FIELDSTG_state.start = (Vec2){0x19B00, 0x23500};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x32;
    FIELDSTG_state.music = MUSIC(0x32, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, 0x9170002);
    FIELDSTG_map.setFile(7, 0x9170003);
    FIELDSTG_map.setFile(4, 0x9170001);
    FIELDSTG_map.setFirstMap(0);
}

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x160, 0x100, 0x80, 0, 0x140, 0x1FF },
};
u16 actor1Talk0Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 0, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0), 0, CODES_END };
u16 actor1Talk1Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 1, CODES_END };
u16 actor1Talk1Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0x10), 0, FLAG(0, 0), 0, CODES_END };
u16 actor1Talk2Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 0), 0, CODES_END };
u16 actor1Talk2Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor1Talk3Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 0), 1, CODES_END };
u16 actor1Talk3Actions[] = { CARD_BATTLE(0x51, 1), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, NULL, 0x35 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x37 },
    { actor1Talk1Conditions, actor1Talk1Actions, 0x38 },
    { actor1Talk2Conditions, actor1Talk2Actions, 0x35 },
    { actor1Talk3Conditions, actor1Talk3Actions, 0x36 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { ITEM(0, 0x192), 0, CODES_END };
u16 actor1Conditions[] = { ITEM(0, 0x192), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x33, 4, 320, 736, 3 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x33, 4, 320, 736, 3 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 1024, 448, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 1088, 448, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 896, 576, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 960, 576, 0, 0 },
    { 1, 0, 0x40, 2, 4, 0, 0, 0, 0, 0, 1024, 576, 0, 0 },
    { 1, 0, 0x40, 2, 5, 0, 0, 0, 0, 0, 1088, 576, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 1024, 640, 0, 0 },
    { 1, 0, 0x40, 2, 7, 0, 0, 0, 0, 0, 1088, 640, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x295, 0x5E, 0x40E, 5, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x291, 0x374, 0x9B, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle area0Battle0 = { 44, 3, MUSIC(2, 0) };
Battle area0Battle1 = { 44, 3, MUSIC(2, 0) };
Battle area0Battle2 = { 44, 3, MUSIC(2, 0) };
Battle area0Battle3 = { 44, 3, MUSIC(2, 0) };
Battle area0Battle4 = { 47, 3, MUSIC(2, 0) };
Battle area0Battle5 = { 47, 3, MUSIC(2, 0) };
Battle area0Battle6 = { 47, 3, MUSIC(2, 0) };
Battle area0Battle7 = { 47, 3, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 148, 8, MUSIC(2, 0) };
Battle area1Battle1 = { 148, 8, MUSIC(2, 0) };
Battle area1Battle2 = { 148, 8, MUSIC(2, 0) };
Battle area1Battle3 = { 148, 8, MUSIC(2, 0) };
Battle area1Battle4 = { 149, 8, MUSIC(2, 0) };
Battle area1Battle5 = { 149, 8, MUSIC(2, 0) };
Battle area1Battle6 = { 149, 8, MUSIC(2, 0) };
Battle area1Battle7 = { 149, 8, MUSIC(2, 0) };
BattleList area1Battles = {
    2,
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
    { 386, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
