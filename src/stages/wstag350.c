#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

extern FieldBattles D_800A54E0[];
extern FieldBattles D_800A54FC[];
extern FieldBattles D_800A5518[];
#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x1AB
#define STAGE_ARCHIVE 0x3C4
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x1B9
#define STAGE_ARCHIVE 0x3D4
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x2D600, 0x8000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2D;
    D_800990B4.music = 0x60B40000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
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
        D_800990B4.battles = D_800A54E0;
    } else if (GAME.progress < 0x18) {
        D_800990B4.battles = D_800A54FC;
    } else {
        D_800990B4.battles = D_800A5518;
    }
}

extern Battle D_800A4EB0;
extern Battle D_800A4EBC;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4EEC;
extern Battle D_800A4EF8;
extern Battle D_800A4F04;
extern Battle D_800A4F34;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A5078;
extern Battle D_800A5084;
extern Battle D_800A5090;
extern Battle D_800A50C0;
extern Battle D_800A50CC;
extern Battle D_800A50D8;
extern Battle D_800A50E4;
extern Battle D_800A50F0;
extern Battle D_800A50FC;
extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5144;
extern Battle D_800A5150;
extern Battle D_800A515C;
extern Battle D_800A5168;
extern Battle D_800A5174;
extern Battle D_800A5180;
extern Battle D_800A518C;
extern Battle D_800A5198;
extern Battle D_800A51C8;
extern Battle D_800A51D4;
extern Battle D_800A51E0;
extern Battle D_800A51EC;
extern Battle D_800A51F8;
extern Battle D_800A5204;
extern Battle D_800A5210;
extern Battle D_800A521C;
extern Battle D_800A524C;
extern Battle D_800A5258;
extern Battle D_800A5264;
extern Battle D_800A5270;
extern Battle D_800A527C;
extern Battle D_800A5288;
extern Battle D_800A5294;
extern Battle D_800A52A0;
extern Battle D_800A52D0;
extern Battle D_800A52DC;
extern Battle D_800A52E8;
extern Battle D_800A52F4;
extern Battle D_800A5300;
extern Battle D_800A530C;
extern Battle D_800A5318;
extern Battle D_800A5324;
extern Battle D_800A5354;
extern Battle D_800A5360;
extern Battle D_800A536C;
extern Battle D_800A5378;
extern Battle D_800A5384;
extern Battle D_800A5390;
extern Battle D_800A539C;
extern Battle D_800A53A8;
extern Battle D_800A53D8;
extern Battle D_800A53E4;
extern Battle D_800A53F0;
extern Battle D_800A53FC;
extern Battle D_800A5408;
extern Battle D_800A5414;
extern Battle D_800A5420;
extern Battle D_800A542C;
extern Battle D_800A545C;
extern Battle D_800A5468;
extern Battle D_800A5474;
extern Battle D_800A5480;
extern Battle D_800A548C;
extern Battle D_800A5498;
extern Battle D_800A54A4;
extern Battle D_800A54B0;
extern BattleList D_800A4F10;
extern BattleList D_800A4F94;
extern BattleList D_800A5018;
extern BattleList D_800A509C;
extern BattleList D_800A5120;
extern BattleList D_800A51A4;
extern BattleList D_800A5228;
extern BattleList D_800A52AC;
extern BattleList D_800A5330;
extern BattleList D_800A53B4;
extern BattleList D_800A5438;
extern BattleList D_800A54BC;
extern u16 D_800A55C4[];
extern u16 D_800A55D4[];
extern u16 D_800A55DC[];
extern u16 D_800A55E4[];
extern u16 D_800A55F0[];
extern u16 D_800A5600[];
extern u16 D_800A5608[];
extern u16 D_800A561C[];
extern u16 D_800A5628[];
extern u16 D_800A5640[];
extern u16 D_800A565C[];
extern u16 D_800A5678[];
extern u16 D_800A5680[];
extern u16 D_800A5688[];
extern u16 D_800A5694[];
extern u16 D_800A569C[];
extern u16 D_800A56A8[];
extern u16 D_800A56B4[];
extern u16 D_800A56BC[];
extern u16 D_800A56C4[];
extern u16 D_800A56D0[];
extern u16 D_800A56E0[];
extern u16 D_800A56E8[];
extern u16 D_800A56FC[];
extern u16 D_800A5708[];
extern u16 D_800A5720[];
extern u16 D_800A573C[];
extern u16 D_800A5758[];
extern u16 D_800A5760[];
extern u16 D_800A5768[];
extern u16 D_800A5770[];
extern u16 D_800A577C[];
extern u16 D_800A578C[];
extern u16 D_800A5794[];
extern u16 D_800A57A8[];
extern u16 D_800A57B4[];
extern u16 D_800A57CC[];
extern u16 D_800A57E8[];
extern u16 D_800A5804[];
extern u16 D_800A580C[];
extern u16 D_800A5814[];
extern u16 D_800A5820[];
extern u16 D_800A5830[];
extern u16 D_800A5838[];
extern u16 D_800A584C[];
extern u16 D_800A5854[];
extern u16 D_800A586C[];
extern u16 D_800A5888[];
extern u16 D_800A58A4[];
extern u16 D_800A5A8C[];
extern FieldTalk D_800A58AC[];
extern u16 D_800A5A94[];
extern FieldTalk D_800A58C4[];
extern u16 D_800A5AA4[];
extern FieldTalk D_800A5924[];
extern u16 D_800A5AB4[];
extern FieldTalk D_800A5954[];
extern u16 D_800A5AC4[];
extern FieldTalk D_800A59B4[];
extern u16 D_800A5AD4[];
extern FieldTalk D_800A5A14[];
extern u16 D_800A5AE4[];
extern FieldTalk D_800A5A2C[];
extern FieldActorEntry D_800A5AEC;
extern FieldActorEntry D_800A5B00;
extern FieldActorEntry D_800A5B14;
extern FieldActorEntry D_800A5B28;
extern FieldActorEntry D_800A5B3C;
extern FieldActorEntry D_800A5B50;
extern FieldActorEntry D_800A5B64;

