#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x1BC;
    D_800990B4.sheetEntry = 0x9170000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x916;
    D_800990B4.start = (Vec2){0x19B00, 0x23500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x32;
    D_800990B4.music = 0x60C80000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, 0x9170002);
    D_8009A70C.setFile(7, 0x9170003);
    D_8009A70C.setFile(4, 0x9170001);
    D_8009A70C.unk50(0);
}

extern u16 D_800A6004[];
extern u16 D_800A6010[];
extern u16 D_800A601C[];
extern u16 D_800A6028[];
extern u16 D_800A6038[];
extern u16 D_800A6044[];
extern u16 D_800A604C[];
extern u16 D_800A6058[];
extern u16 D_800A60B4[];
extern FieldTalk D_800A6060[];
extern u16 D_800A60BC[];
extern FieldTalk D_800A6078[];
extern FieldActorEntry D_800A60C4;
extern FieldActorEntry D_800A60D8;
extern Battle D_800A61E8;
extern Battle D_800A61F4;
extern Battle D_800A6200;
extern Battle D_800A620C;
extern Battle D_800A6218;
extern Battle D_800A6224;
extern Battle D_800A6230;
extern Battle D_800A623C;
extern Battle D_800A626C;
extern Battle D_800A6278;
extern Battle D_800A6284;
extern Battle D_800A6290;
extern Battle D_800A629C;
extern Battle D_800A62A8;
extern Battle D_800A62B4;
extern Battle D_800A62C0;
extern Battle D_800A62F0;
extern Battle D_800A62FC;
extern Battle D_800A6308;
extern Battle D_800A6314;
extern Battle D_800A6320;
extern Battle D_800A632C;
extern Battle D_800A6338;
extern Battle D_800A6344;
extern Battle D_800A6374;
extern Battle D_800A6380;
extern Battle D_800A638C;
extern Battle D_800A6398;
extern Battle D_800A63A4;
extern Battle D_800A63B0;
extern Battle D_800A63BC;
extern Battle D_800A63C8;
extern BattleList D_800A6248;
extern BattleList D_800A62CC;
extern BattleList D_800A6350;
extern BattleList D_800A63D4;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x160, 0x100, 0x80, 0, 0x140, 0x1FF },
};
u16 D_800A6004[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A6010[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A601C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6028[] = { 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A6038[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6044[] = { 0, 1, 0xFFFF };
u16 D_800A604C[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A6058[] = { 0x7851, 1, 0xFFFF };
FieldTalk D_800A6060[] = {
    { NULL, NULL, 0x35 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6078[] = {
    { D_800A6004, D_800A6010, 0x37 },
    { D_800A601C, D_800A6028, 0x38 },
    { D_800A6038, D_800A6044, 0x35 },
    { D_800A604C, D_800A6058, 0x36 },
    { NULL, NULL, 0 },
};
u16 D_800A60B4[] = { 0x8192, 0, 0xFFFF };
u16 D_800A60BC[] = { 0x8192, 1, 0xFFFF };
FieldActorEntry D_800A60C4 = { D_800A60B4, D_800A6060, 0x33, 4, 320, 736, 3 };
FieldActorEntry D_800A60D8 = { D_800A60BC, D_800A6078, 0x33, 4, 320, 736, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A60C4,
    &D_800A60D8,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 1024, 448, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 1088, 448, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 896, 576, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 960, 576, 0, 0 },
    { 1, 0, 0x40, 2, 4, 0, 0, 0, 0, 0, 1024, 576, 0, 0 },
    { 1, 0, 0x40, 2, 5, 0, 0, 0, 0, 0, 1088, 576, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 1024, 640, 0, 0 },
    { 1, 0, 0x40, 2, 7, 0, 0, 0, 0, 0, 1088, 640, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x295, 0x5E, 0x40E, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x291, 0x374, 0x9B, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A61E8 = { 44, 3, 0x60080000 };
Battle D_800A61F4 = { 44, 3, 0x60080000 };
Battle D_800A6200 = { 44, 3, 0x60080000 };
Battle D_800A620C = { 44, 3, 0x60080000 };
Battle D_800A6218 = { 47, 3, 0x60080000 };
Battle D_800A6224 = { 47, 3, 0x60080000 };
Battle D_800A6230 = { 47, 3, 0x60080000 };
Battle D_800A623C = { 47, 3, 0x60080000 };
BattleList D_800A6248 = {
    3,
    { &D_800A61E8, &D_800A61F4, &D_800A6200, &D_800A620C,
      &D_800A6218, &D_800A6224, &D_800A6230, &D_800A623C },
};
Battle D_800A626C = { 148, 8, 0x60080000 };
Battle D_800A6278 = { 148, 8, 0x60080000 };
Battle D_800A6284 = { 148, 8, 0x60080000 };
Battle D_800A6290 = { 148, 8, 0x60080000 };
Battle D_800A629C = { 149, 8, 0x60080000 };
Battle D_800A62A8 = { 149, 8, 0x60080000 };
Battle D_800A62B4 = { 149, 8, 0x60080000 };
Battle D_800A62C0 = { 149, 8, 0x60080000 };
BattleList D_800A62CC = {
    2,
    { &D_800A626C, &D_800A6278, &D_800A6284, &D_800A6290,
      &D_800A629C, &D_800A62A8, &D_800A62B4, &D_800A62C0 },
};
Battle D_800A62F0 = { 0, 0, 0x60040000 };
Battle D_800A62FC = { 0, 0, 0x60040000 };
Battle D_800A6308 = { 0, 0, 0x60040000 };
Battle D_800A6314 = { 0, 0, 0x60040000 };
Battle D_800A6320 = { 0, 0, 0x60040000 };
Battle D_800A632C = { 0, 0, 0x60040000 };
Battle D_800A6338 = { 0, 0, 0x60040000 };
Battle D_800A6344 = { 0, 0, 0x60040000 };
BattleList D_800A6350 = {
    0,
    { &D_800A62F0, &D_800A62FC, &D_800A6308, &D_800A6314,
      &D_800A6320, &D_800A632C, &D_800A6338, &D_800A6344 },
};
Battle D_800A6374 = { 0, 0, 0x60040000 };
Battle D_800A6380 = { 0, 0, 0x60040000 };
Battle D_800A638C = { 0, 0, 0x60040000 };
Battle D_800A6398 = { 0, 0, 0x60040000 };
Battle D_800A63A4 = { 0, 0, 0x60040000 };
Battle D_800A63B0 = { 0, 0, 0x60040000 };
Battle D_800A63BC = { 0, 0, 0x60040000 };
Battle D_800A63C8 = { 0, 0, 0x60040000 };
BattleList D_800A63D4 = {
    0,
    { &D_800A6374, &D_800A6380, &D_800A638C, &D_800A6398,
      &D_800A63A4, &D_800A63B0, &D_800A63BC, &D_800A63C8 },
};
FieldBattles stageBattles[] = {
    { 386, 0, 0, { &D_800A6248, &D_800A62CC, &D_800A6350, &D_800A63D4 } },
};
