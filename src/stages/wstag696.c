#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x5F3
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x603
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xBA00, 0x24900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2F;
    D_800990B4.music = 0x60BC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E4C;
extern Battle D_800A4E58;
extern Battle D_800A4E64;
extern Battle D_800A4E70;
extern Battle D_800A4E7C;
extern Battle D_800A4E88;
extern Battle D_800A4E94;
extern Battle D_800A4EA0;
extern Battle D_800A4ED0;
extern Battle D_800A4EDC;
extern Battle D_800A4EE8;
extern Battle D_800A4EF4;
extern Battle D_800A4F00;
extern Battle D_800A4F0C;
extern Battle D_800A4F18;
extern Battle D_800A4F24;
extern Battle D_800A4F54;
extern Battle D_800A4F60;
extern Battle D_800A4F6C;
extern Battle D_800A4F78;
extern Battle D_800A4F84;
extern Battle D_800A4F90;
extern Battle D_800A4F9C;
extern Battle D_800A4FA8;
extern Battle D_800A4FD8;
extern Battle D_800A4FE4;
extern Battle D_800A4FF0;
extern Battle D_800A4FFC;
extern Battle D_800A5008;
extern Battle D_800A5014;
extern Battle D_800A5020;
extern Battle D_800A502C;
extern BattleList D_800A4EAC;
extern BattleList D_800A4F30;
extern BattleList D_800A4FB4;
extern BattleList D_800A5038;
extern u16 D_800A5138[];
extern u16 D_800A5140[];
extern u16 D_800A5148[];
extern u16 D_800A5154[];
extern u16 D_800A5164[];
extern u16 D_800A5170[];
extern u16 D_800A5184[];
extern u16 D_800A5198[];
extern u16 D_800A51A0[];
extern u16 D_800A51AC[];
extern u16 D_800A51B8[];
extern u16 D_800A51C4[];
extern u16 D_800A51CC[];
extern u16 D_800A51D8[];
extern u16 D_800A51E0[];
extern u16 D_800A51F0[];
extern u16 D_800A5204[];
extern u16 D_800A520C[];
extern u16 D_800A5224[];
extern u16 D_800A5230[];
extern u16 D_800A524C[];
extern u16 D_800A526C[];
extern u16 D_800A528C[];
extern u16 D_800A5294[];
extern u16 D_800A529C[];
extern u16 D_800A52A4[];
extern u16 D_800A52AC[];
extern u16 D_800A52B4[];
extern u16 D_800A52C0[];
extern u16 D_800A52C8[];
extern u16 D_800A52D0[];
extern u16 D_800A52DC[];
extern u16 D_800A52EC[];
extern u16 D_800A52F8[];
extern u16 D_800A530C[];
extern u16 D_800A5320[];
extern u16 D_800A5328[];
extern u16 D_800A5334[];
extern u16 D_800A5340[];
extern u16 D_800A534C[];
extern u16 D_800A5354[];
extern u16 D_800A5360[];
extern u16 D_800A5368[];
extern u16 D_800A5378[];
extern u16 D_800A538C[];
extern u16 D_800A5394[];
extern u16 D_800A53AC[];
extern u16 D_800A53B8[];
extern u16 D_800A53D4[];
extern u16 D_800A53F4[];
extern u16 D_800A5414[];
extern u16 D_800A541C[];
extern u16 D_800A5424[];
extern u16 D_800A542C[];
extern u16 D_800A5434[];
extern u16 D_800A543C[];
extern u16 D_800A56E8[];
extern FieldTalk D_800A5448[];
extern u16 D_800A56F4[];
extern FieldTalk D_800A5460[];
extern u16 D_800A5700[];
extern FieldTalk D_800A5478[];
extern u16 D_800A5708[];
extern FieldTalk D_800A54C0[];
extern u16 D_800A5714[];
extern FieldTalk D_800A5538[];
extern u16 D_800A571C[];
extern FieldTalk D_800A5568[];
extern u16 D_800A5728[];
extern FieldTalk D_800A5580[];
extern u16 D_800A5730[];
extern FieldTalk D_800A55C8[];
extern u16 D_800A573C[];
extern FieldTalk D_800A5640[];
extern u16 D_800A5744[];
extern FieldTalk D_800A5670[];
extern u16 D_800A5750[];
extern FieldTalk D_800A5688[];
extern u16 D_800A575C[];
extern FieldTalk D_800A56A0[];
extern u16 D_800A5764[];
extern FieldTalk D_800A56B8[];
extern u16 D_800A5770[];
extern FieldTalk D_800A56D0[];
extern FieldActorEntry D_800A5778;
extern FieldActorEntry D_800A578C;
extern FieldActorEntry D_800A57A0;
extern FieldActorEntry D_800A57B4;
extern FieldActorEntry D_800A57C8;
extern FieldActorEntry D_800A57DC;
extern FieldActorEntry D_800A57F0;
extern FieldActorEntry D_800A5804;
extern FieldActorEntry D_800A5818;
extern FieldActorEntry D_800A582C;
extern FieldActorEntry D_800A5840;
extern FieldActorEntry D_800A5854;
extern FieldActorEntry D_800A5868;
extern FieldActorEntry D_800A587C;

