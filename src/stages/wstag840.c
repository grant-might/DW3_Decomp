#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places_last.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x73B
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x74B
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x15300, 0x13900};
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
extern StagePoint D_800A50F0;
extern StagePoint D_800A5100;
extern StagePoint D_800A5118;
extern StagePoint D_800A5128;
extern StagePoints D_800A4FD0;
extern StagePoints D_800A4FF8;
extern StagePoints D_800A5020;
extern StagePoints D_800A5048;
extern StagePoints D_800A5070;
extern StagePoints D_800A5098;
extern StagePoints D_800A50C0;
extern StagePoints D_800A50E8;
extern StagePoints D_800A5110;
extern StagePoints D_800A5138;
extern StagePoints D_800A5140;
extern Battle D_800A5178;
extern Battle D_800A5184;
extern Battle D_800A5190;
extern Battle D_800A519C;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51FC;
extern Battle D_800A5208;
extern Battle D_800A5214;
extern Battle D_800A5220;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A5280;
extern Battle D_800A528C;
extern Battle D_800A5298;
extern Battle D_800A52A4;
extern Battle D_800A52B0;
extern Battle D_800A52BC;
extern Battle D_800A52C8;
extern Battle D_800A52D4;
extern Battle D_800A5304;
extern Battle D_800A5310;
extern Battle D_800A531C;
extern Battle D_800A5328;
extern Battle D_800A5334;
extern Battle D_800A5340;
extern Battle D_800A534C;
extern Battle D_800A5358;
extern Battle D_800A5388;
extern Battle D_800A5394;
extern Battle D_800A53A0;
extern Battle D_800A53AC;
extern Battle D_800A53B8;
extern Battle D_800A53C4;
extern Battle D_800A53D0;
extern Battle D_800A53DC;
extern Battle D_800A540C;
extern Battle D_800A5418;
extern Battle D_800A5424;
extern Battle D_800A5430;
extern Battle D_800A543C;
extern Battle D_800A5448;
extern Battle D_800A5454;
extern Battle D_800A5460;
extern Battle D_800A5490;
extern Battle D_800A549C;
extern Battle D_800A54A8;
extern Battle D_800A54B4;
extern Battle D_800A54C0;
extern Battle D_800A54CC;
extern Battle D_800A54D8;
extern Battle D_800A54E4;
extern Battle D_800A5514;
extern Battle D_800A5520;
extern Battle D_800A552C;
extern Battle D_800A5538;
extern Battle D_800A5544;
extern Battle D_800A5550;
extern Battle D_800A555C;
extern Battle D_800A5568;
extern Battle D_800A5598;
extern Battle D_800A55A4;
extern Battle D_800A55B0;
extern Battle D_800A55BC;
extern Battle D_800A55C8;
extern Battle D_800A55D4;
extern Battle D_800A55E0;
extern Battle D_800A55EC;
extern Battle D_800A561C;
extern Battle D_800A5628;
extern Battle D_800A5634;
extern Battle D_800A5640;
extern Battle D_800A564C;
extern Battle D_800A5658;
extern Battle D_800A5664;
extern Battle D_800A5670;
extern Battle D_800A56A0;
extern Battle D_800A56AC;
extern Battle D_800A56B8;
extern Battle D_800A56C4;
extern Battle D_800A56D0;
extern Battle D_800A56DC;
extern Battle D_800A56E8;
extern Battle D_800A56F4;
extern Battle D_800A5724;
extern Battle D_800A5730;
extern Battle D_800A573C;
extern Battle D_800A5748;
extern Battle D_800A5754;
extern Battle D_800A5760;
extern Battle D_800A576C;
extern Battle D_800A5778;
extern Battle D_800A57A8;
extern Battle D_800A57B4;
extern Battle D_800A57C0;
extern Battle D_800A57CC;
extern Battle D_800A57D8;
extern Battle D_800A57E4;
extern Battle D_800A57F0;
extern Battle D_800A57FC;
extern Battle D_800A582C;
extern Battle D_800A5838;
extern Battle D_800A5844;
extern Battle D_800A5850;
extern Battle D_800A585C;
extern Battle D_800A5868;
extern Battle D_800A5874;
extern Battle D_800A5880;
extern Battle D_800A58B0;
extern Battle D_800A58BC;
extern Battle D_800A58C8;
extern Battle D_800A58D4;
extern Battle D_800A58E0;
extern Battle D_800A58EC;
extern Battle D_800A58F8;
extern Battle D_800A5904;
extern Battle D_800A5934;
extern Battle D_800A5940;
extern Battle D_800A594C;
extern Battle D_800A5958;
extern Battle D_800A5964;
extern Battle D_800A5970;
extern Battle D_800A597C;
extern Battle D_800A5988;
extern Battle D_800A59B8;
extern Battle D_800A59C4;
extern Battle D_800A59D0;
extern Battle D_800A59DC;
extern Battle D_800A59E8;
extern Battle D_800A59F4;
extern Battle D_800A5A00;
extern Battle D_800A5A0C;
extern Battle D_800A5A3C;
extern Battle D_800A5A48;
extern Battle D_800A5A54;
extern Battle D_800A5A60;
extern Battle D_800A5A6C;
extern Battle D_800A5A78;
extern Battle D_800A5A84;
extern Battle D_800A5A90;
extern Battle D_800A5AC0;
extern Battle D_800A5ACC;
extern Battle D_800A5AD8;
extern Battle D_800A5AE4;
extern Battle D_800A5AF0;
extern Battle D_800A5AFC;
extern Battle D_800A5B08;
extern Battle D_800A5B14;
extern Battle D_800A5B44;
extern Battle D_800A5B50;
extern Battle D_800A5B5C;
extern Battle D_800A5B68;
extern Battle D_800A5B74;
extern Battle D_800A5B80;
extern Battle D_800A5B8C;
extern Battle D_800A5B98;
extern Battle D_800A5BC8;
extern Battle D_800A5BD4;
extern Battle D_800A5BE0;
extern Battle D_800A5BEC;
extern Battle D_800A5BF8;
extern Battle D_800A5C04;
extern Battle D_800A5C10;
extern Battle D_800A5C1C;
extern Battle D_800A5C4C;
extern Battle D_800A5C58;
extern Battle D_800A5C64;
extern Battle D_800A5C70;
extern Battle D_800A5C7C;
extern Battle D_800A5C88;
extern Battle D_800A5C94;
extern Battle D_800A5CA0;
extern Battle D_800A5CD0;
extern Battle D_800A5CDC;
extern Battle D_800A5CE8;
extern Battle D_800A5CF4;
extern Battle D_800A5D00;
extern Battle D_800A5D0C;
extern Battle D_800A5D18;
extern Battle D_800A5D24;
extern Battle D_800A5D54;
extern Battle D_800A5D60;
extern Battle D_800A5D6C;
extern Battle D_800A5D78;
extern Battle D_800A5D84;
extern Battle D_800A5D90;
extern Battle D_800A5D9C;
extern Battle D_800A5DA8;
extern Battle D_800A5DD8;
extern Battle D_800A5DE4;
extern Battle D_800A5DF0;
extern Battle D_800A5DFC;
extern Battle D_800A5E08;
extern Battle D_800A5E14;
extern Battle D_800A5E20;
extern Battle D_800A5E2C;
extern Battle D_800A5E5C;
extern Battle D_800A5E68;
extern Battle D_800A5E74;
extern Battle D_800A5E80;
extern Battle D_800A5E8C;
extern Battle D_800A5E98;
extern Battle D_800A5EA4;
extern Battle D_800A5EB0;
extern Battle D_800A5EE0;
extern Battle D_800A5EEC;
extern Battle D_800A5EF8;
extern Battle D_800A5F04;
extern Battle D_800A5F10;
extern Battle D_800A5F1C;
extern Battle D_800A5F28;
extern Battle D_800A5F34;
extern Battle D_800A5F64;
extern Battle D_800A5F70;
extern Battle D_800A5F7C;
extern Battle D_800A5F88;
extern Battle D_800A5F94;
extern Battle D_800A5FA0;
extern Battle D_800A5FAC;
extern Battle D_800A5FB8;
extern Battle D_800A5FE8;
extern Battle D_800A5FF4;
extern Battle D_800A6000;
extern Battle D_800A600C;
extern Battle D_800A6018;
extern Battle D_800A6024;
extern Battle D_800A6030;
extern Battle D_800A603C;
extern Battle D_800A606C;
extern Battle D_800A6078;
extern Battle D_800A6084;
extern Battle D_800A6090;
extern Battle D_800A609C;
extern Battle D_800A60A8;
extern Battle D_800A60B4;
extern Battle D_800A60C0;
extern Battle D_800A60F0;
extern Battle D_800A60FC;
extern Battle D_800A6108;
extern Battle D_800A6114;
extern Battle D_800A6120;
extern Battle D_800A612C;
extern Battle D_800A6138;
extern Battle D_800A6144;
extern Battle D_800A6174;
extern Battle D_800A6180;
extern Battle D_800A618C;
extern Battle D_800A6198;
extern Battle D_800A61A4;
extern Battle D_800A61B0;
extern Battle D_800A61BC;
extern Battle D_800A61C8;
extern Battle D_800A61F8;
extern Battle D_800A6204;
extern Battle D_800A6210;
extern Battle D_800A621C;
extern Battle D_800A6228;
extern Battle D_800A6234;
extern Battle D_800A6240;
extern Battle D_800A624C;
extern Battle D_800A627C;
extern Battle D_800A6288;
extern Battle D_800A6294;
extern Battle D_800A62A0;
extern Battle D_800A62AC;
extern Battle D_800A62B8;
extern Battle D_800A62C4;
extern Battle D_800A62D0;
extern Battle D_800A6300;
extern Battle D_800A630C;
extern Battle D_800A6318;
extern Battle D_800A6324;
extern Battle D_800A6330;
extern Battle D_800A633C;
extern Battle D_800A6348;
extern Battle D_800A6354;
extern Battle D_800A6384;
extern Battle D_800A6390;
extern Battle D_800A639C;
extern Battle D_800A63A8;
extern Battle D_800A63B4;
extern Battle D_800A63C0;
extern Battle D_800A63CC;
extern Battle D_800A63D8;
extern Battle D_800A6408;
extern Battle D_800A6414;
extern Battle D_800A6420;
extern Battle D_800A642C;
extern Battle D_800A6438;
extern Battle D_800A6444;
extern Battle D_800A6450;
extern Battle D_800A645C;
extern Battle D_800A648C;
extern Battle D_800A6498;
extern Battle D_800A64A4;
extern Battle D_800A64B0;
extern Battle D_800A64BC;
extern Battle D_800A64C8;
extern Battle D_800A64D4;
extern Battle D_800A64E0;
extern Battle D_800A6510;
extern Battle D_800A651C;
extern Battle D_800A6528;
extern Battle D_800A6534;
extern Battle D_800A6540;
extern Battle D_800A654C;
extern Battle D_800A6558;
extern Battle D_800A6564;
extern Battle D_800A6594;
extern Battle D_800A65A0;
extern Battle D_800A65AC;
extern Battle D_800A65B8;
extern Battle D_800A65C4;
extern Battle D_800A65D0;
extern Battle D_800A65DC;
extern Battle D_800A65E8;
extern BattleList D_800A51D8;
extern BattleList D_800A525C;
extern BattleList D_800A52E0;
extern BattleList D_800A5364;
extern BattleList D_800A53E8;
extern BattleList D_800A546C;
extern BattleList D_800A54F0;
extern BattleList D_800A5574;
extern BattleList D_800A55F8;
extern BattleList D_800A567C;
extern BattleList D_800A5700;
extern BattleList D_800A5784;
extern BattleList D_800A5808;
extern BattleList D_800A588C;
extern BattleList D_800A5910;
extern BattleList D_800A5994;
extern BattleList D_800A5A18;
extern BattleList D_800A5A9C;
extern BattleList D_800A5B20;
extern BattleList D_800A5BA4;
extern BattleList D_800A5C28;
extern BattleList D_800A5CAC;
extern BattleList D_800A5D30;
extern BattleList D_800A5DB4;
extern BattleList D_800A5E38;
extern BattleList D_800A5EBC;
extern BattleList D_800A5F40;
extern BattleList D_800A5FC4;
extern BattleList D_800A6048;
extern BattleList D_800A60CC;
extern BattleList D_800A6150;
extern BattleList D_800A61D4;
extern BattleList D_800A6258;
extern BattleList D_800A62DC;
extern BattleList D_800A6360;
extern BattleList D_800A63E4;
extern BattleList D_800A6468;
extern BattleList D_800A64EC;
extern BattleList D_800A6570;
extern BattleList D_800A65F4;
extern FieldActorEntry D_800A67A0;

