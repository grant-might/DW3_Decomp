#include "common.h"
#include "stage.h"
extern StageEffectSpot D_800A5698[];

/* Creates the stage's ten effects and the event object of flags 0x400E/0x4019 */
void updateStage(StageTask *task, void **children) {
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        for (i = 0; i < 10; i++) {
            if (D_800A5698[i].kind == 0) {
                children[i] = createStageEffect(D_800A5698[i].x, D_800A5698[i].y, D_800A5698[i].frame);
            }
        }
        if (FLAGS_00.checkCondition(0x400E, 1) && FLAGS_00.checkCondition(0x4019, 0)) {
            children[10] = FIELDSTG_startEvent(0x317);
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
    FLAGS_00.applyAction(0x400E, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Applies flag actions 0x8ADD and 0x4019 */
void func_800A5408(void) {
    FLAGS_00.applyAction(0x8ADD, 1);
    FLAGS_00.applyAction(0x4019, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xDB
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6AC
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6BB
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x12500, 0x24E00};
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

void func_800A5408();
extern Battle D_800A5780;
extern Battle D_800A578C;
extern Battle D_800A5798;
extern Battle D_800A57A4;
extern Battle D_800A57B0;
extern Battle D_800A57BC;
extern Battle D_800A57C8;
extern Battle D_800A57D4;
extern Battle D_800A5804;
extern Battle D_800A5810;
extern Battle D_800A581C;
extern Battle D_800A5828;
extern Battle D_800A5834;
extern Battle D_800A5840;
extern Battle D_800A584C;
extern Battle D_800A5858;
extern Battle D_800A5888;
extern Battle D_800A5894;
extern Battle D_800A58A0;
extern Battle D_800A58AC;
extern Battle D_800A58B8;
extern Battle D_800A58C4;
extern Battle D_800A58D0;
extern Battle D_800A58DC;
extern Battle D_800A590C;
extern Battle D_800A5918;
extern Battle D_800A5924;
extern Battle D_800A5930;
extern Battle D_800A593C;
extern Battle D_800A5948;
extern Battle D_800A5954;
extern Battle D_800A5960;
extern BattleList D_800A57E0;
extern BattleList D_800A5864;
extern BattleList D_800A58E8;
extern BattleList D_800A596C;
extern u16 D_800A5A5C[];
extern u16 D_800A5A64[];
extern u16 D_800A5A6C[];
extern u16 D_800A5BB8[];
extern FieldTalk D_800A5A74[];
extern u16 D_800A5BC0[];
extern FieldTalk D_800A5A8C[];
extern u16 D_800A5BC8[];
extern FieldTalk D_800A5AA4[];
extern u16 D_800A5BD0[];
extern FieldTalk D_800A5AC8[];
extern u16 D_800A5BD8[];
extern FieldTalk D_800A5AE0[];
extern u16 D_800A5BE0[];
extern FieldTalk D_800A5AF8[];
extern u16 D_800A5BE8[];
extern FieldTalk D_800A5B10[];
extern u16 D_800A5BF0[];
extern FieldTalk D_800A5B28[];
extern u16 D_800A5BF8[];
extern FieldTalk D_800A5B40[];
extern u16 D_800A5C00[];
extern FieldTalk D_800A5B58[];
extern u16 D_800A5C08[];
extern FieldTalk D_800A5B70[];
extern u16 D_800A5C10[];
extern FieldTalk D_800A5B88[];
extern u16 D_800A5C1C[];
extern FieldTalk D_800A5BA0[];
extern FieldActorEntry D_800A5C28;
extern FieldActorEntry D_800A5C3C;
extern FieldActorEntry D_800A5C50;
extern FieldActorEntry D_800A5C64;
extern FieldActorEntry D_800A5C78;
extern FieldActorEntry D_800A5C8C;
extern FieldActorEntry D_800A5CA0;
extern FieldActorEntry D_800A5CB4;
extern FieldActorEntry D_800A5CC8;
extern FieldActorEntry D_800A5CDC;
extern FieldActorEntry D_800A5CF0;
extern FieldActorEntry D_800A5D04;
extern FieldActorEntry D_800A5D18;
extern s16 D_800A5568[];
extern s16 D_800A5604[];

s16 D_800A5568[] = {
    0x600, 1, 2,
    0x102, 2, 0x138, 0x25C, 3,
    0x100, 0xC8, 0x120, 0x251,
    0x101, 0xC8, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xC8, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xC8, 2,
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
__asm__(".section .data\n\t.half 0x240\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x800A\n");
#endif
s16 D_800A5604[] = {
    0x600, 1, 0xC8,
    0x100, 2, 0x138, 0x25C,
    0x101, 2, 1, 3,
    0x100, 0xC8, 0x120, 0x251,
    0x101, 0xC8, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0xC8, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0xC8, 1, 5,
    0x300, 0x1E,
    0x102, 0xC8, 0x150, 0x239, 5,
    0x302, 0xC8,
    0x101, 0xC8, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x120, 0x251, 3,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0xC8, 2,
    0x301,
    0x600, 1, 2,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x1\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x800A\n");
#endif
StageEffectSpot D_800A5698[] = {
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
Battle D_800A5780 = { 117, 25, 0x60080000 };
Battle D_800A578C = { 117, 25, 0x60080000 };
Battle D_800A5798 = { 117, 25, 0x60080000 };
Battle D_800A57A4 = { 117, 25, 0x60080000 };
Battle D_800A57B0 = { 167, 25, 0x60080000 };
Battle D_800A57BC = { 167, 25, 0x60080000 };
Battle D_800A57C8 = { 167, 25, 0x60080000 };
Battle D_800A57D4 = { 167, 25, 0x60080000 };
BattleList D_800A57E0 = {
    5,
    { &D_800A5780, &D_800A578C, &D_800A5798, &D_800A57A4,
      &D_800A57B0, &D_800A57BC, &D_800A57C8, &D_800A57D4 },
};
Battle D_800A5804 = { 0, 0, 0x60040000 };
Battle D_800A5810 = { 0, 0, 0x60040000 };
Battle D_800A581C = { 0, 0, 0x60040000 };
Battle D_800A5828 = { 0, 0, 0x60040000 };
Battle D_800A5834 = { 0, 0, 0x60040000 };
Battle D_800A5840 = { 0, 0, 0x60040000 };
Battle D_800A584C = { 0, 0, 0x60040000 };
Battle D_800A5858 = { 0, 0, 0x60040000 };
BattleList D_800A5864 = {
    0,
    { &D_800A5804, &D_800A5810, &D_800A581C, &D_800A5828,
      &D_800A5834, &D_800A5840, &D_800A584C, &D_800A5858 },
};
Battle D_800A5888 = { 0, 0, 0x60040000 };
Battle D_800A5894 = { 0, 0, 0x60040000 };
Battle D_800A58A0 = { 0, 0, 0x60040000 };
Battle D_800A58AC = { 0, 0, 0x60040000 };
Battle D_800A58B8 = { 0, 0, 0x60040000 };
Battle D_800A58C4 = { 0, 0, 0x60040000 };
Battle D_800A58D0 = { 0, 0, 0x60040000 };
Battle D_800A58DC = { 0, 0, 0x60040000 };
BattleList D_800A58E8 = {
    0,
    { &D_800A5888, &D_800A5894, &D_800A58A0, &D_800A58AC,
      &D_800A58B8, &D_800A58C4, &D_800A58D0, &D_800A58DC },
};
Battle D_800A590C = { 19, 25, 0x608C0000 };
Battle D_800A5918 = { 0, 0, 0x60040000 };
Battle D_800A5924 = { 0, 0, 0x60040000 };
Battle D_800A5930 = { 0, 0, 0x60040000 };
Battle D_800A593C = { 0, 0, 0x60040000 };
Battle D_800A5948 = { 0, 0, 0x60040000 };
Battle D_800A5954 = { 0, 0, 0x60040000 };
Battle D_800A5960 = { 0, 0, 0x60040000 };
BattleList D_800A596C = {
    0,
    { &D_800A590C, &D_800A5918, &D_800A5924, &D_800A5930,
      &D_800A593C, &D_800A5948, &D_800A5954, &D_800A5960 },
};
FieldBattles stageBattles[] = {
    { 87, 0, 0, { &D_800A57E0, &D_800A5864, &D_800A58E8, &D_800A596C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x15E, 0x1A8, 0x78, 0xA8, 0x150, 0x1F6 },
    { 0x140, 0x100, 0x166, 0x1A8, 0x98, 0xA8, 0x160, 0x1F6 },
    { 0x140, 0x100, 0x16E, 0x1A8, 0xB8, 0xA8, 0x170, 0x1F6 },
    { 0x140, 0x100, 0x176, 0x1A8, 0xD8, 0xA8, 0x140, 0x1F5 },
    { 0x140, 0x100, 0x140, 0x1B0, 0, 0xB0, 0x150, 0x1F5 },
};
u16 D_800A5A5C[] = { 0, 0, 0xFFFF };
u16 D_800A5A64[] = { 0, 1, 0xFFFF };
u16 D_800A5A6C[] = { 0, 1, 0xFFFF };
FieldTalk D_800A5A74[] = {
    { NULL, NULL, 0x1F7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A8C[] = {
    { NULL, NULL, 0x1F5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AA4[] = {
    { D_800A5A5C, D_800A5A64, 0x1F4 },
    { D_800A5A6C, NULL, 0x1F5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AC8[] = {
    { NULL, NULL, 0x1FB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AE0[] = {
    { NULL, NULL, 0x1FA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AF8[] = {
    { NULL, NULL, 0x1F9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B10[] = {
    { NULL, NULL, 0x1F8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B28[] = {
    { NULL, NULL, 0x1F6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B40[] = {
    { NULL, NULL, 0x204 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B58[] = {
    { NULL, NULL, 0x205 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B70[] = {
    { NULL, NULL, 0x203 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B88[] = {
    { NULL, NULL, 0x202 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BA0[] = {
    { NULL, NULL, 0x202 },
    { NULL, NULL, 0 },
};
u16 D_800A5BB8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5BC0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5BC8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5BD0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5BD8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5BE0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5BE8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5BF0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5BF8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5C00[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5C08[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5C10[] = { 0x4019, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5C1C[] = { 0x7019, 1, 0x4019, 1, 0xFFFF };
FieldActorEntry D_800A5C28 = { D_800A5BB8, D_800A5A74, 0x2E, 4, 1041, 105, 1 };
FieldActorEntry D_800A5C3C = { D_800A5BC0, D_800A5A8C, 0x2E, 4, 944, 233, 1 };
FieldActorEntry D_800A5C50 = { D_800A5BC8, D_800A5AA4, 0x2E, 4, 944, 233, 1 };
FieldActorEntry D_800A5C64 = { D_800A5BD0, D_800A5AC8, 0x41, 5, 944, 233, 5 };
FieldActorEntry D_800A5C78 = { D_800A5BD8, D_800A5AE0, 0x41, 5, 1041, 105, 3 };
FieldActorEntry D_800A5C8C = { D_800A5BE0, D_800A5AF8, 0x41, 5, 1041, 105, 3 };
FieldActorEntry D_800A5CA0 = { D_800A5BE8, D_800A5B10, 0x41, 5, 1041, 105, 3 };
FieldActorEntry D_800A5CB4 = { D_800A5BF0, D_800A5B28, 0x9D, 6, 944, 233, 1 };
FieldActorEntry D_800A5CC8 = { D_800A5BF8, D_800A5B40, 0x9E, 7, 336, 569, 1 };
FieldActorEntry D_800A5CDC = { D_800A5C00, D_800A5B58, 0xC8, 8, 336, 569, 1 };
FieldActorEntry D_800A5CF0 = { D_800A5C08, D_800A5B70, 0xC8, 8, 336, 569, 1 };
FieldActorEntry D_800A5D04 = { D_800A5C10, D_800A5B88, 0xC8, 8, 288, 593, 7 };
FieldActorEntry D_800A5D18 = { D_800A5C1C, D_800A5BA0, 0xC8, 8, 336, 569, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5C28,
    &D_800A5C3C,
    &D_800A5C50,
    &D_800A5C64,
    &D_800A5C78,
    &D_800A5C8C,
    &D_800A5CA0,
    &D_800A5CB4,
    &D_800A5CC8,
    &D_800A5CDC,
    &D_800A5CF0,
    &D_800A5D04,
    &D_800A5D18,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x268, 0x78, 0x144, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x26B, 0x40C, 0x6E, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x400, 0x80, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x3F0, 0xD8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 6, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 9, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 0xB, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26A, 0x140, 0x260, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xD, 0x26A, 0x3C0, 0x50, 7, 0, 0, 0 },
    { { { 0x8011, 1 }, { 0x400E, 0 } }, 8, 0x316, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xB, 0, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0xC, 0, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 790, D_800A5568, EVENT_TEXT(0xA), NULL, func_800A53BC },
    { 791, D_800A5604, EVENT_TEXT(0xB), NULL, func_800A5408 },
    { -1, NULL, 0, NULL, NULL },
};