Battle D_800A4E4C = { 184, 14, 0x60080000 };
Battle D_800A4E58 = { 184, 14, 0x60080000 };
Battle D_800A4E64 = { 184, 14, 0x60080000 };
Battle D_800A4E70 = { 184, 14, 0x60080000 };
Battle D_800A4E7C = { 160, 14, 0x60080000 };
Battle D_800A4E88 = { 160, 14, 0x60080000 };
Battle D_800A4E94 = { 160, 14, 0x60080000 };
Battle D_800A4EA0 = { 160, 14, 0x60080000 };
BattleList D_800A4EAC = {
    3,
    { &D_800A4E4C, &D_800A4E58, &D_800A4E64, &D_800A4E70,
      &D_800A4E7C, &D_800A4E88, &D_800A4E94, &D_800A4EA0 },
};
Battle D_800A4ED0 = { 0, 0, 0x60040000 };
Battle D_800A4EDC = { 0, 0, 0x60040000 };
Battle D_800A4EE8 = { 0, 0, 0x60040000 };
Battle D_800A4EF4 = { 0, 0, 0x60040000 };
Battle D_800A4F00 = { 0, 0, 0x60040000 };
Battle D_800A4F0C = { 0, 0, 0x60040000 };
Battle D_800A4F18 = { 0, 0, 0x60040000 };
Battle D_800A4F24 = { 0, 0, 0x60040000 };
BattleList D_800A4F30 = {
    0,
    { &D_800A4ED0, &D_800A4EDC, &D_800A4EE8, &D_800A4EF4,
      &D_800A4F00, &D_800A4F0C, &D_800A4F18, &D_800A4F24 },
};
Battle D_800A4F54 = { 0, 0, 0x60040000 };
Battle D_800A4F60 = { 0, 0, 0x60040000 };
Battle D_800A4F6C = { 0, 0, 0x60040000 };
Battle D_800A4F78 = { 0, 0, 0x60040000 };
Battle D_800A4F84 = { 0, 0, 0x60040000 };
Battle D_800A4F90 = { 0, 0, 0x60040000 };
Battle D_800A4F9C = { 0, 0, 0x60040000 };
Battle D_800A4FA8 = { 0, 0, 0x60040000 };
BattleList D_800A4FB4 = {
    0,
    { &D_800A4F54, &D_800A4F60, &D_800A4F6C, &D_800A4F78,
      &D_800A4F84, &D_800A4F90, &D_800A4F9C, &D_800A4FA8 },
};
Battle D_800A4FD8 = { 245, 14, 0x60080000 };
Battle D_800A4FE4 = { 246, 14, 0x60080000 };
Battle D_800A4FF0 = { 293, 14, 0x600C0000 };
Battle D_800A4FFC = { 333, 14, 0x60080000 };
Battle D_800A5008 = { 0, 0, 0x60040000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 187, 14, 0x60080000 };
Battle D_800A502C = { 0, 0, 0x60040000 };
BattleList D_800A5038 = {
    0,
    { &D_800A4FD8, &D_800A4FE4, &D_800A4FF0, &D_800A4FFC,
      &D_800A5008, &D_800A5014, &D_800A5020, &D_800A502C },
};
FieldBattles stageBattles[] = {
    { 115, 0, 0, { &D_800A4EAC, &D_800A4F30, &D_800A4FB4, &D_800A5038 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14C, 0x1C8, 0x30, 0xC8, 0x170, 0x1FE },
    { 0x140, 0x100, 0x154, 0x1C8, 0x50, 0xC8, 0x170, 0x1FD },
    { 0x180, 0x100, 0x180, 0x100, 0x100, 0, 0x170, 0x1FC },
    { 0x180, 0x100, 0x188, 0x100, 0x120, 0, 0x160, 0x1FB },
    { 0x180, 0x100, 0x190, 0x100, 0x140, 0, 0x170, 0x1FB },
    { 0x180, 0x100, 0x198, 0x100, 0x160, 0, 0x160, 0x1FA },
};
u16 D_800A5138[] = { 1, 0, 0xFFFF };
u16 D_800A5140[] = { 1, 0, 0xFFFF };
u16 D_800A5148[] = { 1, 1, 0x720B, 0, 0xFFFF };
u16 D_800A5154[] = { 1, 1, 0x720B, 1, 0xE51, 0, 0xFFFF };
u16 D_800A5164[] = { 0xE51, 1, 0x7401, 1, 0xFFFF };
u16 D_800A5170[] = { 1, 1, 0x720B, 1, 0xE51, 1, 0x720D, 0, 0xFFFF };
u16 D_800A5184[] = { 1, 1, 0x720B, 1, 0xE51, 1, 0x720D, 1, 0xFFFF };
u16 D_800A5198[] = { 0x783E, 1, 0xFFFF };
u16 D_800A51A0[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A51AC[] = { 0x10, 0, 0x11, 0, 0xFFFF };
u16 D_800A51B8[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A51C4[] = { 0x11, 0, 0xFFFF };
u16 D_800A51CC[] = { 0, 0, 0x11, 0, 0xFFFF };
u16 D_800A51D8[] = { 0, 1, 0xFFFF };
u16 D_800A51E0[] = { 0x7208, 0, 0, 1, 0x11, 0, 0xFFFF };
u16 D_800A51F0[] = { 0x7208, 1, 0, 1, 0x11, 0, 0x720A, 0, 0xFFFF };
u16 D_800A5204[] = { 0x763E, 1, 0xFFFF };
u16 D_800A520C[] = {
    0xE31, 0, 0x720A, 1, 0x7208, 1, 0, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A5224[] = { 0x7401, 1, 0xE31, 1, 0xFFFF };
u16 D_800A5230[] = {
    0x8014, 0, 0xE31, 1, 0x720A, 1, 0x7208, 1,
    0, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A524C[] = {
    0xE31, 1, 0x720B, 0, 0x8014, 1, 0x720A, 1,
    0x7208, 1, 0, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A526C[] = {
    0, 1, 0x11, 0, 0x720A, 1, 0x720B, 1,
    0x8014, 1, 0xE31, 1, 0x7208, 1, 0xFFFF,
};
u16 D_800A528C[] = { 0x783E, 1, 0xFFFF };
u16 D_800A5294[] = { 0x11, 0, 0xFFFF };
u16 D_800A529C[] = { 0x10, 0, 0xFFFF };
u16 D_800A52A4[] = { 0x11, 0, 0xFFFF };
u16 D_800A52AC[] = { 0x10, 1, 0xFFFF };
u16 D_800A52B4[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A52C0[] = { 0, 0, 0xFFFF };
u16 D_800A52C8[] = { 0, 1, 0xFFFF };
u16 D_800A52D0[] = { 0, 1, 0x720B, 0, 0xFFFF };
u16 D_800A52DC[] = { 0, 1, 0x720B, 1, 0xE52, 0, 0xFFFF };
u16 D_800A52EC[] = { 0xE52, 1, 0x7400, 1, 0xFFFF };
u16 D_800A52F8[] = { 0, 1, 0x720B, 1, 0xE52, 1, 0x720D, 0, 0xFFFF };
u16 D_800A530C[] = { 0, 1, 0x720B, 1, 0xE52, 1, 0x720D, 1, 0xFFFF };
u16 D_800A5320[] = { 0x783D, 1, 0xFFFF };
u16 D_800A5328[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5334[] = { 0x10, 0, 0x11, 0, 0xFFFF };
u16 D_800A5340[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A534C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5354[] = { 1, 0, 0x11, 0, 0xFFFF };
u16 D_800A5360[] = { 1, 1, 0xFFFF };
u16 D_800A5368[] = { 0x7208, 0, 1, 1, 0x11, 0, 0xFFFF };
u16 D_800A5378[] = { 0x720A, 0, 0x7208, 1, 1, 1, 0x11, 0, 0xFFFF };
u16 D_800A538C[] = { 0x763D, 1, 0xFFFF };
u16 D_800A5394[] = {
    0xE30, 0, 0x720A, 1, 0x7208, 1, 1, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A53AC[] = { 0x7400, 1, 0xE30, 1, 0xFFFF };
u16 D_800A53B8[] = {
    0x8014, 0, 0xE30, 1, 0x720A, 1, 0x7208, 1,
    1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A53D4[] = {
    0x720B, 0, 0x8014, 1, 0xE30, 1, 0x720A, 1,
    0x7208, 1, 1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A53F4[] = {
    0x720B, 1, 0x8014, 1, 0xE30, 1, 0x720A, 1,
    0x7208, 1, 1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5414[] = { 0x783D, 1, 0xFFFF };
u16 D_800A541C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5424[] = { 0x10, 0, 0xFFFF };
u16 D_800A542C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5434[] = { 0x10, 1, 0xFFFF };
u16 D_800A543C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
FieldTalk D_800A5448[] = {
    { NULL, NULL, 0x264 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5460[] = {
    { NULL, NULL, 0x266 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5478[] = {
    { D_800A5138, D_800A5140, 0x24C },
    { D_800A5148, NULL, 0x24E },
    { D_800A5154, D_800A5164, 0x24D },
    { D_800A5170, NULL, 0x248 },
    { D_800A5184, D_800A5198, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54C0[] = {
    { D_800A51A0, D_800A51AC, 0x24A },
    { D_800A51B8, D_800A51C4, 0x249 },
    { D_800A51CC, D_800A51D8, 0x244 },
    { D_800A51E0, NULL, 0x245 },
    { D_800A51F0, D_800A5204, 0x246 },
    { D_800A520C, D_800A5224, 0x247 },
    { D_800A5230, NULL, 0x248 },
    { D_800A524C, NULL, 0x24B },
    { D_800A526C, D_800A528C, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5538[] = {
    { D_800A5294, NULL, 0x39B },
    { D_800A529C, D_800A52A4, 0x249 },
    { D_800A52AC, D_800A52B4, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5568[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5580[] = {
    { D_800A52C0, D_800A52C8, 0x22C },
    { D_800A52D0, NULL, 0x22E },
    { D_800A52DC, D_800A52EC, 0x22D },
    { D_800A52F8, NULL, 0x228 },
    { D_800A530C, D_800A5320, 0x22F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55C8[] = {
    { D_800A5328, D_800A5334, 0x22A },
    { D_800A5340, D_800A534C, 0x229 },
    { D_800A5354, D_800A5360, 0x224 },
    { D_800A5368, NULL, 0x225 },
    { D_800A5378, D_800A538C, 0x226 },
    { D_800A5394, D_800A53AC, 0x227 },
    { D_800A53B8, NULL, 0x228 },
    { D_800A53D4, NULL, 0x22C },
    { D_800A53F4, D_800A5414, 0x226 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5640[] = {
    { D_800A541C, NULL, 0x39D },
    { D_800A5424, D_800A542C, 0x229 },
    { D_800A5434, D_800A543C, 0x22A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5670[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5688[] = {
    { NULL, NULL, 0x267 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56A0[] = {
    { NULL, NULL, 0x267 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56B8[] = {
    { NULL, NULL, 0x265 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56D0[] = {
    { NULL, NULL, 0x265 },
    { NULL, NULL, 0 },
};
u16 D_800A56E8[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A56F4[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5700[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5708[] = { 0x8192, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5714[] = { 0x602B, 1, 0xFFFF };
u16 D_800A571C[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5728[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5730[] = { 0x7019, 1, 0x8192, 1, 0xFFFF };
u16 D_800A573C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5744[] = { 0x7019, 1, 0x8192, 0, 0xFFFF };
u16 D_800A5750[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A575C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5764[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5770[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5778 = { D_800A56E8, D_800A5448, 0x31, 4, 656, 409, 1 };
FieldActorEntry D_800A578C = { D_800A56F4, D_800A5460, 0x37, 5, 272, 825, 3 };
FieldActorEntry D_800A57A0 = { D_800A5700, D_800A5478, 0x45, 6, 721, 569, 1 };
FieldActorEntry D_800A57B4 = { D_800A5708, D_800A54C0, 0x45, 6, 721, 569, 1 };
FieldActorEntry D_800A57C8 = { D_800A5714, D_800A5538, 0x45, 6, 721, 569, 1 };
FieldActorEntry D_800A57DC = { D_800A571C, D_800A5568, 0x45, 6, 721, 569, 1 };
FieldActorEntry D_800A57F0 = { D_800A5728, D_800A5580, 0x46, 7, 353, 320, 7 };
FieldActorEntry D_800A5804 = { D_800A5730, D_800A55C8, 0x46, 7, 353, 320, 7 };
FieldActorEntry D_800A5818 = { D_800A573C, D_800A5640, 0x46, 7, 353, 320, 7 };
FieldActorEntry D_800A582C = { D_800A5744, D_800A5670, 0x46, 7, 353, 320, 7 };
FieldActorEntry D_800A5840 = { D_800A5750, D_800A5688, 0x9D, 8, 272, 825, 3 };
FieldActorEntry D_800A5854 = { D_800A575C, D_800A56A0, 0x9D, 8, 272, 825, 3 };
FieldActorEntry D_800A5868 = { D_800A5764, D_800A56B8, 0x9E, 9, 656, 409, 1 };
FieldActorEntry D_800A587C = { D_800A5770, D_800A56D0, 0x9E, 9, 656, 409, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5778,
    &D_800A578C,
    &D_800A57A0,
    &D_800A57B4,
    &D_800A57C8,
    &D_800A57DC,
    &D_800A57F0,
    &D_800A5804,
    &D_800A5818,
    &D_800A582C,
    &D_800A5840,
    &D_800A5854,
    &D_800A5868,
    &D_800A587C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 6, 0, 472, 329, 0, 0 },
    { 1, 0, 0xC8, 2, 0x34, 1, 0x34, 0x37, 8, 0, 542, 48, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 90, 310, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 584, 768, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 1032, 512, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xD, 6, 0, 579, 336, 0, 0 },
    { 1, 0x64, 0x40, 6, 1, 0, 0, 0, 0, 0, 546, 340, 0, 0 },
    { 1, 0, 0x48, 4, 0, 0, 0, 0, 0, 0, 517, 329, 393, 0 },
    { 1, 0, 0x53, 4, 8, 0, 0, 0, 0, 0, 448, 290, 368, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 192, 783, 783, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 400, 263, 263, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 672, 175, 175, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 720, 199, 199, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C9, 0x500, 0x290, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C9, 0x500, 0x300, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CC, 0x238, 0x444, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CB, 0x108, 0x12C, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x1CE, 0xAA, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x1BF, 0x112, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x3B0, 0x16A, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x3BF, 0x1D0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x380, 0x253, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x38F, 0x2EA, 0, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x14, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 7, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
