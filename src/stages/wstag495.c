#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x3B7
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x3C7
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x10300, 0x1EC00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x36;
    D_800990B4.music = 0x60D80000;
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
extern u16 D_800A511C[];
extern u16 D_800A5124[];
extern u16 D_800A512C[];
extern u16 D_800A5138[];
extern u16 D_800A5148[];
extern u16 D_800A5150[];
extern u16 D_800A5164[];
extern u16 D_800A5170[];
extern u16 D_800A5188[];
extern u16 D_800A51A4[];
extern u16 D_800A51C0[];
extern u16 D_800A51C8[];
extern u16 D_800A51D0[];
extern u16 D_800A51D8[];
extern u16 D_800A51E4[];
extern u16 D_800A51F4[];
extern u16 D_800A51FC[];
extern u16 D_800A5210[];
extern u16 D_800A521C[];
extern u16 D_800A5234[];
extern u16 D_800A5250[];
extern u16 D_800A526C[];
extern u16 D_800A5274[];
extern u16 D_800A527C[];
extern u16 D_800A5284[];
extern u16 D_800A5290[];
extern u16 D_800A52A0[];
extern u16 D_800A52A8[];
extern u16 D_800A52BC[];
extern u16 D_800A52C8[];
extern u16 D_800A52E0[];
extern u16 D_800A52FC[];
extern u16 D_800A5318[];
extern u16 D_800A5320[];
extern u16 D_800A5328[];
extern u16 D_800A5334[];
extern u16 D_800A533C[];
extern u16 D_800A5348[];
extern u16 D_800A5354[];
extern u16 D_800A5360[];
extern u16 D_800A5368[];
extern u16 D_800A5374[];
extern u16 D_800A537C[];
extern u16 D_800A5384[];
extern u16 D_800A538C[];
extern u16 D_800A5398[];
extern u16 D_800A53A8[];
extern u16 D_800A53B0[];
extern u16 D_800A53C4[];
extern u16 D_800A53CC[];
extern u16 D_800A53E4[];
extern u16 D_800A5400[];
extern u16 D_800A541C[];
extern u16 D_800A5688[];
extern FieldTalk D_800A5424[];
extern u16 D_800A5698[];
extern FieldTalk D_800A5484[];
extern u16 D_800A56A8[];
extern FieldTalk D_800A54E4[];
extern u16 D_800A56B8[];
extern FieldTalk D_800A54FC[];
extern u16 D_800A56C8[];
extern FieldTalk D_800A555C[];
extern u16 D_800A56D8[];
extern FieldTalk D_800A558C[];
extern u16 D_800A56E0[];
extern FieldTalk D_800A55A4[];
extern u16 D_800A56E8[];
extern FieldTalk D_800A55BC[];
extern u16 D_800A56F0[];
extern FieldTalk D_800A55D4[];
extern u16 D_800A56F8[];
extern FieldTalk D_800A55EC[];
extern u16 D_800A5700[];
extern FieldTalk D_800A5610[];
extern u16 D_800A5708[];
extern FieldTalk D_800A5628[];
extern FieldActorEntry D_800A5710;
extern FieldActorEntry D_800A5724;
extern FieldActorEntry D_800A5738;
extern FieldActorEntry D_800A574C;
extern FieldActorEntry D_800A5760;
extern FieldActorEntry D_800A5774;
extern FieldActorEntry D_800A5788;
extern FieldActorEntry D_800A579C;
extern FieldActorEntry D_800A57B0;
extern FieldActorEntry D_800A57C4;
extern FieldActorEntry D_800A57D8;
extern FieldActorEntry D_800A57EC;

