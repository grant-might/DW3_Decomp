#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 16 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0x10 && FLAGS_00.checkCondition(FLAG(0x40, 0xA2), 0)) {
            children[0] = FIELDSTG_startEvent(0x1A6);
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
    FLAGS_00.applyAction(FLAG(0x40, 0xA2), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x471
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x481
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x15C00, 0xF800};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x39;
    FIELDSTG_state.music = MUSIC(0x39, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script422[] = {
    0x601, 1, 0xD2, 0x1F1,
    0x100, 2, 0, 0,
    0x101, 2, 1, 0,
    0x100, 0x69, 0x72, 0x1C1,
    0x101, 0x69, 1, 7,
    0x300, 0x1E,
    0x102, 0x69, 0xAA, 0x1DD, 7,
    0x302, 0x69,
    0x100, 2, 0x91, 0x1D0,
    0x101, 2, 1, 7,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0xD2, 0x1F1, 7,
    0x102, 0x69, 0xD2, 0x1C9, 1,
    0x302, 2,
    0x600, 1, 2,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x102, 0x69, 0xAF, 0x1DB, 7,
    0x302, 0x69,
    0x101, 0x69, 1, 7,
    0x300, 0x1E,
    0x200, 0, 1, 0x69, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x69, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0x69, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 7, 0x69, 0,
    0x301,
    0x300, 0x1E,
    0x102, 0x69, 0x9F, 0x1D3, 7,
    0x302, 0x69,
    0x101, 0x69, 1, 7,
    0x300, 0x1E,
    0x200, 0, 8, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 9, 2, 3,
    0x301,
    0x300, 0x3C,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x181\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x6004\n");
#endif
Battle area0Battle0 = { 149, 3, MUSIC(2, 0) };
Battle area0Battle1 = { 149, 3, MUSIC(2, 0) };
Battle area0Battle2 = { 149, 3, MUSIC(2, 0) };
Battle area0Battle3 = { 149, 3, MUSIC(2, 0) };
Battle area0Battle4 = { 70, 3, MUSIC(2, 0) };
Battle area0Battle5 = { 70, 3, MUSIC(2, 0) };
Battle area0Battle6 = { 70, 3, MUSIC(2, 0) };
Battle area0Battle7 = { 70, 3, MUSIC(2, 0) };
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
Battle area3Battle3 = { 329, 3, MUSIC(2, 0) };
Battle area3Battle4 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle6 = { 156, 3, MUSIC(2, 0) };
Battle area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 33, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x172, 0x118, 0xC8, 0x18, 0x150, 0x1FF },
};
FieldTalk actor0Talks[] = {
    { NULL, NULL, 0x310 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { PROGRESS(0x10), 1, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x69, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &actor0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 166, 265, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 186, 261, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 186, 277, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 195, 287, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 207, 278, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 208, 273, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 217, 281, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 223, 291, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 237, 301, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 244, 290, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 264, 305, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 532, 182, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 551, 182, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 553, 172, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 496, 200, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 520, 201, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 526, 192, 0, 0 },
    { 1, 0, 0x40, 2, 6, 1, 6, 0xD, 4, 0, 490, 26, 0, 0 },
    { 1, 0, 0x40, 2, 6, 1, 6, 0xD, 4, 0, 528, 45, 0, 0 },
    { 1, 0, 0x40, 2, 6, 1, 6, 0xD, 4, 0, 567, 64, 0, 0 },
    { 1, 0, 0x64, 2, 0xE, 0, 0, 0, 0, 0, 698, 491, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 418, 122, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 421, 128, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 434, 112, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 450, 120, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 384, 141, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 391, 147, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 392, 125, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 414, 137, 0, 0 },
    { 1, 0, 0x73, 4, 0, 0, 0, 0, 0, 0, 349, 733, 824, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 444, 766, 777, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 310, 576, 599, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 487, 596, 610, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 592, 118, 160, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 103, 411, 477, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 336, 535, 535, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 384, 559, 559, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 576, 895, 895, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 636, 800, 800, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 673, 767, 767, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x24A, 0x5D8, 0x104, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x24D, 0x88, 0x3F4, 5, 0, 0, 0 },
    { { { SPECIAL(0x94), 1 }, { CODES_END, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x10, 1 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 8, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 422, script422, EVENT_TEXT(5), NULL, func_800A4D94 },
    { -1, NULL, 0, NULL, NULL },
};
