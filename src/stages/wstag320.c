#include "common.h"
#include "stage.h"

/* Hides the map objects with animation 10 from story progress 0x16 on */
void updateStage(StageTask *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress >= 0x16) {
            for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
                if (tile->anim == 10) {
                    tile->visible = 0;
                }
            }
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#include "common/start_stage.inc.c"

/* Sets flag 0x800F */
void func_800A4DA8(void) {
    FLAGS_00.applyAction(0x800F, 1);
}

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x295
#define STAGE_ARCHIVE 0x317
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x2A4
#define STAGE_ARCHIVE 0x326
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x26F00, 0x1EF00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 6;
    D_800990B4.music = 0x60180000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
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

void func_800A4DA8();
extern Battle D_800A505C;
extern Battle D_800A5068;
extern Battle D_800A5074;
extern Battle D_800A5080;
extern Battle D_800A508C;
extern Battle D_800A5098;
extern Battle D_800A50A4;
extern Battle D_800A50B0;
extern Battle D_800A50E0;
extern Battle D_800A50EC;
extern Battle D_800A50F8;
extern Battle D_800A5104;
extern Battle D_800A5110;
extern Battle D_800A511C;
extern Battle D_800A5128;
extern Battle D_800A5134;
extern Battle D_800A5164;
extern Battle D_800A5170;
extern Battle D_800A517C;
extern Battle D_800A5188;
extern Battle D_800A5194;
extern Battle D_800A51A0;
extern Battle D_800A51AC;
extern Battle D_800A51B8;
extern Battle D_800A51E8;
extern Battle D_800A51F4;
extern Battle D_800A5200;
extern Battle D_800A520C;
extern Battle D_800A5218;
extern Battle D_800A5224;
extern Battle D_800A5230;
extern Battle D_800A523C;
extern BattleList D_800A50BC;
extern BattleList D_800A5140;
extern BattleList D_800A51C4;
extern BattleList D_800A5248;
extern u16 D_800A5338[];
extern u16 D_800A5348[];
extern u16 D_800A5350[];
extern u16 D_800A5358[];
extern u16 D_800A5364[];
extern u16 D_800A536C[];
extern u16 D_800A5378[];
extern u16 D_800A5388[];
extern u16 D_800A5390[];
extern u16 D_800A539C[];
extern u16 D_800A5548[];
extern FieldTalk D_800A53A4[];
extern u16 D_800A5550[];
extern FieldTalk D_800A53BC[];
extern u16 D_800A555C[];
extern FieldTalk D_800A53EC[];
extern u16 D_800A5564[];
extern FieldTalk D_800A5404[];
extern u16 D_800A556C[];
extern FieldTalk D_800A541C[];
extern u16 D_800A5574[];
extern FieldTalk D_800A5434[];
extern u16 D_800A557C[];
extern FieldTalk D_800A544C[];
extern u16 D_800A5584[];
extern FieldTalk D_800A5464[];
extern u16 D_800A558C[];
extern FieldTalk D_800A547C[];
extern u16 D_800A5594[];
extern FieldTalk D_800A5494[];
extern u16 D_800A559C[];
extern FieldTalk D_800A54AC[];
extern u16 D_800A55A4[];
extern FieldTalk D_800A54C4[];
extern u16 D_800A55AC[];
extern FieldTalk D_800A54DC[];
extern u16 D_800A55B4[];
extern FieldTalk D_800A54F4[];
extern u16 D_800A55C0[];
extern FieldTalk D_800A550C[];
extern u16 D_800A55CC[];
extern FieldTalk D_800A5530[];
extern FieldActorEntry D_800A55D4;
extern FieldActorEntry D_800A55E8;
extern FieldActorEntry D_800A55FC;
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
extern FieldActorEntry D_800A56D8;
extern FieldActorEntry D_800A56EC;
extern FieldActorEntry D_800A5700;
extern s16 D_800A4F50[];

