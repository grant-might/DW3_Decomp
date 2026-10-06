#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x299
#define STAGE_ARCHIVE 0x30E
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x2A8
#define STAGE_ARCHIVE 0x31D
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x43C00, 0x25900};
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
extern u16 D_800A5128[];
extern u16 D_800A5134[];
extern u16 D_800A5140[];
extern u16 D_800A5148[];
extern u16 D_800A5158[];
extern u16 D_800A5160[];
extern u16 D_800A5170[];
extern u16 D_800A5178[];
extern u16 D_800A5188[];
extern u16 D_800A519C[];
extern u16 D_800A51A4[];
extern u16 D_800A51BC[];
extern u16 D_800A51C8[];
extern u16 D_800A51E4[];
extern u16 D_800A5204[];
extern u16 D_800A5224[];
extern u16 D_800A522C[];
extern u16 D_800A5234[];
extern u16 D_800A5240[];
extern u16 D_800A5248[];
extern u16 D_800A5254[];
extern u16 D_800A5260[];
extern u16 D_800A5268[];
extern u16 D_800A5270[];
extern u16 D_800A527C[];
extern u16 D_800A528C[];
extern u16 D_800A5294[];
extern u16 D_800A52A8[];
extern u16 D_800A52C0[];
extern u16 D_800A52CC[];
extern u16 D_800A52E8[];
extern u16 D_800A5304[];
extern u16 D_800A530C[];
extern u16 D_800A5318[];
extern u16 D_800A5324[];
extern u16 D_800A5330[];
extern u16 D_800A5338[];
extern u16 D_800A5348[];
extern u16 D_800A5350[];
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
extern u16 D_800A5430[];
extern u16 D_800A5438[];
extern u16 D_800A5444[];
extern u16 D_800A5450[];
extern u16 D_800A5458[];
extern u16 D_800A5460[];
extern u16 D_800A546C[];
extern u16 D_800A547C[];
extern u16 D_800A5484[];
extern u16 D_800A5498[];
extern u16 D_800A54B0[];
extern u16 D_800A54BC[];
extern u16 D_800A54D8[];
extern u16 D_800A54F4[];
extern u16 D_800A54FC[];
extern u16 D_800A5504[];
extern u16 D_800A5510[];
extern u16 D_800A5520[];
extern u16 D_800A5528[];
extern u16 D_800A553C[];
extern u16 D_800A5554[];
extern u16 D_800A555C[];
extern u16 D_800A5578[];
extern u16 D_800A5594[];
extern u16 D_800A559C[];
extern u16 D_800A55A4[];
extern u16 D_800A55B0[];
extern u16 D_800A55C0[];
extern u16 D_800A55C8[];
extern u16 D_800A55DC[];
extern u16 D_800A55F4[];
extern u16 D_800A55FC[];
extern u16 D_800A5618[];
extern u16 D_800A5634[];
extern u16 D_800A5954[];
extern FieldTalk D_800A563C[];
extern u16 D_800A5960[];
extern FieldTalk D_800A56C0[];
extern u16 D_800A596C[];
extern FieldTalk D_800A56D8[];
extern u16 D_800A5978[];
extern FieldTalk D_800A5708[];
extern u16 D_800A5984[];
extern FieldTalk D_800A5768[];
extern u16 D_800A5990[];
extern FieldTalk D_800A57EC[];
extern u16 D_800A599C[];
extern FieldTalk D_800A5804[];
extern u16 D_800A59A8[];
extern FieldTalk D_800A5834[];
extern u16 D_800A59B4[];
extern FieldTalk D_800A5894[];
extern u16 D_800A59BC[];
extern FieldTalk D_800A58F4[];
extern FieldActorEntry D_800A59C4;
extern FieldActorEntry D_800A59D8;
extern FieldActorEntry D_800A59EC;
extern FieldActorEntry D_800A5A00;
extern FieldActorEntry D_800A5A14;
extern FieldActorEntry D_800A5A28;
extern FieldActorEntry D_800A5A3C;
extern FieldActorEntry D_800A5A50;
extern FieldActorEntry D_800A5A64;
extern FieldActorEntry D_800A5A78;

