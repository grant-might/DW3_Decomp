#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x4B7
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x4C7
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1F800, 0x2E200};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x17;
    D_800990B4.music = 0x605C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress >= 0xF && GAME.progress < 0x18) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern u16 D_800A51D8[];
extern u16 D_800A51E0[];
extern u16 D_800A51E8[];
extern u16 D_800A51F0[];
extern u16 D_800A51F8[];
extern u16 D_800A5458[];
extern FieldTalk D_800A5200[];
extern u16 D_800A5460[];
extern FieldTalk D_800A5218[];
extern u16 D_800A5468[];
extern FieldTalk D_800A5230[];
extern u16 D_800A5470[];
extern FieldTalk D_800A5248[];
extern u16 D_800A5478[];
extern FieldTalk D_800A5260[];
extern u16 D_800A5480[];
extern FieldTalk D_800A5278[];
extern u16 D_800A5488[];
extern FieldTalk D_800A5290[];
extern u16 D_800A5490[];
extern FieldTalk D_800A52A8[];
extern u16 D_800A5498[];
extern FieldTalk D_800A52C0[];
extern u16 D_800A54A0[];
extern FieldTalk D_800A52D8[];
extern u16 D_800A54A8[];
extern FieldTalk D_800A52F0[];
extern u16 D_800A54B0[];
extern FieldTalk D_800A5308[];
extern u16 D_800A54B8[];
extern FieldTalk D_800A5320[];
extern u16 D_800A54C0[];
extern FieldTalk D_800A5338[];
extern u16 D_800A54C8[];
extern FieldTalk D_800A5350[];
extern u16 D_800A54D0[];
extern FieldTalk D_800A5368[];
extern u16 D_800A54D8[];
extern FieldTalk D_800A5380[];
extern u16 D_800A54E0[];
extern u16 D_800A54E8[];
extern FieldTalk D_800A5398[];
extern u16 D_800A54F0[];
extern u16 D_800A54F8[];
extern FieldTalk D_800A53B0[];
extern u16 D_800A5500[];
extern u16 D_800A5508[];
extern FieldTalk D_800A53C8[];
extern u16 D_800A5510[];
extern u16 D_800A5518[];
extern FieldTalk D_800A53E0[];
extern u16 D_800A5520[];
extern FieldTalk D_800A53F8[];
extern u16 D_800A5528[];
extern FieldTalk D_800A5410[];
extern u16 D_800A5530[];
extern FieldTalk D_800A5428[];
extern u16 D_800A5538[];
extern FieldTalk D_800A5440[];
extern FieldActorEntry D_800A5540;
extern FieldActorEntry D_800A5554;
extern FieldActorEntry D_800A5568;
extern FieldActorEntry D_800A557C;
extern FieldActorEntry D_800A5590;
extern FieldActorEntry D_800A55A4;
extern FieldActorEntry D_800A55B8;
extern FieldActorEntry D_800A55CC;
extern FieldActorEntry D_800A55E0;
extern FieldActorEntry D_800A55F4;
extern FieldActorEntry D_800A5608;
extern FieldActorEntry D_800A561C;
extern FieldActorEntry D_800A5630;
extern FieldActorEntry D_800A5644;
extern FieldActorEntry D_800A5658;
extern FieldActorEntry D_800A566C;
extern FieldActorEntry D_800A5680;
extern FieldActorEntry D_800A5694;
extern FieldActorEntry D_800A56A8;
extern FieldActorEntry D_800A56BC;
extern FieldActorEntry D_800A56D0;
extern FieldActorEntry D_800A56E4;
extern FieldActorEntry D_800A56F8;
extern FieldActorEntry D_800A570C;
extern FieldActorEntry D_800A5720;
extern FieldActorEntry D_800A5734;
extern FieldActorEntry D_800A5748;
extern FieldActorEntry D_800A575C;
extern FieldActorEntry D_800A5770;
extern s16 D_800A5004[];
extern s16 D_800A4EA4[];

