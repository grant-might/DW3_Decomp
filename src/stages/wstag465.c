#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x1B5
#define STAGE_ARCHIVE 0x3D1
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x1C3
#define STAGE_ARCHIVE 0x3E1
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16 | 1;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x37F00, 0x1F600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x34;
    D_800990B4.music = 0x60D00000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E70;
extern Battle D_800A4E7C;
extern Battle D_800A4E88;
extern Battle D_800A4E94;
extern Battle D_800A4EA0;
extern Battle D_800A4EAC;
extern Battle D_800A4EB8;
extern Battle D_800A4EC4;
extern Battle D_800A4EF4;
extern Battle D_800A4F00;
extern Battle D_800A4F0C;
extern Battle D_800A4F18;
extern Battle D_800A4F24;
extern Battle D_800A4F30;
extern Battle D_800A4F3C;
extern Battle D_800A4F48;
extern Battle D_800A4F78;
extern Battle D_800A4F84;
extern Battle D_800A4F90;
extern Battle D_800A4F9C;
extern Battle D_800A4FA8;
extern Battle D_800A4FB4;
extern Battle D_800A4FC0;
extern Battle D_800A4FCC;
extern Battle D_800A4FFC;
extern Battle D_800A5008;
extern Battle D_800A5014;
extern Battle D_800A5020;
extern Battle D_800A502C;
extern Battle D_800A5038;
extern Battle D_800A5044;
extern Battle D_800A5050;
extern BattleList D_800A4ED0;
extern BattleList D_800A4F54;
extern BattleList D_800A4FD8;
extern BattleList D_800A505C;
extern u16 D_800A513C[];
extern u16 D_800A5144[];
extern u16 D_800A514C[];
extern u16 D_800A5158[];
extern u16 D_800A5164[];
extern u16 D_800A516C[];
extern u16 D_800A5174[];
extern u16 D_800A517C[];
extern u16 D_800A5188[];
extern u16 D_800A5194[];
extern u16 D_800A519C[];
extern u16 D_800A51A4[];
extern u16 D_800A51AC[];
extern u16 D_800A51B8[];
extern u16 D_800A51C4[];
extern u16 D_800A51CC[];
extern u16 D_800A51D4[];
extern u16 D_800A51DC[];
extern u16 D_800A51E8[];
extern u16 D_800A51F4[];
extern u16 D_800A5204[];
extern u16 D_800A5214[];
extern u16 D_800A521C[];
extern u16 D_800A5224[];
extern u16 D_800A5230[];
extern u16 D_800A5238[];
extern u16 D_800A5244[];
extern u16 D_800A5250[];
extern u16 D_800A5258[];
extern u16 D_800A5264[];
extern u16 D_800A526C[];
extern u16 D_800A527C[];
extern u16 D_800A5290[];
extern u16 D_800A52A0[];
extern u16 D_800A52AC[];
extern u16 D_800A52B4[];
extern u16 D_800A52C0[];
extern u16 D_800A52CC[];
extern u16 D_800A55BC[];
extern FieldTalk D_800A52D4[];
extern u16 D_800A55C4[];
extern FieldTalk D_800A52EC[];
extern u16 D_800A55CC[];
extern FieldTalk D_800A5304[];
extern u16 D_800A55D4[];
extern FieldTalk D_800A531C[];
extern u16 D_800A55DC[];
extern FieldTalk D_800A5334[];
extern u16 D_800A55E4[];
extern FieldTalk D_800A534C[];
extern u16 D_800A55EC[];
extern FieldTalk D_800A5364[];
extern u16 D_800A55F4[];
extern FieldTalk D_800A537C[];
extern u16 D_800A55FC[];
extern FieldTalk D_800A5394[];
extern u16 D_800A5604[];
extern FieldTalk D_800A53AC[];
extern u16 D_800A560C[];
extern FieldTalk D_800A53C4[];
extern u16 D_800A5614[];
extern FieldTalk D_800A53DC[];
extern u16 D_800A561C[];
extern FieldTalk D_800A53F4[];
extern u16 D_800A5624[];
extern FieldTalk D_800A540C[];
extern u16 D_800A562C[];
extern FieldTalk D_800A5424[];
extern u16 D_800A5640[];
extern FieldTalk D_800A5454[];
extern u16 D_800A5654[];
extern FieldTalk D_800A5484[];
extern u16 D_800A5668[];
extern FieldTalk D_800A54B4[];
extern u16 D_800A567C[];
extern FieldTalk D_800A54F0[];
extern u16 D_800A5690[];
extern FieldTalk D_800A5520[];
extern u16 D_800A56A4[];
extern FieldTalk D_800A555C[];
extern u16 D_800A56B4[];
extern FieldTalk D_800A5574[];
extern u16 D_800A56BC[];
extern FieldTalk D_800A55A4[];
extern FieldActorEntry D_800A56C4;
extern FieldActorEntry D_800A56D8;
extern FieldActorEntry D_800A56EC;
extern FieldActorEntry D_800A5700;
extern FieldActorEntry D_800A5714;
extern FieldActorEntry D_800A5728;
extern FieldActorEntry D_800A573C;
extern FieldActorEntry D_800A5750;
extern FieldActorEntry D_800A5764;
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

