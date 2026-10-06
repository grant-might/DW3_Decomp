#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x700;
    D_800990B4.sheetEntry = 0x9310004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x930;
    D_800990B4.start = (Vec2){0xDB00, 0x12300};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1D;
    D_800990B4.music = 0x60740000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x9310006);
    D_8009A70C.setFile(7, 0x9310007);
    D_8009A70C.setFile(4, 0x9310005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60FC;
extern StagePoint D_800A610C;
extern StagePoint D_800A611C;
extern StagePoints D_800A612C;
extern FieldActorEntry D_800A61AC;
extern Battle D_800A63B8;
extern Battle D_800A63C4;
extern Battle D_800A63D0;
extern Battle D_800A63DC;
extern Battle D_800A63E8;
extern Battle D_800A63F4;
extern Battle D_800A6400;
extern Battle D_800A640C;
extern Battle D_800A643C;
extern Battle D_800A6448;
extern Battle D_800A6454;
extern Battle D_800A6460;
extern Battle D_800A646C;
extern Battle D_800A6478;
extern Battle D_800A6484;
extern Battle D_800A6490;
extern Battle D_800A64C0;
extern Battle D_800A64CC;
extern Battle D_800A64D8;
extern Battle D_800A64E4;
extern Battle D_800A64F0;
extern Battle D_800A64FC;
extern Battle D_800A6508;
extern Battle D_800A6514;
extern Battle D_800A6544;
extern Battle D_800A6550;
extern Battle D_800A655C;
extern Battle D_800A6568;
extern Battle D_800A6574;
extern Battle D_800A6580;
extern Battle D_800A658C;
extern Battle D_800A6598;
extern BattleList D_800A6418;
extern BattleList D_800A649C;
extern BattleList D_800A6520;
extern BattleList D_800A65A4;

StagePoint D_800A60FC = { 0x2E3, 1, 1, 160, 0x180, 5, NULL };
StagePoint D_800A610C = { 0x272, 0, 0, 0x420, 0x1F0, 0, &D_800A60FC };
StagePoint D_800A611C = { 0x272, 0, 0, 0x150, 0x148, 0, &D_800A610C };
StagePoints D_800A612C = { 1, 1, &D_800A611C };
StagePoints *placePoints[] = {
    &D_800A612C, NULL,
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
FieldActorEntry D_800A61AC = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A61AC,
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
Battle D_800A63B8 = { 62, 11, 0x60080000 };
Battle D_800A63C4 = { 62, 11, 0x60080000 };
Battle D_800A63D0 = { 62, 11, 0x60080000 };
Battle D_800A63DC = { 62, 11, 0x60080000 };
Battle D_800A63E8 = { 62, 11, 0x60080000 };
Battle D_800A63F4 = { 62, 11, 0x60080000 };
Battle D_800A6400 = { 103, 11, 0x60080000 };
Battle D_800A640C = { 103, 11, 0x60080000 };
BattleList D_800A6418 = {
    5,
    { &D_800A63B8, &D_800A63C4, &D_800A63D0, &D_800A63DC,
      &D_800A63E8, &D_800A63F4, &D_800A6400, &D_800A640C },
};
Battle D_800A643C = { 0, 0, 0x60040000 };
Battle D_800A6448 = { 0, 0, 0x60040000 };
Battle D_800A6454 = { 0, 0, 0x60040000 };
Battle D_800A6460 = { 0, 0, 0x60040000 };
Battle D_800A646C = { 0, 0, 0x60040000 };
Battle D_800A6478 = { 0, 0, 0x60040000 };
Battle D_800A6484 = { 0, 0, 0x60040000 };
Battle D_800A6490 = { 0, 0, 0x60040000 };
BattleList D_800A649C = {
    0,
    { &D_800A643C, &D_800A6448, &D_800A6454, &D_800A6460,
      &D_800A646C, &D_800A6478, &D_800A6484, &D_800A6490 },
};
Battle D_800A64C0 = { 0, 0, 0x60040000 };
Battle D_800A64CC = { 0, 0, 0x60040000 };
Battle D_800A64D8 = { 0, 0, 0x60040000 };
Battle D_800A64E4 = { 0, 0, 0x60040000 };
Battle D_800A64F0 = { 0, 0, 0x60040000 };
Battle D_800A64FC = { 0, 0, 0x60040000 };
Battle D_800A6508 = { 0, 0, 0x60040000 };
Battle D_800A6514 = { 0, 0, 0x60040000 };
BattleList D_800A6520 = {
    0,
    { &D_800A64C0, &D_800A64CC, &D_800A64D8, &D_800A64E4,
      &D_800A64F0, &D_800A64FC, &D_800A6508, &D_800A6514 },
};
Battle D_800A6544 = { 0, 0, 0x60040000 };
Battle D_800A6550 = { 0, 0, 0x60040000 };
Battle D_800A655C = { 0, 0, 0x60040000 };
Battle D_800A6568 = { 0, 0, 0x60040000 };
Battle D_800A6574 = { 0, 0, 0x60040000 };
Battle D_800A6580 = { 0, 0, 0x60040000 };
Battle D_800A658C = { 0, 0, 0x60040000 };
Battle D_800A6598 = { 0, 0, 0x60040000 };
BattleList D_800A65A4 = {
    0,
    { &D_800A6544, &D_800A6550, &D_800A655C, &D_800A6568,
      &D_800A6574, &D_800A6580, &D_800A658C, &D_800A6598 },
};
FieldBattles stageBattles[] = {
    { 395, 1, 0, { &D_800A6418, &D_800A649C, &D_800A6520, &D_800A65A4 } },
};
