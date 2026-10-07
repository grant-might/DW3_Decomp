#include "common.h"
#include "stage.h"
extern StageEffectSpot D_800A56BC[];

/* Creates the stage's ten effects and the event object of flags 0x4082/0x4083 */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (i = 0; i < 10; i++) {
            if (D_800A56BC[i].kind == 0) {
                children[i] = createStageEffect(D_800A56BC[i].x, D_800A56BC[i].y, D_800A56BC[i].frame);
            }
        }
        if (FLAGS_00.checkCondition(FLAG(0x40, 0x82), 1) && FLAGS_00.checkCondition(FLAG(0x40, 0x83), 0)) {
            children[10] = FIELDSTG_startEvent(0x50E);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x2C
#include "common/start_stage.inc.c"
#include "common/step_animation.inc.c"
#include "common/draw_stage_effect.inc.c"
#include "common/is_on_screen.inc.c"
#include "common/update_stage_effect.inc.c"
#include "common/create_stage_effect.inc.c"

void func_800A53BC(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x82), 1);
    FLAGS_00.applyAction(EVENT_BATTLE(0), 1);
}

void func_800A5408(void) {
    FLAGS_00.applyAction(FLAG(0x40, 0x83), 1);
    FLAGS_00.applyAction(ITEM(1, 0x30), 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6BB
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6CA
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x12700, 0x24B00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x19;
    FIELDSTG_state.music = MUSIC(0x19, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

s16 script1293[] = {
    0x600, 1, 2,
    0x102, 2, 0x138, 0x25C, 3,
    0x100, 0xCB, 0x120, 0x251,
    0x101, 0xCB, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xCB, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xCB, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x1\n");
#endif
s16 script1294[] = {
    0x600, 1, 0xCB,
    0x100, 2, 0x138, 0x25C,
    0x101, 2, 1, 3,
    0x100, 0xCB, 0x120, 0x251,
    0x101, 0xCB, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0xCB, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x3C,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x101, 0xCB, 1, 5,
    0x300, 0x1E,
    0x102, 0xCB, 0x150, 0x239, 5,
    0x302, 0xCB,
    0x101, 0xCB, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x120, 0x251, 3,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0xCB, 0,
    0x301,
    0x600, 1, 2,
    0x300, 0x1E,
    0,
};
StageEffectSpot D_800A56BC[] = {
    { 36, 0, 0x14C, 0x264 },
    { 28, 0, 236, 0x1B4 },
    { 28, 0, 0x17C, 0x1CC },
    { 28, 0, 0x1BC, 0x28C },
    { 28, 0, 0x21C, 0x2BC },
    { 28, 0, 0x2AC, 0x2D4 },
    { 28, 0, 0x32C, 0x2F4 },
    { 28, 0, 0x38C, 0x2F4 },
    { 28, 0, 0x3FC, 0x2BC },
    { 20, 0, 0x3AC, 68 },
};
AnimFrame effectClutFrames[] = {
    { 0, 6 }, { 1, 6 }, { 2, 68 }, { 1, 4 },
    { 0, 4 }, { 255, 0 },
};
AnimFrame effectFrames[] = {
    { 0x12C, 18 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 4 }, { 6, 4 }, { 7, 4 },
    { 5, 4 }, { 6, 4 }, { 7, 4 }, { 5, 4 },
    { 6, 4 }, { 7, 4 }, { 5, 4 }, { 6, 4 },
    { 7, 4 }, { 4, 4 }, { 3, 4 }, { 2, 4 },
    { 1, 4 }, { 255, 0x3E7 },
};
Battle area0Battle0 = { 187, 25, MUSIC(2, 0) };
Battle area0Battle1 = { 187, 25, MUSIC(2, 0) };
Battle area0Battle2 = { 187, 25, MUSIC(2, 0) };
Battle area0Battle3 = { 187, 25, MUSIC(2, 0) };
Battle area0Battle4 = { 129, 25, MUSIC(2, 0) };
Battle area0Battle5 = { 129, 25, MUSIC(2, 0) };
Battle area0Battle6 = { 129, 25, MUSIC(2, 0) };
Battle area0Battle7 = { 129, 25, MUSIC(2, 0) };
BattleList area0Battles = {
    5,
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
Battle area3Battle0 = { 27, 25, MUSIC(0x23, 0) };
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
    { 120, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x146, 0x1B0, 0x18, 0xB0, 0x150, 0x1F6 },
    { 0x140, 0x100, 0x15E, 0x1A8, 0x78, 0xA8, 0x160, 0x1F6 },
    { 0x140, 0x100, 0x166, 0x1A8, 0x98, 0xA8, 0x170, 0x1F6 },
    { 0x140, 0x100, 0x16E, 0x1A8, 0xB8, 0xA8, 0x140, 0x1F5 },
    { 0x140, 0x100, 0x140, 0x1B0, 0, 0xB0, 0x160, 0x1F5 },
};
u16 actor0Talk0Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor0Talk1Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor0Talk2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor2Talk0Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor2Talk1Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor2Talk2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor8Talk0Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor8Talk1Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor8Talk2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor8Talk3Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor9Talk0Conditions[] = { SPECIAL(0x1D), 1, CODES_END };
u16 actor9Talk1Conditions[] = { PROGRESS(0x25), 1, CODES_END };
u16 actor9Talk2Conditions[] = { PROGRESS(0x26), 1, CODES_END };
u16 actor9Talk3Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { actor0Talk0Conditions, NULL, 0x207 },
    { actor0Talk1Conditions, NULL, 0x208 },
    { actor0Talk2Conditions, NULL, 0x209 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x20B },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, NULL, 0x20C },
    { actor2Talk1Conditions, NULL, 0x20D },
    { actor2Talk2Conditions, NULL, 0x20E },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x210 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { NULL, NULL, 0x20F },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x205 },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { NULL, NULL, 0x205 },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, NULL, 0x20A },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { actor8Talk0Conditions, NULL, 0x202 },
    { actor8Talk1Conditions, NULL, 0x203 },
    { actor8Talk2Conditions, NULL, 0x204 },
    { actor8Talk3Conditions, NULL, 0x206 },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { actor9Talk0Conditions, NULL, 0x202 },
    { actor9Talk1Conditions, NULL, 0x203 },
    { actor9Talk2Conditions, NULL, 0x204 },
    { actor9Talk3Conditions, NULL, 0x206 },
    { NULL, NULL, 0 },
};
u16 actor0Conditions[] = { SPECIAL(8), 1, SPECIAL(0x1A), 0, CODES_END };
u16 actor1Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor2Conditions[] = { SPECIAL(0x1E), 1, CODES_END };
u16 actor3Conditions[] = { PROGRESS(0x2B), 1, CODES_END };
u16 actor4Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor5Conditions[] = { FLAG(0x40, 0x83), 0, SPECIAL(0x1A), 1, CODES_END };
u16 actor6Conditions[] = { SPECIAL(0x1A), 1, FLAG(0x40, 0x83), 1, CODES_END };
u16 actor7Conditions[] = { SPECIAL(0x1A), 1, CODES_END };
u16 actor8Conditions[] = { SPECIAL(0x1A), 0, FLAG(0x40, 0x83), 1, SPECIAL(8), 1, CODES_END };
u16 actor9Conditions[] = { SPECIAL(8), 1, FLAG(0x40, 0x83), 0, SPECIAL(0x1A), 0, CODES_END };
FieldActorEntry actor0 = { actor0Conditions, actor0Talks, 0x2D, 4, 944, 233, 1 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x2D, 4, 944, 233, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x42, 5, 1041, 105, 3 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x42, 5, 1041, 105, 3 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x42, 5, 1041, 105, 3 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x9D, 6, 288, 593, 7 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x9D, 6, 336, 569, 1 };
FieldActorEntry actor7 = { actor7Conditions, actor7Talks, 0x9E, 7, 944, 233, 1 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0xCB, 8, 336, 569, 1 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0xCB, 8, 288, 593, 7 };
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 430, 326, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 443, 315, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 456, 288, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 458, 346, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 464, 275, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 494, 375, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 500, 402, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 555, 192, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 574, 190, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 698, 393, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 727, 379, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 778, 446, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 814, 430, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 872, 226, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 886, 236, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 909, 415, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 971, 387, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 996, 373, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 1022, 295, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 1036, 293, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 435, 329, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 446, 320, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 452, 282, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 462, 280, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 464, 350, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 497, 381, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 501, 395, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 548, 194, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 567, 186, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 573, 196, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 584, 253, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 691, 394, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 694, 361, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 699, 371, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 724, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 785, 443, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 817, 425, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 841, 435, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 848, 267, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 852, 465, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 875, 232, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 890, 242, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 915, 412, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 976, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 988, 346, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 991, 377, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 1014, 291, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 1034, 300, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2D0, 0x78, 0x144, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x2D3, 0x40C, 0x6E, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 5, 0x400, 0x80, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 5, 0x3F0, 0xD8, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 6, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 9, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 0xB, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D2, 0x140, 0x260, 3, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xD, 0x2D2, 0x3C0, 0x50, 7, 0, 0, 0 },
    { { { FLAG(0x40, 0x82), 0 }, { SPECIAL(0x1A), 0 } }, 8, 0x50D, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xB, 0, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0xC, 0, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1293, script1293, EVENT_TEXT(9), NULL, func_800A53BC },
    { 1294, script1294, EVENT_TEXT(0x14), NULL, func_800A5408 },
    { -1, NULL, 0, NULL, NULL },
};
