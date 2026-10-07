#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D4C(void) {
    GAME.progress = 9;
}

extern FieldBattles stageBattles0[];
extern FieldBattles stageBattles1[];
extern FieldBattles stageBattles2[];
const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x2AC
#define STAGE_ARCHIVE 0x320
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x2BB
#define STAGE_ARCHIVE 0x32F
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_ARCHIVE;
    FIELDSTG_state.start = (Vec2){0x13D00, 0x34000};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 9;
    FIELDSTG_state.music = MUSIC(9, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        FIELDSTG_state.soundBank = 0x1F;
        FIELDSTG_state.music = MUSIC(0x1F, 0);
    }
    if (GAME.progress < 0xB) {
        FIELDSTG_state.battles = stageBattles0;
    } else if (GAME.progress < 0x18) {
        FIELDSTG_state.battles = stageBattles1;
    } else {
        FIELDSTG_state.battles = stageBattles2;
    }
}

s16 script205[] = {
    0x600, 0, 2,
    0x102, 2, 0xA1, 0x1B1, 3,
    0x100, 0x67, 0x81, 0x1A1,
    0x101, 0x67, 1, 7,
    0x101, 0x323, 0x325, 0x67,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x3C,
    0x101, 2, 1, 3,
    0x101, 0x323, 0x326, 0x67,
    0x300, 0x1E,
    0x200, 0, 1, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x301,
    0x101, 0x323, 0x325, 0x67,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x67,
    0x300, 0x1E,
    0x200, 0, 3, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 7, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 2, 3,
    0x301,
    0x101, 0x323, 0x327, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 9, 0x67, 0,
    0x301,
    0x101, 0x67, 1, 3,
    0x300, 0x1E,
    0x200, 0, 0xA, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xA0, 0x1D0, 0,
    0x302, 2,
    0x102, 2, 0xE0, 0x1F0, 7,
    0x300, 0x3C,
    0x304, 0x222, 0x32A, 0x334, 3,
    0,
};
Battle battles0Area0Battle0 = { 39, 13, MUSIC(2, 0) };
Battle battles0Area0Battle1 = { 39, 13, MUSIC(2, 0) };
Battle battles0Area0Battle2 = { 39, 13, MUSIC(2, 0) };
Battle battles0Area0Battle3 = { 39, 13, MUSIC(2, 0) };
Battle battles0Area0Battle4 = { 36, 13, MUSIC(2, 0) };
Battle battles0Area0Battle5 = { 36, 13, MUSIC(2, 0) };
Battle battles0Area0Battle6 = { 36, 13, MUSIC(2, 0) };
Battle battles0Area0Battle7 = { 36, 13, MUSIC(2, 0) };
BattleList battles0Area0Battles = {
    3,
    { &battles0Area0Battle0, &battles0Area0Battle1, &battles0Area0Battle2, &battles0Area0Battle3,
      &battles0Area0Battle4, &battles0Area0Battle5, &battles0Area0Battle6, &battles0Area0Battle7 },
};
Battle battles0Area1Battle0 = { 0, 13, MUSIC(2, 0) };
Battle battles0Area1Battle1 = { 0, 13, MUSIC(2, 0) };
Battle battles0Area1Battle2 = { 0, 13, MUSIC(2, 0) };
Battle battles0Area1Battle3 = { 0, 13, MUSIC(2, 0) };
Battle battles0Area1Battle4 = { 0, 13, MUSIC(2, 0) };
Battle battles0Area1Battle5 = { 0, 13, MUSIC(2, 0) };
Battle battles0Area1Battle6 = { 0, 13, MUSIC(2, 0) };
Battle battles0Area1Battle7 = { 0, 13, MUSIC(2, 0) };
BattleList battles0Area1Battles = {
    0,
    { &battles0Area1Battle0, &battles0Area1Battle1, &battles0Area1Battle2, &battles0Area1Battle3,
      &battles0Area1Battle4, &battles0Area1Battle5, &battles0Area1Battle6, &battles0Area1Battle7 },
};
Battle battles0Area2Battle0 = { 0, 0, MUSIC(1, 0) };
Battle battles0Area2Battle1 = { 0, 0, MUSIC(1, 0) };
Battle battles0Area2Battle2 = { 0, 0, MUSIC(1, 0) };
Battle battles0Area2Battle3 = { 0, 0, MUSIC(1, 0) };
Battle battles0Area2Battle4 = { 0, 0, MUSIC(1, 0) };
Battle battles0Area2Battle5 = { 0, 0, MUSIC(1, 0) };
Battle battles0Area2Battle6 = { 0, 0, MUSIC(1, 0) };
Battle battles0Area2Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList battles0Area2Battles = {
    0,
    { &battles0Area2Battle0, &battles0Area2Battle1, &battles0Area2Battle2, &battles0Area2Battle3,
      &battles0Area2Battle4, &battles0Area2Battle5, &battles0Area2Battle6, &battles0Area2Battle7 },
};
Battle battles0Area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle battles0Area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle battles0Area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle battles0Area3Battle3 = { 327, 13, MUSIC(2, 0) };
Battle battles0Area3Battle4 = { 328, 8, MUSIC(2, 0) };
Battle battles0Area3Battle5 = { 36, 13, MUSIC(2, 0) };
Battle battles0Area3Battle6 = { 49, 13, MUSIC(2, 0) };
Battle battles0Area3Battle7 = { 64, 8, MUSIC(2, 0) };
BattleList battles0Area3Battles = {
    0,
    { &battles0Area3Battle0, &battles0Area3Battle1, &battles0Area3Battle2, &battles0Area3Battle3,
      &battles0Area3Battle4, &battles0Area3Battle5, &battles0Area3Battle6, &battles0Area3Battle7 },
};
Battle battles1Area0Battle0 = { 36, 13, MUSIC(2, 0) };
Battle battles1Area0Battle1 = { 36, 13, MUSIC(2, 0) };
Battle battles1Area0Battle2 = { 66, 13, MUSIC(2, 0) };
Battle battles1Area0Battle3 = { 66, 13, MUSIC(2, 0) };
Battle battles1Area0Battle4 = { 66, 13, MUSIC(2, 0) };
Battle battles1Area0Battle5 = { 66, 13, MUSIC(2, 0) };
Battle battles1Area0Battle6 = { 66, 13, MUSIC(2, 0) };
Battle battles1Area0Battle7 = { 66, 13, MUSIC(2, 0) };
BattleList battles1Area0Battles = {
    3,
    { &battles1Area0Battle0, &battles1Area0Battle1, &battles1Area0Battle2, &battles1Area0Battle3,
      &battles1Area0Battle4, &battles1Area0Battle5, &battles1Area0Battle6, &battles1Area0Battle7 },
};
Battle battles1Area1Battle0 = { 0, 13, MUSIC(2, 0) };
Battle battles1Area1Battle1 = { 0, 13, MUSIC(2, 0) };
Battle battles1Area1Battle2 = { 0, 13, MUSIC(2, 0) };
Battle battles1Area1Battle3 = { 0, 13, MUSIC(2, 0) };
Battle battles1Area1Battle4 = { 0, 13, MUSIC(2, 0) };
Battle battles1Area1Battle5 = { 0, 13, MUSIC(2, 0) };
Battle battles1Area1Battle6 = { 0, 13, MUSIC(2, 0) };
Battle battles1Area1Battle7 = { 0, 13, MUSIC(2, 0) };
BattleList battles1Area1Battles = {
    0,
    { &battles1Area1Battle0, &battles1Area1Battle1, &battles1Area1Battle2, &battles1Area1Battle3,
      &battles1Area1Battle4, &battles1Area1Battle5, &battles1Area1Battle6, &battles1Area1Battle7 },
};
Battle battles1Area2Battle0 = { 0, 0, MUSIC(1, 0) };
Battle battles1Area2Battle1 = { 0, 0, MUSIC(1, 0) };
Battle battles1Area2Battle2 = { 0, 0, MUSIC(1, 0) };
Battle battles1Area2Battle3 = { 0, 0, MUSIC(1, 0) };
Battle battles1Area2Battle4 = { 0, 0, MUSIC(1, 0) };
Battle battles1Area2Battle5 = { 0, 0, MUSIC(1, 0) };
Battle battles1Area2Battle6 = { 0, 0, MUSIC(1, 0) };
Battle battles1Area2Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList battles1Area2Battles = {
    0,
    { &battles1Area2Battle0, &battles1Area2Battle1, &battles1Area2Battle2, &battles1Area2Battle3,
      &battles1Area2Battle4, &battles1Area2Battle5, &battles1Area2Battle6, &battles1Area2Battle7 },
};
Battle battles1Area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle battles1Area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle battles1Area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle battles1Area3Battle3 = { 327, 13, MUSIC(2, 0) };
Battle battles1Area3Battle4 = { 328, 8, MUSIC(2, 0) };
Battle battles1Area3Battle5 = { 36, 13, MUSIC(2, 0) };
Battle battles1Area3Battle6 = { 49, 13, MUSIC(2, 0) };
Battle battles1Area3Battle7 = { 64, 8, MUSIC(2, 0) };
BattleList battles1Area3Battles = {
    0,
    { &battles1Area3Battle0, &battles1Area3Battle1, &battles1Area3Battle2, &battles1Area3Battle3,
      &battles1Area3Battle4, &battles1Area3Battle5, &battles1Area3Battle6, &battles1Area3Battle7 },
};
Battle battles2Area0Battle0 = { 36, 13, MUSIC(2, 0) };
Battle battles2Area0Battle1 = { 36, 13, MUSIC(2, 0) };
Battle battles2Area0Battle2 = { 66, 13, MUSIC(2, 0) };
Battle battles2Area0Battle3 = { 66, 13, MUSIC(2, 0) };
Battle battles2Area0Battle4 = { 60, 13, MUSIC(2, 0) };
Battle battles2Area0Battle5 = { 60, 13, MUSIC(2, 0) };
Battle battles2Area0Battle6 = { 60, 13, MUSIC(2, 0) };
Battle battles2Area0Battle7 = { 60, 13, MUSIC(2, 0) };
BattleList battles2Area0Battles = {
    3,
    { &battles2Area0Battle0, &battles2Area0Battle1, &battles2Area0Battle2, &battles2Area0Battle3,
      &battles2Area0Battle4, &battles2Area0Battle5, &battles2Area0Battle6, &battles2Area0Battle7 },
};
Battle battles2Area1Battle0 = { 0, 13, MUSIC(2, 0) };
Battle battles2Area1Battle1 = { 0, 13, MUSIC(2, 0) };
Battle battles2Area1Battle2 = { 0, 13, MUSIC(2, 0) };
Battle battles2Area1Battle3 = { 0, 13, MUSIC(2, 0) };
Battle battles2Area1Battle4 = { 0, 13, MUSIC(2, 0) };
Battle battles2Area1Battle5 = { 0, 13, MUSIC(2, 0) };
Battle battles2Area1Battle6 = { 0, 13, MUSIC(2, 0) };
Battle battles2Area1Battle7 = { 0, 13, MUSIC(2, 0) };
BattleList battles2Area1Battles = {
    0,
    { &battles2Area1Battle0, &battles2Area1Battle1, &battles2Area1Battle2, &battles2Area1Battle3,
      &battles2Area1Battle4, &battles2Area1Battle5, &battles2Area1Battle6, &battles2Area1Battle7 },
};
Battle battles2Area2Battle0 = { 0, 0, MUSIC(1, 0) };
Battle battles2Area2Battle1 = { 0, 0, MUSIC(1, 0) };
Battle battles2Area2Battle2 = { 0, 0, MUSIC(1, 0) };
Battle battles2Area2Battle3 = { 0, 0, MUSIC(1, 0) };
Battle battles2Area2Battle4 = { 0, 0, MUSIC(1, 0) };
Battle battles2Area2Battle5 = { 0, 0, MUSIC(1, 0) };
Battle battles2Area2Battle6 = { 0, 0, MUSIC(1, 0) };
Battle battles2Area2Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList battles2Area2Battles = {
    0,
    { &battles2Area2Battle0, &battles2Area2Battle1, &battles2Area2Battle2, &battles2Area2Battle3,
      &battles2Area2Battle4, &battles2Area2Battle5, &battles2Area2Battle6, &battles2Area2Battle7 },
};
Battle battles2Area3Battle0 = { 0, 0, MUSIC(1, 0) };
Battle battles2Area3Battle1 = { 0, 0, MUSIC(1, 0) };
Battle battles2Area3Battle2 = { 0, 0, MUSIC(1, 0) };
Battle battles2Area3Battle3 = { 327, 13, MUSIC(2, 0) };
Battle battles2Area3Battle4 = { 328, 8, MUSIC(2, 0) };
Battle battles2Area3Battle5 = { 36, 13, MUSIC(2, 0) };
Battle battles2Area3Battle6 = { 49, 13, MUSIC(2, 0) };
Battle battles2Area3Battle7 = { 64, 8, MUSIC(2, 0) };
BattleList battles2Area3Battles = {
    0,
    { &battles2Area3Battle0, &battles2Area3Battle1, &battles2Area3Battle2, &battles2Area3Battle3,
      &battles2Area3Battle4, &battles2Area3Battle5, &battles2Area3Battle6, &battles2Area3Battle7 },
};
FieldBattles stageBattles0[] = {
    { 7, 0, 0, { &battles0Area0Battles, &battles0Area1Battles, &battles0Area2Battles, &battles0Area3Battles } },
};
FieldBattles stageBattles1[] = {
    { 24, 1, 0, { &battles1Area0Battles, &battles1Area1Battles, &battles1Area2Battles, &battles1Area3Battles } },
};
FieldBattles stageBattles2[] = {
    { 53, 2, 0, { &battles2Area0Battles, &battles2Area1Battles, &battles2Area2Battles, &battles2Area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x19A, 0x120, 0x168, 0x20, 0x160, 0x1FF },
    { 0x140, 0x100, 0x170, 0x1CC, 0xC0, 0xCC, 0x140, 0x1FE },
    { 0x180, 0x100, 0x1B0, 0x100, 0x1C0, 0, 0x150, 0x1FE },
    { 0x180, 0x100, 0x180, 0x120, 0x100, 0x20, 0x160, 0x1FE },
    { 0x180, 0x100, 0x18A, 0x120, 0x128, 0x20, 0x170, 0x1FE },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 actor0Talk0Actions[] = { FLAG(2, 3), 1, ITEM(5, 0xD7), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor1Talk0Conditions[] = { FLAG(0x1A, 0x2C), 0, CODES_END };
u16 actor1Talk0Actions[] = { FLAG(0x1A, 0x2C), 1, ITEM(0, 7), 1, SPECIAL(0x13), 1, CODES_END };
u16 actor1Talk1Conditions[] = { FLAG(0x1A, 0x2C), 1, CODES_END };
u16 actor4Talk0Actions[] = { START_EVENT(0x20), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x16F },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { actor1Talk0Conditions, actor1Talk0Actions, 0x2B9 },
    { actor1Talk1Conditions, NULL, 0x2BA },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, actor4Talk0Actions, 0x248 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { FLAG(2, 3), 0, CODES_END };
u16 actor1Conditions[] = { FLAG(0x1A, 0x21), 1, FLAG(0x1A, 0x2C), 0, CODES_END };
u16 actor4Conditions[] = { PROGRESS(8), 1, FLAG(0x1A, 0x1A), 1, CODES_END };
u16 actor5Conditions[] = { FLAG(0x1A, 0x21), 1, FLAG(0x1A, 0x2C), 0, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x21, 4, 776, 125, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x4B, 5, 530, 430, 1 };
FieldActorEntry actor2 = { NULL, NULL, 0x4C, 6, 760, 357, 7 };
FieldActorEntry actor3 = { NULL, NULL, 0x58, 7, 670, 280, 1 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x67, 8, 129, 417, 3 };
FieldActorEntry actor5 = { actor5Conditions, NULL, 0x11C, 9, 520, 437, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    &actor5,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 4, 1, 4, 9, 8, 0, 43, 521, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 9, 8, 0, 426, -16, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 9, 8, 0, 761, 743, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 337, 409, 0, 0 },
    { 1, 0, 0x74, 2, 2, 0, 0, 0, 0, 0, 655, 662, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 732, 199, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 810, 177, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 868, 149, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 989, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1051, 414, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1125, 373, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 431, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 541, 288, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 618, 226, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 781, 193, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 907, 130, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 34, 772, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 470, 378, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 504, 455, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 606, 516, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 611, 441, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 660, 472, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 686, 214, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 700, 583, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 764, 605, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 840, 162, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 372, 442, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 411, 412, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 492, 502, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 988, 429, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 58, 779, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 293, 404, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 427, 470, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 537, 476, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 940, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 337, 423, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 538, 522, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 624, 465, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 764, 635, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 793, 425, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1050, 398, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 45, 781, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 466, 351, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 467, 390, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 523, 455, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 552, 295, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 563, 474, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 564, 271, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 575, 246, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 632, 233, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 644, 473, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 664, 324, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 684, 581, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 690, 456, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 733, 208, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 788, 632, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 792, 404, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 819, 419, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 850, 168, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 952, 332, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 977, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1021, 428, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1072, 376, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1131, 347, 0, 0 },
    { 1, 0, 0x74, 6, 3, 0, 0, 0, 0, 0, 768, 640, 0, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 96, 687, 687, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 103, 923, 923, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 144, 663, 663, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 160, 703, 703, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 160, 943, 943, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 192, 639, 639, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 192, 911, 911, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 208, 679, 679, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 224, 952, 952, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 559, 559, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 655, 655, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 272, 197, 197, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 274, 262, 262, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 288, 623, 623, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 288, 937, 937, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 304, 535, 535, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 305, 230, 230, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 175, 175, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 336, 599, 599, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 352, 207, 207, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 400, 583, 583, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 480, 591, 591, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 576, 127, 127, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 624, 110, 110, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 656, 135, 135, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 720, 110, 110, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 896, 831, 831, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 944, 807, 807, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 992, 783, 783, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1115, 428, 428, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x222, 0x32A, 0x334, 3, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x229, 0x9A, 0x74, 7, 0, 0, 0 },
    { { { SPECIAL(0x93), 1 }, { CODES_END, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 8, 1 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 3, 0x1A1, 0x140, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 3, 0x1B0, 0x176, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0x38, 0x58, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0x40, 0x40, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0, 0xFFC0, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0xFFB8, 0x28, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0xFFC0, 0x38, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0xFF90, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0xFFB0, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0x40, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0xFFE0, 0x18, 0, 0, 0, 0, 0 },
    { { { ITEM(0, 5), 1 }, { CODES_END, 0 } }, 7, 0xFFF0, 0x10, 0, 0, 0, 0, 0 },
    { { { FLAG(0, 0xF), 0 }, { CODES_END, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 205, script205, EVENT_TEXT(1), NULL, func_800A4D4C },
    { 9000, NULL, 0, FIELDSTG_startEventBattle5, NULL },
    { -1, NULL, 0, NULL, NULL },
};
