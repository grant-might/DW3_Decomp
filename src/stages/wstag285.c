#include "common.h"
#include "stage.h"

/* Creates the event object of the story so far, the first that applies */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        do {
            if (FLAGS_00.checkCondition(0x4005, 0)) {
                children[0] = FIELDSTG_startEvent(0x28);
                break;
            }
            if (GAME.progress == 0xB) {
                children[0] = FIELDSTG_startEvent(0x110);
                break;
            }
            if (GAME.progress == 0xD && FLAGS_00.checkCondition(0x1C0C, 0)) {
                children[0] = FIELDSTG_startEvent(0x154);
                break;
            }
        } while (0);
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

/* Clears the flag of the story so far */
void func_800A4DCC(void) {
    FLAGS_00.applyAction(0x4005, 0);
}

void func_800A4DF8(void) {
    FLAGS_00.applyAction(0x1C0C, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x2A6
#define STAGE_ARCHIVE 0x31E
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x2B5
#define STAGE_ARCHIVE 0x32D
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x23900, 0x29F00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
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

void func_800A4DCC();
extern Battle D_800A5228;
extern Battle D_800A5234;
extern Battle D_800A5240;
extern Battle D_800A524C;
extern Battle D_800A5258;
extern Battle D_800A5264;
extern Battle D_800A5270;
extern Battle D_800A527C;
extern Battle D_800A52AC;
extern Battle D_800A52B8;
extern Battle D_800A52C4;
extern Battle D_800A52D0;
extern Battle D_800A52DC;
extern Battle D_800A52E8;
extern Battle D_800A52F4;
extern Battle D_800A5300;
extern Battle D_800A5330;
extern Battle D_800A533C;
extern Battle D_800A5348;
extern Battle D_800A5354;
extern Battle D_800A5360;
extern Battle D_800A536C;
extern Battle D_800A5378;
extern Battle D_800A5384;
extern Battle D_800A53B4;
extern Battle D_800A53C0;
extern Battle D_800A53CC;
extern Battle D_800A53D8;
extern Battle D_800A53E4;
extern Battle D_800A53F0;
extern Battle D_800A53FC;
extern Battle D_800A5408;
extern BattleList D_800A5288;
extern BattleList D_800A530C;
extern BattleList D_800A5390;
extern BattleList D_800A5414;
extern u16 D_800A5574[];
extern u16 D_800A5584[];
extern u16 D_800A5590[];
extern u16 D_800A559C[];
extern u16 D_800A55A8[];
extern u16 D_800A5674[];
extern u16 D_800A567C[];
extern FieldTalk D_800A55B4[];
extern u16 D_800A5684[];
extern u16 D_800A568C[];
extern FieldTalk D_800A55CC[];
extern u16 D_800A5694[];
extern u16 D_800A569C[];
extern u16 D_800A56A4[];
extern u16 D_800A56AC[];
extern FieldTalk D_800A55E4[];
extern u16 D_800A56B8[];
extern FieldTalk D_800A55FC[];
extern u16 D_800A56C4[];
extern FieldTalk D_800A5614[];
extern u16 D_800A56D0[];
extern FieldTalk D_800A562C[];
extern u16 D_800A56DC[];
extern FieldTalk D_800A5644[];
extern u16 D_800A56E4[];
extern FieldTalk D_800A565C[];
extern FieldActorEntry D_800A56EC;
extern FieldActorEntry D_800A5700;
extern FieldActorEntry D_800A5714;
extern FieldActorEntry D_800A5728;
extern FieldActorEntry D_800A573C;
extern FieldActorEntry D_800A5750;
extern FieldActorEntry D_800A5764;
extern FieldActorEntry D_800A5778;
extern FieldActorEntry D_800A578C;
extern FieldActorEntry D_800A57A0;
extern FieldActorEntry D_800A57B4;
extern FieldActorEntry D_800A57C8;
extern FieldActorEntry D_800A57DC;
extern s16 D_800A4F6C[];
extern s16 D_800A5030[];
extern s16 D_800A5150[];

s16 D_800A4F6C[] = {
    0x600, 1, 2,
    0x100, 2, 0x1E3, 0x2C6,
    0x101, 2, 1, 5,
    0x100, 0x25, 0x230, 0x2A1,
    0x101, 0x25, 1, 1,
    0x300, 0x78,
    0x102, 2, 0x208, 0x2B4, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0x25,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x25,
    0x300, 0x1E,
    0x102, 0x25, 0x220, 0x2A7, 1,
    0x302, 0x25,
    0x101, 0x25, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0x25, 1,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x1DA, 0x2CC, 1,
    0x302, 2,
    0x601, 1, 0x1DA, 0x2CC,
    0x100, 2, 0, 0,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x304, 0x203, 0x14A, 0xC4, 1,
    0,
};
s16 D_800A5030[] = {
    0x600, 1, 2,
    0x100, 2, 0x1E3, 0x2C6,
    0x101, 2, 1, 5,
    0x100, 0x25, 0x230, 0x2A1,
    0x101, 0x25, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x1F4, 0x2BE, 5,
    0x100, 0xB, 0x1E3, 0x2C6,
    0x101, 0xB, 1, 5,
    0x302, 2,
    0x102, 2, 0x208, 0x2B4, 5,
    0x102, 0xB, 0x1F4, 0x2BE, 5,
    0x101, 0x323, 0x325, 0x25,
    0x300, 0x3C,
    0x101, 2, 1, 5,
    0x101, 0xB, 1, 5,
    0x101, 0x323, 0x326, 0x25,
    0x300, 0x1E,
    0x102, 0x25, 0x220, 0x2A7, 1,
    0x302, 0x25,
    0x101, 0x25, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0x25, 0,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x101, 0xB, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x1FB, 0x2BB, 1,
    0x102, 0xB, 0x1E3, 0x2C6, 1,
    0x302, 2,
    0x102, 2, 0x1DA, 0x2CC, 1,
    0x100, 0xB, 0, 0,
    0x101, 0xB, 1, 1,
    0x302, 2,
    0x601, 1, 0x1DA, 0x2CC,
    0x100, 2, 0, 0,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x304, 0x204, 0x12A, 0x12B, 1,
    0,
};
s16 D_800A5150[] = {
    0x600, 1, 0x6A,
    0x100, 0x25, 0x230, 0x2A1,
    0x101, 0x25, 1, 1,
    0x100, 0x6A, 0x1E3, 0x2C6,
    0x101, 0x6A, 1, 5,
    0x300, 0x1E,
    0x102, 0x6A, 0x208, 0x2B4, 5,
    0x302, 0x6A,
    0x101, 0x6A, 1, 5,
    0x101, 0x323, 0x325, 0x25,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x25,
    0x300, 0x1E,
    0x102, 0x25, 0x220, 0x2A7, 1,
    0x302, 0x25,
    0x101, 0x25, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0x25, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0x6A, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x327, 0x25,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x25,
    0x300, 0x1E,
    0x200, 0, 3, 0x25, 0,
    0x301,
    0x300, 0x1E,
    0x102, 0x25, 0x230, 0x2A1, 5,
    0x302, 0x25,
    0x101, 0x25, 1, 1,
    0x300, 0x1E,
    0,
};
Battle D_800A5228 = { 0, 0, 0x60040000 };
Battle D_800A5234 = { 0, 0, 0x60040000 };
Battle D_800A5240 = { 0, 0, 0x60040000 };
Battle D_800A524C = { 0, 0, 0x60040000 };
Battle D_800A5258 = { 0, 0, 0x60040000 };
Battle D_800A5264 = { 0, 0, 0x60040000 };
Battle D_800A5270 = { 0, 0, 0x60040000 };
Battle D_800A527C = { 0, 0, 0x60040000 };
BattleList D_800A5288 = {
    0,
    { &D_800A5228, &D_800A5234, &D_800A5240, &D_800A524C,
      &D_800A5258, &D_800A5264, &D_800A5270, &D_800A527C },
};
Battle D_800A52AC = { 0, 0, 0x60040000 };
Battle D_800A52B8 = { 0, 0, 0x60040000 };
Battle D_800A52C4 = { 0, 0, 0x60040000 };
Battle D_800A52D0 = { 0, 0, 0x60040000 };
Battle D_800A52DC = { 0, 0, 0x60040000 };
Battle D_800A52E8 = { 0, 0, 0x60040000 };
Battle D_800A52F4 = { 0, 0, 0x60040000 };
Battle D_800A5300 = { 0, 0, 0x60040000 };
BattleList D_800A530C = {
    0,
    { &D_800A52AC, &D_800A52B8, &D_800A52C4, &D_800A52D0,
      &D_800A52DC, &D_800A52E8, &D_800A52F4, &D_800A5300 },
};
Battle D_800A5330 = { 0, 0, 0x60040000 };
Battle D_800A533C = { 0, 0, 0x60040000 };
Battle D_800A5348 = { 0, 0, 0x60040000 };
Battle D_800A5354 = { 0, 0, 0x60040000 };
Battle D_800A5360 = { 0, 0, 0x60040000 };
Battle D_800A536C = { 0, 0, 0x60040000 };
Battle D_800A5378 = { 0, 0, 0x60040000 };
Battle D_800A5384 = { 0, 0, 0x60040000 };
BattleList D_800A5390 = {
    0,
    { &D_800A5330, &D_800A533C, &D_800A5348, &D_800A5354,
      &D_800A5360, &D_800A536C, &D_800A5378, &D_800A5384 },
};
Battle D_800A53B4 = { 189, 15, 0x60080000 };
Battle D_800A53C0 = { 0, 0, 0x60040000 };
Battle D_800A53CC = { 0, 0, 0x60040000 };
Battle D_800A53D8 = { 0, 0, 0x60040000 };
Battle D_800A53E4 = { 0, 0, 0x60040000 };
Battle D_800A53F0 = { 0, 0, 0x60040000 };
Battle D_800A53FC = { 0, 0, 0x60040000 };
Battle D_800A5408 = { 0, 0, 0x60040000 };
BattleList D_800A5414 = {
    0,
    { &D_800A53B4, &D_800A53C0, &D_800A53CC, &D_800A53D8,
      &D_800A53E4, &D_800A53F0, &D_800A53FC, &D_800A5408 },
};
FieldBattles stageBattles[] = {
    { 134, 0, 0, { &D_800A5288, &D_800A530C, &D_800A5390, &D_800A5414 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B2, 0x1B0, 0x1C8, 0xB0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x170, 0x100, 0xC0, 0, 0x160, 0x1FE },
    { 0x140, 0x100, 0x170, 0x130, 0xC0, 0x30, 0x170, 0x1FE },
    { 0x140, 0x100, 0x172, 0x1B1, 0xC8, 0xB1, 0x150, 0x1FD },
    { 0x180, 0x100, 0x180, 0x1BB, 0x100, 0xBB, 0x160, 0x1FD },
    { 0x180, 0x100, 0x1B6, 0x160, 0x1D8, 0x60, 0x170, 0x1FD },
    { 0x180, 0x100, 0x1B6, 0x188, 0x1D8, 0x88, 0x150, 0x1FC },
    { 0x180, 0x100, 0x1A2, 0x1A2, 0x188, 0xA2, 0x160, 0x1FC },
    { 0x180, 0x100, 0x1AA, 0x1A2, 0x1A8, 0xA2, 0x170, 0x1FC },
    { 0x180, 0x100, 0x1B2, 0x100, 0x1C8, 0, 0x150, 0x1FB },
    { 0x180, 0x100, 0x1B2, 0x130, 0x1C8, 0x30, 0x160, 0x1FB },
};
u16 D_800A5574[] = { 0x215, 1, 0x84CF, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5584[] = { 0xC05, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5590[] = { 0x7400, 1, 0xC06, 1, 0xFFFF };
u16 D_800A559C[] = { 0x7400, 1, 0xC07, 1, 0xFFFF };
u16 D_800A55A8[] = { 0x7400, 1, 0xC07, 1, 0xFFFF };
FieldTalk D_800A55B4[] = {
    { NULL, D_800A5574, 0x452 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55CC[] = {
    { NULL, NULL, 0xA6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55E4[] = {
    { NULL, D_800A5584, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55FC[] = {
    { NULL, D_800A5590, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5614[] = {
    { NULL, D_800A559C, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A562C[] = {
    { NULL, D_800A55A8, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5644[] = {
    { NULL, NULL, 0xA7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A565C[] = {
    { NULL, NULL, 0xA8 },
    { NULL, NULL, 0 },
};
u16 D_800A5674[] = { 0x600B, 1, 0xFFFF };
u16 D_800A567C[] = { 0x215, 0, 0xFFFF };
u16 D_800A5684[] = { 0x6002, 1, 0xFFFF };
u16 D_800A568C[] = { 0x7023, 1, 0xFFFF };
u16 D_800A5694[] = { 0x6002, 1, 0xFFFF };
u16 D_800A569C[] = { 0x6002, 1, 0xFFFF };
u16 D_800A56A4[] = { 0x600D, 1, 0xFFFF };
u16 D_800A56AC[] = { 0x6016, 1, 0xC05, 0, 0xFFFF };
u16 D_800A56B8[] = { 0xC06, 0, 0x6016, 1, 0xFFFF };
u16 D_800A56C4[] = { 0x6016, 1, 0xC07, 0, 0xFFFF };
u16 D_800A56D0[] = { 0x6016, 1, 0xC07, 0, 0xFFFF };
u16 D_800A56DC[] = { 0x7023, 1, 0xFFFF };
u16 D_800A56E4[] = { 0x7023, 1, 0xFFFF };
FieldActorEntry D_800A56EC = { D_800A5674, NULL, 0xB, 4, 0, 0, 1 };
FieldActorEntry D_800A5700 = { D_800A567C, D_800A55B4, 0x21, 5, 825, 285, 1 };
FieldActorEntry D_800A5714 = { D_800A5684, NULL, 0x25, 6, 560, 673, 1 };
FieldActorEntry D_800A5728 = { D_800A568C, D_800A55CC, 0x25, 6, 560, 673, 1 };
FieldActorEntry D_800A573C = { D_800A5694, NULL, 0x26, 7, 823, 819, 3 };
FieldActorEntry D_800A5750 = { D_800A569C, NULL, 0x27, 8, 438, 244, 1 };
FieldActorEntry D_800A5764 = { D_800A56A4, NULL, 0x6A, 9, 0, 0, 1 };
FieldActorEntry D_800A5778 = { D_800A56AC, D_800A55E4, 0x132, 0xA, 823, 819, 3 };
FieldActorEntry D_800A578C = { D_800A56B8, D_800A55FC, 0x133, 0xB, 438, 244, 1 };
FieldActorEntry D_800A57A0 = { D_800A56C4, D_800A5614, 0x134, 0xC, 370, 574, 3 };
FieldActorEntry D_800A57B4 = { D_800A56D0, D_800A562C, 0x135, 0xD, 349, 586, 7 };
FieldActorEntry D_800A57C8 = { D_800A56DC, D_800A5644, 0x17D, 0xE, 823, 819, 3 };
FieldActorEntry D_800A57DC = { D_800A56E4, D_800A565C, 0x17E, 0xF, 438, 244, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A56EC,
    &D_800A5700,
    &D_800A5714,
    &D_800A5728,
    &D_800A573C,
    &D_800A5750,
    &D_800A5764,
    &D_800A5778,
    &D_800A578C,
    &D_800A57A0,
    &D_800A57B4,
    &D_800A57C8,
    &D_800A57DC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x36, 2, 0, 5, 8, 0, 437, 121, 0, 0 },
    { 1, 0, 0x78, 2, 0x32, 2, 0, 1, 4, 0, 121, 400, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 1, 4, 0, 104, 383, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 1, 4, 0, 212, 501, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 1, 4, 0, 264, 240, 0, 0 },
    { 1, 0, 0x78, 6, 0x33, 2, 0, 1, 4, 0, 116, 230, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 4, 0, 104, 334, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 4, 0, 212, 215, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 1, 4, 0, 263, 476, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 8, 0, 76, 291, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 8, 0, 152, 217, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 8, 0, 203, 161, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 8, 0, 284, 121, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 8, 0, 748, 208, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 269, 421, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 348, 461, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 429, 501, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 509, 540, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 517, 161, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 597, 201, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 653, 613, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 733, 653, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 813, 693, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 837, 193, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 8, 0, 893, 733, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 5, 8, 0, 554, 542, 0, 0 },
    { 1, 0x64, 0x40, 6, 0xD, 0, 0, 0, 0, 0, 384, 133, 0, 0 },
    { 1, 0, 0x78, 4, 0x32, 2, 0, 1, 4, 0, 172, 373, 385, 0 },
    { 1, 0, 0x40, 4, 0x34, 2, 0, 1, 4, 0, 156, 358, 385, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 833, 737, 808, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 850, 744, 800, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 753, 706, 752, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 672, 666, 712, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 448, 554, 600, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 368, 514, 560, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 288, 474, 520, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 174, 336, 385, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 608, 250, 296, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 528, 210, 256, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 449, 161, 233, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 466, 168, 224, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 408, 135, 186, 0 },
    { 1, 0, 0x78, 4, 0x33, 2, 0, 1, 4, 0, 167, 255, 385, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x217, 0x318, 0x1DC, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x203, 0x14A, 0xC4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x215, 0xC8, 0x7C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 40, D_800A4F6C, EVENT_TEXT(0xA), NULL, NULL },
    { 272, D_800A5030, EVENT_TEXT(0x19), NULL, func_800A4DCC },
    { 340, D_800A5150, EVENT_TEXT(0x1F), NULL, func_800A4DF8 },
    { -1, NULL, 0, NULL, NULL },
};
