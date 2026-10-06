#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D4C(void) {
    GAME.progress = 9;
}

extern FieldBattles D_800A5664[];
extern FieldBattles D_800A5680[];
extern FieldBattles D_800A569C[];
const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x2AC
#define STAGE_ARCHIVE 0x320
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x2BB
#define STAGE_ARCHIVE 0x32F
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x13D00, 0x34000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 9;
    D_800990B4.music = 0x60240000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress < 0xB) {
        D_800990B4.battles = D_800A5664;
    } else if (GAME.progress < 0x18) {
        D_800990B4.battles = D_800A5680;
    } else {
        D_800990B4.battles = D_800A569C;
    }
}

extern Battle D_800A5034;
extern Battle D_800A5040;
extern Battle D_800A504C;
extern Battle D_800A5058;
extern Battle D_800A5064;
extern Battle D_800A5070;
extern Battle D_800A507C;
extern Battle D_800A5088;
extern Battle D_800A50B8;
extern Battle D_800A50C4;
extern Battle D_800A50D0;
extern Battle D_800A50DC;
extern Battle D_800A50E8;
extern Battle D_800A50F4;
extern Battle D_800A5100;
extern Battle D_800A510C;
extern Battle D_800A513C;
extern Battle D_800A5148;
extern Battle D_800A5154;
extern Battle D_800A5160;
extern Battle D_800A516C;
extern Battle D_800A5178;
extern Battle D_800A5184;
extern Battle D_800A5190;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A51F0;
extern Battle D_800A51FC;
extern Battle D_800A5208;
extern Battle D_800A5214;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5274;
extern Battle D_800A5280;
extern Battle D_800A528C;
extern Battle D_800A5298;
extern Battle D_800A52C8;
extern Battle D_800A52D4;
extern Battle D_800A52E0;
extern Battle D_800A52EC;
extern Battle D_800A52F8;
extern Battle D_800A5304;
extern Battle D_800A5310;
extern Battle D_800A531C;
extern Battle D_800A534C;
extern Battle D_800A5358;
extern Battle D_800A5364;
extern Battle D_800A5370;
extern Battle D_800A537C;
extern Battle D_800A5388;
extern Battle D_800A5394;
extern Battle D_800A53A0;
extern Battle D_800A53D0;
extern Battle D_800A53DC;
extern Battle D_800A53E8;
extern Battle D_800A53F4;
extern Battle D_800A5400;
extern Battle D_800A540C;
extern Battle D_800A5418;
extern Battle D_800A5424;
extern Battle D_800A5454;
extern Battle D_800A5460;
extern Battle D_800A546C;
extern Battle D_800A5478;
extern Battle D_800A5484;
extern Battle D_800A5490;
extern Battle D_800A549C;
extern Battle D_800A54A8;
extern Battle D_800A54D8;
extern Battle D_800A54E4;
extern Battle D_800A54F0;
extern Battle D_800A54FC;
extern Battle D_800A5508;
extern Battle D_800A5514;
extern Battle D_800A5520;
extern Battle D_800A552C;
extern Battle D_800A555C;
extern Battle D_800A5568;
extern Battle D_800A5574;
extern Battle D_800A5580;
extern Battle D_800A558C;
extern Battle D_800A5598;
extern Battle D_800A55A4;
extern Battle D_800A55B0;
extern Battle D_800A55E0;
extern Battle D_800A55EC;
extern Battle D_800A55F8;
extern Battle D_800A5604;
extern Battle D_800A5610;
extern Battle D_800A561C;
extern Battle D_800A5628;
extern Battle D_800A5634;
extern BattleList D_800A5094;
extern BattleList D_800A5118;
extern BattleList D_800A519C;
extern BattleList D_800A5220;
extern BattleList D_800A52A4;
extern BattleList D_800A5328;
extern BattleList D_800A53AC;
extern BattleList D_800A5430;
extern BattleList D_800A54B4;
extern BattleList D_800A5538;
extern BattleList D_800A55BC;
extern BattleList D_800A5640;
extern u16 D_800A5778[];
extern u16 D_800A5788[];
extern u16 D_800A5790[];
extern u16 D_800A57A0[];
extern u16 D_800A57A8[];
extern u16 D_800A5804[];
extern FieldTalk D_800A57B0[];
extern u16 D_800A580C[];
extern FieldTalk D_800A57C8[];
extern u16 D_800A5818[];
extern FieldTalk D_800A57EC[];
extern u16 D_800A5824[];
extern FieldActorEntry D_800A5830;
extern FieldActorEntry D_800A5844;
extern FieldActorEntry D_800A5858;
extern FieldActorEntry D_800A586C;
extern FieldActorEntry D_800A5880;
extern FieldActorEntry D_800A5894;
extern s16 D_800A4EE4[];

