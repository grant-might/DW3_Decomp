#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x4023, 1) && FLAGS_00.checkCondition(0x4024, 0)) {
            children[0] = FIELDSTG_startEvent(0x4F2);
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

void func_800A4DA4(void) {
    FLAGS_00.applyAction(0x4023, 1);
    FLAGS_00.applyAction(0x7401, 1);
}

void func_800A4DF0(void) {
    FLAGS_00.applyAction(0x4024, 1);
    FLAGS_00.applyAction(0x8006, 1);
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x501
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x511
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x14C00, 0x14400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x34;
    D_800990B4.music = 0x60D00000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress < 0x18) {
        D_800990B4.battles = &stageBattles[0];
    } else {
        D_800990B4.battles = &stageBattles[1];
    }
}

extern Battle D_800A5094;
extern Battle D_800A50A0;
extern Battle D_800A50AC;
extern Battle D_800A50B8;
extern Battle D_800A50C4;
extern Battle D_800A50D0;
extern Battle D_800A50DC;
extern Battle D_800A50E8;
extern Battle D_800A5118;
extern Battle D_800A5124;
extern Battle D_800A5130;
extern Battle D_800A513C;
extern Battle D_800A5148;
extern Battle D_800A5154;
extern Battle D_800A5160;
extern Battle D_800A516C;
extern Battle D_800A519C;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A51F0;
extern Battle D_800A5220;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5274;
extern Battle D_800A52A4;
extern Battle D_800A52B0;
extern Battle D_800A52BC;
extern Battle D_800A52C8;
extern Battle D_800A52D4;
extern Battle D_800A52E0;
extern Battle D_800A52EC;
extern Battle D_800A52F8;
extern Battle D_800A5328;
extern Battle D_800A5334;
extern Battle D_800A5340;
extern Battle D_800A534C;
extern Battle D_800A5358;
extern Battle D_800A5364;
extern Battle D_800A5370;
extern Battle D_800A537C;
extern Battle D_800A53AC;
extern Battle D_800A53B8;
extern Battle D_800A53C4;
extern Battle D_800A53D0;
extern Battle D_800A53DC;
extern Battle D_800A53E8;
extern Battle D_800A53F4;
extern Battle D_800A5400;
extern Battle D_800A5430;
extern Battle D_800A543C;
extern Battle D_800A5448;
extern Battle D_800A5454;
extern Battle D_800A5460;
extern Battle D_800A546C;
extern Battle D_800A5478;
extern Battle D_800A5484;
extern BattleList D_800A50F4;
extern BattleList D_800A5178;
extern BattleList D_800A51FC;
extern BattleList D_800A5280;
extern BattleList D_800A5304;
extern BattleList D_800A5388;
extern BattleList D_800A540C;
extern BattleList D_800A5490;
extern u16 D_800A55AC[];
extern u16 D_800A55B4[];
extern u16 D_800A55BC[];
extern u16 D_800A55C8[];
extern u16 D_800A55D8[];
extern u16 D_800A55E0[];
extern u16 D_800A55F4[];
extern u16 D_800A5600[];
extern u16 D_800A5618[];
extern u16 D_800A5634[];
extern u16 D_800A5650[];
extern u16 D_800A5658[];
extern u16 D_800A5660[];
extern u16 D_800A5668[];
extern u16 D_800A5674[];
extern u16 D_800A5684[];
extern u16 D_800A568C[];
extern u16 D_800A56A0[];
extern u16 D_800A56AC[];
extern u16 D_800A56C4[];
extern u16 D_800A56E0[];
extern u16 D_800A56FC[];
extern u16 D_800A5704[];
extern u16 D_800A570C[];
extern u16 D_800A5714[];
extern u16 D_800A5720[];
extern u16 D_800A5730[];
extern u16 D_800A5738[];
extern u16 D_800A574C[];
extern u16 D_800A5758[];
extern u16 D_800A5770[];
extern u16 D_800A578C[];
extern u16 D_800A57A8[];
extern u16 D_800A57B0[];
extern u16 D_800A57B8[];
extern u16 D_800A57C4[];
extern u16 D_800A57CC[];
extern u16 D_800A57D8[];
extern u16 D_800A57E4[];
extern u16 D_800A57EC[];
extern u16 D_800A57F8[];
extern u16 D_800A5800[];
extern u16 D_800A5808[];
extern u16 D_800A5814[];
extern u16 D_800A5824[];
extern u16 D_800A582C[];
extern u16 D_800A5840[];
extern u16 D_800A5848[];
extern u16 D_800A5860[];
extern u16 D_800A587C[];
extern u16 D_800A5898[];
extern u16 D_800A5B64[];
extern FieldTalk D_800A58A0[];
extern u16 D_800A5B74[];
extern FieldTalk D_800A5900[];
extern u16 D_800A5B84[];
extern FieldTalk D_800A5918[];
extern u16 D_800A5B94[];
extern FieldTalk D_800A5978[];
extern u16 D_800A5BA4[];
extern FieldTalk D_800A59D8[];
extern u16 D_800A5BB4[];
extern FieldTalk D_800A5A08[];
extern u16 D_800A5BBC[];
extern FieldTalk D_800A5A20[];
extern u16 D_800A5BC4[];
extern FieldTalk D_800A5A38[];
extern u16 D_800A5BCC[];
extern FieldTalk D_800A5A50[];
extern u16 D_800A5BD4[];
extern FieldTalk D_800A5A68[];
extern u16 D_800A5BDC[];
extern FieldTalk D_800A5A80[];
extern u16 D_800A5BE8[];
extern FieldTalk D_800A5AA4[];
extern u16 D_800A5BF0[];
extern FieldTalk D_800A5ABC[];
extern u16 D_800A5BF8[];
extern FieldTalk D_800A5B1C[];
extern u16 D_800A5C00[];
extern FieldTalk D_800A5B34[];
extern u16 D_800A5C08[];
extern FieldTalk D_800A5B4C[];
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
extern FieldActorEntry D_800A5CEC;
extern FieldActorEntry D_800A5D00;
extern FieldActorEntry D_800A5D14;
extern FieldActorEntry D_800A5D28;
extern FieldActorEntry D_800A5D3C;
extern s16 D_800A4FA0[];
extern s16 D_800A5010[];

