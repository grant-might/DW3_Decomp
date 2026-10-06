#include "common.h"
#include "stage.h"

/* Creates the event object of flags 0x4033 and 0x1C20 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (FLAGS_00.checkCondition(0x4033, 0) && FLAGS_00.checkCondition(0x1C20, 1)) {
            children[0] = FIELDSTG_startEvent(0x1CC);
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

void func_800A4DA8(void) {
    FLAGS_00.applyAction(0x4033, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x4F5
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x505
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x13200, 0x15B00};
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

extern Battle D_800A4F58;
extern Battle D_800A4F64;
extern Battle D_800A4F70;
extern Battle D_800A4F7C;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FDC;
extern Battle D_800A4FE8;
extern Battle D_800A4FF4;
extern Battle D_800A5000;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A5078;
extern Battle D_800A5084;
extern Battle D_800A5090;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50B4;
extern Battle D_800A50E4;
extern Battle D_800A50F0;
extern Battle D_800A50FC;
extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern Battle D_800A5138;
extern BattleList D_800A4FB8;
extern BattleList D_800A503C;
extern BattleList D_800A50C0;
extern BattleList D_800A5144;
extern u16 D_800A51F4[];
extern u16 D_800A521C[];
extern FieldTalk D_800A5204[];
extern FieldActorEntry D_800A5228;
extern s16 D_800A4EE8[];

s16 D_800A4EE8[] = {
    0x600, 1, 2,
    0x100, 2, 0xEF, 0x180,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x115, 0x16E, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x3C,
    0x101, 2, 1, 3,
    0x300, 0x3C,
    0x101, 2, 1, 5,
    0x300, 0x3C,
    0x200, 0, 1, 2, 2,
    0x301,
    0x600, 0, 2,
    0x300, 0x3C,
    0,
};
Battle D_800A4F58 = { 75, 12, 0x60080000 };
Battle D_800A4F64 = { 75, 12, 0x60080000 };
Battle D_800A4F70 = { 75, 12, 0x60080000 };
Battle D_800A4F7C = { 75, 12, 0x60080000 };
Battle D_800A4F88 = { 75, 12, 0x60080000 };
Battle D_800A4F94 = { 75, 12, 0x60080000 };
Battle D_800A4FA0 = { 75, 12, 0x60080000 };
Battle D_800A4FAC = { 75, 12, 0x60080000 };
BattleList D_800A4FB8 = {
    4,
    { &D_800A4F58, &D_800A4F64, &D_800A4F70, &D_800A4F7C,
      &D_800A4F88, &D_800A4F94, &D_800A4FA0, &D_800A4FAC },
};
Battle D_800A4FDC = { 0, 0, 0x60040000 };
Battle D_800A4FE8 = { 0, 0, 0x60040000 };
Battle D_800A4FF4 = { 0, 0, 0x60040000 };
Battle D_800A5000 = { 0, 0, 0x60040000 };
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
BattleList D_800A503C = {
    0,
    { &D_800A4FDC, &D_800A4FE8, &D_800A4FF4, &D_800A5000,
      &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030 },
};
Battle D_800A5060 = { 0, 0, 0x60040000 };
Battle D_800A506C = { 0, 0, 0x60040000 };
Battle D_800A5078 = { 0, 0, 0x60040000 };
Battle D_800A5084 = { 0, 0, 0x60040000 };
Battle D_800A5090 = { 0, 0, 0x60040000 };
Battle D_800A509C = { 0, 0, 0x60040000 };
Battle D_800A50A8 = { 0, 0, 0x60040000 };
Battle D_800A50B4 = { 0, 0, 0x60040000 };
BattleList D_800A50C0 = {
    0,
    { &D_800A5060, &D_800A506C, &D_800A5078, &D_800A5084,
      &D_800A5090, &D_800A509C, &D_800A50A8, &D_800A50B4 },
};
Battle D_800A50E4 = { 0, 0, 0x60040000 };
Battle D_800A50F0 = { 0, 0, 0x60040000 };
Battle D_800A50FC = { 0, 0, 0x60040000 };
Battle D_800A5108 = { 0, 0, 0x60040000 };
Battle D_800A5114 = { 0, 0, 0x60040000 };
Battle D_800A5120 = { 0, 0, 0x60040000 };
Battle D_800A512C = { 0, 0, 0x60040000 };
Battle D_800A5138 = { 0, 0, 0x60040000 };
BattleList D_800A5144 = {
    0,
    { &D_800A50E4, &D_800A50F0, &D_800A50FC, &D_800A5108,
      &D_800A5114, &D_800A5120, &D_800A512C, &D_800A5138 },
};
FieldBattles stageBattles[] = {
    { 42, 0, 0, { &D_800A4FB8, &D_800A503C, &D_800A50C0, &D_800A5144 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x100, 0xD8, 0, 0x150, 0x1FF },
};
u16 D_800A51F4[] = { 0x20D, 1, 0x822F, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A5204[] = {
    { NULL, D_800A51F4, 0x256 },
    { NULL, NULL, 0 },
};
u16 D_800A521C[] = { 0x20D, 0, 0x1C20, 1, 0xFFFF };
FieldActorEntry D_800A5228 = { D_800A521C, D_800A5204, 0x21, 4, 379, 318, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5228,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 6, 0, 277, 252, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 405, 317, 0, 0 },
    { 1, 0, 0x40, 6, 0, 1, 0, 0xB, 4, 0, 214, 250, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24D, 0x358, 0x37C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 460, D_800A4EE8, EVENT_TEXT(7), NULL, func_800A4DA8 },
    { -1, NULL, 0, NULL, NULL },
};
