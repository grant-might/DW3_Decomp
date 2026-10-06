#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 28 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0x1C && FLAGS_00.checkCondition(0x4052, 1)) {
            children[0] = FIELDSTG_startEvent(0x2EF);
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

void func_800A4D94(void) {
    FLAGS_00.applyAction(0x4052, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Sets the story progress to 29 and flag 0x8017 */
void func_800A4DE0(void) {
    GAME.progress = 29;
    FLAGS_00.applyAction(0x8017, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x5BA
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x5CA
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x14600, 0xEA00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x12;
    D_800990B4.music = 0x60480000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

void func_800A4DE0();
extern Battle D_800A50F0;
extern Battle D_800A50FC;
extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern Battle D_800A5138;
extern Battle D_800A5144;
extern Battle D_800A5174;
extern Battle D_800A5180;
extern Battle D_800A518C;
extern Battle D_800A5198;
extern Battle D_800A51A4;
extern Battle D_800A51B0;
extern Battle D_800A51BC;
extern Battle D_800A51C8;
extern Battle D_800A51F8;
extern Battle D_800A5204;
extern Battle D_800A5210;
extern Battle D_800A521C;
extern Battle D_800A5228;
extern Battle D_800A5234;
extern Battle D_800A5240;
extern Battle D_800A524C;
extern Battle D_800A527C;
extern Battle D_800A5288;
extern Battle D_800A5294;
extern Battle D_800A52A0;
extern Battle D_800A52AC;
extern Battle D_800A52B8;
extern Battle D_800A52C4;
extern Battle D_800A52D0;
extern BattleList D_800A5150;
extern BattleList D_800A51D4;
extern BattleList D_800A5258;
extern BattleList D_800A52DC;
extern u16 D_800A547C[];
extern u16 D_800A55EC[];
extern FieldTalk D_800A5484[];
extern u16 D_800A55F8[];
extern FieldTalk D_800A549C[];
extern u16 D_800A5604[];
extern FieldTalk D_800A54B4[];
extern u16 D_800A5610[];
extern FieldTalk D_800A54CC[];
extern u16 D_800A5618[];
extern FieldTalk D_800A54E4[];
extern u16 D_800A5620[];
extern FieldTalk D_800A54FC[];
extern u16 D_800A5628[];
extern FieldTalk D_800A5514[];
extern u16 D_800A5630[];
extern FieldTalk D_800A552C[];
extern u16 D_800A563C[];
extern FieldTalk D_800A5544[];
extern u16 D_800A5644[];
extern FieldTalk D_800A555C[];
extern u16 D_800A5650[];
extern FieldTalk D_800A5574[];
extern u16 D_800A5658[];
extern FieldTalk D_800A558C[];
extern u16 D_800A5664[];
extern FieldTalk D_800A55A4[];
extern u16 D_800A566C[];
extern FieldTalk D_800A55BC[];
extern u16 D_800A5674[];
extern FieldTalk D_800A55D4[];
extern u16 D_800A567C[];
extern FieldActorEntry D_800A5684;
extern FieldActorEntry D_800A5698;
extern FieldActorEntry D_800A56AC;
extern FieldActorEntry D_800A56C0;
extern FieldActorEntry D_800A56D4;
extern FieldActorEntry D_800A56E8;
extern FieldActorEntry D_800A56FC;
extern FieldActorEntry D_800A5710;
extern FieldActorEntry D_800A5724;
extern FieldActorEntry D_800A5738;
extern FieldActorEntry D_800A574C;
extern FieldActorEntry D_800A5760;
extern FieldActorEntry D_800A5774;
extern FieldActorEntry D_800A5788;
extern FieldActorEntry D_800A579C;
extern FieldActorEntry D_800A57B0;
extern FieldActorEntry D_800A57C4;
extern FieldActorEntry D_800A57D8;
extern FieldActorEntry D_800A57EC;
extern s16 D_800A4F58[];
extern s16 D_800A503C[];

s16 D_800A4F58[] = {
    0x102, 2, 0x1B9, 0xD5, 3,
    0x100, 0xD2, 0x1A1, 0xC9,
    0x101, 0xD2, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 5, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 0,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 8, 0xD2, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A503C[] = {
    0x100, 2, 0x1B9, 0xD5,
    0x101, 2, 1, 3,
    0x100, 0x13C, 0x1A1, 0xC9,
    0x101, 0x13C, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 2, 0,
    0x301,
    0x300, 0x1E,
    0x300, 0x3C,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x1A9, 0xCD, 3,
    0x302, 2,
    0x300, 0x1E,
    0x100, 0x13C, 0, 0,
    0x101, 0x13C, 1, 7,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x301,
    0x102, 2, 0x1D1, 0xE1, 7,
    0x300, 0x1E,
    0x304, 0x2AB, 0x238, 0x8C, 1,
    0,
};
Battle D_800A50F0 = { 0, 0, 0x60040000 };
Battle D_800A50FC = { 0, 0, 0x60040000 };
Battle D_800A5108 = { 0, 0, 0x60040000 };
Battle D_800A5114 = { 0, 0, 0x60040000 };
Battle D_800A5120 = { 0, 0, 0x60040000 };
Battle D_800A512C = { 0, 0, 0x60040000 };
Battle D_800A5138 = { 0, 0, 0x60040000 };
Battle D_800A5144 = { 0, 0, 0x60040000 };
BattleList D_800A5150 = {
    0,
    { &D_800A50F0, &D_800A50FC, &D_800A5108, &D_800A5114,
      &D_800A5120, &D_800A512C, &D_800A5138, &D_800A5144 },
};
Battle D_800A5174 = { 0, 0, 0x60040000 };
Battle D_800A5180 = { 0, 0, 0x60040000 };
Battle D_800A518C = { 0, 0, 0x60040000 };
Battle D_800A5198 = { 0, 0, 0x60040000 };
Battle D_800A51A4 = { 0, 0, 0x60040000 };
Battle D_800A51B0 = { 0, 0, 0x60040000 };
Battle D_800A51BC = { 0, 0, 0x60040000 };
Battle D_800A51C8 = { 0, 0, 0x60040000 };
BattleList D_800A51D4 = {
    0,
    { &D_800A5174, &D_800A5180, &D_800A518C, &D_800A5198,
      &D_800A51A4, &D_800A51B0, &D_800A51BC, &D_800A51C8 },
};
Battle D_800A51F8 = { 0, 0, 0x60040000 };
Battle D_800A5204 = { 0, 0, 0x60040000 };
Battle D_800A5210 = { 0, 0, 0x60040000 };
Battle D_800A521C = { 0, 0, 0x60040000 };
Battle D_800A5228 = { 0, 0, 0x60040000 };
Battle D_800A5234 = { 0, 0, 0x60040000 };
Battle D_800A5240 = { 0, 0, 0x60040000 };
Battle D_800A524C = { 0, 0, 0x60040000 };
BattleList D_800A5258 = {
    0,
    { &D_800A51F8, &D_800A5204, &D_800A5210, &D_800A521C,
      &D_800A5228, &D_800A5234, &D_800A5240, &D_800A524C },
};
Battle D_800A527C = { 16, 18, 0x608C0000 };
Battle D_800A5288 = { 306, 18, 0x608C0000 };
Battle D_800A5294 = { 0, 0, 0x60040000 };
Battle D_800A52A0 = { 0, 0, 0x60040000 };
Battle D_800A52AC = { 0, 0, 0x60040000 };
Battle D_800A52B8 = { 0, 0, 0x60040000 };
Battle D_800A52C4 = { 0, 0, 0x60040000 };
Battle D_800A52D0 = { 0, 0, 0x60040000 };
BattleList D_800A52DC = {
    0,
    { &D_800A527C, &D_800A5288, &D_800A5294, &D_800A52A0,
      &D_800A52AC, &D_800A52B8, &D_800A52C4, &D_800A52D0 },
};
FieldBattles stageBattles[] = {
    { 151, 0, 0, { &D_800A5150, &D_800A51D4, &D_800A5258, &D_800A52DC } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x19D, 0xC0, 0x9D, 0x160, 0x1FF },
    { 0x140, 0x100, 0x174, 0x175, 0xD0, 0x75, 0x170, 0x1FF },
    { 0x140, 0x100, 0x140, 0x19E, 0, 0x9E, 0x160, 0x1FE },
    { 0x140, 0x100, 0x156, 0x1A6, 0x58, 0xA6, 0x170, 0x1FE },
    { 0x140, 0x100, 0x15E, 0x1A6, 0x78, 0xA6, 0x150, 0x1FD },
    { 0x140, 0x100, 0x148, 0x1B2, 0x20, 0xB2, 0x160, 0x1FD },
    { 0x140, 0x100, 0x16A, 0x175, 0xA8, 0x75, 0x170, 0x1FD },
    { 0x140, 0x100, 0x158, 0x17E, 0x60, 0x7E, 0x150, 0x1FC },
    { 0x140, 0x100, 0x160, 0x17E, 0x80, 0x7E, 0x160, 0x1FC },
    { 0x140, 0x100, 0x14E, 0x18A, 0x38, 0x8A, 0x170, 0x1FC },
    { 0x140, 0x100, 0x166, 0x1BD, 0x98, 0xBD, 0x150, 0x1FB },
    { 0x140, 0x100, 0x16E, 0x1BD, 0xB8, 0xBD, 0x160, 0x1FB },
    { 0x140, 0x100, 0x176, 0x1BD, 0xD8, 0xBD, 0x170, 0x1FB },
    { 0x140, 0x100, 0x14E, 0x15A, 0x38, 0x5A, 0x150, 0x1FA },
    { 0x140, 0x100, 0x140, 0x1BE, 0, 0xBE, 0x160, 0x1FA },
    { 0x140, 0x100, 0x17A, 0x100, 0xE8, 0, 0x170, 0x1FA },
};
u16 D_800A547C[] = { 0x9049, 1, 0xFFFF };
FieldTalk D_800A5484[] = {
    { NULL, NULL, 0x11F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A549C[] = {
    { NULL, NULL, 0x125 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B4[] = {
    { NULL, NULL, 0x122 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54CC[] = {
    { NULL, NULL, 0x12A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54E4[] = {
    { NULL, NULL, 0x128 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54FC[] = {
    { NULL, NULL, 0x129 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5514[] = {
    { NULL, NULL, 0x127 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A552C[] = {
    { NULL, NULL, 0x121 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5544[] = {
    { NULL, NULL, 0x123 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A555C[] = {
    { NULL, NULL, 0x124 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5574[] = {
    { NULL, NULL, 0x120 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A558C[] = {
    { NULL, NULL, 0x11E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A4[] = {
    { NULL, NULL, 0x126 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55BC[] = {
    { NULL, D_800A547C, 0x11D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55D4[] = {
    { NULL, NULL, 0x200 },
    { NULL, NULL, 0 },
};
u16 D_800A55EC[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A55F8[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5604[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5610[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5618[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5620[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5628[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5630[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A563C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5644[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5650[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5658[] = { 0x703D, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5664[] = { 0x701A, 1, 0xFFFF };
u16 D_800A566C[] = { 0x4052, 0, 0xFFFF };
u16 D_800A5674[] = { 0x601C, 1, 0xFFFF };
u16 D_800A567C[] = { 0x601C, 1, 0xFFFF };
FieldActorEntry D_800A5684 = { D_800A55EC, D_800A5484, 0x2E, 4, 517, 289, 1 };
FieldActorEntry D_800A5698 = { D_800A55F8, D_800A549C, 0x31, 5, 321, 193, 3 };
FieldActorEntry D_800A56AC = { D_800A5604, D_800A54B4, 0x39, 6, 241, 217, 3 };
FieldActorEntry D_800A56C0 = { D_800A5610, D_800A54CC, 0x40, 7, 241, 217, 3 };
FieldActorEntry D_800A56D4 = { D_800A5618, D_800A54E4, 0x41, 8, 517, 289, 3 };
FieldActorEntry D_800A56E8 = { D_800A5620, D_800A54FC, 0x42, 9, 321, 193, 3 };
FieldActorEntry D_800A56FC = { D_800A5628, D_800A5514, 0x90, 0xA, 417, 201, 3 };
FieldActorEntry D_800A5710 = { NULL, NULL, 0x93, 0xB, 198, 184, 6 };
FieldActorEntry D_800A5724 = { NULL, NULL, 0x94, 0xC, 223, 172, 7 };
FieldActorEntry D_800A5738 = { NULL, NULL, 0x95, 0xD, 248, 160, 7 };
FieldActorEntry D_800A574C = { D_800A5630, D_800A552C, 0x9D, 0xE, 241, 217, 3 };
FieldActorEntry D_800A5760 = { D_800A563C, D_800A5544, 0x9D, 0xE, 241, 217, 3 };
FieldActorEntry D_800A5774 = { D_800A5644, D_800A555C, 0x9E, 0xF, 321, 193, 3 };
FieldActorEntry D_800A5788 = { D_800A5650, D_800A5574, 0x9E, 0xF, 321, 193, 3 };
FieldActorEntry D_800A579C = { D_800A5658, D_800A558C, 0x9F, 0x10, 517, 289, 1 };
FieldActorEntry D_800A57B0 = { D_800A5664, D_800A55A4, 0x9F, 0x10, 517, 289, 1 };
FieldActorEntry D_800A57C4 = { D_800A566C, D_800A55BC, 0xD2, 0x11, 417, 201, 3 };
FieldActorEntry D_800A57D8 = { D_800A5674, D_800A55D4, 0x119, 0x12, 520, 252, 3 };
FieldActorEntry D_800A57EC = { D_800A567C, NULL, 0x13C, 0x13, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5684,
    &D_800A5698,
    &D_800A56AC,
    &D_800A56C0,
    &D_800A56D4,
    &D_800A56E8,
    &D_800A56FC,
    &D_800A5710,
    &D_800A5724,
    &D_800A5738,
    &D_800A574C,
    &D_800A5760,
    &D_800A5774,
    &D_800A5788,
    &D_800A579C,
    &D_800A57B0,
    &D_800A57C4,
    &D_800A57D8,
    &D_800A57EC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 323, 114, 0, 0 },
    { 1, 0, 0xA0, 6, 0xA, 0, 0, 0, 0, 0, 367, 110, 0, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 205, 181, 199, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 237, 165, 183, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 270, 149, 167, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 186, 161, 199, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 218, 145, 183, 0 },
    { 1, 0, 0x40, 4, 0x33, 2, 0, 1, 4, 0, 252, 129, 167, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 521, 189, 272, 0 },
    { 1, 0, 0xA0, 4, 1, 0, 0, 0, 0, 0, 367, 110, 256, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 230, 243, 272, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 259, 221, 255, 0 },
    { 1, 0, 0x58, 4, 4, 0, 0, 0, 0, 0, 171, 118, 198, 0 },
    { 1, 0, 0x55, 4, 5, 0, 0, 0, 0, 0, 138, 106, 182, 0 },
    { 1, 0, 0x5C, 4, 6, 0, 0, 0, 0, 0, 263, 68, 153, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2AB, 0x32A, 0x9C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2AB, 0x238, 0x8C, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x1CE, 0xE6, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x1BE, 0x12E, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x220, 0x150, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x230, 0x1B8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 750, D_800A4F58, EVENT_TEXT(0x22), NULL, func_800A4D94 },
    { 751, D_800A503C, EVENT_TEXT(0x1E), NULL, func_800A4DE0 },
    { -1, NULL, 0, NULL, NULL },
};
