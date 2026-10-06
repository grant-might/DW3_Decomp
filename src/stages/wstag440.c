#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 6 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress == 6) {
            children[0] = FIELDSTG_startEvent(0x98);
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

void func_800A4D70(void) {
    GAME.progress = 7;
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x36D
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x37D
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1A000, 0x21C00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xE;
    D_800990B4.music = 0x60380000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4F8C;
extern Battle D_800A4F98;
extern Battle D_800A4FA4;
extern Battle D_800A4FB0;
extern Battle D_800A4FBC;
extern Battle D_800A4FC8;
extern Battle D_800A4FD4;
extern Battle D_800A4FE0;
extern Battle D_800A5010;
extern Battle D_800A501C;
extern Battle D_800A5028;
extern Battle D_800A5034;
extern Battle D_800A5040;
extern Battle D_800A504C;
extern Battle D_800A5058;
extern Battle D_800A5064;
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
extern BattleList D_800A4FEC;
extern BattleList D_800A5070;
extern BattleList D_800A50F4;
extern BattleList D_800A5178;
extern u16 D_800A5268[];
extern u16 D_800A5270[];
extern u16 D_800A5278[];
extern u16 D_800A5284[];
extern u16 D_800A5294[];
extern u16 D_800A529C[];
extern u16 D_800A52B0[];
extern u16 D_800A52BC[];
extern u16 D_800A52D4[];
extern u16 D_800A52F0[];
extern u16 D_800A530C[];
extern u16 D_800A5314[];
extern u16 D_800A531C[];
extern u16 D_800A5324[];
extern u16 D_800A5330[];
extern u16 D_800A5340[];
extern u16 D_800A5348[];
extern u16 D_800A535C[];
extern u16 D_800A5368[];
extern u16 D_800A5380[];
extern u16 D_800A539C[];
extern u16 D_800A53B8[];
extern u16 D_800A53C0[];
extern u16 D_800A53C8[];
extern u16 D_800A53D0[];
extern u16 D_800A53DC[];
extern u16 D_800A53EC[];
extern u16 D_800A53F4[];
extern u16 D_800A5408[];
extern u16 D_800A5414[];
extern u16 D_800A542C[];
extern u16 D_800A5448[];
extern u16 D_800A5464[];
extern u16 D_800A546C[];
extern u16 D_800A5474[];
extern u16 D_800A5480[];
extern u16 D_800A5488[];
extern u16 D_800A5494[];
extern u16 D_800A54A0[];
extern u16 D_800A54A8[];
extern u16 D_800A54B0[];
extern u16 D_800A54BC[];
extern u16 D_800A54CC[];
extern u16 D_800A54D4[];
extern u16 D_800A54E8[];
extern u16 D_800A54F0[];
extern u16 D_800A5508[];
extern u16 D_800A5524[];
extern u16 D_800A5540[];
extern u16 D_800A5890[];
extern FieldTalk D_800A5548[];
extern u16 D_800A58A0[];
extern FieldTalk D_800A55A8[];
extern u16 D_800A58B0[];
extern FieldTalk D_800A5608[];
extern u16 D_800A58C0[];
extern FieldTalk D_800A5668[];
extern u16 D_800A58D0[];
extern FieldTalk D_800A5698[];
extern u16 D_800A58E0[];
extern FieldTalk D_800A56B0[];
extern u16 D_800A58E8[];
extern FieldTalk D_800A56C8[];
extern u16 D_800A58F0[];
extern FieldTalk D_800A56E0[];
extern u16 D_800A58F8[];
extern FieldTalk D_800A56F8[];
extern u16 D_800A5900[];
extern FieldTalk D_800A5710[];
extern u16 D_800A5908[];
extern FieldTalk D_800A5728[];
extern u16 D_800A5910[];
extern FieldTalk D_800A5740[];
extern u16 D_800A5918[];
extern FieldTalk D_800A5758[];
extern u16 D_800A5920[];
extern FieldTalk D_800A5770[];
extern u16 D_800A5928[];
extern FieldTalk D_800A5788[];
extern u16 D_800A5930[];
extern FieldTalk D_800A57A0[];
extern u16 D_800A5938[];
extern FieldTalk D_800A57B8[];
extern u16 D_800A5940[];
extern FieldTalk D_800A57D0[];
extern u16 D_800A5948[];
extern FieldTalk D_800A57E8[];
extern FieldTalk D_800A5800[];
extern u16 D_800A5950[];
extern FieldTalk D_800A5818[];
extern u16 D_800A5958[];
extern FieldTalk D_800A5878[];
extern FieldActorEntry D_800A5960;
extern FieldActorEntry D_800A5974;
extern FieldActorEntry D_800A5988;
extern FieldActorEntry D_800A599C;
extern FieldActorEntry D_800A59B0;
extern FieldActorEntry D_800A59C4;
extern FieldActorEntry D_800A59D8;
extern FieldActorEntry D_800A59EC;
extern FieldActorEntry D_800A5A00;
extern FieldActorEntry D_800A5A14;
extern FieldActorEntry D_800A5A28;
extern FieldActorEntry D_800A5A3C;
extern FieldActorEntry D_800A5A50;
extern FieldActorEntry D_800A5A64;
extern FieldActorEntry D_800A5A78;
extern FieldActorEntry D_800A5A8C;
extern FieldActorEntry D_800A5AA0;
extern FieldActorEntry D_800A5AB4;
extern FieldActorEntry D_800A5AC8;
extern FieldActorEntry D_800A5ADC;
extern FieldActorEntry D_800A5AF0;
extern FieldActorEntry D_800A5B04;
extern s16 D_800A4F44[];
extern s16 D_800A4EC8[];

s16 D_800A4EC8[] = {
    0x102, 2, 0x1BF, 0x120, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x338, 2,
    0x300, 0x78,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 4,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x1A0, 0x130, 1,
    0x302, 2,
    0x102, 2, 0x150, 0x109, 3,
    0x300, 0x3C,
    0x304, 0x22C, 0x140, 0x140, 5,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x8E02\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x128\n");
#endif
s16 D_800A4F44[] = {
    0x601, 1, 0x1AF, 0xD9,
    0x100, 2, 0x1EF, 0xB9,
    0x101, 2, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 2, 1,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x16F, 0xF9, 1,
    0x300, 0x3C,
    0x304, 0x233, 0x208, 0x9C, 7,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x8FBF\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x1FB\n");
#endif
Battle D_800A4F8C = { 0, 0, 0x60040000 };
Battle D_800A4F98 = { 0, 0, 0x60040000 };
Battle D_800A4FA4 = { 0, 0, 0x60040000 };
Battle D_800A4FB0 = { 0, 0, 0x60040000 };
Battle D_800A4FBC = { 0, 0, 0x60040000 };
Battle D_800A4FC8 = { 0, 0, 0x60040000 };
Battle D_800A4FD4 = { 0, 0, 0x60040000 };
Battle D_800A4FE0 = { 0, 0, 0x60040000 };
BattleList D_800A4FEC = {
    3,
    { &D_800A4F8C, &D_800A4F98, &D_800A4FA4, &D_800A4FB0,
      &D_800A4FBC, &D_800A4FC8, &D_800A4FD4, &D_800A4FE0 },
};
Battle D_800A5010 = { 0, 0, 0x60040000 };
Battle D_800A501C = { 0, 0, 0x60040000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 0, 0, 0x60040000 };
Battle D_800A504C = { 0, 0, 0x60040000 };
Battle D_800A5058 = { 0, 0, 0x60040000 };
Battle D_800A5064 = { 0, 0, 0x60040000 };
BattleList D_800A5070 = {
    0,
    { &D_800A5010, &D_800A501C, &D_800A5028, &D_800A5034,
      &D_800A5040, &D_800A504C, &D_800A5058, &D_800A5064 },
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
Battle D_800A5118 = { 210, 20, 0x600C0000 };
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
FieldBattles stageBattles[] = {
    { 156, 0, 0, { &D_800A4FEC, &D_800A5070, &D_800A50F4, &D_800A5178 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x158, 0x150, 0x60, 0x50, 0x170, 0x1FE },
    { 0x140, 0x100, 0x140, 0x150, 0, 0x50, 0x160, 0x1FD },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x148, 0x150, 0x20, 0x50, 0x170, 0x1FD },
    { 0x140, 0x100, 0x150, 0x150, 0x40, 0x50, 0x160, 0x1FC },
};
u16 D_800A5268[] = { 0, 0, 0xFFFF };
u16 D_800A5270[] = { 0, 1, 0xFFFF };
u16 D_800A5278[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5284[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A5294[] = { 0x7614, 1, 0xFFFF };
u16 D_800A529C[] = { 0, 1, 0x7202, 1, 0xE0A, 0, 0x7204, 1, 0xFFFF };
u16 D_800A52B0[] = { 0x7400, 1, 0xE0A, 1, 0xFFFF };
u16 D_800A52BC[] = {
    0x7202, 1, 0xE0A, 1, 0, 1, 0x7204, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A52D4[] = {
    0, 1, 0x7204, 1, 0x8012, 1, 0x7202, 1,
    0xE0A, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A52F0[] = {
    0, 1, 0x7204, 1, 0x8012, 1, 0x7202, 1,
    0xE0A, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A530C[] = { 0x7814, 1, 0xFFFF };
u16 D_800A5314[] = { 0, 0, 0xFFFF };
u16 D_800A531C[] = { 0, 1, 0xFFFF };
u16 D_800A5324[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5330[] = { 0, 1, 0x7204, 0, 0x7202, 1, 0xFFFF };
u16 D_800A5340[] = { 0x7614, 1, 0xFFFF };
u16 D_800A5348[] = { 0, 1, 0x7204, 1, 0x7202, 1, 0xE0A, 0, 0xFFFF };
u16 D_800A535C[] = { 0x7400, 1, 0xE0A, 1, 0xFFFF };
u16 D_800A5368[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0A, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5380[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0A, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A539C[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0A, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A53B8[] = { 0x7814, 1, 0xFFFF };
u16 D_800A53C0[] = { 0, 0, 0xFFFF };
u16 D_800A53C8[] = { 0, 1, 0xFFFF };
u16 D_800A53D0[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A53DC[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A53EC[] = { 0x7614, 1, 0xFFFF };
u16 D_800A53F4[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0A, 0, 0xFFFF };
u16 D_800A5408[] = { 0x7400, 1, 0xE0A, 1, 0xFFFF };
u16 D_800A5414[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0A, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A542C[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0A, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A5448[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0A, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A5464[] = { 0x7814, 1, 0xFFFF };
u16 D_800A546C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5474[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5480[] = { 0x11, 0, 0xFFFF };
u16 D_800A5488[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5494[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A54A0[] = { 0x9060, 1, 0xFFFF };
u16 D_800A54A8[] = { 0, 0, 0xFFFF };
u16 D_800A54B0[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A54BC[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A54CC[] = { 0x7614, 1, 0xFFFF };
u16 D_800A54D4[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0A, 0, 0xFFFF };
u16 D_800A54E8[] = { 0xE0A, 1, 0xFFFF };
u16 D_800A54F0[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0A, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5508[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0A, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A5524[] = {
    0, 1, 0x7202, 1, 0x7206, 1, 0x7204, 1,
    0x8012, 1, 0xE0A, 1, 0xFFFF,
};
u16 D_800A5540[] = { 0x7814, 1, 0xFFFF };
FieldTalk D_800A5548[] = {
    { D_800A5268, D_800A5270, 0x8A },
    { D_800A5278, NULL, 0x8F },
    { D_800A5284, D_800A5294, 0x90 },
    { D_800A529C, D_800A52B0, 0x91 },
    { D_800A52BC, NULL, 0x92 },
    { D_800A52D4, NULL, 0x93 },
    { D_800A52F0, D_800A530C, 0x94 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A8[] = {
    { D_800A5314, D_800A531C, 0x8B },
    { D_800A5324, NULL, 0x8F },
    { D_800A5330, D_800A5340, 0x90 },
    { D_800A5348, D_800A535C, 0x91 },
    { D_800A5368, NULL, 0x92 },
    { D_800A5380, NULL, 0x93 },
    { D_800A539C, D_800A53B8, 0x94 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5608[] = {
    { D_800A53C0, D_800A53C8, 0x8C },
    { D_800A53D0, NULL, 0x8F },
    { D_800A53DC, D_800A53EC, 0x90 },
    { D_800A53F4, D_800A5408, 0x91 },
    { D_800A5414, NULL, 0x92 },
    { D_800A542C, NULL, 0x93 },
    { D_800A5448, D_800A5464, 0x94 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5668[] = {
    { D_800A546C, NULL, 0x8A },
    { D_800A5474, D_800A5480, 0x95 },
    { D_800A5488, D_800A5494, 0x96 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5698[] = {
    { NULL, NULL, 0x27E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56B0[] = {
    { NULL, NULL, 0x1E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56C8[] = {
    { NULL, NULL, 0xF8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56E0[] = {
    { NULL, NULL, 0xFC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56F8[] = {
    { NULL, NULL, 0x1E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5710[] = {
    { NULL, NULL, 0x1E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5728[] = {
    { NULL, NULL, 0xF9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5740[] = {
    { NULL, NULL, 0xF2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5758[] = {
    { NULL, NULL, 0xF3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5770[] = {
    { NULL, NULL, 0xF4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5788[] = {
    { NULL, NULL, 0xF5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57A0[] = {
    { NULL, NULL, 0xF6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57B8[] = {
    { NULL, NULL, 0xF7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57D0[] = {
    { NULL, NULL, 0xFA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57E8[] = {
    { NULL, NULL, 0xF8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5800[] = {
    { NULL, D_800A54A0, 0x32B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5818[] = {
    { D_800A54A8, NULL, 0x8D },
    { D_800A54B0, NULL, 0x8D },
    { D_800A54BC, D_800A54CC, 0x8D },
    { D_800A54D4, D_800A54E8, 0x8D },
    { D_800A54F0, NULL, 0x8D },
    { D_800A5508, NULL, 0x8D },
    { D_800A5524, D_800A5540, 0x8D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5878[] = {
    { NULL, NULL, 0xFB },
    { NULL, NULL, 0 },
};
u16 D_800A5890[] = { 0x7003, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A58A0[] = { 0x7004, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A58B0[] = { 0x6026, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A58C0[] = { 0x7009, 1, 0x8192, 1, 0x11, 1, 0xFFFF };
u16 D_800A58D0[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A58E0[] = { 0x6007, 1, 0xFFFF };
u16 D_800A58E8[] = { 0x6019, 1, 0xFFFF };
u16 D_800A58F0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A58F8[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5900[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5908[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5910[] = { 0x600A, 1, 0xFFFF };
u16 D_800A5918[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5920[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5928[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5930[] = { 0x7017, 1, 0xFFFF };
u16 D_800A5938[] = { 0x6018, 1, 0xFFFF };
u16 D_800A5940[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5948[] = { 0x601A, 1, 0xFFFF };
u16 D_800A5950[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5958[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5960 = { D_800A5890, D_800A5548, 0x2D, 4, 177, 313, 7 };
FieldActorEntry D_800A5974 = { D_800A58A0, D_800A55A8, 0x2D, 4, 177, 313, 7 };
FieldActorEntry D_800A5988 = { D_800A58B0, D_800A5608, 0x2D, 4, 177, 313, 7 };
FieldActorEntry D_800A599C = { D_800A58C0, D_800A5668, 0x2D, 4, 177, 313, 7 };
FieldActorEntry D_800A59B0 = { D_800A58D0, D_800A5698, 0x2D, 4, 177, 313, 7 };
FieldActorEntry D_800A59C4 = { D_800A58E0, D_800A56B0, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A59D8 = { D_800A58E8, D_800A56C8, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A59EC = { D_800A58F0, D_800A56E0, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5A00 = { D_800A58F8, D_800A56F8, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5A14 = { D_800A5900, D_800A5710, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5A28 = { D_800A5908, D_800A5728, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5A3C = { D_800A5910, D_800A5740, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5A50 = { D_800A5918, D_800A5758, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5A64 = { D_800A5920, D_800A5770, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5A78 = { D_800A5928, D_800A5788, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5A8C = { D_800A5930, D_800A57A0, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5AA0 = { D_800A5938, D_800A57B8, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5AB4 = { D_800A5940, D_800A57D0, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5AC8 = { D_800A5948, D_800A57E8, 0x2E, 5, 145, 329, 5 };
FieldActorEntry D_800A5ADC = { NULL, D_800A5800, 0x3F, 6, 463, 280, 1 };
FieldActorEntry D_800A5AF0 = { D_800A5950, D_800A5818, 0x9D, 7, 177, 313, 7 };
FieldActorEntry D_800A5B04 = { D_800A5958, D_800A5878, 0x9E, 8, 145, 329, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A5960,
    &D_800A5974,
    &D_800A5988,
    &D_800A599C,
    &D_800A59B0,
    &D_800A59C4,
    &D_800A59D8,
    &D_800A59EC,
    &D_800A5A00,
    &D_800A5A14,
    &D_800A5A28,
    &D_800A5A3C,
    &D_800A5A50,
    &D_800A5A64,
    &D_800A5A78,
    &D_800A5A8C,
    &D_800A5AA0,
    &D_800A5AB4,
    &D_800A5AC8,
    &D_800A5ADC,
    &D_800A5AF0,
    &D_800A5B04,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 9, 0, 435, 247, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 1, 0x33, 0x38, 9, 0, 443, 254, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 5, 6, 0, 443, 348, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x3F, 6, 0, 377, 384, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 482, 177, 200, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x233, 0x208, 0x9C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 152, D_800A4F44, EVENT_TEXT(6), NULL, func_800A4D70 },
    { 144, D_800A4EC8, EVENT_TEXT(0x21), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