Battle D_800A4EB0 = { 34, 13, 0x60080000 };
Battle D_800A4EBC = { 34, 13, 0x60080000 };
Battle D_800A4EC8 = { 39, 13, 0x60080000 };
Battle D_800A4ED4 = { 39, 13, 0x60080000 };
Battle D_800A4EE0 = { 39, 13, 0x60080000 };
Battle D_800A4EEC = { 41, 13, 0x60080000 };
Battle D_800A4EF8 = { 41, 13, 0x60080000 };
Battle D_800A4F04 = { 41, 13, 0x60080000 };
BattleList D_800A4F10 = {
    3,
    { &D_800A4EB0, &D_800A4EBC, &D_800A4EC8, &D_800A4ED4,
      &D_800A4EE0, &D_800A4EEC, &D_800A4EF8, &D_800A4F04 },
};
Battle D_800A4F34 = { 0, 13, 0x60080000 };
Battle D_800A4F40 = { 0, 13, 0x60080000 };
Battle D_800A4F4C = { 0, 13, 0x60080000 };
Battle D_800A4F58 = { 0, 13, 0x60080000 };
Battle D_800A4F64 = { 0, 13, 0x60080000 };
Battle D_800A4F70 = { 0, 13, 0x60080000 };
Battle D_800A4F7C = { 0, 13, 0x60080000 };
Battle D_800A4F88 = { 0, 13, 0x60080000 };
BattleList D_800A4F94 = {
    0,
    { &D_800A4F34, &D_800A4F40, &D_800A4F4C, &D_800A4F58,
      &D_800A4F64, &D_800A4F70, &D_800A4F7C, &D_800A4F88 },
};
Battle D_800A4FB8 = { 0, 0, 0x60040000 };
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
BattleList D_800A5018 = {
    0,
    { &D_800A4FB8, &D_800A4FC4, &D_800A4FD0, &D_800A4FDC,
      &D_800A4FE8, &D_800A4FF4, &D_800A5000, &D_800A500C },
};
Battle D_800A503C = { 203, 13, 0x600C0000 };
Battle D_800A5048 = { 0, 0, 0x60040000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
Battle D_800A5060 = { 327, 13, 0x60080000 };
Battle D_800A506C = { 328, 8, 0x60080000 };
Battle D_800A5078 = { 41, 13, 0x60080000 };
Battle D_800A5084 = { 49, 13, 0x60080000 };
Battle D_800A5090 = { 54, 8, 0x60080000 };
BattleList D_800A509C = {
    0,
    { &D_800A503C, &D_800A5048, &D_800A5054, &D_800A5060,
      &D_800A506C, &D_800A5078, &D_800A5084, &D_800A5090 },
};
Battle D_800A50C0 = { 39, 13, 0x60080000 };
Battle D_800A50CC = { 39, 13, 0x60080000 };
Battle D_800A50D8 = { 41, 13, 0x60080000 };
Battle D_800A50E4 = { 41, 13, 0x60080000 };
Battle D_800A50F0 = { 48, 13, 0x60080000 };
Battle D_800A50FC = { 48, 13, 0x60080000 };
Battle D_800A5108 = { 48, 13, 0x60080000 };
Battle D_800A5114 = { 48, 13, 0x60080000 };
BattleList D_800A5120 = {
    3,
    { &D_800A50C0, &D_800A50CC, &D_800A50D8, &D_800A50E4,
      &D_800A50F0, &D_800A50FC, &D_800A5108, &D_800A5114 },
};
Battle D_800A5144 = { 0, 13, 0x60080000 };
Battle D_800A5150 = { 0, 13, 0x60080000 };
Battle D_800A515C = { 0, 13, 0x60080000 };
Battle D_800A5168 = { 0, 13, 0x60080000 };
Battle D_800A5174 = { 0, 13, 0x60080000 };
Battle D_800A5180 = { 0, 13, 0x60080000 };
Battle D_800A518C = { 0, 13, 0x60080000 };
Battle D_800A5198 = { 0, 13, 0x60080000 };
BattleList D_800A51A4 = {
    0,
    { &D_800A5144, &D_800A5150, &D_800A515C, &D_800A5168,
      &D_800A5174, &D_800A5180, &D_800A518C, &D_800A5198 },
};
Battle D_800A51C8 = { 0, 0, 0x60040000 };
Battle D_800A51D4 = { 0, 0, 0x60040000 };
Battle D_800A51E0 = { 0, 0, 0x60040000 };
Battle D_800A51EC = { 0, 0, 0x60040000 };
Battle D_800A51F8 = { 0, 0, 0x60040000 };
Battle D_800A5204 = { 0, 0, 0x60040000 };
Battle D_800A5210 = { 0, 0, 0x60040000 };
Battle D_800A521C = { 0, 0, 0x60040000 };
BattleList D_800A5228 = {
    0,
    { &D_800A51C8, &D_800A51D4, &D_800A51E0, &D_800A51EC,
      &D_800A51F8, &D_800A5204, &D_800A5210, &D_800A521C },
};
Battle D_800A524C = { 203, 13, 0x600C0000 };
Battle D_800A5258 = { 0, 0, 0x60040000 };
Battle D_800A5264 = { 0, 0, 0x60040000 };
Battle D_800A5270 = { 327, 13, 0x60080000 };
Battle D_800A527C = { 328, 8, 0x60080000 };
Battle D_800A5288 = { 41, 13, 0x60080000 };
Battle D_800A5294 = { 49, 13, 0x60080000 };
Battle D_800A52A0 = { 54, 8, 0x60080000 };
BattleList D_800A52AC = {
    0,
    { &D_800A524C, &D_800A5258, &D_800A5264, &D_800A5270,
      &D_800A527C, &D_800A5288, &D_800A5294, &D_800A52A0 },
};
Battle D_800A52D0 = { 39, 13, 0x60080000 };
Battle D_800A52DC = { 39, 13, 0x60080000 };
Battle D_800A52E8 = { 41, 13, 0x60080000 };
Battle D_800A52F4 = { 41, 13, 0x60080000 };
Battle D_800A5300 = { 146, 13, 0x60080000 };
Battle D_800A530C = { 146, 13, 0x60080000 };
Battle D_800A5318 = { 146, 13, 0x60080000 };
Battle D_800A5324 = { 146, 13, 0x60080000 };
BattleList D_800A5330 = {
    3,
    { &D_800A52D0, &D_800A52DC, &D_800A52E8, &D_800A52F4,
      &D_800A5300, &D_800A530C, &D_800A5318, &D_800A5324 },
};
Battle D_800A5354 = { 0, 13, 0x60080000 };
Battle D_800A5360 = { 0, 13, 0x60080000 };
Battle D_800A536C = { 0, 13, 0x60080000 };
Battle D_800A5378 = { 0, 13, 0x60080000 };
Battle D_800A5384 = { 0, 13, 0x60080000 };
Battle D_800A5390 = { 0, 13, 0x60080000 };
Battle D_800A539C = { 0, 13, 0x60080000 };
Battle D_800A53A8 = { 0, 13, 0x60080000 };
BattleList D_800A53B4 = {
    0,
    { &D_800A5354, &D_800A5360, &D_800A536C, &D_800A5378,
      &D_800A5384, &D_800A5390, &D_800A539C, &D_800A53A8 },
};
Battle D_800A53D8 = { 0, 0, 0x60040000 };
Battle D_800A53E4 = { 0, 0, 0x60040000 };
Battle D_800A53F0 = { 0, 0, 0x60040000 };
Battle D_800A53FC = { 0, 0, 0x60040000 };
Battle D_800A5408 = { 0, 0, 0x60040000 };
Battle D_800A5414 = { 0, 0, 0x60040000 };
Battle D_800A5420 = { 0, 0, 0x60040000 };
Battle D_800A542C = { 0, 0, 0x60040000 };
BattleList D_800A5438 = {
    0,
    { &D_800A53D8, &D_800A53E4, &D_800A53F0, &D_800A53FC,
      &D_800A5408, &D_800A5414, &D_800A5420, &D_800A542C },
};
Battle D_800A545C = { 203, 13, 0x600C0000 };
Battle D_800A5468 = { 0, 0, 0x60040000 };
Battle D_800A5474 = { 0, 0, 0x60040000 };
Battle D_800A5480 = { 327, 13, 0x60080000 };
Battle D_800A548C = { 328, 8, 0x60080000 };
Battle D_800A5498 = { 41, 13, 0x60080000 };
Battle D_800A54A4 = { 49, 13, 0x60080000 };
Battle D_800A54B0 = { 54, 8, 0x60080000 };
BattleList D_800A54BC = {
    0,
    { &D_800A545C, &D_800A5468, &D_800A5474, &D_800A5480,
      &D_800A548C, &D_800A5498, &D_800A54A4, &D_800A54B0 },
};
FieldBattles D_800A54E0[] = {
    { 5, 0, 0, { &D_800A4F10, &D_800A4F94, &D_800A5018, &D_800A509C } },
};
FieldBattles D_800A54FC[] = {
    { 22, 1, 0, { &D_800A5120, &D_800A51A4, &D_800A5228, &D_800A52AC } },
};
FieldBattles D_800A5518[] = {
    { 51, 2, 0, { &D_800A5330, &D_800A53B4, &D_800A5438, &D_800A54BC } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x100, 0xB0, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x174, 0x160, 0xD0, 0x60, 0x170, 0x1FF },
};
u16 D_800A55C4[] = { 0x202, 1, 0x8B13, 1, 0x7013, 1, 0xFFFF };
u16 D_800A55D4[] = { 0, 0, 0xFFFF };
u16 D_800A55DC[] = { 0, 1, 0xFFFF };
u16 D_800A55E4[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A55F0[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A5600[] = { 0x7607, 1, 0xFFFF };
u16 D_800A5608[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE03, 0, 0xFFFF };
u16 D_800A561C[] = { 0xE03, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5628[] = {
    0xE03, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5640[] = {
    0x7205, 0, 0xE03, 1, 0, 1, 0x7201, 1,
    0x7203, 1, 0x8012, 1, 0xFFFF,
};
u16 D_800A565C[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 1, 0xE03, 1, 0xFFFF,
};
u16 D_800A5678[] = { 0x7807, 1, 0xFFFF };
u16 D_800A5680[] = { 0x11, 0, 0xFFFF };
u16 D_800A5688[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5694[] = { 0x11, 0, 0xFFFF };
u16 D_800A569C[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A56A8[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A56B4[] = { 0, 0, 0xFFFF };
u16 D_800A56BC[] = { 0, 1, 0xFFFF };
u16 D_800A56C4[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A56D0[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A56E0[] = { 0x7607, 1, 0xFFFF };
u16 D_800A56E8[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE03, 0, 0xFFFF };
u16 D_800A56FC[] = { 0xE03, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5708[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0x8012, 0,
    0xE03, 1, 0xFFFF,
};
u16 D_800A5720[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 0, 0xE03, 1, 0xFFFF,
};
u16 D_800A573C[] = {
    0xE03, 1, 0, 1, 0x7201, 1, 0x8012, 1,
    0x7203, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A5758[] = { 0x7807, 1, 0xFFFF };
u16 D_800A5760[] = { 0, 0, 0xFFFF };
u16 D_800A5768[] = { 0, 1, 0xFFFF };
u16 D_800A5770[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A577C[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A578C[] = { 0x7607, 1, 0xFFFF };
u16 D_800A5794[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE03, 0, 0xFFFF };
u16 D_800A57A8[] = { 0x7400, 1, 0xE03, 1, 0xFFFF };
u16 D_800A57B4[] = {
    0xE03, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A57CC[] = {
    0xE03, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A57E8[] = {
    0xE03, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A5804[] = { 0x7807, 1, 0xFFFF };
u16 D_800A580C[] = { 0, 0, 0xFFFF };
u16 D_800A5814[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5820[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A5830[] = { 0x7607, 1, 0xFFFF };
u16 D_800A5838[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE03, 0, 0xFFFF };
u16 D_800A584C[] = { 0xE03, 1, 0xFFFF };
u16 D_800A5854[] = {
    0xE03, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A586C[] = {
    0xE03, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A5888[] = {
    0xE03, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A58A4[] = { 0x7807, 1, 0xFFFF };
FieldTalk D_800A58AC[] = {
    { NULL, D_800A55C4, 0x16E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C4[] = {
    { D_800A55D4, D_800A55DC, 0x3A },
    { D_800A55E4, NULL, 0x3F },
    { D_800A55F0, D_800A5600, 0x40 },
    { D_800A5608, D_800A561C, 0x41 },
    { D_800A5628, NULL, 0x42 },
    { D_800A5640, NULL, 0x43 },
    { D_800A565C, D_800A5678, 0x6B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5924[] = {
    { D_800A5680, NULL, 0x3A },
    { D_800A5688, D_800A5694, 0x44 },
    { D_800A569C, D_800A56A8, 0x45 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5954[] = {
    { D_800A56B4, D_800A56BC, 0x3B },
    { D_800A56C4, NULL, 0x3F },
    { D_800A56D0, D_800A56E0, 0x40 },
    { D_800A56E8, D_800A56FC, 0x41 },
    { D_800A5708, NULL, 0x42 },
    { D_800A5720, NULL, 0x43 },
    { D_800A573C, D_800A5758, 0x6B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59B4[] = {
    { D_800A5760, D_800A5768, 0x3C },
    { D_800A5770, NULL, 0x3F },
    { D_800A577C, D_800A578C, 0x40 },
    { D_800A5794, D_800A57A8, 0x41 },
    { D_800A57B4, NULL, 0x42 },
    { D_800A57CC, NULL, 0x43 },
    { D_800A57E8, D_800A5804, 0x6B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A14[] = {
    { NULL, NULL, 0x272 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A2C[] = {
    { D_800A580C, NULL, 0x3D },
    { D_800A5814, NULL, 0x3D },
    { D_800A5820, D_800A5830, 0x3D },
    { D_800A5838, D_800A584C, 0x3D },
    { D_800A5854, NULL, 0x3D },
    { D_800A586C, NULL, 0x3D },
    { D_800A5888, D_800A58A4, 0x3D },
    { NULL, NULL, 0 },
};
u16 D_800A5A8C[] = { 0x202, 0, 0xFFFF };
u16 D_800A5A94[] = { 0x7003, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A5AA4[] = { 0x7009, 1, 0x11, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5AB4[] = { 0x7004, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A5AC4[] = { 0x6026, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A5AD4[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5AE4[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5AEC = { D_800A5A8C, D_800A58AC, 0x21, 4, 1353, 405, 1 };
FieldActorEntry D_800A5B00 = { D_800A5A94, D_800A58C4, 0x2E, 5, 241, 297, 7 };
FieldActorEntry D_800A5B14 = { D_800A5AA4, D_800A5924, 0x2E, 5, 241, 297, 7 };
FieldActorEntry D_800A5B28 = { D_800A5AB4, D_800A5954, 0x2E, 5, 241, 297, 7 };
FieldActorEntry D_800A5B3C = { D_800A5AC4, D_800A59B4, 0x2E, 5, 241, 297, 7 };
FieldActorEntry D_800A5B50 = { D_800A5AD4, D_800A5A14, 0x2E, 5, 241, 297, 7 };
FieldActorEntry D_800A5B64 = { D_800A5AE4, D_800A5A2C, 0x9D, 6, 241, 297, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5AEC,
    &D_800A5B00,
    &D_800A5B14,
    &D_800A5B28,
    &D_800A5B3C,
    &D_800A5B50,
    &D_800A5B64,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 313, 257, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 730, 365, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 932, 55, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 161, 378, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 83, 403, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 50, 403, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 182, 431, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 196, 377, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 208, 446, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 188, 444, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 230, 394, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 273, 422, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 129, 383, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x44, 0x46, 0xA, 0, 196, 436, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 248, 483, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 272, 461, 0, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 441, 339, 339, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 488, 363, 363, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 527, 207, 207, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 576, 230, 230, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 584, 131, 131, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 632, 107, 107, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 679, 83, 83, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 687, 551, 551, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 760, 83, 83, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 784, 551, 551, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 808, 107, 107, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 856, 131, 131, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 880, 551, 551, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 896, 151, 151, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 944, 463, 463, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 991, 440, 440, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1037, 410, 410, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1079, 395, 395, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1144, 387, 387, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1192, 410, 410, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1240, 435, 435, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1280, 455, 455, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1304, 499, 499, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1328, 335, 335, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1336, 531, 531, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1368, 355, 355, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1380, 553, 553, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1411, 376, 376, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x21E, 0x28C, 0x33C, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x222, 0x8C, 0xCE, 7, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x50, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0xF, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 9000, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