Battle D_800A4E70 = { 53, 8, 0x60080000 };
Battle D_800A4E7C = { 53, 8, 0x60080000 };
Battle D_800A4E88 = { 53, 8, 0x60080000 };
Battle D_800A4E94 = { 147, 8, 0x60080000 };
Battle D_800A4EA0 = { 147, 8, 0x60080000 };
Battle D_800A4EAC = { 147, 8, 0x60080000 };
Battle D_800A4EB8 = { 54, 8, 0x60080000 };
Battle D_800A4EC4 = { 54, 8, 0x60080000 };
BattleList D_800A4ED0 = {
    3,
    { &D_800A4E70, &D_800A4E7C, &D_800A4E88, &D_800A4E94,
      &D_800A4EA0, &D_800A4EAC, &D_800A4EB8, &D_800A4EC4 },
};
Battle D_800A4EF4 = { 0, 0, 0x60040000 };
Battle D_800A4F00 = { 0, 0, 0x60040000 };
Battle D_800A4F0C = { 0, 0, 0x60040000 };
Battle D_800A4F18 = { 0, 0, 0x60040000 };
Battle D_800A4F24 = { 0, 0, 0x60040000 };
Battle D_800A4F30 = { 0, 0, 0x60040000 };
Battle D_800A4F3C = { 0, 0, 0x60040000 };
Battle D_800A4F48 = { 0, 0, 0x60040000 };
BattleList D_800A4F54 = {
    0,
    { &D_800A4EF4, &D_800A4F00, &D_800A4F0C, &D_800A4F18,
      &D_800A4F24, &D_800A4F30, &D_800A4F3C, &D_800A4F48 },
};
Battle D_800A4F78 = { 0, 0, 0x60040000 };
Battle D_800A4F84 = { 0, 0, 0x60040000 };
Battle D_800A4F90 = { 0, 0, 0x60040000 };
Battle D_800A4F9C = { 0, 0, 0x60040000 };
Battle D_800A4FA8 = { 0, 0, 0x60040000 };
Battle D_800A4FB4 = { 0, 0, 0x60040000 };
Battle D_800A4FC0 = { 0, 0, 0x60040000 };
Battle D_800A4FCC = { 0, 0, 0x60040000 };
BattleList D_800A4FD8 = {
    0,
    { &D_800A4F78, &D_800A4F84, &D_800A4F90, &D_800A4F9C,
      &D_800A4FA8, &D_800A4FB4, &D_800A4FC0, &D_800A4FCC },
};
Battle D_800A4FFC = { 213, 8, 0x600C0000 };
Battle D_800A5008 = { 0, 0, 0x60040000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 329, 8, 0x60080000 };
Battle D_800A502C = { 328, 8, 0x60080000 };
Battle D_800A5038 = { 0, 0, 0x60040000 };
Battle D_800A5044 = { 147, 8, 0x60080000 };
Battle D_800A5050 = { 66, 8, 0x60080000 };
BattleList D_800A505C = {
    0,
    { &D_800A4FFC, &D_800A5008, &D_800A5014, &D_800A5020,
      &D_800A502C, &D_800A5038, &D_800A5044, &D_800A5050 },
};
FieldBattles stageBattles[] = {
    { 15, 0, 0, { &D_800A4ED0, &D_800A4F54, &D_800A4FD8, &D_800A505C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x148, 0x1D4, 0x20, 0xD4, 0x170, 0x1FF },
    { 0x180, 0x100, 0x198, 0x100, 0x160, 0, 0x140, 0x1FE },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1A8, 0x100, 0x1A0, 0, 0x160, 0x1FE },
};
u16 D_800A513C[] = { 0, 0, 0xFFFF };
u16 D_800A5144[] = { 0, 1, 0xFFFF };
u16 D_800A514C[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A5158[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A5164[] = { 0x7617, 1, 0xFFFF };
u16 D_800A516C[] = { 0, 0, 0xFFFF };
u16 D_800A5174[] = { 0, 1, 0xFFFF };
u16 D_800A517C[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A5188[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A5194[] = { 0x7617, 1, 0xFFFF };
u16 D_800A519C[] = { 0, 0, 0xFFFF };
u16 D_800A51A4[] = { 0, 1, 0xFFFF };
u16 D_800A51AC[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A51B8[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A51C4[] = { 0x7617, 1, 0xFFFF };
u16 D_800A51CC[] = { 0, 0, 0xFFFF };
u16 D_800A51D4[] = { 0, 1, 0xFFFF };
u16 D_800A51DC[] = { 0, 1, 0xE0D, 0, 0xFFFF };
u16 D_800A51E8[] = { 0x7400, 1, 0xE0D, 1, 0xFFFF };
u16 D_800A51F4[] = { 0, 1, 0xE0D, 1, 0x720D, 0, 0xFFFF };
u16 D_800A5204[] = { 0, 1, 0xE0D, 1, 0x720D, 1, 0xFFFF };
u16 D_800A5214[] = { 0x7817, 1, 0xFFFF };
u16 D_800A521C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5224[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5230[] = { 0x11, 0, 0xFFFF };
u16 D_800A5238[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5244[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5250[] = { 0x11, 0, 0xFFFF };
u16 D_800A5258[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5264[] = { 0x11, 0, 0xFFFF };
u16 D_800A526C[] = { 0x10, 1, 0x9213, 0, 0x11, 1, 0xFFFF };
u16 D_800A527C[] = { 0x9213, 1, 0x11, 0, 0x7013, 1, 0x10, 0, 0xFFFF };
u16 D_800A5290[] = { 0x10, 1, 0x9213, 1, 0x11, 1, 0xFFFF };
u16 D_800A52A0[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A52AC[] = { 0, 0, 0xFFFF };
u16 D_800A52B4[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A52C0[] = { 0, 1, 0x7209, 1, 0xFFFF };
u16 D_800A52CC[] = { 0x7617, 1, 0xFFFF };
FieldTalk D_800A52D4[] = {
    { NULL, NULL, 0x20 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52EC[] = {
    { NULL, NULL, 0x133 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5304[] = {
    { NULL, NULL, 0x133 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A531C[] = {
    { NULL, NULL, 0x20 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5334[] = {
    { NULL, NULL, 0x20 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A534C[] = {
    { NULL, NULL, 0x12D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5364[] = {
    { NULL, NULL, 0x12E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A537C[] = {
    { NULL, NULL, 0x12F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5394[] = {
    { NULL, NULL, 0x130 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53AC[] = {
    { NULL, NULL, 0x137 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53C4[] = {
    { NULL, NULL, 0x135 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53DC[] = {
    { NULL, NULL, 0x131 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53F4[] = {
    { NULL, NULL, 0x132 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A540C[] = {
    { NULL, NULL, 0x134 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5424[] = {
    { D_800A513C, D_800A5144, 0xBE },
    { D_800A514C, NULL, 0xC2 },
    { D_800A5158, D_800A5164, 0xC3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5454[] = {
    { D_800A516C, D_800A5174, 0xBF },
    { D_800A517C, NULL, 0xC2 },
    { D_800A5188, D_800A5194, 0xC3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5484[] = {
    { D_800A519C, D_800A51A4, 0xC0 },
    { D_800A51AC, NULL, 0xC2 },
    { D_800A51B8, D_800A51C4, 0xC3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B4[] = {
    { D_800A51CC, D_800A51D4, 0xC4 },
    { D_800A51DC, D_800A51E8, 0xC5 },
    { D_800A51F4, NULL, 0xC6 },
    { D_800A5204, D_800A5214, 0xC7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54F0[] = {
    { D_800A521C, NULL, 0xBE },
    { D_800A5224, D_800A5230, 0xCA },
    { D_800A5238, D_800A5244, 0xC9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5520[] = {
    { D_800A5250, NULL, 0xBE },
    { D_800A5258, D_800A5264, 0xC8 },
    { D_800A526C, D_800A527C, 0xCB },
    { D_800A5290, D_800A52A0, 0xC9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A555C[] = {
    { NULL, NULL, 0x283 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5574[] = {
    { D_800A52AC, NULL, 0xC1 },
    { D_800A52B4, NULL, 0xC1 },
    { D_800A52C0, D_800A52CC, 0xC1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A4[] = {
    { NULL, NULL, 0x136 },
    { NULL, NULL, 0 },
};
u16 D_800A55BC[] = { 0x6007, 1, 0xFFFF };
u16 D_800A55C4[] = { 0x601A, 1, 0xFFFF };
u16 D_800A55CC[] = { 0x6019, 1, 0xFFFF };
u16 D_800A55D4[] = { 0x6008, 1, 0xFFFF };
u16 D_800A55DC[] = { 0x6009, 1, 0xFFFF };
u16 D_800A55E4[] = { 0x600A, 1, 0xFFFF };
u16 D_800A55EC[] = { 0x600C, 1, 0xFFFF };
u16 D_800A55F4[] = { 0x600E, 1, 0xFFFF };
u16 D_800A55FC[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5604[] = { 0x602B, 1, 0xFFFF };
u16 D_800A560C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5614[] = { 0x7017, 1, 0xFFFF };
u16 D_800A561C[] = { 0x6018, 1, 0xFFFF };
u16 D_800A5624[] = { 0x601B, 1, 0xFFFF };
u16 D_800A562C[] = { 0x7003, 1, 0x11, 0, 0x8192, 1, 0x8012, 0, 0xFFFF };
u16 D_800A5640[] = { 0x7004, 1, 0x11, 0, 0x8192, 1, 0x8012, 0, 0xFFFF };
u16 D_800A5654[] = { 0x6026, 1, 0x11, 0, 0x8192, 1, 0x8012, 0, 0xFFFF };
u16 D_800A5668[] = { 0x8012, 1, 0x11, 0, 0x8192, 1, 0x7022, 1, 0xFFFF };
u16 D_800A567C[] = { 0x700A, 1, 0x11, 1, 0x8192, 1, 0x8012, 0, 0xFFFF };
u16 D_800A5690[] = { 0x8012, 1, 0x8192, 1, 0x11, 1, 0x7022, 1, 0xFFFF };
u16 D_800A56A4[] = { 0x8192, 0, 0x701A, 0, 0x7009, 1, 0xFFFF };
u16 D_800A56B4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A56BC[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A56C4 = { D_800A55BC, D_800A52D4, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A56D8 = { D_800A55C4, D_800A52EC, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A56EC = { D_800A55CC, D_800A5304, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A5700 = { D_800A55D4, D_800A531C, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A5714 = { D_800A55DC, D_800A5334, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A5728 = { D_800A55E4, D_800A534C, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A573C = { D_800A55EC, D_800A5364, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A5750 = { D_800A55F4, D_800A537C, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A5764 = { D_800A55FC, D_800A5394, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A5778 = { D_800A5604, D_800A53AC, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A578C = { D_800A560C, D_800A53C4, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A57A0 = { D_800A5614, D_800A53DC, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A57B4 = { D_800A561C, D_800A53F4, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A57C8 = { D_800A5624, D_800A540C, 0x33, 4, 897, 514, 5 };
FieldActorEntry D_800A57DC = { D_800A562C, D_800A5424, 0x3A, 5, 690, 251, 7 };
FieldActorEntry D_800A57F0 = { D_800A5640, D_800A5454, 0x3A, 5, 690, 251, 7 };
FieldActorEntry D_800A5804 = { D_800A5654, D_800A5484, 0x3A, 5, 690, 251, 7 };
FieldActorEntry D_800A5818 = { D_800A5668, D_800A54B4, 0x3A, 5, 690, 251, 7 };
FieldActorEntry D_800A582C = { D_800A567C, D_800A54F0, 0x3A, 5, 690, 251, 7 };
FieldActorEntry D_800A5840 = { D_800A5690, D_800A5520, 0x3A, 5, 690, 251, 7 };
FieldActorEntry D_800A5854 = { D_800A56A4, D_800A555C, 0x3A, 5, 690, 251, 7 };
FieldActorEntry D_800A5868 = { D_800A56B4, D_800A5574, 0x9D, 6, 690, 251, 7 };
FieldActorEntry D_800A587C = { D_800A56BC, D_800A55A4, 0x9E, 7, 897, 514, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A56C4,
    &D_800A56D8,
    &D_800A56EC,
    &D_800A5700,
    &D_800A5714,
    &D_800A5728,
    &D_800A573C,
    &D_800A5750,
    &D_800A5764,
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
    { 1, 0, 0x40, 2, 3, 1, 3, 8, 8, 0, 1098, 580, 0, 0 },
    { 1, 0, 0x40, 2, 0x12, 0, 0, 0, 0, 0, 1107, 563, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 1187, 603, 0, 0 },
    { 1, 0, 0x40, 2, 0x14, 0, 0, 0, 0, 0, 545, 152, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 255, 371, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 476, 316, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 482, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 656, 359, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 815, 365, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 960, 347, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 978, 599, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 319, 380, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 474, 400, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 606, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 707, 423, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 784, 382, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 999, 583, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1177, 467, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 373, 367, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 712, 325, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 797, 287, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3A, 0x3D, 0xA, 0, 290, 429, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 415, 553, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 528, 419, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 702, 495, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1084, 593, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 211, 355, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 312, 442, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 436, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 504, 517, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 195, 355, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 290, 442, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 431, 551, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 544, 418, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 668, 475, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 747, 327, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 125, 305, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 128, 296, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 245, 93, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 252, 98, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 262, 91, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 299, 379, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 366, 425, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 392, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 416, 486, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 507, 441, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 521, 46, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 526, 292, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 532, 49, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 562, 496, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 584, 131, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 599, 479, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 633, 525, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 642, 298, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 643, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 650, 514, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 651, 522, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 672, 157, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 718, 410, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 758, 167, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 812, 274, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 820, 409, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 821, 417, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 835, 409, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 908, 370, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 971, 337, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1080, 569, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1268, 556, 0, 0 },
    { 1, 0, 0x40, 6, 0x15, 0, 0, 0, 0, 0, 185, 274, 0, 0 },
    { 1, 0, 0x40, 6, 0x16, 0, 0, 0, 0, 0, 233, 298, 0, 0 },
    { 1, 0, 0x40, 6, 0x17, 0, 0, 0, 0, 0, 281, 322, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 164, 311, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 192, 229, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 393, 331, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 511, 381, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 514, 482, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 541, 92, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 639, 447, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 660, 178, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 731, 383, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 767, 326, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 791, 457, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 843, 243, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 861, 362, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1153, 592, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 139, 211, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 349, 379, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 467, 497, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 504, 336, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 567, 337, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 569, 438, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 577, 275, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 613, 264, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 650, 386, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 730, 179, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 735, 458, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 762, 229, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 776, 165, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 912, 408, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 919, 329, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1140, 529, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1234, 356, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1336, 600, 0, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 1072, 384, 422, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 1104, 368, 412, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 1120, 368, 404, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 1136, 368, 396, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 1152, 352, 389, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 1168, 352, 381, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 400, 144, 191, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 384, 160, 197, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 446, 290, 318, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 766, 258, 287, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 486, 160, 189, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 1099, 491, 511, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 207, 286, 286, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 255, 310, 310, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 303, 334, 334, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 735, 581, 581, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 799, 581, 581, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 864, 470, 470, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 912, 446, 446, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 960, 422, 422, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x234, 0x340, 0x90, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x239, 0xA8, 0x132, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x238, 0x1F2, 0x164, 3, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x48, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x30, 0x38, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x38, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
