#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF0
#define STAGE_FILE 0x738
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define STAGE_FILE 0x748
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x13B00, 0x1B900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 6;
    D_800990B4.music = 0x60180000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4E38;
extern Battle D_800A4E44;
extern Battle D_800A4E50;
extern Battle D_800A4E5C;
extern Battle D_800A4E68;
extern Battle D_800A4E74;
extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4EBC;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4EE0;
extern Battle D_800A4EEC;
extern Battle D_800A4EF8;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern BattleList D_800A4E98;
extern BattleList D_800A4F1C;
extern BattleList D_800A4FA0;
extern BattleList D_800A5024;
extern u16 D_800A5154[];
extern u16 D_800A5164[];
extern u16 D_800A5174[];
extern u16 D_800A5184[];
extern u16 D_800A5190[];
extern u16 D_800A519C[];
extern u16 D_800A51A8[];
extern u16 D_800A51B4[];
extern u16 D_800A51C0[];
extern u16 D_800A52A4[];
extern FieldTalk D_800A51CC[];
extern u16 D_800A52AC[];
extern FieldTalk D_800A51E4[];
extern u16 D_800A52B4[];
extern FieldTalk D_800A51FC[];
extern u16 D_800A52BC[];
extern FieldTalk D_800A5214[];
extern u16 D_800A52C8[];
extern FieldTalk D_800A522C[];
extern u16 D_800A52D4[];
extern FieldTalk D_800A5244[];
extern u16 D_800A52E0[];
extern FieldTalk D_800A525C[];
extern u16 D_800A52EC[];
extern FieldTalk D_800A5274[];
extern u16 D_800A52F8[];
extern FieldTalk D_800A528C[];
extern FieldActorEntry D_800A5304;
extern FieldActorEntry D_800A5318;
extern FieldActorEntry D_800A532C;
extern FieldActorEntry D_800A5340;
extern FieldActorEntry D_800A5354;
extern FieldActorEntry D_800A5368;
extern FieldActorEntry D_800A537C;
extern FieldActorEntry D_800A5390;
extern FieldActorEntry D_800A53A4;

