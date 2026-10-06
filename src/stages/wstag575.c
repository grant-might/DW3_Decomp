#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 16 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0x10 && FLAGS_00.checkCondition(0x40A2, 0)) {
            children[0] = FIELDSTG_startEvent(0x1A6);
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
    FLAGS_00.applyAction(0x40A2, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x471
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x481
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x15C00, 0xF800};
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

extern Battle D_800A5064;
extern Battle D_800A5070;
extern Battle D_800A507C;
extern Battle D_800A5088;
extern Battle D_800A5094;
extern Battle D_800A50A0;
extern Battle D_800A50AC;
extern Battle D_800A50B8;
extern Battle D_800A50E8;
extern Battle D_800A50F4;
extern Battle D_800A5100;
extern Battle D_800A510C;
extern Battle D_800A5118;
extern Battle D_800A5124;
extern Battle D_800A5130;
extern Battle D_800A513C;
extern Battle D_800A516C;
extern Battle D_800A5178;
extern Battle D_800A5184;
extern Battle D_800A5190;
extern Battle D_800A519C;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51F0;
extern Battle D_800A51FC;
extern Battle D_800A5208;
extern Battle D_800A5214;
extern Battle D_800A5220;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern BattleList D_800A50C4;
extern BattleList D_800A5148;
extern BattleList D_800A51CC;
extern BattleList D_800A5250;
extern u16 D_800A5318[];
extern FieldTalk D_800A5300[];
extern FieldActorEntry D_800A5320;
extern s16 D_800A4ED0[];

