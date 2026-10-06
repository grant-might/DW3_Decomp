#include "common.h"
#include "stage.h"

/* The stage's task: a loop over its 14 children with nothing left in it (no object is created) */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (i = 0; i < 14; i++) {
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x38
#include "common/start_stage.inc.c"

extern FieldBattles D_800A5508[];
extern FieldBattles D_800A5524[];
extern FieldBattles D_800A5540[];
const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x1A9
#define STAGE_ARCHIVE 0x2C3
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x1B7
#define STAGE_ARCHIVE 0x2D2
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x19000, 0x12C00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 9;
    D_800990B4.music = 0x60240000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.spriteColor = stageColor;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress < 0xB) {
        D_800990B4.battles = D_800A5508;
    } else if (GAME.progress < 0x18) {
        D_800990B4.battles = D_800A5524;
    } else {
        D_800990B4.battles = D_800A5540;
    }
}

extern Battle D_800A4ED8;
extern Battle D_800A4EE4;
extern Battle D_800A4EF0;
extern Battle D_800A4EFC;
extern Battle D_800A4F08;
extern Battle D_800A4F14;
extern Battle D_800A4F20;
extern Battle D_800A4F2C;
extern Battle D_800A4F5C;
extern Battle D_800A4F68;
extern Battle D_800A4F74;
extern Battle D_800A4F80;
extern Battle D_800A4F8C;
extern Battle D_800A4F98;
extern Battle D_800A4FA4;
extern Battle D_800A4FB0;
extern Battle D_800A4FE0;
extern Battle D_800A4FEC;
extern Battle D_800A4FF8;
extern Battle D_800A5004;
extern Battle D_800A5010;
extern Battle D_800A501C;
extern Battle D_800A5028;
extern Battle D_800A5034;
extern Battle D_800A5064;
extern Battle D_800A5070;
extern Battle D_800A507C;
extern Battle D_800A5088;
extern Battle D_800A5094;
extern Battle D_800A50A0;
extern Battle D_800A50AC;
extern Battle D_800A50B8;
extern Battle D_800A50E8;
extern Battle D_800A50F4;
extern Battle D_800A5100;
extern Battle D_800A510C;
extern Battle D_800A5118;
extern Battle D_800A5124;
extern Battle D_800A5130;
extern Battle D_800A513C;
extern Battle D_800A516C;
extern Battle D_800A5178;
extern Battle D_800A5184;
extern Battle D_800A5190;
extern Battle D_800A519C;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51F0;
extern Battle D_800A51FC;
extern Battle D_800A5208;
extern Battle D_800A5214;
extern Battle D_800A5220;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5274;
extern Battle D_800A5280;
extern Battle D_800A528C;
extern Battle D_800A5298;
extern Battle D_800A52A4;
extern Battle D_800A52B0;
extern Battle D_800A52BC;
extern Battle D_800A52C8;
extern Battle D_800A52F8;
extern Battle D_800A5304;
extern Battle D_800A5310;
extern Battle D_800A531C;
extern Battle D_800A5328;
extern Battle D_800A5334;
extern Battle D_800A5340;
extern Battle D_800A534C;
extern Battle D_800A537C;
extern Battle D_800A5388;
extern Battle D_800A5394;
extern Battle D_800A53A0;
extern Battle D_800A53AC;
extern Battle D_800A53B8;
extern Battle D_800A53C4;
extern Battle D_800A53D0;
extern Battle D_800A5400;
extern Battle D_800A540C;
extern Battle D_800A5418;
extern Battle D_800A5424;
extern Battle D_800A5430;
extern Battle D_800A543C;
extern Battle D_800A5448;
extern Battle D_800A5454;
extern Battle D_800A5484;
extern Battle D_800A5490;
extern Battle D_800A549C;
extern Battle D_800A54A8;
extern Battle D_800A54B4;
extern Battle D_800A54C0;
extern Battle D_800A54CC;
extern Battle D_800A54D8;
extern BattleList D_800A4F38;
extern BattleList D_800A4FBC;
extern BattleList D_800A5040;
extern BattleList D_800A50C4;
extern BattleList D_800A5148;
extern BattleList D_800A51CC;
extern BattleList D_800A5250;
extern BattleList D_800A52D4;
extern BattleList D_800A5358;
extern BattleList D_800A53DC;
extern BattleList D_800A5460;
extern BattleList D_800A54E4;
extern u16 D_800A55DC[];
extern u16 D_800A55E4[];
extern u16 D_800A55F0[];
extern u16 D_800A55F8[];
extern u16 D_800A5604[];
extern u16 D_800A5610[];
extern u16 D_800A5618[];
extern u16 D_800A5620[];
extern u16 D_800A562C[];
extern u16 D_800A5638[];
extern u16 D_800A5640[];
extern u16 D_800A5648[];
extern u16 D_800A5650[];
extern u16 D_800A565C[];
extern u16 D_800A5668[];
extern u16 D_800A5670[];
extern u16 D_800A5678[];
extern u16 D_800A5680[];
extern u16 D_800A568C[];
extern u16 D_800A5698[];
extern u16 D_800A56A0[];
extern u16 D_800A56A8[];
extern u16 D_800A56B0[];
extern u16 D_800A56BC[];
extern u16 D_800A56C8[];
extern u16 D_800A56D8[];
extern u16 D_800A56E8[];
extern u16 D_800A56F0[];
extern u16 D_800A56F8[];
extern u16 D_800A5704[];
extern u16 D_800A570C[];
extern u16 D_800A571C[];
extern u16 D_800A5730[];
extern u16 D_800A5740[];
extern u16 D_800A574C[];
extern u16 D_800A5754[];
extern u16 D_800A5760[];
extern u16 D_800A576C[];
extern u16 D_800A58F4[];
extern FieldTalk D_800A5774[];
extern u16 D_800A5908[];
extern FieldTalk D_800A57A4[];
extern u16 D_800A591C[];
extern FieldTalk D_800A57D4[];
extern u16 D_800A5930[];
extern FieldTalk D_800A5804[];
extern u16 D_800A5944[];
extern FieldTalk D_800A5834[];
extern u16 D_800A5958[];
extern FieldTalk D_800A5870[];
extern u16 D_800A596C[];
extern FieldTalk D_800A58AC[];
extern u16 D_800A597C[];
extern FieldTalk D_800A58C4[];
extern FieldActorEntry D_800A5984;
extern FieldActorEntry D_800A5998;
extern FieldActorEntry D_800A59AC;
extern FieldActorEntry D_800A59C0;
extern FieldActorEntry D_800A59D4;
extern FieldActorEntry D_800A59E8;
extern FieldActorEntry D_800A59FC;
extern FieldActorEntry D_800A5A10;

