#include "common.h"
#include "stage.h"
void func_800A4CA4();

void func_800A4CA4(StageTask *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
            switch (tile->anim) {
            case 1:
                tile->visible = 1;
                break;
            case 2:
                tile->visible = 1;
                break;
            case 3:
                tile->visible = 0;
                break;
            case 4:
                tile->visible = 0;
                break;
            }
        }
        break;
    case TASK_DONE:
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
            switch (tile->anim) {
            case 1:
                tile->visible = 0;
                break;
            case 2:
                tile->visible = 0;
                break;
            case 3:
                tile->visible = 1;
                break;
            case 4:
                tile->visible = 1;
                break;
            }
        }
        break;
    case TASK_KILL:
        break;
    }
}

void *func_800A4E24(s32 arg) {
    return createTaskWithId(func_800A4CA4, 0x50, 0, arg);
}

void func_800A4E54(StageTask *task, s32 id) {
    if (task != NULL && id == 0x35A) {
        task->setState(task, TASK_DONE);
    }
}

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x4076, 1) && FLAGS_00.checkCondition(0x4077, 0)) {
            children[1] = FIELDSTG_startEvent(0x502);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x8
#include "common/start_stage.inc.c"

void func_800A4F88(void) {
    FLAGS_00.applyAction(0x4076, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4FD4(void) {
    FLAGS_00.applyAction(0x4077, 1);
    FLAGS_00.applyAction(0x802A, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x52A
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x53A
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xF300, 0x17A00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2B;
    D_800990B4.music = 0x60AC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5274;
extern Battle D_800A5280;
extern Battle D_800A528C;
extern Battle D_800A5298;
extern Battle D_800A52A4;
extern Battle D_800A52B0;
extern Battle D_800A52E0;
extern Battle D_800A52EC;
extern Battle D_800A52F8;
extern Battle D_800A5304;
extern Battle D_800A5310;
extern Battle D_800A531C;
extern Battle D_800A5328;
extern Battle D_800A5334;
extern Battle D_800A5364;
extern Battle D_800A5370;
extern Battle D_800A537C;
extern Battle D_800A5388;
extern Battle D_800A5394;
extern Battle D_800A53A0;
extern Battle D_800A53AC;
extern Battle D_800A53B8;
extern Battle D_800A53E8;
extern Battle D_800A53F4;
extern Battle D_800A5400;
extern Battle D_800A540C;
extern Battle D_800A5418;
extern Battle D_800A5424;
extern Battle D_800A5430;
extern Battle D_800A543C;
extern BattleList D_800A52BC;
extern BattleList D_800A5340;
extern BattleList D_800A53C4;
extern BattleList D_800A5448;
extern u16 D_800A54F8[];
extern u16 D_800A5504[];
extern u16 D_800A5510[];
extern u16 D_800A551C[];
extern u16 D_800A5528[];
extern u16 D_800A5534[];
extern u16 D_800A5540[];
extern u16 D_800A5548[];
extern u16 D_800A5554[];
extern u16 D_800A555C[];
extern u16 D_800A5564[];
extern u16 D_800A5570[];
extern u16 D_800A55FC[];
extern FieldTalk D_800A5578[];
extern u16 D_800A5604[];
extern FieldTalk D_800A55B4[];
extern u16 D_800A560C[];
extern FieldTalk D_800A55D8[];
extern FieldActorEntry D_800A5614;
extern FieldActorEntry D_800A5628;
extern FieldActorEntry D_800A563C;
extern s16 D_800A5118[];
extern s16 D_800A51B8[];

s16 D_800A5118[] = {
    0x600, 1, 2,
    0x102, 2, 0x18D, 0x10E, 5,
    0x100, 0x105, 0x1A9, 0x100,
    0x101, 0x105, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0x105, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x105, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x6004\n");
#endif
s16 D_800A51B8[] = {
    0x600, 1, 2,
    0x100, 2, 0x18D, 0x10E,
    0x101, 2, 1, 5,
    0x100, 0x105, 0x1A9, 0x100,
    0x101, 0x105, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x105, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x105, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x105, 0,
    0x301,
    0x300, 0x3C,
    0,
};
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
Battle D_800A5274 = { 0, 0, 0x60040000 };
Battle D_800A5280 = { 0, 0, 0x60040000 };
Battle D_800A528C = { 0, 0, 0x60040000 };
Battle D_800A5298 = { 0, 0, 0x60040000 };
Battle D_800A52A4 = { 0, 0, 0x60040000 };
Battle D_800A52B0 = { 0, 0, 0x60040000 };
BattleList D_800A52BC = {
    0,
    { &D_800A525C, &D_800A5268, &D_800A5274, &D_800A5280,
      &D_800A528C, &D_800A5298, &D_800A52A4, &D_800A52B0 },
};
Battle D_800A52E0 = { 0, 0, 0x60040000 };
Battle D_800A52EC = { 0, 0, 0x60040000 };
Battle D_800A52F8 = { 0, 0, 0x60040000 };
Battle D_800A5304 = { 0, 0, 0x60040000 };
Battle D_800A5310 = { 0, 0, 0x60040000 };
Battle D_800A531C = { 0, 0, 0x60040000 };
Battle D_800A5328 = { 0, 0, 0x60040000 };
Battle D_800A5334 = { 0, 0, 0x60040000 };
BattleList D_800A5340 = {
    0,
    { &D_800A52E0, &D_800A52EC, &D_800A52F8, &D_800A5304,
      &D_800A5310, &D_800A531C, &D_800A5328, &D_800A5334 },
};
Battle D_800A5364 = { 0, 0, 0x60040000 };
Battle D_800A5370 = { 0, 0, 0x60040000 };
Battle D_800A537C = { 0, 0, 0x60040000 };
Battle D_800A5388 = { 0, 0, 0x60040000 };
Battle D_800A5394 = { 0, 0, 0x60040000 };
Battle D_800A53A0 = { 0, 0, 0x60040000 };
Battle D_800A53AC = { 0, 0, 0x60040000 };
Battle D_800A53B8 = { 0, 0, 0x60040000 };
BattleList D_800A53C4 = {
    0,
    { &D_800A5364, &D_800A5370, &D_800A537C, &D_800A5388,
      &D_800A5394, &D_800A53A0, &D_800A53AC, &D_800A53B8 },
};
Battle D_800A53E8 = { 31, 19, 0x60880000 };
Battle D_800A53F4 = { 321, 19, 0x60880000 };
Battle D_800A5400 = { 0, 0, 0x60040000 };
Battle D_800A540C = { 0, 0, 0x60040000 };
Battle D_800A5418 = { 0, 0, 0x60040000 };
Battle D_800A5424 = { 0, 0, 0x60040000 };
Battle D_800A5430 = { 0, 0, 0x60040000 };
Battle D_800A543C = { 0, 0, 0x60040000 };
BattleList D_800A5448 = {
    0,
    { &D_800A53E8, &D_800A53F4, &D_800A5400, &D_800A540C,
      &D_800A5418, &D_800A5424, &D_800A5430, &D_800A543C },
};
FieldBattles stageBattles[] = {
    { 129, 0, 0, { &D_800A52BC, &D_800A5340, &D_800A53C4, &D_800A5448 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x140, 0x1FB },
};
u16 D_800A54F8[] = { 0x6025, 1, 0xA0D, 0, 0xFFFF };
u16 D_800A5504[] = { 0xA0D, 1, 0x9038, 1, 0xFFFF };
u16 D_800A5510[] = { 0xA0D, 1, 0x6025, 1, 0xFFFF };
u16 D_800A551C[] = { 0x6026, 1, 0xA0D, 0, 0xFFFF };
u16 D_800A5528[] = { 0xA0D, 1, 0x9038, 1, 0xFFFF };
u16 D_800A5534[] = { 0xA0D, 1, 0x6026, 1, 0xFFFF };
u16 D_800A5540[] = { 0xA0D, 0, 0xFFFF };
u16 D_800A5548[] = { 0xA0D, 1, 0x9038, 1, 0xFFFF };
u16 D_800A5554[] = { 0xA0D, 1, 0xFFFF };
u16 D_800A555C[] = { 0xA0D, 0, 0xFFFF };
u16 D_800A5564[] = { 0xA0D, 1, 0x9038, 1, 0xFFFF };
u16 D_800A5570[] = { 0xA0D, 1, 0xFFFF };
FieldTalk D_800A5578[] = {
    { D_800A54F8, D_800A5504, 0x1AB },
    { D_800A5510, NULL, 0xB1 },
    { D_800A551C, D_800A5528, 0x1AB },
    { D_800A5534, NULL, 0xB2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55B4[] = {
    { D_800A5540, D_800A5548, 0x1AB },
    { D_800A5554, NULL, 0xB3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55D8[] = {
    { D_800A555C, D_800A5564, 0x1AB },
    { D_800A5570, NULL, 0xB4 },
    { NULL, NULL, 0 },
};
u16 D_800A55FC[] = { 0x701C, 1, 0xFFFF };
u16 D_800A5604[] = { 0x701A, 1, 0xFFFF };
u16 D_800A560C[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A5614 = { D_800A55FC, D_800A5578, 0x105, 4, 425, 256, 1 };
FieldActorEntry D_800A5628 = { D_800A5604, D_800A55B4, 0x105, 4, 425, 256, 1 };
FieldActorEntry D_800A563C = { D_800A560C, D_800A55D8, 0x105, 4, 425, 256, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5614,
    &D_800A5628,
    &D_800A563C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 374, 301, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 390, 293, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 406, 285, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 422, 277, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 458, 262, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 2, 0, 2, 0x10, 0, 438, 220, 0, 0 },
    { 1, 3, 0x40, 6, 0x33, 2, 0, 1, 0x10, 0, 438, 220, 0, 0 },
    { 1, 4, 0x40, 6, 0x35, 2, 0, 3, 4, 0, 444, 202, 0, 0 },
    { 1, 2, 0x40, 6, 0x34, 2, 0, 3, 4, 0, 444, 202, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 294, 261, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 310, 253, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 326, 245, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 342, 237, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 374, 220, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 0, 0, 0, 0, 0, 448, 207, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28A, 0x3F8, 0x2DC, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1281, D_800A5118, EVENT_TEXT(0x20), NULL, func_800A4F88 },
    { 1282, D_800A51B8, EVENT_TEXT(0x21), NULL, func_800A4FD4 },
    { -1, NULL, 0, NULL, NULL },
};
