#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };

/* Creates the event object that the flags call for, the first that applies */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (FLAGS_00.checkCondition(0x4025, 1) && FLAGS_00.checkCondition(0x4026, 0)) {
            children[0] = FIELDSTG_startEvent(0x4F4);
        } else if (FLAGS_00.checkCondition(0x402F, 1) && FLAGS_00.checkCondition(0x4030, 0)) {
            children[0] = FIELDSTG_startEvent(0x4FE);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void func_800A4DE8(void) {
    FLAGS_00.applyAction(0x4025, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4E34(void) {
    FLAGS_00.applyAction(0x4026, 1);
    FLAGS_00.applyAction(0x8022, 1);
}

void func_800A4E80(void) {
    FLAGS_00.applyAction(0x402F, 1);
    FLAGS_00.applyAction(0x7401, 1);
}

void func_800A4ECC(void) {
    FLAGS_00.applyAction(0x4030, 1);
    FLAGS_00.applyAction(0x818B, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x3EF
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x3FF
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x33900, 0x3D200};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x35;
    D_800990B4.music = 0x60D40000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

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
extern BattleList D_800A5290;
extern BattleList D_800A5314;
extern BattleList D_800A5398;
extern BattleList D_800A541C;
extern u16 D_800A550C[];
extern u16 D_800A5514[];
extern u16 D_800A5520[];
extern u16 D_800A5528[];
extern u16 D_800A5530[];
extern u16 D_800A553C[];
extern u16 D_800A5634[];
extern FieldTalk D_800A5544[];
extern u16 D_800A563C[];
extern FieldTalk D_800A555C[];
extern u16 D_800A5644[];
extern FieldTalk D_800A5574[];
extern u16 D_800A564C[];
extern FieldTalk D_800A558C[];
extern u16 D_800A5654[];
extern FieldTalk D_800A55A4[];
extern u16 D_800A565C[];
extern FieldTalk D_800A55BC[];
extern u16 D_800A5664[];
extern FieldTalk D_800A55D4[];
extern u16 D_800A5670[];
extern FieldTalk D_800A55F8[];
extern u16 D_800A567C[];
extern FieldTalk D_800A561C[];
extern FieldActorEntry D_800A5684;
extern FieldActorEntry D_800A5698;
extern FieldActorEntry D_800A56AC;
extern FieldActorEntry D_800A56C0;
extern FieldActorEntry D_800A56D4;
extern FieldActorEntry D_800A56E8;
extern FieldActorEntry D_800A56FC;
extern FieldActorEntry D_800A5710;
extern FieldActorEntry D_800A5724;
extern s16 D_800A5048[];
extern s16 D_800A50B8[];
extern s16 D_800A513C[];
extern s16 D_800A51AC[];

s16 D_800A5048[] = {
    0x600, 1, 2,
    0x102, 2, 0x3E5, 0x187, 5,
    0x100, 0x7E, 0x405, 0x177,
    0x101, 0x7E, 1, 1,
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
    0x200, 0, 2, 0x7E, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A50B8[] = {
    0x600, 1, 2,
    0x100, 2, 0x3E5, 0x187,
    0x101, 2, 1, 5,
    0x100, 0x7E, 0x405, 0x177,
    0x101, 0x7E, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0x7E, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x3C,
    0,
};
s16 D_800A513C[] = {
    0x600, 1, 2,
    0x102, 2, 0x138, 0x2D4, 3,
    0x100, 0x81, 0x118, 0x2C4,
    0x101, 0x81, 1, 7,
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
    0x200, 0, 2, 0x81, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A51AC[] = {
    0x600, 1, 2,
    0x100, 2, 0x138, 0x2D4,
    0x101, 2, 1, 3,
    0x100, 0x81, 0x118, 0x2C4,
    0x101, 0x81, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 2, 0x81, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x3C,
    0,
};
Battle D_800A5230 = { 152, 8, 0x60080000 };
Battle D_800A523C = { 152, 8, 0x60080000 };
Battle D_800A5248 = { 152, 8, 0x60080000 };
Battle D_800A5254 = { 152, 8, 0x60080000 };
Battle D_800A5260 = { 145, 8, 0x60080000 };
Battle D_800A526C = { 145, 8, 0x60080000 };
Battle D_800A5278 = { 58, 8, 0x60080000 };
Battle D_800A5284 = { 58, 8, 0x60080000 };
BattleList D_800A5290 = {
    3,
    { &D_800A5230, &D_800A523C, &D_800A5248, &D_800A5254,
      &D_800A5260, &D_800A526C, &D_800A5278, &D_800A5284 },
};
Battle D_800A52B4 = { 0, 0, 0x60040000 };
Battle D_800A52C0 = { 0, 0, 0x60040000 };
Battle D_800A52CC = { 0, 0, 0x60040000 };
Battle D_800A52D8 = { 0, 0, 0x60040000 };
Battle D_800A52E4 = { 0, 0, 0x60040000 };
Battle D_800A52F0 = { 0, 0, 0x60040000 };
Battle D_800A52FC = { 0, 0, 0x60040000 };
Battle D_800A5308 = { 0, 0, 0x60040000 };
BattleList D_800A5314 = {
    0,
    { &D_800A52B4, &D_800A52C0, &D_800A52CC, &D_800A52D8,
      &D_800A52E4, &D_800A52F0, &D_800A52FC, &D_800A5308 },
};
Battle D_800A5338 = { 0, 0, 0x60040000 };
Battle D_800A5344 = { 0, 0, 0x60040000 };
Battle D_800A5350 = { 0, 0, 0x60040000 };
Battle D_800A535C = { 0, 0, 0x60040000 };
Battle D_800A5368 = { 0, 0, 0x60040000 };
Battle D_800A5374 = { 0, 0, 0x60040000 };
Battle D_800A5380 = { 0, 0, 0x60040000 };
Battle D_800A538C = { 0, 0, 0x60040000 };
BattleList D_800A5398 = {
    0,
    { &D_800A5338, &D_800A5344, &D_800A5350, &D_800A535C,
      &D_800A5368, &D_800A5374, &D_800A5380, &D_800A538C },
};
Battle D_800A53BC = { 265, 8, 0x60880000 };
Battle D_800A53C8 = { 269, 8, 0x60880000 };
Battle D_800A53D4 = { 0, 0, 0x60040000 };
Battle D_800A53E0 = { 329, 8, 0x60080000 };
Battle D_800A53EC = { 328, 8, 0x60080000 };
Battle D_800A53F8 = { 0, 0, 0x60040000 };
Battle D_800A5404 = { 152, 8, 0x60080000 };
Battle D_800A5410 = { 59, 8, 0x60080000 };
BattleList D_800A541C = {
    0,
    { &D_800A53BC, &D_800A53C8, &D_800A53D4, &D_800A53E0,
      &D_800A53EC, &D_800A53F8, &D_800A5404, &D_800A5410 },
};
FieldBattles stageBattles[] = {
    { 20, 0, 0, { &D_800A5290, &D_800A5314, &D_800A5398, &D_800A541C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1F6, 0x158, 0x2D8, 0x58, 0x160, 0x1FE },
    { 0x1C0, 0x100, 0x1F0, 0x158, 0x2C0, 0x58, 0x170, 0x1FE },
    { 0x180, 0x100, 0x19E, 0x133, 0x178, 0x33, 0x150, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x1CC, 0x1C0, 0xCC, 0x160, 0x1FD },
    { 0x1C0, 0x100, 0x1C8, 0x15A, 0x220, 0x5A, 0x170, 0x1FD },
};
u16 D_800A550C[] = { 0x1C13, 0, 0xFFFF };
u16 D_800A5514[] = { 0x9026, 1, 0x1C13, 1, 0xFFFF };
u16 D_800A5520[] = { 0x1C13, 1, 0xFFFF };
u16 D_800A5528[] = { 0x1C18, 0, 0xFFFF };
u16 D_800A5530[] = { 0x902B, 1, 0x1C18, 1, 0xFFFF };
u16 D_800A553C[] = { 0x1C18, 1, 0xFFFF };
FieldTalk D_800A5544[] = {
    { NULL, NULL, 0x22 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A555C[] = {
    { NULL, NULL, 0x144 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5574[] = {
    { NULL, NULL, 0x147 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A558C[] = {
    { NULL, NULL, 0x145 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A4[] = {
    { NULL, NULL, 0x143 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55BC[] = {
    { NULL, NULL, 0x335 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55D4[] = {
    { D_800A550C, D_800A5514, 0x2BF },
    { D_800A5520, NULL, 0x2C0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55F8[] = {
    { D_800A5528, D_800A5530, 0x2C9 },
    { D_800A553C, NULL, 0x2CA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A561C[] = {
    { NULL, NULL, 0x146 },
    { NULL, NULL, 0 },
};
u16 D_800A5634[] = { 0x6019, 1, 0xFFFF };
u16 D_800A563C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5644[] = { 0x602B, 1, 0xFFFF };
u16 D_800A564C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5654[] = { 0x601A, 1, 0xFFFF };
u16 D_800A565C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5664[] = { 0x601, 1, 0x8022, 0, 0xFFFF };
u16 D_800A5670[] = { 0x605, 1, 0x818B, 0, 0xFFFF };
u16 D_800A567C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5684 = { D_800A5634, D_800A5544, 0x2E, 4, 561, 458, 7 };
FieldActorEntry D_800A5698 = { D_800A563C, D_800A555C, 0x2E, 4, 561, 458, 7 };
FieldActorEntry D_800A56AC = { D_800A5644, D_800A5574, 0x2E, 4, 561, 458, 7 };
FieldActorEntry D_800A56C0 = { D_800A564C, D_800A558C, 0x2E, 4, 561, 458, 7 };
FieldActorEntry D_800A56D4 = { D_800A5654, D_800A55A4, 0x2E, 4, 561, 458, 7 };
FieldActorEntry D_800A56E8 = { D_800A565C, D_800A55BC, 0x66, 5, 776, 996, 1 };
FieldActorEntry D_800A56FC = { D_800A5664, D_800A55D4, 0x7E, 6, 1029, 375, 1 };
FieldActorEntry D_800A5710 = { D_800A5670, D_800A55F8, 0x81, 7, 280, 708, 7 };
FieldActorEntry D_800A5724 = { D_800A567C, D_800A561C, 0x9D, 8, 561, 458, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5684,
    &D_800A5698,
    &D_800A56AC,
    &D_800A56C0,
    &D_800A56D4,
    &D_800A56E8,
    &D_800A56FC,
    &D_800A5710,
    &D_800A5724,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0xC, 1, 0xC, 0x11, 8, 0, 330, 130, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 1, 0xC, 0x11, 8, 0, 555, 650, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 1, 0xC, 0x11, 8, 0, 1017, 793, 0, 0 },
    { 1, 0, 0x70, 2, 0xA, 0, 0, 0, 0, 0, 896, 548, 0, 0 },
    { 1, 0, 0x78, 2, 0xB, 0, 0, 0, 0, 0, 768, 265, 0, 0 },
    { 1, 0, 0x40, 6, 0x62, 2, 0, 0xD, 0xA, 0, 902, 118, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 1, 0x58, 0x61, 0xA, 0, 324, 437, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 1, 0x58, 0x61, 0xA, 0, 480, 1007, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 1, 0x58, 0x61, 0xA, 0, 1091, 911, 0, 0 },
    { 1, 0, 0x40, 6, 0x28, 1, 0x28, 0x31, 0xA, 0, 259, 436, 0, 0 },
    { 1, 0, 0x40, 6, 0x28, 1, 0x28, 0x31, 0xA, 0, 452, 984, 0, 0 },
    { 1, 0, 0x40, 6, 0x28, 1, 0x28, 0x31, 0xA, 0, 1034, 904, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 70, 825, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 200, 1009, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 200, 1054, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 562, 1103, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 683, 1086, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 260, 993, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 155, 855, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 281, 1130, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 30, 836, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 220, 983, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 301, 1071, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 438, 1073, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 530, 1107, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 651, 1054, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 743, 1116, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 842, 1095, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 29, 789, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 148, 1013, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 162, 889, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 471, 1092, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 701, 1043, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 802, 1118, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 109, 831, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 166, 952, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 241, 980, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 336, 1112, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 377, 1083, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 502, 1067, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 588, 1055, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 599, 1017, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 659, 1036, 0, 0 },
    { 1, 0, 0x40, 4, 0x4F, 1, 0x4F, 0x57, 0xA, 0, 103, 696, 1152, 0 },
    { 1, 0, 0x40, 4, 0x4F, 1, 0x4F, 0x57, 0xA, 0, 287, 790, 1152, 0 },
    { 1, 0, 0x40, 4, 0x4F, 1, 0x4F, 0x57, 0xA, 0, 319, 634, 1152, 0 },
    { 1, 0, 0x40, 4, 0x4F, 1, 0x4F, 0x57, 0xA, 0, 331, 860, 1152, 0 },
    { 1, 0, 0x40, 4, 0x4F, 1, 0x4F, 0x57, 0xA, 0, 425, 935, 1152, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 566, 586, 673, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 455, 303, 335, 0 },
    { 1, 0, 0x50, 4, 1, 0, 0, 0, 0, 0, 1013, 384, 452, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 959, 427, 502, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 310, 860, 900, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 455, 303, 335, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 448, 513, 569, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 592, 744, 782, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 992, 151, 200, 0 },
    { 1, 0, 0x64, 4, 0x12, 0, 0, 0, 0, 0, 445, 977, 1021, 0 },
    { 1, 0, 0x64, 4, 0x13, 0, 0, 0, 0, 0, 896, 756, 810, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 80, 759, 759, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 224, 191, 191, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 223, 223, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 304, 247, 247, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 368, 471, 471, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 447, 647, 647, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 464, 439, 439, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 464, 615, 615, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 496, 471, 471, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 512, 559, 559, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 613, 879, 879, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 624, 839, 839, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 640, 447, 447, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 688, 487, 487, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 688, 887, 887, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 704, 543, 543, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 752, 935, 935, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 784, 871, 871, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 816, 823, 823, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23D, 0x372, 0x272, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x242, 0x90, 0x128, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23B, 0xA0, 0x80, 7, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 4, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 1, 2 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 4, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB0, 0x48, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB0, 0x20, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 4, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1267, D_800A5048, EVENT_TEXT(0x15), NULL, func_800A4DE8 },
    { 1268, D_800A50B8, EVENT_TEXT(0x16), NULL, func_800A4E34 },
    { 1277, D_800A513C, EVENT_TEXT(0x17), NULL, func_800A4E80 },
    { 1278, D_800A51AC, EVENT_TEXT(0x18), NULL, func_800A4ECC },
    { -1, NULL, 0, NULL, NULL },
};
