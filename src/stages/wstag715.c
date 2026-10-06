#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x726
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x736
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x36300, 0x1C700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3E;
    D_800990B4.music = 0x60F80000;
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
extern u16 D_800A524C[];
extern FieldTalk D_800A512C[];
extern u16 D_800A5254[];
extern FieldTalk D_800A5144[];
extern u16 D_800A525C[];
extern FieldTalk D_800A515C[];
extern u16 D_800A5264[];
extern FieldTalk D_800A5174[];
extern u16 D_800A526C[];
extern FieldTalk D_800A518C[];
extern u16 D_800A5274[];
extern FieldTalk D_800A51A4[];
extern u16 D_800A527C[];
extern FieldTalk D_800A51BC[];
extern u16 D_800A5284[];
extern FieldTalk D_800A51D4[];
extern u16 D_800A528C[];
extern FieldTalk D_800A51EC[];
extern u16 D_800A5294[];
extern FieldTalk D_800A5204[];
extern u16 D_800A529C[];
extern FieldTalk D_800A521C[];
extern u16 D_800A52A4[];
extern FieldTalk D_800A5234[];
extern FieldActorEntry D_800A52AC;
extern FieldActorEntry D_800A52C0;
extern FieldActorEntry D_800A52D4;
extern FieldActorEntry D_800A52E8;
extern FieldActorEntry D_800A52FC;
extern FieldActorEntry D_800A5310;
extern FieldActorEntry D_800A5324;
extern FieldActorEntry D_800A5338;
extern FieldActorEntry D_800A534C;
extern FieldActorEntry D_800A5360;
extern FieldActorEntry D_800A5374;
extern FieldActorEntry D_800A5388;

