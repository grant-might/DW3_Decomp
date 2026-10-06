#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x620
#define STAGE_ARCHIVE 0x618
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x630
#define STAGE_ARCHIVE 0x628
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 4;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x47400, 0x2B500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3D;
    D_800990B4.music = 0x60F40000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E50;
extern Battle D_800A4E5C;
extern Battle D_800A4E68;
extern Battle D_800A4E74;
extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4EEC;
extern Battle D_800A4EF8;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern BattleList D_800A4EB0;
extern BattleList D_800A4F34;
extern BattleList D_800A4FB8;
extern BattleList D_800A503C;
extern u16 D_800A514C[];
extern u16 D_800A515C[];
extern u16 D_800A5168[];
extern u16 D_800A5174[];
extern u16 D_800A5180[];
extern u16 D_800A5188[];
extern u16 D_800A5194[];
extern u16 D_800A519C[];
extern u16 D_800A51AC[];
extern u16 D_800A51C0[];
extern u16 D_800A51C8[];
extern u16 D_800A51E0[];
extern u16 D_800A51EC[];
extern u16 D_800A5208[];
extern u16 D_800A5228[];
extern u16 D_800A5248[];
extern u16 D_800A5250[];
extern u16 D_800A5258[];
extern u16 D_800A5260[];
extern u16 D_800A526C[];
extern u16 D_800A527C[];
extern u16 D_800A5288[];
extern u16 D_800A529C[];
extern u16 D_800A52B0[];
extern u16 D_800A52B8[];
extern u16 D_800A52C0[];
extern u16 D_800A52C8[];
extern u16 D_800A52D0[];
extern u16 D_800A52D8[];
extern u16 D_800A52E4[];
extern u16 D_800A52F0[];
extern u16 D_800A52FC[];
extern u16 D_800A5308[];
extern u16 D_800A5310[];
extern u16 D_800A531C[];
extern u16 D_800A5324[];
extern u16 D_800A5334[];
extern u16 D_800A5348[];
extern u16 D_800A5350[];
extern u16 D_800A5368[];
extern u16 D_800A5374[];
extern u16 D_800A5390[];
extern u16 D_800A53B0[];
extern u16 D_800A53D0[];
extern u16 D_800A53D8[];
extern u16 D_800A53E0[];
extern u16 D_800A53E8[];
extern u16 D_800A53F4[];
extern u16 D_800A5404[];
extern u16 D_800A5410[];
extern u16 D_800A5424[];
extern u16 D_800A5438[];
extern u16 D_800A5440[];
extern u16 D_800A5448[];
extern u16 D_800A5450[];
extern u16 D_800A5458[];
extern u16 D_800A5460[];
extern u16 D_800A5724[];
extern FieldTalk D_800A546C[];
extern u16 D_800A572C[];
extern FieldTalk D_800A5484[];
extern u16 D_800A5738[];
extern FieldTalk D_800A549C[];
extern u16 D_800A5744[];
extern FieldTalk D_800A54B4[];
extern u16 D_800A5750[];
extern FieldTalk D_800A552C[];
extern u16 D_800A5758[];
extern FieldTalk D_800A5574[];
extern u16 D_800A5760[];
extern FieldTalk D_800A55A4[];
extern u16 D_800A576C[];
extern FieldTalk D_800A55BC[];
extern u16 D_800A5778[];
extern FieldTalk D_800A5634[];
extern u16 D_800A5780[];
extern FieldTalk D_800A567C[];
extern u16 D_800A5788[];
extern FieldTalk D_800A56AC[];
extern u16 D_800A5794[];
extern FieldTalk D_800A56C4[];
extern u16 D_800A57A0[];
extern FieldTalk D_800A56DC[];
extern u16 D_800A57A8[];
extern FieldTalk D_800A56F4[];
extern u16 D_800A57B4[];
extern FieldTalk D_800A570C[];
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

