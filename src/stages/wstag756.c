#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };

/* Creates the event object of story progress 0xD or 0x23 that applies */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress == 0xD && FLAGS_00.checkCondition(0x1C0D, 1)) {
            children[0] = FIELDSTG_startEvent(0x160);
        } else if (GAME.progress == 0x23 && FLAGS_00.checkCondition(0x405B, 1)) {
            children[0] = FIELDSTG_startEvent(0x38F);
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

void func_800A4DC0(void) {
    FLAGS_00.applyAction(0x405B, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Sets the story progress to 36 and flag 0x8019 */
void func_800A4E0C(void) {
    GAME.progress = 36;
    FLAGS_00.applyAction(0x8019, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6C6
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6D5
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1B000, 0x34100};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2F;
    D_800990B4.music = 0x60BC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

void func_800A4E0C();
extern Battle D_800A5094;
extern Battle D_800A50A0;
extern Battle D_800A50AC;
extern Battle D_800A50B8;
extern Battle D_800A50C4;
extern Battle D_800A50D0;
extern Battle D_800A50DC;
extern Battle D_800A50E8;
extern Battle D_800A5118;
extern Battle D_800A5124;
extern Battle D_800A5130;
extern Battle D_800A513C;
extern Battle D_800A5148;
extern Battle D_800A5154;
extern Battle D_800A5160;
extern Battle D_800A516C;
extern Battle D_800A519C;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A51F0;
extern Battle D_800A5220;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5274;
extern BattleList D_800A50F4;
extern BattleList D_800A5178;
extern BattleList D_800A51FC;
extern BattleList D_800A5280;
extern u16 D_800A53B0[];
extern u16 D_800A53B8[];
extern u16 D_800A53C0[];
extern u16 D_800A53C8[];
extern u16 D_800A53D0[];
extern u16 D_800A53D8[];
extern u16 D_800A5578[];
extern FieldTalk D_800A53E0[];
extern u16 D_800A5580[];
extern FieldTalk D_800A5410[];
extern u16 D_800A5588[];
extern FieldTalk D_800A5428[];
extern u16 D_800A5590[];
extern FieldTalk D_800A5440[];
extern u16 D_800A5598[];
extern FieldTalk D_800A5470[];
extern u16 D_800A55A0[];
extern FieldTalk D_800A5488[];
extern u16 D_800A55A8[];
extern FieldTalk D_800A54A0[];
extern u16 D_800A55B0[];
extern FieldTalk D_800A54B8[];
extern u16 D_800A55B8[];
extern FieldTalk D_800A54D0[];
extern u16 D_800A55C8[];
extern FieldTalk D_800A54E8[];
extern u16 D_800A55D4[];
extern FieldTalk D_800A5500[];
extern u16 D_800A55DC[];
extern FieldTalk D_800A5518[];
extern u16 D_800A55E8[];
extern FieldTalk D_800A5530[];
extern u16 D_800A55F0[];
extern FieldTalk D_800A5548[];
extern u16 D_800A55FC[];
extern FieldTalk D_800A5560[];
extern u16 D_800A5604[];
extern FieldActorEntry D_800A560C;
extern FieldActorEntry D_800A5620;
extern FieldActorEntry D_800A5634;
extern FieldActorEntry D_800A5648;
extern FieldActorEntry D_800A565C;
extern FieldActorEntry D_800A5670;
extern FieldActorEntry D_800A5684;
extern FieldActorEntry D_800A5698;
extern FieldActorEntry D_800A56AC;
extern FieldActorEntry D_800A56C0;
extern FieldActorEntry D_800A56D4;
extern FieldActorEntry D_800A56E8;
extern FieldActorEntry D_800A56FC;
extern FieldActorEntry D_800A5710;
extern FieldActorEntry D_800A5724;
extern FieldActorEntry D_800A5738;
extern s16 D_800A4F5C[];
extern s16 D_800A4FF8[];

s16 D_800A4F5C[] = {
    0x102, 2, 0x40A, 0xAD, 5,
    0x100, 0xD2, 0x42A, 0x9D,
    0x101, 0xD2, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 3,
    0x101, 2, 1, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0,
};
s16 D_800A4FF8[] = {
    0x100, 2, 0x40A, 0xAD,
    0x101, 2, 1, 5,
    0x100, 0x13C, 0x42A, 0x9D,
    0x101, 0x13C, 1, 5,
    0x300, 0x78,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x422, 0xA1, 5,
    0x302, 2,
    0x300, 0x1E,
    0x100, 0x13C, 0, 0,
    0x101, 0x13C, 1, 5,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x3DA, 0xC5, 1,
    0x300, 6,
    0x304, 0x2D6, 0x78, 0x21C, 5,
    0,
};
Battle D_800A5094 = { 0, 0, 0x60040000 };
Battle D_800A50A0 = { 0, 0, 0x60040000 };
Battle D_800A50AC = { 0, 0, 0x60040000 };
Battle D_800A50B8 = { 0, 0, 0x60040000 };
Battle D_800A50C4 = { 0, 0, 0x60040000 };
Battle D_800A50D0 = { 0, 0, 0x60040000 };
Battle D_800A50DC = { 0, 0, 0x60040000 };
Battle D_800A50E8 = { 0, 0, 0x60040000 };
BattleList D_800A50F4 = {
    0,
    { &D_800A5094, &D_800A50A0, &D_800A50AC, &D_800A50B8,
      &D_800A50C4, &D_800A50D0, &D_800A50DC, &D_800A50E8 },
};
Battle D_800A5118 = { 0, 0, 0x60040000 };
Battle D_800A5124 = { 0, 0, 0x60040000 };
Battle D_800A5130 = { 0, 0, 0x60040000 };
Battle D_800A513C = { 0, 0, 0x60040000 };
Battle D_800A5148 = { 0, 0, 0x60040000 };
Battle D_800A5154 = { 0, 0, 0x60040000 };
Battle D_800A5160 = { 0, 0, 0x60040000 };
Battle D_800A516C = { 0, 0, 0x60040000 };
BattleList D_800A5178 = {
    0,
    { &D_800A5118, &D_800A5124, &D_800A5130, &D_800A513C,
      &D_800A5148, &D_800A5154, &D_800A5160, &D_800A516C },
};
Battle D_800A519C = { 0, 0, 0x60040000 };
Battle D_800A51A8 = { 0, 0, 0x60040000 };
Battle D_800A51B4 = { 0, 0, 0x60040000 };
Battle D_800A51C0 = { 0, 0, 0x60040000 };
Battle D_800A51CC = { 0, 0, 0x60040000 };
Battle D_800A51D8 = { 0, 0, 0x60040000 };
Battle D_800A51E4 = { 0, 0, 0x60040000 };
Battle D_800A51F0 = { 0, 0, 0x60040000 };
BattleList D_800A51FC = {
    0,
    { &D_800A519C, &D_800A51A8, &D_800A51B4, &D_800A51C0,
      &D_800A51CC, &D_800A51D8, &D_800A51E4, &D_800A51F0 },
};
Battle D_800A5220 = { 26, 18, 0x608C0000 };
Battle D_800A522C = { 308, 18, 0x608C0000 };
Battle D_800A5238 = { 0, 0, 0x60040000 };
Battle D_800A5244 = { 0, 0, 0x60040000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
Battle D_800A5274 = { 0, 0, 0x60040000 };
BattleList D_800A5280 = {
    0,
    { &D_800A5220, &D_800A522C, &D_800A5238, &D_800A5244,
      &D_800A5250, &D_800A525C, &D_800A5268, &D_800A5274 },
};
FieldBattles stageBattles[] = {
    { 153, 0, 0, { &D_800A50F4, &D_800A5178, &D_800A51FC, &D_800A5280 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1A8, 0x1C3, 0x1A0, 0xC3, 0x140, 0x1FE },
    { 0x180, 0x100, 0x180, 0x1CF, 0x100, 0xCF, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1B4, 0x100, 0x1D0, 0, 0x170, 0x1FE },
    { 0x180, 0x100, 0x190, 0x1AF, 0x140, 0xAF, 0x150, 0x1FD },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x160, 0x1FD },
    { 0x180, 0x100, 0x198, 0x1AF, 0x160, 0xAF, 0x170, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x1BB, 0x1C0, 0xBB, 0x140, 0x1FC },
    { 0x180, 0x100, 0x1A0, 0x1C3, 0x180, 0xC3, 0x150, 0x1FC },
    { 0x140, 0x100, 0x16C, 0x1A3, 0xB0, 0xA3, 0x160, 0x1FC },
};
u16 D_800A53B0[] = { 0x701D, 1, 0xFFFF };
u16 D_800A53B8[] = { 0x6025, 1, 0xFFFF };
u16 D_800A53C0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A53C8[] = { 0x701D, 1, 0xFFFF };
u16 D_800A53D0[] = { 0x6025, 1, 0xFFFF };
u16 D_800A53D8[] = { 0x6026, 1, 0xFFFF };
FieldTalk D_800A53E0[] = {
    { D_800A53B0, NULL, 0x1DA },
    { D_800A53B8, NULL, 0x1DB },
    { D_800A53C0, NULL, 0x1DC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5410[] = {
    { NULL, NULL, 0x1DD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5428[] = {
    { NULL, NULL, 0x1DE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5440[] = {
    { D_800A53C8, NULL, 0x1DF },
    { D_800A53D0, NULL, 0x1E0 },
    { D_800A53D8, NULL, 0x1E1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5470[] = {
    { NULL, NULL, 0x1E2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5488[] = {
    { NULL, NULL, 0x1E3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54A0[] = {
    { NULL, NULL, 0x1E9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B8[] = {
    { NULL, NULL, 0x1E8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54D0[] = {
    { NULL, NULL, 0x1E7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E8[] = {
    { NULL, NULL, 0x1E4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5500[] = {
    { NULL, NULL, 0x1E4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5518[] = {
    { NULL, NULL, 0x1E5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5530[] = {
    { NULL, NULL, 0x1E5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5548[] = {
    { NULL, NULL, 0x1E6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5560[] = {
    { NULL, NULL, 0x1E6 },
    { NULL, NULL, 0 },
};
u16 D_800A5578[] = { 0x701E, 1, 0xFFFF };
u16 D_800A5580[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5588[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5590[] = { 0x701E, 1, 0xFFFF };
u16 D_800A5598[] = { 0x701A, 1, 0xFFFF };
u16 D_800A55A0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A55A8[] = { 0x6023, 1, 0xFFFF };
u16 D_800A55B0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A55B8[] = { 0x405B, 0, 0x6024, 0, 0x701D, 1, 0xFFFF };
u16 D_800A55C8[] = { 0x701E, 1, 0x7021, 0, 0xFFFF };
u16 D_800A55D4[] = { 0x6022, 1, 0xFFFF };
u16 D_800A55DC[] = { 0x701E, 1, 0x7021, 0, 0xFFFF };
u16 D_800A55E8[] = { 0x6022, 1, 0xFFFF };
u16 D_800A55F0[] = { 0x701E, 1, 0x7021, 0, 0xFFFF };
u16 D_800A55FC[] = { 0x6022, 1, 0xFFFF };
u16 D_800A5604[] = { 0x6023, 1, 0xFFFF };
FieldActorEntry D_800A560C = { D_800A5578, D_800A53E0, 0x22, 4, 641, 449, 1 };
FieldActorEntry D_800A5620 = { D_800A5580, D_800A5410, 0x22, 4, 641, 449, 1 };
FieldActorEntry D_800A5634 = { D_800A5588, D_800A5428, 0x22, 4, 641, 449, 1 };
FieldActorEntry D_800A5648 = { D_800A5590, D_800A5440, 0x23, 5, 929, 593, 1 };
FieldActorEntry D_800A565C = { D_800A5598, D_800A5470, 0x23, 5, 929, 593, 1 };
FieldActorEntry D_800A5670 = { D_800A55A0, D_800A5488, 0x23, 5, 929, 593, 1 };
FieldActorEntry D_800A5684 = { D_800A55A8, D_800A54A0, 0x74, 6, 559, 776, 1 };
FieldActorEntry D_800A5698 = { D_800A55B0, D_800A54B8, 0x92, 7, 1066, 157, 1 };
FieldActorEntry D_800A56AC = { D_800A55B8, D_800A54D0, 0xD2, 8, 1066, 157, 1 };
FieldActorEntry D_800A56C0 = { D_800A55C8, D_800A54E8, 0x12B, 9, 520, 757, 1 };
FieldActorEntry D_800A56D4 = { D_800A55D4, D_800A5500, 0x12B, 9, 520, 757, 1 };
FieldActorEntry D_800A56E8 = { D_800A55DC, D_800A5518, 0x12F, 0xA, 544, 769, 1 };
FieldActorEntry D_800A56FC = { D_800A55E8, D_800A5530, 0x12F, 0xA, 544, 769, 1 };
FieldActorEntry D_800A5710 = { D_800A55F0, D_800A5548, 0x130, 0xB, 568, 781, 1 };
FieldActorEntry D_800A5724 = { D_800A55FC, D_800A5560, 0x130, 0xB, 568, 781, 1 };
FieldActorEntry D_800A5738 = { D_800A5604, NULL, 0x13C, 0xC, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A560C,
    &D_800A5620,
    &D_800A5634,
    &D_800A5648,
    &D_800A565C,
    &D_800A5670,
    &D_800A5684,
    &D_800A5698,
    &D_800A56AC,
    &D_800A56C0,
    &D_800A56D4,
    &D_800A56E8,
    &D_800A56FC,
    &D_800A5710,
    &D_800A5724,
    &D_800A5738,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 1087, 451, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 0, 0, 0, 0, 0, 1022, 436, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x39, 4, 0, 672, 291, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x41, 4, 0, 700, 302, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x45, 4, 0, 696, 569, 0, 0 },
    { 1, 0x64, 0x40, 6, 6, 0, 0, 0, 0, 0, 1035, 452, 0, 0 },
    { 1, 0x65, 0x40, 6, 7, 0, 0, 0, 0, 0, 843, 356, 0, 0 },
    { 1, 0x66, 0x40, 6, 8, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x40, 6, 9, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x40, 6, 0xA, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x40, 6, 0xB, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x40, 6, 0xC, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 821, 545, 623, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1055, 451, 505, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 864, 348, 412, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 783, 246, 264, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 785, 410, 448, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 715, 589, 612, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 912, 533, 559, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 896, 539, 580, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 908, 539, 574, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CC, 0x508, 0x6C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D6, 0x78, 0x21C, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D6, 0x398, 0x3AC, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D6, 0x1F0, 0x358, 5, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 7, 0x328, 0x108, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 7, 0x318, 0x180, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 7, 0x3D8, 0xC0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 7, 0x3C8, 0x138, 0, 0, 0, 0 },
    { { { 0x6023, 1 }, { 0x405B, 0 } }, 8, 0x38E, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 910, D_800A4F5C, EVENT_TEXT(0x12), NULL, func_800A4DC0 },
    { 911, D_800A4FF8, EVENT_TEXT(0x13), NULL, func_800A4E0C },
    { -1, NULL, 0, NULL, NULL },
};
