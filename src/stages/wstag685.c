#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 0xF */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0xF) {
            children[0] = FIELDSTG_startEvent(0x19D);
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

void func_800A4D78(void) {
    GAME.progress = 16;
}

void func_800A4D88(void) {
    FLAGS_00.applyAction(0x4020, 1);
}

void func_800A4DB4(void) {
    GAME.progress = 25;
}

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x4B4
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x4C4
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x23700, 0x1AF00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3C;
    D_800990B4.music = 0x60F00000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A536C[];
extern u16 D_800A5374[];
extern u16 D_800A537C[];
extern u16 D_800A5384[];
extern u16 D_800A5390[];
extern u16 D_800A5398[];
extern u16 D_800A53A4[];
extern u16 D_800A53AC[];
extern u16 D_800A53B4[];
extern u16 D_800A53BC[];
extern u16 D_800A53C4[];
extern u16 D_800A563C[];
extern u16 D_800A5644[];
extern FieldTalk D_800A53CC[];
extern u16 D_800A564C[];
extern FieldTalk D_800A53E4[];
extern u16 D_800A5654[];
extern FieldTalk D_800A53FC[];
extern u16 D_800A565C[];
extern FieldTalk D_800A5414[];
extern FieldTalk D_800A542C[];
extern u16 D_800A5664[];
extern FieldTalk D_800A5450[];
extern u16 D_800A566C[];
extern FieldTalk D_800A5474[];
extern u16 D_800A5674[];
extern FieldTalk D_800A548C[];
extern u16 D_800A567C[];
extern FieldTalk D_800A54A4[];
extern u16 D_800A5684[];
extern FieldTalk D_800A54C8[];
extern u16 D_800A568C[];
extern FieldTalk D_800A54E0[];
extern u16 D_800A5694[];
extern u16 D_800A569C[];
extern FieldTalk D_800A54F8[];
extern u16 D_800A56A4[];
extern FieldTalk D_800A551C[];
extern u16 D_800A56AC[];
extern FieldTalk D_800A5534[];
extern u16 D_800A56B4[];
extern FieldTalk D_800A554C[];
extern u16 D_800A56BC[];
extern FieldTalk D_800A5564[];
extern u16 D_800A56C4[];
extern FieldTalk D_800A557C[];
extern u16 D_800A56CC[];
extern FieldTalk D_800A5594[];
extern u16 D_800A56D4[];
extern FieldTalk D_800A55AC[];
extern u16 D_800A56DC[];
extern u16 D_800A56E4[];
extern FieldTalk D_800A55C4[];
extern u16 D_800A56EC[];
extern FieldTalk D_800A55DC[];
extern u16 D_800A56F4[];
extern FieldTalk D_800A55F4[];
extern u16 D_800A56FC[];
extern FieldTalk D_800A560C[];
extern u16 D_800A5704[];
extern FieldTalk D_800A5624[];
extern FieldActorEntry D_800A570C;
extern FieldActorEntry D_800A5720;
extern FieldActorEntry D_800A5734;
extern FieldActorEntry D_800A5748;
extern FieldActorEntry D_800A575C;
extern FieldActorEntry D_800A5770;
extern FieldActorEntry D_800A5784;
extern FieldActorEntry D_800A5798;
extern FieldActorEntry D_800A57AC;
extern FieldActorEntry D_800A57C0;
extern FieldActorEntry D_800A57D4;
extern FieldActorEntry D_800A57E8;
extern FieldActorEntry D_800A57FC;
extern FieldActorEntry D_800A5810;
extern FieldActorEntry D_800A5824;
extern FieldActorEntry D_800A5838;
extern FieldActorEntry D_800A584C;
extern FieldActorEntry D_800A5860;
extern FieldActorEntry D_800A5874;
extern FieldActorEntry D_800A5888;
extern FieldActorEntry D_800A589C;
extern FieldActorEntry D_800A58B0;
extern FieldActorEntry D_800A58C4;
extern FieldActorEntry D_800A58D8;
extern FieldActorEntry D_800A58EC;
extern FieldActorEntry D_800A5900;
extern FieldActorEntry D_800A5914;
extern s16 D_800A4EB4[];
extern s16 D_800A4F54[];
extern s16 D_800A5050[];

