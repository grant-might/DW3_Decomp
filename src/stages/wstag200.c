#include "common.h"
#include "stage.h"

/* Creates the event object of progress 3, which depends on flag 0x400D */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 3) {
            children[0] = FIELDSTG_startEvent(FLAGS_00.checkCondition(0x400D, 0) ? 0x32 : 0x34);
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

void func_800A4D9C(void) {
    FLAGS_00.applyAction(0x400D, 1);
    FLAGS_00.applyAction(0x7401, 1);
}

void func_800A4DE8(void) {
    GAME.progress = 4;
}

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xCD
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x189
#define STAGE_ARCHIVE 0x30F
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xC5)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x197
#define STAGE_ARCHIVE 0x31E
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x3E800, 0xEC00};
    D_800990B4.startDir = 1;
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 4;
    D_800990B4.music = 0x60100000;
    D_800990B4.actors = stageActors;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x14 && GAME.progress < 0x18) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A50F8;
extern Battle D_800A5104;
extern Battle D_800A5110;
extern Battle D_800A511C;
extern Battle D_800A5128;
extern Battle D_800A5134;
extern Battle D_800A5140;
extern Battle D_800A514C;
extern Battle D_800A517C;
extern Battle D_800A5188;
extern Battle D_800A5194;
extern Battle D_800A51A0;
extern Battle D_800A51AC;
extern Battle D_800A51B8;
extern Battle D_800A51C4;
extern Battle D_800A51D0;
extern Battle D_800A5200;
extern Battle D_800A520C;
extern Battle D_800A5218;
extern Battle D_800A5224;
extern Battle D_800A5230;
extern Battle D_800A523C;
extern Battle D_800A5248;
extern Battle D_800A5254;
extern Battle D_800A5284;
extern Battle D_800A5290;
extern Battle D_800A529C;
extern Battle D_800A52A8;
extern Battle D_800A52B4;
extern Battle D_800A52C0;
extern Battle D_800A52CC;
extern Battle D_800A52D8;
extern BattleList D_800A5158;
extern BattleList D_800A51DC;
extern BattleList D_800A5260;
extern BattleList D_800A52E4;
extern u16 D_800A5424[];
extern u16 D_800A542C[];
extern u16 D_800A5434[];
extern u16 D_800A543C[];
extern u16 D_800A5444[];
extern u16 D_800A544C[];
extern u16 D_800A5454[];
extern u16 D_800A5460[];
extern u16 D_800A5470[];
extern u16 D_800A5478[];
extern u16 D_800A548C[];
extern u16 D_800A5498[];
extern u16 D_800A54B0[];
extern u16 D_800A54CC[];
extern u16 D_800A54E8[];
extern u16 D_800A54F0[];
extern u16 D_800A54F8[];
extern u16 D_800A5500[];
extern u16 D_800A550C[];
extern u16 D_800A551C[];
extern u16 D_800A5524[];
extern u16 D_800A5538[];
extern u16 D_800A5544[];
extern u16 D_800A555C[];
extern u16 D_800A5578[];
extern u16 D_800A5594[];
extern u16 D_800A559C[];
extern u16 D_800A55A4[];
extern u16 D_800A55AC[];
extern u16 D_800A55B8[];
extern u16 D_800A55C8[];
extern u16 D_800A55D0[];
extern u16 D_800A55E4[];
extern u16 D_800A55F0[];
extern u16 D_800A5608[];
extern u16 D_800A5624[];
extern u16 D_800A5640[];
extern u16 D_800A5648[];
extern u16 D_800A5650[];
extern u16 D_800A565C[];
extern u16 D_800A5664[];
extern u16 D_800A5670[];
extern u16 D_800A567C[];
extern u16 D_800A5684[];
extern u16 D_800A5690[];
extern u16 D_800A56A0[];
extern u16 D_800A56A8[];
extern u16 D_800A56BC[];
extern u16 D_800A56C4[];
extern u16 D_800A56DC[];
extern u16 D_800A56F8[];
extern u16 D_800A5714[];
extern u16 D_800A571C[];
extern u16 D_800A5724[];
extern u16 D_800A572C[];
extern u16 D_800A5734[];
extern u16 D_800A5DB4[];
extern u16 D_800A5DBC[];
extern FieldTalk D_800A573C[];
extern u16 D_800A5DC4[];
extern FieldTalk D_800A5754[];
extern u16 D_800A5DCC[];
extern FieldTalk D_800A576C[];
extern u16 D_800A5DD4[];
extern FieldTalk D_800A5784[];
extern u16 D_800A5DDC[];
extern FieldTalk D_800A579C[];
extern u16 D_800A5DEC[];
extern FieldTalk D_800A57B4[];
extern u16 D_800A5DF4[];
extern FieldTalk D_800A57CC[];
extern u16 D_800A5DFC[];
extern FieldTalk D_800A57E4[];
extern u16 D_800A5E04[];
extern FieldTalk D_800A57FC[];
extern u16 D_800A5E0C[];
extern FieldTalk D_800A5814[];
extern u16 D_800A5E14[];
extern FieldTalk D_800A582C[];
extern u16 D_800A5E1C[];
extern FieldTalk D_800A5850[];
extern u16 D_800A5E24[];
extern FieldTalk D_800A5868[];
extern u16 D_800A5E34[];
extern FieldTalk D_800A5880[];
extern u16 D_800A5E3C[];
extern FieldTalk D_800A5898[];
extern u16 D_800A5E44[];
extern FieldTalk D_800A58B0[];
extern u16 D_800A5E4C[];
extern FieldTalk D_800A58C8[];
extern u16 D_800A5E54[];
extern FieldTalk D_800A58E0[];
extern u16 D_800A5E5C[];
extern FieldTalk D_800A5904[];
extern u16 D_800A5E64[];
extern FieldTalk D_800A591C[];
extern u16 D_800A5E6C[];
extern FieldTalk D_800A5934[];
extern u16 D_800A5E74[];
extern FieldTalk D_800A594C[];
extern u16 D_800A5E7C[];
extern FieldTalk D_800A5964[];
extern u16 D_800A5E8C[];
extern FieldTalk D_800A59C4[];
extern u16 D_800A5E9C[];
extern u16 D_800A5EA4[];
extern FieldTalk D_800A5A24[];
extern u16 D_800A5EB4[];
extern FieldTalk D_800A5A84[];
extern u16 D_800A5EC4[];
extern FieldTalk D_800A5AB4[];
extern u16 D_800A5ED4[];
extern FieldTalk D_800A5ACC[];
extern u16 D_800A5EDC[];
extern FieldTalk D_800A5B2C[];
extern u16 D_800A5EE4[];
extern FieldTalk D_800A5B44[];
extern u16 D_800A5EEC[];
extern FieldTalk D_800A5B5C[];
extern u16 D_800A5EF8[];
extern FieldTalk D_800A5B80[];
extern u16 D_800A5F00[];
extern FieldTalk D_800A5B98[];
extern u16 D_800A5F08[];
extern FieldTalk D_800A5BB0[];
extern u16 D_800A5F10[];
extern FieldTalk D_800A5BC8[];
extern u16 D_800A5F18[];
extern FieldTalk D_800A5BE0[];
extern u16 D_800A5F20[];
extern FieldTalk D_800A5BF8[];
extern u16 D_800A5F28[];
extern FieldTalk D_800A5C10[];
extern u16 D_800A5F30[];
extern FieldTalk D_800A5C28[];
extern u16 D_800A5F38[];
extern FieldTalk D_800A5C40[];
extern u16 D_800A5F40[];
extern FieldTalk D_800A5C58[];
extern u16 D_800A5F48[];
extern FieldTalk D_800A5C70[];
extern u16 D_800A5F50[];
extern FieldTalk D_800A5C88[];
extern u16 D_800A5F58[];
extern FieldTalk D_800A5CA0[];
extern u16 D_800A5F60[];
extern FieldTalk D_800A5CB8[];
extern u16 D_800A5F68[];
extern FieldTalk D_800A5CD0[];
extern u16 D_800A5F70[];
extern FieldTalk D_800A5CE8[];
extern u16 D_800A5F80[];
extern FieldTalk D_800A5D00[];
extern u16 D_800A5F88[];
extern FieldTalk D_800A5D18[];
extern u16 D_800A5F90[];
extern FieldTalk D_800A5D3C[];
extern u16 D_800A5F98[];
extern FieldTalk D_800A5D54[];
extern u16 D_800A5FA0[];
extern FieldTalk D_800A5D6C[];
extern u16 D_800A5FA8[];
extern FieldTalk D_800A5D84[];
extern u16 D_800A5FB0[];
extern FieldTalk D_800A5D9C[];
extern FieldActorEntry D_800A5FB8;
extern FieldActorEntry D_800A5FCC;
extern FieldActorEntry D_800A5FE0;
extern FieldActorEntry D_800A5FF4;
extern FieldActorEntry D_800A6008;
extern FieldActorEntry D_800A601C;
extern FieldActorEntry D_800A6030;
extern FieldActorEntry D_800A6044;
extern FieldActorEntry D_800A6058;
extern FieldActorEntry D_800A606C;
extern FieldActorEntry D_800A6080;
extern FieldActorEntry D_800A6094;
extern FieldActorEntry D_800A60A8;
extern FieldActorEntry D_800A60BC;
extern FieldActorEntry D_800A60D0;
extern FieldActorEntry D_800A60E4;
extern FieldActorEntry D_800A60F8;
extern FieldActorEntry D_800A610C;
extern FieldActorEntry D_800A6120;
extern FieldActorEntry D_800A6134;
extern FieldActorEntry D_800A6148;
extern FieldActorEntry D_800A615C;
extern FieldActorEntry D_800A6170;
extern FieldActorEntry D_800A6184;
extern FieldActorEntry D_800A6198;
extern FieldActorEntry D_800A61AC;
extern FieldActorEntry D_800A61C0;
extern FieldActorEntry D_800A61D4;
extern FieldActorEntry D_800A61E8;
extern FieldActorEntry D_800A61FC;
extern FieldActorEntry D_800A6210;
extern FieldActorEntry D_800A6224;
extern FieldActorEntry D_800A6238;
extern FieldActorEntry D_800A624C;
extern FieldActorEntry D_800A6260;
extern FieldActorEntry D_800A6274;
extern FieldActorEntry D_800A6288;
extern FieldActorEntry D_800A629C;
extern FieldActorEntry D_800A62B0;
extern FieldActorEntry D_800A62C4;
extern FieldActorEntry D_800A62D8;
extern FieldActorEntry D_800A62EC;
extern FieldActorEntry D_800A6300;
extern FieldActorEntry D_800A6314;
extern FieldActorEntry D_800A6328;
extern FieldActorEntry D_800A633C;
extern FieldActorEntry D_800A6350;
extern FieldActorEntry D_800A6364;
extern FieldActorEntry D_800A6378;
extern FieldActorEntry D_800A638C;
extern FieldActorEntry D_800A63A0;
extern FieldActorEntry D_800A63B4;
extern FieldActorEntry D_800A63C8;
extern FieldActorEntry D_800A63DC;
extern FieldActorEntry D_800A63F0;
extern FieldActorEntry D_800A6404;
extern s16 D_800A4F5C[];
extern s16 D_800A5008[];

