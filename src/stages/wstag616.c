#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x4080, 1) && FLAGS_00.checkCondition(0x4081, 0)) {
            children[0] = FIELDSTG_startEvent(0x50C);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void func_800A4DA4(void) {
    FLAGS_00.applyAction(0x4080, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4DF0(void) {
    FLAGS_00.applyAction(0x4081, 1);
    FLAGS_00.applyAction(0x8F42, 1);
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x613
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x623
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xB700, 0x2B200};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3A;
    D_800990B4.music = 0x60E80000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A50AC;
extern Battle D_800A50B8;
extern Battle D_800A50C4;
extern Battle D_800A50D0;
extern Battle D_800A50DC;
extern Battle D_800A50E8;
extern Battle D_800A50F4;
extern Battle D_800A5100;
extern Battle D_800A5130;
extern Battle D_800A513C;
extern Battle D_800A5148;
extern Battle D_800A5154;
extern Battle D_800A5160;
extern Battle D_800A516C;
extern Battle D_800A5178;
extern Battle D_800A5184;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A51F0;
extern Battle D_800A51FC;
extern Battle D_800A5208;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5274;
extern Battle D_800A5280;
extern Battle D_800A528C;
extern BattleList D_800A510C;
extern BattleList D_800A5190;
extern BattleList D_800A5214;
extern BattleList D_800A5298;
extern u16 D_800A5358[];
extern u16 D_800A5360[];
extern u16 D_800A536C[];
extern u16 D_800A5374[];
extern u16 D_800A5384[];
extern u16 D_800A5394[];
extern u16 D_800A53A8[];
extern u16 D_800A53B0[];
extern u16 D_800A53BC[];
extern u16 D_800A53C4[];
extern u16 D_800A53CC[];
extern u16 D_800A53D8[];
extern u16 D_800A53E0[];
extern u16 D_800A53E8[];
extern u16 D_800A53F4[];
extern u16 D_800A53FC[];
extern u16 D_800A5404[];
extern u16 D_800A5410[];
extern u16 D_800A5418[];
extern u16 D_800A5420[];
extern u16 D_800A542C[];
extern u16 D_800A5524[];
extern FieldTalk D_800A5434[];
extern u16 D_800A5538[];
extern FieldTalk D_800A5470[];
extern u16 D_800A5540[];
extern FieldTalk D_800A5494[];
extern u16 D_800A5548[];
extern FieldTalk D_800A54B8[];
extern u16 D_800A5550[];
extern FieldTalk D_800A54DC[];
extern u16 D_800A5558[];
extern FieldTalk D_800A5500[];
extern FieldActorEntry D_800A5560;
extern FieldActorEntry D_800A5574;
extern FieldActorEntry D_800A5588;
extern FieldActorEntry D_800A559C;
extern FieldActorEntry D_800A55B0;
extern FieldActorEntry D_800A55C4;
extern s16 D_800A4F68[];
extern s16 D_800A5008[];

s16 D_800A4F68[] = {
    0x600, 1, 2,
    0x102, 2, 0x290, 0x230, 3,
    0x100, 0x10A, 0x270, 0x220,
    0x101, 0x10A, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 2, 0x10A, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 4, 0x10A, 2,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x6004\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x325\n");
#endif
s16 D_800A5008[] = {
    0x600, 1, 2,
    0x100, 2, 0x290, 0x230,
    0x101, 2, 1, 3,
    0x100, 0x10A, 0x270, 0x220,
    0x101, 0x10A, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0x10A, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x10A, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x3C,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0x10A, 2,
    0x301,
    0x300, 0x3C,
    0,
};
Battle D_800A50AC = { 83, 12, 0x60080000 };
Battle D_800A50B8 = { 83, 12, 0x60080000 };
Battle D_800A50C4 = { 83, 12, 0x60080000 };
Battle D_800A50D0 = { 83, 12, 0x60080000 };
Battle D_800A50DC = { 84, 12, 0x60080000 };
Battle D_800A50E8 = { 84, 12, 0x60080000 };
Battle D_800A50F4 = { 84, 12, 0x60080000 };
Battle D_800A5100 = { 84, 12, 0x60080000 };
BattleList D_800A510C = {
    3,
    { &D_800A50AC, &D_800A50B8, &D_800A50C4, &D_800A50D0,
      &D_800A50DC, &D_800A50E8, &D_800A50F4, &D_800A5100 },
};
Battle D_800A5130 = { 0, 0, 0x60040000 };
Battle D_800A513C = { 0, 0, 0x60040000 };
Battle D_800A5148 = { 0, 0, 0x60040000 };
Battle D_800A5154 = { 0, 0, 0x60040000 };
Battle D_800A5160 = { 0, 0, 0x60040000 };
Battle D_800A516C = { 0, 0, 0x60040000 };
Battle D_800A5178 = { 0, 0, 0x60040000 };
Battle D_800A5184 = { 0, 0, 0x60040000 };
BattleList D_800A5190 = {
    0,
    { &D_800A5130, &D_800A513C, &D_800A5148, &D_800A5154,
      &D_800A5160, &D_800A516C, &D_800A5178, &D_800A5184 },
};
Battle D_800A51B4 = { 0, 0, 0x60040000 };
Battle D_800A51C0 = { 0, 0, 0x60040000 };
Battle D_800A51CC = { 0, 0, 0x60040000 };
Battle D_800A51D8 = { 0, 0, 0x60040000 };
Battle D_800A51E4 = { 0, 0, 0x60040000 };
Battle D_800A51F0 = { 0, 0, 0x60040000 };
Battle D_800A51FC = { 0, 0, 0x60040000 };
Battle D_800A5208 = { 0, 0, 0x60040000 };
BattleList D_800A5214 = {
    0,
    { &D_800A51B4, &D_800A51C0, &D_800A51CC, &D_800A51D8,
      &D_800A51E4, &D_800A51F0, &D_800A51FC, &D_800A5208 },
};
Battle D_800A5238 = { 24, 19, 0x60880000 };
Battle D_800A5244 = { 320, 19, 0x60880000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
Battle D_800A5274 = { 0, 0, 0x60040000 };
Battle D_800A5280 = { 0, 0, 0x60040000 };
Battle D_800A528C = { 0, 0, 0x60040000 };
BattleList D_800A5298 = {
    0,
    { &D_800A5238, &D_800A5244, &D_800A5250, &D_800A525C,
      &D_800A5268, &D_800A5274, &D_800A5280, &D_800A528C },
};
FieldBattles stageBattles[] = {
    { 113, 0, 0, { &D_800A510C, &D_800A5190, &D_800A5214, &D_800A5298 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x156, 0x177, 0x58, 0x77, 0x170, 0x1FE },
    { 0x140, 0x100, 0x160, 0x170, 0x80, 0x70, 0x140, 0x1FD },
};
u16 D_800A5358[] = { 0x869A, 1, 0xFFFF };
u16 D_800A5360[] = { 0x869A, 0, 0, 0, 0xFFFF };
u16 D_800A536C[] = { 0, 1, 0xFFFF };
u16 D_800A5374[] = { 0x869A, 0, 0, 1, 0x8496, 0, 0xFFFF };
u16 D_800A5384[] = { 0x869A, 0, 0, 1, 0x8496, 1, 0xFFFF };
u16 D_800A5394[] = { 0x869A, 1, 0x8699, 0, 0x8496, 0, 0x7013, 1, 0xFFFF };
u16 D_800A53A8[] = { 0xA0C, 0, 0xFFFF };
u16 D_800A53B0[] = { 0xA0C, 1, 0x903D, 1, 0xFFFF };
u16 D_800A53BC[] = { 0xA0C, 1, 0xFFFF };
u16 D_800A53C4[] = { 0xA0C, 0, 0xFFFF };
u16 D_800A53CC[] = { 0xA0C, 1, 0x903D, 1, 0xFFFF };
u16 D_800A53D8[] = { 0xA0C, 1, 0xFFFF };
u16 D_800A53E0[] = { 0xA0C, 0, 0xFFFF };
u16 D_800A53E8[] = { 0xA0C, 1, 0x903D, 1, 0xFFFF };
u16 D_800A53F4[] = { 0xA0C, 1, 0xFFFF };
u16 D_800A53FC[] = { 0xA0C, 0, 0xFFFF };
u16 D_800A5404[] = { 0xA0C, 1, 0x903D, 1, 0xFFFF };
u16 D_800A5410[] = { 0xA0C, 1, 0xFFFF };
u16 D_800A5418[] = { 0xA0C, 0, 0xFFFF };
u16 D_800A5420[] = { 0xA0C, 1, 0x903D, 1, 0xFFFF };
u16 D_800A542C[] = { 0xA0C, 1, 0xFFFF };
FieldTalk D_800A5434[] = {
    { D_800A5358, NULL, 0x2EA },
    { D_800A5360, D_800A536C, 0x2EB },
    { D_800A5374, NULL, 0x2EC },
    { D_800A5384, D_800A5394, 0x2ED },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5470[] = {
    { D_800A53A8, D_800A53B0, 0x2D6 },
    { D_800A53BC, NULL, 0x119 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5494[] = {
    { D_800A53C4, D_800A53CC, 0x2D6 },
    { D_800A53D8, NULL, 0x11D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B8[] = {
    { D_800A53E0, D_800A53E8, 0x2D6 },
    { D_800A53F4, NULL, 0x11C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54DC[] = {
    { D_800A53FC, D_800A5404, 0x2D6 },
    { D_800A5410, NULL, 0x11B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5500[] = {
    { D_800A5418, D_800A5420, 0x2D6 },
    { D_800A542C, NULL, 0x11A },
    { NULL, NULL, 0 },
};
u16 D_800A5524[] = { 0x7047, 1, 0x704F, 1, 0x8699, 1, 0x869A, 0, 0xFFFF };
u16 D_800A5538[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5540[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5548[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5550[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5558[] = { 0x6025, 1, 0xFFFF };
FieldActorEntry D_800A5560 = { D_800A5524, D_800A5434, 0xA9, 4, 464, 320, 1 };
FieldActorEntry D_800A5574 = { D_800A5538, D_800A5470, 0x10A, 5, 624, 544, 7 };
FieldActorEntry D_800A5588 = { D_800A5540, D_800A5494, 0x10A, 5, 624, 544, 7 };
FieldActorEntry D_800A559C = { D_800A5548, D_800A54B8, 0x10A, 5, 624, 544, 7 };
FieldActorEntry D_800A55B0 = { D_800A5550, D_800A54DC, 0x10A, 5, 624, 544, 7 };
FieldActorEntry D_800A55C4 = { D_800A5558, D_800A5500, 0x10A, 5, 624, 544, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5560,
    &D_800A5574,
    &D_800A5588,
    &D_800A559C,
    &D_800A55B0,
    &D_800A55C4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x56, 2, 0, 1, 4, 0, 660, 140, 0, 0 },
    { 1, 0, 0x40, 6, 2, 0, 0, 0, 0, 0, 512, 816, 0, 0 },
    { 1, 0, 0x44, 6, 3, 0, 0, 0, 0, 0, 298, 816, 0, 0 },
    { 1, 0, 0x48, 6, 4, 0, 0, 0, 0, 0, 143, 793, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 1, 4, 0, 395, 684, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 1, 4, 0, 552, 763, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 1, 4, 0, 96, 746, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 1, 4, 0, 196, 576, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 1, 4, 0, 236, 352, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 1, 4, 0, 436, 252, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 1, 4, 0, 532, 204, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 1, 4, 0, 724, 108, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 1, 4, 0, 789, 575, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 2, 0, 1, 4, 0, 476, 568, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 2, 0, 1, 4, 0, 652, 624, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 2, 0, 1, 4, 0, 684, 276, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 2, 0, 1, 4, 0, 836, 352, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 2, 0, 1, 4, 0, 908, 460, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 2, 0, 1, 4, 0, 988, 664, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x41, 0xA, 0, 227, 467, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x41, 0xA, 0, 676, 506, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x41, 0xA, 0, 838, 140, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x4C, 0xA, 0, 410, 672, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x4C, 0xA, 0, 517, 306, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x4C, 0xA, 0, 686, 382, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x4C, 0xA, 0, 756, 723, 0, 0 },
    { 1, 0x64, 0x40, 6, 0, 0, 0, 0, 0, 0, 687, 136, 0, 0 },
    { 1, 0, 0x78, 6, 0x1D, 0, 0, 0, 0, 0, 810, 120, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2C, 1, 0x2C, 0x2E, 0x14, 0, 691, 754, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x58, 1, 0x58, 0x5B, 0x14, 0, 681, 794, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x58, 1, 0x58, 0x5B, 0x14, 0, 705, 816, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x58, 1, 0x58, 0x5B, 0x14, 0, 853, 676, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x58, 1, 0x58, 0x5B, 0x14, 0, 949, 526, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x60, 1, 0x60, 0x62, 0x14, 0, 80, 601, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x60, 1, 0x60, 0x62, 0x14, 0, 80, 702, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2F, 1, 0x2F, 0x31, 0x14, 0, 295, 495, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2F, 1, 0x2F, 0x31, 0x14, 0, 298, 606, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x5C, 1, 0x5C, 0x5F, 0x14, 0, 92, 757, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x5C, 1, 0x5C, 0x5F, 0x14, 0, 190, 431, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x5C, 1, 0x5C, 0x5F, 0x14, 0, 329, 641, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x5C, 1, 0x5C, 0x5F, 0x14, 0, 483, 287, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x5C, 1, 0x5C, 0x5F, 0x14, 0, 806, 127, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x5C, 1, 0x5C, 0x5F, 0x14, 0, 872, 90, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x5C, 1, 0x5C, 0x5F, 0x14, 0, 922, 390, 0, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 646, 144, 191, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2BD, 0x90, 0x240, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2BF, 0x268, 0x1AC, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0xB3, 0x238, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0xC3, 0x2A0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1291, D_800A4F68, EVENT_TEXT(0xA), NULL, func_800A4DA4 },
    { 1292, D_800A5008, EVENT_TEXT(0xB), NULL, func_800A4DF0 },
    { -1, NULL, 0, NULL, NULL },
};
