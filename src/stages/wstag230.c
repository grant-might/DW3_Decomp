#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF0
#define STAGE_FILE 0x193
#define STAGE_ARCHIVE 0x386
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define STAGE_FILE 0x1A1
#define STAGE_ARCHIVE 0x396
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0xDE00, 0xDE00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x14 && GAME.progress < 0x18) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern u16 D_800A52D4[];
extern FieldTalk D_800A4F5C[];
extern u16 D_800A52DC[];
extern FieldTalk D_800A4F74[];
extern u16 D_800A52E4[];
extern FieldTalk D_800A4F8C[];
extern u16 D_800A52EC[];
extern FieldTalk D_800A4FA4[];
extern u16 D_800A52F4[];
extern FieldTalk D_800A4FBC[];
extern u16 D_800A52FC[];
extern FieldTalk D_800A4FD4[];
extern u16 D_800A5304[];
extern FieldTalk D_800A4FEC[];
extern u16 D_800A530C[];
extern FieldTalk D_800A5004[];
extern u16 D_800A5314[];
extern FieldTalk D_800A501C[];
extern u16 D_800A531C[];
extern FieldTalk D_800A5034[];
extern u16 D_800A5324[];
extern FieldTalk D_800A504C[];
extern u16 D_800A532C[];
extern FieldTalk D_800A5064[];
extern u16 D_800A5334[];
extern u16 D_800A533C[];
extern u16 D_800A5344[];
extern u16 D_800A534C[];
extern FieldTalk D_800A507C[];
extern u16 D_800A5354[];
extern FieldTalk D_800A5094[];
extern u16 D_800A535C[];
extern FieldTalk D_800A50AC[];
extern u16 D_800A5364[];
extern FieldTalk D_800A50C4[];
extern u16 D_800A536C[];
extern FieldTalk D_800A50DC[];
extern u16 D_800A5374[];
extern FieldTalk D_800A50F4[];
extern u16 D_800A537C[];
extern FieldTalk D_800A510C[];
extern u16 D_800A5384[];
extern FieldTalk D_800A5124[];
extern u16 D_800A538C[];
extern FieldTalk D_800A513C[];
extern u16 D_800A5394[];
extern FieldTalk D_800A5154[];
extern u16 D_800A539C[];
extern FieldTalk D_800A516C[];
extern u16 D_800A53A4[];
extern FieldTalk D_800A5184[];
extern u16 D_800A53AC[];
extern FieldTalk D_800A519C[];
extern u16 D_800A53B4[];
extern FieldTalk D_800A51B4[];
extern u16 D_800A53BC[];
extern FieldTalk D_800A51CC[];
extern u16 D_800A53C4[];
extern FieldTalk D_800A51E4[];
extern u16 D_800A53CC[];
extern FieldTalk D_800A51FC[];
extern u16 D_800A53D4[];
extern FieldTalk D_800A5214[];
extern u16 D_800A53DC[];
extern FieldTalk D_800A522C[];
extern u16 D_800A53E4[];
extern FieldTalk D_800A5244[];
extern u16 D_800A53EC[];
extern FieldTalk D_800A525C[];
extern u16 D_800A53F4[];
extern FieldTalk D_800A5274[];
extern u16 D_800A53FC[];
extern u16 D_800A5404[];
extern FieldTalk D_800A528C[];
extern u16 D_800A540C[];
extern FieldTalk D_800A52A4[];
extern u16 D_800A5414[];
extern FieldTalk D_800A52BC[];
extern u16 D_800A541C[];
extern FieldActorEntry D_800A5424;
extern FieldActorEntry D_800A5438;
extern FieldActorEntry D_800A544C;
extern FieldActorEntry D_800A5460;
extern FieldActorEntry D_800A5474;
extern FieldActorEntry D_800A5488;
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

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x148, 0xD0, 0x48, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15C, 0x161, 0x70, 0x61, 0x160, 0x1FE },
    { 0x140, 0x100, 0x164, 0x161, 0x90, 0x61, 0x170, 0x1FE },
    { 0x140, 0x100, 0x174, 0x170, 0xD0, 0x70, 0x150, 0x1FD },
    { 0x140, 0x100, 0x140, 0x175, 0, 0x75, 0x160, 0x1FD },
    { 0x140, 0x100, 0x148, 0x175, 0x20, 0x75, 0x170, 0x1FD },
    { 0x140, 0x100, 0x150, 0x175, 0x40, 0x75, 0x150, 0x1FC },
    { 0x140, 0x100, 0x16C, 0x181, 0xB0, 0x81, 0x160, 0x1FC },
    { 0x140, 0x100, 0x158, 0x189, 0x60, 0x89, 0x170, 0x1FC },
};
FieldTalk D_800A4F5C[] = {
    { NULL, NULL, 0x1C9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F74[] = {
    { NULL, NULL, 0x1B2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F8C[] = {
    { NULL, NULL, 0x1B3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FA4[] = {
    { NULL, NULL, 0x151 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FBC[] = {
    { NULL, NULL, 0x1B4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FD4[] = {
    { NULL, NULL, 0x1B5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FEC[] = {
    { NULL, NULL, 0x1B6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5004[] = {
    { NULL, NULL, 0x1B7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A501C[] = {
    { NULL, NULL, 0x1B8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5034[] = {
    { NULL, NULL, 0x1B9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A504C[] = {
    { NULL, NULL, 0x1C6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5064[] = {
    { NULL, NULL, 0x1C8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A507C[] = {
    { NULL, NULL, 0x1CA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5094[] = {
    { NULL, NULL, 0x1D0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50AC[] = {
    { NULL, NULL, 0x1CB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50C4[] = {
    { NULL, NULL, 0x1CD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50DC[] = {
    { NULL, NULL, 0x1DB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A50F4[] = {
    { NULL, NULL, 0x1EE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A510C[] = {
    { NULL, NULL, 0x1EF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5124[] = {
    { NULL, NULL, 0x1CC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A513C[] = {
    { NULL, NULL, 0x1CE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5154[] = {
    { NULL, NULL, 0x1CF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A516C[] = {
    { NULL, NULL, 0x1F1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5184[] = {
    { NULL, NULL, 0x1F2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A519C[] = {
    { NULL, NULL, 0x1F8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51B4[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51CC[] = {
    { NULL, NULL, 0x1F5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51E4[] = {
    { NULL, NULL, 0x1F9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A51FC[] = {
    { NULL, NULL, 0x1FA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5214[] = {
    { NULL, NULL, 0x1FB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A522C[] = {
    { NULL, NULL, 0x1F4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5244[] = {
    { NULL, NULL, 0x1F6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A525C[] = {
    { NULL, NULL, 0x1F7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5274[] = {
    { NULL, NULL, 0x1FD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A528C[] = {
    { NULL, NULL, 0x1FC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52A4[] = {
    { NULL, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52BC[] = {
    { NULL, NULL, 0x1C7 },
    { NULL, NULL, 0 },
};
u16 D_800A52D4[] = { 0x6002, 1, 0xFFFF };
u16 D_800A52DC[] = { 0x7015, 1, 0xFFFF };
u16 D_800A52E4[] = { 0x600C, 1, 0xFFFF };
u16 D_800A52EC[] = { 0x6004, 1, 0xFFFF };
u16 D_800A52F4[] = { 0x600D, 1, 0xFFFF };
u16 D_800A52FC[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5304[] = { 0x7016, 1, 0xFFFF };
u16 D_800A530C[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5314[] = { 0x7018, 1, 0xFFFF };
u16 D_800A531C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5324[] = { 0x6026, 1, 0xFFFF };
u16 D_800A532C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5334[] = { 0x7022, 1, 0xFFFF };
u16 D_800A533C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5344[] = { 0x6002, 1, 0xFFFF };
u16 D_800A534C[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5354[] = { 0x6016, 1, 0xFFFF };
u16 D_800A535C[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5364[] = { 0x600D, 1, 0xFFFF };
u16 D_800A536C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5374[] = { 0x7019, 1, 0xFFFF };
u16 D_800A537C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5384[] = { 0x600C, 1, 0xFFFF };
u16 D_800A538C[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5394[] = { 0x7016, 1, 0xFFFF };
u16 D_800A539C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A53A4[] = { 0x6004, 1, 0xFFFF };
u16 D_800A53AC[] = { 0x6016, 1, 0xFFFF };
u16 D_800A53B4[] = { 0x7015, 1, 0xFFFF };
u16 D_800A53BC[] = { 0x600D, 1, 0xFFFF };
u16 D_800A53C4[] = { 0x7018, 1, 0xFFFF };
u16 D_800A53CC[] = { 0x7019, 1, 0xFFFF };
u16 D_800A53D4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A53DC[] = { 0x600C, 1, 0xFFFF };
u16 D_800A53E4[] = { 0x600E, 1, 0xFFFF };
u16 D_800A53EC[] = { 0x7016, 1, 0xFFFF };
u16 D_800A53F4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A53FC[] = { 0x600D, 1, 0xFFFF };
u16 D_800A5404[] = { 0x701A, 1, 0xFFFF };
u16 D_800A540C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5414[] = { 0x701A, 1, 0xFFFF };
u16 D_800A541C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5424 = { D_800A52D4, D_800A4F5C, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A5438 = { D_800A52DC, D_800A4F74, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A544C = { D_800A52E4, D_800A4F8C, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A5460 = { D_800A52EC, D_800A4FA4, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A5474 = { D_800A52F4, D_800A4FBC, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A5488 = { D_800A52FC, D_800A4FD4, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A549C = { D_800A5304, D_800A4FEC, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A54B0 = { D_800A530C, D_800A5004, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A54C4 = { D_800A5314, D_800A501C, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A54D8 = { D_800A531C, D_800A5034, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A54EC = { D_800A5324, D_800A504C, 0x20, 4, 277, 344, 7 };
FieldActorEntry D_800A5500 = { D_800A532C, D_800A5064, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A5514 = { D_800A5334, NULL, 0x24, 5, 240, 329, 3 };
FieldActorEntry D_800A5528 = { D_800A533C, NULL, 0x24, 5, 240, 329, 3 };
FieldActorEntry D_800A553C = { D_800A5344, NULL, 0x24, 5, 240, 329, 3 };
FieldActorEntry D_800A5550 = { D_800A534C, D_800A507C, 0x34, 6, 352, 239, 1 };
FieldActorEntry D_800A5564 = { D_800A5354, D_800A5094, 0x34, 6, 352, 239, 1 };
FieldActorEntry D_800A5578 = { D_800A535C, D_800A50AC, 0x34, 6, 352, 239, 1 };
FieldActorEntry D_800A558C = { D_800A5364, D_800A50C4, 0x34, 6, 352, 239, 1 };
FieldActorEntry D_800A55A0 = { D_800A536C, D_800A50DC, 0x34, 6, 352, 239, 1 };
FieldActorEntry D_800A55B4 = { D_800A5374, D_800A50F4, 0x34, 6, 352, 239, 1 };
FieldActorEntry D_800A55C8 = { D_800A537C, D_800A510C, 0x34, 6, 352, 239, 1 };
FieldActorEntry D_800A55DC = { D_800A5384, D_800A5124, 0x34, 6, 352, 239, 1 };
FieldActorEntry D_800A55F0 = { D_800A538C, D_800A513C, 0x34, 6, 352, 239, 1 };
FieldActorEntry D_800A5604 = { D_800A5394, D_800A5154, 0x34, 6, 352, 239, 1 };
FieldActorEntry D_800A5618 = { D_800A539C, D_800A516C, 0x34, 6, 237, 202, 3 };
FieldActorEntry D_800A562C = { D_800A53A4, D_800A5184, 0x39, 7, 237, 202, 3 };
FieldActorEntry D_800A5640 = { D_800A53AC, D_800A519C, 0x39, 7, 237, 202, 3 };
FieldActorEntry D_800A5654 = { D_800A53B4, D_800A51B4, 0x39, 7, 237, 202, 3 };
FieldActorEntry D_800A5668 = { D_800A53BC, D_800A51CC, 0x39, 7, 237, 202, 3 };
FieldActorEntry D_800A567C = { D_800A53C4, D_800A51E4, 0x39, 7, 237, 202, 3 };
FieldActorEntry D_800A5690 = { D_800A53CC, D_800A51FC, 0x39, 7, 237, 202, 3 };
FieldActorEntry D_800A56A4 = { D_800A53D4, D_800A5214, 0x39, 7, 237, 202, 3 };
FieldActorEntry D_800A56B8 = { D_800A53DC, D_800A522C, 0x39, 7, 237, 202, 3 };
FieldActorEntry D_800A56CC = { D_800A53E4, D_800A5244, 0x39, 7, 237, 202, 3 };
FieldActorEntry D_800A56E0 = { D_800A53EC, D_800A525C, 0x39, 7, 237, 202, 3 };
FieldActorEntry D_800A56F4 = { D_800A53F4, D_800A5274, 0x39, 7, 240, 327, 3 };
FieldActorEntry D_800A5708 = { D_800A53FC, NULL, 0x6A, 8, 0, 0, 1 };
FieldActorEntry D_800A571C = { D_800A5404, D_800A528C, 0x9D, 9, 237, 202, 3 };
FieldActorEntry D_800A5730 = { D_800A540C, D_800A52A4, 0x9E, 0xA, 352, 239, 1 };
FieldActorEntry D_800A5744 = { D_800A5414, D_800A52BC, 0x9F, 0xB, 272, 344, 7 };
FieldActorEntry D_800A5758 = { D_800A541C, NULL, 0xA0, 0xC, 240, 329, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A5424,
    &D_800A5438,
    &D_800A544C,
    &D_800A5460,
    &D_800A5474,
    &D_800A5488,
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
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 192, 256, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 144, 104, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 168, 92, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 224, 64, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 127, 112, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 127, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 159, 96, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 159, 128, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 191, 80, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 191, 112, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 223, 64, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 0xB, 8, 0, 223, 96, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 0xB, 8, 0, 196, 289, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 0xB, 8, 0, 226, 274, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 0xB, 8, 0, 212, 266, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 0xB, 8, 0, 212, 281, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 0xB, 8, 0, 196, 275, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 0xB, 8, 0, 226, 260, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 1, 0x37, 0x39, 0xA, 0, 200, 290, 0, 0 },
    { 1, 0, 0x40, 6, 2, 0, 0, 0, 0, 0, 256, 336, 0, 0 },
    { 1, 0, 0x40, 4, 0x3A, 1, 0x3A, 0x3C, 0xA, 0, 256, 286, 315, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 304, 312, 329, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 256, 280, 315, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x203, 0x200, 0x11C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
