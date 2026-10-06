#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places_last.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x6E1
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x6F1
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x13300, 0x13B00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1D;
    D_800990B4.music = 0x60740000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A4FB0;
extern StagePoint D_800A4FC0;
extern StagePoint D_800A4FD8;
extern StagePoint D_800A4FE8;
extern StagePoint D_800A5000;
extern StagePoint D_800A5010;
extern StagePoint D_800A5028;
extern StagePoint D_800A5038;
extern StagePoint D_800A5050;
extern StagePoint D_800A5060;
extern StagePoint D_800A5078;
extern StagePoint D_800A5088;
extern StagePoint D_800A50A0;
extern StagePoint D_800A50B0;
extern StagePoint D_800A50C8;
extern StagePoint D_800A50D8;
extern StagePoints D_800A4FD0;
extern StagePoints D_800A4FF8;
extern StagePoints D_800A5020;
extern StagePoints D_800A5048;
extern StagePoints D_800A5070;
extern StagePoints D_800A5098;
extern StagePoints D_800A50C0;
extern StagePoints D_800A50E8;
extern StagePoints D_800A50F0;
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
extern Battle D_800A54BC;
extern Battle D_800A54C8;
extern Battle D_800A54D4;
extern Battle D_800A54E0;
extern Battle D_800A54EC;
extern Battle D_800A54F8;
extern Battle D_800A5504;
extern Battle D_800A5510;
extern Battle D_800A5540;
extern Battle D_800A554C;
extern Battle D_800A5558;
extern Battle D_800A5564;
extern Battle D_800A5570;
extern Battle D_800A557C;
extern Battle D_800A5588;
extern Battle D_800A5594;
extern Battle D_800A55C4;
extern Battle D_800A55D0;
extern Battle D_800A55DC;
extern Battle D_800A55E8;
extern Battle D_800A55F4;
extern Battle D_800A5600;
extern Battle D_800A560C;
extern Battle D_800A5618;
extern Battle D_800A5648;
extern Battle D_800A5654;
extern Battle D_800A5660;
extern Battle D_800A566C;
extern Battle D_800A5678;
extern Battle D_800A5684;
extern Battle D_800A5690;
extern Battle D_800A569C;
extern Battle D_800A56CC;
extern Battle D_800A56D8;
extern Battle D_800A56E4;
extern Battle D_800A56F0;
extern Battle D_800A56FC;
extern Battle D_800A5708;
extern Battle D_800A5714;
extern Battle D_800A5720;
extern Battle D_800A5750;
extern Battle D_800A575C;
extern Battle D_800A5768;
extern Battle D_800A5774;
extern Battle D_800A5780;
extern Battle D_800A578C;
extern Battle D_800A5798;
extern Battle D_800A57A4;
extern Battle D_800A57D4;
extern Battle D_800A57E0;
extern Battle D_800A57EC;
extern Battle D_800A57F8;
extern Battle D_800A5804;
extern Battle D_800A5810;
extern Battle D_800A581C;
extern Battle D_800A5828;
extern Battle D_800A5858;
extern Battle D_800A5864;
extern Battle D_800A5870;
extern Battle D_800A587C;
extern Battle D_800A5888;
extern Battle D_800A5894;
extern Battle D_800A58A0;
extern Battle D_800A58AC;
extern Battle D_800A58DC;
extern Battle D_800A58E8;
extern Battle D_800A58F4;
extern Battle D_800A5900;
extern Battle D_800A590C;
extern Battle D_800A5918;
extern Battle D_800A5924;
extern Battle D_800A5930;
extern Battle D_800A5960;
extern Battle D_800A596C;
extern Battle D_800A5978;
extern Battle D_800A5984;
extern Battle D_800A5990;
extern Battle D_800A599C;
extern Battle D_800A59A8;
extern Battle D_800A59B4;
extern Battle D_800A59E4;
extern Battle D_800A59F0;
extern Battle D_800A59FC;
extern Battle D_800A5A08;
extern Battle D_800A5A14;
extern Battle D_800A5A20;
extern Battle D_800A5A2C;
extern Battle D_800A5A38;
extern Battle D_800A5A68;
extern Battle D_800A5A74;
extern Battle D_800A5A80;
extern Battle D_800A5A8C;
extern Battle D_800A5A98;
extern Battle D_800A5AA4;
extern Battle D_800A5AB0;
extern Battle D_800A5ABC;
extern Battle D_800A5AEC;
extern Battle D_800A5AF8;
extern Battle D_800A5B04;
extern Battle D_800A5B10;
extern Battle D_800A5B1C;
extern Battle D_800A5B28;
extern Battle D_800A5B34;
extern Battle D_800A5B40;
extern Battle D_800A5B70;
extern Battle D_800A5B7C;
extern Battle D_800A5B88;
extern Battle D_800A5B94;
extern Battle D_800A5BA0;
extern Battle D_800A5BAC;
extern Battle D_800A5BB8;
extern Battle D_800A5BC4;
extern Battle D_800A5BF4;
extern Battle D_800A5C00;
extern Battle D_800A5C0C;
extern Battle D_800A5C18;
extern Battle D_800A5C24;
extern Battle D_800A5C30;
extern Battle D_800A5C3C;
extern Battle D_800A5C48;
extern Battle D_800A5C78;
extern Battle D_800A5C84;
extern Battle D_800A5C90;
extern Battle D_800A5C9C;
extern Battle D_800A5CA8;
extern Battle D_800A5CB4;
extern Battle D_800A5CC0;
extern Battle D_800A5CCC;
extern Battle D_800A5CFC;
extern Battle D_800A5D08;
extern Battle D_800A5D14;
extern Battle D_800A5D20;
extern Battle D_800A5D2C;
extern Battle D_800A5D38;
extern Battle D_800A5D44;
extern Battle D_800A5D50;
extern Battle D_800A5D80;
extern Battle D_800A5D8C;
extern Battle D_800A5D98;
extern Battle D_800A5DA4;
extern Battle D_800A5DB0;
extern Battle D_800A5DBC;
extern Battle D_800A5DC8;
extern Battle D_800A5DD4;
extern Battle D_800A5E04;
extern Battle D_800A5E10;
extern Battle D_800A5E1C;
extern Battle D_800A5E28;
extern Battle D_800A5E34;
extern Battle D_800A5E40;
extern Battle D_800A5E4C;
extern Battle D_800A5E58;
extern Battle D_800A5E88;
extern Battle D_800A5E94;
extern Battle D_800A5EA0;
extern Battle D_800A5EAC;
extern Battle D_800A5EB8;
extern Battle D_800A5EC4;
extern Battle D_800A5ED0;
extern Battle D_800A5EDC;
extern Battle D_800A5F0C;
extern Battle D_800A5F18;
extern Battle D_800A5F24;
extern Battle D_800A5F30;
extern Battle D_800A5F3C;
extern Battle D_800A5F48;
extern Battle D_800A5F54;
extern Battle D_800A5F60;
extern Battle D_800A5F90;
extern Battle D_800A5F9C;
extern Battle D_800A5FA8;
extern Battle D_800A5FB4;
extern Battle D_800A5FC0;
extern Battle D_800A5FCC;
extern Battle D_800A5FD8;
extern Battle D_800A5FE4;
extern Battle D_800A6014;
extern Battle D_800A6020;
extern Battle D_800A602C;
extern Battle D_800A6038;
extern Battle D_800A6044;
extern Battle D_800A6050;
extern Battle D_800A605C;
extern Battle D_800A6068;
extern Battle D_800A6098;
extern Battle D_800A60A4;
extern Battle D_800A60B0;
extern Battle D_800A60BC;
extern Battle D_800A60C8;
extern Battle D_800A60D4;
extern Battle D_800A60E0;
extern Battle D_800A60EC;
extern Battle D_800A611C;
extern Battle D_800A6128;
extern Battle D_800A6134;
extern Battle D_800A6140;
extern Battle D_800A614C;
extern Battle D_800A6158;
extern Battle D_800A6164;
extern Battle D_800A6170;
extern BattleList D_800A5180;
extern BattleList D_800A5204;
extern BattleList D_800A5288;
extern BattleList D_800A530C;
extern BattleList D_800A5390;
extern BattleList D_800A5414;
extern BattleList D_800A5498;
extern BattleList D_800A551C;
extern BattleList D_800A55A0;
extern BattleList D_800A5624;
extern BattleList D_800A56A8;
extern BattleList D_800A572C;
extern BattleList D_800A57B0;
extern BattleList D_800A5834;
extern BattleList D_800A58B8;
extern BattleList D_800A593C;
extern BattleList D_800A59C0;
extern BattleList D_800A5A44;
extern BattleList D_800A5AC8;
extern BattleList D_800A5B4C;
extern BattleList D_800A5BD0;
extern BattleList D_800A5C54;
extern BattleList D_800A5CD8;
extern BattleList D_800A5D5C;
extern BattleList D_800A5DE0;
extern BattleList D_800A5E64;
extern BattleList D_800A5EE8;
extern BattleList D_800A5F6C;
extern BattleList D_800A5FF0;
extern BattleList D_800A6074;
extern BattleList D_800A60F8;
extern BattleList D_800A617C;
extern FieldActorEntry D_800A62F0;

