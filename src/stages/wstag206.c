#include "common.h"
#include "stage.h"

/* Creates the event object of progress 0x24, which depends on flag 0x40CA */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        do {
            if (GAME.progress == 0x24 && FLAGS_00.checkCondition(0x40CA, 0)) {
                children[0] = FIELDSTG_startEvent(0x399);
                break;
            }
            if (GAME.progress == 0x24 && FLAGS_00.checkCondition(0x40CA, 1)) {
                children[0] = FIELDSTG_startEvent(0x39A);
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

void func_800A4DE0(void) {
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4E0C(void) {
    FLAGS_00.applyAction(0x40CA, 1);
}

void func_800A4E38(void) {
    GAME.progress = 37;
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x49C
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x4AC
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x2E300, 0xEE00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 4;
    D_800990B4.music = 0x60100000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A54B4;
extern Battle D_800A54C0;
extern Battle D_800A54CC;
extern Battle D_800A54D8;
extern Battle D_800A54E4;
extern Battle D_800A54F0;
extern Battle D_800A54FC;
extern Battle D_800A5508;
extern Battle D_800A5538;
extern Battle D_800A5544;
extern Battle D_800A5550;
extern Battle D_800A555C;
extern Battle D_800A5568;
extern Battle D_800A5574;
extern Battle D_800A5580;
extern Battle D_800A558C;
extern Battle D_800A55BC;
extern Battle D_800A55C8;
extern Battle D_800A55D4;
extern Battle D_800A55E0;
extern Battle D_800A55EC;
extern Battle D_800A55F8;
extern Battle D_800A5604;
extern Battle D_800A5610;
extern Battle D_800A5640;
extern Battle D_800A564C;
extern Battle D_800A5658;
extern Battle D_800A5664;
extern Battle D_800A5670;
extern Battle D_800A567C;
extern Battle D_800A5688;
extern Battle D_800A5694;
extern BattleList D_800A5514;
extern BattleList D_800A5598;
extern BattleList D_800A561C;
extern BattleList D_800A56A0;
extern u16 D_800A5850[];
extern u16 D_800A5860[];
extern u16 D_800A5868[];
extern u16 D_800A5870[];
extern u16 D_800A5878[];
extern u16 D_800A5970[];
extern FieldTalk D_800A5880[];
extern u16 D_800A5978[];
extern FieldTalk D_800A5898[];
extern u16 D_800A5980[];
extern u16 D_800A5988[];
extern FieldTalk D_800A58B0[];
extern u16 D_800A5990[];
extern u16 D_800A5998[];
extern u16 D_800A59A0[];
extern u16 D_800A59A8[];
extern u16 D_800A59B0[];
extern u16 D_800A59B8[];
extern FieldTalk D_800A58C8[];
extern u16 D_800A59C0[];
extern u16 D_800A59C8[];
extern u16 D_800A59D0[];
extern FieldTalk D_800A58E0[];
extern u16 D_800A59D8[];
extern u16 D_800A59E0[];
extern FieldTalk D_800A58F8[];
extern u16 D_800A59E8[];
extern u16 D_800A59F4[];
extern FieldTalk D_800A591C[];
extern u16 D_800A59FC[];
extern u16 D_800A5A04[];
extern FieldTalk D_800A5934[];
extern u16 D_800A5A0C[];
extern u16 D_800A5A18[];
extern FieldTalk D_800A5958[];
extern u16 D_800A5A20[];
extern u16 D_800A5A28[];
extern u16 D_800A5A34[];
extern u16 D_800A5A40[];
extern u16 D_800A5A4C[];
extern u16 D_800A5A54[];
extern FieldActorEntry D_800A5A5C;
extern FieldActorEntry D_800A5A70;
extern FieldActorEntry D_800A5A84;
extern FieldActorEntry D_800A5A98;
extern FieldActorEntry D_800A5AAC;
extern FieldActorEntry D_800A5AC0;
extern FieldActorEntry D_800A5AD4;
extern FieldActorEntry D_800A5AE8;
extern FieldActorEntry D_800A5AFC;
extern FieldActorEntry D_800A5B10;
extern FieldActorEntry D_800A5B24;
extern FieldActorEntry D_800A5B38;
extern FieldActorEntry D_800A5B4C;
extern FieldActorEntry D_800A5B60;
extern FieldActorEntry D_800A5B74;
extern FieldActorEntry D_800A5B88;
extern FieldActorEntry D_800A5B9C;
extern FieldActorEntry D_800A5BB0;
extern FieldActorEntry D_800A5BC4;
extern FieldActorEntry D_800A5BD8;
extern FieldActorEntry D_800A5BEC;
extern FieldActorEntry D_800A5C00;
extern FieldActorEntry D_800A5C14;
extern FieldActorEntry D_800A5C28;
extern FieldActorEntry D_800A5C3C;
extern FieldActorEntry D_800A5C50;
extern FieldActorEntry D_800A5C64;
extern s16 D_800A4FA4[];
extern s16 D_800A5038[];
extern s16 D_800A527C[];

s16 D_800A4FA4[] = {
    0x102, 2, 0x1D0, 0x180, 5,
    0x101, 0x323, 0x325, 0xF3,
    0x101, 0x324, 0x325, 0xF4,
    0x101, 0x325, 0x325, 0xF5,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x3C,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x326, 0xF3,
    0x101, 0x324, 0x326, 0xF4,
    0x101, 0x325, 0x326, 0xF5,
    0x300, 0x1E,
    0x200, 0, 1, 0xF3, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0xF3, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5038[] = {
    0x601, 1, 0x2DA, 0xEC,
    0x100, 2, 0x2F0, 0x10E,
    0x101, 2, 1, 4,
    0x100, 0x25, 0x288, 0x124,
    0x101, 0x25, 1, 5,
    0x100, 0x26, 0x250, 0x130,
    0x101, 0x26, 1, 5,
    0x100, 0x27, 0x261, 0x141,
    0x101, 0x27, 1, 5,
    0x100, 0x65, 0x2F0, 0xE8,
    0x101, 0x65, 1, 1,
    0x100, 0x66, 0x2E0, 0xE0,
    0x101, 0x66, 1, 1,
    0x100, 0x67, 0x300, 0xF0,
    0x101, 0x67, 1, 1,
    0x100, 0x6F, 0x248, 0x154,
    0x101, 0x6F, 1, 5,
    0x100, 0xB3, 0x340, 0x108,
    0x101, 0xB3, 1, 3,
    0x100, 0xE6, 0x226, 0x144,
    0x101, 0xE6, 1, 5,
    0x100, 0x186, 0x220, 0x168,
    0x101, 0x186, 1, 5,
    0x100, 0x187, 0x200, 0x158,
    0x101, 0x187, 1, 5,
    0x101, 0x32D, 0x34D, 2,
    0x300, 0x78,
    0x200, 0, 1, 0x65, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0x25, 2,
    0x101, 0x25, 1, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0x25, 1, 5,
    0x101, 0x65, 1, 5,
    0x101, 0x66, 1, 5,
    0x101, 0x67, 1, 5,
    0x300, 0x1E,
    0x102, 0x25, 0x380, 0xA8, 5,
    0x102, 0x26, 0x380, 0x98, 5,
    0x102, 0x27, 0x371, 0xA5, 5,
    0x102, 0x65, 0x3A0, 0x90, 5,
    0x102, 0x66, 0x390, 0x88, 5,
    0x102, 0x67, 0x3B0, 0x98, 5,
    0x102, 0x6F, 0x380, 0xB8, 5,
    0x102, 0xE6, 0x380, 0x98, 5,
    0x102, 0x186, 0x380, 0xB8, 5,
    0x102, 0x187, 0x380, 0x98, 5,
    0x300, 0x48,
    0x200, 0, 4, 0x27, 3,
    0x300, 0x48,
    0x200, 1, 3, 0x26, 2,
    0x300, 0x78,
    0x200, 1, 5, 0x187, 1,
    0x200, 0, 5, 0x187, 1,
    0x300, 0xCC,
    0x600, 0, 2,
    0x200, 1, 6, 0xB3, 1,
    0x200, 0, 6, 0xB3, 1,
    0x101, 0xB3, 1, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 0,
    0x101, 2, 7, 6,
    0x301,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x102, 0xB3, 0x320, 0xF8, 4,
    0x302, 0xB3,
    0x101, 0xB3, 1, 1,
    0x300, 0x1E,
    0x200, 0, 8, 0xB3, 0,
    0x301,
    0x300, 0x1E,
#if VERSION_US
    0x304, 0xE05, 0x2F0, 0x10E, 5,
#elif VERSION_EU
    0x304, 0xE06, 0x2F0, 0x10E, 5,
#endif
    0,
};
s16 D_800A527C[] = {
    0x100, 2, 0x2F0, 0x10E,
    0x101, 2, 1, 5,
    0x100, 0xB3, 0x320, 0xF8,
    0x101, 0xB3, 1, 1,
    0x101, 0x32D, 0x34D, 2,
    0x300, 0x78,
    0x200, 0, 1, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0xB3, 0,
    0x301,
    0x100, 0x67, 0x370, 0xB0,
    0x101, 0x67, 1, 1,
    0x300, 0x1E,
    0x102, 0x67, 0x316, 0xDC, 1,
    0x302, 0x67,
    0x600, 0, 0x67,
    0x101, 0x67, 1, 1,
    0x101, 0x323, 0x325, 0x67,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 0x67, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x101, 0x324, 0x325, 0xB3,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x101, 0x324, 0x326, 0xB3,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 4,
    0x101, 0xB3, 1, 4,
    0x301,
    0x102, 2, 0x2F0, 0xD8, 4,
    0x302, 2,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x200, 0, 5, 0xB3, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x67, 2,
    0x101, 0x67, 1, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 0,
    0x101, 2, 7, 6,
    0x301,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x200, 0, 8, 0x67, 2,
    0x101, 0x67, 1, 2,
    0x101, 0xB3, 1, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 2, 0,
    0x101, 2, 7, 6,
    0x301,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x200, 0, 0xA, 0x67, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xB, 2, 0,
    0x101, 2, 7, 6,
    0x301,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x200, 0, 0xC, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 0xD, 0xB3, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x308, 0xCC, 5,
    0x101, 0x67, 1, 3,
    0x101, 0xB3, 1, 4,
    0x302, 2,
    0x102, 2, 0x358, 0xA4, 5,
    0x101, 0x67, 1, 4,
    0x300, 0x5A,
    0x304, 0x270, 0x60, 0x31C, 5,
    0,
};
Battle D_800A54B4 = { 0, 0, 0x60040000 };
Battle D_800A54C0 = { 0, 0, 0x60040000 };
Battle D_800A54CC = { 0, 0, 0x60040000 };
Battle D_800A54D8 = { 0, 0, 0x60040000 };
Battle D_800A54E4 = { 0, 0, 0x60040000 };
Battle D_800A54F0 = { 0, 0, 0x60040000 };
Battle D_800A54FC = { 0, 0, 0x60040000 };
Battle D_800A5508 = { 0, 0, 0x60040000 };
BattleList D_800A5514 = {
    0,
    { &D_800A54B4, &D_800A54C0, &D_800A54CC, &D_800A54D8,
      &D_800A54E4, &D_800A54F0, &D_800A54FC, &D_800A5508 },
};
Battle D_800A5538 = { 0, 0, 0x60040000 };
Battle D_800A5544 = { 0, 0, 0x60040000 };
Battle D_800A5550 = { 0, 0, 0x60040000 };
Battle D_800A555C = { 0, 0, 0x60040000 };
Battle D_800A5568 = { 0, 0, 0x60040000 };
Battle D_800A5574 = { 0, 0, 0x60040000 };
Battle D_800A5580 = { 0, 0, 0x60040000 };
Battle D_800A558C = { 0, 0, 0x60040000 };
BattleList D_800A5598 = {
    0,
    { &D_800A5538, &D_800A5544, &D_800A5550, &D_800A555C,
      &D_800A5568, &D_800A5574, &D_800A5580, &D_800A558C },
};
Battle D_800A55BC = { 0, 0, 0x60040000 };
Battle D_800A55C8 = { 0, 0, 0x60040000 };
Battle D_800A55D4 = { 0, 0, 0x60040000 };
Battle D_800A55E0 = { 0, 0, 0x60040000 };
Battle D_800A55EC = { 0, 0, 0x60040000 };
Battle D_800A55F8 = { 0, 0, 0x60040000 };
Battle D_800A5604 = { 0, 0, 0x60040000 };
Battle D_800A5610 = { 0, 0, 0x60040000 };
BattleList D_800A561C = {
    0,
    { &D_800A55BC, &D_800A55C8, &D_800A55D4, &D_800A55E0,
      &D_800A55EC, &D_800A55F8, &D_800A5604, &D_800A5610 },
};
Battle D_800A5640 = { 30, 19, 0x60880000 };
Battle D_800A564C = { 0, 0, 0x60040000 };
Battle D_800A5658 = { 0, 0, 0x60040000 };
Battle D_800A5664 = { 0, 0, 0x60040000 };
Battle D_800A5670 = { 0, 0, 0x60040000 };
Battle D_800A567C = { 0, 0, 0x60040000 };
Battle D_800A5688 = { 0, 0, 0x60040000 };
Battle D_800A5694 = { 0, 0, 0x60040000 };
BattleList D_800A56A0 = {
    0,
    { &D_800A5640, &D_800A564C, &D_800A5658, &D_800A5664,
      &D_800A5670, &D_800A567C, &D_800A5688, &D_800A5694 },
};
FieldBattles stageBattles[] = {
    { 130, 0, 0, { &D_800A5514, &D_800A5598, &D_800A561C, &D_800A56A0 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B8, 0x19C, 0x1E0, 0x9C, 0x160, 0x1FF },
    { 0x180, 0x100, 0x198, 0x1C0, 0x160, 0xC0, 0x170, 0x1FF },
    { 0x180, 0x100, 0x190, 0x1C0, 0x140, 0xC0, 0x140, 0x1FE },
    { 0x180, 0x100, 0x1A0, 0x1C0, 0x180, 0xC0, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1A4, 0x180, 0x190, 0x80, 0x160, 0x1FE },
    { 0x180, 0x100, 0x1B8, 0x16C, 0x1E0, 0x6C, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1B0, 0x194, 0x1C0, 0x94, 0x140, 0x1FD },
    { 0x180, 0x100, 0x198, 0x100, 0x160, 0, 0x150, 0x1FD },
    { 0x180, 0x100, 0x188, 0x1C0, 0x120, 0xC0, 0x160, 0x1FD },
    { 0x180, 0x100, 0x180, 0x138, 0x100, 0x38, 0x170, 0x1FD },
    { 0x180, 0x100, 0x198, 0x138, 0x160, 0x38, 0x140, 0x1FC },
    { 0x180, 0x100, 0x1A4, 0x100, 0x190, 0, 0x150, 0x1FC },
    { 0x180, 0x100, 0x180, 0x100, 0x100, 0, 0x160, 0x1FC },
    { 0x180, 0x100, 0x18C, 0x100, 0x130, 0, 0x170, 0x1FC },
    { 0x180, 0x100, 0x1A4, 0x138, 0x190, 0x38, 0x140, 0x1FB },
    { 0x180, 0x100, 0x188, 0x138, 0x120, 0x38, 0x150, 0x1FB },
    { 0x180, 0x100, 0x190, 0x138, 0x140, 0x38, 0x160, 0x1FB },
};
u16 D_800A5850[] = { 0x708B, 1, 0x25E, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5860[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5868[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5870[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5878[] = { 0x6026, 1, 0xFFFF };
FieldTalk D_800A5880[] = {
    { NULL, D_800A5850, 0x16C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5898[] = {
    { NULL, NULL, 0xED },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58B0[] = {
    { NULL, NULL, 0xEE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C8[] = {
    { NULL, NULL, 0x1B5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58E0[] = {
    { NULL, NULL, 0x1B4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58F8[] = {
    { D_800A5860, NULL, 0xE7 },
    { D_800A5868, NULL, 0xE8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A591C[] = {
    { NULL, NULL, 0xE9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5934[] = {
    { D_800A5870, NULL, 0xEA },
    { D_800A5878, NULL, 0xEB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5958[] = {
    { NULL, NULL, 0xEC },
    { NULL, NULL, 0 },
};
u16 D_800A5970[] = { 0x25E, 0, 0xFFFF };
u16 D_800A5978[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5980[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5988[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5990[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5998[] = { 0x6024, 1, 0xFFFF };
u16 D_800A59A0[] = { 0x6024, 1, 0xFFFF };
u16 D_800A59A8[] = { 0x6024, 1, 0xFFFF };
u16 D_800A59B0[] = { 0x6024, 1, 0xFFFF };
u16 D_800A59B8[] = { 0x6025, 1, 0xFFFF };
u16 D_800A59C0[] = { 0x6024, 1, 0xFFFF };
u16 D_800A59C8[] = { 0x6024, 1, 0xFFFF };
u16 D_800A59D0[] = { 0x6025, 1, 0xFFFF };
u16 D_800A59D8[] = { 0x6024, 1, 0xFFFF };
u16 D_800A59E0[] = { 0x701C, 1, 0xFFFF };
u16 D_800A59E8[] = { 0x6024, 0, 0x701D, 1, 0xFFFF };
u16 D_800A59F4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A59FC[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5A04[] = { 0x701C, 1, 0xFFFF };
u16 D_800A5A0C[] = { 0x6024, 0, 0x701D, 1, 0xFFFF };
u16 D_800A5A18[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5A20[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5A28[] = { 0x6024, 0, 0x701D, 1, 0xFFFF };
u16 D_800A5A34[] = { 0x6024, 0, 0x701D, 1, 0xFFFF };
u16 D_800A5A40[] = { 0x701D, 1, 0x6024, 0, 0xFFFF };
u16 D_800A5A4C[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5A54[] = { 0x6024, 1, 0xFFFF };
FieldActorEntry D_800A5A5C = { D_800A5970, D_800A5880, 0x21, 4, 304, 160, 1 };
FieldActorEntry D_800A5A70 = { D_800A5978, D_800A5898, 0x25, 5, 736, 184, 1 };
FieldActorEntry D_800A5A84 = { D_800A5980, NULL, 0x25, 5, 0, 0, 1 };
FieldActorEntry D_800A5A98 = { D_800A5988, D_800A58B0, 0x26, 6, 848, 240, 1 };
FieldActorEntry D_800A5AAC = { D_800A5990, NULL, 0x26, 6, 0, 0, 1 };
FieldActorEntry D_800A5AC0 = { D_800A5998, NULL, 0x27, 7, 0, 0, 1 };
FieldActorEntry D_800A5AD4 = { D_800A59A0, NULL, 0x65, 8, 0, 0, 1 };
FieldActorEntry D_800A5AE8 = { D_800A59A8, NULL, 0x66, 9, 0, 0, 1 };
FieldActorEntry D_800A5AFC = { D_800A59B0, NULL, 0x67, 0xA, 0, 0, 1 };
FieldActorEntry D_800A5B10 = { D_800A59B8, D_800A58C8, 0x67, 0xA, 752, 216, 7 };
FieldActorEntry D_800A5B24 = { D_800A59C0, NULL, 0x6F, 0xB, 0, 0, 1 };
FieldActorEntry D_800A5B38 = { D_800A59C8, NULL, 0xB3, 0xC, 0, 0, 1 };
FieldActorEntry D_800A5B4C = { D_800A59D0, D_800A58E0, 0xB3, 0xC, 720, 232, 7 };
FieldActorEntry D_800A5B60 = { D_800A59D8, NULL, 0xE6, 0xD, 0, 0, 1 };
FieldActorEntry D_800A5B74 = { D_800A59E0, D_800A58F8, 0xF3, 0xE, 736, 184, 1 };
FieldActorEntry D_800A5B88 = { D_800A59E8, NULL, 0xF3, 0xE, 488, 372, 1 };
FieldActorEntry D_800A5B9C = { D_800A59F4, D_800A591C, 0xF3, 0xE, 736, 184, 1 };
FieldActorEntry D_800A5BB0 = { D_800A59FC, NULL, 0xF3, 0xE, 735, 192, 1 };
FieldActorEntry D_800A5BC4 = { D_800A5A04, D_800A5934, 0xF4, 0xF, 848, 240, 1 };
FieldActorEntry D_800A5BD8 = { D_800A5A0C, NULL, 0xF4, 0xF, 512, 344, 1 };
FieldActorEntry D_800A5BEC = { D_800A5A18, D_800A5958, 0xF4, 0xF, 848, 240, 1 };
FieldActorEntry D_800A5C00 = { D_800A5A20, NULL, 0xF4, 0xF, 848, 240, 1 };
FieldActorEntry D_800A5C14 = { D_800A5A28, NULL, 0xF5, 0x10, 544, 360, 1 };
FieldActorEntry D_800A5C28 = { D_800A5A34, NULL, 0xF6, 0x11, 551, 325, 1 };
FieldActorEntry D_800A5C3C = { D_800A5A40, NULL, 0xF7, 0x12, 584, 341, 1 };
FieldActorEntry D_800A5C50 = { D_800A5A4C, NULL, 0x186, 0x13, 0, 0, 1 };
FieldActorEntry D_800A5C64 = { D_800A5A54, NULL, 0x187, 0x14, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5A5C,
    &D_800A5A70,
    &D_800A5A84,
    &D_800A5A98,
    &D_800A5AAC,
    &D_800A5AC0,
    &D_800A5AD4,
    &D_800A5AE8,
    &D_800A5AFC,
    &D_800A5B10,
    &D_800A5B24,
    &D_800A5B38,
    &D_800A5B4C,
    &D_800A5B60,
    &D_800A5B74,
    &D_800A5B88,
    &D_800A5B9C,
    &D_800A5BB0,
    &D_800A5BC4,
    &D_800A5BD8,
    &D_800A5BEC,
    &D_800A5C00,
    &D_800A5C14,
    &D_800A5C28,
    &D_800A5C3C,
    &D_800A5C50,
    &D_800A5C64,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x80, 2, 0, 0, 0, 0, 0, 0, 384, 384, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 128, 475, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 240, 499, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 252, 384, 0, 0 },
    { 1, 0, 0x80, 2, 4, 0, 0, 0, 0, 0, 512, 307, 0, 0 },
    { 1, 0, 0x40, 2, 5, 0, 0, 0, 0, 0, 496, 371, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 248, 352, 0, 0 },
    { 1, 0, 0x80, 2, 7, 0, 0, 0, 0, 0, 256, 384, 0, 0 },
    { 1, 0, 0x80, 2, 8, 0, 0, 0, 0, 0, 896, 128, 0, 0 },
    { 1, 0, 0x40, 2, 0x10, 0, 0, 0, 0, 0, 100, 512, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 414, 80, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 631, 406, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1257, 341, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 396, 323, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 805, 413, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 950, 554, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1127, 489, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 30, 340, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 70, 360, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 110, 380, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 150, 400, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 190, 420, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 470, 560, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 510, 580, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 1, 0x58, 0x5B, 4, 0, 585, 125, 0, 0 },
    { 1, 0, 0x40, 6, 0x5C, 1, 0x5C, 0x5F, 4, 0, 363, 49, 0, 0 },
    { 1, 0, 0x40, 6, 0x5C, 1, 0x5C, 0x5F, 4, 0, 433, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 1, 0x54, 0x57, 4, 0, 1009, 162, 0, 0 },
    { 1, 0x64, 0x80, 6, 9, 0, 0, 0, 0, 0, 758, 96, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 37, 267, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 77, 287, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 117, 307, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 157, 327, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 196, 347, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 236, 367, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 276, 387, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 477, 487, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 517, 507, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x50, 1, 0x50, 0x53, 4, 0, 230, 440, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x60, 1, 0x60, 0x63, 6, 0, 422, 110, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4C, 1, 0x4C, 0x4F, 6, 0, 942, 205, 0, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 224, 177, 200, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 600, 214, 273, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 1046, 371, 407, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 1062, 315, 337, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 902, 275, 295, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 846, 177, 226, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x60, 0x31C, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28C, 0x5E2, 0xE0, 1, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E1, 0x1D0, 0x154, 7, 0, 0xC, 1 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E1, 0xE0, 0x110, 7, 0, 0xC, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x110, 0x100, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0x120, 0xC8, 0, 0, 0, 0 },
    { { { 0x701D, 1 }, { 0xFFFF, 0 } }, 8, 0x2DA, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 730, D_800A4FA4, EVENT_TEXT(0x23), NULL, func_800A4DE0 },
    { 921, D_800A5038, EVENT_TEXT(0x26), NULL, func_800A4E0C },
    { 922, D_800A527C, EVENT_TEXT(0x27), NULL, func_800A4E38 },
    { -1, NULL, 0, NULL, NULL },
};
