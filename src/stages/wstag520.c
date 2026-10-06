#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 10 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0xA && FLAGS_00.checkCondition(0x4002, 1)) {
            children[0] = FIELDSTG_startEvent(0x105);
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

void func_800A4D94(void) {
    FLAGS_00.applyAction(0x4002, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Event: applies action 0x800A and sets the progress to 11 */
void func_800A4DE0(void) {
    FLAGS_00.applyAction(0x800A, 1);
    GAME.progress = 0xB;
}

void func_800A4E14(void) {
    GAME.progress = 26;
}

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x23C
#define STAGE_ARCHIVE 0x3CC
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x24B
#define STAGE_ARCHIVE 0x3DC
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x11500, 0xDC00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x12;
    D_800990B4.music = 0x60480000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

void func_800A4DE0();
extern Battle D_800A514C;
extern Battle D_800A5158;
extern Battle D_800A5164;
extern Battle D_800A5170;
extern Battle D_800A517C;
extern Battle D_800A5188;
extern Battle D_800A5194;
extern Battle D_800A51A0;
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
extern BattleList D_800A51AC;
extern BattleList D_800A5230;
extern BattleList D_800A52B4;
extern BattleList D_800A5338;
extern u16 D_800A5468[];
extern u16 D_800A5474[];
extern u16 D_800A5480[];
extern u16 D_800A548C[];
extern u16 D_800A5494[];
extern u16 D_800A549C[];
extern u16 D_800A54A4[];
extern u16 D_800A5860[];
extern FieldTalk D_800A54AC[];
extern u16 D_800A5868[];
extern FieldTalk D_800A54C4[];
extern u16 D_800A5870[];
extern FieldTalk D_800A54DC[];
extern u16 D_800A5878[];
extern FieldTalk D_800A54F4[];
extern u16 D_800A5880[];
extern FieldTalk D_800A550C[];
extern u16 D_800A5888[];
extern FieldTalk D_800A5524[];
extern u16 D_800A5890[];
extern FieldTalk D_800A553C[];
extern u16 D_800A5898[];
extern FieldTalk D_800A5554[];
extern u16 D_800A58A0[];
extern FieldTalk D_800A5584[];
extern u16 D_800A58A8[];
extern FieldTalk D_800A559C[];
extern u16 D_800A58B0[];
extern FieldTalk D_800A55B4[];
extern u16 D_800A58B8[];
extern FieldTalk D_800A55CC[];
extern u16 D_800A58C0[];
extern FieldTalk D_800A55E4[];
extern u16 D_800A58C8[];
extern FieldTalk D_800A55FC[];
extern u16 D_800A58D0[];
extern FieldTalk D_800A5614[];
extern u16 D_800A58D8[];
extern FieldTalk D_800A5638[];
extern u16 D_800A58E0[];
extern FieldTalk D_800A5650[];
extern u16 D_800A58E8[];
extern FieldTalk D_800A5668[];
extern u16 D_800A58F4[];
extern FieldTalk D_800A5680[];
extern u16 D_800A58FC[];
extern FieldTalk D_800A5698[];
extern u16 D_800A5904[];
extern FieldTalk D_800A56B0[];
extern u16 D_800A590C[];
extern FieldTalk D_800A56C8[];
extern u16 D_800A5914[];
extern FieldTalk D_800A56E0[];
extern u16 D_800A591C[];
extern FieldTalk D_800A56F8[];
extern u16 D_800A5924[];
extern FieldTalk D_800A5710[];
extern u16 D_800A592C[];
extern FieldTalk D_800A5728[];
extern u16 D_800A5938[];
extern FieldTalk D_800A5740[];
extern u16 D_800A5940[];
extern FieldTalk D_800A5758[];
extern u16 D_800A5948[];
extern FieldTalk D_800A5770[];
extern u16 D_800A5950[];
extern FieldTalk D_800A5788[];
extern u16 D_800A5958[];
extern FieldTalk D_800A57A0[];
extern u16 D_800A5960[];
extern FieldTalk D_800A57B8[];
extern u16 D_800A5968[];
extern FieldTalk D_800A57D0[];
extern u16 D_800A5970[];
extern FieldTalk D_800A57E8[];
extern u16 D_800A5978[];
extern FieldTalk D_800A5800[];
extern u16 D_800A5980[];
extern FieldTalk D_800A5818[];
extern u16 D_800A5988[];
extern FieldTalk D_800A5830[];
extern u16 D_800A5990[];
extern FieldTalk D_800A5848[];
extern FieldActorEntry D_800A5998;
extern FieldActorEntry D_800A59AC;
extern FieldActorEntry D_800A59C0;
extern FieldActorEntry D_800A59D4;
extern FieldActorEntry D_800A59E8;
extern FieldActorEntry D_800A59FC;
extern FieldActorEntry D_800A5A10;
extern FieldActorEntry D_800A5A24;
extern FieldActorEntry D_800A5A38;
extern FieldActorEntry D_800A5A4C;
extern FieldActorEntry D_800A5A60;
extern FieldActorEntry D_800A5A74;
extern FieldActorEntry D_800A5A88;
extern FieldActorEntry D_800A5A9C;
extern FieldActorEntry D_800A5AB0;
extern FieldActorEntry D_800A5AC4;
extern FieldActorEntry D_800A5AD8;
extern FieldActorEntry D_800A5AEC;
extern FieldActorEntry D_800A5B00;
extern FieldActorEntry D_800A5B14;
extern FieldActorEntry D_800A5B28;
extern FieldActorEntry D_800A5B3C;
extern FieldActorEntry D_800A5B50;
extern FieldActorEntry D_800A5B64;
extern FieldActorEntry D_800A5B78;
extern FieldActorEntry D_800A5B8C;
extern FieldActorEntry D_800A5BA0;
extern FieldActorEntry D_800A5BB4;
extern FieldActorEntry D_800A5BC8;
extern FieldActorEntry D_800A5BDC;
extern FieldActorEntry D_800A5BF0;
extern FieldActorEntry D_800A5C04;
extern FieldActorEntry D_800A5C18;
extern FieldActorEntry D_800A5C2C;
extern FieldActorEntry D_800A5C40;
extern FieldActorEntry D_800A5C54;
extern FieldActorEntry D_800A5C68;
extern FieldActorEntry D_800A5C7C;
extern FieldActorEntry D_800A5C90;
extern FieldActorEntry D_800A5CA4;
extern FieldActorEntry D_800A5CB8;
extern s16 D_800A4F4C[];
extern s16 D_800A4FC0[];
extern s16 D_800A5078[];

s16 D_800A4F4C[] = {
    0x102, 2, 0x1B9, 0xD5, 3,
    0x100, 0x8D, 0x1A1, 0xC9,
    0x101, 0x8D, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0x8D, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x8D, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A4FC0[] = {
    0x100, 2, 0x1B9, 0xD5,
    0x101, 2, 1, 3,
    0x100, 0x8D, 0x1A1, 0xC9,
    0x101, 0x8D, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0x8D, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x8D, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0x8D, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x1D1, 0xE1, 7,
    0x300, 6,
    0x304, 0x23E, 0x238, 0x8C, 1,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x1\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x800A\n");
#endif
s16 D_800A5078[] = {
    0x102, 2, 0x129, 0xCD, 5,
    0x100, 0x42, 0x141, 0xC1,
    0x101, 0x42, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0x42, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x42, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x168, 0xF5, 7,
    0x101, 0x42, 1, 3,
    0x300, 0x3C,
    0x304, 0x23E, 0x238, 0x8C, 1,
    0,
};
Battle D_800A514C = { 0, 0, 0x60040000 };
Battle D_800A5158 = { 0, 0, 0x60040000 };
Battle D_800A5164 = { 0, 0, 0x60040000 };
Battle D_800A5170 = { 0, 0, 0x60040000 };
Battle D_800A517C = { 0, 0, 0x60040000 };
Battle D_800A5188 = { 0, 0, 0x60040000 };
Battle D_800A5194 = { 0, 0, 0x60040000 };
Battle D_800A51A0 = { 0, 0, 0x60040000 };
BattleList D_800A51AC = {
    3,
    { &D_800A514C, &D_800A5158, &D_800A5164, &D_800A5170,
      &D_800A517C, &D_800A5188, &D_800A5194, &D_800A51A0 },
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
Battle D_800A52D8 = { 4, 18, 0x608C0000 };
Battle D_800A52E4 = { 302, 18, 0x608C0000 };
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
FieldBattles stageBattles[] = {
    { 165, 0, 0, { &D_800A51AC, &D_800A5230, &D_800A52B4, &D_800A5338 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x19D, 0, 0x9D, 0x160, 0x1FF },
    { 0x140, 0x100, 0x166, 0x19D, 0x98, 0x9D, 0x170, 0x1FF },
    { 0x140, 0x100, 0x168, 0x175, 0xA0, 0x75, 0x160, 0x1FE },
    { 0x140, 0x100, 0x14C, 0x15A, 0x30, 0x5A, 0x170, 0x1FE },
    { 0x140, 0x100, 0x170, 0x175, 0xC0, 0x75, 0x150, 0x1FD },
    { 0x140, 0x100, 0x156, 0x17E, 0x58, 0x7E, 0x160, 0x1FD },
    { 0x140, 0x100, 0x15E, 0x17E, 0x78, 0x7E, 0x170, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x19D, 0xB8, 0x9D, 0x150, 0x1FC },
    { 0x140, 0x100, 0x176, 0x19D, 0xD8, 0x9D, 0x160, 0x1FC },
};
u16 D_800A5468[] = { 0x1C1C, 0, 0x6014, 1, 0xFFFF };
u16 D_800A5474[] = { 0x1C1C, 1, 0x6014, 1, 0xFFFF };
u16 D_800A5480[] = { 0x7017, 1, 0x6014, 0, 0xFFFF };
u16 D_800A548C[] = { 0x1C1C, 0, 0xFFFF };
u16 D_800A5494[] = { 0x1C1C, 1, 0xFFFF };
u16 D_800A549C[] = { 0x9040, 1, 0xFFFF };
u16 D_800A54A4[] = { 0x9042, 1, 0xFFFF };
FieldTalk D_800A54AC[] = {
    { NULL, NULL, 0xA2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54C4[] = {
    { NULL, NULL, 0x93 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54DC[] = {
    { NULL, NULL, 0x96 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54F4[] = {
    { NULL, NULL, 0x99 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A550C[] = {
    { NULL, NULL, 0xAE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5524[] = {
    { NULL, NULL, 0xAB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A553C[] = {
    { NULL, NULL, 0xA8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5554[] = {
    { D_800A5468, NULL, 0x99 },
    { D_800A5474, NULL, 0x9C },
    { D_800A5480, NULL, 0x99 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5584[] = {
    { NULL, NULL, 0x9F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A559C[] = {
    { NULL, NULL, 0xA2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55B4[] = {
    { NULL, NULL, 0xA5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55CC[] = {
    { NULL, NULL, 0x11E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55E4[] = {
    { NULL, NULL, 0x97 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55FC[] = {
    { NULL, NULL, 0x9A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5614[] = {
    { D_800A548C, NULL, 0x9D },
    { D_800A5494, NULL, 0x3D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5638[] = {
    { NULL, NULL, 0xAC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5650[] = {
    { NULL, NULL, 0xA9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5668[] = {
    { NULL, NULL, 0x9D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5680[] = {
    { NULL, NULL, 0xA0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5698[] = {
    { NULL, NULL, 0xA3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56B0[] = {
    { NULL, NULL, 0xA6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56C8[] = {
    { NULL, NULL, 0x11F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56E0[] = {
    { NULL, NULL, 0x91 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56F8[] = {
    { NULL, D_800A549C, 0xA3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5710[] = {
    { NULL, NULL, 0x94 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5728[] = {
    { NULL, NULL, 0x170 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5740[] = {
    { NULL, NULL, 0x170 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5758[] = {
    { NULL, NULL, 0x11D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5770[] = {
    { NULL, D_800A54A4, 0x92 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5788[] = {
    { NULL, NULL, 0xAA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57A0[] = {
    { NULL, NULL, 0x95 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57B8[] = {
    { NULL, NULL, 0x98 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57D0[] = {
    { NULL, NULL, 0x9B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57E8[] = {
    { NULL, NULL, 0xB0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5800[] = {
    { NULL, NULL, 0x9E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5818[] = {
    { NULL, NULL, 0xA1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5830[] = {
    { NULL, NULL, 0xAD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5848[] = {
    { NULL, NULL, 0x90 },
    { NULL, NULL, 0 },
};
u16 D_800A5860[] = { 0x6019, 1, 0xFFFF };
u16 D_800A5868[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5870[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5878[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5880[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5888[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5890[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5898[] = { 0x7017, 1, 0xFFFF };
u16 D_800A58A0[] = { 0x6018, 1, 0xFFFF };
u16 D_800A58A8[] = { 0x601A, 1, 0xFFFF };
u16 D_800A58B0[] = { 0x7019, 1, 0xFFFF };
u16 D_800A58B8[] = { 0x600B, 1, 0xFFFF };
u16 D_800A58C0[] = { 0x600E, 1, 0xFFFF };
u16 D_800A58C8[] = { 0x7016, 1, 0xFFFF };
u16 D_800A58D0[] = { 0x6014, 1, 0xFFFF };
u16 D_800A58D8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A58E0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A58E8[] = { 0x7017, 1, 0x6014, 0, 0xFFFF };
u16 D_800A58F4[] = { 0x6018, 1, 0xFFFF };
u16 D_800A58FC[] = { 0x601A, 1, 0xFFFF };
u16 D_800A5904[] = { 0x7019, 1, 0xFFFF };
u16 D_800A590C[] = { 0x600B, 1, 0xFFFF };
u16 D_800A5914[] = { 0x600A, 1, 0xFFFF };
u16 D_800A591C[] = { 0x6019, 1, 0xFFFF };
u16 D_800A5924[] = { 0x600C, 1, 0xFFFF };
u16 D_800A592C[] = { 0x7020, 1, 0x6021, 0, 0xFFFF };
u16 D_800A5938[] = { 0x601A, 1, 0xFFFF };
u16 D_800A5940[] = { 0x600B, 1, 0xFFFF };
u16 D_800A5948[] = { 0x600A, 1, 0xFFFF };
u16 D_800A5950[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5958[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5960[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5968[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5970[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5978[] = { 0x7017, 1, 0xFFFF };
u16 D_800A5980[] = { 0x6018, 1, 0xFFFF };
u16 D_800A5988[] = { 0x7005, 1, 0xFFFF };
u16 D_800A5990[] = { 0x600A, 1, 0xFFFF };
FieldActorEntry D_800A5998 = { D_800A5860, D_800A54AC, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A59AC = { D_800A5868, D_800A54C4, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A59C0 = { D_800A5870, D_800A54DC, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A59D4 = { D_800A5878, D_800A54F4, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A59E8 = { D_800A5880, D_800A550C, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A59FC = { D_800A5888, D_800A5524, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A5A10 = { D_800A5890, D_800A553C, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A5A24 = { D_800A5898, D_800A5554, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A5A38 = { D_800A58A0, D_800A5584, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A5A4C = { D_800A58A8, D_800A559C, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A5A60 = { D_800A58B0, D_800A55B4, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A5A74 = { D_800A58B8, D_800A55CC, 0x41, 4, 517, 289, 5 };
FieldActorEntry D_800A5A88 = { D_800A58C0, D_800A55E4, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5A9C = { D_800A58C8, D_800A55FC, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5AB0 = { D_800A58D0, D_800A5614, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5AC4 = { D_800A58D8, D_800A5638, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5AD8 = { D_800A58E0, D_800A5650, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5AEC = { D_800A58E8, D_800A5668, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5B00 = { D_800A58F4, D_800A5680, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5B14 = { D_800A58FC, D_800A5698, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5B28 = { D_800A5904, D_800A56B0, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5B3C = { D_800A590C, D_800A56C8, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5B50 = { D_800A5914, D_800A56E0, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5B64 = { D_800A591C, D_800A56F8, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5B78 = { D_800A5924, D_800A5710, 0x42, 5, 321, 193, 3 };
FieldActorEntry D_800A5B8C = { D_800A592C, D_800A5728, 0x67, 6, 400, 303, 7 };
FieldActorEntry D_800A5BA0 = { D_800A5938, D_800A5740, 0x67, 6, 400, 303, 7 };
FieldActorEntry D_800A5BB4 = { D_800A5940, D_800A5758, 0x8D, 7, 417, 201, 3 };
FieldActorEntry D_800A5BC8 = { D_800A5948, D_800A5770, 0x8D, 7, 417, 201, 3 };
FieldActorEntry D_800A5BDC = { D_800A5950, D_800A5788, 0x8D, 7, 417, 201, 3 };
FieldActorEntry D_800A5BF0 = { D_800A5958, D_800A57A0, 0x8D, 7, 417, 201, 3 };
FieldActorEntry D_800A5C04 = { D_800A5960, D_800A57B8, 0x8D, 7, 417, 201, 3 };
FieldActorEntry D_800A5C18 = { D_800A5968, D_800A57D0, 0x8D, 7, 417, 201, 3 };
FieldActorEntry D_800A5C2C = { D_800A5970, D_800A57E8, 0x8D, 7, 417, 201, 3 };
FieldActorEntry D_800A5C40 = { D_800A5978, D_800A5800, 0x8D, 7, 417, 201, 3 };
FieldActorEntry D_800A5C54 = { D_800A5980, D_800A5818, 0x8D, 7, 417, 201, 3 };
FieldActorEntry D_800A5C68 = { NULL, NULL, 0x93, 8, 198, 184, 7 };
FieldActorEntry D_800A5C7C = { NULL, NULL, 0x94, 9, 223, 172, 7 };
FieldActorEntry D_800A5C90 = { NULL, NULL, 0x95, 0xA, 248, 160, 7 };
FieldActorEntry D_800A5CA4 = { D_800A5988, D_800A5830, 0x9D, 0xB, 417, 201, 3 };
FieldActorEntry D_800A5CB8 = { D_800A5990, D_800A5848, 0x12C, 0xC, 520, 252, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A5998,
    &D_800A59AC,
    &D_800A59C0,
    &D_800A59D4,
    &D_800A59E8,
    &D_800A59FC,
    &D_800A5A10,
    &D_800A5A24,
    &D_800A5A38,
    &D_800A5A4C,
    &D_800A5A60,
    &D_800A5A74,
    &D_800A5A88,
    &D_800A5A9C,
    &D_800A5AB0,
    &D_800A5AC4,
    &D_800A5AD8,
    &D_800A5AEC,
    &D_800A5B00,
    &D_800A5B14,
    &D_800A5B28,
    &D_800A5B3C,
    &D_800A5B50,
    &D_800A5B64,
    &D_800A5B78,
    &D_800A5B8C,
    &D_800A5BA0,
    &D_800A5BB4,
    &D_800A5BC8,
    &D_800A5BDC,
    &D_800A5BF0,
    &D_800A5C04,
    &D_800A5C18,
    &D_800A5C2C,
    &D_800A5C40,
    &D_800A5C54,
    &D_800A5C68,
    &D_800A5C7C,
    &D_800A5C90,
    &D_800A5CA4,
    &D_800A5CB8,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 323, 114, 0, 0 },
    { 1, 0, 0xA0, 6, 0xA, 0, 0, 0, 0, 0, 367, 110, 0, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 205, 181, 199, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 237, 165, 183, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 270, 149, 167, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 186, 161, 199, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 218, 145, 183, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 252, 129, 167, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 521, 189, 272, 0 },
    { 1, 0, 0xA0, 4, 1, 0, 0, 0, 0, 0, 367, 110, 256, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 230, 243, 272, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 259, 221, 255, 0 },
    { 1, 0, 0x58, 4, 4, 0, 0, 0, 0, 0, 171, 118, 198, 0 },
    { 1, 0, 0x55, 4, 5, 0, 0, 0, 0, 0, 138, 106, 182, 0 },
    { 1, 0, 0x5C, 4, 6, 0, 0, 0, 0, 0, 263, 68, 153, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23E, 0x32A, 0x9C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23E, 0x238, 0x8C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x1CE, 0xE6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x1BE, 0x12E, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x220, 0x150, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x230, 0x1B8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 260, D_800A4F4C, EVENT_TEXT(1), NULL, func_800A4D94 },
    { 261, D_800A4FC0, EVENT_TEXT(2), NULL, func_800A4DE0 },
    { 695, D_800A5078, EVENT_TEXT(0x20), NULL, func_800A4E14 },
    { -1, NULL, 0, NULL, NULL },
};
