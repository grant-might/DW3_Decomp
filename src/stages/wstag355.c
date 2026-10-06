#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#define STAGE_CHILDREN_SIZE 0x50
#include "common/start_stage.inc.c"

extern FieldBattles D_800A54BC[];
extern FieldBattles D_800A54D8[];
extern FieldBattles D_800A54F4[];
#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x1AD
#define STAGE_ARCHIVE 0x3C5
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x1BB
#define STAGE_ARCHIVE 0x3D5
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16 | 1;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x13800, 0x27100};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2D;
    D_800990B4.music = 0x60B40000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress < 0xB) {
        D_800990B4.battles = D_800A54BC;
    } else if (GAME.progress < 0x18) {
        D_800990B4.battles = D_800A54D8;
    } else {
        D_800990B4.battles = D_800A54F4;
    }
}

extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4EB0;
extern Battle D_800A4EBC;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F34;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50B4;
extern Battle D_800A50C0;
extern Battle D_800A50CC;
extern Battle D_800A50D8;
extern Battle D_800A50E4;
extern Battle D_800A50F0;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern Battle D_800A5138;
extern Battle D_800A5144;
extern Battle D_800A5150;
extern Battle D_800A515C;
extern Battle D_800A5168;
extern Battle D_800A5174;
extern Battle D_800A51A4;
extern Battle D_800A51B0;
extern Battle D_800A51BC;
extern Battle D_800A51C8;
extern Battle D_800A51D4;
extern Battle D_800A51E0;
extern Battle D_800A51EC;
extern Battle D_800A51F8;
extern Battle D_800A5228;
extern Battle D_800A5234;
extern Battle D_800A5240;
extern Battle D_800A524C;
extern Battle D_800A5258;
extern Battle D_800A5264;
extern Battle D_800A5270;
extern Battle D_800A527C;
extern Battle D_800A52AC;
extern Battle D_800A52B8;
extern Battle D_800A52C4;
extern Battle D_800A52D0;
extern Battle D_800A52DC;
extern Battle D_800A52E8;
extern Battle D_800A52F4;
extern Battle D_800A5300;
extern Battle D_800A5330;
extern Battle D_800A533C;
extern Battle D_800A5348;
extern Battle D_800A5354;
extern Battle D_800A5360;
extern Battle D_800A536C;
extern Battle D_800A5378;
extern Battle D_800A5384;
extern Battle D_800A53B4;
extern Battle D_800A53C0;
extern Battle D_800A53CC;
extern Battle D_800A53D8;
extern Battle D_800A53E4;
extern Battle D_800A53F0;
extern Battle D_800A53FC;
extern Battle D_800A5408;
extern Battle D_800A5438;
extern Battle D_800A5444;
extern Battle D_800A5450;
extern Battle D_800A545C;
extern Battle D_800A5468;
extern Battle D_800A5474;
extern Battle D_800A5480;
extern Battle D_800A548C;
extern BattleList D_800A4EEC;
extern BattleList D_800A4F70;
extern BattleList D_800A4FF4;
extern BattleList D_800A5078;
extern BattleList D_800A50FC;
extern BattleList D_800A5180;
extern BattleList D_800A5204;
extern BattleList D_800A5288;
extern BattleList D_800A530C;
extern BattleList D_800A5390;
extern BattleList D_800A5414;
extern BattleList D_800A5498;
extern u16 D_800A55C0[];
extern u16 D_800A55CC[];
extern u16 D_800A55D8[];
extern u16 D_800A55E4[];
extern u16 D_800A55EC[];
extern u16 D_800A55FC[];
extern u16 D_800A5604[];
extern u16 D_800A5614[];
extern u16 D_800A561C[];
extern u16 D_800A562C[];
extern u16 D_800A5634[];
extern u16 D_800A5644[];
extern u16 D_800A5658[];
extern u16 D_800A5660[];
extern u16 D_800A5678[];
extern u16 D_800A5684[];
extern u16 D_800A56A0[];
extern u16 D_800A56C0[];
extern u16 D_800A56E0[];
extern u16 D_800A56E8[];
extern u16 D_800A56F0[];
extern u16 D_800A56F8[];
extern u16 D_800A5704[];
extern u16 D_800A5714[];
extern u16 D_800A571C[];
extern u16 D_800A5730[];
extern u16 D_800A573C[];
extern u16 D_800A5754[];
extern u16 D_800A5770[];
extern u16 D_800A578C[];
extern u16 D_800A5794[];
extern u16 D_800A579C[];
extern u16 D_800A57A4[];
extern u16 D_800A57B0[];
extern u16 D_800A57C0[];
extern u16 D_800A57C8[];
extern u16 D_800A57DC[];
extern u16 D_800A57E8[];
extern u16 D_800A5800[];
extern u16 D_800A581C[];
extern u16 D_800A5838[];
extern u16 D_800A5840[];
extern u16 D_800A5848[];
extern u16 D_800A5854[];
extern u16 D_800A585C[];
extern u16 D_800A5868[];
extern u16 D_800A5874[];
extern u16 D_800A5880[];
extern u16 D_800A588C[];
extern u16 D_800A5898[];
extern u16 D_800A58A0[];
extern u16 D_800A58B0[];
extern u16 D_800A58B8[];
extern u16 D_800A58C8[];
extern u16 D_800A58D0[];
extern u16 D_800A58E0[];
extern u16 D_800A58E8[];
extern u16 D_800A58F8[];
extern u16 D_800A590C[];
extern u16 D_800A5914[];
extern u16 D_800A592C[];
extern u16 D_800A5938[];
extern u16 D_800A5954[];
extern u16 D_800A5974[];
extern u16 D_800A5994[];
extern u16 D_800A599C[];
extern u16 D_800A59A4[];
extern u16 D_800A59B0[];
extern u16 D_800A59B8[];
extern u16 D_800A59C4[];
extern u16 D_800A59D0[];
extern u16 D_800A59D8[];
extern u16 D_800A59E0[];
extern u16 D_800A59EC[];
extern u16 D_800A59FC[];
extern u16 D_800A5A04[];
extern u16 D_800A5A18[];
extern u16 D_800A5A24[];
extern u16 D_800A5A3C[];
extern u16 D_800A5A58[];
extern u16 D_800A5A74[];
extern u16 D_800A5A7C[];
extern u16 D_800A5A84[];
extern u16 D_800A5A8C[];
extern u16 D_800A5A98[];
extern u16 D_800A5AA8[];
extern u16 D_800A5AB0[];
extern u16 D_800A5AC4[];
extern u16 D_800A5AD0[];
extern u16 D_800A5AE8[];
extern u16 D_800A5B04[];
extern u16 D_800A5B20[];
extern u16 D_800A5B28[];
extern u16 D_800A5B30[];
extern u16 D_800A5B3C[];
extern u16 D_800A5B4C[];
extern u16 D_800A5B54[];
extern u16 D_800A5B68[];
extern u16 D_800A5B70[];
extern u16 D_800A5B88[];
extern u16 D_800A5BA4[];
extern u16 D_800A5BC0[];
extern u16 D_800A5BC8[];
extern u16 D_800A5BD0[];
extern u16 D_800A5BDC[];
extern u16 D_800A5BEC[];
extern u16 D_800A5BF4[];
extern u16 D_800A5C08[];
extern u16 D_800A5C10[];
extern u16 D_800A5C28[];
extern u16 D_800A5C44[];
extern u16 D_800A5C60[];
extern u16 D_800A6070[];
extern FieldTalk D_800A5C68[];
extern u16 D_800A607C[];
extern FieldTalk D_800A5CF8[];
extern u16 D_800A6088[];
extern FieldTalk D_800A5D58[];
extern u16 D_800A6094[];
extern FieldTalk D_800A5DB8[];
extern u16 D_800A60A0[];
extern FieldTalk D_800A5DE8[];
extern u16 D_800A60AC[];
extern FieldTalk D_800A5E00[];
extern u16 D_800A60B8[];
extern FieldTalk D_800A5E90[];
extern u16 D_800A60C4[];
extern FieldTalk D_800A5EC0[];
extern u16 D_800A60D0[];
extern FieldTalk D_800A5F20[];
extern u16 D_800A60DC[];
extern FieldTalk D_800A5F80[];
extern FieldTalk D_800A5F98[];
extern u16 D_800A60E8[];
extern FieldTalk D_800A5FB0[];
extern u16 D_800A60F0[];
extern FieldTalk D_800A6010[];
extern FieldActorEntry D_800A60F8;
extern FieldActorEntry D_800A610C;
extern FieldActorEntry D_800A6120;
extern FieldActorEntry D_800A6134;
extern FieldActorEntry D_800A6148;
extern FieldActorEntry D_800A615C;
extern FieldActorEntry D_800A6170;
extern FieldActorEntry D_800A6184;
extern FieldActorEntry D_800A6198;
extern FieldActorEntry D_800A61AC;
extern FieldActorEntry D_800A61C0;
extern FieldActorEntry D_800A61D4;
extern FieldActorEntry D_800A61E8;

