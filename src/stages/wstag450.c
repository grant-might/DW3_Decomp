#include "common.h"
#include "stage.h"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x4031, 1) && FLAGS_00.checkCondition(0x4032, 0)) {
            children[0] = FIELDSTG_startEvent(0x500);
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
    FLAGS_00.applyAction(0x4031, 1);
    FLAGS_00.applyAction(0x7401, 1);
}

void func_800A4DF0(void) {
    FLAGS_00.applyAction(0x4032, 1);
    FLAGS_00.applyAction(0x8023, 1);
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x389
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x399
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1E800, 0x2FB00};
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

extern Battle D_800A50D4;
extern Battle D_800A50E0;
extern Battle D_800A50EC;
extern Battle D_800A50F8;
extern Battle D_800A5104;
extern Battle D_800A5110;
extern Battle D_800A511C;
extern Battle D_800A5128;
extern Battle D_800A5158;
extern Battle D_800A5164;
extern Battle D_800A5170;
extern Battle D_800A517C;
extern Battle D_800A5188;
extern Battle D_800A5194;
extern Battle D_800A51A0;
extern Battle D_800A51AC;
extern Battle D_800A51DC;
extern Battle D_800A51E8;
extern Battle D_800A51F4;
extern Battle D_800A5200;
extern Battle D_800A520C;
extern Battle D_800A5218;
extern Battle D_800A5224;
extern Battle D_800A5230;
extern Battle D_800A5260;
extern Battle D_800A526C;
extern Battle D_800A5278;
extern Battle D_800A5284;
extern Battle D_800A5290;
extern Battle D_800A529C;
extern Battle D_800A52A8;
extern Battle D_800A52B4;
extern Battle D_800A52E4;
extern Battle D_800A52F0;
extern Battle D_800A52FC;
extern Battle D_800A5308;
extern Battle D_800A5314;
extern Battle D_800A5320;
extern Battle D_800A532C;
extern Battle D_800A5338;
extern Battle D_800A5368;
extern Battle D_800A5374;
extern Battle D_800A5380;
extern Battle D_800A538C;
extern Battle D_800A5398;
extern Battle D_800A53A4;
extern Battle D_800A53B0;
extern Battle D_800A53BC;
extern Battle D_800A53EC;
extern Battle D_800A53F8;
extern Battle D_800A5404;
extern Battle D_800A5410;
extern Battle D_800A541C;
extern Battle D_800A5428;
extern Battle D_800A5434;
extern Battle D_800A5440;
extern Battle D_800A5470;
extern Battle D_800A547C;
extern Battle D_800A5488;
extern Battle D_800A5494;
extern Battle D_800A54A0;
extern Battle D_800A54AC;
extern Battle D_800A54B8;
extern Battle D_800A54C4;
extern BattleList D_800A5134;
extern BattleList D_800A51B8;
extern BattleList D_800A523C;
extern BattleList D_800A52C0;
extern BattleList D_800A5344;
extern BattleList D_800A53C8;
extern BattleList D_800A544C;
extern BattleList D_800A54D0;
extern u16 D_800A55CC[];
extern u16 D_800A55DC[];
extern u16 D_800A55E4[];
extern u16 D_800A55EC[];
extern u16 D_800A55F8[];
extern u16 D_800A5608[];
extern u16 D_800A5610[];
extern u16 D_800A5624[];
extern u16 D_800A5630[];
extern u16 D_800A5648[];
extern u16 D_800A5664[];
extern u16 D_800A5680[];
extern u16 D_800A5688[];
extern u16 D_800A5690[];
extern u16 D_800A5698[];
extern u16 D_800A56A4[];
extern u16 D_800A56B4[];
extern u16 D_800A56BC[];
extern u16 D_800A56D0[];
extern u16 D_800A56DC[];
extern u16 D_800A56F4[];
extern u16 D_800A5710[];
extern u16 D_800A572C[];
extern u16 D_800A5734[];
extern u16 D_800A573C[];
extern u16 D_800A5748[];
extern u16 D_800A5750[];
extern u16 D_800A575C[];
extern u16 D_800A5768[];
extern u16 D_800A5770[];
extern u16 D_800A5778[];
extern u16 D_800A5784[];
extern u16 D_800A5794[];
extern u16 D_800A579C[];
extern u16 D_800A57B0[];
extern u16 D_800A57BC[];
extern u16 D_800A57D4[];
extern u16 D_800A57F0[];
extern u16 D_800A580C[];
extern u16 D_800A5814[];
extern u16 D_800A581C[];
extern u16 D_800A5828[];
extern u16 D_800A5830[];
extern u16 D_800A5838[];
extern u16 D_800A5844[];
extern u16 D_800A5854[];
extern u16 D_800A585C[];
extern u16 D_800A5870[];
extern u16 D_800A5878[];
extern u16 D_800A5890[];
extern u16 D_800A58AC[];
extern u16 D_800A58C8[];
extern u16 D_800A5AD4[];
extern FieldTalk D_800A58D0[];
extern u16 D_800A5ADC[];
extern FieldTalk D_800A58E8[];
extern u16 D_800A5AEC[];
extern FieldTalk D_800A5948[];
extern u16 D_800A5AFC[];
extern FieldTalk D_800A59A8[];
extern u16 D_800A5B0C[];
extern FieldTalk D_800A59D8[];
extern u16 D_800A5B1C[];
extern FieldTalk D_800A5A38[];
extern u16 D_800A5B2C[];
extern FieldTalk D_800A5A50[];
extern u16 D_800A5B38[];
extern FieldTalk D_800A5A74[];
extern FieldActorEntry D_800A5B40;
extern FieldActorEntry D_800A5B54;
extern FieldActorEntry D_800A5B68;
extern FieldActorEntry D_800A5B7C;
extern FieldActorEntry D_800A5B90;
extern FieldActorEntry D_800A5BA4;
extern FieldActorEntry D_800A5BB8;
extern FieldActorEntry D_800A5BCC;
extern s16 D_800A4FA0[];
extern s16 D_800A5040[];

