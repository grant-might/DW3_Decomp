#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x623
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x633
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xF500, 0x2FA00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x38;
    D_800990B4.music = 0x60E00000;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A4F6C;
extern StagePoint D_800A4F7C;
extern StagePoint D_800A4F8C;
extern StagePoint D_800A4F9C;
extern StagePoint D_800A4FB4;
extern StagePoint D_800A4FC4;
extern StagePoint D_800A4FD4;
extern StagePoint D_800A4FE4;
extern StagePoint D_800A4FFC;
extern StagePoint D_800A500C;
extern StagePoint D_800A501C;
extern StagePoint D_800A502C;
extern StagePoint D_800A5044;
extern StagePoint D_800A5054;
extern StagePoint D_800A5064;
extern StagePoint D_800A5074;
extern StagePoint D_800A508C;
extern StagePoint D_800A509C;
extern StagePoint D_800A50AC;
extern StagePoint D_800A50BC;
extern StagePoint D_800A50D4;
extern StagePoint D_800A50E4;
extern StagePoint D_800A50F4;
extern StagePoint D_800A5104;
extern StagePoint D_800A511C;
extern StagePoint D_800A512C;
extern StagePoint D_800A513C;
extern StagePoint D_800A514C;
extern StagePoint D_800A5164;
extern StagePoint D_800A5174;
extern StagePoint D_800A5184;
extern StagePoint D_800A5194;
extern StagePoints D_800A4FAC;
extern StagePoints D_800A4FF4;
extern StagePoints D_800A503C;
extern StagePoints D_800A5084;
extern StagePoints D_800A50CC;
extern StagePoints D_800A5114;
extern StagePoints D_800A515C;
extern StagePoints D_800A51A4;
extern StagePoints D_800A51AC;
extern Battle D_800A51DC;
extern Battle D_800A51E8;
extern Battle D_800A51F4;
extern Battle D_800A5200;
extern Battle D_800A520C;
extern Battle D_800A5218;
extern Battle D_800A5224;
extern Battle D_800A5230;
extern Battle D_800A5260;
extern Battle D_800A526C;
extern Battle D_800A5278;
extern Battle D_800A5284;
extern Battle D_800A5290;
extern Battle D_800A529C;
extern Battle D_800A52A8;
extern Battle D_800A52B4;
extern Battle D_800A52E4;
extern Battle D_800A52F0;
extern Battle D_800A52FC;
extern Battle D_800A5308;
extern Battle D_800A5314;
extern Battle D_800A5320;
extern Battle D_800A532C;
extern Battle D_800A5338;
extern Battle D_800A5368;
extern Battle D_800A5374;
extern Battle D_800A5380;
extern Battle D_800A538C;
extern Battle D_800A5398;
extern Battle D_800A53A4;
extern Battle D_800A53B0;
extern Battle D_800A53BC;
extern BattleList D_800A523C;
extern BattleList D_800A52C0;
extern BattleList D_800A5344;
extern BattleList D_800A53C8;