Battle D_800A4E50 = { 115, 14, 0x60080000 };
Battle D_800A4E5C = { 115, 14, 0x60080000 };
Battle D_800A4E68 = { 115, 14, 0x60080000 };
Battle D_800A4E74 = { 115, 14, 0x60080000 };
Battle D_800A4E80 = { 115, 14, 0x60080000 };
Battle D_800A4E8C = { 115, 14, 0x60080000 };
Battle D_800A4E98 = { 115, 14, 0x60080000 };
Battle D_800A4EA4 = { 115, 14, 0x60080000 };
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
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 333, 14, 0x60080000 };
Battle D_800A500C = { 332, 14, 0x60080000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 114, 14, 0x60080000 };
Battle D_800A5030 = { 179, 14, 0x60080000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
FieldBattles stageBattles[] = {
    { 85, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x168, 0x1A5, 0xA0, 0xA5, 0x160, 0x1FF },
    { 0x140, 0x100, 0x170, 0x1A5, 0xC0, 0xA5, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15C, 0x1A8, 0x70, 0xA8, 0x150, 0x1FE },
    { 0x140, 0x100, 0x140, 0x1B1, 0, 0xB1, 0x160, 0x1FE },
    { 0x140, 0x100, 0x148, 0x1B1, 0x20, 0xB1, 0x170, 0x1FE },
};
FieldTalk D_800A512C[] = {
    { NULL, NULL, 0x213 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5144[] = {
    { NULL, NULL, 0x216 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A515C[] = {
    { NULL, NULL, 0x214 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5174[] = {
    { NULL, NULL, 0x217 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A518C[] = {
    { NULL, NULL, 0x218 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51A4[] = {
    { NULL, NULL, 0x21A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51BC[] = {
    { NULL, NULL, 0x21B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51D4[] = {
    { NULL, NULL, 0x21E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51EC[] = {
    { NULL, NULL, 0x21D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5204[] = {
    { NULL, NULL, 0x21C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A521C[] = {
    { NULL, NULL, 0x215 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5234[] = {
    { NULL, NULL, 0x219 },
    { NULL, NULL, 0 },
};
u16 D_800A524C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5254[] = { 0x602B, 1, 0xFFFF };
u16 D_800A525C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5264[] = { 0x7019, 1, 0xFFFF };
u16 D_800A526C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5274[] = { 0x602B, 1, 0xFFFF };
u16 D_800A527C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5284[] = { 0x602B, 1, 0xFFFF };
u16 D_800A528C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5294[] = { 0x6026, 1, 0xFFFF };
u16 D_800A529C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A52A4[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A52AC = { D_800A524C, D_800A512C, 0x31, 4, 433, 393, 7 };
FieldActorEntry D_800A52C0 = { D_800A5254, D_800A5144, 0x31, 4, 256, 431, 7 };
FieldActorEntry D_800A52D4 = { D_800A525C, D_800A515C, 0x31, 4, 433, 393, 7 };
FieldActorEntry D_800A52E8 = { D_800A5264, D_800A5174, 0x35, 5, 272, 209, 5 };
FieldActorEntry D_800A52FC = { D_800A526C, D_800A518C, 0x35, 5, 272, 209, 5 };
FieldActorEntry D_800A5310 = { D_800A5274, D_800A51A4, 0x35, 5, 512, 519, 1 };
FieldActorEntry D_800A5324 = { D_800A527C, D_800A51BC, 0x40, 6, 529, 392, 1 };
FieldActorEntry D_800A5338 = { D_800A5284, D_800A51D4, 0x40, 6, 272, 209, 7 };
FieldActorEntry D_800A534C = { D_800A528C, D_800A51EC, 0x40, 6, 529, 392, 1 };
FieldActorEntry D_800A5360 = { D_800A5294, D_800A5204, 0x40, 6, 529, 392, 1 };
FieldActorEntry D_800A5374 = { D_800A529C, D_800A521C, 0x9D, 7, 433, 393, 7 };
FieldActorEntry D_800A5388 = { D_800A52A4, D_800A5234, 0x9E, 8, 272, 209, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A52AC,
    &D_800A52C0,
    &D_800A52D4,
    &D_800A52E8,
    &D_800A52FC,
    &D_800A5310,
    &D_800A5324,
    &D_800A5338,
    &D_800A534C,
    &D_800A5360,
    &D_800A5374,
    &D_800A5388,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 49, 138, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 128, 512, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 222, 441, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 600, 352, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 615, 376, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x38, 4, 0, 640, 368, 0, 0 },
    { 1, 0, 0x40, 2, 0x39, 2, 0, 5, 6, 0, 21, 133, 0, 0 },
    { 1, 0, 0x40, 2, 3, 1, 3, 8, 4, 0, 801, 513, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x38, 4, 0, 243, 53, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x38, 4, 0, 270, 56, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 5, 6, 0, 234, 51, 0, 0 },
    { 1, 0, 0x40, 4, 0x3B, 0, 0, 0, 0, 0, 406, 413, 478, 0 },
    { 1, 0, 0x40, 4, 0x3C, 0, 0, 0, 0, 0, 360, 401, 458, 0 },
    { 1, 0, 0x40, 4, 0x46, 1, 0x46, 0x51, 0xC, 0, 381, 406, 458, 0 },
    { 1, 0, 0x40, 4, 0x3E, 0, 0, 0, 0, 0, 406, 388, 438, 0 },
    { 1, 0, 0x40, 4, 0x3F, 0, 0, 0, 0, 0, 433, 401, 458, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 128, 120, 175, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 235, 368, 374, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 665, 307, 322, 0 },
    { 1, 0, 0x4F, 4, 9, 0, 0, 0, 0, 0, 65, 377, 445, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 304, 152, 152, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 352, 128, 128, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 592, 199, 199, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 656, 183, 183, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 704, 207, 207, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 736, 239, 239, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 784, 263, 263, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x265, 0xB4, 0x98, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x267, 0x298, 0x134, 3, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 6, 1 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E3, 0x380, 0x70, 1, 0, 5, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x170, 0x98, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x180, 0xE0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x48, 0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x48, 0xFFDC, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFC8, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
