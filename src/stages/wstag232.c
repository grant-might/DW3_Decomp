#include "common.h"
#include "stage.h"
extern AnimFrame D_800A5088[];
extern AnimFrame D_800A50D8[];

#include "common/step_looping_animation.inc.c"

/* Sets the frame of the map objects from two animations, which run once per record */
void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A5088[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A50D8[0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
            if (tile->anim == 1) {
                tile->frame = stepLoopingAnimation(&task->anims[0], D_800A5088, 0);
            }
            if (tile->anim == 2) {
                tile->frame = stepLoopingAnimation(&task->anims[1], D_800A50D8, 0);
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
#define STAGE_TEXT 0xF0
#define STAGE_FILE 0x338
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define STAGE_FILE 0x347
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x11D00, 0x12800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x14 && GAME.progress < 0x18) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A5128;
extern Battle D_800A5134;
extern Battle D_800A5140;
extern Battle D_800A514C;
extern Battle D_800A5158;
extern Battle D_800A5164;
extern Battle D_800A5170;
extern Battle D_800A517C;
extern Battle D_800A51AC;
extern Battle D_800A51B8;
extern Battle D_800A51C4;
extern Battle D_800A51D0;
extern Battle D_800A51DC;
extern Battle D_800A51E8;
extern Battle D_800A51F4;
extern Battle D_800A5200;
extern Battle D_800A5230;
extern Battle D_800A523C;
extern Battle D_800A5248;
extern Battle D_800A5254;
extern Battle D_800A5260;
extern Battle D_800A526C;
extern Battle D_800A5278;
extern Battle D_800A5284;
extern Battle D_800A52B4;
extern Battle D_800A52C0;
extern Battle D_800A52CC;
extern Battle D_800A52D8;
extern Battle D_800A52E4;
extern Battle D_800A52F0;
extern Battle D_800A52FC;
extern Battle D_800A5308;
extern BattleList D_800A5188;
extern BattleList D_800A520C;
extern BattleList D_800A5290;
extern BattleList D_800A5314;

AnimFrame D_800A5088[] = {
    { 50, 18 }, { 44, 6 }, { 50, 60 }, { 44, 6 },
    { 45, 6 }, { 46, 6 }, { 44, 6 }, { 51, 78 },
    { 44, 6 }, { 45, 6 }, { 46, 6 }, { 44, 6 },
    { 52, 60 }, { 44, 6 }, { 52, 18 }, { 44, 6 },
    { 45, 6 }, { 46, 6 }, { 44, 6 }, { 255, 0 },
};
AnimFrame D_800A50D8[] = {
    { 56, 60 }, { 47, 6 }, { 56, 18 }, { 47, 6 },
    { 48, 6 }, { 49, 6 }, { 47, 6 }, { 57, 78 },
    { 47, 6 }, { 48, 6 }, { 49, 6 }, { 47, 6 },
    { 58, 18 }, { 47, 6 }, { 58, 60 }, { 47, 6 },
    { 48, 6 }, { 49, 6 }, { 47, 6 }, { 255, 0 },
};
Battle D_800A5128 = { 0, 0, 0x60040000 };
Battle D_800A5134 = { 0, 0, 0x60040000 };
Battle D_800A5140 = { 0, 0, 0x60040000 };
Battle D_800A514C = { 0, 0, 0x60040000 };
Battle D_800A5158 = { 0, 0, 0x60040000 };
Battle D_800A5164 = { 0, 0, 0x60040000 };
Battle D_800A5170 = { 0, 0, 0x60040000 };
Battle D_800A517C = { 0, 0, 0x60040000 };
BattleList D_800A5188 = {
    3,
    { &D_800A5128, &D_800A5134, &D_800A5140, &D_800A514C,
      &D_800A5158, &D_800A5164, &D_800A5170, &D_800A517C },
};
Battle D_800A51AC = { 0, 0, 0x60040000 };
Battle D_800A51B8 = { 0, 0, 0x60040000 };
Battle D_800A51C4 = { 0, 0, 0x60040000 };
Battle D_800A51D0 = { 0, 0, 0x60040000 };
Battle D_800A51DC = { 0, 0, 0x60040000 };
Battle D_800A51E8 = { 0, 0, 0x60040000 };
Battle D_800A51F4 = { 0, 0, 0x60040000 };
Battle D_800A5200 = { 0, 0, 0x60040000 };
BattleList D_800A520C = {
    0,
    { &D_800A51AC, &D_800A51B8, &D_800A51C4, &D_800A51D0,
      &D_800A51DC, &D_800A51E8, &D_800A51F4, &D_800A5200 },
};
Battle D_800A5230 = { 0, 0, 0x60040000 };
Battle D_800A523C = { 0, 0, 0x60040000 };
Battle D_800A5248 = { 0, 0, 0x60040000 };
Battle D_800A5254 = { 0, 0, 0x60040000 };
Battle D_800A5260 = { 0, 0, 0x60040000 };
Battle D_800A526C = { 0, 0, 0x60040000 };
Battle D_800A5278 = { 0, 0, 0x60040000 };
Battle D_800A5284 = { 0, 0, 0x60040000 };
BattleList D_800A5290 = {
    0,
    { &D_800A5230, &D_800A523C, &D_800A5248, &D_800A5254,
      &D_800A5260, &D_800A526C, &D_800A5278, &D_800A5284 },
};
Battle D_800A52B4 = { 253, 20, 0x600C0000 };
Battle D_800A52C0 = { 254, 20, 0x600C0000 };
Battle D_800A52CC = { 255, 20, 0x600C0000 };
Battle D_800A52D8 = { 256, 20, 0x600C0000 };
Battle D_800A52E4 = { 257, 20, 0x608C0000 };
Battle D_800A52F0 = { 0, 0, 0x60040000 };
Battle D_800A52FC = { 0, 0, 0x60040000 };
Battle D_800A5308 = { 0, 0, 0x60040000 };
BattleList D_800A5314 = {
    0,
    { &D_800A52B4, &D_800A52C0, &D_800A52CC, &D_800A52D8,
      &D_800A52E4, &D_800A52F0, &D_800A52FC, &D_800A5308 },
};
FieldBattles stageBattles[] = {
    { 170, 0, 0, { &D_800A5188, &D_800A520C, &D_800A5290, &D_800A5314 } },
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
