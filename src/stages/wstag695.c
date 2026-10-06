#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x75F
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x76E
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x33200, 0xD500};
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
extern u16 D_800A5118[];
extern u16 D_800A5128[];
extern u16 D_800A5130[];
extern u16 D_800A5138[];
extern u16 D_800A5144[];
extern u16 D_800A5154[];
extern u16 D_800A515C[];
extern u16 D_800A5170[];
extern u16 D_800A5188[];
extern u16 D_800A5194[];
extern u16 D_800A51B0[];
extern u16 D_800A51CC[];
extern u16 D_800A51D4[];
extern u16 D_800A51DC[];
extern u16 D_800A51E8[];
extern u16 D_800A51F0[];
extern u16 D_800A51FC[];
extern u16 D_800A5208[];
extern u16 D_800A5210[];
extern u16 D_800A5218[];
extern u16 D_800A5224[];
extern u16 D_800A5234[];
extern u16 D_800A523C[];
extern u16 D_800A5250[];
extern u16 D_800A5268[];
extern u16 D_800A5274[];
extern u16 D_800A5290[];
extern u16 D_800A52AC[];
extern u16 D_800A52B4[];
extern u16 D_800A52C4[];
extern u16 D_800A52CC[];
extern u16 D_800A52D8[];
extern u16 D_800A52E8[];
extern u16 D_800A52F0[];
extern u16 D_800A5304[];
extern u16 D_800A531C[];
extern u16 D_800A5324[];
extern u16 D_800A5340[];
extern u16 D_800A535C[];
extern u16 D_800A54FC[];
extern FieldTalk D_800A5364[];
extern u16 D_800A5504[];
extern FieldTalk D_800A537C[];
extern u16 D_800A5514[];
extern FieldTalk D_800A53DC[];
extern u16 D_800A5524[];
extern FieldTalk D_800A540C[];
extern u16 D_800A5534[];
extern FieldTalk D_800A546C[];
extern u16 D_800A5544[];
extern FieldTalk D_800A5484[];
extern u16 D_800A554C[];
extern FieldTalk D_800A549C[];
extern FieldActorEntry D_800A5554;
extern FieldActorEntry D_800A5568;
extern FieldActorEntry D_800A557C;
extern FieldActorEntry D_800A5590;
extern FieldActorEntry D_800A55A4;
extern FieldActorEntry D_800A55B8;
extern FieldActorEntry D_800A55CC;