s16 D_800A4F5C[] = {
    0x600, 1, 1,
    0x100, 1, 0x418, 0xD4,
    0x101, 1, 1, 1,
    0x100, 0x39, 0x448, 0x11E,
    0x101, 0x39, 1, 1,
    0x101, 0x32D, 0x337, 1,
    0x300, 0x78,
    0x102, 1, 0x3E8, 0xEC, 1,
    0x300, 0x3C,
    0x101, 0x323, 0x325, 0x39,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x39,
    0x300, 0x1E,
    0x102, 0x39, 0x408, 0xFE, 3,
    0x302, 0x39,
    0x101, 1, 1, 7,
    0x101, 0x39, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0x39, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 1, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x39, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5008[] = {
    0x100, 1, 0x3E8, 0xEC,
    0x101, 1, 1, 7,
    0x100, 0x39, 0x408, 0xFE,
    0x101, 0x39, 1, 3,
    0x300, 0x78,
    0x200, 0, 1, 1, 0,
    0x101, 1, 7, 7,
    0x301,
    0x101, 1, 1, 7,
    0x300, 0x1E,
    0x200, 0, 2, 0x39, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 1, 0,
    0x101, 1, 7, 7,
    0x301,
    0x101, 1, 1, 7,
    0x300, 0x1E,
    0x200, 0, 4, 0x39, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 1, 0,
    0x101, 1, 7, 7,
    0x301,
    0x101, 1, 1, 7,
    0x300, 0x1E,
    0x200, 0, 6, 0x39, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 1, 0,
    0x101, 1, 7, 7,
    0x301,
    0x101, 1, 1, 7,
    0x300, 0x1E,
    0x200, 0, 8, 0x39, 3,
    0x301,
    0x300, 0x1E,
    0x304, 0x206, 0x70, 0xF0, 7,
    0,
};
Battle D_800A50F8 = { 0, 0, 0x60040000 };
Battle D_800A5104 = { 0, 0, 0x60040000 };
Battle D_800A5110 = { 0, 0, 0x60040000 };
Battle D_800A511C = { 0, 0, 0x60040000 };
Battle D_800A5128 = { 0, 0, 0x60040000 };
Battle D_800A5134 = { 0, 0, 0x60040000 };
Battle D_800A5140 = { 0, 0, 0x60040000 };
Battle D_800A514C = { 0, 0, 0x60040000 };
BattleList D_800A5158 = {
    0,
    { &D_800A50F8, &D_800A5104, &D_800A5110, &D_800A511C,
      &D_800A5128, &D_800A5134, &D_800A5140, &D_800A514C },
};
Battle D_800A517C = { 0, 0, 0x60040000 };
Battle D_800A5188 = { 0, 0, 0x60040000 };
Battle D_800A5194 = { 0, 0, 0x60040000 };
Battle D_800A51A0 = { 0, 0, 0x60040000 };
Battle D_800A51AC = { 0, 0, 0x60040000 };
Battle D_800A51B8 = { 0, 0, 0x60040000 };
Battle D_800A51C4 = { 0, 0, 0x60040000 };
Battle D_800A51D0 = { 0, 0, 0x60040000 };
BattleList D_800A51DC = {
    0,
    { &D_800A517C, &D_800A5188, &D_800A5194, &D_800A51A0,
      &D_800A51AC, &D_800A51B8, &D_800A51C4, &D_800A51D0 },
};
Battle D_800A5200 = { 0, 0, 0x60040000 };
Battle D_800A520C = { 0, 0, 0x60040000 };
Battle D_800A5218 = { 0, 0, 0x60040000 };
Battle D_800A5224 = { 0, 0, 0x60040000 };
Battle D_800A5230 = { 0, 0, 0x60040000 };
Battle D_800A523C = { 0, 0, 0x60040000 };
Battle D_800A5248 = { 0, 0, 0x60040000 };
Battle D_800A5254 = { 0, 0, 0x60040000 };
BattleList D_800A5260 = {
    0,
    { &D_800A5200, &D_800A520C, &D_800A5218, &D_800A5224,
      &D_800A5230, &D_800A523C, &D_800A5248, &D_800A5254 },
};
Battle D_800A5284 = { 188, 18, 0x60080000 };
Battle D_800A5290 = { 200, 18, 0x60080000 };
Battle D_800A529C = { 272, 20, 0x600C0000 };
Battle D_800A52A8 = { 0, 0, 0x60040000 };
Battle D_800A52B4 = { 0, 0, 0x60040000 };
Battle D_800A52C0 = { 0, 0, 0x60040000 };
Battle D_800A52CC = { 0, 0, 0x60040000 };
Battle D_800A52D8 = { 0, 0, 0x60040000 };
BattleList D_800A52E4 = {
    0,
    { &D_800A5284, &D_800A5290, &D_800A529C, &D_800A52A8,
      &D_800A52B4, &D_800A52C0, &D_800A52CC, &D_800A52D8 },
};
FieldBattles stageBattles[] = {
    { 131, 0, 0, { &D_800A5158, &D_800A51DC, &D_800A5260, &D_800A52E4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1F6, 0x17C, 0x2D8, 0x7C, 0x170, 0x1F2 },
    { 0x1C0, 0x100, 0x1C0, 0x185, 0x200, 0x85, 0x170, 0x1F1 },
    { 0x1C0, 0x100, 0x1F6, 0x154, 0x2D8, 0x54, 0x170, 0x1F0 },
    { 0x1C0, 0x100, 0x1D4, 0x185, 0x250, 0x85, 0x170, 0x1EF },
    { 0x1C0, 0x100, 0x1DC, 0x185, 0x270, 0x85, 0x170, 0x1EE },
    { 0x1C0, 0x100, 0x1E4, 0x18C, 0x290, 0x8C, 0x170, 0x1ED },
    { 0x1C0, 0x100, 0x1C8, 0x192, 0x220, 0x92, 0x170, 0x1EC },
    { 0x1C0, 0x100, 0x1EC, 0x19C, 0x2B0, 0x9C, 0x170, 0x1EB },
    { 0x1C0, 0x100, 0x1F4, 0x19C, 0x2D0, 0x9C, 0x170, 0x1EA },
    { 0x1C0, 0x100, 0x1C0, 0x1A5, 0x200, 0xA5, 0x170, 0x1E9 },
};
u16 D_800A5424[] = { 0x1A18, 0, 0xFFFF };
u16 D_800A542C[] = { 0x1A18, 1, 0xFFFF };
u16 D_800A5434[] = { 0x1A18, 0, 0xFFFF };
u16 D_800A543C[] = { 0x1A18, 1, 0xFFFF };
u16 D_800A5444[] = { 0, 0, 0xFFFF };
u16 D_800A544C[] = { 0, 1, 0xFFFF };
u16 D_800A5454[] = { 0, 1, 0x7200, 0, 0xFFFF };
u16 D_800A5460[] = { 0, 1, 0x7200, 1, 0x7202, 0, 0xFFFF };
u16 D_800A5470[] = { 0x7600, 1, 0xFFFF };
u16 D_800A5478[] = { 0, 1, 0x7200, 1, 0x7202, 1, 0xE00, 0, 0xFFFF };
u16 D_800A548C[] = { 0x7402, 1, 0xE00, 1, 0xFFFF };
u16 D_800A5498[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0xE00, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A54B0[] = {
    0x8012, 1, 0, 1, 0x7200, 1, 0x7202, 1,
    0xE00, 1, 0x7204, 0, 0xFFFF,
};
u16 D_800A54CC[] = {
    0, 1, 0x7202, 1, 0x8012, 1, 0x7200, 1,
    0xE00, 1, 0x7204, 1, 0xFFFF,
};
u16 D_800A54E8[] = { 0x7800, 1, 0xFFFF };
u16 D_800A54F0[] = { 0, 0, 0xFFFF };
u16 D_800A54F8[] = { 0, 1, 0xFFFF };
u16 D_800A5500[] = { 0, 1, 0x7200, 0, 0xFFFF };
u16 D_800A550C[] = { 0, 1, 0x7200, 1, 0x7202, 0, 0xFFFF };
u16 D_800A551C[] = { 0x7600, 1, 0xFFFF };
u16 D_800A5524[] = { 0, 1, 0x7200, 1, 0x7202, 1, 0xE00, 0, 0xFFFF };
u16 D_800A5538[] = { 0x7402, 1, 0xE00, 1, 0xFFFF };
u16 D_800A5544[] = {
    0x8012, 0, 0, 1, 0x7200, 1, 0xE00, 1,
    0x7202, 1, 0xFFFF,
};
u16 D_800A555C[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0xE00, 1,
    0x8012, 1, 0x7204, 0, 0xFFFF,
};
u16 D_800A5578[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0xE00, 1,
    0x8012, 1, 0x7204, 1, 0xFFFF,
};
u16 D_800A5594[] = { 0x7800, 1, 0xFFFF };
u16 D_800A559C[] = { 0, 0, 0xFFFF };
u16 D_800A55A4[] = { 0, 1, 0xFFFF };
u16 D_800A55AC[] = { 0x7200, 0, 0, 1, 0xFFFF };
u16 D_800A55B8[] = { 0x7200, 1, 0, 1, 0x7202, 0, 0xFFFF };
u16 D_800A55C8[] = { 0x7600, 1, 0xFFFF };
u16 D_800A55D0[] = { 0x7200, 1, 0xE00, 0, 0, 1, 0x7202, 1, 0xFFFF };
u16 D_800A55E4[] = { 0xE00, 1, 0x7402, 1, 0xFFFF };
u16 D_800A55F0[] = {
    0, 1, 0x7200, 1, 0x7202, 1, 0xE00, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5608[] = {
    0x7200, 1, 0xE00, 1, 0x7204, 0, 0, 1,
    0x7202, 1, 0x8012, 1, 0xFFFF,
};
u16 D_800A5624[] = {
    0, 1, 0x7202, 1, 0x8012, 1, 0x7204, 1,
    0x7200, 1, 0xE00, 1, 0xFFFF,
};
u16 D_800A5640[] = { 0x7800, 1, 0xFFFF };
u16 D_800A5648[] = { 0x11, 0, 0xFFFF };
u16 D_800A5650[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A565C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5664[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5670[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A567C[] = { 0, 0, 0xFFFF };
u16 D_800A5684[] = { 0, 1, 0x7200, 0, 0xFFFF };
u16 D_800A5690[] = { 0, 1, 0x7202, 0, 0x7200, 1, 0xFFFF };
u16 D_800A56A0[] = { 0x7600, 1, 0xFFFF };
u16 D_800A56A8[] = { 0, 1, 0x7202, 1, 0x7200, 1, 0xE00, 0, 0xFFFF };
u16 D_800A56BC[] = { 0xE00, 1, 0xFFFF };
u16 D_800A56C4[] = {
    0, 1, 0x7202, 1, 0x8012, 0, 0x7202, 1,
    0xE00, 1, 0xFFFF,
};
u16 D_800A56DC[] = {
    0, 1, 0x7200, 1, 0x8012, 1, 0x7204, 0,
    0x7202, 1, 0xE00, 1, 0xFFFF,
};
u16 D_800A56F8[] = {
    0, 1, 0xE00, 1, 0x7204, 1, 0x7200, 1,
    0x7202, 1, 0x8012, 1, 0xFFFF,
};
u16 D_800A5714[] = { 0x7800, 1, 0xFFFF };
u16 D_800A571C[] = { 0x1A0C, 0, 0xFFFF };
u16 D_800A5724[] = { 0x1A0C, 1, 0xFFFF };
u16 D_800A572C[] = { 0x1A18, 0, 0xFFFF };
u16 D_800A5734[] = { 0x1A18, 1, 0xFFFF };
FieldTalk D_800A573C[] = {
    { NULL, NULL, 0x13 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5754[] = {
    { NULL, NULL, 0x26F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A576C[] = {
    { NULL, NULL, 0x270 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5784[] = {
    { NULL, NULL, 0x271 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A579C[] = {
    { NULL, NULL, 0x26E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57B4[] = {
    { NULL, NULL, 0x272 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57CC[] = {
    { NULL, NULL, 0x4A3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57E4[] = {
    { NULL, NULL, 0x273 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57FC[] = {
    { NULL, NULL, 0x274 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5814[] = {
    { NULL, NULL, 0x275 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A582C[] = {
    { D_800A5424, NULL, 0x26E },
    { D_800A542C, NULL, 0x4A3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5850[] = {
    { NULL, NULL, 0xF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5868[] = {
    { NULL, NULL, 0x299 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5880[] = {
    { NULL, NULL, 0x29A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5898[] = {
    { NULL, NULL, 0x29B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58B0[] = {
    { NULL, NULL, 0x29C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C8[] = {
    { NULL, NULL, 0x29D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58E0[] = {
    { D_800A5434, NULL, 0x299 },
    { D_800A543C, NULL, 0x4A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5904[] = {
    { NULL, NULL, 0x29E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A591C[] = {
    { NULL, NULL, 0x29F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5934[] = {
    { NULL, NULL, 0x2A0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A594C[] = {
    { NULL, NULL, 0x4A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5964[] = {
    { D_800A5444, D_800A544C, 0x69 },
    { D_800A5454, NULL, 0x6D },
    { D_800A5460, D_800A5470, 0x6E },
    { D_800A5478, D_800A548C, 0x6F },
    { D_800A5498, NULL, 0x81 },
    { D_800A54B0, NULL, 0x82 },
    { D_800A54CC, D_800A54E8, 0x83 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59C4[] = {
    { D_800A54F0, D_800A54F8, 0x68 },
    { D_800A5500, NULL, 0x6D },
    { D_800A550C, D_800A551C, 0x6E },
    { D_800A5524, D_800A5538, 0x6F },
    { D_800A5544, NULL, 0x81 },
    { D_800A555C, NULL, 0x82 },
    { D_800A5578, D_800A5594, 0x83 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A24[] = {
    { D_800A559C, D_800A55A4, 0x6A },
    { D_800A55AC, NULL, 0x6D },
    { D_800A55B8, D_800A55C8, 0x6E },
    { D_800A55D0, D_800A55E4, 0x6F },
    { D_800A55F0, NULL, 0x81 },
    { D_800A5608, NULL, 0x82 },
    { D_800A5624, D_800A5640, 0x83 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A84[] = {
    { D_800A5648, NULL, 0x68 },
    { D_800A5650, D_800A565C, 0x7F },
    { D_800A5664, D_800A5670, 0x80 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AB4[] = {
    { NULL, NULL, 0x41A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5ACC[] = {
    { D_800A567C, NULL, 0x6B },
    { D_800A5684, NULL, 0x6D },
    { D_800A5690, D_800A56A0, 0x6E },
    { D_800A56A8, D_800A56BC, 0x6F },
    { D_800A56C4, NULL, 0x81 },
    { D_800A56DC, NULL, 0x82 },
    { D_800A56F8, D_800A5714, 0x83 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B2C[] = {
    { NULL, NULL, 0x2A1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B44[] = {
    { NULL, NULL, 0x276 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B5C[] = {
    { D_800A571C, NULL, 0x4D },
    { D_800A5724, NULL, 0x4E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B80[] = {
    { NULL, NULL, 0x15 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B98[] = {
    { NULL, NULL, 0x25A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BB0[] = {
    { NULL, NULL, 0x25B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BC8[] = {
    { NULL, NULL, 0x25C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BE0[] = {
    { NULL, NULL, 0x25D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BF8[] = {
    { NULL, NULL, 0x25E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C10[] = {
    { NULL, NULL, 0x263 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C28[] = {
    { NULL, NULL, 0x25F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C40[] = {
    { NULL, NULL, 0x260 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C58[] = {
    { NULL, NULL, 0x261 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C70[] = {
    { NULL, NULL, 0x262 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C88[] = {
    { NULL, NULL, 0x14 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CA0[] = {
    { NULL, NULL, 0x265 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CB8[] = {
    { NULL, NULL, 0x266 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CD0[] = {
    { NULL, NULL, 0x267 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CE8[] = {
    { NULL, NULL, 0x264 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D00[] = {
    { NULL, NULL, 0x268 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D18[] = {
    { D_800A572C, NULL, 0x264 },
    { D_800A5734, NULL, 0x4A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D3C[] = {
    { NULL, NULL, 0x269 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D54[] = {
    { NULL, NULL, 0x26A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D6C[] = {
    { NULL, NULL, 0x26B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D84[] = {
    { NULL, NULL, 0x26C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D9C[] = {
    { NULL, NULL, 0x4A4 },
    { NULL, NULL, 0 },
};
u16 D_800A5DB4[] = { 0x6003, 1, 0xFFFF };
u16 D_800A5DBC[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5DC4[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5DCC[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5DD4[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5DDC[] = { 0x7015, 1, 0x6008, 0, 0x6009, 0, 0xFFFF };
u16 D_800A5DEC[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5DF4[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5DFC[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5E04[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5E0C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5E14[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5E1C[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5E24[] = { 0x7015, 1, 0x6008, 0, 0x6009, 0, 0xFFFF };
u16 D_800A5E34[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5E3C[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5E44[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5E4C[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5E54[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5E5C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5E64[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5E6C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5E74[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5E7C[] = { 0x7004, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A5E8C[] = { 0x7003, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A5E9C[] = { 0x6003, 1, 0xFFFF };
u16 D_800A5EA4[] = { 0x6026, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A5EB4[] = { 0x11, 1, 0x7009, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5EC4[] = { 0x701A, 0, 0x8192, 0, 0x7009, 1, 0xFFFF };
u16 D_800A5ED4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5EDC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5EE4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5EEC[] = { 0x600C, 1, 0x1A15, 0, 0xFFFF };
u16 D_800A5EF8[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5F00[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5F08[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5F10[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5F18[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5F20[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5F28[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5F30[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5F38[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5F40[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5F48[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5F50[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5F58[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5F60[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5F68[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5F70[] = { 0x7015, 1, 0x6008, 0, 0x6009, 0, 0xFFFF };
u16 D_800A5F80[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5F88[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5F90[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5F98[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5FA0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5FA8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5FB0[] = { 0x6009, 1, 0xFFFF };
FieldActorEntry D_800A5FB8 = { D_800A5DB4, NULL, 1, 4, 0, 0, 1 };
FieldActorEntry D_800A5FCC = { D_800A5DBC, D_800A573C, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A5FE0 = { D_800A5DC4, D_800A5754, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A5FF4 = { D_800A5DCC, D_800A576C, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A6008 = { D_800A5DD4, D_800A5784, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A601C = { D_800A5DDC, D_800A579C, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A6030 = { D_800A5DEC, D_800A57B4, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A6044 = { D_800A5DF4, D_800A57CC, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A6058 = { D_800A5DFC, D_800A57E4, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A606C = { D_800A5E04, D_800A57FC, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A6080 = { D_800A5E0C, D_800A5814, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A6094 = { D_800A5E14, D_800A582C, 0x2E, 5, 564, 558, 5 };
FieldActorEntry D_800A60A8 = { D_800A5E1C, D_800A5850, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A60BC = { D_800A5E24, D_800A5868, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A60D0 = { D_800A5E34, D_800A5880, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A60E4 = { D_800A5E3C, D_800A5898, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A60F8 = { D_800A5E44, D_800A58B0, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A610C = { D_800A5E4C, D_800A58C8, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A6120 = { D_800A5E54, D_800A58E0, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A6134 = { D_800A5E5C, D_800A5904, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A6148 = { D_800A5E64, D_800A591C, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A615C = { D_800A5E6C, D_800A5934, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A6170 = { D_800A5E74, D_800A594C, 0x2F, 6, 555, 474, 7 };
FieldActorEntry D_800A6184 = { D_800A5E7C, D_800A5964, 0x39, 7, 1088, 288, 1 };
FieldActorEntry D_800A6198 = { D_800A5E8C, D_800A59C4, 0x39, 7, 1088, 288, 1 };
FieldActorEntry D_800A61AC = { D_800A5E9C, NULL, 0x39, 7, 1096, 286, 1 };
FieldActorEntry D_800A61C0 = { D_800A5EA4, D_800A5A24, 0x39, 7, 1088, 288, 1 };
FieldActorEntry D_800A61D4 = { D_800A5EB4, D_800A5A84, 0x39, 7, 1088, 288, 1 };
FieldActorEntry D_800A61E8 = { D_800A5EC4, D_800A5AB4, 0x39, 7, 1088, 288, 1 };
FieldActorEntry D_800A61FC = { D_800A5ED4, D_800A5ACC, 0x9D, 8, 1088, 288, 1 };
FieldActorEntry D_800A6210 = { D_800A5EDC, D_800A5B2C, 0x9E, 9, 555, 474, 7 };
FieldActorEntry D_800A6224 = { D_800A5EE4, D_800A5B44, 0x9F, 0xA, 564, 558, 5 };
FieldActorEntry D_800A6238 = { D_800A5EEC, D_800A5B5C, 0xB2, 0xB, 305, 616, 1 };
FieldActorEntry D_800A624C = { D_800A5EF8, D_800A5B80, 0x16D, 0xC, 719, 235, 7 };
FieldActorEntry D_800A6260 = { D_800A5F00, D_800A5B98, 0x16D, 0xC, 719, 235, 7 };
FieldActorEntry D_800A6274 = { D_800A5F08, D_800A5BB0, 0x16D, 0xC, 719, 235, 7 };
FieldActorEntry D_800A6288 = { D_800A5F10, D_800A5BC8, 0x16D, 0xC, 719, 235, 7 };
FieldActorEntry D_800A629C = { D_800A5F18, D_800A5BE0, 0x16D, 0xC, 719, 235, 7 };
FieldActorEntry D_800A62B0 = { D_800A5F20, D_800A5BF8, 0x16D, 0xC, 719, 235, 7 };
FieldActorEntry D_800A62C4 = { D_800A5F28, D_800A5C10, 0x16D, 0xC, 464, 640, 1 };
FieldActorEntry D_800A62D8 = { D_800A5F30, D_800A5C28, 0x16D, 0xC, 719, 235, 7 };
FieldActorEntry D_800A62EC = { D_800A5F38, D_800A5C40, 0x16D, 0xC, 719, 235, 7 };
FieldActorEntry D_800A6300 = { D_800A5F40, D_800A5C58, 0x16D, 0xC, 719, 235, 7 };
FieldActorEntry D_800A6314 = { D_800A5F48, D_800A5C70, 0x16D, 0xC, 719, 235, 7 };
FieldActorEntry D_800A6328 = { D_800A5F50, D_800A5C88, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A633C = { D_800A5F58, D_800A5CA0, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A6350 = { D_800A5F60, D_800A5CB8, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A6364 = { D_800A5F68, D_800A5CD0, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A6378 = { D_800A5F70, D_800A5CE8, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A638C = { D_800A5F80, D_800A5D00, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A63A0 = { D_800A5F88, D_800A5D18, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A63B4 = { D_800A5F90, D_800A5D3C, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A63C8 = { D_800A5F98, D_800A5D54, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A63DC = { D_800A5FA0, D_800A5D6C, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A63F0 = { D_800A5FA8, D_800A5D84, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry D_800A6404 = { D_800A5FB0, D_800A5D9C, 0x173, 0xD, 595, 542, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5FB8,
    &D_800A5FCC,
    &D_800A5FE0,
    &D_800A5FF4,
    &D_800A6008,
    &D_800A601C,
    &D_800A6030,
    &D_800A6044,
    &D_800A6058,
    &D_800A606C,
    &D_800A6080,
    &D_800A6094,
    &D_800A60A8,
    &D_800A60BC,
    &D_800A60D0,
    &D_800A60E4,
    &D_800A60F8,
    &D_800A610C,
    &D_800A6120,
    &D_800A6134,
    &D_800A6148,
    &D_800A615C,
    &D_800A6170,
    &D_800A6184,
    &D_800A6198,
    &D_800A61AC,
    &D_800A61C0,
    &D_800A61D4,
    &D_800A61E8,
    &D_800A61FC,
    &D_800A6210,
    &D_800A6224,
    &D_800A6238,
    &D_800A624C,
    &D_800A6260,
    &D_800A6274,
    &D_800A6288,
    &D_800A629C,
    &D_800A62B0,
    &D_800A62C4,
    &D_800A62D8,
    &D_800A62EC,
    &D_800A6300,
    &D_800A6314,
    &D_800A6328,
    &D_800A633C,
    &D_800A6350,
    &D_800A6364,
    &D_800A6378,
    &D_800A638C,
    &D_800A63A0,
    &D_800A63B4,
    &D_800A63C8,
    &D_800A63DC,
    &D_800A63F0,
    &D_800A6404,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x47, 2, 0, 3, 6, 0, 1048, 211, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 3, 6, 0, 437, 437, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 3, 6, 0, 533, 389, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 3, 6, 0, 1231, 344, 0, 0 },
    { 1, 0, 0x40, 2, 0x4A, 2, 0, 3, 6, 0, 623, 331, 0, 0 },
    { 1, 0, 0x40, 2, 0x10, 0, 0, 0, 0, 0, 268, 384, 0, 0 },
    { 1, 0, 0x48, 2, 0x11, 0, 0, 0, 0, 0, 274, 440, 0, 0 },
    { 1, 0, 0x40, 2, 0x12, 0, 0, 0, 0, 0, 1044, 416, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 1088, 384, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 1, 0xA, 0xF, 8, 0, 123, 518, 0, 0 },
    { 1, 0, 0x40, 2, 0xA, 1, 0xA, 0xF, 8, 0, 355, 626, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 3, 6, 0, 430, 722, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 3, 6, 0, 501, 687, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 3, 6, 0, 945, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 3, 6, 0, 1096, 700, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 3, 6, 0, 1142, 723, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 483, 414, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 597, 695, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 642, 672, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 3, 6, 0, 754, 617, 0, 0 },
    { 1, 0, 0x40, 6, 0x49, 2, 0, 3, 6, 0, 1023, 463, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 3, 6, 0, 669, 308, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 379, 807, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 503, 863, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 888, 683, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 940, 652, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 982, 613, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1028, 842, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1049, 728, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1205, 438, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1250, 795, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 252, 805, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 962, 641, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 997, 616, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1013, 582, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1055, 570, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1111, 806, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1117, 352, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1168, 791, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 207, 510, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 277, 265, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 375, 819, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 473, 878, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 539, 844, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 903, 771, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 982, 769, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1027, 745, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1054, 560, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1066, 878, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1075, 817, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1151, 788, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1197, 422, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 99, 649, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 340, 734, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 372, 865, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 562, 848, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 866, 606, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 929, 659, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1025, 722, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1032, 734, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1058, 835, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1240, 804, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 210, 645, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 455, 793, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 845, 597, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 915, 647, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1005, 702, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1183, 406, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 225, 814, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 235, 656, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 322, 260, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 353, 809, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 399, 780, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 425, 874, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 887, 617, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1004, 681, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1014, 762, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1059, 824, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1076, 720, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1077, 565, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1161, 394, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1217, 795, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 43, 657, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 124, 617, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 182, 805, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 192, 797, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 212, 468, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 217, 460, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 298, 247, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 396, 858, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 656, 802, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 678, 794, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 835, 638, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 850, 713, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 852, 699, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 866, 656, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 867, 705, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 876, 648, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 895, 628, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 925, 783, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 955, 784, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1012, 665, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1027, 656, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1040, 832, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1051, 411, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1061, 414, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1064, 754, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1075, 725, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1119, 793, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1279, 782, 0, 0 },
    { 1, 0x64, 0x40, 6, 0x18, 0, 0, 0, 0, 0, 1045, 458, 0, 0 },
    { 1, 0x65, 0x40, 6, 0x17, 0, 0, 0, 0, 0, 638, 321, 0, 0 },
    { 1, 0x66, 0x40, 6, 0x14, 0, 0, 0, 0, 0, 277, 489, 0, 0 },
    { 1, 0x67, 0x40, 6, 0x15, 0, 0, 0, 0, 0, 446, 416, 0, 0 },
    { 1, 0x68, 0x40, 6, 0x16, 0, 0, 0, 0, 0, 542, 367, 0, 0 },
    { 1, 0, 0x68, 6, 6, 1, 6, 8, 4, 0, 879, 428, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4B, 1, 0x4B, 0x4E, 6, 0, 241, 396, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4F, 1, 0x4F, 0x52, 6, 0, 226, 450, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x53, 1, 0x53, 0x56, 6, 0, 1091, 316, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x57, 1, 0x57, 0x5A, 6, 0, 1103, 338, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 303, 495, 544, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 409, 416, 472, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 510, 375, 423, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 609, 327, 375, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 1051, 192, 246, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 1073, 463, 512, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0x7007, 0 }, { 0xFFFF, 0 } }, 1, 0x202, 0x308, 0xE0, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20F, 0xE0, 0x14E, 5, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20D, 0x178, 0x19C, 3, 0x67, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20D, 0x218, 0x14C, 3, 0x68, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20A, 0x116, 0xDA, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x203, 0x60, 0x190, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x206, 0xD8, 0x178, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 50, D_800A4F5C, EVENT_TEXT(0xB), NULL, func_800A4D9C },
    { 52, D_800A5008, EVENT_TEXT(0xC), NULL, func_800A4DE8 },
    { -1, NULL, 0, NULL, NULL },
};
