#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x64E
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x65E
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x42D00, 0x25F00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2F;
    D_800990B4.music = 0x60BC0000;
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
extern u16 D_800A516C[];
extern u16 D_800A5174[];
extern u16 D_800A5180[];
extern u16 D_800A5188[];
extern u16 D_800A5198[];
extern u16 D_800A51A8[];
extern u16 D_800A5318[];
extern FieldTalk D_800A51BC[];
extern u16 D_800A532C[];
extern FieldTalk D_800A51F8[];
extern u16 D_800A5338[];
extern FieldTalk D_800A5210[];
extern u16 D_800A5340[];
extern FieldTalk D_800A5228[];
extern u16 D_800A534C[];
extern FieldTalk D_800A5240[];
extern u16 D_800A5358[];
extern FieldTalk D_800A5258[];
extern u16 D_800A5360[];
extern FieldTalk D_800A5270[];
extern u16 D_800A536C[];
extern FieldTalk D_800A5288[];
extern u16 D_800A5374[];
extern FieldTalk D_800A52A0[];
extern u16 D_800A5380[];
extern FieldTalk D_800A52B8[];
extern u16 D_800A5388[];
extern FieldTalk D_800A52D0[];
extern u16 D_800A5394[];
extern FieldTalk D_800A52E8[];
extern u16 D_800A539C[];
extern FieldTalk D_800A5300[];
extern FieldActorEntry D_800A53A4;
extern FieldActorEntry D_800A53B8;
extern FieldActorEntry D_800A53CC;
extern FieldActorEntry D_800A53E0;
extern FieldActorEntry D_800A53F4;
extern FieldActorEntry D_800A5408;
extern FieldActorEntry D_800A541C;
extern FieldActorEntry D_800A5430;
extern FieldActorEntry D_800A5444;
extern FieldActorEntry D_800A5458;
extern FieldActorEntry D_800A546C;
extern FieldActorEntry D_800A5480;
extern FieldActorEntry D_800A5494;