s16 D_800A4EB4[] = {
    0x100, 1, 0x330, 0x108,
    0x101, 1, 0x10, 7,
    0x100, 0x11F, 0x340, 0x10D,
    0x101, 0x11F, 1, 7,
    0x300, 0x3C,
    0x101, 0x32D, 0x37E, 1,
    0x300, 0x3C,
    0x101, 1, 0x27, 7,
    0x303, 1,
    0x101, 1, 0x26, 7,
    0x100, 0x11F, 0, 0,
    0x101, 0x11F, 1, 0,
    0x303, 1,
    0x101, 1, 1, 7,
    0x300, 0x1E,
    0x101, 1, 0x3A, 7,
    0x300, 0x5A,
    0x200, 0, 1, 1, 2,
    0x101, 1, 1, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 1, 2,
    0x301,
    0x304, 0x260, 0x330, 0x108, 1,
    0,
};
s16 D_800A4F54[] = {
    0x102, 2, 0x3D5, 0x147, 5,
    0x100, 0x69, 0x415, 0x127,
    0x101, 0x69, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 1,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x600, 0, 0x69,
    0x200, 0, 2, 0x69, 0,
    0x301,
    0x300, 0x1E,
    0x600, 0, 2,
    0x200, 0, 3, 2, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0x69, 1, 1,
    0x300, 0x1E,
    0x102, 0x69, 0x3F5, 0x137, 1,
    0x302, 0x69,
    0x200, 0, 4, 0x69, 0,
    0x101, 0x69, 1, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x69, 0,
    0x301,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x41E, 0x122, 5,
    0x102, 0x69, 0x41E, 0x122, 5,
    0x300, 6,
    0x304, 0x24C, 0x64, 0x64, 0,
    0,
};
s16 D_800A5050[] = {
    0x102, 2, 0x248, 0x1B4, 1,
    0x100, 0x98, 0x230, 0x1C1,
    0x101, 0x98, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x101, 0x323, 0x325, 0x98,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x98,
    0x300, 0x1E,
    0x200, 0, 1, 0x98, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 3, 0x98, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 5, 0x98, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 7, 0x98, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 8, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 9, 0x98, 1,
    0x301,
    0x101, 0x98, 1, 7,
    0x300, 0x3C,
    0x102, 2, 0x248, 0x164, 4,
    0x302, 2,
    0x101, 2, 1, 3,
    0x101, 0x323, 0x327, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 0xA, 2, 0,
    0x301,
    0x102, 2, 0x1C8, 0x106, 3,
    0x300, 0x3C,
    0x304, 0x25E, 0x290, 0x1F0, 1,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x1A6, 0, 0xA6, 0x150, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x158, 0xB8, 0x58, 0x160, 0x1FF },
    { 0x140, 0x100, 0x176, 0x158, 0xD8, 0x58, 0x170, 0x1FF },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x164, 0x180, 0x90, 0x80, 0x150, 0x1FE },
    { 0x140, 0x100, 0x16C, 0x188, 0xB0, 0x88, 0x160, 0x1FE },
    { 0x140, 0x100, 0x15E, 0x1A8, 0x78, 0xA8, 0x170, 0x1FE },
    { 0x140, 0x100, 0x174, 0x188, 0xD0, 0x88, 0x140, 0x1FD },
    { 0x140, 0x100, 0x166, 0x1B0, 0x98, 0xB0, 0x150, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x1B0, 0xB8, 0xB0, 0x160, 0x1FD },
    { 0x140, 0x100, 0x176, 0x1B0, 0xD8, 0xB0, 0x170, 0x1FD },
    { 0x140, 0x100, 0x148, 0x1B5, 0x20, 0xB5, 0x140, 0x1FC },
    { 0x140, 0x100, 0x150, 0x1BD, 0x40, 0xBD, 0x150, 0x1FC },
    { 0x140, 0x100, 0x168, 0x1D0, 0xA0, 0xD0, 0x160, 0x1FC },
    { 0x140, 0x100, 0x14E, 0x18D, 0x38, 0x8D, 0x170, 0x1FC },
    { 0x140, 0x100, 0x156, 0x195, 0x58, 0x95, 0x140, 0x1FB },
    { 0x140, 0x100, 0x140, 0x1C6, 0, 0xC6, 0x150, 0x1FB },
    { 0x140, 0x100, 0x158, 0x1C8, 0x60, 0xC8, 0x160, 0x1FB },
    { 0x140, 0x100, 0x160, 0x1D0, 0x80, 0xD0, 0x170, 0x1FB },
};
u16 D_800A536C[] = { 0x6010, 1, 0xFFFF };
u16 D_800A5374[] = { 0x7008, 1, 0xFFFF };
u16 D_800A537C[] = { 0x6018, 1, 0xFFFF };
u16 D_800A5384[] = { 0x6018, 0, 0x7018, 1, 0xFFFF };
u16 D_800A5390[] = { 0x6018, 1, 0xFFFF };
u16 D_800A5398[] = { 0x7018, 1, 0x6018, 0, 0xFFFF };
u16 D_800A53A4[] = { 0x6018, 0, 0xFFFF };
u16 D_800A53AC[] = { 0x6018, 1, 0xFFFF };
u16 D_800A53B4[] = { 0x9043, 1, 0xFFFF };
u16 D_800A53BC[] = { 0x1A03, 1, 0xFFFF };
u16 D_800A53C4[] = { 0x1A03, 1, 0xFFFF };
FieldTalk D_800A53CC[] = {
    { NULL, NULL, 0x13A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53E4[] = {
    { NULL, NULL, 0x13C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53FC[] = {
    { NULL, NULL, 0x13B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5414[] = {
    { NULL, NULL, 0x13D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A542C[] = {
    { D_800A536C, NULL, 0x140 },
    { D_800A5374, NULL, 0x12A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5450[] = {
    { D_800A537C, NULL, 0x172 },
    { D_800A5384, NULL, 0x12B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5474[] = {
    { NULL, NULL, 0x12E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A548C[] = {
    { NULL, NULL, 0x131 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54A4[] = {
    { D_800A5390, NULL, 0x173 },
    { D_800A5398, NULL, 0x12C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54C8[] = {
    { NULL, NULL, 0x12F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E0[] = {
    { NULL, NULL, 0x132 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54F8[] = {
    { D_800A53A4, NULL, 0x12D },
    { D_800A53AC, D_800A53B4, 0x171 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A551C[] = {
    { NULL, NULL, 0x130 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5534[] = {
    { NULL, NULL, 0x133 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A554C[] = {
    { NULL, NULL, 0x136 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5564[] = {
    { NULL, NULL, 0x134 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A557C[] = {
    { NULL, NULL, 0x135 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5594[] = {
    { NULL, NULL, 0x13E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55AC[] = {
    { NULL, NULL, 0x13F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55C4[] = {
    { NULL, D_800A53BC, 0x129 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55DC[] = {
    { NULL, D_800A53C4, 0x15C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55F4[] = {
    { NULL, NULL, 0x137 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A560C[] = {
    { NULL, NULL, 0x138 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5624[] = {
    { NULL, NULL, 0x139 },
    { NULL, NULL, 0 },
};
u16 D_800A563C[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5644[] = { 0x7004, 1, 0xFFFF };
u16 D_800A564C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5654[] = { 0x7004, 1, 0xFFFF };
u16 D_800A565C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5664[] = { 0x7018, 1, 0xFFFF };
u16 D_800A566C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5674[] = { 0x6026, 1, 0xFFFF };
u16 D_800A567C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5684[] = { 0x7019, 1, 0xFFFF };
u16 D_800A568C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5694[] = { 0x6010, 1, 0xFFFF };
u16 D_800A569C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A56A4[] = { 0x7019, 1, 0xFFFF };
u16 D_800A56AC[] = { 0x6026, 1, 0xFFFF };
u16 D_800A56B4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A56BC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A56C4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A56CC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A56D4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A56DC[] = { 0x600F, 1, 0xFFFF };
u16 D_800A56E4[] = { 0x6010, 1, 0xFFFF };
u16 D_800A56EC[] = { 0x6010, 1, 0xFFFF };
u16 D_800A56F4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A56FC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5704[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A570C = { D_800A563C, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry D_800A5720 = { D_800A5644, D_800A53CC, 0x25, 5, 386, 129, 1 };
FieldActorEntry D_800A5734 = { D_800A564C, D_800A53E4, 0x25, 5, 386, 129, 1 };
FieldActorEntry D_800A5748 = { D_800A5654, D_800A53FC, 0x26, 6, 415, 145, 7 };
FieldActorEntry D_800A575C = { D_800A565C, D_800A5414, 0x26, 6, 415, 145, 7 };
FieldActorEntry D_800A5770 = { NULL, D_800A542C, 0x3F, 7, 1040, 298, 1 };
FieldActorEntry D_800A5784 = { D_800A5664, D_800A5450, 0x45, 8, 561, 305, 1 };
FieldActorEntry D_800A5798 = { D_800A566C, D_800A5474, 0x45, 8, 561, 305, 1 };
FieldActorEntry D_800A57AC = { D_800A5674, D_800A548C, 0x45, 8, 561, 305, 1 };
FieldActorEntry D_800A57C0 = { D_800A567C, D_800A54A4, 0x46, 9, 993, 321, 5 };
FieldActorEntry D_800A57D4 = { D_800A5684, D_800A54C8, 0x46, 9, 993, 321, 5 };
FieldActorEntry D_800A57E8 = { D_800A568C, D_800A54E0, 0x46, 9, 993, 321, 5 };
FieldActorEntry D_800A57FC = { D_800A5694, NULL, 0x69, 0xA, 1045, 295, 5 };
FieldActorEntry D_800A5810 = { D_800A569C, D_800A54F8, 0x98, 0xB, 560, 449, 7 };
FieldActorEntry D_800A5824 = { D_800A56A4, D_800A551C, 0x98, 0xB, 560, 449, 7 };
FieldActorEntry D_800A5838 = { D_800A56AC, D_800A5534, 0x98, 0xB, 560, 449, 7 };
FieldActorEntry D_800A584C = { D_800A56B4, D_800A554C, 0x9D, 0xC, 560, 449, 7 };
FieldActorEntry D_800A5860 = { D_800A56BC, D_800A5564, 0x9E, 0xD, 561, 305, 1 };
FieldActorEntry D_800A5874 = { D_800A56C4, D_800A557C, 0x9F, 0xE, 993, 321, 5 };
FieldActorEntry D_800A5888 = { D_800A56CC, D_800A5594, 0xA0, 0xF, 386, 129, 1 };
FieldActorEntry D_800A589C = { D_800A56D4, D_800A55AC, 0xA1, 0x10, 415, 145, 7 };
FieldActorEntry D_800A58B0 = { D_800A56DC, NULL, 0x11F, 0x11, 0, 0, 1 };
FieldActorEntry D_800A58C4 = { D_800A56E4, D_800A55C4, 0x132, 0x12, 328, 142, 7 };
FieldActorEntry D_800A58D8 = { D_800A56EC, D_800A55DC, 0x133, 0x13, 354, 128, 7 };
FieldActorEntry D_800A58EC = { D_800A56F4, D_800A55F4, 0x16D, 0x14, 825, 269, 7 };
FieldActorEntry D_800A5900 = { D_800A56FC, D_800A560C, 0x16F, 0x15, 560, 449, 7 };
FieldActorEntry D_800A5914 = { D_800A5704, D_800A5624, 0x171, 0x16, 561, 305, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A570C,
    &D_800A5720,
    &D_800A5734,
    &D_800A5748,
    &D_800A575C,
    &D_800A5770,
    &D_800A5784,
    &D_800A5798,
    &D_800A57AC,
    &D_800A57C0,
    &D_800A57D4,
    &D_800A57E8,
    &D_800A57FC,
    &D_800A5810,
    &D_800A5824,
    &D_800A5838,
    &D_800A584C,
    &D_800A5860,
    &D_800A5874,
    &D_800A5888,
    &D_800A589C,
    &D_800A58B0,
    &D_800A58C4,
    &D_800A58D8,
    &D_800A58EC,
    &D_800A5900,
    &D_800A5914,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 177, 76, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 244, 43, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 6, 0, 350, 54, 0, 0 },
    { 1, 0, 0x80, 6, 4, 0, 0, 0, 0, 0, 390, 289, 0, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 1025, 223, 307, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 492, 452, 508, 0 },
    { 1, 0, 0x42, 4, 2, 0, 0, 0, 0, 0, 625, 443, 501, 0 },
    { 1, 0, 0x5B, 4, 3, 0, 0, 0, 0, 0, 639, 378, 454, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x25E, 0x290, 0x1F0, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 9, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x1C4, 0xA0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x1D5, 0x12C, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x1BF, 0x150, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x1AF, 0x198, 0, 0, 0, 0 },
    { { { 0x1A03, 1 }, { 0x6010, 1 } }, 8, 0x1A5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 413, D_800A4EB4, EVENT_TEXT(3), NULL, func_800A4D78 },
    { 421, D_800A4F54, EVENT_TEXT(4), NULL, func_800A4D88 },
    { 690, D_800A5050, EVENT_TEXT(0x1B), NULL, func_800A4DB4 },
    { -1, NULL, 0, NULL, NULL },
};
