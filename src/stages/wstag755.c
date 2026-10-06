#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };

/* Creates the event object of story progress 0x1E once flag 0x4001 is set */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress == 0x1E && FLAGS_00.checkCondition(0x4001, 1)) {
            children[0] = FIELDSTG_startEvent(0x30D);
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

void func_800A4D8C(void) {
    FLAGS_00.applyAction(0x4001, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Sets the progress to 31 and applies flag action 0x800C */
void func_800A4DD8(void) {
    GAME.progress = 31;
    FLAGS_00.applyAction(0x800C, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6C3
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6D2
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x19200, 0x34F00};
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

void func_800A4DD8();
extern Battle D_800A50A4;
extern Battle D_800A50B0;
extern Battle D_800A50BC;
extern Battle D_800A50C8;
extern Battle D_800A50D4;
extern Battle D_800A50E0;
extern Battle D_800A50EC;
extern Battle D_800A50F8;
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
extern BattleList D_800A5104;
extern BattleList D_800A5188;
extern BattleList D_800A520C;
extern BattleList D_800A5290;
extern u16 D_800A5370[];
extern u16 D_800A5380[];
extern u16 D_800A5388[];
extern u16 D_800A5398[];
extern u16 D_800A53A0[];
extern u16 D_800A5504[];
extern FieldTalk D_800A53A8[];
extern u16 D_800A550C[];
extern FieldTalk D_800A53C0[];
extern u16 D_800A5514[];
extern FieldTalk D_800A53D8[];
extern u16 D_800A551C[];
extern FieldTalk D_800A53F0[];
extern u16 D_800A5524[];
extern FieldTalk D_800A5408[];
extern u16 D_800A552C[];
extern FieldTalk D_800A5420[];
extern u16 D_800A5534[];
extern FieldTalk D_800A5438[];
extern u16 D_800A553C[];
extern FieldTalk D_800A5450[];
extern u16 D_800A5544[];
extern FieldTalk D_800A5468[];
extern u16 D_800A554C[];
extern FieldTalk D_800A5480[];
extern u16 D_800A5554[];
extern FieldTalk D_800A5498[];
extern u16 D_800A5560[];
extern FieldTalk D_800A54B0[];
extern u16 D_800A5568[];
extern FieldTalk D_800A54EC[];
extern FieldActorEntry D_800A5570;
extern FieldActorEntry D_800A5584;
extern FieldActorEntry D_800A5598;
extern FieldActorEntry D_800A55AC;
extern FieldActorEntry D_800A55C0;
extern FieldActorEntry D_800A55D4;
extern FieldActorEntry D_800A55E8;
extern FieldActorEntry D_800A55FC;
extern FieldActorEntry D_800A5610;
extern FieldActorEntry D_800A5624;
extern FieldActorEntry D_800A5638;
extern FieldActorEntry D_800A564C;
extern FieldActorEntry D_800A5660;
extern s16 D_800A4F28[];
extern s16 D_800A4FBC[];

s16 D_800A4F28[] = {
    0x102, 2, 0x40A, 0xAD, 5,
    0x100, 0x8E, 0x42A, 0x9D,
    0x101, 0x8E, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 0x8E, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x8E, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0,
};
s16 D_800A4FBC[] = {
    0x100, 2, 0x40A, 0xAD,
    0x101, 2, 1, 5,
    0x100, 0x8E, 0x42A, 0x9D,
    0x101, 0x8E, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0x8E, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x8E, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 5, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 6, 0x8E, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x3DA, 0xC5, 1,
    0x300, 6,
    0x304, 0x26F, 0x78, 0x21C, 5,
    0,
};
Battle D_800A50A4 = { 0, 0, 0x60040000 };
Battle D_800A50B0 = { 0, 0, 0x60040000 };
Battle D_800A50BC = { 0, 0, 0x60040000 };
Battle D_800A50C8 = { 0, 0, 0x60040000 };
Battle D_800A50D4 = { 0, 0, 0x60040000 };
Battle D_800A50E0 = { 0, 0, 0x60040000 };
Battle D_800A50EC = { 0, 0, 0x60040000 };
Battle D_800A50F8 = { 0, 0, 0x60040000 };
BattleList D_800A5104 = {
    3,
    { &D_800A50A4, &D_800A50B0, &D_800A50BC, &D_800A50C8,
      &D_800A50D4, &D_800A50E0, &D_800A50EC, &D_800A50F8 },
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
    0,
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
Battle D_800A5230 = { 18, 18, 0x608C0000 };
Battle D_800A523C = { 304, 18, 0x608C0000 };
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
FieldBattles stageBattles[] = {
    { 167, 0, 0, { &D_800A5104, &D_800A5188, &D_800A520C, &D_800A5290 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B4, 0x100, 0x1D0, 0, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1B4, 0x120, 0x1D0, 0x20, 0x140, 0x1FE },
    { 0x140, 0x100, 0x174, 0x120, 0xD0, 0x20, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1B0, 0x193, 0x1C0, 0x93, 0x160, 0x1FE },
};
u16 D_800A5370[] = { 0x6020, 0, 0x6021, 0, 5, 0, 0xFFFF };
u16 D_800A5380[] = { 5, 1, 0xFFFF };
u16 D_800A5388[] = { 0x6020, 0, 0x6021, 0, 5, 1, 0xFFFF };
u16 D_800A5398[] = { 0x6020, 1, 0xFFFF };
u16 D_800A53A0[] = { 0x6021, 1, 0xFFFF };
FieldTalk D_800A53A8[] = {
    { NULL, NULL, 0x169 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53C0[] = {
    { NULL, NULL, 0x168 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53D8[] = {
    { NULL, NULL, 0x167 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53F0[] = {
    { NULL, NULL, 0x166 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5408[] = {
    { NULL, NULL, 0x165 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5420[] = {
    { NULL, NULL, 0x163 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5438[] = {
    { NULL, NULL, 0x162 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5450[] = {
    { NULL, NULL, 0x164 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5468[] = {
    { NULL, NULL, 0x161 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5480[] = {
    { NULL, NULL, 0x15F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5498[] = {
    { NULL, NULL, 0x15E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B0[] = {
    { D_800A5370, D_800A5380, 0x15E },
    { D_800A5388, NULL, 8 },
    { D_800A5398, NULL, 0x15E },
    { D_800A53A0, NULL, 0x15E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54EC[] = {
    { NULL, NULL, 0x160 },
    { NULL, NULL, 0 },
};
u16 D_800A5504[] = { 0x602B, 1, 0xFFFF };
u16 D_800A550C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5514[] = { 0x6026, 1, 0xFFFF };
u16 D_800A551C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5524[] = { 0x602B, 1, 0xFFFF };
u16 D_800A552C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5534[] = { 0x7019, 1, 0xFFFF };
u16 D_800A553C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5544[] = { 0x602B, 1, 0xFFFF };
u16 D_800A554C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5554[] = { 0x7019, 1, 0x7020, 0, 0xFFFF };
u16 D_800A5560[] = { 0x7020, 1, 0xFFFF };
u16 D_800A5568[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5570 = { D_800A5504, D_800A53A8, 0x40, 4, 641, 449, 1 };
FieldActorEntry D_800A5584 = { D_800A550C, D_800A53C0, 0x40, 4, 641, 449, 1 };
FieldActorEntry D_800A5598 = { D_800A5514, D_800A53D8, 0x40, 4, 641, 449, 1 };
FieldActorEntry D_800A55AC = { D_800A551C, D_800A53F0, 0x40, 4, 641, 449, 1 };
FieldActorEntry D_800A55C0 = { D_800A5524, D_800A5408, 0x41, 5, 929, 593, 1 };
FieldActorEntry D_800A55D4 = { D_800A552C, D_800A5420, 0x41, 5, 929, 593, 1 };
FieldActorEntry D_800A55E8 = { D_800A5534, D_800A5438, 0x41, 5, 929, 593, 1 };
FieldActorEntry D_800A55FC = { D_800A553C, D_800A5450, 0x41, 5, 929, 593, 1 };
FieldActorEntry D_800A5610 = { D_800A5544, D_800A5468, 0x8E, 6, 1066, 157, 1 };
FieldActorEntry D_800A5624 = { D_800A554C, D_800A5480, 0x8E, 6, 1066, 157, 1 };
FieldActorEntry D_800A5638 = { D_800A5554, D_800A5498, 0x8E, 6, 1066, 157, 1 };
FieldActorEntry D_800A564C = { D_800A5560, D_800A54B0, 0x8E, 6, 1066, 157, 1 };
FieldActorEntry D_800A5660 = { D_800A5568, D_800A54EC, 0x9D, 7, 1066, 157, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5570,
    &D_800A5584,
    &D_800A5598,
    &D_800A55AC,
    &D_800A55C0,
    &D_800A55D4,
    &D_800A55E8,
    &D_800A55FC,
    &D_800A5610,
    &D_800A5624,
    &D_800A5638,
    &D_800A564C,
    &D_800A5660,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x44, 2, 0xC, 0, 0, 0, 0, 0, 1087, 451, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 1022, 436, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x39, 4, 0, 672, 291, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x41, 4, 0, 700, 302, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x45, 4, 0, 696, 569, 0, 0 },
    { 1, 0x64, 0x40, 6, 5, 0, 0, 0, 0, 0, 1035, 452, 0, 0 },
    { 1, 0x65, 0x40, 6, 6, 0, 0, 0, 0, 0, 843, 356, 0, 0 },
    { 1, 0x66, 0x48, 6, 7, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x48, 6, 8, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x48, 6, 9, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x48, 6, 0xA, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 0, 0, 0x48, 6, 0xB, 0, 0, 0, 0, 0, 777, 548, 0, 0 },
    { 1, 0, 0x4F, 4, 0, 0, 0, 0, 0, 0, 821, 545, 623, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1055, 451, 505, 0 },
    { 1, 0, 0x41, 4, 2, 0, 0, 0, 0, 0, 864, 348, 412, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 783, 246, 264, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 785, 410, 448, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 715, 589, 612, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 912, 533, 559, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 896, 539, 580, 0 },
    { 1, 0, 0x40, 4, 0x12, 0, 0, 0, 0, 0, 908, 539, 574, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x264, 0x508, 0x6C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26F, 0x78, 0x21C, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26F, 0x398, 0x3AC, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26F, 0x1F0, 0x358, 5, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 7, 0x328, 0x108, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 7, 0x318, 0x180, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 7, 0x3D8, 0xC0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 7, 0x3C8, 0x138, 0, 0, 0, 0 },
    { { { 0x601E, 1 }, { 0x4001, 0 } }, 8, 0x30C, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 780, D_800A4F28, EVENT_TEXT(0x10), NULL, func_800A4D8C },
    { 781, D_800A4FBC, EVENT_TEXT(0x11), NULL, func_800A4DD8 },
    { -1, NULL, 0, NULL, NULL },
};
