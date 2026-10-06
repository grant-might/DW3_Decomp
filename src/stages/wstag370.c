#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

extern FieldBattles D_800A5298[];
extern FieldBattles D_800A52B4[];
#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x1AF
#define STAGE_ARCHIVE 0x3C8
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x1BD
#define STAGE_ARCHIVE 0x3D8
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x19B00, 0x23500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x32;
    D_800990B4.music = 0x60C80000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress < 0xE) {
        D_800990B4.battles = D_800A5298;
    } else {
        D_800990B4.battles = D_800A52B4;
    }
}

extern Battle D_800A4E78;
extern Battle D_800A4E84;
extern Battle D_800A4E90;
extern Battle D_800A4E9C;
extern Battle D_800A4EA8;
extern Battle D_800A4EB4;
extern Battle D_800A4EC0;
extern Battle D_800A4ECC;
extern Battle D_800A4EFC;
extern Battle D_800A4F08;
extern Battle D_800A4F14;
extern Battle D_800A4F20;
extern Battle D_800A4F2C;
extern Battle D_800A4F38;
extern Battle D_800A4F44;
extern Battle D_800A4F50;
extern Battle D_800A4F80;
extern Battle D_800A4F8C;
extern Battle D_800A4F98;
extern Battle D_800A4FA4;
extern Battle D_800A4FB0;
extern Battle D_800A4FBC;
extern Battle D_800A4FC8;
extern Battle D_800A4FD4;
extern Battle D_800A5004;
extern Battle D_800A5010;
extern Battle D_800A501C;
extern Battle D_800A5028;
extern Battle D_800A5034;
extern Battle D_800A5040;
extern Battle D_800A504C;
extern Battle D_800A5058;
extern Battle D_800A5088;
extern Battle D_800A5094;
extern Battle D_800A50A0;
extern Battle D_800A50AC;
extern Battle D_800A50B8;
extern Battle D_800A50C4;
extern Battle D_800A50D0;
extern Battle D_800A50DC;
extern Battle D_800A510C;
extern Battle D_800A5118;
extern Battle D_800A5124;
extern Battle D_800A5130;
extern Battle D_800A513C;
extern Battle D_800A5148;
extern Battle D_800A5154;
extern Battle D_800A5160;
extern Battle D_800A5190;
extern Battle D_800A519C;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A5214;
extern Battle D_800A5220;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern BattleList D_800A4ED8;
extern BattleList D_800A4F5C;
extern BattleList D_800A4FE0;
extern BattleList D_800A5064;
extern BattleList D_800A50E8;
extern BattleList D_800A516C;
extern BattleList D_800A51F0;
extern BattleList D_800A5274;
extern u16 D_800A5388[];
extern FieldTalk D_800A5340[];
extern u16 D_800A5390[];
extern FieldTalk D_800A5358[];
extern u16 D_800A5398[];
extern FieldTalk D_800A5370[];
extern FieldActorEntry D_800A53A0;
extern FieldActorEntry D_800A53B4;
extern FieldActorEntry D_800A53C8;

