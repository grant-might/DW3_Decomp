#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x631
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x641
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x4BE00, 0x2DA00};
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
extern u16 D_800A511C[];
extern u16 D_800A512C[];
extern u16 D_800A5134[];
extern u16 D_800A513C[];
extern u16 D_800A5148[];
extern u16 D_800A5158[];
extern u16 D_800A5160[];
extern u16 D_800A5174[];
extern u16 D_800A518C[];
extern u16 D_800A5198[];
extern u16 D_800A51B4[];
extern u16 D_800A51D0[];
extern u16 D_800A51D8[];
extern u16 D_800A51E0[];
extern u16 D_800A51E8[];
extern u16 D_800A51F4[];
extern u16 D_800A5204[];
extern u16 D_800A520C[];
extern u16 D_800A5220[];
extern u16 D_800A5238[];
extern u16 D_800A5244[];
extern u16 D_800A5260[];
extern u16 D_800A527C[];
extern u16 D_800A5284[];
extern u16 D_800A528C[];
extern u16 D_800A5298[];
extern u16 D_800A52A0[];
extern u16 D_800A52AC[];
extern u16 D_800A52B8[];
extern u16 D_800A52C8[];
extern u16 D_800A52D0[];
extern u16 D_800A52DC[];
extern u16 D_800A52EC[];
extern u16 D_800A52F4[];
extern u16 D_800A5308[];
extern u16 D_800A5320[];
extern u16 D_800A5328[];
extern u16 D_800A5344[];
extern u16 D_800A5360[];
extern u16 D_800A5500[];
extern FieldTalk D_800A5368[];
extern u16 D_800A5508[];
extern FieldTalk D_800A5380[];
extern u16 D_800A5518[];
extern FieldTalk D_800A53E0[];
extern u16 D_800A5528[];
extern FieldTalk D_800A53F8[];
extern u16 D_800A5538[];
extern FieldTalk D_800A5458[];
extern u16 D_800A5548[];
extern FieldTalk D_800A5488[];
extern u16 D_800A5550[];
extern FieldTalk D_800A54A0[];
extern FieldActorEntry D_800A5558;
extern FieldActorEntry D_800A556C;
extern FieldActorEntry D_800A5580;
extern FieldActorEntry D_800A5594;
extern FieldActorEntry D_800A55A8;
extern FieldActorEntry D_800A55BC;
extern FieldActorEntry D_800A55D0;

