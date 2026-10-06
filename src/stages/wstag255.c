#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF0
#define STAGE_FILE 0x19D
#define STAGE_ARCHIVE 0x3C0
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define STAGE_FILE 0x1AB
#define STAGE_ARCHIVE 0x3D0
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x10B00, 0x12C00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 8;
    D_800990B4.music = 0x60200000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
}

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
extern u16 D_800A4F7C[];
extern u16 D_800A5314[];
extern FieldTalk D_800A4F84[];
extern u16 D_800A531C[];
extern FieldTalk D_800A4F9C[];
extern u16 D_800A5324[];
extern FieldTalk D_800A4FC0[];
extern u16 D_800A532C[];
extern FieldTalk D_800A4FD8[];
extern u16 D_800A5334[];
extern FieldTalk D_800A4FF0[];
extern u16 D_800A533C[];
extern FieldTalk D_800A5014[];
extern u16 D_800A5344[];
extern FieldTalk D_800A502C[];
extern u16 D_800A534C[];
extern FieldTalk D_800A5044[];
extern u16 D_800A5354[];
extern FieldTalk D_800A505C[];
extern u16 D_800A5364[];
extern FieldTalk D_800A5074[];
extern u16 D_800A536C[];
extern FieldTalk D_800A508C[];
extern u16 D_800A5374[];
extern FieldTalk D_800A50A4[];
extern u16 D_800A5380[];
extern FieldTalk D_800A50BC[];
extern u16 D_800A538C[];
extern FieldTalk D_800A50D4[];
extern u16 D_800A5398[];
extern FieldTalk D_800A50F8[];
extern u16 D_800A53A4[];
extern FieldTalk D_800A5110[];
extern u16 D_800A53B0[];
extern FieldTalk D_800A5128[];
extern u16 D_800A53BC[];
extern FieldTalk D_800A514C[];
extern u16 D_800A53C8[];
extern FieldTalk D_800A5164[];
extern u16 D_800A53D4[];
extern FieldTalk D_800A517C[];
extern u16 D_800A53E0[];
extern FieldTalk D_800A5194[];
extern u16 D_800A53EC[];
extern FieldTalk D_800A51AC[];
extern u16 D_800A53F8[];
extern FieldTalk D_800A51C4[];
extern u16 D_800A5404[];
extern FieldTalk D_800A51DC[];
extern u16 D_800A540C[];
extern FieldTalk D_800A51F4[];
extern u16 D_800A5414[];
extern FieldTalk D_800A520C[];
extern u16 D_800A541C[];
extern FieldTalk D_800A5224[];
extern u16 D_800A5424[];
extern FieldTalk D_800A523C[];
extern u16 D_800A542C[];
extern FieldTalk D_800A5254[];
extern u16 D_800A5434[];
extern FieldTalk D_800A526C[];
extern u16 D_800A543C[];
extern FieldTalk D_800A5284[];
extern u16 D_800A5444[];
extern FieldTalk D_800A529C[];
extern u16 D_800A544C[];
extern FieldTalk D_800A52B4[];
extern u16 D_800A5454[];
extern u16 D_800A545C[];
extern u16 D_800A5464[];
extern FieldTalk D_800A52CC[];
extern u16 D_800A546C[];
extern u16 D_800A5474[];
extern FieldTalk D_800A52E4[];
extern u16 D_800A547C[];
extern FieldTalk D_800A52FC[];
extern u16 D_800A5484[];
extern u16 D_800A548C[];
extern u16 D_800A5494[];
extern FieldActorEntry D_800A549C;
extern FieldActorEntry D_800A54B0;
extern FieldActorEntry D_800A54C4;
extern FieldActorEntry D_800A54D8;
extern FieldActorEntry D_800A54EC;
extern FieldActorEntry D_800A5500;
extern FieldActorEntry D_800A5514;
extern FieldActorEntry D_800A5528;
extern FieldActorEntry D_800A553C;
extern FieldActorEntry D_800A5550;
extern FieldActorEntry D_800A5564;
extern FieldActorEntry D_800A5578;
extern FieldActorEntry D_800A558C;
extern FieldActorEntry D_800A55A0;
extern FieldActorEntry D_800A55B4;
extern FieldActorEntry D_800A55C8;
extern FieldActorEntry D_800A55DC;
extern FieldActorEntry D_800A55F0;
extern FieldActorEntry D_800A5604;
extern FieldActorEntry D_800A5618;
extern FieldActorEntry D_800A562C;
extern FieldActorEntry D_800A5640;
extern FieldActorEntry D_800A5654;
extern FieldActorEntry D_800A5668;
extern FieldActorEntry D_800A567C;
extern FieldActorEntry D_800A5690;
extern FieldActorEntry D_800A56A4;
extern FieldActorEntry D_800A56B8;
extern FieldActorEntry D_800A56CC;
extern FieldActorEntry D_800A56E0;
extern FieldActorEntry D_800A56F4;
extern FieldActorEntry D_800A5708;
extern FieldActorEntry D_800A571C;
extern FieldActorEntry D_800A5730;
extern FieldActorEntry D_800A5744;
extern FieldActorEntry D_800A5758;
extern FieldActorEntry D_800A576C;
extern FieldActorEntry D_800A5780;
extern FieldActorEntry D_800A5794;
extern FieldActorEntry D_800A57A8;
extern FieldActorEntry D_800A57BC;
extern FieldActorEntry D_800A57D0;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x178, 0xB8, 0x78, 0x150, 0x1FF },
    { 0x140, 0x100, 0x140, 0x158, 0, 0x58, 0x160, 0x1FF },
    { 0x140, 0x100, 0x176, 0x178, 0xD8, 0x78, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15A, 0x162, 0x68, 0x62, 0x150, 0x1FE },
    { 0x140, 0x100, 0x152, 0x17A, 0x48, 0x7A, 0x160, 0x1FE },
    { 0x140, 0x100, 0x140, 0x180, 0, 0x80, 0x170, 0x1FE },
    { 0x140, 0x100, 0x164, 0x183, 0x90, 0x83, 0x150, 0x1FD },
    { 0x140, 0x100, 0x15A, 0x18A, 0x68, 0x8A, 0x160, 0x1FD },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A4F2C[] = { 0x1A0C, 0, 0xFFFF };
