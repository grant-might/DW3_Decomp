#include "common.h"
#include "stage.h"

/* Creates the event object of progress 0x16, which depends on flags 0x404A to 0x404C */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress == 0x16 && FLAGS_00.checkCondition(0x404A, 1) && FLAGS_00.checkCondition(0x404B, 0)) {
            children[0] = FIELDSTG_startEvent(0x23B);
        } else if (GAME.progress == 0x16 && FLAGS_00.checkCondition(0x404B, 1) && FLAGS_00.checkCondition(0x404C, 0)) {
            children[0] = FIELDSTG_startEvent(0x23C);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

/* Sets flags 0x404A, 0xC11 and 0x7401 */
void func_800A4DF8(void) {
    FLAGS_00.applyAction(0x404A, 1);
    FLAGS_00.applyAction(0xC11, 1);
    FLAGS_00.applyAction(0x7401, 1);
}

void func_800A4E58(void) {
    FLAGS_00.applyAction(0x404B, 1);
    FLAGS_00.applyAction(0x7402, 1);
}

void func_800A4EA4(void) {
    FLAGS_00.applyAction(0x404C, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x340
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x34F
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x49B00, 0x20900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
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

void func_800A4DF8();
extern Battle D_800A53FC;
extern Battle D_800A5408;
extern Battle D_800A5414;
extern Battle D_800A5420;
extern Battle D_800A542C;
extern Battle D_800A5438;
extern Battle D_800A5444;
extern Battle D_800A5450;
extern Battle D_800A5480;
extern Battle D_800A548C;
extern Battle D_800A5498;
extern Battle D_800A54A4;
extern Battle D_800A54B0;
extern Battle D_800A54BC;
extern Battle D_800A54C8;
extern Battle D_800A54D4;
extern Battle D_800A5504;
extern Battle D_800A5510;
extern Battle D_800A551C;
extern Battle D_800A5528;
extern Battle D_800A5534;
extern Battle D_800A5540;
extern Battle D_800A554C;
extern Battle D_800A5558;
extern Battle D_800A5588;
extern Battle D_800A5594;
extern Battle D_800A55A0;
extern Battle D_800A55AC;
extern Battle D_800A55B8;
extern Battle D_800A55C4;
extern Battle D_800A55D0;
extern Battle D_800A55DC;
extern BattleList D_800A545C;
extern BattleList D_800A54E0;
extern BattleList D_800A5564;
extern BattleList D_800A55E8;
extern u16 D_800A5788[];
extern u16 D_800A5798[];
extern u16 D_800A57A4[];
extern u16 D_800A57B0[];
extern u16 D_800A57BC[];
extern u16 D_800A57C8[];
extern u16 D_800A57D4[];
extern u16 D_800A57E0[];
extern u16 D_800A59FC[];
extern FieldTalk D_800A57EC[];
extern u16 D_800A5A04[];
extern FieldTalk D_800A5804[];
extern u16 D_800A5A0C[];
extern FieldTalk D_800A581C[];
extern u16 D_800A5A18[];
extern FieldTalk D_800A5834[];
extern u16 D_800A5A20[];
extern FieldTalk D_800A584C[];
extern u16 D_800A5A2C[];
extern FieldTalk D_800A5864[];
extern u16 D_800A5A34[];
extern FieldTalk D_800A587C[];
extern u16 D_800A5A40[];
extern FieldTalk D_800A5894[];
extern u16 D_800A5A48[];
extern FieldTalk D_800A58AC[];
extern u16 D_800A5A54[];
extern FieldTalk D_800A58C4[];
extern u16 D_800A5A5C[];
extern FieldTalk D_800A58DC[];
extern u16 D_800A5A68[];
extern u16 D_800A5A70[];
extern u16 D_800A5A78[];
extern FieldTalk D_800A58F4[];
extern u16 D_800A5A84[];
extern FieldTalk D_800A590C[];
extern u16 D_800A5A90[];
extern FieldTalk D_800A5924[];
extern u16 D_800A5A9C[];
extern FieldTalk D_800A593C[];
extern u16 D_800A5AA8[];
extern FieldTalk D_800A5954[];
extern u16 D_800A5AB4[];
extern FieldTalk D_800A596C[];
extern u16 D_800A5AC0[];
extern FieldTalk D_800A5984[];
extern u16 D_800A5ACC[];
extern u16 D_800A5AD4[];
extern FieldTalk D_800A599C[];
extern u16 D_800A5ADC[];
extern FieldTalk D_800A59B4[];
extern u16 D_800A5AE4[];
extern FieldTalk D_800A59CC[];
extern u16 D_800A5AF0[];
extern FieldTalk D_800A59E4[];
extern FieldActorEntry D_800A5AF8;
extern FieldActorEntry D_800A5B0C;
extern FieldActorEntry D_800A5B20;
extern FieldActorEntry D_800A5B34;
extern FieldActorEntry D_800A5B48;
extern FieldActorEntry D_800A5B5C;
extern FieldActorEntry D_800A5B70;
extern FieldActorEntry D_800A5B84;
extern FieldActorEntry D_800A5B98;
extern FieldActorEntry D_800A5BAC;
extern FieldActorEntry D_800A5BC0;
extern FieldActorEntry D_800A5BD4;
extern FieldActorEntry D_800A5BE8;
extern FieldActorEntry D_800A5BFC;
extern FieldActorEntry D_800A5C10;
extern FieldActorEntry D_800A5C24;
extern FieldActorEntry D_800A5C38;
extern FieldActorEntry D_800A5C4C;
extern FieldActorEntry D_800A5C60;
extern FieldActorEntry D_800A5C74;
extern FieldActorEntry D_800A5C88;
extern FieldActorEntry D_800A5C9C;
extern FieldActorEntry D_800A5CB0;
extern FieldActorEntry D_800A5CC4;
extern FieldActorEntry D_800A5CD8;
extern s16 D_800A5018[];
extern s16 D_800A5178[];
extern s16 D_800A51F8[];
extern s16 D_800A5358[];

s16 D_800A5018[] = {
    0x600, 0, 0x6A,
    0x101, 0x6A, 1, 3,
    0x100, 0x14A, 0x370, 0xE1,
    0x101, 0x14A, 1, 5,
    0x101, 0x323, 0x325, 0x14A,
    0x300, 0x1E,
    0x102, 0x6A, 0x390, 0xF1, 3,
    0x101, 0x14A, 1, 7,
    0x101, 0x323, 0x326, 0x14A,
    0x302, 0x6A,
    0x101, 0x6A, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0x14A, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0x6A, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x14A, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0x6A, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0x14A, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x6A, 3,
    0x301,
    0x101, 0x14A, 1, 5,
    0x300, 0x1E,
    0x200, 0, 7, 0x14A, 0,
    0x301,
    0x101, 0x6A, 1, 5,
    0x300, 0x3C,
    0x200, 0, 8, 0x14A, 0,
    0x301,
    0x101, 0x6A, 1, 3,
    0x101, 0x14A, 1, 7,
    0x300, 0x1E,
    0x200, 0, 9, 0x6A, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xA, 0x14A, 0,
    0x301,
    0x101, 0x6A, 1, 4,
    0x101, 0x14A, 1, 5,
    0x300, 0x1E,
    0x102, 0x6A, 0x390, 0xD0, 4,
    0x302, 0x6A,
    0x102, 0x6A, 0x3A8, 0xC4, 5,
    0x102, 0x14A, 0x3A8, 0xC4, 5,
    0x300, 0x1E,
    0x101, 0x32D, 0x34D, 0x6A,
    0x304, 0x218, 0x58, 0x18C, 5,
    0,
};
s16 D_800A5178[] = {
    0x102, 2, 0x370, 0xE0, 3,
    0x100, 0x130, 0x3A1, 0xC9,
    0x101, 0x130, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0x130,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 0x130, 0x389, 0xD5, 1,
    0x302, 0x130,
    0x200, 0, 1, 0x130, 2,
    0x101, 0x130, 1, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A51F8[] = {
    0x100, 2, 0x370, 0xE0,
    0x101, 2, 1, 5,
    0x300, 0x5A,
    0x101, 0x32D, 0x34D, 2,
    0x300, 0x1E,
    0x100, 0x76, 0x3B9, 0xBD,
    0x101, 0x76, 1, 1,
    0x300, 0x1E,
    0x102, 0x76, 0x389, 0xD5, 1,
    0x302, 0x76,
    0x200, 0, 1, 0x76, 2,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x301,
    0x300, 0x1E,
    0x101, 0x76, 1, 2,
    0x300, 0x1E,
    0x101, 0x76, 1, 0,
    0x300, 0x1E,
    0x101, 0x76, 1, 1,
    0x300, 0x1E,
    0x200, 0, 3, 0x76, 2,
    0x301,
    0x101, 0x76, 1, 0,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 0x76, 1, 2,
    0x301,
    0x101, 0x76, 1, 1,
    0x300, 0x1E,
    0x101, 0x76, 1, 0,
    0x300, 0x1E,
    0x101, 0x76, 1, 1,
    0x300, 0x1E,
    0x200, 0, 5, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 6, 0x76, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x327, 2,
    0x300, 0x78,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 8, 0x76, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5358[] = {
    0x100, 2, 0x370, 0xE0,
    0x101, 2, 1, 5,
    0x100, 0x76, 0x389, 0xD5,
    0x101, 0x76, 1, 1,
    0x101, 0x32D, 0x34D, 2,
    0x300, 0x78,
    0x200, 0, 2, 0x76, 2,
    0x301,
    0x102, 0x76, 0x3C9, 0xB5, 5,
    0x302, 0x76,
    0x200, 0, 4, 2, 1,
    0x301,
    0x100, 0x76, 0, 0,
    0x101, 0x76, 1, 0,
    0x101, 0x32D, 0x353, 2,
    0x300, 0x5A,
    0x200, 0, 1, 2, 3,
    0x301,
    0x101, 0x323, 0x327, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x301,
    0x300, 0x1E,
    0,
};
Battle D_800A53FC = { 0, 0, 0x60040000 };
Battle D_800A5408 = { 0, 0, 0x60040000 };
Battle D_800A5414 = { 0, 0, 0x60040000 };
Battle D_800A5420 = { 0, 0, 0x60040000 };
Battle D_800A542C = { 0, 0, 0x60040000 };
Battle D_800A5438 = { 0, 0, 0x60040000 };
Battle D_800A5444 = { 0, 0, 0x60040000 };
Battle D_800A5450 = { 0, 0, 0x60040000 };
BattleList D_800A545C = {
    0,
    { &D_800A53FC, &D_800A5408, &D_800A5414, &D_800A5420,
      &D_800A542C, &D_800A5438, &D_800A5444, &D_800A5450 },
};
Battle D_800A5480 = { 0, 0, 0x60040000 };
Battle D_800A548C = { 0, 0, 0x60040000 };
Battle D_800A5498 = { 0, 0, 0x60040000 };
Battle D_800A54A4 = { 0, 0, 0x60040000 };
Battle D_800A54B0 = { 0, 0, 0x60040000 };
Battle D_800A54BC = { 0, 0, 0x60040000 };
Battle D_800A54C8 = { 0, 0, 0x60040000 };
Battle D_800A54D4 = { 0, 0, 0x60040000 };
BattleList D_800A54E0 = {
    0,
    { &D_800A5480, &D_800A548C, &D_800A5498, &D_800A54A4,
      &D_800A54B0, &D_800A54BC, &D_800A54C8, &D_800A54D4 },
};
Battle D_800A5504 = { 0, 0, 0x60040000 };
Battle D_800A5510 = { 0, 0, 0x60040000 };
Battle D_800A551C = { 0, 0, 0x60040000 };
Battle D_800A5528 = { 0, 0, 0x60040000 };
Battle D_800A5534 = { 0, 0, 0x60040000 };
Battle D_800A5540 = { 0, 0, 0x60040000 };
Battle D_800A554C = { 0, 0, 0x60040000 };
Battle D_800A5558 = { 0, 0, 0x60040000 };
BattleList D_800A5564 = {
    0,
    { &D_800A5504, &D_800A5510, &D_800A551C, &D_800A5528,
      &D_800A5534, &D_800A5540, &D_800A554C, &D_800A5558 },
};
Battle D_800A5588 = { 189, 15, 0x60080000 };
Battle D_800A5594 = { 190, 15, 0x60080000 };
Battle D_800A55A0 = { 322, 15, 0x60080000 };
Battle D_800A55AC = { 0, 0, 0x60040000 };
Battle D_800A55B8 = { 0, 0, 0x60040000 };
Battle D_800A55C4 = { 0, 0, 0x60040000 };
Battle D_800A55D0 = { 0, 0, 0x60040000 };
Battle D_800A55DC = { 0, 0, 0x60040000 };
BattleList D_800A55E8 = {
    0,
    { &D_800A5588, &D_800A5594, &D_800A55A0, &D_800A55AC,
      &D_800A55B8, &D_800A55C4, &D_800A55D0, &D_800A55DC },
};
FieldBattles stageBattles[] = {
    { 136, 0, 0, { &D_800A545C, &D_800A54E0, &D_800A5564, &D_800A55E8 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B8, 0x100, 0x1E0, 0, 0x170, 0x1F9 },
    { 0x140, 0x100, 0x172, 0x1B1, 0xC8, 0xB1, 0x170, 0x1F8 },
    { 0x180, 0x100, 0x1B0, 0x100, 0x1C0, 0, 0x170, 0x1F7 },
    { 0x180, 0x100, 0x1B0, 0x130, 0x1C0, 0x30, 0x170, 0x1F6 },
    { 0x180, 0x100, 0x1A0, 0x197, 0x180, 0x97, 0x150, 0x1F5 },
    { 0x180, 0x100, 0x190, 0x19C, 0x140, 0x9C, 0x160, 0x1F5 },
    { 0x180, 0x100, 0x1A8, 0x167, 0x1A0, 0x67, 0x170, 0x1F5 },
    { 0x180, 0x100, 0x190, 0x174, 0x140, 0x74, 0x150, 0x1F4 },
    { 0x180, 0x100, 0x198, 0x174, 0x160, 0x74, 0x160, 0x1F4 },
    { 0x180, 0x100, 0x180, 0x17F, 0x100, 0x7F, 0x170, 0x1F4 },
    { 0x180, 0x100, 0x188, 0x17F, 0x120, 0x7F, 0x150, 0x1F3 },
    { 0x180, 0x100, 0x1A8, 0x18F, 0x1A0, 0x8F, 0x160, 0x1F3 },
    { 0x180, 0x100, 0x1B0, 0x190, 0x1C0, 0x90, 0x170, 0x1F3 },
    { 0x180, 0x100, 0x198, 0x19C, 0x160, 0x9C, 0x150, 0x1F2 },
    { 0x180, 0x100, 0x1B0, 0x160, 0x1C0, 0x60, 0x160, 0x1F2 },
    { 0x180, 0x100, 0x1A0, 0x167, 0x180, 0x67, 0x170, 0x1F2 },
};
u16 D_800A5788[] = { 0x214, 1, 0x822B, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5798[] = { 0x7401, 1, 0xC0F, 1, 0xFFFF };
u16 D_800A57A4[] = { 0xC10, 1, 0x7401, 1, 0xFFFF };
u16 D_800A57B0[] = { 0x7401, 1, 0xC11, 1, 0xFFFF };
u16 D_800A57BC[] = { 0x7400, 1, 0xC0B, 1, 0xFFFF };
u16 D_800A57C8[] = { 0x7400, 1, 0xC0C, 1, 0xFFFF };
u16 D_800A57D4[] = { 0x7400, 1, 0xC0D, 1, 0xFFFF };
u16 D_800A57E0[] = { 0x7400, 1, 0xC0E, 1, 0xFFFF };
FieldTalk D_800A57EC[] = {
    { NULL, D_800A5788, 0x2B6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5804[] = {
    { NULL, NULL, 0xAC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A581C[] = {
    { NULL, NULL, 0xAB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5834[] = {
    { NULL, NULL, 0xAA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A584C[] = {
    { NULL, NULL, 0xAB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5864[] = {
    { NULL, NULL, 0xAC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A587C[] = {
    { NULL, NULL, 0xAB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5894[] = {
    { NULL, NULL, 0xAA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58AC[] = {
    { NULL, NULL, 0xAB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C4[] = {
    { NULL, NULL, 0xAC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58DC[] = {
    { NULL, NULL, 0xAB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58F4[] = {
    { NULL, D_800A5798, 0x417 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A590C[] = {
    { NULL, D_800A57A4, 0x417 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5924[] = {
    { NULL, D_800A57B0, 0x1ED },
    { NULL, NULL, 0 },
};
FieldTalk D_800A593C[] = {
    { NULL, D_800A57BC, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5954[] = {
    { NULL, D_800A57C8, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A596C[] = {
    { NULL, D_800A57D4, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5984[] = {
    { NULL, D_800A57E0, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A599C[] = {
    { NULL, NULL, 0x1E6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59B4[] = {
    { NULL, NULL, 0xAA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59CC[] = {
    { NULL, NULL, 0xAB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59E4[] = {
    { NULL, NULL, 0xA7 },
    { NULL, NULL, 0 },
};
u16 D_800A59FC[] = { 0x214, 0, 0xFFFF };
u16 D_800A5A04[] = { 0x6021, 1, 0xFFFF };
u16 D_800A5A0C[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A5A18[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5A20[] = { 0x7020, 1, 0x6021, 0, 0xFFFF };
u16 D_800A5A2C[] = { 0x6021, 1, 0xFFFF };
u16 D_800A5A34[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A5A40[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5A48[] = { 0x7020, 1, 0x6021, 0, 0xFFFF };
u16 D_800A5A54[] = { 0x6021, 1, 0xFFFF };
u16 D_800A5A5C[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A5A68[] = { 0x600D, 1, 0xFFFF };
u16 D_800A5A70[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5A78[] = { 0x6016, 1, 0xC0F, 0, 0xFFFF };
u16 D_800A5A84[] = { 0x6016, 1, 0xC10, 0, 0xFFFF };
u16 D_800A5A90[] = { 0x6016, 1, 0xC11, 0, 0xFFFF };
u16 D_800A5A9C[] = { 0x6016, 1, 0xC0B, 0, 0xFFFF };
u16 D_800A5AA8[] = { 0x6016, 1, 0xC0C, 0, 0xFFFF };
u16 D_800A5AB4[] = { 0x6016, 1, 0xC0D, 0, 0xFFFF };
u16 D_800A5AC0[] = { 0x6016, 1, 0xC0E, 0, 0xFFFF };
u16 D_800A5ACC[] = { 0x600D, 1, 0xFFFF };
u16 D_800A5AD4[] = { 0x600D, 1, 0xFFFF };
u16 D_800A5ADC[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5AE4[] = { 0x7020, 1, 0x6021, 0, 0xFFFF };
u16 D_800A5AF0[] = { 0x600D, 1, 0xFFFF };
FieldActorEntry D_800A5AF8 = { D_800A59FC, D_800A57EC, 0x21, 4, 700, 283, 1 };
FieldActorEntry D_800A5B0C = { D_800A5A04, D_800A5804, 0x25, 5, 880, 225, 1 };
FieldActorEntry D_800A5B20 = { D_800A5A0C, D_800A581C, 0x25, 5, 880, 225, 1 };
FieldActorEntry D_800A5B34 = { D_800A5A18, D_800A5834, 0x26, 6, 905, 188, 1 };
FieldActorEntry D_800A5B48 = { D_800A5A20, D_800A584C, 0x26, 6, 905, 188, 1 };
FieldActorEntry D_800A5B5C = { D_800A5A2C, D_800A5864, 0x26, 6, 848, 209, 3 };
FieldActorEntry D_800A5B70 = { D_800A5A34, D_800A587C, 0x26, 6, 848, 209, 3 };
FieldActorEntry D_800A5B84 = { D_800A5A40, D_800A5894, 0x27, 7, 953, 213, 1 };
FieldActorEntry D_800A5B98 = { D_800A5A48, D_800A58AC, 0x27, 7, 953, 213, 1 };
FieldActorEntry D_800A5BAC = { D_800A5A54, D_800A58C4, 0x27, 7, 912, 240, 7 };
FieldActorEntry D_800A5BC0 = { D_800A5A5C, D_800A58DC, 0x27, 7, 912, 240, 7 };
FieldActorEntry D_800A5BD4 = { D_800A5A68, NULL, 0x6A, 8, 0, 0, 1 };
FieldActorEntry D_800A5BE8 = { D_800A5A70, NULL, 0x76, 9, 0, 0, 1 };
FieldActorEntry D_800A5BFC = { D_800A5A78, D_800A58F4, 0x12B, 0xA, 992, 282, 1 };
FieldActorEntry D_800A5C10 = { D_800A5A84, D_800A590C, 0x12F, 0xB, 769, 169, 1 };
FieldActorEntry D_800A5C24 = { D_800A5A90, D_800A5924, 0x130, 0xC, 929, 201, 1 };
FieldActorEntry D_800A5C38 = { D_800A5A9C, D_800A593C, 0x132, 0xD, 936, 477, 1 };
FieldActorEntry D_800A5C4C = { D_800A5AA8, D_800A5954, 0x133, 0xE, 1225, 429, 3 };
FieldActorEntry D_800A5C60 = { D_800A5AB4, D_800A596C, 0x134, 0xF, 321, 201, 7 };
FieldActorEntry D_800A5C74 = { D_800A5AC0, D_800A5984, 0x135, 0x10, 1120, 281, 1 };
FieldActorEntry D_800A5C88 = { D_800A5ACC, NULL, 0x14A, 0x11, 880, 225, 5 };
FieldActorEntry D_800A5C9C = { D_800A5AD4, D_800A599C, 0x17D, 0x12, 1225, 429, 3 };
FieldActorEntry D_800A5CB0 = { D_800A5ADC, D_800A59B4, 0x17D, 0x12, 929, 201, 1 };
FieldActorEntry D_800A5CC4 = { D_800A5AE4, D_800A59CC, 0x17D, 0x12, 929, 201, 1 };
FieldActorEntry D_800A5CD8 = { D_800A5AF0, D_800A59E4, 0x17E, 0x13, 318, 199, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5AF8,
    &D_800A5B0C,
    &D_800A5B20,
    &D_800A5B34,
    &D_800A5B48,
    &D_800A5B5C,
    &D_800A5B70,
    &D_800A5B84,
    &D_800A5B98,
    &D_800A5BAC,
    &D_800A5BC0,
    &D_800A5BD4,
    &D_800A5BE8,
    &D_800A5BFC,
    &D_800A5C10,
    &D_800A5C24,
    &D_800A5C38,
    &D_800A5C4C,
    &D_800A5C60,
    &D_800A5C74,
    &D_800A5C88,
    &D_800A5C9C,
    &D_800A5CB0,
    &D_800A5CC4,
    &D_800A5CD8,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x36, 2, 0, 9, 8, 0, 918, 96, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 9, 0xA, 0, 918, 96, 0, 0 },
    { 1, 0, 0xFF, 2, 0xB, 0, 0, 0, 0, 0, 992, 126, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 8, 0, 166, 118, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 8, 0, 541, 90, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 8, 0, 1115, 172, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 332, 103, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 1009, 185, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 1211, 143, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 8, 0, 1294, 168, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 8, 0, 860, 89, 0, 0 },
    { 1, 0, 0x80, 6, 0x35, 3, 0, 0xF, 0xE, 0, 660, 434, 0, 0 },
    { 1, 0x64, 0x40, 6, 0, 0, 0, 0, 0, 0, 929, 148, 0, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 768, 107, 151, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 992, 218, 264, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 1088, 218, 264, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 1152, 186, 230, 0 },
    { 1, 0, 0x60, 4, 5, 0, 0, 0, 0, 0, 816, 333, 432, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 945, 441, 462, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 960, 190, 231, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 480, 321, 342, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 497, 256, 272, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 953, 144, 200, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x205, 0x158, 0xA4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x218, 0x56, 0x18A, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x203, 0xC8, 0x9C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x214, 0x177, 0xBD, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x205, 0x372, 0x132, 7, 0, 0, 0 },
    { { { 0x6016, 1 }, { 0x404A, 0 } }, 8, 0x23A, 0, 0, 0, 0, 0, 0 },
    { { { 0x600D, 1 }, { 0xFFFF, 0 } }, 8, 0x15D, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 349, D_800A5018, EVENT_TEXT(3), NULL, NULL },
    { 570, D_800A5178, EVENT_TEXT(7), NULL, func_800A4DF8 },
    { 571, D_800A51F8, EVENT_TEXT(8), NULL, func_800A4E58 },
    { 572, D_800A5358, EVENT_TEXT(9), NULL, func_800A4EA4 },
    { -1, NULL, 0, NULL, NULL },
};