s16 D_800A4EA4[] = {
    0x600, 0, 2,
    0x102, 2, 0x186, 0x320, 5,
    0x100, 0x45, 0x127, 0x266,
    0x101, 0x45, 1, 7,
    0x100, 0x46, 0x1E0, 0x2D1,
    0x101, 0x46, 1, 1,
    0x100, 0x47, 0x201, 0x2E1,
    0x101, 0x47, 1, 1,
    0x100, 0x48, 0x221, 0x2F1,
    0x101, 0x48, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x1BD, 0x320, 6,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x601, 0, 0x190, 0x282,
    0x101, 0x323, 0x325, 0x45,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x45,
    0x300, 0x1E,
    0x200, 0, 2, 0x45, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x45, 3,
    0x301,
    0x300, 0x1E,
    0x601, 0, 0x202, 0x2CA,
    0x101, 0x46, 1, 2,
    0x101, 0x48, 1, 0,
    0x300, 0x3C,
    0x200, 0, 4, 0x46, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0x47, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x48, 0,
    0x301,
    0x101, 0x46, 1, 1,
    0x101, 0x48, 1, 1,
    0x300, 0x1E,
    0x600, 0, 2,
    0x300, 0x3C,
    0x200, 0, 8, 2, 1,
    0x301,
    0x300, 0x1E,
    0x304, 0x248, 0x1F0, 0x68, 1,
    0,
};
s16 D_800A5004[] = {
    0x102, 2, 0x43E, 0x204, 5,
    0x100, 0x15, 0x45F, 0x1F6,
    0x101, 0x15, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 1,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 1,
    0x300, 0x5A,
    0x304, 0xC06, 0, 0, 0,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x6004\n");
#endif
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1E4, 0x1B0, 0x290, 0xB0, 0x150, 0x1FB },
    { 0x180, 0x100, 0x180, 0x1CF, 0x100, 0xCF, 0x160, 0x1FB },
    { 0x1C0, 0x100, 0x1F2, 0x128, 0x2C8, 0x28, 0x170, 0x1FB },
    { 0x1C0, 0x100, 0x1E2, 0x132, 0x288, 0x32, 0x150, 0x1FA },
    { 0x1C0, 0x100, 0x1EE, 0x100, 0x2B8, 0, 0x160, 0x1FA },
    { 0x140, 0x100, 0x170, 0x1CE, 0xC0, 0xCE, 0x170, 0x1FA },
    { 0x1C0, 0x100, 0x1C0, 0x138, 0x200, 0x38, 0x140, 0x1F9 },
    { 0x1C0, 0x100, 0x1EC, 0x1B0, 0x2B0, 0xB0, 0x150, 0x1F9 },
    { 0x1C0, 0x100, 0x1D6, 0x144, 0x258, 0x44, 0x160, 0x1F9 },
    { 0x1C0, 0x100, 0x1C8, 0x14D, 0x220, 0x4D, 0x170, 0x1F9 },
    { 0x1C0, 0x100, 0x1EC, 0x150, 0x2B0, 0x50, 0x140, 0x1F8 },
    { 0x1C0, 0x100, 0x1F4, 0x150, 0x2D0, 0x50, 0x150, 0x1F8 },
    { 0x1C0, 0x100, 0x1DE, 0x152, 0x278, 0x52, 0x160, 0x1F8 },
    { 0x1C0, 0x100, 0x1F4, 0x1B0, 0x2D0, 0xB0, 0x170, 0x1F8 },
    { 0x1C0, 0x100, 0x1D0, 0x1B2, 0x240, 0xB2, 0x140, 0x1F7 },
    { 0x1C0, 0x100, 0x1D8, 0x1B2, 0x260, 0xB2, 0x150, 0x1F7 },
};
u16 D_800A51D8[] = { 0x7A24, 1, 0xFFFF };
u16 D_800A51E0[] = { 0x9014, 1, 0xFFFF };
u16 D_800A51E8[] = { 0x7A0C, 1, 0xFFFF };
u16 D_800A51F0[] = { 0x7A0B, 1, 0xFFFF };
u16 D_800A51F8[] = { 0x7C00, 1, 0xFFFF };
FieldTalk D_800A5200[] = {
    { NULL, D_800A51D8, 5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5218[] = {
    { NULL, D_800A51E0, 2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5230[] = {
    { NULL, D_800A51E8, 0xF3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5248[] = {
    { NULL, D_800A51F0, 0xF2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5260[] = {
    { NULL, D_800A51F8, 0x4C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5278[] = {
    { NULL, NULL, 0x155 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5290[] = {
    { NULL, NULL, 0x154 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52A8[] = {
    { NULL, NULL, 0x151 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52C0[] = {
    { NULL, NULL, 0x152 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52D8[] = {
    { NULL, NULL, 0x147 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52F0[] = {
    { NULL, NULL, 0x14B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5308[] = {
    { NULL, NULL, 0x148 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5320[] = {
    { NULL, NULL, 0x149 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5338[] = {
    { NULL, NULL, 0x14C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5350[] = {
    { NULL, NULL, 0x150 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5368[] = {
    { NULL, NULL, 0x14D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5380[] = {
    { NULL, NULL, 0x14E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5398[] = {
    { NULL, NULL, 0x145 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53B0[] = {
    { NULL, NULL, 0x142 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53C8[] = {
    { NULL, NULL, 0x144 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53E0[] = {
    { NULL, NULL, 0x146 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53F8[] = {
    { NULL, NULL, 0x143 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5410[] = {
    { NULL, NULL, 0x14A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5428[] = {
    { NULL, NULL, 0x14F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5440[] = {
    { NULL, NULL, 0x153 },
    { NULL, NULL, 0 },
};
u16 D_800A5458[] = { 0x7008, 1, 0xFFFF };
u16 D_800A5460[] = { 0x7008, 1, 0xFFFF };
u16 D_800A5468[] = { 0x7008, 1, 0xFFFF };
u16 D_800A5470[] = { 0x7008, 1, 0xFFFF };
u16 D_800A5478[] = { 0x7008, 1, 0xFFFF };
u16 D_800A5480[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5488[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5490[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5498[] = { 0x6026, 1, 0xFFFF };
u16 D_800A54A0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A54A8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A54B0[] = { 0x7019, 1, 0xFFFF };
u16 D_800A54B8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A54C0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A54C8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A54D0[] = { 0x7019, 1, 0xFFFF };
u16 D_800A54D8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A54E0[] = { 0x1C26, 1, 0xFFFF };
u16 D_800A54E8[] = { 0x600F, 1, 0xFFFF };
u16 D_800A54F0[] = { 0x1C26, 1, 0xFFFF };
u16 D_800A54F8[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5500[] = { 0x1C26, 1, 0xFFFF };
u16 D_800A5508[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5510[] = { 0x1C26, 1, 0xFFFF };
u16 D_800A5518[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5520[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5528[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5530[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5538[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5540 = { D_800A5458, D_800A5200, 0x14, 4, 908, 596, 7 };
FieldActorEntry D_800A5554 = { D_800A5460, D_800A5218, 0x15, 5, 1119, 502, 1 };
FieldActorEntry D_800A5568 = { D_800A5468, D_800A5230, 0x16, 6, 834, 470, 7 };
FieldActorEntry D_800A557C = { D_800A5470, D_800A5248, 0x17, 7, 690, 493, 1 };
FieldActorEntry D_800A5590 = { D_800A5478, D_800A5260, 0x18, 8, 1329, 411, 1 };
FieldActorEntry D_800A55A4 = { D_800A5480, D_800A5278, 0x2D, 9, 897, 289, 5 };
FieldActorEntry D_800A55B8 = { D_800A5488, D_800A5290, 0x2D, 9, 767, 529, 3 };
FieldActorEntry D_800A55CC = { D_800A5490, D_800A52A8, 0x2D, 9, 897, 289, 5 };
FieldActorEntry D_800A55E0 = { D_800A5498, D_800A52C0, 0x2D, 9, 897, 289, 5 };
FieldActorEntry D_800A55F4 = { D_800A54A0, D_800A52D8, 0x36, 0xA, 993, 531, 7 };
FieldActorEntry D_800A5608 = { D_800A54A8, D_800A52F0, 0x36, 0xA, 897, 289, 5 };
FieldActorEntry D_800A561C = { D_800A54B0, D_800A5308, 0x36, 0xA, 993, 531, 7 };
FieldActorEntry D_800A5630 = { D_800A54B8, D_800A5320, 0x36, 0xA, 993, 531, 7 };
FieldActorEntry D_800A5644 = { D_800A54C0, D_800A5338, 0x3A, 0xB, 767, 529, 3 };
FieldActorEntry D_800A5658 = { D_800A54C8, D_800A5350, 0x3A, 0xB, 993, 531, 7 };
FieldActorEntry D_800A566C = { D_800A54D0, D_800A5368, 0x3A, 0xB, 767, 529, 3 };
FieldActorEntry D_800A5680 = { D_800A54D8, D_800A5380, 0x3A, 0xB, 767, 529, 3 };
FieldActorEntry D_800A5694 = { D_800A54E0, NULL, 0x45, 0xC, 295, 614, 7 };
FieldActorEntry D_800A56A8 = { D_800A54E8, D_800A5398, 0x45, 0xC, 834, 470, 7 };
FieldActorEntry D_800A56BC = { D_800A54F0, NULL, 0x46, 0xD, 480, 721, 1 };
FieldActorEntry D_800A56D0 = { D_800A54F8, D_800A53B0, 0x46, 0xD, 1123, 499, 1 };
FieldActorEntry D_800A56E4 = { D_800A5500, NULL, 0x47, 0xE, 513, 737, 1 };
FieldActorEntry D_800A56F8 = { D_800A5508, D_800A53C8, 0x47, 0xE, 690, 493, 1 };
FieldActorEntry D_800A570C = { D_800A5510, NULL, 0x48, 0xF, 545, 753, 1 };
FieldActorEntry D_800A5720 = { D_800A5518, D_800A53E0, 0x48, 0xF, 908, 596, 7 };
FieldActorEntry D_800A5734 = { D_800A5520, D_800A53F8, 0x49, 0x10, 1329, 411, 1 };
FieldActorEntry D_800A5748 = { D_800A5528, D_800A5410, 0x9D, 0x11, 993, 531, 7 };
FieldActorEntry D_800A575C = { D_800A5530, D_800A5428, 0x9E, 0x12, 767, 529, 3 };
FieldActorEntry D_800A5770 = { D_800A5538, D_800A5440, 0x9F, 0x13, 897, 289, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A5540,
    &D_800A5554,
    &D_800A5568,
    &D_800A557C,
    &D_800A5590,
    &D_800A55A4,
    &D_800A55B8,
    &D_800A55CC,
    &D_800A55E0,
    &D_800A55F4,
    &D_800A5608,
    &D_800A561C,
    &D_800A5630,
    &D_800A5644,
    &D_800A5658,
    &D_800A566C,
    &D_800A5680,
    &D_800A5694,
    &D_800A56A8,
    &D_800A56BC,
    &D_800A56D0,
    &D_800A56E4,
    &D_800A56F8,
    &D_800A570C,
    &D_800A5720,
    &D_800A5734,
    &D_800A5748,
    &D_800A575C,
    &D_800A5770,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0xC8, 2, 0x5A, 1, 0x5A, 0x61, 0xA, 0, 1314, 270, 0, 0 },
    { 1, 0, 0x48, 2, 0, 0, 0, 0, 0, 0, 444, 419, 0, 0 },
    { 1, 0, 0x58, 2, 0xD, 0, 0, 0, 0, 0, 683, 345, 0, 0 },
    { 1, 0, 0x4C, 2, 0xE, 0, 0, 0, 0, 0, 947, 492, 0, 0 },
    { 1, 0, 0x60, 2, 0x10, 0, 0, 0, 0, 0, 640, 515, 0, 0 },
    { 1, 0, 0x74, 2, 0x11, 0, 0, 0, 0, 0, 624, 524, 0, 0 },
    { 1, 0, 0x44, 2, 0x12, 0, 0, 0, 0, 0, 304, 556, 0, 0 },
    { 1, 0, 0x40, 2, 7, 1, 7, 0xC, 4, 0, 379, 317, 0, 0 },
    { 1, 0, 0x40, 2, 7, 1, 7, 0xC, 4, 0, 924, 587, 0, 0 },
    { 1, 0, 0x41, 2, 3, 0, 0, 0, 0, 0, 960, 418, 0, 0 },
    { 1, 0, 0x62, 2, 0xF, 0, 0, 0, 0, 0, 938, 609, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 8, 0, 1378, 348, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 1391, 358, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 8, 0, 1250, 357, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 8, 0, 1263, 350, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x38, 4, 0, 1217, 367, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x38, 4, 0, 1417, 367, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 6, 0, 1310, 259, 0, 0 },
    { 1, 0, 0xC8, 6, 0x57, 1, 0x57, 0x59, 6, 0, 1144, 428, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x3E, 0xA, 0, 939, 765, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x3E, 0xA, 0, 1005, 684, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x3E, 0xA, 0, 1163, 605, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x3E, 0xA, 0, 1324, 525, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x41, 0xA, 0, 971, 701, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x41, 0xA, 0, 1013, 599, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 1, 0x3F, 0x41, 0xA, 0, 1160, 527, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 337, 398, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 411, 485, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 489, 399, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 701, 294, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 815, 743, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 995, 695, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 1025, 674, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 1079, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 1139, 536, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 1182, 595, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 1, 0x42, 0x44, 0xA, 0, 1306, 536, 0, 0 },
    { 1, 0, 0x40, 6, 0x45, 1, 0x45, 0x47, 0xA, 0, 551, 531, 0, 0 },
    { 1, 0, 0x40, 6, 0x45, 1, 0x45, 0x47, 0xA, 0, 733, 621, 0, 0 },
    { 1, 0, 0x40, 6, 0x45, 1, 0x45, 0x47, 0xA, 0, 873, 609, 0, 0 },
    { 1, 0, 0x40, 6, 0x45, 1, 0x45, 0x47, 0xA, 0, 886, 745, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 1, 0x48, 0x4A, 0xA, 0, 345, 477, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 1, 0x48, 0x4A, 0xA, 0, 575, 542, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 1, 0x48, 0x4A, 0xA, 0, 814, 580, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 1, 0x48, 0x4A, 0xA, 0, 896, 701, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 1, 0x4B, 0x4D, 0xA, 0, 869, 689, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 273, 423, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 289, 417, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 297, 409, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 310, 410, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 510, 386, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 531, 377, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 719, 281, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 804, 560, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 817, 561, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 922, 500, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 964, 753, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 977, 754, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 1101, 351, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 1171, 513, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 1, 0x4E, 0x50, 0xA, 0, 1174, 506, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0x51, 1, 0x51, 0x53, 6, 0, 799, 318, 0, 0 },
    { 1, 0, 0xC8, 0xA, 0x54, 1, 0x54, 0x56, 6, 0, 1052, 371, 0, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 944, 515, 569, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 582, 424, 454, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1056, 269, 327, 0 },
    { 1, 0, 0x41, 4, 4, 0, 0, 0, 0, 0, 369, 703, 751, 0 },
    { 1, 0, 0x41, 4, 4, 0, 0, 0, 0, 0, 449, 743, 791, 0 },
    { 1, 0, 0x60, 4, 2, 0, 0, 0, 0, 0, 914, 233, 303, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x25E, 0x100, 0x220, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x248, 0x1F0, 0x68, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x170, 0x268, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x180, 0x2B0, 0, 0, 0, 0 },
    { { { 0x1C26, 1 }, { 0xFFFF, 0 } }, 8, 0x19F, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1231, D_800A5004, EVENT_TEXT(7), NULL, NULL },
    { 415, D_800A4EA4, EVENT_TEXT(0xE), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