StagePoint D_800A4FB0 = { 0x2E6, 3, 1, 0x450, 0x248, 1, NULL };
StagePoint D_800A4FC0 = { 0x220, 0, 0, 112, 184, 0, &D_800A4FB0 };
StagePoints D_800A4FD0 = { 3, 1, &D_800A4FC0 };
StagePoint D_800A4FD8 = { 0x2E4, 4, 1, 0x340, 160, 1, NULL };
StagePoint D_800A4FE8 = { 0x21F, 0, 0, 224, 0x208, 0, &D_800A4FD8 };
StagePoints D_800A4FF8 = { 4, 1, &D_800A4FE8 };
StagePoint D_800A5000 = { 0x2E4, 5, 1, 0x340, 160, 1, NULL };
StagePoint D_800A5010 = { 0x266, 0, 0, 0x2A0, 0x228, 0, &D_800A5000 };
StagePoints D_800A5020 = { 5, 1, &D_800A5010 };
StagePoint D_800A5028 = { 0x2E4, 6, 1, 0x340, 160, 1, NULL };
StagePoint D_800A5038 = { 0x266, 0, 0, 0x1C0, 0x108, 0, &D_800A5028 };
StagePoints D_800A5048 = { 6, 1, &D_800A5038 };
StagePoint D_800A5050 = { 0x2E6, 9, 1, 0x450, 0x248, 1, NULL };
StagePoint D_800A5060 = { 0x23D, 0, 0, 0x240, 216, 0, &D_800A5050 };
StagePoints D_800A5070 = { 9, 1, &D_800A5060 };
StagePoint D_800A5078 = { 0x2E6, 13, 1, 0x450, 0x248, 1, NULL };
StagePoint D_800A5088 = { 0x28F, 0, 0, 112, 184, 0, &D_800A5078 };
StagePoints D_800A5098 = { 13, 1, &D_800A5088 };
StagePoint D_800A50A0 = { 0x2E4, 14, 1, 0x340, 160, 1, NULL };
StagePoint D_800A50B0 = { 0x28E, 0, 0, 224, 0x208, 0, &D_800A50A0 };
StagePoints D_800A50C0 = { 14, 1, &D_800A50B0 };
StagePoint D_800A50C8 = { 0x2E4, 15, 1, 0x340, 160, 1, NULL };
StagePoint D_800A50D8 = { 0x2CE, 0, 0, 0x2A0, 0x228, 0, &D_800A50C8 };
StagePoints D_800A50E8 = { 15, 1, &D_800A50D8 };
StagePoint D_800A50F0 = { 0x2E4, 16, 1, 0x340, 160, 1, NULL };
StagePoint D_800A5100 = { 0x2CE, 0, 0, 0x1C0, 0x108, 0, &D_800A50F0 };
StagePoints D_800A5110 = { 16, 1, &D_800A5100 };
StagePoint D_800A5118 = { 0x2E6, 19, 1, 0x450, 0x248, 1, NULL };
StagePoint D_800A5128 = { 0x2AA, 0, 0, 0x240, 216, 0, &D_800A5118 };
StagePoints D_800A5138 = { 19, 1, &D_800A5128 };
StagePoints D_800A5140 = { 0, 0, &D_800A4FC0 };
StagePoints *placePoints[] = {
    &D_800A4FD0, &D_800A4FF8, &D_800A5020, &D_800A5048,
    &D_800A5070, &D_800A5098, &D_800A50C0, &D_800A50E8,
    &D_800A5110, &D_800A5138, &D_800A5140, NULL,
};
Battle D_800A5178 = { 61, 11, 0x60080000 };
Battle D_800A5184 = { 61, 11, 0x60080000 };
Battle D_800A5190 = { 61, 11, 0x60080000 };
Battle D_800A519C = { 61, 11, 0x60080000 };
Battle D_800A51A8 = { 61, 11, 0x60080000 };
Battle D_800A51B4 = { 61, 11, 0x60080000 };
Battle D_800A51C0 = { 61, 11, 0x60080000 };
Battle D_800A51CC = { 61, 11, 0x60080000 };
BattleList D_800A51D8 = {
    3,
    { &D_800A5178, &D_800A5184, &D_800A5190, &D_800A519C,
      &D_800A51A8, &D_800A51B4, &D_800A51C0, &D_800A51CC },
};
Battle D_800A51FC = { 0, 0, 0x60040000 };
Battle D_800A5208 = { 0, 0, 0x60040000 };
Battle D_800A5214 = { 0, 0, 0x60040000 };
Battle D_800A5220 = { 0, 0, 0x60040000 };
Battle D_800A522C = { 0, 0, 0x60040000 };
Battle D_800A5238 = { 0, 0, 0x60040000 };
Battle D_800A5244 = { 0, 0, 0x60040000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
BattleList D_800A525C = {
    0,
    { &D_800A51FC, &D_800A5208, &D_800A5214, &D_800A5220,
      &D_800A522C, &D_800A5238, &D_800A5244, &D_800A5250 },
};
Battle D_800A5280 = { 0, 0, 0x60040000 };
Battle D_800A528C = { 0, 0, 0x60040000 };
Battle D_800A5298 = { 0, 0, 0x60040000 };
Battle D_800A52A4 = { 0, 0, 0x60040000 };
Battle D_800A52B0 = { 0, 0, 0x60040000 };
Battle D_800A52BC = { 0, 0, 0x60040000 };
Battle D_800A52C8 = { 0, 0, 0x60040000 };
Battle D_800A52D4 = { 0, 0, 0x60040000 };
BattleList D_800A52E0 = {
    0,
    { &D_800A5280, &D_800A528C, &D_800A5298, &D_800A52A4,
      &D_800A52B0, &D_800A52BC, &D_800A52C8, &D_800A52D4 },
};
Battle D_800A5304 = { 0, 0, 0x60040000 };
Battle D_800A5310 = { 0, 0, 0x60040000 };
Battle D_800A531C = { 0, 0, 0x60040000 };
Battle D_800A5328 = { 0, 0, 0x60040000 };
Battle D_800A5334 = { 0, 0, 0x60040000 };
Battle D_800A5340 = { 0, 0, 0x60040000 };
Battle D_800A534C = { 0, 0, 0x60040000 };
Battle D_800A5358 = { 0, 0, 0x60040000 };
BattleList D_800A5364 = {
    0,
    { &D_800A5304, &D_800A5310, &D_800A531C, &D_800A5328,
      &D_800A5334, &D_800A5340, &D_800A534C, &D_800A5358 },
};
Battle D_800A5388 = { 61, 11, 0x60080000 };
Battle D_800A5394 = { 61, 11, 0x60080000 };
Battle D_800A53A0 = { 61, 11, 0x60080000 };
Battle D_800A53AC = { 61, 11, 0x60080000 };
Battle D_800A53B8 = { 62, 11, 0x60080000 };
Battle D_800A53C4 = { 62, 11, 0x60080000 };
Battle D_800A53D0 = { 62, 11, 0x60080000 };
Battle D_800A53DC = { 62, 11, 0x60080000 };
BattleList D_800A53E8 = {
    2,
    { &D_800A5388, &D_800A5394, &D_800A53A0, &D_800A53AC,
      &D_800A53B8, &D_800A53C4, &D_800A53D0, &D_800A53DC },
};
Battle D_800A540C = { 0, 0, 0x60040000 };
Battle D_800A5418 = { 0, 0, 0x60040000 };
Battle D_800A5424 = { 0, 0, 0x60040000 };
Battle D_800A5430 = { 0, 0, 0x60040000 };
Battle D_800A543C = { 0, 0, 0x60040000 };
Battle D_800A5448 = { 0, 0, 0x60040000 };
Battle D_800A5454 = { 0, 0, 0x60040000 };
Battle D_800A5460 = { 0, 0, 0x60040000 };
BattleList D_800A546C = {
    0,
    { &D_800A540C, &D_800A5418, &D_800A5424, &D_800A5430,
      &D_800A543C, &D_800A5448, &D_800A5454, &D_800A5460 },
};
Battle D_800A5490 = { 0, 0, 0x60040000 };
Battle D_800A549C = { 0, 0, 0x60040000 };
Battle D_800A54A8 = { 0, 0, 0x60040000 };
Battle D_800A54B4 = { 0, 0, 0x60040000 };
Battle D_800A54C0 = { 0, 0, 0x60040000 };
Battle D_800A54CC = { 0, 0, 0x60040000 };
Battle D_800A54D8 = { 0, 0, 0x60040000 };
Battle D_800A54E4 = { 0, 0, 0x60040000 };
BattleList D_800A54F0 = {
    0,
    { &D_800A5490, &D_800A549C, &D_800A54A8, &D_800A54B4,
      &D_800A54C0, &D_800A54CC, &D_800A54D8, &D_800A54E4 },
};
Battle D_800A5514 = { 0, 0, 0x60040000 };
Battle D_800A5520 = { 0, 0, 0x60040000 };
Battle D_800A552C = { 0, 0, 0x60040000 };
Battle D_800A5538 = { 0, 0, 0x60040000 };
Battle D_800A5544 = { 0, 0, 0x60040000 };
Battle D_800A5550 = { 0, 0, 0x60040000 };
Battle D_800A555C = { 0, 0, 0x60040000 };
Battle D_800A5568 = { 0, 0, 0x60040000 };
BattleList D_800A5574 = {
    0,
    { &D_800A5514, &D_800A5520, &D_800A552C, &D_800A5538,
      &D_800A5544, &D_800A5550, &D_800A555C, &D_800A5568 },
};
Battle D_800A5598 = { 63, 11, 0x60080000 };
Battle D_800A55A4 = { 63, 11, 0x60080000 };
Battle D_800A55B0 = { 63, 11, 0x60080000 };
Battle D_800A55BC = { 63, 11, 0x60080000 };
Battle D_800A55C8 = { 63, 11, 0x60080000 };
Battle D_800A55D4 = { 63, 11, 0x60080000 };
Battle D_800A55E0 = { 63, 11, 0x60080000 };
Battle D_800A55EC = { 63, 11, 0x60080000 };
BattleList D_800A55F8 = {
    3,
    { &D_800A5598, &D_800A55A4, &D_800A55B0, &D_800A55BC,
      &D_800A55C8, &D_800A55D4, &D_800A55E0, &D_800A55EC },
};
Battle D_800A561C = { 0, 0, 0x60040000 };
Battle D_800A5628 = { 0, 0, 0x60040000 };
Battle D_800A5634 = { 0, 0, 0x60040000 };
Battle D_800A5640 = { 0, 0, 0x60040000 };
Battle D_800A564C = { 0, 0, 0x60040000 };
Battle D_800A5658 = { 0, 0, 0x60040000 };
Battle D_800A5664 = { 0, 0, 0x60040000 };
Battle D_800A5670 = { 0, 0, 0x60040000 };
BattleList D_800A567C = {
    0,
    { &D_800A561C, &D_800A5628, &D_800A5634, &D_800A5640,
      &D_800A564C, &D_800A5658, &D_800A5664, &D_800A5670 },
};
Battle D_800A56A0 = { 0, 0, 0x60040000 };
Battle D_800A56AC = { 0, 0, 0x60040000 };
Battle D_800A56B8 = { 0, 0, 0x60040000 };
Battle D_800A56C4 = { 0, 0, 0x60040000 };
Battle D_800A56D0 = { 0, 0, 0x60040000 };
Battle D_800A56DC = { 0, 0, 0x60040000 };
Battle D_800A56E8 = { 0, 0, 0x60040000 };
Battle D_800A56F4 = { 0, 0, 0x60040000 };
BattleList D_800A5700 = {
    0,
    { &D_800A56A0, &D_800A56AC, &D_800A56B8, &D_800A56C4,
      &D_800A56D0, &D_800A56DC, &D_800A56E8, &D_800A56F4 },
};
Battle D_800A5724 = { 0, 0, 0x60040000 };
Battle D_800A5730 = { 0, 0, 0x60040000 };
Battle D_800A573C = { 0, 0, 0x60040000 };
Battle D_800A5748 = { 0, 0, 0x60040000 };
Battle D_800A5754 = { 0, 0, 0x60040000 };
Battle D_800A5760 = { 0, 0, 0x60040000 };
Battle D_800A576C = { 0, 0, 0x60040000 };
Battle D_800A5778 = { 0, 0, 0x60040000 };
BattleList D_800A5784 = {
    0,
    { &D_800A5724, &D_800A5730, &D_800A573C, &D_800A5748,
      &D_800A5754, &D_800A5760, &D_800A576C, &D_800A5778 },
};
Battle D_800A57A8 = { 63, 11, 0x60080000 };
Battle D_800A57B4 = { 63, 11, 0x60080000 };
Battle D_800A57C0 = { 63, 11, 0x60080000 };
Battle D_800A57CC = { 63, 11, 0x60080000 };
Battle D_800A57D8 = { 63, 11, 0x60080000 };
Battle D_800A57E4 = { 63, 11, 0x60080000 };
Battle D_800A57F0 = { 63, 11, 0x60080000 };
Battle D_800A57FC = { 63, 11, 0x60080000 };
BattleList D_800A5808 = {
    5,
    { &D_800A57A8, &D_800A57B4, &D_800A57C0, &D_800A57CC,
      &D_800A57D8, &D_800A57E4, &D_800A57F0, &D_800A57FC },
};
Battle D_800A582C = { 0, 0, 0x60040000 };
Battle D_800A5838 = { 0, 0, 0x60040000 };
Battle D_800A5844 = { 0, 0, 0x60040000 };
Battle D_800A5850 = { 0, 0, 0x60040000 };
Battle D_800A585C = { 0, 0, 0x60040000 };
Battle D_800A5868 = { 0, 0, 0x60040000 };
Battle D_800A5874 = { 0, 0, 0x60040000 };
Battle D_800A5880 = { 0, 0, 0x60040000 };
BattleList D_800A588C = {
    0,
    { &D_800A582C, &D_800A5838, &D_800A5844, &D_800A5850,
      &D_800A585C, &D_800A5868, &D_800A5874, &D_800A5880 },
};
Battle D_800A58B0 = { 0, 0, 0x60040000 };
Battle D_800A58BC = { 0, 0, 0x60040000 };
Battle D_800A58C8 = { 0, 0, 0x60040000 };
Battle D_800A58D4 = { 0, 0, 0x60040000 };
Battle D_800A58E0 = { 0, 0, 0x60040000 };
Battle D_800A58EC = { 0, 0, 0x60040000 };
Battle D_800A58F8 = { 0, 0, 0x60040000 };
Battle D_800A5904 = { 0, 0, 0x60040000 };
BattleList D_800A5910 = {
    0,
    { &D_800A58B0, &D_800A58BC, &D_800A58C8, &D_800A58D4,
      &D_800A58E0, &D_800A58EC, &D_800A58F8, &D_800A5904 },
};
Battle D_800A5934 = { 0, 0, 0x60040000 };
Battle D_800A5940 = { 0, 0, 0x60040000 };
Battle D_800A594C = { 0, 0, 0x60040000 };
Battle D_800A5958 = { 0, 0, 0x60040000 };
Battle D_800A5964 = { 0, 0, 0x60040000 };
Battle D_800A5970 = { 0, 0, 0x60040000 };
Battle D_800A597C = { 0, 0, 0x60040000 };
Battle D_800A5988 = { 0, 0, 0x60040000 };
BattleList D_800A5994 = {
    0,
    { &D_800A5934, &D_800A5940, &D_800A594C, &D_800A5958,
      &D_800A5964, &D_800A5970, &D_800A597C, &D_800A5988 },
};
Battle D_800A59B8 = { 61, 11, 0x60080000 };
Battle D_800A59C4 = { 61, 11, 0x60080000 };
Battle D_800A59D0 = { 61, 11, 0x60080000 };
Battle D_800A59DC = { 61, 11, 0x60080000 };
Battle D_800A59E8 = { 61, 11, 0x60080000 };
Battle D_800A59F4 = { 61, 11, 0x60080000 };
Battle D_800A5A00 = { 61, 11, 0x60080000 };
Battle D_800A5A0C = { 61, 11, 0x60080000 };
BattleList D_800A5A18 = {
    3,
    { &D_800A59B8, &D_800A59C4, &D_800A59D0, &D_800A59DC,
      &D_800A59E8, &D_800A59F4, &D_800A5A00, &D_800A5A0C },
};
Battle D_800A5A3C = { 0, 0, 0x60040000 };
Battle D_800A5A48 = { 0, 0, 0x60040000 };
Battle D_800A5A54 = { 0, 0, 0x60040000 };
Battle D_800A5A60 = { 0, 0, 0x60040000 };
Battle D_800A5A6C = { 0, 0, 0x60040000 };
Battle D_800A5A78 = { 0, 0, 0x60040000 };
Battle D_800A5A84 = { 0, 0, 0x60040000 };
Battle D_800A5A90 = { 0, 0, 0x60040000 };
BattleList D_800A5A9C = {
    0,
    { &D_800A5A3C, &D_800A5A48, &D_800A5A54, &D_800A5A60,
      &D_800A5A6C, &D_800A5A78, &D_800A5A84, &D_800A5A90 },
};
Battle D_800A5AC0 = { 0, 0, 0x60040000 };
Battle D_800A5ACC = { 0, 0, 0x60040000 };
Battle D_800A5AD8 = { 0, 0, 0x60040000 };
Battle D_800A5AE4 = { 0, 0, 0x60040000 };
Battle D_800A5AF0 = { 0, 0, 0x60040000 };
Battle D_800A5AFC = { 0, 0, 0x60040000 };
Battle D_800A5B08 = { 0, 0, 0x60040000 };
Battle D_800A5B14 = { 0, 0, 0x60040000 };
BattleList D_800A5B20 = {
    0,
    { &D_800A5AC0, &D_800A5ACC, &D_800A5AD8, &D_800A5AE4,
      &D_800A5AF0, &D_800A5AFC, &D_800A5B08, &D_800A5B14 },
};
Battle D_800A5B44 = { 0, 0, 0x60040000 };
Battle D_800A5B50 = { 0, 0, 0x60040000 };
Battle D_800A5B5C = { 0, 0, 0x60040000 };
Battle D_800A5B68 = { 0, 0, 0x60040000 };
Battle D_800A5B74 = { 0, 0, 0x60040000 };
Battle D_800A5B80 = { 0, 0, 0x60040000 };
Battle D_800A5B8C = { 0, 0, 0x60040000 };
Battle D_800A5B98 = { 0, 0, 0x60040000 };
BattleList D_800A5BA4 = {
    0,
    { &D_800A5B44, &D_800A5B50, &D_800A5B5C, &D_800A5B68,
      &D_800A5B74, &D_800A5B80, &D_800A5B8C, &D_800A5B98 },
};
Battle D_800A5BC8 = { 104, 11, 0x60080000 };
Battle D_800A5BD4 = { 104, 11, 0x60080000 };
Battle D_800A5BE0 = { 104, 11, 0x60080000 };
Battle D_800A5BEC = { 104, 11, 0x60080000 };
Battle D_800A5BF8 = { 104, 11, 0x60080000 };
Battle D_800A5C04 = { 104, 11, 0x60080000 };
Battle D_800A5C10 = { 104, 11, 0x60080000 };
Battle D_800A5C1C = { 104, 11, 0x60080000 };
BattleList D_800A5C28 = {
    3,
    { &D_800A5BC8, &D_800A5BD4, &D_800A5BE0, &D_800A5BEC,
      &D_800A5BF8, &D_800A5C04, &D_800A5C10, &D_800A5C1C },
};
Battle D_800A5C4C = { 0, 0, 0x60040000 };
Battle D_800A5C58 = { 0, 0, 0x60040000 };
Battle D_800A5C64 = { 0, 0, 0x60040000 };
Battle D_800A5C70 = { 0, 0, 0x60040000 };
Battle D_800A5C7C = { 0, 0, 0x60040000 };
Battle D_800A5C88 = { 0, 0, 0x60040000 };
Battle D_800A5C94 = { 0, 0, 0x60040000 };
Battle D_800A5CA0 = { 0, 0, 0x60040000 };
BattleList D_800A5CAC = {
    0,
    { &D_800A5C4C, &D_800A5C58, &D_800A5C64, &D_800A5C70,
      &D_800A5C7C, &D_800A5C88, &D_800A5C94, &D_800A5CA0 },
};
Battle D_800A5CD0 = { 0, 0, 0x60040000 };
Battle D_800A5CDC = { 0, 0, 0x60040000 };
Battle D_800A5CE8 = { 0, 0, 0x60040000 };
Battle D_800A5CF4 = { 0, 0, 0x60040000 };
Battle D_800A5D00 = { 0, 0, 0x60040000 };
Battle D_800A5D0C = { 0, 0, 0x60040000 };
Battle D_800A5D18 = { 0, 0, 0x60040000 };
Battle D_800A5D24 = { 0, 0, 0x60040000 };
BattleList D_800A5D30 = {
    0,
    { &D_800A5CD0, &D_800A5CDC, &D_800A5CE8, &D_800A5CF4,
      &D_800A5D00, &D_800A5D0C, &D_800A5D18, &D_800A5D24 },
};
Battle D_800A5D54 = { 0, 0, 0x60040000 };
Battle D_800A5D60 = { 0, 0, 0x60040000 };
Battle D_800A5D6C = { 0, 0, 0x60040000 };
Battle D_800A5D78 = { 0, 0, 0x60040000 };
Battle D_800A5D84 = { 0, 0, 0x60040000 };
Battle D_800A5D90 = { 0, 0, 0x60040000 };
Battle D_800A5D9C = { 0, 0, 0x60040000 };
Battle D_800A5DA8 = { 0, 0, 0x60040000 };
BattleList D_800A5DB4 = {
    0,
    { &D_800A5D54, &D_800A5D60, &D_800A5D6C, &D_800A5D78,
      &D_800A5D84, &D_800A5D90, &D_800A5D9C, &D_800A5DA8 },
};
Battle D_800A5DD8 = { 103, 11, 0x60080000 };
Battle D_800A5DE4 = { 103, 11, 0x60080000 };
Battle D_800A5DF0 = { 103, 11, 0x60080000 };
Battle D_800A5DFC = { 103, 11, 0x60080000 };
Battle D_800A5E08 = { 103, 11, 0x60080000 };
Battle D_800A5E14 = { 103, 11, 0x60080000 };
Battle D_800A5E20 = { 103, 11, 0x60080000 };
Battle D_800A5E2C = { 103, 11, 0x60080000 };
BattleList D_800A5E38 = {
    2,
    { &D_800A5DD8, &D_800A5DE4, &D_800A5DF0, &D_800A5DFC,
      &D_800A5E08, &D_800A5E14, &D_800A5E20, &D_800A5E2C },
};
Battle D_800A5E5C = { 0, 0, 0x60040000 };
Battle D_800A5E68 = { 0, 0, 0x60040000 };
Battle D_800A5E74 = { 0, 0, 0x60040000 };
Battle D_800A5E80 = { 0, 0, 0x60040000 };
Battle D_800A5E8C = { 0, 0, 0x60040000 };
Battle D_800A5E98 = { 0, 0, 0x60040000 };
Battle D_800A5EA4 = { 0, 0, 0x60040000 };
Battle D_800A5EB0 = { 0, 0, 0x60040000 };
BattleList D_800A5EBC = {
    0,
    { &D_800A5E5C, &D_800A5E68, &D_800A5E74, &D_800A5E80,
      &D_800A5E8C, &D_800A5E98, &D_800A5EA4, &D_800A5EB0 },
};
Battle D_800A5EE0 = { 0, 0, 0x60040000 };
Battle D_800A5EEC = { 0, 0, 0x60040000 };
Battle D_800A5EF8 = { 0, 0, 0x60040000 };
Battle D_800A5F04 = { 0, 0, 0x60040000 };
Battle D_800A5F10 = { 0, 0, 0x60040000 };
Battle D_800A5F1C = { 0, 0, 0x60040000 };
Battle D_800A5F28 = { 0, 0, 0x60040000 };
Battle D_800A5F34 = { 0, 0, 0x60040000 };
BattleList D_800A5F40 = {
    0,
    { &D_800A5EE0, &D_800A5EEC, &D_800A5EF8, &D_800A5F04,
      &D_800A5F10, &D_800A5F1C, &D_800A5F28, &D_800A5F34 },
};
Battle D_800A5F64 = { 0, 0, 0x60040000 };
Battle D_800A5F70 = { 0, 0, 0x60040000 };
Battle D_800A5F7C = { 0, 0, 0x60040000 };
Battle D_800A5F88 = { 0, 0, 0x60040000 };
Battle D_800A5F94 = { 0, 0, 0x60040000 };
Battle D_800A5FA0 = { 0, 0, 0x60040000 };
Battle D_800A5FAC = { 0, 0, 0x60040000 };
Battle D_800A5FB8 = { 0, 0, 0x60040000 };
BattleList D_800A5FC4 = {
    0,
    { &D_800A5F64, &D_800A5F70, &D_800A5F7C, &D_800A5F88,
      &D_800A5F94, &D_800A5FA0, &D_800A5FAC, &D_800A5FB8 },
};
Battle D_800A5FE8 = { 178, 11, 0x60080000 };
Battle D_800A5FF4 = { 178, 11, 0x60080000 };
Battle D_800A6000 = { 178, 11, 0x60080000 };
Battle D_800A600C = { 178, 11, 0x60080000 };
Battle D_800A6018 = { 178, 11, 0x60080000 };
Battle D_800A6024 = { 178, 11, 0x60080000 };
Battle D_800A6030 = { 178, 11, 0x60080000 };
Battle D_800A603C = { 178, 11, 0x60080000 };
BattleList D_800A6048 = {
    3,
    { &D_800A5FE8, &D_800A5FF4, &D_800A6000, &D_800A600C,
      &D_800A6018, &D_800A6024, &D_800A6030, &D_800A603C },
};
Battle D_800A606C = { 0, 0, 0x60040000 };
Battle D_800A6078 = { 0, 0, 0x60040000 };
Battle D_800A6084 = { 0, 0, 0x60040000 };
Battle D_800A6090 = { 0, 0, 0x60040000 };
Battle D_800A609C = { 0, 0, 0x60040000 };
Battle D_800A60A8 = { 0, 0, 0x60040000 };
Battle D_800A60B4 = { 0, 0, 0x60040000 };
Battle D_800A60C0 = { 0, 0, 0x60040000 };
BattleList D_800A60CC = {
    0,
    { &D_800A606C, &D_800A6078, &D_800A6084, &D_800A6090,
      &D_800A609C, &D_800A60A8, &D_800A60B4, &D_800A60C0 },
};
Battle D_800A60F0 = { 0, 0, 0x60040000 };
Battle D_800A60FC = { 0, 0, 0x60040000 };
Battle D_800A6108 = { 0, 0, 0x60040000 };
Battle D_800A6114 = { 0, 0, 0x60040000 };
Battle D_800A6120 = { 0, 0, 0x60040000 };
Battle D_800A612C = { 0, 0, 0x60040000 };
Battle D_800A6138 = { 0, 0, 0x60040000 };
Battle D_800A6144 = { 0, 0, 0x60040000 };
BattleList D_800A6150 = {
    0,
    { &D_800A60F0, &D_800A60FC, &D_800A6108, &D_800A6114,
      &D_800A6120, &D_800A612C, &D_800A6138, &D_800A6144 },
};
Battle D_800A6174 = { 0, 0, 0x60040000 };
Battle D_800A6180 = { 0, 0, 0x60040000 };
Battle D_800A618C = { 0, 0, 0x60040000 };
Battle D_800A6198 = { 0, 0, 0x60040000 };
Battle D_800A61A4 = { 0, 0, 0x60040000 };
Battle D_800A61B0 = { 0, 0, 0x60040000 };
Battle D_800A61BC = { 0, 0, 0x60040000 };
Battle D_800A61C8 = { 0, 0, 0x60040000 };
BattleList D_800A61D4 = {
    0,
    { &D_800A6174, &D_800A6180, &D_800A618C, &D_800A6198,
      &D_800A61A4, &D_800A61B0, &D_800A61BC, &D_800A61C8 },
};
Battle D_800A61F8 = { 178, 11, 0x60080000 };
Battle D_800A6204 = { 178, 11, 0x60080000 };
Battle D_800A6210 = { 178, 11, 0x60080000 };
Battle D_800A621C = { 178, 11, 0x60080000 };
Battle D_800A6228 = { 178, 11, 0x60080000 };
Battle D_800A6234 = { 178, 11, 0x60080000 };
Battle D_800A6240 = { 178, 11, 0x60080000 };
Battle D_800A624C = { 178, 11, 0x60080000 };
BattleList D_800A6258 = {
    5,
    { &D_800A61F8, &D_800A6204, &D_800A6210, &D_800A621C,
      &D_800A6228, &D_800A6234, &D_800A6240, &D_800A624C },
};
Battle D_800A627C = { 0, 0, 0x60040000 };
Battle D_800A6288 = { 0, 0, 0x60040000 };
Battle D_800A6294 = { 0, 0, 0x60040000 };
Battle D_800A62A0 = { 0, 0, 0x60040000 };
Battle D_800A62AC = { 0, 0, 0x60040000 };
Battle D_800A62B8 = { 0, 0, 0x60040000 };
Battle D_800A62C4 = { 0, 0, 0x60040000 };
Battle D_800A62D0 = { 0, 0, 0x60040000 };
BattleList D_800A62DC = {
    0,
    { &D_800A627C, &D_800A6288, &D_800A6294, &D_800A62A0,
      &D_800A62AC, &D_800A62B8, &D_800A62C4, &D_800A62D0 },
};
Battle D_800A6300 = { 0, 0, 0x60040000 };
Battle D_800A630C = { 0, 0, 0x60040000 };
Battle D_800A6318 = { 0, 0, 0x60040000 };
Battle D_800A6324 = { 0, 0, 0x60040000 };
Battle D_800A6330 = { 0, 0, 0x60040000 };
Battle D_800A633C = { 0, 0, 0x60040000 };
Battle D_800A6348 = { 0, 0, 0x60040000 };
Battle D_800A6354 = { 0, 0, 0x60040000 };
BattleList D_800A6360 = {
    0,
    { &D_800A6300, &D_800A630C, &D_800A6318, &D_800A6324,
      &D_800A6330, &D_800A633C, &D_800A6348, &D_800A6354 },
};
Battle D_800A6384 = { 0, 0, 0x60040000 };
Battle D_800A6390 = { 0, 0, 0x60040000 };
Battle D_800A639C = { 0, 0, 0x60040000 };
Battle D_800A63A8 = { 0, 0, 0x60040000 };
Battle D_800A63B4 = { 0, 0, 0x60040000 };
Battle D_800A63C0 = { 0, 0, 0x60040000 };
Battle D_800A63CC = { 0, 0, 0x60040000 };
Battle D_800A63D8 = { 0, 0, 0x60040000 };
BattleList D_800A63E4 = {
    0,
    { &D_800A6384, &D_800A6390, &D_800A639C, &D_800A63A8,
      &D_800A63B4, &D_800A63C0, &D_800A63CC, &D_800A63D8 },
};
Battle D_800A6408 = { 104, 11, 0x60080000 };
Battle D_800A6414 = { 104, 11, 0x60080000 };
Battle D_800A6420 = { 104, 11, 0x60080000 };
Battle D_800A642C = { 104, 11, 0x60080000 };
Battle D_800A6438 = { 104, 11, 0x60080000 };
Battle D_800A6444 = { 104, 11, 0x60080000 };
Battle D_800A6450 = { 104, 11, 0x60080000 };
Battle D_800A645C = { 104, 11, 0x60080000 };
BattleList D_800A6468 = {
    3,
    { &D_800A6408, &D_800A6414, &D_800A6420, &D_800A642C,
      &D_800A6438, &D_800A6444, &D_800A6450, &D_800A645C },
};
Battle D_800A648C = { 0, 0, 0x60040000 };
Battle D_800A6498 = { 0, 0, 0x60040000 };
Battle D_800A64A4 = { 0, 0, 0x60040000 };
Battle D_800A64B0 = { 0, 0, 0x60040000 };
Battle D_800A64BC = { 0, 0, 0x60040000 };
Battle D_800A64C8 = { 0, 0, 0x60040000 };
Battle D_800A64D4 = { 0, 0, 0x60040000 };
Battle D_800A64E0 = { 0, 0, 0x60040000 };
BattleList D_800A64EC = {
    0,
    { &D_800A648C, &D_800A6498, &D_800A64A4, &D_800A64B0,
      &D_800A64BC, &D_800A64C8, &D_800A64D4, &D_800A64E0 },
};
Battle D_800A6510 = { 0, 0, 0x60040000 };
Battle D_800A651C = { 0, 0, 0x60040000 };
Battle D_800A6528 = { 0, 0, 0x60040000 };
Battle D_800A6534 = { 0, 0, 0x60040000 };
Battle D_800A6540 = { 0, 0, 0x60040000 };
Battle D_800A654C = { 0, 0, 0x60040000 };
Battle D_800A6558 = { 0, 0, 0x60040000 };
Battle D_800A6564 = { 0, 0, 0x60040000 };
BattleList D_800A6570 = {
    0,
    { &D_800A6510, &D_800A651C, &D_800A6528, &D_800A6534,
      &D_800A6540, &D_800A654C, &D_800A6558, &D_800A6564 },
};
Battle D_800A6594 = { 0, 0, 0x60040000 };
Battle D_800A65A0 = { 0, 0, 0x60040000 };
Battle D_800A65AC = { 0, 0, 0x60040000 };
Battle D_800A65B8 = { 0, 0, 0x60040000 };
Battle D_800A65C4 = { 0, 0, 0x60040000 };
Battle D_800A65D0 = { 0, 0, 0x60040000 };
Battle D_800A65DC = { 0, 0, 0x60040000 };
Battle D_800A65E8 = { 0, 0, 0x60040000 };
BattleList D_800A65F4 = {
    0,
    { &D_800A6594, &D_800A65A0, &D_800A65AC, &D_800A65B8,
      &D_800A65C4, &D_800A65D0, &D_800A65DC, &D_800A65E8 },
};
FieldBattles stageBattles[] = {
    { 180, 3, 0, { &D_800A51D8, &D_800A525C, &D_800A52E0, &D_800A5364 } },
    { 183, 4, 0, { &D_800A53E8, &D_800A546C, &D_800A54F0, &D_800A5574 } },
    { 187, 5, 0, { &D_800A55F8, &D_800A567C, &D_800A5700, &D_800A5784 } },
    { 191, 6, 0, { &D_800A5808, &D_800A588C, &D_800A5910, &D_800A5994 } },
    { 198, 9, 0, { &D_800A5A18, &D_800A5A9C, &D_800A5B20, &D_800A5BA4 } },
    { 208, 13, 0, { &D_800A5C28, &D_800A5CAC, &D_800A5D30, &D_800A5DB4 } },
    { 211, 14, 0, { &D_800A5E38, &D_800A5EBC, &D_800A5F40, &D_800A5FC4 } },
    { 215, 15, 0, { &D_800A6048, &D_800A60CC, &D_800A6150, &D_800A61D4 } },
    { 219, 16, 0, { &D_800A6258, &D_800A62DC, &D_800A6360, &D_800A63E4 } },
    { 226, 19, 0, { &D_800A6468, &D_800A64EC, &D_800A6570, &D_800A65F4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x1A1, 0, 0xA1, 0x160, 0x1FF },
};
FieldActorEntry D_800A67A0 = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A67A0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 948, 29, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 311, 207, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 636, 93, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 871, 27, 0, 0 },
    { 1, 0, 0x8B, 2, 0, 0, 0, 0, 0, 0, 720, 158, 0, 0 },
    { 1, 0, 0xA1, 2, 1, 0, 0, 0, 0, 0, 688, 136, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 0, 0, 0, 0, 0, 262, 340, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 0, 0, 0, 0, 0, 320, 330, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 384, 299, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 448, 266, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 373, 118, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 490, 66, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 148, 233, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 753, 1, 0, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 860, -124, 120, 0 },
    { 1, 0, 0x8B, 4, 2, 0, 0, 0, 0, 0, 656, 118, 250, 0 },
    { 1, 0, 0x8A, 4, 3, 0, 0, 0, 0, 0, 624, 104, 234, 0 },
    { 1, 0, 0x79, 4, 4, 0, 0, 0, 0, 0, 592, 89, 218, 0 },
    { 1, 0, 0x98, 4, 5, 0, 0, 0, 0, 0, 560, 70, 202, 0 },
    { 1, 0, 0x55, 4, 7, 0, 0, 0, 0, 0, 400, 249, 338, 0 },
    { 1, 0, 0x67, 4, 8, 0, 0, 0, 0, 0, 368, 233, 322, 0 },
    { 1, 0, 0x5E, 4, 9, 0, 0, 0, 0, 0, 352, 228, 314, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E3, 0x380, 0x70, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E3, 0xA0, 0x180, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