Battle D_800A4E50 = { 153, 4, 0x60080000 };
Battle D_800A4E5C = { 153, 4, 0x60080000 };
Battle D_800A4E68 = { 153, 4, 0x60080000 };
Battle D_800A4E74 = { 111, 4, 0x60080000 };
Battle D_800A4E80 = { 111, 4, 0x60080000 };
Battle D_800A4E8C = { 111, 4, 0x60080000 };
Battle D_800A4E98 = { 112, 4, 0x60080000 };
Battle D_800A4EA4 = { 112, 4, 0x60080000 };
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
Battle D_800A4FDC = { 217, 4, 0x600C0000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 333, 4, 0x60080000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 168, 4, 0x60080000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
FieldBattles stageBattles[] = {
    { 81, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x148, 0xD8, 0x48, 0x160, 0x1FE },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x170, 0x1FE },
    { 0x140, 0x100, 0x176, 0x168, 0xD8, 0x68, 0x160, 0x1FD },
    { 0x140, 0x100, 0x176, 0x128, 0xD8, 0x28, 0x170, 0x1FD },
};
u16 D_800A511C[] = { 0x220, 1, 0x846D, 1, 0x7013, 1, 0xFFFF };
u16 D_800A512C[] = { 0, 0, 0xFFFF };
u16 D_800A5134[] = { 0, 1, 0xFFFF };
u16 D_800A513C[] = { 0x7206, 0, 0, 1, 0xFFFF };
u16 D_800A5148[] = { 0x7206, 1, 0x8014, 0, 0, 1, 0xFFFF };
u16 D_800A5158[] = { 0x761B, 1, 0xFFFF };
u16 D_800A5160[] = { 0x7206, 1, 0x8014, 1, 0x7208, 0, 0, 1, 0xFFFF };
u16 D_800A5174[] = {
    0x7206, 1, 0x8014, 1, 0x7208, 1, 0xE11, 0,
    0, 1, 0xFFFF,
};
u16 D_800A518C[] = { 0x7400, 1, 0xE11, 1, 0xFFFF };
u16 D_800A5198[] = {
    0xE11, 1, 0x720A, 0, 0x7206, 1, 0x8014, 1,
    0x7208, 1, 0, 1, 0xFFFF,
};
u16 D_800A51B4[] = {
    0x7206, 1, 0x8014, 1, 0x7208, 1, 0xE11, 1,
    0x720A, 1, 0, 1, 0xFFFF,
};
u16 D_800A51D0[] = { 0x781B, 1, 0xFFFF };
u16 D_800A51D8[] = { 0, 0, 0xFFFF };
u16 D_800A51E0[] = { 0, 1, 0xFFFF };
u16 D_800A51E8[] = { 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A51F4[] = { 0x7206, 1, 0, 1, 0x8014, 0, 0xFFFF };
u16 D_800A5204[] = { 0x761B, 1, 0xFFFF };
u16 D_800A520C[] = { 0, 1, 0x7208, 0, 0x8014, 1, 0x7206, 1, 0xFFFF };
u16 D_800A5220[] = {
    0x7206, 1, 0xE11, 0, 0, 1, 0x8014, 1,
    0x7208, 1, 0xFFFF,
};
u16 D_800A5238[] = { 0x7400, 1, 0xE11, 1, 0xFFFF };
u16 D_800A5244[] = {
    0, 1, 0x8014, 1, 0x7208, 1, 0x7206, 1,
    0xE11, 1, 0x720A, 0, 0xFFFF,
};
u16 D_800A5260[] = {
    0x7206, 1, 0xE11, 1, 0x720A, 1, 0, 1,
    0x8014, 1, 0x7208, 1, 0xFFFF,
};
u16 D_800A527C[] = { 0x781B, 1, 0xFFFF };
u16 D_800A5284[] = { 0x11, 0, 0xFFFF };
u16 D_800A528C[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5298[] = { 0x11, 0, 0xFFFF };
u16 D_800A52A0[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A52AC[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A52B8[] = { 0x221, 1, 0x822B, 1, 0x7013, 1, 0xFFFF };
u16 D_800A52C8[] = { 0, 0, 0xFFFF };
u16 D_800A52D0[] = { 0, 1, 0x7206, 0, 0xFFFF };
u16 D_800A52DC[] = { 0, 1, 0x7206, 1, 0x8014, 0, 0xFFFF };
u16 D_800A52EC[] = { 0x761B, 1, 0xFFFF };
u16 D_800A52F4[] = { 0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 0, 0xFFFF };
u16 D_800A5308[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE11, 0, 0xFFFF,
};
u16 D_800A5320[] = { 0xE11, 1, 0xFFFF };
u16 D_800A5328[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE11, 1, 0x720A, 0, 0xFFFF,
};
u16 D_800A5344[] = {
    0, 1, 0x7206, 1, 0x8014, 1, 0x7208, 1,
    0xE11, 1, 0x720A, 1, 0xFFFF,
};
u16 D_800A5360[] = { 0x781B, 1, 0xFFFF };
FieldTalk D_800A5368[] = {
    { NULL, D_800A511C, 0x265 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5380[] = {
    { D_800A512C, D_800A5134, 1 },
    { D_800A513C, NULL, 5 },
    { D_800A5148, D_800A5158, 6 },
    { D_800A5160, NULL, 7 },
    { D_800A5174, D_800A518C, 8 },
    { D_800A5198, NULL, 9 },
    { D_800A51B4, D_800A51D0, 0xA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53E0[] = {
    { NULL, NULL, 0x294 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53F8[] = {
    { D_800A51D8, D_800A51E0, 2 },
    { D_800A51E8, NULL, 5 },
    { D_800A51F4, D_800A5204, 6 },
    { D_800A520C, NULL, 7 },
    { D_800A5220, D_800A5238, 8 },
    { D_800A5244, NULL, 9 },
    { D_800A5260, D_800A527C, 0xA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5458[] = {
    { D_800A5284, NULL, 1 },
    { D_800A528C, D_800A5298, 0xB },
    { D_800A52A0, D_800A52AC, 0xC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5488[] = {
    { NULL, D_800A52B8, 0x16D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54A0[] = {
    { D_800A52C8, NULL, 3 },
    { D_800A52D0, NULL, 3 },
    { D_800A52DC, D_800A52EC, 3 },
    { D_800A52F4, NULL, 3 },
    { D_800A5308, D_800A5320, 3 },
    { D_800A5328, NULL, 3 },
    { D_800A5344, D_800A5360, 3 },
    { NULL, NULL, 0 },
};
u16 D_800A5500[] = { 0x220, 0, 0xFFFF };
u16 D_800A5508[] = { 0x8192, 1, 0x11, 0, 0x7004, 1, 0xFFFF };
u16 D_800A5518[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5528[] = { 0x8192, 1, 0x11, 0, 0x6026, 1, 0xFFFF };
u16 D_800A5538[] = { 0x8192, 1, 0x11, 1, 0x7009, 1, 0xFFFF };
u16 D_800A5548[] = { 0x221, 0, 0xFFFF };
u16 D_800A5550[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5558 = { D_800A5500, D_800A5368, 0x21, 4, 1281, 353, 1 };
FieldActorEntry D_800A556C = { D_800A5508, D_800A5380, 0x32, 5, 617, 589, 7 };
FieldActorEntry D_800A5580 = { D_800A5518, D_800A53E0, 0x32, 5, 617, 589, 7 };
FieldActorEntry D_800A5594 = { D_800A5528, D_800A53F8, 0x32, 5, 617, 589, 7 };
FieldActorEntry D_800A55A8 = { D_800A5538, D_800A5458, 0x32, 5, 617, 589, 7 };
FieldActorEntry D_800A55BC = { D_800A5548, D_800A5488, 0x4D, 6, 241, 409, 1 };
FieldActorEntry D_800A55D0 = { D_800A5550, D_800A54A0, 0x9D, 7, 617, 589, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5558,
    &D_800A556C,
    &D_800A5580,
    &D_800A5594,
    &D_800A55A8,
    &D_800A55BC,
    &D_800A55D0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 323, 826, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 690, 795, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 4, 0, 455, 285, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 4, 0, 749, 532, 0, 0 },
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x265, 0x4F0, 0x2B8, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x262, 0xA0, 0x1D0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x262, 0xA0, 0x240, 7, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x16, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 2, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 5, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0xC, 1 },
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
