#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D48(void) {
    FLAGS_00.applyAction(0x7C19, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x61F
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x62F
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1CB00, 0x21100};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x16;
    D_800990B4.music = 0x60580000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4EE4;
extern Battle D_800A4EF0;
extern Battle D_800A4EFC;
extern Battle D_800A4F08;
extern Battle D_800A4F14;
extern Battle D_800A4F20;
extern Battle D_800A4F2C;
extern Battle D_800A4F38;
extern Battle D_800A4F68;
extern Battle D_800A4F74;
extern Battle D_800A4F80;
extern Battle D_800A4F8C;
extern Battle D_800A4F98;
extern Battle D_800A4FA4;
extern Battle D_800A4FB0;
extern Battle D_800A4FBC;
extern Battle D_800A4FEC;
extern Battle D_800A4FF8;
extern Battle D_800A5004;
extern Battle D_800A5010;
extern Battle D_800A501C;
extern Battle D_800A5028;
extern Battle D_800A5034;
extern Battle D_800A5040;
extern Battle D_800A5070;
extern Battle D_800A507C;
extern Battle D_800A5088;
extern Battle D_800A5094;
extern Battle D_800A50A0;
extern Battle D_800A50AC;
extern Battle D_800A50B8;
extern Battle D_800A50C4;
extern BattleList D_800A4F44;
extern BattleList D_800A4FC8;
extern BattleList D_800A504C;
extern BattleList D_800A50D0;
extern u16 D_800A5240[];
extern u16 D_800A5248[];
extern u16 D_800A5250[];
extern u16 D_800A5258[];
extern u16 D_800A5260[];
extern u16 D_800A5268[];
extern u16 D_800A5270[];
extern u16 D_800A5278[];
extern u16 D_800A5284[];
extern u16 D_800A5294[];
extern u16 D_800A52A0[];
extern u16 D_800A52B0[];
extern u16 D_800A52BC[];
extern u16 D_800A52CC[];
extern u16 D_800A52D4[];
extern u16 D_800A52E4[];
extern u16 D_800A52EC[];
extern u16 D_800A52FC[];
extern u16 D_800A5304[];
extern u16 D_800A5314[];
extern u16 D_800A531C[];
extern u16 D_800A532C[];
extern u16 D_800A5340[];
extern u16 D_800A5348[];
extern u16 D_800A5360[];
extern u16 D_800A536C[];
extern u16 D_800A5388[];
extern u16 D_800A53A8[];
extern u16 D_800A53C8[];
extern u16 D_800A53D0[];
extern u16 D_800A53D8[];
extern u16 D_800A53E0[];
extern u16 D_800A53E8[];
extern u16 D_800A53F0[];
extern u16 D_800A53F8[];
extern u16 D_800A5400[];
extern u16 D_800A5408[];
extern u16 D_800A5410[];
extern u16 D_800A5418[];
extern u16 D_800A5424[];
extern u16 D_800A542C[];
extern u16 D_800A5434[];
extern u16 D_800A5444[];
extern u16 D_800A5450[];
extern u16 D_800A5460[];
extern u16 D_800A546C[];
extern u16 D_800A547C[];
extern u16 D_800A5484[];
extern u16 D_800A5494[];
extern u16 D_800A549C[];
extern u16 D_800A54AC[];
extern u16 D_800A54B4[];
extern u16 D_800A54C4[];
extern u16 D_800A54CC[];
extern u16 D_800A54DC[];
extern u16 D_800A54F0[];
extern u16 D_800A54F8[];
extern u16 D_800A5510[];
extern u16 D_800A551C[];
extern u16 D_800A5538[];
extern u16 D_800A5558[];
extern u16 D_800A5578[];
extern u16 D_800A5580[];
extern u16 D_800A5590[];
extern u16 D_800A559C[];
extern u16 D_800A55AC[];
extern u16 D_800A55B8[];
extern u16 D_800A55C8[];
extern u16 D_800A55D0[];
extern u16 D_800A55E0[];
extern u16 D_800A55E8[];
extern u16 D_800A55F8[];
extern u16 D_800A5600[];
extern u16 D_800A5610[];
extern u16 D_800A5618[];
extern u16 D_800A5628[];
extern u16 D_800A563C[];
extern u16 D_800A5644[];
extern u16 D_800A565C[];
extern u16 D_800A5668[];
extern u16 D_800A5684[];
extern u16 D_800A56A4[];
extern u16 D_800A56C4[];
extern u16 D_800A56CC[];
extern u16 D_800A56D4[];
extern u16 D_800A56DC[];
extern u16 D_800A56E4[];
extern u16 D_800A56EC[];
extern u16 D_800A56F8[];
extern u16 D_800A5700[];
extern FieldTalk D_800A5708[];
extern FieldTalk D_800A5720[];
extern FieldTalk D_800A5738[];
extern u16 D_800A5AE0[];
extern FieldTalk D_800A5750[];
extern u16 D_800A5AEC[];
extern FieldTalk D_800A5780[];
extern u16 D_800A5AF8[];
extern FieldTalk D_800A581C[];
extern u16 D_800A5B04[];
extern FieldTalk D_800A5840[];
extern u16 D_800A5B0C[];
extern FieldTalk D_800A5858[];
extern u16 D_800A5B14[];
extern FieldTalk D_800A5888[];
extern u16 D_800A5B20[];
extern FieldTalk D_800A58B8[];
extern u16 D_800A5B2C[];
extern FieldTalk D_800A58DC[];
extern u16 D_800A5B38[];
extern FieldTalk D_800A5978[];
extern u16 D_800A5B40[];
extern FieldTalk D_800A5990[];
extern u16 D_800A5B4C[];
extern FieldTalk D_800A5A2C[];
extern u16 D_800A5B58[];
extern FieldTalk D_800A5A5C[];
extern u16 D_800A5B64[];
extern FieldTalk D_800A5A80[];
extern u16 D_800A5B6C[];
extern FieldTalk D_800A5A98[];
extern u16 D_800A5B74[];
extern FieldTalk D_800A5AB0[];
extern u16 D_800A5B7C[];
extern FieldTalk D_800A5AC8[];
extern FieldActorEntry D_800A5B84;
extern FieldActorEntry D_800A5B98;
extern FieldActorEntry D_800A5BAC;
extern FieldActorEntry D_800A5BC0;
extern FieldActorEntry D_800A5BD4;
extern FieldActorEntry D_800A5BE8;
extern FieldActorEntry D_800A5BFC;
extern FieldActorEntry D_800A5C10;
extern FieldActorEntry D_800A5C24;
extern FieldActorEntry D_800A5C38;
extern FieldActorEntry D_800A5C4C;
extern FieldActorEntry D_800A5C60;
extern FieldActorEntry D_800A5C74;
extern FieldActorEntry D_800A5C88;
extern FieldActorEntry D_800A5C9C;
extern FieldActorEntry D_800A5CB0;
extern FieldActorEntry D_800A5CC4;
extern FieldActorEntry D_800A5CD8;
extern FieldActorEntry D_800A5CEC;
extern s16 D_800A4E70[];