u16 D_800A4F34[] = { 0x1A0C, 1, 0xFFFF };
u16 D_800A4F3C[] = { 0x1A0C, 1, 0xFFFF };
u16 D_800A4F44[] = { 0x1A18, 0, 0xFFFF };
u16 D_800A4F4C[] = { 0x1A18, 1, 0xFFFF };
u16 D_800A4F54[] = { 0x1A25, 0, 0xFFFF };
u16 D_800A4F5C[] = { 0x1A25, 1, 0xFFFF };
u16 D_800A4F64[] = { 0x1A25, 1, 0xFFFF };
u16 D_800A4F6C[] = { 0x1A25, 0, 0xFFFF };
u16 D_800A4F74[] = { 0x1A25, 1, 0xFFFF };
u16 D_800A4F7C[] = { 0x1A25, 1, 0xFFFF };
FieldTalk D_800A4F84[] = {
    { NULL, NULL, 0x243 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F9C[] = {
    { D_800A4F2C, D_800A4F34, 0x23D },
    { D_800A4F3C, NULL, 0x4C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FC0[] = {
    { NULL, NULL, 0x23E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FD8[] = {
    { NULL, NULL, 0x23F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FF0[] = {
    { D_800A4F44, NULL, 0x23C },
    { D_800A4F4C, NULL, 0x4A9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5014[] = {
    { NULL, NULL, 0x240 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A502C[] = {
    { NULL, NULL, 0x2C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5044[] = {
    { NULL, NULL, 0x241 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A505C[] = {
    { NULL, NULL, 0x23C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5074[] = {
    { NULL, NULL, 0x242 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A508C[] = {
    { NULL, NULL, 0x4A9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50A4[] = {
    { NULL, NULL, 0x22D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50BC[] = {
    { NULL, NULL, 0x229 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50D4[] = {
    { D_800A4F54, D_800A4F5C, 0xB7 },
    { D_800A4F64, NULL, 0xB8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50F8[] = {
    { NULL, NULL, 0x22E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5110[] = {
    { NULL, NULL, 0x2D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5128[] = {
    { D_800A4F6C, D_800A4F74, 0xB7 },
    { D_800A4F7C, NULL, 0xB8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A514C[] = {
    { NULL, NULL, 0x22F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5164[] = {
    { NULL, NULL, 0x230 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A517C[] = {
    { NULL, NULL, 0x22A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5194[] = {
    { NULL, NULL, 0x22B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51AC[] = {
    { NULL, NULL, 0x22C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51C4[] = {
    { NULL, NULL, 0x232 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51DC[] = {
    { NULL, NULL, 0x236 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51F4[] = {
    { NULL, NULL, 0x239 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A520C[] = {
    { NULL, NULL, 0x2E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5224[] = {
    { NULL, NULL, 0x23B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A523C[] = {
    { NULL, NULL, 0x228 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5254[] = {
    { NULL, NULL, 0x237 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A526C[] = {
    { NULL, NULL, 0x238 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5284[] = {
    { NULL, NULL, 0x233 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A529C[] = {
    { NULL, NULL, 0x234 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52B4[] = {
    { NULL, NULL, 0x235 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52CC[] = {
    { NULL, NULL, 0x244 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52E4[] = {
    { NULL, NULL, 0x23A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52FC[] = {
    { NULL, NULL, 0x231 },
    { NULL, NULL, 0 },
};
u16 D_800A5314[] = { 0x6026, 1, 0xFFFF };
u16 D_800A531C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5324[] = { 0x600E, 1, 0xFFFF };
u16 D_800A532C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5334[] = { 0x6008, 1, 0xFFFF };
u16 D_800A533C[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5344[] = { 0x6004, 1, 0xFFFF };
u16 D_800A534C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5354[] = { 0x7015, 1, 0x6008, 0, 0x6009, 0, 0xFFFF };
u16 D_800A5364[] = { 0x7019, 1, 0xFFFF };
u16 D_800A536C[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5374[] = { 0x6016, 1, 0x1C08, 0, 0xFFFF };
u16 D_800A5380[] = { 0x7015, 1, 0x1C08, 0, 0xFFFF };
u16 D_800A538C[] = { 0x602B, 1, 0x1C08, 1, 0xFFFF };
u16 D_800A5398[] = { 0x7018, 1, 0x1C08, 0, 0xFFFF };
u16 D_800A53A4[] = { 0x6004, 1, 0x1C08, 0, 0xFFFF };
u16 D_800A53B0[] = { 0x7022, 1, 0x1C08, 1, 0xFFFF };
u16 D_800A53BC[] = { 0x7019, 1, 0x1C08, 0, 0xFFFF };
u16 D_800A53C8[] = { 0x6026, 1, 0x1C08, 0, 0xFFFF };
u16 D_800A53D4[] = { 0x600C, 1, 0x1C08, 0, 0xFFFF };
u16 D_800A53E0[] = { 0x600E, 1, 0x1C08, 0, 0xFFFF };
u16 D_800A53EC[] = { 0x7016, 1, 0x1C08, 0, 0xFFFF };
u16 D_800A53F8[] = { 0x602B, 1, 0x1C08, 0, 0xFFFF };
u16 D_800A5404[] = { 0x6016, 1, 0xFFFF };
u16 D_800A540C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5414[] = { 0x6004, 1, 0xFFFF };
u16 D_800A541C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5424[] = { 0x7015, 1, 0xFFFF };
u16 D_800A542C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5434[] = { 0x7019, 1, 0xFFFF };
u16 D_800A543C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5444[] = { 0x600E, 1, 0xFFFF };
u16 D_800A544C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5454[] = { 0x602B, 1, 0xFFFF };
u16 D_800A545C[] = { 0x7022, 1, 0xFFFF };
u16 D_800A5464[] = { 0x701A, 1, 0xFFFF };
u16 D_800A546C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5474[] = { 0x701A, 1, 0xFFFF };
u16 D_800A547C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5484[] = { 0x602B, 1, 0xFFFF };
u16 D_800A548C[] = { 0x7022, 1, 0xFFFF };
u16 D_800A5494[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A549C = { D_800A5314, D_800A4F84, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A54B0 = { D_800A531C, D_800A4F9C, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A54C4 = { D_800A5324, D_800A4FC0, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A54D8 = { D_800A532C, D_800A4FD8, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A54EC = { D_800A5334, D_800A4FF0, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A5500 = { D_800A533C, D_800A5014, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A5514 = { D_800A5344, D_800A502C, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A5528 = { D_800A534C, D_800A5044, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A553C = { D_800A5354, D_800A505C, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A5550 = { D_800A5364, D_800A5074, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A5564 = { D_800A536C, D_800A508C, 0x19, 4, 275, 255, 1 };
FieldActorEntry D_800A5578 = { D_800A5374, D_800A50A4, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A558C = { D_800A5380, D_800A50BC, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A55A0 = { D_800A538C, D_800A50D4, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A55B4 = { D_800A5398, D_800A50F8, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A55C8 = { D_800A53A4, D_800A5110, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A55DC = { D_800A53B0, D_800A5128, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A55F0 = { D_800A53BC, D_800A514C, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A5604 = { D_800A53C8, D_800A5164, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A5618 = { D_800A53D4, D_800A517C, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A562C = { D_800A53E0, D_800A5194, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A5640 = { D_800A53EC, D_800A51AC, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A5654 = { D_800A53F8, D_800A51C4, 0x1A, 5, 256, 321, 1 };
FieldActorEntry D_800A5668 = { D_800A5404, D_800A51DC, 0x35, 6, 217, 257, 5 };
FieldActorEntry D_800A567C = { D_800A540C, D_800A51F4, 0x35, 6, 217, 257, 5 };
FieldActorEntry D_800A5690 = { D_800A5414, D_800A520C, 0x35, 6, 217, 257, 5 };
FieldActorEntry D_800A56A4 = { D_800A541C, D_800A5224, 0x35, 6, 101, 203, 3 };
FieldActorEntry D_800A56B8 = { D_800A5424, D_800A523C, 0x35, 6, 217, 257, 5 };
FieldActorEntry D_800A56CC = { D_800A542C, D_800A5254, 0x35, 6, 217, 257, 5 };
FieldActorEntry D_800A56E0 = { D_800A5434, D_800A526C, 0x35, 6, 217, 257, 5 };
FieldActorEntry D_800A56F4 = { D_800A543C, D_800A5284, 0x35, 6, 217, 257, 5 };
FieldActorEntry D_800A5708 = { D_800A5444, D_800A529C, 0x35, 6, 217, 257, 5 };
FieldActorEntry D_800A571C = { D_800A544C, D_800A52B4, 0x35, 6, 217, 257, 5 };
FieldActorEntry D_800A5730 = { D_800A5454, NULL, 0x44, 7, 307, 240, 5 };
FieldActorEntry D_800A5744 = { D_800A545C, NULL, 0x44, 7, 307, 240, 5 };
FieldActorEntry D_800A5758 = { D_800A5464, D_800A52CC, 0x9D, 8, 275, 255, 1 };
FieldActorEntry D_800A576C = { D_800A546C, NULL, 0x9E, 9, 307, 240, 5 };
FieldActorEntry D_800A5780 = { D_800A5474, D_800A52E4, 0x9F, 0xA, 217, 257, 5 };
FieldActorEntry D_800A5794 = { D_800A547C, D_800A52FC, 0xA0, 0xB, 256, 321, 1 };
FieldActorEntry D_800A57A8 = { D_800A5484, NULL, 0xE0, 0xC, 259, 263, 1 };
FieldActorEntry D_800A57BC = { D_800A548C, NULL, 0xE0, 0xC, 259, 263, 1 };
FieldActorEntry D_800A57D0 = { D_800A5494, NULL, 0x10E, 0xD, 259, 263, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A549C,
    &D_800A54B0,
    &D_800A54C4,
    &D_800A54D8,
    &D_800A54EC,
    &D_800A5500,
    &D_800A5514,
    &D_800A5528,
    &D_800A553C,
    &D_800A5550,
    &D_800A5564,
    &D_800A5578,
    &D_800A558C,
    &D_800A55A0,
    &D_800A55B4,
    &D_800A55C8,
    &D_800A55DC,
    &D_800A55F0,
    &D_800A5604,
    &D_800A5618,
    &D_800A562C,
    &D_800A5640,
    &D_800A5654,
    &D_800A5668,
    &D_800A567C,
    &D_800A5690,
    &D_800A56A4,
    &D_800A56B8,
    &D_800A56CC,
    &D_800A56E0,
    &D_800A56F4,
    &D_800A5708,
    &D_800A571C,
    &D_800A5730,
    &D_800A5744,
    &D_800A5758,
    &D_800A576C,
    &D_800A5780,
    &D_800A5794,
    &D_800A57A8,
    &D_800A57BC,
    &D_800A57D0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 115, 131, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 163, 107, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 227, 75, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 280, 73, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 328, 97, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 376, 121, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 2, 0, 2, 4, 0, 117, 147, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 2, 0, 2, 4, 0, 165, 124, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 2, 0, 2, 4, 0, 229, 92, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 2, 0, 2, 4, 0, 259, 90, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 2, 0, 2, 4, 0, 307, 115, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 2, 0, 2, 4, 0, 355, 139, 0, 0 },
    { 1, 0x64, 0x40, 6, 0xF, 0, 0, 0, 0, 0, 350, 125, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 192, 271, 301, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 184, 263, 288, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 152, 216, 233, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 178, 254, 277, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 280, 256, 280, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 264, 248, 271, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 248, 240, 264, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 232, 232, 256, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 217, 222, 248, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 312, 231, 263, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 332, 222, 253, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x200, 0x112, 0x220, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20A, 0x68, 0x15A, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
