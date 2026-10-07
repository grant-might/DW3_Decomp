#include "common.h"
#include "stage.h"
extern AnimFrame D_800A5210[];
extern AnimFrame D_800A5244[];
extern AnimFrame D_800A5278[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    s32 frames[3];
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A5210[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A5244[0].duration;
        task->anims[2].index = 0;
        task->anims[2].timer = D_800A5278[0].duration;
        break;
    case TASK_RUN:
        tile = FIELDSTG_state.objects;
        frames[0] = stepLoopingAnimation(&task->anims[0], D_800A5210, 0);
        frames[1] = stepLoopingAnimation(&task->anims[1], D_800A5244, 0);
        frames[2] = stepLoopingAnimation(&task->anims[2], D_800A5278, 0);
        for (; tile->unk2 != 0; tile++) {
            switch (tile->anim) {
            case 1:
                tile->frame = frames[0];
                break;
            case 2:
                tile->frame = frames[1];
                break;
            case 3:
                tile->frame = frames[2];
                break;
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *createTileAnims(void) {
    return createTask(updateTileAnims, 0x5C, 0);
}

#include "common/copy_place_points.inc.c"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = createTileAnims();
        copyPlacePoints(FIELDSTG_state.slots, placePoints, GAME.place, GAME.placeArg);
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

#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x490
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x4A0
#endif
void setupStage(void) {
    FIELDSTG_state.textFile = STAGE_TEXT;
    FIELDSTG_state.mapFile = STAGE_FILE - 1;
    FIELDSTG_state.sheetEntry = STAGE_FILE << 16;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = STAGE_FILE - 2;
    FIELDSTG_state.start = (Vec2){0x1F400, 0x32000};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 0x38;
    FIELDSTG_state.music = MUSIC(0x38, 0);
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.battles = stageBattles;
    FIELDSTG_map.setFile(0, STAGE_FILE << 16 | 1);
    FIELDSTG_map.setFile(7, STAGE_FILE << 16 | 2);
    FIELDSTG_map.setFile(4, STAGE_FILE << 16 | 3);
    FIELDSTG_map.setFirstMap(0);
}

AnimFrame D_800A5210[] = {
    { 50, 8 }, { 51, 8 }, { 52, 8 }, { 53, 8 },
    { 54, 8 }, { 55, 8 }, { 56, 8 }, { 57, 8 },
    { 58, 8 }, { 59, 8 }, { 60, 8 }, { 82, 160 },
    { 255, 0 },
};
AnimFrame D_800A5244[] = {
    { 61, 8 }, { 62, 8 }, { 63, 8 }, { 64, 8 },
    { 65, 8 }, { 66, 8 }, { 67, 8 }, { 68, 8 },
    { 69, 8 }, { 70, 8 }, { 71, 8 }, { 82, 160 },
    { 255, 0 },
};
AnimFrame D_800A5278[] = {
    { 72, 8 }, { 73, 8 }, { 74, 8 }, { 75, 8 },
    { 76, 8 }, { 77, 8 }, { 78, 8 }, { 79, 8 },
    { 80, 8 }, { 81, 8 }, { 82, 160 }, { 255, 0 },
};
StagePoint D_800A52A8 = { 0x258, 1, 1, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A52B8 = { 0x258, 1, 3, 0x340, 240, 1, &D_800A52A8 };
StagePoint D_800A52C8 = { 0x258, 1, 2, 0x110, 0x108, 7, &D_800A52B8 };
StagePoint D_800A52D8 = { 0x257, 0, 0, 0x100, 0x278, 5, &D_800A52C8 };
StagePoints placePoints1_1 = { 1, 1, &D_800A52D8 };
StagePoint placePoints1_2Point3 = { 0x258, 1, 2, 0x368, 0x2EC, 3, NULL };
StagePoint placePoints1_2Point2 = { 0x258, 1, 4, 0x340, 240, 1, &placePoints1_2Point3 };
StagePoint placePoints1_2Point1 = { 0x258, 1, 1, 0x110, 0x108, 7, &placePoints1_2Point2 };
StagePoint placePoints1_2Point0 = { 0x257, 0, 0, 0x100, 0x278, 5, &placePoints1_2Point1 };
StagePoints placePoints1_2 = { 1, 2, &placePoints1_2Point0 };
StagePoint placePoints1_3Point3 = { 0x258, 1, 4, 0x368, 0x2EC, 3, NULL };
StagePoint placePoints1_3Point2 = { 0x258, 1, 5, 0x340, 240, 1, &placePoints1_3Point3 };
StagePoint placePoints1_3Point1 = { 0x258, 1, 3, 0x110, 0x108, 7, &placePoints1_3Point2 };
StagePoint placePoints1_3Point0 = { 0x258, 1, 1, 0x128, 0x2F4, 5, &placePoints1_3Point1 };
StagePoints placePoints1_3 = { 1, 3, &placePoints1_3Point0 };
StagePoint placePoints1_4Point3 = { 0x258, 1, 3, 0x368, 0x2EC, 3, NULL };
StagePoint placePoints1_4Point2 = { 0x258, 1, 6, 0x340, 240, 1, &placePoints1_4Point3 };
StagePoint placePoints1_4Point1 = { 0x258, 1, 4, 0x110, 0x108, 7, &placePoints1_4Point2 };
StagePoint placePoints1_4Point0 = { 0x258, 1, 2, 0x128, 0x2F4, 5, &placePoints1_4Point1 };
StagePoints placePoints1_4 = { 1, 4, &placePoints1_4Point0 };
StagePoint placePoints1_5Point3 = { 0x258, 1, 5, 0x368, 0x2EC, 3, NULL };
StagePoint placePoints1_5Point2 = { 0x258, 1, 7, 0x340, 240, 1, &placePoints1_5Point3 };
StagePoint placePoints1_5Point1 = { 0x258, 1, 6, 0x110, 0x108, 7, &placePoints1_5Point2 };
StagePoint placePoints1_5Point0 = { 0x258, 1, 3, 0x128, 0x2F4, 5, &placePoints1_5Point1 };
StagePoints placePoints1_5 = { 1, 5, &placePoints1_5Point0 };
StagePoint placePoints1_6Point3 = { 0x258, 1, 6, 0x368, 0x2EC, 3, NULL };
StagePoint placePoints1_6Point2 = { 0x258, 1, 8, 0x340, 240, 1, &placePoints1_6Point3 };
StagePoint placePoints1_6Point1 = { 0x258, 1, 5, 0x110, 0x108, 7, &placePoints1_6Point2 };
StagePoint placePoints1_6Point0 = { 0x258, 1, 4, 0x128, 0x2F4, 5, &placePoints1_6Point1 };
StagePoints placePoints1_6 = { 1, 6, &placePoints1_6Point0 };
StagePoint placePoints1_7Point3 = { 0x258, 1, 8, 0x368, 0x2EC, 3, NULL };
StagePoint placePoints1_7Point2 = { 0x258, 1, 1, 0x340, 240, 1, &placePoints1_7Point3 };
StagePoint placePoints1_7Point1 = { 0x258, 1, 7, 0x110, 0x108, 7, &placePoints1_7Point2 };
StagePoint placePoints1_7Point0 = { 0x258, 1, 5, 0x128, 0x2F4, 5, &placePoints1_7Point1 };
StagePoints placePoints1_7 = { 1, 7, &placePoints1_7Point0 };
StagePoint placePoints1_8Point3 = { 0x258, 1, 7, 0x368, 0x2EC, 3, NULL };
StagePoint placePoints1_8Point2 = { 0x258, 1, 2, 0x340, 240, 1, &placePoints1_8Point3 };
StagePoint placePoints1_8Point1 = { 0x258, 1, 8, 0x110, 0x108, 7, &placePoints1_8Point2 };
StagePoint placePoints1_8Point0 = { 0x258, 1, 6, 0x128, 0x2F4, 5, &placePoints1_8Point1 };
StagePoints placePoints1_8 = { 1, 8, &placePoints1_8Point0 };
StagePoints placePoints0_0 = { 0, 0, &D_800A52D8 };
StagePoints *placePoints[] = {
    &placePoints1_1, &placePoints1_2, &placePoints1_3, &placePoints1_4,
    &placePoints1_5, &placePoints1_6, &placePoints1_7, &placePoints1_8,
    &placePoints0_0, NULL,
};
Battle area0Battle0 = { 73, 5, MUSIC(2, 0) };
Battle area0Battle1 = { 73, 5, MUSIC(2, 0) };
Battle area0Battle2 = { 73, 5, MUSIC(2, 0) };
Battle area0Battle3 = { 74, 5, MUSIC(2, 0) };
Battle area0Battle4 = { 74, 5, MUSIC(2, 0) };
Battle area0Battle5 = { 74, 5, MUSIC(2, 0) };
Battle area0Battle6 = { 156, 5, MUSIC(2, 0) };
Battle area0Battle7 = { 156, 5, MUSIC(2, 0) };
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
    { 38, 0, 0, { &area0Battles, &area1Battles, &area2Battles, &area3Battles } },
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
    { 1, 3, 0xC8, 2, 0x48, 0, 0, 0, 0, 0, 384, 97, 0, 0 },
    { 1, 3, 0xC8, 2, 0x48, 0, 0, 0, 0, 0, 384, 871, 0, 0 },
    { 1, 3, 0xC8, 2, 0x48, 0, 0, 0, 0, 0, 916, 384, 0, 0 },
    { 1, 0, 0x40, 2, 8, 1, 8, 0xD, 4, 0, 328, 532, 0, 0 },
    { 1, 0, 0x40, 2, 8, 1, 8, 0xD, 4, 0, 375, 220, 0, 0 },
    { 1, 0, 0x40, 2, 8, 1, 8, 0xD, 4, 0, 519, 660, 0, 0 },
    { 1, 0, 0x40, 2, 8, 1, 8, 0xD, 4, 0, 536, 283, 0, 0 },
    { 1, 0, 0x40, 2, 8, 1, 8, 0xD, 4, 0, 583, 454, 0, 0 },
    { 1, 0, 0x40, 2, 8, 1, 8, 0xD, 4, 0, 711, 612, 0, 0 },
    { 1, 0, 0x40, 2, 8, 1, 8, 0xD, 4, 0, 728, 267, 0, 0 },
    { 1, 0, 0x40, 2, 8, 1, 8, 0xD, 4, 0, 791, 460, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 166, 937, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 171, 489, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 184, 363, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 335, 801, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 933, 296, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 968, 498, 0, 0 },
    { 1, 0, 0x60, 4, 0, 0, 0, 0, 0, 0, 724, 631, 721, 0 },
    { 1, 0, 0x60, 4, 1, 0, 0, 0, 0, 0, 532, 679, 769, 0 },
    { 1, 0, 0x60, 4, 2, 0, 0, 0, 0, 0, 340, 551, 641, 0 },
    { 1, 0, 0x60, 4, 3, 0, 0, 0, 0, 0, 804, 479, 569, 0 },
    { 1, 0, 0x60, 4, 4, 0, 0, 0, 0, 0, 596, 471, 562, 0 },
    { 1, 0, 0x60, 4, 5, 0, 0, 0, 0, 0, 740, 287, 378, 0 },
    { 1, 0, 0x60, 4, 6, 0, 0, 0, 0, 0, 548, 303, 393, 0 },
    { 1, 0, 0x60, 4, 7, 0, 0, 0, 0, 0, 388, 239, 329, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x259, 0x358, 0xFC, 5, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x259, 0x350, 0x2F8, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x259, 0x118, 0x2EC, 1, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x259, 0x120, 0x100, 3, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
