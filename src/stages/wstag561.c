#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x7C1A, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x5C6
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x5D6
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x26F00, 0x1DF00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x41;
    FIELDSTG_state.music = MUSIC(0x41, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1463[] = {
    0x102, 2, 0x117, 0x133, 3,
    0x100, 0x15, 0xF7, 0x123,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x24,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC18, 0, 0, 0,
    0,
};
Battle area0Battle0 = { 134, 3, MUSIC(2, 0) };
Battle area0Battle1 = { 134, 3, MUSIC(2, 0) };
Battle area0Battle2 = { 134, 3, MUSIC(2, 0) };
Battle area0Battle3 = { 134, 3, MUSIC(2, 0) };
Battle area0Battle4 = { 172, 3, MUSIC(2, 0) };
Battle area0Battle5 = { 172, 3, MUSIC(2, 0) };
Battle area0Battle6 = { 172, 3, MUSIC(2, 0) };
Battle area0Battle7 = { 172, 3, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 134, 8, MUSIC(2, 0) };
Battle area1Battle1 = { 134, 8, MUSIC(2, 0) };
Battle area1Battle2 = { 134, 8, MUSIC(2, 0) };
Battle area1Battle3 = { 134, 8, MUSIC(2, 0) };
Battle area1Battle4 = { 172, 8, MUSIC(2, 0) };
Battle area1Battle5 = { 172, 8, MUSIC(2, 0) };
Battle area1Battle6 = { 172, 8, MUSIC(2, 0) };
Battle area1Battle7 = { 172, 8, MUSIC(2, 0) };
BattleList area1Battles = {
    3,
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
Battle area3Battle4 = { 334, 8, MUSIC(2, 0) };
Battle area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle7 = { 180, 8, MUSIC(2, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 98, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x175, 0xD8, 0x75, 0x160, 0x1FF },
    { 0x180, 0x100, 0x1A0, 0x1BA, 0x180, 0xBA, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x195, 0xD8, 0x95, 0x150, 0x1FE },
};
u16 actor0Talk0Actions[] = { 0x7A45, 1, CODES_END };
u16 actor1Talk0Actions[] = { START_EVENT(0x69), 1, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(2, 0x54), 1, ITEM(1, 0x36), 1, SPECIAL(0x13), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x2D7 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, actor1Talk0Actions, 0x2CF },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, actor2Talk0Actions, 0x187 },
    { NULL, NULL, 0 },
};
u16 actor2Conditions[] = { FLAG(2, 0x54), 0, CODES_END };
FieldActorEntry actor0 = { NULL, actor0Talks, 0x14, 4, 450, 368, 1 };
FieldActorEntry actor1 = { NULL, actor1Talks, 0x15, 5, 247, 291, 7 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x21, 6, 502, 546, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 407, 226, 0, 0 },
    { 1, 0, 0x64, 2, 1, 0, 0, 0, 0, 0, 551, 516, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 211, 335, 0, 0 },
    { 1, 0, 0x80, 2, 2, 0, 0, 0, 0, 0, 0, 384, 0, 0 },
    { 1, 0, 0x80, 2, 3, 0, 0, 0, 0, 0, 384, 384, 0, 0 },
    { 1, 0, 0x70, 2, 4, 0, 0, 0, 0, 0, 20, 512, 0, 0 },
    { 1, 0, 0x78, 2, 5, 0, 0, 0, 0, 0, 264, 523, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 1, 0x47, 0x49, 6, 0, 204, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x4D, 6, 0, 213, 360, 0, 0 },
    { 1, 0, 0x68, 6, 0x4E, 2, 0, 2, 6, 0, 181, 376, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 153, 444, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 277, 512, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 322, 397, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 584, 137, 169, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2B2, 0x610, 0x240, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2B4, 0x80, 0x178, 7, 0, 0, 0 },
    { { { SPECIAL(0x93), 1 }, { CODES_END, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0xF, 1 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0xFFC8, 0x3C, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0xFFD0, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0x40, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { SPECIAL(0x93), 1 }, { CODES_END, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0xF, 1 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1463, script1463, EVENT_TEXT(0x27), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
