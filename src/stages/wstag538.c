#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x407C, 1) && FLAGS_00.checkCondition(0x407D, 0)) {
            children[0] = FIELDSTG_startEvent(0x508);
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
    FLAGS_00.applyAction(0x407C, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4DEC(void) {
    FLAGS_00.applyAction(0x407D, 1);
    FLAGS_00.applyAction(0x8B00, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x5BE
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x5CE
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xCE00, 0xA700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x11;
    D_800990B4.music = 0x60440000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A5088;
extern Battle D_800A5094;
extern Battle D_800A50A0;
extern Battle D_800A50AC;
extern Battle D_800A50B8;
extern Battle D_800A50C4;
extern Battle D_800A50D0;
extern Battle D_800A50DC;
extern Battle D_800A510C;
extern Battle D_800A5118;
extern Battle D_800A5124;
extern Battle D_800A5130;
extern Battle D_800A513C;
extern Battle D_800A5148;
extern Battle D_800A5154;
extern Battle D_800A5160;
extern Battle D_800A5190;
extern Battle D_800A519C;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A5214;
extern Battle D_800A5220;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern BattleList D_800A50E8;
extern BattleList D_800A516C;
extern BattleList D_800A51F0;
extern BattleList D_800A5274;
extern u16 D_800A5334[];
extern u16 D_800A533C[];
extern u16 D_800A5348[];
extern u16 D_800A5350[];
extern u16 D_800A5360[];
extern u16 D_800A5370[];
extern u16 D_800A5384[];
extern u16 D_800A538C[];
extern u16 D_800A5398[];
extern u16 D_800A53A0[];
extern u16 D_800A53A8[];
extern u16 D_800A53B4[];
extern u16 D_800A53BC[];
extern u16 D_800A53C4[];
extern u16 D_800A53D0[];
extern u16 D_800A53D8[];
extern u16 D_800A53E0[];
extern u16 D_800A53EC[];
extern u16 D_800A53F4[];
extern u16 D_800A53FC[];
extern u16 D_800A5408[];
extern u16 D_800A5500[];
extern FieldTalk D_800A5410[];
extern u16 D_800A5514[];
extern FieldTalk D_800A544C[];
extern u16 D_800A551C[];
extern FieldTalk D_800A5470[];
extern u16 D_800A5524[];
extern FieldTalk D_800A5494[];
extern u16 D_800A552C[];
extern FieldTalk D_800A54B8[];
extern u16 D_800A5534[];
extern FieldTalk D_800A54DC[];
extern FieldActorEntry D_800A553C;
extern FieldActorEntry D_800A5550;
extern FieldActorEntry D_800A5564;
extern FieldActorEntry D_800A5578;
extern FieldActorEntry D_800A558C;
extern FieldActorEntry D_800A55A0;
extern s16 D_800A4F44[];
extern s16 D_800A4FE4[];

s16 D_800A4F44[] = {
    0x600, 1, 2,
    0x102, 2, 0x361, 0x94, 5,
    0x100, 0x107, 0x377, 0x85,
    0x101, 0x107, 1, 1,
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
    0x200, 0, 2, 0x107, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x107, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x300\n");
#endif
s16 D_800A4FE4[] = {
    0x600, 1, 2,
    0x100, 2, 0x361, 0x94,
    0x101, 2, 1, 5,
    0x100, 0x107, 0x377, 0x85,
    0x101, 0x107, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x107, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x107, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x107, 0,
    0x301,
    0x300, 0x3C,
    0,
};
Battle D_800A5088 = { 108, 6, 0x60080000 };
Battle D_800A5094 = { 108, 6, 0x60080000 };
Battle D_800A50A0 = { 108, 6, 0x60080000 };
Battle D_800A50AC = { 108, 6, 0x60080000 };
Battle D_800A50B8 = { 108, 6, 0x60080000 };
Battle D_800A50C4 = { 108, 6, 0x60080000 };
Battle D_800A50D0 = { 108, 6, 0x60080000 };
Battle D_800A50DC = { 108, 6, 0x60080000 };
BattleList D_800A50E8 = {
    4,
    { &D_800A5088, &D_800A5094, &D_800A50A0, &D_800A50AC,
      &D_800A50B8, &D_800A50C4, &D_800A50D0, &D_800A50DC },
};
Battle D_800A510C = { 0, 6, 0x60080000 };
Battle D_800A5118 = { 0, 6, 0x60080000 };
Battle D_800A5124 = { 0, 6, 0x60080000 };
Battle D_800A5130 = { 0, 6, 0x60080000 };
Battle D_800A513C = { 0, 6, 0x60080000 };
Battle D_800A5148 = { 0, 6, 0x60080000 };
Battle D_800A5154 = { 0, 6, 0x60080000 };
Battle D_800A5160 = { 0, 6, 0x60080000 };
BattleList D_800A516C = {
    0,
    { &D_800A510C, &D_800A5118, &D_800A5124, &D_800A5130,
      &D_800A513C, &D_800A5148, &D_800A5154, &D_800A5160 },
};
Battle D_800A5190 = { 0, 0, 0x60040000 };
Battle D_800A519C = { 0, 0, 0x60040000 };
Battle D_800A51A8 = { 0, 0, 0x60040000 };
Battle D_800A51B4 = { 0, 0, 0x60040000 };
Battle D_800A51C0 = { 0, 0, 0x60040000 };
Battle D_800A51CC = { 0, 0, 0x60040000 };
Battle D_800A51D8 = { 0, 0, 0x60040000 };
Battle D_800A51E4 = { 0, 0, 0x60040000 };
BattleList D_800A51F0 = {
    0,
    { &D_800A5190, &D_800A519C, &D_800A51A8, &D_800A51B4,
      &D_800A51C0, &D_800A51CC, &D_800A51D8, &D_800A51E4 },
};
Battle D_800A5214 = { 17, 19, 0x60880000 };
Battle D_800A5220 = { 318, 19, 0x60880000 };
Battle D_800A522C = { 0, 0, 0x60040000 };
Battle D_800A5238 = { 0, 0, 0x60040000 };
Battle D_800A5244 = { 0, 0, 0x60040000 };
Battle D_800A5250 = { 108, 6, 0x60080000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
BattleList D_800A5274 = {
    0,
    { &D_800A5214, &D_800A5220, &D_800A522C, &D_800A5238,
      &D_800A5244, &D_800A5250, &D_800A525C, &D_800A5268 },
};
FieldBattles stageBattles[] = {
    { 80, 0, 0, { &D_800A50E8, &D_800A516C, &D_800A51F0, &D_800A5274 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x170, 0x1F5 },
    { 0x180, 0x100, 0x180, 0x100, 0x100, 0, 0x160, 0x1F4 },
};
u16 D_800A5334[] = { 0x8675, 1, 0xFFFF };
u16 D_800A533C[] = { 0x8675, 0, 0, 0, 0xFFFF };
u16 D_800A5348[] = { 0, 1, 0xFFFF };
u16 D_800A5350[] = { 0x8675, 0, 0, 1, 0x8471, 0, 0xFFFF };
u16 D_800A5360[] = { 0x8675, 0, 0, 1, 0x8471, 1, 0xFFFF };
u16 D_800A5370[] = { 0x8675, 1, 0x8674, 0, 0x8471, 0, 0x7013, 1, 0xFFFF };
u16 D_800A5384[] = { 0xA0A, 0, 0xFFFF };
u16 D_800A538C[] = { 0xA0A, 1, 0x903B, 1, 0xFFFF };
u16 D_800A5398[] = { 0xA0A, 1, 0xFFFF };
u16 D_800A53A0[] = { 0xA0A, 0, 0xFFFF };
u16 D_800A53A8[] = { 0xA0A, 1, 0x903B, 1, 0xFFFF };
u16 D_800A53B4[] = { 0xA0A, 1, 0xFFFF };
u16 D_800A53BC[] = { 0xA0A, 0, 0xFFFF };
u16 D_800A53C4[] = { 0xA0A, 1, 0x903B, 1, 0xFFFF };
u16 D_800A53D0[] = { 0xA0A, 1, 0xFFFF };
u16 D_800A53D8[] = { 0xA0A, 0, 0xFFFF };
u16 D_800A53E0[] = { 0xA0A, 1, 0x903B, 1, 0xFFFF };
u16 D_800A53EC[] = { 0xA0A, 1, 0xFFFF };
u16 D_800A53F4[] = { 0xA0A, 0, 0xFFFF };
u16 D_800A53FC[] = { 0xA0A, 1, 0x903B, 1, 0xFFFF };
u16 D_800A5408[] = { 0xA0A, 1, 0xFFFF };
FieldTalk D_800A5410[] = {
    { D_800A5334, NULL, 0x2E6 },
    { D_800A533C, D_800A5348, 0x2E7 },
    { D_800A5350, NULL, 0x2E8 },
    { D_800A5360, D_800A5370, 0x2E9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A544C[] = {
    { D_800A5384, D_800A538C, 0x2D4 },
    { D_800A5398, NULL, 0xB5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5470[] = {
    { D_800A53A0, D_800A53A8, 0x2D4 },
    { D_800A53B4, NULL, 0xB9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5494[] = {
    { D_800A53BC, D_800A53C4, 0x2D4 },
    { D_800A53D0, NULL, 0xB8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B8[] = {
    { D_800A53D8, D_800A53E0, 0x2D4 },
    { D_800A53EC, NULL, 0xB7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54DC[] = {
    { D_800A53F4, D_800A53FC, 0x2D4 },
    { D_800A5408, NULL, 0xB6 },
    { NULL, NULL, 0 },
};
u16 D_800A5500[] = { 0x7044, 1, 0x704C, 1, 0x8674, 1, 0x8675, 0, 0xFFFF };
u16 D_800A5514[] = { 0x701D, 1, 0xFFFF };
u16 D_800A551C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5524[] = { 0x701A, 1, 0xFFFF };
u16 D_800A552C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5534[] = { 0x6025, 1, 0xFFFF };
FieldActorEntry D_800A553C = { D_800A5500, D_800A5410, 0xAD, 4, 962, 353, 1 };
FieldActorEntry D_800A5550 = { D_800A5514, D_800A544C, 0x107, 5, 887, 133, 1 };
FieldActorEntry D_800A5564 = { D_800A551C, D_800A5470, 0x107, 5, 887, 133, 1 };
FieldActorEntry D_800A5578 = { D_800A5524, D_800A5494, 0x107, 5, 887, 133, 1 };
FieldActorEntry D_800A558C = { D_800A552C, D_800A54B8, 0x107, 5, 887, 133, 1 };
FieldActorEntry D_800A55A0 = { D_800A5534, D_800A54DC, 0x107, 5, 887, 133, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A553C,
    &D_800A5550,
    &D_800A5564,
    &D_800A5578,
    &D_800A558C,
    &D_800A55A0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x70, 2, 0x36, 1, 0x36, 0x3B, 6, 0, 949, 142, 0, 0 },
    { 1, 0, 0x70, 2, 0x3C, 1, 0x3C, 0x41, 6, 0, 941, 141, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 999, 304, 0, 0 },
    { 1, 0, 0x78, 6, 0x32, 2, 0, 0xD, 8, 0, 1000, 393, 0, 0 },
    { 1, 0, 0x78, 6, 0x33, 2, 0, 0xD, 8, 0, 993, 389, 0, 0 },
    { 1, 0, 0x70, 6, 0x34, 2, 0, 0xD, 8, 0, 642, 153, 0, 0 },
    { 1, 0, 0x70, 6, 0x35, 2, 0, 0xD, 8, 0, 634, 144, 0, 0 },
    { 1, 0, 0x70, 6, 0x42, 1, 0x42, 0x47, 6, 0, 955, 71, 0, 0 },
    { 1, 0, 0x70, 6, 0x48, 1, 0x48, 0x4D, 6, 0, 946, 71, 0, 0 },
    { 1, 0, 0x70, 6, 0x4E, 1, 0x4E, 0x53, 6, 0, 618, 227, 0, 0 },
    { 1, 0, 0x70, 6, 0x4E, 1, 0x4E, 0x53, 6, 0, 730, 171, 0, 0 },
    { 1, 0, 0x70, 6, 0x54, 2, 0, 3, 6, 0, 614, 232, 0, 0 },
    { 1, 0, 0x70, 6, 0x54, 2, 0, 3, 6, 0, 726, 176, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 258, 102, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 531, 190, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 758, 111, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 806, 87, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 827, 275, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 859, 292, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 1002, 301, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 266, 105, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 539, 193, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 766, 114, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 814, 90, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 835, 279, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 867, 295, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 1010, 304, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2AF, 0x3E0, 0x1B0, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x3A0, 0x190, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x3B0, 0x1E8, 0, 0, 0, 0 },
    { { { 0xF, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1287, D_800A4F44, EVENT_TEXT(0x14), NULL, func_800A4DA0 },
    { 1288, D_800A4FE4, EVENT_TEXT(0x15), NULL, func_800A4DEC },
    { 9000, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
