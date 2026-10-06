#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x617
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x627
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xF200, 0x12F00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x16;
    D_800990B4.music = 0x60580000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A5078;
extern Battle D_800A5084;
extern Battle D_800A5090;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50D8;
extern Battle D_800A50E4;
extern Battle D_800A50F0;
extern Battle D_800A50FC;
extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern BattleList D_800A4FAC;
extern BattleList D_800A5030;
extern BattleList D_800A50B4;
extern BattleList D_800A5138;
extern u16 D_800A5248[];
extern u16 D_800A5250[];
extern u16 D_800A525C[];
extern u16 D_800A5360[];
extern FieldTalk D_800A5264[];
extern u16 D_800A536C[];
extern FieldTalk D_800A527C[];
extern u16 D_800A5374[];
extern FieldTalk D_800A52A0[];
extern u16 D_800A537C[];
extern FieldTalk D_800A52B8[];
extern u16 D_800A5384[];
extern FieldTalk D_800A52D0[];
extern u16 D_800A538C[];
extern FieldTalk D_800A52E8[];
extern u16 D_800A5398[];
extern FieldTalk D_800A5300[];
extern u16 D_800A53A0[];
extern FieldTalk D_800A5318[];
extern u16 D_800A53A8[];
extern FieldTalk D_800A5330[];
extern u16 D_800A53B0[];
extern FieldTalk D_800A5348[];
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
extern s16 D_800A4E40[];

