#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x656
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x666
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x1FA00, 0x2DE00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x17;
    FIELDSTG_state.music = MUSIC(0x17, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.spriteColor = stageColor;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(FLAG(0x1A, 0xA), 0) != 0) {
        FIELDSTG_state.soundBank = 0x1F;
        FIELDSTG_state.music = MUSIC(0x1F, 0);
    }
}

s16 script1230[] = {
    0x102, 2, 0x43E, 0x204, 5,
    0x100, 0x15, 0x45F, 0x1F6,
    0x101, 0x15, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 1,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 1,
    0x300, 0x5A,
    0x304, 0xC0F, 0, 0, 0,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x2\n");
#endif
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1F6, 0x160, 0x2D8, 0x60, 0x150, 0x1FB },
    { 0x180, 0x100, 0x194, 0x1A8, 0x150, 0xA8, 0x160, 0x1FB },
    { 0x1C0, 0x100, 0x1F4, 0x100, 0x2D0, 0, 0x170, 0x1FB },
    { 0x180, 0x100, 0x1A8, 0x1D8, 0x1A0, 0xD8, 0x150, 0x1FA },
    { 0x1C0, 0x100, 0x1CC, 0x100, 0x230, 0, 0x160, 0x1FA },
    { 0x1C0, 0x100, 0x1C0, 0x178, 0x200, 0x78, 0x170, 0x1FA },
    { 0x1C0, 0x100, 0x1C8, 0x178, 0x220, 0x78, 0x140, 0x1F9 },
    { 0x1C0, 0x100, 0x1D0, 0x178, 0x240, 0x78, 0x150, 0x1F9 },
    { 0x1C0, 0x100, 0x1D8, 0x180, 0x260, 0x80, 0x160, 0x1F9 },
    { 0x1C0, 0x100, 0x1EC, 0x180, 0x2B0, 0x80, 0x170, 0x1F9 },
};
u16 actor0Talk0Actions[] = { 0x7A2E, 1, CODES_END };
u16 actor1Talk0Actions[] = { START_EVENT(0x13), 1, CODES_END };
u16 actor2Talk0Actions[] = { 0x7A1B, 1, CODES_END };
u16 actor3Talk0Actions[] = { 0x7A1A, 1, CODES_END };
u16 actor4Talk0Actions[] = { 0x7C00, 1, CODES_END };
u16 actor12Talk0Conditions[] = { SPECIAL(0x1F), 1, CODES_END };
u16 actor12Talk1Conditions[] = { PROGRESS(0x26), 1, CODES_END };
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
    { NULL, NULL, 0x176 },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x178 },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x174 },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { NULL, NULL, 0x175 },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { NULL, NULL, 0x175 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, NULL, 0x177 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, NULL, 0x177 },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { actor12Talk0Conditions, NULL, 0x1D7 },
    { actor12Talk1Conditions, NULL, 0x1D8 },
    { NULL, NULL, 0 },
};
FieldTalk actor13Talks[] = {
    { NULL, NULL, 0x1D9 },
    { NULL, NULL, 0 },
};
FieldTalk actor14Talks[] = {
    { NULL, NULL, 0x1EB },
    { NULL, NULL, 0 },
};
u16 actor5Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor7Conditions[] = { PROGRESS(0x26), 1, FLAG(0x1A, 0xA), 1, CODES_END };
u16 actor8Conditions[] = { SPECIAL(0x21), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor9Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor10Conditions[] = { SPECIAL(0x21), 1, FLAG(0x1A, 0xA), 0, CODES_END };
u16 actor11Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor12Conditions[] = { SPECIAL(0x21), 1, CODES_END };
u16 actor13Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor14Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
FieldActorEntry actor0 = { NULL, actor0Talks, 0x14, 4, 908, 596, 7 };
FieldActorEntry actor1 = { NULL, actor1Talks, 0x15, 5, 1119, 502, 1 };
FieldActorEntry actor2 = { NULL, actor2Talks, 0x16, 6, 834, 470, 7 };
FieldActorEntry actor3 = { NULL, actor3Talks, 0x17, 7, 690, 493, 1 };
FieldActorEntry actor4 = { NULL, actor4Talks, 0x18, 8, 1329, 411, 1 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x2E, 9, 961, 368, 1 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x2E, 9, 767, 529, 3 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x39, 0xA, 993, 531, 7 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x9D, 0xB, 993, 531, 7 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x9D, 0xB, 993, 531, 7 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x9E, 0xC, 961, 368, 1 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x9E, 0xC, 961, 368, 1 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x175, 0xD, 897, 289, 1 };
FieldActorEntry actor13 = { actor13Conditions, actor13Talks, 0x175, 0xD, 897, 289, 1 };
FieldActorEntry actor14 = { actor14Conditions, actor14Talks, 0x175, 0xD, 961, 368, 1 };
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 7, 0, 7, 0xC, 4, 0, 374, 313, 0, 0 },
    { 1, 0, 0x40, 2, 7, 0, 7, 0xC, 4, 0, 919, 586, 0, 0 },
    { 1, 0, 0xC8, 2, 0x5A, 1, 0x5A, 0x61, 0xA, 0, 1314, 270, 0, 0 },
    { 1, 0, 0x48, 2, 0, 0, 0, 0, 0, 0, 444, 419, 0, 0 },
    { 1, 0, 0x58, 2, 0xD, 0, 0, 0, 0, 0, 683, 345, 0, 0 },
    { 1, 0, 0x4C, 2, 0xE, 0, 0, 0, 0, 0, 947, 492, 0, 0 },
    { 1, 0, 0x60, 2, 0x10, 0, 0, 0, 0, 0, 640, 515, 0, 0 },
    { 1, 0, 0x74, 2, 0x11, 0, 0, 0, 0, 0, 624, 524, 0, 0 },
    { 1, 0, 0x44, 2, 0x12, 0, 0, 0, 0, 0, 304, 556, 0, 0 },
    { 1, 0, 0x62, 2, 0xF, 0, 0, 0, 0, 0, 932, 598, 0, 0 },
    { 1, 0, 0x41, 2, 3, 0, 0, 0, 0, 0, 960, 418, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 8, 0, 1378, 348, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 1391, 358, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 8, 0, 1250, 357, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 8, 0, 1263, 350, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x38, 4, 0, 1217, 367, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x38, 4, 0, 1417, 367, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 6, 0, 1310, 259, 0, 0 },
    { 1, 0, 0xC8, 6, 0x57, 1, 0x57, 0x59, 6, 0, 1144, 428, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x49, 0xA, 0, 290, 451, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x49, 0xA, 0, 344, 408, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x49, 0xA, 0, 851, 700, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x49, 0xA, 0, 996, 725, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0x51, 1, 0x51, 0x53, 6, 0, 799, 318, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0x54, 1, 0x54, 0x56, 6, 0, 1052, 371, 0, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 944, 515, 569, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 582, 424, 454, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1056, 269, 327, 0 },
    { 1, 0, 0x41, 4, 4, 0, 0, 0, 0, 0, 369, 703, 751, 0 },
    { 1, 0, 0x41, 4, 4, 0, 0, 0, 0, 0, 449, 743, 791, 0 },
    { 1, 0, 0x60, 4, 2, 0, 0, 0, 0, 0, 914, 233, 303, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2C7, 0x100, 0x220, 5, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2B2, 0x1F0, 0x68, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 4, 0x170, 0x268, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 4, 0x180, 0x2B0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1230, script1230, EVENT_TEXT(6), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
