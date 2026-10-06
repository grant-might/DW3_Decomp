#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D4C(void) {
    FLAGS_00.applyAction(0x7C16, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x2A1
#define STAGE_ARCHIVE 0x315
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x2B0
#define STAGE_ARCHIVE 0x324
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x25900, 0x1AB00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x41;
    D_800990B4.music = 0x61040000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4F18;
extern Battle D_800A4F24;
extern Battle D_800A4F30;
extern Battle D_800A4F3C;
extern Battle D_800A4F48;
extern Battle D_800A4F54;
extern Battle D_800A4F60;
extern Battle D_800A4F6C;
extern Battle D_800A4F9C;
extern Battle D_800A4FA8;
extern Battle D_800A4FB4;
extern Battle D_800A4FC0;
extern Battle D_800A4FCC;
extern Battle D_800A4FD8;
extern Battle D_800A4FE4;
extern Battle D_800A4FF0;
extern Battle D_800A5020;
extern Battle D_800A502C;
extern Battle D_800A5038;
extern Battle D_800A5044;
extern Battle D_800A5050;
extern Battle D_800A505C;
extern Battle D_800A5068;
extern Battle D_800A5074;
extern Battle D_800A50A4;
extern Battle D_800A50B0;
extern Battle D_800A50BC;
extern Battle D_800A50C8;
extern Battle D_800A50D4;
extern Battle D_800A50E0;
extern Battle D_800A50EC;
extern Battle D_800A50F8;
extern BattleList D_800A4F78;
extern BattleList D_800A4FFC;
extern BattleList D_800A5080;
extern BattleList D_800A5104;
extern u16 D_800A51E4[];
extern u16 D_800A51EC[];
extern u16 D_800A51F4[];
extern FieldTalk D_800A5204[];
extern FieldTalk D_800A521C[];
extern u16 D_800A5264[];
extern FieldTalk D_800A5234[];
extern u16 D_800A526C[];
extern FieldTalk D_800A524C[];
extern FieldActorEntry D_800A5278;
extern FieldActorEntry D_800A528C;
extern FieldActorEntry D_800A52A0;
extern FieldActorEntry D_800A52B4;
extern s16 D_800A4EA8[];

s16 D_800A4EA8[] = {
    0x102, 2, 0x117, 0x133, 3,
    0x100, 0x15, 0xF7, 0x123,
    0x101, 0x15, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x24,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 7,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 7,
    0x300, 0x5A,
    0x304, 0xC14, 0, 0, 0,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x37\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x6004\n");
#endif
Battle D_800A4F18 = { 148, 3, 0x60080000 };
Battle D_800A4F24 = { 148, 3, 0x60080000 };
Battle D_800A4F30 = { 148, 3, 0x60080000 };
Battle D_800A4F3C = { 148, 3, 0x60080000 };
Battle D_800A4F48 = { 154, 3, 0x60080000 };
Battle D_800A4F54 = { 154, 3, 0x60080000 };
Battle D_800A4F60 = { 154, 3, 0x60080000 };
Battle D_800A4F6C = { 154, 3, 0x60080000 };
BattleList D_800A4F78 = {
    3,
    { &D_800A4F18, &D_800A4F24, &D_800A4F30, &D_800A4F3C,
      &D_800A4F48, &D_800A4F54, &D_800A4F60, &D_800A4F6C },
};
Battle D_800A4F9C = { 148, 8, 0x60080000 };
Battle D_800A4FA8 = { 148, 8, 0x60080000 };
Battle D_800A4FB4 = { 148, 8, 0x60080000 };
Battle D_800A4FC0 = { 148, 8, 0x60080000 };
Battle D_800A4FCC = { 154, 8, 0x60080000 };
Battle D_800A4FD8 = { 154, 8, 0x60080000 };
Battle D_800A4FE4 = { 154, 8, 0x60080000 };
Battle D_800A4FF0 = { 154, 8, 0x60080000 };
BattleList D_800A4FFC = {
    3,
    { &D_800A4F9C, &D_800A4FA8, &D_800A4FB4, &D_800A4FC0,
      &D_800A4FCC, &D_800A4FD8, &D_800A4FE4, &D_800A4FF0 },
};
Battle D_800A5020 = { 0, 0, 0x60040000 };
Battle D_800A502C = { 0, 0, 0x60040000 };
Battle D_800A5038 = { 0, 0, 0x60040000 };
Battle D_800A5044 = { 0, 0, 0x60040000 };
Battle D_800A5050 = { 0, 0, 0x60040000 };
Battle D_800A505C = { 0, 0, 0x60040000 };
Battle D_800A5068 = { 0, 0, 0x60040000 };
Battle D_800A5074 = { 0, 0, 0x60040000 };
BattleList D_800A5080 = {
    0,
    { &D_800A5020, &D_800A502C, &D_800A5038, &D_800A5044,
      &D_800A5050, &D_800A505C, &D_800A5068, &D_800A5074 },
};
Battle D_800A50A4 = { 0, 0, 0x60040000 };
Battle D_800A50B0 = { 0, 0, 0x60040000 };
Battle D_800A50BC = { 0, 0, 0x60040000 };
Battle D_800A50C8 = { 0, 0, 0x60040000 };
Battle D_800A50D4 = { 330, 8, 0x60080000 };
Battle D_800A50E0 = { 0, 0, 0x60040000 };
Battle D_800A50EC = { 0, 0, 0x60040000 };
Battle D_800A50F8 = { 61, 8, 0x60080000 };
BattleList D_800A5104 = {
    0,
    { &D_800A50A4, &D_800A50B0, &D_800A50BC, &D_800A50C8,
      &D_800A50D4, &D_800A50E0, &D_800A50EC, &D_800A50F8 },
};
FieldBattles stageBattles[] = {
    { 35, 0, 0, { &D_800A4F78, &D_800A4FFC, &D_800A5080, &D_800A5104 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x19D, 0xD8, 0x9D, 0x160, 0x1FF },
    { 0x1C0, 0x100, 0x1EA, 0x176, 0x2A8, 0x76, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x1BD, 0xD8, 0xBD, 0x150, 0x1FE },
    { 0x140, 0x100, 0x176, 0x175, 0xD8, 0x75, 0x160, 0x1FE },
};
u16 D_800A51E4[] = { 0x7A30, 1, 0xFFFF };
u16 D_800A51EC[] = { 0x9065, 1, 0xFFFF };
u16 D_800A51F4[] = { 0x229, 1, 0x8236, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A5204[] = {
    { NULL, D_800A51E4, 0x309 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A521C[] = {
    { NULL, D_800A51EC, 0x168 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5234[] = {
    { NULL, D_800A51F4, 0x26E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A524C[] = {
    { NULL, NULL, 0x333 },
    { NULL, NULL, 0 },
};
u16 D_800A5264[] = { 0x229, 0, 0xFFFF };
u16 D_800A526C[] = { 0x7016, 1, 0x6012, 0, 0xFFFF };
FieldActorEntry D_800A5278 = { NULL, D_800A5204, 0x14, 4, 450, 368, 1 };
FieldActorEntry D_800A528C = { NULL, D_800A521C, 0x15, 5, 247, 291, 7 };
FieldActorEntry D_800A52A0 = { D_800A5264, D_800A5234, 0x21, 6, 502, 546, 1 };
FieldActorEntry D_800A52B4 = { D_800A526C, D_800A524C, 0x65, 7, 608, 240, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A5278,
    &D_800A528C,
    &D_800A52A0,
    &D_800A52B4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 410, 231, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 554, 520, 0, 0 },
    { 1, 0, 0x80, 2, 7, 0, 0, 0, 0, 0, 0, 384, 0, 0 },
    { 1, 0, 0x80, 2, 8, 0, 0, 0, 0, 0, 384, 384, 0, 0 },
    { 1, 0, 0x70, 2, 9, 0, 0, 0, 0, 0, 20, 512, 0, 0 },
    { 1, 0, 0x78, 2, 0xA, 0, 0, 0, 0, 0, 264, 523, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 94, 473, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 254, 516, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 367, 431, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 386, 432, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 160, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 298, 481, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 268, 346, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 347, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 155, 525, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 197, 568, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 208, 580, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 124, 412, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 201, 372, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 226, 530, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 291, 355, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 309, 520, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 419, 451, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x49, 6, 0, 204, 396, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4A, 1, 0x4A, 0x4D, 6, 0, 213, 360, 0, 0 },
    { 1, 0, 0x68, 0xA, 0x4E, 2, 0, 2, 6, 0, 181, 376, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 584, 137, 169, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x248, 0x610, 0x240, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24A, 0x80, 0x178, 7, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 5, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC8, 0x3C, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x40, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E2, 0xB0, 0x148, 7, 0, 5, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1459, D_800A4EA8, EVENT_TEXT(0x26), NULL, func_800A4D4C },
    { -1, NULL, 0, NULL, NULL },
};
