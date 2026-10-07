#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D4C(void) {
    FLAGS_00.applyAction(0x7C16, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x2A1
#define STAGE_ARCHIVE 0x315
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x2B0
#define STAGE_ARCHIVE 0x324
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_ARCHIVE;
    FIELDSTG_state.start = (Vec2){0x25900, 0x1AB00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x41;
    FIELDSTG_state.music = MUSIC(0x41, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1459[] = {
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
    0x304, 0xC14, 0, 0, 0,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x37\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x6004\n");
#endif
Battle area0Battle0 = { 148, 3, MUSIC(2, 0) };
Battle area0Battle1 = { 148, 3, MUSIC(2, 0) };
Battle area0Battle2 = { 148, 3, MUSIC(2, 0) };
Battle area0Battle3 = { 148, 3, MUSIC(2, 0) };
Battle area0Battle4 = { 154, 3, MUSIC(2, 0) };
Battle area0Battle5 = { 154, 3, MUSIC(2, 0) };
Battle area0Battle6 = { 154, 3, MUSIC(2, 0) };
Battle area0Battle7 = { 154, 3, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 148, 8, MUSIC(2, 0) };
Battle area1Battle1 = { 148, 8, MUSIC(2, 0) };
Battle area1Battle2 = { 148, 8, MUSIC(2, 0) };
Battle area1Battle3 = { 148, 8, MUSIC(2, 0) };
Battle area1Battle4 = { 154, 8, MUSIC(2, 0) };
Battle area1Battle5 = { 154, 8, MUSIC(2, 0) };
Battle area1Battle6 = { 154, 8, MUSIC(2, 0) };
Battle area1Battle7 = { 154, 8, MUSIC(2, 0) };
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
Battle area3Battle4 = { 330, 8, MUSIC(2, 0) };
Battle area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle7 = { 61, 8, MUSIC(2, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 35, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x19D, 0xD8, 0x9D, 0x160, 0x1FF },
    { 0x1C0, 0x100, 0x1EA, 0x176, 0x2A8, 0x76, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x1BD, 0xD8, 0xBD, 0x150, 0x1FE },
    { 0x140, 0x100, 0x176, 0x175, 0xD8, 0x75, 0x160, 0x1FE },
};
u16 actor0Talk0Actions[] = { 0x7A30, 1, CODES_END };
u16 actor1Talk0Actions[] = { START_EVENT(0x65), 1, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(2, 0x29), 1, ITEM(1, 0x36), 1, SPECIAL(0x13), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x309 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, actor1Talk0Actions, 0x168 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, actor2Talk0Actions, 0x26E },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x333 },
    { NULL, NULL, 0 },
};
u16 actor2Conditions[] = { FLAG(2, 0x29), 0, CODES_END };
u16 actor3Conditions[] = { SPECIAL(0x16), 1, PROGRESS(0x12), 0, CODES_END };
FieldActorEntry actor0 = { NULL, actor0Talks, 0x14, 4, 450, 368, 1 };
FieldActorEntry actor1 = { NULL, actor1Talks, 0x15, 5, 247, 291, 7 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x21, 6, 502, 546, 1 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x65, 7, 608, 240, 5 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 410, 231, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 554, 520, 0, 0 },
    { 1, 0, 0x80, 2, 7, 0, 0, 0, 0, 0, 0, 384, 0, 0 },
    { 1, 0, 0x80, 2, 8, 0, 0, 0, 0, 0, 384, 384, 0, 0 },
    { 1, 0, 0x70, 2, 9, 0, 0, 0, 0, 0, 20, 512, 0, 0 },
    { 1, 0, 0x78, 2, 0xA, 0, 0, 0, 0, 0, 264, 523, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 94, 473, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 254, 516, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 367, 431, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 386, 432, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 160, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 298, 481, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 268, 346, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 347, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 155, 525, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 197, 568, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 208, 580, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 124, 412, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 201, 372, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 226, 530, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 291, 355, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 309, 520, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 419, 451, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x49, 6, 0, 204, 396, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4A, 1, 0x4A, 0x4D, 6, 0, 213, 360, 0, 0 },
    { 1, 0, 0x68, 0xA, 0x4E, 2, 0, 2, 6, 0, 181, 376, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 584, 137, 169, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x248, 0x610, 0x240, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x24A, 0x80, 0x178, 7, 0, 0, 0 },
    { { { SPECIAL(0x93), 1 }, { CODES_END, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 5, 1 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0xFFC8, 0x3C, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0xFFD0, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0x40, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { SPECIAL(0x93), 1 }, { CODES_END, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 5, 1 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1459, script1459, EVENT_TEXT(0x26), NULL, func_800A4D4C },
    { -1, NULL, 0, NULL, NULL },
};
