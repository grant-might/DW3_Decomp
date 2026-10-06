#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places_last.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x6D6
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x6E5
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xC700, 0x16D00};
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

extern StagePoint D_800A4FAC;
extern StagePoint D_800A4FBC;
extern StagePoint D_800A4FD4;
extern StagePoint D_800A4FE4;
extern StagePoint D_800A4FFC;
extern StagePoint D_800A500C;
extern StagePoint D_800A5024;
extern StagePoint D_800A5034;
extern StagePoint D_800A504C;
extern StagePoint D_800A505C;
extern StagePoint D_800A5074;
extern StagePoint D_800A5084;
extern StagePoint D_800A509C;
extern StagePoint D_800A50AC;
extern StagePoint D_800A50C4;
extern StagePoint D_800A50D4;
extern StagePoint D_800A50EC;
extern StagePoint D_800A50FC;
extern StagePoint D_800A5114;
extern StagePoint D_800A5124;
extern StagePoint D_800A513C;
extern StagePoint D_800A514C;
extern StagePoint D_800A5164;
extern StagePoint D_800A5174;
extern StagePoints D_800A4FCC;
extern StagePoints D_800A4FF4;
extern StagePoints D_800A501C;
extern StagePoints D_800A5044;
extern StagePoints D_800A506C;
extern StagePoints D_800A5094;
extern StagePoints D_800A50BC;
extern StagePoints D_800A50E4;
extern StagePoints D_800A510C;
extern StagePoints D_800A5134;
extern StagePoints D_800A515C;
extern StagePoints D_800A5184;
extern StagePoints D_800A518C;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A51F0;
extern Battle D_800A51FC;
extern Battle D_800A5208;
extern Battle D_800A5214;
extern Battle D_800A5220;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5274;
extern Battle D_800A5280;
extern Battle D_800A528C;
extern Battle D_800A5298;
extern Battle D_800A52A4;
extern Battle D_800A52D4;
extern Battle D_800A52E0;
extern Battle D_800A52EC;
extern Battle D_800A52F8;
extern Battle D_800A5304;
extern Battle D_800A5310;
extern Battle D_800A531C;
extern Battle D_800A5328;
extern Battle D_800A5358;
extern Battle D_800A5364;
extern Battle D_800A5370;
extern Battle D_800A537C;
extern Battle D_800A5388;
extern Battle D_800A5394;
extern Battle D_800A53A0;
extern Battle D_800A53AC;
extern Battle D_800A53DC;
extern Battle D_800A53E8;
extern Battle D_800A53F4;
extern Battle D_800A5400;
extern Battle D_800A540C;
extern Battle D_800A5418;
extern Battle D_800A5424;
extern Battle D_800A5430;
extern Battle D_800A5460;
extern Battle D_800A546C;
extern Battle D_800A5478;
extern Battle D_800A5484;
extern Battle D_800A5490;
extern Battle D_800A549C;
extern Battle D_800A54A8;
extern Battle D_800A54B4;
extern Battle D_800A54E4;
extern Battle D_800A54F0;
extern Battle D_800A54FC;
extern Battle D_800A5508;
extern Battle D_800A5514;
extern Battle D_800A5520;
extern Battle D_800A552C;
extern Battle D_800A5538;
extern Battle D_800A5568;
extern Battle D_800A5574;
extern Battle D_800A5580;
extern Battle D_800A558C;
extern Battle D_800A5598;
extern Battle D_800A55A4;
extern Battle D_800A55B0;
extern Battle D_800A55BC;
extern Battle D_800A55EC;
extern Battle D_800A55F8;
extern Battle D_800A5604;
extern Battle D_800A5610;
extern Battle D_800A561C;
extern Battle D_800A5628;
extern Battle D_800A5634;
extern Battle D_800A5640;
extern Battle D_800A5670;
extern Battle D_800A567C;
extern Battle D_800A5688;
extern Battle D_800A5694;
extern Battle D_800A56A0;
extern Battle D_800A56AC;
extern Battle D_800A56B8;
extern Battle D_800A56C4;
extern Battle D_800A56F4;
extern Battle D_800A5700;
extern Battle D_800A570C;
extern Battle D_800A5718;
extern Battle D_800A5724;
extern Battle D_800A5730;
extern Battle D_800A573C;
extern Battle D_800A5748;
extern Battle D_800A5778;
extern Battle D_800A5784;
extern Battle D_800A5790;
extern Battle D_800A579C;
extern Battle D_800A57A8;
extern Battle D_800A57B4;
extern Battle D_800A57C0;
extern Battle D_800A57CC;
extern Battle D_800A57FC;
extern Battle D_800A5808;
extern Battle D_800A5814;
extern Battle D_800A5820;
extern Battle D_800A582C;
extern Battle D_800A5838;
extern Battle D_800A5844;
extern Battle D_800A5850;
extern Battle D_800A5880;
extern Battle D_800A588C;
extern Battle D_800A5898;
extern Battle D_800A58A4;
extern Battle D_800A58B0;
extern Battle D_800A58BC;
extern Battle D_800A58C8;
extern Battle D_800A58D4;
extern Battle D_800A5904;
extern Battle D_800A5910;
extern Battle D_800A591C;
extern Battle D_800A5928;
extern Battle D_800A5934;
extern Battle D_800A5940;
extern Battle D_800A594C;
extern Battle D_800A5958;
extern Battle D_800A5988;
extern Battle D_800A5994;
extern Battle D_800A59A0;
extern Battle D_800A59AC;
extern Battle D_800A59B8;
extern Battle D_800A59C4;
extern Battle D_800A59D0;
extern Battle D_800A59DC;
extern Battle D_800A5A0C;
extern Battle D_800A5A18;
extern Battle D_800A5A24;
extern Battle D_800A5A30;
extern Battle D_800A5A3C;
extern Battle D_800A5A48;
extern Battle D_800A5A54;
extern Battle D_800A5A60;
extern Battle D_800A5A90;
extern Battle D_800A5A9C;
extern Battle D_800A5AA8;
extern Battle D_800A5AB4;
extern Battle D_800A5AC0;
extern Battle D_800A5ACC;
extern Battle D_800A5AD8;
extern Battle D_800A5AE4;
extern Battle D_800A5B14;
extern Battle D_800A5B20;
extern Battle D_800A5B2C;
extern Battle D_800A5B38;
extern Battle D_800A5B44;
extern Battle D_800A5B50;
extern Battle D_800A5B5C;
extern Battle D_800A5B68;
extern Battle D_800A5B98;
extern Battle D_800A5BA4;
extern Battle D_800A5BB0;
extern Battle D_800A5BBC;
extern Battle D_800A5BC8;
extern Battle D_800A5BD4;
extern Battle D_800A5BE0;
extern Battle D_800A5BEC;
extern Battle D_800A5C1C;
extern Battle D_800A5C28;
extern Battle D_800A5C34;
extern Battle D_800A5C40;
extern Battle D_800A5C4C;
extern Battle D_800A5C58;
extern Battle D_800A5C64;
extern Battle D_800A5C70;
extern Battle D_800A5CA0;
extern Battle D_800A5CAC;
extern Battle D_800A5CB8;
extern Battle D_800A5CC4;
extern Battle D_800A5CD0;
extern Battle D_800A5CDC;
extern Battle D_800A5CE8;
extern Battle D_800A5CF4;
extern Battle D_800A5D24;
extern Battle D_800A5D30;
extern Battle D_800A5D3C;
extern Battle D_800A5D48;
extern Battle D_800A5D54;
extern Battle D_800A5D60;
extern Battle D_800A5D6C;
extern Battle D_800A5D78;
extern Battle D_800A5DA8;
extern Battle D_800A5DB4;
extern Battle D_800A5DC0;
extern Battle D_800A5DCC;
extern Battle D_800A5DD8;
extern Battle D_800A5DE4;
extern Battle D_800A5DF0;
extern Battle D_800A5DFC;
extern Battle D_800A5E2C;
extern Battle D_800A5E38;
extern Battle D_800A5E44;
extern Battle D_800A5E50;
extern Battle D_800A5E5C;
extern Battle D_800A5E68;
extern Battle D_800A5E74;
extern Battle D_800A5E80;
extern Battle D_800A5EB0;
extern Battle D_800A5EBC;
extern Battle D_800A5EC8;
extern Battle D_800A5ED4;
extern Battle D_800A5EE0;
extern Battle D_800A5EEC;
extern Battle D_800A5EF8;
extern Battle D_800A5F04;
extern Battle D_800A5F34;
extern Battle D_800A5F40;
extern Battle D_800A5F4C;
extern Battle D_800A5F58;
extern Battle D_800A5F64;
extern Battle D_800A5F70;
extern Battle D_800A5F7C;
extern Battle D_800A5F88;
extern Battle D_800A5FB8;
extern Battle D_800A5FC4;
extern Battle D_800A5FD0;
extern Battle D_800A5FDC;
extern Battle D_800A5FE8;
extern Battle D_800A5FF4;
extern Battle D_800A6000;
extern Battle D_800A600C;
extern Battle D_800A603C;
extern Battle D_800A6048;
extern Battle D_800A6054;
extern Battle D_800A6060;
extern Battle D_800A606C;
extern Battle D_800A6078;
extern Battle D_800A6084;
extern Battle D_800A6090;
extern Battle D_800A60C0;
extern Battle D_800A60CC;
extern Battle D_800A60D8;
extern Battle D_800A60E4;
extern Battle D_800A60F0;
extern Battle D_800A60FC;
extern Battle D_800A6108;
extern Battle D_800A6114;
extern Battle D_800A6144;
extern Battle D_800A6150;
extern Battle D_800A615C;
extern Battle D_800A6168;
extern Battle D_800A6174;
extern Battle D_800A6180;
extern Battle D_800A618C;
extern Battle D_800A6198;
extern Battle D_800A61C8;
extern Battle D_800A61D4;
extern Battle D_800A61E0;
extern Battle D_800A61EC;
extern Battle D_800A61F8;
extern Battle D_800A6204;
extern Battle D_800A6210;
extern Battle D_800A621C;
extern Battle D_800A624C;
extern Battle D_800A6258;
extern Battle D_800A6264;
extern Battle D_800A6270;
extern Battle D_800A627C;
extern Battle D_800A6288;
extern Battle D_800A6294;
extern Battle D_800A62A0;
extern Battle D_800A62D0;
extern Battle D_800A62DC;
extern Battle D_800A62E8;
extern Battle D_800A62F4;
extern Battle D_800A6300;
extern Battle D_800A630C;
extern Battle D_800A6318;
extern Battle D_800A6324;
extern Battle D_800A6354;
extern Battle D_800A6360;
extern Battle D_800A636C;
extern Battle D_800A6378;
extern Battle D_800A6384;
extern Battle D_800A6390;
extern Battle D_800A639C;
extern Battle D_800A63A8;
extern Battle D_800A63D8;
extern Battle D_800A63E4;
extern Battle D_800A63F0;
extern Battle D_800A63FC;
extern Battle D_800A6408;
extern Battle D_800A6414;
extern Battle D_800A6420;
extern Battle D_800A642C;
extern Battle D_800A645C;
extern Battle D_800A6468;
extern Battle D_800A6474;
extern Battle D_800A6480;
extern Battle D_800A648C;
extern Battle D_800A6498;
extern Battle D_800A64A4;
extern Battle D_800A64B0;
extern Battle D_800A64E0;
extern Battle D_800A64EC;
extern Battle D_800A64F8;
extern Battle D_800A6504;
extern Battle D_800A6510;
extern Battle D_800A651C;
extern Battle D_800A6528;
extern Battle D_800A6534;
extern Battle D_800A6564;
extern Battle D_800A6570;
extern Battle D_800A657C;
extern Battle D_800A6588;
extern Battle D_800A6594;
extern Battle D_800A65A0;
extern Battle D_800A65AC;
extern Battle D_800A65B8;
extern Battle D_800A65E8;
extern Battle D_800A65F4;
extern Battle D_800A6600;
extern Battle D_800A660C;
extern Battle D_800A6618;
extern Battle D_800A6624;
extern Battle D_800A6630;
extern Battle D_800A663C;
extern Battle D_800A666C;
extern Battle D_800A6678;
extern Battle D_800A6684;
extern Battle D_800A6690;
extern Battle D_800A669C;
extern Battle D_800A66A8;
extern Battle D_800A66B4;
extern Battle D_800A66C0;
extern Battle D_800A66F0;
extern Battle D_800A66FC;
extern Battle D_800A6708;
extern Battle D_800A6714;
extern Battle D_800A6720;
extern Battle D_800A672C;
extern Battle D_800A6738;
extern Battle D_800A6744;
extern Battle D_800A6774;
extern Battle D_800A6780;
extern Battle D_800A678C;
extern Battle D_800A6798;
extern Battle D_800A67A4;
extern Battle D_800A67B0;
extern Battle D_800A67BC;
extern Battle D_800A67C8;
extern Battle D_800A67F8;
extern Battle D_800A6804;
extern Battle D_800A6810;
extern Battle D_800A681C;
extern Battle D_800A6828;
extern Battle D_800A6834;
extern Battle D_800A6840;
extern Battle D_800A684C;
extern Battle D_800A687C;
extern Battle D_800A6888;
extern Battle D_800A6894;
extern Battle D_800A68A0;
extern Battle D_800A68AC;
extern Battle D_800A68B8;
extern Battle D_800A68C4;
extern Battle D_800A68D0;
extern Battle D_800A6900;
extern Battle D_800A690C;
extern Battle D_800A6918;
extern Battle D_800A6924;
extern Battle D_800A6930;
extern Battle D_800A693C;
extern Battle D_800A6948;
extern Battle D_800A6954;
extern Battle D_800A6984;
extern Battle D_800A6990;
extern Battle D_800A699C;
extern Battle D_800A69A8;
extern Battle D_800A69B4;
extern Battle D_800A69C0;
extern Battle D_800A69CC;
extern Battle D_800A69D8;
extern Battle D_800A6A08;
extern Battle D_800A6A14;
extern Battle D_800A6A20;
extern Battle D_800A6A2C;
extern Battle D_800A6A38;
extern Battle D_800A6A44;
extern Battle D_800A6A50;
extern Battle D_800A6A5C;
extern BattleList D_800A522C;
extern BattleList D_800A52B0;
extern BattleList D_800A5334;
extern BattleList D_800A53B8;
extern BattleList D_800A543C;
extern BattleList D_800A54C0;
extern BattleList D_800A5544;
extern BattleList D_800A55C8;
extern BattleList D_800A564C;
extern BattleList D_800A56D0;
extern BattleList D_800A5754;
extern BattleList D_800A57D8;
extern BattleList D_800A585C;
extern BattleList D_800A58E0;
extern BattleList D_800A5964;
extern BattleList D_800A59E8;
extern BattleList D_800A5A6C;
extern BattleList D_800A5AF0;
extern BattleList D_800A5B74;
extern BattleList D_800A5BF8;
extern BattleList D_800A5C7C;
extern BattleList D_800A5D00;
extern BattleList D_800A5D84;
extern BattleList D_800A5E08;
extern BattleList D_800A5E8C;
extern BattleList D_800A5F10;
extern BattleList D_800A5F94;
extern BattleList D_800A6018;
extern BattleList D_800A609C;
extern BattleList D_800A6120;
extern BattleList D_800A61A4;
extern BattleList D_800A6228;
extern BattleList D_800A62AC;
extern BattleList D_800A6330;
extern BattleList D_800A63B4;
extern BattleList D_800A6438;
extern BattleList D_800A64BC;
extern BattleList D_800A6540;
extern BattleList D_800A65C4;
extern BattleList D_800A6648;
extern BattleList D_800A66CC;
extern BattleList D_800A6750;
extern BattleList D_800A67D4;
extern BattleList D_800A6858;
extern BattleList D_800A68DC;
extern BattleList D_800A6960;
extern BattleList D_800A69E4;
extern BattleList D_800A6A68;
extern FieldActorEntry D_800A6C4C;

