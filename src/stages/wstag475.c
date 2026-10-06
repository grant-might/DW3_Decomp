#include "common.h"
#include "stage.h"

/* Creates the event object of the story so far, the first that applies */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 8 && FLAGS_00.checkCondition(0x1A17, 0) && FLAGS_00.checkCondition(0x1C43, 1)) {
            children[0] = FIELDSTG_startEvent(0xB4);
        } else if (GAME.progress == 8 && FLAGS_00.checkCondition(0x1C43, 0)) {
            children[0] = FIELDSTG_startEvent(0xB5);
        } else if (FLAGS_00.checkCondition(0x1A17, 1) && FLAGS_00.checkCondition(0x1A19, 0)) {
            children[0] = FIELDSTG_startEvent(0xBE);
        } else if (FLAGS_00.checkCondition(0x1A17, 1) && FLAGS_00.checkCondition(0x1A19, 1) &&
                   FLAGS_00.checkCondition(0x8015, 0)) {
            children[0] = FIELDSTG_startEvent(0xC8);
        } else if (GAME.progress == 9 && FLAGS_00.checkCondition(0x8015, 1)) {
            children[0] = FIELDSTG_startEvent(0xE6);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void func_800A4EA8(void) {
    FLAGS_00.applyAction(0x1A17, 1);
}

/* Sets the progress to 10 and applies flag action 0x800D */
void func_800A4ED4(void) {
    GAME.progress = 10;
    FLAGS_00.applyAction(0x800D, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x223
#define STAGE_ARCHIVE 0x3CA
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x232
#define STAGE_ARCHIVE 0x3DA
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x8E00, 0x10000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xF;
    D_800990B4.music = 0x603C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
}

void func_800A4ED4();
extern u16 D_800A5648[];
extern u16 D_800A5650[];
extern u16 D_800A5658[];
extern u16 D_800A5660[];
extern u16 D_800A5668[];
extern u16 D_800A5670[];
extern u16 D_800A567C[];
extern u16 D_800A5684[];
extern u16 D_800A57EC[];
extern FieldTalk D_800A5690[];
extern u16 D_800A57F4[];
extern u16 D_800A57FC[];
extern FieldTalk D_800A56B4[];
extern u16 D_800A5804[];
extern FieldTalk D_800A56CC[];
extern u16 D_800A580C[];
extern FieldTalk D_800A56E4[];
extern u16 D_800A5814[];
extern FieldTalk D_800A56FC[];
extern u16 D_800A581C[];
extern FieldTalk D_800A5714[];
extern u16 D_800A5824[];
extern FieldTalk D_800A572C[];
extern u16 D_800A582C[];
extern FieldTalk D_800A5744[];
extern u16 D_800A5834[];
extern FieldTalk D_800A5774[];
extern u16 D_800A583C[];
extern FieldTalk D_800A578C[];
extern u16 D_800A5844[];
extern FieldTalk D_800A57A4[];
extern u16 D_800A584C[];
extern FieldTalk D_800A57BC[];
extern u16 D_800A5854[];
extern FieldTalk D_800A57D4[];
extern u16 D_800A585C[];
extern u16 D_800A5864[];
extern u16 D_800A586C[];
extern FieldActorEntry D_800A5874;
extern FieldActorEntry D_800A5888;
extern FieldActorEntry D_800A589C;
extern FieldActorEntry D_800A58B0;
extern FieldActorEntry D_800A58C4;
extern FieldActorEntry D_800A58D8;
extern FieldActorEntry D_800A58EC;
extern FieldActorEntry D_800A5900;
extern FieldActorEntry D_800A5914;
extern FieldActorEntry D_800A5928;
extern FieldActorEntry D_800A593C;
extern FieldActorEntry D_800A5950;
extern FieldActorEntry D_800A5964;
extern FieldActorEntry D_800A5978;
extern FieldActorEntry D_800A598C;
extern FieldActorEntry D_800A59A0;
extern FieldActorEntry D_800A59B4;
extern FieldActorEntry D_800A59C8;
extern s16 D_800A4FF4[];
extern s16 D_800A50C8[];
extern s16 D_800A520C[];
extern s16 D_800A52C4[];
extern s16 D_800A5344[];
extern s16 D_800A53CC[];

s16 D_800A4FF4[] = {
    0x600, 1, 2,
    0x102, 2, 0xB6, 0x113, 3,
    0x100, 0xC5, 0x76, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 3,
    0x301,
    0x300, 0x1E,
    0x304, 0x237, 0x41E, 0x19E, 1,
    0,
};
s16 D_800A50C8[] = {
    0x600, 1, 2,
    0x100, 2, 0x98, 0x13C,
    0x101, 2, 1, 5,
    0x100, 0xC5, 0x76, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 5,
    0x302, 2,
    0x102, 2, 0xAF, 0x10F, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xC5, 3,
    0x301,
    0x300, 0x3C,
    0x200, 0, 8, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0xC5, 3,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 6, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 7, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 0,
    0x304, 0x237, 0x41E, 0x19E, 1,
    0,
};
s16 D_800A520C[] = {
    0x600, 1, 2,
    0x100, 2, 0x98, 0x13C,
    0x101, 2, 1, 5,
    0x100, 0xC5, 0x67, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 5,
    0x302, 2,
    0x102, 2, 0xAF, 0x10F, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x301,
    0x304, 0x237, 0x41E, 0x19E, 1,
    0,
};
s16 D_800A52C4[] = {
    0x600, 1, 2,
    0x100, 2, 0x98, 0x13C,
    0x101, 2, 1, 5,
    0x100, 0xC5, 0x76, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 5,
    0x302, 2,
    0x102, 2, 0xAF, 0x10F, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 0,
    0x304, 0x237, 0x41E, 0x19E, 1,
    0,
};
s16 D_800A5344[] = {
    0x600, 1, 2,
    0x100, 2, 0x98, 0x13C,
    0x101, 2, 1, 5,
    0x100, 0xC5, 0x76, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 5,
    0x101, 0x32D, 1, 0,
    0x302, 2,
    0x102, 2, 0xAF, 0x10F, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 0,
    0x304, 0x237, 0x41E, 0x19E, 1,
    0,
};
s16 D_800A53CC[] = {
    0x600, 1, 2,
    0x100, 2, 0x98, 0x13C,
    0x101, 2, 1, 5,
    0x100, 0xC5, 0x67, 0x8C,
    0x101, 0xC5, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x12F, 5,
    0x302, 2,
    0x102, 2, 0xAF, 0x10F, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x301,
    0x100, 0x13F, 0x90, 0x101,
    0x101, 0x13F, 1, 7,
    0x300, 0x3C,
    0x200, 0, 2, 0xC5, 3,
    0x301,
    0x300, 0x5A,
    0x200, 0, 3, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0xC5, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 3,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x3C,
    0x100, 0xC5, 0x67, 0xED,
    0x101, 0xC5, 0x46, 7,
    0x303, 0xC5,
    0x101, 0xC5, 1, 7,
    0x300, 0x1E,
    0x200, 0, 0xD, 0xC5, 2,
    0x301,
    0x300, 0x1E,
    0x102, 0xC5, 0x88, 0xFD, 7,
    0x302, 0xC5,
    0x100, 0x84, 0x90, 0x101,
    0x101, 0x84, 1, 7,
    0x100, 0xC5, 0, 0,
    0x101, 0xC5, 1, 0,
    0x100, 0x13F, 0, 0,
    0x101, 0x13F, 1, 7,
    0x101, 0x32D, 0x36D, 2,
    0x300, 0x3C,
    0x200, 0, 7, 0x84, 0,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 8, 0x84, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 9, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xA, 0x84, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xB, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xC, 0x84, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0xAF, 0x141, 0,
    0x300, 6,
    0x304, 0x237, 0x412, 0x1A4, 1,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14C, 0x100, 0x30, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15C, 0x100, 0x70, 0, 0x140, 0x1FE },
};
u16 D_800A5648[] = { 0x1C35, 0, 0xFFFF };
u16 D_800A5650[] = { 0x1C35, 1, 0xFFFF };
u16 D_800A5658[] = { 0x1C35, 1, 0xFFFF };
u16 D_800A5660[] = { 0x7C01, 1, 0xFFFF };
u16 D_800A5668[] = { 0x1A2A, 0, 0xFFFF };
u16 D_800A5670[] = { 0x1A2A, 1, 0x800E, 0, 0xFFFF };
u16 D_800A567C[] = { 0x1A2B, 1, 0xFFFF };
u16 D_800A5684[] = { 0x1A2A, 1, 0x800E, 1, 0xFFFF };
FieldTalk D_800A5690[] = {
    { D_800A5648, D_800A5650, 0x30F },
    { D_800A5658, D_800A5660, 0x35E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56B4[] = {
    { NULL, NULL, 0x124 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56CC[] = {
    { NULL, NULL, 0x126 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56E4[] = {
    { NULL, NULL, 0x127 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56FC[] = {
    { NULL, NULL, 0x129 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5714[] = {
    { NULL, NULL, 0x11F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A572C[] = {
    { NULL, NULL, 0x120 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5744[] = {
    { D_800A5668, NULL, 0x121 },
    { D_800A5670, D_800A567C, 0x2ED },
    { D_800A5684, NULL, 0x2EE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5774[] = {
    { NULL, NULL, 0x122 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A578C[] = {
    { NULL, NULL, 0x123 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57A4[] = {
    { NULL, NULL, 0x128 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57BC[] = {
    { NULL, NULL, 0x125 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57D4[] = {
    { NULL, NULL, 0x125 },
    { NULL, NULL, 0 },
};
u16 D_800A57EC[] = { 0x7093, 1, 0xFFFF };
u16 D_800A57F4[] = { 0x6009, 1, 0xFFFF };
u16 D_800A57FC[] = { 0x6018, 1, 0xFFFF };
u16 D_800A5804[] = { 0x7019, 1, 0xFFFF };
u16 D_800A580C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5814[] = { 0x602B, 1, 0xFFFF };
u16 D_800A581C[] = { 0x600A, 1, 0xFFFF };
u16 D_800A5824[] = { 0x600C, 1, 0xFFFF };
u16 D_800A582C[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5834[] = { 0x7016, 1, 0xFFFF };
u16 D_800A583C[] = { 0x7017, 1, 0xFFFF };
u16 D_800A5844[] = { 0x701A, 1, 0xFFFF };
u16 D_800A584C[] = { 0x6019, 1, 0xFFFF };
u16 D_800A5854[] = { 0x601A, 1, 0xFFFF };
u16 D_800A585C[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5864[] = { 0x6007, 1, 0xFFFF };
u16 D_800A586C[] = { 0x6009, 1, 0xFFFF };
FieldActorEntry D_800A5874 = { D_800A57EC, D_800A5690, 0x3D, 4, 288, 296, 1 };
FieldActorEntry D_800A5888 = { D_800A57F4, NULL, 0x84, 5, 0, 0, 7 };
FieldActorEntry D_800A589C = { D_800A57FC, D_800A56B4, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A58B0 = { D_800A5804, D_800A56CC, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A58C4 = { D_800A580C, D_800A56E4, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A58D8 = { D_800A5814, D_800A56FC, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A58EC = { D_800A581C, D_800A5714, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A5900 = { D_800A5824, D_800A572C, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A5914 = { D_800A582C, D_800A5744, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A5928 = { D_800A5834, D_800A5774, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A593C = { D_800A583C, D_800A578C, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A5950 = { D_800A5844, D_800A57A4, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A5964 = { D_800A584C, D_800A57BC, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A5978 = { D_800A5854, D_800A57D4, 0x84, 5, 144, 257, 7 };
FieldActorEntry D_800A598C = { D_800A585C, NULL, 0xC5, 6, 0, 0, 1 };
FieldActorEntry D_800A59A0 = { D_800A5864, NULL, 0xC5, 6, 0, 0, 1 };
FieldActorEntry D_800A59B4 = { D_800A586C, NULL, 0xC5, 6, 0, 0, 1 };
FieldActorEntry D_800A59C8 = { NULL, NULL, 0x13F, 7, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5874,
    &D_800A5888,
    &D_800A589C,
    &D_800A58B0,
    &D_800A58C4,
    &D_800A58D8,
    &D_800A58EC,
    &D_800A5900,
    &D_800A5914,
    &D_800A5928,
    &D_800A593C,
    &D_800A5950,
    &D_800A5964,
    &D_800A5978,
    &D_800A598C,
    &D_800A59A0,
    &D_800A59B4,
    &D_800A59C8,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x37, 0xA, 0, 216, 262, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3D, 0xA, 0, 72, 170, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x43, 0xA, 0, 348, 225, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x43, 0xA, 0, 355, 229, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x237, 0x412, 0x1A4, 1, 0, 0, 0 },
    { { { 0x6007, 1 }, { 0xFFFF, 0 } }, 8, 0xA0, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 160, D_800A4FF4, EVENT_TEXT(7), NULL, NULL },
    { 180, D_800A50C8, EVENT_TEXT(0xA), NULL, func_800A4EA8 },
    { 181, D_800A520C, EVENT_TEXT(0xB), NULL, NULL },
    { 190, D_800A52C4, EVENT_TEXT(0xC), NULL, NULL },
    { 200, D_800A5344, EVENT_TEXT(0xD), NULL, NULL },
    { 230, D_800A53CC, EVENT_TEXT(0xE), NULL, func_800A4ED4 },
    { -1, NULL, 0, NULL, NULL },
};
