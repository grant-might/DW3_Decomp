#include "common.h"
#include "stage.h"
extern AnimFrame D_800A61A4[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A61A4[0].duration;
        break;
    case TASK_RUN:
        for (tile = FIELDSTG_state.objects; tile->unk2 != 0; tile++) {
            if (tile->anim == 1) {
                tile->frame = stepLoopingAnimation(&task->anims[0], D_800A61A4, 0);
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *createTileAnims(void) {
    return createTask(updateTileAnims, 0x54, 0);
}

/* Creates the stage's object (its second child) */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[1] = createTileAnims();
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x8
#include "common/start_stage.inc.c"

void setupStage(void) {
    FIELDSTG_state.textFile = LANGUAGE + 0x104;
    FIELDSTG_state.mapFile = 0x256;
    FIELDSTG_state.sheetEntry = 0x9230000;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = 0x922;
    FIELDSTG_state.start = (Vec2){0x16B00, 0x44400};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x2F;
    FIELDSTG_state.music = MUSIC(0x2F, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, 0x9230002);
    FIELDSTG_map.setFile(7, 0x9230003);
    FIELDSTG_map.setFile(4, 0x9230001);
    FIELDSTG_map.setFirstMap(0);
}

AnimFrame D_800A61A4[] = {
    { 50, 8 }, { 51, 4 }, { 52, 8 }, { 53, 4 },
    { 54, 8 }, { 55, 4 }, { 56, 8 }, { 57, 16 },
    { 58, 4 }, { 59, 8 }, { 60, 4 }, { 61, 8 },
    { 62, 8 }, { 63, 12 }, { 64, 20 }, { 65, 4 },
    { 66, 8 }, { 67, 4 }, { 68, 8 }, { 69, 8 },
    { 70, 8 }, { 71, 8 }, { 72, 8 }, { 73, 4 },
    { 74, 8 }, { 75, 4 }, { 76, 8 }, { 77, 8 },
    { 78, 8 }, { 79, 8 }, { 80, 8 }, { 81, 12 },
    { 82, 8 }, { 83, 30 }, { 255, 0 },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x19C, 0x148, 0x170, 0x48, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1AA, 0x120, 0x1A8, 0x20, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1B2, 0x120, 0x1C8, 0x20, 0x160, 0x1FE },
};
u16 actor2Talk0Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 0, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0), 0, CODES_END };
u16 actor2Talk1Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 1, CODES_END };
u16 actor2Talk1Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0x10), 0, FLAG(0, 0), 0, CODES_END };
u16 actor2Talk2Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 0), 0, CODES_END };
u16 actor2Talk2Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor2Talk3Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 0), 1, CODES_END };
u16 actor2Talk3Actions[] = { CARD_BATTLE(0x2F, 1), 1, CODES_END };
u16 actor3Talk0Conditions[] = { SPECIAL(0x96), 0, CODES_END };
u16 actor3Talk1Conditions[] = { SPECIAL(0x96), 1, FLAG(0x10, 0x10), 0, CODES_END };
u16 actor3Talk1Actions[] = { FLAG(0x10, 0x10), 1, EVENT_BATTLE(0), 1, CODES_END };
u16 actor3Talk2Conditions[] = { SPECIAL(0x96), 1, FLAG(0x10, 0x10), 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, NULL, 0x92 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x49 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, actor2Talk0Actions, 0x4B },
    { actor2Talk1Conditions, actor2Talk1Actions, 0x4C },
    { actor2Talk2Conditions, actor2Talk2Actions, 0x49 },
    { actor2Talk3Conditions, actor2Talk3Actions, 0x4A },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { actor3Talk0Conditions, NULL, 0x8F },
    { actor3Talk1Conditions, actor3Talk1Actions, 0x90 },
    { actor3Talk2Conditions, NULL, 0x91 },
    { NULL, NULL, 0 },
};
u16 actor1Conditions[] = { ITEM(0, 0x192), 0, CODES_END };
u16 actor2Conditions[] = { ITEM(0, 0x192), 1, CODES_END };
FieldActorEntry actor0 = { NULL, actor0Talks, 0x2D, 4, 764, 1138, 5 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x38, 5, 976, 632, 1 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x38, 5, 976, 632, 1 };
FieldActorEntry actor3 = { NULL, actor3Talks, 0x92, 6, 924, 323, 1 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 1, 0xE6, 2, 0x32, 0, 0, 0, 0, 0, 966, 364, 0, 0 },
    { 1, 0, 0x40, 2, 0x54, 2, 0, 2, 6, 0, 931, 293, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 179, 400, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 602, 1071, 0, 0 },
    { 1, 0, 0xC8, 6, 7, 0, 0, 0, 0, 0, 745, 598, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 298, 442, 505, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x299, 0x648, 0xD0, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 8, 0xF0, 0x4D8, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 8, 0x100, 0x450, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 9, 0x102, 0x420, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 9, 0xF2, 0x388, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 6, 0x1D2, 0x4C8, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 6, 0x1C2, 0x460, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 0xF, 0x1AF, 0x428, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 0xF, 0x1BF, 0x330, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 4, 0x16, 0, 0, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 2, 9, 0x330, 0x208, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 3, 9, 0x340, 0x170, 0, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle area0Battle0 = { 50, 4, MUSIC(2, 0) };
Battle area0Battle1 = { 50, 4, MUSIC(2, 0) };
Battle area0Battle2 = { 130, 4, MUSIC(2, 0) };
Battle area0Battle3 = { 130, 4, MUSIC(2, 0) };
Battle area0Battle4 = { 131, 4, MUSIC(2, 0) };
Battle area0Battle5 = { 131, 4, MUSIC(2, 0) };
Battle area0Battle6 = { 134, 4, MUSIC(2, 0) };
Battle area0Battle7 = { 134, 4, MUSIC(2, 0) };
BattleList area0Battles = {
    3,
    { &area0Battle0, &area0Battle1, &area0Battle2, &area0Battle3,
      &area0Battle4, &area0Battle5, &area0Battle6, &area0Battle7 },
};
Battle area1Battle0 = { 100, 4, MUSIC(2, 0) };
Battle area1Battle1 = { 100, 4, MUSIC(2, 0) };
Battle area1Battle2 = { 100, 4, MUSIC(2, 0) };
Battle area1Battle3 = { 100, 4, MUSIC(2, 0) };
Battle area1Battle4 = { 100, 4, MUSIC(2, 0) };
Battle area1Battle5 = { 100, 4, MUSIC(2, 0) };
Battle area1Battle6 = { 100, 4, MUSIC(2, 0) };
Battle area1Battle7 = { 100, 4, MUSIC(2, 0) };
BattleList area1Battles = {
    5,
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
Battle area3Battle0 = { 308, 18, MUSIC(0x23, 0) };
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
    { 391, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