s16 D_800A4F50[] = {
    0x600, 1, 2,
    0x102, 2, 0x181, 0xC1, 7,
    0x100, 0x37, 0x1A1, 0xD1,
    0x101, 0x37, 1, 3,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 7,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x37, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 3, 0x37, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 5, 0x37, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 6, 2, 0,
    0x101, 2, 7, 7,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 7, 0x37, 2,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x199, 0xB5, 5,
    0x302, 2,
    0x102, 2, 0x15D, 0x77, 3,
    0x300, 6,
    0x304, 0x20B, 0x240, 0x140, 3,
    0,
};
Battle D_800A505C = { 85, 7, 0x60080000 };
Battle D_800A5068 = { 85, 7, 0x60080000 };
Battle D_800A5074 = { 85, 7, 0x60080000 };
Battle D_800A5080 = { 85, 7, 0x60080000 };
Battle D_800A508C = { 86, 7, 0x60080000 };
Battle D_800A5098 = { 86, 7, 0x60080000 };
Battle D_800A50A4 = { 86, 7, 0x60080000 };
Battle D_800A50B0 = { 86, 7, 0x60080000 };
BattleList D_800A50BC = {
    4,
    { &D_800A505C, &D_800A5068, &D_800A5074, &D_800A5080,
      &D_800A508C, &D_800A5098, &D_800A50A4, &D_800A50B0 },
};
Battle D_800A50E0 = { 0, 0, 0x60040000 };
Battle D_800A50EC = { 0, 0, 0x60040000 };
Battle D_800A50F8 = { 0, 0, 0x60040000 };
Battle D_800A5104 = { 0, 0, 0x60040000 };
Battle D_800A5110 = { 0, 0, 0x60040000 };
Battle D_800A511C = { 0, 0, 0x60040000 };
Battle D_800A5128 = { 0, 0, 0x60040000 };
Battle D_800A5134 = { 0, 0, 0x60040000 };
BattleList D_800A5140 = {
    0,
    { &D_800A50E0, &D_800A50EC, &D_800A50F8, &D_800A5104,
      &D_800A5110, &D_800A511C, &D_800A5128, &D_800A5134 },
};
Battle D_800A5164 = { 0, 0, 0x60040000 };
Battle D_800A5170 = { 0, 0, 0x60040000 };
Battle D_800A517C = { 0, 0, 0x60040000 };
Battle D_800A5188 = { 0, 0, 0x60040000 };
Battle D_800A5194 = { 0, 0, 0x60040000 };
Battle D_800A51A0 = { 0, 0, 0x60040000 };
Battle D_800A51AC = { 0, 0, 0x60040000 };
Battle D_800A51B8 = { 0, 0, 0x60040000 };
BattleList D_800A51C4 = {
    0,
    { &D_800A5164, &D_800A5170, &D_800A517C, &D_800A5188,
      &D_800A5194, &D_800A51A0, &D_800A51AC, &D_800A51B8 },
};
Battle D_800A51E8 = { 0, 0, 0x60040000 };
Battle D_800A51F4 = { 0, 0, 0x60040000 };
Battle D_800A5200 = { 0, 0, 0x60040000 };
Battle D_800A520C = { 0, 0, 0x60040000 };
Battle D_800A5218 = { 0, 0, 0x60040000 };
Battle D_800A5224 = { 0, 0, 0x60040000 };
Battle D_800A5230 = { 0, 0, 0x60040000 };
Battle D_800A523C = { 0, 0, 0x60040000 };
BattleList D_800A5248 = {
    0,
    { &D_800A51E8, &D_800A51F4, &D_800A5200, &D_800A520C,
      &D_800A5218, &D_800A5224, &D_800A5230, &D_800A523C },
};
FieldBattles stageBattles[] = {
    { 49, 0, 0, { &D_800A50BC, &D_800A5140, &D_800A51C4, &D_800A5248 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B8, 0x100, 0x1E0, 0, 0x170, 0x1F5 },
    { 0x180, 0x100, 0x194, 0x150, 0x150, 0x50, 0x140, 0x1F4 },
    { 0x180, 0x100, 0x19E, 0x130, 0x178, 0x30, 0x160, 0x1F4 },
    { 0x180, 0x100, 0x19C, 0x150, 0x170, 0x50, 0x170, 0x1F4 },
    { 0x180, 0x100, 0x1A4, 0x170, 0x190, 0x70, 0x140, 0x1F3 },
};
u16 D_800A5338[] = { 0x708C, 1, 0x200, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5348[] = { 0x1A16, 0, 0xFFFF };
u16 D_800A5350[] = { 0x1A15, 1, 0xFFFF };
u16 D_800A5358[] = { 0x800F, 0, 0x1A16, 1, 0xFFFF };
u16 D_800A5364[] = { 0x9021, 1, 0xFFFF };
u16 D_800A536C[] = { 0x800F, 1, 0x1A16, 1, 0xFFFF };
u16 D_800A5378[] = { 0x7013, 1, 0x207, 1, 0x845E, 1, 0xFFFF };
u16 D_800A5388[] = { 0x8015, 0, 0xFFFF };
u16 D_800A5390[] = { 0x8015, 1, 0x7013, 1, 0xFFFF };
u16 D_800A539C[] = { 0x8015, 1, 0xFFFF };
FieldTalk D_800A53A4[] = {
    { NULL, D_800A5338, 0x453 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53BC[] = {
    { D_800A5348, D_800A5350, 0x54 },
    { D_800A5358, D_800A5364, 0x55 },
    { D_800A536C, NULL, 0x455 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53EC[] = {
    { NULL, NULL, 0x455 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5404[] = {
    { NULL, NULL, 0x456 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A541C[] = {
    { NULL, NULL, 0x45A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5434[] = {
    { NULL, NULL, 0x458 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A544C[] = {
    { NULL, NULL, 0x45D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5464[] = {
    { NULL, NULL, 0x455 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A547C[] = {
    { NULL, NULL, 0x459 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5494[] = {
    { NULL, NULL, 0x45B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54AC[] = {
    { NULL, NULL, 0x457 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54C4[] = {
    { NULL, D_800A5378, 0x44D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54DC[] = {
    { NULL, NULL, 0x89 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54F4[] = {
    { NULL, NULL, 0x53 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A550C[] = {
    { D_800A5388, D_800A5390, 0x56 },
    { D_800A539C, NULL, 0x57 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5530[] = {
    { NULL, NULL, 0x45C },
    { NULL, NULL, 0 },
};
u16 D_800A5548[] = { 0x200, 0, 0xFFFF };
u16 D_800A5550[] = { 0x600C, 1, 0x1A14, 1, 0xFFFF };
u16 D_800A555C[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5564[] = { 0x6014, 1, 0xFFFF };
u16 D_800A556C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5574[] = { 0x6016, 1, 0xFFFF };
u16 D_800A557C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5584[] = { 0x7016, 1, 0xFFFF };
u16 D_800A558C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5594[] = { 0x6026, 1, 0xFFFF };
u16 D_800A559C[] = { 0x6015, 1, 0xFFFF };
u16 D_800A55A4[] = { 0x207, 0, 0xFFFF };
u16 D_800A55AC[] = { 0x600A, 1, 0xFFFF };
u16 D_800A55B4[] = { 0x600C, 1, 0x1A14, 0, 0xFFFF };
u16 D_800A55C0[] = { 0x6009, 1, 0x1A1B, 1, 0xFFFF };
u16 D_800A55CC[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A55D4 = { D_800A5548, D_800A53A4, 0x21, 4, 465, 169, 1 };
FieldActorEntry D_800A55E8 = { D_800A5550, D_800A53BC, 0x37, 5, 417, 209, 7 };
FieldActorEntry D_800A55FC = { D_800A555C, D_800A53EC, 0x37, 5, 417, 209, 7 };
FieldActorEntry D_800A5610 = { D_800A5564, D_800A5404, 0x37, 5, 417, 209, 7 };
FieldActorEntry D_800A5624 = { D_800A556C, D_800A541C, 0x37, 5, 417, 209, 7 };
FieldActorEntry D_800A5638 = { D_800A5574, D_800A5434, 0x37, 5, 417, 209, 7 };
FieldActorEntry D_800A564C = { D_800A557C, D_800A544C, 0x37, 5, 417, 209, 7 };
FieldActorEntry D_800A5660 = { D_800A5584, D_800A5464, 0x37, 5, 417, 209, 7 };
FieldActorEntry D_800A5674 = { D_800A558C, D_800A547C, 0x37, 5, 417, 209, 7 };
FieldActorEntry D_800A5688 = { D_800A5594, D_800A5494, 0x37, 5, 417, 209, 7 };
FieldActorEntry D_800A569C = { D_800A559C, D_800A54AC, 0x37, 5, 417, 209, 7 };
FieldActorEntry D_800A56B0 = { D_800A55A4, D_800A54C4, 0x4D, 6, 272, 217, 1 };
FieldActorEntry D_800A56C4 = { D_800A55AC, D_800A54DC, 0x61, 7, 417, 209, 7 };
FieldActorEntry D_800A56D8 = { D_800A55B4, D_800A54F4, 0x61, 7, 417, 209, 7 };
FieldActorEntry D_800A56EC = { D_800A55C0, D_800A550C, 0x61, 7, 417, 209, 7 };
FieldActorEntry D_800A5700 = { D_800A55CC, D_800A5530, 0x9D, 8, 417, 209, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A55D4,
    &D_800A55E8,
    &D_800A55FC,
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
    &D_800A56D8,
    &D_800A56EC,
    &D_800A5700,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x47, 1, 0x47, 0x4C, 4, 0, 395, 311, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 1, 0x47, 0x4C, 4, 0, 871, 533, 0, 0 },
    { 1, 0, 0x40, 2, 0x47, 1, 0x47, 0x4C, 4, 0, 1037, 703, 0, 0 },
    { 1, 0, 0x40, 2, 0x4D, 2, 0, 3, 4, 0, 1012, 671, 0, 0 },
    { 1, 0, 0x40, 2, 0x52, 2, 0, 3, 8, 0, 442, 116, 0, 0 },
    { 1, 0, 0x40, 2, 0x52, 2, 0, 3, 8, 0, 473, 132, 0, 0 },
    { 1, 0, 0x40, 2, 0x53, 2, 0, 3, 4, 0, 299, 39, 0, 0 },
    { 1, 0, 0x40, 2, 0x5A, 0, 0, 0, 0, 0, 472, 396, 0, 0 },
    { 1, 0, 0x40, 2, 0x5E, 2, 0, 5, 4, 0, 871, 417, 0, 0 },
    { 1, 0, 0x40, 2, 0x5E, 2, 0, 5, 4, 0, 871, 449, 0, 0 },
    { 1, 0, 0x40, 2, 0x5E, 2, 0, 5, 4, 0, 871, 481, 0, 0 },
    { 1, 0, 0x40, 2, 0x5E, 2, 0, 5, 4, 0, 871, 513, 0, 0 },
    { 1, 0, 0x40, 2, 0x5E, 2, 0, 5, 4, 0, 871, 544, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 1, 0x47, 0x4C, 4, 0, 735, 465, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 2, 0, 3, 6, 0, 328, 658, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 2, 0, 3, 6, 0, 616, 802, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 2, 0, 3, 6, 0, 760, 730, 0, 0 },
    { 1, 0, 0x40, 6, 0x4E, 2, 0, 3, 6, 0, 904, 802, 0, 0 },
    { 1, 0, 0x40, 6, 0x4F, 2, 0, 3, 6, 0, 351, 643, 0, 0 },
    { 1, 0, 0x40, 6, 0x4F, 2, 0, 3, 6, 0, 639, 787, 0, 0 },
    { 1, 0, 0x40, 6, 0x4F, 2, 0, 3, 6, 0, 783, 715, 0, 0 },
    { 1, 0, 0x40, 6, 0x4F, 2, 0, 3, 6, 0, 927, 787, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 2, 0, 3, 6, 0, 324, 632, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 2, 0, 3, 6, 0, 612, 776, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 2, 0, 3, 6, 0, 756, 704, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 2, 0, 3, 6, 0, 900, 776, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 2, 0, 3, 6, 0, 305, 643, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 2, 0, 3, 6, 0, 593, 788, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 2, 0, 3, 6, 0, 737, 715, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 2, 0, 3, 6, 0, 881, 787, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 202, 416, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 210, 420, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 218, 424, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 226, 428, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 234, 432, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 242, 436, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 250, 440, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 258, 444, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 266, 352, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 274, 356, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 282, 360, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 290, 364, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 298, 368, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 306, 372, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 2, 0, 3, 8, 0, 314, 376, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 3, 8, 0, 322, 380, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 270, 444, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 278, 440, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 286, 436, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 294, 432, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 302, 428, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 310, 424, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 358, 400, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 366, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 374, 392, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 382, 388, 0, 0 },
    { 1, 0, 0x40, 6, 0x56, 2, 0, 3, 8, 0, 390, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 2, 0, 3, 8, 0, 349, 405, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 3, 4, 0, 439, 395, 0, 0 },
    { 1, 0, 0x40, 6, 0x59, 2, 0, 3, 4, 0, 540, 398, 0, 0 },
    { 1, 0, 0x40, 6, 0x5B, 2, 0, 3, 4, 0, 612, 416, 0, 0 },
    { 1, 0, 0x40, 6, 0x5F, 2, 0, 1, 4, 0, 646, 530, 0, 0 },
    { 1, 0, 0x40, 6, 0x5F, 2, 0, 1, 4, 0, 688, 509, 0, 0 },
    { 1, 0, 0x40, 6, 0x5F, 2, 0, 1, 4, 0, 790, 602, 0, 0 },
    { 1, 0, 0x40, 6, 0x5F, 2, 0, 1, 4, 0, 790, 746, 0, 0 },
    { 1, 0, 0x40, 6, 0x5F, 2, 0, 1, 4, 0, 832, 581, 0, 0 },
    { 1, 0, 0x40, 6, 0x5F, 2, 0, 1, 4, 0, 832, 725, 0, 0 },
    { 1, 0, 0x40, 6, 0x60, 2, 0, 1, 4, 0, 358, 674, 0, 0 },
    { 1, 0, 0x40, 6, 0x60, 2, 0, 1, 4, 0, 400, 653, 0, 0 },
    { 1, 0, 0x40, 6, 0x60, 2, 0, 1, 4, 0, 519, 754, 0, 0 },
    { 1, 0, 0x40, 6, 0x60, 2, 0, 1, 4, 0, 535, 458, 0, 0 },
    { 1, 0, 0x40, 6, 0x60, 2, 0, 1, 4, 0, 560, 733, 0, 0 },
    { 1, 0, 0x40, 6, 0x60, 2, 0, 1, 4, 0, 576, 437, 0, 0 },
    { 1, 0, 0x40, 6, 0x61, 2, 0, 1, 4, 0, 648, 724, 0, 0 },
    { 1, 0, 0x40, 6, 0x61, 2, 0, 1, 4, 0, 690, 746, 0, 0 },
    { 1, 0, 0x40, 6, 0x61, 2, 0, 1, 4, 0, 792, 653, 0, 0 },
    { 1, 0, 0x40, 6, 0x61, 2, 0, 1, 4, 0, 833, 674, 0, 0 },
    { 1, 0, 0x40, 6, 0x61, 2, 0, 1, 4, 0, 936, 725, 0, 0 },
    { 1, 0, 0x40, 6, 0x61, 2, 0, 1, 4, 0, 978, 746, 0, 0 },
    { 1, 0, 0x40, 6, 0x62, 2, 0, 1, 4, 0, 654, 640, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 102, 448, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 159, 484, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 174, 374, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 273, 382, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 390, 366, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 128, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 177, 460, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 209, 367, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 94, 418, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 194, 530, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 98, 495, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 546, 532, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 366, 486, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 1, 0x41, 0x43, 0xA, 0, 251, 381, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 70, 467, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 76, 433, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 129, 505, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 179, 534, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 186, 472, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 187, 526, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 263, 395, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 352, 473, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 393, 415, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 553, 516, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 956, 689, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 1, 0x44, 0x46, 0xA, 0, 966, 668, 0, 0 },
    { 1, 0xA, 0xA0, 6, 0, 0, 0, 0, 0, 0, 792, 381, 0, 0 },
    { 1, 0, 0x60, 6, 1, 0, 0, 0, 0, 0, 721, 691, 0, 0 },
    { 1, 0, 0x60, 6, 1, 0, 0, 0, 0, 0, 865, 763, 0, 0 },
    { 1, 0, 0x40, 6, 0x5E, 2, 0, 5, 4, 0, 775, 369, 0, 0 },
    { 1, 0, 0x40, 6, 0x5E, 2, 0, 5, 4, 0, 775, 401, 0, 0 },
    { 1, 0, 0x40, 6, 0x5E, 2, 0, 5, 4, 0, 775, 433, 0, 0 },
    { 1, 0, 0x40, 6, 0x5E, 2, 0, 5, 4, 0, 775, 465, 0, 0 },
    { 1, 0, 0x40, 6, 0x5E, 2, 0, 5, 4, 0, 775, 497, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x20, 1, 0x20, 0x22, 6, 0, 546, 665, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x20, 1, 0x20, 0x22, 6, 0, 833, 798, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2A, 1, 0x2A, 0x2D, 6, 0, 545, 558, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2A, 1, 0x2A, 0x2D, 6, 0, 834, 701, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x23, 1, 0x23, 0x25, 6, 0, -12, 814, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x23, 1, 0x23, 0x25, 6, 0, 0, 364, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x23, 1, 0x23, 0x25, 6, 0, 100, 758, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x23, 1, 0x23, 0x25, 6, 0, 212, 702, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x23, 1, 0x23, 0x25, 6, 0, 324, 646, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, -14, 713, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 99, 658, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 210, 602, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 322, 546, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x26, 1, 0x26, 0x29, 6, 0, 11, 408, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20B, 0x242, 0x13E, 3, 0, 0, 0 },
    { { { 0x703F, 1 }, { 0xFFFF, 0 } }, 1, 0x21A, 0x68, 0x304, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x21C, 0x88, 0x1B4, 5, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 2, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x130, 0xF8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x120, 0x140, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E0, 0x240, 0xD8, 1, 0, 2, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 290, D_800A4F50, EVENT_TEXT(2), NULL, func_800A4DA8 },
    { -1, NULL, 0, NULL, NULL },
};
