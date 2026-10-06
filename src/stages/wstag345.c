#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D4C(void) {
    FLAGS_00.applyAction(0x1C07, 1);
    FLAGS_00.applyAction(0x1A22, 1);
}

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xDB
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x396
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x3A6
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x6E00, 0xB600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x36;
    D_800990B4.music = 0x60D80000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
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
        D_800990B4.battles = &stageBattles[0];
    } else {
        D_800990B4.battles = &stageBattles[1];
    }
}

extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern Battle D_800A5138;
extern Battle D_800A5144;
extern Battle D_800A5150;
extern Battle D_800A515C;
extern Battle D_800A518C;
extern Battle D_800A5198;
extern Battle D_800A51A4;
extern Battle D_800A51B0;
extern Battle D_800A51BC;
extern Battle D_800A51C8;
extern Battle D_800A51D4;
extern Battle D_800A51E0;
extern Battle D_800A5210;
extern Battle D_800A521C;
extern Battle D_800A5228;
extern Battle D_800A5234;
extern Battle D_800A5240;
extern Battle D_800A524C;
extern Battle D_800A5258;
extern Battle D_800A5264;
extern Battle D_800A5294;
extern Battle D_800A52A0;
extern Battle D_800A52AC;
extern Battle D_800A52B8;
extern Battle D_800A52C4;
extern Battle D_800A52D0;
extern Battle D_800A52DC;
extern Battle D_800A52E8;
extern Battle D_800A5318;
extern Battle D_800A5324;
extern Battle D_800A5330;
extern Battle D_800A533C;
extern Battle D_800A5348;
extern Battle D_800A5354;
extern Battle D_800A5360;
extern Battle D_800A536C;
extern Battle D_800A539C;
extern Battle D_800A53A8;
extern Battle D_800A53B4;
extern Battle D_800A53C0;
extern Battle D_800A53CC;
extern Battle D_800A53D8;
extern Battle D_800A53E4;
extern Battle D_800A53F0;
extern Battle D_800A5420;
extern Battle D_800A542C;
extern Battle D_800A5438;
extern Battle D_800A5444;
extern Battle D_800A5450;
extern Battle D_800A545C;
extern Battle D_800A5468;
extern Battle D_800A5474;
extern Battle D_800A54A4;
extern Battle D_800A54B0;
extern Battle D_800A54BC;
extern Battle D_800A54C8;
extern Battle D_800A54D4;
extern Battle D_800A54E0;
extern Battle D_800A54EC;
extern Battle D_800A54F8;
extern BattleList D_800A5168;
extern BattleList D_800A51EC;
extern BattleList D_800A5270;
extern BattleList D_800A52F4;
extern BattleList D_800A5378;
extern BattleList D_800A53FC;
extern BattleList D_800A5480;
extern BattleList D_800A5504;
extern u16 D_800A5600[];
extern u16 D_800A5608[];
extern u16 D_800A5618[];
extern u16 D_800A5620[];
extern u16 D_800A5630[];
extern u16 D_800A5640[];
extern u16 D_800A564C[];
extern u16 D_800A5660[];
extern u16 D_800A5674[];
extern u16 D_800A567C[];
extern u16 D_800A5688[];
extern u16 D_800A5698[];
extern u16 D_800A56A4[];
extern u16 D_800A56B8[];
extern u16 D_800A57E0[];
extern FieldTalk D_800A56CC[];
extern u16 D_800A57E8[];
extern FieldTalk D_800A56E4[];
extern u16 D_800A57F0[];
extern FieldTalk D_800A56FC[];
extern u16 D_800A57FC[];
extern FieldTalk D_800A5750[];
extern u16 D_800A5808[];
extern FieldTalk D_800A5768[];
extern u16 D_800A5814[];
extern FieldTalk D_800A57B0[];
extern u16 D_800A5820[];
extern FieldTalk D_800A57C8[];
extern FieldActorEntry D_800A5828;
extern FieldActorEntry D_800A583C;
extern FieldActorEntry D_800A5850;
extern FieldActorEntry D_800A5864;
extern FieldActorEntry D_800A5878;
extern FieldActorEntry D_800A588C;
extern FieldActorEntry D_800A58A0;
extern s16 D_800A4F10[];

