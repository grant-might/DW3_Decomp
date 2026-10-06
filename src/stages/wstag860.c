#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places_last.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x6E5
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x6F5
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xEC00, 0x14D00};
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
extern StagePoint D_800A4FC4;
extern StagePoint D_800A4FDC;
extern StagePoint D_800A4FF4;
extern StagePoints D_800A4FBC;
extern StagePoints D_800A4FD4;
extern StagePoints D_800A4FEC;
extern StagePoints D_800A5004;
extern StagePoints D_800A500C;
extern Battle D_800A502C;
extern Battle D_800A5038;
extern Battle D_800A5044;
extern Battle D_800A5050;
extern Battle D_800A505C;
extern Battle D_800A5068;
extern Battle D_800A5074;
extern Battle D_800A5080;
extern Battle D_800A50B0;
extern Battle D_800A50BC;
extern Battle D_800A50C8;
extern Battle D_800A50D4;
extern Battle D_800A50E0;
extern Battle D_800A50EC;
extern Battle D_800A50F8;
extern Battle D_800A5104;
extern Battle D_800A5134;
extern Battle D_800A5140;
extern Battle D_800A514C;
extern Battle D_800A5158;
extern Battle D_800A5164;
extern Battle D_800A5170;
extern Battle D_800A517C;
extern Battle D_800A5188;
extern Battle D_800A51B8;
extern Battle D_800A51C4;
extern Battle D_800A51D0;
extern Battle D_800A51DC;
extern Battle D_800A51E8;
extern Battle D_800A51F4;
extern Battle D_800A5200;
extern Battle D_800A520C;
extern Battle D_800A523C;
extern Battle D_800A5248;
extern Battle D_800A5254;
extern Battle D_800A5260;
extern Battle D_800A526C;
extern Battle D_800A5278;
extern Battle D_800A5284;
extern Battle D_800A5290;
extern Battle D_800A52C0;
extern Battle D_800A52CC;
extern Battle D_800A52D8;
extern Battle D_800A52E4;
extern Battle D_800A52F0;
extern Battle D_800A52FC;
extern Battle D_800A5308;
extern Battle D_800A5314;
extern Battle D_800A5344;
extern Battle D_800A5350;
extern Battle D_800A535C;
extern Battle D_800A5368;
extern Battle D_800A5374;
extern Battle D_800A5380;
extern Battle D_800A538C;
extern Battle D_800A5398;
extern Battle D_800A53C8;
extern Battle D_800A53D4;
extern Battle D_800A53E0;
extern Battle D_800A53EC;
extern Battle D_800A53F8;
extern Battle D_800A5404;
extern Battle D_800A5410;
extern Battle D_800A541C;
extern Battle D_800A544C;
extern Battle D_800A5458;
extern Battle D_800A5464;
extern Battle D_800A5470;
extern Battle D_800A547C;
extern Battle D_800A5488;
extern Battle D_800A5494;
extern Battle D_800A54A0;
extern Battle D_800A54D0;
extern Battle D_800A54DC;
extern Battle D_800A54E8;
extern Battle D_800A54F4;
extern Battle D_800A5500;
extern Battle D_800A550C;
extern Battle D_800A5518;
extern Battle D_800A5524;
extern Battle D_800A5554;
extern Battle D_800A5560;
extern Battle D_800A556C;
extern Battle D_800A5578;
extern Battle D_800A5584;
extern Battle D_800A5590;
extern Battle D_800A559C;
extern Battle D_800A55A8;
extern Battle D_800A55D8;
extern Battle D_800A55E4;
extern Battle D_800A55F0;
extern Battle D_800A55FC;
extern Battle D_800A5608;
extern Battle D_800A5614;
extern Battle D_800A5620;
extern Battle D_800A562C;
extern Battle D_800A565C;
extern Battle D_800A5668;
extern Battle D_800A5674;
extern Battle D_800A5680;
extern Battle D_800A568C;
extern Battle D_800A5698;
extern Battle D_800A56A4;
extern Battle D_800A56B0;
extern Battle D_800A56E0;
extern Battle D_800A56EC;
extern Battle D_800A56F8;
extern Battle D_800A5704;
extern Battle D_800A5710;
extern Battle D_800A571C;
extern Battle D_800A5728;
extern Battle D_800A5734;
extern Battle D_800A5764;
extern Battle D_800A5770;
extern Battle D_800A577C;
extern Battle D_800A5788;
extern Battle D_800A5794;
extern Battle D_800A57A0;
extern Battle D_800A57AC;
extern Battle D_800A57B8;
extern Battle D_800A57E8;
extern Battle D_800A57F4;
extern Battle D_800A5800;
extern Battle D_800A580C;
extern Battle D_800A5818;
extern Battle D_800A5824;
extern Battle D_800A5830;
extern Battle D_800A583C;
extern BattleList D_800A508C;
extern BattleList D_800A5110;
extern BattleList D_800A5194;
extern BattleList D_800A5218;
extern BattleList D_800A529C;
extern BattleList D_800A5320;
extern BattleList D_800A53A4;
extern BattleList D_800A5428;
extern BattleList D_800A54AC;
extern BattleList D_800A5530;
extern BattleList D_800A55B4;
extern BattleList D_800A5638;
extern BattleList D_800A56BC;
extern BattleList D_800A5740;
extern BattleList D_800A57C4;
extern BattleList D_800A5848;
extern u16 D_800A596C[];
extern u16 D_800A5978[];
extern u16 D_800A59B4[];
extern FieldTalk D_800A5984[];
extern u16 D_800A59C4[];
extern FieldTalk D_800A599C[];
extern FieldActorEntry D_800A59D4;
extern FieldActorEntry D_800A59E8;
extern FieldActorEntry D_800A59FC;

