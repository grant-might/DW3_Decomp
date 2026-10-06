#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x6B5
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x6C4
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x50500, 0x38700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x14;
    D_800990B4.music = 0x60500000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4EB0;
extern Battle D_800A4EBC;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4EEC;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F34;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A5078;
extern BattleList D_800A4EF8;
extern BattleList D_800A4F7C;
extern BattleList D_800A5000;
extern BattleList D_800A5084;
extern u16 D_800A5154[];
extern u16 D_800A5164[];
extern u16 D_800A516C[];
extern u16 D_800A5174[];
extern u16 D_800A5180[];
extern u16 D_800A5190[];
extern u16 D_800A5198[];
extern u16 D_800A51AC[];
extern u16 D_800A51B8[];
extern u16 D_800A51CC[];
extern u16 D_800A51D4[];
extern u16 D_800A51DC[];
extern u16 D_800A51E8[];
extern u16 D_800A51F8[];
extern u16 D_800A5204[];
extern u16 D_800A5218[];
extern u16 D_800A522C[];
extern u16 D_800A5234[];
extern u16 D_800A523C[];
extern u16 D_800A5244[];
extern u16 D_800A524C[];
extern u16 D_800A5254[];
extern u16 D_800A5260[];
extern u16 D_800A5378[];
extern FieldTalk D_800A5270[];
extern u16 D_800A5380[];
extern FieldTalk D_800A5288[];
extern u16 D_800A5394[];
extern FieldTalk D_800A52D0[];
extern u16 D_800A53A8[];
extern FieldTalk D_800A5318[];
extern u16 D_800A53B8[];
extern FieldTalk D_800A5348[];
extern u16 D_800A53C4[];
extern FieldTalk D_800A5360[];
extern FieldActorEntry D_800A53CC;
extern FieldActorEntry D_800A53E0;
extern FieldActorEntry D_800A53F4;
extern FieldActorEntry D_800A5408;
extern FieldActorEntry D_800A541C;
extern FieldActorEntry D_800A5430;

