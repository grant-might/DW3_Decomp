#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x5B6
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x5C6
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x20000, 0x2AA00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x12;
    D_800990B4.music = 0x60480000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4E7C;
extern Battle D_800A4E88;
extern Battle D_800A4E94;
extern Battle D_800A4EA0;
extern Battle D_800A4EAC;
extern Battle D_800A4EB8;
extern Battle D_800A4EC4;
extern Battle D_800A4ED0;
extern Battle D_800A4F00;
extern Battle D_800A4F0C;
extern Battle D_800A4F18;
extern Battle D_800A4F24;
extern Battle D_800A4F30;
extern Battle D_800A4F3C;
extern Battle D_800A4F48;
extern Battle D_800A4F54;
extern Battle D_800A4F84;
extern Battle D_800A4F90;
extern Battle D_800A4F9C;
extern Battle D_800A4FA8;
extern Battle D_800A4FB4;
extern Battle D_800A4FC0;
extern Battle D_800A4FCC;
extern Battle D_800A4FD8;
extern Battle D_800A5008;
extern Battle D_800A5014;
extern Battle D_800A5020;
extern Battle D_800A502C;
extern Battle D_800A5038;
extern Battle D_800A5044;
extern Battle D_800A5050;
extern Battle D_800A505C;
extern BattleList D_800A4EDC;
extern BattleList D_800A4F60;
extern BattleList D_800A4FE4;
extern BattleList D_800A5068;
extern u16 D_800A51D8[];
extern u16 D_800A51E0[];
extern u16 D_800A51E8[];
extern u16 D_800A51F0[];
extern u16 D_800A51FC[];
extern u16 D_800A5208[];
extern u16 D_800A5214[];
extern u16 D_800A521C[];
extern u16 D_800A5228[];
extern u16 D_800A5230[];
extern u16 D_800A5240[];
extern u16 D_800A5254[];
extern u16 D_800A525C[];
extern u16 D_800A5274[];
extern u16 D_800A5280[];
extern u16 D_800A529C[];
extern u16 D_800A52BC[];
extern u16 D_800A52DC[];
extern u16 D_800A52E4[];
extern u16 D_800A52EC[];
extern u16 D_800A52F4[];
extern u16 D_800A5300[];
extern u16 D_800A5310[];
extern u16 D_800A531C[];
extern u16 D_800A5330[];
extern u16 D_800A5344[];
extern u16 D_800A534C[];
extern u16 D_800A5354[];
extern u16 D_800A535C[];
extern u16 D_800A5364[];
extern u16 D_800A536C[];
extern u16 D_800A5378[];
extern u16 D_800A5384[];
extern u16 D_800A5390[];
extern u16 D_800A539C[];
extern u16 D_800A53A4[];
extern u16 D_800A53B0[];
extern u16 D_800A53B8[];
extern u16 D_800A53C8[];
extern u16 D_800A53DC[];
extern u16 D_800A53E4[];
extern u16 D_800A53FC[];
extern u16 D_800A5408[];
extern u16 D_800A5424[];
extern u16 D_800A5444[];
extern u16 D_800A5464[];
extern u16 D_800A546C[];
extern u16 D_800A5474[];
extern u16 D_800A547C[];
extern u16 D_800A5488[];
extern u16 D_800A5498[];
extern u16 D_800A54A4[];
extern u16 D_800A54B8[];
extern u16 D_800A54CC[];
extern u16 D_800A54D4[];
extern u16 D_800A54DC[];
extern u16 D_800A54E4[];
extern u16 D_800A54EC[];
extern u16 D_800A54F4[];
extern u16 D_800A5500[];
extern u16 D_800A5508[];
extern u16 D_800A5514[];
extern u16 D_800A5520[];
extern FieldTalk D_800A5528[];
extern FieldTalk D_800A5540[];
extern FieldTalk D_800A5558[];
extern u16 D_800A5894[];
extern FieldTalk D_800A5570[];
extern u16 D_800A58A0[];
extern FieldTalk D_800A5588[];
extern u16 D_800A58AC[];
extern FieldTalk D_800A55A0[];
extern u16 D_800A58B8[];
extern FieldTalk D_800A55B8[];
extern u16 D_800A58C4[];
extern FieldTalk D_800A5630[];
extern u16 D_800A58CC[];
extern FieldTalk D_800A5678[];
extern u16 D_800A58D4[];
extern FieldTalk D_800A56A8[];
extern u16 D_800A58E0[];
extern FieldTalk D_800A56C0[];
extern u16 D_800A58EC[];
extern FieldTalk D_800A5738[];
extern u16 D_800A58F4[];
extern FieldTalk D_800A5780[];
extern u16 D_800A58FC[];
extern FieldTalk D_800A57B0[];
extern u16 D_800A5908[];
extern FieldTalk D_800A57C8[];
extern u16 D_800A5914[];
extern FieldTalk D_800A57E0[];
extern u16 D_800A591C[];
extern FieldTalk D_800A57F8[];
extern u16 D_800A5928[];
extern FieldTalk D_800A5810[];
extern u16 D_800A5930[];
extern FieldTalk D_800A5828[];
extern u16 D_800A593C[];
extern FieldTalk D_800A5840[];
extern FieldTalk D_800A5858[];
extern FieldTalk D_800A5870[];
extern FieldActorEntry D_800A5944;
extern FieldActorEntry D_800A5958;
extern FieldActorEntry D_800A596C;
extern FieldActorEntry D_800A5980;
extern FieldActorEntry D_800A5994;
extern FieldActorEntry D_800A59A8;
extern FieldActorEntry D_800A59BC;
extern FieldActorEntry D_800A59D0;
extern FieldActorEntry D_800A59E4;
extern FieldActorEntry D_800A59F8;
extern FieldActorEntry D_800A5A0C;
extern FieldActorEntry D_800A5A20;
extern FieldActorEntry D_800A5A34;
extern FieldActorEntry D_800A5A48;
extern FieldActorEntry D_800A5A5C;
extern FieldActorEntry D_800A5A70;
extern FieldActorEntry D_800A5A84;
extern FieldActorEntry D_800A5A98;
extern FieldActorEntry D_800A5AAC;
extern FieldActorEntry D_800A5AC0;
extern FieldActorEntry D_800A5AD4;
extern FieldActorEntry D_800A5AE8;

