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
        tile = D_800990B4.objects;
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
        copyPlacePoints(D_800990B4.slots, placePoints, GAME.unk44, GAME.unk46);
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
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1F400, 0x32000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x38;
    D_800990B4.music = 0x60E00000;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A52A8;
extern StagePoint D_800A52B8;
extern StagePoint D_800A52C8;
extern StagePoint D_800A52D8;
extern StagePoint D_800A52F0;
extern StagePoint D_800A5300;
extern StagePoint D_800A5310;
extern StagePoint D_800A5320;
extern StagePoint D_800A5338;
extern StagePoint D_800A5348;
extern StagePoint D_800A5358;
extern StagePoint D_800A5368;
extern StagePoint D_800A5380;
extern StagePoint D_800A5390;
extern StagePoint D_800A53A0;
extern StagePoint D_800A53B0;
extern StagePoint D_800A53C8;
extern StagePoint D_800A53D8;
extern StagePoint D_800A53E8;
extern StagePoint D_800A53F8;
extern StagePoint D_800A5410;
extern StagePoint D_800A5420;
extern StagePoint D_800A5430;
extern StagePoint D_800A5440;
extern StagePoint D_800A5458;
extern StagePoint D_800A5468;
extern StagePoint D_800A5478;
extern StagePoint D_800A5488;
extern StagePoint D_800A54A0;
extern StagePoint D_800A54B0;
extern StagePoint D_800A54C0;
extern StagePoint D_800A54D0;
extern StagePoints D_800A52E8;
extern StagePoints D_800A5330;
extern StagePoints D_800A5378;
extern StagePoints D_800A53C0;
extern StagePoints D_800A5408;
extern StagePoints D_800A5450;
extern StagePoints D_800A5498;
extern StagePoints D_800A54E0;
extern StagePoints D_800A54E8;
extern Battle D_800A5518;
extern Battle D_800A5524;
extern Battle D_800A5530;
extern Battle D_800A553C;
extern Battle D_800A5548;
extern Battle D_800A5554;
extern Battle D_800A5560;
extern Battle D_800A556C;
extern Battle D_800A559C;
extern Battle D_800A55A8;
extern Battle D_800A55B4;
extern Battle D_800A55C0;
extern Battle D_800A55CC;
extern Battle D_800A55D8;
extern Battle D_800A55E4;
extern Battle D_800A55F0;
extern Battle D_800A5620;
extern Battle D_800A562C;
extern Battle D_800A5638;
extern Battle D_800A5644;
extern Battle D_800A5650;
extern Battle D_800A565C;
extern Battle D_800A5668;
extern Battle D_800A5674;
extern Battle D_800A56A4;
extern Battle D_800A56B0;
extern Battle D_800A56BC;
extern Battle D_800A56C8;
extern Battle D_800A56D4;
extern Battle D_800A56E0;
extern Battle D_800A56EC;
extern Battle D_800A56F8;
extern BattleList D_800A5578;
extern BattleList D_800A55FC;
extern BattleList D_800A5680;
extern BattleList D_800A5704;

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
StagePoints D_800A52E8 = { 1, 1, &D_800A52D8 };
StagePoint D_800A52F0 = { 0x258, 1, 2, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A5300 = { 0x258, 1, 4, 0x340, 240, 1, &D_800A52F0 };
StagePoint D_800A5310 = { 0x258, 1, 1, 0x110, 0x108, 7, &D_800A5300 };
StagePoint D_800A5320 = { 0x257, 0, 0, 0x100, 0x278, 5, &D_800A5310 };
StagePoints D_800A5330 = { 1, 2, &D_800A5320 };
StagePoint D_800A5338 = { 0x258, 1, 4, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A5348 = { 0x258, 1, 5, 0x340, 240, 1, &D_800A5338 };
StagePoint D_800A5358 = { 0x258, 1, 3, 0x110, 0x108, 7, &D_800A5348 };
StagePoint D_800A5368 = { 0x258, 1, 1, 0x128, 0x2F4, 5, &D_800A5358 };
StagePoints D_800A5378 = { 1, 3, &D_800A5368 };
StagePoint D_800A5380 = { 0x258, 1, 3, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A5390 = { 0x258, 1, 6, 0x340, 240, 1, &D_800A5380 };
StagePoint D_800A53A0 = { 0x258, 1, 4, 0x110, 0x108, 7, &D_800A5390 };
StagePoint D_800A53B0 = { 0x258, 1, 2, 0x128, 0x2F4, 5, &D_800A53A0 };
StagePoints D_800A53C0 = { 1, 4, &D_800A53B0 };
StagePoint D_800A53C8 = { 0x258, 1, 5, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A53D8 = { 0x258, 1, 7, 0x340, 240, 1, &D_800A53C8 };
StagePoint D_800A53E8 = { 0x258, 1, 6, 0x110, 0x108, 7, &D_800A53D8 };
StagePoint D_800A53F8 = { 0x258, 1, 3, 0x128, 0x2F4, 5, &D_800A53E8 };
StagePoints D_800A5408 = { 1, 5, &D_800A53F8 };
StagePoint D_800A5410 = { 0x258, 1, 6, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A5420 = { 0x258, 1, 8, 0x340, 240, 1, &D_800A5410 };
StagePoint D_800A5430 = { 0x258, 1, 5, 0x110, 0x108, 7, &D_800A5420 };
StagePoint D_800A5440 = { 0x258, 1, 4, 0x128, 0x2F4, 5, &D_800A5430 };
StagePoints D_800A5450 = { 1, 6, &D_800A5440 };
StagePoint D_800A5458 = { 0x258, 1, 8, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A5468 = { 0x258, 1, 1, 0x340, 240, 1, &D_800A5458 };
StagePoint D_800A5478 = { 0x258, 1, 7, 0x110, 0x108, 7, &D_800A5468 };
StagePoint D_800A5488 = { 0x258, 1, 5, 0x128, 0x2F4, 5, &D_800A5478 };
StagePoints D_800A5498 = { 1, 7, &D_800A5488 };
StagePoint D_800A54A0 = { 0x258, 1, 7, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A54B0 = { 0x258, 1, 2, 0x340, 240, 1, &D_800A54A0 };
StagePoint D_800A54C0 = { 0x258, 1, 8, 0x110, 0x108, 7, &D_800A54B0 };
StagePoint D_800A54D0 = { 0x258, 1, 6, 0x128, 0x2F4, 5, &D_800A54C0 };
StagePoints D_800A54E0 = { 1, 8, &D_800A54D0 };
StagePoints D_800A54E8 = { 0, 0, &D_800A52D8 };
StagePoints *placePoints[] = {
    &D_800A52E8, &D_800A5330, &D_800A5378, &D_800A53C0,
    &D_800A5408, &D_800A5450, &D_800A5498, &D_800A54E0,
    &D_800A54E8, NULL,
};
Battle D_800A5518 = { 73, 5, 0x60080000 };
Battle D_800A5524 = { 73, 5, 0x60080000 };
Battle D_800A5530 = { 73, 5, 0x60080000 };
Battle D_800A553C = { 74, 5, 0x60080000 };
Battle D_800A5548 = { 74, 5, 0x60080000 };
Battle D_800A5554 = { 74, 5, 0x60080000 };
Battle D_800A5560 = { 156, 5, 0x60080000 };
Battle D_800A556C = { 156, 5, 0x60080000 };
BattleList D_800A5578 = {
    3,
    { &D_800A5518, &D_800A5524, &D_800A5530, &D_800A553C,
      &D_800A5548, &D_800A5554, &D_800A5560, &D_800A556C },
};
Battle D_800A559C = { 0, 0, 0x60040000 };
Battle D_800A55A8 = { 0, 0, 0x60040000 };
Battle D_800A55B4 = { 0, 0, 0x60040000 };
Battle D_800A55C0 = { 0, 0, 0x60040000 };
Battle D_800A55CC = { 0, 0, 0x60040000 };
Battle D_800A55D8 = { 0, 0, 0x60040000 };
Battle D_800A55E4 = { 0, 0, 0x60040000 };
Battle D_800A55F0 = { 0, 0, 0x60040000 };
BattleList D_800A55FC = {
    0,
    { &D_800A559C, &D_800A55A8, &D_800A55B4, &D_800A55C0,
      &D_800A55CC, &D_800A55D8, &D_800A55E4, &D_800A55F0 },
};
Battle D_800A5620 = { 0, 0, 0x60040000 };
Battle D_800A562C = { 0, 0, 0x60040000 };
Battle D_800A5638 = { 0, 0, 0x60040000 };
Battle D_800A5644 = { 0, 0, 0x60040000 };
Battle D_800A5650 = { 0, 0, 0x60040000 };
Battle D_800A565C = { 0, 0, 0x60040000 };
Battle D_800A5668 = { 0, 0, 0x60040000 };
Battle D_800A5674 = { 0, 0, 0x60040000 };
BattleList D_800A5680 = {
    0,
    { &D_800A5620, &D_800A562C, &D_800A5638, &D_800A5644,
      &D_800A5650, &D_800A565C, &D_800A5668, &D_800A5674 },
};
Battle D_800A56A4 = { 0, 0, 0x60040000 };
Battle D_800A56B0 = { 0, 0, 0x60040000 };
Battle D_800A56BC = { 0, 0, 0x60040000 };
Battle D_800A56C8 = { 0, 0, 0x60040000 };
Battle D_800A56D4 = { 0, 0, 0x60040000 };
Battle D_800A56E0 = { 0, 0, 0x60040000 };
Battle D_800A56EC = { 0, 0, 0x60040000 };
Battle D_800A56F8 = { 0, 0, 0x60040000 };
BattleList D_800A5704 = {
    0,
    { &D_800A56A4, &D_800A56B0, &D_800A56BC, &D_800A56C8,
      &D_800A56D4, &D_800A56E0, &D_800A56EC, &D_800A56F8 },
};
FieldBattles stageBattles[] = {
    { 38, 0, 0, { &D_800A5578, &D_800A55FC, &D_800A5680, &D_800A5704 } },
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x259, 0x358, 0xFC, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x259, 0x350, 0x2F8, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x259, 0x118, 0x2EC, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x259, 0x120, 0x100, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
