#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x4B0
#define STAGE_FILE_8 0x4AA
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x4C0
#define STAGE_FILE_8 0x4BA
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE_8;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 1;
    D_800990B4.start = (Vec2){0xD300, 0x26100};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3A;
    D_800990B4.music = 0x60E80000;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E40;
extern Battle D_800A4E4C;
extern Battle D_800A4E58;
extern Battle D_800A4E64;
extern Battle D_800A4E70;
extern Battle D_800A4E7C;
extern Battle D_800A4E88;
extern Battle D_800A4E94;
extern Battle D_800A4EC4;
extern Battle D_800A4ED0;
extern Battle D_800A4EDC;
extern Battle D_800A4EE8;
extern Battle D_800A4EF4;
extern Battle D_800A4F00;
extern Battle D_800A4F0C;
extern Battle D_800A4F18;
extern Battle D_800A4F48;
extern Battle D_800A4F54;
extern Battle D_800A4F60;
extern Battle D_800A4F6C;
extern Battle D_800A4F78;
extern Battle D_800A4F84;
extern Battle D_800A4F90;
extern Battle D_800A4F9C;
extern Battle D_800A4FCC;
extern Battle D_800A4FD8;
extern Battle D_800A4FE4;
extern Battle D_800A4FF0;
extern Battle D_800A4FFC;
extern Battle D_800A5008;
extern Battle D_800A5014;
extern Battle D_800A5020;
extern BattleList D_800A4EA0;
extern BattleList D_800A4F24;
extern BattleList D_800A4FA8;
extern BattleList D_800A502C;

Battle D_800A4E40 = { 80, 12, 0x60080000 };
Battle D_800A4E4C = { 80, 12, 0x60080000 };
Battle D_800A4E58 = { 80, 12, 0x60080000 };
Battle D_800A4E64 = { 80, 12, 0x60080000 };
Battle D_800A4E70 = { 75, 12, 0x60080000 };
Battle D_800A4E7C = { 75, 12, 0x60080000 };
Battle D_800A4E88 = { 75, 12, 0x60080000 };
Battle D_800A4E94 = { 75, 12, 0x60080000 };
BattleList D_800A4EA0 = {
    2,
    { &D_800A4E40, &D_800A4E4C, &D_800A4E58, &D_800A4E64,
      &D_800A4E70, &D_800A4E7C, &D_800A4E88, &D_800A4E94 },
};
Battle D_800A4EC4 = { 0, 0, 0x60040000 };
Battle D_800A4ED0 = { 0, 0, 0x60040000 };
Battle D_800A4EDC = { 0, 0, 0x60040000 };
Battle D_800A4EE8 = { 0, 0, 0x60040000 };
Battle D_800A4EF4 = { 0, 0, 0x60040000 };
Battle D_800A4F00 = { 0, 0, 0x60040000 };
Battle D_800A4F0C = { 0, 0, 0x60040000 };
Battle D_800A4F18 = { 0, 0, 0x60040000 };
BattleList D_800A4F24 = {
    0,
    { &D_800A4EC4, &D_800A4ED0, &D_800A4EDC, &D_800A4EE8,
      &D_800A4EF4, &D_800A4F00, &D_800A4F0C, &D_800A4F18 },
};
Battle D_800A4F48 = { 0, 0, 0x60040000 };
Battle D_800A4F54 = { 0, 0, 0x60040000 };
Battle D_800A4F60 = { 0, 0, 0x60040000 };
Battle D_800A4F6C = { 0, 0, 0x60040000 };
Battle D_800A4F78 = { 0, 0, 0x60040000 };
Battle D_800A4F84 = { 0, 0, 0x60040000 };
Battle D_800A4F90 = { 0, 0, 0x60040000 };
Battle D_800A4F9C = { 0, 0, 0x60040000 };
BattleList D_800A4FA8 = {
    0,
    { &D_800A4F48, &D_800A4F54, &D_800A4F60, &D_800A4F6C,
      &D_800A4F78, &D_800A4F84, &D_800A4F90, &D_800A4F9C },
};
Battle D_800A4FCC = { 0, 0, 0x60040000 };
Battle D_800A4FD8 = { 0, 0, 0x60040000 };
Battle D_800A4FE4 = { 0, 0, 0x60040000 };
Battle D_800A4FF0 = { 0, 0, 0x60040000 };
Battle D_800A4FFC = { 0, 0, 0x60040000 };
Battle D_800A5008 = { 0, 0, 0x60040000 };
Battle D_800A5014 = { 0, 0, 0x60040000 };
Battle D_800A5020 = { 0, 0, 0x60040000 };
BattleList D_800A502C = {
    0,
    { &D_800A4FCC, &D_800A4FD8, &D_800A4FE4, &D_800A4FF0,
      &D_800A4FFC, &D_800A5008, &D_800A5014, &D_800A5020 },
};
FieldBattles stageBattles[] = {
    { 47, 0, 0, { &D_800A4EA0, &D_800A4F24, &D_800A4FA8, &D_800A502C } },
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
    { 1, 0, 0x80, 2, 2, 0, 0, 0, 0, 0, 463, 0, 0, 0 },
    { 1, 0, 0x80, 2, 3, 0, 0, 0, 0, 0, 512, 0, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x37, 4, 0, 180, 506, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x37, 4, 0, 249, 388, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3D, 4, 0, 160, 486, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3D, 4, 0, 229, 368, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 1, 4, 0, 388, 395, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 1, 4, 0, 429, 415, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 1, 4, 0, 441, 565, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 1, 4, 0, 468, 435, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 1, 4, 0, 482, 585, 0, 0 },
    { 1, 0, 0x40, 4, 0x3F, 2, 0, 1, 4, 0, 460, 138, 584, 0 },
    { 1, 0, 0x40, 4, 0x3F, 2, 0, 1, 4, 0, 492, 154, 584, 0 },
    { 1, 0, 0x40, 4, 0x3F, 2, 0, 1, 4, 0, 586, 201, 584, 0 },
    { 1, 0, 0x65, 4, 0, 0, 0, 0, 0, 0, 84, 484, 584, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 489, 136, 190, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 509, 136, 198, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 525, 136, 207, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 541, 136, 215, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24D, 0x88, 0x22C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x254, 0x3F0, 0x2F0, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
