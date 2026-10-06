#include "common.h"
#include "stage.h"
extern AnimFrame D_800A5294[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A5294[0].duration;
        break;
    case TASK_RUN:
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
            if (tile->anim == 1) {
                tile->frame = stepLoopingAnimation(&task->anims[0], D_800A5294, 0);
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

/* Creates the stage helper task, and the event object when flag 0x407A is set and 0x407B is not */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = createTileAnims();
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x407A, 1) && FLAGS_00.checkCondition(0x407B, 0)) {
            children[1] = FIELDSTG_startEvent(0x506);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x8
#include "common/start_stage.inc.c"

void func_800A4FA4(void) {
    FLAGS_00.applyAction(0x407A, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4FF0(void) {
    FLAGS_00.applyAction(0x407B, 1);
    FLAGS_00.applyAction(0x8AF5, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xE9
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x734
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x744
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x17A00, 0x44500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2F;
    D_800990B4.music = 0x60BC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A5320;
extern Battle D_800A532C;
extern Battle D_800A5338;
extern Battle D_800A5344;
extern Battle D_800A5350;
extern Battle D_800A535C;
extern Battle D_800A5368;
extern Battle D_800A5374;
extern Battle D_800A53A4;
extern Battle D_800A53B0;
extern Battle D_800A53BC;
extern Battle D_800A53C8;
extern Battle D_800A53D4;
extern Battle D_800A53E0;
extern Battle D_800A53EC;
extern Battle D_800A53F8;
extern Battle D_800A5428;
extern Battle D_800A5434;
extern Battle D_800A5440;
extern Battle D_800A544C;
extern Battle D_800A5458;
extern Battle D_800A5464;
extern Battle D_800A5470;
extern Battle D_800A547C;
extern Battle D_800A54AC;
extern Battle D_800A54B8;
extern Battle D_800A54C4;
extern Battle D_800A54D0;
extern Battle D_800A54DC;
extern Battle D_800A54E8;
extern Battle D_800A54F4;
extern Battle D_800A5500;
extern BattleList D_800A5380;
extern BattleList D_800A5404;
extern BattleList D_800A5488;
extern BattleList D_800A550C;
extern u16 D_800A55BC[];
extern u16 D_800A55C4[];
extern u16 D_800A55D0[];
extern u16 D_800A55D8[];
extern u16 D_800A55E0[];
extern u16 D_800A55EC[];
extern u16 D_800A55F4[];
extern u16 D_800A55FC[];
extern u16 D_800A5608[];
extern u16 D_800A5610[];
extern u16 D_800A5618[];
extern u16 D_800A5624[];
extern u16 D_800A562C[];
extern u16 D_800A5634[];
extern u16 D_800A5640[];
extern u16 D_800A56FC[];
extern FieldTalk D_800A5648[];
extern u16 D_800A5704[];
extern FieldTalk D_800A566C[];
extern u16 D_800A570C[];
extern FieldTalk D_800A5690[];
extern u16 D_800A5714[];
extern FieldTalk D_800A56B4[];
extern u16 D_800A571C[];
extern FieldTalk D_800A56D8[];
extern FieldActorEntry D_800A5724;
extern FieldActorEntry D_800A5738;
extern FieldActorEntry D_800A574C;
extern FieldActorEntry D_800A5760;
extern FieldActorEntry D_800A5774;
extern s16 D_800A5150[];
extern s16 D_800A51F0[];

s16 D_800A5150[] = {
    0x600, 1, 2,
    0x102, 2, 0x37B, 0x153, 5,
    0x100, 0x108, 0x39B, 0x13D,
    0x101, 0x108, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0x108, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x108, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x800A\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x2\n");
#endif
s16 D_800A51F0[] = {
    0x600, 1, 2,
    0x100, 2, 0x37B, 0x153,
    0x101, 2, 1, 5,
    0x100, 0x108, 0x39B, 0x13D,
    0x101, 0x108, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x108, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x108, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x108, 0,
    0x301,
    0x300, 0x3C,
    0,
};
AnimFrame D_800A5294[] = {
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
Battle D_800A5320 = { 100, 4, 0x60080000 };
Battle D_800A532C = { 100, 4, 0x60080000 };
Battle D_800A5338 = { 100, 4, 0x60080000 };
Battle D_800A5344 = { 100, 4, 0x60080000 };
Battle D_800A5350 = { 101, 4, 0x60080000 };
Battle D_800A535C = { 101, 4, 0x60080000 };
Battle D_800A5368 = { 101, 4, 0x60080000 };
Battle D_800A5374 = { 101, 4, 0x60080000 };
BattleList D_800A5380 = {
    3,
    { &D_800A5320, &D_800A532C, &D_800A5338, &D_800A5344,
      &D_800A5350, &D_800A535C, &D_800A5368, &D_800A5374 },
};
Battle D_800A53A4 = { 101, 4, 0x60080000 };
Battle D_800A53B0 = { 101, 4, 0x60080000 };
Battle D_800A53BC = { 101, 4, 0x60080000 };
Battle D_800A53C8 = { 101, 4, 0x60080000 };
Battle D_800A53D4 = { 101, 4, 0x60080000 };
Battle D_800A53E0 = { 101, 4, 0x60080000 };
Battle D_800A53EC = { 101, 4, 0x60080000 };
Battle D_800A53F8 = { 101, 4, 0x60080000 };
BattleList D_800A5404 = {
    5,
    { &D_800A53A4, &D_800A53B0, &D_800A53BC, &D_800A53C8,
      &D_800A53D4, &D_800A53E0, &D_800A53EC, &D_800A53F8 },
};
Battle D_800A5428 = { 0, 0, 0x60040000 };
Battle D_800A5434 = { 0, 0, 0x60040000 };
Battle D_800A5440 = { 0, 0, 0x60040000 };
Battle D_800A544C = { 0, 0, 0x60040000 };
Battle D_800A5458 = { 0, 0, 0x60040000 };
Battle D_800A5464 = { 0, 0, 0x60040000 };
Battle D_800A5470 = { 0, 0, 0x60040000 };
Battle D_800A547C = { 0, 0, 0x60040000 };
BattleList D_800A5488 = {
    0,
    { &D_800A5428, &D_800A5434, &D_800A5440, &D_800A544C,
      &D_800A5458, &D_800A5464, &D_800A5470, &D_800A547C },
};
Battle D_800A54AC = { 15, 19, 0x60880000 };
Battle D_800A54B8 = { 317, 19, 0x60880000 };
Battle D_800A54C4 = { 0, 0, 0x60040000 };
Battle D_800A54D0 = { 0, 0, 0x60040000 };
Battle D_800A54DC = { 0, 0, 0x60040000 };
Battle D_800A54E8 = { 0, 0, 0x60040000 };
Battle D_800A54F4 = { 0, 0, 0x60040000 };
Battle D_800A5500 = { 0, 0, 0x60040000 };
BattleList D_800A550C = {
    0,
    { &D_800A54AC, &D_800A54B8, &D_800A54C4, &D_800A54D0,
      &D_800A54DC, &D_800A54E8, &D_800A54F4, &D_800A5500 },
};
FieldBattles stageBattles[] = {
    { 69, 0, 0, { &D_800A5380, &D_800A5404, &D_800A5488, &D_800A550C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16A, 0x100, 0xA8, 0, 0x170, 0x1FF },
};
u16 D_800A55BC[] = { 0xA09, 0, 0xFFFF };
u16 D_800A55C4[] = { 0xA09, 1, 0x903A, 1, 0xFFFF };
u16 D_800A55D0[] = { 0xA09, 1, 0xFFFF };
u16 D_800A55D8[] = { 0xA09, 0, 0xFFFF };
u16 D_800A55E0[] = { 0xA09, 1, 0x903A, 1, 0xFFFF };
u16 D_800A55EC[] = { 0xA09, 1, 0xFFFF };
u16 D_800A55F4[] = { 0xA09, 0, 0xFFFF };
u16 D_800A55FC[] = { 0xA09, 1, 0x903A, 1, 0xFFFF };
u16 D_800A5608[] = { 0xA09, 1, 0xFFFF };
u16 D_800A5610[] = { 0xA09, 0, 0xFFFF };
u16 D_800A5618[] = { 0xA09, 1, 0x903A, 1, 0xFFFF };
u16 D_800A5624[] = { 0xA09, 1, 0xFFFF };
u16 D_800A562C[] = { 0xA09, 0, 0xFFFF };
u16 D_800A5634[] = { 0xA09, 1, 0x903A, 1, 0xFFFF };
u16 D_800A5640[] = { 0xA09, 1, 0xFFFF };
FieldTalk D_800A5648[] = {
    { D_800A55BC, D_800A55C4, 0x2D3 },
    { D_800A55D0, NULL, 0x99 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A566C[] = {
    { D_800A55D8, D_800A55E0, 0x2D3 },
    { D_800A55EC, NULL, 0x9A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5690[] = {
    { D_800A55F4, D_800A55FC, 0x2D3 },
    { D_800A5608, NULL, 0x9B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56B4[] = {
    { D_800A5610, D_800A5618, 0x2D3 },
    { D_800A5624, NULL, 0x9C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56D8[] = {
    { D_800A562C, D_800A5634, 0x2D3 },
    { D_800A5640, NULL, 0x9D },
    { NULL, NULL, 0 },
};
u16 D_800A56FC[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5704[] = { 0x6025, 1, 0xFFFF };
u16 D_800A570C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5714[] = { 0x701A, 1, 0xFFFF };
u16 D_800A571C[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A5724 = { D_800A56FC, D_800A5648, 0x108, 4, 923, 317, 1 };
FieldActorEntry D_800A5738 = { D_800A5704, D_800A566C, 0x108, 4, 923, 317, 1 };
FieldActorEntry D_800A574C = { D_800A570C, D_800A5690, 0x108, 4, 923, 317, 1 };
FieldActorEntry D_800A5760 = { D_800A5714, D_800A56B4, 0x108, 4, 923, 317, 1 };
FieldActorEntry D_800A5774 = { D_800A571C, D_800A56D8, 0x108, 4, 923, 317, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5724,
    &D_800A5738,
    &D_800A574C,
    &D_800A5760,
    &D_800A5774,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 1, 0xE6, 2, 0x32, 0, 0, 0, 0, 0, 966, 364, 0, 0 },
    { 1, 0, 0x40, 2, 0x54, 2, 0, 2, 6, 0, 931, 293, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 176, 403, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 600, 1073, 0, 0 },
    { 1, 0, 0x78, 6, 7, 0, 0, 0, 0, 0, 745, 598, 0, 0 },
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
FieldEvent stageEvents[] = {
    { 1285, D_800A5150, EVENT_TEXT(0x1B), NULL, func_800A4FA4 },
    { 1286, D_800A51F0, EVENT_TEXT(0x1C), NULL, func_800A4FF0 },
    { -1, NULL, 0, NULL, NULL },
};