Battle D_800A4E7C = { 0, 0, 0x60040000 };
Battle D_800A4E88 = { 0, 0, 0x60040000 };
Battle D_800A4E94 = { 0, 0, 0x60040000 };
Battle D_800A4EA0 = { 0, 0, 0x60040000 };
Battle D_800A4EAC = { 0, 0, 0x60040000 };
Battle D_800A4EB8 = { 0, 0, 0x60040000 };
Battle D_800A4EC4 = { 0, 0, 0x60040000 };
Battle D_800A4ED0 = { 0, 0, 0x60040000 };
BattleList D_800A4EDC = {
    3,
    { &D_800A4E7C, &D_800A4E88, &D_800A4E94, &D_800A4EA0,
      &D_800A4EAC, &D_800A4EB8, &D_800A4EC4, &D_800A4ED0 },
};
Battle D_800A4F00 = { 0, 0, 0x60040000 };
Battle D_800A4F0C = { 0, 0, 0x60040000 };
Battle D_800A4F18 = { 0, 0, 0x60040000 };
Battle D_800A4F24 = { 0, 0, 0x60040000 };
Battle D_800A4F30 = { 0, 0, 0x60040000 };
Battle D_800A4F3C = { 0, 0, 0x60040000 };
Battle D_800A4F48 = { 0, 0, 0x60040000 };
Battle D_800A4F54 = { 0, 0, 0x60040000 };
BattleList D_800A4F60 = {
    0,
    { &D_800A4F00, &D_800A4F0C, &D_800A4F18, &D_800A4F24,
      &D_800A4F30, &D_800A4F3C, &D_800A4F48, &D_800A4F54 },
};
Battle D_800A4F84 = { 0, 0, 0x60040000 };
Battle D_800A4F90 = { 0, 0, 0x60040000 };
Battle D_800A4F9C = { 0, 0, 0x60040000 };
Battle D_800A4FA8 = { 0, 0, 0x60040000 };
Battle D_800A4FB4 = { 0, 0, 0x60040000 };
Battle D_800A4FC0 = { 0, 0, 0x60040000 };
Battle D_800A4FCC = { 0, 0, 0x60040000 };
Battle D_800A4FD8 = { 0, 0, 0x60040000 };
BattleList D_800A4FE4 = {
    0,
    { &D_800A4F84, &D_800A4F90, &D_800A4F9C, &D_800A4FA8,
      &D_800A4FB4, &D_800A4FC0, &D_800A4FCC, &D_800A4FD8 },
};
Battle D_800A5008 = { 232, 18, 0x60080000 };
Battle D_800A5014 = { 233, 18, 0x60080000 };
Battle D_800A5020 = { 280, 18, 0x600C0000 };
Battle D_800A502C = { 281, 18, 0x600C0000 };
Battle D_800A5038 = { 0, 0, 0x60040000 };
Battle D_800A5044 = { 0, 0, 0x60040000 };
Battle D_800A5050 = { 0, 0, 0x60040000 };
Battle D_800A505C = { 0, 0, 0x60040000 };
BattleList D_800A5068 = {
    0,
    { &D_800A5008, &D_800A5014, &D_800A5020, &D_800A502C,
      &D_800A5038, &D_800A5044, &D_800A5050, &D_800A505C },
};
FieldBattles stageBattles[] = {
    { 160, 0, 0, { &D_800A4EDC, &D_800A4F60, &D_800A4FE4, &D_800A5068 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x195, 0, 0x95, 0x160, 0x1FF },
    { 0x140, 0x100, 0x148, 0x19D, 0x20, 0x9D, 0x170, 0x1FF },
    { 0x140, 0x100, 0x140, 0x16D, 0, 0x6D, 0x150, 0x1FE },
    { 0x140, 0x100, 0x140, 0x1D5, 0, 0xD5, 0x160, 0x1FE },
    { 0x140, 0x100, 0x14A, 0x1BD, 0x28, 0xBD, 0x170, 0x1FE },
    { 0x140, 0x100, 0x152, 0x1A4, 0x48, 0xA4, 0x150, 0x1FD },
    { 0x140, 0x100, 0x15A, 0x1A4, 0x68, 0xA4, 0x160, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x1A4, 0xB8, 0xA4, 0x170, 0x1FD },
    { 0x140, 0x100, 0x162, 0x1C1, 0x88, 0xC1, 0x150, 0x1FC },
    { 0x140, 0x100, 0x176, 0x1C4, 0xD8, 0xC4, 0x160, 0x1FC },
    { 0x140, 0x100, 0x152, 0x1CC, 0x48, 0xCC, 0x170, 0x1FC },
    { 0x140, 0x100, 0x15A, 0x1CC, 0x68, 0xCC, 0x140, 0x1FB },
    { 0x140, 0x100, 0x14C, 0x16D, 0x30, 0x6D, 0x150, 0x1FB },
};
u16 D_800A51D8[] = { 0x7A18, 1, 0xFFFF };
u16 D_800A51E0[] = { 0x7A16, 1, 0xFFFF };
u16 D_800A51E8[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A51F0[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A51FC[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5208[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5214[] = { 0x11, 0, 0xFFFF };
u16 D_800A521C[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A5228[] = { 0, 1, 0xFFFF };
u16 D_800A5230[] = { 0x11, 0, 0, 1, 0x7205, 0, 0xFFFF };
u16 D_800A5240[] = { 0x11, 0, 0, 1, 0x7205, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5254[] = { 0x7631, 1, 0xFFFF };
u16 D_800A525C[] = {
    0x11, 0, 0, 1, 0x7205, 1, 0x7208, 1,
    0xE23, 0, 0xFFFF,
};
u16 D_800A5274[] = { 0xE23, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5280[] = {
    0, 1, 0x7205, 1, 0x7208, 1, 0xE23, 1,
    0x8014, 0, 0x11, 0, 0xFFFF,
};
u16 D_800A529C[] = {
    0x11, 0, 0, 1, 0x7205, 1, 0x7208, 1,
    0xE23, 1, 0x8014, 1, 0x7209, 0, 0xFFFF,
};
u16 D_800A52BC[] = {
    0x11, 0, 0, 1, 0x7205, 1, 0x7208, 1,
    0xE23, 1, 0x8014, 1, 0x7209, 1, 0xFFFF,
};
u16 D_800A52DC[] = { 0x7831, 1, 0xFFFF };
u16 D_800A52E4[] = { 0, 0, 0xFFFF };
u16 D_800A52EC[] = { 0, 1, 0xFFFF };
u16 D_800A52F4[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A5300[] = { 0x7209, 1, 0, 1, 0xE44, 0, 0xFFFF };
u16 D_800A5310[] = { 0x7400, 1, 0xE44, 1, 0xFFFF };
u16 D_800A531C[] = { 0, 1, 0xE44, 1, 0x720B, 0, 0x7209, 1, 0xFFFF };
u16 D_800A5330[] = { 0x7209, 1, 0, 1, 0xE44, 1, 0x720B, 1, 0xFFFF };
u16 D_800A5344[] = { 0x7831, 1, 0xFFFF };
u16 D_800A534C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5354[] = { 0x10, 0, 0xFFFF };
u16 D_800A535C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5364[] = { 0x10, 1, 0xFFFF };
u16 D_800A536C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5378[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A5384[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5390[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A539C[] = { 0x11, 0, 0xFFFF };
u16 D_800A53A4[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A53B0[] = { 1, 1, 0xFFFF };
u16 D_800A53B8[] = { 0x11, 0, 1, 1, 0x7205, 0, 0xFFFF };
u16 D_800A53C8[] = { 0x7208, 0, 0x7205, 1, 1, 1, 0x11, 0, 0xFFFF };
u16 D_800A53DC[] = { 0x7630, 1, 0xFFFF };
u16 D_800A53E4[] = {
    0xE24, 0, 0x7208, 1, 0x7205, 1, 1, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A53FC[] = { 0x7401, 1, 0xE24, 1, 0xFFFF };
u16 D_800A5408[] = {
    0x8014, 0, 0xE24, 1, 0x7208, 1, 0x7205, 1,
    1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5424[] = {
    0x7209, 0, 0x8014, 1, 0xE24, 1, 0x7208, 1,
    0x7205, 1, 1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5444[] = {
    0x7209, 1, 0x8014, 1, 0xE24, 1, 0x7208, 1,
    0x7205, 1, 1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5464[] = { 0x7830, 1, 0xFFFF };
u16 D_800A546C[] = { 1, 0, 0xFFFF };
u16 D_800A5474[] = { 1, 1, 0xFFFF };
u16 D_800A547C[] = { 0x7209, 0, 1, 1, 0xFFFF };
u16 D_800A5488[] = { 1, 1, 0xE45, 0, 0x7209, 1, 0xFFFF };
u16 D_800A5498[] = { 0x7401, 1, 0xE45, 1, 0xFFFF };
u16 D_800A54A4[] = { 0x7209, 1, 0xE45, 1, 0x720B, 0, 1, 1, 0xFFFF };
u16 D_800A54B8[] = { 1, 1, 0x7209, 1, 0xE45, 1, 0x720B, 1, 0xFFFF };
u16 D_800A54CC[] = { 0x7830, 1, 0xFFFF };
u16 D_800A54D4[] = { 0x11, 0, 0xFFFF };
u16 D_800A54DC[] = { 0x10, 0, 0xFFFF };
u16 D_800A54E4[] = { 0x11, 0, 0xFFFF };
u16 D_800A54EC[] = { 0x10, 1, 0xFFFF };
u16 D_800A54F4[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5500[] = { 0x7A17, 1, 0xFFFF };
u16 D_800A5508[] = { 0x7008, 1, 0x8192, 0, 0xFFFF };
u16 D_800A5514[] = { 0x7008, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5520[] = { 0x7A48, 1, 0xFFFF };
FieldTalk D_800A5528[] = {
    { NULL, D_800A51D8, 0x1A8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5540[] = {
    { NULL, D_800A51E0, 0x1A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5558[] = {
    { NULL, D_800A51E8, 0x1A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5570[] = {
    { NULL, NULL, 0x14E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5588[] = {
    { NULL, NULL, 0x154 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A0[] = {
    { NULL, NULL, 0x153 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55B8[] = {
    { D_800A51F0, D_800A51FC, 0x131 },
    { D_800A5208, D_800A5214, 0x130 },
    { D_800A521C, D_800A5228, 0x12B },
    { D_800A5230, NULL, 0x12C },
    { D_800A5240, D_800A5254, 0x12D },
    { D_800A525C, D_800A5274, 0x12E },
    { D_800A5280, NULL, 0x132 },
    { D_800A529C, NULL, 0x12C },
    { D_800A52BC, D_800A52DC, 0x12D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5630[] = {
    { D_800A52E4, D_800A52EC, 0x133 },
    { D_800A52F4, NULL, 0x135 },
    { D_800A5300, D_800A5310, 0x134 },
    { D_800A531C, NULL, 0x12F },
    { D_800A5330, D_800A5344, 0x136 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5678[] = {
    { D_800A534C, NULL, 0x205 },
    { D_800A5354, D_800A535C, 0x130 },
    { D_800A5364, D_800A536C, 0x131 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56A8[] = {
    { NULL, NULL, 0x132 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56C0[] = {
    { D_800A5378, D_800A5384, 0x183 },
    { D_800A5390, D_800A539C, 0x182 },
    { D_800A53A4, D_800A53B0, 0x133 },
    { D_800A53B8, NULL, 0x135 },
    { D_800A53C8, D_800A53DC, 0x136 },
    { D_800A53E4, D_800A53FC, 0x134 },
    { D_800A5408, NULL, 0x181 },
    { D_800A5424, NULL, 0x187 },
    { D_800A5444, D_800A5464, 0x188 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5738[] = {
    { D_800A546C, D_800A5474, 0x185 },
    { D_800A547C, NULL, 0x187 },
    { D_800A5488, D_800A5498, 0x186 },
    { D_800A54A4, NULL, 0x181 },
    { D_800A54B8, D_800A54CC, 0x188 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5780[] = {
    { D_800A54D4, NULL, 0x206 },
    { D_800A54DC, D_800A54E4, 0x182 },
    { D_800A54EC, D_800A54F4, 0x183 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57B0[] = {
    { NULL, NULL, 0x184 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57C8[] = {
    { NULL, NULL, 0x151 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57E0[] = {
    { NULL, NULL, 0x152 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57F8[] = {
    { NULL, NULL, 0x14F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5810[] = {
    { NULL, NULL, 0x150 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5828[] = {
    { NULL, NULL, 0x14C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5840[] = {
    { NULL, NULL, 0x14D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5858[] = {
    { NULL, D_800A5500, 0x1A6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5870[] = {
    { D_800A5508, NULL, 0x20D },
    { D_800A5514, D_800A5520, 0x1A7 },
    { NULL, NULL, 0 },
};
u16 D_800A5894[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A58A0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A58AC[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A58B8[] = { 0x7019, 1, 0x8192, 1, 0xFFFF };
u16 D_800A58C4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A58CC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A58D4[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A58E0[] = { 0x7019, 1, 0x8192, 1, 0xFFFF };
u16 D_800A58EC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A58F4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A58FC[] = { 0x7019, 1, 0x8192, 0, 0xFFFF };
u16 D_800A5908[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5914[] = { 0x701A, 1, 0xFFFF };
u16 D_800A591C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5928[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5930[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A593C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5944 = { NULL, D_800A5528, 0x16, 4, 923, 892, 3 };
FieldActorEntry D_800A5958 = { NULL, D_800A5540, 0x17, 5, 816, 521, 1 };
FieldActorEntry D_800A596C = { NULL, D_800A5558, 0x18, 6, 1189, 666, 1 };
FieldActorEntry D_800A5980 = { D_800A5894, D_800A5570, 0x2D, 7, 645, 199, 1 };
FieldActorEntry D_800A5994 = { D_800A58A0, D_800A5588, 0x2E, 8, 432, 249, 7 };
FieldActorEntry D_800A59A8 = { D_800A58AC, D_800A55A0, 0x36, 9, 304, 369, 7 };
FieldActorEntry D_800A59BC = { D_800A58B8, D_800A55B8, 0x45, 0xA, 545, 673, 1 };
FieldActorEntry D_800A59D0 = { D_800A58C4, D_800A5630, 0x45, 0xA, 545, 673, 7 };
FieldActorEntry D_800A59E4 = { D_800A58CC, D_800A5678, 0x45, 0xA, 545, 673, 1 };
FieldActorEntry D_800A59F8 = { D_800A58D4, D_800A56A8, 0x45, 0xA, 545, 673, 1 };
FieldActorEntry D_800A5A0C = { D_800A58E0, D_800A56C0, 0x46, 0xB, 687, 682, 7 };
FieldActorEntry D_800A5A20 = { D_800A58EC, D_800A5738, 0x46, 0xB, 687, 682, 1 };
FieldActorEntry D_800A5A34 = { D_800A58F4, D_800A5780, 0x46, 0xB, 687, 682, 7 };
FieldActorEntry D_800A5A48 = { D_800A58FC, D_800A57B0, 0x46, 0xB, 687, 682, 7 };
FieldActorEntry D_800A5A5C = { D_800A5908, D_800A57C8, 0x9D, 0xC, 304, 369, 7 };
FieldActorEntry D_800A5A70 = { D_800A5914, D_800A57E0, 0x9D, 0xC, 304, 369, 7 };
FieldActorEntry D_800A5A84 = { D_800A591C, D_800A57F8, 0x9E, 0xD, 432, 249, 7 };
FieldActorEntry D_800A5A98 = { D_800A5928, D_800A5810, 0x9E, 0xD, 432, 249, 7 };
FieldActorEntry D_800A5AAC = { D_800A5930, D_800A5828, 0x9F, 0xE, 645, 199, 1 };
FieldActorEntry D_800A5AC0 = { D_800A593C, D_800A5840, 0x9F, 0xE, 645, 199, 1 };
FieldActorEntry D_800A5AD4 = { NULL, D_800A5858, 0xB7, 0xF, 990, 767, 1 };
FieldActorEntry D_800A5AE8 = { NULL, D_800A5870, 0xCE, 0x10, 1216, 913, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A5944,
    &D_800A5958,
    &D_800A596C,
    &D_800A5980,
    &D_800A5994,
    &D_800A59A8,
    &D_800A59BC,
    &D_800A59D0,
    &D_800A59E4,
    &D_800A59F8,
    &D_800A5A0C,
    &D_800A5A20,
    &D_800A5A34,
    &D_800A5A48,
    &D_800A5A5C,
    &D_800A5A70,
    &D_800A5A84,
    &D_800A5A98,
    &D_800A5AAC,
    &D_800A5AC0,
    &D_800A5AD4,
    &D_800A5AE8,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 8, 0, 160, 342, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 8, 0, 234, 305, 0, 0 },
    { 1, 0, 0x78, 2, 0xC, 0, 0, 0, 0, 0, 542, 517, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 70, 849, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 614, 820, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1038, 280, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1089, 931, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 462, 518, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 832, 752, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1124, 522, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1343, 870, 0, 0 },
    { 1, 0x64, 0x40, 6, 9, 0, 0, 0, 0, 0, 769, 100, 0, 0 },
    { 1, 0x65, 0x40, 6, 0xA, 0, 0, 0, 0, 0, 574, 93, 0, 0 },
    { 1, 0x66, 0x40, 6, 0xB, 0, 0, 0, 0, 0, 186, 320, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 606, 118, 136, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 156, 353, 380, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 318, 390, 407, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 400, 341, 354, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 501, 625, 649, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 660, 626, 649, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 537, 158, 166, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 1206, 636, 682, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 1120, 656, 670, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A8, 0x630, 0x88, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2AC, 0x2C0, 0x1B0, 3, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2AD, 0xC8, 0x164, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2AD, 0x258, 0x1C2, 3, 0x64, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0x11, 1 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 0x11, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
