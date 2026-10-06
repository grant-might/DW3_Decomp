#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places_last.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x690
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x6A0
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x9D00, 0x17F00};
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
extern StagePoints D_800A4FCC;
extern StagePoints D_800A4FF4;
extern StagePoints D_800A501C;
extern StagePoints D_800A5044;
extern StagePoints D_800A506C;
extern StagePoints D_800A5094;
extern StagePoints D_800A50BC;
extern StagePoints D_800A50E4;
extern StagePoints D_800A50EC;
extern Battle D_800A511C;
extern Battle D_800A5128;
extern Battle D_800A5134;
extern Battle D_800A5140;
extern Battle D_800A514C;
extern Battle D_800A5158;
extern Battle D_800A5164;
extern Battle D_800A5170;
extern Battle D_800A51A0;
extern Battle D_800A51AC;
extern Battle D_800A51B8;
extern Battle D_800A51C4;
extern Battle D_800A51D0;
extern Battle D_800A51DC;
extern Battle D_800A51E8;
extern Battle D_800A51F4;
extern Battle D_800A5224;
extern Battle D_800A5230;
extern Battle D_800A523C;
extern Battle D_800A5248;
extern Battle D_800A5254;
extern Battle D_800A5260;
extern Battle D_800A526C;
extern Battle D_800A5278;
extern Battle D_800A52A8;
extern Battle D_800A52B4;
extern Battle D_800A52C0;
extern Battle D_800A52CC;
extern Battle D_800A52D8;
extern Battle D_800A52E4;
extern Battle D_800A52F0;
extern Battle D_800A52FC;
extern Battle D_800A532C;
extern Battle D_800A5338;
extern Battle D_800A5344;
extern Battle D_800A5350;
extern Battle D_800A535C;
extern Battle D_800A5368;
extern Battle D_800A5374;
extern Battle D_800A5380;
extern Battle D_800A53B0;
extern Battle D_800A53BC;
extern Battle D_800A53C8;
extern Battle D_800A53D4;
extern Battle D_800A53E0;
extern Battle D_800A53EC;
extern Battle D_800A53F8;
extern Battle D_800A5404;
extern Battle D_800A5434;
extern Battle D_800A5440;
extern Battle D_800A544C;
extern Battle D_800A5458;
extern Battle D_800A5464;
extern Battle D_800A5470;
extern Battle D_800A547C;
extern Battle D_800A5488;
extern Battle D_800A54B8;
extern Battle D_800A54C4;
extern Battle D_800A54D0;
extern Battle D_800A54DC;
extern Battle D_800A54E8;
extern Battle D_800A54F4;
extern Battle D_800A5500;
extern Battle D_800A550C;
extern Battle D_800A553C;
extern Battle D_800A5548;
extern Battle D_800A5554;
extern Battle D_800A5560;
extern Battle D_800A556C;
extern Battle D_800A5578;
extern Battle D_800A5584;
extern Battle D_800A5590;
extern Battle D_800A55C0;
extern Battle D_800A55CC;
extern Battle D_800A55D8;
extern Battle D_800A55E4;
extern Battle D_800A55F0;
extern Battle D_800A55FC;
extern Battle D_800A5608;
extern Battle D_800A5614;
extern Battle D_800A5644;
extern Battle D_800A5650;
extern Battle D_800A565C;
extern Battle D_800A5668;
extern Battle D_800A5674;
extern Battle D_800A5680;
extern Battle D_800A568C;
extern Battle D_800A5698;
extern Battle D_800A56C8;
extern Battle D_800A56D4;
extern Battle D_800A56E0;
extern Battle D_800A56EC;
extern Battle D_800A56F8;
extern Battle D_800A5704;
extern Battle D_800A5710;
extern Battle D_800A571C;
extern Battle D_800A574C;
extern Battle D_800A5758;
extern Battle D_800A5764;
extern Battle D_800A5770;
extern Battle D_800A577C;
extern Battle D_800A5788;
extern Battle D_800A5794;
extern Battle D_800A57A0;
extern Battle D_800A57D0;
extern Battle D_800A57DC;
extern Battle D_800A57E8;
extern Battle D_800A57F4;
extern Battle D_800A5800;
extern Battle D_800A580C;
extern Battle D_800A5818;
extern Battle D_800A5824;
extern Battle D_800A5854;
extern Battle D_800A5860;
extern Battle D_800A586C;
extern Battle D_800A5878;
extern Battle D_800A5884;
extern Battle D_800A5890;
extern Battle D_800A589C;
extern Battle D_800A58A8;
extern Battle D_800A58D8;
extern Battle D_800A58E4;
extern Battle D_800A58F0;
extern Battle D_800A58FC;
extern Battle D_800A5908;
extern Battle D_800A5914;
extern Battle D_800A5920;
extern Battle D_800A592C;
extern Battle D_800A595C;
extern Battle D_800A5968;
extern Battle D_800A5974;
extern Battle D_800A5980;
extern Battle D_800A598C;
extern Battle D_800A5998;
extern Battle D_800A59A4;
extern Battle D_800A59B0;
extern Battle D_800A59E0;
extern Battle D_800A59EC;
extern Battle D_800A59F8;
extern Battle D_800A5A04;
extern Battle D_800A5A10;
extern Battle D_800A5A1C;
extern Battle D_800A5A28;
extern Battle D_800A5A34;
extern Battle D_800A5A64;
extern Battle D_800A5A70;
extern Battle D_800A5A7C;
extern Battle D_800A5A88;
extern Battle D_800A5A94;
extern Battle D_800A5AA0;
extern Battle D_800A5AAC;
extern Battle D_800A5AB8;
extern Battle D_800A5AE8;
extern Battle D_800A5AF4;
extern Battle D_800A5B00;
extern Battle D_800A5B0C;
extern Battle D_800A5B18;
extern Battle D_800A5B24;
extern Battle D_800A5B30;
extern Battle D_800A5B3C;
extern Battle D_800A5B6C;
extern Battle D_800A5B78;
extern Battle D_800A5B84;
extern Battle D_800A5B90;
extern Battle D_800A5B9C;
extern Battle D_800A5BA8;
extern Battle D_800A5BB4;
extern Battle D_800A5BC0;
extern Battle D_800A5BF0;
extern Battle D_800A5BFC;
extern Battle D_800A5C08;
extern Battle D_800A5C14;
extern Battle D_800A5C20;
extern Battle D_800A5C2C;
extern Battle D_800A5C38;
extern Battle D_800A5C44;
extern Battle D_800A5C74;
extern Battle D_800A5C80;
extern Battle D_800A5C8C;
extern Battle D_800A5C98;
extern Battle D_800A5CA4;
extern Battle D_800A5CB0;
extern Battle D_800A5CBC;
extern Battle D_800A5CC8;
extern Battle D_800A5CF8;
extern Battle D_800A5D04;
extern Battle D_800A5D10;
extern Battle D_800A5D1C;
extern Battle D_800A5D28;
extern Battle D_800A5D34;
extern Battle D_800A5D40;
extern Battle D_800A5D4C;
extern Battle D_800A5D7C;
extern Battle D_800A5D88;
extern Battle D_800A5D94;
extern Battle D_800A5DA0;
extern Battle D_800A5DAC;
extern Battle D_800A5DB8;
extern Battle D_800A5DC4;
extern Battle D_800A5DD0;
extern Battle D_800A5E00;
extern Battle D_800A5E0C;
extern Battle D_800A5E18;
extern Battle D_800A5E24;
extern Battle D_800A5E30;
extern Battle D_800A5E3C;
extern Battle D_800A5E48;
extern Battle D_800A5E54;
extern Battle D_800A5E84;
extern Battle D_800A5E90;
extern Battle D_800A5E9C;
extern Battle D_800A5EA8;
extern Battle D_800A5EB4;
extern Battle D_800A5EC0;
extern Battle D_800A5ECC;
extern Battle D_800A5ED8;
extern Battle D_800A5F08;
extern Battle D_800A5F14;
extern Battle D_800A5F20;
extern Battle D_800A5F2C;
extern Battle D_800A5F38;
extern Battle D_800A5F44;
extern Battle D_800A5F50;
extern Battle D_800A5F5C;
extern Battle D_800A5F8C;
extern Battle D_800A5F98;
extern Battle D_800A5FA4;
extern Battle D_800A5FB0;
extern Battle D_800A5FBC;
extern Battle D_800A5FC8;
extern Battle D_800A5FD4;
extern Battle D_800A5FE0;
extern Battle D_800A6010;
extern Battle D_800A601C;
extern Battle D_800A6028;
extern Battle D_800A6034;
extern Battle D_800A6040;
extern Battle D_800A604C;
extern Battle D_800A6058;
extern Battle D_800A6064;
extern Battle D_800A6094;
extern Battle D_800A60A0;
extern Battle D_800A60AC;
extern Battle D_800A60B8;
extern Battle D_800A60C4;
extern Battle D_800A60D0;
extern Battle D_800A60DC;
extern Battle D_800A60E8;
extern Battle D_800A6118;
extern Battle D_800A6124;
extern Battle D_800A6130;
extern Battle D_800A613C;
extern Battle D_800A6148;
extern Battle D_800A6154;
extern Battle D_800A6160;
extern Battle D_800A616C;
extern BattleList D_800A517C;
extern BattleList D_800A5200;
extern BattleList D_800A5284;
extern BattleList D_800A5308;
extern BattleList D_800A538C;
extern BattleList D_800A5410;
extern BattleList D_800A5494;
extern BattleList D_800A5518;
extern BattleList D_800A559C;
extern BattleList D_800A5620;
extern BattleList D_800A56A4;
extern BattleList D_800A5728;
extern BattleList D_800A57AC;
extern BattleList D_800A5830;
extern BattleList D_800A58B4;
extern BattleList D_800A5938;
extern BattleList D_800A59BC;
extern BattleList D_800A5A40;
extern BattleList D_800A5AC4;
extern BattleList D_800A5B48;
extern BattleList D_800A5BCC;
extern BattleList D_800A5C50;
extern BattleList D_800A5CD4;
extern BattleList D_800A5D58;
extern BattleList D_800A5DDC;
extern BattleList D_800A5E60;
extern BattleList D_800A5EE4;
extern BattleList D_800A5F68;
extern BattleList D_800A5FEC;
extern BattleList D_800A6070;
extern BattleList D_800A60F4;
extern BattleList D_800A6178;
extern FieldActorEntry D_800A62EC;

