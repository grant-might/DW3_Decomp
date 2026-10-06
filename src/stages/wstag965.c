#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x01 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x6E0;
    D_800990B4.sheetEntry = 0x9390004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x938;
    D_800990B4.start = (Vec2){0x24000, 0x15200};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1D;
    D_800990B4.music = 0x60740000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x9390006);
    D_8009A70C.setFile(7, 0x9390007);
    D_8009A70C.setFile(4, 0x9390005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A6100;
extern StagePoint D_800A6110;
extern StagePoint D_800A6120;
extern StagePoints D_800A6130;
extern FieldActorEntry D_800A61B0;
extern Battle D_800A6350;
extern Battle D_800A635C;
extern Battle D_800A6368;
extern Battle D_800A6374;
extern Battle D_800A6380;
extern Battle D_800A638C;
extern Battle D_800A6398;
extern Battle D_800A63A4;
extern Battle D_800A63D4;
extern Battle D_800A63E0;
extern Battle D_800A63EC;
extern Battle D_800A63F8;
extern Battle D_800A6404;
extern Battle D_800A6410;
extern Battle D_800A641C;
extern Battle D_800A6428;
extern Battle D_800A6458;
extern Battle D_800A6464;
extern Battle D_800A6470;
extern Battle D_800A647C;
extern Battle D_800A6488;
extern Battle D_800A6494;
extern Battle D_800A64A0;
extern Battle D_800A64AC;
extern Battle D_800A64DC;
extern Battle D_800A64E8;
extern Battle D_800A64F4;
extern Battle D_800A6500;
extern Battle D_800A650C;
extern Battle D_800A6518;
extern Battle D_800A6524;
extern Battle D_800A6530;
extern BattleList D_800A63B0;
extern BattleList D_800A6434;
extern BattleList D_800A64B8;
extern BattleList D_800A653C;

StagePoint D_800A6100 = { 0x2E6, 3, 1, 0x450, 0x248, 1, NULL };
StagePoint D_800A6110 = { 0x2E4, 3, 1, 192, 0x180, 5, &D_800A6100 };
StagePoint D_800A6120 = { 0x296, 0, 0, 0x240, 0x200, 0, &D_800A6110 };
StagePoints D_800A6130 = { 3, 1, &D_800A6120 };
StagePoints *placePoints[] = {
    &D_800A6130, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x1CF, 0xC0, 0xCF, 0x160, 0x1FF },
};
FieldActorEntry D_800A61B0 = { NULL, NULL, 0x147, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A61B0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 231, 159, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 386, 203, 0, 0 },
    { 1, 0, 0x8F, 2, 0x37, 1, 0x37, 0x4B, 0xA, 0, 943, 97, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 587, 241, 0, 0 },
    { 1, 0, 0xB6, 2, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 783, 147, 0, 0 },
    { 1, 0, 0xFF, 2, 0x33, 2, 0, 7, 0x18, 0, 540, -76, 0, 0 },
    { 1, 0, 0x55, 2, 0, 0, 0, 0, 0, 0, 384, 299, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 448, 344, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 640, 339, 0, 0 },
    { 1, 0, 0x52, 2, 3, 0, 0, 0, 0, 0, 704, 302, 0, 0 },
    { 1, 0, 0x8F, 6, 0x37, 1, 0x37, 0x4B, 0xA, 0, 669, 89, 0, 0 },
    { 1, 0, 0xB6, 6, 0x4C, 1, 0x4C, 0x62, 0xA, 0, 538, 16, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 448, 180, 0, 0 },
    { 1, 0, 0x68, 6, 0x34, 1, 0x34, 0x36, 0xA, 0, 848, 69, 0, 0 },
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x18, 0, 540, 52, 296, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E5, 0x240, 0x120, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E5, 0x3B0, 0xD8, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E5, 0xE0, 0x120, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6350 = { 64, 11, 0x60080000 };
Battle D_800A635C = { 64, 11, 0x60080000 };
Battle D_800A6368 = { 64, 11, 0x60080000 };
Battle D_800A6374 = { 64, 11, 0x60080000 };
Battle D_800A6380 = { 64, 11, 0x60080000 };
Battle D_800A638C = { 64, 11, 0x60080000 };
Battle D_800A6398 = { 64, 11, 0x60080000 };
Battle D_800A63A4 = { 64, 11, 0x60080000 };
BattleList D_800A63B0 = {
    3,
    { &D_800A6350, &D_800A635C, &D_800A6368, &D_800A6374,
      &D_800A6380, &D_800A638C, &D_800A6398, &D_800A63A4 },
};
Battle D_800A63D4 = { 0, 0, 0x60040000 };
Battle D_800A63E0 = { 0, 0, 0x60040000 };
Battle D_800A63EC = { 0, 0, 0x60040000 };
Battle D_800A63F8 = { 0, 0, 0x60040000 };
Battle D_800A6404 = { 0, 0, 0x60040000 };
Battle D_800A6410 = { 0, 0, 0x60040000 };
Battle D_800A641C = { 0, 0, 0x60040000 };
Battle D_800A6428 = { 0, 0, 0x60040000 };
BattleList D_800A6434 = {
    0,
    { &D_800A63D4, &D_800A63E0, &D_800A63EC, &D_800A63F8,
      &D_800A6404, &D_800A6410, &D_800A641C, &D_800A6428 },
};
Battle D_800A6458 = { 0, 0, 0x60040000 };
Battle D_800A6464 = { 0, 0, 0x60040000 };
Battle D_800A6470 = { 0, 0, 0x60040000 };
Battle D_800A647C = { 0, 0, 0x60040000 };
Battle D_800A6488 = { 0, 0, 0x60040000 };
Battle D_800A6494 = { 0, 0, 0x60040000 };
Battle D_800A64A0 = { 0, 0, 0x60040000 };
Battle D_800A64AC = { 0, 0, 0x60040000 };
BattleList D_800A64B8 = {
    0,
    { &D_800A6458, &D_800A6464, &D_800A6470, &D_800A647C,
      &D_800A6488, &D_800A6494, &D_800A64A0, &D_800A64AC },
};
Battle D_800A64DC = { 0, 0, 0x60040000 };
Battle D_800A64E8 = { 0, 0, 0x60040000 };
Battle D_800A64F4 = { 0, 0, 0x60040000 };
Battle D_800A6500 = { 0, 0, 0x60040000 };
Battle D_800A650C = { 0, 0, 0x60040000 };
Battle D_800A6518 = { 0, 0, 0x60040000 };
Battle D_800A6524 = { 0, 0, 0x60040000 };
Battle D_800A6530 = { 0, 0, 0x60040000 };
BattleList D_800A653C = {
    0,
    { &D_800A64DC, &D_800A64E8, &D_800A64F4, &D_800A6500,
      &D_800A650C, &D_800A6518, &D_800A6524, &D_800A6530 },
};
FieldBattles stageBattles[] = {
    { 403, 3, 0, { &D_800A63B0, &D_800A6434, &D_800A64B8, &D_800A653C } },
};
