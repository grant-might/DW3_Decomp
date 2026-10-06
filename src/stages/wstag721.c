#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x666
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x676
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x8C00, 0x2BB00};
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
extern u16 D_800A5120[];
extern u16 D_800A5128[];
extern u16 D_800A5134[];
extern u16 D_800A513C[];
extern u16 D_800A514C[];
extern u16 D_800A515C[];
extern u16 D_800A5170[];
extern u16 D_800A5180[];
extern u16 D_800A518C[];
extern u16 D_800A519C[];
extern u16 D_800A51A8[];
extern u16 D_800A51B8[];
extern u16 D_800A51C0[];
extern u16 D_800A51D0[];
extern u16 D_800A51D8[];
extern u16 D_800A51E8[];
extern u16 D_800A51F0[];
extern u16 D_800A5200[];
extern u16 D_800A5208[];
extern u16 D_800A5218[];
extern u16 D_800A522C[];
extern u16 D_800A5234[];
extern u16 D_800A524C[];
extern u16 D_800A5258[];
extern u16 D_800A5274[];
extern u16 D_800A5294[];
extern u16 D_800A52B4[];
extern u16 D_800A52BC[];
extern u16 D_800A52C4[];
extern u16 D_800A52CC[];
extern u16 D_800A52D4[];
extern u16 D_800A52DC[];
extern u16 D_800A52E8[];
extern u16 D_800A52F0[];
extern u16 D_800A52F8[];
extern u16 D_800A5308[];
extern u16 D_800A5314[];
extern u16 D_800A5324[];
extern u16 D_800A5330[];
extern u16 D_800A5340[];
extern u16 D_800A5348[];
extern u16 D_800A5358[];
extern u16 D_800A5360[];
extern u16 D_800A5370[];
extern u16 D_800A5378[];
extern u16 D_800A5388[];
extern u16 D_800A5390[];
extern u16 D_800A53A0[];
extern u16 D_800A53B4[];
extern u16 D_800A53BC[];
extern u16 D_800A53D4[];
extern u16 D_800A53E0[];
extern u16 D_800A53FC[];
extern u16 D_800A541C[];
extern u16 D_800A543C[];
extern u16 D_800A5444[];
extern u16 D_800A544C[];
extern u16 D_800A5454[];
extern u16 D_800A545C[];
extern u16 D_800A5464[];
extern u16 D_800A5470[];
extern u16 D_800A5478[];
extern u16 D_800A5480[];
extern u16 D_800A548C[];
extern u16 D_800A5494[];
extern u16 D_800A54A0[];
extern u16 D_800A54A8[];
extern u16 D_800A5738[];
extern FieldTalk D_800A54B0[];
extern u16 D_800A574C[];
extern FieldTalk D_800A54EC[];
extern u16 D_800A5758[];
extern FieldTalk D_800A5588[];
extern u16 D_800A5764[];
extern FieldTalk D_800A55B8[];
extern u16 D_800A5770[];
extern FieldTalk D_800A55DC[];
extern u16 D_800A577C[];
extern FieldTalk D_800A5678[];
extern u16 D_800A5788[];
extern FieldTalk D_800A56A8[];
extern u16 D_800A5794[];
extern FieldTalk D_800A56CC[];
extern u16 D_800A579C[];
extern FieldTalk D_800A56F0[];
extern u16 D_800A57A4[];
extern FieldTalk D_800A5708[];
extern u16 D_800A57AC[];
extern FieldTalk D_800A5720[];
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

