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
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
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
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x11100, 0x12D00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A5124;
extern Battle D_800A5130;
extern Battle D_800A513C;
extern Battle D_800A5148;
extern Battle D_800A5154;
extern Battle D_800A5160;
extern Battle D_800A516C;
extern Battle D_800A5178;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A51F0;
extern Battle D_800A51FC;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5274;
extern Battle D_800A5280;
extern Battle D_800A52B0;
extern Battle D_800A52BC;
extern Battle D_800A52C8;
extern Battle D_800A52D4;
extern Battle D_800A52E0;
extern Battle D_800A52EC;
extern Battle D_800A52F8;
extern Battle D_800A5304;
extern BattleList D_800A5184;
extern BattleList D_800A5208;
extern BattleList D_800A528C;
extern BattleList D_800A5310;

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
Battle D_800A5124 = { 0, 0, 0x60040000 };
Battle D_800A5130 = { 0, 0, 0x60040000 };
Battle D_800A513C = { 0, 0, 0x60040000 };
Battle D_800A5148 = { 0, 0, 0x60040000 };
Battle D_800A5154 = { 0, 0, 0x60040000 };
Battle D_800A5160 = { 0, 0, 0x60040000 };
Battle D_800A516C = { 0, 0, 0x60040000 };
Battle D_800A5178 = { 0, 0, 0x60040000 };
BattleList D_800A5184 = {
    3,
    { &D_800A5124, &D_800A5130, &D_800A513C, &D_800A5148,
      &D_800A5154, &D_800A5160, &D_800A516C, &D_800A5178 },
};
Battle D_800A51A8 = { 0, 0, 0x60040000 };
Battle D_800A51B4 = { 0, 0, 0x60040000 };
Battle D_800A51C0 = { 0, 0, 0x60040000 };
Battle D_800A51CC = { 0, 0, 0x60040000 };
Battle D_800A51D8 = { 0, 0, 0x60040000 };
Battle D_800A51E4 = { 0, 0, 0x60040000 };
Battle D_800A51F0 = { 0, 0, 0x60040000 };
Battle D_800A51FC = { 0, 0, 0x60040000 };
BattleList D_800A5208 = {
    0,
    { &D_800A51A8, &D_800A51B4, &D_800A51C0, &D_800A51CC,
      &D_800A51D8, &D_800A51E4, &D_800A51F0, &D_800A51FC },
};
Battle D_800A522C = { 0, 0, 0x60040000 };
Battle D_800A5238 = { 0, 0, 0x60040000 };
Battle D_800A5244 = { 0, 0, 0x60040000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
Battle D_800A5274 = { 0, 0, 0x60040000 };
Battle D_800A5280 = { 0, 0, 0x60040000 };
BattleList D_800A528C = {
    0,
    { &D_800A522C, &D_800A5238, &D_800A5244, &D_800A5250,
      &D_800A525C, &D_800A5268, &D_800A5274, &D_800A5280 },
};
Battle D_800A52B0 = { 258, 20, 0x600C0000 };
Battle D_800A52BC = { 259, 20, 0x600C0000 };
Battle D_800A52C8 = { 260, 20, 0x600C0000 };
Battle D_800A52D4 = { 261, 20, 0x600C0000 };
Battle D_800A52E0 = { 262, 20, 0x608C0000 };
Battle D_800A52EC = { 0, 0, 0x60040000 };
Battle D_800A52F8 = { 0, 0, 0x60040000 };
Battle D_800A5304 = { 0, 0, 0x60040000 };
BattleList D_800A5310 = {
    0,
    { &D_800A52B0, &D_800A52BC, &D_800A52C8, &D_800A52D4,
      &D_800A52E0, &D_800A52EC, &D_800A52F8, &D_800A5304 },
};
FieldBattles stageBattles[] = {
    { 171, 0, 0, { &D_800A5184, &D_800A5208, &D_800A528C, &D_800A5310 } },
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
