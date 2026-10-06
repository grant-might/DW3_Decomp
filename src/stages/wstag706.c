#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x674
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x684
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x4BE00, 0x8800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3E;
    D_800990B4.music = 0x60F80000;
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
extern u16 D_800A5108[];
extern u16 D_800A5118[];
extern u16 D_800A5120[];
extern u16 D_800A5128[];
extern u16 D_800A5130[];
extern u16 D_800A5138[];
extern u16 D_800A5144[];
extern u16 D_800A5150[];
extern u16 D_800A515C[];
extern u16 D_800A5168[];
extern u16 D_800A5170[];
extern u16 D_800A517C[];
extern u16 D_800A5184[];
extern u16 D_800A5194[];
extern u16 D_800A51A8[];
extern u16 D_800A51B0[];
extern u16 D_800A51C8[];
extern u16 D_800A51D4[];
extern u16 D_800A51F0[];
extern u16 D_800A5210[];
extern u16 D_800A5230[];
extern u16 D_800A5238[];
extern u16 D_800A5240[];
extern u16 D_800A5248[];
extern u16 D_800A5254[];
extern u16 D_800A5264[];
extern u16 D_800A5270[];
extern u16 D_800A5284[];
extern u16 D_800A5298[];
extern u16 D_800A52A0[];
extern u16 D_800A52AC[];
extern u16 D_800A52B8[];
extern u16 D_800A52C4[];
extern u16 D_800A52CC[];
extern u16 D_800A52D8[];
extern u16 D_800A52E0[];
extern u16 D_800A52F0[];
extern u16 D_800A5304[];
extern u16 D_800A530C[];
extern u16 D_800A5324[];
extern u16 D_800A5330[];
extern u16 D_800A534C[];
extern u16 D_800A536C[];
extern u16 D_800A538C[];
extern u16 D_800A5394[];
extern u16 D_800A539C[];
extern u16 D_800A53A4[];
extern u16 D_800A53B0[];
extern u16 D_800A53C0[];
extern u16 D_800A53CC[];
extern u16 D_800A53E0[];
extern u16 D_800A53F4[];
extern u16 D_800A53FC[];
extern u16 D_800A5404[];
extern u16 D_800A540C[];
extern u16 D_800A5414[];
extern u16 D_800A541C[];
extern u16 D_800A5650[];
extern FieldTalk D_800A5428[];
extern u16 D_800A5658[];
extern FieldTalk D_800A5440[];
extern u16 D_800A5660[];
extern FieldTalk D_800A5470[];
extern u16 D_800A566C[];
extern FieldTalk D_800A54E8[];
extern u16 D_800A5674[];
extern FieldTalk D_800A5530[];
extern u16 D_800A5680[];
extern FieldTalk D_800A5548[];
extern u16 D_800A568C[];
extern FieldTalk D_800A55C0[];
extern u16 D_800A5694[];
extern FieldTalk D_800A5608[];
extern u16 D_800A569C[];
extern FieldTalk D_800A5638[];
extern FieldActorEntry D_800A56A8;
extern FieldActorEntry D_800A56BC;
extern FieldActorEntry D_800A56D0;
extern FieldActorEntry D_800A56E4;
extern FieldActorEntry D_800A56F8;
extern FieldActorEntry D_800A570C;
extern FieldActorEntry D_800A5720;
extern FieldActorEntry D_800A5734;
extern FieldActorEntry D_800A5748;

