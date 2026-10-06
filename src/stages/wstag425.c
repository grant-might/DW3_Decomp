#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xD4
#define STAGE_FILE 0x245
#define STAGE_FILE_8 0x23D
#define STAGE_ARCHIVE 0x321
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define STAGE_FILE 0x254
#define STAGE_FILE_8 0x24C
#define STAGE_ARCHIVE 0x330
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE_8;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x1A200, 0x17A00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F0C[];
extern u16 D_800A4F14[];
extern u16 D_800A4F1C[];
extern u16 D_800A4F24[];
extern u16 D_800A4F2C[];
extern u16 D_800A4F34[];
extern u16 D_800A4F3C[];
extern u16 D_800A4F44[];
extern u16 D_800A4F4C[];
extern u16 D_800A4F54[];
extern u16 D_800A4F5C[];
extern u16 D_800A4F64[];
extern u16 D_800A4F6C[];
extern u16 D_800A4F74[];
extern u16 D_800A4F80[];
extern u16 D_800A4F88[];
extern u16 D_800A4F94[];
extern u16 D_800A4F9C[];
extern u16 D_800A4FA8[];
extern u16 D_800A4FB0[];
extern u16 D_800A4FB8[];
extern u16 D_800A4FC0[];
extern u16 D_800A4FC8[];
extern u16 D_800A4FD0[];
extern u16 D_800A4FD8[];
extern u16 D_800A4FE0[];
extern u16 D_800A4FE8[];
extern u16 D_800A4FF0[];
extern u16 D_800A4FFC[];
extern u16 D_800A5004[];
extern u16 D_800A500C[];
extern u16 D_800A5014[];
extern u16 D_800A501C[];
extern u16 D_800A5024[];
extern u16 D_800A502C[];
extern FieldTalk D_800A5034[];
extern FieldTalk D_800A5058[];
extern FieldTalk D_800A507C[];
extern u16 D_800A5268[];
extern FieldTalk D_800A50A0[];
extern u16 D_800A5270[];
extern FieldTalk D_800A50B8[];
extern u16 D_800A5278[];
extern FieldTalk D_800A50D0[];
extern u16 D_800A5280[];
extern FieldTalk D_800A50E8[];
extern u16 D_800A5288[];
extern FieldTalk D_800A5100[];
extern u16 D_800A5290[];
extern FieldTalk D_800A5118[];
extern u16 D_800A5298[];
extern FieldTalk D_800A5130[];
extern u16 D_800A52A0[];
extern FieldTalk D_800A5148[];
extern u16 D_800A52A8[];
extern FieldTalk D_800A5160[];
extern u16 D_800A52B0[];
extern FieldTalk D_800A5178[];
extern u16 D_800A52B8[];
extern FieldTalk D_800A5190[];
extern u16 D_800A52C8[];
extern FieldTalk D_800A51B4[];
extern u16 D_800A52D0[];
extern FieldTalk D_800A51CC[];
extern u16 D_800A52D8[];
extern FieldTalk D_800A5250[];
extern FieldActorEntry D_800A52E0;
extern FieldActorEntry D_800A52F4;
extern FieldActorEntry D_800A5308;
extern FieldActorEntry D_800A531C;
extern FieldActorEntry D_800A5330;
extern FieldActorEntry D_800A5344;
extern FieldActorEntry D_800A5358;
extern FieldActorEntry D_800A536C;
extern FieldActorEntry D_800A5380;
extern FieldActorEntry D_800A5394;
extern FieldActorEntry D_800A53A8;
extern FieldActorEntry D_800A53BC;
extern FieldActorEntry D_800A53D0;
extern FieldActorEntry D_800A53E4;
extern FieldActorEntry D_800A53F8;
extern FieldActorEntry D_800A540C;
extern FieldActorEntry D_800A5420;
extern FieldActorEntry D_800A5434;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x15C, 0x1A7, 0x70, 0xA7, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x173, 0xD8, 0x73, 0x170, 0x1FE },
    { 0x140, 0x100, 0x160, 0x147, 0x80, 0x47, 0x170, 0x1FD },
    { 0x180, 0x100, 0x190, 0x11A, 0x140, 0x1A, 0x170, 0x1FC },
    { 0x180, 0x100, 0x198, 0x11A, 0x160, 0x1A, 0x170, 0x1FB },
    { 0x180, 0x100, 0x180, 0x11B, 0x100, 0x1B, 0x170, 0x1FA },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x170, 0x1F9 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A4F0C[] = { 0x1A08, 0, 0xFFFF };