s16 D_800A4E40[] = {
    0x102, 2, 0x184, 0x74, 5,
    0x100, 0x25, 0x1A4, 0x67,
    0x101, 0x25, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x300, 0x1E,
    0x200, 0, 1, 0x25, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x25, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x25, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 7, 0x25, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 9, 0x25, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xA, 2, 1,
    0x301,
    0x300, 0x1E,
    0,
};
Battle D_800A4F4C = { 0, 0, 0x60040000 };
Battle D_800A4F58 = { 0, 0, 0x60040000 };
Battle D_800A4F64 = { 0, 0, 0x60040000 };
Battle D_800A4F70 = { 0, 0, 0x60040000 };
Battle D_800A4F7C = { 0, 0, 0x60040000 };
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
BattleList D_800A4FAC = {
    3,
    { &D_800A4F4C, &D_800A4F58, &D_800A4F64, &D_800A4F70,
      &D_800A4F7C, &D_800A4F88, &D_800A4F94, &D_800A4FA0 },
};
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
BattleList D_800A5030 = {
    0,
    { &D_800A4FD0, &D_800A4FDC, &D_800A4FE8, &D_800A4FF4,
      &D_800A5000, &D_800A500C, &D_800A5018, &D_800A5024 },
};
Battle D_800A5054 = { 0, 0, 0x60040000 };
Battle D_800A5060 = { 0, 0, 0x60040000 };
Battle D_800A506C = { 0, 0, 0x60040000 };
Battle D_800A5078 = { 0, 0, 0x60040000 };
Battle D_800A5084 = { 0, 0, 0x60040000 };
Battle D_800A5090 = { 0, 0, 0x60040000 };
Battle D_800A509C = { 0, 0, 0x60040000 };
Battle D_800A50A8 = { 0, 0, 0x60040000 };
BattleList D_800A50B4 = {
    0,
    { &D_800A5054, &D_800A5060, &D_800A506C, &D_800A5078,
      &D_800A5084, &D_800A5090, &D_800A509C, &D_800A50A8 },
};
Battle D_800A50D8 = { 0, 18, 0x60080000 };
Battle D_800A50E4 = { 0, 18, 0x600C0000 };
Battle D_800A50F0 = { 0, 0, 0x60040000 };
Battle D_800A50FC = { 0, 0, 0x60040000 };
Battle D_800A5108 = { 0, 0, 0x60040000 };
Battle D_800A5114 = { 0, 0, 0x60040000 };
Battle D_800A5120 = { 0, 0, 0x60040000 };
Battle D_800A512C = { 0, 0, 0x60040000 };
BattleList D_800A5138 = {
    0,
    { &D_800A50D8, &D_800A50E4, &D_800A50F0, &D_800A50FC,
      &D_800A5108, &D_800A5114, &D_800A5120, &D_800A512C },
};
FieldBattles stageBattles[] = {
    { 162, 0, 0, { &D_800A4FAC, &D_800A5030, &D_800A50B4, &D_800A5138 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x100, 0xB0, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x174, 0x168, 0xD0, 0x68, 0x170, 0x1FF },
    { 0x140, 0x100, 0x174, 0x128, 0xD0, 0x28, 0x150, 0x1FE },
    { 0x140, 0x100, 0x16C, 0x130, 0xB0, 0x30, 0x160, 0x1FE },
    { 0x140, 0x100, 0x174, 0x148, 0xD0, 0x48, 0x170, 0x1FE },
    { 0x140, 0x100, 0x16C, 0x150, 0xB0, 0x50, 0x150, 0x1FD },
};
u16 D_800A5248[] = { 0x1A34, 0, 0xFFFF };
u16 D_800A5250[] = { 0x1A34, 1, 0x9048, 1, 0xFFFF };
u16 D_800A525C[] = { 0x1A34, 1, 0xFFFF };
FieldTalk D_800A5264[] = {
    { NULL, NULL, 0x157 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A527C[] = {
    { D_800A5248, D_800A5250, 0x2DD },
    { D_800A525C, NULL, 0x323 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52A0[] = {
    { NULL, NULL, 0x154 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52B8[] = {
    { NULL, NULL, 0x153 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52D0[] = {
    { NULL, NULL, 0x159 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52E8[] = {
    { NULL, NULL, 0x158 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5300[] = {
    { NULL, NULL, 0x158 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5318[] = {
    { NULL, NULL, 0x158 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5330[] = {
    { NULL, NULL, 0x15B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5348[] = {
    { NULL, NULL, 0x156 },
    { NULL, NULL, 0 },
};
u16 D_800A5360[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A536C[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5374[] = { 0x701C, 1, 0xFFFF };
u16 D_800A537C[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5384[] = { 0x701C, 1, 0xFFFF };
u16 D_800A538C[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5398[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53A0[] = { 0x701D, 1, 0xFFFF };
u16 D_800A53A8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A53B0[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A53B8 = { D_800A5360, D_800A5264, 0x20, 4, 128, 196, 1 };
FieldActorEntry D_800A53CC = { D_800A536C, D_800A527C, 0x25, 5, 420, 103, 1 };
FieldActorEntry D_800A53E0 = { D_800A5374, D_800A52A0, 0x2D, 6, 305, 283, 1 };
FieldActorEntry D_800A53F4 = { D_800A537C, D_800A52B8, 0x2D, 6, 305, 283, 1 };
FieldActorEntry D_800A5408 = { D_800A5384, D_800A52D0, 0x39, 7, 420, 103, 1 };
FieldActorEntry D_800A541C = { D_800A538C, D_800A52E8, 0x9D, 8, 128, 196, 1 };
FieldActorEntry D_800A5430 = { D_800A5398, D_800A5300, 0x9D, 8, 128, 196, 1 };
FieldActorEntry D_800A5444 = { D_800A53A0, D_800A5318, 0x9D, 8, 128, 196, 1 };
FieldActorEntry D_800A5458 = { D_800A53A8, D_800A5330, 0x9E, 9, 420, 103, 1 };
FieldActorEntry D_800A546C = { D_800A53B0, D_800A5348, 0x9F, 0xA, 305, 283, 1 };
FieldActorEntry *stageActors[] = {
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0xFF, 6, 0x32, 2, 0, 2, 0xC, 0, 318, 266, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C4, 0x126, 0x96, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0xEE, 0x138, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0xDC, 0x1A0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 736, D_800A4E40, EVENT_TEXT(0x1C), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