Battle D_800A4E50 = { 163, 4, 0x60080000 };
Battle D_800A4E5C = { 163, 4, 0x60080000 };
Battle D_800A4E68 = { 163, 4, 0x60080000 };
Battle D_800A4E74 = { 163, 4, 0x60080000 };
Battle D_800A4E80 = { 137, 4, 0x60080000 };
Battle D_800A4E8C = { 137, 4, 0x60080000 };
Battle D_800A4E98 = { 137, 4, 0x60080000 };
Battle D_800A4EA4 = { 137, 4, 0x60080000 };
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
Battle D_800A5000 = { 333, 4, 0x60080000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 175, 4, 0x60080000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
FieldBattles stageBattles[] = {
    { 117, 0, 0, { &D_800A4EB0, &D_800A4F34, &D_800A4FB8, &D_800A503C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x19C, 0x11F, 0x170, 0x1F, 0x160, 0x1FF },
    { 0x180, 0x100, 0x1A4, 0x147, 0x190, 0x47, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x1C1, 0xD8, 0xC1, 0x160, 0x1FE },
    { 0x180, 0x100, 0x1A6, 0x11F, 0x198, 0x1F, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1AE, 0x125, 0x1B8, 0x25, 0x140, 0x1FD },
    { 0x180, 0x100, 0x1B6, 0x125, 0x1D8, 0x25, 0x150, 0x1FD },
    { 0x180, 0x100, 0x1AE, 0x145, 0x1B8, 0x45, 0x160, 0x1FD },
    { 0x180, 0x100, 0x1B6, 0x145, 0x1D8, 0x45, 0x170, 0x1FD },
    { 0x180, 0x100, 0x19C, 0x147, 0x170, 0x47, 0x140, 0x1FC },
};
u16 D_800A516C[] = { 0x868F, 1, 0xFFFF };
u16 D_800A5174[] = { 0x868F, 0, 0, 0, 0xFFFF };
u16 D_800A5180[] = { 0, 1, 0xFFFF };
u16 D_800A5188[] = {
#if VERSION_US
    0x868F, 0, 0, 1, 0x848B, 0, 0xFFFF,
#elif VERSION_EU
    0x848B, 0, 0x868F, 0, 0, 1, 0xFFFF,
#endif
};
u16 D_800A5198[] = { 0x868F, 0, 0, 1, 0x848B, 1, 0xFFFF };
u16 D_800A51A8[] = {
#if VERSION_US
    0x868F, 1, 0x868E, 0, 0x848B, 0, 0x7013, 1,
#elif VERSION_EU
    0x7013, 1, 0x868F, 1, 0x868E, 0, 0x848B, 0,
#endif
    0xFFFF,
};
FieldTalk D_800A51BC[] = {
    { D_800A516C, NULL, 0x302 },
    { D_800A5174, D_800A5180, 0x303 },
    { D_800A5188, NULL, 0x304 },
    { D_800A5198, D_800A51A8, 0x305 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F8[] = {
    { NULL, NULL, 0x288 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5210[] = {
    { NULL, NULL, 0x28E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5228[] = {
    { NULL, NULL, 0x28A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5240[] = {
    { NULL, NULL, 0x28C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5258[] = {
    { NULL, NULL, 0x28F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5270[] = {
    { NULL, NULL, 0x28B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5288[] = {
    { NULL, NULL, 0x28B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52A0[] = {
    { NULL, NULL, 0x289 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52B8[] = {
    { NULL, NULL, 0x289 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52D0[] = {
    { NULL, NULL, 0x28D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52E8[] = {
    { NULL, NULL, 0x28D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5300[] = {
    { NULL, NULL, 0x290 },
    { NULL, NULL, 0 },
};
u16 D_800A5318[] = { 0x7048, 1, 0x7050, 1, 0x868E, 1, 0x868F, 0, 0xFFFF };
u16 D_800A532C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5338[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5340[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A534C[] = {
#if VERSION_US
    0x6026, 1, 0x1A0A, 1, 0xFFFF,
#elif VERSION_EU
    0x1A0A, 1, 0x6026, 1, 0xFFFF,
#endif
};
u16 D_800A5358[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5360[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A536C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5374[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5380[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5388[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5394[] = { 0x701A, 1, 0xFFFF };
u16 D_800A539C[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A53A4 = { D_800A5318, D_800A51BC, 0x1F, 4, 255, 706, 7 };
FieldActorEntry D_800A53B8 = { D_800A532C, D_800A51F8, 0x2D, 5, 1214, 517, 1 };
FieldActorEntry D_800A53CC = { D_800A5338, D_800A5210, 0x2D, 5, 768, 369, 3 };
FieldActorEntry D_800A53E0 = { D_800A5340, D_800A5228, 0x30, 6, 1089, 234, 7 };
FieldActorEntry D_800A53F4 = { D_800A534C, D_800A5240, 0x31, 7, 465, 345, 1 };
FieldActorEntry D_800A5408 = { D_800A5358, D_800A5258, 0x42, 8, 463, 193, 1 };
FieldActorEntry D_800A541C = { D_800A5360, D_800A5270, 0x9D, 9, 1089, 234, 7 };
FieldActorEntry D_800A5430 = { D_800A536C, D_800A5288, 0x9D, 9, 1089, 234, 7 };
FieldActorEntry D_800A5444 = { D_800A5374, D_800A52A0, 0x9E, 0xA, 1214, 577, 1 };
FieldActorEntry D_800A5458 = { D_800A5380, D_800A52B8, 0x9E, 0xA, 1214, 517, 1 };
FieldActorEntry D_800A546C = { D_800A5388, D_800A52D0, 0x9F, 0xB, 465, 345, 1 };
FieldActorEntry D_800A5480 = { D_800A5394, D_800A52E8, 0x9F, 0xB, 465, 345, 1 };
FieldActorEntry D_800A5494 = { D_800A539C, D_800A5300, 0xB4, 0xC, 1089, 234, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A53A4,
    &D_800A53B8,
    &D_800A53CC,
    &D_800A53E0,
    &D_800A53F4,
    &D_800A5408,
    &D_800A541C,
    &D_800A5430,
    &D_800A5444,
    &D_800A5458,
    &D_800A546C,
    &D_800A5480,
    &D_800A5494,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 1, 6, 0, 603, 223, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 1, 6, 0, 952, 485, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 6, 0, 567, 357, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 6, 0, 604, 375, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 6, 0, 857, 450, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 529, 660, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 198, 395, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 221, 591, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 1084, 623, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 140, 499, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 476, 616, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 569, 552, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 827, 661, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 408, 122, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 479, 678, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 772, 301, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 869, 528, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 919, 263, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 929, 414, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 1166, 732, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 6, 0, 1218, 758, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 6, 0, 986, 299, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 6, 0, 1025, 319, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 6, 0, 1195, 732, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 1, 6, 0, 522, 632, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 1, 6, 0, 599, 379, 0, 0 },
    { 1, 0, 0xC4, 4, 0, 0, 0, 0, 0, 0, 413, 523, 715, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 699, 190, 233, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 138, 383, 410, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 161, 328, 364, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 542, 196, 217, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 208, 311, 311, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 672, 719, 719, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 688, 455, 455, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 720, 743, 743, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 736, 479, 479, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 864, 175, 175, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 928, 351, 351, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 944, 167, 167, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2CE, 0x390, 0x1E8, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C9, 0x80, 0x90, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D0, 0x390, 0x118, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x20F, 0xF8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x21F, 0x190, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x34F, 0x106, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x35F, 0x16F, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x440, 0x161, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x430, 0x1C8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x3EF, 0x2C9, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x3E1, 0x32F, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x150, 0x258, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x15F, 0x2BE, 0, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 5, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0xB, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 3, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x17, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