Battle D_800A4E34 = { 0, 0, 0x60040000 };
Battle D_800A4E40 = { 0, 0, 0x60040000 };
Battle D_800A4E4C = { 0, 0, 0x60040000 };
Battle D_800A4E58 = { 0, 0, 0x60040000 };
Battle D_800A4E64 = { 0, 0, 0x60040000 };
Battle D_800A4E70 = { 0, 0, 0x60040000 };
Battle D_800A4E7C = { 0, 0, 0x60040000 };
Battle D_800A4E88 = { 0, 0, 0x60040000 };
BattleList D_800A4E94 = {
    3,
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
Battle D_800A4FC0 = { 249, 20, 0x600C0000 };
Battle D_800A4FCC = { 250, 20, 0x600C0000 };
Battle D_800A4FD8 = { 297, 18, 0x600C0000 };
Battle D_800A4FE4 = { 298, 18, 0x600C0000 };
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
    { 163, 0, 0, { &D_800A4E94, &D_800A4F18, &D_800A4F9C, &D_800A5020 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x172, 0x174, 0xC8, 0x74, 0x160, 0x1FF },
    { 0x140, 0x100, 0x176, 0x139, 0xD8, 0x39, 0x170, 0x1FF },
    { 0x140, 0x100, 0x148, 0x176, 0x20, 0x76, 0x160, 0x1FE },
    { 0x140, 0x100, 0x140, 0x176, 0, 0x76, 0x170, 0x1FE },
    { 0x140, 0x100, 0x150, 0x176, 0x40, 0x76, 0x160, 0x1FD },
    { 0x140, 0x100, 0x158, 0x176, 0x60, 0x76, 0x170, 0x1FD },
};
u16 D_800A5120[] = { 0x868F, 1, 0xFFFF };
u16 D_800A5128[] = { 2, 0, 0x868F, 0, 0xFFFF };
u16 D_800A5134[] = { 2, 1, 0xFFFF };
u16 D_800A513C[] = { 2, 1, 0x868F, 0, 0x848B, 0, 0xFFFF };
u16 D_800A514C[] = { 2, 1, 0x868F, 0, 0x848B, 1, 0xFFFF };
u16 D_800A515C[] = { 0x868F, 1, 0x868E, 0, 0x848B, 0, 0x7013, 1, 0xFFFF };
u16 D_800A5170[] = { 0x11, 1, 0x10, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5180[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A518C[] = { 0x11, 1, 0x10, 1, 0x6026, 1, 0xFFFF };
u16 D_800A519C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A51A8[] = { 0x11, 1, 0x10, 0, 0x7019, 1, 0xFFFF };
u16 D_800A51B8[] = { 0x11, 0, 0xFFFF };
u16 D_800A51C0[] = { 0x11, 1, 0x10, 0, 0x6026, 1, 0xFFFF };
u16 D_800A51D0[] = { 0x11, 0, 0xFFFF };
u16 D_800A51D8[] = { 0, 0, 0x11, 0, 0x7019, 1, 0xFFFF };
u16 D_800A51E8[] = { 0, 1, 0xFFFF };
u16 D_800A51F0[] = { 0x11, 0, 0, 0, 0x6026, 1, 0xFFFF };
u16 D_800A5200[] = { 0, 1, 0xFFFF };
u16 D_800A5208[] = { 0, 1, 0x7208, 0, 0x11, 0, 0xFFFF };
u16 D_800A5218[] = { 0, 1, 0x7208, 1, 0x720A, 0, 0x11, 0, 0xFFFF };
u16 D_800A522C[] = { 0x7641, 1, 0xFFFF };
u16 D_800A5234[] = {
    0, 1, 0x7208, 1, 0xE34, 0, 0x720A, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A524C[] = { 0xE34, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5258[] = {
    0, 1, 0x7208, 1, 0x8014, 0, 0x720A, 1,
    0xE34, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5274[] = {
    0x720C, 0, 0, 1, 0x7208, 1, 0x8014, 1,
    0x720A, 1, 0xE34, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5294[] = {
    0xE34, 1, 0x720C, 1, 0, 1, 0x7208, 1,
    0x8014, 1, 0x720A, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A52B4[] = { 0x7841, 1, 0xFFFF };
u16 D_800A52BC[] = { 0x11, 0, 0xFFFF };
u16 D_800A52C4[] = { 0x10, 0, 0xFFFF };
u16 D_800A52CC[] = { 0x11, 0, 0xFFFF };
u16 D_800A52D4[] = { 0x10, 1, 0xFFFF };
u16 D_800A52DC[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A52E8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A52F0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A52F8[] = { 0x11, 1, 0x10, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5308[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5314[] = { 0x11, 1, 0x10, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5324[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5330[] = { 0x11, 1, 0x10, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5340[] = { 0x11, 0, 0xFFFF };
u16 D_800A5348[] = { 0x11, 1, 0x10, 0, 0x6026, 1, 0xFFFF };
u16 D_800A5358[] = { 0x11, 0, 0xFFFF };
u16 D_800A5360[] = { 1, 0, 0x11, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5370[] = { 1, 1, 0xFFFF };
u16 D_800A5378[] = { 0x11, 0, 1, 0, 0x6026, 1, 0xFFFF };
u16 D_800A5388[] = { 1, 1, 0xFFFF };
u16 D_800A5390[] = { 1, 1, 0x7208, 0, 0x11, 0, 0xFFFF };
u16 D_800A53A0[] = { 1, 1, 0x7208, 1, 0x720A, 0, 0x11, 0, 0xFFFF };
u16 D_800A53B4[] = { 0x7642, 1, 0xFFFF };
u16 D_800A53BC[] = {
    1, 1, 0x7208, 1, 0xE35, 0, 0x720A, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A53D4[] = { 0xE35, 1, 0x7401, 1, 0xFFFF };
u16 D_800A53E0[] = {
    1, 1, 0x7208, 1, 0x8014, 0, 0x720A, 1,
    0xE35, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A53FC[] = {
    1, 1, 0x7208, 1, 0x8014, 1, 0x720A, 1,
    0xE35, 1, 0x720C, 0, 0x11, 0, 0xFFFF,
};
u16 D_800A541C[] = {
    1, 1, 0x7208, 1, 0x8014, 1, 0x720A, 1,
    0xE35, 1, 0x720C, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A543C[] = { 0x7842, 1, 0xFFFF };
u16 D_800A5444[] = { 0x11, 0, 0xFFFF };
u16 D_800A544C[] = { 0x10, 0, 0xFFFF };
u16 D_800A5454[] = { 0x11, 0, 0xFFFF };
u16 D_800A545C[] = { 0x10, 1, 0xFFFF };
u16 D_800A5464[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5470[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5478[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5480[] = { 0x8028, 1, 0x8029, 0, 0xFFFF };
u16 D_800A548C[] = { 0x940B, 1, 0xFFFF };
u16 D_800A5494[] = { 0x8028, 1, 0x8029, 1, 0xFFFF };
u16 D_800A54A0[] = { 0x940C, 1, 0xFFFF };
u16 D_800A54A8[] = { 0x940D, 1, 0xFFFF };
FieldTalk D_800A54B0[] = {
    { D_800A5120, NULL, 0x306 },
    { D_800A5128, D_800A5134, 0x307 },
    { D_800A513C, NULL, 0x308 },
    { D_800A514C, D_800A515C, 0x309 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54EC[] = {
    { D_800A5170, D_800A5180, 0x2A1 },
    { D_800A518C, D_800A519C, 0x25 },
    { D_800A51A8, D_800A51B8, 0x2A0 },
    { D_800A51C0, D_800A51D0, 0x24 },
    { D_800A51D8, D_800A51E8, 0x29A },
    { D_800A51F0, D_800A5200, 0x23 },
    { D_800A5208, NULL, 0x29C },
    { D_800A5218, D_800A522C, 0x29D },
    { D_800A5234, D_800A524C, 0x29F },
    { D_800A5258, NULL, 0x29E },
    { D_800A5274, NULL, 0x2A3 },
    { D_800A5294, D_800A52B4, 0x2A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5588[] = {
    { D_800A52BC, NULL, 0x2A2 },
    { D_800A52C4, D_800A52CC, 0x2A0 },
    { D_800A52D4, D_800A52DC, 0x2A1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55B8[] = {
    { D_800A52E8, NULL, 0x2A2 },
    { D_800A52F0, NULL, 0x23 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55DC[] = {
    { D_800A52F8, D_800A5308, 0x2AE },
    { D_800A5314, D_800A5324, 0x2E },
    { D_800A5330, D_800A5340, 0x2AD },
    { D_800A5348, D_800A5358, 0x2D },
    { D_800A5360, D_800A5370, 0x2A5 },
    { D_800A5378, D_800A5388, 0x2A5 },
    { D_800A5390, NULL, 0x2A7 },
    { D_800A53A0, D_800A53B4, 0x2A8 },
    { D_800A53BC, D_800A53D4, 0x2AA },
    { D_800A53E0, NULL, 0x2AE },
    { D_800A53FC, NULL, 0x2AB },
    { D_800A541C, D_800A543C, 0x2AC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5678[] = {
    { D_800A5444, NULL, 0x2AF },
    { D_800A544C, D_800A5454, 0x2AD },
    { D_800A545C, D_800A5464, 0x2AE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56A8[] = {
    { D_800A5470, NULL, 0x2AF },
    { D_800A5478, NULL, 0x2C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56CC[] = {
    { D_800A5480, D_800A548C, 0x2DB },
    { D_800A5494, D_800A54A0, 0x2DB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56F0[] = {
    { NULL, D_800A54A8, 0x2DB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5708[] = {
    { NULL, NULL, 0x2B0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5720[] = {
    { NULL, NULL, 0x2B1 },
    { NULL, NULL, 0 },
};
u16 D_800A5738[] = { 0x7049, 1, 0x7051, 1, 0x868E, 1, 0x868F, 0, 0xFFFF };
u16 D_800A574C[] = { 0x8192, 1, 0x701E, 1, 0xFFFF };
u16 D_800A5758[] = { 0x8192, 1, 0x602B, 1, 0xFFFF };
u16 D_800A5764[] = { 0x8192, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5770[] = { 0x8192, 1, 0x701E, 1, 0xFFFF };
u16 D_800A577C[] = { 0x8192, 1, 0x602B, 1, 0xFFFF };
u16 D_800A5788[] = { 0x8192, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5794[] = { 0x802A, 0, 0xFFFF };
u16 D_800A579C[] = { 0x802A, 1, 0xFFFF };
u16 D_800A57A4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57AC[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A57B4 = { D_800A5738, D_800A54B0, 0x1F, 4, 538, 145, 1 };
FieldActorEntry D_800A57C8 = { D_800A574C, D_800A54EC, 0x36, 5, 320, 216, 1 };
FieldActorEntry D_800A57DC = { D_800A5758, D_800A5588, 0x36, 5, 320, 216, 1 };
FieldActorEntry D_800A57F0 = { D_800A5764, D_800A55B8, 0x36, 5, 320, 216, 1 };
FieldActorEntry D_800A5804 = { D_800A5770, D_800A55DC, 0x39, 6, 203, 152, 1 };
FieldActorEntry D_800A5818 = { D_800A577C, D_800A5678, 0x39, 6, 273, 89, 1 };
FieldActorEntry D_800A582C = { D_800A5788, D_800A56A8, 0x39, 6, 203, 152, 1 };
FieldActorEntry D_800A5840 = { D_800A5794, D_800A56CC, 0x8C, 7, 124, 700, 7 };
FieldActorEntry D_800A5854 = { D_800A579C, D_800A56F0, 0x8C, 7, 124, 700, 7 };
FieldActorEntry D_800A5868 = { D_800A57A4, D_800A5708, 0x9D, 8, 320, 216, 1 };
FieldActorEntry D_800A587C = { D_800A57AC, D_800A5720, 0x9E, 9, 203, 152, 1 };
FieldActorEntry *stageActors[] = {
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
    { 1, 0, 0x76, 2, 2, 0, 0, 0, 0, 0, 15, 51, 0, 0 },
    { 1, 0, 0x76, 2, 2, 0, 0, 0, 0, 0, 367, 644, 0, 0 },
    { 1, 0, 0x48, 2, 3, 0, 0, 0, 0, 0, 184, 716, 0, 0 },
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
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 495, 232, 286, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CE, 0xC8, 0xAC, 7, 0, 0, 0 },
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