Battle D_800A4E38 = { 0, 0, 0x60040000 };
Battle D_800A4E44 = { 0, 0, 0x60040000 };
Battle D_800A4E50 = { 0, 0, 0x60040000 };
Battle D_800A4E5C = { 0, 0, 0x60040000 };
Battle D_800A4E68 = { 0, 0, 0x60040000 };
Battle D_800A4E74 = { 0, 0, 0x60040000 };
Battle D_800A4E80 = { 0, 0, 0x60040000 };
Battle D_800A4E8C = { 0, 0, 0x60040000 };
BattleList D_800A4E98 = {
    0,
    { &D_800A4E38, &D_800A4E44, &D_800A4E50, &D_800A4E5C,
      &D_800A4E68, &D_800A4E74, &D_800A4E80, &D_800A4E8C },
};
Battle D_800A4EBC = { 0, 0, 0x60040000 };
Battle D_800A4EC8 = { 0, 0, 0x60040000 };
Battle D_800A4ED4 = { 0, 0, 0x60040000 };
Battle D_800A4EE0 = { 0, 0, 0x60040000 };
Battle D_800A4EEC = { 0, 0, 0x60040000 };
Battle D_800A4EF8 = { 0, 0, 0x60040000 };
Battle D_800A4F04 = { 0, 0, 0x60040000 };
Battle D_800A4F10 = { 0, 0, 0x60040000 };
BattleList D_800A4F1C = {
    0,
    { &D_800A4EBC, &D_800A4EC8, &D_800A4ED4, &D_800A4EE0,
      &D_800A4EEC, &D_800A4EF8, &D_800A4F04, &D_800A4F10 },
};
Battle D_800A4F40 = { 0, 0, 0x60040000 };
Battle D_800A4F4C = { 0, 0, 0x60040000 };
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
Battle D_800A4F70 = { 0, 0, 0x60040000 };
Battle D_800A4F7C = { 0, 0, 0x60040000 };
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
BattleList D_800A4FA0 = {
    0,
    { &D_800A4F40, &D_800A4F4C, &D_800A4F58, &D_800A4F64,
      &D_800A4F70, &D_800A4F7C, &D_800A4F88, &D_800A4F94 },
};
Battle D_800A4FC4 = { 192, 12, 0x60080000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
BattleList D_800A5024 = {
    0,
    { &D_800A4FC4, &D_800A4FD0, &D_800A4FDC, &D_800A4FE8,
      &D_800A4FF4, &D_800A5000, &D_800A500C, &D_800A5018 },
};
FieldBattles stageBattles[] = {
    { 138, 0, 0, { &D_800A4E98, &D_800A4F1C, &D_800A4FA0, &D_800A5024 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x175, 0xE0, 0x75, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1B8, 0x100, 0x1E0, 0, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1A8, 0x118, 0x1A0, 0x18, 0x170, 0x1FD },
    { 0x140, 0x100, 0x170, 0x155, 0xC0, 0x55, 0x170, 0x1FC },
    { 0x140, 0x100, 0x170, 0x17D, 0xC0, 0x7D, 0x150, 0x1FB },
    { 0x140, 0x100, 0x158, 0x18E, 0x60, 0x8E, 0x160, 0x1FB },
    { 0x140, 0x100, 0x172, 0x1A5, 0xC8, 0xA5, 0x170, 0x1FB },
    { 0x140, 0x100, 0x172, 0x1CD, 0xC8, 0xCD, 0x150, 0x1FA },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x160, 0x1FA },
};
u16 D_800A5154[] = { 0x211, 1, 0x822B, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5164[] = { 0x708B, 1, 0x212, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5174[] = { 0x213, 1, 0x8246, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5184[] = { 0x7400, 1, 0xC14, 1, 0xFFFF };
u16 D_800A5190[] = { 0x7400, 1, 0xC15, 1, 0xFFFF };
u16 D_800A519C[] = { 0x7400, 1, 0xC16, 1, 0xFFFF };
u16 D_800A51A8[] = { 0x7400, 1, 0xC15, 1, 0xFFFF };
u16 D_800A51B4[] = { 0x7400, 1, 0xC17, 1, 0xFFFF };
u16 D_800A51C0[] = { 0x7400, 1, 0xC18, 1, 0xFFFF };
FieldTalk D_800A51CC[] = {
    { NULL, D_800A5154, 0x2B6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51E4[] = {
    { NULL, D_800A5164, 0x489 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51FC[] = {
    { NULL, D_800A5174, 0x450 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5214[] = {
    { NULL, D_800A5184, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A522C[] = {
    { NULL, D_800A5190, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5244[] = {
    { NULL, D_800A519C, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A525C[] = {
    { NULL, D_800A51A8, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5274[] = {
    { NULL, D_800A51B4, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A528C[] = {
    { NULL, D_800A51C0, 0xA9 },
    { NULL, NULL, 0 },
};
u16 D_800A52A4[] = { 0x211, 0, 0xFFFF };
u16 D_800A52AC[] = { 0x212, 0, 0xFFFF };
u16 D_800A52B4[] = { 0x213, 0, 0xFFFF };
u16 D_800A52BC[] = { 0x6016, 1, 0xC14, 0, 0xFFFF };
u16 D_800A52C8[] = { 0x6016, 1, 0xC15, 0, 0xFFFF };
u16 D_800A52D4[] = { 0x6016, 1, 0xC16, 0, 0xFFFF };
u16 D_800A52E0[] = { 0x6016, 1, 0xC15, 0, 0xFFFF };
u16 D_800A52EC[] = { 0x6016, 1, 0xC17, 0, 0xFFFF };
u16 D_800A52F8[] = { 0x6016, 1, 0xC18, 0, 0xFFFF };
FieldActorEntry D_800A5304 = { D_800A52A4, D_800A51CC, 0x21, 4, 144, 647, 1 };
FieldActorEntry D_800A5318 = { D_800A52AC, D_800A51E4, 0x4D, 5, 209, 201, 1 };
FieldActorEntry D_800A532C = { D_800A52B4, D_800A51FC, 0x4E, 6, 768, 490, 1 };
FieldActorEntry D_800A5340 = { D_800A52BC, D_800A5214, 0x132, 7, 236, 720, 1 };
FieldActorEntry D_800A5354 = { D_800A52C8, D_800A522C, 0x133, 8, 419, 666, 1 };
FieldActorEntry D_800A5368 = { D_800A52D4, D_800A5244, 0x134, 9, 377, 310, 7 };
FieldActorEntry D_800A537C = { D_800A52E0, D_800A525C, 0x135, 0xA, 446, 679, 1 };
FieldActorEntry D_800A5390 = { D_800A52EC, D_800A5274, 0x136, 0xB, 736, 233, 1 };
FieldActorEntry D_800A53A4 = { D_800A52F8, D_800A528C, 0x137, 0xC, 593, 608, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5304,
    &D_800A5318,
    &D_800A532C,
    &D_800A5340,
    &D_800A5354,
    &D_800A5368,
    &D_800A537C,
    &D_800A5390,
    &D_800A53A4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 4, 0, 191, 124, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 4, 0, 383, 219, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 4, 0, 735, 142, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 4, 0, 807, 178, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 4, 0, 855, 202, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 4, 0, 927, 238, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 3, 4, 0, 492, 156, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 3, 4, 0, 70, 458, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 3, 4, 0, 110, 478, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 3, 4, 0, 150, 498, 0, 0 },
    { 1, 0, 0x40, 2, 0x35, 2, 0, 3, 4, 0, 380, 474, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 3, 4, 0, 584, 338, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 2, 0, 0xB, 4, 0, 569, 365, 0, 0 },
    { 1, 0, 0x4E, 2, 5, 0, 0, 0, 0, 0, 640, 434, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 704, 448, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 336, 602, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 0xB, 4, 0, 702, 441, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 0xB, 4, 0, 838, 509, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 737, 176, 214, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 392, 265, 292, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 419, 258, 304, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 544, 550, 583, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 185, 681, 707, 0 },
    { 1, 0, 0x60, 4, 7, 0, 0, 0, 0, 0, 704, 89, 176, 0 },
    { 1, 0, 0x60, 4, 8, 0, 0, 0, 0, 0, 512, 89, 174, 0 },
    { 1, 0, 0x48, 4, 9, 0, 0, 0, 0, 0, 233, 359, 422, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0x703F, 1 }, { 0xFFFF, 0 } }, 1, 0x21B, 0x338, 0x21C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x215, 0x78, 0x124, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x19E, 0x1C0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x1AE, 0x248, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