StagePoint D_800A4F6C = { 0x2C1, 1, 1, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A4F7C = { 0x2C1, 1, 3, 0x340, 240, 1, &D_800A4F6C };
StagePoint D_800A4F8C = { 0x2C1, 1, 2, 0x110, 0x108, 7, &D_800A4F7C };
StagePoint D_800A4F9C = { 0x2C0, 0, 0, 0x100, 0x278, 5, &D_800A4F8C };
StagePoints D_800A4FAC = { 1, 1, &D_800A4F9C };
StagePoint D_800A4FB4 = { 0x2C1, 1, 2, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A4FC4 = { 0x2C1, 1, 4, 0x340, 240, 1, &D_800A4FB4 };
StagePoint D_800A4FD4 = { 0x2C1, 1, 1, 0x110, 0x108, 7, &D_800A4FC4 };
StagePoint D_800A4FE4 = { 0x2C0, 0, 0, 0x100, 0x278, 5, &D_800A4FD4 };
StagePoints D_800A4FF4 = { 1, 2, &D_800A4FE4 };
StagePoint D_800A4FFC = { 0x2C1, 1, 4, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A500C = { 0x2C1, 1, 5, 0x340, 240, 1, &D_800A4FFC };
StagePoint D_800A501C = { 0x2C1, 1, 3, 0x110, 0x108, 7, &D_800A500C };
StagePoint D_800A502C = { 0x2C1, 1, 1, 0x128, 0x2F4, 5, &D_800A501C };
StagePoints D_800A503C = { 1, 3, &D_800A502C };
StagePoint D_800A5044 = { 0x2C1, 1, 3, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A5054 = { 0x2C1, 1, 6, 0x340, 240, 1, &D_800A5044 };
StagePoint D_800A5064 = { 0x2C1, 1, 4, 0x110, 0x108, 7, &D_800A5054 };
StagePoint D_800A5074 = { 0x2C1, 1, 2, 0x128, 0x2F4, 5, &D_800A5064 };
StagePoints D_800A5084 = { 1, 4, &D_800A5074 };
StagePoint D_800A508C = { 0x2C1, 1, 5, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A509C = { 0x2C1, 1, 7, 0x340, 240, 1, &D_800A508C };
StagePoint D_800A50AC = { 0x2C1, 1, 6, 0x110, 0x108, 7, &D_800A509C };
StagePoint D_800A50BC = { 0x2C1, 1, 3, 0x128, 0x2F4, 5, &D_800A50AC };
StagePoints D_800A50CC = { 1, 5, &D_800A50BC };
StagePoint D_800A50D4 = { 0x2C1, 1, 6, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A50E4 = { 0x2C1, 1, 8, 0x340, 240, 1, &D_800A50D4 };
StagePoint D_800A50F4 = { 0x2C1, 1, 5, 0x110, 0x108, 7, &D_800A50E4 };
StagePoint D_800A5104 = { 0x2C1, 1, 4, 0x128, 0x2F4, 5, &D_800A50F4 };
StagePoints D_800A5114 = { 1, 6, &D_800A5104 };
StagePoint D_800A511C = { 0x2C1, 1, 8, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A512C = { 0x2C1, 1, 1, 0x340, 240, 1, &D_800A511C };
StagePoint D_800A513C = { 0x2C1, 1, 7, 0x110, 0x108, 7, &D_800A512C };
StagePoint D_800A514C = { 0x2C1, 1, 5, 0x128, 0x2F4, 5, &D_800A513C };
StagePoints D_800A515C = { 1, 7, &D_800A514C };
StagePoint D_800A5164 = { 0x2C1, 1, 7, 0x368, 0x2EC, 3, NULL };
StagePoint D_800A5174 = { 0x2C1, 1, 2, 0x340, 240, 1, &D_800A5164 };
StagePoint D_800A5184 = { 0x2C1, 1, 8, 0x110, 0x108, 7, &D_800A5174 };
StagePoint D_800A5194 = { 0x2C1, 1, 6, 0x128, 0x2F4, 5, &D_800A5184 };
StagePoints D_800A51A4 = { 1, 8, &D_800A5194 };
StagePoints D_800A51AC = { 0, 0, &D_800A4F9C };
StagePoints *placePoints[] = {
    &D_800A4FAC, &D_800A4FF4, &D_800A503C, &D_800A5084,
    &D_800A50CC, &D_800A5114, &D_800A515C, &D_800A51A4,
    &D_800A51AC, NULL,
};
Battle D_800A51DC = { 72, 5, 0x60080000 };
Battle D_800A51E8 = { 72, 5, 0x60080000 };
Battle D_800A51F4 = { 72, 5, 0x60080000 };
Battle D_800A5200 = { 72, 5, 0x60080000 };
Battle D_800A520C = { 162, 5, 0x60080000 };
Battle D_800A5218 = { 162, 5, 0x60080000 };
Battle D_800A5224 = { 162, 5, 0x60080000 };
Battle D_800A5230 = { 162, 5, 0x60080000 };
BattleList D_800A523C = {
    3,
    { &D_800A51DC, &D_800A51E8, &D_800A51F4, &D_800A5200,
      &D_800A520C, &D_800A5218, &D_800A5224, &D_800A5230 },
};
Battle D_800A5260 = { 0, 0, 0x60040000 };
Battle D_800A526C = { 0, 0, 0x60040000 };
Battle D_800A5278 = { 0, 0, 0x60040000 };
Battle D_800A5284 = { 0, 0, 0x60040000 };
Battle D_800A5290 = { 0, 0, 0x60040000 };
Battle D_800A529C = { 0, 0, 0x60040000 };
Battle D_800A52A8 = { 0, 0, 0x60040000 };
Battle D_800A52B4 = { 0, 0, 0x60040000 };
BattleList D_800A52C0 = {
    0,
    { &D_800A5260, &D_800A526C, &D_800A5278, &D_800A5284,
      &D_800A5290, &D_800A529C, &D_800A52A8, &D_800A52B4 },
};
Battle D_800A52E4 = { 0, 0, 0x60040000 };
Battle D_800A52F0 = { 0, 0, 0x60040000 };
Battle D_800A52FC = { 0, 0, 0x60040000 };
Battle D_800A5308 = { 0, 0, 0x60040000 };
Battle D_800A5314 = { 0, 0, 0x60040000 };
Battle D_800A5320 = { 0, 0, 0x60040000 };
Battle D_800A532C = { 0, 0, 0x60040000 };
Battle D_800A5338 = { 0, 0, 0x60040000 };
BattleList D_800A5344 = {
    0,
    { &D_800A52E4, &D_800A52F0, &D_800A52FC, &D_800A5308,
      &D_800A5314, &D_800A5320, &D_800A532C, &D_800A5338 },
};
Battle D_800A5368 = { 0, 0, 0x60040000 };
Battle D_800A5374 = { 0, 0, 0x60040000 };
Battle D_800A5380 = { 0, 0, 0x60040000 };
Battle D_800A538C = { 0, 0, 0x60040000 };
Battle D_800A5398 = { 0, 0, 0x60040000 };
Battle D_800A53A4 = { 0, 0, 0x60040000 };
Battle D_800A53B0 = { 0, 0, 0x60040000 };
Battle D_800A53BC = { 0, 0, 0x60040000 };
BattleList D_800A53C8 = {
    0,
    { &D_800A5368, &D_800A5374, &D_800A5380, &D_800A538C,
      &D_800A5398, &D_800A53A4, &D_800A53B0, &D_800A53BC },
};
FieldBattles stageBattles[] = {
    { 103, 0, 0, { &D_800A523C, &D_800A52C0, &D_800A5344, &D_800A53C8 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 324, 536, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 372, 224, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 516, 664, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 532, 288, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 580, 456, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 708, 616, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 724, 272, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 788, 464, 0, 0 },
    { 1, 0, 0x60, 4, 1, 0, 0, 0, 0, 0, 388, 238, 328, 0 },
    { 1, 0, 0x60, 4, 2, 0, 0, 0, 0, 0, 548, 302, 392, 0 },
    { 1, 0, 0x60, 4, 3, 0, 0, 0, 0, 0, 740, 286, 377, 0 },
    { 1, 0, 0x60, 4, 4, 0, 0, 0, 0, 0, 596, 470, 561, 0 },
    { 1, 0, 0x60, 4, 5, 0, 0, 0, 0, 0, 804, 478, 568, 0 },
    { 1, 0, 0x60, 4, 6, 0, 0, 0, 0, 0, 340, 550, 640, 0 },
    { 1, 0, 0x60, 4, 7, 0, 0, 0, 0, 0, 532, 678, 768, 0 },
    { 1, 0, 0x60, 4, 8, 0, 0, 0, 0, 0, 724, 630, 717, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C2, 0x358, 0xFC, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C2, 0x350, 0x2F8, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C2, 0x118, 0x2EC, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C2, 0x120, 0x100, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
