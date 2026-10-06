#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x4078, 1) && FLAGS_00.checkCondition(0x4079, 0)) {
            children[0] = FIELDSTG_startEvent(0x504);
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
    FLAGS_00.applyAction(0x4078, 1);
    FLAGS_00.applyAction(0x7401, 1);
}

void func_800A4DF0(void) {
    FLAGS_00.applyAction(0x4079, 1);
    FLAGS_00.applyAction(0x8AF2, 1);
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x579
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x589
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x11A00, 0x3AD00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xB;
    D_800990B4.music = 0x602C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(1, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 3);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 4);
    D_8009A70C.unk50(0);
}

extern Battle D_800A50C8;
extern Battle D_800A50D4;
extern Battle D_800A50E0;
extern Battle D_800A50EC;
extern Battle D_800A50F8;
extern Battle D_800A5104;
extern Battle D_800A5110;
extern Battle D_800A511C;
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
extern BattleList D_800A5128;
extern BattleList D_800A51AC;
extern BattleList D_800A5230;
extern BattleList D_800A52B4;
extern u16 D_800A5374[];
extern u16 D_800A537C[];
extern u16 D_800A5388[];
extern u16 D_800A5390[];
extern u16 D_800A53A0[];
extern u16 D_800A53B0[];
extern u16 D_800A53C4[];
extern u16 D_800A53CC[];
extern u16 D_800A53D8[];
extern u16 D_800A53E0[];
extern u16 D_800A53E8[];
extern u16 D_800A53F4[];
extern u16 D_800A53FC[];
extern u16 D_800A5404[];
extern u16 D_800A5410[];
extern u16 D_800A5418[];
extern u16 D_800A5420[];
extern u16 D_800A542C[];
extern u16 D_800A5434[];
extern u16 D_800A543C[];
extern u16 D_800A5448[];
extern u16 D_800A5540[];
extern FieldTalk D_800A5450[];
extern u16 D_800A5554[];
extern FieldTalk D_800A548C[];
extern u16 D_800A555C[];
extern FieldTalk D_800A54B0[];
extern u16 D_800A5564[];
extern FieldTalk D_800A54D4[];
extern u16 D_800A556C[];
extern FieldTalk D_800A54F8[];
extern u16 D_800A5574[];
extern FieldTalk D_800A551C[];
extern FieldActorEntry D_800A557C;
extern FieldActorEntry D_800A5590;
extern FieldActorEntry D_800A55A4;
extern FieldActorEntry D_800A55B8;
extern FieldActorEntry D_800A55CC;
extern FieldActorEntry D_800A55E0;
extern s16 D_800A4F84[];
extern s16 D_800A5024[];

