#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 10 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0xA && FLAGS_00.checkCondition(FLAG(0x40, 2), 1)) {
            children[0] = FIELDSTG_startEvent(0x105);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void func_800A4D94(void) {
    FLAGS_00.applyAction(FLAG(0x40, 2), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

/* Event: applies action 0x800A and sets the progress to 11 */
void func_800A4DE0(void) {
    FLAGS_00.applyAction(ITEM(0, 0xA), 1);
    GAME.progress = 0xB;
}

void func_800A4E14(void) {
    GAME.progress = 26;
}

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x23C
#define STAGE_ARCHIVE 0x3CC
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x24B
#define STAGE_ARCHIVE 0x3DC
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_ARCHIVE;
    FIELDSTG_state.start = (Vec2){0x11500, 0xDC00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x12;
    FIELDSTG_state.music = MUSIC(0x12, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFirstMap(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        FIELDSTG_state.soundBank = 0x1F;
        FIELDSTG_state.music = MUSIC(0x1F, 0);
    }
}

s16 script260[] = {
    0x102, 2, 0x1B9, 0xD5, 3,
    0x100, 0x8D, 0x1A1, 0xC9,
    0x101, 0x8D, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0x8D, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x8D, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 script261[] = {
    0x100, 2, 0x1B9, 0xD5,
    0x101, 2, 1, 3,
    0x100, 0x8D, 0x1A1, 0xC9,
    0x101, 0x8D, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0x8D, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x8D, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0x8D, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x1D1, 0xE1, 7,
    0x300, 6,
    0x304, 0x23E, 0x238, 0x8C, 1,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x1\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x800A\n");
#endif
s16 script695[] = {
    0x102, 2, 0x129, 0xCD, 5,
    0x100, 0x42, 0x141, 0xC1,
    0x101, 0x42, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0x42, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x42, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x168, 0xF5, 7,
    0x101, 0x42, 1, 3,
    0x300, 0x3C,
    0x304, 0x23E, 0x238, 0x8C, 1,
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
Battle area3Battle0 = { 4, 18, MUSIC(0x23, 0) };
Battle area3Battle1 = { 302, 18, MUSIC(0x23, 0) };
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
    { 165, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x19D, 0, 0x9D, 0x160, 0x1FF },
    { 0x140, 0x100, 0x166, 0x19D, 0x98, 0x9D, 0x170, 0x1FF },
    { 0x140, 0x100, 0x168, 0x175, 0xA0, 0x75, 0x160, 0x1FE },
    { 0x140, 0x100, 0x14C, 0x15A, 0x30, 0x5A, 0x170, 0x1FE },
    { 0x140, 0x100, 0x170, 0x175, 0xC0, 0x75, 0x150, 0x1FD },
    { 0x140, 0x100, 0x156, 0x17E, 0x58, 0x7E, 0x160, 0x1FD },
    { 0x140, 0x100, 0x15E, 0x17E, 0x78, 0x7E, 0x170, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x19D, 0xB8, 0x9D, 0x150, 0x1FC },
    { 0x140, 0x100, 0x176, 0x19D, 0xD8, 0x9D, 0x160, 0x1FC },
};
u16 actor7Talk0Conditions[] = { FLAG(0x1C, 0x1C), 0, PROGRESS(0x14), 1, CODES_END };
u16 actor7Talk1Conditions[] = { FLAG(0x1C, 0x1C), 1, PROGRESS(0x14), 1, CODES_END };
u16 actor7Talk2Conditions[] = { SPECIAL(0x17), 1, PROGRESS(0x14), 0, CODES_END };
u16 actor14Talk0Conditions[] = { FLAG(0x1C, 0x1C), 0, CODES_END };
u16 actor14Talk1Conditions[] = { FLAG(0x1C, 0x1C), 1, CODES_END };
u16 actor23Talk0Actions[] = { START_EVENT(0x40), 1, CODES_END };
u16 actor28Talk0Actions[] = { START_EVENT(0x42), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, NULL, 0xA2 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x93 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { NULL, NULL, 0x96 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x99 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0xAE },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0xAB },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0xA8 },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { actor7Talk0Conditions, NULL, 0x99 },
    { actor7Talk1Conditions, NULL, 0x9C },
    { actor7Talk2Conditions, NULL, 0x99 },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { NULL, NULL, 0x9F },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { NULL, NULL, 0xA2 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, NULL, 0xA5 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, NULL, 0x11E },
    { NULL, NULL, 0 },
};
FieldTalk actor12Talks[] = {
    { NULL, NULL, 0x97 },
    { NULL, NULL, 0 },
};
FieldTalk actor13Talks[] = {
    { NULL, NULL, 0x9A },
    { NULL, NULL, 0 },
};
FieldTalk actor14Talks[] = {
    { actor14Talk0Conditions, NULL, 0x9D },
    { actor14Talk1Conditions, NULL, 0x3D },
    { NULL, NULL, 0 },
};
FieldTalk actor15Talks[] = {
    { NULL, NULL, 0xAC },
    { NULL, NULL, 0 },
};
FieldTalk actor16Talks[] = {
    { NULL, NULL, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk actor17Talks[] = {
    { NULL, NULL, 0x9D },
    { NULL, NULL, 0 },
};
FieldTalk actor18Talks[] = {
    { NULL, NULL, 0xA0 },
    { NULL, NULL, 0 },
};
FieldTalk actor19Talks[] = {
    { NULL, NULL, 0xA3 },
    { NULL, NULL, 0 },
};
FieldTalk actor20Talks[] = {
    { NULL, NULL, 0xA6 },
    { NULL, NULL, 0 },
};
FieldTalk actor21Talks[] = {
    { NULL, NULL, 0x11F },
    { NULL, NULL, 0 },
};
FieldTalk actor22Talks[] = {
    { NULL, NULL, 0x91 },
    { NULL, NULL, 0 },
};
FieldTalk actor23Talks[] = {
    { NULL, actor23Talk0Actions, 0xA3 },
    { NULL, NULL, 0 },
};
FieldTalk actor24Talks[] = {
    { NULL, NULL, 0x94 },
    { NULL, NULL, 0 },
};
FieldTalk actor25Talks[] = {
    { NULL, NULL, 0x170 },
    { NULL, NULL, 0 },
};
FieldTalk actor26Talks[] = {
    { NULL, NULL, 0x170 },
    { NULL, NULL, 0 },
};
FieldTalk actor27Talks[] = {
    { NULL, NULL, 0x11D },
    { NULL, NULL, 0 },
};
FieldTalk actor28Talks[] = {
    { NULL, actor28Talk0Actions, 0x92 },
    { NULL, NULL, 0 },
};
FieldTalk actor29Talks[] = {
    { NULL, NULL, 0xAA },
    { NULL, NULL, 0 },
};
FieldTalk actor30Talks[] = {
    { NULL, NULL, 0x95 },
    { NULL, NULL, 0 },
};
FieldTalk actor31Talks[] = {
    { NULL, NULL, 0x98 },
    { NULL, NULL, 0 },
};
FieldTalk actor32Talks[] = {
    { NULL, NULL, 0x9B },
    { NULL, NULL, 0 },
};
FieldTalk actor33Talks[] = {
    { NULL, NULL, 0xB0 },
    { NULL, NULL, 0 },
};
FieldTalk actor34Talks[] = {
    { NULL, NULL, 0x9E },
    { NULL, NULL, 0 },
};
FieldTalk actor35Talks[] = {
    { NULL, NULL, 0xA1 },
    { NULL, NULL, 0 },
};
FieldTalk actor39Talks[] = {
    { NULL, NULL, 0xAD },
    { NULL, NULL, 0 },
};
FieldTalk actor40Talks[] = {
    { NULL, NULL, 0x90 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { PROGRESS(0x19), 1, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0xC), 1, CODES_END };
u16 actor2Conditions[] = { PROGRESS(0xE), 1, CODES_END };
u16 actor3Conditions[] = { SPECIAL(0x16), 1, CODES_END };
u16 actor4Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor5Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor6Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor7Conditions[] = { SPECIAL(0x17), 1, CODES_END };
u16 actor8Conditions[] = { PROGRESS(0x18), 1, CODES_END };
u16 actor9Conditions[] = { PROGRESS(0x1A), 1, CODES_END };
u16 actor10Conditions[] = { SPECIAL(0x19), 1, CODES_END };
u16 actor11Conditions[] = { PROGRESS(0xB), 1, CODES_END };
u16 actor12Conditions[] = { PROGRESS(0xE), 1, CODES_END };
u16 actor13Conditions[] = { SPECIAL(0x16), 1, CODES_END };
u16 actor14Conditions[] = { PROGRESS(0x14), 1, CODES_END };
u16 actor15Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor16Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor17Conditions[] = { SPECIAL(0x17), 1, PROGRESS(0x14), 0, CODES_END };
u16 actor18Conditions[] = { PROGRESS(0x18), 1, CODES_END };
u16 actor19Conditions[] = { PROGRESS(0x1A), 1, CODES_END };
u16 actor20Conditions[] = { SPECIAL(0x19), 1, CODES_END };
u16 actor21Conditions[] = { PROGRESS(0xB), 1, CODES_END };
u16 actor22Conditions[] = { PROGRESS(0xA), 1, CODES_END };
u16 actor23Conditions[] = { PROGRESS(0x19), 1, CODES_END };
u16 actor24Conditions[] = { PROGRESS(0xC), 1, CODES_END };
u16 actor25Conditions[] = { SPECIAL(0x20), 1, PROGRESS(0x21), 0, CODES_END };
u16 actor26Conditions[] = { PROGRESS(0x1A), 1, CODES_END };
u16 actor27Conditions[] = { PROGRESS(0xB), 1, CODES_END };
u16 actor28Conditions[] = { PROGRESS(0xA), 1, CODES_END };
u16 actor29Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor30Conditions[] = { PROGRESS(0xC), 1, CODES_END };
u16 actor31Conditions[] = { PROGRESS(0xE), 1, CODES_END };
u16 actor32Conditions[] = { SPECIAL(0x16), 1, CODES_END };
u16 actor33Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor34Conditions[] = { SPECIAL(0x17), 1, CODES_END };
u16 actor35Conditions[] = { PROGRESS(0x18), 1, CODES_END };
u16 actor39Conditions[] = { SPECIAL(5), 1, CODES_END };
u16 actor40Conditions[] = { PROGRESS(0xA), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0x41, 4, 517, 289, 5 };
FieldActorEntry actor12 = { actor12Conditions, actor12Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor13 = { actor13Conditions, actor13Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor14 = { actor14Conditions, actor14Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor15 = { actor15Conditions, actor15Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor16 = { actor16Conditions, actor16Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor17 = { actor17Conditions, actor17Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor18 = { actor18Conditions, actor18Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor19 = { actor19Conditions, actor19Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor20 = { actor20Conditions, actor20Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor21 = { actor21Conditions, actor21Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor22 = { actor22Conditions, actor22Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor23 = { actor23Conditions, actor23Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor24 = { actor24Conditions, actor24Talks, 0x42, 5, 321, 193, 3 };
FieldActorEntry actor25 = { actor25Conditions, actor25Talks, 0x67, 6, 400, 303, 7 };
FieldActorEntry actor26 = { actor26Conditions, actor26Talks, 0x67, 6, 400, 303, 7 };
FieldActorEntry actor27 = { actor27Conditions, actor27Talks, 0x8D, 7, 417, 201, 3 };
FieldActorEntry actor28 = { actor28Conditions, actor28Talks, 0x8D, 7, 417, 201, 3 };
FieldActorEntry actor29 = { actor29Conditions, actor29Talks, 0x8D, 7, 417, 201, 3 };
FieldActorEntry actor30 = { actor30Conditions, actor30Talks, 0x8D, 7, 417, 201, 3 };
FieldActorEntry actor31 = { actor31Conditions, actor31Talks, 0x8D, 7, 417, 201, 3 };
FieldActorEntry actor32 = { actor32Conditions, actor32Talks, 0x8D, 7, 417, 201, 3 };
FieldActorEntry actor33 = { actor33Conditions, actor33Talks, 0x8D, 7, 417, 201, 3 };
FieldActorEntry actor34 = { actor34Conditions, actor34Talks, 0x8D, 7, 417, 201, 3 };
FieldActorEntry actor35 = { actor35Conditions, actor35Talks, 0x8D, 7, 417, 201, 3 };
FieldActorEntry actor36 = { NULL, NULL, 0x93, 8, 198, 184, 7 };
FieldActorEntry actor37 = { NULL, NULL, 0x94, 9, 223, 172, 7 };
FieldActorEntry actor38 = { NULL, NULL, 0x95, 0xA, 248, 160, 7 };
FieldActorEntry actor39 = { actor39Conditions, actor39Talks, 0x9D, 0xB, 417, 201, 3 };
FieldActorEntry actor40 = { actor40Conditions, actor40Talks, 0x12C, 0xC, 520, 252, 3 };
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
    &actor21,
    &actor22,
    &actor23,
    &actor24,
    &actor25,
    &actor26,
    &actor27,
    &actor28,
    &actor29,
    &actor30,
    &actor31,
    &actor32,
    &actor33,
    &actor34,
    &actor35,
    &actor36,
    &actor37,
    &actor38,
    &actor39,
    &actor40,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 323, 114, 0, 0 },
    { 1, 0, 0xA0, 6, 0xA, 0, 0, 0, 0, 0, 367, 110, 0, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 205, 181, 199, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 237, 165, 183, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 270, 149, 167, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 186, 161, 199, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 218, 145, 183, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 252, 129, 167, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 521, 189, 272, 0 },
    { 1, 0, 0xA0, 4, 1, 0, 0, 0, 0, 0, 367, 110, 256, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 230, 243, 272, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 259, 221, 255, 0 },
    { 1, 0, 0x58, 4, 4, 0, 0, 0, 0, 0, 171, 118, 198, 0 },
    { 1, 0, 0x55, 4, 5, 0, 0, 0, 0, 0, 138, 106, 182, 0 },
    { 1, 0, 0x5C, 4, 6, 0, 0, 0, 0, 0, 263, 68, 153, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x23E, 0x32A, 0x9C, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x23E, 0x238, 0x8C, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 4, 0x1CE, 0xE6, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 4, 0x1BE, 0x12E, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 6, 0x220, 0x150, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 6, 0x230, 0x1B8, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 260, script260, EVENT_TEXT(1), NULL, func_800A4D94 },
    { 261, script261, EVENT_TEXT(2), NULL, func_800A4DE0 },
    { 695, script695, EVENT_TEXT(0x20), NULL, func_800A4E14 },
    { -1, NULL, 0, NULL, NULL },
};
