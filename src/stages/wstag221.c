#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x4D0
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x4E0
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x10500, 0x15F00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.spriteColor = stageColor;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern u16 D_800A4FC4[];
extern u16 D_800A4FCC[];
extern u16 D_800A4FD8[];
extern u16 D_800A4FE0[];
extern u16 D_800A4FEC[];
extern u16 D_800A5120[];
extern FieldTalk D_800A4FF4[];
extern u16 D_800A512C[];
extern FieldTalk D_800A500C[];
extern u16 D_800A5134[];
extern FieldTalk D_800A5024[];
extern u16 D_800A5140[];
extern FieldTalk D_800A503C[];
extern u16 D_800A5148[];
extern FieldTalk D_800A5054[];
extern u16 D_800A5150[];
extern u16 D_800A5158[];
extern u16 D_800A5164[];
extern u16 D_800A5170[];
extern u16 D_800A517C[];
extern FieldTalk D_800A506C[];
extern u16 D_800A5188[];
extern FieldTalk D_800A5084[];
extern u16 D_800A5190[];
extern FieldTalk D_800A509C[];
extern u16 D_800A519C[];
extern FieldTalk D_800A50B4[];
extern u16 D_800A51A4[];
extern u16 D_800A51B0[];
extern u16 D_800A51B8[];
extern FieldTalk D_800A50CC[];
extern u16 D_800A51C0[];
extern FieldTalk D_800A50E4[];
extern u16 D_800A51C8[];
extern FieldTalk D_800A5108[];
extern u16 D_800A51D0[];
extern u16 D_800A51DC[];
extern u16 D_800A51E8[];
extern u16 D_800A51F4[];
extern FieldActorEntry D_800A5200;
extern FieldActorEntry D_800A5214;
extern FieldActorEntry D_800A5228;
extern FieldActorEntry D_800A523C;
extern FieldActorEntry D_800A5250;
extern FieldActorEntry D_800A5264;
extern FieldActorEntry D_800A5278;
extern FieldActorEntry D_800A528C;
extern FieldActorEntry D_800A52A0;
extern FieldActorEntry D_800A52B4;
extern FieldActorEntry D_800A52C8;
extern FieldActorEntry D_800A52DC;
extern FieldActorEntry D_800A52F0;
extern FieldActorEntry D_800A5304;
extern FieldActorEntry D_800A5318;
extern FieldActorEntry D_800A532C;
extern FieldActorEntry D_800A5340;
extern FieldActorEntry D_800A5354;
extern FieldActorEntry D_800A5368;
extern FieldActorEntry D_800A537C;
extern FieldActorEntry D_800A5390;
extern FieldActorEntry D_800A53A4;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x158, 0x180, 0x60, 0x80, 0x150, 0x1F7 },
    { 0x140, 0x100, 0x160, 0x190, 0x80, 0x90, 0x160, 0x1F7 },
    { 0x140, 0x100, 0x168, 0x190, 0xA0, 0x90, 0x170, 0x1F7 },
    { 0x140, 0x100, 0x170, 0x190, 0xC0, 0x90, 0x150, 0x1F6 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x154, 0x1A8, 0x50, 0xA8, 0x160, 0x1F6 },
    { 0x140, 0x100, 0x140, 0x1AE, 0, 0xAE, 0x170, 0x1F6 },
    { 0x140, 0x100, 0x148, 0x1AE, 0x20, 0xAE, 0x140, 0x1F5 },
    { 0x140, 0x100, 0x15C, 0x1B8, 0x70, 0xB8, 0x150, 0x1F5 },
    { 0x140, 0x100, 0x178, 0x190, 0xE0, 0x90, 0x160, 0x1F5 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A4FC4[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A4FCC[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A4FD8[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A4FE0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A4FEC[] = { 0x7C00, 1, 0xFFFF };
FieldTalk D_800A4FF4[] = {
    { NULL, NULL, 0x51 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A500C[] = {
    { NULL, NULL, 0x56 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5024[] = {
    { NULL, NULL, 0x52 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A503C[] = {
    { NULL, NULL, 0x57 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5054[] = {
    { NULL, NULL, 0x59 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A506C[] = {
    { NULL, NULL, 0x4D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5084[] = {
    { NULL, NULL, 0x53 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A509C[] = {
    { NULL, NULL, 0x4E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50B4[] = {
    { NULL, NULL, 0x54 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50CC[] = {
    { NULL, D_800A4FC4, 0x55 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50E4[] = {
    { D_800A4FCC, D_800A4FD8, 0x4F },
    { D_800A4FE0, D_800A4FEC, 0x50 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5108[] = {
    { NULL, NULL, 0x58 },
    { NULL, NULL, 0 },
};
u16 D_800A5120[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A512C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5134[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5140[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5148[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5150[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5158[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5164[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5170[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A517C[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5188[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5190[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A519C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A51A4[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51B0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A51B8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A51C0[] = { 0x701C, 1, 0xFFFF };
u16 D_800A51C8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A51D0[] = { 0x7094, 1, 0x6026, 0, 0xFFFF };
u16 D_800A51DC[] = { 0x6026, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A51E8[] = { 0x7094, 1, 0x6026, 0, 0xFFFF };
u16 D_800A51F4[] = { 0x6026, 1, 0x1A0A, 0, 0xFFFF };
FieldActorEntry D_800A5200 = { D_800A5120, D_800A4FF4, 0x20, 4, 187, 215, 1 };
FieldActorEntry D_800A5214 = { D_800A512C, D_800A500C, 0x20, 4, 187, 215, 1 };
FieldActorEntry D_800A5228 = { D_800A5134, D_800A5024, 0x24, 5, 220, 232, 1 };
FieldActorEntry D_800A523C = { D_800A5140, D_800A503C, 0x24, 5, 220, 232, 1 };
FieldActorEntry D_800A5250 = { D_800A5148, D_800A5054, 0x31, 6, 256, 385, 3 };
FieldActorEntry D_800A5264 = { D_800A5150, NULL, 0x59, 7, 300, 217, 5 };
FieldActorEntry D_800A5278 = { D_800A5158, NULL, 0x59, 7, 300, 217, 5 };
FieldActorEntry D_800A528C = { D_800A5164, NULL, 0x70, 8, 169, 224, 1 };
FieldActorEntry D_800A52A0 = { D_800A5170, NULL, 0x71, 9, 202, 241, 1 };
FieldActorEntry D_800A52B4 = { D_800A517C, D_800A506C, 0x9D, 0xA, 187, 215, 1 };
FieldActorEntry D_800A52C8 = { D_800A5188, D_800A5084, 0x9D, 0xA, 187, 215, 1 };
FieldActorEntry D_800A52DC = { D_800A5190, D_800A509C, 0x9E, 0xB, 220, 232, 1 };
FieldActorEntry D_800A52F0 = { D_800A519C, D_800A50B4, 0x9E, 0xB, 220, 232, 1 };
FieldActorEntry D_800A5304 = { D_800A51A4, NULL, 0x9F, 0xC, 300, 217, 5 };
FieldActorEntry D_800A5318 = { D_800A51B0, NULL, 0x9F, 0xC, 300, 217, 5 };
FieldActorEntry D_800A532C = { D_800A51B8, D_800A50CC, 0xA0, 0xD, 399, 248, 1 };
FieldActorEntry D_800A5340 = { D_800A51C0, D_800A50E4, 0xFE, 0xE, 399, 248, 1 };
FieldActorEntry D_800A5354 = { D_800A51C8, D_800A5108, 0xFE, 0xE, 399, 248, 1 };
FieldActorEntry D_800A5368 = { D_800A51D0, NULL, 0x10E, 0xF, 169, 224, 1 };
FieldActorEntry D_800A537C = { D_800A51DC, NULL, 0x10E, 0xF, 169, 224, 1 };
FieldActorEntry D_800A5390 = { D_800A51E8, NULL, 0x10F, 0x10, 202, 241, 1 };
FieldActorEntry D_800A53A4 = { D_800A51F4, NULL, 0x10F, 0x10, 202, 241, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5200,
    &D_800A5214,
    &D_800A5228,
    &D_800A523C,
    &D_800A5250,
    &D_800A5264,
    &D_800A5278,
    &D_800A528C,
    &D_800A52A0,
    &D_800A52B4,
    &D_800A52C8,
    &D_800A52DC,
    &D_800A52F0,
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
    { 1, 0, 0x40, 2, 0x45, 2, 0, 2, 0xA, 0, 376, 237, 0, 0 },
    { 1, 0, 0x40, 2, 5, 0, 0, 0, 0, 0, 368, 277, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 0, 204, 0, 0 },
    { 1, 0, 0x40, 2, 0x46, 2, 0, 1, 4, 0, 38, 197, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 110, 341, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 198, 149, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 221, 148, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 235, 149, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 249, 297, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 271, 168, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 398, 350, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 102, 333, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 200, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 213, 145, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 242, 167, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 248, 230, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 254, 280, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 265, 153, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 391, 343, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 1, 0x4A, 0x59, 0xA, 0, 124, 331, 0, 0 },
    { 1, 0, 0x40, 6, 0x14, 1, 0x14, 0x1E, 0xA, 0, 349, 336, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x39, 0xE, 0, 318, 172, 0, 0 },
    { 1, 0, 0x40, 6, 0x2F, 1, 0x2F, 0x31, 4, 0, 305, 193, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3F, 8, 0, 354, 209, 0, 0 },
    { 1, 0, 0x40, 6, 0x40, 2, 0, 9, 8, 0, 336, 217, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 2, 0, 2, 0x10, 0, 328, 232, 0, 0 },
    { 1, 0x64, 0x40, 6, 4, 0, 0, 0, 0, 0, 79, 186, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 2, 0, 2, 6, 0, 136, 185, 0, 0 },
    { 1, 0, 0x40, 6, 0x43, 2, 0, 2, 0x10, 0, 306, 231, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 2, 0, 2, 0xA, 0, 321, 223, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 1, 4, 0, 140, 123, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 1, 4, 0, 307, 122, 0, 0 },
    { 1, 0, 0x40, 6, 0x49, 2, 0, 1, 4, 0, 346, 144, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 143, 287, 340, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 326, 288, 340, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 398, 240, 263, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 33, 201, 239, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x273, 0x2C8, 0x24C, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x410, 0x200, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