StagePoint D_800A4FAC = { 0x2E5, 1, 2, 224, 0x120, 5, NULL };
StagePoints D_800A4FBC = { 1, 1, &D_800A4FAC };
StagePoint D_800A4FC4 = { 0x2E4, 6, 1, 192, 0x180, 5, NULL };
StagePoints D_800A4FD4 = { 6, 1, &D_800A4FC4 };
StagePoint D_800A4FDC = { 0x2E5, 11, 2, 224, 0x120, 5, NULL };
StagePoints D_800A4FEC = { 11, 1, &D_800A4FDC };
StagePoint D_800A4FF4 = { 0x2E4, 16, 1, 192, 0x180, 5, NULL };
StagePoints D_800A5004 = { 16, 1, &D_800A4FF4 };
StagePoints D_800A500C = { 0, 0, &D_800A4FAC };
StagePoints *placePoints[] = {
    &D_800A4FBC, &D_800A4FD4, &D_800A4FEC, &D_800A5004,
    &D_800A500C, NULL,
};
Battle D_800A502C = { 61, 11, 0x60080000 };
Battle D_800A5038 = { 61, 11, 0x60080000 };
Battle D_800A5044 = { 61, 11, 0x60080000 };
Battle D_800A5050 = { 61, 11, 0x60080000 };
Battle D_800A505C = { 62, 11, 0x60080000 };
Battle D_800A5068 = { 62, 11, 0x60080000 };
Battle D_800A5074 = { 62, 11, 0x60080000 };
Battle D_800A5080 = { 62, 11, 0x60080000 };
BattleList D_800A508C = {
    2,
    { &D_800A502C, &D_800A5038, &D_800A5044, &D_800A5050,
      &D_800A505C, &D_800A5068, &D_800A5074, &D_800A5080 },
};
Battle D_800A50B0 = { 0, 0, 0x60040000 };
Battle D_800A50BC = { 0, 0, 0x60040000 };
Battle D_800A50C8 = { 0, 0, 0x60040000 };
Battle D_800A50D4 = { 0, 0, 0x60040000 };
Battle D_800A50E0 = { 0, 0, 0x60040000 };
Battle D_800A50EC = { 0, 0, 0x60040000 };
Battle D_800A50F8 = { 0, 0, 0x60040000 };
Battle D_800A5104 = { 0, 0, 0x60040000 };
BattleList D_800A5110 = {
    0,
    { &D_800A50B0, &D_800A50BC, &D_800A50C8, &D_800A50D4,
      &D_800A50E0, &D_800A50EC, &D_800A50F8, &D_800A5104 },
};
Battle D_800A5134 = { 0, 0, 0x60040000 };
Battle D_800A5140 = { 0, 0, 0x60040000 };
Battle D_800A514C = { 0, 0, 0x60040000 };
Battle D_800A5158 = { 0, 0, 0x60040000 };
Battle D_800A5164 = { 0, 0, 0x60040000 };
Battle D_800A5170 = { 0, 0, 0x60040000 };
Battle D_800A517C = { 0, 0, 0x60040000 };
Battle D_800A5188 = { 0, 0, 0x60040000 };
BattleList D_800A5194 = {
    0,
    { &D_800A5134, &D_800A5140, &D_800A514C, &D_800A5158,
      &D_800A5164, &D_800A5170, &D_800A517C, &D_800A5188 },
};
Battle D_800A51B8 = { 0, 0, 0x60040000 };
Battle D_800A51C4 = { 0, 0, 0x60040000 };
Battle D_800A51D0 = { 0, 0, 0x60040000 };
Battle D_800A51DC = { 0, 0, 0x60040000 };
Battle D_800A51E8 = { 0, 0, 0x60040000 };
Battle D_800A51F4 = { 0, 0, 0x60040000 };
Battle D_800A5200 = { 0, 0, 0x60040000 };
Battle D_800A520C = { 0, 0, 0x60040000 };
BattleList D_800A5218 = {
    0,
    { &D_800A51B8, &D_800A51C4, &D_800A51D0, &D_800A51DC,
      &D_800A51E8, &D_800A51F4, &D_800A5200, &D_800A520C },
};
Battle D_800A523C = { 63, 11, 0x60080000 };
Battle D_800A5248 = { 63, 11, 0x60080000 };
Battle D_800A5254 = { 63, 11, 0x60080000 };
Battle D_800A5260 = { 63, 11, 0x60080000 };
Battle D_800A526C = { 63, 11, 0x60080000 };
Battle D_800A5278 = { 63, 11, 0x60080000 };
Battle D_800A5284 = { 63, 11, 0x60080000 };
Battle D_800A5290 = { 63, 11, 0x60080000 };
BattleList D_800A529C = {
    5,
    { &D_800A523C, &D_800A5248, &D_800A5254, &D_800A5260,
      &D_800A526C, &D_800A5278, &D_800A5284, &D_800A5290 },
};
Battle D_800A52C0 = { 0, 0, 0x60040000 };
Battle D_800A52CC = { 0, 0, 0x60040000 };
Battle D_800A52D8 = { 0, 0, 0x60040000 };
Battle D_800A52E4 = { 0, 0, 0x60040000 };
Battle D_800A52F0 = { 0, 0, 0x60040000 };
Battle D_800A52FC = { 0, 0, 0x60040000 };
Battle D_800A5308 = { 0, 0, 0x60040000 };
Battle D_800A5314 = { 0, 0, 0x60040000 };
BattleList D_800A5320 = {
    0,
    { &D_800A52C0, &D_800A52CC, &D_800A52D8, &D_800A52E4,
      &D_800A52F0, &D_800A52FC, &D_800A5308, &D_800A5314 },
};
Battle D_800A5344 = { 0, 0, 0x60040000 };
Battle D_800A5350 = { 0, 0, 0x60040000 };
Battle D_800A535C = { 0, 0, 0x60040000 };
Battle D_800A5368 = { 0, 0, 0x60040000 };
Battle D_800A5374 = { 0, 0, 0x60040000 };
Battle D_800A5380 = { 0, 0, 0x60040000 };
Battle D_800A538C = { 0, 0, 0x60040000 };
Battle D_800A5398 = { 0, 0, 0x60040000 };
BattleList D_800A53A4 = {
    0,
    { &D_800A5344, &D_800A5350, &D_800A535C, &D_800A5368,
      &D_800A5374, &D_800A5380, &D_800A538C, &D_800A5398 },
};
Battle D_800A53C8 = { 0, 0, 0x60040000 };
Battle D_800A53D4 = { 0, 0, 0x60040000 };
Battle D_800A53E0 = { 0, 0, 0x60040000 };
Battle D_800A53EC = { 0, 0, 0x60040000 };
Battle D_800A53F8 = { 0, 0, 0x60040000 };
Battle D_800A5404 = { 0, 0, 0x60040000 };
Battle D_800A5410 = { 0, 0, 0x60040000 };
Battle D_800A541C = { 0, 0, 0x60040000 };
BattleList D_800A5428 = {
    0,
    { &D_800A53C8, &D_800A53D4, &D_800A53E0, &D_800A53EC,
      &D_800A53F8, &D_800A5404, &D_800A5410, &D_800A541C },
};
Battle D_800A544C = { 103, 11, 0x60080000 };
Battle D_800A5458 = { 103, 11, 0x60080000 };
Battle D_800A5464 = { 103, 11, 0x60080000 };
Battle D_800A5470 = { 103, 11, 0x60080000 };
Battle D_800A547C = { 103, 11, 0x60080000 };
Battle D_800A5488 = { 103, 11, 0x60080000 };
Battle D_800A5494 = { 103, 11, 0x60080000 };
Battle D_800A54A0 = { 103, 11, 0x60080000 };
BattleList D_800A54AC = {
    2,
    { &D_800A544C, &D_800A5458, &D_800A5464, &D_800A5470,
      &D_800A547C, &D_800A5488, &D_800A5494, &D_800A54A0 },
};
Battle D_800A54D0 = { 0, 0, 0x60040000 };
Battle D_800A54DC = { 0, 0, 0x60040000 };
Battle D_800A54E8 = { 0, 0, 0x60040000 };
Battle D_800A54F4 = { 0, 0, 0x60040000 };
Battle D_800A5500 = { 0, 0, 0x60040000 };
Battle D_800A550C = { 0, 0, 0x60040000 };
Battle D_800A5518 = { 0, 0, 0x60040000 };
Battle D_800A5524 = { 0, 0, 0x60040000 };
BattleList D_800A5530 = {
    0,
    { &D_800A54D0, &D_800A54DC, &D_800A54E8, &D_800A54F4,
      &D_800A5500, &D_800A550C, &D_800A5518, &D_800A5524 },
};
Battle D_800A5554 = { 0, 0, 0x60040000 };
Battle D_800A5560 = { 0, 0, 0x60040000 };
Battle D_800A556C = { 0, 0, 0x60040000 };
Battle D_800A5578 = { 0, 0, 0x60040000 };
Battle D_800A5584 = { 0, 0, 0x60040000 };
Battle D_800A5590 = { 0, 0, 0x60040000 };
Battle D_800A559C = { 0, 0, 0x60040000 };
Battle D_800A55A8 = { 0, 0, 0x60040000 };
BattleList D_800A55B4 = {
    0,
    { &D_800A5554, &D_800A5560, &D_800A556C, &D_800A5578,
      &D_800A5584, &D_800A5590, &D_800A559C, &D_800A55A8 },
};
Battle D_800A55D8 = { 0, 0, 0x60040000 };
Battle D_800A55E4 = { 0, 0, 0x60040000 };
Battle D_800A55F0 = { 0, 0, 0x60040000 };
Battle D_800A55FC = { 0, 0, 0x60040000 };
Battle D_800A5608 = { 0, 0, 0x60040000 };
Battle D_800A5614 = { 0, 0, 0x60040000 };
Battle D_800A5620 = { 0, 0, 0x60040000 };
Battle D_800A562C = { 0, 0, 0x60040000 };
BattleList D_800A5638 = {
    0,
    { &D_800A55D8, &D_800A55E4, &D_800A55F0, &D_800A55FC,
      &D_800A5608, &D_800A5614, &D_800A5620, &D_800A562C },
};
Battle D_800A565C = { 178, 11, 0x60080000 };
Battle D_800A5668 = { 178, 11, 0x60080000 };
Battle D_800A5674 = { 178, 11, 0x60080000 };
Battle D_800A5680 = { 178, 11, 0x60080000 };
Battle D_800A568C = { 178, 11, 0x60080000 };
Battle D_800A5698 = { 178, 11, 0x60080000 };
Battle D_800A56A4 = { 178, 11, 0x60080000 };
Battle D_800A56B0 = { 178, 11, 0x60080000 };
BattleList D_800A56BC = {
    5,
    { &D_800A565C, &D_800A5668, &D_800A5674, &D_800A5680,
      &D_800A568C, &D_800A5698, &D_800A56A4, &D_800A56B0 },
};
Battle D_800A56E0 = { 0, 0, 0x60040000 };
Battle D_800A56EC = { 0, 0, 0x60040000 };
Battle D_800A56F8 = { 0, 0, 0x60040000 };
Battle D_800A5704 = { 0, 0, 0x60040000 };
Battle D_800A5710 = { 0, 0, 0x60040000 };
Battle D_800A571C = { 0, 0, 0x60040000 };
Battle D_800A5728 = { 0, 0, 0x60040000 };
Battle D_800A5734 = { 0, 0, 0x60040000 };
BattleList D_800A5740 = {
    0,
    { &D_800A56E0, &D_800A56EC, &D_800A56F8, &D_800A5704,
      &D_800A5710, &D_800A571C, &D_800A5728, &D_800A5734 },
};
Battle D_800A5764 = { 0, 0, 0x60040000 };
Battle D_800A5770 = { 0, 0, 0x60040000 };
Battle D_800A577C = { 0, 0, 0x60040000 };
Battle D_800A5788 = { 0, 0, 0x60040000 };
Battle D_800A5794 = { 0, 0, 0x60040000 };
Battle D_800A57A0 = { 0, 0, 0x60040000 };
Battle D_800A57AC = { 0, 0, 0x60040000 };
Battle D_800A57B8 = { 0, 0, 0x60040000 };
BattleList D_800A57C4 = {
    0,
    { &D_800A5764, &D_800A5770, &D_800A577C, &D_800A5788,
      &D_800A5794, &D_800A57A0, &D_800A57AC, &D_800A57B8 },
};
Battle D_800A57E8 = { 0, 0, 0x60040000 };
Battle D_800A57F4 = { 0, 0, 0x60040000 };
Battle D_800A5800 = { 0, 0, 0x60040000 };
Battle D_800A580C = { 0, 0, 0x60040000 };
Battle D_800A5818 = { 0, 0, 0x60040000 };
Battle D_800A5824 = { 0, 0, 0x60040000 };
Battle D_800A5830 = { 0, 0, 0x60040000 };
Battle D_800A583C = { 0, 0, 0x60040000 };
BattleList D_800A5848 = {
    0,
    { &D_800A57E8, &D_800A57F4, &D_800A5800, &D_800A580C,
      &D_800A5818, &D_800A5824, &D_800A5830, &D_800A583C },
};
FieldBattles stageBattles[] = {
    { 177, 1, 0, { &D_800A508C, &D_800A5110, &D_800A5194, &D_800A5218 } },
    { 193, 6, 0, { &D_800A529C, &D_800A5320, &D_800A53A4, &D_800A5428 } },
    { 205, 11, 0, { &D_800A54AC, &D_800A5530, &D_800A55B4, &D_800A5638 } },
    { 221, 16, 0, { &D_800A56BC, &D_800A5740, &D_800A57C4, &D_800A5848 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x15F, 0xB8, 0x5F, 0x150, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x17F, 0xB8, 0x7F, 0x160, 0x1FF },
    { 0x140, 0x100, 0x160, 0x160, 0x80, 0x60, 0x170, 0x1FF },
};
u16 D_800A596C[] = { 0x22C, 1, 0x8236, 1, 0xFFFF };
u16 D_800A5978[] = { 0x255, 1, 0x8240, 1, 0xFFFF };
FieldTalk D_800A5984[] = {
    { NULL, D_800A596C, 0x34E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A599C[] = {
    { NULL, D_800A5978, 0x34F },
    { NULL, NULL, 0 },
};
u16 D_800A59B4[] = { 0x7E05, 1, 0x7E1E, 1, 0x22C, 0, 0xFFFF };
u16 D_800A59C4[] = { 0x7E0F, 1, 0x7E1E, 1, 0x255, 0, 0xFFFF };
FieldActorEntry D_800A59D4 = { D_800A59B4, D_800A5984, 0x21, 4, 192, 280, 1 };
FieldActorEntry D_800A59E8 = { D_800A59C4, D_800A599C, 0x4D, 5, 192, 280, 1 };
FieldActorEntry D_800A59FC = { NULL, NULL, 0x147, 6, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A59D4,
    &D_800A59E8,
    &D_800A59FC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 360, 185, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 589, 120, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 268, 192, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 512, 122, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 110, 120, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 412, 114, 0, 0 },
    { 1, 0, 0x4A, 4, 0, 0, 0, 0, 0, 0, 416, 215, 288, 0 },
    { 1, 0, 0x61, 4, 1, 0, 0, 0, 0, 0, 384, 198, 288, 0 },
    { 1, 0, 0x5F, 4, 2, 0, 0, 0, 0, 0, 365, 191, 281, 0 },
    { 1, 0, 0x4F, 4, 3, 0, 0, 0, 0, 0, 592, 173, 251, 0 },
    { 1, 0, 0x63, 4, 4, 0, 0, 0, 0, 0, 560, 157, 247, 0 },
    { 1, 0, 0x60, 4, 5, 0, 0, 0, 0, 0, 541, 150, 240, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E7, 0x250, 0xE8, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