u16 D_800A4F14[] = { 0x1A08, 1, 0xFFFF };
u16 D_800A4F1C[] = { 0x1A08, 1, 0xFFFF };
u16 D_800A4F24[] = { 0x7A20, 1, 0xFFFF };
u16 D_800A4F2C[] = { 0x1A0F, 0, 0xFFFF };
u16 D_800A4F34[] = { 0x1A0F, 1, 0xFFFF };
u16 D_800A4F3C[] = { 0x1A0F, 1, 0xFFFF };
u16 D_800A4F44[] = { 0x7A06, 1, 0xFFFF };
u16 D_800A4F4C[] = { 0x1A0E, 0, 0xFFFF };
u16 D_800A4F54[] = { 0x1A0E, 1, 0xFFFF };
u16 D_800A4F5C[] = { 0x1A0E, 1, 0xFFFF };
u16 D_800A4F64[] = { 0x7A05, 1, 0xFFFF };
u16 D_800A4F6C[] = { 0x818F, 0, 0xFFFF };
u16 D_800A4F74[] = { 0x818F, 1, 0x7013, 1, 0xFFFF };
u16 D_800A4F80[] = { 0x818F, 1, 0xFFFF };
u16 D_800A4F88[] = { 0x1A1C, 0, 0x6004, 1, 0xFFFF };
u16 D_800A4F94[] = { 0x1A1C, 1, 0xFFFF };
u16 D_800A4F9C[] = { 0x1A1C, 1, 0x6004, 1, 0xFFFF };
u16 D_800A4FA8[] = { 0x7A37, 1, 0xFFFF };
u16 D_800A4FB0[] = { 0x7015, 1, 0xFFFF };
u16 D_800A4FB8[] = { 0x7A37, 1, 0xFFFF };
u16 D_800A4FC0[] = { 0x703E, 1, 0xFFFF };
u16 D_800A4FC8[] = { 0x7A37, 1, 0xFFFF };
u16 D_800A4FD0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A4FD8[] = { 0x7A38, 1, 0xFFFF };
u16 D_800A4FE0[] = { 0x7020, 1, 0xFFFF };
u16 D_800A4FE8[] = { 0x7A38, 1, 0xFFFF };
u16 D_800A4FF0[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A4FFC[] = { 0x7A39, 1, 0xFFFF };
u16 D_800A5004[] = { 0x6026, 1, 0xFFFF };
u16 D_800A500C[] = { 0x7A3A, 1, 0xFFFF };
u16 D_800A5014[] = { 0x701A, 1, 0xFFFF };
u16 D_800A501C[] = { 0x7A3A, 1, 0xFFFF };
u16 D_800A5024[] = { 0x602B, 1, 0xFFFF };
u16 D_800A502C[] = { 0x7A3A, 1, 0xFFFF };
FieldTalk D_800A5034[] = {
    { D_800A4F0C, D_800A4F14, 4 },
    { D_800A4F1C, D_800A4F24, 5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5058[] = {
    { D_800A4F2C, D_800A4F34, 0x121 },
    { D_800A4F3C, D_800A4F44, 0xF3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A507C[] = {
    { D_800A4F4C, D_800A4F54, 0x123 },
    { D_800A4F5C, D_800A4F64, 0xF2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50A0[] = {
    { NULL, NULL, 0x41 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50B8[] = {
    { NULL, NULL, 0x43 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50D0[] = {
    { NULL, NULL, 0x49 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50E8[] = {
    { NULL, NULL, 0x48 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5100[] = {
    { NULL, NULL, 0x47 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5118[] = {
    { NULL, NULL, 0x46 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5130[] = {
    { NULL, NULL, 0x45 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5148[] = {
    { NULL, NULL, 0x44 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5160[] = {
    { NULL, NULL, 0x42 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5178[] = {
    { NULL, NULL, 0x4B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5190[] = {
    { D_800A4F6C, D_800A4F74, 0x128 },
    { D_800A4F80, NULL, 0x16C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51B4[] = {
    { NULL, NULL, 0x4A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51CC[] = {
    { D_800A4F88, D_800A4F94, 0x124 },
    { D_800A4F9C, D_800A4FA8, 1 },
    { D_800A4FB0, D_800A4FB8, 1 },
    { D_800A4FC0, D_800A4FC8, 1 },
    { D_800A4FD0, D_800A4FD8, 1 },
    { D_800A4FE0, D_800A4FE8, 1 },
    { D_800A4FF0, D_800A4FFC, 1 },
    { D_800A5004, D_800A500C, 1 },
    { D_800A5014, D_800A501C, 1 },
    { D_800A5024, D_800A502C, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5250[] = {
    { NULL, NULL, 0x174 },
    { NULL, NULL, 0 },
};
u16 D_800A5268[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5270[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5278[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5280[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5288[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5290[] = { 0x7017, 1, 0xFFFF };
u16 D_800A5298[] = { 0x7016, 1, 0xFFFF };
u16 D_800A52A0[] = { 0x600E, 1, 0xFFFF };
u16 D_800A52A8[] = { 0x7015, 1, 0xFFFF };
u16 D_800A52B0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A52B8[] = { 0x1C45, 1, 0x6006, 1, 0x1C46, 0, 0xFFFF };
u16 D_800A52C8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A52D0[] = { 0x8192, 1, 0xFFFF };
u16 D_800A52D8[] = { 0x8192, 0, 0xFFFF };
FieldActorEntry D_800A52E0 = { NULL, D_800A5034, 0x14, 4, 345, 197, 7 };
FieldActorEntry D_800A52F4 = { NULL, D_800A5058, 0x16, 5, 408, 341, 7 };
FieldActorEntry D_800A5308 = { NULL, D_800A507C, 0x17, 6, 330, 380, 7 };
FieldActorEntry D_800A531C = { D_800A5268, D_800A50A0, 0x2E, 7, 384, 418, 3 };
FieldActorEntry D_800A5330 = { D_800A5270, D_800A50B8, 0x2E, 7, 384, 418, 3 };
FieldActorEntry D_800A5344 = { D_800A5278, D_800A50D0, 0x2E, 7, 384, 418, 3 };
FieldActorEntry D_800A5358 = { D_800A5280, D_800A50E8, 0x2E, 7, 384, 418, 3 };
FieldActorEntry D_800A536C = { D_800A5288, D_800A5100, 0x2E, 7, 384, 418, 3 };
FieldActorEntry D_800A5380 = { D_800A5290, D_800A5118, 0x2E, 7, 384, 418, 3 };
FieldActorEntry D_800A5394 = { D_800A5298, D_800A5130, 0x2E, 7, 384, 418, 3 };
FieldActorEntry D_800A53A8 = { D_800A52A0, D_800A5148, 0x2E, 7, 384, 418, 3 };
FieldActorEntry D_800A53BC = { D_800A52A8, D_800A5160, 0x2E, 7, 384, 418, 3 };
FieldActorEntry D_800A53D0 = { D_800A52B0, D_800A5178, 0x2E, 7, 384, 418, 5 };
FieldActorEntry D_800A53E4 = { D_800A52B8, D_800A5190, 0x40, 8, 207, 152, 3 };
FieldActorEntry D_800A53F8 = { D_800A52C8, D_800A51B4, 0x9D, 9, 384, 418, 3 };
FieldActorEntry D_800A540C = { D_800A52D0, D_800A51CC, 0xCE, 0xA, 128, 201, 7 };
FieldActorEntry D_800A5420 = { D_800A52D8, D_800A5250, 0xCE, 0xA, 128, 201, 7 };
FieldActorEntry D_800A5434 = { NULL, NULL, 0xDB, 0xB, 345, 213, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A52E0,
    &D_800A52F4,
    &D_800A5308,
    &D_800A531C,
    &D_800A5330,
    &D_800A5344,
    &D_800A5358,
    &D_800A536C,
    &D_800A5380,
    &D_800A5394,
    &D_800A53A8,
    &D_800A53BC,
    &D_800A53D0,
    &D_800A53E4,
    &D_800A53F8,
    &D_800A540C,
    &D_800A5420,
    &D_800A5434,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 304, 189, 222, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 290, 166, 222, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 328, 195, 215, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 336, 187, 207, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 352, 180, 199, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 367, 164, 199, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 472, 281, 331, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 496, 352, 399, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 271, 382, 399, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 289, 374, 391, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 336, 350, 367, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 353, 343, 358, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 366, 323, 351, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 416, 309, 326, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 435, 292, 319, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 176, 155, 211, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 160, 148, 199, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 144, 140, 191, 0 },
    { 1, 0, 0x40, 4, 0x12, 0, 0, 0, 0, 0, 128, 132, 184, 0 },
    { 1, 0, 0x40, 4, 0x13, 0, 0, 0, 0, 0, 118, 127, 179, 0 },
    { 1, 0, 0x64, 4, 0x14, 0, 0, 0, 0, 0, 448, 251, 310, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x22E, 0x1E8, 0x1AC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x100, 0xB0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x10F, 0xF6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0xB0, 0xD8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xBF, 0x11E, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