Battle D_800A4E78 = { 44, 3, 0x60080000 };
Battle D_800A4E84 = { 44, 3, 0x60080000 };
Battle D_800A4E90 = { 44, 3, 0x60080000 };
Battle D_800A4E9C = { 44, 3, 0x60080000 };
Battle D_800A4EA8 = { 44, 3, 0x60080000 };
Battle D_800A4EB4 = { 44, 3, 0x60080000 };
Battle D_800A4EC0 = { 44, 3, 0x60080000 };
Battle D_800A4ECC = { 44, 3, 0x60080000 };
BattleList D_800A4ED8 = {
    3,
    { &D_800A4E78, &D_800A4E84, &D_800A4E90, &D_800A4E9C,
      &D_800A4EA8, &D_800A4EB4, &D_800A4EC0, &D_800A4ECC },
};
Battle D_800A4EFC = { 45, 8, 0x60080000 };
Battle D_800A4F08 = { 45, 8, 0x60080000 };
Battle D_800A4F14 = { 45, 8, 0x60080000 };
Battle D_800A4F20 = { 45, 8, 0x60080000 };
Battle D_800A4F2C = { 45, 8, 0x60080000 };
Battle D_800A4F38 = { 45, 8, 0x60080000 };
Battle D_800A4F44 = { 45, 8, 0x60080000 };
Battle D_800A4F50 = { 45, 8, 0x60080000 };
BattleList D_800A4F5C = {
    1,
    { &D_800A4EFC, &D_800A4F08, &D_800A4F14, &D_800A4F20,
      &D_800A4F2C, &D_800A4F38, &D_800A4F44, &D_800A4F50 },
};
Battle D_800A4F80 = { 0, 0, 0x60040000 };
Battle D_800A4F8C = { 0, 0, 0x60040000 };
Battle D_800A4F98 = { 0, 0, 0x60040000 };
Battle D_800A4FA4 = { 0, 0, 0x60040000 };
Battle D_800A4FB0 = { 0, 0, 0x60040000 };
Battle D_800A4FBC = { 0, 0, 0x60040000 };
Battle D_800A4FC8 = { 0, 0, 0x60040000 };
Battle D_800A4FD4 = { 0, 0, 0x60040000 };
BattleList D_800A4FE0 = {
    0,
    { &D_800A4F80, &D_800A4F8C, &D_800A4F98, &D_800A4FA4,
      &D_800A4FB0, &D_800A4FBC, &D_800A4FC8, &D_800A4FD4 },
};
Battle D_800A5004 = { 0, 0, 0x60040000 };
Battle D_800A5010 = { 0, 0, 0x60040000 };
Battle D_800A501C = { 0, 0, 0x60040000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 0, 0, 0x60040000 };
Battle D_800A504C = { 0, 0, 0x60040000 };
Battle D_800A5058 = { 0, 0, 0x60040000 };
BattleList D_800A5064 = {
    0,
    { &D_800A5004, &D_800A5010, &D_800A501C, &D_800A5028,
      &D_800A5034, &D_800A5040, &D_800A504C, &D_800A5058 },
};
Battle D_800A5088 = { 44, 3, 0x60080000 };
Battle D_800A5094 = { 44, 3, 0x60080000 };
Battle D_800A50A0 = { 44, 3, 0x60080000 };
Battle D_800A50AC = { 44, 3, 0x60080000 };
Battle D_800A50B8 = { 44, 3, 0x60080000 };
Battle D_800A50C4 = { 44, 3, 0x60080000 };
Battle D_800A50D0 = { 44, 3, 0x60080000 };
Battle D_800A50DC = { 44, 3, 0x60080000 };
BattleList D_800A50E8 = {
    3,
    { &D_800A5088, &D_800A5094, &D_800A50A0, &D_800A50AC,
      &D_800A50B8, &D_800A50C4, &D_800A50D0, &D_800A50DC },
};
Battle D_800A510C = { 45, 8, 0x60080000 };
Battle D_800A5118 = { 45, 8, 0x60080000 };
Battle D_800A5124 = { 57, 8, 0x60080000 };
Battle D_800A5130 = { 57, 8, 0x60080000 };
Battle D_800A513C = { 57, 8, 0x60080000 };
Battle D_800A5148 = { 57, 8, 0x60080000 };
Battle D_800A5154 = { 57, 8, 0x60080000 };
Battle D_800A5160 = { 57, 8, 0x60080000 };
BattleList D_800A516C = {
    1,
    { &D_800A510C, &D_800A5118, &D_800A5124, &D_800A5130,
      &D_800A513C, &D_800A5148, &D_800A5154, &D_800A5160 },
};
Battle D_800A5190 = { 0, 0, 0x60040000 };
Battle D_800A519C = { 0, 0, 0x60040000 };
Battle D_800A51A8 = { 0, 0, 0x60040000 };
Battle D_800A51B4 = { 0, 0, 0x60040000 };
Battle D_800A51C0 = { 0, 0, 0x60040000 };
Battle D_800A51CC = { 0, 0, 0x60040000 };
Battle D_800A51D8 = { 0, 0, 0x60040000 };
Battle D_800A51E4 = { 0, 0, 0x60040000 };
BattleList D_800A51F0 = {
    0,
    { &D_800A5190, &D_800A519C, &D_800A51A8, &D_800A51B4,
      &D_800A51C0, &D_800A51CC, &D_800A51D8, &D_800A51E4 },
};
Battle D_800A5214 = { 0, 0, 0x60040000 };
Battle D_800A5220 = { 0, 0, 0x60040000 };
Battle D_800A522C = { 0, 0, 0x60040000 };
Battle D_800A5238 = { 0, 0, 0x60040000 };
Battle D_800A5244 = { 0, 0, 0x60040000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
BattleList D_800A5274 = {
    0,
    { &D_800A5214, &D_800A5220, &D_800A522C, &D_800A5238,
      &D_800A5244, &D_800A5250, &D_800A525C, &D_800A5268 },
};
FieldBattles D_800A5298[] = {
    { 10, 0, 0, { &D_800A4ED8, &D_800A4F5C, &D_800A4FE0, &D_800A5064 } },
};
FieldBattles D_800A52B4[] = {
    { 29, 1, 0, { &D_800A50E8, &D_800A516C, &D_800A51F0, &D_800A5274 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x160, 0x100, 0x80, 0, 0x140, 0x1FF },
};
FieldTalk D_800A5340[] = {
    { NULL, NULL, 0x330 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5358[] = {
    { NULL, NULL, 0x330 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5370[] = {
    { NULL, NULL, 0x330 },
    { NULL, NULL, 0 },
};
u16 D_800A5388[] = { 0x6005, 1, 0xFFFF };
u16 D_800A5390[] = { 0x6006, 1, 0xFFFF };
u16 D_800A5398[] = { 0x6007, 1, 0xFFFF };
FieldActorEntry D_800A53A0 = { D_800A5388, D_800A5340, 0xB2, 4, 320, 736, 3 };
FieldActorEntry D_800A53B4 = { D_800A5390, D_800A5358, 0xB2, 4, 320, 736, 3 };
FieldActorEntry D_800A53C8 = { D_800A5398, D_800A5370, 0xB2, 4, 320, 736, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A53A0,
    &D_800A53B4,
    &D_800A53C8,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x226, 0x5E, 0x40E, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x222, 0x374, 0x9B, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
