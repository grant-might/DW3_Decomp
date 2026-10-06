#include "common.h"
#include "stage.h"
extern AnimFrame D_800A50EC[];
extern AnimFrame D_800A5120[];
extern AnimFrame D_800A5154[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    s32 frames[3];
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A50EC[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A5120[0].duration;
        task->anims[2].index = 0;
        task->anims[2].timer = D_800A5154[0].duration;
        break;
    case TASK_RUN:
        tile = D_800990B4.objects;
        frames[0] = stepLoopingAnimation(&task->anims[0], D_800A50EC, 0);
        frames[1] = stepLoopingAnimation(&task->anims[1], D_800A5120, 0);
        frames[2] = stepLoopingAnimation(&task->anims[2], D_800A5154, 0);
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

#include "common/update_stage_tile_anims.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x498
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x4A8
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x18C00, 0x22D00};
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

extern Battle D_800A5184;
extern Battle D_800A5190;
extern Battle D_800A519C;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A5208;
extern Battle D_800A5214;
extern Battle D_800A5220;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A528C;
extern Battle D_800A5298;
extern Battle D_800A52A4;
extern Battle D_800A52B0;
extern Battle D_800A52BC;
extern Battle D_800A52C8;
extern Battle D_800A52D4;
extern Battle D_800A52E0;
extern Battle D_800A5310;
extern Battle D_800A531C;
extern Battle D_800A5328;
extern Battle D_800A5334;
extern Battle D_800A5340;
extern Battle D_800A534C;
extern Battle D_800A5358;
extern Battle D_800A5364;
extern BattleList D_800A51E4;
extern BattleList D_800A5268;
extern BattleList D_800A52EC;
extern BattleList D_800A5370;

AnimFrame D_800A50EC[] = {
    { 50, 8 }, { 51, 8 }, { 52, 8 }, { 53, 8 },
    { 54, 8 }, { 55, 8 }, { 56, 8 }, { 57, 8 },
    { 58, 8 }, { 59, 8 }, { 60, 8 }, { 82, 160 },
    { 255, 0 },
};
AnimFrame D_800A5120[] = {
    { 61, 8 }, { 62, 8 }, { 63, 8 }, { 64, 8 },
    { 65, 8 }, { 66, 8 }, { 67, 8 }, { 68, 8 },
    { 69, 8 }, { 70, 8 }, { 71, 8 }, { 82, 160 },
    { 255, 0 },
};
AnimFrame D_800A5154[] = {
    { 72, 8 }, { 73, 8 }, { 74, 8 }, { 75, 8 },
    { 76, 8 }, { 77, 8 }, { 78, 8 }, { 79, 8 },
    { 80, 8 }, { 81, 8 }, { 82, 160 }, { 255, 0 },
};
Battle D_800A5184 = { 156, 5, 0x60080000 };
Battle D_800A5190 = { 156, 5, 0x60080000 };
Battle D_800A519C = { 156, 5, 0x60080000 };
Battle D_800A51A8 = { 156, 5, 0x60080000 };
Battle D_800A51B4 = { 156, 5, 0x60080000 };
Battle D_800A51C0 = { 156, 5, 0x60080000 };
Battle D_800A51CC = { 156, 5, 0x60080000 };
Battle D_800A51D8 = { 156, 5, 0x60080000 };
BattleList D_800A51E4 = {
    3,
    { &D_800A5184, &D_800A5190, &D_800A519C, &D_800A51A8,
      &D_800A51B4, &D_800A51C0, &D_800A51CC, &D_800A51D8 },
};
Battle D_800A5208 = { 0, 0, 0x60040000 };
Battle D_800A5214 = { 0, 0, 0x60040000 };
Battle D_800A5220 = { 0, 0, 0x60040000 };
Battle D_800A522C = { 0, 0, 0x60040000 };
Battle D_800A5238 = { 0, 0, 0x60040000 };
Battle D_800A5244 = { 0, 0, 0x60040000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
BattleList D_800A5268 = {
    0,
    { &D_800A5208, &D_800A5214, &D_800A5220, &D_800A522C,
      &D_800A5238, &D_800A5244, &D_800A5250, &D_800A525C },
};
Battle D_800A528C = { 0, 0, 0x60040000 };
Battle D_800A5298 = { 0, 0, 0x60040000 };
Battle D_800A52A4 = { 0, 0, 0x60040000 };
Battle D_800A52B0 = { 0, 0, 0x60040000 };
Battle D_800A52BC = { 0, 0, 0x60040000 };
Battle D_800A52C8 = { 0, 0, 0x60040000 };
Battle D_800A52D4 = { 0, 0, 0x60040000 };
Battle D_800A52E0 = { 0, 0, 0x60040000 };
BattleList D_800A52EC = {
    0,
    { &D_800A528C, &D_800A5298, &D_800A52A4, &D_800A52B0,
      &D_800A52BC, &D_800A52C8, &D_800A52D4, &D_800A52E0 },
};
Battle D_800A5310 = { 0, 0, 0x60040000 };
Battle D_800A531C = { 0, 0, 0x60040000 };
Battle D_800A5328 = { 0, 0, 0x60040000 };
Battle D_800A5334 = { 0, 0, 0x60040000 };
Battle D_800A5340 = { 0, 0, 0x60040000 };
Battle D_800A534C = { 0, 0, 0x60040000 };
Battle D_800A5358 = { 0, 0, 0x60040000 };
Battle D_800A5364 = { 0, 0, 0x60040000 };
BattleList D_800A5370 = {
    0,
    { &D_800A5310, &D_800A531C, &D_800A5328, &D_800A5334,
      &D_800A5340, &D_800A534C, &D_800A5358, &D_800A5364 },
};
FieldBattles stageBattles[] = {
    { 39, 0, 0, { &D_800A51E4, &D_800A5268, &D_800A52EC, &D_800A5370 } },
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
    { 1, 3, 0xC8, 2, 0x48, 0, 0, 0, 0, 0, 59, 435, 0, 0 },
    { 1, 3, 0xC8, 2, 0x48, 0, 0, 0, 0, 0, 384, 640, 0, 0 },
    { 1, 3, 0xC8, 2, 0x48, 0, 0, 0, 0, 0, 606, 469, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 260, 441, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 394, 596, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 569, 465, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 706, 596, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 858, 657, 0, 0 },
    { 1, 0, 0x40, 6, 4, 0, 0, 0, 0, 0, 562, 254, 0, 0 },
    { 1, 0, 0x40, 4, 0x53, 2, 0, 0xF, 8, 0, 604, 194, 256, 0 },
    { 1, 0, 0x40, 4, 0x54, 2, 0, 0xF, 8, 0, 604, 194, 252, 0 },
    { 1, 0, 0x40, 4, 0x55, 2, 0, 0xF, 8, 0, 604, 194, 248, 0 },
    { 1, 0, 0x40, 4, 0x56, 2, 0, 0xF, 8, 0, 604, 194, 244, 0 },
    { 1, 0, 0x40, 4, 0x57, 2, 0, 0xF, 8, 0, 604, 194, 240, 0 },
    { 1, 0, 0x40, 4, 0x58, 2, 0, 0xF, 8, 0, 604, 194, 236, 0 },
    { 1, 0, 0x40, 4, 0x59, 2, 0, 0xF, 8, 0, 604, 194, 232, 0 },
    { 1, 0, 0x40, 4, 0x5A, 2, 0, 0xF, 8, 0, 604, 194, 228, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 566, 208, 264, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x25B, 0x27A, 0x256, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x258, 0x110, 0x108, 7, 0, 1, 6 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