Battle D_800A4E98 = { 98, 3, 0x60080000 };
Battle D_800A4EA4 = { 98, 3, 0x60080000 };
Battle D_800A4EB0 = { 98, 3, 0x60080000 };
Battle D_800A4EBC = { 130, 3, 0x60080000 };
Battle D_800A4EC8 = { 130, 3, 0x60080000 };
Battle D_800A4ED4 = { 131, 3, 0x60080000 };
Battle D_800A4EE0 = { 131, 3, 0x60080000 };
Battle D_800A4EEC = { 131, 3, 0x60080000 };
BattleList D_800A4EF8 = {
    3,
    { &D_800A4E98, &D_800A4EA4, &D_800A4EB0, &D_800A4EBC,
      &D_800A4EC8, &D_800A4ED4, &D_800A4EE0, &D_800A4EEC },
};
Battle D_800A4F1C = { 0, 0, 0x60040000 };
Battle D_800A4F28 = { 0, 0, 0x60040000 };
Battle D_800A4F34 = { 0, 0, 0x60040000 };
Battle D_800A4F40 = { 0, 0, 0x60040000 };
Battle D_800A4F4C = { 0, 0, 0x60040000 };
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
Battle D_800A4F70 = { 0, 0, 0x60040000 };
BattleList D_800A4F7C = {
    0,
    { &D_800A4F1C, &D_800A4F28, &D_800A4F34, &D_800A4F40,
      &D_800A4F4C, &D_800A4F58, &D_800A4F64, &D_800A4F70 },
};
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
Battle D_800A4FB8 = { 0, 0, 0x60040000 };
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
BattleList D_800A5000 = {
    0,
    { &D_800A4FA0, &D_800A4FAC, &D_800A4FB8, &D_800A4FC4,
      &D_800A4FD0, &D_800A4FDC, &D_800A4FE8, &D_800A4FF4 },
};
Battle D_800A5024 = { 236, 3, 0x60080000 };
Battle D_800A5030 = { 284, 3, 0x600C0000 };
Battle D_800A503C = { 0, 0, 0x60040000 };
Battle D_800A5048 = { 333, 3, 0x60080000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
Battle D_800A5060 = { 0, 0, 0x60040000 };
Battle D_800A506C = { 175, 3, 0x60080000 };
Battle D_800A5078 = { 0, 0, 0x60040000 };
BattleList D_800A5084 = {
    0,
    { &D_800A5024, &D_800A5030, &D_800A503C, &D_800A5048,
      &D_800A5054, &D_800A5060, &D_800A506C, &D_800A5078 },
};
FieldBattles stageBattles[] = {
    { 97, 0, 0, { &D_800A4EF8, &D_800A4F7C, &D_800A5000, &D_800A5084 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x128, 0xD8, 0x28, 0x150, 0x1FF },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x146, 0xB0, 0x46, 0x170, 0x1FF },
};
u16 D_800A5154[] = { 0x24A, 1, 0x822C, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5164[] = { 0, 0, 0xFFFF };
u16 D_800A516C[] = { 0, 1, 0xFFFF };
u16 D_800A5174[] = { 0, 1, 0x7207, 0, 0xFFFF };
u16 D_800A5180[] = { 0x7207, 1, 0x7209, 0, 0, 1, 0xFFFF };
u16 D_800A5190[] = { 0x7634, 1, 0xFFFF };
u16 D_800A5198[] = { 0, 1, 0x7207, 1, 0x7209, 1, 0xE27, 0, 0xFFFF };
u16 D_800A51AC[] = { 0x7400, 1, 0xE27, 1, 0xFFFF };
u16 D_800A51B8[] = { 0, 1, 0x7207, 1, 0x7209, 1, 0xE27, 1, 0xFFFF };
u16 D_800A51CC[] = { 0, 0, 0xFFFF };
u16 D_800A51D4[] = { 0, 1, 0xFFFF };
u16 D_800A51DC[] = { 0, 1, 0x720A, 0, 0xFFFF };
u16 D_800A51E8[] = { 0, 1, 0x720A, 1, 0xE47, 0, 0xFFFF };
u16 D_800A51F8[] = { 0xE47, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5204[] = { 0, 1, 0x720A, 1, 0xE47, 1, 0x720C, 0, 0xFFFF };
u16 D_800A5218[] = { 0x720C, 1, 0, 1, 0x720A, 1, 0xE47, 1, 0xFFFF };
u16 D_800A522C[] = { 0x7834, 1, 0xFFFF };
u16 D_800A5234[] = { 0x11, 0, 0xFFFF };
u16 D_800A523C[] = { 0x10, 0, 0xFFFF };
u16 D_800A5244[] = { 0x11, 0, 0xFFFF };
u16 D_800A524C[] = { 0x10, 1, 0xFFFF };
u16 D_800A5254[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5260[] = { 0x24B, 1, 0x8246, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A5270[] = {
    { NULL, D_800A5154, 0x17D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5288[] = {
    { D_800A5164, D_800A516C, 0x244 },
    { D_800A5174, NULL, 0x245 },
    { D_800A5180, D_800A5190, 0x246 },
    { D_800A5198, D_800A51AC, 0x247 },
    { D_800A51B8, NULL, 0x248 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52D0[] = {
    { D_800A51CC, D_800A51D4, 0x24C },
    { D_800A51DC, NULL, 0x24E },
    { D_800A51E8, D_800A51F8, 0x24D },
    { D_800A5204, NULL, 0x248 },
    { D_800A5218, D_800A522C, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5318[] = {
    { D_800A5234, NULL, 0x39C },
    { D_800A523C, D_800A5244, 0x249 },
    { D_800A524C, D_800A5254, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5348[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5360[] = {
    { NULL, D_800A5260, 0x183 },
    { NULL, NULL, 0 },
};
u16 D_800A5378[] = { 0x24A, 0, 0xFFFF };
u16 D_800A5380[] = { 0x7019, 1, 0x8192, 1, 0x11, 0, 0x8014, 0, 0xFFFF };
u16 D_800A5394[] = { 0x8192, 1, 0x11, 0, 0x7019, 1, 0x8014, 1, 0xFFFF };
u16 D_800A53A8[] = { 0x7019, 1, 0x8192, 1, 0x11, 1, 0xFFFF };
u16 D_800A53B8[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A53C4[] = { 0x24B, 0, 0xFFFF };
FieldActorEntry D_800A53CC = { D_800A5378, D_800A5270, 0x21, 4, 1057, 961, 1 };
FieldActorEntry D_800A53E0 = { D_800A5380, D_800A5288, 0x45, 5, 784, 393, 7 };
FieldActorEntry D_800A53F4 = { D_800A5394, D_800A52D0, 0x45, 5, 784, 393, 7 };
FieldActorEntry D_800A5408 = { D_800A53A8, D_800A5318, 0x45, 5, 784, 393, 7 };
FieldActorEntry D_800A541C = { D_800A53B8, D_800A5348, 0x45, 5, 784, 393, 7 };
FieldActorEntry D_800A5430 = { D_800A53C4, D_800A5360, 0x4D, 6, 256, 561, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A53CC,
    &D_800A53E0,
    &D_800A53F4,
    &D_800A5408,
    &D_800A541C,
    &D_800A5430,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 1234, 165, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 1279, 187, 0, 0 },
    { 1, 0, 0x80, 2, 4, 0, 0, 0, 0, 0, 896, 149, 0, 0 },
    { 1, 0, 0x80, 2, 5, 0, 0, 0, 0, 0, 1239, 635, 0, 0 },
    { 1, 0, 0x40, 6, 3, 0, 0, 0, 0, 0, 125, 286, 0, 0 },
    { 1, 0, 0x40, 6, 3, 0, 0, 0, 0, 0, 1409, 823, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 1497, 247, 283, 0 },
    { 1, 0, 0x6C, 4, 1, 0, 0, 0, 0, 0, 920, 640, 699, 0 },
    { 1, 0, 0x57, 4, 2, 0, 0, 0, 0, 0, 1040, 220, 285, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 512, 512, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 432, 320, 320, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 496, 336, 336, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 720, 584, 584, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 936, 900, 900, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1136, 168, 168, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1328, 896, 896, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1568, 479, 479, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B3, 0x294, 0x1F0, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B6, 0xA8, 0x3FC, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B5, 0x90, 0xD0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 9, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 4, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x1E, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x12, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
