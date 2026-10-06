#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x65E
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x66E
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xDA00, 0x2E500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x18;
    D_800990B4.music = 0x60600000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E34;
extern Battle D_800A4E40;
extern Battle D_800A4E4C;
extern Battle D_800A4E58;
extern Battle D_800A4E64;
extern Battle D_800A4E70;
extern Battle D_800A4E7C;
extern Battle D_800A4E88;
extern Battle D_800A4EB8;
extern Battle D_800A4EC4;
extern Battle D_800A4ED0;
extern Battle D_800A4EDC;
extern Battle D_800A4EE8;
extern Battle D_800A4EF4;
extern Battle D_800A4F00;
extern Battle D_800A4F0C;
extern Battle D_800A4F3C;
extern Battle D_800A4F48;
extern Battle D_800A4F54;
extern Battle D_800A4F60;
extern Battle D_800A4F6C;
extern Battle D_800A4F78;
extern Battle D_800A4F84;
extern Battle D_800A4F90;
extern Battle D_800A4FC0;
extern Battle D_800A4FCC;
extern Battle D_800A4FD8;
extern Battle D_800A4FE4;
extern Battle D_800A4FF0;
extern Battle D_800A4FFC;
extern Battle D_800A5008;
extern Battle D_800A5014;
extern BattleList D_800A4E94;
extern BattleList D_800A4F18;
extern BattleList D_800A4F9C;
extern BattleList D_800A5020;
extern u16 D_800A5150[];
extern u16 D_800A5158[];
extern u16 D_800A5160[];
extern u16 D_800A516C[];
extern u16 D_800A517C[];
extern u16 D_800A5184[];
extern u16 D_800A5198[];
extern u16 D_800A51B0[];
extern u16 D_800A51BC[];
extern u16 D_800A51D8[];
extern u16 D_800A51F4[];
extern u16 D_800A51FC[];
extern u16 D_800A5204[];
extern u16 D_800A5210[];
extern u16 D_800A5218[];
extern u16 D_800A5224[];
extern u16 D_800A5230[];
extern u16 D_800A5238[];
extern u16 D_800A5240[];
extern u16 D_800A524C[];
extern u16 D_800A525C[];
extern u16 D_800A5264[];
extern u16 D_800A5278[];
extern u16 D_800A5290[];
extern u16 D_800A529C[];
extern u16 D_800A52B8[];
extern u16 D_800A52D4[];
extern u16 D_800A52DC[];
extern u16 D_800A52E8[];
extern u16 D_800A52F0[];
extern u16 D_800A52FC[];
extern u16 D_800A5304[];
extern u16 D_800A530C[];
extern u16 D_800A5314[];
extern u16 D_800A5320[];
extern u16 D_800A5330[];
extern u16 D_800A5338[];
extern u16 D_800A534C[];
extern u16 D_800A5364[];
extern u16 D_800A536C[];
extern u16 D_800A5388[];
extern u16 D_800A53A4[];
extern u16 D_800A56D0[];
extern FieldTalk D_800A53AC[];
extern u16 D_800A56D8[];
extern FieldTalk D_800A53C4[];
extern u16 D_800A56E0[];
extern FieldTalk D_800A53DC[];
extern u16 D_800A56E8[];
extern FieldTalk D_800A53F4[];
extern u16 D_800A56F0[];
extern FieldTalk D_800A540C[];
extern u16 D_800A56F8[];
extern FieldTalk D_800A5424[];
extern u16 D_800A5700[];
extern FieldTalk D_800A543C[];
extern u16 D_800A5710[];
extern FieldTalk D_800A549C[];
extern u16 D_800A5720[];
extern FieldTalk D_800A54B4[];
extern u16 D_800A5730[];
extern FieldTalk D_800A54E4[];
extern u16 D_800A5740[];
extern FieldTalk D_800A5544[];
extern u16 D_800A5748[];
extern FieldTalk D_800A5568[];
extern u16 D_800A5750[];
extern FieldTalk D_800A5580[];
extern u16 D_800A5758[];
extern FieldTalk D_800A55E0[];
extern u16 D_800A5760[];
extern FieldTalk D_800A55F8[];
extern u16 D_800A5768[];
extern FieldTalk D_800A5610[];
extern u16 D_800A5770[];
extern FieldTalk D_800A5628[];
extern u16 D_800A5778[];
extern FieldTalk D_800A5640[];
extern u16 D_800A5780[];
extern FieldTalk D_800A5658[];
extern u16 D_800A5788[];
extern FieldTalk D_800A5670[];
extern u16 D_800A5790[];
extern FieldTalk D_800A5688[];
extern u16 D_800A5798[];
extern FieldTalk D_800A56A0[];
extern u16 D_800A57A0[];
extern FieldTalk D_800A56B8[];
extern FieldActorEntry D_800A57A8;
extern FieldActorEntry D_800A57BC;
extern FieldActorEntry D_800A57D0;
extern FieldActorEntry D_800A57E4;
extern FieldActorEntry D_800A57F8;
extern FieldActorEntry D_800A580C;
extern FieldActorEntry D_800A5820;
extern FieldActorEntry D_800A5834;
extern FieldActorEntry D_800A5848;
extern FieldActorEntry D_800A585C;
extern FieldActorEntry D_800A5870;
extern FieldActorEntry D_800A5884;
extern FieldActorEntry D_800A5898;
extern FieldActorEntry D_800A58AC;
extern FieldActorEntry D_800A58C0;
extern FieldActorEntry D_800A58D4;
extern FieldActorEntry D_800A58E8;
extern FieldActorEntry D_800A58FC;
extern FieldActorEntry D_800A5910;
extern FieldActorEntry D_800A5924;
extern FieldActorEntry D_800A5938;
extern FieldActorEntry D_800A594C;
extern FieldActorEntry D_800A5960;

