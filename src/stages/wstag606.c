#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x407E, 1) && FLAGS_00.checkCondition(0x407F, 0)) {
            children[0] = FIELDSTG_startEvent(0x50A);
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

void func_800A4DA0(void) {
    FLAGS_00.applyAction(0x407E, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4DEC(void) {
    FLAGS_00.applyAction(0x407F, 1);
    FLAGS_00.applyAction(0x8B0E, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x603
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x613
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x2C000, 0x25C00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x39;
    D_800990B4.music = 0x60E40000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A5090;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50B4;
extern Battle D_800A50C0;
extern Battle D_800A50CC;
extern Battle D_800A50D8;
extern Battle D_800A50E4;
extern Battle D_800A5114;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern Battle D_800A5138;
extern Battle D_800A5144;
extern Battle D_800A5150;
extern Battle D_800A515C;
extern Battle D_800A5168;
extern Battle D_800A5198;
extern Battle D_800A51A4;
extern Battle D_800A51B0;
extern Battle D_800A51BC;
extern Battle D_800A51C8;
extern Battle D_800A51D4;
extern Battle D_800A51E0;
extern Battle D_800A51EC;
extern Battle D_800A521C;
extern Battle D_800A5228;
extern Battle D_800A5234;
extern Battle D_800A5240;
extern Battle D_800A524C;
extern Battle D_800A5258;
extern Battle D_800A5264;
extern Battle D_800A5270;
extern BattleList D_800A50F0;
extern BattleList D_800A5174;
extern BattleList D_800A51F8;
extern BattleList D_800A527C;
extern u16 D_800A532C[];
extern u16 D_800A5334[];
extern u16 D_800A5340[];
extern u16 D_800A5348[];
extern u16 D_800A5350[];
extern u16 D_800A535C[];
extern u16 D_800A5364[];
extern u16 D_800A536C[];
extern u16 D_800A5378[];
extern u16 D_800A5380[];
extern u16 D_800A5388[];
extern u16 D_800A5394[];
extern u16 D_800A539C[];
extern u16 D_800A53A4[];
extern u16 D_800A53B0[];
extern u16 D_800A546C[];
extern FieldTalk D_800A53B8[];
extern u16 D_800A5474[];
extern FieldTalk D_800A53DC[];
extern u16 D_800A547C[];
extern FieldTalk D_800A5400[];
extern u16 D_800A5484[];
extern FieldTalk D_800A5424[];
extern u16 D_800A548C[];
extern FieldTalk D_800A5448[];
extern FieldActorEntry D_800A5494;
extern FieldActorEntry D_800A54A8;
extern FieldActorEntry D_800A54BC;
extern FieldActorEntry D_800A54D0;
extern FieldActorEntry D_800A54E4;
extern s16 D_800A4F4C[];
extern s16 D_800A4FEC[];

s16 D_800A4F4C[] = {
    0x600, 1, 2,
    0x102, 2, 0x275, 0xCE, 5,
    0x100, 0x109, 0x291, 0xB9,
    0x101, 0x109, 1, 1,
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
    0x200, 0, 2, 0x109, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x109, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x7\n");
#endif
s16 D_800A4FEC[] = {
    0x600, 1, 2,
    0x100, 2, 0x275, 0xCE,
    0x101, 2, 1, 5,
    0x100, 0x109, 0x290, 0xBF,
    0x101, 0x109, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x109, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x109, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x109, 0,
    0x301,
    0x300, 0x3C,
    0,
};
Battle D_800A5090 = { 116, 12, 0x60080000 };
Battle D_800A509C = { 116, 12, 0x60080000 };
Battle D_800A50A8 = { 116, 12, 0x60080000 };
Battle D_800A50B4 = { 116, 12, 0x60080000 };
Battle D_800A50C0 = { 164, 12, 0x60080000 };
Battle D_800A50CC = { 164, 12, 0x60080000 };
Battle D_800A50D8 = { 164, 12, 0x60080000 };
Battle D_800A50E4 = { 164, 12, 0x60080000 };
BattleList D_800A50F0 = {
    3,
    { &D_800A5090, &D_800A509C, &D_800A50A8, &D_800A50B4,
      &D_800A50C0, &D_800A50CC, &D_800A50D8, &D_800A50E4 },
};
Battle D_800A5114 = { 0, 0, 0x60040000 };
Battle D_800A5120 = { 0, 0, 0x60040000 };
Battle D_800A512C = { 0, 0, 0x60040000 };
Battle D_800A5138 = { 0, 0, 0x60040000 };
Battle D_800A5144 = { 0, 0, 0x60040000 };
Battle D_800A5150 = { 0, 0, 0x60040000 };
Battle D_800A515C = { 0, 0, 0x60040000 };
Battle D_800A5168 = { 0, 0, 0x60040000 };
BattleList D_800A5174 = {
    0,
    { &D_800A5114, &D_800A5120, &D_800A512C, &D_800A5138,
      &D_800A5144, &D_800A5150, &D_800A515C, &D_800A5168 },
};
Battle D_800A5198 = { 0, 0, 0x60040000 };
Battle D_800A51A4 = { 0, 0, 0x60040000 };
Battle D_800A51B0 = { 0, 0, 0x60040000 };
Battle D_800A51BC = { 0, 0, 0x60040000 };
Battle D_800A51C8 = { 0, 0, 0x60040000 };
Battle D_800A51D4 = { 0, 0, 0x60040000 };
Battle D_800A51E0 = { 0, 0, 0x60040000 };
Battle D_800A51EC = { 0, 0, 0x60040000 };
BattleList D_800A51F8 = {
    0,
    { &D_800A5198, &D_800A51A4, &D_800A51B0, &D_800A51BC,
      &D_800A51C8, &D_800A51D4, &D_800A51E0, &D_800A51EC },
};
Battle D_800A521C = { 23, 19, 0x60880000 };
Battle D_800A5228 = { 319, 19, 0x60880000 };
Battle D_800A5234 = { 0, 0, 0x60040000 };
Battle D_800A5240 = { 0, 0, 0x60040000 };
Battle D_800A524C = { 0, 0, 0x60040000 };
Battle D_800A5258 = { 0, 0, 0x60040000 };
Battle D_800A5264 = { 0, 0, 0x60040000 };
Battle D_800A5270 = { 0, 0, 0x60040000 };
BattleList D_800A527C = {
    0,
    { &D_800A521C, &D_800A5228, &D_800A5234, &D_800A5240,
      &D_800A524C, &D_800A5258, &D_800A5264, &D_800A5270 },
};
FieldBattles stageBattles[] = {
    { 111, 0, 0, { &D_800A50F0, &D_800A5174, &D_800A51F8, &D_800A527C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x15C, 0x100, 0x70, 0, 0x150, 0x1F9 },
};
u16 D_800A532C[] = { 0xA0B, 0, 0xFFFF };
u16 D_800A5334[] = { 0xA0B, 1, 0x903C, 1, 0xFFFF };
u16 D_800A5340[] = { 0xA0B, 1, 0xFFFF };
u16 D_800A5348[] = { 0xA0B, 0, 0xFFFF };
u16 D_800A5350[] = { 0xA0B, 1, 0x903C, 1, 0xFFFF };
u16 D_800A535C[] = { 0xA0B, 1, 0xFFFF };
u16 D_800A5364[] = { 0xA0B, 0, 0xFFFF };
u16 D_800A536C[] = { 0xA0B, 1, 0x903C, 1, 0xFFFF };
u16 D_800A5378[] = { 0xA0B, 1, 0xFFFF };
u16 D_800A5380[] = { 0xA0B, 0, 0xFFFF };
u16 D_800A5388[] = { 0xA0B, 1, 0x903C, 1, 0xFFFF };
u16 D_800A5394[] = { 0xA0B, 1, 0xFFFF };
u16 D_800A539C[] = { 0xA0B, 0, 0xFFFF };
u16 D_800A53A4[] = { 0xA0B, 1, 0x903C, 1, 0xFFFF };
u16 D_800A53B0[] = { 0xA0B, 1, 0xFFFF };
FieldTalk D_800A53B8[] = {
    { D_800A532C, D_800A5334, 0x2D5 },
    { D_800A5340, NULL, 0x110 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53DC[] = {
    { D_800A5348, D_800A5350, 0x2D5 },
    { D_800A535C, NULL, 0x113 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5400[] = {
    { D_800A5364, D_800A536C, 0x2D5 },
    { D_800A5378, NULL, 0x112 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5424[] = {
    { D_800A5380, D_800A5388, 0x2D5 },
    { D_800A5394, NULL, 0x111 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5448[] = {
    { D_800A539C, D_800A53A4, 0x2D5 },
    { D_800A53B0, NULL, 0x114 },
    { NULL, NULL, 0 },
};
u16 D_800A546C[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5474[] = { 0x701A, 1, 0xFFFF };
u16 D_800A547C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5484[] = { 0x6025, 1, 0xFFFF };
u16 D_800A548C[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A5494 = { D_800A546C, D_800A53B8, 0x109, 4, 657, 185, 1 };
FieldActorEntry D_800A54A8 = { D_800A5474, D_800A53DC, 0x109, 4, 657, 185, 1 };
FieldActorEntry D_800A54BC = { D_800A547C, D_800A5400, 0x109, 4, 657, 185, 1 };
FieldActorEntry D_800A54D0 = { D_800A5484, D_800A5424, 0x109, 4, 657, 185, 1 };
FieldActorEntry D_800A54E4 = { D_800A548C, D_800A5448, 0x109, 4, 657, 185, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5494,
    &D_800A54A8,
    &D_800A54BC,
    &D_800A54D0,
    &D_800A54E4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 5, 8, 0, 639, 174, 0, 0 },
    { 1, 0, 0x40, 2, 0x3C, 2, 0, 5, 8, 0, 671, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 6, 0, 782, 501, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 800, 478, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 6, 0, 576, 480, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 6, 0, 609, 493, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 6, 0, 646, 507, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 0xB, 8, 0, 587, 71, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 0xB, 8, 0, 573, 142, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 0xB, 8, 0, 705, 96, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 2, 0, 0xB, 8, 0, 692, 116, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 5, 8, 0, 709, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 0xB, 8, 0, 743, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 5, 6, 0, 710, 359, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 5, 6, 0, 758, 383, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 5, 6, 0, 854, 431, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 5, 6, 0, 32, 447, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 5, 6, 0, 416, 255, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 5, 6, 0, 463, 231, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B7, 0x110, 0x8C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B7, 0x3A8, 0xE4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B7, 0x468, 0xFC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1289, D_800A4F4C, EVENT_TEXT(8), NULL, func_800A4DA0 },
    { 1290, D_800A4FEC, EVENT_TEXT(9), NULL, func_800A4DEC },
    { -1, NULL, 0, NULL, NULL },
};
