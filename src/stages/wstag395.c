#include "common.h"
#include "stage.h"

/* Creates the event object of progress 5 while flag 0x4011 is clear, or else the one of flags 0x1A27 and 0x1A28 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        do {
            if (GAME.progress == 5 && FLAGS_00.checkCondition(0x4011, 0)) {
                children[0] = FIELDSTG_startEvent(0x50);
                break;
            }
            if (FLAGS_00.checkCondition(0x1A27, 1) && FLAGS_00.checkCondition(0x1A28, 0)) {
                children[0] = FIELDSTG_startEvent(0x519);
                break;
            }
        } while (0);
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

void func_800A4DD8(void) {
    FLAGS_00.applyAction(0x4011, 1);
}

/* Applies flag actions 0x8004, 0x1A28 and 0x1C08 (cleared) */
void func_800A4E04(void) {
    FLAGS_00.applyAction(0x8004, 1);
    FLAGS_00.applyAction(0x1A28, 1);
    FLAGS_00.applyAction(0x1C08, 0);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x20C
#define STAGE_ARCHIVE 0x310
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x21B
#define STAGE_ARCHIVE 0x31F
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x30200, 0x23500};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2E;
    D_800990B4.music = 0x60B80000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

void func_800A4E04();
extern Battle D_800A54CC;
extern Battle D_800A54D8;
extern Battle D_800A54E4;
extern Battle D_800A54F0;
extern Battle D_800A54FC;
extern Battle D_800A5508;
extern Battle D_800A5514;
extern Battle D_800A5520;
extern Battle D_800A5550;
extern Battle D_800A555C;
extern Battle D_800A5568;
extern Battle D_800A5574;
extern Battle D_800A5580;
extern Battle D_800A558C;
extern Battle D_800A5598;
extern Battle D_800A55A4;
extern Battle D_800A55D4;
extern Battle D_800A55E0;
extern Battle D_800A55EC;
extern Battle D_800A55F8;
extern Battle D_800A5604;
extern Battle D_800A5610;
extern Battle D_800A561C;
extern Battle D_800A5628;
extern Battle D_800A5658;
extern Battle D_800A5664;
extern Battle D_800A5670;
extern Battle D_800A567C;
extern Battle D_800A5688;
extern Battle D_800A5694;
extern Battle D_800A56A0;
extern Battle D_800A56AC;
extern BattleList D_800A552C;
extern BattleList D_800A55B0;
extern BattleList D_800A5634;
extern BattleList D_800A56B8;
extern u16 D_800A57A8[];
extern u16 D_800A57B8[];
extern u16 D_800A57C0[];
extern u16 D_800A57D0[];
extern u16 D_800A57D8[];
extern u16 D_800A57E0[];
extern u16 D_800A57E8[];
extern u16 D_800A57F0[];
extern u16 D_800A57FC[];
extern u16 D_800A580C[];
extern u16 D_800A5814[];
extern u16 D_800A5828[];
extern u16 D_800A5834[];
extern u16 D_800A584C[];
extern u16 D_800A5868[];
extern u16 D_800A5884[];
extern u16 D_800A588C[];
extern u16 D_800A5894[];
extern u16 D_800A589C[];
extern u16 D_800A58A8[];
extern u16 D_800A58B8[];
extern u16 D_800A58C0[];
extern u16 D_800A58D4[];
extern u16 D_800A58E0[];
extern u16 D_800A58F8[];
extern u16 D_800A5914[];
extern u16 D_800A5930[];
extern u16 D_800A5938[];
extern u16 D_800A5940[];
extern u16 D_800A5948[];
extern u16 D_800A5954[];
extern u16 D_800A5964[];
extern u16 D_800A596C[];
extern u16 D_800A5980[];
extern u16 D_800A598C[];
extern u16 D_800A59A4[];
extern u16 D_800A59C0[];
extern u16 D_800A59DC[];
extern u16 D_800A59E4[];
extern u16 D_800A59EC[];
extern u16 D_800A59F8[];
extern u16 D_800A5A00[];
extern u16 D_800A5A0C[];
extern u16 D_800A5A18[];
extern u16 D_800A5A20[];
extern u16 D_800A5A2C[];
extern u16 D_800A5A3C[];
extern u16 D_800A5A44[];
extern u16 D_800A5A58[];
extern u16 D_800A5A60[];
extern u16 D_800A5A78[];
extern u16 D_800A5A94[];
extern u16 D_800A5AB0[];
extern u16 D_800A5CD4[];
extern u16 D_800A5CDC[];
extern FieldTalk D_800A5AB8[];
extern u16 D_800A5CE4[];
extern FieldTalk D_800A5AD0[];
extern u16 D_800A5CF0[];
extern FieldTalk D_800A5AF4[];
extern u16 D_800A5CFC[];
extern FieldTalk D_800A5B0C[];
extern u16 D_800A5D0C[];
extern FieldTalk D_800A5B6C[];
extern u16 D_800A5D1C[];
extern FieldTalk D_800A5BCC[];
extern u16 D_800A5D2C[];
extern FieldTalk D_800A5C2C[];
extern u16 D_800A5D3C[];
extern FieldTalk D_800A5C5C[];
extern u16 D_800A5D4C[];
extern FieldTalk D_800A5C74[];
extern FieldActorEntry D_800A5D54;
extern FieldActorEntry D_800A5D68;
extern FieldActorEntry D_800A5D7C;
extern FieldActorEntry D_800A5D90;
extern FieldActorEntry D_800A5DA4;
extern FieldActorEntry D_800A5DB8;
extern FieldActorEntry D_800A5DCC;
extern FieldActorEntry D_800A5DE0;
extern FieldActorEntry D_800A5DF4;
extern FieldActorEntry D_800A5E08;
extern s16 D_800A4F78[];
extern s16 D_800A5264[];
extern s16 D_800A5430[];