Battle D_800A4E50 = { 59, 2, 0x60080000 };
Battle D_800A4E5C = { 59, 2, 0x60080000 };
Battle D_800A4E68 = { 59, 2, 0x60080000 };
Battle D_800A4E74 = { 59, 2, 0x60080000 };
Battle D_800A4E80 = { 59, 2, 0x60080000 };
Battle D_800A4E8C = { 59, 2, 0x60080000 };
Battle D_800A4E98 = { 59, 2, 0x60080000 };
Battle D_800A4EA4 = { 59, 2, 0x60080000 };
BattleList D_800A4EB0 = {
    3,
    { &D_800A4E50, &D_800A4E5C, &D_800A4E68, &D_800A4E74,
      &D_800A4E80, &D_800A4E8C, &D_800A4E98, &D_800A4EA4 },
};
Battle D_800A4ED4 = { 152, 2, 0x60080000 };
Battle D_800A4EE0 = { 152, 2, 0x60080000 };
Battle D_800A4EEC = { 152, 2, 0x60080000 };
Battle D_800A4EF8 = { 152, 2, 0x60080000 };
Battle D_800A4F04 = { 152, 2, 0x60080000 };
Battle D_800A4F10 = { 152, 2, 0x60080000 };
Battle D_800A4F1C = { 152, 2, 0x60080000 };
Battle D_800A4F28 = { 152, 2, 0x60080000 };
BattleList D_800A4F34 = {
    3,
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
Battle D_800A4FDC = { 214, 2, 0x600C0000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 328, 2, 0x60080000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 59, 2, 0x60080000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
FieldBattles stageBattles[] = {
    { 21, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16C, 0x130, 0xB0, 0x30, 0x150, 0x1FF },
    { 0x140, 0x100, 0x174, 0x130, 0xD0, 0x30, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x100, 0xB0, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x158, 0xB0, 0x58, 0x140, 0x1FE },
};
u16 D_800A511C[] = { 0, 0, 0xFFFF };
u16 D_800A5124[] = { 0, 1, 0xFFFF };
u16 D_800A512C[] = { 0x7202, 0, 0, 1, 0xFFFF };
u16 D_800A5138[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A5148[] = { 0x7618, 1, 0xFFFF };
u16 D_800A5150[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 0, 0xFFFF };
u16 D_800A5164[] = { 0x7400, 1, 0xE0E, 1, 0xFFFF };
u16 D_800A5170[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5188[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A51A4[] = {
    0, 1, 0x7204, 1, 0xE0E, 1, 0x7202, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A51C0[] = { 0x7818, 1, 0xFFFF };
u16 D_800A51C8[] = { 0, 0, 0xFFFF };
u16 D_800A51D0[] = { 0, 1, 0xFFFF };
u16 D_800A51D8[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A51E4[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A51F4[] = { 0x7618, 1, 0xFFFF };
u16 D_800A51FC[] = { 0x7202, 1, 0xE0E, 0, 0, 1, 0x7204, 1, 0xFFFF };
u16 D_800A5210[] = { 0x7400, 1, 0xE0E, 1, 0xFFFF };
u16 D_800A521C[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5234[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A5250[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A526C[] = { 0x7818, 1, 0xFFFF };
u16 D_800A5274[] = { 0, 0, 0xFFFF };
u16 D_800A527C[] = { 0, 1, 0xFFFF };
u16 D_800A5284[] = { 0x7202, 0, 0, 1, 0xFFFF };
u16 D_800A5290[] = { 0, 1, 0x7204, 0, 0x7202, 1, 0xFFFF };
u16 D_800A52A0[] = { 0x7618, 1, 0xFFFF };
u16 D_800A52A8[] = { 0x7202, 1, 0xE0E, 0, 0, 1, 0x7204, 1, 0xFFFF };
u16 D_800A52BC[] = { 0x7400, 1, 0xE0E, 1, 0xFFFF };
u16 D_800A52C8[] = {
    0x7202, 1, 0xE0E, 1, 0, 1, 0x7204, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A52E0[] = {
    0, 1, 0x7204, 1, 0x7202, 1, 0xE0E, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A52FC[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A5318[] = { 0x7818, 1, 0xFFFF };
u16 D_800A5320[] = { 0x11, 0, 0xFFFF };
u16 D_800A5328[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5334[] = { 0x11, 0, 0xFFFF };
u16 D_800A533C[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5348[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5354[] = { 0x8028, 1, 0x8029, 0, 0xFFFF };
u16 D_800A5360[] = { 0x9402, 1, 0xFFFF };
u16 D_800A5368[] = { 0x8028, 1, 0x8029, 1, 0xFFFF };
u16 D_800A5374[] = { 0x9406, 1, 0xFFFF };
u16 D_800A537C[] = { 0x940D, 1, 0xFFFF };
u16 D_800A5384[] = { 0, 0, 0xFFFF };
u16 D_800A538C[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5398[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A53A8[] = { 0x7618, 1, 0xFFFF };
u16 D_800A53B0[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 0, 0xFFFF };
u16 D_800A53C4[] = { 0xE0E, 1, 0xFFFF };
u16 D_800A53CC[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A53E4[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A5400[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0E, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A541C[] = { 0x7818, 1, 0xFFFF };
FieldTalk D_800A5424[] = {
    { D_800A511C, D_800A5124, 0xB2 },
    { D_800A512C, NULL, 0xB6 },
    { D_800A5138, D_800A5148, 0xB7 },
    { D_800A5150, D_800A5164, 0xB8 },
    { D_800A5170, NULL, 0xB9 },
    { D_800A5188, NULL, 0xBA },
    { D_800A51A4, D_800A51C0, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5484[] = {
    { D_800A51C8, D_800A51D0, 0xB3 },
    { D_800A51D8, NULL, 0xB6 },
    { D_800A51E4, D_800A51F4, 0xB7 },
    { D_800A51FC, D_800A5210, 0xB8 },
    { D_800A521C, NULL, 0xB9 },
    { D_800A5234, NULL, 0xBA },
    { D_800A5250, D_800A526C, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E4[] = {
    { NULL, NULL, 0xB2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54FC[] = {
    { D_800A5274, D_800A527C, 0xB4 },
    { D_800A5284, NULL, 0xB6 },
    { D_800A5290, D_800A52A0, 0xB7 },
    { D_800A52A8, D_800A52BC, 0xB8 },
    { D_800A52C8, NULL, 0xB9 },
    { D_800A52E0, NULL, 0xBA },
    { D_800A52FC, D_800A5318, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A555C[] = {
    { D_800A5320, NULL, 0xB2 },
    { D_800A5328, D_800A5334, 0xBC },
    { D_800A533C, D_800A5348, 0xBD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A558C[] = {
    { NULL, NULL, 0x332 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A4[] = {
    { NULL, NULL, 0x332 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55BC[] = {
    { NULL, NULL, 0x332 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55D4[] = {
    { NULL, NULL, 0x332 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55EC[] = {
    { D_800A5354, D_800A5360, 0x23 },
    { D_800A5368, D_800A5374, 0x23 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5610[] = {
    { NULL, D_800A537C, 0x23 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5628[] = {
    { D_800A5384, NULL, 0xB5 },
    { D_800A538C, NULL, 0xB5 },
    { D_800A5398, D_800A53A8, 0xB5 },
    { D_800A53B0, D_800A53C4, 0xB5 },
    { D_800A53CC, NULL, 0xB5 },
    { D_800A53E4, NULL, 0xB5 },
    { D_800A5400, D_800A541C, 0xB5 },
    { NULL, NULL, 0 },
};
u16 D_800A5688[] = { 0x7003, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5698[] = { 0x7004, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A56A8[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A56B8[] = { 0x6026, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A56C8[] = { 0x7009, 1, 0x11, 1, 0x8192, 1, 0xFFFF };
u16 D_800A56D8[] = { 0x600B, 1, 0xFFFF };
u16 D_800A56E0[] = { 0x600C, 1, 0xFFFF };
u16 D_800A56E8[] = { 0x600D, 1, 0xFFFF };
u16 D_800A56F0[] = { 0x600E, 1, 0xFFFF };
u16 D_800A56F8[] = { 0x802A, 0, 0xFFFF };
u16 D_800A5700[] = { 0x802A, 1, 0xFFFF };
u16 D_800A5708[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5710 = { D_800A5688, D_800A5424, 0x35, 4, 480, 480, 7 };
FieldActorEntry D_800A5724 = { D_800A5698, D_800A5484, 0x35, 4, 480, 480, 7 };
FieldActorEntry D_800A5738 = { D_800A56A8, D_800A54E4, 0x35, 4, 480, 480, 7 };
FieldActorEntry D_800A574C = { D_800A56B8, D_800A54FC, 0x35, 4, 480, 480, 7 };
FieldActorEntry D_800A5760 = { D_800A56C8, D_800A555C, 0x35, 4, 480, 480, 7 };
FieldActorEntry D_800A5774 = { D_800A56D8, D_800A558C, 0x65, 5, 192, 496, 1 };
FieldActorEntry D_800A5788 = { D_800A56E0, D_800A55A4, 0x65, 5, 192, 496, 1 };
FieldActorEntry D_800A579C = { D_800A56E8, D_800A55BC, 0x65, 5, 192, 496, 1 };
FieldActorEntry D_800A57B0 = { D_800A56F0, D_800A55D4, 0x65, 5, 192, 496, 1 };
FieldActorEntry D_800A57C4 = { D_800A56F8, D_800A55EC, 0x86, 6, 204, 412, 7 };
FieldActorEntry D_800A57D8 = { D_800A5700, D_800A5610, 0x86, 6, 204, 412, 7 };
FieldActorEntry D_800A57EC = { D_800A5708, D_800A5628, 0x9D, 7, 480, 480, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5710,
    &D_800A5724,
    &D_800A5738,
    &D_800A574C,
    &D_800A5760,
    &D_800A5774,
    &D_800A5788,
    &D_800A579C,
    &D_800A57B0,
    &D_800A57C4,
    &D_800A57D8,
    &D_800A57EC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 427, 217, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 182, 185, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 267, 201, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 377, 286, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 400, 136, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 456, 92, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 211, 228, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 347, 466, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 445, 194, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 48, 497, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 369, 416, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 496, 331, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 667, 251, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 712, 378, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 142, 472, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 356, 367, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 541, 241, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 564, 420, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 640, 332, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 730, 597, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 839, 559, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 34, 567, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 138, 506, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 19, 568, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 214, 575, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 324, 588, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 445, 584, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 587, 528, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 739, 511, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 18, 509, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 182, 191, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 232, 601, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 262, 206, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 361, 453, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 417, 288, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 467, 189, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 479, 600, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 516, 331, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 558, 244, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 648, 406, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 697, 378, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 716, 634, 0, 0 },
    { 1, 0, 0x64, 4, 6, 0, 0, 0, 0, 0, 209, 351, 391, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23C, 0x88, 0x1BE, 7, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 9, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x50, 0xFFD8, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
