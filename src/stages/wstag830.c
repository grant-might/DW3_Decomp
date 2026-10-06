#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x6F1
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x701
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xDB00, 0x12300};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1D;
    D_800990B4.music = 0x60740000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A4FB4;
extern StagePoint D_800A4FC4;
extern StagePoint D_800A4FD4;
extern StagePoint D_800A4FEC;
extern StagePoint D_800A4FFC;
extern StagePoint D_800A500C;
extern StagePoints D_800A4FE4;
extern StagePoints D_800A501C;
extern StagePoints D_800A5024;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A5078;
extern Battle D_800A5084;
extern Battle D_800A5090;
extern Battle D_800A50C0;
extern Battle D_800A50CC;
extern Battle D_800A50D8;
extern Battle D_800A50E4;
extern Battle D_800A50F0;
extern Battle D_800A50FC;
extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5144;
extern Battle D_800A5150;
extern Battle D_800A515C;
extern Battle D_800A5168;
extern Battle D_800A5174;
extern Battle D_800A5180;
extern Battle D_800A518C;
extern Battle D_800A5198;
extern Battle D_800A51C8;
extern Battle D_800A51D4;
extern Battle D_800A51E0;
extern Battle D_800A51EC;
extern Battle D_800A51F8;
extern Battle D_800A5204;
extern Battle D_800A5210;
extern Battle D_800A521C;
extern Battle D_800A524C;
extern Battle D_800A5258;
extern Battle D_800A5264;
extern Battle D_800A5270;
extern Battle D_800A527C;
extern Battle D_800A5288;
extern Battle D_800A5294;
extern Battle D_800A52A0;
extern Battle D_800A52D0;
extern Battle D_800A52DC;
extern Battle D_800A52E8;
extern Battle D_800A52F4;
extern Battle D_800A5300;
extern Battle D_800A530C;
extern Battle D_800A5318;
extern Battle D_800A5324;
extern Battle D_800A5354;
extern Battle D_800A5360;
extern Battle D_800A536C;
extern Battle D_800A5378;
extern Battle D_800A5384;
extern Battle D_800A5390;
extern Battle D_800A539C;
extern Battle D_800A53A8;
extern Battle D_800A53D8;
extern Battle D_800A53E4;
extern Battle D_800A53F0;
extern Battle D_800A53FC;
extern Battle D_800A5408;
extern Battle D_800A5414;
extern Battle D_800A5420;
extern Battle D_800A542C;
extern BattleList D_800A509C;
extern BattleList D_800A5120;
extern BattleList D_800A51A4;
extern BattleList D_800A5228;
extern BattleList D_800A52AC;
extern BattleList D_800A5330;
extern BattleList D_800A53B4;
extern BattleList D_800A5438;
extern FieldActorEntry D_800A5504;

