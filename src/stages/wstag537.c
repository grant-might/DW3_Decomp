#include "common.h"
#include "stage.h"

/* Creates the event object of flags 0x40CB and 0x40CC */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (FLAGS_00.checkCondition(0x40CB, 1) && FLAGS_00.checkCondition(0x40CC, 0)) {
            children[0] = FIELDSTG_startEvent(0x5B0);
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
    FLAGS_00.applyAction(0x400B, 1);
}

void func_800A4DD4(void) {
    FLAGS_00.applyAction(0x40CB, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A4E20(void) {
    FLAGS_00.applyAction(0x40CC, 1);
    FLAGS_00.applyAction(0x8666, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x544
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x554
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xD400, 0xA700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x11;
    D_800990B4.music = 0x60440000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A5320;
extern Battle D_800A532C;
extern Battle D_800A5338;
extern Battle D_800A5344;
extern Battle D_800A5350;
extern Battle D_800A535C;
extern Battle D_800A5368;
extern Battle D_800A5374;
extern Battle D_800A53A4;
extern Battle D_800A53B0;
extern Battle D_800A53BC;
extern Battle D_800A53C8;
extern Battle D_800A53D4;
extern Battle D_800A53E0;
extern Battle D_800A53EC;
extern Battle D_800A53F8;
extern Battle D_800A5428;
extern Battle D_800A5434;
extern Battle D_800A5440;
extern Battle D_800A544C;
extern Battle D_800A5458;
extern Battle D_800A5464;
extern Battle D_800A5470;
extern Battle D_800A547C;
extern Battle D_800A54AC;
extern Battle D_800A54B8;
extern Battle D_800A54C4;
extern Battle D_800A54D0;
extern Battle D_800A54DC;
extern Battle D_800A54E8;
extern Battle D_800A54F4;
extern Battle D_800A5500;
extern BattleList D_800A5380;
extern BattleList D_800A5404;
extern BattleList D_800A5488;
extern BattleList D_800A550C;
extern u16 D_800A55CC[];
extern u16 D_800A55D4[];
extern u16 D_800A55E0[];
extern u16 D_800A55E8[];
extern u16 D_800A55F0[];
extern u16 D_800A55FC[];
extern u16 D_800A5604[];
extern u16 D_800A560C[];
extern u16 D_800A5618[];
extern u16 D_800A5620[];
extern u16 D_800A5628[];
extern u16 D_800A5634[];
extern u16 D_800A563C[];
extern u16 D_800A5644[];
extern u16 D_800A5650[];
extern u16 D_800A5658[];
extern u16 D_800A5660[];
extern u16 D_800A566C[];
extern u16 D_800A5674[];
extern u16 D_800A567C[];
extern u16 D_800A5688[];
extern u16 D_800A5690[];
extern u16 D_800A5698[];
extern u16 D_800A56A4[];
extern u16 D_800A56AC[];
extern u16 D_800A56B4[];
extern u16 D_800A56C0[];
extern u16 D_800A56C8[];
extern u16 D_800A56D0[];
extern u16 D_800A56DC[];
extern u16 D_800A56E4[];
extern u16 D_800A56EC[];
extern u16 D_800A56F8[];
extern u16 D_800A5700[];
extern u16 D_800A5708[];
extern u16 D_800A5714[];
extern u16 D_800A571C[];
extern u16 D_800A5724[];
extern u16 D_800A5730[];
extern u16 D_800A5738[];
extern u16 D_800A5740[];
extern u16 D_800A574C[];
extern u16 D_800A5754[];
extern u16 D_800A575C[];
extern u16 D_800A5764[];
extern u16 D_800A576C[];
extern u16 D_800A5774[];
extern u16 D_800A577C[];
extern u16 D_800A5784[];
extern u16 D_800A578C[];
extern u16 D_800A5794[];
extern u16 D_800A579C[];
extern u16 D_800A57A4[];
extern u16 D_800A57AC[];
extern u16 D_800A57B4[];
extern u16 D_800A57BC[];
extern u16 D_800A57C4[];
extern u16 D_800A57CC[];
extern u16 D_800A57D4[];
extern u16 D_800A57DC[];
extern u16 D_800A57E4[];
extern u16 D_800A57EC[];
extern u16 D_800A57F4[];
extern u16 D_800A5B68[];
extern FieldTalk D_800A57FC[];
extern u16 D_800A5B70[];
extern FieldTalk D_800A5820[];
extern u16 D_800A5B78[];
extern FieldTalk D_800A5844[];
extern u16 D_800A5B80[];
extern FieldTalk D_800A5868[];
extern u16 D_800A5B88[];
extern FieldTalk D_800A588C[];
extern u16 D_800A5B90[];
extern FieldTalk D_800A58B0[];
extern u16 D_800A5B98[];
extern FieldTalk D_800A58D4[];
extern u16 D_800A5BA0[];
extern FieldTalk D_800A58F8[];
extern u16 D_800A5BA8[];
extern FieldTalk D_800A591C[];
extern u16 D_800A5BB0[];
extern FieldTalk D_800A5940[];
extern u16 D_800A5BB8[];
extern FieldTalk D_800A5964[];
extern u16 D_800A5BC0[];
extern FieldTalk D_800A5988[];
extern u16 D_800A5BC8[];
extern FieldTalk D_800A59AC[];
extern u16 D_800A5BD0[];
extern FieldTalk D_800A59D0[];
extern u16 D_800A5BD8[];
extern FieldTalk D_800A59F4[];
extern u16 D_800A5BE0[];
extern FieldTalk D_800A5A18[];
extern u16 D_800A5BE8[];
extern FieldTalk D_800A5A30[];
extern u16 D_800A5BF0[];
extern FieldTalk D_800A5A54[];
extern u16 D_800A5BF8[];
extern FieldTalk D_800A5A6C[];
extern u16 D_800A5C00[];
extern FieldTalk D_800A5A90[];
extern u16 D_800A5C08[];
extern FieldTalk D_800A5AB4[];
extern u16 D_800A5C10[];
extern FieldTalk D_800A5AD8[];
extern u16 D_800A5C18[];
extern FieldTalk D_800A5AF0[];
extern u16 D_800A5C24[];
extern FieldTalk D_800A5B14[];
extern u16 D_800A5C2C[];
extern FieldTalk D_800A5B2C[];
extern u16 D_800A5C34[];
extern FieldTalk D_800A5B44[];
extern FieldActorEntry D_800A5C40;
extern FieldActorEntry D_800A5C54;
extern FieldActorEntry D_800A5C68;
extern FieldActorEntry D_800A5C7C;
extern FieldActorEntry D_800A5C90;
extern FieldActorEntry D_800A5CA4;
extern FieldActorEntry D_800A5CB8;
extern FieldActorEntry D_800A5CCC;
extern FieldActorEntry D_800A5CE0;
extern FieldActorEntry D_800A5CF4;
extern FieldActorEntry D_800A5D08;
extern FieldActorEntry D_800A5D1C;
extern FieldActorEntry D_800A5D30;
extern FieldActorEntry D_800A5D44;
extern FieldActorEntry D_800A5D58;
extern FieldActorEntry D_800A5D6C;
extern FieldActorEntry D_800A5D80;
extern FieldActorEntry D_800A5D94;
extern FieldActorEntry D_800A5DA8;
extern FieldActorEntry D_800A5DBC;
extern FieldActorEntry D_800A5DD0;
extern FieldActorEntry D_800A5DE4;
extern FieldActorEntry D_800A5DF8;
extern FieldActorEntry D_800A5E0C;
extern FieldActorEntry D_800A5E20;
extern FieldActorEntry D_800A5E34;
extern s16 D_800A4F78[];
extern s16 D_800A51E0[];
extern s16 D_800A527C[];

s16 D_800A4F78[] = {
    0x101, 2, 1, 7,
    0x100, 0x8D, 0x374, 0x17A,
    0x101, 0x8D, 1, 7,
    0x101, 0x323, 0x325, 2,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 2, 0x354, 0x16A, 7,
    0x302, 2,
    0x101, 2, 1, 7,
    0x101, 0x323, 0x325, 0x8D,
    0x300, 0x3C,
    0x101, 0x8D, 1, 3,
    0x101, 0x323, 0x326, 0x8D,
    0x300, 0x1E,
    0x200, 0, 1, 0x8D, 3,
    0x301,
    0x101, 2, 1, 6,
    0x101, 0x8D, 1, 6,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x601, 0, 0x3D2, 0x1A2,
    0x101, 0x323, 0x326, 2,
    0x300, 0x3C,
    0x300, 0xB4,
    0x600, 0, 2,
    0x200, 0, 2, 2, 2,
    0x101, 2, 7, 6,
    0x301,
    0x101, 2, 1, 6,
    0x300, 0x1E,
    0x200, 0, 3, 0x8D, 3,
    0x101, 2, 1, 7,
    0x101, 0x8D, 1, 3,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x37C, 2,
    0x300, 0x78,
    0x101, 2, 1, 6,
    0x101, 0x8D, 1, 6,
    0x101, 0x323, 0x325, 2,
    0x101, 0x324, 0x325, 0x8D,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x101, 0x324, 0x326, 0x8D,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xA, 2, 0,
    0x301,
    0x102, 2, 0x35C, 0x16E, 7,
    0x302, 2,
    0x101, 0x323, 0x325, 0x8D,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x8D,
    0x300, 0x1E,
    0x200, 0, 5, 0x8D, 3,
    0x101, 0x8D, 1, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 7, 0x8D, 3,
    0x301,
    0x101, 0x323, 0x327, 0x8D,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x8D,
    0x300, 0x1E,
    0x200, 0, 8, 0x8D, 3,
    0x301,
    0x300, 0x1E,
    0x102, 0x8D, 0x3B0, 0x15D, 5,
    0x302, 0x8D,
    0x102, 2, 0x374, 0x17A, 7,
    0x101, 0x8D, 1, 1,
    0x302, 2,
    0x200, 0, 0xB, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 0xC, 0x8D, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 2, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x394, 0x18A, 7,
    0x302, 2,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0,
};
s16 D_800A51E0[] = {
    0x600, 1, 2,
    0x102, 2, 0x357, 0x93, 5,
    0x100, 0x85, 0x377, 0x85,
    0x101, 0x85, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x24,
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
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A527C[] = {
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
Battle D_800A5320 = { 91, 6, 0x60080000 };
Battle D_800A532C = { 91, 6, 0x60080000 };
Battle D_800A5338 = { 91, 6, 0x60080000 };
Battle D_800A5344 = { 91, 6, 0x60080000 };
Battle D_800A5350 = { 91, 6, 0x60080000 };
Battle D_800A535C = { 91, 6, 0x60080000 };
Battle D_800A5368 = { 91, 6, 0x60080000 };
Battle D_800A5374 = { 91, 6, 0x60080000 };
BattleList D_800A5380 = {
    4,
    { &D_800A5320, &D_800A532C, &D_800A5338, &D_800A5344,
      &D_800A5350, &D_800A535C, &D_800A5368, &D_800A5374 },
};
Battle D_800A53A4 = { 0, 0, 0x60040000 };
Battle D_800A53B0 = { 0, 0, 0x60040000 };
Battle D_800A53BC = { 0, 0, 0x60040000 };
Battle D_800A53C8 = { 0, 0, 0x60040000 };
Battle D_800A53D4 = { 0, 0, 0x60040000 };
Battle D_800A53E0 = { 0, 0, 0x60040000 };
Battle D_800A53EC = { 0, 0, 0x60040000 };
Battle D_800A53F8 = { 0, 0, 0x60040000 };
BattleList D_800A5404 = {
    0,
    { &D_800A53A4, &D_800A53B0, &D_800A53BC, &D_800A53C8,
      &D_800A53D4, &D_800A53E0, &D_800A53EC, &D_800A53F8 },
};
Battle D_800A5428 = { 0, 0, 0x60040000 };
Battle D_800A5434 = { 0, 0, 0x60040000 };
Battle D_800A5440 = { 0, 0, 0x60040000 };
Battle D_800A544C = { 0, 0, 0x60040000 };
Battle D_800A5458 = { 0, 0, 0x60040000 };
Battle D_800A5464 = { 0, 0, 0x60040000 };
Battle D_800A5470 = { 0, 0, 0x60040000 };
Battle D_800A547C = { 0, 0, 0x60040000 };
BattleList D_800A5488 = {
    0,
    { &D_800A5428, &D_800A5434, &D_800A5440, &D_800A544C,
      &D_800A5458, &D_800A5464, &D_800A5470, &D_800A547C },
};
Battle D_800A54AC = { 11, 19, 0x60880000 };
Battle D_800A54B8 = { 314, 19, 0x60880000 };
Battle D_800A54C4 = { 0, 0, 0x60040000 };
Battle D_800A54D0 = { 0, 0, 0x60040000 };
Battle D_800A54DC = { 0, 0, 0x60040000 };
Battle D_800A54E8 = { 0, 0, 0x60040000 };
Battle D_800A54F4 = { 0, 0, 0x60040000 };
Battle D_800A5500 = { 0, 0, 0x60040000 };
BattleList D_800A550C = {
    0,
    { &D_800A54AC, &D_800A54B8, &D_800A54C4, &D_800A54D0,
      &D_800A54DC, &D_800A54E8, &D_800A54F4, &D_800A5500 },
};
FieldBattles stageBattles[] = {
    { 126, 0, 0, { &D_800A5380, &D_800A5404, &D_800A5488, &D_800A550C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x170, 0x1FC },
    { 0x140, 0x100, 0x14E, 0x100, 0x38, 0, 0x140, 0x1FB },
};
u16 D_800A55CC[] = { 0xA02, 0, 0xFFFF };
u16 D_800A55D4[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A55E0[] = { 0xA02, 1, 0xFFFF };
u16 D_800A55E8[] = { 0xA02, 0, 0xFFFF };
u16 D_800A55F0[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A55FC[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5604[] = { 0xA02, 0, 0xFFFF };
u16 D_800A560C[] = { 0xA02, 1, 0x9036, 1, 0xFFFF };
u16 D_800A5618[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5620[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5628[] = { 0x9064, 1, 0xA02, 1, 0xFFFF };
u16 D_800A5634[] = { 0xA02, 1, 0xFFFF };
u16 D_800A563C[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5644[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A5650[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5658[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5660[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A566C[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5674[] = { 0xA02, 0, 0xFFFF };
u16 D_800A567C[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A5688[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5690[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5698[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A56A4[] = { 0xA02, 1, 0xFFFF };
u16 D_800A56AC[] = { 0xA02, 0, 0xFFFF };
u16 D_800A56B4[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A56C0[] = { 0xA02, 1, 0xFFFF };
u16 D_800A56C8[] = { 0xA02, 0, 0xFFFF };
u16 D_800A56D0[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A56DC[] = { 0xA02, 1, 0xFFFF };
u16 D_800A56E4[] = { 0xA02, 0, 0xFFFF };
u16 D_800A56EC[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A56F8[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5700[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5708[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A5714[] = { 0xA02, 1, 0xFFFF };
u16 D_800A571C[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5724[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A5730[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5738[] = { 0xA02, 0, 0xFFFF };
u16 D_800A5740[] = { 0xA02, 1, 0x9064, 1, 0xFFFF };
u16 D_800A574C[] = { 0xA02, 1, 0xFFFF };
u16 D_800A5754[] = { 0, 0, 0xFFFF };
u16 D_800A575C[] = { 0, 1, 0xFFFF };
u16 D_800A5764[] = { 0, 1, 0xFFFF };
u16 D_800A576C[] = { 0, 0, 0xFFFF };
u16 D_800A5774[] = { 0, 1, 0xFFFF };
u16 D_800A577C[] = { 0, 1, 0xFFFF };
u16 D_800A5784[] = { 0, 0, 0xFFFF };
u16 D_800A578C[] = { 0, 1, 0xFFFF };
u16 D_800A5794[] = { 0, 1, 0xFFFF };
u16 D_800A579C[] = { 0, 0, 0xFFFF };
u16 D_800A57A4[] = { 0, 1, 0xFFFF };
u16 D_800A57AC[] = { 0, 1, 0xFFFF };
u16 D_800A57B4[] = { 0, 0, 0xFFFF };
u16 D_800A57BC[] = { 0, 1, 0xFFFF };
u16 D_800A57C4[] = { 0, 1, 0xFFFF };
u16 D_800A57CC[] = { 0, 0, 0xFFFF };
u16 D_800A57D4[] = { 0, 1, 0xFFFF };
u16 D_800A57DC[] = { 0, 1, 0xFFFF };
u16 D_800A57E4[] = { 0, 0, 0xFFFF };
u16 D_800A57EC[] = { 0, 1, 0xFFFF };
u16 D_800A57F4[] = { 0, 1, 0xFFFF };
FieldTalk D_800A57FC[] = {
    { D_800A55CC, D_800A55D4, 0x2F8 },
    { D_800A55E0, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5820[] = {
    { D_800A55E8, D_800A55F0, 0x2F8 },
    { D_800A55FC, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5844[] = {
    { D_800A5604, D_800A560C, 0x2F8 },
    { D_800A5618, NULL, 0x1EF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5868[] = {
    { D_800A5620, D_800A5628, 0x2F8 },
    { D_800A5634, NULL, 0x1EC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A588C[] = {
    { D_800A563C, D_800A5644, 0x2F8 },
    { D_800A5650, NULL, 0x1ED },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58B0[] = {
    { D_800A5658, D_800A5660, 0x2F8 },
    { D_800A566C, NULL, 0x1EE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58D4[] = {
    { D_800A5674, D_800A567C, 0x2F8 },
    { D_800A5688, NULL, 0x1EB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58F8[] = {
    { D_800A5690, D_800A5698, 0x2F8 },
    { D_800A56A4, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A591C[] = {
    { D_800A56AC, D_800A56B4, 0x2F8 },
    { D_800A56C0, NULL, 0x1EC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5940[] = {
    { D_800A56C8, D_800A56D0, 0x2F8 },
    { D_800A56DC, NULL, 0x1EC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5964[] = {
    { D_800A56E4, D_800A56EC, 0x2F8 },
    { D_800A56F8, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5988[] = {
    { D_800A5700, D_800A5708, 0x2F8 },
    { D_800A5714, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59AC[] = {
    { D_800A571C, D_800A5724, 0x2F8 },
    { D_800A5730, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59D0[] = {
    { D_800A5738, D_800A5740, 0x2F8 },
    { D_800A574C, NULL, 0x1F0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59F4[] = {
    { D_800A5754, D_800A575C, 0x1F2 },
    { D_800A5764, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A18[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A30[] = {
    { D_800A576C, D_800A5774, 0x1F2 },
    { D_800A577C, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A54[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A6C[] = {
    { D_800A5784, D_800A578C, 0x1F2 },
    { D_800A5794, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A90[] = {
    { D_800A579C, D_800A57A4, 0x1F3 },
    { D_800A57AC, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AB4[] = {
    { D_800A57B4, D_800A57BC, 0x1F3 },
    { D_800A57C4, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AD8[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AF0[] = {
    { D_800A57CC, D_800A57D4, 0x1F1 },
    { D_800A57DC, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B14[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B2C[] = {
    { NULL, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B44[] = {
    { D_800A57E4, D_800A57EC, 0x1F1 },
    { D_800A57F4, NULL, 1 },
    { NULL, NULL, 0 },
};
u16 D_800A5B68[] = { 0x6022, 1, 0xFFFF };
u16 D_800A5B70[] = { 0x6021, 1, 0xFFFF };
u16 D_800A5B78[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5B80[] = { 0x601B, 1, 0xFFFF };
u16 D_800A5B88[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5B90[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5B98[] = { 0x601A, 1, 0xFFFF };
u16 D_800A5BA0[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5BA8[] = { 0x601C, 1, 0xFFFF };
u16 D_800A5BB0[] = { 0x601D, 1, 0xFFFF };
u16 D_800A5BB8[] = { 0x601E, 1, 0xFFFF };
u16 D_800A5BC0[] = { 0x601F, 1, 0xFFFF };
u16 D_800A5BC8[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5BD0[] = { 0x6023, 1, 0xFFFF };
u16 D_800A5BD8[] = { 0x601B, 1, 0xFFFF };
u16 D_800A5BE0[] = { 0x6025, 1, 0xFFFF };
u16 D_800A5BE8[] = { 0x601C, 1, 0xFFFF };
u16 D_800A5BF0[] = { 0x6022, 1, 0xFFFF };
u16 D_800A5BF8[] = { 0x601D, 1, 0xFFFF };
u16 D_800A5C00[] = { 0x601E, 1, 0xFFFF };
u16 D_800A5C08[] = { 0x601F, 1, 0xFFFF };
u16 D_800A5C10[] = { 0x6021, 1, 0xFFFF };
u16 D_800A5C18[] = { 0x601A, 1, 0x400B, 0, 0xFFFF };
u16 D_800A5C24[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5C2C[] = { 0x6023, 1, 0xFFFF };
u16 D_800A5C34[] = { 0x601A, 1, 0x400B, 1, 0xFFFF };
FieldActorEntry D_800A5C40 = { D_800A5B68, D_800A57FC, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5C54 = { D_800A5B70, D_800A5820, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5C68 = { D_800A5B78, D_800A5844, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5C7C = { D_800A5B80, D_800A5868, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5C90 = { D_800A5B88, D_800A588C, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5CA4 = { D_800A5B90, D_800A58B0, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5CB8 = { D_800A5B98, D_800A58D4, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5CCC = { D_800A5BA0, D_800A58F8, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5CE0 = { D_800A5BA8, D_800A591C, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5CF4 = { D_800A5BB0, D_800A5940, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5D08 = { D_800A5BB8, D_800A5964, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5D1C = { D_800A5BC0, D_800A5988, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5D30 = { D_800A5BC8, D_800A59AC, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5D44 = { D_800A5BD0, D_800A59D0, 0x85, 4, 887, 133, 1 };
FieldActorEntry D_800A5D58 = { D_800A5BD8, D_800A59F4, 0x8D, 5, 962, 353, 1 };
FieldActorEntry D_800A5D6C = { D_800A5BE0, D_800A5A18, 0x8D, 5, 962, 353, 1 };
FieldActorEntry D_800A5D80 = { D_800A5BE8, D_800A5A30, 0x8D, 5, 962, 353, 1 };
FieldActorEntry D_800A5D94 = { D_800A5BF0, D_800A5A54, 0x8D, 5, 962, 353, 1 };
FieldActorEntry D_800A5DA8 = { D_800A5BF8, D_800A5A6C, 0x8D, 5, 962, 353, 1 };
FieldActorEntry D_800A5DBC = { D_800A5C00, D_800A5A90, 0x8D, 5, 962, 353, 1 };
FieldActorEntry D_800A5DD0 = { D_800A5C08, D_800A5AB4, 0x8D, 5, 962, 353, 1 };
FieldActorEntry D_800A5DE4 = { D_800A5C10, D_800A5AD8, 0x8D, 5, 962, 353, 1 };
FieldActorEntry D_800A5DF8 = { D_800A5C18, D_800A5AF0, 0x8D, 5, 884, 378, 7 };
FieldActorEntry D_800A5E0C = { D_800A5C24, D_800A5B14, 0x8D, 5, 962, 353, 1 };
FieldActorEntry D_800A5E20 = { D_800A5C2C, D_800A5B2C, 0x8D, 5, 962, 353, 1 };
FieldActorEntry D_800A5E34 = { D_800A5C34, D_800A5B44, 0x8D, 5, 962, 353, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5C40,
    &D_800A5C54,
    &D_800A5C68,
    &D_800A5C7C,
    &D_800A5C90,
    &D_800A5CA4,
    &D_800A5CB8,
    &D_800A5CCC,
    &D_800A5CE0,
    &D_800A5CF4,
    &D_800A5D08,
    &D_800A5D1C,
    &D_800A5D30,
    &D_800A5D44,
    &D_800A5D58,
    &D_800A5D6C,
    &D_800A5D80,
    &D_800A5D94,
    &D_800A5DA8,
    &D_800A5DBC,
    &D_800A5DD0,
    &D_800A5DE4,
    &D_800A5DF8,
    &D_800A5E0C,
    &D_800A5E20,
    &D_800A5E34,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 999, 303, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 3, 6, 0, 613, 221, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 3, 6, 0, 725, 165, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 258, 102, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 531, 190, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 758, 111, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 806, 87, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 827, 275, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 859, 292, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 1002, 301, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 266, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 539, 193, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 621, 224, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 733, 168, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 766, 114, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 814, 90, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 835, 279, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 867, 295, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 1010, 304, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x242, 0x3E0, 0x1B0, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x245, 0x78, 0x21C, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x3A0, 0x190, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x3B0, 0x1E8, 0, 0, 0, 0 },
    { { { 0x601A, 1 }, { 0x400B, 0 } }, 8, 0x2BC, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 700, D_800A4F78, EVENT_TEXT(0x1D), NULL, func_800A4DA8 },
    { 1455, D_800A51E0, EVENT_TEXT(0x24), NULL, func_800A4DD4 },
    { 1456, D_800A527C, EVENT_TEXT(0x25), NULL, func_800A4E20 },
    { -1, NULL, 0, NULL, NULL },
};