StagePoint D_800A4FB0 = { 0x2E5, 1, 1, 0x3B0, 216, 1, NULL };
StagePoint D_800A4FC0 = { 0x2E0, 1, 1, 176, 0x178, 5, &D_800A4FB0 };
StagePoints D_800A4FD0 = { 1, 1, &D_800A4FC0 };
StagePoint D_800A4FD8 = { 0x2E2, 3, 1, 0x330, 248, 1, NULL };
StagePoint D_800A4FE8 = { 0x2E3, 3, 1, 160, 0x180, 5, &D_800A4FD8 };
StagePoints D_800A4FF8 = { 3, 1, &D_800A4FE8 };
StagePoint D_800A5000 = { 0x2E2, 5, 1, 0x330, 248, 1, NULL };
StagePoint D_800A5010 = { 0x2E4, 5, 1, 192, 0x180, 5, &D_800A5000 };
StagePoints D_800A5020 = { 5, 1, &D_800A5010 };
StagePoint D_800A5028 = { 0x2E2, 9, 1, 0x330, 248, 1, NULL };
StagePoint D_800A5038 = { 0x2E3, 9, 1, 160, 0x180, 5, &D_800A5028 };
StagePoints D_800A5048 = { 9, 1, &D_800A5038 };
StagePoint D_800A5050 = { 0x2E5, 11, 1, 0x3B0, 216, 1, NULL };
StagePoint D_800A5060 = { 0x2E0, 11, 1, 176, 0x178, 5, &D_800A5050 };
StagePoints D_800A5070 = { 11, 1, &D_800A5060 };
StagePoint D_800A5078 = { 0x2E2, 13, 1, 0x330, 248, 1, NULL };
StagePoint D_800A5088 = { 0x2E3, 13, 1, 160, 0x180, 5, &D_800A5078 };
StagePoints D_800A5098 = { 13, 1, &D_800A5088 };
StagePoint D_800A50A0 = { 0x2E2, 15, 1, 0x330, 248, 1, NULL };
StagePoint D_800A50B0 = { 0x2E4, 15, 1, 192, 0x180, 5, &D_800A50A0 };
StagePoints D_800A50C0 = { 15, 1, &D_800A50B0 };
StagePoint D_800A50C8 = { 0x2E2, 19, 1, 0x330, 248, 1, NULL };
StagePoint D_800A50D8 = { 0x2E3, 19, 1, 160, 0x180, 5, &D_800A50C8 };
StagePoints D_800A50E8 = { 19, 1, &D_800A50D8 };
StagePoints D_800A50F0 = { 0, 0, &D_800A4FE8 };
StagePoints *placePoints[] = {
    &D_800A4FD0, &D_800A4FF8, &D_800A5020, &D_800A5048,
    &D_800A5070, &D_800A5098, &D_800A50C0, &D_800A50E8,
    &D_800A50F0, NULL,
};
Battle D_800A5120 = { 61, 11, 0x60080000 };
Battle D_800A512C = { 61, 11, 0x60080000 };
Battle D_800A5138 = { 61, 11, 0x60080000 };
Battle D_800A5144 = { 61, 11, 0x60080000 };
Battle D_800A5150 = { 62, 11, 0x60080000 };
Battle D_800A515C = { 62, 11, 0x60080000 };
Battle D_800A5168 = { 62, 11, 0x60080000 };
Battle D_800A5174 = { 62, 11, 0x60080000 };
BattleList D_800A5180 = {
    2,
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
Battle D_800A5228 = { 0, 0, 0x60040000 };
Battle D_800A5234 = { 0, 0, 0x60040000 };
Battle D_800A5240 = { 0, 0, 0x60040000 };
Battle D_800A524C = { 0, 0, 0x60040000 };
Battle D_800A5258 = { 0, 0, 0x60040000 };
Battle D_800A5264 = { 0, 0, 0x60040000 };
Battle D_800A5270 = { 0, 0, 0x60040000 };
Battle D_800A527C = { 0, 0, 0x60040000 };
BattleList D_800A5288 = {
    0,
    { &D_800A5228, &D_800A5234, &D_800A5240, &D_800A524C,
      &D_800A5258, &D_800A5264, &D_800A5270, &D_800A527C },
};
Battle D_800A52AC = { 0, 0, 0x60040000 };
Battle D_800A52B8 = { 0, 0, 0x60040000 };
Battle D_800A52C4 = { 0, 0, 0x60040000 };
Battle D_800A52D0 = { 0, 0, 0x60040000 };
Battle D_800A52DC = { 0, 0, 0x60040000 };
Battle D_800A52E8 = { 0, 0, 0x60040000 };
Battle D_800A52F4 = { 0, 0, 0x60040000 };
Battle D_800A5300 = { 0, 0, 0x60040000 };
BattleList D_800A530C = {
    0,
    { &D_800A52AC, &D_800A52B8, &D_800A52C4, &D_800A52D0,
      &D_800A52DC, &D_800A52E8, &D_800A52F4, &D_800A5300 },
};
Battle D_800A5330 = { 61, 11, 0x60080000 };
Battle D_800A533C = { 61, 11, 0x60080000 };
Battle D_800A5348 = { 61, 11, 0x60080000 };
Battle D_800A5354 = { 61, 11, 0x60080000 };
Battle D_800A5360 = { 61, 11, 0x60080000 };
Battle D_800A536C = { 61, 11, 0x60080000 };
Battle D_800A5378 = { 61, 11, 0x60080000 };
Battle D_800A5384 = { 61, 11, 0x60080000 };
BattleList D_800A5390 = {
    3,
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
Battle D_800A5438 = { 0, 0, 0x60040000 };
Battle D_800A5444 = { 0, 0, 0x60040000 };
Battle D_800A5450 = { 0, 0, 0x60040000 };
Battle D_800A545C = { 0, 0, 0x60040000 };
Battle D_800A5468 = { 0, 0, 0x60040000 };
Battle D_800A5474 = { 0, 0, 0x60040000 };
Battle D_800A5480 = { 0, 0, 0x60040000 };
Battle D_800A548C = { 0, 0, 0x60040000 };
BattleList D_800A5498 = {
    0,
    { &D_800A5438, &D_800A5444, &D_800A5450, &D_800A545C,
      &D_800A5468, &D_800A5474, &D_800A5480, &D_800A548C },
};
Battle D_800A54BC = { 0, 0, 0x60040000 };
Battle D_800A54C8 = { 0, 0, 0x60040000 };
Battle D_800A54D4 = { 0, 0, 0x60040000 };
Battle D_800A54E0 = { 0, 0, 0x60040000 };
Battle D_800A54EC = { 0, 0, 0x60040000 };
Battle D_800A54F8 = { 0, 0, 0x60040000 };
Battle D_800A5504 = { 0, 0, 0x60040000 };
Battle D_800A5510 = { 0, 0, 0x60040000 };
BattleList D_800A551C = {
    0,
    { &D_800A54BC, &D_800A54C8, &D_800A54D4, &D_800A54E0,
      &D_800A54EC, &D_800A54F8, &D_800A5504, &D_800A5510 },
};
Battle D_800A5540 = { 63, 11, 0x60080000 };
Battle D_800A554C = { 63, 11, 0x60080000 };
Battle D_800A5558 = { 63, 11, 0x60080000 };
Battle D_800A5564 = { 63, 11, 0x60080000 };
Battle D_800A5570 = { 63, 11, 0x60080000 };
Battle D_800A557C = { 63, 11, 0x60080000 };
Battle D_800A5588 = { 63, 11, 0x60080000 };
Battle D_800A5594 = { 63, 11, 0x60080000 };
BattleList D_800A55A0 = {
    3,
    { &D_800A5540, &D_800A554C, &D_800A5558, &D_800A5564,
      &D_800A5570, &D_800A557C, &D_800A5588, &D_800A5594 },
};
Battle D_800A55C4 = { 0, 0, 0x60040000 };
Battle D_800A55D0 = { 0, 0, 0x60040000 };
Battle D_800A55DC = { 0, 0, 0x60040000 };
Battle D_800A55E8 = { 0, 0, 0x60040000 };
Battle D_800A55F4 = { 0, 0, 0x60040000 };
Battle D_800A5600 = { 0, 0, 0x60040000 };
Battle D_800A560C = { 0, 0, 0x60040000 };
Battle D_800A5618 = { 0, 0, 0x60040000 };
BattleList D_800A5624 = {
    0,
    { &D_800A55C4, &D_800A55D0, &D_800A55DC, &D_800A55E8,
      &D_800A55F4, &D_800A5600, &D_800A560C, &D_800A5618 },
};
Battle D_800A5648 = { 0, 0, 0x60040000 };
Battle D_800A5654 = { 0, 0, 0x60040000 };
Battle D_800A5660 = { 0, 0, 0x60040000 };
Battle D_800A566C = { 0, 0, 0x60040000 };
Battle D_800A5678 = { 0, 0, 0x60040000 };
Battle D_800A5684 = { 0, 0, 0x60040000 };
Battle D_800A5690 = { 0, 0, 0x60040000 };
Battle D_800A569C = { 0, 0, 0x60040000 };
BattleList D_800A56A8 = {
    0,
    { &D_800A5648, &D_800A5654, &D_800A5660, &D_800A566C,
      &D_800A5678, &D_800A5684, &D_800A5690, &D_800A569C },
};
Battle D_800A56CC = { 0, 0, 0x60040000 };
Battle D_800A56D8 = { 0, 0, 0x60040000 };
Battle D_800A56E4 = { 0, 0, 0x60040000 };
Battle D_800A56F0 = { 0, 0, 0x60040000 };
Battle D_800A56FC = { 0, 0, 0x60040000 };
Battle D_800A5708 = { 0, 0, 0x60040000 };
Battle D_800A5714 = { 0, 0, 0x60040000 };
Battle D_800A5720 = { 0, 0, 0x60040000 };
BattleList D_800A572C = {
    0,
    { &D_800A56CC, &D_800A56D8, &D_800A56E4, &D_800A56F0,
      &D_800A56FC, &D_800A5708, &D_800A5714, &D_800A5720 },
};
Battle D_800A5750 = { 61, 11, 0x60080000 };
Battle D_800A575C = { 61, 11, 0x60080000 };
Battle D_800A5768 = { 61, 11, 0x60080000 };
Battle D_800A5774 = { 61, 11, 0x60080000 };
Battle D_800A5780 = { 61, 11, 0x60080000 };
Battle D_800A578C = { 61, 11, 0x60080000 };
Battle D_800A5798 = { 61, 11, 0x60080000 };
Battle D_800A57A4 = { 61, 11, 0x60080000 };
BattleList D_800A57B0 = {
    3,
    { &D_800A5750, &D_800A575C, &D_800A5768, &D_800A5774,
      &D_800A5780, &D_800A578C, &D_800A5798, &D_800A57A4 },
};
Battle D_800A57D4 = { 0, 0, 0x60040000 };
Battle D_800A57E0 = { 0, 0, 0x60040000 };
Battle D_800A57EC = { 0, 0, 0x60040000 };
Battle D_800A57F8 = { 0, 0, 0x60040000 };
Battle D_800A5804 = { 0, 0, 0x60040000 };
Battle D_800A5810 = { 0, 0, 0x60040000 };
Battle D_800A581C = { 0, 0, 0x60040000 };
Battle D_800A5828 = { 0, 0, 0x60040000 };
BattleList D_800A5834 = {
    0,
    { &D_800A57D4, &D_800A57E0, &D_800A57EC, &D_800A57F8,
      &D_800A5804, &D_800A5810, &D_800A581C, &D_800A5828 },
};
Battle D_800A5858 = { 0, 0, 0x60040000 };
Battle D_800A5864 = { 0, 0, 0x60040000 };
Battle D_800A5870 = { 0, 0, 0x60040000 };
Battle D_800A587C = { 0, 0, 0x60040000 };
Battle D_800A5888 = { 0, 0, 0x60040000 };
Battle D_800A5894 = { 0, 0, 0x60040000 };
Battle D_800A58A0 = { 0, 0, 0x60040000 };
Battle D_800A58AC = { 0, 0, 0x60040000 };
BattleList D_800A58B8 = {
    0,
    { &D_800A5858, &D_800A5864, &D_800A5870, &D_800A587C,
      &D_800A5888, &D_800A5894, &D_800A58A0, &D_800A58AC },
};
Battle D_800A58DC = { 0, 0, 0x60040000 };
Battle D_800A58E8 = { 0, 0, 0x60040000 };
Battle D_800A58F4 = { 0, 0, 0x60040000 };
Battle D_800A5900 = { 0, 0, 0x60040000 };
Battle D_800A590C = { 0, 0, 0x60040000 };
Battle D_800A5918 = { 0, 0, 0x60040000 };
Battle D_800A5924 = { 0, 0, 0x60040000 };
Battle D_800A5930 = { 0, 0, 0x60040000 };
BattleList D_800A593C = {
    0,
    { &D_800A58DC, &D_800A58E8, &D_800A58F4, &D_800A5900,
      &D_800A590C, &D_800A5918, &D_800A5924, &D_800A5930 },
};
Battle D_800A5960 = { 103, 11, 0x60080000 };
Battle D_800A596C = { 103, 11, 0x60080000 };
Battle D_800A5978 = { 103, 11, 0x60080000 };
Battle D_800A5984 = { 103, 11, 0x60080000 };
Battle D_800A5990 = { 103, 11, 0x60080000 };
Battle D_800A599C = { 103, 11, 0x60080000 };
Battle D_800A59A8 = { 103, 11, 0x60080000 };
Battle D_800A59B4 = { 103, 11, 0x60080000 };
BattleList D_800A59C0 = {
    2,
    { &D_800A5960, &D_800A596C, &D_800A5978, &D_800A5984,
      &D_800A5990, &D_800A599C, &D_800A59A8, &D_800A59B4 },
};
Battle D_800A59E4 = { 0, 0, 0x60040000 };
Battle D_800A59F0 = { 0, 0, 0x60040000 };
Battle D_800A59FC = { 0, 0, 0x60040000 };
Battle D_800A5A08 = { 0, 0, 0x60040000 };
Battle D_800A5A14 = { 0, 0, 0x60040000 };
Battle D_800A5A20 = { 0, 0, 0x60040000 };
Battle D_800A5A2C = { 0, 0, 0x60040000 };
Battle D_800A5A38 = { 0, 0, 0x60040000 };
BattleList D_800A5A44 = {
    0,
    { &D_800A59E4, &D_800A59F0, &D_800A59FC, &D_800A5A08,
      &D_800A5A14, &D_800A5A20, &D_800A5A2C, &D_800A5A38 },
};
Battle D_800A5A68 = { 0, 0, 0x60040000 };
Battle D_800A5A74 = { 0, 0, 0x60040000 };
Battle D_800A5A80 = { 0, 0, 0x60040000 };
Battle D_800A5A8C = { 0, 0, 0x60040000 };
Battle D_800A5A98 = { 0, 0, 0x60040000 };
Battle D_800A5AA4 = { 0, 0, 0x60040000 };
Battle D_800A5AB0 = { 0, 0, 0x60040000 };
Battle D_800A5ABC = { 0, 0, 0x60040000 };
BattleList D_800A5AC8 = {
    0,
    { &D_800A5A68, &D_800A5A74, &D_800A5A80, &D_800A5A8C,
      &D_800A5A98, &D_800A5AA4, &D_800A5AB0, &D_800A5ABC },
};
Battle D_800A5AEC = { 0, 0, 0x60040000 };
Battle D_800A5AF8 = { 0, 0, 0x60040000 };
Battle D_800A5B04 = { 0, 0, 0x60040000 };
Battle D_800A5B10 = { 0, 0, 0x60040000 };
Battle D_800A5B1C = { 0, 0, 0x60040000 };
Battle D_800A5B28 = { 0, 0, 0x60040000 };
Battle D_800A5B34 = { 0, 0, 0x60040000 };
Battle D_800A5B40 = { 0, 0, 0x60040000 };
BattleList D_800A5B4C = {
    0,
    { &D_800A5AEC, &D_800A5AF8, &D_800A5B04, &D_800A5B10,
      &D_800A5B1C, &D_800A5B28, &D_800A5B34, &D_800A5B40 },
};
Battle D_800A5B70 = { 104, 11, 0x60080000 };
Battle D_800A5B7C = { 104, 11, 0x60080000 };
Battle D_800A5B88 = { 104, 11, 0x60080000 };
Battle D_800A5B94 = { 104, 11, 0x60080000 };
Battle D_800A5BA0 = { 104, 11, 0x60080000 };
Battle D_800A5BAC = { 104, 11, 0x60080000 };
Battle D_800A5BB8 = { 104, 11, 0x60080000 };
Battle D_800A5BC4 = { 104, 11, 0x60080000 };
BattleList D_800A5BD0 = {
    3,
    { &D_800A5B70, &D_800A5B7C, &D_800A5B88, &D_800A5B94,
      &D_800A5BA0, &D_800A5BAC, &D_800A5BB8, &D_800A5BC4 },
};
Battle D_800A5BF4 = { 0, 0, 0x60040000 };
Battle D_800A5C00 = { 0, 0, 0x60040000 };
Battle D_800A5C0C = { 0, 0, 0x60040000 };
Battle D_800A5C18 = { 0, 0, 0x60040000 };
Battle D_800A5C24 = { 0, 0, 0x60040000 };
Battle D_800A5C30 = { 0, 0, 0x60040000 };
Battle D_800A5C3C = { 0, 0, 0x60040000 };
Battle D_800A5C48 = { 0, 0, 0x60040000 };
BattleList D_800A5C54 = {
    0,
    { &D_800A5BF4, &D_800A5C00, &D_800A5C0C, &D_800A5C18,
      &D_800A5C24, &D_800A5C30, &D_800A5C3C, &D_800A5C48 },
};
Battle D_800A5C78 = { 0, 0, 0x60040000 };
Battle D_800A5C84 = { 0, 0, 0x60040000 };
Battle D_800A5C90 = { 0, 0, 0x60040000 };
Battle D_800A5C9C = { 0, 0, 0x60040000 };
Battle D_800A5CA8 = { 0, 0, 0x60040000 };
Battle D_800A5CB4 = { 0, 0, 0x60040000 };
Battle D_800A5CC0 = { 0, 0, 0x60040000 };
Battle D_800A5CCC = { 0, 0, 0x60040000 };
BattleList D_800A5CD8 = {
    0,
    { &D_800A5C78, &D_800A5C84, &D_800A5C90, &D_800A5C9C,
      &D_800A5CA8, &D_800A5CB4, &D_800A5CC0, &D_800A5CCC },
};
Battle D_800A5CFC = { 0, 0, 0x60040000 };
Battle D_800A5D08 = { 0, 0, 0x60040000 };
Battle D_800A5D14 = { 0, 0, 0x60040000 };
Battle D_800A5D20 = { 0, 0, 0x60040000 };
Battle D_800A5D2C = { 0, 0, 0x60040000 };
Battle D_800A5D38 = { 0, 0, 0x60040000 };
Battle D_800A5D44 = { 0, 0, 0x60040000 };
Battle D_800A5D50 = { 0, 0, 0x60040000 };
BattleList D_800A5D5C = {
    0,
    { &D_800A5CFC, &D_800A5D08, &D_800A5D14, &D_800A5D20,
      &D_800A5D2C, &D_800A5D38, &D_800A5D44, &D_800A5D50 },
};
Battle D_800A5D80 = { 178, 11, 0x60080000 };
Battle D_800A5D8C = { 178, 11, 0x60080000 };
Battle D_800A5D98 = { 178, 11, 0x60080000 };
Battle D_800A5DA4 = { 178, 11, 0x60080000 };
Battle D_800A5DB0 = { 178, 11, 0x60080000 };
Battle D_800A5DBC = { 178, 11, 0x60080000 };
Battle D_800A5DC8 = { 178, 11, 0x60080000 };
Battle D_800A5DD4 = { 178, 11, 0x60080000 };
BattleList D_800A5DE0 = {
    3,
    { &D_800A5D80, &D_800A5D8C, &D_800A5D98, &D_800A5DA4,
      &D_800A5DB0, &D_800A5DBC, &D_800A5DC8, &D_800A5DD4 },
};
Battle D_800A5E04 = { 0, 0, 0x60040000 };
Battle D_800A5E10 = { 0, 0, 0x60040000 };
Battle D_800A5E1C = { 0, 0, 0x60040000 };
Battle D_800A5E28 = { 0, 0, 0x60040000 };
Battle D_800A5E34 = { 0, 0, 0x60040000 };
Battle D_800A5E40 = { 0, 0, 0x60040000 };
Battle D_800A5E4C = { 0, 0, 0x60040000 };
Battle D_800A5E58 = { 0, 0, 0x60040000 };
BattleList D_800A5E64 = {
    0,
    { &D_800A5E04, &D_800A5E10, &D_800A5E1C, &D_800A5E28,
      &D_800A5E34, &D_800A5E40, &D_800A5E4C, &D_800A5E58 },
};
Battle D_800A5E88 = { 0, 0, 0x60040000 };
Battle D_800A5E94 = { 0, 0, 0x60040000 };
Battle D_800A5EA0 = { 0, 0, 0x60040000 };
Battle D_800A5EAC = { 0, 0, 0x60040000 };
Battle D_800A5EB8 = { 0, 0, 0x60040000 };
Battle D_800A5EC4 = { 0, 0, 0x60040000 };
Battle D_800A5ED0 = { 0, 0, 0x60040000 };
Battle D_800A5EDC = { 0, 0, 0x60040000 };
BattleList D_800A5EE8 = {
    0,
    { &D_800A5E88, &D_800A5E94, &D_800A5EA0, &D_800A5EAC,
      &D_800A5EB8, &D_800A5EC4, &D_800A5ED0, &D_800A5EDC },
};
Battle D_800A5F0C = { 0, 0, 0x60040000 };
Battle D_800A5F18 = { 0, 0, 0x60040000 };
Battle D_800A5F24 = { 0, 0, 0x60040000 };
Battle D_800A5F30 = { 0, 0, 0x60040000 };
Battle D_800A5F3C = { 0, 0, 0x60040000 };
Battle D_800A5F48 = { 0, 0, 0x60040000 };
Battle D_800A5F54 = { 0, 0, 0x60040000 };
Battle D_800A5F60 = { 0, 0, 0x60040000 };
BattleList D_800A5F6C = {
    0,
    { &D_800A5F0C, &D_800A5F18, &D_800A5F24, &D_800A5F30,
      &D_800A5F3C, &D_800A5F48, &D_800A5F54, &D_800A5F60 },
};
Battle D_800A5F90 = { 104, 11, 0x60080000 };
Battle D_800A5F9C = { 104, 11, 0x60080000 };
Battle D_800A5FA8 = { 104, 11, 0x60080000 };
Battle D_800A5FB4 = { 104, 11, 0x60080000 };
Battle D_800A5FC0 = { 104, 11, 0x60080000 };
Battle D_800A5FCC = { 104, 11, 0x60080000 };
Battle D_800A5FD8 = { 104, 11, 0x60080000 };
Battle D_800A5FE4 = { 104, 11, 0x60080000 };
BattleList D_800A5FF0 = {
    3,
    { &D_800A5F90, &D_800A5F9C, &D_800A5FA8, &D_800A5FB4,
      &D_800A5FC0, &D_800A5FCC, &D_800A5FD8, &D_800A5FE4 },
};
Battle D_800A6014 = { 0, 0, 0x60040000 };
Battle D_800A6020 = { 0, 0, 0x60040000 };
Battle D_800A602C = { 0, 0, 0x60040000 };
Battle D_800A6038 = { 0, 0, 0x60040000 };
Battle D_800A6044 = { 0, 0, 0x60040000 };
Battle D_800A6050 = { 0, 0, 0x60040000 };
Battle D_800A605C = { 0, 0, 0x60040000 };
Battle D_800A6068 = { 0, 0, 0x60040000 };
BattleList D_800A6074 = {
    0,
    { &D_800A6014, &D_800A6020, &D_800A602C, &D_800A6038,
      &D_800A6044, &D_800A6050, &D_800A605C, &D_800A6068 },
};
Battle D_800A6098 = { 0, 0, 0x60040000 };
Battle D_800A60A4 = { 0, 0, 0x60040000 };
Battle D_800A60B0 = { 0, 0, 0x60040000 };
Battle D_800A60BC = { 0, 0, 0x60040000 };
Battle D_800A60C8 = { 0, 0, 0x60040000 };
Battle D_800A60D4 = { 0, 0, 0x60040000 };
Battle D_800A60E0 = { 0, 0, 0x60040000 };
Battle D_800A60EC = { 0, 0, 0x60040000 };
BattleList D_800A60F8 = {
    0,
    { &D_800A6098, &D_800A60A4, &D_800A60B0, &D_800A60BC,
      &D_800A60C8, &D_800A60D4, &D_800A60E0, &D_800A60EC },
};
Battle D_800A611C = { 0, 0, 0x60040000 };
Battle D_800A6128 = { 0, 0, 0x60040000 };
Battle D_800A6134 = { 0, 0, 0x60040000 };
Battle D_800A6140 = { 0, 0, 0x60040000 };
Battle D_800A614C = { 0, 0, 0x60040000 };
Battle D_800A6158 = { 0, 0, 0x60040000 };
Battle D_800A6164 = { 0, 0, 0x60040000 };
Battle D_800A6170 = { 0, 0, 0x60040000 };
BattleList D_800A617C = {
    0,
    { &D_800A611C, &D_800A6128, &D_800A6134, &D_800A6140,
      &D_800A614C, &D_800A6158, &D_800A6164, &D_800A6170 },
};
FieldBattles stageBattles[] = {
    { 174, 1, 0, { &D_800A5180, &D_800A5204, &D_800A5288, &D_800A530C } },
    { 181, 3, 0, { &D_800A5390, &D_800A5414, &D_800A5498, &D_800A551C } },
    { 189, 5, 0, { &D_800A55A0, &D_800A5624, &D_800A56A8, &D_800A572C } },
    { 199, 9, 0, { &D_800A57B0, &D_800A5834, &D_800A58B8, &D_800A593C } },
    { 202, 11, 0, { &D_800A59C0, &D_800A5A44, &D_800A5AC8, &D_800A5B4C } },
    { 209, 13, 0, { &D_800A5BD0, &D_800A5C54, &D_800A5CD8, &D_800A5D5C } },
    { 217, 15, 0, { &D_800A5DE0, &D_800A5E64, &D_800A5EE8, &D_800A5F6C } },
    { 227, 19, 0, { &D_800A5FF0, &D_800A6074, &D_800A60F8, &D_800A617C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x1BC, 0xC0, 0xBC, 0x150, 0x1FF },
};
FieldActorEntry D_800A62F0 = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A62F0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 155, 230, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 440, 261, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 797, 447, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 1127, 463, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 312, 203, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 657, 342, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 916, 467, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 768, 289, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 215, 158, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 591, 261, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 983, 460, 0, 0 },
    { 1, 0, 0x50, 4, 0, 0, 0, 0, 0, 0, 192, 257, 340, 0 },
    { 1, 0, 0x65, 4, 1, 0, 0, 0, 0, 0, 160, 241, 334, 0 },
    { 1, 0, 0x5E, 4, 2, 0, 0, 0, 0, 0, 144, 237, 324, 0 },
    { 1, 0, 0x91, 4, 3, 0, 0, 0, 0, 0, 368, 184, 306, 0 },
    { 1, 0, 0x77, 4, 4, 0, 0, 0, 0, 0, 336, 204, 322, 0 },
    { 1, 0, 0x89, 4, 5, 0, 0, 0, 0, 0, 304, 218, 347, 0 },
    { 1, 0, 0x82, 4, 6, 0, 0, 0, 0, 0, 272, 238, 354, 0 },
    { 1, 0, 0x5E, 4, 7, 0, 0, 0, 0, 0, 464, 278, 368, 0 },
    { 1, 0, 0x66, 4, 8, 0, 0, 0, 0, 0, 432, 283, 375, 0 },
    { 1, 0, 0x52, 4, 9, 0, 0, 0, 0, 0, 414, 298, 380, 0 },
    { 1, 0, 0x51, 4, 0xA, 0, 0, 0, 0, 0, 544, 316, 390, 0 },
    { 1, 0, 0x60, 4, 0xB, 0, 0, 0, 0, 0, 512, 320, 405, 0 },
    { 1, 0, 0x52, 4, 0xC, 0, 0, 0, 0, 0, 494, 336, 415, 0 },
    { 1, 0, 0x93, 4, 0xD, 0, 0, 0, 0, 0, 720, 311, 435, 0 },
    { 1, 0, 0x79, 4, 0xE, 0, 0, 0, 0, 0, 688, 331, 451, 0 },
    { 1, 0, 0x8B, 4, 0xF, 0, 0, 0, 0, 0, 656, 345, 476, 0 },
    { 1, 0, 0x89, 4, 0x10, 0, 0, 0, 0, 0, 624, 360, 483, 0 },
    { 1, 0, 0x5D, 4, 0x11, 0, 0, 0, 0, 0, 752, 421, 506, 0 },
    { 1, 0, 0x67, 4, 0x12, 0, 0, 0, 0, 0, 720, 424, 515, 0 },
    { 1, 0, 0x50, 4, 0x13, 0, 0, 0, 0, 0, 702, 441, 527, 0 },
    { 1, 0, 0x52, 4, 0x14, 0, 0, 0, 0, 0, 1104, 521, 606, 0 },
    { 1, 0, 0x65, 4, 0x15, 0, 0, 0, 0, 0, 1072, 505, 598, 0 },
    { 1, 0, 0x5D, 4, 0x16, 0, 0, 0, 0, 0, 1057, 501, 587, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E6, 0x450, 0x248, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E6, 0xA0, 0x150, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
