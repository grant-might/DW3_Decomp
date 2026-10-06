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
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
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
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x256;
    D_800990B4.sheetEntry = 0x9230000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x922;
    D_800990B4.start = (Vec2){0x16B00, 0x44400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2F;
    D_800990B4.music = 0x60BC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, 0x9230002);
    D_8009A70C.setFile(7, 0x9230003);
    D_8009A70C.setFile(4, 0x9230001);
    D_8009A70C.unk50(0);
}

extern u16 D_800A62C0[];
extern u16 D_800A62CC[];
extern u16 D_800A62D8[];
extern u16 D_800A62E4[];
extern u16 D_800A62F4[];
extern u16 D_800A6300[];
extern u16 D_800A6308[];
extern u16 D_800A6314[];
extern u16 D_800A631C[];
extern u16 D_800A6324[];
extern u16 D_800A6330[];
extern u16 D_800A633C[];
extern FieldTalk D_800A6348[];
extern u16 D_800A63E4[];
extern FieldTalk D_800A6360[];
extern u16 D_800A63EC[];
extern FieldTalk D_800A6378[];
extern FieldTalk D_800A63B4[];
extern FieldActorEntry D_800A63F4;
extern FieldActorEntry D_800A6408;
extern FieldActorEntry D_800A641C;
extern FieldActorEntry D_800A6430;
extern Battle D_800A6614;
extern Battle D_800A6620;
extern Battle D_800A662C;
extern Battle D_800A6638;
extern Battle D_800A6644;
extern Battle D_800A6650;
extern Battle D_800A665C;
extern Battle D_800A6668;
extern Battle D_800A6698;
extern Battle D_800A66A4;
extern Battle D_800A66B0;
extern Battle D_800A66BC;
extern Battle D_800A66C8;
extern Battle D_800A66D4;
extern Battle D_800A66E0;
extern Battle D_800A66EC;
extern Battle D_800A671C;
extern Battle D_800A6728;
extern Battle D_800A6734;
extern Battle D_800A6740;
extern Battle D_800A674C;
extern Battle D_800A6758;
extern Battle D_800A6764;
extern Battle D_800A6770;
extern Battle D_800A67A0;
extern Battle D_800A67AC;
extern Battle D_800A67B8;
extern Battle D_800A67C4;
extern Battle D_800A67D0;
extern Battle D_800A67DC;
extern Battle D_800A67E8;
extern Battle D_800A67F4;
extern BattleList D_800A6674;
extern BattleList D_800A66F8;
extern BattleList D_800A677C;
extern BattleList D_800A6800;

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
u16 D_800A62C0[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A62CC[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A62D8[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A62E4[] = { 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A62F4[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6300[] = { 0, 1, 0xFFFF };
u16 D_800A6308[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A6314[] = { 0x782F, 1, 0xFFFF };
u16 D_800A631C[] = { 0x7096, 0, 0xFFFF };
u16 D_800A6324[] = { 0x7096, 1, 0x1010, 0, 0xFFFF };
u16 D_800A6330[] = { 0x1010, 1, 0x7400, 1, 0xFFFF };
u16 D_800A633C[] = { 0x7096, 1, 0x1010, 1, 0xFFFF };
FieldTalk D_800A6348[] = {
    { NULL, NULL, 0x92 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6360[] = {
    { NULL, NULL, 0x49 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6378[] = {
    { D_800A62C0, D_800A62CC, 0x4B },
    { D_800A62D8, D_800A62E4, 0x4C },
    { D_800A62F4, D_800A6300, 0x49 },
    { D_800A6308, D_800A6314, 0x4A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A63B4[] = {
    { D_800A631C, NULL, 0x8F },
    { D_800A6324, D_800A6330, 0x90 },
    { D_800A633C, NULL, 0x91 },
    { NULL, NULL, 0 },
};
u16 D_800A63E4[] = { 0x8192, 0, 0xFFFF };
u16 D_800A63EC[] = { 0x8192, 1, 0xFFFF };
FieldActorEntry D_800A63F4 = { NULL, D_800A6348, 0x2D, 4, 764, 1138, 5 };
FieldActorEntry D_800A6408 = { D_800A63E4, D_800A6360, 0x38, 5, 976, 632, 1 };
FieldActorEntry D_800A641C = { D_800A63EC, D_800A6378, 0x38, 5, 976, 632, 1 };
FieldActorEntry D_800A6430 = { NULL, D_800A63B4, 0x92, 6, 924, 323, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A63F4,
    &D_800A6408,
    &D_800A641C,
    &D_800A6430,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x299, 0x648, 0xD0, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0xF0, 0x4D8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x100, 0x450, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x102, 0x420, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0xF2, 0x388, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x1D2, 0x4C8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x1C2, 0x460, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 0xF, 0x1AF, 0x428, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 0xF, 0x1BF, 0x330, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 0x16, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x330, 0x208, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x340, 0x170, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6614 = { 50, 4, 0x60080000 };
Battle D_800A6620 = { 50, 4, 0x60080000 };
Battle D_800A662C = { 130, 4, 0x60080000 };
Battle D_800A6638 = { 130, 4, 0x60080000 };
Battle D_800A6644 = { 131, 4, 0x60080000 };
Battle D_800A6650 = { 131, 4, 0x60080000 };
Battle D_800A665C = { 134, 4, 0x60080000 };
Battle D_800A6668 = { 134, 4, 0x60080000 };
BattleList D_800A6674 = {
    3,
    { &D_800A6614, &D_800A6620, &D_800A662C, &D_800A6638,
      &D_800A6644, &D_800A6650, &D_800A665C, &D_800A6668 },
};
Battle D_800A6698 = { 100, 4, 0x60080000 };
Battle D_800A66A4 = { 100, 4, 0x60080000 };
Battle D_800A66B0 = { 100, 4, 0x60080000 };
Battle D_800A66BC = { 100, 4, 0x60080000 };
Battle D_800A66C8 = { 100, 4, 0x60080000 };
Battle D_800A66D4 = { 100, 4, 0x60080000 };
Battle D_800A66E0 = { 100, 4, 0x60080000 };
Battle D_800A66EC = { 100, 4, 0x60080000 };
BattleList D_800A66F8 = {
    5,
    { &D_800A6698, &D_800A66A4, &D_800A66B0, &D_800A66BC,
      &D_800A66C8, &D_800A66D4, &D_800A66E0, &D_800A66EC },
};
Battle D_800A671C = { 0, 0, 0x60040000 };
Battle D_800A6728 = { 0, 0, 0x60040000 };
Battle D_800A6734 = { 0, 0, 0x60040000 };
Battle D_800A6740 = { 0, 0, 0x60040000 };
Battle D_800A674C = { 0, 0, 0x60040000 };
Battle D_800A6758 = { 0, 0, 0x60040000 };
Battle D_800A6764 = { 0, 0, 0x60040000 };
Battle D_800A6770 = { 0, 0, 0x60040000 };
BattleList D_800A677C = {
    0,
    { &D_800A671C, &D_800A6728, &D_800A6734, &D_800A6740,
      &D_800A674C, &D_800A6758, &D_800A6764, &D_800A6770 },
};
Battle D_800A67A0 = { 308, 18, 0x608C0000 };
Battle D_800A67AC = { 0, 0, 0x60040000 };
Battle D_800A67B8 = { 0, 0, 0x60040000 };
Battle D_800A67C4 = { 0, 0, 0x60040000 };
Battle D_800A67D0 = { 0, 0, 0x60040000 };
Battle D_800A67DC = { 0, 0, 0x60040000 };
Battle D_800A67E8 = { 0, 0, 0x60040000 };
Battle D_800A67F4 = { 0, 0, 0x60040000 };
BattleList D_800A6800 = {
    0,
    { &D_800A67A0, &D_800A67AC, &D_800A67B8, &D_800A67C4,
      &D_800A67D0, &D_800A67DC, &D_800A67E8, &D_800A67F4 },
};
FieldBattles stageBattles[] = {
    { 391, 0, 0, { &D_800A6674, &D_800A66F8, &D_800A677C, &D_800A6800 } },
};