Battle D_800A4E34 = { 0, 0, 0x60040000 };
Battle D_800A4E40 = { 0, 0, 0x60040000 };
Battle D_800A4E4C = { 0, 0, 0x60040000 };
Battle D_800A4E58 = { 0, 0, 0x60040000 };
Battle D_800A4E64 = { 0, 0, 0x60040000 };
Battle D_800A4E70 = { 0, 0, 0x60040000 };
Battle D_800A4E7C = { 0, 0, 0x60040000 };
Battle D_800A4E88 = { 0, 0, 0x60040000 };
BattleList D_800A4E94 = {
    0,
    { &D_800A4E34, &D_800A4E40, &D_800A4E4C, &D_800A4E58,
      &D_800A4E64, &D_800A4E70, &D_800A4E7C, &D_800A4E88 },
};
Battle D_800A4EB8 = { 0, 0, 0x60040000 };
Battle D_800A4EC4 = { 0, 0, 0x60040000 };
Battle D_800A4ED0 = { 0, 0, 0x60040000 };
Battle D_800A4EDC = { 0, 0, 0x60040000 };
Battle D_800A4EE8 = { 0, 0, 0x60040000 };
Battle D_800A4EF4 = { 0, 0, 0x60040000 };
Battle D_800A4F00 = { 0, 0, 0x60040000 };
Battle D_800A4F0C = { 0, 0, 0x60040000 };
BattleList D_800A4F18 = {
    0,
    { &D_800A4EB8, &D_800A4EC4, &D_800A4ED0, &D_800A4EDC,
      &D_800A4EE8, &D_800A4EF4, &D_800A4F00, &D_800A4F0C },
};
Battle D_800A4F3C = { 0, 0, 0x60040000 };
Battle D_800A4F48 = { 0, 0, 0x60040000 };
Battle D_800A4F54 = { 0, 0, 0x60040000 };
Battle D_800A4F60 = { 0, 0, 0x60040000 };
Battle D_800A4F6C = { 0, 0, 0x60040000 };
Battle D_800A4F78 = { 0, 0, 0x60040000 };
Battle D_800A4F84 = { 0, 0, 0x60040000 };
Battle D_800A4F90 = { 0, 0, 0x60040000 };
BattleList D_800A4F9C = {
    0,
    { &D_800A4F3C, &D_800A4F48, &D_800A4F54, &D_800A4F60,
      &D_800A4F6C, &D_800A4F78, &D_800A4F84, &D_800A4F90 },
};
Battle D_800A4FC0 = { 222, 20, 0x600C0000 };
Battle D_800A4FCC = { 0, 0, 0x60040000 };
Battle D_800A4FD8 = { 0, 0, 0x60040000 };
Battle D_800A4FE4 = { 0, 0, 0x60040000 };
Battle D_800A4FF0 = { 0, 0, 0x60040000 };
Battle D_800A4FFC = { 0, 0, 0x60040000 };
Battle D_800A5008 = { 0, 0, 0x60040000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
BattleList D_800A5020 = {
    0,
    { &D_800A4FC0, &D_800A4FCC, &D_800A4FD8, &D_800A4FE4,
      &D_800A4FF0, &D_800A4FFC, &D_800A5008, &D_800A5014 },
};
FieldBattles stageBattles[] = {
    { 159, 0, 0, { &D_800A4E94, &D_800A4F18, &D_800A4F9C, &D_800A5020 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1AA, 0x100, 0x1A8, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x172, 0x189, 0xC8, 0x89, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x139, 0xD8, 0x39, 0x160, 0x1FE },
    { 0x140, 0x100, 0x176, 0x161, 0xD8, 0x61, 0x170, 0x1FE },
    { 0x140, 0x100, 0x172, 0x1A9, 0xC8, 0xA9, 0x160, 0x1FD },
    { 0x140, 0x100, 0x172, 0x1C9, 0xC8, 0xC9, 0x170, 0x1FD },
    { 0x140, 0x100, 0x162, 0x1D2, 0x88, 0xD2, 0x160, 0x1FC },
    { 0x140, 0x100, 0x16A, 0x1D2, 0xA8, 0xD2, 0x170, 0x1FC },
    { 0x180, 0x100, 0x1A2, 0x100, 0x188, 0, 0x160, 0x1FB },
};
u16 D_800A5150[] = { 0, 0, 0xFFFF };
u16 D_800A5158[] = { 0, 1, 0xFFFF };
u16 D_800A5160[] = { 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A516C[] = { 0, 1, 0x7206, 1, 0x8014, 0, 0xFFFF };
u16 D_800A517C[] = { 0x7620, 1, 0xFFFF };
u16 D_800A5184[] = { 0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5198[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE16, 0, 0xFFFF,
};
u16 D_800A51B0[] = { 0x7400, 1, 0xE16, 1, 0xFFFF };
u16 D_800A51BC[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE16, 1, 0x720A, 0, 0xFFFF,
};
u16 D_800A51D8[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE16, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A51F4[] = { 0x7820, 1, 0xFFFF };
u16 D_800A51FC[] = { 0x11, 0, 0xFFFF };
u16 D_800A5204[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5210[] = { 0x11, 0, 0xFFFF };
u16 D_800A5218[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5224[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5230[] = { 0, 0, 0xFFFF };
u16 D_800A5238[] = { 0, 1, 0xFFFF };
u16 D_800A5240[] = { 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A524C[] = { 0, 1, 0x7206, 1, 0x8014, 0, 0xFFFF };
u16 D_800A525C[] = { 0x7620, 1, 0xFFFF };
u16 D_800A5264[] = { 0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5278[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE16, 0, 0xFFFF,
};
u16 D_800A5290[] = { 0x7400, 1, 0xE16, 1, 0xFFFF };
u16 D_800A529C[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE16, 1, 0x720A, 0, 0xFFFF,
};
u16 D_800A52B8[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE16, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A52D4[] = { 0x7820, 1, 0xFFFF };
u16 D_800A52DC[] = { 0x8028, 1, 0x8029, 0, 0xFFFF };
u16 D_800A52E8[] = { 0x9405, 1, 0xFFFF };
u16 D_800A52F0[] = { 0x8028, 1, 0x8029, 1, 0xFFFF };
u16 D_800A52FC[] = { 0x9406, 1, 0xFFFF };
u16 D_800A5304[] = { 0x940D, 1, 0xFFFF };
u16 D_800A530C[] = { 0, 0, 0xFFFF };
u16 D_800A5314[] = { 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A5320[] = { 0, 1, 0x7206, 1, 0x8014, 0, 0xFFFF };
u16 D_800A5330[] = { 0x7620, 1, 0xFFFF };
u16 D_800A5338[] = { 0x7206, 1, 0, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A534C[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE16, 0, 0xFFFF,
};
u16 D_800A5364[] = { 0xE16, 1, 0xFFFF };
u16 D_800A536C[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE16, 1, 0x720A, 0, 0xFFFF,
};
u16 D_800A5388[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE16, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A53A4[] = { 0x7820, 1, 0xFFFF };
FieldTalk D_800A53AC[] = {
    { NULL, NULL, 0x223 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53C4[] = {
    { NULL, NULL, 0x226 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53DC[] = {
    { NULL, NULL, 0x224 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53F4[] = {
    { NULL, NULL, 0x21F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A540C[] = {
    { NULL, NULL, 0x222 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5424[] = {
    { NULL, NULL, 0x220 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A543C[] = {
    { D_800A5150, D_800A5158, 0x194 },
    { D_800A5160, NULL, 0x198 },
    { D_800A516C, D_800A517C, 0x199 },
    { D_800A5184, NULL, 0x19A },
    { D_800A5198, D_800A51B0, 0x19B },
    { D_800A51BC, NULL, 0x19C },
    { D_800A51D8, D_800A51F4, 0x19D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A549C[] = {
    { NULL, NULL, 0x299 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B4[] = {
    { D_800A51FC, NULL, 0x194 },
    { D_800A5204, D_800A5210, 0x19E },
    { D_800A5218, D_800A5224, 0x19F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E4[] = {
    { D_800A5230, D_800A5238, 0x195 },
    { D_800A5240, NULL, 0x198 },
    { D_800A524C, D_800A525C, 0x199 },
    { D_800A5264, NULL, 0x19A },
    { D_800A5278, D_800A5290, 0x19B },
    { D_800A529C, NULL, 0x19C },
    { D_800A52B8, D_800A52D4, 0x19D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5544[] = {
    { D_800A52DC, D_800A52E8, 0x30A },
    { D_800A52F0, D_800A52FC, 0x30A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5568[] = {
    { NULL, D_800A5304, 0x30A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5580[] = {
    { D_800A530C, NULL, 0x196 },
    { D_800A5314, NULL, 0x196 },
    { D_800A5320, D_800A5330, 0x196 },
    { D_800A5338, NULL, 0x196 },
    { D_800A534C, D_800A5364, 0x196 },
    { D_800A536C, NULL, 0x196 },
    { D_800A5388, D_800A53A4, 0x196 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55E0[] = {
    { NULL, NULL, 0x225 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55F8[] = {
    { NULL, NULL, 0x221 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5610[] = {
    { NULL, NULL, 0x22E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5628[] = {
    { NULL, NULL, 0x22D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5640[] = {
    { NULL, NULL, 0x22C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5658[] = {
    { NULL, NULL, 0x22B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5670[] = {
    { NULL, NULL, 0x227 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5688[] = {
    { NULL, NULL, 0x22A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56A0[] = {
    { NULL, NULL, 0x228 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56B8[] = {
    { NULL, NULL, 0x229 },
    { NULL, NULL, 0 },
};
u16 D_800A56D0[] = { 0x7019, 1, 0xFFFF };
u16 D_800A56D8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A56E0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A56E8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A56F0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A56F8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5700[] = { 0x11, 0, 0x7004, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5710[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5720[] = { 0x11, 1, 0x7009, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5730[] = { 0x8192, 1, 0x11, 0, 0x6026, 1, 0xFFFF };
u16 D_800A5740[] = { 0x802A, 0, 0xFFFF };
u16 D_800A5748[] = { 0x802A, 1, 0xFFFF };
u16 D_800A5750[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5758[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5760[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5768[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5770[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5778[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5780[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5788[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5790[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5798[] = { 0x6026, 1, 0xFFFF };
u16 D_800A57A0[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A57A8 = { D_800A56D0, D_800A53AC, 0x2D, 4, 537, 145, 3 };
FieldActorEntry D_800A57BC = { D_800A56D8, D_800A53C4, 0x2D, 4, 120, 504, 7 };
FieldActorEntry D_800A57D0 = { D_800A56E0, D_800A53DC, 0x2D, 4, 537, 145, 3 };
FieldActorEntry D_800A57E4 = { D_800A56E8, D_800A53F4, 0x2E, 5, 119, 137, 7 };
FieldActorEntry D_800A57F8 = { D_800A56F0, D_800A540C, 0x2E, 5, 433, 567, 1 };
FieldActorEntry D_800A580C = { D_800A56F8, D_800A5424, 0x2E, 5, 119, 137, 7 };
FieldActorEntry D_800A5820 = { D_800A5700, D_800A543C, 0x35, 6, 321, 217, 1 };
FieldActorEntry D_800A5834 = { D_800A5710, D_800A549C, 0x35, 6, 321, 217, 1 };
FieldActorEntry D_800A5848 = { D_800A5720, D_800A54B4, 0x35, 6, 321, 217, 1 };
FieldActorEntry D_800A585C = { D_800A5730, D_800A54E4, 0x35, 6, 321, 217, 1 };
FieldActorEntry D_800A5870 = { D_800A5740, D_800A5544, 0x88, 7, 124, 700, 7 };
FieldActorEntry D_800A5884 = { D_800A5748, D_800A5568, 0x88, 7, 124, 700, 7 };
FieldActorEntry D_800A5898 = { D_800A5750, D_800A5580, 0x9D, 8, 321, 217, 1 };
FieldActorEntry D_800A58AC = { D_800A5758, D_800A55E0, 0x9E, 9, 537, 145, 3 };
FieldActorEntry D_800A58C0 = { D_800A5760, D_800A55F8, 0x9F, 0xA, 119, 137, 7 };
FieldActorEntry D_800A58D4 = { D_800A5768, D_800A5610, 0xB4, 0xB, 118, 135, 5 };
FieldActorEntry D_800A58E8 = { D_800A5770, D_800A5628, 0xB4, 0xB, 369, 345, 1 };
FieldActorEntry D_800A58FC = { D_800A5778, D_800A5640, 0xB4, 0xB, 369, 345, 1 };
FieldActorEntry D_800A5910 = { D_800A5780, D_800A5658, 0xB4, 0xB, 369, 345, 1 };
FieldActorEntry D_800A5924 = { D_800A5788, D_800A5670, 0xB6, 0xC, 121, 505, 5 };
FieldActorEntry D_800A5938 = { D_800A5790, D_800A5688, 0xB6, 0xC, 272, 90, 1 };
FieldActorEntry D_800A594C = { D_800A5798, D_800A56A0, 0xB6, 0xC, 121, 505, 5 };
FieldActorEntry D_800A5960 = { D_800A57A0, D_800A56B8, 0xB6, 0xC, 121, 505, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A57A8,
    &D_800A57BC,
    &D_800A57D0,
    &D_800A57E4,
    &D_800A57F8,
    &D_800A580C,
    &D_800A5820,
    &D_800A5834,
    &D_800A5848,
    &D_800A585C,
    &D_800A5870,
    &D_800A5884,
    &D_800A5898,
    &D_800A58AC,
    &D_800A58C0,
    &D_800A58D4,
    &D_800A58E8,
    &D_800A58FC,
    &D_800A5910,
    &D_800A5924,
    &D_800A5938,
    &D_800A594C,
    &D_800A5960,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x76, 2, 2, 1, 2, 7, 4, 0, 15, 51, 0, 0 },
    { 1, 0, 0x76, 2, 2, 1, 2, 7, 4, 0, 367, 644, 0, 0 },
    { 1, 0, 0x48, 2, 8, 0, 0, 0, 0, 0, 184, 716, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 106, 91, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 115, 78, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 120, 99, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 189, 348, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 192, 392, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 209, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 317, 142, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 326, 165, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 341, 120, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 361, 421, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 368, 442, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 408, 678, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 421, 702, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 457, 290, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 468, 270, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 502, 466, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 509, 451, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 519, 66, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 522, 96, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 550, 31, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 633, 234, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 703, 228, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 714, 256, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 103, 97, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 115, 85, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 122, 106, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 188, 402, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 192, 354, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 207, 370, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 314, 148, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 328, 171, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 342, 125, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 360, 427, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 371, 449, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 409, 685, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 419, 707, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 454, 296, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 471, 276, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 505, 473, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 506, 456, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 517, 71, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 523, 102, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 553, 36, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 634, 239, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 702, 233, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 717, 264, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 257, 598, 631, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 385, 439, 488, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 495, 232, 286, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x266, 0xC8, 0xAC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x1B0, 0xE8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x1A0, 0x140, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x100, 0x140, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0xF0, 0x198, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x161, 0x200, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x171, 0x258, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 0x12, 0xA2, 0xB0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 0x12, 0xB2, 0x1D8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 0x10, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 6, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