Battle D_800A4E4C = { 113, 14, 0x60080000 };
Battle D_800A4E58 = { 113, 14, 0x60080000 };
Battle D_800A4E64 = { 113, 14, 0x60080000 };
Battle D_800A4E70 = { 113, 14, 0x60080000 };
Battle D_800A4E7C = { 114, 14, 0x60080000 };
Battle D_800A4E88 = { 114, 14, 0x60080000 };
Battle D_800A4E94 = { 114, 14, 0x60080000 };
Battle D_800A4EA0 = { 114, 14, 0x60080000 };
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
Battle D_800A4FD8 = { 218, 14, 0x600C0000 };
Battle D_800A4FE4 = { 0, 0, 0x60040000 };
Battle D_800A4FF0 = { 0, 0, 0x60040000 };
Battle D_800A4FFC = { 333, 14, 0x60080000 };
Battle D_800A5008 = { 0, 0, 0x60040000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 114, 14, 0x60080000 };
Battle D_800A502C = { 0, 0, 0x60040000 };
BattleList D_800A5038 = {
    0,
    { &D_800A4FD8, &D_800A4FE4, &D_800A4FF0, &D_800A4FFC,
      &D_800A5008, &D_800A5014, &D_800A5020, &D_800A502C },
};
FieldBattles stageBattles[] = {
    { 82, 0, 0, { &D_800A4EAC, &D_800A4F30, &D_800A4FB4, &D_800A5038 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x156, 0x1C8, 0x58, 0xC8, 0x170, 0x1FD },
    { 0x140, 0x100, 0x176, 0x188, 0xD8, 0x88, 0x170, 0x1FC },
    { 0x140, 0x100, 0x176, 0x1D0, 0xD8, 0xD0, 0x160, 0x1FB },
    { 0x140, 0x100, 0x176, 0x1B0, 0xD8, 0xB0, 0x170, 0x1FB },
};
u16 D_800A5118[] = { 0x7090, 1, 0x222, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5128[] = { 0, 0, 0xFFFF };
u16 D_800A5130[] = { 0, 1, 0xFFFF };
u16 D_800A5138[] = { 0x7206, 0, 0, 1, 0xFFFF };
u16 D_800A5144[] = { 0, 1, 0x8014, 0, 0x7206, 1, 0xFFFF };
u16 D_800A5154[] = { 0x761C, 1, 0xFFFF };
u16 D_800A515C[] = { 0x7206, 1, 0, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5170[] = {
    0, 1, 0x8014, 1, 0x7208, 1, 0x7206, 1,
    0xE12, 0, 0xFFFF,
};
u16 D_800A5188[] = { 0x7400, 1, 0xE12, 1, 0xFFFF };
u16 D_800A5194[] = {
    0x7206, 1, 0xE12, 1, 0x720A, 0, 0, 1,
    0x8014, 1, 0x7208, 1, 0xFFFF,
};
u16 D_800A51B0[] = {
    0, 1, 0x8014, 1, 0x7208, 1, 0x7206, 1,
    0xE12, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A51CC[] = { 0x781C, 1, 0xFFFF };
u16 D_800A51D4[] = { 0x11, 0, 0xFFFF };
u16 D_800A51DC[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A51E8[] = { 0x11, 0, 0xFFFF };
u16 D_800A51F0[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A51FC[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5208[] = { 0, 0, 0xFFFF };
u16 D_800A5210[] = { 0, 1, 0xFFFF };
u16 D_800A5218[] = { 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A5224[] = { 0x8014, 0, 0, 1, 0x7206, 1, 0xFFFF };
u16 D_800A5234[] = { 0x761C, 1, 0xFFFF };
u16 D_800A523C[] = { 0x7206, 1, 0, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5250[] = {
    0x8014, 1, 0x7208, 1, 0, 1, 0x7206, 1,
    0xE12, 0, 0xFFFF,
};
u16 D_800A5268[] = { 0xE12, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5274[] = {
    0x7206, 1, 0xE12, 1, 0x720A, 0, 0, 1,
    0x8014, 1, 0x7208, 1, 0xFFFF,
};
u16 D_800A5290[] = {
    0x8014, 1, 0x7208, 1, 0, 1, 0x7206, 1,
    0xE12, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A52AC[] = { 0x781C, 1, 0xFFFF };
u16 D_800A52B4[] = { 0x223, 1, 0x88A0, 1, 0x7013, 1, 0xFFFF };
u16 D_800A52C4[] = { 0, 0, 0xFFFF };
u16 D_800A52CC[] = { 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A52D8[] = { 0, 1, 0x7206, 1, 0x8014, 0, 0xFFFF };
u16 D_800A52E8[] = { 0x761C, 1, 0xFFFF };
u16 D_800A52F0[] = { 0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5304[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE12, 0, 0xFFFF,
};
u16 D_800A531C[] = { 0xE12, 1, 0xFFFF };
u16 D_800A5324[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE12, 1, 0x720A, 0, 0xFFFF,
};
u16 D_800A5340[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE12, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A535C[] = { 0x781C, 1, 0xFFFF };
FieldTalk D_800A5364[] = {
    { NULL, D_800A5118, 0x32E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A537C[] = {
    { D_800A5128, D_800A5130, 0xD },
    { D_800A5138, NULL, 0x11 },
    { D_800A5144, D_800A5154, 0x12 },
    { D_800A515C, NULL, 0x13 },
    { D_800A5170, D_800A5188, 0x14 },
    { D_800A5194, NULL, 0x15 },
    { D_800A51B0, D_800A51CC, 0x16 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53DC[] = {
    { D_800A51D4, NULL, 0xD },
    { D_800A51DC, D_800A51E8, 0x17 },
    { D_800A51F0, D_800A51FC, 0x18 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A540C[] = {
    { D_800A5208, D_800A5210, 0xE },
    { D_800A5218, NULL, 0x11 },
    { D_800A5224, D_800A5234, 0x12 },
    { D_800A523C, NULL, 0x13 },
    { D_800A5250, D_800A5268, 0x14 },
    { D_800A5274, NULL, 0x15 },
    { D_800A5290, D_800A52AC, 0x16 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A546C[] = {
    { NULL, NULL, 0x295 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5484[] = {
    { NULL, D_800A52B4, 0x268 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A549C[] = {
    { D_800A52C4, NULL, 0xF },
    { D_800A52CC, NULL, 0xF },
    { D_800A52D8, D_800A52E8, 0xF },
    { D_800A52F0, NULL, 0xF },
    { D_800A5304, D_800A531C, 0xF },
    { D_800A5324, NULL, 0xF },
    { D_800A5340, D_800A535C, 0xF },
    { NULL, NULL, 0 },
};
u16 D_800A54FC[] = { 0x222, 0, 0xFFFF };
u16 D_800A5504[] = { 0x11, 0, 0x7004, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5514[] = { 0x11, 1, 0x8192, 1, 0x7009, 1, 0xFFFF };
u16 D_800A5524[] = { 0x6026, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5534[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5544[] = { 0x223, 0, 0xFFFF };
u16 D_800A554C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5554 = { D_800A54FC, D_800A5364, 0x21, 4, 384, 453, 1 };
FieldActorEntry D_800A5568 = { D_800A5504, D_800A537C, 0x34, 5, 657, 408, 1 };
FieldActorEntry D_800A557C = { D_800A5514, D_800A53DC, 0x34, 5, 657, 408, 1 };
FieldActorEntry D_800A5590 = { D_800A5524, D_800A540C, 0x34, 5, 657, 408, 1 };
FieldActorEntry D_800A55A4 = { D_800A5534, D_800A546C, 0x34, 5, 657, 408, 1 };
FieldActorEntry D_800A55B8 = { D_800A5544, D_800A5484, 0x4D, 6, 961, 241, 1 };
FieldActorEntry D_800A55CC = { D_800A554C, D_800A549C, 0x9D, 7, 657, 408, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5554,
    &D_800A5568,
    &D_800A557C,
    &D_800A5590,
    &D_800A55A4,
    &D_800A55B8,
    &D_800A55CC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 5, 6, 0, 472, 329, 0, 0 },
    { 1, 0, 0xC8, 2, 0x34, 1, 0x34, 0x37, 8, 0, 542, 52, 0, 0 },
    { 1, 0, 0x40, 2, 0x3B, 2, 0, 3, 8, 0, 412, 670, 0, 0 },
    { 1, 0, 0x40, 2, 2, 1, 2, 7, 4, 0, 93, 305, 0, 0 },
    { 1, 0, 0x40, 2, 2, 1, 2, 7, 4, 0, 585, 772, 0, 0 },
    { 1, 0, 0x40, 2, 2, 1, 2, 7, 4, 0, 1033, 514, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xD, 6, 0, 579, 336, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 3, 8, 0, 557, 494, 0, 0 },
    { 1, 0, 0x50, 6, 0x39, 2, 0, 3, 8, 0, 549, 528, 0, 0 },
    { 1, 0, 0x50, 6, 0x3A, 2, 0, 3, 8, 0, 493, 598, 0, 0 },
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x261, 0x500, 0x290, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x261, 0x500, 0x300, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x264, 0x238, 0x444, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x263, 0x108, 0x12C, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x1CE, 0xAA, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x1BF, 0x112, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x3B0, 0x16A, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x3BF, 0x1D0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x380, 0x253, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x38F, 0x2EA, 0, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x13, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 7, 2 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