s16 D_800A4E70[] = {
    0x102, 2, 0xD7, 0x129, 3,
    0x100, 0x15, 0xB7, 0x119,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC17, 0, 0, 0,
    0,
};
Battle D_800A4EE4 = { 0, 0, 0x60040000 };
Battle D_800A4EF0 = { 0, 0, 0x60040000 };
Battle D_800A4EFC = { 0, 0, 0x60040000 };
Battle D_800A4F08 = { 0, 0, 0x60040000 };
Battle D_800A4F14 = { 0, 0, 0x60040000 };
Battle D_800A4F20 = { 0, 0, 0x60040000 };
Battle D_800A4F2C = { 0, 0, 0x60040000 };
Battle D_800A4F38 = { 0, 0, 0x60040000 };
BattleList D_800A4F44 = {
    3,
    { &D_800A4EE4, &D_800A4EF0, &D_800A4EFC, &D_800A4F08,
      &D_800A4F14, &D_800A4F20, &D_800A4F2C, &D_800A4F38 },
};
Battle D_800A4F68 = { 0, 0, 0x60040000 };
Battle D_800A4F74 = { 0, 0, 0x60040000 };
Battle D_800A4F80 = { 0, 0, 0x60040000 };
Battle D_800A4F8C = { 0, 0, 0x60040000 };
Battle D_800A4F98 = { 0, 0, 0x60040000 };
Battle D_800A4FA4 = { 0, 0, 0x60040000 };
Battle D_800A4FB0 = { 0, 0, 0x60040000 };
Battle D_800A4FBC = { 0, 0, 0x60040000 };
BattleList D_800A4FC8 = {
    0,
    { &D_800A4F68, &D_800A4F74, &D_800A4F80, &D_800A4F8C,
      &D_800A4F98, &D_800A4FA4, &D_800A4FB0, &D_800A4FBC },
};
Battle D_800A4FEC = { 0, 0, 0x60040000 };
Battle D_800A4FF8 = { 0, 0, 0x60040000 };
Battle D_800A5004 = { 0, 0, 0x60040000 };
Battle D_800A5010 = { 0, 0, 0x60040000 };
Battle D_800A501C = { 0, 0, 0x60040000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 0, 0, 0x60040000 };
BattleList D_800A504C = {
    0,
    { &D_800A4FEC, &D_800A4FF8, &D_800A5004, &D_800A5010,
      &D_800A501C, &D_800A5028, &D_800A5034, &D_800A5040 },
};
Battle D_800A5070 = { 240, 20, 0x600C0000 };
Battle D_800A507C = { 241, 20, 0x600C0000 };
Battle D_800A5088 = { 288, 18, 0x600C0000 };
Battle D_800A5094 = { 289, 18, 0x600C0000 };
Battle D_800A50A0 = { 242, 18, 0x60080000 };
Battle D_800A50AC = { 290, 18, 0x600C0000 };
Battle D_800A50B8 = { 0, 0, 0x60040000 };
Battle D_800A50C4 = { 0, 0, 0x60040000 };
BattleList D_800A50D0 = {
    0,
    { &D_800A5070, &D_800A507C, &D_800A5088, &D_800A5094,
      &D_800A50A0, &D_800A50AC, &D_800A50B8, &D_800A50C4 },
};
FieldBattles stageBattles[] = {
    { 161, 0, 0, { &D_800A4F44, &D_800A4FC8, &D_800A504C, &D_800A50D0 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x164, 0x1A7, 0x90, 0xA7, 0x160, 0x1FF },
    { 0x140, 0x100, 0x150, 0x178, 0x40, 0x78, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x1A5, 0xB0, 0xA5, 0x160, 0x1FE },
    { 0x140, 0x100, 0x140, 0x18B, 0, 0x8B, 0x170, 0x1FE },
    { 0x140, 0x100, 0x156, 0x1C8, 0x58, 0xC8, 0x160, 0x1FD },
    { 0x140, 0x100, 0x150, 0x1A8, 0x40, 0xA8, 0x170, 0x1FD },
    { 0x140, 0x100, 0x148, 0x18B, 0x20, 0x8B, 0x160, 0x1FC },
    { 0x140, 0x100, 0x176, 0x1A5, 0xD8, 0xA5, 0x170, 0x1FC },
    { 0x140, 0x100, 0x15C, 0x1A7, 0x70, 0xA7, 0x160, 0x1FB },
    { 0x140, 0x100, 0x148, 0x1B3, 0x20, 0xB3, 0x170, 0x1FB },
    { 0x140, 0x100, 0x140, 0x1BB, 0, 0xBB, 0x160, 0x1FA },
    { 0x140, 0x100, 0x16C, 0x1C5, 0xB0, 0xC5, 0x170, 0x1FA },
    { 0x140, 0x100, 0x164, 0x1C7, 0x90, 0xC7, 0x160, 0x1F9 },
};
u16 D_800A5240[] = { 0x7A2D, 1, 0xFFFF };
u16 D_800A5248[] = { 0x9068, 1, 0xFFFF };
u16 D_800A5250[] = { 0x7A19, 1, 0xFFFF };
u16 D_800A5258[] = { 0x11, 0, 0xFFFF };
u16 D_800A5260[] = { 0x10, 0, 0xFFFF };
u16 D_800A5268[] = { 0x11, 0, 0xFFFF };
u16 D_800A5270[] = { 0x10, 1, 0xFFFF };
u16 D_800A5278[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5284[] = { 0x11, 1, 0x10, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5294[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A52A0[] = { 0x11, 1, 0x10, 1, 0x6026, 1, 0xFFFF };
u16 D_800A52B0[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A52BC[] = { 0x11, 1, 0x10, 0, 0x7019, 1, 0xFFFF };
u16 D_800A52CC[] = { 0x11, 0, 0xFFFF };
u16 D_800A52D4[] = { 0x11, 1, 0x10, 0, 0x6026, 1, 0xFFFF };
u16 D_800A52E4[] = { 0x11, 0, 0xFFFF };
u16 D_800A52EC[] = { 2, 0, 0x11, 0, 0x7019, 1, 0xFFFF };
u16 D_800A52FC[] = { 2, 1, 0xFFFF };
u16 D_800A5304[] = { 0x11, 0, 2, 0, 0x6026, 1, 0xFFFF };
u16 D_800A5314[] = { 2, 1, 0xFFFF };
u16 D_800A531C[] = { 2, 1, 0x7207, 0, 0x11, 0, 0xFFFF };
u16 D_800A532C[] = { 2, 1, 0x7207, 1, 0x7209, 0, 0x11, 0, 0xFFFF };
u16 D_800A5340[] = { 0x763A, 1, 0xFFFF };
u16 D_800A5348[] = {
    2, 1, 0x7207, 1, 0xE2D, 0, 0x7209, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A5360[] = { 0xE2D, 1, 0x7404, 1, 0xFFFF };
u16 D_800A536C[] = {
    2, 1, 0x7207, 1, 0x8014, 0, 0x7209, 1,
    0xE2D, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5388[] = {
    2, 1, 0x7207, 1, 0x8014, 1, 0x7209, 1,
    0xE2D, 1, 0x720B, 0, 0x11, 0, 0xFFFF,
};
u16 D_800A53A8[] = {
    2, 1, 0x7207, 1, 0x8014, 1, 0x7209, 1,
    0xE2D, 1, 0x720B, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A53C8[] = { 0x783A, 1, 0xFFFF };
u16 D_800A53D0[] = { 0x7019, 1, 0xFFFF };
u16 D_800A53D8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A53E0[] = { 0x701D, 1, 0xFFFF };
u16 D_800A53E8[] = { 0x6025, 1, 0xFFFF };
u16 D_800A53F0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A53F8[] = { 0x11, 0, 0xFFFF };
u16 D_800A5400[] = { 0x10, 0, 0xFFFF };
u16 D_800A5408[] = { 0x11, 0, 0xFFFF };
u16 D_800A5410[] = { 0x10, 1, 0xFFFF };
u16 D_800A5418[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5424[] = { 0x7019, 1, 0xFFFF };
u16 D_800A542C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5434[] = { 0x11, 1, 0x10, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5444[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5450[] = { 0x11, 1, 0x10, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5460[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A546C[] = { 0x11, 1, 0x10, 0, 0x7019, 1, 0xFFFF };
u16 D_800A547C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5484[] = { 0x11, 1, 0x10, 0, 0x6026, 1, 0xFFFF };
u16 D_800A5494[] = { 0x11, 0, 0xFFFF };
u16 D_800A549C[] = { 0, 0, 0x11, 0, 0x7019, 1, 0xFFFF };
u16 D_800A54AC[] = { 0, 1, 0xFFFF };
u16 D_800A54B4[] = { 0x11, 0, 0, 0, 0x6026, 1, 0xFFFF };
u16 D_800A54C4[] = { 0, 1, 0xFFFF };
u16 D_800A54CC[] = { 0, 1, 0x7207, 0, 0x11, 0, 0xFFFF };
u16 D_800A54DC[] = { 0, 1, 0x7207, 1, 0x7209, 0, 0x11, 0, 0xFFFF };
u16 D_800A54F0[] = { 0x7638, 1, 0xFFFF };
u16 D_800A54F8[] = {
    0xE2B, 0, 0x7209, 1, 0, 1, 0x7207, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A5510[] = { 0xE2B, 1, 0x7400, 1, 0xFFFF };
u16 D_800A551C[] = {
    0x8014, 0, 0x7209, 1, 0xE2B, 1, 0, 1,
    0x7207, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5538[] = {
    0xE2B, 1, 0x8014, 1, 0x7209, 1, 0x720B, 0,
    0, 1, 0x7207, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5558[] = {
    0, 1, 0x7207, 1, 0x8014, 1, 0x7209, 1,
    0xE2B, 1, 0x720B, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5578[] = { 0x7838, 1, 0xFFFF };
u16 D_800A5580[] = { 0x11, 1, 0x10, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5590[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A559C[] = { 0x11, 1, 0x10, 1, 0x6026, 1, 0xFFFF };
u16 D_800A55AC[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A55B8[] = { 0x11, 1, 0x10, 0, 0x7019, 1, 0xFFFF };
u16 D_800A55C8[] = { 0x11, 0, 0xFFFF };
u16 D_800A55D0[] = { 0x11, 1, 0x10, 0, 0x6026, 1, 0xFFFF };
u16 D_800A55E0[] = { 0x11, 0, 0xFFFF };
u16 D_800A55E8[] = { 1, 0, 0x11, 0, 0x7019, 1, 0xFFFF };
u16 D_800A55F8[] = { 1, 1, 0xFFFF };
u16 D_800A5600[] = { 0x11, 0, 1, 0, 0x6026, 1, 0xFFFF };
u16 D_800A5610[] = { 1, 1, 0xFFFF };
u16 D_800A5618[] = { 1, 1, 0x7207, 0, 0x11, 0, 0xFFFF };
u16 D_800A5628[] = { 1, 1, 0x7207, 1, 0x7209, 0, 0x11, 0, 0xFFFF };
u16 D_800A563C[] = { 0x7639, 1, 0xFFFF };
u16 D_800A5644[] = {
    1, 1, 0x7207, 1, 0x7209, 1, 0xE2C, 0,
    0x11, 0, 0xFFFF,
};
u16 D_800A565C[] = { 0xE2C, 1, 0x7401, 1, 0xFFFF };
u16 D_800A5668[] = {
    1, 1, 0x7207, 1, 0x8014, 0, 0x7209, 1,
    0xE2C, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5684[] = {
    1, 1, 0x7207, 1, 0x8014, 1, 0x7209, 1,
    0xE2C, 1, 0x720B, 0, 0x11, 0, 0xFFFF,
};
u16 D_800A56A4[] = {
    1, 1, 0x7207, 1, 0x8014, 1, 0x7209, 1,
    0xE2C, 1, 0x720B, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A56C4[] = { 0x7839, 1, 0xFFFF };
u16 D_800A56CC[] = { 0x11, 0, 0xFFFF };
u16 D_800A56D4[] = { 0x10, 0, 0xFFFF };
u16 D_800A56DC[] = { 0x11, 0, 0xFFFF };
u16 D_800A56E4[] = { 0x10, 1, 0xFFFF };
u16 D_800A56EC[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A56F8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5700[] = { 0x6026, 1, 0xFFFF };
FieldTalk D_800A5708[] = {
    { NULL, D_800A5240, 0x2CE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5720[] = {
    { NULL, D_800A5248, 0x2CF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5738[] = {
    { NULL, D_800A5250, 0x2D0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5750[] = {
    { D_800A5258, NULL, 0x151 },
    { D_800A5260, D_800A5268, 0x14F },
    { D_800A5270, D_800A5278, 0x150 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5780[] = {
    { D_800A5284, D_800A5294, 0x150 },
    { D_800A52A0, D_800A52B0, 0x21 },
    { D_800A52BC, D_800A52CC, 0x14F },
    { D_800A52D4, D_800A52E4, 0x20 },
    { D_800A52EC, D_800A52FC, 0x148 },
    { D_800A5304, D_800A5314, 0x1F },
    { D_800A531C, NULL, 0x149 },
    { D_800A532C, D_800A5340, 0x14A },
    { D_800A5348, D_800A5360, 0x14C },
    { D_800A536C, NULL, 0x14B },
    { D_800A5388, NULL, 0x14D },
    { D_800A53A8, D_800A53C8, 0x14E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A581C[] = {
    { D_800A53D0, NULL, 0x151 },
    { D_800A53D8, NULL, 0x1F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5840[] = {
    { NULL, NULL, 0x147 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5858[] = {
    { D_800A53E0, NULL, 0x143 },
    { D_800A53E8, NULL, 0x144 },
    { D_800A53F0, NULL, 0x145 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5888[] = {
    { D_800A53F8, NULL, 0x134 },
    { D_800A5400, D_800A5408, 0x132 },
    { D_800A5410, D_800A5418, 0x133 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58B8[] = {
    { D_800A5424, NULL, 0x134 },
    { D_800A542C, NULL, 0x17 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58DC[] = {
    { D_800A5434, D_800A5444, 0x133 },
    { D_800A5450, D_800A5460, 0x19 },
    { D_800A546C, D_800A547C, 0x132 },
    { D_800A5484, D_800A5494, 0x18 },
    { D_800A549C, D_800A54AC, 0x12A },
    { D_800A54B4, D_800A54C4, 0x17 },
    { D_800A54CC, NULL, 0x12C },
    { D_800A54DC, D_800A54F0, 0x12D },
    { D_800A54F8, D_800A5510, 0x12F },
    { D_800A551C, NULL, 0x12E },
    { D_800A5538, NULL, 0x130 },
    { D_800A5558, D_800A5578, 0x131 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5978[] = {
    { NULL, NULL, 0x146 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5990[] = {
    { D_800A5580, D_800A5590, 0x13E },
    { D_800A559C, D_800A55AC, 0x1D },
    { D_800A55B8, D_800A55C8, 0x13D },
    { D_800A55D0, D_800A55E0, 0x1C },
    { D_800A55E8, D_800A55F8, 0x135 },
    { D_800A5600, D_800A5610, 0x1B },
    { D_800A5618, NULL, 0x137 },
    { D_800A5628, D_800A563C, 0x138 },
    { D_800A5644, D_800A565C, 0x139 },
    { D_800A5668, NULL, 0x13A },
    { D_800A5684, NULL, 0x13B },
    { D_800A56A4, D_800A56C4, 0x13C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A2C[] = {
    { D_800A56CC, NULL, 0x13F },
    { D_800A56D4, D_800A56DC, 0x13D },
    { D_800A56E4, D_800A56EC, 0x13E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A5C[] = {
    { D_800A56F8, NULL, 0x135 },
    { D_800A5700, NULL, 0x1B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A80[] = {
    { NULL, NULL, 0x141 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A98[] = {
    { NULL, NULL, 0x140 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AB0[] = {
    { NULL, NULL, 0x142 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AC8[] = {
    { NULL, NULL, 0x2DC },
    { NULL, NULL, 0 },
};
u16 D_800A5AE0[] = { 0x8192, 1, 0x602B, 1, 0xFFFF };
u16 D_800A5AEC[] = { 0x8192, 1, 0x701E, 1, 0xFFFF };
u16 D_800A5AF8[] = { 0x8192, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5B04[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5B0C[] = { 0x701E, 1, 0xFFFF };
u16 D_800A5B14[] = { 0x8192, 1, 0x602B, 1, 0xFFFF };
u16 D_800A5B20[] = { 0x8192, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5B2C[] = { 0x8192, 1, 0x701E, 1, 0xFFFF };
u16 D_800A5B38[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5B40[] = { 0x8192, 1, 0x701E, 1, 0xFFFF };
u16 D_800A5B4C[] = { 0x8192, 1, 0x602B, 1, 0xFFFF };
u16 D_800A5B58[] = { 0x8192, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5B64[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5B6C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5B74[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5B7C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5B84 = { NULL, D_800A5708, 0x14, 4, 321, 593, 1 };
FieldActorEntry D_800A5B98 = { NULL, D_800A5720, 0x15, 5, 183, 281, 7 };
FieldActorEntry D_800A5BAC = { NULL, D_800A5738, 0x17, 6, 528, 305, 7 };
FieldActorEntry D_800A5BC0 = { D_800A5AE0, D_800A5750, 0x25, 7, 239, 177, 1 };
FieldActorEntry D_800A5BD4 = { D_800A5AEC, D_800A5780, 0x25, 7, 239, 177, 1 };
FieldActorEntry D_800A5BE8 = { D_800A5AF8, D_800A581C, 0x25, 7, 239, 177, 1 };
FieldActorEntry D_800A5BFC = { D_800A5B04, D_800A5840, 0x2D, 8, 537, 493, 7 };
FieldActorEntry D_800A5C10 = { D_800A5B0C, D_800A5858, 0x2E, 9, 537, 493, 7 };
FieldActorEntry D_800A5C24 = { D_800A5B14, D_800A5888, 0x2F, 0xA, 352, 440, 1 };
FieldActorEntry D_800A5C38 = { D_800A5B20, D_800A58B8, 0x2F, 0xA, 352, 440, 1 };
FieldActorEntry D_800A5C4C = { D_800A5B2C, D_800A58DC, 0x2F, 0xA, 352, 440, 1 };
FieldActorEntry D_800A5C60 = { D_800A5B38, D_800A5978, 0x33, 0xB, 209, 304, 7 };
FieldActorEntry D_800A5C74 = { D_800A5B40, D_800A5990, 0x37, 0xC, 401, 528, 7 };
FieldActorEntry D_800A5C88 = { D_800A5B4C, D_800A5A2C, 0x37, 0xC, 401, 528, 7 };
FieldActorEntry D_800A5C9C = { D_800A5B58, D_800A5A5C, 0x37, 0xC, 401, 528, 7 };
FieldActorEntry D_800A5CB0 = { D_800A5B64, D_800A5A80, 0x9D, 0xD, 401, 528, 7 };
FieldActorEntry D_800A5CC4 = { D_800A5B6C, D_800A5A98, 0x9E, 0xE, 352, 440, 1 };
FieldActorEntry D_800A5CD8 = { D_800A5B74, D_800A5AB0, 0x9F, 0xF, 537, 493, 7 };
FieldActorEntry D_800A5CEC = { D_800A5B7C, D_800A5AC8, 0xA0, 0x10, 239, 177, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5B84,
    &D_800A5B98,
    &D_800A5BAC,
    &D_800A5BC0,
    &D_800A5BD4,
    &D_800A5BE8,
    &D_800A5BFC,
    &D_800A5C10,
    &D_800A5C24,
    &D_800A5C38,
    &D_800A5C4C,
    &D_800A5C60,
    &D_800A5C74,
    &D_800A5C88,
    &D_800A5C9C,
    &D_800A5CB0,
    &D_800A5CC4,
    &D_800A5CD8,
    &D_800A5CEC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 0xE, 0, 252, 269, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 0xE, 0, 482, 625, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 7, 0xE, 0, 195, 353, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 7, 0xE, 0, 339, 386, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 7, 0xE, 0, 539, 364, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 7, 0xE, 0, 366, 485, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 7, 0xE, 0, 475, 430, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 0xB, 0xA, 0, 164, 326, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 0xB, 0xA, 0, 164, 354, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 0xB, 0xA, 0, 508, 337, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 0xB, 0xA, 0, 512, 364, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 2, 0, 0xB, 0xA, 0, 568, 388, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 0xB, 0xA, 0, 481, 426, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 0xB, 0xA, 0, 453, 432, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 0xB, 0xA, 0, 346, 480, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 0xB, 0xA, 0, 342, 488, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 311, 96, 151, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 318, 579, 600, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 335, 572, 595, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C5, 0xA8, 0x1B4, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C3, 0x298, 0x104, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0xFD, 0xD0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xEC, 0x118, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x133, 0xC8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x142, 0x150, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x192, 0x148, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x1A2, 0x190, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x1C2, 0x1A0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x1D2, 0x1E8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x25C, 0x160, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x24C, 0x1A8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x1AC, 0x228, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x19C, 0x270, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 9, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1462, D_800A4E70, EVENT_TEXT(0x1F), NULL, func_800A4D48 },
    { -1, NULL, 0, NULL, NULL },
};
