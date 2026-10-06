#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places_last.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x6D2
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x6E1
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x24000, 0x15200};
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
extern StagePoint D_800A4FD0;
extern StagePoint D_800A4FE8;
extern StagePoint D_800A4FF8;
extern StagePoint D_800A5008;
extern StagePoint D_800A5020;
extern StagePoint D_800A5030;
extern StagePoint D_800A5040;
extern StagePoint D_800A5058;
extern StagePoint D_800A5068;
extern StagePoint D_800A5078;
extern StagePoint D_800A5090;
extern StagePoint D_800A50A0;
extern StagePoint D_800A50B0;
extern StagePoint D_800A50C8;
extern StagePoint D_800A50D8;
extern StagePoint D_800A50E8;
extern StagePoints D_800A4FE0;
extern StagePoints D_800A5018;
extern StagePoints D_800A5050;
extern StagePoints D_800A5088;
extern StagePoints D_800A50C0;
extern StagePoints D_800A50F8;
extern StagePoints D_800A5100;
extern Battle D_800A5128;
extern Battle D_800A5134;
extern Battle D_800A5140;
extern Battle D_800A514C;
extern Battle D_800A5158;
extern Battle D_800A5164;
extern Battle D_800A5170;
extern Battle D_800A517C;
extern Battle D_800A51AC;
extern Battle D_800A51B8;
extern Battle D_800A51C4;
extern Battle D_800A51D0;
extern Battle D_800A51DC;
extern Battle D_800A51E8;
extern Battle D_800A51F4;
extern Battle D_800A5200;
extern Battle D_800A5230;
extern Battle D_800A523C;
extern Battle D_800A5248;
extern Battle D_800A5254;
extern Battle D_800A5260;
extern Battle D_800A526C;
extern Battle D_800A5278;
extern Battle D_800A5284;
extern Battle D_800A52B4;
extern Battle D_800A52C0;
extern Battle D_800A52CC;
extern Battle D_800A52D8;
extern Battle D_800A52E4;
extern Battle D_800A52F0;
extern Battle D_800A52FC;
extern Battle D_800A5308;
extern Battle D_800A5338;
extern Battle D_800A5344;
extern Battle D_800A5350;
extern Battle D_800A535C;
extern Battle D_800A5368;
extern Battle D_800A5374;
extern Battle D_800A5380;
extern Battle D_800A538C;
extern Battle D_800A53BC;
extern Battle D_800A53C8;
extern Battle D_800A53D4;
extern Battle D_800A53E0;
extern Battle D_800A53EC;
extern Battle D_800A53F8;
extern Battle D_800A5404;
extern Battle D_800A5410;
extern Battle D_800A5440;
extern Battle D_800A544C;
extern Battle D_800A5458;
extern Battle D_800A5464;
extern Battle D_800A5470;
extern Battle D_800A547C;
extern Battle D_800A5488;
extern Battle D_800A5494;
extern Battle D_800A54C4;
extern Battle D_800A54D0;
extern Battle D_800A54DC;
extern Battle D_800A54E8;
extern Battle D_800A54F4;
extern Battle D_800A5500;
extern Battle D_800A550C;
extern Battle D_800A5518;
extern Battle D_800A5548;
extern Battle D_800A5554;
extern Battle D_800A5560;
extern Battle D_800A556C;
extern Battle D_800A5578;
extern Battle D_800A5584;
extern Battle D_800A5590;
extern Battle D_800A559C;
extern Battle D_800A55CC;
extern Battle D_800A55D8;
extern Battle D_800A55E4;
extern Battle D_800A55F0;
extern Battle D_800A55FC;
extern Battle D_800A5608;
extern Battle D_800A5614;
extern Battle D_800A5620;
extern Battle D_800A5650;
extern Battle D_800A565C;
extern Battle D_800A5668;
extern Battle D_800A5674;
extern Battle D_800A5680;
extern Battle D_800A568C;
extern Battle D_800A5698;
extern Battle D_800A56A4;
extern Battle D_800A56D4;
extern Battle D_800A56E0;
extern Battle D_800A56EC;
extern Battle D_800A56F8;
extern Battle D_800A5704;
extern Battle D_800A5710;
extern Battle D_800A571C;
extern Battle D_800A5728;
extern Battle D_800A5758;
extern Battle D_800A5764;
extern Battle D_800A5770;
extern Battle D_800A577C;
extern Battle D_800A5788;
extern Battle D_800A5794;
extern Battle D_800A57A0;
extern Battle D_800A57AC;
extern Battle D_800A57DC;
extern Battle D_800A57E8;
extern Battle D_800A57F4;
extern Battle D_800A5800;
extern Battle D_800A580C;
extern Battle D_800A5818;
extern Battle D_800A5824;
extern Battle D_800A5830;
extern Battle D_800A5860;
extern Battle D_800A586C;
extern Battle D_800A5878;
extern Battle D_800A5884;
extern Battle D_800A5890;
extern Battle D_800A589C;
extern Battle D_800A58A8;
extern Battle D_800A58B4;
extern Battle D_800A58E4;
extern Battle D_800A58F0;
extern Battle D_800A58FC;
extern Battle D_800A5908;
extern Battle D_800A5914;
extern Battle D_800A5920;
extern Battle D_800A592C;
extern Battle D_800A5938;
extern BattleList D_800A5188;
extern BattleList D_800A520C;
extern BattleList D_800A5290;
extern BattleList D_800A5314;
extern BattleList D_800A5398;
extern BattleList D_800A541C;
extern BattleList D_800A54A0;
extern BattleList D_800A5524;
extern BattleList D_800A55A8;
extern BattleList D_800A562C;
extern BattleList D_800A56B0;
extern BattleList D_800A5734;
extern BattleList D_800A57B8;
extern BattleList D_800A583C;
extern BattleList D_800A58C0;
extern BattleList D_800A5944;
extern FieldActorEntry D_800A5A48;

