#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6C9
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6D8
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x25D00, 0x2F900};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x1A;
    FIELDSTG_state.music = MUSIC(0x1A, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(FLAG(0x1A, 0xA), 0) != 0) {
        FIELDSTG_state.soundBank = 0x1F;
        FIELDSTG_state.music = MUSIC(0x1F, 0);
    }
}

s16 script1241[] = {
    0x102, 2, 0x4B0, 0x381, 5,
    0x100, 0x15, 0x4D1, 0x371,
    0x101, 0x15, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 0,
    0x200, 0, 1, 0x32D, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 1,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 1,
    0x300, 0x5A,
    0x304, 0xC11, 0, 0, 0,
    0,
};
Battle area0Battle0 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle1 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle2 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle3 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area0Battle7 = { 0, 0, MUSIC(1, 0) };
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
Battle area3Battle0 = { 251, 18, MUSIC(2, 0) };
Battle area3Battle1 = { 252, 18, MUSIC(2, 0) };
Battle area3Battle2 = { 299, 18, MUSIC(3, 0) };
Battle area3Battle3 = { 300, 18, MUSIC(3, 0) };
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
    { 164, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x198, 0xD8, 0x98, 0x170, 0x1FB },
    { 0x140, 0x100, 0x170, 0x100, 0xC0, 0, 0x160, 0x1FA },
    { 0x140, 0x100, 0x168, 0x158, 0xA0, 0x58, 0x170, 0x1FA },
    { 0x140, 0x100, 0x170, 0x158, 0xC0, 0x58, 0x150, 0x1F9 },
    { 0x140, 0x100, 0x16E, 0x130, 0xB8, 0x30, 0x160, 0x1F9 },
    { 0x140, 0x100, 0x168, 0x134, 0xA0, 0x34, 0x170, 0x1F9 },
    { 0x140, 0x100, 0x160, 0x134, 0x80, 0x34, 0x150, 0x1F8 },
    { 0x140, 0x100, 0x140, 0x154, 0, 0x54, 0x160, 0x1F8 },
    { 0x140, 0x100, 0x148, 0x160, 0x20, 0x60, 0x170, 0x1F8 },
    { 0x140, 0x100, 0x150, 0x164, 0x40, 0x64, 0x150, 0x1F7 },
    { 0x140, 0x100, 0x166, 0x1A0, 0x98, 0xA0, 0x160, 0x1F7 },
    { 0x140, 0x100, 0x140, 0x1A4, 0, 0xA4, 0x170, 0x1F7 },
    { 0x140, 0x100, 0x156, 0x134, 0x58, 0x34, 0x150, 0x1F6 },
};
u16 actor0Talk0Actions[] = { 0x7A30, 1, CODES_END };
u16 actor1Talk0Actions[] = { START_EVENT(0x18), 1, CODES_END };
u16 actor2Talk0Actions[] = { 0x7A1D, 1, CODES_END };
u16 actor3Talk0Actions[] = { 0x7A1C, 1, CODES_END };
u16 actor4Talk0Actions[] = { 0x7C00, 1, CODES_END };
u16 actor5Talk0Actions[] = { FLAG(2, 0x53), 1, ITEM(5, 0x118), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor8Talk0Conditions[] = { FLAG(0, 0x10), 1, FLAG(0, 0x11), 1, CODES_END };
u16 actor8Talk0Actions[] = { FLAG(0, 0x10), 0, FLAG(0, 0x11), 0, CODES_END };
u16 actor8Talk1Conditions[] = { FLAG(0, 0x10), 0, FLAG(0, 0x11), 1, CODES_END };
u16 actor8Talk1Actions[] = { FLAG(0, 0x11), 0, CODES_END };
u16 actor8Talk2Conditions[] = { FLAG(0, 0), 0, FLAG(0, 0x11), 0, CODES_END };
u16 actor8Talk2Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor8Talk3Conditions[] = { PARTY_STAT(8), 0, FLAG(0, 0), 1, FLAG(0, 0x11), 0, CODES_END };
u16 actor8Talk4Conditions[] = {
    PARTY_STAT(0xA), 0,
    PARTY_STAT(8), 1,
    FLAG(0, 0), 1,
    FLAG(0, 0x11), 0,
    CODES_END,
};
u16 actor8Talk4Actions[] = { CARD_BATTLE(0x44, 0), 1, CODES_END };
u16 actor8Talk5Conditions[] = {
    FLAG(0xE, 0x3B), 0,
    PARTY_STAT(0xA), 1,
    PARTY_STAT(8), 1,
    FLAG(0, 0), 1,
    FLAG(0, 0x11), 0,
    CODES_END,
};
u16 actor8Talk5Actions[] = { EVENT_BATTLE(1), 1, FLAG(0xE, 0x3B), 1, CODES_END };
u16 actor8Talk6Conditions[] = {
    ITEM(0, 0x14), 0,
    FLAG(0xE, 0x3B), 1,
    PARTY_STAT(0xA), 1,
    PARTY_STAT(8), 1,
    FLAG(0, 0), 1,
    FLAG(0, 0x11), 0,
    CODES_END,
};
u16 actor8Talk7Conditions[] = {
    PARTY_STAT(0xB), 0,
    ITEM(0, 0x14), 1,
    FLAG(0xE, 0x3B), 1,
    PARTY_STAT(0xA), 1,
    PARTY_STAT(8), 1,
    FLAG(0, 0), 1,
    FLAG(0, 0x11), 0,
    CODES_END,
};
u16 actor8Talk8Conditions[] = {
    PARTY_STAT(0xB), 1,
    ITEM(0, 0x14), 1,
    FLAG(0xE, 0x3B), 1,
    PARTY_STAT(0xA), 1,
    PARTY_STAT(8), 1,
    FLAG(0, 0), 1,
    FLAG(0, 0x11), 0,
    CODES_END,
};
u16 actor8Talk8Actions[] = { CARD_BATTLE(0x44, 1), 1, CODES_END };
u16 actor9Talk0Conditions[] = { FLAG(0, 1), 0, CODES_END };
u16 actor9Talk0Actions[] = { FLAG(0, 1), 1, CODES_END };
u16 actor9Talk1Conditions[] = { FLAG(0, 1), 1, PARTY_STAT(0xB), 0, CODES_END };
u16 actor9Talk2Conditions[] = { FLAG(0, 1), 1, PARTY_STAT(0xB), 1, FLAG(0xE, 0x59), 0, CODES_END };
u16 actor9Talk2Actions[] = { EVENT_BATTLE(1), 1, FLAG(0xE, 0x59), 1, CODES_END };
u16 actor9Talk3Conditions[] = {
    FLAG(0, 1), 1,
    PARTY_STAT(0xB), 1,
    FLAG(0xE, 0x59), 1,
    PARTY_STAT(0xD), 0,
    CODES_END,
};
u16 actor9Talk4Conditions[] = {
    FLAG(0, 1), 1,
    PARTY_STAT(0xB), 1,
    FLAG(0xE, 0x59), 1,
    PARTY_STAT(0xD), 1,
    CODES_END,
};
u16 actor9Talk4Actions[] = { CARD_BATTLE(0x44, 1), 1, CODES_END };
u16 actor10Talk0Conditions[] = { FLAG(0, 0x11), 0, CODES_END };
u16 actor10Talk1Conditions[] = { FLAG(0, 0x10), 0, CODES_END };
u16 actor10Talk1Actions[] = { FLAG(0, 0x11), 0, CODES_END };
u16 actor10Talk2Conditions[] = { FLAG(0, 0x10), 1, CODES_END };
u16 actor10Talk2Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0x10), 0, CODES_END };
u16 actor12Talk0Conditions[] = { FLAG(0, 0x10), 1, FLAG(0, 0x11), 1, CODES_END };
u16 actor12Talk0Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0x10), 0, CODES_END };
u16 actor12Talk1Conditions[] = { FLAG(0, 0x10), 0, FLAG(0, 0x11), 1, CODES_END };
u16 actor12Talk1Actions[] = { FLAG(0, 0x11), 0, CODES_END };
u16 actor12Talk2Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 1), 0, CODES_END };
u16 actor12Talk2Actions[] = { FLAG(0, 1), 1, CODES_END };
u16 actor12Talk3Conditions[] = { PARTY_STAT(8), 0, FLAG(0, 1), 1, FLAG(0, 0x11), 0, CODES_END };
u16 actor12Talk4Conditions[] = {
    PARTY_STAT(0xA), 0,
    PARTY_STAT(8), 1,
    FLAG(0, 1), 1,
    FLAG(0, 0x11), 0,
    CODES_END,
};
u16 actor12Talk4Actions[] = { CARD_BATTLE(0x43, 0), 1, CODES_END };
u16 actor12Talk5Conditions[] = {
    FLAG(0xE, 0x3A), 0,
    PARTY_STAT(0xA), 1,
    PARTY_STAT(8), 1,
    FLAG(0, 1), 1,
    FLAG(0, 0x11), 0,
    CODES_END,
};
u16 actor12Talk5Actions[] = { EVENT_BATTLE(0), 1, FLAG(0xE, 0x3A), 1, CODES_END };
u16 actor12Talk6Conditions[] = {
    ITEM(0, 0x14), 0,
    FLAG(0xE, 0x3A), 1,
    PARTY_STAT(0xA), 1,
    PARTY_STAT(8), 1,
    FLAG(0, 1), 1,
    FLAG(0, 0x11), 0,
    CODES_END,
};
u16 actor12Talk7Conditions[] = {
    PARTY_STAT(0xB), 0,
    ITEM(0, 0x14), 1,
    FLAG(0xE, 0x3A), 1,
    PARTY_STAT(0xA), 1,
    PARTY_STAT(8), 1,
    FLAG(0, 1), 1,
    FLAG(0, 0x11), 0,
    CODES_END,
};
u16 actor12Talk8Conditions[] = {
    PARTY_STAT(0xB), 1,
    ITEM(0, 0x14), 1,
    FLAG(0xE, 0x3A), 1,
    PARTY_STAT(0xA), 1,
    PARTY_STAT(8), 1,
    FLAG(0, 1), 1,
    FLAG(0, 0x11), 0,
    CODES_END,
};
u16 actor12Talk8Actions[] = { CARD_BATTLE(0x43, 1), 1, CODES_END };
u16 actor13Talk0Conditions[] = { FLAG(0, 0), 0, CODES_END };
u16 actor13Talk0Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor13Talk1Conditions[] = { FLAG(0, 0), 1, PARTY_STAT(0xB), 0, CODES_END };
u16 actor13Talk2Conditions[] = { FLAG(0, 0), 1, PARTY_STAT(0xB), 1, FLAG(0xE, 0x58), 0, CODES_END };
u16 actor13Talk2Actions[] = { EVENT_BATTLE(0), 1, FLAG(0xE, 0x58), 1, CODES_END };
u16 actor13Talk3Conditions[] = {
    FLAG(0, 0), 1,
    PARTY_STAT(0xB), 1,
    FLAG(0xE, 0x58), 1,
    PARTY_STAT(0xD), 0,
    CODES_END,
};
u16 actor13Talk4Conditions[] = {
    FLAG(0, 0), 1,
    PARTY_STAT(0xB), 1,
    FLAG(0xE, 0x58), 1,
    PARTY_STAT(0xD), 1,
    CODES_END,
};
u16 actor13Talk4Actions[] = { CARD_BATTLE(0x43, 1), 1, CODES_END };
u16 actor14Talk0Conditions[] = { FLAG(0, 0x11), 0, CODES_END };
u16 actor14Talk1Conditions[] = { FLAG(0, 0x10), 0, CODES_END };
u16 actor14Talk1Actions[] = { FLAG(0, 0x11), 0, CODES_END };
u16 actor14Talk2Conditions[] = { FLAG(0, 0x10), 1, CODES_END };
u16 actor14Talk2Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0x10), 0, CODES_END };
u16 actor20Talk0Conditions[] = { ITEM(0, 0x192), 0, CODES_END };
u16 actor20Talk1Conditions[] = { ITEM(0, 0x192), 1, CODES_END };
u16 actor20Talk1Actions[] = { 0x7A4A, 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x1A3 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, actor1Talk0Actions, 0x1A2 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, actor2Talk0Actions, 0x1A8 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, actor3Talk0Actions, 0x1A4 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, actor4Talk0Actions, 0x1A5 },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, actor5Talk0Actions, 0x16B },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x179 },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x17B },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { actor8Talk0Conditions, actor8Talk0Actions, 0x183 },
    { actor8Talk1Conditions, actor8Talk1Actions, 0x182 },
    { actor8Talk2Conditions, actor8Talk2Actions, 0x185 },
    { actor8Talk3Conditions, NULL, 0x187 },
    { actor8Talk4Conditions, actor8Talk4Actions, 0x188 },
    { actor8Talk5Conditions, actor8Talk5Actions, 0x186 },
    { actor8Talk6Conditions, NULL, 0x181 },
    { actor8Talk7Conditions, NULL, 0x17D },
    { actor8Talk8Conditions, actor8Talk8Actions, 0x136 },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { actor9Talk0Conditions, actor9Talk0Actions, 0x133 },
    { actor9Talk1Conditions, NULL, 0x135 },
    { actor9Talk2Conditions, actor9Talk2Actions, 0x134 },
    { actor9Talk3Conditions, NULL, 0x12F },
    { actor9Talk4Conditions, actor9Talk4Actions, 0x136 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { actor10Talk0Conditions, NULL, 0x205 },
    { actor10Talk1Conditions, actor10Talk1Actions, 0x130 },
    { actor10Talk2Conditions, actor10Talk2Actions, 0x131 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, NULL, 0x132 },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { actor12Talk0Conditions, actor12Talk0Actions, 0x183 },
    { actor12Talk1Conditions, actor12Talk1Actions, 0x182 },
    { actor12Talk2Conditions, actor12Talk2Actions, 0x17D },
    { actor12Talk3Conditions, NULL, 0x17E },
    { actor12Talk4Conditions, actor12Talk4Actions, 0x17F },
    { actor12Talk5Conditions, actor12Talk5Actions, 0x180 },
    { actor12Talk6Conditions, NULL, 0x181 },
    { actor12Talk7Conditions, NULL, 0x17E },
    { actor12Talk8Conditions, actor12Talk8Actions, 0x12D },
    { NULL, NULL, 0 },
};
FieldTalk actor13Talks[] = {
    { actor13Talk0Conditions, actor13Talk0Actions, 0x185 },
    { actor13Talk1Conditions, NULL, 0x187 },
    { actor13Talk2Conditions, actor13Talk2Actions, 0x186 },
    { actor13Talk3Conditions, NULL, 0x181 },
    { actor13Talk4Conditions, actor13Talk4Actions, 0x188 },
    { NULL, NULL, 0 },
};
FieldTalk actor14Talks[] = {
    { actor14Talk0Conditions, NULL, 0x206 },
    { actor14Talk1Conditions, actor14Talk1Actions, 0x182 },
    { actor14Talk2Conditions, actor14Talk2Actions, 0x183 },
    { NULL, NULL, 0 },
};
FieldTalk actor15Talks[] = {
    { NULL, NULL, 0x184 },
    { NULL, NULL, 0 },
};
FieldTalk actor16Talks[] = {
    { NULL, NULL, 0x17A },
    { NULL, NULL, 0 },
};
FieldTalk actor17Talks[] = {
    { NULL, NULL, 0x17A },
    { NULL, NULL, 0 },
};
FieldTalk actor18Talks[] = {
    { NULL, NULL, 0x17C },
    { NULL, NULL, 0 },
};
FieldTalk actor19Talks[] = {
    { NULL, NULL, 0x17C },
    { NULL, NULL, 0 },
};
FieldTalk actor20Talks[] = {
    { actor20Talk0Conditions, NULL, 0x20D },
    { actor20Talk1Conditions, actor20Talk1Actions, 0x1A7 },
    { NULL, NULL, 0 },
};
u16 actor5Conditions[] = { FLAG(2, 0x53), 0, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor7Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor8Conditions[] = { ITEM(0, 0x192), 1, SPECIAL(0x19), 1, CODES_END };
u16 actor9Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor10Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor11Conditions[] = { ITEM(0, 0x192), 0, SPECIAL(0x19), 1, CODES_END };
u16 actor12Conditions[] = { ITEM(0, 0x192), 1, SPECIAL(0x19), 1, CODES_END };
u16 actor13Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor14Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor15Conditions[] = { ITEM(0, 0x192), 0, SPECIAL(0x19), 1, CODES_END };
u16 actor16Conditions[] = { SPECIAL(0x1E), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor17Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor18Conditions[] = { SPECIAL(0x1E), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor19Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
FieldActorEntry actor0 = { NULL, actor0Talks, 0x14, 4, 1073, 798, 1 };
FieldActorEntry actor1 = { NULL, actor1Talks, 0x15, 5, 1233, 881, 1 };
FieldActorEntry actor2 = { NULL, actor2Talks, 0x16, 6, 705, 597, 1 };
FieldActorEntry actor3 = { NULL, actor3Talks, 0x17, 7, 626, 557, 1 };
FieldActorEntry actor4 = { NULL, actor4Talks, 0x18, 8, 1283, 541, 1 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x21, 9, 1041, 881, 1 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x45, 0xC, 290, 490, 7 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x45, 0xC, 290, 490, 7 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x45, 0xC, 290, 490, 7 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x45, 0xC, 290, 490, 7 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x46, 0xD, 721, 256, 7 };
FieldActorEntry actor13 = { actor13Conditions, actor13Talks, 0x46, 0xD, 721, 256, 7 };
FieldActorEntry actor14 = { actor14Conditions, actor14Talks, 0x46, 0xD, 721, 256, 7 };
FieldActorEntry actor15 = { actor15Conditions, actor15Talks, 0x46, 0xD, 721, 256, 7 };
FieldActorEntry actor16 = { actor16Conditions, actor16Talks, 0x9D, 0xE, 593, 702, 1 };
FieldActorEntry actor17 = { actor17Conditions, actor17Talks, 0x9D, 0xE, 593, 702, 1 };
FieldActorEntry actor18 = { actor18Conditions, actor18Talks, 0x9E, 0xF, 745, 777, 1 };
FieldActorEntry actor19 = { actor19Conditions, actor19Talks, 0x9E, 0xF, 745, 777, 1 };
FieldActorEntry actor20 = { NULL, actor20Talks, 0xCE, 0x10, 1041, 657, 3 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    &actor5,
    &actor6,
    &actor7,
    &actor8,
    &actor9,
    &actor10,
    &actor11,
    &actor12,
    &actor13,
    &actor14,
    &actor15,
    &actor16,
    &actor17,
    &actor18,
    &actor19,
    &actor20,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 1273, 492, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xB, 6, 0, 1277, 496, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 1, 0x34, 0x3B, 6, 0, 1184, 497, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 3, 6, 0, 1180, 483, 0, 0 },
    { 1, 0, 0x40, 6, 3, 0, 0, 0, 0, 0, 1272, 754, 0, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 325, 419, 441, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 388, 386, 410, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 1104, 797, 832, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2D5, 0x344, 0x196, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2D5, 0x318, 0x264, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2D5, 0x404, 0x1F6, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 5, 0x49E, 0x2F0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 5, 0x48F, 0x348, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1241, script1241, EVENT_TEXT(7), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