s16 D_800A4FA0[] = {
    0x600, 1, 2,
    0x102, 2, 0x14A, 0x125, 3,
    0x100, 0x7F, 0x131, 0x119,
    0x101, 0x7F, 1, 7,
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
    0x200, 0, 2, 0x7F, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 4, 0x7F, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5040[] = {
    0x600, 1, 2,
    0x100, 2, 0x14A, 0x125,
    0x101, 2, 1, 3,
    0x100, 0x7F, 0x131, 0x119,
    0x101, 0x7F, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 2, 0x7F, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 4, 0x7F, 2,
    0x301,
    0x300, 0x3C,
    0,
};
Battle D_800A50D4 = { 53, 8, 0x60080000 };
Battle D_800A50E0 = { 53, 8, 0x60080000 };
Battle D_800A50EC = { 53, 8, 0x60080000 };
Battle D_800A50F8 = { 147, 8, 0x60080000 };
Battle D_800A5104 = { 147, 8, 0x60080000 };
Battle D_800A5110 = { 147, 8, 0x60080000 };
Battle D_800A511C = { 54, 8, 0x60080000 };
Battle D_800A5128 = { 54, 8, 0x60080000 };
BattleList D_800A5134 = {
    3,
    { &D_800A50D4, &D_800A50E0, &D_800A50EC, &D_800A50F8,
      &D_800A5104, &D_800A5110, &D_800A511C, &D_800A5128 },
};
Battle D_800A5158 = { 0, 0, 0x60040000 };
Battle D_800A5164 = { 0, 0, 0x60040000 };
Battle D_800A5170 = { 0, 0, 0x60040000 };
Battle D_800A517C = { 0, 0, 0x60040000 };
Battle D_800A5188 = { 0, 0, 0x60040000 };
Battle D_800A5194 = { 0, 0, 0x60040000 };
Battle D_800A51A0 = { 0, 0, 0x60040000 };
Battle D_800A51AC = { 0, 0, 0x60040000 };
BattleList D_800A51B8 = {
    0,
    { &D_800A5158, &D_800A5164, &D_800A5170, &D_800A517C,
      &D_800A5188, &D_800A5194, &D_800A51A0, &D_800A51AC },
};
Battle D_800A51DC = { 0, 0, 0x60040000 };
Battle D_800A51E8 = { 0, 0, 0x60040000 };
Battle D_800A51F4 = { 0, 0, 0x60040000 };
Battle D_800A5200 = { 0, 0, 0x60040000 };
Battle D_800A520C = { 0, 0, 0x60040000 };
Battle D_800A5218 = { 0, 0, 0x60040000 };
Battle D_800A5224 = { 0, 0, 0x60040000 };
Battle D_800A5230 = { 0, 0, 0x60040000 };
BattleList D_800A523C = {
    0,
    { &D_800A51DC, &D_800A51E8, &D_800A51F4, &D_800A5200,
      &D_800A520C, &D_800A5218, &D_800A5224, &D_800A5230 },
};
Battle D_800A5260 = { 212, 8, 0x600C0000 };
Battle D_800A526C = { 271, 8, 0x60880000 };
Battle D_800A5278 = { 0, 0, 0x60040000 };
Battle D_800A5284 = { 0, 0, 0x60040000 };
Battle D_800A5290 = { 328, 8, 0x60080000 };
Battle D_800A529C = { 0, 0, 0x60040000 };
Battle D_800A52A8 = { 0, 0, 0x60040000 };
Battle D_800A52B4 = { 66, 8, 0x60080000 };
BattleList D_800A52C0 = {
    0,
    { &D_800A5260, &D_800A526C, &D_800A5278, &D_800A5284,
      &D_800A5290, &D_800A529C, &D_800A52A8, &D_800A52B4 },
};
Battle D_800A52E4 = { 53, 8, 0x60080000 };
Battle D_800A52F0 = { 147, 8, 0x60080000 };
Battle D_800A52FC = { 60, 8, 0x60080000 };
Battle D_800A5308 = { 60, 8, 0x60080000 };
Battle D_800A5314 = { 60, 8, 0x60080000 };
Battle D_800A5320 = { 60, 8, 0x60080000 };
Battle D_800A532C = { 60, 8, 0x60080000 };
Battle D_800A5338 = { 60, 8, 0x60080000 };
BattleList D_800A5344 = {
    3,
    { &D_800A52E4, &D_800A52F0, &D_800A52FC, &D_800A5308,
      &D_800A5314, &D_800A5320, &D_800A532C, &D_800A5338 },
};
Battle D_800A5368 = { 0, 0, 0x60040000 };
Battle D_800A5374 = { 0, 0, 0x60040000 };
Battle D_800A5380 = { 0, 0, 0x60040000 };
Battle D_800A538C = { 0, 0, 0x60040000 };
Battle D_800A5398 = { 0, 0, 0x60040000 };
Battle D_800A53A4 = { 0, 0, 0x60040000 };
Battle D_800A53B0 = { 0, 0, 0x60040000 };
Battle D_800A53BC = { 0, 0, 0x60040000 };
BattleList D_800A53C8 = {
    0,
    { &D_800A5368, &D_800A5374, &D_800A5380, &D_800A538C,
      &D_800A5398, &D_800A53A4, &D_800A53B0, &D_800A53BC },
};
Battle D_800A53EC = { 0, 0, 0x60040000 };
Battle D_800A53F8 = { 0, 0, 0x60040000 };
Battle D_800A5404 = { 0, 0, 0x60040000 };
Battle D_800A5410 = { 0, 0, 0x60040000 };
Battle D_800A541C = { 0, 0, 0x60040000 };
Battle D_800A5428 = { 0, 0, 0x60040000 };
Battle D_800A5434 = { 0, 0, 0x60040000 };
Battle D_800A5440 = { 0, 0, 0x60040000 };
BattleList D_800A544C = {
    0,
    { &D_800A53EC, &D_800A53F8, &D_800A5404, &D_800A5410,
      &D_800A541C, &D_800A5428, &D_800A5434, &D_800A5440 },
};
Battle D_800A5470 = { 212, 8, 0x600C0000 };
Battle D_800A547C = { 271, 8, 0x60880000 };
Battle D_800A5488 = { 0, 0, 0x60040000 };
Battle D_800A5494 = { 0, 0, 0x60040000 };
Battle D_800A54A0 = { 328, 8, 0x60080000 };
Battle D_800A54AC = { 0, 0, 0x60040000 };
Battle D_800A54B8 = { 0, 0, 0x60040000 };
Battle D_800A54C4 = { 66, 8, 0x60080000 };
BattleList D_800A54D0 = {
    0,
    { &D_800A5470, &D_800A547C, &D_800A5488, &D_800A5494,
      &D_800A54A0, &D_800A54AC, &D_800A54B8, &D_800A54C4 },
};
FieldBattles stageBattles[] = {
    { 14, 0, 0, { &D_800A5134, &D_800A51B8, &D_800A523C, &D_800A52C0 } },
    { 55, 1, 0, { &D_800A5344, &D_800A53C8, &D_800A544C, &D_800A54D0 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x158, 0x197, 0x60, 0x97, 0x160, 0x1FF },
    { 0x140, 0x100, 0x176, 0x167, 0xD8, 0x67, 0x140, 0x1FE },
    { 0x140, 0x100, 0x15A, 0x100, 0x68, 0, 0x150, 0x1FE },
    { 0x140, 0x100, 0x14A, 0x184, 0x28, 0x84, 0x160, 0x1FE },
};
u16 D_800A55CC[] = { 0x204, 1, 0x8B07, 1, 0x7013, 1, 0xFFFF };
u16 D_800A55DC[] = { 0, 0, 0xFFFF };
u16 D_800A55E4[] = { 0, 1, 0xFFFF };
u16 D_800A55EC[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A55F8[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A5608[] = { 0x7616, 1, 0xFFFF };
u16 D_800A5610[] = { 0x7202, 1, 0x7204, 1, 0xE0C, 0, 0, 1, 0xFFFF };
u16 D_800A5624[] = { 0x7400, 1, 0xE0C, 1, 0xFFFF };
u16 D_800A5630[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0C, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5648[] = {
    0, 1, 0x7204, 1, 0x7202, 1, 0xE0C, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A5664[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0C, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A5680[] = { 0x7816, 1, 0xFFFF };
u16 D_800A5688[] = { 0, 0, 0xFFFF };
u16 D_800A5690[] = { 0, 1, 0xFFFF };
u16 D_800A5698[] = { 0x7202, 0, 0, 1, 0xFFFF };
u16 D_800A56A4[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A56B4[] = { 0x7616, 1, 0xFFFF };
u16 D_800A56BC[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0C, 0, 0xFFFF };
u16 D_800A56D0[] = { 0x7400, 1, 0xE0C, 1, 0xFFFF };
u16 D_800A56DC[] = {
    0, 1, 0x8012, 0, 0x7202, 1, 0x7204, 1,
    0xE0C, 1, 0xFFFF,
};
u16 D_800A56F4[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0C, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A5710[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0C, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A572C[] = { 0x7816, 1, 0xFFFF };
u16 D_800A5734[] = { 0x11, 0, 0xFFFF };
u16 D_800A573C[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5748[] = { 0x11, 0, 0xFFFF };
u16 D_800A5750[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A575C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5768[] = { 0, 0, 0xFFFF };
u16 D_800A5770[] = { 0, 1, 0xFFFF };
u16 D_800A5778[] = { 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5784[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A5794[] = { 0x7616, 1, 0xFFFF };
u16 D_800A579C[] = { 0, 1, 0x7202, 1, 0x7204, 1, 0xE0C, 0, 0xFFFF };
u16 D_800A57B0[] = { 0x7400, 1, 0xE0C, 1, 0xFFFF };
u16 D_800A57BC[] = {
    0, 1, 0x7202, 1, 0xE0C, 1, 0x7204, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A57D4[] = {
    0x7202, 1, 0xE0C, 1, 0x7206, 0, 0, 1,
    0x7204, 1, 0x8012, 1, 0xFFFF,
};
u16 D_800A57F0[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0C, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A580C[] = { 0x7816, 1, 0xFFFF };
u16 D_800A5814[] = { 0x1C19, 0, 0xFFFF };
u16 D_800A581C[] = { 0x1C19, 1, 0x902C, 1, 0xFFFF };
u16 D_800A5828[] = { 0x1C19, 1, 0xFFFF };
u16 D_800A5830[] = { 0, 0, 0xFFFF };
u16 D_800A5838[] = { 0x7202, 0, 0, 1, 0xFFFF };
u16 D_800A5844[] = { 0, 1, 0x7202, 1, 0x7204, 0, 0xFFFF };
u16 D_800A5854[] = { 0x7616, 1, 0xFFFF };
u16 D_800A585C[] = { 0, 1, 0x7202, 1, 0xE0C, 0, 0x7204, 1, 0xFFFF };
u16 D_800A5870[] = { 0xE0C, 1, 0xFFFF };
u16 D_800A5878[] = {
    0, 1, 0x7204, 1, 0x7202, 1, 0xE0C, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5890[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE03, 1,
    0x8012, 1, 0x7206, 0, 0xFFFF,
};
u16 D_800A58AC[] = {
    0, 1, 0x7202, 1, 0x7204, 1, 0xE0C, 1,
    0x8012, 1, 0x7206, 1, 0xFFFF,
};
u16 D_800A58C8[] = { 0x7816, 1, 0xFFFF };
FieldTalk D_800A58D0[] = {
    { NULL, D_800A55CC, 0x24D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58E8[] = {
    { D_800A55DC, D_800A55E4, 0xA5 },
    { D_800A55EC, NULL, 0xA9 },
    { D_800A55F8, D_800A5608, 0xAA },
    { D_800A5610, D_800A5624, 0xAB },
    { D_800A5630, NULL, 0xAC },
    { D_800A5648, NULL, 0xAD },
    { D_800A5664, D_800A5680, 0xAE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5948[] = {
    { D_800A5688, D_800A5690, 0xA6 },
    { D_800A5698, NULL, 0xA9 },
    { D_800A56A4, D_800A56B4, 0xAA },
    { D_800A56BC, D_800A56D0, 0xAB },
    { D_800A56DC, NULL, 0xAC },
    { D_800A56F4, NULL, 0xAD },
    { D_800A5710, D_800A572C, 0xAE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59A8[] = {
    { D_800A5734, NULL, 0xA4 },
    { D_800A573C, D_800A5748, 0xAF },
    { D_800A5750, D_800A575C, 0xB0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59D8[] = {
    { D_800A5768, D_800A5770, 0xA4 },
    { D_800A5778, NULL, 0xA9 },
    { D_800A5784, D_800A5794, 0xAA },
    { D_800A579C, D_800A57B0, 0xAB },
    { D_800A57BC, NULL, 0xAC },
    { D_800A57D4, NULL, 0xAD },
    { D_800A57F0, D_800A580C, 0xAE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A38[] = {
    { NULL, NULL, 0x280 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A50[] = {
    { D_800A5814, D_800A581C, 0x2CB },
    { D_800A5828, NULL, 0x2CC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A74[] = {
    { D_800A5830, NULL, 0xA7 },
    { D_800A5838, NULL, 0xA7 },
    { D_800A5844, D_800A5854, 0xA7 },
    { D_800A585C, D_800A5870, 0xA7 },
    { D_800A5878, NULL, 0xA7 },
    { D_800A5890, NULL, 0xA7 },
    { D_800A58AC, D_800A58C8, 0xA7 },
    { NULL, NULL, 0 },
};
u16 D_800A5AD4[] = { 0x204, 0, 0xFFFF };
u16 D_800A5ADC[] = { 0x7004, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A5AEC[] = { 0x6026, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A5AFC[] = { 0x7009, 1, 0x8192, 1, 0x11, 1, 0xFFFF };
u16 D_800A5B0C[] = { 0x7003, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A5B1C[] = { 0x8192, 0, 0x701A, 0, 0x7009, 1, 0xFFFF };
u16 D_800A5B2C[] = { 0x607, 1, 0x8023, 0, 0xFFFF };
u16 D_800A5B38[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5B40 = { D_800A5AD4, D_800A58D0, 0x21, 4, 1569, 642, 1 };
FieldActorEntry D_800A5B54 = { D_800A5ADC, D_800A58E8, 0x32, 5, 1345, 225, 7 };
FieldActorEntry D_800A5B68 = { D_800A5AEC, D_800A5948, 0x32, 5, 1345, 225, 7 };
FieldActorEntry D_800A5B7C = { D_800A5AFC, D_800A59A8, 0x32, 5, 1345, 225, 7 };
FieldActorEntry D_800A5B90 = { D_800A5B0C, D_800A59D8, 0x32, 5, 1345, 225, 7 };
FieldActorEntry D_800A5BA4 = { D_800A5B1C, D_800A5A38, 0x32, 5, 1345, 225, 7 };
FieldActorEntry D_800A5BB8 = { D_800A5B2C, D_800A5A50, 0x7F, 6, 305, 281, 7 };
FieldActorEntry D_800A5BCC = { D_800A5B38, D_800A5A74, 0x9D, 7, 1345, 225, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5B40,
    &D_800A5B54,
    &D_800A5B68,
    &D_800A5B7C,
    &D_800A5B90,
    &D_800A5BA4,
    &D_800A5BB8,
    &D_800A5BCC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 3, 1, 3, 8, 8, 0, 665, 621, 0, 0 },
    { 1, 0, 0x40, 2, 3, 1, 3, 8, 8, 0, 1102, 881, 0, 0 },
    { 1, 0, 0x40, 2, 3, 1, 3, 8, 8, 0, 1232, 197, 0, 0 },
    { 1, 0, 0x40, 2, 3, 1, 3, 8, 8, 0, 1668, 433, 0, 0 },
    { 1, 0, 0x64, 2, 9, 0, 0, 0, 0, 0, 29, 246, 0, 0 },
    { 1, 0, 0x64, 2, 0xA, 0, 0, 0, 0, 0, 30, 321, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 391, 857, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 615, 820, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 632, 617, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 664, 966, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 708, 828, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 804, 888, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1037, 765, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1113, 492, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1321, 622, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1392, 440, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1427, 532, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1577, 549, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1693, 707, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 52, 229, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 158, 422, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 206, 840, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 264, 567, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 408, 861, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 958, 570, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1212, 539, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1312, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1447, 533, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1467, 678, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 727, 829, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 796, 674, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 923, 864, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1546, 718, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1592, 300, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1678, 629, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 450, 189, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 614, 453, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 739, 309, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 849, 430, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 939, 336, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1006, 804, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1099, 261, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1106, 204, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1281, 849, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1351, 965, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1373, 906, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1515, 148, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1638, 263, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 487, 418, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 615, 738, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 650, 168, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 726, 724, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 753, 138, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 824, 182, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 919, 759, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1024, 129, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1070, 887, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 448, 657, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 481, 570, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 496, 432, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 499, 893, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 623, 462, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 654, 771, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 729, 295, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 789, 504, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 806, 100, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 821, 172, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 821, 172, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 900, 723, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 946, 346, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 995, 394, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1042, 140, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1084, 901, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1270, 536, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1295, 946, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1326, 147, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1435, 1007, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 124, 163, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 268, 145, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 367, 150, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 381, 194, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 491, 192, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 500, 597, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 522, 343, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 584, 290, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 644, 607, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 689, 964, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 742, 662, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 789, 927, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 814, 673, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 822, 887, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 850, 658, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 940, 627, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 942, 864, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1028, 955, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1055, 523, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1055, 764, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1059, 515, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1062, 755, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1128, 198, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1178, 288, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1184, 281, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1281, 291, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1309, 391, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1533, 140, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1568, 715, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1628, 413, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1629, 254, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1641, 414, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1699, 627, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 61, 371, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 76, 156, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 111, 502, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 177, 675, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 215, 912, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 227, 135, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 270, 479, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 349, 725, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 380, 125, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 472, 371, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 539, 550, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 645, 71, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 660, 485, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 697, 754, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 727, 802, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 741, 442, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 815, 657, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 862, 133, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 870, 300, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 925, 595, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 939, 777, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 954, 913, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1040, 166, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1068, 486, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1138, 820, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1157, 911, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1164, 207, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1171, 545, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1343, 282, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1346, 642, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1381, 970, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1384, 858, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1421, 456, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1428, 127, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1446, 956, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1488, 682, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1609, 121, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1623, 498, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1637, 334, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x4A, 0xA, 0, 1740, 602, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 294, 561, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 298, 104, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 305, 774, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 535, 30, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 634, 887, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 727, 249, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 773, 71, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 849, 883, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 924, 465, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 961, 383, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 977, 93, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1133, 96, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1219, 951, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1270, 589, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1312, 412, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1380, 577, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1455, 655, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1484, 908, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1513, 169, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1615, 540, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1647, 699, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1691, 390, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1737, 761, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 0xA, 0, 1738, 188, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 1425, 433, 443, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 1041, 394, 430, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 918, 546, 581, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x233, 0x80, 0x220, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x237, 0x49C, 0x246, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x235, 0xF8, 0xA4, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23A, 0x560, 0x440, 1, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E5, 0x240, 0x120, 1, 0, 1, 2 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x50, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x50, 0xFFD8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFB8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB0, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x50, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1279, D_800A4FA0, EVENT_TEXT(0x19), NULL, func_800A4DA4 },
    { 1280, D_800A5040, EVENT_TEXT(0x1A), NULL, func_800A4DF0 },
    { -1, NULL, 0, NULL, NULL },
};
