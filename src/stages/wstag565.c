#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x4029, 1) && FLAGS_00.checkCondition(0x402A, 0)) {
            children[0] = FIELDSTG_startEvent(0x4F8);
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

void func_800A4DA0(void) {
    FLAGS_00.applyAction(0x4029, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4DEC(void) {
    FLAGS_00.applyAction(0x402A, 1);
    FLAGS_00.applyAction(0x8026, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x50B
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x51B
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xC700, 0x1E500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x14;
    D_800990B4.music = 0x60500000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A506C;
extern Battle D_800A5078;
extern Battle D_800A5084;
extern Battle D_800A5090;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50B4;
extern Battle D_800A50C0;
extern Battle D_800A50F0;
extern Battle D_800A50FC;
extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern Battle D_800A5138;
extern Battle D_800A5144;
extern Battle D_800A5174;
extern Battle D_800A5180;
extern Battle D_800A518C;
extern Battle D_800A5198;
extern Battle D_800A51A4;
extern Battle D_800A51B0;
extern Battle D_800A51BC;
extern Battle D_800A51C8;
extern Battle D_800A51F8;
extern Battle D_800A5204;
extern Battle D_800A5210;
extern Battle D_800A521C;
extern Battle D_800A5228;
extern Battle D_800A5234;
extern Battle D_800A5240;
extern Battle D_800A524C;
extern BattleList D_800A50CC;
extern BattleList D_800A5150;
extern BattleList D_800A51D4;
extern BattleList D_800A5258;
extern u16 D_800A5338[];
extern u16 D_800A5348[];
extern u16 D_800A5358[];
extern u16 D_800A5368[];
extern u16 D_800A5370[];
extern u16 D_800A537C[];
extern u16 D_800A53F0[];
extern FieldTalk D_800A5384[];
extern u16 D_800A53F8[];
extern FieldTalk D_800A539C[];
extern u16 D_800A5400[];
extern FieldTalk D_800A53B4[];
extern u16 D_800A5408[];
extern FieldTalk D_800A53CC[];
extern FieldActorEntry D_800A5414;
extern FieldActorEntry D_800A5428;
extern FieldActorEntry D_800A543C;
extern FieldActorEntry D_800A5450;
extern s16 D_800A4F78[];
extern s16 D_800A4FE8[];

s16 D_800A4F78[] = {
    0x600, 1, 2,
    0x102, 2, 0x3F9, 0x3B5, 7,
    0x100, 0x7D, 0x419, 0x3C5,
    0x101, 0x7D, 1, 3,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 7,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 2, 0x7D, 2,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x325\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x800A\n");
#endif
s16 D_800A4FE8[] = {
    0x600, 1, 2,
    0x100, 2, 0x3F9, 0x3B5,
    0x101, 2, 1, 7,
    0x100, 0x7D, 0x419, 0x3C5,
    0x101, 0x7D, 1, 3,
    0x300, 0x78,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 2, 0x7D, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x3C,
    0,
};
Battle D_800A506C = { 149, 3, 0x60080000 };
Battle D_800A5078 = { 149, 3, 0x60080000 };
Battle D_800A5084 = { 149, 3, 0x60080000 };
Battle D_800A5090 = { 70, 3, 0x60080000 };
Battle D_800A509C = { 70, 3, 0x60080000 };
Battle D_800A50A8 = { 70, 3, 0x60080000 };
Battle D_800A50B4 = { 67, 3, 0x60080000 };
Battle D_800A50C0 = { 67, 3, 0x60080000 };
BattleList D_800A50CC = {
    3,
    { &D_800A506C, &D_800A5078, &D_800A5084, &D_800A5090,
      &D_800A509C, &D_800A50A8, &D_800A50B4, &D_800A50C0 },
};
Battle D_800A50F0 = { 0, 0, 0x60040000 };
Battle D_800A50FC = { 0, 0, 0x60040000 };
Battle D_800A5108 = { 0, 0, 0x60040000 };
Battle D_800A5114 = { 0, 0, 0x60040000 };
Battle D_800A5120 = { 0, 0, 0x60040000 };
Battle D_800A512C = { 0, 0, 0x60040000 };
Battle D_800A5138 = { 0, 0, 0x60040000 };
Battle D_800A5144 = { 0, 0, 0x60040000 };
BattleList D_800A5150 = {
    0,
    { &D_800A50F0, &D_800A50FC, &D_800A5108, &D_800A5114,
      &D_800A5120, &D_800A512C, &D_800A5138, &D_800A5144 },
};
Battle D_800A5174 = { 0, 0, 0x60040000 };
Battle D_800A5180 = { 0, 0, 0x60040000 };
Battle D_800A518C = { 0, 0, 0x60040000 };
Battle D_800A5198 = { 0, 0, 0x60040000 };
Battle D_800A51A4 = { 0, 0, 0x60040000 };
Battle D_800A51B0 = { 0, 0, 0x60040000 };
Battle D_800A51BC = { 0, 0, 0x60040000 };
Battle D_800A51C8 = { 0, 0, 0x60040000 };
BattleList D_800A51D4 = {
    0,
    { &D_800A5174, &D_800A5180, &D_800A518C, &D_800A5198,
      &D_800A51A4, &D_800A51B0, &D_800A51BC, &D_800A51C8 },
};
Battle D_800A51F8 = { 267, 3, 0x60880000 };
Battle D_800A5204 = { 0, 0, 0x60040000 };
Battle D_800A5210 = { 0, 0, 0x60040000 };
Battle D_800A521C = { 329, 3, 0x60080000 };
Battle D_800A5228 = { 0, 0, 0x60040000 };
Battle D_800A5234 = { 0, 0, 0x60040000 };
Battle D_800A5240 = { 156, 3, 0x60080000 };
Battle D_800A524C = { 0, 0, 0x60040000 };
BattleList D_800A5258 = {
    0,
    { &D_800A51F8, &D_800A5204, &D_800A5210, &D_800A521C,
      &D_800A5228, &D_800A5234, &D_800A5240, &D_800A524C },
};
FieldBattles stageBattles[] = {
    { 34, 0, 0, { &D_800A50CC, &D_800A5150, &D_800A51D4, &D_800A5258 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x176, 0x120, 0xD8, 0x20, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x172, 0xB8, 0x72, 0x170, 0x1FF },
    { 0x140, 0x100, 0x162, 0x172, 0x88, 0x72, 0x150, 0x1FE },
};
u16 D_800A5338[] = { 0x209, 1, 0x822B, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5348[] = { 0x20A, 1, 0x708B, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5358[] = { 0x20B, 1, 0x8245, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5368[] = { 0x1C15, 0, 0xFFFF };
u16 D_800A5370[] = { 0x9028, 1, 0x1C15, 1, 0xFFFF };
u16 D_800A537C[] = { 0x1C15, 1, 0xFFFF };
FieldTalk D_800A5384[] = {
    { NULL, D_800A5338, 0x16D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A539C[] = {
    { NULL, D_800A5348, 0x16C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53B4[] = {
    { NULL, D_800A5358, 0x254 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53CC[] = {
    { D_800A5368, D_800A5370, 0x2C3 },
    { D_800A537C, NULL, 0x2C4 },
    { NULL, NULL, 0 },
};
u16 D_800A53F0[] = { 0x209, 0, 0xFFFF };
u16 D_800A53F8[] = { 0x20A, 0, 0xFFFF };
u16 D_800A5400[] = { 0x20B, 0, 0xFFFF };
u16 D_800A5408[] = { 0x603, 1, 0x8026, 0, 0xFFFF };
FieldActorEntry D_800A5414 = { D_800A53F0, D_800A5384, 0x21, 4, 256, 561, 1 };
FieldActorEntry D_800A5428 = { D_800A53F8, D_800A539C, 0x4D, 5, 784, 393, 1 };
FieldActorEntry D_800A543C = { D_800A5400, D_800A53B4, 0x4E, 6, 593, 793, 1 };
FieldActorEntry D_800A5450 = { D_800A5408, D_800A53CC, 0x7D, 7, 1049, 965, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5414,
    &D_800A5428,
    &D_800A543C,
    &D_800A5450,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 1234, 165, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 6, 0, 1279, 187, 0, 0 },
    { 1, 0, 0x40, 6, 3, 1, 3, 8, 4, 0, 125, 286, 0, 0 },
    { 1, 0, 0x40, 6, 3, 1, 3, 8, 4, 0, 1409, 823, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 1497, 247, 283, 0 },
    { 1, 0, 0x6C, 4, 1, 0, 0, 0, 0, 0, 920, 640, 699, 0 },
    { 1, 0, 0x57, 4, 2, 0, 0, 0, 0, 0, 1040, 220, 285, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 320, 512, 512, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 432, 320, 320, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 496, 336, 336, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 720, 584, 584, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 936, 900, 900, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1136, 168, 168, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1328, 896, 896, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1568, 479, 479, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x249, 0x294, 0x1F0, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24C, 0xA8, 0x3FC, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24B, 0x90, 0xD0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 7, 0, 0, 0, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 2, 3 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 4, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 0x1E, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 8, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1271, D_800A4F78, EVENT_TEXT(0x10), NULL, func_800A4DA0 },
    { 1272, D_800A4FE8, EVENT_TEXT(0x11), NULL, func_800A4DEC },
    { -1, NULL, 0, NULL, NULL },
};
