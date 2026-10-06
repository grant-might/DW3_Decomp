#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x4D7
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x4E7
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x15C00, 0x18B00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F1C[];
extern u16 D_800A4F24[];
extern u16 D_800A4F2C[];
extern FieldTalk D_800A4F34[];
extern FieldTalk D_800A4F4C[];
extern u16 D_800A50B4[];
extern FieldTalk D_800A4F64[];
extern u16 D_800A50BC[];
extern FieldTalk D_800A4F7C[];
extern u16 D_800A50C8[];
extern FieldTalk D_800A4F94[];
extern u16 D_800A50D4[];
extern FieldTalk D_800A4FAC[];
extern u16 D_800A50E0[];
extern FieldTalk D_800A4FC4[];
extern u16 D_800A50E8[];
extern FieldTalk D_800A4FDC[];
extern u16 D_800A50F4[];
extern FieldTalk D_800A4FF4[];
extern FieldTalk D_800A500C[];
extern u16 D_800A50FC[];
extern FieldTalk D_800A5024[];
extern u16 D_800A5108[];
extern FieldTalk D_800A503C[];
extern u16 D_800A5118[];
extern FieldTalk D_800A5054[];
extern u16 D_800A5124[];
extern FieldTalk D_800A506C[];
extern u16 D_800A5134[];
extern FieldTalk D_800A5084[];
extern u16 D_800A5140[];
extern FieldTalk D_800A509C[];
extern FieldActorEntry D_800A5148;
extern FieldActorEntry D_800A515C;
extern FieldActorEntry D_800A5170;
extern FieldActorEntry D_800A5184;
extern FieldActorEntry D_800A5198;
extern FieldActorEntry D_800A51AC;
extern FieldActorEntry D_800A51C0;
extern FieldActorEntry D_800A51D4;
extern FieldActorEntry D_800A51E8;
extern FieldActorEntry D_800A51FC;
extern FieldActorEntry D_800A5210;
extern FieldActorEntry D_800A5224;
extern FieldActorEntry D_800A5238;
extern FieldActorEntry D_800A524C;
extern FieldActorEntry D_800A5260;
extern FieldActorEntry D_800A5274;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x16E, 0x1C0, 0x6E, 0x150, 0x1FF },
    { 0x180, 0x100, 0x1B0, 0x196, 0x1C0, 0x96, 0x160, 0x1FF },
    { 0x180, 0x100, 0x1B0, 0x1DE, 0x1C0, 0xDE, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1B0, 0x1B6, 0x1C0, 0xB6, 0x150, 0x1FE },
    { 0x1C0, 0x100, 0x1F2, 0x100, 0x2C8, 0, 0x160, 0x1FE },
    { 0x1C0, 0x100, 0x1F2, 0x120, 0x2C8, 0x20, 0x170, 0x1FE },
    { 0x1C0, 0x100, 0x1E2, 0x13F, 0x288, 0x3F, 0x150, 0x1FD },
    { 0x180, 0x100, 0x1A0, 0x1C4, 0x180, 0xC4, 0x160, 0x1FD },
    { 0x1C0, 0x100, 0x1EA, 0x13F, 0x2A8, 0x3F, 0x170, 0x1FD },
};
u16 D_800A4F1C[] = { 0x7A11, 1, 0xFFFF };
u16 D_800A4F24[] = { 0x7A0F, 1, 0xFFFF };
u16 D_800A4F2C[] = { 0x7A10, 1, 0xFFFF };
FieldTalk D_800A4F34[] = {
    { NULL, D_800A4F1C, 0x1A8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F4C[] = {
    { NULL, D_800A4F24, 0x1A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F64[] = {
    { NULL, NULL, 0x6F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F7C[] = {
    { NULL, NULL, 0x6D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F94[] = {
    { NULL, NULL, 0x71 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FAC[] = {
    { NULL, NULL, 0x70 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FC4[] = {
    { NULL, NULL, 0x72 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FDC[] = {
    { NULL, NULL, 0x6C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FF4[] = {
    { NULL, NULL, 0x6E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A500C[] = {
    { NULL, D_800A4F2C, 0x1A6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5024[] = {
    { NULL, NULL, 0x1BB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A503C[] = {
    { NULL, NULL, 0x69 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5054[] = {
    { NULL, NULL, 0x6B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A506C[] = {
    { NULL, NULL, 0x1BA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5084[] = {
    { NULL, NULL, 0x68 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A509C[] = {
    { NULL, NULL, 0x6A },
    { NULL, NULL, 0 },
};
u16 D_800A50B4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A50BC[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A50C8[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A50D4[] = { 0x1A0A, 0, 0x701C, 1, 0xFFFF };
u16 D_800A50E0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A50E8[] = { 0x1A0A, 0, 0x701C, 1, 0xFFFF };
u16 D_800A50F4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A50FC[] = { 0x602B, 1, 0x8008, 1, 0xFFFF };
u16 D_800A5108[] = { 0x8008, 0, 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5118[] = { 0x8008, 0, 0x602B, 1, 0xFFFF };
u16 D_800A5124[] = { 0x6026, 1, 0x1A0A, 1, 0x8008, 1, 0xFFFF };
u16 D_800A5134[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5140[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5148 = { NULL, D_800A4F34, 0x16, 4, 449, 281, 7 };
FieldActorEntry D_800A515C = { NULL, D_800A4F4C, 0x17, 5, 304, 369, 7 };
FieldActorEntry D_800A5170 = { D_800A50B4, D_800A4F64, 0x2E, 6, 287, 433, 5 };
FieldActorEntry D_800A5184 = { D_800A50BC, D_800A4F7C, 0x2E, 6, 287, 433, 5 };
FieldActorEntry D_800A5198 = { D_800A50C8, D_800A4F94, 0x34, 7, 480, 338, 3 };
FieldActorEntry D_800A51AC = { D_800A50D4, D_800A4FAC, 0x9D, 8, 480, 338, 3 };
FieldActorEntry D_800A51C0 = { D_800A50E0, D_800A4FC4, 0x9D, 8, 480, 338, 3 };
FieldActorEntry D_800A51D4 = { D_800A50E8, D_800A4FDC, 0x9E, 9, 287, 433, 5 };
FieldActorEntry D_800A51E8 = { D_800A50F4, D_800A4FF4, 0x9E, 9, 287, 433, 5 };
FieldActorEntry D_800A51FC = { NULL, D_800A500C, 0xB7, 0xA, 359, 308, 7 };
FieldActorEntry D_800A5210 = { D_800A50FC, D_800A5024, 0xFF, 0xB, 144, 352, 1 };
FieldActorEntry D_800A5224 = { D_800A5108, D_800A503C, 0xFF, 0xB, 152, 397, 7 };
FieldActorEntry D_800A5238 = { D_800A5118, D_800A5054, 0xFF, 0xB, 152, 397, 7 };
FieldActorEntry D_800A524C = { D_800A5124, D_800A506C, 0xFF, 0xB, 144, 352, 1 };
FieldActorEntry D_800A5260 = { D_800A5134, D_800A5084, 0x119, 0xC, 152, 397, 7 };
FieldActorEntry D_800A5274 = { D_800A5140, D_800A509C, 0x119, 0xC, 152, 397, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5148,
    &D_800A515C,
    &D_800A5170,
    &D_800A5184,
    &D_800A5198,
    &D_800A51AC,
    &D_800A51C0,
    &D_800A51D4,
    &D_800A51E8,
    &D_800A51FC,
    &D_800A5210,
    &D_800A5224,
    &D_800A5238,
    &D_800A524C,
    &D_800A5260,
    &D_800A5274,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x11, 2, 0, 1, 4, 0, 384, 79, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 2, 0, 1, 4, 0, 492, 137, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 2, 0, 1, 4, 0, 548, 165, 0, 0 },
    { 1, 0x64, 0x40, 6, 5, 0, 0, 0, 0, 0, 304, 99, 0, 0 },
    { 1, 0x65, 0x40, 6, 6, 0, 0, 0, 0, 0, 64, 285, 0, 0 },
    { 1, 0, 0x40, 6, 7, 0, 0, 0, 0, 0, 485, 145, 0, 0 },
    { 1, 0, 0x40, 6, 7, 0, 0, 0, 0, 0, 541, 173, 0, 0 },
    { 1, 0, 0xA0, 4, 0, 0, 0, 0, 0, 0, 144, 257, 380, 0 },
    { 1, 0, 0x78, 4, 1, 0, 0, 0, 0, 0, 256, 257, 337, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 384, 262, 287, 0 },
    { 1, 0, 0x64, 4, 3, 0, 0, 0, 0, 0, 240, 73, 150, 0 },
    { 1, 0, 0x64, 4, 4, 0, 0, 0, 0, 0, 0, 255, 335, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x1E0, 0x1DA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x240, 0x1AA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27D, 0x218, 0xE4, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x27D, 0x128, 0x19C, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x11F, 0xBA, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x110, 0xFE, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
