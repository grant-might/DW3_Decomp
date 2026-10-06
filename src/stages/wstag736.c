#include "common.h"
#include "stage.h"
extern StageEffectSpot D_800A56BC[];

/* Creates the stage's ten effects and the event object of flags 0x4082/0x4083 */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (i = 0; i < 10; i++) {
            if (D_800A56BC[i].kind == 0) {
                children[i] = createStageEffect(D_800A56BC[i].x, D_800A56BC[i].y, D_800A56BC[i].frame);
            }
        }
        if (FLAGS_00.checkCondition(0x4082, 1) && FLAGS_00.checkCondition(0x4083, 0)) {
            children[10] = FIELDSTG_startEvent(0x50E);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x2C
#include "common/start_stage.inc.c"
#include "common/step_animation.inc.c"
#include "common/draw_stage_effect.inc.c"
#include "common/is_on_screen.inc.c"
#include "common/update_stage_effect.inc.c"
#include "common/create_stage_effect.inc.c"

void func_800A53BC(void) {
    FLAGS_00.applyAction(0x4082, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A5408(void) {
    FLAGS_00.applyAction(0x4083, 1);
    FLAGS_00.applyAction(0x8230, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6BB
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6CA
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x12700, 0x24B00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x19;
    D_800990B4.music = 0x60640000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A57A4;
extern Battle D_800A57B0;
extern Battle D_800A57BC;
extern Battle D_800A57C8;
extern Battle D_800A57D4;
extern Battle D_800A57E0;
extern Battle D_800A57EC;
extern Battle D_800A57F8;
extern Battle D_800A5828;
extern Battle D_800A5834;
extern Battle D_800A5840;
extern Battle D_800A584C;
extern Battle D_800A5858;
extern Battle D_800A5864;
extern Battle D_800A5870;
extern Battle D_800A587C;
extern Battle D_800A58AC;
extern Battle D_800A58B8;
extern Battle D_800A58C4;
extern Battle D_800A58D0;
extern Battle D_800A58DC;
extern Battle D_800A58E8;
extern Battle D_800A58F4;
extern Battle D_800A5900;
extern Battle D_800A5930;
extern Battle D_800A593C;
extern Battle D_800A5948;
extern Battle D_800A5954;
extern Battle D_800A5960;
extern Battle D_800A596C;
extern Battle D_800A5978;
extern Battle D_800A5984;
extern BattleList D_800A5804;
extern BattleList D_800A5888;
extern BattleList D_800A590C;
extern BattleList D_800A5990;
extern u16 D_800A5A80[];
extern u16 D_800A5A88[];
extern u16 D_800A5A90[];
extern u16 D_800A5A98[];
extern u16 D_800A5AA0[];
extern u16 D_800A5AA8[];
extern u16 D_800A5AB0[];
extern u16 D_800A5AB8[];
extern u16 D_800A5AC0[];
extern u16 D_800A5AC8[];
extern u16 D_800A5AD0[];
extern u16 D_800A5AD8[];
extern u16 D_800A5AE0[];
extern u16 D_800A5AE8[];
extern u16 D_800A5C58[];
extern FieldTalk D_800A5AF0[];
extern u16 D_800A5C64[];
extern FieldTalk D_800A5B20[];
extern u16 D_800A5C6C[];
extern FieldTalk D_800A5B38[];
extern u16 D_800A5C74[];
extern FieldTalk D_800A5B68[];
extern u16 D_800A5C7C[];
extern FieldTalk D_800A5B80[];
extern u16 D_800A5C84[];
extern FieldTalk D_800A5B98[];
extern u16 D_800A5C90[];
extern FieldTalk D_800A5BB0[];
extern u16 D_800A5C9C[];
extern FieldTalk D_800A5BC8[];
extern u16 D_800A5CA4[];
extern FieldTalk D_800A5BE0[];
extern u16 D_800A5CB4[];
extern FieldTalk D_800A5C1C[];
extern FieldActorEntry D_800A5CC4;
extern FieldActorEntry D_800A5CD8;
extern FieldActorEntry D_800A5CEC;
extern FieldActorEntry D_800A5D00;
extern FieldActorEntry D_800A5D14;
extern FieldActorEntry D_800A5D28;
extern FieldActorEntry D_800A5D3C;
extern FieldActorEntry D_800A5D50;
extern FieldActorEntry D_800A5D64;
extern FieldActorEntry D_800A5D78;
extern s16 D_800A5568[];
extern s16 D_800A5604[];

s16 D_800A5568[] = {
    0x600, 1, 2,
    0x102, 2, 0x138, 0x25C, 3,
    0x100, 0xCB, 0x120, 0x251,
    0x101, 0xCB, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xCB, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xCB, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x1\n");
#endif
s16 D_800A5604[] = {
    0x600, 1, 0xCB,
    0x100, 2, 0x138, 0x25C,
    0x101, 2, 1, 3,
    0x100, 0xCB, 0x120, 0x251,
    0x101, 0xCB, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0xCB, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x3C,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x101, 0xCB, 1, 5,
    0x300, 0x1E,
    0x102, 0xCB, 0x150, 0x239, 5,
    0x302, 0xCB,
    0x101, 0xCB, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x120, 0x251, 3,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0xCB, 0,
    0x301,
    0x600, 1, 2,
    0x300, 0x1E,
    0,
};
StageEffectSpot D_800A56BC[] = {
    { 36, 0, 0x14C, 0x264 },
    { 28, 0, 236, 0x1B4 },
    { 28, 0, 0x17C, 0x1CC },
    { 28, 0, 0x1BC, 0x28C },
    { 28, 0, 0x21C, 0x2BC },
    { 28, 0, 0x2AC, 0x2D4 },
    { 28, 0, 0x32C, 0x2F4 },
    { 28, 0, 0x38C, 0x2F4 },
    { 28, 0, 0x3FC, 0x2BC },
    { 20, 0, 0x3AC, 68 },
};
AnimFrame effectClutFrames[] = {
    { 0, 6 }, { 1, 6 }, { 2, 68 }, { 1, 4 },
    { 0, 4 }, { 255, 0 },
};
AnimFrame effectFrames[] = {
    { 0x12C, 18 }, { 1, 6 }, { 2, 6 }, { 3, 6 },
    { 4, 6 }, { 5, 4 }, { 6, 4 }, { 7, 4 },
    { 5, 4 }, { 6, 4 }, { 7, 4 }, { 5, 4 },
    { 6, 4 }, { 7, 4 }, { 5, 4 }, { 6, 4 },
    { 7, 4 }, { 4, 4 }, { 3, 4 }, { 2, 4 },
    { 1, 4 }, { 255, 0x3E7 },
};
Battle D_800A57A4 = { 187, 25, 0x60080000 };
Battle D_800A57B0 = { 187, 25, 0x60080000 };
Battle D_800A57BC = { 187, 25, 0x60080000 };
Battle D_800A57C8 = { 187, 25, 0x60080000 };
Battle D_800A57D4 = { 129, 25, 0x60080000 };
Battle D_800A57E0 = { 129, 25, 0x60080000 };
Battle D_800A57EC = { 129, 25, 0x60080000 };
Battle D_800A57F8 = { 129, 25, 0x60080000 };
BattleList D_800A5804 = {
    5,
    { &D_800A57A4, &D_800A57B0, &D_800A57BC, &D_800A57C8,
      &D_800A57D4, &D_800A57E0, &D_800A57EC, &D_800A57F8 },
};
Battle D_800A5828 = { 0, 0, 0x60040000 };
Battle D_800A5834 = { 0, 0, 0x60040000 };
Battle D_800A5840 = { 0, 0, 0x60040000 };
Battle D_800A584C = { 0, 0, 0x60040000 };
Battle D_800A5858 = { 0, 0, 0x60040000 };
Battle D_800A5864 = { 0, 0, 0x60040000 };
Battle D_800A5870 = { 0, 0, 0x60040000 };
Battle D_800A587C = { 0, 0, 0x60040000 };
BattleList D_800A5888 = {
    0,
    { &D_800A5828, &D_800A5834, &D_800A5840, &D_800A584C,
      &D_800A5858, &D_800A5864, &D_800A5870, &D_800A587C },
};
Battle D_800A58AC = { 0, 0, 0x60040000 };
Battle D_800A58B8 = { 0, 0, 0x60040000 };
Battle D_800A58C4 = { 0, 0, 0x60040000 };
Battle D_800A58D0 = { 0, 0, 0x60040000 };
Battle D_800A58DC = { 0, 0, 0x60040000 };
Battle D_800A58E8 = { 0, 0, 0x60040000 };
Battle D_800A58F4 = { 0, 0, 0x60040000 };
Battle D_800A5900 = { 0, 0, 0x60040000 };
BattleList D_800A590C = {
    0,
    { &D_800A58AC, &D_800A58B8, &D_800A58C4, &D_800A58D0,
      &D_800A58DC, &D_800A58E8, &D_800A58F4, &D_800A5900 },
};
Battle D_800A5930 = { 27, 25, 0x608C0000 };
Battle D_800A593C = { 0, 0, 0x60040000 };
Battle D_800A5948 = { 0, 0, 0x60040000 };
Battle D_800A5954 = { 0, 0, 0x60040000 };
Battle D_800A5960 = { 0, 0, 0x60040000 };
Battle D_800A596C = { 0, 0, 0x60040000 };
Battle D_800A5978 = { 0, 0, 0x60040000 };
Battle D_800A5984 = { 0, 0, 0x60040000 };
BattleList D_800A5990 = {
    0,
    { &D_800A5930, &D_800A593C, &D_800A5948, &D_800A5954,
      &D_800A5960, &D_800A596C, &D_800A5978, &D_800A5984 },
};
FieldBattles stageBattles[] = {
    { 120, 0, 0, { &D_800A5804, &D_800A5888, &D_800A590C, &D_800A5990 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x146, 0x1B0, 0x18, 0xB0, 0x150, 0x1F6 },
    { 0x140, 0x100, 0x15E, 0x1A8, 0x78, 0xA8, 0x160, 0x1F6 },
    { 0x140, 0x100, 0x166, 0x1A8, 0x98, 0xA8, 0x170, 0x1F6 },
    { 0x140, 0x100, 0x16E, 0x1A8, 0xB8, 0xA8, 0x140, 0x1F5 },
    { 0x140, 0x100, 0x140, 0x1B0, 0, 0xB0, 0x160, 0x1F5 },
};
u16 D_800A5A80[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5A88[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5A90[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5A98[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5AA0[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5AA8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5AB0[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5AB8[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5AC0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5AC8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5AD0[] = { 0x701D, 1, 0xFFFF };
u16 D_800A5AD8[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5AE0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5AE8[] = { 0x602B, 1, 0xFFFF };
FieldTalk D_800A5AF0[] = {
    { D_800A5A80, NULL, 0x207 },
    { D_800A5A88, NULL, 0x208 },
    { D_800A5A90, NULL, 0x209 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B20[] = {
    { NULL, NULL, 0x20B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B38[] = {
    { D_800A5A98, NULL, 0x20C },
    { D_800A5AA0, NULL, 0x20D },
    { D_800A5AA8, NULL, 0x20E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B68[] = {
    { NULL, NULL, 0x210 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B80[] = {
    { NULL, NULL, 0x20F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B98[] = {
    { NULL, NULL, 0x205 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BB0[] = {
    { NULL, NULL, 0x205 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BC8[] = {
    { NULL, NULL, 0x20A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BE0[] = {
    { D_800A5AB0, NULL, 0x202 },
    { D_800A5AB8, NULL, 0x203 },
    { D_800A5AC0, NULL, 0x204 },
    { D_800A5AC8, NULL, 0x206 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C1C[] = {
    { D_800A5AD0, NULL, 0x202 },
    { D_800A5AD8, NULL, 0x203 },
    { D_800A5AE0, NULL, 0x204 },
    { D_800A5AE8, NULL, 0x206 },
    { NULL, NULL, 0 },
};
u16 D_800A5C58[] = { 0x7008, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5C64[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5C6C[] = { 0x701E, 1, 0xFFFF };
u16 D_800A5C74[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5C7C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5C84[] = { 0x4083, 0, 0x701A, 1, 0xFFFF };
u16 D_800A5C90[] = { 0x701A, 1, 0x4083, 1, 0xFFFF };
u16 D_800A5C9C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5CA4[] = { 0x701A, 0, 0x4083, 1, 0x7008, 1, 0xFFFF };
u16 D_800A5CB4[] = { 0x7008, 1, 0x4083, 0, 0x701A, 0, 0xFFFF };
FieldActorEntry D_800A5CC4 = { D_800A5C58, D_800A5AF0, 0x2D, 4, 944, 233, 1 };
FieldActorEntry D_800A5CD8 = { D_800A5C64, D_800A5B20, 0x2D, 4, 944, 233, 1 };
FieldActorEntry D_800A5CEC = { D_800A5C6C, D_800A5B38, 0x42, 5, 1041, 105, 3 };
FieldActorEntry D_800A5D00 = { D_800A5C74, D_800A5B68, 0x42, 5, 1041, 105, 3 };
FieldActorEntry D_800A5D14 = { D_800A5C7C, D_800A5B80, 0x42, 5, 1041, 105, 3 };
FieldActorEntry D_800A5D28 = { D_800A5C84, D_800A5B98, 0x9D, 6, 288, 593, 7 };
FieldActorEntry D_800A5D3C = { D_800A5C90, D_800A5BB0, 0x9D, 6, 336, 569, 1 };
FieldActorEntry D_800A5D50 = { D_800A5C9C, D_800A5BC8, 0x9E, 7, 944, 233, 1 };
FieldActorEntry D_800A5D64 = { D_800A5CA4, D_800A5BE0, 0xCB, 8, 336, 569, 1 };
FieldActorEntry D_800A5D78 = { D_800A5CB4, D_800A5C1C, 0xCB, 8, 288, 593, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5CC4,
    &D_800A5CD8,
    &D_800A5CEC,
    &D_800A5D00,
    &D_800A5D14,
    &D_800A5D28,
    &D_800A5D3C,
    &D_800A5D50,
    &D_800A5D64,
    &D_800A5D78,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 430, 326, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 443, 315, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 456, 288, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 458, 346, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 464, 275, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 494, 375, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 500, 402, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 555, 192, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 574, 190, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 698, 393, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 727, 379, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 778, 446, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 814, 430, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 872, 226, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 886, 236, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 909, 415, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 971, 387, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 996, 373, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 1022, 295, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 7, 4, 0, 1036, 293, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 435, 329, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 446, 320, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 452, 282, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 462, 280, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 464, 350, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 497, 381, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 501, 395, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 548, 194, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 567, 186, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 573, 196, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 584, 253, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 691, 394, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 694, 361, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 699, 371, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 724, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 785, 443, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 817, 425, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 841, 435, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 848, 267, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 852, 465, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 875, 232, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 890, 242, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 915, 412, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 976, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 988, 346, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 991, 377, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 1014, 291, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 7, 4, 0, 1034, 300, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D0, 0x78, 0x144, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D3, 0x40C, 0x6E, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x400, 0x80, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x3F0, 0xD8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 6, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 9, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 0xB, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D2, 0x140, 0x260, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x2D2, 0x3C0, 0x50, 7, 0, 0, 0 },
    { { { 0x4082, 0 }, { 0x701A, 0 } }, 8, 0x50D, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xB, 0, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xC, 0, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1293, D_800A5568, EVENT_TEXT(9), NULL, func_800A53BC },
    { 1294, D_800A5604, EVENT_TEXT(0x14), NULL, func_800A5408 },
    { -1, NULL, 0, NULL, NULL },
};