StagePoint D_800A4FAC = { 0x2E6, 1, 1, 0x450, 0x248, 1, NULL };
StagePoint D_800A4FBC = { 0x22A, 0, 0, 0x32C, 0x232, 0, &D_800A4FAC };
StagePoints D_800A4FCC = { 1, 1, &D_800A4FBC };
StagePoint D_800A4FD4 = { 0x2E1, 2, 1, 0x390, 0x108, 1, NULL };
StagePoint D_800A4FE4 = { 0x21B, 0, 0, 128, 0x1E0, 0, &D_800A4FD4 };
StagePoints D_800A4FF4 = { 2, 1, &D_800A4FE4 };
StagePoint D_800A4FFC = { 0x2E2, 7, 1, 0x330, 248, 1, NULL };
StagePoint D_800A500C = { 0x241, 0, 0, 208, 0x400, 0, &D_800A4FFC };
StagePoints D_800A501C = { 7, 1, &D_800A500C };
StagePoint D_800A5024 = { 0x2E2, 8, 1, 0x330, 248, 1, NULL };
StagePoint D_800A5034 = { 0x228, 0, 0, 0x210, 0x370, 0, &D_800A5024 };
StagePoints D_800A5044 = { 8, 1, &D_800A5034 };
StagePoint D_800A504C = { 0x2E6, 11, 1, 0x450, 0x248, 1, NULL };
StagePoint D_800A505C = { 0x299, 0, 0, 0x32C, 0x232, 0, &D_800A504C };
StagePoints D_800A506C = { 11, 1, &D_800A505C };
StagePoint D_800A5074 = { 0x2E1, 12, 1, 0x390, 0x108, 1, NULL };
StagePoint D_800A5084 = { 0x28A, 0, 0, 128, 0x1E0, 0, &D_800A5074 };
StagePoints D_800A5094 = { 12, 1, &D_800A5084 };
StagePoint D_800A509C = { 0x2E2, 17, 1, 0x330, 248, 1, NULL };
StagePoint D_800A50AC = { 0x2AE, 0, 0, 208, 0x400, 0, &D_800A509C };
StagePoints D_800A50BC = { 17, 1, &D_800A50AC };
StagePoint D_800A50C4 = { 0x2E2, 18, 1, 0x330, 248, 1, NULL };
StagePoint D_800A50D4 = { 0x297, 0, 0, 0x210, 0x370, 0, &D_800A50C4 };
StagePoints D_800A50E4 = { 18, 1, &D_800A50D4 };
StagePoints D_800A50EC = { 0, 0, &D_800A4FBC };
StagePoints *placePoints[] = {
    &D_800A4FCC, &D_800A4FF4, &D_800A501C, &D_800A5044,
    &D_800A506C, &D_800A5094, &D_800A50BC, &D_800A50E4,
    &D_800A50EC, NULL,
};
Battle D_800A511C = { 61, 11, 0x60080000 };
Battle D_800A5128 = { 61, 11, 0x60080000 };
Battle D_800A5134 = { 61, 11, 0x60080000 };
Battle D_800A5140 = { 61, 11, 0x60080000 };
Battle D_800A514C = { 62, 11, 0x60080000 };
Battle D_800A5158 = { 62, 11, 0x60080000 };
Battle D_800A5164 = { 62, 11, 0x60080000 };
Battle D_800A5170 = { 62, 11, 0x60080000 };
BattleList D_800A517C = {
    2,
    { &D_800A511C, &D_800A5128, &D_800A5134, &D_800A5140,
      &D_800A514C, &D_800A5158, &D_800A5164, &D_800A5170 },
};
Battle D_800A51A0 = { 0, 0, 0x60040000 };
Battle D_800A51AC = { 0, 0, 0x60040000 };
Battle D_800A51B8 = { 0, 0, 0x60040000 };
Battle D_800A51C4 = { 0, 0, 0x60040000 };
Battle D_800A51D0 = { 0, 0, 0x60040000 };
Battle D_800A51DC = { 0, 0, 0x60040000 };
Battle D_800A51E8 = { 0, 0, 0x60040000 };
Battle D_800A51F4 = { 0, 0, 0x60040000 };
BattleList D_800A5200 = {
    0,
    { &D_800A51A0, &D_800A51AC, &D_800A51B8, &D_800A51C4,
      &D_800A51D0, &D_800A51DC, &D_800A51E8, &D_800A51F4 },
};
Battle D_800A5224 = { 0, 0, 0x60040000 };
Battle D_800A5230 = { 0, 0, 0x60040000 };
Battle D_800A523C = { 0, 0, 0x60040000 };
Battle D_800A5248 = { 0, 0, 0x60040000 };
Battle D_800A5254 = { 0, 0, 0x60040000 };
Battle D_800A5260 = { 0, 0, 0x60040000 };
Battle D_800A526C = { 0, 0, 0x60040000 };
Battle D_800A5278 = { 0, 0, 0x60040000 };
BattleList D_800A5284 = {
    0,
    { &D_800A5224, &D_800A5230, &D_800A523C, &D_800A5248,
      &D_800A5254, &D_800A5260, &D_800A526C, &D_800A5278 },
};
Battle D_800A52A8 = { 0, 0, 0x60040000 };
Battle D_800A52B4 = { 0, 0, 0x60040000 };
Battle D_800A52C0 = { 0, 0, 0x60040000 };
Battle D_800A52CC = { 0, 0, 0x60040000 };
Battle D_800A52D8 = { 0, 0, 0x60040000 };
Battle D_800A52E4 = { 0, 0, 0x60040000 };
Battle D_800A52F0 = { 0, 0, 0x60040000 };
Battle D_800A52FC = { 0, 0, 0x60040000 };
BattleList D_800A5308 = {
    0,
    { &D_800A52A8, &D_800A52B4, &D_800A52C0, &D_800A52CC,
      &D_800A52D8, &D_800A52E4, &D_800A52F0, &D_800A52FC },
};
Battle D_800A532C = { 62, 11, 0x60080000 };
Battle D_800A5338 = { 62, 11, 0x60080000 };
Battle D_800A5344 = { 62, 11, 0x60080000 };
Battle D_800A5350 = { 62, 11, 0x60080000 };
Battle D_800A535C = { 62, 11, 0x60080000 };
Battle D_800A5368 = { 62, 11, 0x60080000 };
Battle D_800A5374 = { 62, 11, 0x60080000 };
Battle D_800A5380 = { 62, 11, 0x60080000 };
BattleList D_800A538C = {
    4,
    { &D_800A532C, &D_800A5338, &D_800A5344, &D_800A5350,
      &D_800A535C, &D_800A5368, &D_800A5374, &D_800A5380 },
};
Battle D_800A53B0 = { 0, 0, 0x60040000 };
Battle D_800A53BC = { 0, 0, 0x60040000 };
Battle D_800A53C8 = { 0, 0, 0x60040000 };
Battle D_800A53D4 = { 0, 0, 0x60040000 };
Battle D_800A53E0 = { 0, 0, 0x60040000 };
Battle D_800A53EC = { 0, 0, 0x60040000 };
Battle D_800A53F8 = { 0, 0, 0x60040000 };
Battle D_800A5404 = { 0, 0, 0x60040000 };
BattleList D_800A5410 = {
    0,
    { &D_800A53B0, &D_800A53BC, &D_800A53C8, &D_800A53D4,
      &D_800A53E0, &D_800A53EC, &D_800A53F8, &D_800A5404 },
};
Battle D_800A5434 = { 0, 0, 0x60040000 };
Battle D_800A5440 = { 0, 0, 0x60040000 };
Battle D_800A544C = { 0, 0, 0x60040000 };
Battle D_800A5458 = { 0, 0, 0x60040000 };
Battle D_800A5464 = { 0, 0, 0x60040000 };
Battle D_800A5470 = { 0, 0, 0x60040000 };
Battle D_800A547C = { 0, 0, 0x60040000 };
Battle D_800A5488 = { 0, 0, 0x60040000 };
BattleList D_800A5494 = {
    0,
    { &D_800A5434, &D_800A5440, &D_800A544C, &D_800A5458,
      &D_800A5464, &D_800A5470, &D_800A547C, &D_800A5488 },
};
Battle D_800A54B8 = { 0, 0, 0x60040000 };
Battle D_800A54C4 = { 0, 0, 0x60040000 };
Battle D_800A54D0 = { 0, 0, 0x60040000 };
Battle D_800A54DC = { 0, 0, 0x60040000 };
Battle D_800A54E8 = { 0, 0, 0x60040000 };
Battle D_800A54F4 = { 0, 0, 0x60040000 };
Battle D_800A5500 = { 0, 0, 0x60040000 };
Battle D_800A550C = { 0, 0, 0x60040000 };
BattleList D_800A5518 = {
    0,
    { &D_800A54B8, &D_800A54C4, &D_800A54D0, &D_800A54DC,
      &D_800A54E8, &D_800A54F4, &D_800A5500, &D_800A550C },
};
Battle D_800A553C = { 61, 11, 0x60080000 };
Battle D_800A5548 = { 61, 11, 0x60080000 };
Battle D_800A5554 = { 61, 11, 0x60080000 };
Battle D_800A5560 = { 61, 11, 0x60080000 };
Battle D_800A556C = { 61, 11, 0x60080000 };
Battle D_800A5578 = { 61, 11, 0x60080000 };
Battle D_800A5584 = { 61, 11, 0x60080000 };
Battle D_800A5590 = { 61, 11, 0x60080000 };
BattleList D_800A559C = {
    4,
    { &D_800A553C, &D_800A5548, &D_800A5554, &D_800A5560,
      &D_800A556C, &D_800A5578, &D_800A5584, &D_800A5590 },
};
Battle D_800A55C0 = { 0, 0, 0x60040000 };
Battle D_800A55CC = { 0, 0, 0x60040000 };
Battle D_800A55D8 = { 0, 0, 0x60040000 };
Battle D_800A55E4 = { 0, 0, 0x60040000 };
Battle D_800A55F0 = { 0, 0, 0x60040000 };
Battle D_800A55FC = { 0, 0, 0x60040000 };
Battle D_800A5608 = { 0, 0, 0x60040000 };
Battle D_800A5614 = { 0, 0, 0x60040000 };
BattleList D_800A5620 = {
    0,
    { &D_800A55C0, &D_800A55CC, &D_800A55D8, &D_800A55E4,
      &D_800A55F0, &D_800A55FC, &D_800A5608, &D_800A5614 },
};
Battle D_800A5644 = { 0, 0, 0x60040000 };
Battle D_800A5650 = { 0, 0, 0x60040000 };
Battle D_800A565C = { 0, 0, 0x60040000 };
Battle D_800A5668 = { 0, 0, 0x60040000 };
Battle D_800A5674 = { 0, 0, 0x60040000 };
Battle D_800A5680 = { 0, 0, 0x60040000 };
Battle D_800A568C = { 0, 0, 0x60040000 };
Battle D_800A5698 = { 0, 0, 0x60040000 };
BattleList D_800A56A4 = {
    0,
    { &D_800A5644, &D_800A5650, &D_800A565C, &D_800A5668,
      &D_800A5674, &D_800A5680, &D_800A568C, &D_800A5698 },
};
Battle D_800A56C8 = { 0, 0, 0x60040000 };
Battle D_800A56D4 = { 0, 0, 0x60040000 };
Battle D_800A56E0 = { 0, 0, 0x60040000 };
Battle D_800A56EC = { 0, 0, 0x60040000 };
Battle D_800A56F8 = { 0, 0, 0x60040000 };
Battle D_800A5704 = { 0, 0, 0x60040000 };
Battle D_800A5710 = { 0, 0, 0x60040000 };
Battle D_800A571C = { 0, 0, 0x60040000 };
BattleList D_800A5728 = {
    0,
    { &D_800A56C8, &D_800A56D4, &D_800A56E0, &D_800A56EC,
      &D_800A56F8, &D_800A5704, &D_800A5710, &D_800A571C },
};
Battle D_800A574C = { 64, 11, 0x60080000 };
Battle D_800A5758 = { 64, 11, 0x60080000 };
Battle D_800A5764 = { 64, 11, 0x60080000 };
Battle D_800A5770 = { 64, 11, 0x60080000 };
Battle D_800A577C = { 64, 11, 0x60080000 };
Battle D_800A5788 = { 64, 11, 0x60080000 };
Battle D_800A5794 = { 64, 11, 0x60080000 };
Battle D_800A57A0 = { 64, 11, 0x60080000 };
BattleList D_800A57AC = {
    4,
    { &D_800A574C, &D_800A5758, &D_800A5764, &D_800A5770,
      &D_800A577C, &D_800A5788, &D_800A5794, &D_800A57A0 },
};
Battle D_800A57D0 = { 0, 0, 0x60040000 };
Battle D_800A57DC = { 0, 0, 0x60040000 };
Battle D_800A57E8 = { 0, 0, 0x60040000 };
Battle D_800A57F4 = { 0, 0, 0x60040000 };
Battle D_800A5800 = { 0, 0, 0x60040000 };
Battle D_800A580C = { 0, 0, 0x60040000 };
Battle D_800A5818 = { 0, 0, 0x60040000 };
Battle D_800A5824 = { 0, 0, 0x60040000 };
BattleList D_800A5830 = {
    0,
    { &D_800A57D0, &D_800A57DC, &D_800A57E8, &D_800A57F4,
      &D_800A5800, &D_800A580C, &D_800A5818, &D_800A5824 },
};
Battle D_800A5854 = { 0, 0, 0x60040000 };
Battle D_800A5860 = { 0, 0, 0x60040000 };
Battle D_800A586C = { 0, 0, 0x60040000 };
Battle D_800A5878 = { 0, 0, 0x60040000 };
Battle D_800A5884 = { 0, 0, 0x60040000 };
Battle D_800A5890 = { 0, 0, 0x60040000 };
Battle D_800A589C = { 0, 0, 0x60040000 };
Battle D_800A58A8 = { 0, 0, 0x60040000 };
BattleList D_800A58B4 = {
    0,
    { &D_800A5854, &D_800A5860, &D_800A586C, &D_800A5878,
      &D_800A5884, &D_800A5890, &D_800A589C, &D_800A58A8 },
};
Battle D_800A58D8 = { 0, 0, 0x60040000 };
Battle D_800A58E4 = { 0, 0, 0x60040000 };
Battle D_800A58F0 = { 0, 0, 0x60040000 };
Battle D_800A58FC = { 0, 0, 0x60040000 };
Battle D_800A5908 = { 0, 0, 0x60040000 };
Battle D_800A5914 = { 0, 0, 0x60040000 };
Battle D_800A5920 = { 0, 0, 0x60040000 };
Battle D_800A592C = { 0, 0, 0x60040000 };
BattleList D_800A5938 = {
    0,
    { &D_800A58D8, &D_800A58E4, &D_800A58F0, &D_800A58FC,
      &D_800A5908, &D_800A5914, &D_800A5920, &D_800A592C },
};
Battle D_800A595C = { 103, 11, 0x60080000 };
Battle D_800A5968 = { 103, 11, 0x60080000 };
Battle D_800A5974 = { 103, 11, 0x60080000 };
Battle D_800A5980 = { 103, 11, 0x60080000 };
Battle D_800A598C = { 103, 11, 0x60080000 };
Battle D_800A5998 = { 103, 11, 0x60080000 };
Battle D_800A59A4 = { 103, 11, 0x60080000 };
Battle D_800A59B0 = { 103, 11, 0x60080000 };
BattleList D_800A59BC = {
    2,
    { &D_800A595C, &D_800A5968, &D_800A5974, &D_800A5980,
      &D_800A598C, &D_800A5998, &D_800A59A4, &D_800A59B0 },
};
Battle D_800A59E0 = { 0, 0, 0x60040000 };
Battle D_800A59EC = { 0, 0, 0x60040000 };
Battle D_800A59F8 = { 0, 0, 0x60040000 };
Battle D_800A5A04 = { 0, 0, 0x60040000 };
Battle D_800A5A10 = { 0, 0, 0x60040000 };
Battle D_800A5A1C = { 0, 0, 0x60040000 };
Battle D_800A5A28 = { 0, 0, 0x60040000 };
Battle D_800A5A34 = { 0, 0, 0x60040000 };
BattleList D_800A5A40 = {
    0,
    { &D_800A59E0, &D_800A59EC, &D_800A59F8, &D_800A5A04,
      &D_800A5A10, &D_800A5A1C, &D_800A5A28, &D_800A5A34 },
};
Battle D_800A5A64 = { 0, 0, 0x60040000 };
Battle D_800A5A70 = { 0, 0, 0x60040000 };
Battle D_800A5A7C = { 0, 0, 0x60040000 };
Battle D_800A5A88 = { 0, 0, 0x60040000 };
Battle D_800A5A94 = { 0, 0, 0x60040000 };
Battle D_800A5AA0 = { 0, 0, 0x60040000 };
Battle D_800A5AAC = { 0, 0, 0x60040000 };
Battle D_800A5AB8 = { 0, 0, 0x60040000 };
BattleList D_800A5AC4 = {
    0,
    { &D_800A5A64, &D_800A5A70, &D_800A5A7C, &D_800A5A88,
      &D_800A5A94, &D_800A5AA0, &D_800A5AAC, &D_800A5AB8 },
};
Battle D_800A5AE8 = { 0, 0, 0x60040000 };
Battle D_800A5AF4 = { 0, 0, 0x60040000 };
Battle D_800A5B00 = { 0, 0, 0x60040000 };
Battle D_800A5B0C = { 0, 0, 0x60040000 };
Battle D_800A5B18 = { 0, 0, 0x60040000 };
Battle D_800A5B24 = { 0, 0, 0x60040000 };
Battle D_800A5B30 = { 0, 0, 0x60040000 };
Battle D_800A5B3C = { 0, 0, 0x60040000 };
BattleList D_800A5B48 = {
    0,
    { &D_800A5AE8, &D_800A5AF4, &D_800A5B00, &D_800A5B0C,
      &D_800A5B18, &D_800A5B24, &D_800A5B30, &D_800A5B3C },
};
Battle D_800A5B6C = { 178, 11, 0x60080000 };
Battle D_800A5B78 = { 178, 11, 0x60080000 };
Battle D_800A5B84 = { 178, 11, 0x60080000 };
Battle D_800A5B90 = { 178, 11, 0x60080000 };
Battle D_800A5B9C = { 178, 11, 0x60080000 };
Battle D_800A5BA8 = { 178, 11, 0x60080000 };
Battle D_800A5BB4 = { 178, 11, 0x60080000 };
Battle D_800A5BC0 = { 178, 11, 0x60080000 };
BattleList D_800A5BCC = {
    4,
    { &D_800A5B6C, &D_800A5B78, &D_800A5B84, &D_800A5B90,
      &D_800A5B9C, &D_800A5BA8, &D_800A5BB4, &D_800A5BC0 },
};
Battle D_800A5BF0 = { 0, 0, 0x60040000 };
Battle D_800A5BFC = { 0, 0, 0x60040000 };
Battle D_800A5C08 = { 0, 0, 0x60040000 };
Battle D_800A5C14 = { 0, 0, 0x60040000 };
Battle D_800A5C20 = { 0, 0, 0x60040000 };
Battle D_800A5C2C = { 0, 0, 0x60040000 };
Battle D_800A5C38 = { 0, 0, 0x60040000 };
Battle D_800A5C44 = { 0, 0, 0x60040000 };
BattleList D_800A5C50 = {
    0,
    { &D_800A5BF0, &D_800A5BFC, &D_800A5C08, &D_800A5C14,
      &D_800A5C20, &D_800A5C2C, &D_800A5C38, &D_800A5C44 },
};
Battle D_800A5C74 = { 0, 0, 0x60040000 };
Battle D_800A5C80 = { 0, 0, 0x60040000 };
Battle D_800A5C8C = { 0, 0, 0x60040000 };
Battle D_800A5C98 = { 0, 0, 0x60040000 };
Battle D_800A5CA4 = { 0, 0, 0x60040000 };
Battle D_800A5CB0 = { 0, 0, 0x60040000 };
Battle D_800A5CBC = { 0, 0, 0x60040000 };
Battle D_800A5CC8 = { 0, 0, 0x60040000 };
BattleList D_800A5CD4 = {
    0,
    { &D_800A5C74, &D_800A5C80, &D_800A5C8C, &D_800A5C98,
      &D_800A5CA4, &D_800A5CB0, &D_800A5CBC, &D_800A5CC8 },
};
Battle D_800A5CF8 = { 0, 0, 0x60040000 };
Battle D_800A5D04 = { 0, 0, 0x60040000 };
Battle D_800A5D10 = { 0, 0, 0x60040000 };
Battle D_800A5D1C = { 0, 0, 0x60040000 };
Battle D_800A5D28 = { 0, 0, 0x60040000 };
Battle D_800A5D34 = { 0, 0, 0x60040000 };
Battle D_800A5D40 = { 0, 0, 0x60040000 };
Battle D_800A5D4C = { 0, 0, 0x60040000 };
BattleList D_800A5D58 = {
    0,
    { &D_800A5CF8, &D_800A5D04, &D_800A5D10, &D_800A5D1C,
      &D_800A5D28, &D_800A5D34, &D_800A5D40, &D_800A5D4C },
};
Battle D_800A5D7C = { 103, 11, 0x60080000 };
Battle D_800A5D88 = { 103, 11, 0x60080000 };
Battle D_800A5D94 = { 103, 11, 0x60080000 };
Battle D_800A5DA0 = { 103, 11, 0x60080000 };
Battle D_800A5DAC = { 103, 11, 0x60080000 };
Battle D_800A5DB8 = { 103, 11, 0x60080000 };
Battle D_800A5DC4 = { 103, 11, 0x60080000 };
Battle D_800A5DD0 = { 103, 11, 0x60080000 };
BattleList D_800A5DDC = {
    2,
    { &D_800A5D7C, &D_800A5D88, &D_800A5D94, &D_800A5DA0,
      &D_800A5DAC, &D_800A5DB8, &D_800A5DC4, &D_800A5DD0 },
};
Battle D_800A5E00 = { 0, 0, 0x60040000 };
Battle D_800A5E0C = { 0, 0, 0x60040000 };
Battle D_800A5E18 = { 0, 0, 0x60040000 };
Battle D_800A5E24 = { 0, 0, 0x60040000 };
Battle D_800A5E30 = { 0, 0, 0x60040000 };
Battle D_800A5E3C = { 0, 0, 0x60040000 };
Battle D_800A5E48 = { 0, 0, 0x60040000 };
Battle D_800A5E54 = { 0, 0, 0x60040000 };
BattleList D_800A5E60 = {
    0,
    { &D_800A5E00, &D_800A5E0C, &D_800A5E18, &D_800A5E24,
      &D_800A5E30, &D_800A5E3C, &D_800A5E48, &D_800A5E54 },
};
Battle D_800A5E84 = { 0, 0, 0x60040000 };
Battle D_800A5E90 = { 0, 0, 0x60040000 };
Battle D_800A5E9C = { 0, 0, 0x60040000 };
Battle D_800A5EA8 = { 0, 0, 0x60040000 };
Battle D_800A5EB4 = { 0, 0, 0x60040000 };
Battle D_800A5EC0 = { 0, 0, 0x60040000 };
Battle D_800A5ECC = { 0, 0, 0x60040000 };
Battle D_800A5ED8 = { 0, 0, 0x60040000 };
BattleList D_800A5EE4 = {
    0,
    { &D_800A5E84, &D_800A5E90, &D_800A5E9C, &D_800A5EA8,
      &D_800A5EB4, &D_800A5EC0, &D_800A5ECC, &D_800A5ED8 },
};
Battle D_800A5F08 = { 0, 0, 0x60040000 };
Battle D_800A5F14 = { 0, 0, 0x60040000 };
Battle D_800A5F20 = { 0, 0, 0x60040000 };
Battle D_800A5F2C = { 0, 0, 0x60040000 };
Battle D_800A5F38 = { 0, 0, 0x60040000 };
Battle D_800A5F44 = { 0, 0, 0x60040000 };
Battle D_800A5F50 = { 0, 0, 0x60040000 };
Battle D_800A5F5C = { 0, 0, 0x60040000 };
BattleList D_800A5F68 = {
    0,
    { &D_800A5F08, &D_800A5F14, &D_800A5F20, &D_800A5F2C,
      &D_800A5F38, &D_800A5F44, &D_800A5F50, &D_800A5F5C },
};
Battle D_800A5F8C = { 64, 11, 0x60080000 };
Battle D_800A5F98 = { 64, 11, 0x60080000 };
Battle D_800A5FA4 = { 64, 11, 0x60080000 };
Battle D_800A5FB0 = { 64, 11, 0x60080000 };
Battle D_800A5FBC = { 64, 11, 0x60080000 };
Battle D_800A5FC8 = { 64, 11, 0x60080000 };
Battle D_800A5FD4 = { 64, 11, 0x60080000 };
Battle D_800A5FE0 = { 64, 11, 0x60080000 };
BattleList D_800A5FEC = {
    4,
    { &D_800A5F8C, &D_800A5F98, &D_800A5FA4, &D_800A5FB0,
      &D_800A5FBC, &D_800A5FC8, &D_800A5FD4, &D_800A5FE0 },
};
Battle D_800A6010 = { 0, 0, 0x60040000 };
Battle D_800A601C = { 0, 0, 0x60040000 };
Battle D_800A6028 = { 0, 0, 0x60040000 };
Battle D_800A6034 = { 0, 0, 0x60040000 };
Battle D_800A6040 = { 0, 0, 0x60040000 };
Battle D_800A604C = { 0, 0, 0x60040000 };
Battle D_800A6058 = { 0, 0, 0x60040000 };
Battle D_800A6064 = { 0, 0, 0x60040000 };
BattleList D_800A6070 = {
    0,
    { &D_800A6010, &D_800A601C, &D_800A6028, &D_800A6034,
      &D_800A6040, &D_800A604C, &D_800A6058, &D_800A6064 },
};
Battle D_800A6094 = { 0, 0, 0x60040000 };
Battle D_800A60A0 = { 0, 0, 0x60040000 };
Battle D_800A60AC = { 0, 0, 0x60040000 };
Battle D_800A60B8 = { 0, 0, 0x60040000 };
Battle D_800A60C4 = { 0, 0, 0x60040000 };
Battle D_800A60D0 = { 0, 0, 0x60040000 };
Battle D_800A60DC = { 0, 0, 0x60040000 };
Battle D_800A60E8 = { 0, 0, 0x60040000 };
BattleList D_800A60F4 = {
    0,
    { &D_800A6094, &D_800A60A0, &D_800A60AC, &D_800A60B8,
      &D_800A60C4, &D_800A60D0, &D_800A60DC, &D_800A60E8 },
};
Battle D_800A6118 = { 0, 0, 0x60040000 };
Battle D_800A6124 = { 0, 0, 0x60040000 };
Battle D_800A6130 = { 0, 0, 0x60040000 };
Battle D_800A613C = { 0, 0, 0x60040000 };
Battle D_800A6148 = { 0, 0, 0x60040000 };
Battle D_800A6154 = { 0, 0, 0x60040000 };
Battle D_800A6160 = { 0, 0, 0x60040000 };
Battle D_800A616C = { 0, 0, 0x60040000 };
BattleList D_800A6178 = {
    0,
    { &D_800A6118, &D_800A6124, &D_800A6130, &D_800A613C,
      &D_800A6148, &D_800A6154, &D_800A6160, &D_800A616C },
};
FieldBattles stageBattles[] = {
    { 173, 1, 0, { &D_800A517C, &D_800A5200, &D_800A5284, &D_800A5308 } },
    { 178, 2, 0, { &D_800A538C, &D_800A5410, &D_800A5494, &D_800A5518 } },
    { 194, 7, 0, { &D_800A559C, &D_800A5620, &D_800A56A4, &D_800A5728 } },
    { 196, 8, 0, { &D_800A57AC, &D_800A5830, &D_800A58B4, &D_800A5938 } },
    { 201, 11, 0, { &D_800A59BC, &D_800A5A40, &D_800A5AC4, &D_800A5B48 } },
    { 206, 12, 0, { &D_800A5BCC, &D_800A5C50, &D_800A5CD4, &D_800A5D58 } },
    { 222, 17, 0, { &D_800A5DDC, &D_800A5E60, &D_800A5EE4, &D_800A5F68 } },
    { 224, 18, 0, { &D_800A5FEC, &D_800A6070, &D_800A60F4, &D_800A6178 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x15D, 0x1C0, 0x5D, 0x160, 0x1FF },
};
FieldActorEntry D_800A62EC = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A62EC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 346, 191, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 653, 112, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 179, 218, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 563, 120, 0, 0 },
    { 1, 0, 0xA0, 2, 0xB, 0, 0, 0, 0, 0, 448, 198, 0, 0 },
    { 1, 0, 0x95, 2, 0xC, 0, 0, 0, 0, 0, 480, 210, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 266, 189, 0, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 540, -12, 244, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 240, 273, 351, 0 },
    { 1, 0, 0x68, 4, 1, 0, 0, 0, 0, 0, 208, 259, 345, 0 },
    { 1, 0, 0x58, 4, 2, 0, 0, 0, 0, 0, 196, 254, 332, 0 },
    { 1, 0, 0x58, 4, 3, 0, 0, 0, 0, 0, 416, 180, 305, 0 },
    { 1, 0, 0x93, 4, 4, 0, 0, 0, 0, 0, 384, 157, 299, 0 },
    { 1, 0, 0x79, 4, 5, 0, 0, 0, 0, 0, 352, 151, 270, 0 },
    { 1, 0, 0x94, 4, 6, 0, 0, 0, 0, 0, 320, 131, 277, 0 },
    { 1, 0, 0x5C, 4, 8, 0, 0, 0, 0, 0, 528, 180, 268, 0 },
    { 1, 0, 0x63, 4, 9, 0, 0, 0, 0, 0, 496, 164, 260, 0 },
    { 1, 0, 0x5D, 4, 0xA, 0, 0, 0, 0, 0, 485, 159, 250, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E0, 0x240, 0xD8, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E0, 0xB0, 0x178, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