s16 D_800A4F84[] = {
    0x600, 1, 2,
    0x102, 2, 0x411, 0xA1, 5,
    0x100, 0x106, 0x431, 0x91,
    0x101, 0x106, 1, 1,
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
    0x200, 0, 2, 0x106, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x106, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5024[] = {
    0x600, 1, 2,
    0x100, 2, 0x411, 0xA1,
    0x101, 2, 1, 5,
    0x100, 0x106, 0x431, 0x91,
    0x101, 0x106, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x106, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x106, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x106, 0,
    0x301,
    0x300, 0x3C,
    0,
};
Battle D_800A50C8 = { 96, 7, 0x60080000 };
Battle D_800A50D4 = { 96, 7, 0x60080000 };
Battle D_800A50E0 = { 96, 7, 0x60080000 };
Battle D_800A50EC = { 96, 7, 0x60080000 };
Battle D_800A50F8 = { 97, 7, 0x60080000 };
Battle D_800A5104 = { 97, 7, 0x60080000 };
Battle D_800A5110 = { 97, 7, 0x60080000 };
Battle D_800A511C = { 97, 7, 0x60080000 };
BattleList D_800A5128 = {
    3,
    { &D_800A50C8, &D_800A50D4, &D_800A50E0, &D_800A50EC,
      &D_800A50F8, &D_800A5104, &D_800A5110, &D_800A511C },
};
Battle D_800A514C = { 0, 7, 0x60080000 };
Battle D_800A5158 = { 0, 7, 0x60080000 };
Battle D_800A5164 = { 0, 7, 0x60080000 };
Battle D_800A5170 = { 0, 7, 0x60080000 };
Battle D_800A517C = { 0, 7, 0x60080000 };
Battle D_800A5188 = { 0, 7, 0x60080000 };
Battle D_800A5194 = { 0, 7, 0x60080000 };
Battle D_800A51A0 = { 0, 7, 0x60080000 };
BattleList D_800A51AC = {
    0,
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
Battle D_800A5254 = { 13, 19, 0x60880000 };
Battle D_800A5260 = { 316, 19, 0x60880000 };
Battle D_800A526C = { 0, 0, 0x60040000 };
Battle D_800A5278 = { 0, 0, 0x60040000 };
Battle D_800A5284 = { 0, 0, 0x60040000 };
Battle D_800A5290 = { 97, 7, 0x60080000 };
Battle D_800A529C = { 0, 0, 0x60040000 };
Battle D_800A52A8 = { 0, 0, 0x60040000 };
BattleList D_800A52B4 = {
    0,
    { &D_800A5254, &D_800A5260, &D_800A526C, &D_800A5278,
      &D_800A5284, &D_800A5290, &D_800A529C, &D_800A52A8 },
};
FieldBattles stageBattles[] = {
    { 68, 0, 0, { &D_800A5128, &D_800A51AC, &D_800A5230, &D_800A52B4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14E, 0x100, 0x38, 0, 0x140, 0x1FF },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x150, 0x1FF },
};
u16 D_800A5374[] = { 0x868E, 1, 0xFFFF };
u16 D_800A537C[] = { 0x868E, 0, 0, 0, 0xFFFF };
u16 D_800A5388[] = { 0, 1, 0xFFFF };
u16 D_800A5390[] = { 0x868E, 0, 0, 1, 0x848A, 0, 0xFFFF };
u16 D_800A53A0[] = { 0x868E, 0, 0, 1, 0x848A, 1, 0xFFFF };
u16 D_800A53B0[] = { 0x868E, 1, 0x868D, 0, 0x848A, 0, 0x7013, 1, 0xFFFF };
u16 D_800A53C4[] = { 0xA07, 0, 0xFFFF };
u16 D_800A53CC[] = { 0xA07, 1, 0x9039, 1, 0xFFFF };
u16 D_800A53D8[] = { 0xA07, 1, 0xFFFF };
u16 D_800A53E0[] = { 0xA07, 0, 0xFFFF };
u16 D_800A53E8[] = { 0xA07, 1, 0x9039, 1, 0xFFFF };
u16 D_800A53F4[] = { 0xA07, 1, 0xFFFF };
u16 D_800A53FC[] = { 0xA07, 0, 0xFFFF };
u16 D_800A5404[] = { 0xA07, 1, 0x9039, 1, 0xFFFF };
u16 D_800A5410[] = { 0xA07, 1, 0xFFFF };
u16 D_800A5418[] = { 0xA07, 0, 0xFFFF };
u16 D_800A5420[] = { 0xA07, 1, 0x9039, 1, 0xFFFF };
u16 D_800A542C[] = { 0xA07, 1, 0xFFFF };
u16 D_800A5434[] = { 0xA07, 0, 0xFFFF };
u16 D_800A543C[] = { 0xA07, 1, 0x9039, 1, 0xFFFF };
u16 D_800A5448[] = { 0xA07, 1, 0xFFFF };
FieldTalk D_800A5450[] = {
    { D_800A5374, NULL, 0x2F6 },
    { D_800A537C, D_800A5388, 0x2F7 },
    { D_800A5390, NULL, 0x2F8 },
    { D_800A53A0, D_800A53B0, 0x2F9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A548C[] = {
    { D_800A53C4, D_800A53CC, 0x2D2 },
    { D_800A53D8, NULL, 0x49 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B0[] = {
    { D_800A53E0, D_800A53E8, 0x2D2 },
    { D_800A53F4, NULL, 0x4C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54D4[] = {
    { D_800A53FC, D_800A5404, 0x2D2 },
    { D_800A5410, NULL, 0x4A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54F8[] = {
    { D_800A5418, D_800A5420, 0x2D2 },
    { D_800A542C, NULL, 0x4B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A551C[] = {
    { D_800A5434, D_800A543C, 0x2D2 },
    { D_800A5448, NULL, 0x4D },
    { NULL, NULL, 0 },
};
u16 D_800A5540[] = { 0x7048, 1, 0x7050, 1, 0x868D, 1, 0x868E, 0, 0xFFFF };
u16 D_800A5554[] = { 0x701D, 1, 0xFFFF };
u16 D_800A555C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5564[] = { 0x6025, 1, 0xFFFF };
u16 D_800A556C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5574[] = { 0x602B, 1, 0xFFFF };
FieldActorEntry D_800A557C = { D_800A5540, D_800A5450, 0x1C, 4, 97, 242, 7 };
FieldActorEntry D_800A5590 = { D_800A5554, D_800A548C, 0x106, 5, 1073, 145, 1 };
FieldActorEntry D_800A55A4 = { D_800A555C, D_800A54B0, 0x106, 5, 1073, 145, 1 };
FieldActorEntry D_800A55B8 = { D_800A5564, D_800A54D4, 0x106, 5, 1073, 145, 1 };
FieldActorEntry D_800A55CC = { D_800A556C, D_800A54F8, 0x106, 5, 1073, 145, 1 };
FieldActorEntry D_800A55E0 = { D_800A5574, D_800A551C, 0x106, 5, 1073, 145, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A557C,
    &D_800A5590,
    &D_800A55A4,
    &D_800A55B8,
    &D_800A55CC,
    &D_800A55E0,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x294, 0x510, 0x88, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 5, 8, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 5, 4, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 6, 1, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 6, 0, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 6, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x7E, 0x1AF, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x6D, 0x117, 0, 0, 0, 0 },
    { { { 0xF, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1283, D_800A4F84, EVENT_TEXT(0x22), NULL, func_800A4DA4 },
    { 1284, D_800A5024, EVENT_TEXT(0x23), NULL, func_800A4DF0 },
    { 9000, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
