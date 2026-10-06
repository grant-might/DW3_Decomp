#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x6ED
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x6FD
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x9100, 0x16C00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xE;
    D_800990B4.music = 0x60380000;
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

extern u16 D_800A5010[];
extern FieldTalk D_800A4F50[];
extern u16 D_800A501C[];
extern FieldTalk D_800A4F68[];
extern u16 D_800A5028[];
extern FieldTalk D_800A4F80[];
extern u16 D_800A5030[];
extern FieldTalk D_800A4F98[];
extern u16 D_800A5038[];
extern FieldTalk D_800A4FB0[];
extern u16 D_800A5044[];
extern FieldTalk D_800A4FC8[];
extern u16 D_800A504C[];
extern FieldTalk D_800A4FE0[];
extern u16 D_800A5058[];
extern FieldTalk D_800A4FF8[];
extern FieldActorEntry D_800A5060;
extern FieldActorEntry D_800A5074;
extern FieldActorEntry D_800A5088;
extern FieldActorEntry D_800A509C;
extern FieldActorEntry D_800A50B0;
extern FieldActorEntry D_800A50C4;
extern FieldActorEntry D_800A50D8;
extern FieldActorEntry D_800A50EC;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x168, 0x130, 0xA0, 0x30, 0x170, 0x1FE },
    { 0x140, 0x100, 0x140, 0x14A, 0, 0x4A, 0x160, 0x1FD },
    { 0x140, 0x100, 0x150, 0x14A, 0x40, 0x4A, 0x170, 0x1FD },
    { 0x140, 0x100, 0x158, 0x150, 0x60, 0x50, 0x160, 0x1FC },
    { 0x140, 0x100, 0x160, 0x150, 0x80, 0x50, 0x170, 0x1FC },
    { 0x140, 0x100, 0x170, 0x150, 0xC0, 0x50, 0x160, 0x1FB },
};
FieldTalk D_800A4F50[] = {
    { NULL, NULL, 0xA2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F68[] = {
    { NULL, NULL, 0x9F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F80[] = {
    { NULL, NULL, 0xA4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F98[] = {
    { NULL, NULL, 0xA5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FB0[] = {
    { NULL, NULL, 0x9E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FC8[] = {
    { NULL, NULL, 0xA0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FE0[] = {
    { NULL, NULL, 0xA1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4FF8[] = {
    { NULL, NULL, 0xA3 },
    { NULL, NULL, 0 },
};
u16 D_800A5010[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A501C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5028[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5030[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5038[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5044[] = { 0x701A, 1, 0xFFFF };
u16 D_800A504C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5058[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5060 = { D_800A5010, D_800A4F50, 0x31, 4, 145, 329, 5 };
FieldActorEntry D_800A5074 = { D_800A501C, D_800A4F68, 0x32, 5, 177, 313, 7 };
FieldActorEntry D_800A5088 = { D_800A5028, D_800A4F80, 0x39, 6, 177, 313, 7 };
FieldActorEntry D_800A509C = { D_800A5030, D_800A4F98, 0x3A, 7, 145, 329, 5 };
FieldActorEntry D_800A50B0 = { D_800A5038, D_800A4FB0, 0x9D, 8, 177, 313, 7 };
FieldActorEntry D_800A50C4 = { D_800A5044, D_800A4FC8, 0x9D, 8, 177, 313, 7 };
FieldActorEntry D_800A50D8 = { D_800A504C, D_800A4FE0, 0x9E, 9, 145, 329, 5 };
FieldActorEntry D_800A50EC = { D_800A5058, D_800A4FF8, 0x9E, 9, 145, 329, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A5060,
    &D_800A5074,
    &D_800A5088,
    &D_800A509C,
    &D_800A50B0,
    &D_800A50C4,
    &D_800A50D8,
    &D_800A50EC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 9, 0, 435, 247, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 1, 0x33, 0x38, 9, 0, 443, 254, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x3F, 6, 0, 377, 384, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 482, 177, 200, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A1, 0x208, 0x9C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
