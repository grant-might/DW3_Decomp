#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x4DA
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x4EA
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xB700, 0x10900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F98[];
extern FieldTalk D_800A4F08[];
extern u16 D_800A4FA0[];
extern FieldTalk D_800A4F20[];
extern u16 D_800A4FA8[];
extern FieldTalk D_800A4F38[];
extern u16 D_800A4FB0[];
extern FieldTalk D_800A4F50[];
extern u16 D_800A4FBC[];
extern FieldTalk D_800A4F68[];
extern u16 D_800A4FC8[];
extern FieldTalk D_800A4F80[];
extern u16 D_800A4FD0[];
extern u16 D_800A4FD8[];
extern u16 D_800A4FE0[];
extern FieldActorEntry D_800A4FE8;
extern FieldActorEntry D_800A4FFC;
extern FieldActorEntry D_800A5010;
extern FieldActorEntry D_800A5024;
extern FieldActorEntry D_800A5038;
extern FieldActorEntry D_800A504C;
extern FieldActorEntry D_800A5060;
extern FieldActorEntry D_800A5074;
extern FieldActorEntry D_800A5088;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x14A, 0x100, 0x28, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x160, 0x1FE },
    { 0x140, 0x100, 0x15C, 0x100, 0x70, 0, 0x170, 0x1FE },
    { 0x140, 0x100, 0x164, 0x100, 0x90, 0, 0x140, 0x1FD },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
FieldTalk D_800A4F08[] = {
    { NULL, NULL, 0x65 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F20[] = {
    { NULL, NULL, 0x66 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F38[] = {
    { NULL, NULL, 0x67 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F50[] = {
    { NULL, NULL, 0x63 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F68[] = {
    { NULL, NULL, 0x62 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A4F80[] = {
    { NULL, NULL, 0x64 },
    { NULL, NULL, 0 },
};
u16 D_800A4F98[] = { 0x602B, 1, 0xFFFF };
u16 D_800A4FA0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A4FA8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A4FB0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A4FBC[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A4FC8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A4FD0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A4FD8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A4FE0[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A4FE8 = { D_800A4F98, D_800A4F08, 0x28, 4, 135, 212, 7 };
FieldActorEntry D_800A4FFC = { D_800A4FA0, D_800A4F20, 0x29, 5, 173, 155, 7 };
FieldActorEntry D_800A5010 = { D_800A4FA8, D_800A4F38, 0x2A, 6, 56, 193, 1 };
FieldActorEntry D_800A5024 = { D_800A4FB0, D_800A4F50, 0x39, 7, 224, 169, 7 };
FieldActorEntry D_800A5038 = { D_800A4FBC, D_800A4F68, 0x9D, 8, 224, 169, 7 };
FieldActorEntry D_800A504C = { D_800A4FC8, D_800A4F80, 0x9D, 8, 224, 169, 7 };
FieldActorEntry D_800A5060 = { D_800A4FD0, NULL, 0xDD, 9, 184, 173, 7 };
FieldActorEntry D_800A5074 = { D_800A4FD8, NULL, 0xDE, 0xA, 143, 240, 7 };
FieldActorEntry D_800A5088 = { D_800A4FE0, NULL, 0xDF, 0xB, 64, 224, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A4FE8,
    &D_800A4FFC,
    &D_800A5010,
    &D_800A5024,
    &D_800A5038,
    &D_800A504C,
    &D_800A5060,
    &D_800A5074,
    &D_800A5088,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 62, 115, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 124, 173, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 218, 227, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 242, 146, 0, 0 },
    { 1, 0, 0x40, 2, 0, 2, 0, 1, 4, 0, 295, 210, 0, 0 },
    { 1, 0, 0x40, 2, 1, 2, 0, 1, 4, 0, 227, 130, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x279, 0xD8, 0x54, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x100, 0xF6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0xF0, 0xBF, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x120, 0xF6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x12F, 0xAE, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
