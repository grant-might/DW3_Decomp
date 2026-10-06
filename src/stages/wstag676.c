#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 34 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress == 0x22 && FLAGS_00.checkCondition(0x405A, 1)) {
            children[0] = FIELDSTG_startEvent(0x385);
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

void func_800A4D88(void) {
    FLAGS_00.applyAction(0x405A, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Moves the story to 0x23 and sets flag 0x8018 */
void func_800A4DD4(void) {
    GAME.progress = 0x23;
    FLAGS_00.applyAction(0x8018, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x652
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x662
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x14E00, 0x1E900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x17;
    D_800990B4.music = 0x605C0000;
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

void func_800A4DD4();
extern Battle D_800A5078;
extern Battle D_800A5084;
extern Battle D_800A5090;
extern Battle D_800A509C;
extern Battle D_800A50A8;
extern Battle D_800A50B4;
extern Battle D_800A50C0;
extern Battle D_800A50CC;
extern Battle D_800A50FC;
extern Battle D_800A5108;
extern Battle D_800A5114;
extern Battle D_800A5120;
extern Battle D_800A512C;
extern Battle D_800A5138;
extern Battle D_800A5144;
extern Battle D_800A5150;
extern Battle D_800A5180;
extern Battle D_800A518C;
extern Battle D_800A5198;
extern Battle D_800A51A4;
extern Battle D_800A51B0;
extern Battle D_800A51BC;
extern Battle D_800A51C8;
extern Battle D_800A51D4;
extern Battle D_800A5204;
extern Battle D_800A5210;
extern Battle D_800A521C;
extern Battle D_800A5228;
extern Battle D_800A5234;
extern Battle D_800A5240;
extern Battle D_800A524C;
extern Battle D_800A5258;
extern BattleList D_800A50D8;
extern BattleList D_800A515C;
extern BattleList D_800A51E0;
extern BattleList D_800A5264;
extern u16 D_800A53C4[];
extern u16 D_800A53CC[];
extern u16 D_800A53D4[];
extern u16 D_800A53DC[];
extern u16 D_800A53E4[];
extern u16 D_800A53EC[];
extern u16 D_800A53F4[];
extern u16 D_800A53FC[];
extern u16 D_800A5404[];
extern u16 D_800A540C[];
extern u16 D_800A5414[];
extern u16 D_800A5560[];
extern FieldTalk D_800A541C[];
extern u16 D_800A5568[];
extern FieldTalk D_800A5434[];
extern u16 D_800A5570[];
extern FieldTalk D_800A544C[];
extern u16 D_800A5578[];
extern FieldTalk D_800A5464[];
extern u16 D_800A5580[];
extern FieldTalk D_800A5488[];
extern u16 D_800A5588[];
extern FieldTalk D_800A54AC[];
extern u16 D_800A5590[];
extern FieldTalk D_800A54D0[];
extern u16 D_800A5598[];
extern FieldTalk D_800A54F4[];
extern u16 D_800A55A0[];
extern FieldTalk D_800A550C[];
extern u16 D_800A55A8[];
extern FieldTalk D_800A5524[];
extern u16 D_800A55B0[];
extern FieldTalk D_800A5548[];
extern u16 D_800A55BC[];
extern FieldActorEntry D_800A55C4;
extern FieldActorEntry D_800A55D8;
extern FieldActorEntry D_800A55EC;
extern FieldActorEntry D_800A5600;
extern FieldActorEntry D_800A5614;
extern FieldActorEntry D_800A5628;
extern FieldActorEntry D_800A563C;
extern FieldActorEntry D_800A5650;
extern FieldActorEntry D_800A5664;
extern FieldActorEntry D_800A5678;
extern FieldActorEntry D_800A568C;
extern FieldActorEntry D_800A56A0;
extern s16 D_800A4F50[];
extern s16 D_800A4FEC[];

s16 D_800A4F50[] = {
    0x600, 1, 2,
    0x102, 2, 0x160, 0xA9, 3,
    0x100, 0xD2, 0x140, 0x99,
    0x101, 0xD2, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 2, 0xD2, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 4, 0xD2, 2,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x2407\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x3\n");
#endif
s16 D_800A4FEC[] = {
    0x100, 2, 0x160, 0xA9,
    0x101, 2, 1, 3,
    0x100, 0x13C, 0x140, 0x99,
    0x101, 0x13C, 1, 5,
    0x300, 0x78,
    0x200, 0, 1, 2, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x148, 0x9D, 3,
    0x302, 2,
    0x300, 0x1E,
    0x100, 0x13C, 0, 0,
    0x101, 0x13C, 1, 5,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x1A0, 0xC9, 7,
    0x300, 0x1E,
    0x304, 0x2C6, 0x46C, 0xAA, 1,
    0,
};
Battle D_800A5078 = { 0, 0, 0x60040000 };
Battle D_800A5084 = { 0, 0, 0x60040000 };
Battle D_800A5090 = { 0, 0, 0x60040000 };
Battle D_800A509C = { 0, 0, 0x60040000 };
Battle D_800A50A8 = { 0, 0, 0x60040000 };
Battle D_800A50B4 = { 0, 0, 0x60040000 };
Battle D_800A50C0 = { 0, 0, 0x60040000 };
Battle D_800A50CC = { 0, 0, 0x60040000 };
BattleList D_800A50D8 = {
    0,
    { &D_800A5078, &D_800A5084, &D_800A5090, &D_800A509C,
      &D_800A50A8, &D_800A50B4, &D_800A50C0, &D_800A50CC },
};
Battle D_800A50FC = { 0, 0, 0x60040000 };
Battle D_800A5108 = { 0, 0, 0x60040000 };
Battle D_800A5114 = { 0, 0, 0x60040000 };
Battle D_800A5120 = { 0, 0, 0x60040000 };
Battle D_800A512C = { 0, 0, 0x60040000 };
Battle D_800A5138 = { 0, 0, 0x60040000 };
Battle D_800A5144 = { 0, 0, 0x60040000 };
Battle D_800A5150 = { 0, 0, 0x60040000 };
BattleList D_800A515C = {
    0,
    { &D_800A50FC, &D_800A5108, &D_800A5114, &D_800A5120,
      &D_800A512C, &D_800A5138, &D_800A5144, &D_800A5150 },
};
Battle D_800A5180 = { 0, 0, 0x60040000 };
Battle D_800A518C = { 0, 0, 0x60040000 };
Battle D_800A5198 = { 0, 0, 0x60040000 };
Battle D_800A51A4 = { 0, 0, 0x60040000 };
Battle D_800A51B0 = { 0, 0, 0x60040000 };
Battle D_800A51BC = { 0, 0, 0x60040000 };
Battle D_800A51C8 = { 0, 0, 0x60040000 };
Battle D_800A51D4 = { 0, 0, 0x60040000 };
BattleList D_800A51E0 = {
    0,
    { &D_800A5180, &D_800A518C, &D_800A5198, &D_800A51A4,
      &D_800A51B0, &D_800A51BC, &D_800A51C8, &D_800A51D4 },
};
Battle D_800A5204 = { 25, 18, 0x608C0000 };
Battle D_800A5210 = { 307, 18, 0x608C0000 };
Battle D_800A521C = { 0, 0, 0x60040000 };
Battle D_800A5228 = { 0, 0, 0x60040000 };
Battle D_800A5234 = { 0, 0, 0x60040000 };
Battle D_800A5240 = { 0, 0, 0x60040000 };
Battle D_800A524C = { 0, 0, 0x60040000 };
Battle D_800A5258 = { 0, 0, 0x60040000 };
BattleList D_800A5264 = {
    0,
    { &D_800A5204, &D_800A5210, &D_800A521C, &D_800A5228,
      &D_800A5234, &D_800A5240, &D_800A524C, &D_800A5258 },
};
FieldBattles stageBattles[] = {
    { 152, 0, 0, { &D_800A50D8, &D_800A515C, &D_800A51E0, &D_800A5264 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B4, 0x128, 0x1D0, 0x28, 0x170, 0x1FE },
    { 0x180, 0x100, 0x19C, 0x128, 0x170, 0x28, 0x140, 0x1FD },
    { 0x180, 0x100, 0x1A4, 0x128, 0x190, 0x28, 0x150, 0x1FD },
    { 0x180, 0x100, 0x180, 0x150, 0x100, 0x50, 0x160, 0x1FD },
    { 0x180, 0x100, 0x188, 0x150, 0x120, 0x50, 0x170, 0x1FD },
    { 0x180, 0x100, 0x198, 0x158, 0x160, 0x58, 0x140, 0x1FC },
    { 0x180, 0x100, 0x194, 0x128, 0x150, 0x28, 0x150, 0x1FC },
    { 0x180, 0x100, 0x1AC, 0x128, 0x1B0, 0x28, 0x160, 0x1FC },
    { 0x180, 0x100, 0x190, 0x150, 0x140, 0x50, 0x170, 0x1FC },
    { 0x140, 0x100, 0x148, 0x186, 0x20, 0x86, 0x140, 0x1FB },
    { 0x140, 0x100, 0x152, 0x186, 0x48, 0x86, 0x150, 0x1FB },
    { 0x140, 0x100, 0x16C, 0x1E8, 0xB0, 0xE8, 0x160, 0x1FB },
};
u16 D_800A53C4[] = { 0x405A, 0, 0xFFFF };
u16 D_800A53CC[] = { 0x405A, 1, 0xFFFF };
u16 D_800A53D4[] = { 0x405A, 0, 0xFFFF };
u16 D_800A53DC[] = { 0x405A, 1, 0xFFFF };
u16 D_800A53E4[] = { 0x405A, 0, 0xFFFF };
u16 D_800A53EC[] = { 0x405A, 1, 0xFFFF };
u16 D_800A53F4[] = { 0x405A, 0, 0xFFFF };
u16 D_800A53FC[] = { 0x405A, 1, 0xFFFF };
u16 D_800A5404[] = { 0x8192, 0, 0xFFFF };
u16 D_800A540C[] = { 0x8192, 1, 0xFFFF };
u16 D_800A5414[] = { 0x7A49, 1, 0xFFFF };
FieldTalk D_800A541C[] = {
    { NULL, NULL, 0x157 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5434[] = {
    { NULL, NULL, 0x158 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A544C[] = {
    { NULL, NULL, 0x159 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5464[] = {
    { D_800A53C4, NULL, 0x1EE },
    { D_800A53CC, NULL, 0x1EF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5488[] = {
    { D_800A53D4, NULL, 0x1F0 },
    { D_800A53DC, NULL, 0x1F1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54AC[] = {
    { D_800A53E4, NULL, 0x1F2 },
    { D_800A53EC, NULL, 0x1F3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54D0[] = {
    { D_800A53F4, NULL, 0x1F4 },
    { D_800A53FC, NULL, 0x1F5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54F4[] = {
    { NULL, NULL, 0x15A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A550C[] = {
    { NULL, NULL, 0x156 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5524[] = {
    { D_800A5404, NULL, 0x20D },
    { D_800A540C, D_800A5414, 0x1A7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5548[] = {
    { NULL, NULL, 0x155 },
    { NULL, NULL, 0 },
};
u16 D_800A5560[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5568[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5570[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5578[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5580[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5588[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5590[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5598[] = { 0x602B, 1, 0xFFFF };
u16 D_800A55A0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A55A8[] = { 0x7094, 1, 0xFFFF };
u16 D_800A55B0[] = { 0x405A, 0, 0x6022, 1, 0xFFFF };
u16 D_800A55BC[] = { 0x6022, 1, 0xFFFF };
FieldActorEntry D_800A55C4 = { D_800A5560, D_800A541C, 0x25, 4, 345, 470, 3 };
FieldActorEntry D_800A55D8 = { D_800A5568, D_800A5434, 0x26, 5, 296, 445, 7 };
FieldActorEntry D_800A55EC = { D_800A5570, D_800A544C, 0x27, 6, 297, 470, 5 };
FieldActorEntry D_800A5600 = { D_800A5578, D_800A5464, 0x46, 7, 345, 470, 3 };
FieldActorEntry D_800A5614 = { D_800A5580, D_800A5488, 0x47, 8, 296, 445, 7 };
FieldActorEntry D_800A5628 = { D_800A5588, D_800A54AC, 0x48, 9, 297, 470, 5 };
FieldActorEntry D_800A563C = { D_800A5590, D_800A54D0, 0x49, 0xA, 344, 446, 1 };
FieldActorEntry D_800A5650 = { D_800A5598, D_800A54F4, 0x6F, 0xB, 344, 446, 1 };
FieldActorEntry D_800A5664 = { D_800A55A0, D_800A550C, 0x91, 0xC, 320, 153, 7 };
FieldActorEntry D_800A5678 = { D_800A55A8, D_800A5524, 0xCE, 0xD, 509, 563, 3 };
FieldActorEntry D_800A568C = { D_800A55B0, D_800A5548, 0xD2, 0xE, 320, 153, 7 };
FieldActorEntry D_800A56A0 = { D_800A55BC, NULL, 0x13C, 0xF, 0, 0, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A55C4,
    &D_800A55D8,
    &D_800A55EC,
    &D_800A5600,
    &D_800A5614,
    &D_800A5628,
    &D_800A563C,
    &D_800A5650,
    &D_800A5664,
    &D_800A5678,
    &D_800A568C,
    &D_800A56A0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x50, 2, 0x2F, 0, 0, 0, 0, 0, 718, 505, 0, 0 },
    { 1, 0, 0x50, 2, 0x2F, 0, 0, 0, 0, 0, 815, 456, 0, 0 },
    { 1, 0, 0x40, 2, 0x30, 2, 0, 1, 0xA, 0, 625, 376, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x35, 0xA, 0, 719, 451, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x35, 0xA, 0, 815, 343, 0, 0 },
    { 1, 0, 0x40, 2, 0x3E, 1, 0x3E, 0x47, 6, 0, 637, 147, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 1, 0x48, 0x51, 6, 0, 769, 352, 0, 0 },
    { 1, 0, 0x50, 6, 0x2E, 0, 0, 0, 0, 0, 182, 516, 0, 0 },
    { 1, 0, 0x40, 6, 0x30, 2, 0, 1, 0xA, 0, 157, 372, 0, 0 },
    { 1, 0, 0x40, 6, 0x30, 2, 0, 1, 0xA, 0, 213, 344, 0, 0 },
    { 1, 0, 0x40, 6, 0x30, 2, 0, 1, 0xA, 0, 221, 194, 0, 0 },
    { 1, 0, 0x40, 6, 0x30, 2, 0, 1, 0xA, 0, 549, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x30, 2, 0, 1, 0xA, 0, 742, 201, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x35, 0xA, 0, 182, 460, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 1, 0x36, 0x39, 8, 0, 91, 349, 0, 0 },
    { 1, 0, 0x40, 6, 0x52, 1, 0x52, 0x5B, 6, 0, 487, 434, 0, 0 },
    { 1, 0, 0x40, 6, 0x5C, 1, 0x5C, 0x5F, 0xA, 0, 661, 151, 0, 0 },
    { 1, 0, 0x40, 6, 0x5C, 1, 0x5C, 0x5F, 0xA, 0, 780, 357, 0, 0 },
    { 1, 0, 0x40, 6, 0x60, 1, 0x60, 0x63, 0xA, 0, 504, 449, 0, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 249, 99, 171, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 287, 425, 455, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 511, 525, 552, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C6, 0x46C, 0xAA, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2C8, 0xA8, 0xA4, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x2C0, 0x100, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x2B0, 0x148, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x210, 0x118, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x200, 0x160, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x1C0, 0x180, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x1B0, 0x1C8, 0, 0, 0, 0 },
    { { { 0x6022, 1 }, { 0x405A, 0 } }, 8, 0x384, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 900, D_800A4F50, EVENT_TEXT(0x19), NULL, func_800A4D88 },
    { 901, D_800A4FEC, EVENT_TEXT(0x1A), NULL, func_800A4DD4 },
    { -1, NULL, 0, NULL, NULL },
};