Battle D_800A4E4C = { 184, 14, 0x60080000 };
Battle D_800A4E58 = { 184, 14, 0x60080000 };
Battle D_800A4E64 = { 184, 14, 0x60080000 };
Battle D_800A4E70 = { 184, 14, 0x60080000 };
Battle D_800A4E7C = { 160, 14, 0x60080000 };
Battle D_800A4E88 = { 160, 14, 0x60080000 };
Battle D_800A4E94 = { 160, 14, 0x60080000 };
Battle D_800A4EA0 = { 160, 14, 0x60080000 };
BattleList D_800A4EAC = {
    2,
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
Battle D_800A4FD8 = { 247, 14, 0x60080000 };
Battle D_800A4FE4 = { 248, 14, 0x60080000 };
Battle D_800A4FF0 = { 295, 14, 0x600C0000 };
Battle D_800A4FFC = { 296, 14, 0x600C0000 };
Battle D_800A5008 = { 0, 0, 0x60040000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 0, 0, 0x60040000 };
Battle D_800A502C = { 0, 0, 0x60040000 };
BattleList D_800A5038 = {
    0,
    { &D_800A4FD8, &D_800A4FE4, &D_800A4FF0, &D_800A4FFC,
      &D_800A5008, &D_800A5014, &D_800A5020, &D_800A502C },
};
FieldBattles stageBattles[] = {
    { 114, 0, 0, { &D_800A4EAC, &D_800A4F30, &D_800A4FB4, &D_800A5038 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16A, 0x100, 0xA8, 0, 0x140, 0x1FF },
    { 0x140, 0x100, 0x15A, 0x100, 0x68, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x162, 0x100, 0x88, 0, 0x160, 0x1FF },
};
u16 D_800A5108[] = { 0x7090, 1, 0x252, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5118[] = { 0x11, 0, 0xFFFF };
u16 D_800A5120[] = { 0x10, 0, 0xFFFF };
u16 D_800A5128[] = { 0x11, 0, 0xFFFF };
u16 D_800A5130[] = { 0x10, 1, 0xFFFF };
u16 D_800A5138[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5144[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A5150[] = { 0x10, 0, 0x11, 0, 0xFFFF };
u16 D_800A515C[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5168[] = { 0x11, 0, 0xFFFF };
u16 D_800A5170[] = { 0, 0, 0x11, 0, 0xFFFF };
u16 D_800A517C[] = { 0, 1, 0xFFFF };
u16 D_800A5184[] = { 0x7208, 0, 0, 1, 0x11, 0, 0xFFFF };
u16 D_800A5194[] = { 0x720A, 0, 0x7208, 1, 0, 1, 0x11, 0, 0xFFFF };
u16 D_800A51A8[] = { 0x763F, 1, 0xFFFF };
u16 D_800A51B0[] = {
    0xE32, 0, 0x720A, 1, 0x7208, 1, 0, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A51C8[] = { 0x7400, 1, 0xE32, 1, 0xFFFF };
u16 D_800A51D4[] = {
    0x8014, 0, 0xE32, 1, 0x720A, 1, 0x7208, 1,
    0, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A51F0[] = {
    0x720B, 0, 0x8014, 1, 0xE32, 1, 0x720A, 1,
    0x7208, 1, 0, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5210[] = {
    0x720B, 1, 0x8014, 1, 0xE32, 1, 0x720A, 1,
    0x7208, 1, 0, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5230[] = { 0x783F, 1, 0xFFFF };
u16 D_800A5238[] = { 0, 0, 0xFFFF };
u16 D_800A5240[] = { 0, 1, 0xFFFF };
u16 D_800A5248[] = { 0x720B, 0, 0, 1, 0xFFFF };
u16 D_800A5254[] = { 0x720B, 1, 0, 1, 0xE53, 0, 0xFFFF };
u16 D_800A5264[] = { 0xE53, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5270[] = { 0x720B, 1, 0, 1, 0xE53, 1, 0x720D, 0, 0xFFFF };
u16 D_800A5284[] = { 0, 1, 0x720B, 1, 0xE53, 1, 0x720D, 1, 0xFFFF };
u16 D_800A5298[] = { 0x783F, 1, 0xFFFF };
u16 D_800A52A0[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A52AC[] = { 0x10, 0, 0x11, 0, 0xFFFF };
u16 D_800A52B8[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A52C4[] = { 0x11, 0, 0xFFFF };
u16 D_800A52CC[] = { 1, 0, 0x11, 0, 0xFFFF };
u16 D_800A52D8[] = { 1, 1, 0xFFFF };
u16 D_800A52E0[] = { 0x7208, 0, 1, 1, 0x11, 0, 0xFFFF };
u16 D_800A52F0[] = { 0x720A, 0, 0x7208, 1, 1, 1, 0x11, 0, 0xFFFF };
u16 D_800A5304[] = { 0x7640, 1, 0xFFFF };
u16 D_800A530C[] = {
    0xE33, 0, 0x720A, 1, 0x7208, 1, 1, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A5324[] = { 0x7401, 1, 0xE33, 1, 0xFFFF };
u16 D_800A5330[] = {
    0x8014, 0, 0xE33, 1, 0x720A, 1, 0x7208, 1,
    1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A534C[] = {
    0x720B, 0, 0x8014, 1, 0xE33, 1, 0x720A, 1,
    0x7208, 1, 1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A536C[] = {
    0x720B, 1, 0x8014, 1, 0xE33, 1, 0x720A, 1,
    0x7208, 1, 1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A538C[] = { 0x7840, 1, 0xFFFF };
u16 D_800A5394[] = { 1, 0, 0xFFFF };
u16 D_800A539C[] = { 1, 1, 0xFFFF };
u16 D_800A53A4[] = { 1, 1, 0x720B, 0, 0xFFFF };
u16 D_800A53B0[] = { 1, 1, 0x720B, 1, 0xE54, 0, 0xFFFF };
u16 D_800A53C0[] = { 0x7401, 1, 0xE54, 1, 0xFFFF };
u16 D_800A53CC[] = { 1, 1, 0x720B, 1, 0xE54, 1, 0x720D, 0, 0xFFFF };
u16 D_800A53E0[] = { 1, 1, 0x720B, 1, 0xE54, 1, 0x720D, 1, 0xFFFF };
u16 D_800A53F4[] = { 0x7840, 1, 0xFFFF };
u16 D_800A53FC[] = { 0x11, 0, 0xFFFF };
u16 D_800A5404[] = { 0x10, 0, 0xFFFF };
u16 D_800A540C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5414[] = { 0x10, 1, 0xFFFF };
u16 D_800A541C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
FieldTalk D_800A5428[] = {
    { NULL, D_800A5108, 0x345 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5440[] = {
    { D_800A5118, NULL, 0x39C },
    { D_800A5120, D_800A5128, 0x249 },
    { D_800A5130, D_800A5138, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5470[] = {
    { D_800A5144, D_800A5150, 0x22A },
    { D_800A515C, D_800A5168, 0x229 },
    { D_800A5170, D_800A517C, 0x224 },
    { D_800A5184, NULL, 0x225 },
    { D_800A5194, D_800A51A8, 0x226 },
    { D_800A51B0, D_800A51C8, 0x227 },
    { D_800A51D4, NULL, 0x228 },
    { D_800A51F0, NULL, 0x225 },
    { D_800A5210, D_800A5230, 0x226 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E8[] = {
    { D_800A5238, D_800A5240, 0x24C },
    { D_800A5248, NULL, 0x24E },
    { D_800A5254, D_800A5264, 0x24D },
    { D_800A5270, NULL, 0x248 },
    { D_800A5284, D_800A5298, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5530[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5548[] = {
    { D_800A52A0, D_800A52AC, 0x24A },
    { D_800A52B8, D_800A52C4, 0x249 },
    { D_800A52CC, D_800A52D8, 0x244 },
    { D_800A52E0, NULL, 0x245 },
    { D_800A52F0, D_800A5304, 0x246 },
    { D_800A530C, D_800A5324, 0x247 },
    { D_800A5330, NULL, 0x248 },
    { D_800A534C, NULL, 0x24B },
    { D_800A536C, D_800A538C, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55C0[] = {
    { D_800A5394, D_800A539C, 0x22C },
    { D_800A53A4, NULL, 0x22E },
    { D_800A53B0, D_800A53C0, 0x22D },
    { D_800A53CC, NULL, 0x228 },
    { D_800A53E0, D_800A53F4, 0x22F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5608[] = {
    { D_800A53FC, NULL, 0x39D },
    { D_800A5404, D_800A540C, 0x229 },
    { D_800A5414, D_800A541C, 0x22A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5638[] = {
    { NULL, NULL, 0x22B },
    { NULL, NULL, 0 },
};
u16 D_800A5650[] = { 0x252, 0, 0xFFFF };
u16 D_800A5658[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5660[] = { 0x8192, 1, 0x7019, 1, 0xFFFF };
u16 D_800A566C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5674[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5680[] = { 0x7019, 1, 0x8192, 1, 0xFFFF };
u16 D_800A568C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5694[] = { 0x602B, 1, 0xFFFF };
u16 D_800A569C[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
FieldActorEntry D_800A56A8 = { D_800A5650, D_800A5428, 0x21, 4, 1281, 401, 1 };
FieldActorEntry D_800A56BC = { D_800A5658, D_800A5440, 0x45, 5, 561, 841, 1 };
FieldActorEntry D_800A56D0 = { D_800A5660, D_800A5470, 0x45, 5, 561, 841, 1 };
FieldActorEntry D_800A56E4 = { D_800A566C, D_800A54E8, 0x45, 5, 561, 841, 1 };
FieldActorEntry D_800A56F8 = { D_800A5674, D_800A5530, 0x45, 5, 561, 841, 1 };
FieldActorEntry D_800A570C = { D_800A5680, D_800A5548, 0x46, 6, 992, 273, 7 };
FieldActorEntry D_800A5720 = { D_800A568C, D_800A55C0, 0x46, 6, 992, 273, 7 };
FieldActorEntry D_800A5734 = { D_800A5694, D_800A5608, 0x46, 6, 992, 273, 7 };
FieldActorEntry D_800A5748 = { D_800A569C, D_800A5638, 0x46, 6, 992, 273, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A56A8,
    &D_800A56BC,
    &D_800A56D0,
    &D_800A56E4,
    &D_800A56F8,
    &D_800A570C,
    &D_800A5720,
    &D_800A5734,
    &D_800A5748,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 834, 768, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 889, 248, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 998, 143, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 1192, 110, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D5, 0xE0, 0x3A8, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CA, 0x3A0, 0xA0, 1, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x18, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 0xD, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 5, 3 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0xB, 2 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x420, 0x140, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x410, 0x1D8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x460, 0x2A0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x450, 0x338, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x430, 0x288, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x420, 0x2F0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x36F, 0x1D8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x37F, 0x240, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x32F, 0x288, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x33F, 0x320, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x1F0, 0x338, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x1E0, 0x3A0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 0xD, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 0xA, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
