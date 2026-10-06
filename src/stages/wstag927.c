#include "common.h"
#include "stage.h"
extern AnimFrame D_800A6244[];
extern AnimFrame D_800A6294[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A6244[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A6294[0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
            if (tile->anim == 1) {
                tile->frame = stepLoopingAnimation(&task->anims[0], D_800A6244, 0);
            }
            if (tile->anim == 2) {
                tile->frame = stepLoopingAnimation(&task->anims[1], D_800A6294, 0);
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

/* Creates an object and the event object of flag 0x100C */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = createTileAnims();
        if (FLAGS_00.checkCondition(0x100C, 0)) {
            children[1] = FIELDSTG_startEvent(0x648);
        }
        if (FLAGS_00.checkCondition(0x100C, 1)) {
            children[1] = FIELDSTG_startEvent(0x64A);
        }
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

/* Event: applies actions 0x100C and 0x7400 */
void func_800A6118(void) {
    FLAGS_00.applyAction(0x100C, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x346;
    D_800990B4.sheetEntry = 0x8ED0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.imageFile = 0x8EC;
    D_800990B4.start = (Vec2){0x11D00, 0x12800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, 0x8ED0001);
    D_8009A70C.unk50(0);
}

void func_800A6118();
extern FieldActorEntry D_800A6354;
extern s16 D_800A6508[];
extern s16 D_800A65FC[];
extern Battle D_800A66D0;
extern Battle D_800A66DC;
extern Battle D_800A66E8;
extern Battle D_800A66F4;
extern Battle D_800A6700;
extern Battle D_800A670C;
extern Battle D_800A6718;
extern Battle D_800A6724;
extern Battle D_800A6754;
extern Battle D_800A6760;
extern Battle D_800A676C;
extern Battle D_800A6778;
extern Battle D_800A6784;
extern Battle D_800A6790;
extern Battle D_800A679C;
extern Battle D_800A67A8;
extern Battle D_800A67D8;
extern Battle D_800A67E4;
extern Battle D_800A67F0;
extern Battle D_800A67FC;
extern Battle D_800A6808;
extern Battle D_800A6814;
extern Battle D_800A6820;
extern Battle D_800A682C;
extern Battle D_800A685C;
extern Battle D_800A6868;
extern Battle D_800A6874;
extern Battle D_800A6880;
extern Battle D_800A688C;
extern Battle D_800A6898;
extern Battle D_800A68A4;
extern Battle D_800A68B0;
extern BattleList D_800A6730;
extern BattleList D_800A67B4;
extern BattleList D_800A6838;
extern BattleList D_800A68BC;

AnimFrame D_800A6244[] = {
    { 50, 18 }, { 44, 6 }, { 50, 60 }, { 44, 6 },
    { 45, 6 }, { 46, 6 }, { 44, 6 }, { 51, 78 },
    { 44, 6 }, { 45, 6 }, { 46, 6 }, { 44, 6 },
    { 52, 60 }, { 44, 6 }, { 52, 18 }, { 44, 6 },
    { 45, 6 }, { 46, 6 }, { 44, 6 }, { 255, 0 },
};
AnimFrame D_800A6294[] = {
    { 56, 60 }, { 47, 6 }, { 56, 18 }, { 47, 6 },
    { 48, 6 }, { 49, 6 }, { 47, 6 }, { 57, 78 },
    { 47, 6 }, { 48, 6 }, { 49, 6 }, { 47, 6 },
    { 58, 18 }, { 47, 6 }, { 58, 60 }, { 47, 6 },
    { 48, 6 }, { 49, 6 }, { 47, 6 }, { 255, 0 },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x1B8, 0xE0, 0xB8, 0x170, 0x1F4 },
};
FieldActorEntry D_800A6354 = { NULL, NULL, 0x68, 4, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6354,
    NULL,
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
#define EVENT_TEXT_FILE 0x158
FieldEvent stageEvents[] = {
    { 1608, D_800A6508, EVENT_TEXT(4), NULL, func_800A6118 },
    { 1610, D_800A65FC, EVENT_TEXT(5), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
s16 D_800A6508[] = {
    0x600, 0, 2,
    0x100, 2, 0xC0, 0x158,
    0x101, 2, 1, 5,
    0x100, 0x68, 0x180, 0xF8,
    0x101, 0x68, 1, 1,
    0x300, 0x78,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 1,
    0x301,
    0x102, 2, 0x140, 0x118, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 0x68, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0x68, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x68, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A65FC[] = {
    0x600, 0, 2,
    0x100, 2, 0x140, 0x118,
    0x101, 2, 1, 5,
    0x100, 0x68, 0x180, 0xF8,
    0x101, 0x68, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0x68, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0x68, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 5, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x68, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0xC0, 0x158, 1,
    0x300, 0x3C,
    0x304, 0x277, 0x12F, 0x168, 5,
    0,
};
Battle D_800A66D0 = { 0, 0, 0x60040000 };
Battle D_800A66DC = { 0, 0, 0x60040000 };
Battle D_800A66E8 = { 0, 0, 0x60040000 };
Battle D_800A66F4 = { 0, 0, 0x60040000 };
Battle D_800A6700 = { 0, 0, 0x60040000 };
Battle D_800A670C = { 0, 0, 0x60040000 };
Battle D_800A6718 = { 0, 0, 0x60040000 };
Battle D_800A6724 = { 0, 0, 0x60040000 };
BattleList D_800A6730 = {
    0,
    { &D_800A66D0, &D_800A66DC, &D_800A66E8, &D_800A66F4,
      &D_800A6700, &D_800A670C, &D_800A6718, &D_800A6724 },
};
Battle D_800A6754 = { 0, 0, 0x60040000 };
Battle D_800A6760 = { 0, 0, 0x60040000 };
Battle D_800A676C = { 0, 0, 0x60040000 };
Battle D_800A6778 = { 0, 0, 0x60040000 };
Battle D_800A6784 = { 0, 0, 0x60040000 };
Battle D_800A6790 = { 0, 0, 0x60040000 };
Battle D_800A679C = { 0, 0, 0x60040000 };
Battle D_800A67A8 = { 0, 0, 0x60040000 };
BattleList D_800A67B4 = {
    0,
    { &D_800A6754, &D_800A6760, &D_800A676C, &D_800A6778,
      &D_800A6784, &D_800A6790, &D_800A679C, &D_800A67A8 },
};
Battle D_800A67D8 = { 0, 0, 0x60040000 };
Battle D_800A67E4 = { 0, 0, 0x60040000 };
Battle D_800A67F0 = { 0, 0, 0x60040000 };
Battle D_800A67FC = { 0, 0, 0x60040000 };
Battle D_800A6808 = { 0, 0, 0x60040000 };
Battle D_800A6814 = { 0, 0, 0x60040000 };
Battle D_800A6820 = { 0, 0, 0x60040000 };
Battle D_800A682C = { 0, 0, 0x60040000 };
BattleList D_800A6838 = {
    0,
    { &D_800A67D8, &D_800A67E4, &D_800A67F0, &D_800A67FC,
      &D_800A6808, &D_800A6814, &D_800A6820, &D_800A682C },
};
Battle D_800A685C = { 262, 47, 0x60940000 };
Battle D_800A6868 = { 0, 0, 0x60040000 };
Battle D_800A6874 = { 0, 0, 0x60040000 };
Battle D_800A6880 = { 0, 0, 0x60040000 };
Battle D_800A688C = { 0, 0, 0x60040000 };
Battle D_800A6898 = { 0, 0, 0x60040000 };
Battle D_800A68A4 = { 0, 0, 0x60040000 };
Battle D_800A68B0 = { 0, 0, 0x60040000 };
BattleList D_800A68BC = {
    0,
    { &D_800A685C, &D_800A6868, &D_800A6874, &D_800A6880,
      &D_800A688C, &D_800A6898, &D_800A68A4, &D_800A68B0 },
};
FieldBattles stageBattles[] = {
    { 392, 0, 0, { &D_800A6730, &D_800A67B4, &D_800A6838, &D_800A68BC } },
};
