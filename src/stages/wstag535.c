#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x4055, 1) && FLAGS_00.checkCondition(0x4056, 0)) {
            children[0] = FIELDSTG_startEvent(0x4EF);
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
    FLAGS_00.applyAction(0x4055, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4DEC(void) {
    FLAGS_00.applyAction(0x4056, 1);
    FLAGS_00.applyAction(0x8666, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x285
#define STAGE_ARCHIVE 0x3CE
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x294
#define STAGE_ARCHIVE 0x3DE
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16 | 1;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x19E00, 0x11300};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x11;
    D_800990B4.music = 0x60440000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A50A4;
extern Battle D_800A50B0;
extern Battle D_800A50BC;
extern Battle D_800A50C8;
extern Battle D_800A50D4;
extern Battle D_800A50E0;
extern Battle D_800A50EC;
extern Battle D_800A50F8;
extern Battle D_800A5128;
extern Battle D_800A5134;
extern Battle D_800A5140;
extern Battle D_800A514C;
extern Battle D_800A5158;
extern Battle D_800A5164;
extern Battle D_800A5170;
extern Battle D_800A517C;
extern Battle D_800A51AC;
extern Battle D_800A51B8;
extern Battle D_800A51C4;
extern Battle D_800A51D0;
extern Battle D_800A51DC;
extern Battle D_800A51E8;
extern Battle D_800A51F4;
extern Battle D_800A5200;
extern Battle D_800A5230;
extern Battle D_800A523C;
extern Battle D_800A5248;
extern Battle D_800A5254;
extern Battle D_800A5260;
extern Battle D_800A526C;
extern Battle D_800A5278;
extern Battle D_800A5284;
extern BattleList D_800A5104;
extern BattleList D_800A5188;
extern BattleList D_800A520C;
extern BattleList D_800A5290;
extern u16 D_800A5340[];
extern u16 D_800A5348[];
extern u16 D_800A5354[];
extern u16 D_800A535C[];
extern u16 D_800A5364[];
extern u16 D_800A5370[];
extern u16 D_800A5378[];
extern u16 D_800A5380[];
extern u16 D_800A538C[];
extern u16 D_800A5394[];
extern u16 D_800A539C[];
extern u16 D_800A53A8[];
extern u16 D_800A53B0[];
extern u16 D_800A53B8[];
extern u16 D_800A53C4[];
extern u16 D_800A53CC[];
extern u16 D_800A53D4[];
extern u16 D_800A53E0[];
extern u16 D_800A53E8[];
extern u16 D_800A53F0[];
extern u16 D_800A53FC[];
extern u16 D_800A5404[];
extern u16 D_800A540C[];
extern u16 D_800A5418[];
extern u16 D_800A5420[];
extern u16 D_800A5428[];
extern u16 D_800A5434[];
extern u16 D_800A543C[];
extern u16 D_800A5444[];
extern u16 D_800A5450[];
extern u16 D_800A55C0[];
extern FieldTalk D_800A5458[];
extern u16 D_800A55C8[];
extern FieldTalk D_800A547C[];
extern u16 D_800A55D0[];
extern FieldTalk D_800A54A0[];
extern u16 D_800A55D8[];
extern FieldTalk D_800A54C4[];
extern u16 D_800A55E0[];
extern FieldTalk D_800A54E8[];
extern u16 D_800A55E8[];
extern FieldTalk D_800A550C[];
extern u16 D_800A55F0[];
extern FieldTalk D_800A5530[];
extern u16 D_800A55F8[];
extern FieldTalk D_800A5554[];
extern u16 D_800A5600[];
extern FieldTalk D_800A5578[];
extern u16 D_800A5608[];
extern FieldTalk D_800A559C[];
extern FieldActorEntry D_800A5610;
extern FieldActorEntry D_800A5624;
extern FieldActorEntry D_800A5638;
extern FieldActorEntry D_800A564C;
extern FieldActorEntry D_800A5660;
extern FieldActorEntry D_800A5674;
extern FieldActorEntry D_800A5688;
extern FieldActorEntry D_800A569C;
extern FieldActorEntry D_800A56B0;
extern FieldActorEntry D_800A56C4;
extern s16 D_800A4F4C[];
extern s16 D_800A5000[];

s16 D_800A4F4C[] = {
    0x600, 1, 2,
    0x102, 2, 0x357, 0x93, 5,
    0x100, 0x85, 0x377, 0x85,
    0x101, 0x85, 1, 1,
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
    0x200, 0, 2, 0x85, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x85, 0,
    0x200, 0, 0, 0, 0,
    0x200, 0, 4, 0x85, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5000[] = {
    0x600, 1, 2,
    0x100, 2, 0x357, 0x93,
    0x101, 2, 1, 5,
    0x100, 0x85, 0x377, 0x85,
    0x101, 0x85, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x85, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x85, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x3C,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x85, 0,
    0x301,
    0x300, 0x3C,
    0,
};
Battle D_800A50A4 = { 91, 6, 0x60080000 };
Battle D_800A50B0 = { 91, 6, 0x60080000 };
Battle D_800A50BC = { 91, 6, 0x60080000 };
Battle D_800A50C8 = { 91, 6, 0x60080000 };
Battle D_800A50D4 = { 91, 6, 0x60080000 };
Battle D_800A50E0 = { 91, 6, 0x60080000 };
Battle D_800A50EC = { 91, 6, 0x60080000 };
Battle D_800A50F8 = { 91, 6, 0x60080000 };
BattleList D_800A5104 = {
    4,
    { &D_800A50A4, &D_800A50B0, &D_800A50BC, &D_800A50C8,
      &D_800A50D4, &D_800A50E0, &D_800A50EC, &D_800A50F8 },
};
Battle D_800A5128 = { 0, 6, 0x60080000 };
Battle D_800A5134 = { 0, 6, 0x60080000 };
Battle D_800A5140 = { 0, 6, 0x60080000 };
Battle D_800A514C = { 0, 6, 0x60080000 };
Battle D_800A5158 = { 0, 6, 0x60080000 };
Battle D_800A5164 = { 0, 6, 0x60080000 };
Battle D_800A5170 = { 0, 6, 0x60080000 };
Battle D_800A517C = { 0, 6, 0x60080000 };
BattleList D_800A5188 = {
    0,
    { &D_800A5128, &D_800A5134, &D_800A5140, &D_800A514C,
      &D_800A5158, &D_800A5164, &D_800A5170, &D_800A517C },
};
Battle D_800A51AC = { 0, 0, 0x60040000 };
Battle D_800A51B8 = { 0, 0, 0x60040000 };
Battle D_800A51C4 = { 0, 0, 0x60040000 };
Battle D_800A51D0 = { 0, 0, 0x60040000 };
Battle D_800A51DC = { 0, 0, 0x60040000 };
Battle D_800A51E8 = { 0, 0, 0x60040000 };
Battle D_800A51F4 = { 0, 0, 0x60040000 };
Battle D_800A5200 = { 0, 0, 0x60040000 };
BattleList D_800A520C = {
    0,
    { &D_800A51AC, &D_800A51B8, &D_800A51C4, &D_800A51D0,
      &D_800A51DC, &D_800A51E8, &D_800A51F4, &D_800A5200 },
};
Battle D_800A5230 = { 11, 19, 0x60880000 };
Battle D_800A523C = { 0, 0, 0x60040000 };
Battle D_800A5248 = { 0, 0, 0x60040000 };
Battle D_800A5254 = { 0, 0, 0x60040000 };
Battle D_800A5260 = { 0, 0, 0x60040000 };
Battle D_800A526C = { 91, 6, 0x60080000 };
Battle D_800A5278 = { 0, 0, 0x60040000 };
Battle D_800A5284 = { 0, 0, 0x60040000 };
BattleList D_800A5290 = {
    0,
    { &D_800A5230, &D_800A523C, &D_800A5248, &D_800A5254,
      &D_800A5260, &D_800A526C, &D_800A5278, &D_800A5284 },
};
FieldBattles stageBattles[] = {
    { 59, 0, 0, { &D_800A5104, &D_800A5188, &D_800A520C, &D_800A5290 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x180, 0x100, 0x100, 0, 0x170, 0x1F5 },
};
u16 D_800A5340[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5348[] = { 0xA02, 1, 0x9036, 1, 0xFFFF };
u16 D_800A5354[] = { 0xA02, 1, 0xFFFF };
u16 D_800A535C[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5364[] = { 0xA02, 1, 0x9036, 1, 0xFFFF };
u16 D_800A5370[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5378[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5380[] = { 0xA02, 1, 0x9036, 1, 0xFFFF };
u16 D_800A538C[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5394[] = { 0xA02, 0, 0xFFFF };
u16 D_800A539C[] = { 0xA02, 1, 0x9036, 1, 0xFFFF };
u16 D_800A53A8[] = { 0xA02, 1, 0xFFFF };
u16 D_800A53B0[] = { 0xA02, 0, 0xFFFF };
u16 D_800A53B8[] = { 0xA02, 1, 0x9036, 1, 0xFFFF };
u16 D_800A53C4[] = { 0xA02, 1, 0xFFFF };
u16 D_800A53CC[] = { 0xA02, 0, 0xFFFF };
u16 D_800A53D4[] = { 0x9036, 1, 0xA02, 1, 0xFFFF };
u16 D_800A53E0[] = { 0xA02, 1, 0xFFFF };
u16 D_800A53E8[] = { 0xA02, 0, 0xFFFF };
u16 D_800A53F0[] = { 0xA02, 1, 0x9036, 1, 0xFFFF };
u16 D_800A53FC[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5404[] = { 0xA02, 0, 0xFFFF };
u16 D_800A540C[] = { 0xA02, 1, 0x9036, 1, 0xFFFF };
u16 D_800A5418[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5420[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5428[] = { 0xA02, 1, 0x9036, 1, 0xFFFF };
u16 D_800A5434[] = { 0xA02, 1, 0xFFFF };
u16 D_800A543C[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5444[] = { 0xA02, 1, 0x9036, 1, 0xFFFF };
u16 D_800A5450[] = { 0xA02, 1, 0xFFFF };
FieldTalk D_800A5458[] = {
    { D_800A5340, D_800A5348, 0x2F8 },
    { D_800A5354, NULL, 0x1E3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A547C[] = {
    { D_800A535C, D_800A5364, 0x2F8 },
    { D_800A5370, NULL, 0x1E3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54A0[] = {
    { D_800A5378, D_800A5380, 0x2F8 },
    { D_800A538C, NULL, 0x1E4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54C4[] = {
    { D_800A5394, D_800A539C, 0x2F8 },
    { D_800A53A8, NULL, 0x1E3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E8[] = {
    { D_800A53B0, D_800A53B8, 0x2F8 },
    { D_800A53C4, NULL, 0x1EA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A550C[] = {
    { D_800A53CC, D_800A53D4, 0x2F8 },
    { D_800A53E0, NULL, 0x1E9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5530[] = {
    { D_800A53E8, D_800A53F0, 0x2F8 },
    { D_800A53FC, NULL, 0x1E8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5554[] = {
    { D_800A5404, D_800A540C, 0x2F8 },
    { D_800A5418, NULL, 0x1E7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5578[] = {
    { D_800A5420, D_800A5428, 0x2F8 },
    { D_800A5434, NULL, 0x1E6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A559C[] = {
    { D_800A543C, D_800A5444, 0x2F8 },
    { D_800A5450, NULL, 0x1E5 },
    { NULL, NULL, 0 },
};
u16 D_800A55C0[] = { 0x6008, 1, 0xFFFF };
u16 D_800A55C8[] = { 0x6009, 1, 0xFFFF };
u16 D_800A55D0[] = { 0x600A, 1, 0xFFFF };
u16 D_800A55D8[] = { 0x6007, 1, 0xFFFF };
u16 D_800A55E0[] = { 0x6019, 1, 0xFFFF };
u16 D_800A55E8[] = { 0x6018, 1, 0xFFFF };
u16 D_800A55F0[] = { 0x7017, 1, 0xFFFF };
u16 D_800A55F8[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5600[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5608[] = { 0x600C, 1, 0xFFFF };
FieldActorEntry D_800A5610 = { D_800A55C0, D_800A5458, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5624 = { D_800A55C8, D_800A547C, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5638 = { D_800A55D0, D_800A54A0, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A564C = { D_800A55D8, D_800A54C4, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5660 = { D_800A55E0, D_800A54E8, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5674 = { D_800A55E8, D_800A550C, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5688 = { D_800A55F0, D_800A5530, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A569C = { D_800A55F8, D_800A5554, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A56B0 = { D_800A5600, D_800A5578, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A56C4 = { D_800A5608, D_800A559C, 0x85, 4, 887, 133, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5610,
    &D_800A5624,
    &D_800A5638,
    &D_800A564C,
    &D_800A5660,
    &D_800A5674,
    &D_800A5688,
    &D_800A569C,
    &D_800A56B0,
    &D_800A56C4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x70, 2, 0x36, 1, 0x36, 0x3B, 6, 0, 949, 142, 0, 0 },
    { 1, 0, 0x70, 2, 0x3C, 1, 0x3C, 0x41, 6, 0, 941, 141, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 999, 304, 0, 0 },
    { 1, 0, 0x78, 6, 0x32, 2, 0, 0xD, 8, 0, 1000, 393, 0, 0 },
    { 1, 0, 0x78, 6, 0x33, 2, 0, 0xD, 8, 0, 993, 389, 0, 0 },
    { 1, 0, 0x70, 6, 0x34, 2, 0, 0xD, 8, 0, 642, 153, 0, 0 },
    { 1, 0, 0x70, 6, 0x35, 2, 0, 0xD, 8, 0, 634, 144, 0, 0 },
    { 1, 0, 0x70, 6, 0x42, 1, 0x42, 0x47, 6, 0, 955, 71, 0, 0 },
    { 1, 0, 0x70, 6, 0x48, 1, 0x48, 0x4D, 6, 0, 946, 71, 0, 0 },
    { 1, 0, 0x70, 6, 0x4E, 1, 0x4E, 0x53, 6, 0, 618, 227, 0, 0 },
    { 1, 0, 0x70, 6, 0x4E, 1, 0x4E, 0x53, 6, 0, 730, 171, 0, 0 },
    { 1, 0, 0x70, 6, 0x54, 2, 0, 3, 6, 0, 614, 232, 0, 0 },
    { 1, 0, 0x70, 6, 0x54, 2, 0, 3, 6, 0, 726, 176, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 258, 102, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 531, 190, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 758, 111, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 806, 87, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 827, 275, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 859, 292, 0, 0 },
    { 1, 0, 0x70, 6, 0x55, 2, 0, 3, 4, 0, 1002, 301, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 266, 105, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 539, 193, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 766, 114, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 814, 90, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 835, 279, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 867, 295, 0, 0 },
    { 1, 0, 0x70, 6, 0x56, 2, 0, 3, 4, 0, 1010, 304, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x242, 0x3E0, 0x1B0, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x3A0, 0x190, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x3B0, 0x1E8, 0, 0, 0, 0 },
    { { { 0xF, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1262, D_800A4F4C, EVENT_TEXT(0xC), NULL, func_800A4DA0 },
    { 1263, D_800A5000, EVENT_TEXT(0xD), NULL, func_800A4DEC },
    { 9000, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