StagePoint D_800A4FAC = { 0x2E6, 3, 1, 160, 0x150, 5, NULL };
StagePoint D_800A4FBC = { 0x24B, 0, 0, 0x2D0, 0x320, 0, &D_800A4FAC };
StagePoints D_800A4FCC = { 3, 1, &D_800A4FBC };
StagePoint D_800A4FD4 = { 0x2E5, 4, 1, 224, 0x120, 5, NULL };
StagePoint D_800A4FE4 = { 0x23C, 0, 0, 160, 0x3E8, 0, &D_800A4FD4 };
StagePoints D_800A4FF4 = { 4, 1, &D_800A4FE4 };
StagePoint D_800A4FFC = { 0x2E6, 5, 1, 160, 0x150, 5, NULL };
StagePoint D_800A500C = { 0x249, 0, 0, 208, 0x200, 0, &D_800A4FFC };
StagePoints D_800A501C = { 5, 1, &D_800A500C };
StagePoint D_800A5024 = { 0x2E0, 7, 1, 176, 0x178, 5, NULL };
StagePoint D_800A5034 = { 0x23E, 0, 0, 0x420, 0x1E8, 0, &D_800A5024 };
StagePoints D_800A5044 = { 7, 1, &D_800A5034 };
StagePoint D_800A504C = { 0x2E0, 8, 1, 176, 0x178, 5, NULL };
StagePoint D_800A505C = { 0x227, 0, 0, 0x240, 0x200, 0, &D_800A504C };
StagePoints D_800A506C = { 8, 1, &D_800A505C };
StagePoint D_800A5074 = { 0x2E6, 9, 1, 160, 0x150, 5, NULL };
StagePoint D_800A5084 = { 0x247, 0, 0, 0x350, 0x3F0, 0, &D_800A5074 };
StagePoints D_800A5094 = { 9, 1, &D_800A5084 };
StagePoint D_800A509C = { 0x2E6, 13, 1, 160, 0x150, 5, NULL };
StagePoint D_800A50AC = { 0x2B5, 0, 0, 0x2D0, 0x320, 0, &D_800A509C };
StagePoints D_800A50BC = { 13, 1, &D_800A50AC };
StagePoint D_800A50C4 = { 0x2E5, 14, 1, 224, 0x120, 5, NULL };
StagePoint D_800A50D4 = { 0x2A9, 0, 0, 160, 0x3E8, 0, &D_800A50C4 };
StagePoints D_800A50E4 = { 14, 1, &D_800A50D4 };
StagePoint D_800A50EC = { 0x2E6, 15, 1, 160, 0x150, 5, NULL };
StagePoint D_800A50FC = { 0x2B3, 0, 0, 208, 0x200, 0, &D_800A50EC };
StagePoints D_800A510C = { 15, 1, &D_800A50FC };
StagePoint D_800A5114 = { 0x2E0, 17, 1, 176, 0x178, 5, NULL };
StagePoint D_800A5124 = { 0x2AB, 0, 0, 0x420, 0x1E8, 0, &D_800A5114 };
StagePoints D_800A5134 = { 17, 1, &D_800A5124 };
StagePoint D_800A513C = { 0x2E0, 18, 1, 176, 0x178, 5, NULL };
StagePoint D_800A514C = { 0x296, 0, 0, 0x240, 0x200, 0, &D_800A513C };
StagePoints D_800A515C = { 18, 1, &D_800A514C };
StagePoint D_800A5164 = { 0x2E6, 19, 1, 160, 0x150, 5, NULL };
StagePoint D_800A5174 = { 0x2B1, 0, 0, 0x350, 0x3F0, 0, &D_800A5164 };
StagePoints D_800A5184 = { 19, 1, &D_800A5174 };
StagePoints D_800A518C = { 0, 0, &D_800A4FBC };
StagePoints *placePoints[] = {
    &D_800A4FCC, &D_800A4FF4, &D_800A501C, &D_800A5044,
    &D_800A506C, &D_800A5094, &D_800A50BC, &D_800A50E4,
    &D_800A510C, &D_800A5134, &D_800A515C, &D_800A5184,
    &D_800A518C, NULL,
};
Battle D_800A51CC = { 61, 11, 0x60080000 };
Battle D_800A51D8 = { 61, 11, 0x60080000 };
Battle D_800A51E4 = { 61, 11, 0x60080000 };
Battle D_800A51F0 = { 61, 11, 0x60080000 };
Battle D_800A51FC = { 61, 11, 0x60080000 };
Battle D_800A5208 = { 61, 11, 0x60080000 };
Battle D_800A5214 = { 61, 11, 0x60080000 };
Battle D_800A5220 = { 61, 11, 0x60080000 };
BattleList D_800A522C = {
    3,
    { &D_800A51CC, &D_800A51D8, &D_800A51E4, &D_800A51F0,
      &D_800A51FC, &D_800A5208, &D_800A5214, &D_800A5220 },
};
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
Battle D_800A5274 = { 0, 0, 0x60040000 };
Battle D_800A5280 = { 0, 0, 0x60040000 };
Battle D_800A528C = { 0, 0, 0x60040000 };
Battle D_800A5298 = { 0, 0, 0x60040000 };
Battle D_800A52A4 = { 0, 0, 0x60040000 };
BattleList D_800A52B0 = {
    0,
    { &D_800A5250, &D_800A525C, &D_800A5268, &D_800A5274,
      &D_800A5280, &D_800A528C, &D_800A5298, &D_800A52A4 },
};
Battle D_800A52D4 = { 0, 0, 0x60040000 };
Battle D_800A52E0 = { 0, 0, 0x60040000 };
Battle D_800A52EC = { 0, 0, 0x60040000 };
Battle D_800A52F8 = { 0, 0, 0x60040000 };
Battle D_800A5304 = { 0, 0, 0x60040000 };
Battle D_800A5310 = { 0, 0, 0x60040000 };
Battle D_800A531C = { 0, 0, 0x60040000 };
Battle D_800A5328 = { 0, 0, 0x60040000 };
BattleList D_800A5334 = {
    0,
    { &D_800A52D4, &D_800A52E0, &D_800A52EC, &D_800A52F8,
      &D_800A5304, &D_800A5310, &D_800A531C, &D_800A5328 },
};
Battle D_800A5358 = { 0, 0, 0x60040000 };
Battle D_800A5364 = { 0, 0, 0x60040000 };
Battle D_800A5370 = { 0, 0, 0x60040000 };
Battle D_800A537C = { 0, 0, 0x60040000 };
Battle D_800A5388 = { 0, 0, 0x60040000 };
Battle D_800A5394 = { 0, 0, 0x60040000 };
Battle D_800A53A0 = { 0, 0, 0x60040000 };
Battle D_800A53AC = { 0, 0, 0x60040000 };
BattleList D_800A53B8 = {
    0,
    { &D_800A5358, &D_800A5364, &D_800A5370, &D_800A537C,
      &D_800A5388, &D_800A5394, &D_800A53A0, &D_800A53AC },
};
Battle D_800A53DC = { 61, 11, 0x60080000 };
Battle D_800A53E8 = { 61, 11, 0x60080000 };
Battle D_800A53F4 = { 61, 11, 0x60080000 };
Battle D_800A5400 = { 61, 11, 0x60080000 };
Battle D_800A540C = { 62, 11, 0x60080000 };
Battle D_800A5418 = { 62, 11, 0x60080000 };
Battle D_800A5424 = { 62, 11, 0x60080000 };
Battle D_800A5430 = { 62, 11, 0x60080000 };
BattleList D_800A543C = {
    2,
    { &D_800A53DC, &D_800A53E8, &D_800A53F4, &D_800A5400,
      &D_800A540C, &D_800A5418, &D_800A5424, &D_800A5430 },
};
Battle D_800A5460 = { 0, 0, 0x60040000 };
Battle D_800A546C = { 0, 0, 0x60040000 };
Battle D_800A5478 = { 0, 0, 0x60040000 };
Battle D_800A5484 = { 0, 0, 0x60040000 };
Battle D_800A5490 = { 0, 0, 0x60040000 };
Battle D_800A549C = { 0, 0, 0x60040000 };
Battle D_800A54A8 = { 0, 0, 0x60040000 };
Battle D_800A54B4 = { 0, 0, 0x60040000 };
BattleList D_800A54C0 = {
    0,
    { &D_800A5460, &D_800A546C, &D_800A5478, &D_800A5484,
      &D_800A5490, &D_800A549C, &D_800A54A8, &D_800A54B4 },
};
Battle D_800A54E4 = { 0, 0, 0x60040000 };
Battle D_800A54F0 = { 0, 0, 0x60040000 };
Battle D_800A54FC = { 0, 0, 0x60040000 };
Battle D_800A5508 = { 0, 0, 0x60040000 };
Battle D_800A5514 = { 0, 0, 0x60040000 };
Battle D_800A5520 = { 0, 0, 0x60040000 };
Battle D_800A552C = { 0, 0, 0x60040000 };
Battle D_800A5538 = { 0, 0, 0x60040000 };
BattleList D_800A5544 = {
    0,
    { &D_800A54E4, &D_800A54F0, &D_800A54FC, &D_800A5508,
      &D_800A5514, &D_800A5520, &D_800A552C, &D_800A5538 },
};
Battle D_800A5568 = { 0, 0, 0x60040000 };
Battle D_800A5574 = { 0, 0, 0x60040000 };
Battle D_800A5580 = { 0, 0, 0x60040000 };
Battle D_800A558C = { 0, 0, 0x60040000 };
Battle D_800A5598 = { 0, 0, 0x60040000 };
Battle D_800A55A4 = { 0, 0, 0x60040000 };
Battle D_800A55B0 = { 0, 0, 0x60040000 };
Battle D_800A55BC = { 0, 0, 0x60040000 };
BattleList D_800A55C8 = {
    0,
    { &D_800A5568, &D_800A5574, &D_800A5580, &D_800A558C,
      &D_800A5598, &D_800A55A4, &D_800A55B0, &D_800A55BC },
};
Battle D_800A55EC = { 63, 11, 0x60080000 };
Battle D_800A55F8 = { 63, 11, 0x60080000 };
Battle D_800A5604 = { 63, 11, 0x60080000 };
Battle D_800A5610 = { 63, 11, 0x60080000 };
Battle D_800A561C = { 63, 11, 0x60080000 };
Battle D_800A5628 = { 63, 11, 0x60080000 };
Battle D_800A5634 = { 63, 11, 0x60080000 };
Battle D_800A5640 = { 63, 11, 0x60080000 };
BattleList D_800A564C = {
    3,
    { &D_800A55EC, &D_800A55F8, &D_800A5604, &D_800A5610,
      &D_800A561C, &D_800A5628, &D_800A5634, &D_800A5640 },
};
Battle D_800A5670 = { 0, 0, 0x60040000 };
Battle D_800A567C = { 0, 0, 0x60040000 };
Battle D_800A5688 = { 0, 0, 0x60040000 };
Battle D_800A5694 = { 0, 0, 0x60040000 };
Battle D_800A56A0 = { 0, 0, 0x60040000 };
Battle D_800A56AC = { 0, 0, 0x60040000 };
Battle D_800A56B8 = { 0, 0, 0x60040000 };
Battle D_800A56C4 = { 0, 0, 0x60040000 };
BattleList D_800A56D0 = {
    0,
    { &D_800A5670, &D_800A567C, &D_800A5688, &D_800A5694,
      &D_800A56A0, &D_800A56AC, &D_800A56B8, &D_800A56C4 },
};
Battle D_800A56F4 = { 0, 0, 0x60040000 };
Battle D_800A5700 = { 0, 0, 0x60040000 };
Battle D_800A570C = { 0, 0, 0x60040000 };
Battle D_800A5718 = { 0, 0, 0x60040000 };
Battle D_800A5724 = { 0, 0, 0x60040000 };
Battle D_800A5730 = { 0, 0, 0x60040000 };
Battle D_800A573C = { 0, 0, 0x60040000 };
Battle D_800A5748 = { 0, 0, 0x60040000 };
BattleList D_800A5754 = {
    0,
    { &D_800A56F4, &D_800A5700, &D_800A570C, &D_800A5718,
      &D_800A5724, &D_800A5730, &D_800A573C, &D_800A5748 },
};
Battle D_800A5778 = { 0, 0, 0x60040000 };
Battle D_800A5784 = { 0, 0, 0x60040000 };
Battle D_800A5790 = { 0, 0, 0x60040000 };
Battle D_800A579C = { 0, 0, 0x60040000 };
Battle D_800A57A8 = { 0, 0, 0x60040000 };
Battle D_800A57B4 = { 0, 0, 0x60040000 };
Battle D_800A57C0 = { 0, 0, 0x60040000 };
Battle D_800A57CC = { 0, 0, 0x60040000 };
BattleList D_800A57D8 = {
    0,
    { &D_800A5778, &D_800A5784, &D_800A5790, &D_800A579C,
      &D_800A57A8, &D_800A57B4, &D_800A57C0, &D_800A57CC },
};
Battle D_800A57FC = { 61, 11, 0x60080000 };
Battle D_800A5808 = { 61, 11, 0x60080000 };
Battle D_800A5814 = { 61, 11, 0x60080000 };
Battle D_800A5820 = { 61, 11, 0x60080000 };
Battle D_800A582C = { 61, 11, 0x60080000 };
Battle D_800A5838 = { 61, 11, 0x60080000 };
Battle D_800A5844 = { 61, 11, 0x60080000 };
Battle D_800A5850 = { 61, 11, 0x60080000 };
BattleList D_800A585C = {
    4,
    { &D_800A57FC, &D_800A5808, &D_800A5814, &D_800A5820,
      &D_800A582C, &D_800A5838, &D_800A5844, &D_800A5850 },
};
Battle D_800A5880 = { 0, 0, 0x60040000 };
Battle D_800A588C = { 0, 0, 0x60040000 };
Battle D_800A5898 = { 0, 0, 0x60040000 };
Battle D_800A58A4 = { 0, 0, 0x60040000 };
Battle D_800A58B0 = { 0, 0, 0x60040000 };
Battle D_800A58BC = { 0, 0, 0x60040000 };
Battle D_800A58C8 = { 0, 0, 0x60040000 };
Battle D_800A58D4 = { 0, 0, 0x60040000 };
BattleList D_800A58E0 = {
    0,
    { &D_800A5880, &D_800A588C, &D_800A5898, &D_800A58A4,
      &D_800A58B0, &D_800A58BC, &D_800A58C8, &D_800A58D4 },
};
Battle D_800A5904 = { 0, 0, 0x60040000 };
Battle D_800A5910 = { 0, 0, 0x60040000 };
Battle D_800A591C = { 0, 0, 0x60040000 };
Battle D_800A5928 = { 0, 0, 0x60040000 };
Battle D_800A5934 = { 0, 0, 0x60040000 };
Battle D_800A5940 = { 0, 0, 0x60040000 };
Battle D_800A594C = { 0, 0, 0x60040000 };
Battle D_800A5958 = { 0, 0, 0x60040000 };
BattleList D_800A5964 = {
    0,
    { &D_800A5904, &D_800A5910, &D_800A591C, &D_800A5928,
      &D_800A5934, &D_800A5940, &D_800A594C, &D_800A5958 },
};
Battle D_800A5988 = { 0, 0, 0x60040000 };
Battle D_800A5994 = { 0, 0, 0x60040000 };
Battle D_800A59A0 = { 0, 0, 0x60040000 };
Battle D_800A59AC = { 0, 0, 0x60040000 };
Battle D_800A59B8 = { 0, 0, 0x60040000 };
Battle D_800A59C4 = { 0, 0, 0x60040000 };
Battle D_800A59D0 = { 0, 0, 0x60040000 };
Battle D_800A59DC = { 0, 0, 0x60040000 };
BattleList D_800A59E8 = {
    0,
    { &D_800A5988, &D_800A5994, &D_800A59A0, &D_800A59AC,
      &D_800A59B8, &D_800A59C4, &D_800A59D0, &D_800A59DC },
};
Battle D_800A5A0C = { 64, 11, 0x60080000 };
Battle D_800A5A18 = { 64, 11, 0x60080000 };
Battle D_800A5A24 = { 64, 11, 0x60080000 };
Battle D_800A5A30 = { 64, 11, 0x60080000 };
Battle D_800A5A3C = { 64, 11, 0x60080000 };
Battle D_800A5A48 = { 64, 11, 0x60080000 };
Battle D_800A5A54 = { 64, 11, 0x60080000 };
Battle D_800A5A60 = { 64, 11, 0x60080000 };
BattleList D_800A5A6C = {
    4,
    { &D_800A5A0C, &D_800A5A18, &D_800A5A24, &D_800A5A30,
      &D_800A5A3C, &D_800A5A48, &D_800A5A54, &D_800A5A60 },
};
Battle D_800A5A90 = { 0, 0, 0x60040000 };
Battle D_800A5A9C = { 0, 0, 0x60040000 };
Battle D_800A5AA8 = { 0, 0, 0x60040000 };
Battle D_800A5AB4 = { 0, 0, 0x60040000 };
Battle D_800A5AC0 = { 0, 0, 0x60040000 };
Battle D_800A5ACC = { 0, 0, 0x60040000 };
Battle D_800A5AD8 = { 0, 0, 0x60040000 };
Battle D_800A5AE4 = { 0, 0, 0x60040000 };
BattleList D_800A5AF0 = {
    0,
    { &D_800A5A90, &D_800A5A9C, &D_800A5AA8, &D_800A5AB4,
      &D_800A5AC0, &D_800A5ACC, &D_800A5AD8, &D_800A5AE4 },
};
Battle D_800A5B14 = { 0, 0, 0x60040000 };
Battle D_800A5B20 = { 0, 0, 0x60040000 };
Battle D_800A5B2C = { 0, 0, 0x60040000 };
Battle D_800A5B38 = { 0, 0, 0x60040000 };
Battle D_800A5B44 = { 0, 0, 0x60040000 };
Battle D_800A5B50 = { 0, 0, 0x60040000 };
Battle D_800A5B5C = { 0, 0, 0x60040000 };
Battle D_800A5B68 = { 0, 0, 0x60040000 };
BattleList D_800A5B74 = {
    0,
    { &D_800A5B14, &D_800A5B20, &D_800A5B2C, &D_800A5B38,
      &D_800A5B44, &D_800A5B50, &D_800A5B5C, &D_800A5B68 },
};
Battle D_800A5B98 = { 0, 0, 0x60040000 };
Battle D_800A5BA4 = { 0, 0, 0x60040000 };
Battle D_800A5BB0 = { 0, 0, 0x60040000 };
Battle D_800A5BBC = { 0, 0, 0x60040000 };
Battle D_800A5BC8 = { 0, 0, 0x60040000 };
Battle D_800A5BD4 = { 0, 0, 0x60040000 };
Battle D_800A5BE0 = { 0, 0, 0x60040000 };
Battle D_800A5BEC = { 0, 0, 0x60040000 };
BattleList D_800A5BF8 = {
    0,
    { &D_800A5B98, &D_800A5BA4, &D_800A5BB0, &D_800A5BBC,
      &D_800A5BC8, &D_800A5BD4, &D_800A5BE0, &D_800A5BEC },
};
Battle D_800A5C1C = { 61, 11, 0x60080000 };
Battle D_800A5C28 = { 61, 11, 0x60080000 };
Battle D_800A5C34 = { 61, 11, 0x60080000 };
Battle D_800A5C40 = { 61, 11, 0x60080000 };
Battle D_800A5C4C = { 61, 11, 0x60080000 };
Battle D_800A5C58 = { 61, 11, 0x60080000 };
Battle D_800A5C64 = { 61, 11, 0x60080000 };
Battle D_800A5C70 = { 61, 11, 0x60080000 };
BattleList D_800A5C7C = {
    3,
    { &D_800A5C1C, &D_800A5C28, &D_800A5C34, &D_800A5C40,
      &D_800A5C4C, &D_800A5C58, &D_800A5C64, &D_800A5C70 },
};
Battle D_800A5CA0 = { 0, 0, 0x60040000 };
Battle D_800A5CAC = { 0, 0, 0x60040000 };
Battle D_800A5CB8 = { 0, 0, 0x60040000 };
Battle D_800A5CC4 = { 0, 0, 0x60040000 };
Battle D_800A5CD0 = { 0, 0, 0x60040000 };
Battle D_800A5CDC = { 0, 0, 0x60040000 };
Battle D_800A5CE8 = { 0, 0, 0x60040000 };
Battle D_800A5CF4 = { 0, 0, 0x60040000 };
BattleList D_800A5D00 = {
    0,
    { &D_800A5CA0, &D_800A5CAC, &D_800A5CB8, &D_800A5CC4,
      &D_800A5CD0, &D_800A5CDC, &D_800A5CE8, &D_800A5CF4 },
};
Battle D_800A5D24 = { 0, 0, 0x60040000 };
Battle D_800A5D30 = { 0, 0, 0x60040000 };
Battle D_800A5D3C = { 0, 0, 0x60040000 };
Battle D_800A5D48 = { 0, 0, 0x60040000 };
Battle D_800A5D54 = { 0, 0, 0x60040000 };
Battle D_800A5D60 = { 0, 0, 0x60040000 };
Battle D_800A5D6C = { 0, 0, 0x60040000 };
Battle D_800A5D78 = { 0, 0, 0x60040000 };
BattleList D_800A5D84 = {
    0,
    { &D_800A5D24, &D_800A5D30, &D_800A5D3C, &D_800A5D48,
      &D_800A5D54, &D_800A5D60, &D_800A5D6C, &D_800A5D78 },
};
Battle D_800A5DA8 = { 0, 0, 0x60040000 };
Battle D_800A5DB4 = { 0, 0, 0x60040000 };
Battle D_800A5DC0 = { 0, 0, 0x60040000 };
Battle D_800A5DCC = { 0, 0, 0x60040000 };
Battle D_800A5DD8 = { 0, 0, 0x60040000 };
Battle D_800A5DE4 = { 0, 0, 0x60040000 };
Battle D_800A5DF0 = { 0, 0, 0x60040000 };
Battle D_800A5DFC = { 0, 0, 0x60040000 };
BattleList D_800A5E08 = {
    0,
    { &D_800A5DA8, &D_800A5DB4, &D_800A5DC0, &D_800A5DCC,
      &D_800A5DD8, &D_800A5DE4, &D_800A5DF0, &D_800A5DFC },
};
Battle D_800A5E2C = { 104, 11, 0x60080000 };
Battle D_800A5E38 = { 104, 11, 0x60080000 };
Battle D_800A5E44 = { 104, 11, 0x60080000 };
Battle D_800A5E50 = { 104, 11, 0x60080000 };
Battle D_800A5E5C = { 104, 11, 0x60080000 };
Battle D_800A5E68 = { 104, 11, 0x60080000 };
Battle D_800A5E74 = { 104, 11, 0x60080000 };
Battle D_800A5E80 = { 104, 11, 0x60080000 };
BattleList D_800A5E8C = {
    3,
    { &D_800A5E2C, &D_800A5E38, &D_800A5E44, &D_800A5E50,
      &D_800A5E5C, &D_800A5E68, &D_800A5E74, &D_800A5E80 },
};
Battle D_800A5EB0 = { 0, 0, 0x60040000 };
Battle D_800A5EBC = { 0, 0, 0x60040000 };
Battle D_800A5EC8 = { 0, 0, 0x60040000 };
Battle D_800A5ED4 = { 0, 0, 0x60040000 };
Battle D_800A5EE0 = { 0, 0, 0x60040000 };
Battle D_800A5EEC = { 0, 0, 0x60040000 };
Battle D_800A5EF8 = { 0, 0, 0x60040000 };
Battle D_800A5F04 = { 0, 0, 0x60040000 };
BattleList D_800A5F10 = {
    0,
    { &D_800A5EB0, &D_800A5EBC, &D_800A5EC8, &D_800A5ED4,
      &D_800A5EE0, &D_800A5EEC, &D_800A5EF8, &D_800A5F04 },
};
Battle D_800A5F34 = { 0, 0, 0x60040000 };
Battle D_800A5F40 = { 0, 0, 0x60040000 };
Battle D_800A5F4C = { 0, 0, 0x60040000 };
Battle D_800A5F58 = { 0, 0, 0x60040000 };
Battle D_800A5F64 = { 0, 0, 0x60040000 };
Battle D_800A5F70 = { 0, 0, 0x60040000 };
Battle D_800A5F7C = { 0, 0, 0x60040000 };
Battle D_800A5F88 = { 0, 0, 0x60040000 };
BattleList D_800A5F94 = {
    0,
    { &D_800A5F34, &D_800A5F40, &D_800A5F4C, &D_800A5F58,
      &D_800A5F64, &D_800A5F70, &D_800A5F7C, &D_800A5F88 },
};
Battle D_800A5FB8 = { 0, 0, 0x60040000 };
Battle D_800A5FC4 = { 0, 0, 0x60040000 };
Battle D_800A5FD0 = { 0, 0, 0x60040000 };
Battle D_800A5FDC = { 0, 0, 0x60040000 };
Battle D_800A5FE8 = { 0, 0, 0x60040000 };
Battle D_800A5FF4 = { 0, 0, 0x60040000 };
Battle D_800A6000 = { 0, 0, 0x60040000 };
Battle D_800A600C = { 0, 0, 0x60040000 };
BattleList D_800A6018 = {
    0,
    { &D_800A5FB8, &D_800A5FC4, &D_800A5FD0, &D_800A5FDC,
      &D_800A5FE8, &D_800A5FF4, &D_800A6000, &D_800A600C },
};
Battle D_800A603C = { 103, 11, 0x60080000 };
Battle D_800A6048 = { 103, 11, 0x60080000 };
Battle D_800A6054 = { 103, 11, 0x60080000 };
Battle D_800A6060 = { 103, 11, 0x60080000 };
Battle D_800A606C = { 103, 11, 0x60080000 };
Battle D_800A6078 = { 103, 11, 0x60080000 };
Battle D_800A6084 = { 103, 11, 0x60080000 };
Battle D_800A6090 = { 103, 11, 0x60080000 };
BattleList D_800A609C = {
    2,
    { &D_800A603C, &D_800A6048, &D_800A6054, &D_800A6060,
      &D_800A606C, &D_800A6078, &D_800A6084, &D_800A6090 },
};
Battle D_800A60C0 = { 0, 0, 0x60040000 };
Battle D_800A60CC = { 0, 0, 0x60040000 };
Battle D_800A60D8 = { 0, 0, 0x60040000 };
Battle D_800A60E4 = { 0, 0, 0x60040000 };
Battle D_800A60F0 = { 0, 0, 0x60040000 };
Battle D_800A60FC = { 0, 0, 0x60040000 };
Battle D_800A6108 = { 0, 0, 0x60040000 };
Battle D_800A6114 = { 0, 0, 0x60040000 };
BattleList D_800A6120 = {
    0,
    { &D_800A60C0, &D_800A60CC, &D_800A60D8, &D_800A60E4,
      &D_800A60F0, &D_800A60FC, &D_800A6108, &D_800A6114 },
};
Battle D_800A6144 = { 0, 0, 0x60040000 };
Battle D_800A6150 = { 0, 0, 0x60040000 };
Battle D_800A615C = { 0, 0, 0x60040000 };
Battle D_800A6168 = { 0, 0, 0x60040000 };
Battle D_800A6174 = { 0, 0, 0x60040000 };
Battle D_800A6180 = { 0, 0, 0x60040000 };
Battle D_800A618C = { 0, 0, 0x60040000 };
Battle D_800A6198 = { 0, 0, 0x60040000 };
BattleList D_800A61A4 = {
    0,
    { &D_800A6144, &D_800A6150, &D_800A615C, &D_800A6168,
      &D_800A6174, &D_800A6180, &D_800A618C, &D_800A6198 },
};
Battle D_800A61C8 = { 0, 0, 0x60040000 };
Battle D_800A61D4 = { 0, 0, 0x60040000 };
Battle D_800A61E0 = { 0, 0, 0x60040000 };
Battle D_800A61EC = { 0, 0, 0x60040000 };
Battle D_800A61F8 = { 0, 0, 0x60040000 };
Battle D_800A6204 = { 0, 0, 0x60040000 };
Battle D_800A6210 = { 0, 0, 0x60040000 };
Battle D_800A621C = { 0, 0, 0x60040000 };
BattleList D_800A6228 = {
    0,
    { &D_800A61C8, &D_800A61D4, &D_800A61E0, &D_800A61EC,
      &D_800A61F8, &D_800A6204, &D_800A6210, &D_800A621C },
};
Battle D_800A624C = { 178, 11, 0x60080000 };
Battle D_800A6258 = { 178, 11, 0x60080000 };
Battle D_800A6264 = { 178, 11, 0x60080000 };
Battle D_800A6270 = { 178, 11, 0x60080000 };
Battle D_800A627C = { 178, 11, 0x60080000 };
Battle D_800A6288 = { 178, 11, 0x60080000 };
Battle D_800A6294 = { 178, 11, 0x60080000 };
Battle D_800A62A0 = { 178, 11, 0x60080000 };
BattleList D_800A62AC = {
    3,
    { &D_800A624C, &D_800A6258, &D_800A6264, &D_800A6270,
      &D_800A627C, &D_800A6288, &D_800A6294, &D_800A62A0 },
};
Battle D_800A62D0 = { 0, 0, 0x60040000 };
Battle D_800A62DC = { 0, 0, 0x60040000 };
Battle D_800A62E8 = { 0, 0, 0x60040000 };
Battle D_800A62F4 = { 0, 0, 0x60040000 };
Battle D_800A6300 = { 0, 0, 0x60040000 };
Battle D_800A630C = { 0, 0, 0x60040000 };
Battle D_800A6318 = { 0, 0, 0x60040000 };
Battle D_800A6324 = { 0, 0, 0x60040000 };
BattleList D_800A6330 = {
    0,
    { &D_800A62D0, &D_800A62DC, &D_800A62E8, &D_800A62F4,
      &D_800A6300, &D_800A630C, &D_800A6318, &D_800A6324 },
};
Battle D_800A6354 = { 0, 0, 0x60040000 };
Battle D_800A6360 = { 0, 0, 0x60040000 };
Battle D_800A636C = { 0, 0, 0x60040000 };
Battle D_800A6378 = { 0, 0, 0x60040000 };
Battle D_800A6384 = { 0, 0, 0x60040000 };
Battle D_800A6390 = { 0, 0, 0x60040000 };
Battle D_800A639C = { 0, 0, 0x60040000 };
Battle D_800A63A8 = { 0, 0, 0x60040000 };
BattleList D_800A63B4 = {
    0,
    { &D_800A6354, &D_800A6360, &D_800A636C, &D_800A6378,
      &D_800A6384, &D_800A6390, &D_800A639C, &D_800A63A8 },
};
Battle D_800A63D8 = { 0, 0, 0x60040000 };
Battle D_800A63E4 = { 0, 0, 0x60040000 };
Battle D_800A63F0 = { 0, 0, 0x60040000 };
Battle D_800A63FC = { 0, 0, 0x60040000 };
Battle D_800A6408 = { 0, 0, 0x60040000 };
Battle D_800A6414 = { 0, 0, 0x60040000 };
Battle D_800A6420 = { 0, 0, 0x60040000 };
Battle D_800A642C = { 0, 0, 0x60040000 };
BattleList D_800A6438 = {
    0,
    { &D_800A63D8, &D_800A63E4, &D_800A63F0, &D_800A63FC,
      &D_800A6408, &D_800A6414, &D_800A6420, &D_800A642C },
};
Battle D_800A645C = { 103, 11, 0x60080000 };
Battle D_800A6468 = { 103, 11, 0x60080000 };
Battle D_800A6474 = { 103, 11, 0x60080000 };
Battle D_800A6480 = { 103, 11, 0x60080000 };
Battle D_800A648C = { 103, 11, 0x60080000 };
Battle D_800A6498 = { 103, 11, 0x60080000 };
Battle D_800A64A4 = { 103, 11, 0x60080000 };
Battle D_800A64B0 = { 103, 11, 0x60080000 };
BattleList D_800A64BC = {
    2,
    { &D_800A645C, &D_800A6468, &D_800A6474, &D_800A6480,
      &D_800A648C, &D_800A6498, &D_800A64A4, &D_800A64B0 },
};
Battle D_800A64E0 = { 0, 0, 0x60040000 };
Battle D_800A64EC = { 0, 0, 0x60040000 };
Battle D_800A64F8 = { 0, 0, 0x60040000 };
Battle D_800A6504 = { 0, 0, 0x60040000 };
Battle D_800A6510 = { 0, 0, 0x60040000 };
Battle D_800A651C = { 0, 0, 0x60040000 };
Battle D_800A6528 = { 0, 0, 0x60040000 };
Battle D_800A6534 = { 0, 0, 0x60040000 };
BattleList D_800A6540 = {
    0,
    { &D_800A64E0, &D_800A64EC, &D_800A64F8, &D_800A6504,
      &D_800A6510, &D_800A651C, &D_800A6528, &D_800A6534 },
};
Battle D_800A6564 = { 0, 0, 0x60040000 };
Battle D_800A6570 = { 0, 0, 0x60040000 };
Battle D_800A657C = { 0, 0, 0x60040000 };
Battle D_800A6588 = { 0, 0, 0x60040000 };
Battle D_800A6594 = { 0, 0, 0x60040000 };
Battle D_800A65A0 = { 0, 0, 0x60040000 };
Battle D_800A65AC = { 0, 0, 0x60040000 };
Battle D_800A65B8 = { 0, 0, 0x60040000 };
BattleList D_800A65C4 = {
    0,
    { &D_800A6564, &D_800A6570, &D_800A657C, &D_800A6588,
      &D_800A6594, &D_800A65A0, &D_800A65AC, &D_800A65B8 },
};
Battle D_800A65E8 = { 0, 0, 0x60040000 };
Battle D_800A65F4 = { 0, 0, 0x60040000 };
Battle D_800A6600 = { 0, 0, 0x60040000 };
Battle D_800A660C = { 0, 0, 0x60040000 };
Battle D_800A6618 = { 0, 0, 0x60040000 };
Battle D_800A6624 = { 0, 0, 0x60040000 };
Battle D_800A6630 = { 0, 0, 0x60040000 };
Battle D_800A663C = { 0, 0, 0x60040000 };
BattleList D_800A6648 = {
    0,
    { &D_800A65E8, &D_800A65F4, &D_800A6600, &D_800A660C,
      &D_800A6618, &D_800A6624, &D_800A6630, &D_800A663C },
};
Battle D_800A666C = { 64, 11, 0x60080000 };
Battle D_800A6678 = { 64, 11, 0x60080000 };
Battle D_800A6684 = { 64, 11, 0x60080000 };
Battle D_800A6690 = { 64, 11, 0x60080000 };
Battle D_800A669C = { 64, 11, 0x60080000 };
Battle D_800A66A8 = { 64, 11, 0x60080000 };
Battle D_800A66B4 = { 64, 11, 0x60080000 };
Battle D_800A66C0 = { 64, 11, 0x60080000 };
BattleList D_800A66CC = {
    4,
    { &D_800A666C, &D_800A6678, &D_800A6684, &D_800A6690,
      &D_800A669C, &D_800A66A8, &D_800A66B4, &D_800A66C0 },
};
Battle D_800A66F0 = { 0, 0, 0x60040000 };
Battle D_800A66FC = { 0, 0, 0x60040000 };
Battle D_800A6708 = { 0, 0, 0x60040000 };
Battle D_800A6714 = { 0, 0, 0x60040000 };
Battle D_800A6720 = { 0, 0, 0x60040000 };
Battle D_800A672C = { 0, 0, 0x60040000 };
Battle D_800A6738 = { 0, 0, 0x60040000 };
Battle D_800A6744 = { 0, 0, 0x60040000 };
BattleList D_800A6750 = {
    0,
    { &D_800A66F0, &D_800A66FC, &D_800A6708, &D_800A6714,
      &D_800A6720, &D_800A672C, &D_800A6738, &D_800A6744 },
};
Battle D_800A6774 = { 0, 0, 0x60040000 };
Battle D_800A6780 = { 0, 0, 0x60040000 };
Battle D_800A678C = { 0, 0, 0x60040000 };
Battle D_800A6798 = { 0, 0, 0x60040000 };
Battle D_800A67A4 = { 0, 0, 0x60040000 };
Battle D_800A67B0 = { 0, 0, 0x60040000 };
Battle D_800A67BC = { 0, 0, 0x60040000 };
Battle D_800A67C8 = { 0, 0, 0x60040000 };
BattleList D_800A67D4 = {
    0,
    { &D_800A6774, &D_800A6780, &D_800A678C, &D_800A6798,
      &D_800A67A4, &D_800A67B0, &D_800A67BC, &D_800A67C8 },
};
Battle D_800A67F8 = { 0, 0, 0x60040000 };
Battle D_800A6804 = { 0, 0, 0x60040000 };
Battle D_800A6810 = { 0, 0, 0x60040000 };
Battle D_800A681C = { 0, 0, 0x60040000 };
Battle D_800A6828 = { 0, 0, 0x60040000 };
Battle D_800A6834 = { 0, 0, 0x60040000 };
Battle D_800A6840 = { 0, 0, 0x60040000 };
Battle D_800A684C = { 0, 0, 0x60040000 };
BattleList D_800A6858 = {
    0,
    { &D_800A67F8, &D_800A6804, &D_800A6810, &D_800A681C,
      &D_800A6828, &D_800A6834, &D_800A6840, &D_800A684C },
};
Battle D_800A687C = { 104, 11, 0x60080000 };
Battle D_800A6888 = { 104, 11, 0x60080000 };
Battle D_800A6894 = { 104, 11, 0x60080000 };
Battle D_800A68A0 = { 104, 11, 0x60080000 };
Battle D_800A68AC = { 104, 11, 0x60080000 };
Battle D_800A68B8 = { 104, 11, 0x60080000 };
Battle D_800A68C4 = { 104, 11, 0x60080000 };
Battle D_800A68D0 = { 104, 11, 0x60080000 };
BattleList D_800A68DC = {
    3,
    { &D_800A687C, &D_800A6888, &D_800A6894, &D_800A68A0,
      &D_800A68AC, &D_800A68B8, &D_800A68C4, &D_800A68D0 },
};
Battle D_800A6900 = { 0, 0, 0x60040000 };
Battle D_800A690C = { 0, 0, 0x60040000 };
Battle D_800A6918 = { 0, 0, 0x60040000 };
Battle D_800A6924 = { 0, 0, 0x60040000 };
Battle D_800A6930 = { 0, 0, 0x60040000 };
Battle D_800A693C = { 0, 0, 0x60040000 };
Battle D_800A6948 = { 0, 0, 0x60040000 };
Battle D_800A6954 = { 0, 0, 0x60040000 };
BattleList D_800A6960 = {
    0,
    { &D_800A6900, &D_800A690C, &D_800A6918, &D_800A6924,
      &D_800A6930, &D_800A693C, &D_800A6948, &D_800A6954 },
};
Battle D_800A6984 = { 0, 0, 0x60040000 };
Battle D_800A6990 = { 0, 0, 0x60040000 };
Battle D_800A699C = { 0, 0, 0x60040000 };
Battle D_800A69A8 = { 0, 0, 0x60040000 };
Battle D_800A69B4 = { 0, 0, 0x60040000 };
Battle D_800A69C0 = { 0, 0, 0x60040000 };
Battle D_800A69CC = { 0, 0, 0x60040000 };
Battle D_800A69D8 = { 0, 0, 0x60040000 };
BattleList D_800A69E4 = {
    0,
    { &D_800A6984, &D_800A6990, &D_800A699C, &D_800A69A8,
      &D_800A69B4, &D_800A69C0, &D_800A69CC, &D_800A69D8 },
};
Battle D_800A6A08 = { 0, 0, 0x60040000 };
Battle D_800A6A14 = { 0, 0, 0x60040000 };
Battle D_800A6A20 = { 0, 0, 0x60040000 };
Battle D_800A6A2C = { 0, 0, 0x60040000 };
Battle D_800A6A38 = { 0, 0, 0x60040000 };
Battle D_800A6A44 = { 0, 0, 0x60040000 };
Battle D_800A6A50 = { 0, 0, 0x60040000 };
Battle D_800A6A5C = { 0, 0, 0x60040000 };
BattleList D_800A6A68 = {
    0,
    { &D_800A6A08, &D_800A6A14, &D_800A6A20, &D_800A6A2C,
      &D_800A6A38, &D_800A6A44, &D_800A6A50, &D_800A6A5C },
};
FieldBattles stageBattles[] = {
    { 182, 3, 0, { &D_800A522C, &D_800A52B0, &D_800A5334, &D_800A53B8 } },
    { 186, 4, 0, { &D_800A543C, &D_800A54C0, &D_800A5544, &D_800A55C8 } },
    { 190, 5, 0, { &D_800A564C, &D_800A56D0, &D_800A5754, &D_800A57D8 } },
    { 195, 7, 0, { &D_800A585C, &D_800A58E0, &D_800A5964, &D_800A59E8 } },
    { 197, 8, 0, { &D_800A5A6C, &D_800A5AF0, &D_800A5B74, &D_800A5BF8 } },
    { 200, 9, 0, { &D_800A5C7C, &D_800A5D00, &D_800A5D84, &D_800A5E08 } },
    { 210, 13, 0, { &D_800A5E8C, &D_800A5F10, &D_800A5F94, &D_800A6018 } },
    { 214, 14, 0, { &D_800A609C, &D_800A6120, &D_800A61A4, &D_800A6228 } },
    { 218, 15, 0, { &D_800A62AC, &D_800A6330, &D_800A63B4, &D_800A6438 } },
    { 223, 17, 0, { &D_800A64BC, &D_800A6540, &D_800A65C4, &D_800A6648 } },
    { 225, 18, 0, { &D_800A66CC, &D_800A6750, &D_800A67D4, &D_800A6858 } },
    { 228, 19, 0, { &D_800A68DC, &D_800A6960, &D_800A69E4, &D_800A6A68 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x152, 0x198, 0x48, 0x98, 0x160, 0x1FF },
};
FieldActorEntry D_800A6C4C = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A6C4C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 254, 275, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 621, 244, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 852, 128, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 384, 171, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 689, 166, 0, 0 },
    { 1, 0, 0xFF, 2, 0x33, 2, 0, 7, 0x18, 0, 140, -36, 0, 0 },
    { 1, 0, 0x98, 2, 5, 0, 0, 0, 0, 0, 432, 254, 0, 0 },
    { 1, 0, 0x8A, 2, 6, 0, 0, 0, 0, 0, 408, 268, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 475, 113, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 169, 206, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 750, 142, 0, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 140, 92, 336, 0 },
    { 1, 0, 0x92, 4, 1, 0, 0, 0, 0, 0, 560, 179, 319, 0 },
    { 1, 0, 0x79, 4, 2, 0, 0, 0, 0, 0, 528, 198, 335, 0 },
    { 1, 0, 0x88, 4, 3, 0, 0, 0, 0, 0, 496, 216, 351, 0 },
    { 1, 0, 0x86, 4, 4, 0, 0, 0, 0, 0, 464, 232, 368, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E2, 0xB0, 0x148, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E2, 0x330, 0xF8, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
