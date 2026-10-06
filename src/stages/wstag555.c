#include "common.h"
#include "stage.h"
extern AnimFrame D_800A52A0[];
extern AnimFrame D_800A52D4[];
extern AnimFrame D_800A5308[];

#include "common/step_looping_animation.inc.c"

/* Sets the frame of the map objects from three animations */
void updateTileAnims(StageTileAnims *task) {
    s32 frames[3];
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A52A0[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A52D4[0].duration;
        task->anims[2].index = 0;
        task->anims[2].timer = D_800A5308[0].duration;
        break;
    case TASK_RUN:
        tile = D_800990B4.objects;
        frames[0] = stepLoopingAnimation(&task->anims[0], D_800A52A0, 0);
        frames[1] = stepLoopingAnimation(&task->anims[1], D_800A52D4, 0);
        frames[2] = stepLoopingAnimation(&task->anims[2], D_800A5308, 0);
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
#define STAGE_CHILDREN_SIZE 0x8
#include "common/start_stage.inc.c"

void func_800A4FF0(void) {
    FLAGS_00.applyAction(0x400C, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x235
#define STAGE_ARCHIVE 0x312
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x244
#define STAGE_ARCHIVE 0x321
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x4D700, 0x4B700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x38;
    D_800990B4.music = 0x60E00000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A5338;
extern Battle D_800A5344;
extern Battle D_800A5350;
extern Battle D_800A535C;
extern Battle D_800A5368;
extern Battle D_800A5374;
extern Battle D_800A5380;
extern Battle D_800A538C;
extern Battle D_800A53BC;
extern Battle D_800A53C8;
extern Battle D_800A53D4;
extern Battle D_800A53E0;
extern Battle D_800A53EC;
extern Battle D_800A53F8;
extern Battle D_800A5404;
extern Battle D_800A5410;
extern Battle D_800A5440;
extern Battle D_800A544C;
extern Battle D_800A5458;
extern Battle D_800A5464;
extern Battle D_800A5470;
extern Battle D_800A547C;
extern Battle D_800A5488;
extern Battle D_800A5494;
extern Battle D_800A54C4;
extern Battle D_800A54D0;
extern Battle D_800A54DC;
extern Battle D_800A54E8;
extern Battle D_800A54F4;
extern Battle D_800A5500;
extern Battle D_800A550C;
extern Battle D_800A5518;
extern BattleList D_800A5398;
extern BattleList D_800A541C;
extern BattleList D_800A54A0;
extern BattleList D_800A5524;
extern u16 D_800A55D4[];
extern FieldActorEntry D_800A55DC;
extern s16 D_800A5130[];

s16 D_800A5130[] = {
    0x600, 1, 2,
    0x102, 2, 0xF6, 0x163, 3,
    0x100, 0x69, 0x140, 0xC8,
    0x101, 0x69, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x102, 0x69, 0xDB, 0xFA, 1,
    0x302, 0x69,
    0x600, 0, 0x69,
    0x101, 0x323, 0x325, 0x69,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0x69,
    0x300, 0x1E,
    0x101, 0x69, 1, 0,
    0x300, 0x1E,
    0x600, 0, 2,
    0x102, 0x69, 0xDB, 0x151, 7,
    0x302, 0x69,
    0x101, 0x69, 1, 7,
    0x300, 0x1E,
    0x200, 0, 1, 0x69, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x69, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0x69, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x69, 1, 1,
    0x300, 0x1E,
    0x200, 0, 6, 2, 2,
    0x101, 2, 7, 3,
    0x301,
    0x102, 0x69, 0xC7, 0x15C, 1,
    0x302, 0x69,
    0x101, 2, 1, 3,
    0x102, 0x69, 0x10E, 0x180, 7,
    0x302, 0x69,
    0x101, 2, 1, 7,
    0x102, 0x69, 0x1A7, 0x1CB, 7,
    0x302, 0x69,
    0x200, 0, 7, 2, 2,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x301,
    0x300, 0x3C,
    0,
};
AnimFrame D_800A52A0[] = {
    { 50, 8 }, { 51, 8 }, { 52, 8 }, { 53, 8 },
    { 54, 8 }, { 55, 8 }, { 56, 8 }, { 57, 8 },
    { 58, 8 }, { 59, 8 }, { 60, 8 }, { 82, 160 },
    { 255, 0 },
};
AnimFrame D_800A52D4[] = {
    { 61, 8 }, { 62, 8 }, { 63, 8 }, { 64, 8 },
    { 65, 8 }, { 66, 8 }, { 67, 8 }, { 68, 8 },
    { 69, 8 }, { 70, 8 }, { 71, 8 }, { 82, 160 },
    { 255, 0 },
};
AnimFrame D_800A5308[] = {
    { 72, 8 }, { 73, 8 }, { 74, 8 }, { 75, 8 },
    { 76, 8 }, { 77, 8 }, { 78, 8 }, { 79, 8 },
    { 80, 8 }, { 81, 8 }, { 82, 160 }, { 255, 0 },
};
Battle D_800A5338 = { 148, 5, 0x60080000 };
Battle D_800A5344 = { 148, 5, 0x60080000 };
Battle D_800A5350 = { 148, 5, 0x60080000 };
Battle D_800A535C = { 148, 5, 0x60080000 };
Battle D_800A5368 = { 154, 5, 0x60080000 };
Battle D_800A5374 = { 154, 5, 0x60080000 };
Battle D_800A5380 = { 154, 5, 0x60080000 };
Battle D_800A538C = { 154, 5, 0x60080000 };
BattleList D_800A5398 = {
    3,
    { &D_800A5338, &D_800A5344, &D_800A5350, &D_800A535C,
      &D_800A5368, &D_800A5374, &D_800A5380, &D_800A538C },
};
Battle D_800A53BC = { 0, 0, 0x60040000 };
Battle D_800A53C8 = { 0, 0, 0x60040000 };
Battle D_800A53D4 = { 0, 0, 0x60040000 };
Battle D_800A53E0 = { 0, 0, 0x60040000 };
Battle D_800A53EC = { 0, 0, 0x60040000 };
Battle D_800A53F8 = { 0, 0, 0x60040000 };
Battle D_800A5404 = { 0, 0, 0x60040000 };
Battle D_800A5410 = { 0, 0, 0x60040000 };
BattleList D_800A541C = {
    0,
    { &D_800A53BC, &D_800A53C8, &D_800A53D4, &D_800A53E0,
      &D_800A53EC, &D_800A53F8, &D_800A5404, &D_800A5410 },
};
Battle D_800A5440 = { 0, 0, 0x60040000 };
Battle D_800A544C = { 0, 0, 0x60040000 };
Battle D_800A5458 = { 0, 0, 0x60040000 };
Battle D_800A5464 = { 0, 0, 0x60040000 };
Battle D_800A5470 = { 0, 0, 0x60040000 };
Battle D_800A547C = { 0, 0, 0x60040000 };
Battle D_800A5488 = { 0, 0, 0x60040000 };
Battle D_800A5494 = { 0, 0, 0x60040000 };
BattleList D_800A54A0 = {
    0,
    { &D_800A5440, &D_800A544C, &D_800A5458, &D_800A5464,
      &D_800A5470, &D_800A547C, &D_800A5488, &D_800A5494 },
};
Battle D_800A54C4 = { 0, 0, 0x60040000 };
Battle D_800A54D0 = { 0, 0, 0x60040000 };
Battle D_800A54DC = { 0, 0, 0x60040000 };
Battle D_800A54E8 = { 0, 0, 0x60040000 };
Battle D_800A54F4 = { 0, 0, 0x60040000 };
Battle D_800A5500 = { 0, 0, 0x60040000 };
Battle D_800A550C = { 0, 0, 0x60040000 };
Battle D_800A5518 = { 0, 0, 0x60040000 };
BattleList D_800A5524 = {
    0,
    { &D_800A54C4, &D_800A54D0, &D_800A54DC, &D_800A54E8,
      &D_800A54F4, &D_800A5500, &D_800A550C, &D_800A5518 },
};
FieldBattles stageBattles[] = {
    { 32, 0, 0, { &D_800A5398, &D_800A541C, &D_800A54A0, &D_800A5524 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x180, 0x1C0, 0x80, 0x170, 0x1FF },
};
u16 D_800A55D4[] = { 0x600F, 1, 0xFFFF };
FieldActorEntry D_800A55DC = { D_800A55D4, NULL, 0x69, 4, 0, 0, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A55DC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x80, 2, 6, 0, 0, 0, 0, 0, 874, 1273, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 50, 721, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 87, 297, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 150, 1359, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 185, 1233, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 211, 917, 0, 0 },
    { 1, 3, 0xC8, 6, 0x48, 0, 0, 0, 0, 0, 232, 991, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 299, 296, 0, 0 },
    { 1, 3, 0xC8, 6, 0x48, 0, 0, 0, 0, 0, 337, 292, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 401, 938, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 530, 1299, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 710, 1019, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 832, 395, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 964, 526, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 967, 699, 0, 0 },
    { 1, 3, 0xC8, 6, 0x48, 0, 0, 0, 0, 0, 1223, 896, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 1411, 668, 0, 0 },
    { 1, 0, 0x80, 6, 7, 0, 0, 0, 0, 0, 856, 1221, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 506, 475, 544, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 317, 423, 488, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 225, 615, 666, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 476, 647, 713, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 592, 815, 880, 0 },
    { 1, 0, 0x64, 4, 5, 0, 0, 0, 0, 0, 289, 127, 230, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x25D, 0xC8, 0x3BC, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x249, 0x7A, 0xEA, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x247, 0xB0, 0x90, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x257, 0x320, 0x88, 1, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 0x1B, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 1, 2 },
    { { { 0x600F, 1 }, { 0x400C, 0 } }, 8, 0x17C, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 380, D_800A5130, EVENT_TEXT(4), NULL, func_800A4FF0 },
    { -1, NULL, 0, NULL, NULL },
};