Battle D_800A4E50 = { 136, 4, 0x60080000 };
Battle D_800A4E5C = { 136, 4, 0x60080000 };
Battle D_800A4E68 = { 136, 4, 0x60080000 };
Battle D_800A4E74 = { 136, 4, 0x60080000 };
Battle D_800A4E80 = { 183, 4, 0x60080000 };
Battle D_800A4E8C = { 183, 4, 0x60080000 };
Battle D_800A4E98 = { 183, 4, 0x60080000 };
Battle D_800A4EA4 = { 183, 4, 0x60080000 };
BattleList D_800A4EB0 = {
    3,
    { &D_800A4E50, &D_800A4E5C, &D_800A4E68, &D_800A4E74,
      &D_800A4E80, &D_800A4E8C, &D_800A4E98, &D_800A4EA4 },
};
Battle D_800A4ED4 = { 0, 0, 0x60040000 };
Battle D_800A4EE0 = { 0, 0, 0x60040000 };
Battle D_800A4EEC = { 0, 0, 0x60040000 };
Battle D_800A4EF8 = { 0, 0, 0x60040000 };
Battle D_800A4F04 = { 0, 0, 0x60040000 };
Battle D_800A4F10 = { 0, 0, 0x60040000 };
Battle D_800A4F1C = { 0, 0, 0x60040000 };
Battle D_800A4F28 = { 0, 0, 0x60040000 };
BattleList D_800A4F34 = {
    0,
    { &D_800A4ED4, &D_800A4EE0, &D_800A4EEC, &D_800A4EF8,
      &D_800A4F04, &D_800A4F10, &D_800A4F1C, &D_800A4F28 },
};
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
Battle D_800A4F70 = { 0, 0, 0x60040000 };
Battle D_800A4F7C = { 0, 0, 0x60040000 };
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
BattleList D_800A4FB8 = {
    0,
    { &D_800A4F58, &D_800A4F64, &D_800A4F70, &D_800A4F7C,
      &D_800A4F88, &D_800A4F94, &D_800A4FA0, &D_800A4FAC },
};
Battle D_800A4FDC = { 243, 4, 0x60080000 };
Battle D_800A4FE8 = { 244, 4, 0x60080000 };
Battle D_800A4FF4 = { 291, 4, 0x600C0000 };
Battle D_800A5000 = { 333, 4, 0x60080000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 175, 4, 0x60080000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
FieldBattles stageBattles[] = {
    { 116, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x175, 0xC0, 0x75, 0x160, 0x1FE },
    { 0x140, 0x100, 0x174, 0x125, 0xD0, 0x25, 0x170, 0x1FE },
    { 0x140, 0x100, 0x16A, 0x145, 0xA8, 0x45, 0x160, 0x1FD },
    { 0x140, 0x100, 0x160, 0x14D, 0x80, 0x4D, 0x170, 0x1FD },
    { 0x140, 0x100, 0x172, 0x14D, 0xC8, 0x4D, 0x160, 0x1FC },
    { 0x140, 0x100, 0x168, 0x16D, 0xA0, 0x6D, 0x170, 0x1FC },
    { 0x140, 0x100, 0x160, 0x175, 0x80, 0x75, 0x140, 0x1FB },
};
u16 D_800A514C[] = { 0x250, 1, 0x822C, 1, 0x7013, 1, 0xFFFF };
u16 D_800A515C[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5168[] = { 0x10, 0, 0x11, 0, 0xFFFF };
u16 D_800A5174[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5180[] = { 0x11, 0, 0xFFFF };
u16 D_800A5188[] = { 0, 0, 0x11, 0, 0xFFFF };
u16 D_800A5194[] = { 0, 1, 0xFFFF };
u16 D_800A519C[] = { 0x7208, 0, 0, 1, 0x11, 0, 0xFFFF };
u16 D_800A51AC[] = { 0x720A, 0, 0x7208, 1, 0, 1, 0x11, 0, 0xFFFF };
u16 D_800A51C0[] = { 0x763C, 1, 0xFFFF };
u16 D_800A51C8[] = {
    0xE2F, 0, 0x720A, 1, 0x7208, 1, 0, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A51E0[] = { 0x7401, 1, 0xE2F, 1, 0xFFFF };
u16 D_800A51EC[] = {
    0xE2F, 1, 0x720A, 1, 0x7208, 1, 0, 1,
    0x11, 0, 0x8014, 0, 0xFFFF,
};
u16 D_800A5208[] = {
    0x720B, 0, 0x8014, 1, 0xE2F, 1, 0x720A, 1,
    0x7208, 1, 0, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5228[] = {
    0x720B, 1, 0x8014, 1, 0xE2F, 1, 0x720A, 1,
    0x7208, 1, 0, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5248[] = { 0x783C, 1, 0xFFFF };
u16 D_800A5250[] = { 1, 0, 0xFFFF };
u16 D_800A5258[] = { 1, 1, 0xFFFF };
u16 D_800A5260[] = { 1, 1, 0x720B, 0, 0xFFFF };
u16 D_800A526C[] = { 1, 1, 0x720B, 1, 0xE4F, 0, 0xFFFF };
u16 D_800A527C[] = { 0xE4F, 1, 0x7401, 1, 0xFFFF };
u16 D_800A5288[] = { 1, 1, 0x720B, 1, 0xE4F, 1, 0x720D, 0, 0xFFFF };
u16 D_800A529C[] = { 1, 1, 0x720B, 1, 0xE4F, 1, 0x720D, 1, 0xFFFF };
u16 D_800A52B0[] = { 0x783C, 1, 0xFFFF };
u16 D_800A52B8[] = { 0x11, 0, 0xFFFF };
u16 D_800A52C0[] = { 0x10, 0, 0xFFFF };
u16 D_800A52C8[] = { 0x11, 0, 0xFFFF };
u16 D_800A52D0[] = { 0x10, 1, 0xFFFF };
u16 D_800A52D8[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A52E4[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A52F0[] = { 0x10, 0, 0x11, 0, 0xFFFF };
u16 D_800A52FC[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5308[] = { 0x11, 0, 0xFFFF };
u16 D_800A5310[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A531C[] = { 1, 1, 0xFFFF };
u16 D_800A5324[] = { 0x7208, 0, 1, 1, 0x11, 0, 0xFFFF };
u16 D_800A5334[] = { 0x720A, 0, 0x7208, 1, 1, 1, 0x11, 0, 0xFFFF };
u16 D_800A5348[] = { 0x763B, 1, 0xFFFF };
u16 D_800A5350[] = {
    0xE2E, 0, 0x720A, 1, 0x7208, 1, 1, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A5368[] = { 0x7400, 1, 0xE2E, 1, 0xFFFF };
u16 D_800A5374[] = {
    0x8014, 0, 0xE2E, 1, 0x720A, 1, 0x7208, 1,
    1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5390[] = {
    0x720B, 0, 0x8014, 1, 0xE2E, 1, 0x720A, 1,
    0x7208, 1, 1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A53B0[] = {
    0x720B, 1, 0x8014, 1, 0xE2E, 1, 0x720A, 1,
    0x7208, 1, 1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A53D0[] = { 0x783B, 1, 0xFFFF };
u16 D_800A53D8[] = { 0, 0, 0xFFFF };
u16 D_800A53E0[] = { 0, 1, 0xFFFF };
u16 D_800A53E8[] = { 0, 1, 0x720B, 0, 0xFFFF };
u16 D_800A53F4[] = { 0, 1, 0x720B, 1, 0xE4E, 0, 0xFFFF };
u16 D_800A5404[] = { 0xE4E, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5410[] = { 0x720D, 0, 0, 1, 0x720B, 1, 0xE4E, 1, 0xFFFF };
u16 D_800A5424[] = { 0xE4E, 1, 0x720D, 1, 0, 1, 0x720B, 1, 0xFFFF };
u16 D_800A5438[] = { 0x783B, 1, 0xFFFF };
u16 D_800A5440[] = { 0x11, 0, 0xFFFF };
u16 D_800A5448[] = { 0x10, 0, 0xFFFF };
u16 D_800A5450[] = { 0x11, 0, 0xFFFF };
u16 D_800A5458[] = { 0x10, 1, 0xFFFF };
u16 D_800A5460[] = { 0x11, 0, 0x10, 0, 0xFFFF };
FieldTalk D_800A546C[] = {
    { NULL, D_800A514C, 0x17D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5484[] = {
    { NULL, NULL, 0x222 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A549C[] = {
    { NULL, NULL, 0x220 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B4[] = {
    { D_800A515C, D_800A5168, 0x24A },
    { D_800A5174, D_800A5180, 0x249 },
    { D_800A5188, D_800A5194, 0x244 },
    { D_800A519C, NULL, 0x245 },
    { D_800A51AC, D_800A51C0, 0x246 },
    { D_800A51C8, D_800A51E0, 0x247 },
    { D_800A51EC, NULL, 0x248 },
    { D_800A5208, NULL, 0x245 },
    { D_800A5228, D_800A5248, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A552C[] = {
    { D_800A5250, D_800A5258, 0x24C },
    { D_800A5260, NULL, 0x24E },
    { D_800A526C, D_800A527C, 0x24D },
    { D_800A5288, NULL, 0x248 },
    { D_800A529C, D_800A52B0, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5574[] = {
    { D_800A52B8, NULL, 0x39C },
    { D_800A52C0, D_800A52C8, 0x249 },
    { D_800A52D0, D_800A52D8, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A4[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55BC[] = {
    { D_800A52E4, D_800A52F0, 0x22A },
    { D_800A52FC, D_800A5308, 0x229 },
    { D_800A5310, D_800A531C, 0x224 },
    { D_800A5324, NULL, 0x225 },
    { D_800A5334, D_800A5348, 0x226 },
    { D_800A5350, D_800A5368, 0x227 },
    { D_800A5374, NULL, 0x228 },
    { D_800A5390, NULL, 0x225 },
    { D_800A53B0, D_800A53D0, 0x226 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5634[] = {
    { D_800A53D8, D_800A53E0, 0x22C },
    { D_800A53E8, NULL, 0x22E },
    { D_800A53F4, D_800A5404, 0x22D },
    { D_800A5410, NULL, 0x228 },
    { D_800A5424, D_800A5438, 0x22F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A567C[] = {
    { D_800A5440, NULL, 0x39D },
    { D_800A5448, D_800A5450, 0x229 },
    { D_800A5458, D_800A5460, 0x22A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56AC[] = {
    { NULL, NULL, 0x22B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56C4[] = {
    { NULL, NULL, 0x223 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56DC[] = {
    { NULL, NULL, 0x223 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56F4[] = {
    { NULL, NULL, 0x221 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A570C[] = {
    { NULL, NULL, 0x221 },
    { NULL, NULL, 0 },
};
u16 D_800A5724[] = { 0x250, 0, 0xFFFF };
u16 D_800A572C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5738[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5744[] = { 0x8192, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5750[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5758[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5760[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A576C[] = { 0x7019, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5778[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5780[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5788[] = { 0x7019, 1, 0x8192, 0, 0xFFFF };
u16 D_800A5794[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57A0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57A8[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57B4[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A57BC = { D_800A5724, D_800A546C, 0x21, 4, 432, 521, 1 };
FieldActorEntry D_800A57D0 = { D_800A572C, D_800A5484, 0x2F, 5, 737, 673, 5 };
FieldActorEntry D_800A57E4 = { D_800A5738, D_800A549C, 0x32, 6, 945, 249, 1 };
FieldActorEntry D_800A57F8 = { D_800A5744, D_800A54B4, 0x45, 7, 617, 589, 1 };
FieldActorEntry D_800A580C = { D_800A5750, D_800A552C, 0x45, 7, 617, 589, 1 };
FieldActorEntry D_800A5820 = { D_800A5758, D_800A5574, 0x45, 7, 617, 589, 1 };
FieldActorEntry D_800A5834 = { D_800A5760, D_800A55A4, 0x45, 7, 617, 589, 1 };
FieldActorEntry D_800A5848 = { D_800A576C, D_800A55BC, 0x46, 8, 851, 490, 1 };
FieldActorEntry D_800A585C = { D_800A5778, D_800A5634, 0x46, 8, 851, 490, 1 };
FieldActorEntry D_800A5870 = { D_800A5780, D_800A567C, 0x46, 8, 851, 490, 1 };
FieldActorEntry D_800A5884 = { D_800A5788, D_800A56AC, 0x46, 8, 851, 490, 1 };
FieldActorEntry D_800A5898 = { D_800A5794, D_800A56C4, 0x9D, 9, 737, 673, 5 };
FieldActorEntry D_800A58AC = { D_800A57A0, D_800A56DC, 0x9D, 9, 737, 673, 5 };
FieldActorEntry D_800A58C0 = { D_800A57A8, D_800A56F4, 0x9E, 0xA, 945, 249, 1 };
FieldActorEntry D_800A58D4 = { D_800A57B4, D_800A570C, 0x9E, 0xA, 945, 249, 1 };
FieldActorEntry *stageActors[] = {
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 323, 826, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 690, 795, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 450, 288, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 745, 533, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 6, 0, 210, 424, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 6, 0, 277, 230, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 6, 0, 788, 245, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 3, 6, 0, 960, 401, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 1, 0x37, 0x3C, 6, 0, 850, 660, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 1, 0x37, 0x3C, 6, 0, 939, 699, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 1, 0x37, 0x3C, 6, 0, 950, 624, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 1, 0x37, 0x3C, 6, 0, 997, 651, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 3, 8, 0, 893, 649, 0, 0 },
    { 1, 0, 0xC8, 4, 0x33, 1, 0x33, 0x36, 8, 0, 130, 97, 896, 0 },
    { 1, 0, 0xC8, 4, 0x33, 1, 0x33, 0x36, 8, 0, 434, 412, 896, 0 },
    { 1, 0, 0xC8, 4, 0x33, 1, 0x33, 0x36, 8, 0, 480, 645, 896, 0 },
    { 1, 0, 0xC8, 4, 0x33, 1, 0x33, 0x36, 8, 0, 513, 10, 896, 0 },
    { 1, 0, 0xC8, 4, 0x33, 1, 0x33, 0x36, 8, 0, 611, 294, 896, 0 },
    { 1, 0, 0xC8, 4, 0x33, 1, 0x33, 0x36, 8, 0, 628, 630, 896, 0 },
    { 1, 0, 0xC8, 4, 0x33, 1, 0x33, 0x36, 8, 0, 893, 695, 896, 0 },
    { 1, 0, 0xC8, 4, 0x33, 1, 0x33, 0x36, 8, 0, 1101, 650, 896, 0 },
    { 1, 0, 0xC8, 4, 0x33, 1, 0x33, 0x36, 8, 0, 1232, -8, 896, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 224, 527, 527, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 512, 703, 703, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 816, 375, 375, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 991, 207, 207, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1088, 207, 207, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CD, 0x4F0, 0x2B8, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CA, 0xA0, 0x1D0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CA, 0xA0, 0x240, 7, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x17, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 9, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 5, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0xD, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x27F, 0x280, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x26E, 0x2E8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x4C0, 0x1A0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x4B0, 0x208, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 0xA, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
