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

/* Ends the task when map object 0x35A is triggered */
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
        if (FLAGS_00.checkCondition(0x4008, 1) && FLAGS_00.checkCondition(0x4009, 0)) {
            children[1] = FIELDSTG_startEvent(0x178);
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
    FLAGS_00.applyAction(0x4008, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4FD4(void) {
    FLAGS_00.applyAction(0x4009, 1);
    FLAGS_00.applyAction(0x8674, 1);
}

void func_800A5020(void) {
    GAME.progress = 22;
}

#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x755
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x765
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xF500, 0x17A00};
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

extern Battle D_800A52FC;
extern Battle D_800A5308;
extern Battle D_800A5314;
extern Battle D_800A5320;
extern Battle D_800A532C;
extern Battle D_800A5338;
extern Battle D_800A5344;
extern Battle D_800A5350;
extern Battle D_800A5380;
extern Battle D_800A538C;
extern Battle D_800A5398;
extern Battle D_800A53A4;
extern Battle D_800A53B0;
extern Battle D_800A53BC;
extern Battle D_800A53C8;
extern Battle D_800A53D4;
extern Battle D_800A5404;
extern Battle D_800A5410;
extern Battle D_800A541C;
extern Battle D_800A5428;
extern Battle D_800A5434;
extern Battle D_800A5440;
extern Battle D_800A544C;
extern Battle D_800A5458;
extern Battle D_800A5488;
extern Battle D_800A5494;
extern Battle D_800A54A0;
extern Battle D_800A54AC;
extern Battle D_800A54B8;
extern Battle D_800A54C4;
extern Battle D_800A54D0;
extern Battle D_800A54DC;
extern BattleList D_800A535C;
extern BattleList D_800A53E0;
extern BattleList D_800A5464;
extern BattleList D_800A54E8;
extern u16 D_800A5598[];
extern u16 D_800A55A4[];
extern u16 D_800A55AC[];
extern u16 D_800A55B4[];
extern u16 D_800A55BC[];
extern u16 D_800A55C4[];
extern u16 D_800A55CC[];
extern u16 D_800A56E4[];
extern FieldTalk D_800A55DC[];
extern u16 D_800A56F0[];
extern FieldTalk D_800A55F4[];
extern u16 D_800A56F8[];
extern FieldTalk D_800A560C[];
extern u16 D_800A5704[];
extern FieldTalk D_800A5624[];
extern u16 D_800A5710[];
extern FieldTalk D_800A5648[];
extern u16 D_800A571C[];
extern FieldTalk D_800A566C[];
extern u16 D_800A5728[];
extern FieldTalk D_800A5684[];
extern u16 D_800A5734[];
extern FieldTalk D_800A569C[];
extern u16 D_800A5740[];
extern FieldTalk D_800A56B4[];
extern u16 D_800A574C[];
extern FieldTalk D_800A56CC[];
extern FieldActorEntry D_800A5758;
extern FieldActorEntry D_800A576C;
extern FieldActorEntry D_800A5780;
extern FieldActorEntry D_800A5794;
extern FieldActorEntry D_800A57A8;
extern FieldActorEntry D_800A57BC;
extern FieldActorEntry D_800A57D0;
extern FieldActorEntry D_800A57E4;
extern FieldActorEntry D_800A57F8;
extern FieldActorEntry D_800A580C;
extern s16 D_800A5128[];
extern s16 D_800A51D0[];
extern s16 D_800A5260[];

s16 D_800A5128[] = {
    0x102, 2, 0x191, 0x114, 5,
    0x100, 0xA5, 0x1B1, 0x104,
    0x101, 0xA5, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0xA5, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0xA5,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 4, 0xA5, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0,
};
s16 D_800A51D0[] = {
    0x100, 2, 0x191, 0x114,
    0x101, 2, 1, 5,
    0x100, 0xA5, 0x1B1, 0x104,
    0x101, 0xA5, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0xA5, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0xA5, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0,
};
s16 D_800A5260[] = {
    0x102, 2, 0x191, 0x114, 5,
    0x100, 0xA5, 0x1B1, 0x104,
    0x101, 0xA5, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0xA5,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0xA5,
    0x300, 0x1E,
    0x200, 0, 1, 0xA5, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x18,
    0x101, 2, 1, 1,
    0x300, 0x18,
    0x102, 2, 0x154, 0x132, 1,
    0x300, 0xC,
    0x304, 0x21B, 0x3F8, 0x2DC, 1,
    0,
};
Battle D_800A52FC = { 0, 0, 0x60040000 };
Battle D_800A5308 = { 0, 0, 0x60040000 };
Battle D_800A5314 = { 0, 0, 0x60040000 };
Battle D_800A5320 = { 0, 0, 0x60040000 };
Battle D_800A532C = { 0, 0, 0x60040000 };
Battle D_800A5338 = { 0, 0, 0x60040000 };
Battle D_800A5344 = { 0, 0, 0x60040000 };
Battle D_800A5350 = { 0, 0, 0x60040000 };
BattleList D_800A535C = {
    0,
    { &D_800A52FC, &D_800A5308, &D_800A5314, &D_800A5320,
      &D_800A532C, &D_800A5338, &D_800A5344, &D_800A5350 },
};
Battle D_800A5380 = { 0, 0, 0x60040000 };
Battle D_800A538C = { 0, 0, 0x60040000 };
Battle D_800A5398 = { 0, 0, 0x60040000 };
Battle D_800A53A4 = { 0, 0, 0x60040000 };
Battle D_800A53B0 = { 0, 0, 0x60040000 };
Battle D_800A53BC = { 0, 0, 0x60040000 };
Battle D_800A53C8 = { 0, 0, 0x60040000 };
Battle D_800A53D4 = { 0, 0, 0x60040000 };
BattleList D_800A53E0 = {
    0,
    { &D_800A5380, &D_800A538C, &D_800A5398, &D_800A53A4,
      &D_800A53B0, &D_800A53BC, &D_800A53C8, &D_800A53D4 },
};
Battle D_800A5404 = { 0, 0, 0x60040000 };
Battle D_800A5410 = { 0, 0, 0x60040000 };
Battle D_800A541C = { 0, 0, 0x60040000 };
Battle D_800A5428 = { 0, 0, 0x60040000 };
Battle D_800A5434 = { 0, 0, 0x60040000 };
Battle D_800A5440 = { 0, 0, 0x60040000 };
Battle D_800A544C = { 0, 0, 0x60040000 };
Battle D_800A5458 = { 0, 0, 0x60040000 };
BattleList D_800A5464 = {
    0,
    { &D_800A5404, &D_800A5410, &D_800A541C, &D_800A5428,
      &D_800A5434, &D_800A5440, &D_800A544C, &D_800A5458 },
};
Battle D_800A5488 = { 9, 19, 0x60880000 };
Battle D_800A5494 = { 313, 19, 0x60880000 };
Battle D_800A54A0 = { 0, 0, 0x60040000 };
Battle D_800A54AC = { 0, 0, 0x60040000 };
Battle D_800A54B8 = { 0, 0, 0x60040000 };
Battle D_800A54C4 = { 0, 0, 0x60040000 };
Battle D_800A54D0 = { 0, 0, 0x60040000 };
Battle D_800A54DC = { 0, 0, 0x60040000 };
BattleList D_800A54E8 = {
    0,
    { &D_800A5488, &D_800A5494, &D_800A54A0, &D_800A54AC,
      &D_800A54B8, &D_800A54C4, &D_800A54D0, &D_800A54DC },
};
FieldBattles stageBattles[] = {
    { 127, 0, 0, { &D_800A535C, &D_800A53E0, &D_800A5464, &D_800A54E8 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x140, 0x1EE },
};
u16 D_800A5598[] = { 0x9041, 1, 0xA03, 1, 0xFFFF };
u16 D_800A55A4[] = { 0x1C1B, 0, 0xFFFF };
u16 D_800A55AC[] = { 0x1C1B, 1, 0xFFFF };
u16 D_800A55B4[] = { 0x1C1B, 1, 0xFFFF };
u16 D_800A55BC[] = { 0x8191, 0, 0xFFFF };
u16 D_800A55C4[] = { 0x8191, 1, 0xFFFF };
u16 D_800A55CC[] = { 0x9024, 1, 0x1C1D, 1, 0x4005, 1, 0xFFFF };
FieldTalk D_800A55DC[] = {
    { NULL, NULL, 0x497 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55F4[] = {
    { NULL, D_800A5598, 0xB3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A560C[] = {
    { NULL, NULL, 0x416 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5624[] = {
    { D_800A55A4, D_800A55AC, 0x498 },
    { D_800A55B4, NULL, 0x499 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5648[] = {
    { D_800A55BC, NULL, 0x410 },
    { D_800A55C4, D_800A55CC, 0xB4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A566C[] = {
    { NULL, NULL, 0x411 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5684[] = {
    { NULL, NULL, 0x412 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A569C[] = {
    { NULL, NULL, 0x413 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56B4[] = {
    { NULL, NULL, 0x414 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56CC[] = {
    { NULL, NULL, 0x415 },
    { NULL, NULL, 0 },
};
u16 D_800A56E4[] = { 0x7016, 1, 0xA03, 1, 0xFFFF };
u16 D_800A56F0[] = { 0xA03, 0, 0xFFFF };
u16 D_800A56F8[] = { 0x602B, 1, 0xA03, 1, 0xFFFF };
u16 D_800A5704[] = { 0xA03, 1, 0x6014, 1, 0xFFFF };
u16 D_800A5710[] = { 0x6015, 1, 0xA03, 1, 0xFFFF };
u16 D_800A571C[] = { 0xA03, 1, 0x6016, 1, 0xFFFF };
u16 D_800A5728[] = { 0x7018, 1, 0xA03, 1, 0xFFFF };
u16 D_800A5734[] = { 0xA03, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5740[] = { 0x6026, 1, 0xA03, 1, 0xFFFF };
u16 D_800A574C[] = { 0xA03, 1, 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5758 = { D_800A56E4, D_800A55DC, 0xA5, 4, 433, 260, 5 };
FieldActorEntry D_800A576C = { D_800A56F0, D_800A55F4, 0xA5, 4, 433, 260, 5 };
FieldActorEntry D_800A5780 = { D_800A56F8, D_800A560C, 0xA5, 4, 433, 260, 5 };
FieldActorEntry D_800A5794 = { D_800A5704, D_800A5624, 0xA5, 4, 433, 260, 5 };
FieldActorEntry D_800A57A8 = { D_800A5710, D_800A5648, 0xA5, 4, 433, 260, 5 };
FieldActorEntry D_800A57BC = { D_800A571C, D_800A566C, 0xA5, 4, 433, 260, 5 };
FieldActorEntry D_800A57D0 = { D_800A5728, D_800A5684, 0xA5, 4, 433, 260, 5 };
FieldActorEntry D_800A57E4 = { D_800A5734, D_800A569C, 0xA5, 4, 433, 260, 5 };
FieldActorEntry D_800A57F8 = { D_800A5740, D_800A56B4, 0xA5, 4, 433, 260, 5 };
FieldActorEntry D_800A580C = { D_800A574C, D_800A56CC, 0xA5, 4, 433, 260, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A5758,
    &D_800A576C,
    &D_800A5780,
    &D_800A5794,
    &D_800A57A8,
    &D_800A57BC,
    &D_800A57D0,
    &D_800A57E4,
    &D_800A57F8,
    &D_800A580C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 374, 301, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 390, 293, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 406, 285, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 422, 277, 0, 0 },
    { 1, 0, 0x40, 2, 0x36, 2, 0, 3, 4, 0, 458, 262, 0, 0 },
    { 1, 0, 0x49, 6, 0, 1, 0, 3, 4, 0, 84, 193, 0, 0 },
    { 1, 0, 0x5D, 6, 4, 1, 4, 7, 4, 0, 68, 252, 0, 0 },
    { 1, 0, 0x5D, 6, 5, 1, 5, 8, 4, 0, 131, 227, 0, 0 },
    { 1, 0, 0x5D, 6, 0xB, 1, 0xB, 0xE, 4, 0, 182, 153, 0, 0 },
    { 1, 0, 0x49, 6, 0, 1, 0, 3, 4, 0, 227, 178, 0, 0 },
    { 1, 0, 0x5D, 6, 7, 1, 7, 0xA, 4, 0, 272, 108, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 2, 0, 2, 0x10, 0, 438, 220, 0, 0 },
    { 1, 3, 0x40, 6, 0x33, 2, 0, 1, 0x10, 0, 438, 220, 0, 0 },
    { 1, 2, 0x40, 6, 0x34, 2, 0, 3, 4, 0, 444, 202, 0, 0 },
    { 1, 4, 0x40, 6, 0x35, 2, 0, 3, 4, 0, 444, 202, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 294, 261, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 310, 253, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 326, 245, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 342, 237, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 3, 4, 0, 374, 220, 0, 0 },
    { 1, 0, 0x40, 6, 0xF, 0, 0, 0, 0, 0, 448, 207, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x21B, 0x3F8, 0x2DC, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 375, D_800A5128, EVENT_TEXT(4), NULL, func_800A4F88 },
    { 376, D_800A51D0, EVENT_TEXT(5), NULL, func_800A4FD4 },
    { 560, D_800A5260, EVENT_TEXT(6), NULL, func_800A5020 },
    { -1, NULL, 0, NULL, NULL },
};