s16 D_800A4EE4[] = {
    0x600, 0, 2,
    0x102, 2, 0xA1, 0x1B1, 3,
    0x100, 0x67, 0x81, 0x1A1,
    0x101, 0x67, 1, 7,
    0x101, 0x323, 0x325, 0x67,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x3C,
    0x101, 2, 1, 3,
    0x101, 0x323, 0x326, 0x67,
    0x300, 0x1E,
    0x200, 0, 1, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x301,
    0x101, 0x323, 0x325, 0x67,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x67,
    0x300, 0x1E,
    0x200, 0, 3, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 7, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 2, 3,
    0x301,
    0x101, 0x323, 0x327, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 9, 0x67, 0,
    0x301,
    0x101, 0x67, 1, 3,
    0x300, 0x1E,
    0x200, 0, 0xA, 0x67, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xA0, 0x1D0, 0,
    0x302, 2,
    0x102, 2, 0xE0, 0x1F0, 7,
    0x300, 0x3C,
    0x304, 0x222, 0x32A, 0x334, 3,
    0,
};
Battle D_800A5034 = { 39, 13, 0x60080000 };
Battle D_800A5040 = { 39, 13, 0x60080000 };
Battle D_800A504C = { 39, 13, 0x60080000 };
Battle D_800A5058 = { 39, 13, 0x60080000 };
Battle D_800A5064 = { 36, 13, 0x60080000 };
Battle D_800A5070 = { 36, 13, 0x60080000 };
Battle D_800A507C = { 36, 13, 0x60080000 };
Battle D_800A5088 = { 36, 13, 0x60080000 };
BattleList D_800A5094 = {
    3,
    { &D_800A5034, &D_800A5040, &D_800A504C, &D_800A5058,
      &D_800A5064, &D_800A5070, &D_800A507C, &D_800A5088 },
};
Battle D_800A50B8 = { 0, 13, 0x60080000 };
Battle D_800A50C4 = { 0, 13, 0x60080000 };
Battle D_800A50D0 = { 0, 13, 0x60080000 };
Battle D_800A50DC = { 0, 13, 0x60080000 };
Battle D_800A50E8 = { 0, 13, 0x60080000 };
Battle D_800A50F4 = { 0, 13, 0x60080000 };
Battle D_800A5100 = { 0, 13, 0x60080000 };
Battle D_800A510C = { 0, 13, 0x60080000 };
BattleList D_800A5118 = {
    0,
    { &D_800A50B8, &D_800A50C4, &D_800A50D0, &D_800A50DC,
      &D_800A50E8, &D_800A50F4, &D_800A5100, &D_800A510C },
};
Battle D_800A513C = { 0, 0, 0x60040000 };
Battle D_800A5148 = { 0, 0, 0x60040000 };
Battle D_800A5154 = { 0, 0, 0x60040000 };
Battle D_800A5160 = { 0, 0, 0x60040000 };
Battle D_800A516C = { 0, 0, 0x60040000 };
Battle D_800A5178 = { 0, 0, 0x60040000 };
Battle D_800A5184 = { 0, 0, 0x60040000 };
Battle D_800A5190 = { 0, 0, 0x60040000 };
BattleList D_800A519C = {
    0,
    { &D_800A513C, &D_800A5148, &D_800A5154, &D_800A5160,
      &D_800A516C, &D_800A5178, &D_800A5184, &D_800A5190 },
};
Battle D_800A51C0 = { 0, 0, 0x60040000 };
Battle D_800A51CC = { 0, 0, 0x60040000 };
Battle D_800A51D8 = { 0, 0, 0x60040000 };
Battle D_800A51E4 = { 327, 13, 0x60080000 };
Battle D_800A51F0 = { 328, 8, 0x60080000 };
Battle D_800A51FC = { 36, 13, 0x60080000 };
Battle D_800A5208 = { 49, 13, 0x60080000 };
Battle D_800A5214 = { 64, 8, 0x60080000 };
BattleList D_800A5220 = {
    0,
    { &D_800A51C0, &D_800A51CC, &D_800A51D8, &D_800A51E4,
      &D_800A51F0, &D_800A51FC, &D_800A5208, &D_800A5214 },
};
Battle D_800A5244 = { 36, 13, 0x60080000 };
Battle D_800A5250 = { 36, 13, 0x60080000 };
Battle D_800A525C = { 66, 13, 0x60080000 };
Battle D_800A5268 = { 66, 13, 0x60080000 };
Battle D_800A5274 = { 66, 13, 0x60080000 };
Battle D_800A5280 = { 66, 13, 0x60080000 };
Battle D_800A528C = { 66, 13, 0x60080000 };
Battle D_800A5298 = { 66, 13, 0x60080000 };
BattleList D_800A52A4 = {
    3,
    { &D_800A5244, &D_800A5250, &D_800A525C, &D_800A5268,
      &D_800A5274, &D_800A5280, &D_800A528C, &D_800A5298 },
};
Battle D_800A52C8 = { 0, 13, 0x60080000 };
Battle D_800A52D4 = { 0, 13, 0x60080000 };
Battle D_800A52E0 = { 0, 13, 0x60080000 };
Battle D_800A52EC = { 0, 13, 0x60080000 };
Battle D_800A52F8 = { 0, 13, 0x60080000 };
Battle D_800A5304 = { 0, 13, 0x60080000 };
Battle D_800A5310 = { 0, 13, 0x60080000 };
Battle D_800A531C = { 0, 13, 0x60080000 };
BattleList D_800A5328 = {
    0,
    { &D_800A52C8, &D_800A52D4, &D_800A52E0, &D_800A52EC,
      &D_800A52F8, &D_800A5304, &D_800A5310, &D_800A531C },
};
Battle D_800A534C = { 0, 0, 0x60040000 };
Battle D_800A5358 = { 0, 0, 0x60040000 };
Battle D_800A5364 = { 0, 0, 0x60040000 };
Battle D_800A5370 = { 0, 0, 0x60040000 };
Battle D_800A537C = { 0, 0, 0x60040000 };
Battle D_800A5388 = { 0, 0, 0x60040000 };
Battle D_800A5394 = { 0, 0, 0x60040000 };
Battle D_800A53A0 = { 0, 0, 0x60040000 };
BattleList D_800A53AC = {
    0,
    { &D_800A534C, &D_800A5358, &D_800A5364, &D_800A5370,
      &D_800A537C, &D_800A5388, &D_800A5394, &D_800A53A0 },
};
Battle D_800A53D0 = { 0, 0, 0x60040000 };
Battle D_800A53DC = { 0, 0, 0x60040000 };
Battle D_800A53E8 = { 0, 0, 0x60040000 };
Battle D_800A53F4 = { 327, 13, 0x60080000 };
Battle D_800A5400 = { 328, 8, 0x60080000 };
Battle D_800A540C = { 36, 13, 0x60080000 };
Battle D_800A5418 = { 49, 13, 0x60080000 };
Battle D_800A5424 = { 64, 8, 0x60080000 };
BattleList D_800A5430 = {
    0,
    { &D_800A53D0, &D_800A53DC, &D_800A53E8, &D_800A53F4,
      &D_800A5400, &D_800A540C, &D_800A5418, &D_800A5424 },
};
Battle D_800A5454 = { 36, 13, 0x60080000 };
Battle D_800A5460 = { 36, 13, 0x60080000 };
Battle D_800A546C = { 66, 13, 0x60080000 };
Battle D_800A5478 = { 66, 13, 0x60080000 };
Battle D_800A5484 = { 60, 13, 0x60080000 };
Battle D_800A5490 = { 60, 13, 0x60080000 };
Battle D_800A549C = { 60, 13, 0x60080000 };
Battle D_800A54A8 = { 60, 13, 0x60080000 };
BattleList D_800A54B4 = {
    3,
    { &D_800A5454, &D_800A5460, &D_800A546C, &D_800A5478,
      &D_800A5484, &D_800A5490, &D_800A549C, &D_800A54A8 },
};
Battle D_800A54D8 = { 0, 13, 0x60080000 };
Battle D_800A54E4 = { 0, 13, 0x60080000 };
Battle D_800A54F0 = { 0, 13, 0x60080000 };
Battle D_800A54FC = { 0, 13, 0x60080000 };
Battle D_800A5508 = { 0, 13, 0x60080000 };
Battle D_800A5514 = { 0, 13, 0x60080000 };
Battle D_800A5520 = { 0, 13, 0x60080000 };
Battle D_800A552C = { 0, 13, 0x60080000 };
BattleList D_800A5538 = {
    0,
    { &D_800A54D8, &D_800A54E4, &D_800A54F0, &D_800A54FC,
      &D_800A5508, &D_800A5514, &D_800A5520, &D_800A552C },
};
Battle D_800A555C = { 0, 0, 0x60040000 };
Battle D_800A5568 = { 0, 0, 0x60040000 };
Battle D_800A5574 = { 0, 0, 0x60040000 };
Battle D_800A5580 = { 0, 0, 0x60040000 };
Battle D_800A558C = { 0, 0, 0x60040000 };
Battle D_800A5598 = { 0, 0, 0x60040000 };
Battle D_800A55A4 = { 0, 0, 0x60040000 };
Battle D_800A55B0 = { 0, 0, 0x60040000 };
BattleList D_800A55BC = {
    0,
    { &D_800A555C, &D_800A5568, &D_800A5574, &D_800A5580,
      &D_800A558C, &D_800A5598, &D_800A55A4, &D_800A55B0 },
};
Battle D_800A55E0 = { 0, 0, 0x60040000 };
Battle D_800A55EC = { 0, 0, 0x60040000 };
Battle D_800A55F8 = { 0, 0, 0x60040000 };
Battle D_800A5604 = { 327, 13, 0x60080000 };
Battle D_800A5610 = { 328, 8, 0x60080000 };
Battle D_800A561C = { 36, 13, 0x60080000 };
Battle D_800A5628 = { 49, 13, 0x60080000 };
Battle D_800A5634 = { 64, 8, 0x60080000 };
BattleList D_800A5640 = {
    0,
    { &D_800A55E0, &D_800A55EC, &D_800A55F8, &D_800A5604,
      &D_800A5610, &D_800A561C, &D_800A5628, &D_800A5634 },
};
FieldBattles D_800A5664[] = {
    { 7, 0, 0, { &D_800A5094, &D_800A5118, &D_800A519C, &D_800A5220 } },
};
FieldBattles D_800A5680[] = {
    { 24, 1, 0, { &D_800A52A4, &D_800A5328, &D_800A53AC, &D_800A5430 } },
};
FieldBattles D_800A569C[] = {
    { 53, 2, 0, { &D_800A54B4, &D_800A5538, &D_800A55BC, &D_800A5640 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x19A, 0x120, 0x168, 0x20, 0x160, 0x1FF },
    { 0x140, 0x100, 0x170, 0x1CC, 0xC0, 0xCC, 0x140, 0x1FE },
    { 0x180, 0x100, 0x1B0, 0x100, 0x1C0, 0, 0x150, 0x1FE },
    { 0x180, 0x100, 0x180, 0x120, 0x100, 0x20, 0x160, 0x1FE },
    { 0x180, 0x100, 0x18A, 0x120, 0x128, 0x20, 0x170, 0x1FE },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A5778[] = { 0x203, 1, 0x8AD7, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5788[] = { 0x1A2C, 0, 0xFFFF };
u16 D_800A5790[] = { 0x1A2C, 1, 0x8007, 1, 0x7013, 1, 0xFFFF };
u16 D_800A57A0[] = { 0x1A2C, 1, 0xFFFF };
u16 D_800A57A8[] = { 0x9020, 1, 0xFFFF };
FieldTalk D_800A57B0[] = {
    { NULL, D_800A5778, 0x16F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57C8[] = {
    { D_800A5788, D_800A5790, 0x2B9 },
    { D_800A57A0, NULL, 0x2BA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57EC[] = {
    { NULL, D_800A57A8, 0x248 },
    { NULL, NULL, 0 },
};
u16 D_800A5804[] = { 0x203, 0, 0xFFFF };
u16 D_800A580C[] = { 0x1A21, 1, 0x1A2C, 0, 0xFFFF };
u16 D_800A5818[] = { 0x6008, 1, 0x1A1A, 1, 0xFFFF };
u16 D_800A5824[] = { 0x1A21, 1, 0x1A2C, 0, 0xFFFF };
FieldActorEntry D_800A5830 = { D_800A5804, D_800A57B0, 0x21, 4, 776, 125, 1 };
FieldActorEntry D_800A5844 = { D_800A580C, D_800A57C8, 0x4B, 5, 530, 430, 1 };
FieldActorEntry D_800A5858 = { NULL, NULL, 0x4C, 6, 760, 357, 7 };
FieldActorEntry D_800A586C = { NULL, NULL, 0x58, 7, 670, 280, 1 };
FieldActorEntry D_800A5880 = { D_800A5818, D_800A57EC, 0x67, 8, 129, 417, 3 };
FieldActorEntry D_800A5894 = { D_800A5824, NULL, 0x11C, 9, 520, 437, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5830,
    &D_800A5844,
    &D_800A5858,
    &D_800A586C,
    &D_800A5880,
    &D_800A5894,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 4, 1, 4, 9, 8, 0, 43, 521, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 9, 8, 0, 426, -16, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 9, 8, 0, 761, 743, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 337, 409, 0, 0 },
    { 1, 0, 0x74, 2, 2, 0, 0, 0, 0, 0, 655, 662, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 732, 199, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 810, 177, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 868, 149, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 989, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1051, 414, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1125, 373, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 431, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 541, 288, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 618, 226, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 781, 193, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 907, 130, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 34, 772, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 470, 378, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 504, 455, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 606, 516, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 611, 441, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 660, 472, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 686, 214, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 700, 583, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 764, 605, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 840, 162, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 372, 442, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 411, 412, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 492, 502, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 988, 429, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 58, 779, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 293, 404, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 427, 470, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 537, 476, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 940, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 337, 423, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 538, 522, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 624, 465, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 764, 635, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 793, 425, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1050, 398, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 45, 781, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 466, 351, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 467, 390, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 523, 455, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 552, 295, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 563, 474, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 564, 271, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 575, 246, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 632, 233, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 644, 473, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 664, 324, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 684, 581, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 690, 456, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 733, 208, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 788, 632, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 792, 404, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 819, 419, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 850, 168, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 952, 332, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 977, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1021, 428, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1072, 376, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1131, 347, 0, 0 },
    { 1, 0, 0x74, 6, 3, 0, 0, 0, 0, 0, 768, 640, 0, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 96, 687, 687, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 103, 923, 923, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 144, 663, 663, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 160, 703, 703, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 160, 943, 943, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 192, 639, 639, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 192, 911, 911, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 208, 679, 679, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 224, 952, 952, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 559, 559, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 256, 655, 655, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 272, 197, 197, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 274, 262, 262, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 288, 623, 623, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 288, 937, 937, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 304, 535, 535, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 305, 230, 230, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 175, 175, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 336, 599, 599, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 352, 207, 207, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 400, 583, 583, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 480, 591, 591, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 576, 127, 127, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 624, 110, 110, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 656, 135, 135, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 720, 110, 110, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 896, 831, 831, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 944, 807, 807, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 992, 783, 783, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1115, 428, 428, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x222, 0x32A, 0x334, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x229, 0x9A, 0x74, 7, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 8, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0x1A1, 0x140, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x1B0, 0x176, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x38, 0x58, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x40, 0x40, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFC0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB8, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFF90, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB0, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x40, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFE0, 0x18, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFF0, 0x10, 0, 0, 0, 0, 0 },
    { { { 0xF, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 205, D_800A4EE4, EVENT_TEXT(1), NULL, func_800A4D4C },
    { 9000, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