s16 D_800A4FA0[] = {
    0x600, 1, 2,
    0x102, 2, 0x104, 0x14A, 3,
    0x100, 0x7B, 0xE8, 0x13C,
    0x101, 0x7B, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 2, 0x7B, 2,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x8FBF\n");
#endif
s16 D_800A5010[] = {
    0x600, 1, 2,
    0x100, 2, 0x104, 0x14A,
    0x101, 2, 1, 3,
    0x100, 0x7B, 0xE8, 0x13C,
    0x101, 0x7B, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 2, 0x7B, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x3C,
    0,
};
Battle D_800A5094 = { 53, 8, 0x60080000 };
Battle D_800A50A0 = { 53, 8, 0x60080000 };
Battle D_800A50AC = { 53, 8, 0x60080000 };
Battle D_800A50B8 = { 147, 8, 0x60080000 };
Battle D_800A50C4 = { 147, 8, 0x60080000 };
Battle D_800A50D0 = { 147, 8, 0x60080000 };
Battle D_800A50DC = { 54, 8, 0x60080000 };
Battle D_800A50E8 = { 54, 8, 0x60080000 };
BattleList D_800A50F4 = {
    3,
    { &D_800A5094, &D_800A50A0, &D_800A50AC, &D_800A50B8,
      &D_800A50C4, &D_800A50D0, &D_800A50DC, &D_800A50E8 },
};
Battle D_800A5118 = { 0, 0, 0x60040000 };
Battle D_800A5124 = { 0, 0, 0x60040000 };
Battle D_800A5130 = { 0, 0, 0x60040000 };
Battle D_800A513C = { 0, 0, 0x60040000 };
Battle D_800A5148 = { 0, 0, 0x60040000 };
Battle D_800A5154 = { 0, 0, 0x60040000 };
Battle D_800A5160 = { 0, 0, 0x60040000 };
Battle D_800A516C = { 0, 0, 0x60040000 };
BattleList D_800A5178 = {
    0,
    { &D_800A5118, &D_800A5124, &D_800A5130, &D_800A513C,
      &D_800A5148, &D_800A5154, &D_800A5160, &D_800A516C },
};
Battle D_800A519C = { 0, 0, 0x60040000 };
Battle D_800A51A8 = { 0, 0, 0x60040000 };
Battle D_800A51B4 = { 0, 0, 0x60040000 };
Battle D_800A51C0 = { 0, 0, 0x60040000 };
Battle D_800A51CC = { 0, 0, 0x60040000 };
Battle D_800A51D8 = { 0, 0, 0x60040000 };
Battle D_800A51E4 = { 0, 0, 0x60040000 };
Battle D_800A51F0 = { 0, 0, 0x60040000 };
BattleList D_800A51FC = {
    0,
    { &D_800A519C, &D_800A51A8, &D_800A51B4, &D_800A51C0,
      &D_800A51CC, &D_800A51D8, &D_800A51E4, &D_800A51F0 },
};
Battle D_800A5220 = { 211, 8, 0x600C0000 };
Battle D_800A522C = { 264, 8, 0x60880000 };
Battle D_800A5238 = { 0, 0, 0x60040000 };
Battle D_800A5244 = { 329, 8, 0x60080000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 147, 8, 0x60080000 };
Battle D_800A5274 = { 0, 0, 0x60040000 };
BattleList D_800A5280 = {
    0,
    { &D_800A5220, &D_800A522C, &D_800A5238, &D_800A5244,
      &D_800A5250, &D_800A525C, &D_800A5268, &D_800A5274 },
};
Battle D_800A52A4 = { 53, 8, 0x60080000 };
Battle D_800A52B0 = { 53, 8, 0x60080000 };
Battle D_800A52BC = { 147, 8, 0x60080000 };
Battle D_800A52C8 = { 147, 8, 0x60080000 };
Battle D_800A52D4 = { 60, 8, 0x60080000 };
Battle D_800A52E0 = { 60, 8, 0x60080000 };
Battle D_800A52EC = { 60, 8, 0x60080000 };
Battle D_800A52F8 = { 60, 8, 0x60080000 };
BattleList D_800A5304 = {
    3,
    { &D_800A52A4, &D_800A52B0, &D_800A52BC, &D_800A52C8,
      &D_800A52D4, &D_800A52E0, &D_800A52EC, &D_800A52F8 },
};
Battle D_800A5328 = { 0, 0, 0x60040000 };
Battle D_800A5334 = { 0, 0, 0x60040000 };
Battle D_800A5340 = { 0, 0, 0x60040000 };
Battle D_800A534C = { 0, 0, 0x60040000 };
Battle D_800A5358 = { 0, 0, 0x60040000 };
Battle D_800A5364 = { 0, 0, 0x60040000 };
Battle D_800A5370 = { 0, 0, 0x60040000 };
Battle D_800A537C = { 0, 0, 0x60040000 };
BattleList D_800A5388 = {
    0,
    { &D_800A5328, &D_800A5334, &D_800A5340, &D_800A534C,
      &D_800A5358, &D_800A5364, &D_800A5370, &D_800A537C },
};
Battle D_800A53AC = { 0, 0, 0x60040000 };
Battle D_800A53B8 = { 0, 0, 0x60040000 };
Battle D_800A53C4 = { 0, 0, 0x60040000 };
Battle D_800A53D0 = { 0, 0, 0x60040000 };
Battle D_800A53DC = { 0, 0, 0x60040000 };
Battle D_800A53E8 = { 0, 0, 0x60040000 };
Battle D_800A53F4 = { 0, 0, 0x60040000 };
Battle D_800A5400 = { 0, 0, 0x60040000 };
BattleList D_800A540C = {
    0,
    { &D_800A53AC, &D_800A53B8, &D_800A53C4, &D_800A53D0,
      &D_800A53DC, &D_800A53E8, &D_800A53F4, &D_800A5400 },
};
Battle D_800A5430 = { 211, 8, 0x600C0000 };
Battle D_800A543C = { 264, 8, 0x60880000 };
Battle D_800A5448 = { 0, 0, 0x60040000 };
Battle D_800A5454 = { 329, 8, 0x60080000 };
Battle D_800A5460 = { 0, 0, 0x60040000 };
Battle D_800A546C = { 0, 0, 0x60040000 };
Battle D_800A5478 = { 147, 8, 0x60080000 };
Battle D_800A5484 = { 0, 0, 0x60040000 };
BattleList D_800A5490 = {
    0,
    { &D_800A5430, &D_800A543C, &D_800A5448, &D_800A5454,
      &D_800A5460, &D_800A546C, &D_800A5478, &D_800A5484 },
};
FieldBattles stageBattles[] = {
    { 13, 0, 0, { &D_800A50F4, &D_800A5178, &D_800A51FC, &D_800A5280 } },
    { 54, 1, 0, { &D_800A5304, &D_800A5388, &D_800A540C, &D_800A5490 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x1A5, 0xD8, 0xA5, 0x160, 0x1FF },
    { 0x140, 0x100, 0x140, 0x1B5, 0, 0xB5, 0x170, 0x1FF },
    { 0x140, 0x100, 0x166, 0x100, 0x98, 0, 0x140, 0x1FE },
    { 0x140, 0x100, 0x148, 0x1B5, 0x20, 0xB5, 0x150, 0x1FE },
    { 0x140, 0x100, 0x150, 0x1B5, 0x40, 0xB5, 0x160, 0x1FE },
    { 0x140, 0x100, 0x158, 0x1BD, 0x60, 0xBD, 0x170, 0x1FE },
};
u16 D_800A55AC[] = { 0, 0, 0xFFFF };
u16 D_800A55B4[] = { 0, 1, 0xFFFF };
u16 D_800A55BC[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A55C8[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A55D8[] = { 0x7615, 1, 0xFFFF };
u16 D_800A55E0[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 0, 0xFFFF };
u16 D_800A55F4[] = { 0x7400, 1, 0xE0B, 1, 0xFFFF };
u16 D_800A5600[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5618[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A5634[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A5650[] = { 0x7815, 1, 0xFFFF };
u16 D_800A5658[] = { 0, 0, 0xFFFF };
u16 D_800A5660[] = { 0, 1, 0xFFFF };
u16 D_800A5668[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5674[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A5684[] = { 0x7615, 1, 0xFFFF };
u16 D_800A568C[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 0, 0xFFFF };
u16 D_800A56A0[] = { 0x7400, 1, 0xE0B, 1, 0xFFFF };
u16 D_800A56AC[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A56C4[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A56E0[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A56FC[] = { 0x7815, 1, 0xFFFF };
u16 D_800A5704[] = { 0, 0, 0xFFFF };
u16 D_800A570C[] = { 0, 1, 0xFFFF };
u16 D_800A5714[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5720[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A5730[] = { 0x7615, 1, 0xFFFF };
u16 D_800A5738[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 0, 0xFFFF };
u16 D_800A574C[] = { 0x7400, 1, 0xE0B, 1, 0xFFFF };
u16 D_800A5758[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5770[] = {
    0, 1, 0x7202, 1, 0x7206, 0, 0x7204, 1,
    0x8012, 1, 0xE0B, 1, 0xFFFF,
};
u16 D_800A578C[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A57A8[] = { 0x7815, 1, 0xFFFF };
u16 D_800A57B0[] = { 0x11, 0, 0xFFFF };
u16 D_800A57B8[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A57C4[] = { 0x11, 0, 0xFFFF };
u16 D_800A57CC[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A57D8[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A57E4[] = { 0x1C12, 0, 0xFFFF };
u16 D_800A57EC[] = { 0x1C12, 1, 0x9025, 1, 0xFFFF };
u16 D_800A57F8[] = { 0x1C12, 1, 0xFFFF };
u16 D_800A5800[] = { 0, 0, 0xFFFF };
u16 D_800A5808[] = { 0, 1, 0x7202, 1, 0xFFFF };
u16 D_800A5814[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A5824[] = { 0x7615, 1, 0xFFFF };
u16 D_800A582C[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0B, 0, 0xFFFF };
u16 D_800A5840[] = { 0xE0B, 1, 0xFFFF };
u16 D_800A5848[] = {
    0x7204, 1, 0x8012, 0, 0, 1, 0x7202, 1,
    0xE0B, 1, 0xFFFF,
};
u16 D_800A5860[] = {
    0x7204, 1, 0x8012, 1, 0, 1, 0x7202, 1,
    0xE0B, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A587C[] = {
    0, 1, 0x7202, 1, 0xE0B, 1, 0x7204, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A5898[] = { 0x7815, 1, 0xFFFF };
FieldTalk D_800A58A0[] = {
    { D_800A55AC, D_800A55B4, 0x97 },
    { D_800A55BC, NULL, 0x9C },
    { D_800A55C8, D_800A55D8, 0x9D },
    { D_800A55E0, D_800A55F4, 0x9E },
    { D_800A5600, NULL, 0x9F },
    { D_800A5618, NULL, 0xA0 },
    { D_800A5634, D_800A5650, 0xA1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5900[] = {
    { NULL, NULL, 0x27F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5918[] = {
    { D_800A5658, D_800A5660, 0x98 },
    { D_800A5668, NULL, 0x9C },
    { D_800A5674, D_800A5684, 0x9D },
    { D_800A568C, D_800A56A0, 0x9E },
    { D_800A56AC, NULL, 0x9F },
    { D_800A56C4, NULL, 0xA0 },
    { D_800A56E0, D_800A56FC, 0xA1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5978[] = {
    { D_800A5704, D_800A570C, 0x99 },
    { D_800A5714, NULL, 0x9C },
    { D_800A5720, D_800A5730, 0x9D },
    { D_800A5738, D_800A574C, 0x9E },
    { D_800A5758, NULL, 0x9F },
    { D_800A5770, NULL, 0xA0 },
    { D_800A578C, D_800A57A8, 0xA1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59D8[] = {
    { D_800A57B0, NULL, 0x97 },
    { D_800A57B8, D_800A57C4, 0xA2 },
    { D_800A57CC, D_800A57D8, 0xA3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A08[] = {
    { NULL, NULL, 0x1F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A20[] = {
    { NULL, NULL, 0x1F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A38[] = {
    { NULL, NULL, 0x11C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A50[] = {
    { NULL, NULL, 0x11D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A68[] = {
    { NULL, NULL, 0x12B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A80[] = {
    { D_800A57E4, D_800A57EC, 0x2BD },
    { D_800A57F8, NULL, 0x2BE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AA4[] = {
    { NULL, NULL, 0x12A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5ABC[] = {
    { D_800A5800, NULL, 0x9A },
    { D_800A5808, NULL, 0x9A },
    { D_800A5814, D_800A5824, 0x9A },
    { D_800A582C, D_800A5840, 0x9A },
    { D_800A5848, NULL, 0x9A },
    { D_800A5860, NULL, 0x9A },
    { D_800A587C, D_800A5898, 0x9A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B1C[] = {
    { NULL, NULL, 0x331 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B34[] = {
    { NULL, NULL, 0x331 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B4C[] = {
    { NULL, NULL, 0x331 },
    { NULL, NULL, 0 },
};
u16 D_800A5B64[] = { 0x7003, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5B74[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5B84[] = { 0x7004, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5B94[] = { 0x6026, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5BA4[] = { 0x7009, 1, 0x11, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5BB4[] = { 0x6019, 1, 0xFFFF };
u16 D_800A5BBC[] = { 0x601A, 1, 0xFFFF };
u16 D_800A5BC4[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5BCC[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5BD4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5BDC[] = { 0x600, 1, 0x8006, 0, 0xFFFF };
u16 D_800A5BE8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5BF0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5BF8[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5C00[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5C08[] = { 0x600A, 1, 0xFFFF };
FieldActorEntry D_800A5C10 = { D_800A5B64, D_800A58A0, 0x31, 4, 595, 475, 1 };
FieldActorEntry D_800A5C24 = { D_800A5B74, D_800A5900, 0x31, 4, 595, 475, 1 };
FieldActorEntry D_800A5C38 = { D_800A5B84, D_800A5918, 0x31, 4, 595, 475, 1 };
FieldActorEntry D_800A5C4C = { D_800A5B94, D_800A5978, 0x31, 4, 595, 475, 1 };
FieldActorEntry D_800A5C60 = { D_800A5BA4, D_800A59D8, 0x31, 4, 595, 475, 1 };
FieldActorEntry D_800A5C74 = { D_800A5BB4, D_800A5A08, 0x39, 5, 611, 171, 1 };
FieldActorEntry D_800A5C88 = { D_800A5BBC, D_800A5A20, 0x39, 5, 611, 171, 1 };
FieldActorEntry D_800A5C9C = { D_800A5BC4, D_800A5A38, 0x39, 5, 611, 171, 1 };
FieldActorEntry D_800A5CB0 = { D_800A5BCC, D_800A5A50, 0x39, 5, 611, 171, 1 };
FieldActorEntry D_800A5CC4 = { D_800A5BD4, D_800A5A68, 0x39, 5, 207, 311, 3 };
FieldActorEntry D_800A5CD8 = { D_800A5BDC, D_800A5A80, 0x7B, 6, 232, 316, 7 };
FieldActorEntry D_800A5CEC = { D_800A5BE8, D_800A5AA4, 0x9D, 7, 611, 171, 1 };
FieldActorEntry D_800A5D00 = { D_800A5BF0, D_800A5ABC, 0x9E, 8, 595, 475, 1 };
FieldActorEntry D_800A5D14 = { D_800A5BF8, D_800A5B1C, 0xB2, 9, 288, 496, 3 };
FieldActorEntry D_800A5D28 = { D_800A5C00, D_800A5B34, 0xB2, 9, 288, 496, 3 };
FieldActorEntry D_800A5D3C = { D_800A5C08, D_800A5B4C, 0xB2, 9, 288, 496, 3 };
FieldActorEntry *stageActors[] = {
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
    &D_800A5CEC,
    &D_800A5D00,
    &D_800A5D14,
    &D_800A5D28,
    &D_800A5D3C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 2, 1, 2, 7, 8, 0, 95, 22, 0, 0 },
    { 1, 0, 0x40, 2, 2, 1, 2, 7, 8, 0, 700, 48, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 235, 430, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 273, 238, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 363, 254, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 696, 424, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 94, 336, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 662, 456, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 367, 482, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 476, 345, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 669, 498, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 417, 446, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 421, 278, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 596, 526, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 166, 432, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 229, 375, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 436, 275, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 483, 489, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 172, 351, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 283, 392, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 451, 287, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 550, 507, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 127, 287, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 133, 280, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 185, 434, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 219, 401, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 390, 474, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 417, 508, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 669, 570, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 672, 562, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 683, 497, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 690, 430, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 709, 426, 0, 0 },
    { 1, 0x64, 0x40, 6, 1, 0, 0, 0, 0, 0, 490, 108, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, -4, 274, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, -2, 366, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 65, 485, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 85, 170, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 129, 227, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 159, 389, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 176, 334, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 273, 212, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 355, 284, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 358, 517, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 378, 421, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 389, 573, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 471, 540, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 498, 475, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 500, 291, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 556, 625, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 650, 485, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 687, 407, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 750, 536, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 104, 604, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 133, 404, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 136, 302, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 142, 447, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 212, 399, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 290, 266, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 300, 550, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 341, 568, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 377, 471, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 420, 254, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 480, 327, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 576, 564, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 623, 521, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 0xA, 0, 750, 426, 0, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 464, 77, 161, 0 },
    { 1, 0, 0x80, 4, 0xD, 0, 0, 0, 0, 0, 358, 119, 155, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 223, 167, 167, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 248, 140, 140, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 295, 115, 115, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 304, 151, 151, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 599, 123, 123, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 656, 313, 313, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 690, 375, 375, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x234, 0x668, 0xB4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x232, 0x190, 0x218, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1265, D_800A4FA0, EVENT_TEXT(0x13), NULL, func_800A4DA4 },
    { 1266, D_800A5010, EVENT_TEXT(0x14), NULL, func_800A4DF0 },
    { -1, NULL, 0, NULL, NULL },
};