Battle D_800A4E8C = { 34, 13, 0x60080000 };
Battle D_800A4E98 = { 34, 13, 0x60080000 };
Battle D_800A4EA4 = { 39, 13, 0x60080000 };
Battle D_800A4EB0 = { 39, 13, 0x60080000 };
Battle D_800A4EBC = { 41, 13, 0x60080000 };
Battle D_800A4EC8 = { 41, 13, 0x60080000 };
Battle D_800A4ED4 = { 41, 13, 0x60080000 };
Battle D_800A4EE0 = { 41, 13, 0x60080000 };
BattleList D_800A4EEC = {
    3,
    { &D_800A4E8C, &D_800A4E98, &D_800A4EA4, &D_800A4EB0,
      &D_800A4EBC, &D_800A4EC8, &D_800A4ED4, &D_800A4EE0 },
};
Battle D_800A4F10 = { 0, 0, 0x60040000 };
Battle D_800A4F1C = { 0, 0, 0x60040000 };
Battle D_800A4F28 = { 0, 0, 0x60040000 };
Battle D_800A4F34 = { 0, 0, 0x60040000 };
Battle D_800A4F40 = { 0, 0, 0x60040000 };
Battle D_800A4F4C = { 0, 0, 0x60040000 };
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
BattleList D_800A4F70 = {
    0,
    { &D_800A4F10, &D_800A4F1C, &D_800A4F28, &D_800A4F34,
      &D_800A4F40, &D_800A4F4C, &D_800A4F58, &D_800A4F64 },
};
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
Battle D_800A4FB8 = { 0, 0, 0x60040000 };
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
BattleList D_800A4FF4 = {
    0,
    { &D_800A4F94, &D_800A4FA0, &D_800A4FAC, &D_800A4FB8,
      &D_800A4FC4, &D_800A4FD0, &D_800A4FDC, &D_800A4FE8 },
};
Battle D_800A5018 = { 204, 13, 0x600C0000 };
Battle D_800A5024 = { 205, 13, 0x600C0000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
Battle D_800A503C = { 327, 13, 0x60080000 };
Battle D_800A5048 = { 0, 0, 0x60040000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
Battle D_800A5060 = { 49, 13, 0x60080000 };
Battle D_800A506C = { 0, 0, 0x60040000 };
BattleList D_800A5078 = {
    0,
    { &D_800A5018, &D_800A5024, &D_800A5030, &D_800A503C,
      &D_800A5048, &D_800A5054, &D_800A5060, &D_800A506C },
};
Battle D_800A509C = { 41, 13, 0x60080000 };
Battle D_800A50A8 = { 41, 13, 0x60080000 };
Battle D_800A50B4 = { 45, 13, 0x60080000 };
Battle D_800A50C0 = { 45, 13, 0x60080000 };
Battle D_800A50CC = { 57, 13, 0x60080000 };
Battle D_800A50D8 = { 57, 13, 0x60080000 };
Battle D_800A50E4 = { 57, 13, 0x60080000 };
Battle D_800A50F0 = { 57, 13, 0x60080000 };
BattleList D_800A50FC = {
    3,
    { &D_800A509C, &D_800A50A8, &D_800A50B4, &D_800A50C0,
      &D_800A50CC, &D_800A50D8, &D_800A50E4, &D_800A50F0 },
};
Battle D_800A5120 = { 0, 0, 0x60040000 };
Battle D_800A512C = { 0, 0, 0x60040000 };
Battle D_800A5138 = { 0, 0, 0x60040000 };
Battle D_800A5144 = { 0, 0, 0x60040000 };
Battle D_800A5150 = { 0, 0, 0x60040000 };
Battle D_800A515C = { 0, 0, 0x60040000 };
Battle D_800A5168 = { 0, 0, 0x60040000 };
Battle D_800A5174 = { 0, 0, 0x60040000 };
BattleList D_800A5180 = {
    0,
    { &D_800A5120, &D_800A512C, &D_800A5138, &D_800A5144,
      &D_800A5150, &D_800A515C, &D_800A5168, &D_800A5174 },
};
Battle D_800A51A4 = { 0, 0, 0x60040000 };
Battle D_800A51B0 = { 0, 0, 0x60040000 };
Battle D_800A51BC = { 0, 0, 0x60040000 };
Battle D_800A51C8 = { 0, 0, 0x60040000 };
Battle D_800A51D4 = { 0, 0, 0x60040000 };
Battle D_800A51E0 = { 0, 0, 0x60040000 };
Battle D_800A51EC = { 0, 0, 0x60040000 };
Battle D_800A51F8 = { 0, 0, 0x60040000 };
BattleList D_800A5204 = {
    0,
    { &D_800A51A4, &D_800A51B0, &D_800A51BC, &D_800A51C8,
      &D_800A51D4, &D_800A51E0, &D_800A51EC, &D_800A51F8 },
};
Battle D_800A5228 = { 204, 13, 0x600C0000 };
Battle D_800A5234 = { 205, 13, 0x600C0000 };
Battle D_800A5240 = { 0, 0, 0x60040000 };
Battle D_800A524C = { 327, 13, 0x60080000 };
Battle D_800A5258 = { 0, 0, 0x60040000 };
Battle D_800A5264 = { 0, 0, 0x60040000 };
Battle D_800A5270 = { 49, 13, 0x60080000 };
Battle D_800A527C = { 0, 0, 0x60040000 };
BattleList D_800A5288 = {
    0,
    { &D_800A5228, &D_800A5234, &D_800A5240, &D_800A524C,
      &D_800A5258, &D_800A5264, &D_800A5270, &D_800A527C },
};
Battle D_800A52AC = { 45, 13, 0x60080000 };
Battle D_800A52B8 = { 45, 13, 0x60080000 };
Battle D_800A52C4 = { 57, 13, 0x60080000 };
Battle D_800A52D0 = { 57, 13, 0x60080000 };
Battle D_800A52DC = { 146, 13, 0x60080000 };
Battle D_800A52E8 = { 146, 13, 0x60080000 };
Battle D_800A52F4 = { 146, 13, 0x60080000 };
Battle D_800A5300 = { 146, 13, 0x60080000 };
BattleList D_800A530C = {
    3,
    { &D_800A52AC, &D_800A52B8, &D_800A52C4, &D_800A52D0,
      &D_800A52DC, &D_800A52E8, &D_800A52F4, &D_800A5300 },
};
Battle D_800A5330 = { 0, 0, 0x60040000 };
Battle D_800A533C = { 0, 0, 0x60040000 };
Battle D_800A5348 = { 0, 0, 0x60040000 };
Battle D_800A5354 = { 0, 0, 0x60040000 };
Battle D_800A5360 = { 0, 0, 0x60040000 };
Battle D_800A536C = { 0, 0, 0x60040000 };
Battle D_800A5378 = { 0, 0, 0x60040000 };
Battle D_800A5384 = { 0, 0, 0x60040000 };
BattleList D_800A5390 = {
    0,
    { &D_800A5330, &D_800A533C, &D_800A5348, &D_800A5354,
      &D_800A5360, &D_800A536C, &D_800A5378, &D_800A5384 },
};
Battle D_800A53B4 = { 0, 0, 0x60040000 };
Battle D_800A53C0 = { 0, 0, 0x60040000 };
Battle D_800A53CC = { 0, 0, 0x60040000 };
Battle D_800A53D8 = { 0, 0, 0x60040000 };
Battle D_800A53E4 = { 0, 0, 0x60040000 };
Battle D_800A53F0 = { 0, 0, 0x60040000 };
Battle D_800A53FC = { 0, 0, 0x60040000 };
Battle D_800A5408 = { 0, 0, 0x60040000 };
BattleList D_800A5414 = {
    0,
    { &D_800A53B4, &D_800A53C0, &D_800A53CC, &D_800A53D8,
      &D_800A53E4, &D_800A53F0, &D_800A53FC, &D_800A5408 },
};
Battle D_800A5438 = { 204, 13, 0x600C0000 };
Battle D_800A5444 = { 205, 13, 0x600C0000 };
Battle D_800A5450 = { 0, 0, 0x60040000 };
Battle D_800A545C = { 327, 13, 0x60080000 };
Battle D_800A5468 = { 0, 0, 0x60040000 };
Battle D_800A5474 = { 0, 0, 0x60040000 };
Battle D_800A5480 = { 49, 13, 0x60080000 };
Battle D_800A548C = { 0, 0, 0x60040000 };
BattleList D_800A5498 = {
    0,
    { &D_800A5438, &D_800A5444, &D_800A5450, &D_800A545C,
      &D_800A5468, &D_800A5474, &D_800A5480, &D_800A548C },
};
FieldBattles D_800A54BC[] = {
    { 6, 0, 0, { &D_800A4EEC, &D_800A4F70, &D_800A4FF4, &D_800A5078 } },
};
FieldBattles D_800A54D8[] = {
    { 23, 1, 0, { &D_800A50FC, &D_800A5180, &D_800A5204, &D_800A5288 } },
};
FieldBattles D_800A54F4[] = {
    { 52, 2, 0, { &D_800A530C, &D_800A5390, &D_800A5414, &D_800A5498 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16C, 0x146, 0xB0, 0x46, 0x150, 0x1FF },
    { 0x140, 0x100, 0x174, 0x146, 0xD0, 0x46, 0x160, 0x1FF },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x170, 0x16E, 0xC0, 0x6E, 0x170, 0x1FF },
    { 0x140, 0x100, 0x170, 0x18E, 0xC0, 0x8E, 0x150, 0x1FE },
};
u16 D_800A55C0[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A55CC[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A55D8[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A55E4[] = { 0x11, 0, 0xFFFF };
u16 D_800A55EC[] = { 0x11, 0, 1, 0, 0x7003, 1, 0xFFFF };
u16 D_800A55FC[] = { 1, 1, 0xFFFF };
u16 D_800A5604[] = { 0x11, 0, 1, 0, 0x7004, 1, 0xFFFF };
u16 D_800A5614[] = { 1, 1, 0xFFFF };
u16 D_800A561C[] = { 1, 0, 0x11, 0, 0x6026, 1, 0xFFFF };
u16 D_800A562C[] = { 1, 1, 0xFFFF };
u16 D_800A5634[] = { 1, 1, 0x7201, 0, 0x11, 0, 0xFFFF };
u16 D_800A5644[] = { 1, 1, 0x7201, 1, 0x7203, 0, 0x11, 0, 0xFFFF };
u16 D_800A5658[] = { 0x7609, 1, 0xFFFF };
u16 D_800A5660[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0xE05, 0,
    0x11, 0, 0xFFFF,
};
u16 D_800A5678[] = { 0xE05, 1, 0x7401, 1, 0xFFFF };
u16 D_800A5684[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 0,
    0xE05, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A56A0[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 0, 0xE05, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A56C0[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 1, 0xE05, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A56E0[] = { 0x7809, 1, 0xFFFF };
u16 D_800A56E8[] = { 1, 0, 0xFFFF };
u16 D_800A56F0[] = { 1, 1, 0xFFFF };
u16 D_800A56F8[] = { 1, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5704[] = { 1, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A5714[] = { 0x7609, 1, 0xFFFF };
u16 D_800A571C[] = { 0x7203, 1, 1, 1, 0x7201, 1, 0xE05, 0, 0xFFFF };
u16 D_800A5730[] = { 0xE05, 1, 0x7401, 1, 0xFFFF };
u16 D_800A573C[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 0,
    0xE05, 1, 0xFFFF,
};
u16 D_800A5754[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 0, 0xE05, 1, 0xFFFF,
};
u16 D_800A5770[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 1, 0xE05, 1, 0xFFFF,
};
u16 D_800A578C[] = { 0x7809, 1, 0xFFFF };
u16 D_800A5794[] = { 1, 0, 0xFFFF };
u16 D_800A579C[] = { 1, 1, 0xFFFF };
u16 D_800A57A4[] = { 1, 1, 0x7201, 0, 0xFFFF };
u16 D_800A57B0[] = { 1, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A57C0[] = { 0x7609, 1, 0xFFFF };
u16 D_800A57C8[] = { 1, 1, 0x7201, 1, 0x7203, 1, 0xE05, 0, 0xFFFF };
u16 D_800A57DC[] = { 0x7401, 1, 0xE05, 1, 0xFFFF };
u16 D_800A57E8[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 0,
    0xE05, 1, 0xFFFF,
};
u16 D_800A5800[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 0, 0xE05, 1, 0xFFFF,
};
u16 D_800A581C[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 1, 0xE05, 1, 0xFFFF,
};
u16 D_800A5838[] = { 0x7809, 1, 0xFFFF };
u16 D_800A5840[] = { 0x11, 0, 0xFFFF };
u16 D_800A5848[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5854[] = { 0x11, 0, 0xFFFF };
u16 D_800A585C[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5868[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5874[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A5880[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A588C[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A5898[] = { 0x11, 0, 0xFFFF };
u16 D_800A58A0[] = { 0x11, 0, 0, 0, 0x7003, 1, 0xFFFF };
u16 D_800A58B0[] = { 0, 1, 0xFFFF };
u16 D_800A58B8[] = { 0x11, 0, 0, 0, 0x7004, 1, 0xFFFF };
u16 D_800A58C8[] = { 0, 1, 0xFFFF };
u16 D_800A58D0[] = { 0, 0, 0x11, 0, 0x6026, 1, 0xFFFF };
u16 D_800A58E0[] = { 0, 1, 0xFFFF };
u16 D_800A58E8[] = { 0, 1, 0x7201, 0, 0x11, 0, 0xFFFF };
u16 D_800A58F8[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0x11, 0, 0xFFFF };
u16 D_800A590C[] = { 0x7608, 1, 0xFFFF };
u16 D_800A5914[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE04, 0,
    0x11, 0, 0xFFFF,
};
u16 D_800A592C[] = { 0x7400, 1, 0xE04, 1, 0xFFFF };
u16 D_800A5938[] = {
    0, 1, 0x7203, 1, 0x8012, 0, 0x7201, 1,
    0xE04, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5954[] = {
    0xE04, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 1, 0x7205, 0, 0x11, 0, 0xFFFF,
};
u16 D_800A5974[] = {
    0xE04, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 1, 0x7205, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5994[] = { 0x7808, 1, 0xFFFF };
u16 D_800A599C[] = { 0x11, 0, 0xFFFF };
u16 D_800A59A4[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A59B0[] = { 0x11, 0, 0xFFFF };
u16 D_800A59B8[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A59C4[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A59D0[] = { 0, 0, 0xFFFF };
u16 D_800A59D8[] = { 0, 1, 0xFFFF };
u16 D_800A59E0[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A59EC[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A59FC[] = { 0x7608, 1, 0xFFFF };
u16 D_800A5A04[] = { 0x7201, 1, 0xE04, 0, 0, 1, 0x7203, 1, 0xFFFF };
u16 D_800A5A18[] = { 0x7400, 1, 0xE04, 1, 0xFFFF };
u16 D_800A5A24[] = {
    0xE04, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5A3C[] = {
    0xE04, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A5A58[] = {
    0xE04, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A5A74[] = { 0x7808, 1, 0xFFFF };
u16 D_800A5A7C[] = { 0, 0, 0xFFFF };
u16 D_800A5A84[] = { 0, 1, 0xFFFF };
u16 D_800A5A8C[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5A98[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A5AA8[] = { 0x7608, 1, 0xFFFF };
u16 D_800A5AB0[] = { 0, 1, 0x7203, 1, 0x7201, 1, 0xE04, 0, 0xFFFF };
u16 D_800A5AC4[] = { 0x7400, 1, 0xE04, 1, 0xFFFF };
u16 D_800A5AD0[] = {
    0xE04, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5AE8[] = {
    0xE04, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A5B04[] = {
    0xE04, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A5B20[] = { 0x7808, 1, 0xFFFF };
u16 D_800A5B28[] = { 0, 0, 0xFFFF };
u16 D_800A5B30[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5B3C[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A5B4C[] = { 0x7608, 1, 0xFFFF };
u16 D_800A5B54[] = { 0x7201, 1, 0xE04, 0, 0, 1, 0x7203, 1, 0xFFFF };
u16 D_800A5B68[] = { 0xE04, 1, 0xFFFF };
u16 D_800A5B70[] = {
    0x8012, 0, 0xE04, 1, 0, 1, 0x7201, 1,
    0x7203, 1, 0xFFFF,
};
u16 D_800A5B88[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 0, 0xE04, 1, 0xFFFF,
};
u16 D_800A5BA4[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 1, 0xE04, 1, 0xFFFF,
};
u16 D_800A5BC0[] = { 0x7808, 1, 0xFFFF };
u16 D_800A5BC8[] = { 1, 0, 0xFFFF };
u16 D_800A5BD0[] = { 1, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5BDC[] = { 1, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A5BEC[] = { 0x7609, 1, 0xFFFF };
u16 D_800A5BF4[] = { 1, 1, 0x7201, 1, 0x7203, 1, 0xE05, 0, 0xFFFF };
u16 D_800A5C08[] = { 0xE05, 1, 0xFFFF };
u16 D_800A5C10[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 0,
    0xE05, 1, 0xFFFF,
};
u16 D_800A5C28[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 0, 0xE05, 1, 0xFFFF,
};
u16 D_800A5C44[] = {
    1, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 1, 0xE05, 1, 0xFFFF,
};
u16 D_800A5C60[] = { 0x7809, 1, 0xFFFF };
FieldTalk D_800A5C68[] = {
    { D_800A55C0, D_800A55CC, 0x5D },
    { D_800A55D8, D_800A55E4, 0x5C },
    { D_800A55EC, D_800A55FC, 0x52 },
    { D_800A5604, D_800A5614, 0x53 },
    { D_800A561C, D_800A562C, 0x5B },
    { D_800A5634, NULL, 0x56 },
    { D_800A5644, D_800A5658, 0x57 },
    { D_800A5660, D_800A5678, 0x58 },
    { D_800A5684, NULL, 0x59 },
    { D_800A56A0, NULL, 0x5A },
    { D_800A56C0, D_800A56E0, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CF8[] = {
    { D_800A56E8, D_800A56F0, 0x53 },
    { D_800A56F8, NULL, 0x56 },
    { D_800A5704, D_800A5714, 0x57 },
    { D_800A571C, D_800A5730, 0x58 },
    { D_800A573C, NULL, 0x59 },
    { D_800A5754, NULL, 0x5A },
    { D_800A5770, D_800A578C, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D58[] = {
    { D_800A5794, D_800A579C, 0x5B },
    { D_800A57A4, NULL, 0x56 },
    { D_800A57B0, D_800A57C0, 0x57 },
    { D_800A57C8, D_800A57DC, 0x58 },
    { D_800A57E8, NULL, 0x59 },
    { D_800A5800, NULL, 0x5A },
    { D_800A581C, D_800A5838, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DB8[] = {
    { D_800A5840, NULL, 0x52 },
    { D_800A5848, D_800A5854, 0x5C },
    { D_800A585C, D_800A5868, 0x5D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DE8[] = {
    { NULL, NULL, 0x274 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E00[] = {
    { D_800A5874, D_800A5880, 0x51 },
    { D_800A588C, D_800A5898, 0x50 },
    { D_800A58A0, D_800A58B0, 0x46 },
    { D_800A58B8, D_800A58C8, 0x47 },
    { D_800A58D0, D_800A58E0, 0x48 },
    { D_800A58E8, NULL, 0x4B },
    { D_800A58F8, D_800A590C, 0x4C },
    { D_800A5914, D_800A592C, 0x4D },
    { D_800A5938, NULL, 0x4E },
    { D_800A5954, NULL, 0x4F },
    { D_800A5974, D_800A5994, 0x78 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E90[] = {
    { D_800A599C, NULL, 0x46 },
    { D_800A59A4, D_800A59B0, 0x50 },
    { D_800A59B8, D_800A59C4, 0x51 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EC0[] = {
    { D_800A59D0, D_800A59D8, 0x47 },
    { D_800A59E0, NULL, 0x4B },
    { D_800A59EC, D_800A59FC, 0x4C },
    { D_800A5A04, D_800A5A18, 0x4D },
    { D_800A5A24, NULL, 0x4E },
    { D_800A5A3C, NULL, 0x4F },
    { D_800A5A58, D_800A5A74, 0x78 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F20[] = {
    { D_800A5A7C, D_800A5A84, 0x48 },
    { D_800A5A8C, NULL, 0x4B },
    { D_800A5A98, D_800A5AA8, 0x4C },
    { D_800A5AB0, D_800A5AC4, 0x4D },
    { D_800A5AD0, NULL, 0x4E },
    { D_800A5AE8, NULL, 0x4F },
    { D_800A5B04, D_800A5B20, 0x78 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F80[] = {
    { NULL, NULL, 0x273 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F98[] = {
    { NULL, NULL, 0xF0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FB0[] = {
    { D_800A5B28, NULL, 0x49 },
    { D_800A5B30, NULL, 0x49 },
    { D_800A5B3C, D_800A5B4C, 0x49 },
    { D_800A5B54, D_800A5B68, 0x49 },
    { D_800A5B70, NULL, 0x49 },
    { D_800A5B88, NULL, 0x49 },
    { D_800A5BA4, D_800A5BC0, 0x49 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6010[] = {
    { D_800A5BC8, NULL, 0x54 },
    { D_800A5BD0, NULL, 0x54 },
    { D_800A5BDC, D_800A5BEC, 0x54 },
    { D_800A5BF4, D_800A5C08, 0x54 },
    { D_800A5C10, NULL, 0x54 },
    { D_800A5C28, NULL, 0x54 },
    { D_800A5C44, D_800A5C60, 0x54 },
    { NULL, NULL, 0 },
};
u16 D_800A6070[] = { 0x7022, 1, 0x8192, 1, 0xFFFF };
u16 D_800A607C[] = { 0x8192, 1, 0x602B, 1, 0xFFFF };
u16 D_800A6088[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6094[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A60A0[] = { 0x8192, 0, 0x7022, 1, 0xFFFF };
u16 D_800A60AC[] = { 0x7022, 1, 0x8192, 1, 0xFFFF };
u16 D_800A60B8[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A60C4[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A60D0[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A60DC[] = { 0x8192, 0, 0x7022, 1, 0xFFFF };
u16 D_800A60E8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A60F0[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A60F8 = { D_800A6070, D_800A5C68, 0x35, 4, 731, 350, 7 };
FieldActorEntry D_800A610C = { D_800A607C, D_800A5CF8, 0x35, 4, 731, 350, 7 };
FieldActorEntry D_800A6120 = { D_800A6088, D_800A5D58, 0x35, 4, 731, 350, 7 };
FieldActorEntry D_800A6134 = { D_800A6094, D_800A5DB8, 0x35, 4, 731, 350, 7 };
FieldActorEntry D_800A6148 = { D_800A60A0, D_800A5DE8, 0x35, 4, 731, 350, 7 };
FieldActorEntry D_800A615C = { D_800A60AC, D_800A5E00, 0x38, 5, 545, 249, 1 };
FieldActorEntry D_800A6170 = { D_800A60B8, D_800A5E90, 0x38, 5, 545, 249, 1 };
FieldActorEntry D_800A6184 = { D_800A60C4, D_800A5EC0, 0x38, 5, 545, 249, 1 };
FieldActorEntry D_800A6198 = { D_800A60D0, D_800A5F20, 0x38, 5, 545, 249, 1 };
FieldActorEntry D_800A61AC = { D_800A60DC, D_800A5F80, 0x38, 5, 545, 249, 1 };
FieldActorEntry D_800A61C0 = { NULL, D_800A5F98, 0x3F, 6, 319, 600, 1 };
FieldActorEntry D_800A61D4 = { D_800A60E8, D_800A5FB0, 0x9D, 7, 545, 249, 1 };
FieldActorEntry D_800A61E8 = { D_800A60F0, D_800A6010, 0x9E, 8, 731, 350, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A60F8,
    &D_800A610C,
    &D_800A6120,
    &D_800A6134,
    &D_800A6148,
    &D_800A615C,
    &D_800A6170,
    &D_800A6184,
    &D_800A6198,
    &D_800A61AC,
    &D_800A61C0,
    &D_800A61D4,
    &D_800A61E8,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 68, 778, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 159, 733, 0, 0 },
    { 1, 0, 0x80, 2, 4, 0, 0, 0, 0, 0, 13, 758, 0, 0 },
    { 1, 0x64, 0x40, 6, 2, 0, 0, 0, 0, 0, 89, 730, 0, 0 },
    { 1, 0, 0x72, 4, 0, 0, 0, 0, 0, 0, 0, 657, 795, 0 },
    { 1, 0, 0x76, 4, 1, 0, 0, 0, 0, 0, 40, 677, 795, 0 },
    { 1, 0, 0x60, 4, 3, 0, 0, 0, 0, 0, 290, 502, 595, 0 },
    { 1, 0, 0x80, 4, 5, 0, 0, 0, 0, 0, 63, 783, 795, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 103, 347, 347, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 119, 387, 387, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 156, 539, 539, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 168, 339, 339, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 169, 579, 579, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 184, 298, 298, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 185, 379, 379, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 206, 603, 603, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 232, 356, 356, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 238, 215, 215, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 249, 635, 635, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 280, 667, 667, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 296, 723, 723, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 312, 219, 219, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 360, 198, 198, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 392, 323, 323, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 400, 631, 631, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 423, 219, 219, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 424, 291, 291, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 440, 603, 603, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 472, 347, 347, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 487, 307, 307, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 552, 451, 451, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 595, 479, 479, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 597, 595, 595, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 597, 691, 691, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 600, 203, 203, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 608, 823, 823, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 623, 231, 231, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 625, 723, 723, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 642, 763, 763, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 648, 803, 803, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 680, 570, 570, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 728, 603, 603, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 760, 195, 195, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 833, 659, 659, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 840, 267, 267, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 845, 571, 571, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 871, 315, 315, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x221, 0x598, 0x260, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x227, 0x154, 0x6A, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x225, 0x80, 0x31C, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x223, 0x1B2, 0x156, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
