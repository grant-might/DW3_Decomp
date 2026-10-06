#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x6E4;
    D_800990B4.sheetEntry = 0x9330004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x932;
    D_800990B4.start = (Vec2){0xC700, 0x16D00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1D;
    D_800990B4.music = 0x60740000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x9330006);
    D_8009A70C.setFile(7, 0x9330007);
    D_8009A70C.setFile(4, 0x9330005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60FC;
extern StagePoint D_800A610C;
extern StagePoints D_800A611C;
extern FieldActorEntry D_800A619C;
extern Battle D_800A6338;
extern Battle D_800A6344;
extern Battle D_800A6350;
extern Battle D_800A635C;
extern Battle D_800A6368;
extern Battle D_800A6374;
extern Battle D_800A6380;
extern Battle D_800A638C;
extern Battle D_800A63BC;
extern Battle D_800A63C8;
extern Battle D_800A63D4;
extern Battle D_800A63E0;
extern Battle D_800A63EC;
extern Battle D_800A63F8;
extern Battle D_800A6404;
extern Battle D_800A6410;
extern Battle D_800A6440;
extern Battle D_800A644C;
extern Battle D_800A6458;
extern Battle D_800A6464;
extern Battle D_800A6470;
extern Battle D_800A647C;
extern Battle D_800A6488;
extern Battle D_800A6494;
extern Battle D_800A64C4;
extern Battle D_800A64D0;
extern Battle D_800A64DC;
extern Battle D_800A64E8;
extern Battle D_800A64F4;
extern Battle D_800A6500;
extern Battle D_800A650C;
extern Battle D_800A6518;
extern BattleList D_800A6398;
extern BattleList D_800A641C;
extern BattleList D_800A64A0;
extern BattleList D_800A6524;

StagePoint D_800A60FC = { 0x2E4, 2, 4, 192, 0x180, 5, NULL };
StagePoint D_800A610C = { 0x28C, 0, 0, 0x328, 0x424, 0, &D_800A60FC };
StagePoints D_800A611C = { 2, 1, &D_800A610C };
StagePoints *placePoints[] = {
    &D_800A611C, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x152, 0x198, 0x48, 0x98, 0x160, 0x1FF },
};
FieldActorEntry D_800A619C = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A619C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 254, 275, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 621, 244, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 852, 128, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 384, 171, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 689, 166, 0, 0 },
    { 1, 0, 0xFF, 2, 0x33, 2, 0, 7, 0x18, 0, 140, -36, 0, 0 },
    { 1, 0, 0x98, 2, 5, 0, 0, 0, 0, 0, 432, 254, 0, 0 },
    { 1, 0, 0x8A, 2, 6, 0, 0, 0, 0, 0, 408, 268, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 475, 113, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 169, 206, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 750, 142, 0, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 140, 92, 336, 0 },
    { 1, 0, 0x92, 4, 1, 0, 0, 0, 0, 0, 560, 179, 319, 0 },
    { 1, 0, 0x79, 4, 2, 0, 0, 0, 0, 0, 528, 198, 335, 0 },
    { 1, 0, 0x88, 4, 3, 0, 0, 0, 0, 0, 496, 216, 351, 0 },
    { 1, 0, 0x86, 4, 4, 0, 0, 0, 0, 0, 464, 232, 368, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E2, 0xB0, 0x148, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E2, 0x330, 0xF8, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6338 = { 61, 11, 0x60080000 };
Battle D_800A6344 = { 61, 11, 0x60080000 };
Battle D_800A6350 = { 61, 11, 0x60080000 };
Battle D_800A635C = { 61, 11, 0x60080000 };
Battle D_800A6368 = { 61, 11, 0x60080000 };
Battle D_800A6374 = { 61, 11, 0x60080000 };
Battle D_800A6380 = { 61, 11, 0x60080000 };
Battle D_800A638C = { 61, 11, 0x60080000 };
BattleList D_800A6398 = {
    3,
    { &D_800A6338, &D_800A6344, &D_800A6350, &D_800A635C,
      &D_800A6368, &D_800A6374, &D_800A6380, &D_800A638C },
};
Battle D_800A63BC = { 0, 0, 0x60040000 };
Battle D_800A63C8 = { 0, 0, 0x60040000 };
Battle D_800A63D4 = { 0, 0, 0x60040000 };
Battle D_800A63E0 = { 0, 0, 0x60040000 };
Battle D_800A63EC = { 0, 0, 0x60040000 };
Battle D_800A63F8 = { 0, 0, 0x60040000 };
Battle D_800A6404 = { 0, 0, 0x60040000 };
Battle D_800A6410 = { 0, 0, 0x60040000 };
BattleList D_800A641C = {
    0,
    { &D_800A63BC, &D_800A63C8, &D_800A63D4, &D_800A63E0,
      &D_800A63EC, &D_800A63F8, &D_800A6404, &D_800A6410 },
};
Battle D_800A6440 = { 0, 0, 0x60040000 };
Battle D_800A644C = { 0, 0, 0x60040000 };
Battle D_800A6458 = { 0, 0, 0x60040000 };
Battle D_800A6464 = { 0, 0, 0x60040000 };
Battle D_800A6470 = { 0, 0, 0x60040000 };
Battle D_800A647C = { 0, 0, 0x60040000 };
Battle D_800A6488 = { 0, 0, 0x60040000 };
Battle D_800A6494 = { 0, 0, 0x60040000 };
BattleList D_800A64A0 = {
    0,
    { &D_800A6440, &D_800A644C, &D_800A6458, &D_800A6464,
      &D_800A6470, &D_800A647C, &D_800A6488, &D_800A6494 },
};
Battle D_800A64C4 = { 0, 0, 0x60040000 };
Battle D_800A64D0 = { 0, 0, 0x60040000 };
Battle D_800A64DC = { 0, 0, 0x60040000 };
Battle D_800A64E8 = { 0, 0, 0x60040000 };
Battle D_800A64F4 = { 0, 0, 0x60040000 };
Battle D_800A6500 = { 0, 0, 0x60040000 };
Battle D_800A650C = { 0, 0, 0x60040000 };
Battle D_800A6518 = { 0, 0, 0x60040000 };
BattleList D_800A6524 = {
    0,
    { &D_800A64C4, &D_800A64D0, &D_800A64DC, &D_800A64E8,
      &D_800A64F4, &D_800A6500, &D_800A650C, &D_800A6518 },
};
FieldBattles stageBattles[] = {
    { 398, 2, 0, { &D_800A6398, &D_800A641C, &D_800A64A0, &D_800A6524 } },
};