Battle D_800A4ED8 = { 34, 1, 0x60080000 };
Battle D_800A4EE4 = { 34, 1, 0x60080000 };
Battle D_800A4EF0 = { 34, 1, 0x60080000 };
Battle D_800A4EFC = { 34, 1, 0x60080000 };
Battle D_800A4F08 = { 35, 1, 0x60080000 };
Battle D_800A4F14 = { 35, 1, 0x60080000 };
Battle D_800A4F20 = { 35, 1, 0x60080000 };
Battle D_800A4F2C = { 35, 1, 0x60080000 };
BattleList D_800A4F38 = {
    3,
    { &D_800A4ED8, &D_800A4EE4, &D_800A4EF0, &D_800A4EFC,
      &D_800A4F08, &D_800A4F14, &D_800A4F20, &D_800A4F2C },
};
Battle D_800A4F5C = { 34, 13, 0x60080000 };
Battle D_800A4F68 = { 34, 13, 0x60080000 };
Battle D_800A4F74 = { 34, 13, 0x60080000 };
Battle D_800A4F80 = { 34, 13, 0x60080000 };
Battle D_800A4F8C = { 35, 13, 0x60080000 };
Battle D_800A4F98 = { 35, 13, 0x60080000 };
Battle D_800A4FA4 = { 35, 13, 0x60080000 };
Battle D_800A4FB0 = { 35, 13, 0x60080000 };
BattleList D_800A4FBC = {
    3,
    { &D_800A4F5C, &D_800A4F68, &D_800A4F74, &D_800A4F80,
      &D_800A4F8C, &D_800A4F98, &D_800A4FA4, &D_800A4FB0 },
};
Battle D_800A4FE0 = { 0, 0, 0x60040000 };
Battle D_800A4FEC = { 0, 0, 0x60040000 };
Battle D_800A4FF8 = { 0, 0, 0x60040000 };
Battle D_800A5004 = { 0, 0, 0x60040000 };
Battle D_800A5010 = { 0, 0, 0x60040000 };
Battle D_800A501C = { 0, 0, 0x60040000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
BattleList D_800A5040 = {
    0,
    { &D_800A4FE0, &D_800A4FEC, &D_800A4FF8, &D_800A5004,
      &D_800A5010, &D_800A501C, &D_800A5028, &D_800A5034 },
};
Battle D_800A5064 = { 202, 13, 0x600C0000 };
Battle D_800A5070 = { 0, 0, 0x60040000 };
Battle D_800A507C = { 0, 0, 0x60040000 };
Battle D_800A5088 = { 327, 13, 0x60080000 };
Battle D_800A5094 = { 328, 8, 0x60080000 };
Battle D_800A50A0 = { 0, 0, 0x60040000 };
Battle D_800A50AC = { 49, 13, 0x60080000 };
Battle D_800A50B8 = { 54, 8, 0x60080000 };
BattleList D_800A50C4 = {
    0,
    { &D_800A5064, &D_800A5070, &D_800A507C, &D_800A5088,
      &D_800A5094, &D_800A50A0, &D_800A50AC, &D_800A50B8 },
};
Battle D_800A50E8 = { 48, 1, 0x60080000 };
Battle D_800A50F4 = { 48, 1, 0x60080000 };
Battle D_800A5100 = { 48, 1, 0x60080000 };
Battle D_800A510C = { 48, 1, 0x60080000 };
Battle D_800A5118 = { 48, 1, 0x60080000 };
Battle D_800A5124 = { 48, 1, 0x60080000 };
Battle D_800A5130 = { 35, 1, 0x60080000 };
Battle D_800A513C = { 35, 1, 0x60080000 };
BattleList D_800A5148 = {
    3,
    { &D_800A50E8, &D_800A50F4, &D_800A5100, &D_800A510C,
      &D_800A5118, &D_800A5124, &D_800A5130, &D_800A513C },
};
Battle D_800A516C = { 48, 13, 0x60080000 };
Battle D_800A5178 = { 48, 13, 0x60080000 };
Battle D_800A5184 = { 48, 13, 0x60080000 };
Battle D_800A5190 = { 48, 13, 0x60080000 };
Battle D_800A519C = { 48, 13, 0x60080000 };
Battle D_800A51A8 = { 48, 13, 0x60080000 };
Battle D_800A51B4 = { 35, 13, 0x60080000 };
Battle D_800A51C0 = { 35, 13, 0x60080000 };
BattleList D_800A51CC = {
    3,
    { &D_800A516C, &D_800A5178, &D_800A5184, &D_800A5190,
      &D_800A519C, &D_800A51A8, &D_800A51B4, &D_800A51C0 },
};
Battle D_800A51F0 = { 0, 0, 0x60040000 };
Battle D_800A51FC = { 0, 0, 0x60040000 };
Battle D_800A5208 = { 0, 0, 0x60040000 };
Battle D_800A5214 = { 0, 0, 0x60040000 };
Battle D_800A5220 = { 0, 0, 0x60040000 };
Battle D_800A522C = { 0, 0, 0x60040000 };
Battle D_800A5238 = { 0, 0, 0x60040000 };
Battle D_800A5244 = { 0, 0, 0x60040000 };
BattleList D_800A5250 = {
    0,
    { &D_800A51F0, &D_800A51FC, &D_800A5208, &D_800A5214,
      &D_800A5220, &D_800A522C, &D_800A5238, &D_800A5244 },
};
Battle D_800A5274 = { 202, 13, 0x600C0000 };
Battle D_800A5280 = { 0, 0, 0x60040000 };
Battle D_800A528C = { 0, 0, 0x60040000 };
Battle D_800A5298 = { 327, 13, 0x60080000 };
Battle D_800A52A4 = { 328, 8, 0x60080000 };
Battle D_800A52B0 = { 0, 0, 0x60040000 };
Battle D_800A52BC = { 49, 13, 0x60080000 };
Battle D_800A52C8 = { 54, 8, 0x60080000 };
BattleList D_800A52D4 = {
    0,
    { &D_800A5274, &D_800A5280, &D_800A528C, &D_800A5298,
      &D_800A52A4, &D_800A52B0, &D_800A52BC, &D_800A52C8 },
};
Battle D_800A52F8 = { 48, 1, 0x60080000 };
Battle D_800A5304 = { 48, 1, 0x60080000 };
Battle D_800A5310 = { 146, 1, 0x60080000 };
Battle D_800A531C = { 146, 1, 0x60080000 };
Battle D_800A5328 = { 146, 1, 0x60080000 };
Battle D_800A5334 = { 146, 1, 0x60080000 };
Battle D_800A5340 = { 146, 1, 0x60080000 };
Battle D_800A534C = { 146, 1, 0x60080000 };
BattleList D_800A5358 = {
    3,
    { &D_800A52F8, &D_800A5304, &D_800A5310, &D_800A531C,
      &D_800A5328, &D_800A5334, &D_800A5340, &D_800A534C },
};
Battle D_800A537C = { 48, 13, 0x60080000 };
Battle D_800A5388 = { 48, 13, 0x60080000 };
Battle D_800A5394 = { 146, 13, 0x60080000 };
Battle D_800A53A0 = { 146, 13, 0x60080000 };
Battle D_800A53AC = { 146, 13, 0x60080000 };
Battle D_800A53B8 = { 146, 13, 0x60080000 };
Battle D_800A53C4 = { 146, 13, 0x60080000 };
Battle D_800A53D0 = { 146, 13, 0x60080000 };
BattleList D_800A53DC = {
    3,
    { &D_800A537C, &D_800A5388, &D_800A5394, &D_800A53A0,
      &D_800A53AC, &D_800A53B8, &D_800A53C4, &D_800A53D0 },
};
Battle D_800A5400 = { 0, 0, 0x60040000 };
Battle D_800A540C = { 0, 0, 0x60040000 };
Battle D_800A5418 = { 0, 0, 0x60040000 };
Battle D_800A5424 = { 0, 0, 0x60040000 };
Battle D_800A5430 = { 0, 0, 0x60040000 };
Battle D_800A543C = { 0, 0, 0x60040000 };
Battle D_800A5448 = { 0, 0, 0x60040000 };
Battle D_800A5454 = { 0, 0, 0x60040000 };
BattleList D_800A5460 = {
    0,
    { &D_800A5400, &D_800A540C, &D_800A5418, &D_800A5424,
      &D_800A5430, &D_800A543C, &D_800A5448, &D_800A5454 },
};
Battle D_800A5484 = { 202, 13, 0x600C0000 };
Battle D_800A5490 = { 0, 0, 0x60040000 };
Battle D_800A549C = { 0, 0, 0x60040000 };
Battle D_800A54A8 = { 327, 13, 0x60080000 };
Battle D_800A54B4 = { 328, 8, 0x60080000 };
Battle D_800A54C0 = { 0, 0, 0x60040000 };
Battle D_800A54CC = { 49, 13, 0x60080000 };
Battle D_800A54D8 = { 54, 8, 0x60080000 };
BattleList D_800A54E4 = {
    0,
    { &D_800A5484, &D_800A5490, &D_800A549C, &D_800A54A8,
      &D_800A54B4, &D_800A54C0, &D_800A54CC, &D_800A54D8 },
};
FieldBattles D_800A5508[] = {
    { 2, 0, 0, { &D_800A4F38, &D_800A4FBC, &D_800A5040, &D_800A50C4 } },
};
FieldBattles D_800A5524[] = {
    { 25, 1, 0, { &D_800A5148, &D_800A51CC, &D_800A5250, &D_800A52D4 } },
};
FieldBattles D_800A5540[] = {
    { 50, 2, 0, { &D_800A5358, &D_800A53DC, &D_800A5460, &D_800A54E4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16C, 0x100, 0xB0, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x160, 0x1FF },
};
u16 D_800A55DC[] = { 0x11, 0, 0xFFFF };
u16 D_800A55E4[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A55F0[] = { 0x11, 0, 0xFFFF };
u16 D_800A55F8[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5604[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5610[] = { 0, 0, 0xFFFF };
u16 D_800A5618[] = { 0, 1, 0xFFFF };
u16 D_800A5620[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A562C[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A5638[] = { 0x7606, 1, 0xFFFF };
u16 D_800A5640[] = { 0, 0, 0xFFFF };
u16 D_800A5648[] = { 0, 1, 0xFFFF };
u16 D_800A5650[] = { 0x7209, 0, 0, 1, 0xFFFF };
u16 D_800A565C[] = { 0x7209, 1, 0, 1, 0xFFFF };
u16 D_800A5668[] = { 0x7606, 1, 0xFFFF };
u16 D_800A5670[] = { 0, 0, 0xFFFF };
u16 D_800A5678[] = { 0, 1, 0xFFFF };
u16 D_800A5680[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A568C[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A5698[] = { 0x7606, 1, 0xFFFF };
u16 D_800A56A0[] = { 0, 0, 0xFFFF };
u16 D_800A56A8[] = { 0, 1, 0xFFFF };
u16 D_800A56B0[] = { 0, 1, 0xE02, 0, 0xFFFF };
u16 D_800A56BC[] = { 0xE02, 1, 0x7400, 1, 0xFFFF };
u16 D_800A56C8[] = { 0, 1, 0xE02, 1, 0x720D, 0, 0xFFFF };
u16 D_800A56D8[] = { 0, 1, 0xE02, 1, 0x720D, 1, 0xFFFF };
u16 D_800A56E8[] = { 0x7806, 1, 0xFFFF };
u16 D_800A56F0[] = { 0x11, 0, 0xFFFF };
u16 D_800A56F8[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5704[] = { 0x11, 0, 0xFFFF };
u16 D_800A570C[] = { 0x10, 1, 0x920D, 0, 0x11, 1, 0xFFFF };
u16 D_800A571C[] = { 0x920D, 1, 0x11, 0, 0x7013, 1, 0x10, 0, 0xFFFF };
u16 D_800A5730[] = { 0x10, 1, 0x920D, 1, 0x11, 1, 0xFFFF };
u16 D_800A5740[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A574C[] = { 0, 0, 0xFFFF };
u16 D_800A5754[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A5760[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A576C[] = { 0x7606, 1, 0xFFFF };
FieldTalk D_800A5774[] = {
    { D_800A55DC, NULL, 0x6C },
    { D_800A55E4, D_800A55F0, 0x29 },
    { D_800A55F8, D_800A5604, 0x2A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57A4[] = {
    { D_800A5610, D_800A5618, 0x6C },
    { D_800A5620, NULL, 0x70 },
    { D_800A562C, D_800A5638, 0x71 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57D4[] = {
    { D_800A5640, D_800A5648, 0x6D },
    { D_800A5650, NULL, 0x70 },
    { D_800A565C, D_800A5668, 0x71 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5804[] = {
    { D_800A5670, D_800A5678, 0x6E },
    { D_800A5680, NULL, 0x70 },
    { D_800A568C, D_800A5698, 0x71 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5834[] = {
    { D_800A56A0, D_800A56A8, 0x74 },
    { D_800A56B0, D_800A56BC, 0x75 },
    { D_800A56C8, NULL, 0x76 },
    { D_800A56D8, D_800A56E8, 0x77 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5870[] = {
    { D_800A56F0, NULL, 0x6C },
    { D_800A56F8, D_800A5704, 0x2B },
    { D_800A570C, D_800A571C, 0x2C },
    { D_800A5730, D_800A5740, 0x2D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58AC[] = {
    { NULL, NULL, 0x271 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C4[] = {
    { D_800A574C, NULL, 0x6F },
    { D_800A5754, NULL, 0x6F },
    { D_800A5760, D_800A576C, 0x6F },
    { NULL, NULL, 0 },
};
u16 D_800A58F4[] = { 0x11, 1, 0x8192, 1, 0x700A, 1, 0x8012, 0, 0xFFFF };
u16 D_800A5908[] = { 0x7003, 1, 0x8192, 1, 0x11, 0, 0x8012, 0, 0xFFFF };
u16 D_800A591C[] = { 0x7004, 1, 0x8192, 1, 0x11, 0, 0x8012, 0, 0xFFFF };
u16 D_800A5930[] = { 0x11, 0, 0x8192, 1, 0x6026, 1, 0x8012, 0, 0xFFFF };
u16 D_800A5944[] = { 0x8192, 1, 0x11, 0, 0x8012, 1, 0x7022, 1, 0xFFFF };
u16 D_800A5958[] = { 0x8192, 1, 0x11, 1, 0x8012, 1, 0x7022, 1, 0xFFFF };
u16 D_800A596C[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A597C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5984 = { D_800A58F4, D_800A5774, 0x2F, 4, 593, 289, 1 };
FieldActorEntry D_800A5998 = { D_800A5908, D_800A57A4, 0x2F, 4, 593, 289, 1 };
FieldActorEntry D_800A59AC = { D_800A591C, D_800A57D4, 0x2F, 4, 593, 289, 1 };
FieldActorEntry D_800A59C0 = { D_800A5930, D_800A5804, 0x2F, 4, 593, 289, 1 };
FieldActorEntry D_800A59D4 = { D_800A5944, D_800A5834, 0x2F, 4, 593, 289, 1 };
FieldActorEntry D_800A59E8 = { D_800A5958, D_800A5870, 0x2F, 4, 593, 289, 1 };
FieldActorEntry D_800A59FC = { D_800A596C, D_800A58AC, 0x2F, 4, 593, 289, 1 };
FieldActorEntry D_800A5A10 = { D_800A597C, D_800A58C4, 0x9D, 5, 593, 289, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5984,
    &D_800A5998,
    &D_800A59AC,
    &D_800A59C0,
    &D_800A59D4,
    &D_800A59E8,
    &D_800A59FC,
    &D_800A5A10,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 199, 607, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 353, -16, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 513, 285, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 113, 393, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 153, 554, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 167, 539, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 192, 494, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 225, 493, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 251, 483, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 313, 468, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 86, 400, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 169, 500, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 193, 527, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 216, 519, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 235, 480, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 248, 454, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 253, 491, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 264, 469, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 58, 404, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 130, 393, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 214, 356, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 233, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 204, 360, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 273, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 219, 483, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 289, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 307, 382, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 317, 385, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 323, 421, 0, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 184, 226, 226, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 232, 250, 250, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 243, 544, 544, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 267, 602, 602, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 271, 135, 135, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 277, 521, 521, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 159, 159, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 399, 167, 167, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 422, 187, 187, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 431, 568, 568, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 489, 501, 501, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 506, 203, 203, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 542, 228, 228, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 641, 286, 286, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x21D, 0x5F4, 0x39E, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x221, 0x138, 0x7A, 7, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC8, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