StagePoint D_800A4FB0 = { 0x2E4, 1, 1, 0x340, 160, 1, NULL };
StagePoint D_800A4FC0 = { 0x2E6, 1, 1, 160, 0x150, 5, &D_800A4FB0 };
StagePoint D_800A4FD0 = { 0x21D, 0, 0, 0x328, 0x424, 0, &D_800A4FC0 };
StagePoints D_800A4FE0 = { 1, 1, &D_800A4FD0 };
StagePoint D_800A4FE8 = { 0x2E7, 1, 1, 0x250, 232, 1, NULL };
StagePoint D_800A4FF8 = { 0x2E4, 1, 1, 192, 0x180, 5, &D_800A4FE8 };
StagePoint D_800A5008 = { 0x234, 0, 0, 0x320, 0x1C8, 0, &D_800A4FF8 };
StagePoints D_800A5018 = { 1, 2, &D_800A5008 };
StagePoint D_800A5020 = { 0x2E2, 4, 1, 0x330, 248, 1, NULL };
StagePoint D_800A5030 = { 0x2E4, 4, 1, 192, 0x180, 5, &D_800A5020 };
StagePoint D_800A5040 = { 0x23B, 0, 0, 0x360, 0x12C, 0, &D_800A5030 };
StagePoints D_800A5050 = { 4, 1, &D_800A5040 };
StagePoint D_800A5058 = { 0x2E4, 11, 1, 0x340, 160, 1, NULL };
StagePoint D_800A5068 = { 0x2E6, 11, 1, 160, 0x150, 5, &D_800A5058 };
StagePoint D_800A5078 = { 0x28C, 0, 0, 0x328, 0x424, 0, &D_800A5068 };
StagePoints D_800A5088 = { 11, 1, &D_800A5078 };
StagePoint D_800A5090 = { 0x2E7, 11, 1, 0x250, 232, 1, NULL };
StagePoint D_800A50A0 = { 0x2E4, 11, 1, 192, 0x180, 5, &D_800A5090 };
StagePoint D_800A50B0 = { 0x2A2, 0, 0, 0x320, 0x1C8, 0, &D_800A50A0 };
StagePoints D_800A50C0 = { 11, 2, &D_800A50B0 };
StagePoint D_800A50C8 = { 0x2E2, 14, 1, 0x330, 248, 1, NULL };
StagePoint D_800A50D8 = { 0x2E4, 14, 1, 192, 0x180, 5, &D_800A50C8 };
StagePoint D_800A50E8 = { 0x2A8, 0, 0, 0x360, 0x12C, 0, &D_800A50D8 };
StagePoints D_800A50F8 = { 14, 1, &D_800A50E8 };
StagePoints D_800A5100 = { 0, 0, &D_800A4FD0 };
StagePoints *placePoints[] = {
    &D_800A4FE0, &D_800A5018, &D_800A5050, &D_800A5088,
    &D_800A50C0, &D_800A50F8, &D_800A5100, NULL,
};
Battle D_800A5128 = { 61, 11, 0x60080000 };
Battle D_800A5134 = { 61, 11, 0x60080000 };
Battle D_800A5140 = { 61, 11, 0x60080000 };
Battle D_800A514C = { 61, 11, 0x60080000 };
Battle D_800A5158 = { 62, 11, 0x60080000 };
Battle D_800A5164 = { 62, 11, 0x60080000 };
Battle D_800A5170 = { 62, 11, 0x60080000 };
Battle D_800A517C = { 62, 11, 0x60080000 };
BattleList D_800A5188 = {
    2,
    { &D_800A5128, &D_800A5134, &D_800A5140, &D_800A514C,
      &D_800A5158, &D_800A5164, &D_800A5170, &D_800A517C },
};
Battle D_800A51AC = { 0, 0, 0x60040000 };
Battle D_800A51B8 = { 0, 0, 0x60040000 };
Battle D_800A51C4 = { 0, 0, 0x60040000 };
Battle D_800A51D0 = { 0, 0, 0x60040000 };
Battle D_800A51DC = { 0, 0, 0x60040000 };
Battle D_800A51E8 = { 0, 0, 0x60040000 };
Battle D_800A51F4 = { 0, 0, 0x60040000 };
Battle D_800A5200 = { 0, 0, 0x60040000 };
BattleList D_800A520C = {
    0,
    { &D_800A51AC, &D_800A51B8, &D_800A51C4, &D_800A51D0,
      &D_800A51DC, &D_800A51E8, &D_800A51F4, &D_800A5200 },
};
Battle D_800A5230 = { 0, 0, 0x60040000 };
Battle D_800A523C = { 0, 0, 0x60040000 };
Battle D_800A5248 = { 0, 0, 0x60040000 };
Battle D_800A5254 = { 0, 0, 0x60040000 };
Battle D_800A5260 = { 0, 0, 0x60040000 };
Battle D_800A526C = { 0, 0, 0x60040000 };
Battle D_800A5278 = { 0, 0, 0x60040000 };
Battle D_800A5284 = { 0, 0, 0x60040000 };
BattleList D_800A5290 = {
    0,
    { &D_800A5230, &D_800A523C, &D_800A5248, &D_800A5254,
      &D_800A5260, &D_800A526C, &D_800A5278, &D_800A5284 },
};
Battle D_800A52B4 = { 0, 0, 0x60040000 };
Battle D_800A52C0 = { 0, 0, 0x60040000 };
Battle D_800A52CC = { 0, 0, 0x60040000 };
Battle D_800A52D8 = { 0, 0, 0x60040000 };
Battle D_800A52E4 = { 0, 0, 0x60040000 };
Battle D_800A52F0 = { 0, 0, 0x60040000 };
Battle D_800A52FC = { 0, 0, 0x60040000 };
Battle D_800A5308 = { 0, 0, 0x60040000 };
BattleList D_800A5314 = {
    0,
    { &D_800A52B4, &D_800A52C0, &D_800A52CC, &D_800A52D8,
      &D_800A52E4, &D_800A52F0, &D_800A52FC, &D_800A5308 },
};
Battle D_800A5338 = { 61, 11, 0x60080000 };
Battle D_800A5344 = { 61, 11, 0x60080000 };
Battle D_800A5350 = { 61, 11, 0x60080000 };
Battle D_800A535C = { 61, 11, 0x60080000 };
Battle D_800A5368 = { 62, 11, 0x60080000 };
Battle D_800A5374 = { 62, 11, 0x60080000 };
Battle D_800A5380 = { 62, 11, 0x60080000 };
Battle D_800A538C = { 62, 11, 0x60080000 };
BattleList D_800A5398 = {
    2,
    { &D_800A5338, &D_800A5344, &D_800A5350, &D_800A535C,
      &D_800A5368, &D_800A5374, &D_800A5380, &D_800A538C },
};
Battle D_800A53BC = { 0, 0, 0x60040000 };
Battle D_800A53C8 = { 0, 0, 0x60040000 };
Battle D_800A53D4 = { 0, 0, 0x60040000 };
Battle D_800A53E0 = { 0, 0, 0x60040000 };
Battle D_800A53EC = { 0, 0, 0x60040000 };
Battle D_800A53F8 = { 0, 0, 0x60040000 };
Battle D_800A5404 = { 0, 0, 0x60040000 };
Battle D_800A5410 = { 0, 0, 0x60040000 };
BattleList D_800A541C = {
    0,
    { &D_800A53BC, &D_800A53C8, &D_800A53D4, &D_800A53E0,
      &D_800A53EC, &D_800A53F8, &D_800A5404, &D_800A5410 },
};
Battle D_800A5440 = { 0, 0, 0x60040000 };
Battle D_800A544C = { 0, 0, 0x60040000 };
Battle D_800A5458 = { 0, 0, 0x60040000 };
Battle D_800A5464 = { 0, 0, 0x60040000 };
Battle D_800A5470 = { 0, 0, 0x60040000 };
Battle D_800A547C = { 0, 0, 0x60040000 };
Battle D_800A5488 = { 0, 0, 0x60040000 };
Battle D_800A5494 = { 0, 0, 0x60040000 };
BattleList D_800A54A0 = {
    0,
    { &D_800A5440, &D_800A544C, &D_800A5458, &D_800A5464,
      &D_800A5470, &D_800A547C, &D_800A5488, &D_800A5494 },
};
Battle D_800A54C4 = { 0, 0, 0x60040000 };
Battle D_800A54D0 = { 0, 0, 0x60040000 };
Battle D_800A54DC = { 0, 0, 0x60040000 };
Battle D_800A54E8 = { 0, 0, 0x60040000 };
Battle D_800A54F4 = { 0, 0, 0x60040000 };
Battle D_800A5500 = { 0, 0, 0x60040000 };
Battle D_800A550C = { 0, 0, 0x60040000 };
Battle D_800A5518 = { 0, 0, 0x60040000 };
BattleList D_800A5524 = {
    0,
    { &D_800A54C4, &D_800A54D0, &D_800A54DC, &D_800A54E8,
      &D_800A54F4, &D_800A5500, &D_800A550C, &D_800A5518 },
};
Battle D_800A5548 = { 103, 11, 0x60080000 };
Battle D_800A5554 = { 103, 11, 0x60080000 };
Battle D_800A5560 = { 103, 11, 0x60080000 };
Battle D_800A556C = { 103, 11, 0x60080000 };
Battle D_800A5578 = { 103, 11, 0x60080000 };
Battle D_800A5584 = { 103, 11, 0x60080000 };
Battle D_800A5590 = { 103, 11, 0x60080000 };
Battle D_800A559C = { 103, 11, 0x60080000 };
BattleList D_800A55A8 = {
    2,
    { &D_800A5548, &D_800A5554, &D_800A5560, &D_800A556C,
      &D_800A5578, &D_800A5584, &D_800A5590, &D_800A559C },
};
Battle D_800A55CC = { 0, 0, 0x60040000 };
Battle D_800A55D8 = { 0, 0, 0x60040000 };
Battle D_800A55E4 = { 0, 0, 0x60040000 };
Battle D_800A55F0 = { 0, 0, 0x60040000 };
Battle D_800A55FC = { 0, 0, 0x60040000 };
Battle D_800A5608 = { 0, 0, 0x60040000 };
Battle D_800A5614 = { 0, 0, 0x60040000 };
Battle D_800A5620 = { 0, 0, 0x60040000 };
BattleList D_800A562C = {
    0,
    { &D_800A55CC, &D_800A55D8, &D_800A55E4, &D_800A55F0,
      &D_800A55FC, &D_800A5608, &D_800A5614, &D_800A5620 },
};
Battle D_800A5650 = { 0, 0, 0x60040000 };
Battle D_800A565C = { 0, 0, 0x60040000 };
Battle D_800A5668 = { 0, 0, 0x60040000 };
Battle D_800A5674 = { 0, 0, 0x60040000 };
Battle D_800A5680 = { 0, 0, 0x60040000 };
Battle D_800A568C = { 0, 0, 0x60040000 };
Battle D_800A5698 = { 0, 0, 0x60040000 };
Battle D_800A56A4 = { 0, 0, 0x60040000 };
BattleList D_800A56B0 = {
    0,
    { &D_800A5650, &D_800A565C, &D_800A5668, &D_800A5674,
      &D_800A5680, &D_800A568C, &D_800A5698, &D_800A56A4 },
};
Battle D_800A56D4 = { 0, 0, 0x60040000 };
Battle D_800A56E0 = { 0, 0, 0x60040000 };
Battle D_800A56EC = { 0, 0, 0x60040000 };
Battle D_800A56F8 = { 0, 0, 0x60040000 };
Battle D_800A5704 = { 0, 0, 0x60040000 };
Battle D_800A5710 = { 0, 0, 0x60040000 };
Battle D_800A571C = { 0, 0, 0x60040000 };
Battle D_800A5728 = { 0, 0, 0x60040000 };
BattleList D_800A5734 = {
    0,
    { &D_800A56D4, &D_800A56E0, &D_800A56EC, &D_800A56F8,
      &D_800A5704, &D_800A5710, &D_800A571C, &D_800A5728 },
};
Battle D_800A5758 = { 103, 11, 0x60080000 };
Battle D_800A5764 = { 103, 11, 0x60080000 };
Battle D_800A5770 = { 103, 11, 0x60080000 };
Battle D_800A577C = { 103, 11, 0x60080000 };
Battle D_800A5788 = { 103, 11, 0x60080000 };
Battle D_800A5794 = { 103, 11, 0x60080000 };
Battle D_800A57A0 = { 103, 11, 0x60080000 };
Battle D_800A57AC = { 103, 11, 0x60080000 };
BattleList D_800A57B8 = {
    2,
    { &D_800A5758, &D_800A5764, &D_800A5770, &D_800A577C,
      &D_800A5788, &D_800A5794, &D_800A57A0, &D_800A57AC },
};
Battle D_800A57DC = { 0, 0, 0x60040000 };
Battle D_800A57E8 = { 0, 0, 0x60040000 };
Battle D_800A57F4 = { 0, 0, 0x60040000 };
Battle D_800A5800 = { 0, 0, 0x60040000 };
Battle D_800A580C = { 0, 0, 0x60040000 };
Battle D_800A5818 = { 0, 0, 0x60040000 };
Battle D_800A5824 = { 0, 0, 0x60040000 };
Battle D_800A5830 = { 0, 0, 0x60040000 };
BattleList D_800A583C = {
    0,
    { &D_800A57DC, &D_800A57E8, &D_800A57F4, &D_800A5800,
      &D_800A580C, &D_800A5818, &D_800A5824, &D_800A5830 },
};
Battle D_800A5860 = { 0, 0, 0x60040000 };
Battle D_800A586C = { 0, 0, 0x60040000 };
Battle D_800A5878 = { 0, 0, 0x60040000 };
Battle D_800A5884 = { 0, 0, 0x60040000 };
Battle D_800A5890 = { 0, 0, 0x60040000 };
Battle D_800A589C = { 0, 0, 0x60040000 };
Battle D_800A58A8 = { 0, 0, 0x60040000 };
Battle D_800A58B4 = { 0, 0, 0x60040000 };
BattleList D_800A58C0 = {
    0,
    { &D_800A5860, &D_800A586C, &D_800A5878, &D_800A5884,
      &D_800A5890, &D_800A589C, &D_800A58A8, &D_800A58B4 },
};
Battle D_800A58E4 = { 0, 0, 0x60040000 };
Battle D_800A58F0 = { 0, 0, 0x60040000 };
Battle D_800A58FC = { 0, 0, 0x60040000 };
Battle D_800A5908 = { 0, 0, 0x60040000 };
Battle D_800A5914 = { 0, 0, 0x60040000 };
Battle D_800A5920 = { 0, 0, 0x60040000 };
Battle D_800A592C = { 0, 0, 0x60040000 };
Battle D_800A5938 = { 0, 0, 0x60040000 };
BattleList D_800A5944 = {
    0,
    { &D_800A58E4, &D_800A58F0, &D_800A58FC, &D_800A5908,
      &D_800A5914, &D_800A5920, &D_800A592C, &D_800A5938 },
};
FieldBattles stageBattles[] = {
    { 175, 1, 0, { &D_800A5188, &D_800A520C, &D_800A5290, &D_800A5314 } },
    { 185, 4, 0, { &D_800A5398, &D_800A541C, &D_800A54A0, &D_800A5524 } },
    { 203, 11, 0, { &D_800A55A8, &D_800A562C, &D_800A56B0, &D_800A5734 } },
    { 213, 14, 0, { &D_800A57B8, &D_800A583C, &D_800A58C0, &D_800A5944 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x1CF, 0xC0, 0xCF, 0x160, 0x1FF },
};
FieldActorEntry D_800A5A48 = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A5A48,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 231, 159, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 386, 203, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 943, 97, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 587, 241, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 783, 147, 0, 0 },
    { 1, 0, 0xFF, 2, 0x33, 2, 0, 7, 0x18, 0, 540, -76, 0, 0 },
    { 1, 0, 0x55, 2, 0, 0, 0, 0, 0, 0, 384, 299, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 448, 344, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 640, 339, 0, 0 },
    { 1, 0, 0x52, 2, 3, 0, 0, 0, 0, 0, 704, 302, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 669, 89, 0, 0 },
    { 1, 0, 0xB6, 6, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 538, 16, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 448, 180, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 848, 69, 0, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 540, 52, 296, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E5, 0x240, 0x120, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E5, 0x3B0, 0xD8, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E5, 0xE0, 0x120, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