StagePoint D_800A4FB4 = { 0x2E0, 2, 1, 176, 0x178, 5, NULL };
StagePoint D_800A4FC4 = { 0x202, 0, 0, 0x420, 0x1F0, 0, &D_800A4FB4 };
StagePoint D_800A4FD4 = { 0x202, 0, 0, 0x150, 0x148, 0, &D_800A4FC4 };
StagePoints D_800A4FE4 = { 2, 1, &D_800A4FD4 };
StagePoint D_800A4FEC = { 0x2E0, 12, 1, 176, 0x178, 5, NULL };
StagePoint D_800A4FFC = { 0x272, 0, 0, 0x420, 0x1F0, 0, &D_800A4FEC };
StagePoint D_800A500C = { 0x272, 0, 0, 0x150, 0x148, 0, &D_800A4FFC };
StagePoints D_800A501C = { 12, 1, &D_800A500C };
StagePoints D_800A5024 = { 0, 0, &D_800A4FD4 };
StagePoints *placePoints[] = {
    &D_800A4FE4, &D_800A501C, &D_800A5024, NULL,
};
Battle D_800A503C = { 62, 11, 0x60080000 };
Battle D_800A5048 = { 62, 11, 0x60080000 };
Battle D_800A5054 = { 62, 11, 0x60080000 };
Battle D_800A5060 = { 62, 11, 0x60080000 };
Battle D_800A506C = { 62, 11, 0x60080000 };
Battle D_800A5078 = { 62, 11, 0x60080000 };
Battle D_800A5084 = { 62, 11, 0x60080000 };
Battle D_800A5090 = { 62, 11, 0x60080000 };
BattleList D_800A509C = {
    4,
    { &D_800A503C, &D_800A5048, &D_800A5054, &D_800A5060,
      &D_800A506C, &D_800A5078, &D_800A5084, &D_800A5090 },
};
Battle D_800A50C0 = { 0, 0, 0x60040000 };
Battle D_800A50CC = { 0, 0, 0x60040000 };
Battle D_800A50D8 = { 0, 0, 0x60040000 };
Battle D_800A50E4 = { 0, 0, 0x60040000 };
Battle D_800A50F0 = { 0, 0, 0x60040000 };
Battle D_800A50FC = { 0, 0, 0x60040000 };
Battle D_800A5108 = { 0, 0, 0x60040000 };
Battle D_800A5114 = { 0, 0, 0x60040000 };
BattleList D_800A5120 = {
    0,
    { &D_800A50C0, &D_800A50CC, &D_800A50D8, &D_800A50E4,
      &D_800A50F0, &D_800A50FC, &D_800A5108, &D_800A5114 },
};
Battle D_800A5144 = { 0, 0, 0x60040000 };
Battle D_800A5150 = { 0, 0, 0x60040000 };
Battle D_800A515C = { 0, 0, 0x60040000 };
Battle D_800A5168 = { 0, 0, 0x60040000 };
Battle D_800A5174 = { 0, 0, 0x60040000 };
Battle D_800A5180 = { 0, 0, 0x60040000 };
Battle D_800A518C = { 0, 0, 0x60040000 };
Battle D_800A5198 = { 0, 0, 0x60040000 };
BattleList D_800A51A4 = {
    0,
    { &D_800A5144, &D_800A5150, &D_800A515C, &D_800A5168,
      &D_800A5174, &D_800A5180, &D_800A518C, &D_800A5198 },
};
Battle D_800A51C8 = { 0, 0, 0x60040000 };
Battle D_800A51D4 = { 0, 0, 0x60040000 };
Battle D_800A51E0 = { 0, 0, 0x60040000 };
Battle D_800A51EC = { 0, 0, 0x60040000 };
Battle D_800A51F8 = { 0, 0, 0x60040000 };
Battle D_800A5204 = { 0, 0, 0x60040000 };
Battle D_800A5210 = { 0, 0, 0x60040000 };
Battle D_800A521C = { 0, 0, 0x60040000 };
BattleList D_800A5228 = {
    0,
    { &D_800A51C8, &D_800A51D4, &D_800A51E0, &D_800A51EC,
      &D_800A51F8, &D_800A5204, &D_800A5210, &D_800A521C },
};
Battle D_800A524C = { 178, 11, 0x60080000 };
Battle D_800A5258 = { 178, 11, 0x60080000 };
Battle D_800A5264 = { 178, 11, 0x60080000 };
Battle D_800A5270 = { 178, 11, 0x60080000 };
Battle D_800A527C = { 178, 11, 0x60080000 };
Battle D_800A5288 = { 178, 11, 0x60080000 };
Battle D_800A5294 = { 178, 11, 0x60080000 };
Battle D_800A52A0 = { 178, 11, 0x60080000 };
BattleList D_800A52AC = {
    4,
    { &D_800A524C, &D_800A5258, &D_800A5264, &D_800A5270,
      &D_800A527C, &D_800A5288, &D_800A5294, &D_800A52A0 },
};
Battle D_800A52D0 = { 0, 0, 0x60040000 };
Battle D_800A52DC = { 0, 0, 0x60040000 };
Battle D_800A52E8 = { 0, 0, 0x60040000 };
Battle D_800A52F4 = { 0, 0, 0x60040000 };
Battle D_800A5300 = { 0, 0, 0x60040000 };
Battle D_800A530C = { 0, 0, 0x60040000 };
Battle D_800A5318 = { 0, 0, 0x60040000 };
Battle D_800A5324 = { 0, 0, 0x60040000 };
BattleList D_800A5330 = {
    0,
    { &D_800A52D0, &D_800A52DC, &D_800A52E8, &D_800A52F4,
      &D_800A5300, &D_800A530C, &D_800A5318, &D_800A5324 },
};
Battle D_800A5354 = { 0, 0, 0x60040000 };
Battle D_800A5360 = { 0, 0, 0x60040000 };
Battle D_800A536C = { 0, 0, 0x60040000 };
Battle D_800A5378 = { 0, 0, 0x60040000 };
Battle D_800A5384 = { 0, 0, 0x60040000 };
Battle D_800A5390 = { 0, 0, 0x60040000 };
Battle D_800A539C = { 0, 0, 0x60040000 };
Battle D_800A53A8 = { 0, 0, 0x60040000 };
BattleList D_800A53B4 = {
    0,
    { &D_800A5354, &D_800A5360, &D_800A536C, &D_800A5378,
      &D_800A5384, &D_800A5390, &D_800A539C, &D_800A53A8 },
};
Battle D_800A53D8 = { 0, 0, 0x60040000 };
Battle D_800A53E4 = { 0, 0, 0x60040000 };
Battle D_800A53F0 = { 0, 0, 0x60040000 };
Battle D_800A53FC = { 0, 0, 0x60040000 };
Battle D_800A5408 = { 0, 0, 0x60040000 };
Battle D_800A5414 = { 0, 0, 0x60040000 };
Battle D_800A5420 = { 0, 0, 0x60040000 };
Battle D_800A542C = { 0, 0, 0x60040000 };
BattleList D_800A5438 = {
    0,
    { &D_800A53D8, &D_800A53E4, &D_800A53F0, &D_800A53FC,
      &D_800A5408, &D_800A5414, &D_800A5420, &D_800A542C },
};
FieldBattles stageBattles[] = {
    { 179, 2, 0, { &D_800A509C, &D_800A5120, &D_800A51A4, &D_800A5228 } },
    { 207, 12, 0, { &D_800A52AC, &D_800A5330, &D_800A53B4, &D_800A5438 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x160, 0x1FF },
};
FieldActorEntry D_800A5504 = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A5504,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 550, 238, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 239, 158, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 661, 204, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 896, 119, 0, 0 },
    { 1, 0, 0xFF, 2, 0x33, 2, 0, 7, 0x18, 0, 188, -92, 0, 0 },
    { 1, 0, 0xFF, 2, 0x33, 2, 0, 7, 0x18, 0, 428, -20, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 128, 276, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 192, 297, 0, 0 },
    { 1, 0, 0x52, 2, 2, 0, 0, 0, 0, 0, 256, 292, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 320, 320, 0, 0 },
    { 1, 0, 0x48, 2, 4, 0, 0, 0, 0, 0, 768, 312, 0, 0 },
    { 1, 0, 0x54, 2, 5, 0, 0, 0, 0, 0, 832, 270, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 512, 335, 0, 0 },
    { 1, 0, 0x44, 2, 7, 0, 0, 0, 0, 0, 576, 316, 0, 0 },
    { 1, 0, 0x40, 2, 8, 0, 0, 0, 0, 0, 640, 337, 0, 0 },
    { 1, 0, 0x40, 2, 9, 0, 0, 0, 0, 0, 704, 338, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 460, 182, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 348, 194, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 761, 156, 0, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 188, 36, 280, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 428, 108, 352, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E1, 0xE0, 0x110, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E1, 0x1D0, 0x154, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E1, 0x390, 0x108, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