s16 D_800A4F10[] = {
    0x102, 2, 0x3A7, 0x394, 5,
    0x100, 0x11B, 0x3C7, 0x385,
    0x101, 0x11B, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x102, 0x11B, 0x3E0, 0x378, 5,
    0x302, 0x11B,
    0x101, 0x11B, 1, 5,
    0x300, 0x1E,
    0x101, 0x11B, 8, 5,
    0x101, 0x323, 0x325, 2,
    0x101, 0x32D, 0x376, 2,
    0x303, 0x11B,
    0x101, 0x11B, 1, 5,
    0x300, 0x1E,
    0x101, 0x11B, 8, 5,
    0x101, 0x32D, 0x376, 2,
    0x303, 0x11B,
    0x101, 0x11B, 1, 5,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 0x11B, 8, 5,
    0x101, 0x32D, 0x376, 2,
    0x303, 0x11B,
    0x101, 0x11B, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 0x11B, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0x11B,
    0x300, 0x1E,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x11B,
    0x300, 0x1E,
    0x101, 0x11B, 1, 1,
    0x300, 0x1E,
    0x102, 0x11B, 0x3C7, 0x385, 1,
    0x302, 0x11B,
    0x101, 0x11B, 1, 1,
    0x300, 0x1E,
    0x200, 0, 3, 0x11B, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x11B, 2,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x1E,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 6, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 7, 0x11B, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x37F, 0x3A7, 1,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0,
};
Battle D_800A5108 = { 39, 13, 0x60080000 };
Battle D_800A5114 = { 39, 13, 0x60080000 };
Battle D_800A5120 = { 39, 13, 0x60080000 };
Battle D_800A512C = { 39, 13, 0x60080000 };
Battle D_800A5138 = { 40, 13, 0x60080000 };
Battle D_800A5144 = { 40, 13, 0x60080000 };
Battle D_800A5150 = { 40, 13, 0x60080000 };
Battle D_800A515C = { 40, 13, 0x60080000 };
BattleList D_800A5168 = {
    3,
    { &D_800A5108, &D_800A5114, &D_800A5120, &D_800A512C,
      &D_800A5138, &D_800A5144, &D_800A5150, &D_800A515C },
};
Battle D_800A518C = { 51, 4, 0x60080000 };
Battle D_800A5198 = { 51, 4, 0x60080000 };
Battle D_800A51A4 = { 51, 4, 0x60080000 };
Battle D_800A51B0 = { 51, 4, 0x60080000 };
Battle D_800A51BC = { 51, 4, 0x60080000 };
Battle D_800A51C8 = { 51, 4, 0x60080000 };
Battle D_800A51D4 = { 51, 4, 0x60080000 };
Battle D_800A51E0 = { 51, 4, 0x60080000 };
BattleList D_800A51EC = {
    3,
    { &D_800A518C, &D_800A5198, &D_800A51A4, &D_800A51B0,
      &D_800A51BC, &D_800A51C8, &D_800A51D4, &D_800A51E0 },
};
Battle D_800A5210 = { 54, 2, 0x60080000 };
Battle D_800A521C = { 54, 2, 0x60080000 };
Battle D_800A5228 = { 54, 2, 0x60080000 };
Battle D_800A5234 = { 54, 2, 0x60080000 };
Battle D_800A5240 = { 54, 2, 0x60080000 };
Battle D_800A524C = { 54, 2, 0x60080000 };
Battle D_800A5258 = { 54, 2, 0x60080000 };
Battle D_800A5264 = { 54, 2, 0x60080000 };
BattleList D_800A5270 = {
    3,
    { &D_800A5210, &D_800A521C, &D_800A5228, &D_800A5234,
      &D_800A5240, &D_800A524C, &D_800A5258, &D_800A5264 },
};
Battle D_800A5294 = { 0, 0, 0x60040000 };
Battle D_800A52A0 = { 0, 0, 0x60040000 };
Battle D_800A52AC = { 0, 0, 0x60040000 };
Battle D_800A52B8 = { 327, 13, 0x60080000 };
Battle D_800A52C4 = { 328, 2, 0x60080000 };
Battle D_800A52D0 = { 0, 0, 0x60040000 };
Battle D_800A52DC = { 49, 13, 0x60080000 };
Battle D_800A52E8 = { 54, 2, 0x60080000 };
BattleList D_800A52F4 = {
    0,
    { &D_800A5294, &D_800A52A0, &D_800A52AC, &D_800A52B8,
      &D_800A52C4, &D_800A52D0, &D_800A52DC, &D_800A52E8 },
};
Battle D_800A5318 = { 39, 13, 0x60080000 };
Battle D_800A5324 = { 39, 13, 0x60080000 };
Battle D_800A5330 = { 39, 13, 0x60080000 };
Battle D_800A533C = { 39, 13, 0x60080000 };
Battle D_800A5348 = { 40, 13, 0x60080000 };
Battle D_800A5354 = { 40, 13, 0x60080000 };
Battle D_800A5360 = { 40, 13, 0x60080000 };
Battle D_800A536C = { 40, 13, 0x60080000 };
BattleList D_800A5378 = {
    3,
    { &D_800A5318, &D_800A5324, &D_800A5330, &D_800A533C,
      &D_800A5348, &D_800A5354, &D_800A5360, &D_800A536C },
};
Battle D_800A539C = { 70, 4, 0x60080000 };
Battle D_800A53A8 = { 70, 4, 0x60080000 };
Battle D_800A53B4 = { 70, 4, 0x60080000 };
Battle D_800A53C0 = { 70, 4, 0x60080000 };
Battle D_800A53CC = { 70, 4, 0x60080000 };
Battle D_800A53D8 = { 70, 4, 0x60080000 };
Battle D_800A53E4 = { 70, 4, 0x60080000 };
Battle D_800A53F0 = { 70, 4, 0x60080000 };
BattleList D_800A53FC = {
    3,
    { &D_800A539C, &D_800A53A8, &D_800A53B4, &D_800A53C0,
      &D_800A53CC, &D_800A53D8, &D_800A53E4, &D_800A53F0 },
};
Battle D_800A5420 = { 59, 2, 0x60080000 };
Battle D_800A542C = { 59, 2, 0x60080000 };
Battle D_800A5438 = { 59, 2, 0x60080000 };
Battle D_800A5444 = { 59, 2, 0x60080000 };
Battle D_800A5450 = { 59, 2, 0x60080000 };
Battle D_800A545C = { 59, 2, 0x60080000 };
Battle D_800A5468 = { 59, 2, 0x60080000 };
Battle D_800A5474 = { 59, 2, 0x60080000 };
BattleList D_800A5480 = {
    3,
    { &D_800A5420, &D_800A542C, &D_800A5438, &D_800A5444,
      &D_800A5450, &D_800A545C, &D_800A5468, &D_800A5474 },
};
Battle D_800A54A4 = { 0, 0, 0x60040000 };
Battle D_800A54B0 = { 0, 0, 0x60040000 };
Battle D_800A54BC = { 0, 0, 0x60040000 };
Battle D_800A54C8 = { 327, 13, 0x60080000 };
Battle D_800A54D4 = { 328, 2, 0x60080000 };
Battle D_800A54E0 = { 0, 0, 0x60040000 };
Battle D_800A54EC = { 49, 13, 0x60080000 };
Battle D_800A54F8 = { 54, 2, 0x60080000 };
BattleList D_800A5504 = {
    0,
    { &D_800A54A4, &D_800A54B0, &D_800A54BC, &D_800A54C8,
      &D_800A54D4, &D_800A54E0, &D_800A54EC, &D_800A54F8 },
};
FieldBattles stageBattles[] = {
    { 4, 0, 0, { &D_800A5168, &D_800A51EC, &D_800A5270, &D_800A52F4 } },
    { 27, 1, 0, { &D_800A5378, &D_800A53FC, &D_800A5480, &D_800A5504 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x137, 0xD8, 0x37, 0x150, 0x1FF },
    { 0x140, 0x100, 0x176, 0x157, 0xD8, 0x57, 0x160, 0x1FF },
    { 0x140, 0x100, 0x176, 0x177, 0xD8, 0x77, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x197, 0xD8, 0x97, 0x140, 0x1FE },
};
u16 D_800A5600[] = { 0x1A22, 0, 0xFFFF };
u16 D_800A5608[] = { 0x1A22, 1, 0x1A23, 0, 0, 0, 0xFFFF };
u16 D_800A5618[] = { 0, 1, 0xFFFF };
u16 D_800A5620[] = { 0x1A22, 1, 0x1A23, 0, 0, 1, 0xFFFF };
u16 D_800A5630[] = { 0x1A22, 1, 0x1A23, 1, 0x1A24, 0, 0xFFFF };
u16 D_800A5640[] = { 0x1A24, 1, 0x1C08, 1, 0xFFFF };
u16 D_800A564C[] = { 0x1A22, 1, 0x1A23, 1, 0x1A24, 1, 0x8004, 0, 0xFFFF };
u16 D_800A5660[] = { 0x1A22, 1, 0x1A23, 1, 0x1A24, 1, 0x8004, 1, 0xFFFF };
u16 D_800A5674[] = { 0x1A22, 0, 0xFFFF };
u16 D_800A567C[] = { 0x1A22, 1, 0x1A23, 0, 0xFFFF };
u16 D_800A5688[] = { 0x1A22, 1, 0x1A23, 1, 0x1A24, 0, 0xFFFF };
u16 D_800A5698[] = { 0x1A24, 1, 0x1C08, 1, 0xFFFF };
u16 D_800A56A4[] = { 0x1A22, 1, 0x1A23, 1, 0x1A24, 1, 0x8004, 0, 0xFFFF };
u16 D_800A56B8[] = { 0x1A22, 1, 0x1A23, 1, 0x1A24, 1, 0x8004, 1, 0xFFFF };
FieldTalk D_800A56CC[] = {
    { NULL, NULL, 0x1C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56E4[] = {
    { NULL, NULL, 0x2A0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56FC[] = {
    { D_800A5600, NULL, 0x29B },
    { D_800A5608, D_800A5618, 0x29C },
    { D_800A5620, NULL, 0x29E },
    { D_800A5630, D_800A5640, 0x29D },
    { D_800A564C, NULL, 0x35D },
    { D_800A5660, NULL, 0x29F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5750[] = {
    { NULL, NULL, 0x29F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5768[] = {
    { D_800A5674, NULL, 0x29B },
    { D_800A567C, NULL, 0x29C },
    { D_800A5688, D_800A5698, 0x29D },
    { D_800A56A4, NULL, 0x29E },
    { D_800A56B8, NULL, 0x2A1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57B0[] = {
    { NULL, NULL, 0x2A1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57C8[] = {
    { NULL, NULL, 0x1D },
    { NULL, NULL, 0 },
};
u16 D_800A57E0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57E8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57F0[] = { 0x7022, 1, 0x8004, 0, 0xFFFF };
u16 D_800A57FC[] = { 0x7022, 1, 0x8004, 1, 0xFFFF };
u16 D_800A5808[] = { 0x602B, 1, 0x8004, 0, 0xFFFF };
u16 D_800A5814[] = { 0x602B, 1, 0x8004, 1, 0xFFFF };
u16 D_800A5820[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5828 = { D_800A57E0, D_800A56CC, 0x9D, 4, 885, 951, 5 };
FieldActorEntry D_800A583C = { D_800A57E8, D_800A56E4, 0x119, 5, 865, 941, 5 };
FieldActorEntry D_800A5850 = { D_800A57F0, D_800A56FC, 0x11B, 6, 967, 901, 1 };
FieldActorEntry D_800A5864 = { D_800A57FC, D_800A5750, 0x11B, 6, 967, 901, 1 };
FieldActorEntry D_800A5878 = { D_800A5808, D_800A5768, 0x11B, 6, 967, 901, 1 };
FieldActorEntry D_800A588C = { D_800A5814, D_800A57B0, 0x11B, 6, 967, 901, 1 };
FieldActorEntry D_800A58A0 = { D_800A5820, D_800A57C8, 0x13A, 7, 905, 961, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A5828,
    &D_800A583C,
    &D_800A5850,
    &D_800A5864,
    &D_800A5878,
    &D_800A588C,
    &D_800A58A0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 330, 524, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 922, 950, 0, 0 },
    { 1, 0, 0x80, 2, 7, 0, 0, 0, 0, 0, 256, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 176, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 212, 597, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 534, 857, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 646, 785, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 820, 685, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 874, 498, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 139, 93, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 148, 223, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 154, 386, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 460, 421, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 651, 773, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 750, 724, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 842, 515, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 185, 199, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 291, 768, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 398, 820, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 480, 897, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 608, 960, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 693, 1010, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 213, 246, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 422, 830, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 462, 898, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 569, 865, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 647, 985, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 680, 763, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 165, 373, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 170, 169, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 258, 270, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 323, 462, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 434, 222, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 595, 944, 0, 0 },
    { 1, 0, 0xFF, 6, 8, 0, 0, 0, 0, 0, 703, 232, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 593, 792, 804, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 623, 849, 864, 0 },
    { 1, 0, 0x80, 4, 9, 0, 0, 0, 0, 0, 631, 378, 433, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 333, 235, 235, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 381, 259, 259, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 429, 283, 283, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 481, 532, 532, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 486, 775, 775, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 557, 557, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 533, 751, 751, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 541, 699, 699, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 574, 580, 580, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1014, 879, 879, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x21D, 0x1D2, 0x92, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 6, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 0xC, 0x231, 0xB0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 0xC, 0x221, 0x178, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 3, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 2, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0xF, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x50, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFA2, 0x10, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x28, 0x20, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x38, 0x29, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 3, 1 },
    { { { 0x1A22, 0 }, { 0x8192, 1 } }, 8, 0x4F0, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1264, D_800A4F10, EVENT_TEXT(0x1D), NULL, func_800A4D4C },
    { -1, NULL, 0, NULL, NULL },
};