s16 D_800A4ED0[] = {
    0x601, 1, 0xD2, 0x1F1,
    0x100, 2, 0, 0,
    0x101, 2, 1, 0,
    0x100, 0x69, 0x72, 0x1C1,
    0x101, 0x69, 1, 7,
    0x300, 0x1E,
    0x102, 0x69, 0xAA, 0x1DD, 7,
    0x302, 0x69,
    0x100, 2, 0x91, 0x1D0,
    0x101, 2, 1, 7,
    0x101, 0x69, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0xD2, 0x1F1, 7,
    0x102, 0x69, 0xD2, 0x1C9, 1,
    0x302, 2,
    0x600, 1, 2,
    0x300, 0x1E,
    0x101, 2, 1, 3,
    0x102, 0x69, 0xAF, 0x1DB, 7,
    0x302, 0x69,
    0x101, 0x69, 1, 7,
    0x300, 0x1E,
    0x200, 0, 1, 0x69, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x69, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0x69, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 7, 0x69, 0,
    0x301,
    0x300, 0x1E,
    0x102, 0x69, 0x9F, 0x1D3, 7,
    0x302, 0x69,
    0x101, 0x69, 1, 7,
    0x300, 0x1E,
    0x200, 0, 8, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 9, 2, 3,
    0x301,
    0x300, 0x3C,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x181\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x6004\n");
#endif
Battle D_800A5064 = { 149, 3, 0x60080000 };
Battle D_800A5070 = { 149, 3, 0x60080000 };
Battle D_800A507C = { 149, 3, 0x60080000 };
Battle D_800A5088 = { 149, 3, 0x60080000 };
Battle D_800A5094 = { 70, 3, 0x60080000 };
Battle D_800A50A0 = { 70, 3, 0x60080000 };
Battle D_800A50AC = { 70, 3, 0x60080000 };
Battle D_800A50B8 = { 70, 3, 0x60080000 };
BattleList D_800A50C4 = {
    3,
    { &D_800A5064, &D_800A5070, &D_800A507C, &D_800A5088,
      &D_800A5094, &D_800A50A0, &D_800A50AC, &D_800A50B8 },
};
Battle D_800A50E8 = { 0, 0, 0x60040000 };
Battle D_800A50F4 = { 0, 0, 0x60040000 };
Battle D_800A5100 = { 0, 0, 0x60040000 };
Battle D_800A510C = { 0, 0, 0x60040000 };
Battle D_800A5118 = { 0, 0, 0x60040000 };
Battle D_800A5124 = { 0, 0, 0x60040000 };
Battle D_800A5130 = { 0, 0, 0x60040000 };
Battle D_800A513C = { 0, 0, 0x60040000 };
BattleList D_800A5148 = {
    0,
    { &D_800A50E8, &D_800A50F4, &D_800A5100, &D_800A510C,
      &D_800A5118, &D_800A5124, &D_800A5130, &D_800A513C },
};
Battle D_800A516C = { 0, 0, 0x60040000 };
Battle D_800A5178 = { 0, 0, 0x60040000 };
Battle D_800A5184 = { 0, 0, 0x60040000 };
Battle D_800A5190 = { 0, 0, 0x60040000 };
Battle D_800A519C = { 0, 0, 0x60040000 };
Battle D_800A51A8 = { 0, 0, 0x60040000 };
Battle D_800A51B4 = { 0, 0, 0x60040000 };
Battle D_800A51C0 = { 0, 0, 0x60040000 };
BattleList D_800A51CC = {
    0,
    { &D_800A516C, &D_800A5178, &D_800A5184, &D_800A5190,
      &D_800A519C, &D_800A51A8, &D_800A51B4, &D_800A51C0 },
};
Battle D_800A51F0 = { 0, 0, 0x60040000 };
Battle D_800A51FC = { 0, 0, 0x60040000 };
Battle D_800A5208 = { 0, 0, 0x60040000 };
Battle D_800A5214 = { 329, 3, 0x60080000 };
Battle D_800A5220 = { 0, 0, 0x60040000 };
Battle D_800A522C = { 0, 0, 0x60040000 };
Battle D_800A5238 = { 156, 3, 0x60080000 };
Battle D_800A5244 = { 0, 0, 0x60040000 };
BattleList D_800A5250 = {
    0,
    { &D_800A51F0, &D_800A51FC, &D_800A5208, &D_800A5214,
      &D_800A5220, &D_800A522C, &D_800A5238, &D_800A5244 },
};
FieldBattles stageBattles[] = {
    { 33, 0, 0, { &D_800A50C4, &D_800A5148, &D_800A51CC, &D_800A5250 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x172, 0x118, 0xC8, 0x18, 0x150, 0x1FF },
};
FieldTalk D_800A5300[] = {
    { NULL, NULL, 0x310 },
    { NULL, NULL, 0 },
};
u16 D_800A5318[] = { 0x6010, 1, 0xFFFF };
FieldActorEntry D_800A5320 = { D_800A5318, D_800A5300, 0x69, 4, 0, 0, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A5320,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 166, 265, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 186, 261, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 186, 277, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 195, 287, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 207, 278, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 208, 273, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 217, 281, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 223, 291, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 237, 301, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 244, 290, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 9, 4, 0, 264, 305, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 532, 182, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 551, 182, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 9, 4, 0, 553, 172, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 496, 200, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 520, 201, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 9, 4, 0, 526, 192, 0, 0 },
    { 1, 0, 0x40, 2, 6, 1, 6, 0xD, 4, 0, 490, 26, 0, 0 },
    { 1, 0, 0x40, 2, 6, 1, 6, 0xD, 4, 0, 528, 45, 0, 0 },
    { 1, 0, 0x40, 2, 6, 1, 6, 0xD, 4, 0, 567, 64, 0, 0 },
    { 1, 0, 0x64, 2, 0xE, 0, 0, 0, 0, 0, 698, 491, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 418, 122, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 421, 128, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 434, 112, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 9, 4, 0, 450, 120, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 384, 141, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 391, 147, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 392, 125, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 9, 4, 0, 414, 137, 0, 0 },
    { 1, 0, 0x73, 4, 0, 0, 0, 0, 0, 0, 349, 733, 824, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 444, 766, 777, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 310, 576, 599, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 487, 596, 610, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 592, 118, 160, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 103, 411, 477, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 336, 535, 535, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 384, 559, 559, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 576, 895, 895, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 636, 800, 800, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 673, 767, 767, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24A, 0x5D8, 0x104, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24D, 0x88, 0x3F4, 5, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x10, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 8, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 422, D_800A4ED0, EVENT_TEXT(5), NULL, func_800A4D94 },
    { -1, NULL, 0, NULL, NULL },
};
