#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x4A4
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x4B4
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xDB00, 0xDF00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern u16 D_800A501C[];
extern FieldTalk D_800A4F5C[];
extern u16 D_800A5028[];
extern FieldTalk D_800A4F74[];
extern u16 D_800A5030[];
extern u16 D_800A503C[];
extern u16 D_800A5044[];
extern FieldTalk D_800A4F8C[];
extern u16 D_800A5050[];
extern FieldTalk D_800A4FA4[];
extern u16 D_800A5058[];
extern FieldTalk D_800A4FBC[];
extern u16 D_800A5060[];
extern FieldTalk D_800A4FD4[];
extern u16 D_800A5068[];
extern FieldTalk D_800A4FEC[];
extern u16 D_800A5074[];
extern u16 D_800A5080[];
extern FieldTalk D_800A5004[];
extern FieldActorEntry D_800A508C;
extern FieldActorEntry D_800A50A0;
extern FieldActorEntry D_800A50B4;
extern FieldActorEntry D_800A50C8;
extern FieldActorEntry D_800A50DC;
extern FieldActorEntry D_800A50F0;
extern FieldActorEntry D_800A5104;
extern FieldActorEntry D_800A5118;
extern FieldActorEntry D_800A512C;
extern FieldActorEntry D_800A5140;
extern FieldActorEntry D_800A5154;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x15C, 0x161, 0x70, 0x61, 0x170, 0x1FF },
    { 0x140, 0x100, 0x164, 0x161, 0x90, 0x61, 0x160, 0x1FE },
    { 0x140, 0x100, 0x174, 0x148, 0xD0, 0x48, 0x170, 0x1FE },
    { 0x140, 0x100, 0x170, 0x198, 0xC0, 0x98, 0x150, 0x1FD },
    { 0x140, 0x100, 0x16C, 0x161, 0xB0, 0x61, 0x160, 0x1FD },
    { 0x140, 0x100, 0x140, 0x175, 0, 0x75, 0x170, 0x1FD },
    { 0x140, 0x100, 0x150, 0x175, 0x40, 0x75, 0x150, 0x1FC },
    { 0x140, 0x100, 0x174, 0x178, 0xD0, 0x78, 0x160, 0x1FC },
    { 0x140, 0x100, 0x158, 0x189, 0x60, 0x89, 0x170, 0x1FC },
};
FieldTalk D_800A4F5C[] = {
    { NULL, NULL, 0x1AC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F74[] = {
    { NULL, NULL, 0x1B0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F8C[] = {
    { NULL, NULL, 0x1AD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FA4[] = {
    { NULL, NULL, 0x1B1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FBC[] = {
    { NULL, NULL, 0x1B2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FD4[] = {
    { NULL, NULL, 0x1B3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FEC[] = {
    { NULL, NULL, 0x1AE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5004[] = {
    { NULL, NULL, 0x1AF },
    { NULL, NULL, 0 },
};
u16 D_800A501C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5028[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5030[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A503C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5044[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5050[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5058[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5060[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5068[] = { 0x1A0A, 0, 0x700A, 1, 0xFFFF };
u16 D_800A5074[] = { 0x700A, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5080[] = { 0x700A, 1, 0x1A0A, 0, 0xFFFF };
FieldActorEntry D_800A508C = { D_800A501C, D_800A4F5C, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A50A0 = { D_800A5028, D_800A4F74, 0x20, 4, 272, 344, 7 };
FieldActorEntry D_800A50B4 = { D_800A5030, NULL, 0x24, 5, 240, 329, 3 };
FieldActorEntry D_800A50C8 = { D_800A503C, NULL, 0x24, 5, 240, 329, 3 };
FieldActorEntry D_800A50DC = { D_800A5044, D_800A4F8C, 0x25, 6, 237, 202, 3 };
FieldActorEntry D_800A50F0 = { D_800A5050, D_800A4FA4, 0x2D, 7, 288, 176, 1 };
FieldActorEntry D_800A5104 = { D_800A5058, D_800A4FBC, 0x30, 8, 352, 239, 1 };
FieldActorEntry D_800A5118 = { D_800A5060, D_800A4FD4, 0x36, 9, 237, 202, 3 };
FieldActorEntry D_800A512C = { D_800A5068, D_800A4FEC, 0x9D, 0xA, 272, 344, 7 };
FieldActorEntry D_800A5140 = { D_800A5074, NULL, 0x9E, 0xB, 240, 329, 3 };
FieldActorEntry D_800A5154 = { D_800A5080, D_800A5004, 0x9F, 0xC, 237, 202, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A508C,
    &D_800A50A0,
    &D_800A50B4,
    &D_800A50C8,
    &D_800A50DC,
    &D_800A50F0,
    &D_800A5104,
    &D_800A5118,
    &D_800A512C,
    &D_800A5140,
    &D_800A5154,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x273, 0x200, 0x11C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