Battle D_800A4E50 = { 161, 4, 0x60080000 };
Battle D_800A4E5C = { 161, 4, 0x60080000 };
Battle D_800A4E68 = { 161, 4, 0x60080000 };
Battle D_800A4E74 = { 110, 4, 0x60080000 };
Battle D_800A4E80 = { 110, 4, 0x60080000 };
Battle D_800A4E8C = { 153, 4, 0x60080000 };
Battle D_800A4E98 = { 153, 4, 0x60080000 };
Battle D_800A4EA4 = { 153, 4, 0x60080000 };
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
Battle D_800A4FDC = { 220, 4, 0x600C0000 };
Battle D_800A4FE8 = { 221, 4, 0x600C0000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 333, 4, 0x60080000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 127, 4, 0x60080000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
FieldBattles stageBattles[] = {
    { 84, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B4, 0x140, 0x1D0, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x174, 0x1C1, 0xD0, 0xC1, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1B4, 0x100, 0x1D0, 0, 0x160, 0x1FE },
    { 0x180, 0x100, 0x1B4, 0x120, 0x1D0, 0x20, 0x170, 0x1FE },
};
u16 D_800A511C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A5128[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5134[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A5140[] = { 0x11, 0, 0xFFFF };
u16 D_800A5148[] = { 0, 0, 0x7004, 1, 0x11, 0, 0xFFFF };
u16 D_800A5158[] = { 0, 1, 0xFFFF };
u16 D_800A5160[] = { 0, 0, 0x6026, 1, 0x11, 0, 0xFFFF };
u16 D_800A5170[] = { 0, 1, 0xFFFF };
u16 D_800A5178[] = { 0, 1, 0x7206, 0, 0x11, 0, 0xFFFF };
u16 D_800A5188[] = { 0, 1, 0x7206, 1, 0x7208, 0, 0x11, 0, 0xFFFF };
u16 D_800A519C[] = { 0x761E, 1, 0xFFFF };
u16 D_800A51A4[] = {
    0, 1, 0x7206, 1, 0xE14, 0, 0x7208, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A51BC[] = { 0xE14, 1, 0x7400, 1, 0xFFFF };
u16 D_800A51C8[] = {
    0, 1, 0x7206, 1, 0x8012, 0, 0x7208, 1,
    0xE14, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A51E4[] = {
    0xE14, 1, 0x720A, 0, 0, 1, 0x7206, 1,
    0x8012, 1, 0x7208, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5204[] = {
    0, 1, 0x7206, 1, 0x8012, 1, 0x7208, 1,
    0xE14, 1, 0x720A, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5224[] = { 0x781E, 1, 0xFFFF };
u16 D_800A522C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5234[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5240[] = { 0x11, 0, 0xFFFF };
u16 D_800A5248[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5254[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5260[] = { 0, 0, 0xFFFF };
u16 D_800A5268[] = { 0, 1, 0xFFFF };
u16 D_800A5270[] = { 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A527C[] = { 0, 1, 0x7206, 1, 0x8014, 0, 0xFFFF };
u16 D_800A528C[] = { 0x761E, 1, 0xFFFF };
u16 D_800A5294[] = { 0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A52A8[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE14, 0, 0xFFFF,
};
u16 D_800A52C0[] = { 0x7400, 1, 0xE14, 1, 0xFFFF };
u16 D_800A52CC[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE14, 1, 0x720A, 0, 0xFFFF,
};
u16 D_800A52E8[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE14, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A5304[] = { 0x781E, 1, 0xFFFF };
u16 D_800A530C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A5318[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5324[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A5330[] = { 0x11, 0, 0xFFFF };
u16 D_800A5338[] = { 1, 0, 0x11, 0, 0x7004, 1, 0xFFFF };
u16 D_800A5348[] = { 1, 1, 0xFFFF };
u16 D_800A5350[] = { 0x11, 0, 1, 0, 0x6026, 1, 0xFFFF };
u16 D_800A5360[] = { 1, 1, 0xFFFF };
u16 D_800A5368[] = { 1, 1, 0x7206, 0, 0x11, 0, 0xFFFF };
u16 D_800A5378[] = { 1, 1, 0x7206, 1, 0x7208, 0, 0x11, 0, 0xFFFF };
u16 D_800A538C[] = { 0x761F, 1, 0xFFFF };
u16 D_800A5394[] = {
    1, 1, 0x7206, 1, 0xE15, 0, 0x7208, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A53AC[] = { 0xE15, 1, 0x7400, 1, 0xFFFF };
u16 D_800A53B8[] = {
    1, 1, 0x7206, 1, 0x8012, 0, 0x7208, 1,
    0xE15, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A53D4[] = {
    1, 1, 0x7206, 1, 0x8012, 1, 0x7208, 1,
    0xE15, 1, 0x720A, 0, 0x11, 0, 0xFFFF,
};
u16 D_800A53F4[] = {
    1, 1, 0x7206, 1, 0x8012, 1, 0x7208, 1,
    0xE15, 1, 0x720A, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5414[] = { 0x781F, 1, 0xFFFF };
u16 D_800A541C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5424[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5430[] = { 0x11, 0, 0xFFFF };
u16 D_800A5438[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5444[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5450[] = { 1, 0, 0xFFFF };
u16 D_800A5458[] = { 1, 1, 0xFFFF };
u16 D_800A5460[] = { 1, 1, 0x7206, 0, 0xFFFF };
u16 D_800A546C[] = { 1, 1, 0x7206, 1, 0x8014, 0, 0xFFFF };
u16 D_800A547C[] = { 0x761F, 1, 0xFFFF };
u16 D_800A5484[] = { 1, 1, 0x7206, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5498[] = {
    1, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE15, 0, 0xFFFF,
};
u16 D_800A54B0[] = { 0x7400, 1, 0xE15, 1, 0xFFFF };
u16 D_800A54BC[] = {
    1, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE15, 1, 0x720A, 0, 0xFFFF,
};
u16 D_800A54D8[] = {
    1, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE15, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A54F4[] = { 0x781F, 1, 0xFFFF };
u16 D_800A54FC[] = { 0, 0, 0xFFFF };
u16 D_800A5504[] = { 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A5510[] = { 0, 1, 0x8014, 0, 0x7206, 1, 0xFFFF };
u16 D_800A5520[] = { 0x761E, 1, 0xFFFF };
u16 D_800A5528[] = { 0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A553C[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE14, 0, 0xFFFF,
};
u16 D_800A5554[] = { 0xE14, 1, 0xFFFF };
u16 D_800A555C[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE14, 1, 0x720A, 0, 0xFFFF,
};
u16 D_800A5578[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE14, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A5594[] = { 0x781E, 1, 0xFFFF };
u16 D_800A559C[] = { 1, 0, 0xFFFF };
u16 D_800A55A4[] = { 1, 1, 0x7206, 0, 0xFFFF };
u16 D_800A55B0[] = { 1, 1, 0x7206, 1, 0x8014, 0, 0xFFFF };
u16 D_800A55C0[] = { 0x761F, 1, 0xFFFF };
u16 D_800A55C8[] = { 1, 1, 0x7206, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A55DC[] = {
    1, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE15, 0, 0xFFFF,
};
u16 D_800A55F4[] = { 0xE15, 1, 0xFFFF };
u16 D_800A55FC[] = {
    1, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE15, 1, 0x720A, 0, 0xFFFF,
};
u16 D_800A5618[] = {
    1, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE15, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A5634[] = { 0x781F, 1, 0xFFFF };
FieldTalk D_800A563C[] = {
    { D_800A511C, D_800A5128, 0x187 },
    { D_800A5134, D_800A5140, 0x186 },
    { D_800A5148, D_800A5158, 0x17C },
    { D_800A5160, D_800A5170, 0x17D },
    { D_800A5178, NULL, 0x180 },
    { D_800A5188, D_800A519C, 0x181 },
    { D_800A51A4, D_800A51BC, 0x183 },
    { D_800A51C8, NULL, 0x182 },
    { D_800A51E4, NULL, 0x184 },
    { D_800A5204, D_800A5224, 0x185 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56C0[] = {
    { NULL, NULL, 0x297 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56D8[] = {
    { D_800A522C, NULL, 0x17C },
    { D_800A5234, D_800A5240, 0x186 },
    { D_800A5248, D_800A5254, 0x187 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5708[] = {
    { D_800A5260, D_800A5268, 0x17D },
    { D_800A5270, NULL, 0x180 },
    { D_800A527C, D_800A528C, 0x181 },
    { D_800A5294, NULL, 0x182 },
    { D_800A52A8, D_800A52C0, 0x183 },
    { D_800A52CC, NULL, 0x184 },
    { D_800A52E8, D_800A5304, 0x185 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5768[] = {
    { D_800A530C, D_800A5318, 0x193 },
    { D_800A5324, D_800A5330, 0x192 },
    { D_800A5338, D_800A5348, 0x188 },
    { D_800A5350, D_800A5360, 0x189 },
    { D_800A5368, NULL, 0x18C },
    { D_800A5378, D_800A538C, 0x18D },
    { D_800A5394, D_800A53AC, 0x18F },
    { D_800A53B8, NULL, 0x18E },
    { D_800A53D4, NULL, 0x190 },
    { D_800A53F4, D_800A5414, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57EC[] = {
    { NULL, NULL, 0x298 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5804[] = {
    { D_800A541C, NULL, 0x188 },
    { D_800A5424, D_800A5430, 0x192 },
    { D_800A5438, D_800A5444, 0x193 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5834[] = {
    { D_800A5450, D_800A5458, 0x189 },
    { D_800A5460, NULL, 0x18C },
    { D_800A546C, D_800A547C, 0x18D },
    { D_800A5484, NULL, 0x18E },
    { D_800A5498, D_800A54B0, 0x18F },
    { D_800A54BC, NULL, 0x190 },
    { D_800A54D8, D_800A54F4, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5894[] = {
    { D_800A54FC, NULL, 0x17E },
    { D_800A5504, NULL, 0x17E },
    { D_800A5510, D_800A5520, 0x17E },
    { D_800A5528, NULL, 0x17E },
    { D_800A553C, D_800A5554, 0x17E },
    { D_800A555C, NULL, 0x17E },
    { D_800A5578, D_800A5594, 0x17E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58F4[] = {
    { D_800A559C, NULL, 0x18A },
    { D_800A55A4, NULL, 0x18A },
    { D_800A55B0, D_800A55C0, 0x18A },
    { D_800A55C8, NULL, 0x18A },
    { D_800A55DC, D_800A55F4, 0x18A },
    { D_800A55FC, NULL, 0x18A },
    { D_800A5618, D_800A5634, 0x18A },
    { NULL, NULL, 0 },
};
u16 D_800A5954[] = { 0x8192, 1, 0x7022, 1, 0xFFFF };
u16 D_800A5960[] = { 0x8192, 0, 0x7022, 1, 0xFFFF };
u16 D_800A596C[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5978[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5984[] = { 0x7022, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5990[] = { 0x8192, 0, 0x7022, 1, 0xFFFF };
u16 D_800A599C[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A59A8[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A59B4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A59BC[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A59C4 = { D_800A5954, D_800A563C, 0x2D, 4, 464, 193, 1 };
FieldActorEntry D_800A59D8 = { D_800A5960, D_800A56C0, 0x2D, 4, 464, 193, 1 };
FieldActorEntry D_800A59EC = { D_800A596C, D_800A56D8, 0x2D, 4, 464, 193, 1 };
FieldActorEntry D_800A5A00 = { D_800A5978, D_800A5708, 0x2D, 4, 464, 193, 1 };
FieldActorEntry D_800A5A14 = { D_800A5984, D_800A5768, 0x39, 5, 1088, 234, 7 };
FieldActorEntry D_800A5A28 = { D_800A5990, D_800A57EC, 0x39, 5, 1088, 234, 7 };
FieldActorEntry D_800A5A3C = { D_800A599C, D_800A5804, 0x39, 5, 1088, 234, 7 };
FieldActorEntry D_800A5A50 = { D_800A59A8, D_800A5834, 0x39, 5, 1088, 234, 7 };
FieldActorEntry D_800A5A64 = { D_800A59B4, D_800A5894, 0x9D, 6, 464, 193, 1 };
FieldActorEntry D_800A5A78 = { D_800A59BC, D_800A58F4, 0x9E, 7, 1088, 234, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A59C4,
    &D_800A59D8,
    &D_800A59EC,
    &D_800A5A00,
    &D_800A5A14,
    &D_800A5A28,
    &D_800A5A3C,
    &D_800A5A50,
    &D_800A5A64,
    &D_800A5A78,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 1, 6, 0, 603, 223, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 1, 6, 0, 952, 485, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 6, 0, 567, 357, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 6, 0, 604, 375, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 6, 0, 857, 450, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 529, 660, 0, 0 },
    { 1, 0, 0x40, 2, 3, 1, 3, 8, 8, 0, 201, 398, 0, 0 },
    { 1, 0, 0x40, 2, 3, 1, 3, 8, 8, 0, 215, 598, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 140, 499, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 476, 616, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 569, 552, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 827, 661, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 408, 122, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 479, 678, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 772, 301, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 869, 528, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 919, 263, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 929, 414, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 1166, 732, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 1218, 758, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 6, 0, 986, 299, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 6, 0, 1025, 319, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 6, 0, 1195, 732, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 1, 6, 0, 522, 632, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 1, 6, 0, 599, 379, 0, 0 },
    { 1, 0, 0xC4, 4, 0, 0, 0, 0, 0, 0, 413, 523, 715, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 699, 190, 233, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 138, 383, 410, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 161, 328, 364, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 542, 196, 217, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 208, 311, 311, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 672, 719, 719, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 688, 455, 455, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 720, 743, 743, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 736, 479, 479, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 864, 175, 175, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 928, 351, 351, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 944, 167, 167, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x266, 0x390, 0x1E8, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x261, 0x80, 0x90, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x268, 0x390, 0x118, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x20F, 0xF8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x21F, 0x190, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x34F, 0x106, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x35F, 0x16F, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x440, 0x161, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x430, 0x1C8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x3EF, 0x2C9, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x3E1, 0x32F, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x150, 0x258, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x15F, 0x2BE, 0, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 5, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0xA, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 6, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x16, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
