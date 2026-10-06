#include "common.h"
#include "stage.h"

/*
 * Sets unk5[0] of the map objects with animation 1 from flag
 * 0x1A0A, and creates the event object of story progress 27
 */
void updateStage(StageTask *task, void **children) {
    StageTile *tile;
    s32 set;

    switch (task->state) {
    case TASK_INIT:
    default:
        set = FLAGS_00.checkCondition(0x1A0A, 1) != 0;
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
            if (tile->anim == 1) {
                tile->cycle = set;
            }
        }
        if (GAME.progress == 0x1B) {
            if (FLAGS_00.checkCondition(0x40A3, 1) && FLAGS_00.checkCondition(0x40A7, 0)) {
                children[0] = FIELDSTG_startEvent(0x2E5);
            } else if (FLAGS_00.checkCondition(0x40A7, 1)) {
                children[0] = FIELDSTG_startEvent(0x2E7);
            }
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

void func_800A4E3C(void) {
    FLAGS_00.applyAction(0x40A3, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Sets flags 0x8016 and 0x40A7 */
void func_800A4E88(void) {
    FLAGS_00.applyAction(0x8016, 1);
    FLAGS_00.applyAction(0x40A7, 1);
}

void func_800A4ED4(void) {
    GAME.progress = 28;
}

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x778
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x787
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1D100, 0x1F600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xC;
    D_800990B4.music = 0x60300000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
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

void func_800A4E88();
extern Battle D_800A51D0;
extern Battle D_800A51DC;
extern Battle D_800A51E8;
extern Battle D_800A51F4;
extern Battle D_800A5200;
extern Battle D_800A520C;
extern Battle D_800A5218;
extern Battle D_800A5224;
extern Battle D_800A5254;
extern Battle D_800A5260;
extern Battle D_800A526C;
extern Battle D_800A5278;
extern Battle D_800A5284;
extern Battle D_800A5290;
extern Battle D_800A529C;
extern Battle D_800A52A8;
extern Battle D_800A52D8;
extern Battle D_800A52E4;
extern Battle D_800A52F0;
extern Battle D_800A52FC;
extern Battle D_800A5308;
extern Battle D_800A5314;
extern Battle D_800A5320;
extern Battle D_800A532C;
extern Battle D_800A535C;
extern Battle D_800A5368;
extern Battle D_800A5374;
extern Battle D_800A5380;
extern Battle D_800A538C;
extern Battle D_800A5398;
extern Battle D_800A53A4;
extern Battle D_800A53B0;
extern BattleList D_800A5230;
extern BattleList D_800A52B4;
extern BattleList D_800A5338;
extern BattleList D_800A53BC;
extern u16 D_800A559C[];
extern u16 D_800A55A4[];
extern u16 D_800A57C8[];
extern FieldTalk D_800A55AC[];
extern u16 D_800A57D0[];
extern FieldTalk D_800A55C4[];
extern u16 D_800A57D8[];
extern FieldTalk D_800A55DC[];
extern u16 D_800A57E4[];
extern FieldTalk D_800A55F4[];
extern u16 D_800A57F0[];
extern FieldTalk D_800A560C[];
extern u16 D_800A57F8[];
extern FieldTalk D_800A5624[];
extern u16 D_800A5800[];
extern FieldTalk D_800A563C[];
extern u16 D_800A5808[];
extern FieldTalk D_800A5654[];
extern u16 D_800A5814[];
extern FieldTalk D_800A566C[];
extern u16 D_800A581C[];
extern FieldTalk D_800A5684[];
extern u16 D_800A5828[];
extern FieldTalk D_800A569C[];
extern u16 D_800A5830[];
extern FieldTalk D_800A56B4[];
extern u16 D_800A5838[];
extern FieldTalk D_800A56D8[];
extern u16 D_800A5840[];
extern FieldTalk D_800A56F0[];
extern u16 D_800A584C[];
extern FieldTalk D_800A5708[];
extern u16 D_800A5854[];
extern FieldTalk D_800A5720[];
extern u16 D_800A585C[];
extern FieldTalk D_800A5738[];
extern u16 D_800A5868[];
extern FieldTalk D_800A5750[];
extern u16 D_800A5874[];
extern FieldTalk D_800A5768[];
extern u16 D_800A587C[];
extern FieldTalk D_800A5780[];
extern u16 D_800A5884[];
extern FieldTalk D_800A5798[];
extern u16 D_800A588C[];
extern FieldTalk D_800A57B0[];
extern u16 D_800A5894[];
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
extern FieldActorEntry D_800A59DC;
extern FieldActorEntry D_800A59F0;
extern FieldActorEntry D_800A5A04;
extern FieldActorEntry D_800A5A18;
extern FieldActorEntry D_800A5A2C;
extern FieldActorEntry D_800A5A40;
extern FieldActorEntry D_800A5A54;
extern s16 D_800A5028[];
extern s16 D_800A50CC[];
extern s16 D_800A5188[];

s16 D_800A5028[] = {
    0x102, 2, 0x180, 0xDA, 1,
    0x100, 0xD2, 0x160, 0xEA,
    0x101, 0xD2, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0xD2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 3, 0xD2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 5, 0xD2, 1,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A50CC[] = {
    0x100, 2, 0x180, 0xDA,
    0x101, 2, 1, 1,
    0x100, 0x13C, 0x160, 0xEA,
    0x101, 0x13C, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 2, 0,
    0x301,
    0x300, 0x1E,
    0x300, 0x3C,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x168, 0xE6, 1,
    0x302, 2,
    0x300, 0x1E,
    0x100, 0x13C, 0, 0,
    0x101, 0x13C, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 0x32D, 0x34A, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x301,
    0x300, 0x1E,
    0x304, 0x2D7, 1, 1, 0,
    0,
};
s16 D_800A5188[] = {
    0x100, 2, 0x180, 0xDA,
    0x101, 2, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 2, 0,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x1E8, 0xA4, 5,
    0x300, 0x3C,
    0x304, 0x29E, 0xC8, 0x1A4, 5,
    0,
};
Battle D_800A51D0 = { 0, 0, 0x60040000 };
Battle D_800A51DC = { 0, 0, 0x60040000 };
Battle D_800A51E8 = { 0, 0, 0x60040000 };
Battle D_800A51F4 = { 0, 0, 0x60040000 };
Battle D_800A5200 = { 0, 0, 0x60040000 };
Battle D_800A520C = { 0, 0, 0x60040000 };
Battle D_800A5218 = { 0, 0, 0x60040000 };
Battle D_800A5224 = { 0, 0, 0x60040000 };
BattleList D_800A5230 = {
    0,
    { &D_800A51D0, &D_800A51DC, &D_800A51E8, &D_800A51F4,
      &D_800A5200, &D_800A520C, &D_800A5218, &D_800A5224 },
};
Battle D_800A5254 = { 0, 0, 0x60040000 };
Battle D_800A5260 = { 0, 0, 0x60040000 };
Battle D_800A526C = { 0, 0, 0x60040000 };
Battle D_800A5278 = { 0, 0, 0x60040000 };
Battle D_800A5284 = { 0, 0, 0x60040000 };
Battle D_800A5290 = { 0, 0, 0x60040000 };
Battle D_800A529C = { 0, 0, 0x60040000 };
Battle D_800A52A8 = { 0, 0, 0x60040000 };
BattleList D_800A52B4 = {
    0,
    { &D_800A5254, &D_800A5260, &D_800A526C, &D_800A5278,
      &D_800A5284, &D_800A5290, &D_800A529C, &D_800A52A8 },
};
Battle D_800A52D8 = { 0, 0, 0x60040000 };
Battle D_800A52E4 = { 0, 0, 0x60040000 };
Battle D_800A52F0 = { 0, 0, 0x60040000 };
Battle D_800A52FC = { 0, 0, 0x60040000 };
Battle D_800A5308 = { 0, 0, 0x60040000 };
Battle D_800A5314 = { 0, 0, 0x60040000 };
Battle D_800A5320 = { 0, 0, 0x60040000 };
Battle D_800A532C = { 0, 0, 0x60040000 };
BattleList D_800A5338 = {
    0,
    { &D_800A52D8, &D_800A52E4, &D_800A52F0, &D_800A52FC,
      &D_800A5308, &D_800A5314, &D_800A5320, &D_800A532C },
};
Battle D_800A535C = { 14, 18, 0x608C0000 };
Battle D_800A5368 = { 305, 18, 0x608C0000 };
Battle D_800A5374 = { 0, 0, 0x60040000 };
Battle D_800A5380 = { 0, 0, 0x60040000 };
Battle D_800A538C = { 0, 0, 0x60040000 };
Battle D_800A5398 = { 0, 0, 0x60040000 };
Battle D_800A53A4 = { 0, 0, 0x60040000 };
Battle D_800A53B0 = { 0, 0, 0x60040000 };
BattleList D_800A53BC = {
    0,
    { &D_800A535C, &D_800A5368, &D_800A5374, &D_800A5380,
      &D_800A538C, &D_800A5398, &D_800A53A4, &D_800A53B0 },
};
FieldBattles stageBattles[] = {
    { 150, 0, 0, { &D_800A5230, &D_800A52B4, &D_800A5338, &D_800A53BC } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x180, 0x1BB, 0x100, 0xBB, 0x140, 0x1FF },
    { 0x180, 0x100, 0x188, 0x1BB, 0x120, 0xBB, 0x150, 0x1FF },
    { 0x1C0, 0x100, 0x1DE, 0x100, 0x278, 0, 0x160, 0x1FF },
    { 0x180, 0x100, 0x1AA, 0x1BB, 0x1A8, 0xBB, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1B2, 0x1BB, 0x1C8, 0xBB, 0x140, 0x1FE },
    { 0x180, 0x100, 0x190, 0x1CF, 0x140, 0xCF, 0x150, 0x1FE },
    { 0x180, 0x100, 0x198, 0x1CF, 0x160, 0xCF, 0x160, 0x1FE },
    { 0x1C0, 0x100, 0x1E6, 0x100, 0x298, 0, 0x170, 0x1FE },
    { 0x1C0, 0x100, 0x1EE, 0x100, 0x2B8, 0, 0x140, 0x1FD },
    { 0x1C0, 0x100, 0x1C0, 0x100, 0x200, 0, 0x150, 0x1FD },
    { 0x1C0, 0x100, 0x1C6, 0x100, 0x218, 0, 0x160, 0x1FD },
    { 0x1C0, 0x100, 0x1CE, 0x100, 0x238, 0, 0x170, 0x1FD },
    { 0x1C0, 0x100, 0x1D6, 0x100, 0x258, 0, 0x140, 0x1FC },
    { 0x1C0, 0x100, 0x1F6, 0x100, 0x2D8, 0, 0x150, 0x1FC },
    { 0x1C0, 0x100, 0x1DE, 0x120, 0x278, 0x20, 0x160, 0x1FC },
    { 0x1C0, 0x100, 0x1E6, 0x120, 0x298, 0x20, 0x170, 0x1FC },
    { 0x1C0, 0x100, 0x1EE, 0x120, 0x2B8, 0x20, 0x140, 0x1FB },
    { 0x1C0, 0x100, 0x1F6, 0x120, 0x2D8, 0x20, 0x150, 0x1FB },
    { 0x180, 0x100, 0x1A0, 0x1AC, 0x180, 0xAC, 0x160, 0x1FB },
    { 0x180, 0x100, 0x1B0, 0x12E, 0x1C0, 0x2E, 0x170, 0x1FB },
};
u16 D_800A559C[] = { 0x601B, 1, 0xFFFF };
u16 D_800A55A4[] = { 0x701F, 1, 0xFFFF };
FieldTalk D_800A55AC[] = {
    { NULL, NULL, 0x10D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55C4[] = {
    { NULL, NULL, 0x10F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55DC[] = {
    { NULL, NULL, 0x10B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55F4[] = {
    { NULL, NULL, 0x108 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A560C[] = {
    { NULL, NULL, 0x115 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5624[] = {
    { NULL, NULL, 0x111 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A563C[] = {
    { NULL, NULL, 0x114 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5654[] = {
    { NULL, NULL, 0x105 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A566C[] = {
    { NULL, NULL, 0x113 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5684[] = {
    { NULL, NULL, 0x116 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A569C[] = {
    { NULL, NULL, 0x1CF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56B4[] = {
    { D_800A559C, NULL, 0x1D0 },
    { D_800A55A4, NULL, 0x1D1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56D8[] = {
    { NULL, NULL, 0x112 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56F0[] = {
    { NULL, NULL, 0x104 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5708[] = {
    { NULL, NULL, 0x10E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5720[] = {
    { NULL, NULL, 0x110 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5738[] = {
    { NULL, NULL, 0x10A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5750[] = {
    { NULL, NULL, 0x107 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5768[] = {
    { NULL, NULL, 0x106 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5780[] = {
    { NULL, NULL, 0x10C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5798[] = {
    { NULL, NULL, 0x109 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57B0[] = {
    { NULL, NULL, 0x103 },
    { NULL, NULL, 0 },
};
u16 D_800A57C8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A57D0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A57D8[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A57E4[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A57F0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A57F8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5800[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5808[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5814[] = { 0x602B, 1, 0xFFFF };
u16 D_800A581C[] = { 0x1A0A, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5828[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5830[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5838[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5840[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A584C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5854[] = { 0x701A, 1, 0xFFFF };
u16 D_800A585C[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5868[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5874[] = { 0x701A, 1, 0xFFFF };
u16 D_800A587C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5884[] = { 0x701A, 1, 0xFFFF };
u16 D_800A588C[] = { 0x40A3, 0, 0xFFFF };
u16 D_800A5894[] = { 0x601B, 1, 0xFFFF };
FieldActorEntry D_800A589C = { D_800A57C8, D_800A55AC, 0x25, 4, 449, 481, 1 };
FieldActorEntry D_800A58B0 = { D_800A57D0, D_800A55C4, 0x26, 5, 833, 257, 7 };
FieldActorEntry D_800A58C4 = { D_800A57D8, D_800A55DC, 0x2E, 6, 632, 406, 1 };
FieldActorEntry D_800A58D8 = { D_800A57E4, D_800A55F4, 0x31, 7, 914, 344, 1 };
FieldActorEntry D_800A58EC = { D_800A57F0, D_800A560C, 0x32, 8, 449, 481, 1 };
FieldActorEntry D_800A5900 = { D_800A57F8, D_800A5624, 0x34, 9, 833, 257, 7 };
FieldActorEntry D_800A5914 = { D_800A5800, D_800A563C, 0x38, 0xA, 882, 585, 3 };
FieldActorEntry D_800A5928 = { D_800A5808, D_800A5654, 0x39, 0xB, 882, 585, 3 };
FieldActorEntry D_800A593C = { D_800A5814, D_800A566C, 0x3A, 0xC, 914, 344, 1 };
FieldActorEntry D_800A5950 = { D_800A581C, D_800A5684, 0x66, 0xD, 553, 461, 1 };
FieldActorEntry D_800A5964 = { D_800A5828, D_800A569C, 0x73, 0xE, 449, 481, 1 };
FieldActorEntry D_800A5978 = { D_800A5830, D_800A56B4, 0x74, 0xF, 833, 257, 7 };
FieldActorEntry D_800A598C = { D_800A5838, D_800A56D8, 0x8F, 0x10, 352, 234, 1 };
FieldActorEntry D_800A59A0 = { D_800A5840, D_800A56F0, 0x9D, 0x11, 882, 585, 3 };
FieldActorEntry D_800A59B4 = { D_800A584C, D_800A5708, 0x9D, 0x11, 449, 481, 1 };
FieldActorEntry D_800A59C8 = { D_800A5854, D_800A5720, 0x9E, 0x12, 833, 257, 7 };
FieldActorEntry D_800A59DC = { D_800A585C, D_800A5738, 0x9E, 0x12, 632, 406, 1 };
FieldActorEntry D_800A59F0 = { D_800A5868, D_800A5750, 0x9F, 0x13, 914, 344, 1 };
FieldActorEntry D_800A5A04 = { D_800A5874, D_800A5768, 0x9F, 0x13, 882, 585, 3 };
FieldActorEntry D_800A5A18 = { D_800A587C, D_800A5780, 0xA0, 0x14, 632, 406, 1 };
FieldActorEntry D_800A5A2C = { D_800A5884, D_800A5798, 0xA1, 0x15, 914, 344, 1 };
FieldActorEntry D_800A5A40 = { D_800A588C, D_800A57B0, 0xD2, 0x16, 352, 234, 1 };
FieldActorEntry D_800A5A54 = { D_800A5894, NULL, 0x13C, 0x17, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
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
    &D_800A59DC,
    &D_800A59F0,
    &D_800A5A04,
    &D_800A5A18,
    &D_800A5A2C,
    &D_800A5A40,
    &D_800A5A54,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 1, 0x4A, 2, 0, 1, 0, 3, 6, 0, 441, 290, 0, 0 },
    { 1, 1, 0x4A, 2, 0, 1, 0, 3, 6, 0, 817, 114, 0, 0 },
    { 1, 1, 0x4A, 2, 0, 1, 0, 3, 6, 0, 949, 528, 0, 0 },
    { 1, 1, 0x40, 2, 4, 1, 4, 7, 4, 0, 366, 274, 0, 0 },
    { 1, 1, 0x40, 2, 4, 1, 4, 7, 4, 0, 446, 241, 0, 0 },
    { 1, 1, 0x40, 2, 4, 1, 4, 7, 4, 0, 1129, 333, 0, 0 },
    { 1, 0, 0x80, 2, 0x24, 0, 0, 0, 0, 0, 469, 191, 0, 0 },
    { 1, 0, 0x80, 2, 0x25, 0, 0, 0, 0, 0, 256, 161, 0, 0 },
    { 1, 1, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 411, 424, 0, 0 },
    { 1, 1, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 538, 379, 0, 0 },
    { 1, 1, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 568, 341, 0, 0 },
    { 1, 1, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 607, 347, 0, 0 },
    { 1, 1, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 976, 215, 0, 0 },
    { 1, 1, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 544, 363, 0, 0 },
    { 1, 1, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 579, 380, 0, 0 },
    { 1, 1, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 884, 243, 0, 0 },
    { 1, 1, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 913, 244, 0, 0 },
    { 1, 1, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 1020, 218, 0, 0 },
    { 1, 0x65, 0x40, 6, 0x1B, 0, 0, 0, 0, 0, 721, 200, 0, 0 },
    { 1, 0x64, 0x40, 6, 0x1C, 0, 0, 0, 0, 0, 451, 367, 0, 0 },
    { 1, 0, 0x78, 6, 0x26, 0, 0, 0, 0, 0, 721, 200, 0, 0 },
    { 1, 0, 0x80, 6, 0x27, 0, 0, 0, 0, 0, 451, 367, 0, 0 },
    { 1, 1, 0x40, 4, 8, 1, 8, 0xB, 4, 0, 448, 405, 445, 0 },
    { 1, 1, 0x40, 4, 0xC, 1, 0xC, 0xF, 4, 0, 465, 438, 464, 0 },
    { 1, 1, 0x40, 4, 0xC, 1, 0xC, 0xF, 4, 0, 737, 256, 281, 0 },
    { 1, 0, 0x64, 4, 0x1D, 0, 0, 0, 0, 0, 784, 496, 560, 0 },
    { 1, 0, 0x64, 4, 0x1E, 0, 0, 0, 0, 0, 768, 488, 552, 0 },
    { 1, 0, 0x64, 4, 0x1F, 0, 0, 0, 0, 0, 752, 480, 544, 0 },
    { 1, 0, 0x64, 4, 0x20, 0, 0, 0, 0, 0, 736, 472, 536, 0 },
    { 1, 0, 0x64, 4, 0x21, 0, 0, 0, 0, 0, 720, 464, 528, 0 },
    { 1, 0, 0x64, 4, 0x22, 0, 0, 0, 0, 0, 704, 456, 520, 0 },
    { 1, 0, 0x64, 4, 0x23, 0, 0, 0, 0, 0, 672, 456, 496, 0 },
    { 1, 0, 0x40, 4, 0x18, 0, 0, 0, 0, 0, 898, 552, 576, 0 },
    { 1, 0, 0x40, 4, 0x19, 0, 0, 0, 0, 0, 727, 258, 280, 0 },
    { 1, 0, 0x40, 4, 0x1A, 0, 0, 0, 0, 0, 447, 408, 444, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x298, 0x448, 0xF8, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29E, 0xC8, 0x1A4, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29E, 0x1B8, 0x204, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29D, 0x208, 0x1AC, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x29F, 0x1A7, 0x254, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x400, 0x120, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x410, 0x188, 0, 0, 0, 0 },
    { { { 0x40A3, 0 }, { 0xFFFF, 0 } }, 8, 0x2E4, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 740, D_800A5028, EVENT_TEXT(0x29), NULL, func_800A4E3C },
    { 741, D_800A50CC, EVENT_TEXT(0x2A), NULL, func_800A4E88 },
    { 743, D_800A5188, EVENT_TEXT(0x2B), NULL, func_800A4ED4 },
    { -1, NULL, 0, NULL, NULL },
};
