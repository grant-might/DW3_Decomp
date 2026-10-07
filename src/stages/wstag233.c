#include "common.h"
#include "stage.h"
extern AnimFrame D_800A5084[];
extern AnimFrame D_800A50D4[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A5084[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A50D4[0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        for (tile = FIELDSTG_state.objects; tile->unk2 != 0; tile++) {
            if (tile->anim == 1) {
                tile->frame = stepLoopingAnimation(&task->anims[0], D_800A5084, 0);
            }
            if (tile->anim == 2) {
                tile->frame = stepLoopingAnimation(&task->anims[1], D_800A50D4, 0);
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *createTileAnims(void) {
    return createTask(updateTileAnims, 0x58, 0);
}

#include "common/update_stage_tile_anims.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x4CC
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x4DC
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x11100, 0x12D00};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 5;
    FIELDSTG_state.music = MUSIC(5, 0);
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFirstMap(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(FLAG(0x1A, 0xA), 0) != 0) {
        FIELDSTG_state.soundBank = 0x1F;
        FIELDSTG_state.music = MUSIC(0x1F, 0);
    }
}

AnimFrame D_800A5084[] = {
    { 50, 18 }, { 44, 6 }, { 50, 60 }, { 44, 6 },
    { 45, 6 }, { 46, 6 }, { 44, 6 }, { 51, 78 },
    { 44, 6 }, { 45, 6 }, { 46, 6 }, { 44, 6 },
    { 52, 60 }, { 44, 6 }, { 52, 18 }, { 44, 6 },
    { 45, 6 }, { 46, 6 }, { 44, 6 }, { 255, 0 },
};
AnimFrame D_800A50D4[] = {
    { 56, 60 }, { 47, 6 }, { 56, 18 }, { 47, 6 },
    { 48, 6 }, { 49, 6 }, { 47, 6 }, { 57, 78 },
    { 47, 6 }, { 48, 6 }, { 49, 6 }, { 47, 6 },
    { 58, 18 }, { 47, 6 }, { 58, 60 }, { 47, 6 },
    { 48, 6 }, { 49, 6 }, { 47, 6 }, { 255, 0 },
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
Battle area3Battle0 = { 258, 20, MUSIC(3, 0) };
Battle area3Battle1 = { 259, 20, MUSIC(3, 0) };
Battle area3Battle2 = { 260, 20, MUSIC(3, 0) };
Battle area3Battle3 = { 261, 20, MUSIC(3, 0) };
Battle area3Battle4 = { 262, 20, MUSIC(0x23, 0) };
Battle area3Battle5 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle6 = { 0, 0, MUSIC(1, 0) };
Battle area3Battle7 = { 0, 0, MUSIC(1, 0) };
BattleList area3Battles = {
    0,
    { &area3Battle0, &area3Battle1, &area3Battle2, &area3Battle3,
      &area3Battle4, &area3Battle5, &area3Battle6, &area3Battle7 },
};
FieldBattles stageBattles[] = {
    { 171, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x41, 2, 0, 5, 8, 0, 350, 180, 0, 0 },
    { 1, 0, 0x40, 2, 0x45, 2, 0, 5, 8, 0, 314, 180, 0, 0 },
    { 1, 2, 0x58, 2, 0x38, 0, 0, 0, 0, 0, 229, 79, 0, 0 },
    { 1, 1, 0x58, 2, 0x32, 0, 0, 0, 0, 0, 395, 79, 0, 0 },
    { 1, 0, 0x40, 2, 0x3E, 1, 0x3E, 0x40, 8, 0, 354, 185, 0, 0 },
    { 1, 0, 0x40, 2, 0x42, 1, 0x42, 0x44, 8, 0, 318, 185, 0, 0 },
    { 1, 0, 0x40, 2, 0x46, 2, 0, 3, 4, 0, 206, 186, 0, 0 },
    { 1, 0, 0x40, 2, 0x46, 2, 0, 3, 4, 0, 370, 138, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 4, 0, 238, 170, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 4, 0, 402, 154, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 3, 4, 0, 270, 154, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 3, 4, 0, 434, 170, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 3, 4, 0, 302, 138, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 3, 4, 0, 466, 186, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 6, 0, 387, 77, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 5, 6, 0, 395, 79, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 5, 6, 0, 229, 77, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 5, 6, 0, 229, 79, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