s16 D_800A4F78[] = {
    0x601, 1, 0x439, 0x103,
    0x100, 1, 0x45E, 0xE9,
    0x101, 1, 1, 1,
    0x100, 2, 0x458, 0xF5,
    0x101, 2, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x102, 1, 0x430, 0x101, 1,
    0x102, 2, 0x439, 0x103, 1,
    0x100, 0xC, 0x393, 0x1A9,
    0x101, 0xC, 1, 5,
    0x302, 2,
    0x101, 1, 1, 1,
    0x101, 2, 1, 1,
    0x102, 0xC, 0x3D4, 0x152, 5,
    0x302, 0xC,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x600, 0, 0xC,
    0x300, 0x5A,
    0x101, 0x323, 0x325, 0xC,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0xC,
    0x300, 0x1E,
    0x200, 0, 1, 0xC, 1,
    0x101, 0xC, 7, 5,
    0x301,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x600, 0, 2,
    0x102, 0xC, 0x3F7, 0x124, 5,
    0x302, 0xC,
    0x102, 0xC, 0x420, 0x10F, 5,
    0x302, 0xC,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x101, 1, 7, 1,
    0x101, 2, 7, 1,
    0x301,
    0x101, 1, 1, 1,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 3, 0xC, 1,
    0x101, 0xC, 7, 5,
    0x301,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 2, 2,
    0x101, 1, 7, 1,
    0x101, 2, 7, 1,
    0x301,
    0x101, 1, 1, 1,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 5, 0xC, 1,
    0x101, 0xC, 7, 5,
    0x301,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x200, 0, 6, 2, 2,
    0x101, 1, 7, 1,
    0x101, 2, 7, 1,
    0x301,
    0x101, 1, 1, 1,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 0xC, 1, 7,
    0x300, 0x1E,
    0x200, 0, 7, 0xC, 1,
    0x101, 0xC, 7, 7,
    0x301,
    0x101, 0xC, 1, 7,
    0x300, 0x1E,
    0x300, 0x5A,
    0x101, 0x323, 0x325, 2,
    0x101, 0x324, 0x325, 0xC,
    0x101, 0x32D, 0x365, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x101, 0x324, 0x326, 0xC,
    0x300, 0x1E,
    0x200, 0, 8, 2, 4,
    0x301,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x200, 0, 9, 0xC, 1,
    0x101, 0xC, 7, 5,
    0x301,
    0x101, 0xC, 1, 1,
    0x300, 0x1E,
    0x102, 0xC, 0x3F7, 0x124, 1,
    0x302, 0xC,
    0x200, 0, 0xA, 2, 2,
    0x101, 1, 7, 1,
    0x101, 2, 7, 1,
    0x301,
    0x101, 1, 1, 1,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 0xC, 0x394, 0x1A9, 1,
    0x302, 0xC,
    0x200, 0, 0xB, 2, 2,
    0x101, 1, 7, 1,
    0x101, 2, 7, 1,
    0x301,
    0x101, 1, 1, 1,
    0x101, 2, 1, 1,
    0x100, 0xC, 0, 0,
    0x101, 0xC, 1, 0,
    0x300, 0x3C,
    0,
};
s16 D_800A5264[] = {
    0x102, 2, 0x5D0, 0x3E8, 5,
    0x101, 0x23, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 0x23, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x23, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0x23,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0x23,
    0x300, 0x1E,
    0x200, 0, 5, 0x23, 2,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 2,
    0x300, 0x5A,
    0x200, 0, 6, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 7, 0x23, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x23, 1, 1,
    0x300, 0x1E,
    0x102, 0x23, 0x610, 0x3E9, 7,
    0x302, 0x23,
    0x101, 2, 1, 7,
    0x102, 0x23, 0x5EF, 0x3F8, 0,
    0x302, 0x23,
    0x102, 0x23, 0x670, 0x438, 7,
    0x302, 0x23,
    0x101, 2, 1, 3,
    0x100, 0x23, 0, 0,
    0x101, 0x23, 1, 0,
    0x300, 0x1E,
    0x200, 0, 8, 2, 2,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x101, 0x323, 0x327, 2,
    0x300, 0x78,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 9, 2, 2,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x102, 2, 0x670, 0x438, 7,
    0x300, 0x3C,
    0x304, 0x22A, 0xEF, 0xE1, 7,
    0,
};
s16 D_800A5430[] = {
    0x100, 2, 0x5CF, 0x3E8,
    0x101, 2, 1, 7,
    0x100, 0x23, 0x5EF, 0x3F8,
    0x101, 0x23, 1, 3,
    0x300, 0x3C,
    0x200, 0, 1, 0x23, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 3, 0x23, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x23, 1, 7,
    0x300, 0x1E,
    0x102, 0x23, 0x670, 0x438, 7,
    0x302, 0x23,
    0x100, 0x23, 0, 0,
    0x101, 0x23, 1, 7,
    0x300, 0x1E,
    0,
};
Battle D_800A54CC = { 42, 1, 0x60080000 };
Battle D_800A54D8 = { 42, 1, 0x60080000 };
Battle D_800A54E4 = { 42, 1, 0x60080000 };
Battle D_800A54F0 = { 42, 1, 0x60080000 };
Battle D_800A54FC = { 43, 1, 0x60080000 };
Battle D_800A5508 = { 43, 1, 0x60080000 };
Battle D_800A5514 = { 43, 1, 0x60080000 };
Battle D_800A5520 = { 43, 1, 0x60080000 };
BattleList D_800A552C = {
    3,
    { &D_800A54CC, &D_800A54D8, &D_800A54E4, &D_800A54F0,
      &D_800A54FC, &D_800A5508, &D_800A5514, &D_800A5520 },
};
Battle D_800A5550 = { 42, 1, 0x60080000 };
Battle D_800A555C = { 42, 1, 0x60080000 };
Battle D_800A5568 = { 42, 1, 0x60080000 };
Battle D_800A5574 = { 42, 1, 0x60080000 };
Battle D_800A5580 = { 43, 1, 0x60080000 };
Battle D_800A558C = { 43, 1, 0x60080000 };
Battle D_800A5598 = { 43, 1, 0x60080000 };
Battle D_800A55A4 = { 43, 1, 0x60080000 };
BattleList D_800A55B0 = {
    1,
    { &D_800A5550, &D_800A555C, &D_800A5568, &D_800A5574,
      &D_800A5580, &D_800A558C, &D_800A5598, &D_800A55A4 },
};
Battle D_800A55D4 = { 153, 4, 0x60080000 };
Battle D_800A55E0 = { 153, 4, 0x60080000 };
Battle D_800A55EC = { 153, 4, 0x60080000 };
Battle D_800A55F8 = { 153, 4, 0x60080000 };
Battle D_800A5604 = { 153, 4, 0x60080000 };
Battle D_800A5610 = { 153, 4, 0x60080000 };
Battle D_800A561C = { 153, 4, 0x60080000 };
Battle D_800A5628 = { 153, 4, 0x60080000 };
BattleList D_800A5634 = {
    3,
    { &D_800A55D4, &D_800A55E0, &D_800A55EC, &D_800A55F8,
      &D_800A5604, &D_800A5610, &D_800A561C, &D_800A5628 },
};
Battle D_800A5658 = { 206, 1, 0x600C0000 };
Battle D_800A5664 = { 0, 0, 0x60040000 };
Battle D_800A5670 = { 0, 0, 0x60040000 };
Battle D_800A567C = { 327, 1, 0x60080000 };
Battle D_800A5688 = { 0, 0, 0x60040000 };
Battle D_800A5694 = { 0, 0, 0x60040000 };
Battle D_800A56A0 = { 49, 1, 0x60080000 };
Battle D_800A56AC = { 0, 0, 0x60040000 };
BattleList D_800A56B8 = {
    0,
    { &D_800A5658, &D_800A5664, &D_800A5670, &D_800A567C,
      &D_800A5688, &D_800A5694, &D_800A56A0, &D_800A56AC },
};
FieldBattles stageBattles[] = {
    { 8, 0, 0, { &D_800A552C, &D_800A55B0, &D_800A5634, &D_800A56B8 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x18A, 0x15A, 0x128, 0x5A, 0x140, 0x1FF },
    { 0x180, 0x100, 0x1B8, 0x14C, 0x1E0, 0x4C, 0x150, 0x1FF },
    { 0x180, 0x100, 0x192, 0x15A, 0x148, 0x5A, 0x160, 0x1FF },
    { 0x180, 0x100, 0x1A8, 0x13C, 0x1A0, 0x3C, 0x170, 0x1FF },
    { 0x180, 0x100, 0x19A, 0x164, 0x168, 0x64, 0x140, 0x1FE },
};
u16 D_800A57A8[] = { 0x227, 1, 0x8B0B, 1, 0x7013, 1, 0xFFFF };
u16 D_800A57B8[] = { 0x1A26, 0, 0xFFFF };
u16 D_800A57C0[] = { 0x1A26, 1, 0x9030, 1, 0x1A25, 0, 0xFFFF };
u16 D_800A57D0[] = { 0x1A26, 1, 0xFFFF };
u16 D_800A57D8[] = { 0x9030, 1, 0xFFFF };
u16 D_800A57E0[] = { 0, 0, 0xFFFF };
u16 D_800A57E8[] = { 0, 1, 0xFFFF };
u16 D_800A57F0[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A57FC[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A580C[] = { 0x7610, 1, 0xFFFF };
u16 D_800A5814[] = { 0, 1, 0x7203, 1, 0x7201, 1, 0xE06, 0, 0xFFFF };
u16 D_800A5828[] = { 0x7400, 1, 0xE06, 1, 0xFFFF };
u16 D_800A5834[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A584C[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 1,
    0x8012, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A5868[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A5884[] = { 0x7810, 1, 0xFFFF };
u16 D_800A588C[] = { 0, 0, 0xFFFF };
u16 D_800A5894[] = { 0, 1, 0xFFFF };
u16 D_800A589C[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A58A8[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A58B8[] = { 0x7610, 1, 0xFFFF };
u16 D_800A58C0[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 0, 0xFFFF };
u16 D_800A58D4[] = { 0x7400, 1, 0xE06, 1, 0xFFFF };
u16 D_800A58E0[] = {
    0xE06, 1, 0, 1, 0x7201, 1, 0x7203, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A58F8[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 1,
    0x8012, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A5914[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A5930[] = { 0x7810, 1, 0xFFFF };
u16 D_800A5938[] = { 0, 0, 0xFFFF };
u16 D_800A5940[] = { 0, 1, 0xFFFF };
u16 D_800A5948[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5954[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A5964[] = { 0x7610, 1, 0xFFFF };
u16 D_800A596C[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 0, 0xFFFF };
u16 D_800A5980[] = { 0x7400, 1, 0xE06, 1, 0xFFFF };
u16 D_800A598C[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A59A4[] = {
    0x7201, 1, 0xE06, 1, 0x7205, 0, 0, 1,
    0x7203, 1, 0x8012, 1, 0xFFFF,
};
u16 D_800A59C0[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A59DC[] = { 0x7810, 1, 0xFFFF };
u16 D_800A59E4[] = { 0x11, 0, 0xFFFF };
u16 D_800A59EC[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A59F8[] = { 0x11, 0, 0xFFFF };
u16 D_800A5A00[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5A0C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5A18[] = { 0, 0, 0xFFFF };
u16 D_800A5A20[] = { 0x7201, 0, 0, 1, 0xFFFF };
u16 D_800A5A2C[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A5A3C[] = { 0x7610, 1, 0xFFFF };
u16 D_800A5A44[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 0, 0xFFFF };
u16 D_800A5A58[] = { 0xE06, 1, 0xFFFF };
u16 D_800A5A60[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5A78[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 1,
    0x8012, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A5A94[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE06, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A5AB0[] = { 0x7810, 1, 0xFFFF };
FieldTalk D_800A5AB8[] = {
    { NULL, D_800A57A8, 0x26C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AD0[] = {
    { D_800A57B8, D_800A57C0, 0x2DF },
    { D_800A57D0, D_800A57D8, 0x2E0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AF4[] = {
    { NULL, NULL, 0x2E1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B0C[] = {
    { D_800A57E0, D_800A57E8, 0xDC },
    { D_800A57F0, NULL, 0xE1 },
    { D_800A57FC, D_800A580C, 0xE2 },
    { D_800A5814, D_800A5828, 0xE3 },
    { D_800A5834, NULL, 0xE4 },
    { D_800A584C, NULL, 0xE5 },
    { D_800A5868, D_800A5884, 0xE6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B6C[] = {
    { D_800A588C, D_800A5894, 0xDD },
    { D_800A589C, NULL, 0xE1 },
    { D_800A58A8, D_800A58B8, 0xE2 },
    { D_800A58C0, D_800A58D4, 0xE3 },
    { D_800A58E0, NULL, 0xE4 },
    { D_800A58F8, NULL, 0xE5 },
    { D_800A5914, D_800A5930, 0xE6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BCC[] = {
    { D_800A5938, D_800A5940, 0xDE },
    { D_800A5948, NULL, 0xE1 },
    { D_800A5954, D_800A5964, 0xE2 },
    { D_800A596C, D_800A5980, 0xE3 },
    { D_800A598C, NULL, 0xE4 },
    { D_800A59A4, NULL, 0xE5 },
    { D_800A59C0, D_800A59DC, 0xE6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C2C[] = {
    { D_800A59E4, NULL, 0xDC },
    { D_800A59EC, D_800A59F8, 0xE7 },
    { D_800A5A00, D_800A5A0C, 0xE8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C5C[] = {
    { NULL, NULL, 0x275 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C74[] = {
    { D_800A5A18, NULL, 0xDF },
    { D_800A5A20, NULL, 0xDF },
    { D_800A5A2C, D_800A5A3C, 0xDF },
    { D_800A5A44, D_800A5A58, 0xDF },
    { D_800A5A60, NULL, 0xDF },
    { D_800A5A78, NULL, 0xDF },
    { D_800A5A94, D_800A5AB0, 0xDF },
    { NULL, NULL, 0 },
};
u16 D_800A5CD4[] = {
#if VERSION_US
    0x6005, 1, 0xFFFF,
#elif VERSION_EU
    0x6005, 1, 0x4011, 0, 0xFFFF,
#endif
};
u16 D_800A5CDC[] = { 0x227, 0, 0xFFFF };
u16 D_800A5CE4[] = { 0x1A25, 1, 0x1A27, 0, 0xFFFF };
u16 D_800A5CF0[] = { 0x1A27, 1, 0x1A28, 0, 0xFFFF };
u16 D_800A5CFC[] = { 0x7003, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5D0C[] = { 0x7004, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5D1C[] = { 0x6026, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5D2C[] = { 0x7009, 1, 0x11, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5D3C[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5D4C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5D54 = { D_800A5CD4, NULL, 0xC, 4, 0, 0, 7 };
FieldActorEntry D_800A5D68 = { D_800A5CDC, D_800A5AB8, 0x21, 5, 1566, 529, 1 };
FieldActorEntry D_800A5D7C = { D_800A5CE4, D_800A5AD0, 0x23, 6, 1520, 985, 1 };
FieldActorEntry D_800A5D90 = { D_800A5CF0, D_800A5AF4, 0x23, 6, 1520, 985, 1 };
FieldActorEntry D_800A5DA4 = { D_800A5CFC, D_800A5B0C, 0x33, 7, 512, 554, 3 };
FieldActorEntry D_800A5DB8 = { D_800A5D0C, D_800A5B6C, 0x33, 7, 512, 554, 3 };
FieldActorEntry D_800A5DCC = { D_800A5D1C, D_800A5BCC, 0x33, 7, 512, 554, 3 };
FieldActorEntry D_800A5DE0 = { D_800A5D2C, D_800A5C2C, 0x33, 7, 512, 554, 3 };
FieldActorEntry D_800A5DF4 = { D_800A5D3C, D_800A5C5C, 0x33, 7, 512, 554, 3 };
FieldActorEntry D_800A5E08 = { D_800A5D4C, D_800A5C74, 0x9D, 8, 512, 554, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A5D54,
    &D_800A5D68,
    &D_800A5D7C,
    &D_800A5D90,
    &D_800A5DA4,
    &D_800A5DB8,
    &D_800A5DCC,
    &D_800A5DE0,
    &D_800A5DF4,
    &D_800A5E08,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0xC, 1, 0xC, 0x11, 8, 0, 1559, 780, 0, 0 },
    { 1, 0, 0x78, 2, 0x12, 0, 0, 0, 0, 0, 1216, 594, 0, 0 },
    { 1, 0, 0x78, 2, 0x14, 0, 0, 0, 0, 0, 1172, 388, 0, 0 },
    { 1, 0, 0x78, 2, 0x16, 0, 0, 0, 0, 0, 998, 303, 0, 0 },
    { 1, 0, 0x78, 2, 0x17, 0, 0, 0, 0, 0, 953, 355, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 1, 0xC, 0x11, 8, 0, 86, 107, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 1, 0xC, 0x11, 8, 0, 621, 642, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 1, 0xC, 0x11, 8, 0, 1201, 300, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 1115, 218, 262, 0 },
    { 1, 0, 0x48, 4, 1, 0, 0, 0, 0, 0, 828, 359, 400, 0 },
    { 1, 0, 0x60, 4, 2, 0, 0, 0, 0, 0, 476, 268, 321, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 1216, 649, 682, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 1169, 434, 465, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 545, 557, 583, 0 },
    { 1, 0, 0x44, 4, 6, 0, 0, 0, 0, 0, 925, 722, 766, 0 },
    { 1, 0, 0x73, 4, 7, 0, 0, 0, 0, 0, 634, 661, 767, 0 },
    { 1, 0, 0x78, 4, 0x13, 0, 0, 0, 0, 0, 1264, 489, 562, 0 },
    { 1, 0, 0x78, 4, 0x15, 0, 0, 0, 0, 0, 905, 338, 355, 0 },
    { 1, 0, 0x78, 4, 0x18, 0, 0, 0, 0, 0, 914, 450, 464, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 288, 133, 133, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 384, 135, 135, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 425, 155, 155, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 432, 311, 311, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 472, 179, 179, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 521, 203, 203, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 263, 263, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 391, 391, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 574, 368, 368, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 607, 214, 214, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 617, 347, 347, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 648, 235, 235, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 695, 259, 259, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 744, 283, 283, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 792, 307, 307, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 840, 331, 331, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 928, 799, 799, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1008, 791, 791, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1376, 751, 751, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1424, 775, 775, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1472, 799, 799, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x227, 0x4A2, 0x36A, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x22A, 0xAA, 0xC3, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x22E, 0x150, 0x268, 5, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 1, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 5, 4 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 80, D_800A4F78, EVENT_TEXT(0), NULL, func_800A4DD8 },
    { 1299, D_800A5264, EVENT_TEXT(0x24), NULL, NULL },
    { 1305, D_800A5430, EVENT_TEXT(0x25), NULL, func_800A4E04 },
    { -1, NULL, 0, NULL, NULL },
};
