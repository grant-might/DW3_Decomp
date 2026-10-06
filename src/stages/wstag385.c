#include "common.h"
#include "stage.h"
const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (FLAGS_00.checkCondition(0x402D, 1) && FLAGS_00.checkCondition(0x402E, 0)) {
            children[0] = FIELDSTG_startEvent(0x4FC);
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
    FLAGS_00.applyAction(0x402D, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4DF0(void) {
    FLAGS_00.applyAction(0x402E, 1);
    FLAGS_00.applyAction(0x8168, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x4E8
#define STAGE_FILE_8 0x503
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x4F8
#define STAGE_FILE_8 0x513
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE_8;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 1;
    D_800990B4.start = (Vec2){0x3C500, 0x3D200};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xA;
    D_800990B4.music = 0x60280000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern Battle D_800A53CC;
extern Battle D_800A53D8;
extern Battle D_800A53E4;
extern Battle D_800A53F0;
extern Battle D_800A53FC;
extern Battle D_800A5408;
extern Battle D_800A5414;
extern Battle D_800A5420;
extern Battle D_800A5450;
extern Battle D_800A545C;
extern Battle D_800A5468;
extern Battle D_800A5474;
extern Battle D_800A5480;
extern Battle D_800A548C;
extern Battle D_800A5498;
extern Battle D_800A54A4;
extern Battle D_800A54D4;
extern Battle D_800A54E0;
extern Battle D_800A54EC;
extern Battle D_800A54F8;
extern Battle D_800A5504;
extern Battle D_800A5510;
extern Battle D_800A551C;
extern Battle D_800A5528;
extern Battle D_800A5558;
extern Battle D_800A5564;
extern Battle D_800A5570;
extern Battle D_800A557C;
extern Battle D_800A5588;
extern Battle D_800A5594;
extern Battle D_800A55A0;
extern Battle D_800A55AC;
extern BattleList D_800A542C;
extern BattleList D_800A54B0;
extern BattleList D_800A5534;
extern BattleList D_800A55B8;
extern u16 D_800A5778[];
extern u16 D_800A5784[];
extern u16 D_800A5790[];
extern u16 D_800A5798[];
extern u16 D_800A57A8[];
extern u16 D_800A57B0[];
extern u16 D_800A57C0[];
extern u16 D_800A57D0[];
extern u16 D_800A57DC[];
extern u16 D_800A57E8[];
extern u16 D_800A57F0[];
extern u16 D_800A5800[];
extern u16 D_800A5808[];
extern u16 D_800A5818[];
extern u16 D_800A5844[];
extern u16 D_800A584C[];
extern u16 D_800A5858[];
extern u16 D_800A5860[];
extern u16 D_800A586C[];
extern u16 D_800A5878[];
extern u16 D_800A5880[];
extern u16 D_800A5890[];
extern u16 D_800A5898[];
extern u16 D_800A58A8[];
extern u16 D_800A58BC[];
extern u16 D_800A58C8[];
extern u16 D_800A58D4[];
extern u16 D_800A58DC[];
extern u16 D_800A58EC[];
extern u16 D_800A58F4[];
extern u16 D_800A5904[];
extern u16 D_800A5918[];
extern u16 D_800A5924[];
extern u16 D_800A5930[];
extern u16 D_800A5938[];
extern u16 D_800A5948[];
extern u16 D_800A5950[];
extern u16 D_800A5960[];
extern u16 D_800A5974[];
extern u16 D_800A5980[];
extern u16 D_800A598C[];
extern u16 D_800A5994[];
extern u16 D_800A59A4[];
extern u16 D_800A59AC[];
extern u16 D_800A59BC[];
extern u16 D_800A59D0[];
extern u16 D_800A59DC[];
extern u16 D_800A59E8[];
extern u16 D_800A59F0[];
extern u16 D_800A5A00[];
extern u16 D_800A5A08[];
extern u16 D_800A5A18[];
extern u16 D_800A5A2C[];
extern u16 D_800A5A38[];
extern u16 D_800A5A44[];
extern u16 D_800A5A4C[];
extern u16 D_800A5A5C[];
extern u16 D_800A5A64[];
extern u16 D_800A5A74[];
extern u16 D_800A5A88[];
extern u16 D_800A5A94[];
extern u16 D_800A5AA0[];
extern u16 D_800A5AA8[];
extern u16 D_800A5AB8[];
extern u16 D_800A5AC0[];
extern u16 D_800A5AD0[];
extern u16 D_800A5AE4[];
extern u16 D_800A5AF0[];
extern u16 D_800A5AFC[];
extern u16 D_800A5B04[];
extern u16 D_800A5B14[];
extern u16 D_800A5B1C[];
extern u16 D_800A5B2C[];
extern u16 D_800A5B40[];
extern u16 D_800A5B4C[];
extern u16 D_800A5B58[];
extern u16 D_800A5B60[];
extern u16 D_800A5B70[];
extern u16 D_800A5B78[];
extern u16 D_800A5B88[];
extern u16 D_800A5B9C[];
extern u16 D_800A5BA8[];
extern u16 D_800A5BB4[];
extern u16 D_800A5BBC[];
extern u16 D_800A5BCC[];
extern u16 D_800A5BD4[];
extern u16 D_800A5BE4[];
extern u16 D_800A5FDC[];
extern u16 D_800A5FE4[];
extern FieldTalk D_800A5BF8[];
extern u16 D_800A5FEC[];
extern FieldTalk D_800A5C10[];
extern u16 D_800A5FF4[];
extern FieldTalk D_800A5C28[];
extern u16 D_800A5FFC[];
extern FieldTalk D_800A5C40[];
extern u16 D_800A6004[];
extern FieldTalk D_800A5C58[];
extern u16 D_800A600C[];
extern FieldTalk D_800A5C70[];
extern u16 D_800A6014[];
extern FieldTalk D_800A5C88[];
extern u16 D_800A601C[];
extern FieldTalk D_800A5CA0[];
extern u16 D_800A6024[];
extern FieldTalk D_800A5CB8[];
extern u16 D_800A602C[];
extern FieldTalk D_800A5CF4[];
extern u16 D_800A6034[];
extern FieldTalk D_800A5D30[];
extern u16 D_800A6040[];
extern FieldTalk D_800A5D54[];
extern u16 D_800A604C[];
extern FieldTalk D_800A5D90[];
extern u16 D_800A6058[];
extern FieldTalk D_800A5DCC[];
extern u16 D_800A6064[];
extern FieldTalk D_800A5E08[];
extern u16 D_800A6070[];
extern FieldTalk D_800A5E44[];
extern u16 D_800A607C[];
extern FieldTalk D_800A5E80[];
extern u16 D_800A6088[];
extern FieldTalk D_800A5EBC[];
extern u16 D_800A6094[];
extern FieldTalk D_800A5EF8[];
extern u16 D_800A60A0[];
extern FieldTalk D_800A5F34[];
extern u16 D_800A60AC[];
extern FieldTalk D_800A5F70[];
extern u16 D_800A60B8[];
extern FieldTalk D_800A5FAC[];
extern u16 D_800A60C0[];
extern FieldTalk D_800A5FC4[];
extern FieldActorEntry D_800A60C8;
extern FieldActorEntry D_800A60DC;
extern FieldActorEntry D_800A60F0;
extern FieldActorEntry D_800A6104;
extern FieldActorEntry D_800A6118;
extern FieldActorEntry D_800A612C;
extern FieldActorEntry D_800A6140;
extern FieldActorEntry D_800A6154;
extern FieldActorEntry D_800A6168;
extern FieldActorEntry D_800A617C;
extern FieldActorEntry D_800A6190;
extern FieldActorEntry D_800A61A4;
extern FieldActorEntry D_800A61B8;
extern FieldActorEntry D_800A61CC;
extern FieldActorEntry D_800A61E0;
extern FieldActorEntry D_800A61F4;
extern FieldActorEntry D_800A6208;
extern FieldActorEntry D_800A621C;
extern FieldActorEntry D_800A6230;
extern FieldActorEntry D_800A6244;
extern FieldActorEntry D_800A6258;
extern FieldActorEntry D_800A626C;
extern FieldActorEntry D_800A6280;
extern FieldActorEntry D_800A6294;
extern s16 D_800A4F54[];
extern s16 D_800A4FC4[];
extern s16 D_800A5048[];
extern s16 D_800A50E4[];
extern s16 D_800A5188[];
extern s16 D_800A5200[];
extern s16 D_800A5278[];
extern s16 D_800A52F0[];

s16 D_800A4F54[] = {
    0x600, 1, 2,
    0x102, 2, 0xBB, 0x406, 1,
    0x100, 0x64, 0x9B, 0x416,
    0x101, 0x64, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 0x64, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A4FC4[] = {
    0x600, 1, 2,
    0x100, 2, 0xBB, 0x406,
    0x101, 2, 1, 1,
    0x100, 0x64, 0x9B, 0x416,
    0x101, 0x64, 1, 5,
    0x300, 0x78,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 0x64, 3,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x3C,
    0,
};
s16 D_800A5048[] = {
    0x102, 2, 0x1F7, 0x214, 3,
    0x100, 0x142, 0x1E0, 0x209,
    0x101, 0x142, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x142, 1, 3,
    0x300, 0x1E,
    0x102, 0x142, 0x1D5, 0x202, 3,
    0x302, 0x142,
    0x101, 0x142, 1, 3,
    0x300, 0x1E,
    0x101, 0x142, 1, 5,
    0x300, 0x1E,
    0x102, 0x142, 0x1F8, 0x1F0, 5,
    0x302, 0x142,
    0x101, 0x142, 1, 5,
    0x300, 0x1E,
    0x101, 0x142, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0x142, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A50E4[] = {
    0x102, 2, 0x191, 0x1E1, 1,
    0x100, 0x141, 0x177, 0x1ED,
    0x101, 0x141, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 0x141, 1, 1,
    0x300, 0x1E,
    0x102, 0x141, 0x165, 0x1F5, 1,
    0x302, 0x141,
    0x101, 0x141, 1, 1,
    0x300, 0x1E,
    0x101, 0x141, 1, 3,
    0x300, 0x1E,
    0x102, 0x141, 0x141, 0x1E5, 3,
    0x302, 0x141,
    0x101, 0x141, 1, 3,
    0x101, 0x141, 1, 3,
    0x300, 0x1E,
    0x101, 0x141, 1, 7,
    0x300, 0x1E,
    0x200, 0, 1, 0x141, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5188[] = {
    0x102, 2, 0x128, 0x1FC, 3,
    0x100, 0x140, 0x110, 0x1F1,
    0x101, 0x140, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x140, 1, 3,
    0x300, 0x1E,
    0x102, 0x140, 0xCC, 0x1CE, 3,
    0x302, 0x140,
    0x101, 0x140, 1, 3,
    0x300, 0x1E,
    0x101, 0x140, 1, 7,
    0x300, 0x1E,
    0x200, 0, 1, 0x140, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5200[] = {
    0x102, 2, 0x140, 0x180, 3,
    0x100, 0x128, 0x129, 0x175,
    0x101, 0x128, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x128, 1, 5,
    0x300, 0x1E,
    0x102, 0x128, 0x155, 0x15D, 5,
    0x302, 0x128,
    0x101, 0x128, 1, 5,
    0x300, 0x1E,
    0x101, 0x128, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0x128, 3,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5278[] = {
    0x102, 2, 0xF0, 0x118, 3,
    0x100, 0x127, 0xD8, 0x10D,
    0x101, 0x127, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x127, 1, 5,
    0x300, 0x1E,
    0x102, 0x127, 0x104, 0xF7, 5,
    0x302, 0x127,
    0x101, 0x127, 1, 5,
    0x300, 0x1E,
    0x101, 0x127, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 0x127, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A52F0[] = {
    0x102, 2, 0xB7, 0xBD, 3,
    0x100, 0x63, 0x9F, 0xB1,
    0x101, 0x63, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x300, 0x1E,
    0x200, 0, 1, 0x63, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x63, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0x63, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x102, 2, 0xBF, 0xC1, 7,
    0x302, 2,
    0x304, 0x228, 0x250, 0x278, 7,
    0,
};
Battle D_800A53CC = { 0, 0, 0x60040000 };
Battle D_800A53D8 = { 0, 0, 0x60040000 };
Battle D_800A53E4 = { 0, 0, 0x60040000 };
Battle D_800A53F0 = { 0, 0, 0x60040000 };
Battle D_800A53FC = { 0, 0, 0x60040000 };
Battle D_800A5408 = { 0, 0, 0x60040000 };
Battle D_800A5414 = { 0, 0, 0x60040000 };
Battle D_800A5420 = { 0, 0, 0x60040000 };
BattleList D_800A542C = {
    3,
    { &D_800A53CC, &D_800A53D8, &D_800A53E4, &D_800A53F0,
      &D_800A53FC, &D_800A5408, &D_800A5414, &D_800A5420 },
};
Battle D_800A5450 = { 0, 0, 0x60040000 };
Battle D_800A545C = { 0, 0, 0x60040000 };
Battle D_800A5468 = { 0, 0, 0x60040000 };
Battle D_800A5474 = { 0, 0, 0x60040000 };
Battle D_800A5480 = { 0, 0, 0x60040000 };
Battle D_800A548C = { 0, 0, 0x60040000 };
Battle D_800A5498 = { 0, 0, 0x60040000 };
Battle D_800A54A4 = { 0, 0, 0x60040000 };
BattleList D_800A54B0 = {
    0,
    { &D_800A5450, &D_800A545C, &D_800A5468, &D_800A5474,
      &D_800A5480, &D_800A548C, &D_800A5498, &D_800A54A4 },
};
Battle D_800A54D4 = { 0, 0, 0x60040000 };
Battle D_800A54E0 = { 0, 0, 0x60040000 };
Battle D_800A54EC = { 0, 0, 0x60040000 };
Battle D_800A54F8 = { 0, 0, 0x60040000 };
Battle D_800A5504 = { 0, 0, 0x60040000 };
Battle D_800A5510 = { 0, 0, 0x60040000 };
Battle D_800A551C = { 0, 0, 0x60040000 };
Battle D_800A5528 = { 0, 0, 0x60040000 };
BattleList D_800A5534 = {
    0,
    { &D_800A54D4, &D_800A54E0, &D_800A54EC, &D_800A54F8,
      &D_800A5504, &D_800A5510, &D_800A551C, &D_800A5528 },
};
Battle D_800A5558 = { 270, 19, 0x60880000 };
Battle D_800A5564 = { 0, 0, 0x60040000 };
Battle D_800A5570 = { 0, 0, 0x60040000 };
Battle D_800A557C = { 0, 0, 0x60040000 };
Battle D_800A5588 = { 0, 0, 0x60040000 };
Battle D_800A5594 = { 0, 0, 0x60040000 };
Battle D_800A55A0 = { 0, 0, 0x60040000 };
Battle D_800A55AC = { 0, 0, 0x60040000 };
BattleList D_800A55B8 = {
    0,
    { &D_800A5558, &D_800A5564, &D_800A5570, &D_800A557C,
      &D_800A5588, &D_800A5594, &D_800A55A0, &D_800A55AC },
};
FieldBattles stageBattles[] = {
    { 169, 0, 0, { &D_800A542C, &D_800A54B0, &D_800A5534, &D_800A55B8 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1AC, 0x100, 0x1B0, 0, 0x170, 0x1F8 },
    { 0x180, 0x100, 0x1AC, 0x130, 0x1B0, 0x30, 0x140, 0x1F7 },
    { 0x180, 0x100, 0x1AC, 0x160, 0x1B0, 0x60, 0x150, 0x1F7 },
    { 0x180, 0x100, 0x180, 0x178, 0x100, 0x78, 0x170, 0x1F7 },
    { 0x180, 0x100, 0x18A, 0x178, 0x128, 0x78, 0x140, 0x1F6 },
    { 0x180, 0x100, 0x194, 0x178, 0x150, 0x78, 0x150, 0x1F6 },
    { 0x180, 0x100, 0x19E, 0x178, 0x178, 0x78, 0x170, 0x1F6 },
    { 0x140, 0x100, 0x16A, 0x1C5, 0xA8, 0xC5, 0x140, 0x1F5 },
    { 0x180, 0x100, 0x1B6, 0x100, 0x1D8, 0, 0x150, 0x1F5 },
    { 0x180, 0x100, 0x1B2, 0x1C0, 0x1C8, 0xC0, 0x170, 0x1F5 },
    { 0x140, 0x100, 0x172, 0x1B3, 0xC8, 0xB3, 0x140, 0x1F4 },
    { 0x180, 0x100, 0x1A8, 0x190, 0x1A0, 0x90, 0x150, 0x1F4 },
    { 0x180, 0x100, 0x1B2, 0x190, 0x1C8, 0x90, 0x170, 0x1F4 },
    { 0x180, 0x100, 0x180, 0x1A8, 0x100, 0xA8, 0x140, 0x1F3 },
    { 0x180, 0x100, 0x18A, 0x1A8, 0x128, 0xA8, 0x150, 0x1F3 },
    { 0x180, 0x100, 0x194, 0x1A8, 0x150, 0xA8, 0x160, 0x1F3 },
    { 0x180, 0x100, 0x19E, 0x1A8, 0x178, 0xA8, 0x170, 0x1F3 },
    { 0x180, 0x100, 0x1A8, 0x1C0, 0x1A0, 0xC0, 0x140, 0x1F2 },
};
u16 D_800A5778[] = { 0x11, 0, 0x1C55, 1, 0xFFFF };
u16 D_800A5784[] = { 0x11, 0, 0x1C55, 0, 0xFFFF };
u16 D_800A5790[] = { 0x780A, 1, 0xFFFF };
u16 D_800A5798[] = { 0x11, 1, 0x10, 0, 0x1C55, 0, 0xFFFF };
u16 D_800A57A8[] = { 0x11, 0, 0xFFFF };
u16 D_800A57B0[] = { 0x11, 1, 0x10, 1, 0x1C55, 0, 0xFFFF };
u16 D_800A57C0[] = { 0x11, 0, 0x10, 0, 0x1C55, 1, 0xFFFF };
u16 D_800A57D0[] = { 0x1C53, 1, 0x11, 0, 0xFFFF };
u16 D_800A57DC[] = { 0x11, 0, 0x1C53, 0, 0xFFFF };
u16 D_800A57E8[] = { 0x760A, 1, 0xFFFF };
u16 D_800A57F0[] = { 0x11, 1, 0x10, 0, 0x1C53, 0, 0xFFFF };
u16 D_800A5800[] = { 0x11, 0, 0xFFFF };
u16 D_800A5808[] = { 0x11, 1, 0x10, 1, 0x1C53, 0, 0xFFFF };
u16 D_800A5818[] = {
    0x11, 0, 0x10, 0, 0x8012, 1, 0x1C53, 1,
    0x1A3B, 0, 0x1A3A, 0, 0x1A39, 0, 0x1A38, 0,
    0x1A37, 0, 0x906B, 1, 0xFFFF,
};
u16 D_800A5844[] = { 0x1C17, 0, 0xFFFF };
u16 D_800A584C[] = { 0x902A, 1, 0x1C17, 1, 0xFFFF };
u16 D_800A5858[] = { 0x1C17, 1, 0xFFFF };
u16 D_800A5860[] = { 0x11, 0, 0x1A3B, 1, 0xFFFF };
u16 D_800A586C[] = { 0x11, 0, 0x1A3B, 0, 0xFFFF };
u16 D_800A5878[] = { 0x760B, 1, 0xFFFF };
u16 D_800A5880[] = { 0x1A3B, 0, 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A5890[] = { 0x11, 0, 0xFFFF };
u16 D_800A5898[] = { 0x11, 1, 0x10, 1, 0x1A3B, 0, 0xFFFF };
u16 D_800A58A8[] = { 0x11, 0, 0x10, 0, 0x9054, 1, 0x1A3B, 1, 0xFFFF };
u16 D_800A58BC[] = { 0x11, 0, 0x1A3B, 1, 0xFFFF };
u16 D_800A58C8[] = { 0x11, 0, 0x1A3B, 0, 0xFFFF };
u16 D_800A58D4[] = { 0x780B, 1, 0xFFFF };
u16 D_800A58DC[] = { 0x11, 1, 0x10, 0, 0x1A3B, 0, 0xFFFF };
u16 D_800A58EC[] = { 0x11, 0, 0xFFFF };
u16 D_800A58F4[] = { 0x11, 1, 0x10, 1, 0x1A3B, 0, 0xFFFF };
u16 D_800A5904[] = { 0x11, 0, 0x10, 0, 0x9054, 1, 0x1A3B, 1, 0xFFFF };
u16 D_800A5918[] = { 0x11, 0, 0x1A3A, 1, 0xFFFF };
u16 D_800A5924[] = { 0x11, 0, 0x1A3A, 0, 0xFFFF };
u16 D_800A5930[] = { 0x760C, 1, 0xFFFF };
u16 D_800A5938[] = { 0x11, 1, 0x10, 0, 0x1A3A, 0, 0xFFFF };
u16 D_800A5948[] = { 0x11, 0, 0xFFFF };
u16 D_800A5950[] = { 0x11, 1, 0x10, 1, 0x1A3A, 0, 0xFFFF };
u16 D_800A5960[] = { 0x11, 0, 0x10, 0, 0x9053, 1, 0x1A3A, 1, 0xFFFF };
u16 D_800A5974[] = { 0x11, 0, 0x1A3A, 1, 0xFFFF };
u16 D_800A5980[] = { 0x11, 0, 0x1A3A, 0, 0xFFFF };
u16 D_800A598C[] = { 0x780C, 1, 0xFFFF };
u16 D_800A5994[] = { 0x11, 1, 0x10, 0, 0x1A3A, 0, 0xFFFF };
u16 D_800A59A4[] = { 0x11, 0, 0xFFFF };
u16 D_800A59AC[] = { 0x11, 1, 0x10, 1, 0x1A3A, 0, 0xFFFF };
u16 D_800A59BC[] = { 0x11, 0, 0x10, 0, 0x9053, 1, 0x1A3A, 1, 0xFFFF };
u16 D_800A59D0[] = { 0x11, 0, 0x1A39, 1, 0xFFFF };
u16 D_800A59DC[] = { 0x11, 0, 0x1A39, 0, 0xFFFF };
u16 D_800A59E8[] = { 0x760D, 1, 0xFFFF };
u16 D_800A59F0[] = { 0x11, 1, 0x10, 0, 0x1A39, 0, 0xFFFF };
u16 D_800A5A00[] = { 0x11, 0, 0xFFFF };
u16 D_800A5A08[] = { 0x10, 1, 0x1A39, 0, 0x11, 1, 0xFFFF };
u16 D_800A5A18[] = { 0x11, 0, 0x10, 0, 0x9052, 1, 0x1A39, 1, 0xFFFF };
u16 D_800A5A2C[] = { 0x11, 0, 0x1A39, 1, 0xFFFF };
u16 D_800A5A38[] = { 0x11, 0, 0x1A39, 0, 0xFFFF };
u16 D_800A5A44[] = { 0x780D, 1, 0xFFFF };
u16 D_800A5A4C[] = { 0x11, 1, 0x10, 0, 0x1A39, 0, 0xFFFF };
u16 D_800A5A5C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5A64[] = { 0x11, 1, 0x10, 1, 0x1A39, 0, 0xFFFF };
u16 D_800A5A74[] = { 0x11, 0, 0x10, 0, 0x9052, 1, 0x1A39, 1, 0xFFFF };
u16 D_800A5A88[] = { 0x11, 0, 0x1A38, 1, 0xFFFF };
u16 D_800A5A94[] = { 0x11, 0, 0x1A38, 0, 0xFFFF };
u16 D_800A5AA0[] = { 0x760E, 1, 0xFFFF };
u16 D_800A5AA8[] = { 0x11, 1, 0x10, 0, 0x1A38, 0, 0xFFFF };
u16 D_800A5AB8[] = { 0x11, 0, 0xFFFF };
u16 D_800A5AC0[] = { 0x11, 1, 0x1A38, 0, 0x10, 1, 0xFFFF };
u16 D_800A5AD0[] = { 0x10, 0, 0x9051, 1, 0x1A38, 1, 0x11, 0, 0xFFFF };
u16 D_800A5AE4[] = { 0x11, 0, 0x1A38, 1, 0xFFFF };
u16 D_800A5AF0[] = { 0x11, 0, 0x1A38, 0, 0xFFFF };
u16 D_800A5AFC[] = { 0x780E, 1, 0xFFFF };
u16 D_800A5B04[] = { 0x11, 1, 0x10, 0, 0x1A38, 0, 0xFFFF };
u16 D_800A5B14[] = { 0x11, 0, 0xFFFF };
u16 D_800A5B1C[] = { 0x11, 1, 0x10, 1, 0x1A38, 0, 0xFFFF };
u16 D_800A5B2C[] = { 0x11, 0, 0x10, 0, 0x9051, 1, 0x1A38, 1, 0xFFFF };
u16 D_800A5B40[] = { 0x11, 0, 0x1A37, 1, 0xFFFF };
u16 D_800A5B4C[] = { 0x11, 0, 0x1A37, 0, 0xFFFF };
u16 D_800A5B58[] = { 0x760F, 1, 0xFFFF };
u16 D_800A5B60[] = { 0x11, 1, 0x10, 0, 0x1A37, 0, 0xFFFF };
u16 D_800A5B70[] = { 0x11, 0, 0xFFFF };
u16 D_800A5B78[] = { 0x11, 1, 0x10, 1, 0x1A37, 0, 0xFFFF };
u16 D_800A5B88[] = { 0x11, 0, 0x10, 0, 0x9050, 1, 0x1A37, 1, 0xFFFF };
u16 D_800A5B9C[] = { 0x1A37, 1, 0x11, 0, 0xFFFF };
u16 D_800A5BA8[] = { 0x11, 0, 0x1A37, 0, 0xFFFF };
u16 D_800A5BB4[] = { 0x780F, 1, 0xFFFF };
u16 D_800A5BBC[] = { 0x11, 1, 0x10, 0, 0x1A37, 0, 0xFFFF };
u16 D_800A5BCC[] = { 0x11, 0, 0xFFFF };
u16 D_800A5BD4[] = { 0x11, 1, 0x10, 1, 0x1A37, 0, 0xFFFF };
u16 D_800A5BE4[] = { 0x11, 0, 0x10, 0, 0x9050, 1, 0x1A37, 1, 0xFFFF };
FieldTalk D_800A5BF8[] = {
    { NULL, NULL, 0x316 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C10[] = {
    { NULL, NULL, 0x316 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C28[] = {
    { NULL, NULL, 0x316 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C40[] = {
    { NULL, NULL, 0x316 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C58[] = {
    { NULL, NULL, 0x316 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C70[] = {
    { NULL, NULL, 0x238 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C88[] = {
    { NULL, NULL, 0x1DD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CA0[] = {
    { NULL, NULL, 0x231 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CB8[] = {
    { D_800A5778, NULL, 0x31A },
    { D_800A5784, D_800A5790, 0x31F },
    { D_800A5798, D_800A57A8, 0x320 },
    { D_800A57B0, D_800A57C0, 0x321 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CF4[] = {
    { D_800A57D0, NULL, 0x31A },
    { D_800A57DC, D_800A57E8, 0x317 },
    { D_800A57F0, D_800A5800, 0x318 },
    { D_800A5808, D_800A5818, 0x319 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D30[] = {
    { D_800A5844, D_800A584C, 0x2C7 },
    { D_800A5858, NULL, 0x2C8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D54[] = {
    { D_800A5860, NULL, 0x316 },
    { D_800A586C, D_800A5878, 0x313 },
    { D_800A5880, D_800A5890, 0x314 },
    { D_800A5898, D_800A58A8, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D90[] = {
    { D_800A58BC, NULL, 0x316 },
    { D_800A58C8, D_800A58D4, 0x313 },
    { D_800A58DC, D_800A58EC, 0x314 },
    { D_800A58F4, D_800A5904, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DCC[] = {
    { D_800A5918, NULL, 0x316 },
    { D_800A5924, D_800A5930, 0x313 },
    { D_800A5938, D_800A5948, 0x314 },
    { D_800A5950, D_800A5960, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E08[] = {
    { D_800A5974, NULL, 0x316 },
    { D_800A5980, D_800A598C, 0x313 },
    { D_800A5994, D_800A59A4, 0x314 },
    { D_800A59AC, D_800A59BC, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E44[] = {
    { D_800A59D0, NULL, 0x316 },
    { D_800A59DC, D_800A59E8, 0x313 },
    { D_800A59F0, D_800A5A00, 0x314 },
    { D_800A5A08, D_800A5A18, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E80[] = {
    { D_800A5A2C, NULL, 0x316 },
    { D_800A5A38, D_800A5A44, 0x313 },
    { D_800A5A4C, D_800A5A5C, 0x314 },
    { D_800A5A64, D_800A5A74, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EBC[] = {
    { D_800A5A88, NULL, 0x316 },
    { D_800A5A94, D_800A5AA0, 0x313 },
    { D_800A5AA8, D_800A5AB8, 0x314 },
    { D_800A5AC0, D_800A5AD0, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EF8[] = {
    { D_800A5AE4, NULL, 0x316 },
    { D_800A5AF0, D_800A5AFC, 0x313 },
    { D_800A5B04, D_800A5B14, 0x314 },
    { D_800A5B1C, D_800A5B2C, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F34[] = {
    { D_800A5B40, NULL, 0x316 },
    { D_800A5B4C, D_800A5B58, 0x313 },
    { D_800A5B60, D_800A5B70, 0x314 },
    { D_800A5B78, D_800A5B88, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F70[] = {
    { D_800A5B9C, NULL, 0x316 },
    { D_800A5BA8, D_800A5BB4, 0x313 },
    { D_800A5BBC, D_800A5BCC, 0x314 },
    { D_800A5BD4, D_800A5BE4, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FAC[] = {
    { NULL, NULL, 0x33C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FC4[] = {
    { NULL, NULL, 0x33C },
    { NULL, NULL, 0 },
};
u16 D_800A5FDC[] = { 0x7093, 1, 0xFFFF };
u16 D_800A5FE4[] = { 0x1A3B, 1, 0xFFFF };
u16 D_800A5FEC[] = { 0x1A3A, 1, 0xFFFF };
u16 D_800A5FF4[] = { 0x1A39, 1, 0xFFFF };
u16 D_800A5FFC[] = { 0x1A38, 1, 0xFFFF };
u16 D_800A6004[] = { 0x1A37, 1, 0xFFFF };
u16 D_800A600C[] = { 0x7093, 1, 0xFFFF };
u16 D_800A6014[] = { 0x7093, 1, 0xFFFF };
u16 D_800A601C[] = { 0x7093, 1, 0xFFFF };
u16 D_800A6024[] = { 0x8012, 1, 0xFFFF };
u16 D_800A602C[] = { 0x8012, 0, 0xFFFF };
u16 D_800A6034[] = { 0x606, 1, 0x8168, 0, 0xFFFF };
u16 D_800A6040[] = { 0x1A3B, 0, 0x8012, 0, 0xFFFF };
u16 D_800A604C[] = { 0x1A3B, 0, 0x8012, 1, 0xFFFF };
u16 D_800A6058[] = { 0x1A3A, 0, 0x8012, 0, 0xFFFF };
u16 D_800A6064[] = { 0x1A3A, 0, 0x8012, 1, 0xFFFF };
u16 D_800A6070[] = { 0x1A39, 0, 0x8012, 0, 0xFFFF };
u16 D_800A607C[] = { 0x1A39, 0, 0x8012, 1, 0xFFFF };
u16 D_800A6088[] = { 0x1A38, 0, 0x8012, 0, 0xFFFF };
u16 D_800A6094[] = { 0x1A38, 0, 0x8012, 1, 0xFFFF };
u16 D_800A60A0[] = { 0x1A37, 0, 0x8012, 0, 0xFFFF };
u16 D_800A60AC[] = { 0x1A37, 0, 0x8012, 1, 0xFFFF };
u16 D_800A60B8[] = { 0x8192, 0, 0xFFFF };
u16 D_800A60C0[] = { 0x8192, 0, 0xFFFF };
FieldActorEntry D_800A60C8 = { D_800A5FDC, NULL, 0x4B, 4, 588, 1083, 1 };
FieldActorEntry D_800A60DC = { D_800A5FE4, D_800A5BF8, 0x5B, 5, 260, 247, 1 };
FieldActorEntry D_800A60F0 = { D_800A5FEC, D_800A5C10, 0x5C, 6, 341, 349, 1 };
FieldActorEntry D_800A6104 = { D_800A5FF4, D_800A5C28, 0x5D, 7, 204, 462, 7 };
FieldActorEntry D_800A6118 = { D_800A5FFC, D_800A5C40, 0x5E, 8, 321, 485, 7 };
FieldActorEntry D_800A612C = { D_800A6004, D_800A5C58, 0x5F, 9, 504, 496, 1 };
FieldActorEntry D_800A6140 = { D_800A600C, D_800A5C70, 0x60, 0xA, 993, 913, 1 };
FieldActorEntry D_800A6154 = { D_800A6014, D_800A5C88, 0x61, 0xB, 769, 209, 1 };
FieldActorEntry D_800A6168 = { D_800A601C, D_800A5CA0, 0x62, 0xC, 929, 417, 1 };
FieldActorEntry D_800A617C = { D_800A6024, D_800A5CB8, 0x63, 0xD, 159, 177, 7 };
FieldActorEntry D_800A6190 = { D_800A602C, D_800A5CF4, 0x63, 0xD, 159, 177, 7 };
FieldActorEntry D_800A61A4 = { D_800A6034, D_800A5D30, 0x64, 0xE, 155, 1046, 7 };
FieldActorEntry D_800A61B8 = { D_800A6040, D_800A5D54, 0x127, 0xF, 216, 269, 7 };
FieldActorEntry D_800A61CC = { D_800A604C, D_800A5D90, 0x127, 0xF, 216, 269, 7 };
FieldActorEntry D_800A61E0 = { D_800A6058, D_800A5DCC, 0x128, 0x10, 297, 373, 7 };
FieldActorEntry D_800A61F4 = { D_800A6064, D_800A5E08, 0x128, 0x10, 297, 373, 7 };
FieldActorEntry D_800A6208 = { D_800A6070, D_800A5E44, 0x140, 0x11, 272, 497, 7 };
FieldActorEntry D_800A621C = { D_800A607C, D_800A5E80, 0x140, 0x11, 272, 497, 7 };
FieldActorEntry D_800A6230 = { D_800A6088, D_800A5EBC, 0x141, 0x12, 375, 493, 7 };
FieldActorEntry D_800A6244 = { D_800A6094, D_800A5EF8, 0x141, 0x12, 375, 493, 7 };
FieldActorEntry D_800A6258 = { D_800A60A0, D_800A5F34, 0x142, 0x13, 480, 521, 7 };
FieldActorEntry D_800A626C = { D_800A60AC, D_800A5F70, 0x142, 0x13, 480, 521, 7 };
FieldActorEntry D_800A6280 = { D_800A60B8, D_800A5FAC, 0x169, 0x14, 501, 549, 7 };
FieldActorEntry D_800A6294 = { D_800A60C0, D_800A5FC4, 0x16A, 0x15, 522, 538, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A60C8,
    &D_800A60DC,
    &D_800A60F0,
    &D_800A6104,
    &D_800A6118,
    &D_800A612C,
    &D_800A6140,
    &D_800A6154,
    &D_800A6168,
    &D_800A617C,
    &D_800A6190,
    &D_800A61A4,
    &D_800A61B8,
    &D_800A61CC,
    &D_800A61E0,
    &D_800A61F4,
    &D_800A6208,
    &D_800A621C,
    &D_800A6230,
    &D_800A6244,
    &D_800A6258,
    &D_800A626C,
    &D_800A6280,
    &D_800A6294,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x47, 2, 0, 5, 8, 0, 85, 81, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 83, 117, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 83, 135, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 91, 113, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 91, 131, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 99, 109, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 99, 127, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 107, 105, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 107, 123, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 115, 101, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 115, 119, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 123, 97, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 123, 115, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 131, 93, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 131, 111, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 139, 89, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 139, 107, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 147, 85, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 147, 103, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 155, 81, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 155, 99, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 163, 77, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 2, 0, 5, 8, 0, 163, 95, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 87, 115, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 87, 133, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 95, 111, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 95, 129, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 103, 107, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 103, 125, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 111, 103, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 111, 121, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 119, 99, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 119, 117, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 127, 95, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 127, 113, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 135, 91, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 135, 109, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 143, 87, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 143, 105, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 151, 83, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 151, 101, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 159, 79, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 159, 97, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 167, 75, 0, 0 },
    { 1, 0, 0x40, 2, 0x49, 2, 0, 5, 8, 0, 167, 93, 0, 0 },
    { 1, 0, 0x40, 2, 0x4A, 2, 0, 7, 4, 0, 103, 201, 0, 0 },
    { 1, 0, 0x40, 2, 0x4B, 2, 0, 7, 4, 0, 105, 205, 0, 0 },
    { 1, 0, 0x80, 2, 1, 0, 0, 0, 0, 0, 768, 128, 0, 0 },
    { 1, 0, 0x45, 2, 2, 0, 0, 0, 0, 0, 880, 156, 0, 0 },
    { 1, 0, 0x78, 2, 3, 0, 0, 0, 0, 0, 896, 256, 0, 0 },
    { 1, 0, 0x55, 2, 4, 0, 0, 0, 0, 0, 984, 299, 0, 0 },
    { 1, 0, 0x33, 2, 5, 0, 0, 0, 0, 0, 278, 813, 0, 0 },
    { 1, 0, 0x1E, 2, 6, 0, 0, 0, 0, 0, 323, 829, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 7, 4, 0, 220, 180, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 7, 4, 0, 232, 138, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 7, 4, 0, 297, 268, 0, 0 },
    { 1, 0, 0x40, 6, 0x4A, 2, 0, 7, 4, 0, 300, 284, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 168, 143, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 220, 184, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 234, 143, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 235, 299, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 280, 241, 0, 0 },
    { 1, 0, 0x40, 6, 0x4B, 2, 0, 7, 4, 0, 300, 270, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 203, 909, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 236, 1022, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 237, 973, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 238, 733, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 273, 861, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 309, 635, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 320, 858, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 396, 960, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 575, 884, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 630, 1071, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 769, 568, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 1138, 909, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 281, 1085, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 320, 983, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 359, 980, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 503, 793, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 657, 718, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 95, 790, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 117, 1016, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 145, 858, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 178, 1068, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 185, 1000, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 212, 747, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 288, 998, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 302, 1076, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 391, 819, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 541, 902, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 773, 705, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 800, 486, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 850, 469, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 967, 574, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 101, 951, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 275, 890, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 461, 890, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 509, 339, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 534, 794, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 600, 441, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 683, 709, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 715, 508, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 874, 539, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 917, 557, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 131, 1058, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 273, 953, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 19, 963, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 106, 1043, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 122, 952, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 249, 923, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 367, 919, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 545, 804, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 582, 430, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 742, 512, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 931, 568, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 1086, 533, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 56, 960, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 117, 787, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 158, 846, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 171, 949, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 216, 834, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 221, 1050, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 227, 1041, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 235, 750, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 280, 713, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 286, 1071, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 287, 1094, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 305, 665, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 332, 909, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 333, 845, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 363, 326, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 378, 309, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 380, 320, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 390, 431, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 391, 981, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 398, 440, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 412, 434, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 430, 770, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 470, 562, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 474, 567, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 499, 344, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 515, 599, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 517, 802, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 526, 345, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 534, 910, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 546, 377, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 591, 852, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 616, 1076, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 622, 1085, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 633, 1077, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 694, 498, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 706, 727, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 775, 559, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 785, 551, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 793, 661, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 797, 555, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 798, 492, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 838, 485, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 916, 780, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 922, 772, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 929, 778, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1026, 1107, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1032, 1114, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1039, 1107, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1047, 546, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1066, 898, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1149, 890, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 1161, 892, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 477, 577, 626, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0xC0, 0xC2, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xCF, 0x106, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x110, 0x12B, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x11F, 0x16E, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x100, 0x192, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0xF1, 0x1D6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x330, 0xEA, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x33F, 0x12E, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x2DE, 0x141, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x2CE, 0x186, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 8, 1 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 8, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1275, D_800A4F54, EVENT_TEXT(0x1E), NULL, func_800A4DA4 },
    { 1276, D_800A4FC4, EVENT_TEXT(0x1F), NULL, func_800A4DF0 },
    { 1421, D_800A5048, EVENT_TEXT(0x27), NULL, NULL },
    { 1423, D_800A50E4, EVENT_TEXT(0x28), NULL, NULL },
    { 1425, D_800A5188, EVENT_TEXT(0x29), NULL, NULL },
    { 1427, D_800A5200, EVENT_TEXT(0x2A), NULL, NULL },
    { 1429, D_800A5278, EVENT_TEXT(0x2B), NULL, NULL },
    { 1431, D_800A52F0, EVENT_TEXT(0x31), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
