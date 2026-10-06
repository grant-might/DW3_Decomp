#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 17 or 18, the first that applies */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        do {
            if (GAME.progress == 0x11 && FLAGS_00.checkCondition(0x403C, 0)) {
                children[0] = FIELDSTG_startEvent(0x1B8);
                break;
            }
            if (GAME.progress == 0x12 && FLAGS_00.checkCondition(0x4038, 0)) {
                children[0] = FIELDSTG_startEvent(0x208);
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

void func_800A4DC8(void) {
    FLAGS_00.applyAction(0x403C, 1);
    FLAGS_00.applyAction(0x1C1F, 1);
}

void func_800A4E14(void) {
    FLAGS_00.applyAction(0x4021, 1);
    FLAGS_00.applyAction(0x1C20, 1);
}

void func_800A4E60(void) {
    FLAGS_00.applyAction(0x4034, 1);
    FLAGS_00.applyAction(0x1C22, 1);
}

void func_800A4EAC(void) {
    FLAGS_00.applyAction(0x4035, 1);
    FLAGS_00.applyAction(0x1C23, 1);
}

void func_800A4EF8(void) {
    FLAGS_00.applyAction(0x4036, 1);
    FLAGS_00.applyAction(0x1C24, 1);
}

void func_800A4F44(void) {
    FLAGS_00.applyAction(0x4037, 1);
    FLAGS_00.applyAction(0x1C25, 1);
}

void func_800A4F90(void) {
    FLAGS_00.applyAction(0x4038, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x771
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x780
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xF600, 0x3B200};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x39;
    D_800990B4.music = 0x60E40000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A57BC;
extern Battle D_800A57C8;
extern Battle D_800A57D4;
extern Battle D_800A57E0;
extern Battle D_800A57EC;
extern Battle D_800A57F8;
extern Battle D_800A5804;
extern Battle D_800A5810;
extern Battle D_800A5840;
extern Battle D_800A584C;
extern Battle D_800A5858;
extern Battle D_800A5864;
extern Battle D_800A5870;
extern Battle D_800A587C;
extern Battle D_800A5888;
extern Battle D_800A5894;
extern Battle D_800A58C4;
extern Battle D_800A58D0;
extern Battle D_800A58DC;
extern Battle D_800A58E8;
extern Battle D_800A58F4;
extern Battle D_800A5900;
extern Battle D_800A590C;
extern Battle D_800A5918;
extern Battle D_800A5948;
extern Battle D_800A5954;
extern Battle D_800A5960;
extern Battle D_800A596C;
extern Battle D_800A5978;
extern Battle D_800A5984;
extern Battle D_800A5990;
extern Battle D_800A599C;
extern BattleList D_800A581C;
extern BattleList D_800A58A0;
extern BattleList D_800A5924;
extern BattleList D_800A59A8;
extern u16 D_800A5A68[];
extern u16 D_800A5A74[];
extern u16 D_800A5A84[];
extern u16 D_800A5A94[];
extern u16 D_800A5AA4[];
extern u16 D_800A5AB4[];
extern u16 D_800A5AC0[];
extern u16 D_800A5AC8[];
extern FieldActorEntry D_800A5AD4;
extern FieldActorEntry D_800A5AE8;
extern FieldActorEntry D_800A5AFC;
extern FieldActorEntry D_800A5B10;
extern FieldActorEntry D_800A5B24;
extern FieldActorEntry D_800A5B38;
extern FieldActorEntry D_800A5B4C;
extern FieldActorEntry D_800A5B60;
extern s16 D_800A50CC[];
extern s16 D_800A5210[];
extern s16 D_800A52EC[];
extern s16 D_800A542C[];
extern s16 D_800A54F8[];
extern s16 D_800A55C8[];
extern s16 D_800A56A4[];

s16 D_800A50CC[] = {
    0x600, 1, 2,
    0x100, 2, 0x70, 0x400,
    0x101, 2, 1, 5,
    0x100, 0x11D, 0x1C7, 0x3BB,
    0x101, 0x11D, 1, 3,
    0x300, 0x1E,
    0x102, 2, 0xD5, 0x3CE, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0x101, 0x3B8,
    0x102, 0x11D, 0x160, 0x387, 3,
    0x302, 0x11D,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 5,
    0x101, 0x11D, 1, 3,
    0x301,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0x11D,
    0x300, 0x3C,
    0x101, 0x11D, 1, 1,
    0x101, 0x323, 0x326, 0x69,
    0x300, 0x1E,
    0x200, 0, 2, 0x11D, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x11D, 1,
    0x301,
    0x101, 0x11D, 1, 5,
    0x300, 0x1E,
    0x102, 0x11D, 0x1A7, 0x363, 5,
    0x302, 0x11D,
    0x200, 0, 5, 2, 0,
    0x101, 2, 7, 5,
    0x100, 0x11D, 0, 0,
    0x101, 0x11D, 1, 0,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x600, 0, 2,
    0x300, 0x3C,
    0,
};
s16 D_800A5210[] = {
    0x102, 2, 0x1F0, 0x2B0, 7,
    0x100, 0x69, 0x339, 0x36C,
    0x101, 0x69, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 2, 0x281, 0x2FA, 7,
    0x302, 2,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x601, 0, 0x2E0, 0x328,
    0x102, 0x69, 0x357, 0x37C, 7,
    0x302, 0x69,
    0x102, 0x69, 0x364, 0x376, 5,
    0x302, 0x69,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x34E, 2,
    0x300, 0x1E,
    0x102, 0x69, 0x394, 0x35E, 5,
    0x302, 0x69,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x101, 0x32D, 0x354, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x301,
    0x300, 0x1E,
    0x600, 0, 2,
    0x300, 0x3C,
    0,
};
s16 D_800A52EC[] = {
    0x102, 2, 0x280, 0x148, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0x2D0, 0x120,
    0x300, 0x3C,
    0x100, 0x69, 0x33E, 0xD8,
    0x101, 0x69, 1, 1,
    0x101, 0x32D, 0x34F, 2,
    0x300, 0x3C,
    0x102, 0x69, 0x301, 0xF7, 1,
    0x302, 0x69,
    0x102, 0x69, 0x312, 0xFF, 7,
    0x302, 0x69,
    0x102, 0x69, 0x2F0, 0x110, 1,
    0x302, 0x69,
    0x200, 0, 1, 2, 2,
    0x101, 2, 7, 5,
    0x101, 0x69, 1, 1,
    0x301,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0x69,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x69,
    0x300, 0x1E,
    0x200, 0, 2, 0x69, 1,
    0x301,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x102, 0x69, 0x312, 0xFF, 5,
    0x302, 0x69,
    0x102, 0x69, 0x301, 0xF7, 3,
    0x302, 0x69,
    0x102, 0x69, 0x310, 0xF0, 5,
    0x302, 0x69,
    0x102, 0x69, 0x338, 0xDC, 5,
    0x302, 0x69,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x101, 0x32D, 0x355, 2,
    0x300, 0x3C,
    0x600, 0, 2,
    0x300, 0x3C,
    0,
};
s16 D_800A542C[] = {
    0x102, 2, 0x42F, 0x2B4, 6,
    0x100, 0x69, 0x4D9, 0x2C4,
    0x101, 0x69, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 6,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0x47E, 0x2B4,
    0x300, 0x78,
    0x102, 0x69, 0x4F1, 0x2D0, 7,
    0x302, 0x69,
    0x102, 0x69, 0x4F7, 0x2CC, 5,
    0x302, 0x69,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x352, 2,
    0x300, 0x1E,
    0x102, 0x69, 0x51F, 0x2B8, 5,
    0x302, 0x69,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x101, 0x32D, 0x358, 2,
    0x300, 0x3C,
    0x200, 0, 1, 2, 1,
    0x301,
    0x300, 0x1E,
    0x600, 0, 2,
    0x300, 0x5A,
    0,
};
s16 D_800A54F8[] = {
    0x600, 0, 2,
    0x102, 2, 0x4BA, 0x1DB, 5,
    0x100, 0x69, 0x3CC, 0x1C1,
    0x101, 0x69, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 2, 1, 2,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x601, 0, 0x460, 0x1C7,
    0x102, 0x69, 0x40F, 0x19F, 5,
    0x302, 0x69,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x350, 2,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x102, 0x69, 0x440, 0x187, 5,
    0x302, 0x69,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x101, 0x32D, 0x356, 2,
    0x300, 0x3C,
    0x200, 0, 1, 2, 1,
    0x301,
    0x300, 0x1E,
    0x600, 0, 2,
    0x300, 0x5A,
    0,
};
s16 D_800A55C8[] = {
    0x102, 2, 0x27F, 0x1D9, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x102, 2, 0x311, 0x221, 7,
    0x101, 0x323, 0x326, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x18,
    0x102, 2, 0x39C, 0x1DB, 5,
    0x100, 0x69, 0x47E, 0x149,
    0x101, 0x69, 1, 3,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x601, 0, 0x3FF, 0x108,
    0x102, 0x69, 0x450, 0x10F, 3,
    0x302, 0x69,
    0x102, 0x69, 0x440, 0x108, 5,
    0x302, 0x69,
    0x102, 0x69, 0x460, 0xF7, 5,
    0x302, 0x69,
    0x101, 0x69, 1, 3,
    0x300, 6,
    0x600, 0, 2,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x300, 0x3C,
    0x300, 0x3C,
    0x200, 0, 1, 2, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A56A4[] = {
    0x601, 1, 0x118, 0xA4,
    0x100, 2, 0xCF, 0x6D,
    0x101, 2, 1, 7,
    0x100, 0x69, 0xA9, 0x21B,
    0x101, 0x69, 1, 1,
    0x101, 0x32D, 0x34D, 2,
    0x300, 0x1E,
    0x102, 2, 0x105, 0x88, 7,
    0x302, 2,
    0x300, 0x1E,
    0x101, 0x32D, 0x353, 2,
    0x300, 0x1E,
    0x102, 2, 0x129, 0x9A, 1,
    0x302, 2,
    0x101, 2, 1, 1,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x3C,
    0x601, 0, 0xCF, 0x1E0,
    0x102, 0x69, 0x89, 0x22B, 1,
    0x302, 0x69,
    0x102, 0x69, 0x81, 0x227, 3,
    0x302, 0x69,
    0x101, 0x69, 1, 3,
    0x300, 0x1E,
    0x101, 0x32D, 0x351, 2,
    0x300, 0x1E,
    0x102, 0x69, 0x56, 0x213, 3,
    0x302, 0x69,
    0x100, 0x69, 0, 0,
    0x101, 0x69, 1, 0,
    0x101, 0x32D, 0x357, 2,
    0x300, 0x3C,
    0x600, 0, 2,
    0x300, 0x3C,
    0x200, 0, 1, 2, 2,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0,
};
Battle D_800A57BC = { 80, 12, 0x60080000 };
Battle D_800A57C8 = { 80, 12, 0x60080000 };
Battle D_800A57D4 = { 79, 12, 0x60080000 };
Battle D_800A57E0 = { 79, 12, 0x60080000 };
Battle D_800A57EC = { 78, 12, 0x60080000 };
Battle D_800A57F8 = { 78, 12, 0x60080000 };
Battle D_800A5804 = { 77, 12, 0x60080000 };
Battle D_800A5810 = { 77, 12, 0x60080000 };
BattleList D_800A581C = {
    2,
    { &D_800A57BC, &D_800A57C8, &D_800A57D4, &D_800A57E0,
      &D_800A57EC, &D_800A57F8, &D_800A5804, &D_800A5810 },
};
Battle D_800A5840 = { 0, 0, 0x60040000 };
Battle D_800A584C = { 0, 0, 0x60040000 };
Battle D_800A5858 = { 0, 0, 0x60040000 };
Battle D_800A5864 = { 0, 0, 0x60040000 };
Battle D_800A5870 = { 0, 0, 0x60040000 };
Battle D_800A587C = { 0, 0, 0x60040000 };
Battle D_800A5888 = { 0, 0, 0x60040000 };
Battle D_800A5894 = { 0, 0, 0x60040000 };
BattleList D_800A58A0 = {
    0,
    { &D_800A5840, &D_800A584C, &D_800A5858, &D_800A5864,
      &D_800A5870, &D_800A587C, &D_800A5888, &D_800A5894 },
};
Battle D_800A58C4 = { 0, 0, 0x60040000 };
Battle D_800A58D0 = { 0, 0, 0x60040000 };
Battle D_800A58DC = { 0, 0, 0x60040000 };
Battle D_800A58E8 = { 0, 0, 0x60040000 };
Battle D_800A58F4 = { 0, 0, 0x60040000 };
Battle D_800A5900 = { 0, 0, 0x60040000 };
Battle D_800A590C = { 0, 0, 0x60040000 };
Battle D_800A5918 = { 0, 0, 0x60040000 };
BattleList D_800A5924 = {
    0,
    { &D_800A58C4, &D_800A58D0, &D_800A58DC, &D_800A58E8,
      &D_800A58F4, &D_800A5900, &D_800A590C, &D_800A5918 },
};
Battle D_800A5948 = { 0, 0, 0x60040000 };
Battle D_800A5954 = { 0, 0, 0x60040000 };
Battle D_800A5960 = { 0, 0, 0x60040000 };
Battle D_800A596C = { 0, 0, 0x60040000 };
Battle D_800A5978 = { 0, 0, 0x60040000 };
Battle D_800A5984 = { 0, 0, 0x60040000 };
Battle D_800A5990 = { 0, 0, 0x60040000 };
Battle D_800A599C = { 0, 0, 0x60040000 };
BattleList D_800A59A8 = {
    0,
    { &D_800A5948, &D_800A5954, &D_800A5960, &D_800A596C,
      &D_800A5978, &D_800A5984, &D_800A5990, &D_800A599C },
};
FieldBattles stageBattles[] = {
    { 41, 0, 0, { &D_800A581C, &D_800A58A0, &D_800A5924, &D_800A59A8 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x150, 0x1DB, 0x40, 0xDB, 0x160, 0x1FF },
    { 0x140, 0x100, 0x158, 0x1DB, 0x60, 0xDB, 0x170, 0x1FF },
};
u16 D_800A5A68[] = { 0x6000, 1, 0x4021, 0, 0xFFFF };
u16 D_800A5A74[] = { 0x6000, 1, 0x20D, 1, 0x4034, 0, 0xFFFF };
u16 D_800A5A84[] = { 0x6000, 1, 0x20E, 1, 0x4035, 0, 0xFFFF };
u16 D_800A5A94[] = { 0x6000, 1, 0x20F, 1, 0x4036, 0, 0xFFFF };
u16 D_800A5AA4[] = { 0x6000, 1, 0x210, 1, 0x4037, 0, 0xFFFF };
u16 D_800A5AB4[] = { 0x6012, 1, 0x4038, 0, 0xFFFF };
u16 D_800A5AC0[] = { 0x6011, 1, 0xFFFF };
u16 D_800A5AC8[] = { 0x403C, 0, 0x6011, 1, 0xFFFF };
FieldActorEntry D_800A5AD4 = { D_800A5A68, NULL, 0x69, 4, 825, 876, 7 };
FieldActorEntry D_800A5AE8 = { D_800A5A74, NULL, 0x69, 4, 830, 216, 1 };
FieldActorEntry D_800A5AFC = { D_800A5A84, NULL, 0x69, 4, 1241, 708, 7 };
FieldActorEntry D_800A5B10 = { D_800A5A94, NULL, 0x69, 4, 972, 449, 5 };
FieldActorEntry D_800A5B24 = { D_800A5AA4, NULL, 0x69, 4, 1150, 329, 3 };
FieldActorEntry D_800A5B38 = { D_800A5AB4, NULL, 0x69, 4, 169, 539, 1 };
FieldActorEntry D_800A5B4C = { D_800A5AC0, NULL, 0x69, 4, 0, 0, 1 };
FieldActorEntry D_800A5B60 = { D_800A5AC8, NULL, 0x11D, 5, 455, 955, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5AD4,
    &D_800A5AE8,
    &D_800A5AFC,
    &D_800A5B10,
    &D_800A5B24,
    &D_800A5B38,
    &D_800A5B4C,
    &D_800A5B60,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 249, 482, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 273, 494, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 720, 847, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 745, 378, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 769, 390, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 891, 346, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 913, 750, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 984, 754, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 1269, 276, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 889, 739, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 960, 766, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 1234, 293, 0, 0 },
    { 1, 0, 0x40, 2, 0x35, 2, 0, 1, 6, 0, 946, 161, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 787, 181, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 867, 829, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 1043, 353, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 6, 0, 1268, 657, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 1, 6, 0, 236, 78, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 1, 6, 0, 1092, 186, 0, 0 },
    { 1, 0, 0x47, 2, 0xE, 0, 0, 0, 0, 0, 799, 790, 0, 0 },
    { 1, 0, 0x41, 2, 0xF, 0, 0, 0, 0, 0, 727, 809, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 9, 4, 0, 696, 835, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 241, 879, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 305, 559, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 1025, 775, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 217, 891, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 281, 571, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 1001, 787, 0, 0 },
    { 1, 0x68, 0x40, 6, 7, 0, 0, 0, 0, 0, 93, 496, 0, 0 },
    { 1, 0x69, 0x40, 6, 8, 0, 0, 0, 0, 0, 1260, 665, 0, 0 },
    { 1, 0x67, 0x40, 6, 9, 0, 0, 0, 0, 0, 1036, 355, 0, 0 },
    { 1, 0x6B, 0x40, 6, 0xA, 0, 0, 0, 0, 0, 1086, 196, 0, 0 },
    { 1, 0x6A, 0x40, 6, 0xB, 0, 0, 0, 0, 0, 943, 171, 0, 0 },
    { 1, 0x66, 0x40, 6, 0xC, 0, 0, 0, 0, 0, 783, 191, 0, 0 },
    { 1, 0x65, 0x40, 6, 0x11, 0, 0, 0, 0, 0, 859, 837, 0, 0 },
    { 1, 0x64, 0x40, 6, 0xD, 0, 0, 0, 0, 0, 230, 86, 0, 0 },
    { 1, 0, 0x80, 6, 0x19, 0, 0, 0, 0, 0, 876, 192, 0, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 9, 4, 0, 401, 463, 491, 0 },
    { 1, 0, 0x40, 4, 0x34, 2, 0, 9, 4, 0, 377, 475, 497, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 64, 512, 552, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1071, 379, 415, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 1049, 211, 247, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 975, 187, 224, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 815, 207, 239, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 894, 347, 370, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 896, 855, 888, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 208, 103, 138, 0 },
    { 1, 0, 0x40, 4, 0x14, 0, 0, 0, 0, 0, 397, 464, 491, 0 },
    { 1, 0, 0x40, 4, 0x15, 0, 0, 0, 0, 0, 381, 476, 497, 0 },
    { 1, 0, 0x80, 4, 0x16, 0, 0, 0, 0, 0, 891, 116, 221, 0 },
    { 1, 0, 0x80, 4, 0x17, 0, 0, 0, 0, 0, 899, 112, 207, 0 },
    { 1, 0, 0x80, 4, 0x18, 0, 0, 0, 0, 0, 907, 108, 203, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24C, 0x228, 0x94, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24E, 0x108, 0x174, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24F, 0x108, 0x174, 5, 0x69, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x252, 0x2F8, 0x264, 3, 0x6B, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x250, 0x108, 0x174, 5, 0x67, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x252, 0x258, 0x24C, 5, 0x6A, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x251, 0x108, 0x174, 5, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x252, 0x68, 0x20C, 3, 0x64, 0, 0 },
    { { { 0x7040, 1 }, { 0xFFFF, 0 } }, 1, 0x253, 0x278, 0xD4, 3, 0x68, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x160, 0x80, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x170, 0xE8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 0xC, 0xDF, 0x142, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 0xC, 0xD2, 0x208, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x2D0, 0x29A, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x2C1, 0x322, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x33E, 0x2D2, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x330, 0x35A, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x42E, 0x34A, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0x420, 0x3D2, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x4B0, 0x25A, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x4BE, 0x2AE, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 8, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0x6011, 1 }, { 0x4021, 0 } }, 8, 0x1C2, 0, 0, 0, 0, 0, 0 },
    { { { 0x20D, 1 }, { 0x4034, 0 } }, 8, 0x1D6, 0, 0, 0, 0, 0, 0 },
    { { { 0x20E, 1 }, { 0x4035, 0 } }, 8, 0x1E0, 0, 0, 0, 0, 0, 0 },
    { { { 0x20F, 1 }, { 0x4036, 0 } }, 8, 0x1EA, 0, 0, 0, 0, 0, 0 },
    { { { 0x210, 1 }, { 0x4037, 0 } }, 8, 0x1F4, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 440, D_800A50CC, EVENT_TEXT(6), NULL, func_800A4DC8 },
    { 450, D_800A5210, EVENT_TEXT(0x16), NULL, func_800A4E14 },
    { 470, D_800A52EC, EVENT_TEXT(0x17), NULL, func_800A4E60 },
    { 480, D_800A542C, EVENT_TEXT(0x18), NULL, func_800A4EAC },
    { 490, D_800A54F8, EVENT_TEXT(0x19), NULL, func_800A4EF8 },
    { 500, D_800A55C8, EVENT_TEXT(0x1A), NULL, func_800A4F44 },
    { 520, D_800A56A4, EVENT_TEXT(0x1B), NULL, func_800A4F90 },
    { -1, NULL, 0, NULL, NULL },
};
