#include "common.h"
#include "stage.h"
void func_800A4CA8();
extern s32 D_800A5284[][2];

/* The file of the sprites, which the versions number differently */
#if VERSION_US
#define SPRITES 0x1B1
#elif VERSION_EU
#define SPRITES 0x1BF
#endif

/* Draws 36 sprites of file SPRITES at the positions of D_800A5284, scrolled at 1/8 */
void func_800A4CA8(StageTask *task) {
    SpriteDrawer drawer;
    s32 pos[2];
    s32 scroll[2];
    Layer *layer;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x1002, 0xC);
        drawer.setTexture(0x140, 0x100);
        drawer.setAltClut(0, 0x1F0);
        layer = GFX.funcs.getLayer(0x1002);
        layer->getScroll(layer, scroll);
        pos[0] = (scroll[0] - 0x2C0) >> 3;
        pos[1] = (scroll[1] - 0x280) >> 3;
        for (i = 0; i < 0x24; i++) {
            drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), 0, D_800A5284[i][0] + pos[0], D_800A5284[i][1] + pos[1]);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A4DFC(void) {
    return createTask(func_800A4CA8, 0x50, 0);
}

/* Creates the stage helper task, and the event object when flag 0x4053 is set and 0x4054 is not */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = func_800A4DFC();
        if (FLAGS_00.checkCondition(0x4053, 1) && FLAGS_00.checkCondition(0x4054, 0)) {
            children[1] = FIELDSTG_startEvent(0x4ED);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 0x8
#include "common/start_stage.inc.c"

void func_800A4F38(void) {
    FLAGS_00.applyAction(0x4053, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Applies flag actions 0x868D and 0x4054 */
void func_800A4F84(void) {
    FLAGS_00.applyAction(0x868D, 1);
    FLAGS_00.applyAction(0x4054, 1);
}

extern FieldBattles D_800A57C4[];
extern FieldBattles D_800A57E0[];
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x1B1
#define STAGE_ARCHIVE 0x2C2
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x1BF
#define STAGE_ARCHIVE 0x2D1
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x1AF00, 0x3B400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xB;
    D_800990B4.music = 0x602C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(1, STAGE_FILE << 16 | 4);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress < 0xE) {
        D_800990B4.battles = D_800A57C4;
    } else {
        D_800990B4.battles = D_800A57E0;
    }
}

void func_800A4F84();
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
extern Battle D_800A5530;
extern Battle D_800A553C;
extern Battle D_800A5548;
extern Battle D_800A5554;
extern Battle D_800A5560;
extern Battle D_800A556C;
extern Battle D_800A5578;
extern Battle D_800A5584;
extern Battle D_800A55B4;
extern Battle D_800A55C0;
extern Battle D_800A55CC;
extern Battle D_800A55D8;
extern Battle D_800A55E4;
extern Battle D_800A55F0;
extern Battle D_800A55FC;
extern Battle D_800A5608;
extern Battle D_800A5638;
extern Battle D_800A5644;
extern Battle D_800A5650;
extern Battle D_800A565C;
extern Battle D_800A5668;
extern Battle D_800A5674;
extern Battle D_800A5680;
extern Battle D_800A568C;
extern Battle D_800A56BC;
extern Battle D_800A56C8;
extern Battle D_800A56D4;
extern Battle D_800A56E0;
extern Battle D_800A56EC;
extern Battle D_800A56F8;
extern Battle D_800A5704;
extern Battle D_800A5710;
extern Battle D_800A5740;
extern Battle D_800A574C;
extern Battle D_800A5758;
extern Battle D_800A5764;
extern Battle D_800A5770;
extern Battle D_800A577C;
extern Battle D_800A5788;
extern Battle D_800A5794;
extern BattleList D_800A5404;
extern BattleList D_800A5488;
extern BattleList D_800A550C;
extern BattleList D_800A5590;
extern BattleList D_800A5614;
extern BattleList D_800A5698;
extern BattleList D_800A571C;
extern BattleList D_800A57A0;
extern u16 D_800A58DC[];
extern u16 D_800A58E4[];
extern u16 D_800A58F0[];
extern u16 D_800A58F8[];
extern u16 D_800A5900[];
extern u16 D_800A5908[];
extern u16 D_800A5914[];
extern u16 D_800A5924[];
extern u16 D_800A592C[];
extern u16 D_800A593C[];
extern u16 D_800A5944[];
extern u16 D_800A5950[];
extern u16 D_800A5958[];
extern u16 D_800A5960[];
extern u16 D_800A5968[];
extern u16 D_800A5974[];
extern u16 D_800A5984[];
extern u16 D_800A598C[];
extern u16 D_800A599C[];
extern u16 D_800A59A4[];
extern u16 D_800A59B0[];
extern u16 D_800A59B8[];
extern u16 D_800A59C0[];
extern u16 D_800A59CC[];
extern u16 D_800A59D4[];
extern u16 D_800A59DC[];
extern u16 D_800A59E8[];
extern u16 D_800A59F0[];
extern u16 D_800A59F8[];
extern u16 D_800A5A04[];
extern u16 D_800A5A0C[];
extern u16 D_800A5A14[];
extern u16 D_800A5A20[];
extern u16 D_800A5A28[];
extern u16 D_800A5A30[];
extern u16 D_800A5A3C[];
extern u16 D_800A5A44[];
extern u16 D_800A5A4C[];
extern u16 D_800A5A58[];
extern u16 D_800A5A60[];
extern u16 D_800A5A68[];
extern u16 D_800A5A74[];
extern u16 D_800A5A7C[];
extern u16 D_800A5A84[];
extern u16 D_800A5A90[];
extern u16 D_800A5A98[];
extern u16 D_800A5AA0[];
extern u16 D_800A5AAC[];
extern u16 D_800A5AB4[];
extern u16 D_800A5ABC[];
extern u16 D_800A5AC8[];
extern u16 D_800A5AD0[];
extern u16 D_800A5AD8[];
extern u16 D_800A5AE4[];
extern u16 D_800A5AF0[];
extern u16 D_800A5AFC[];
extern u16 D_800A5B04[];
extern u16 D_800A5B10[];
extern u16 D_800A5B18[];
extern u16 D_800A5B24[];
extern u16 D_800A5B30[];
extern u16 D_800A5B40[];
extern u16 D_800A5B48[];
extern u16 D_800A5B5C[];
extern u16 D_800A5B70[];
extern u16 D_800A5B7C[];
extern u16 D_800A5F08[];
extern FieldTalk D_800A5B84[];
extern u16 D_800A5F14[];
extern FieldTalk D_800A5B9C[];
extern u16 D_800A5F20[];
extern FieldTalk D_800A5BB4[];
extern u16 D_800A5F2C[];
extern FieldTalk D_800A5BD8[];
extern u16 D_800A5F38[];
extern FieldTalk D_800A5C14[];
extern u16 D_800A5F44[];
extern FieldTalk D_800A5C38[];
extern u16 D_800A5F50[];
extern FieldTalk D_800A5C74[];
extern u16 D_800A5F58[];
extern FieldTalk D_800A5C98[];
extern u16 D_800A5F60[];
extern FieldTalk D_800A5CBC[];
extern u16 D_800A5F68[];
extern FieldTalk D_800A5CE0[];
extern u16 D_800A5F70[];
extern FieldTalk D_800A5D04[];
extern u16 D_800A5F78[];
extern FieldTalk D_800A5D28[];
extern u16 D_800A5F80[];
extern FieldTalk D_800A5D4C[];
extern u16 D_800A5F88[];
extern FieldTalk D_800A5D70[];
extern u16 D_800A5F90[];
extern FieldTalk D_800A5D94[];
extern u16 D_800A5F98[];
extern FieldTalk D_800A5DB8[];
extern u16 D_800A5FA0[];
extern FieldTalk D_800A5DDC[];
extern u16 D_800A5FA8[];
extern FieldTalk D_800A5E00[];
extern u16 D_800A5FB4[];
extern FieldTalk D_800A5E30[];
extern u16 D_800A5FBC[];
extern FieldTalk D_800A5E60[];
extern u16 D_800A5FC4[];
extern FieldTalk D_800A5E78[];
extern u16 D_800A5FCC[];
extern FieldTalk D_800A5E90[];
extern u16 D_800A5FD4[];
extern FieldTalk D_800A5ED8[];
extern u16 D_800A5FE0[];
extern FieldTalk D_800A5EF0[];
extern FieldActorEntry D_800A5FE8;
extern FieldActorEntry D_800A5FFC;
extern FieldActorEntry D_800A6010;
extern FieldActorEntry D_800A6024;
extern FieldActorEntry D_800A6038;
extern FieldActorEntry D_800A604C;
extern FieldActorEntry D_800A6060;
extern FieldActorEntry D_800A6074;
extern FieldActorEntry D_800A6088;
extern FieldActorEntry D_800A609C;
extern FieldActorEntry D_800A60B0;
extern FieldActorEntry D_800A60C4;
extern FieldActorEntry D_800A60D8;
extern FieldActorEntry D_800A60EC;
extern FieldActorEntry D_800A6100;
extern FieldActorEntry D_800A6114;
extern FieldActorEntry D_800A6128;
extern FieldActorEntry D_800A613C;
extern FieldActorEntry D_800A6150;
extern FieldActorEntry D_800A6164;
extern FieldActorEntry D_800A6178;
extern FieldActorEntry D_800A618C;
extern FieldActorEntry D_800A61A0;
extern FieldActorEntry D_800A61B4;
extern s16 D_800A5140[];
extern s16 D_800A51E0[];

s16 D_800A5140[] = {
    0x600, 1, 2,
    0x102, 2, 0x414, 0x9F, 5,
    0x100, 0x3B, 0x431, 0x91,
    0x101, 0x3B, 1, 1,
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
    0x200, 0, 2, 0x3B, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x3B, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x640\n");
#endif
s16 D_800A51E0[] = {
    0x600, 1, 2,
    0x100, 2, 0x414, 0x9F,
    0x101, 2, 1, 5,
    0x100, 0x3B, 0x431, 0x91,
    0x101, 0x3B, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x3B, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x3B, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x3C,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x3B, 0,
    0x301,
    0x300, 0x3C,
    0,
};
s32 D_800A5284[][2] = {
    596, 399, 809, 564,
    820, 832, 1143, 1009,
    738, 1035, 416, 1055,
    36, 28, 140, 0,
    178, 159, 218, 202,
    186, 242, 299, 93,
    418, 16, 440, 329,
    476, 369, 725, 82,
    1137, 24, 1213, 103,
    1281, 147, 1349, 48,
    669, 632, 491, 796,
    661, 889, 624, 926,
    998, 634, 1026, 648,
    890, 940, 915, 959,
    826, 1119, 1028, 1089,
    1227, 1002, 1306, 861,
    498, 1190, 146, 569,
    187, 590, 394, 616,
};
Battle D_800A53A4 = { 47, 7, 0x60080000 };
Battle D_800A53B0 = { 47, 7, 0x60080000 };
Battle D_800A53BC = { 47, 7, 0x60080000 };
Battle D_800A53C8 = { 47, 7, 0x60080000 };
Battle D_800A53D4 = { 45, 7, 0x60080000 };
Battle D_800A53E0 = { 45, 7, 0x60080000 };
Battle D_800A53EC = { 45, 7, 0x60080000 };
Battle D_800A53F8 = { 45, 7, 0x60080000 };
BattleList D_800A5404 = {
    3,
    { &D_800A53A4, &D_800A53B0, &D_800A53BC, &D_800A53C8,
      &D_800A53D4, &D_800A53E0, &D_800A53EC, &D_800A53F8 },
};
Battle D_800A5428 = { 0, 7, 0x60080000 };
Battle D_800A5434 = { 0, 7, 0x60080000 };
Battle D_800A5440 = { 0, 7, 0x60080000 };
Battle D_800A544C = { 0, 7, 0x60080000 };
Battle D_800A5458 = { 0, 7, 0x60080000 };
Battle D_800A5464 = { 0, 7, 0x60080000 };
Battle D_800A5470 = { 0, 7, 0x60080000 };
Battle D_800A547C = { 0, 7, 0x60080000 };
BattleList D_800A5488 = {
    0,
    { &D_800A5428, &D_800A5434, &D_800A5440, &D_800A544C,
      &D_800A5458, &D_800A5464, &D_800A5470, &D_800A547C },
};
Battle D_800A54AC = { 0, 0, 0x60040000 };
Battle D_800A54B8 = { 0, 0, 0x60040000 };
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
Battle D_800A5530 = { 1, 19, 0x60880000 };
Battle D_800A553C = { 309, 19, 0x60880000 };
Battle D_800A5548 = { 0, 0, 0x60040000 };
Battle D_800A5554 = { 0, 0, 0x60040000 };
Battle D_800A5560 = { 0, 0, 0x60040000 };
Battle D_800A556C = { 47, 7, 0x60080000 };
Battle D_800A5578 = { 0, 0, 0x60040000 };
Battle D_800A5584 = { 0, 0, 0x60040000 };
BattleList D_800A5590 = {
    0,
    { &D_800A5530, &D_800A553C, &D_800A5548, &D_800A5554,
      &D_800A5560, &D_800A556C, &D_800A5578, &D_800A5584 },
};
Battle D_800A55B4 = { 47, 7, 0x60080000 };
Battle D_800A55C0 = { 45, 7, 0x60080000 };
Battle D_800A55CC = { 46, 7, 0x60080000 };
Battle D_800A55D8 = { 46, 7, 0x60080000 };
Battle D_800A55E4 = { 46, 7, 0x60080000 };
Battle D_800A55F0 = { 46, 7, 0x60080000 };
Battle D_800A55FC = { 46, 7, 0x60080000 };
Battle D_800A5608 = { 46, 7, 0x60080000 };
BattleList D_800A5614 = {
    3,
    { &D_800A55B4, &D_800A55C0, &D_800A55CC, &D_800A55D8,
      &D_800A55E4, &D_800A55F0, &D_800A55FC, &D_800A5608 },
};
Battle D_800A5638 = { 0, 7, 0x60080000 };
Battle D_800A5644 = { 0, 7, 0x60080000 };
Battle D_800A5650 = { 0, 7, 0x60080000 };
Battle D_800A565C = { 0, 7, 0x60080000 };
Battle D_800A5668 = { 0, 7, 0x60080000 };
Battle D_800A5674 = { 0, 7, 0x60080000 };
Battle D_800A5680 = { 0, 7, 0x60080000 };
Battle D_800A568C = { 0, 7, 0x60080000 };
BattleList D_800A5698 = {
    0,
    { &D_800A5638, &D_800A5644, &D_800A5650, &D_800A565C,
      &D_800A5668, &D_800A5674, &D_800A5680, &D_800A568C },
};
Battle D_800A56BC = { 0, 0, 0x60040000 };
Battle D_800A56C8 = { 0, 0, 0x60040000 };
Battle D_800A56D4 = { 0, 0, 0x60040000 };
Battle D_800A56E0 = { 0, 0, 0x60040000 };
Battle D_800A56EC = { 0, 0, 0x60040000 };
Battle D_800A56F8 = { 0, 0, 0x60040000 };
Battle D_800A5704 = { 0, 0, 0x60040000 };
Battle D_800A5710 = { 0, 0, 0x60040000 };
BattleList D_800A571C = {
    0,
    { &D_800A56BC, &D_800A56C8, &D_800A56D4, &D_800A56E0,
      &D_800A56EC, &D_800A56F8, &D_800A5704, &D_800A5710 },
};
Battle D_800A5740 = { 1, 19, 0x60880000 };
Battle D_800A574C = { 309, 19, 0x60880000 };
Battle D_800A5758 = { 0, 0, 0x60040000 };
Battle D_800A5764 = { 0, 0, 0x60040000 };
Battle D_800A5770 = { 0, 0, 0x60040000 };
Battle D_800A577C = { 47, 7, 0x60080000 };
Battle D_800A5788 = { 0, 0, 0x60040000 };
Battle D_800A5794 = { 0, 0, 0x60040000 };
BattleList D_800A57A0 = {
    0,
    { &D_800A5740, &D_800A574C, &D_800A5758, &D_800A5764,
      &D_800A5770, &D_800A577C, &D_800A5788, &D_800A5794 },
};
FieldBattles D_800A57C4[] = {
    { 11, 0, 0, { &D_800A5404, &D_800A5488, &D_800A550C, &D_800A5590 } },
};
FieldBattles D_800A57E0[] = {
    { 30, 1, 0, { &D_800A5614, &D_800A5698, &D_800A571C, &D_800A57A0 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x162, 0x128, 0x88, 0x28, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16A, 0x128, 0xA8, 0x28, 0x140, 0x1FE },
    { 0x140, 0x100, 0x15A, 0x100, 0x68, 0, 0x150, 0x1FE },
    { 0x140, 0x100, 0x150, 0x100, 0x40, 0, 0x160, 0x1FE },
    { 0x140, 0x100, 0x162, 0x100, 0x88, 0, 0x170, 0x1FE },
    { 0x140, 0x100, 0x16A, 0x100, 0xA8, 0, 0x140, 0x1FD },
    { 0x140, 0x100, 0x150, 0x130, 0x40, 0x30, 0x150, 0x1FD },
    { 0x140, 0x100, 0x172, 0x140, 0xC8, 0x40, 0x160, 0x1FD },
};
u16 D_800A58DC[] = { 0x700D, 0, 0xFFFF };
u16 D_800A58E4[] = { 0x7013, 1, 0x7032, 1, 0xFFFF };
u16 D_800A58F0[] = { 0x700D, 1, 0xFFFF };
u16 D_800A58F8[] = { 0x1A29, 0, 0xFFFF };
u16 D_800A5900[] = { 0x1A29, 1, 0xFFFF };
u16 D_800A5908[] = { 0x1A29, 1, 0x702B, 0, 0xFFFF };
u16 D_800A5914[] = { 0x1A29, 1, 0x702B, 1, 0x7025, 0, 0xFFFF };
u16 D_800A5924[] = { 0x607, 1, 0xFFFF };
u16 D_800A592C[] = { 0x1A29, 1, 0x702B, 1, 0x7025, 1, 0xFFFF };
u16 D_800A593C[] = { 0x700D, 0, 0xFFFF };
u16 D_800A5944[] = { 0x7013, 1, 0x7032, 1, 0xFFFF };
u16 D_800A5950[] = { 0x700D, 1, 0xFFFF };
u16 D_800A5958[] = { 0x1A29, 0, 0xFFFF };
u16 D_800A5960[] = { 0x1A29, 1, 0xFFFF };
u16 D_800A5968[] = { 0x1A29, 1, 0x702B, 0, 0xFFFF };
u16 D_800A5974[] = { 0x1A29, 1, 0x702B, 1, 0x7025, 0, 0xFFFF };
u16 D_800A5984[] = { 0x607, 1, 0xFFFF };
u16 D_800A598C[] = { 0x1A29, 1, 0x702B, 1, 0x7025, 1, 0xFFFF };
u16 D_800A599C[] = { 0xA00, 0, 0xFFFF };
u16 D_800A59A4[] = { 0xA00, 1, 0x9035, 1, 0xFFFF };
u16 D_800A59B0[] = { 0xA00, 1, 0xFFFF };
u16 D_800A59B8[] = { 0xA00, 0, 0xFFFF };
u16 D_800A59C0[] = { 0xA00, 1, 0x9035, 1, 0xFFFF };
u16 D_800A59CC[] = { 0xA00, 1, 0xFFFF };
u16 D_800A59D4[] = { 0xA00, 0, 0xFFFF };
u16 D_800A59DC[] = { 0xA00, 1, 0x9035, 1, 0xFFFF };
u16 D_800A59E8[] = { 0xA00, 1, 0xFFFF };
u16 D_800A59F0[] = { 0xA00, 0, 0xFFFF };
u16 D_800A59F8[] = { 0xA00, 1, 0x9035, 1, 0xFFFF };
u16 D_800A5A04[] = { 0xA00, 1, 0xFFFF };
u16 D_800A5A0C[] = { 0xA00, 0, 0xFFFF };
u16 D_800A5A14[] = { 0xA00, 1, 0x9035, 1, 0xFFFF };
u16 D_800A5A20[] = { 0xA00, 1, 0xFFFF };
u16 D_800A5A28[] = { 0xA00, 0, 0xFFFF };
u16 D_800A5A30[] = { 0xA00, 1, 0x9035, 1, 0xFFFF };
u16 D_800A5A3C[] = { 0xA00, 1, 0xFFFF };
u16 D_800A5A44[] = { 0xA00, 0, 0xFFFF };
u16 D_800A5A4C[] = { 0xA00, 1, 0x9035, 1, 0xFFFF };
u16 D_800A5A58[] = { 0xA00, 1, 0xFFFF };
u16 D_800A5A60[] = { 0xA00, 0, 0xFFFF };
u16 D_800A5A68[] = { 0xA00, 1, 0x9035, 1, 0xFFFF };
u16 D_800A5A74[] = { 0xA00, 1, 0xFFFF };
u16 D_800A5A7C[] = { 0xA00, 0, 0xFFFF };
u16 D_800A5A84[] = { 0xA00, 1, 0x9035, 1, 0xFFFF };
u16 D_800A5A90[] = { 0xA00, 1, 0xFFFF };
u16 D_800A5A98[] = { 0xA00, 0, 0xFFFF };
u16 D_800A5AA0[] = { 0xA00, 1, 0x9035, 1, 0xFFFF };
u16 D_800A5AAC[] = { 0xA00, 1, 0xFFFF };
u16 D_800A5AB4[] = { 0xA00, 0, 0xFFFF };
u16 D_800A5ABC[] = { 0x9035, 1, 0xA00, 1, 0xFFFF };
u16 D_800A5AC8[] = { 0xA00, 1, 0xFFFF };
u16 D_800A5AD0[] = { 0x1C0F, 0, 0xFFFF };
u16 D_800A5AD8[] = { 0x1C0F, 1, 5, 0, 0xFFFF };
u16 D_800A5AE4[] = { 0x1C10, 1, 5, 1, 0xFFFF };
u16 D_800A5AF0[] = { 0x1C0F, 1, 5, 1, 0xFFFF };
u16 D_800A5AFC[] = { 0x1A17, 0, 0xFFFF };
u16 D_800A5B04[] = { 0x1A17, 1, 0x1A18, 0, 0xFFFF };
u16 D_800A5B10[] = { 0x1A18, 1, 0xFFFF };
u16 D_800A5B18[] = { 0x1A17, 1, 0x1A18, 1, 0xFFFF };
u16 D_800A5B24[] = { 0x800E, 0, 0x1A2B, 0, 0xFFFF };
u16 D_800A5B30[] = { 0x800E, 0, 0x1A2B, 1, 0x1C4F, 0, 0xFFFF };
u16 D_800A5B40[] = { 0x1C4F, 1, 0xFFFF };
u16 D_800A5B48[] = { 0x825A, 0, 0x800E, 0, 0x1A2B, 1, 0x1C4F, 1, 0xFFFF };
u16 D_800A5B5C[] = { 0x800E, 0, 0x1A2B, 1, 0x825A, 1, 0x1C4F, 1, 0xFFFF };
u16 D_800A5B70[] = { 0x7013, 1, 0x800E, 1, 0xFFFF };
u16 D_800A5B7C[] = { 0x800E, 1, 0xFFFF };
FieldTalk D_800A5B84[] = {
    { NULL, NULL, 0xED },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B9C[] = {
    { NULL, NULL, 0xEF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BB4[] = {
    { D_800A58DC, D_800A58E4, 0x2A5 },
    { D_800A58F0, NULL, 0x2A7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BD8[] = {
    { D_800A58F8, D_800A5900, 0x2A3 },
    { D_800A5908, NULL, 0x2A8 },
    { D_800A5914, D_800A5924, 0x2A4 },
    { D_800A592C, NULL, 0x2A9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C14[] = {
    { D_800A593C, D_800A5944, 0x2A5 },
    { D_800A5950, NULL, 0x2A7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C38[] = {
    { D_800A5958, D_800A5960, 0x2A3 },
    { D_800A5968, NULL, 0x2A8 },
    { D_800A5974, D_800A5984, 0x2A4 },
    { D_800A598C, NULL, 0x2A9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C74[] = {
    { D_800A599C, D_800A59A4, 0xEB },
    { D_800A59B0, NULL, 0x1B8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C98[] = {
    { D_800A59B8, D_800A59C0, 0xEB },
    { D_800A59CC, NULL, 0x1B0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CBC[] = {
    { D_800A59D4, D_800A59DC, 0xEB },
    { D_800A59E8, NULL, 0x1B1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CE0[] = {
    { D_800A59F0, D_800A59F8, 0xEB },
    { D_800A5A04, NULL, 0x1B2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D04[] = {
    { D_800A5A0C, D_800A5A14, 0xEB },
    { D_800A5A20, NULL, 0x1B3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D28[] = {
    { D_800A5A28, D_800A5A30, 0xEB },
    { D_800A5A3C, NULL, 0x1B4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D4C[] = {
    { D_800A5A44, D_800A5A4C, 0xEB },
    { D_800A5A58, NULL, 0x1B5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D70[] = {
    { D_800A5A60, D_800A5A68, 0xEB },
    { D_800A5A74, NULL, 0x1B6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D94[] = {
    { D_800A5A7C, D_800A5A84, 0xEB },
    { D_800A5A90, NULL, 0x1B7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DB8[] = {
    { D_800A5A98, D_800A5AA0, 0xEB },
    { D_800A5AAC, NULL, 0x1AF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DDC[] = {
    { D_800A5AB4, D_800A5ABC, 0xEB },
    { D_800A5AC8, NULL, 0x2E8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E00[] = {
    { D_800A5AD0, NULL, 0xEC },
    { D_800A5AD8, D_800A5AE4, 0x2DA },
    { D_800A5AF0, NULL, 0x2DB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E30[] = {
    { D_800A5AFC, NULL, 0x2AA },
    { D_800A5B04, D_800A5B10, 0x2AB },
    { D_800A5B18, NULL, 0x2AC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E60[] = {
    { NULL, NULL, 0x2AC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E78[] = {
    { NULL, NULL, 0x2AD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E90[] = {
    { D_800A5B24, NULL, 0x2AE },
    { D_800A5B30, D_800A5B40, 0x2AF },
    { D_800A5B48, NULL, 4 },
    { D_800A5B5C, D_800A5B70, 0x2B0 },
    { D_800A5B7C, NULL, 0x2B1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5ED8[] = {
    { NULL, NULL, 0xEE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EF0[] = {
    { NULL, NULL, 0x2A6 },
    { NULL, NULL, 0 },
};
u16 D_800A5F08[] = { 0x1C11, 0, 0x6004, 1, 0xFFFF };
u16 D_800A5F14[] = { 0x1C11, 0, 0x6004, 1, 0xFFFF };
u16 D_800A5F20[] = { 0x703B, 1, 0x8023, 1, 0xFFFF };
u16 D_800A5F2C[] = { 0x602B, 1, 0x8023, 0, 0xFFFF };
u16 D_800A5F38[] = { 0x602B, 1, 0x8023, 1, 0xFFFF };
u16 D_800A5F44[] = { 0x8023, 0, 0x703B, 1, 0xFFFF };
u16 D_800A5F50[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5F58[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5F60[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5F68[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5F70[] = { 0x7017, 1, 0xFFFF };
u16 D_800A5F78[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5F80[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5F88[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5F90[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5F98[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5FA0[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5FA8[] = { 0x1C11, 0, 0x6004, 1, 0xFFFF };
u16 D_800A5FB4[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5FBC[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5FC4[] = { 0x703C, 1, 0xFFFF };
u16 D_800A5FCC[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5FD4[] = { 0x1C11, 0, 0x6004, 1, 0xFFFF };
u16 D_800A5FE0[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A5FE8 = { D_800A5F08, D_800A5B84, 0x22, 4, 505, 213, 7 };
FieldActorEntry D_800A5FFC = { D_800A5F14, D_800A5B9C, 0x23, 5, 480, 225, 7 };
FieldActorEntry D_800A6010 = { D_800A5F20, D_800A5BB4, 0x2B, 6, 304, 328, 1 };
FieldActorEntry D_800A6024 = { D_800A5F2C, D_800A5BD8, 0x2B, 6, 304, 328, 1 };
FieldActorEntry D_800A6038 = { D_800A5F38, D_800A5C14, 0x2B, 6, 304, 328, 1 };
FieldActorEntry D_800A604C = { D_800A5F44, D_800A5C38, 0x2B, 6, 304, 328, 1 };
FieldActorEntry D_800A6060 = { D_800A5F50, D_800A5C74, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A6074 = { D_800A5F58, D_800A5C98, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A6088 = { D_800A5F60, D_800A5CBC, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A609C = { D_800A5F68, D_800A5CE0, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A60B0 = { D_800A5F70, D_800A5D04, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A60C4 = { D_800A5F78, D_800A5D28, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A60D8 = { D_800A5F80, D_800A5D4C, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A60EC = { D_800A5F88, D_800A5D70, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A6100 = { D_800A5F90, D_800A5D94, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A6114 = { D_800A5F98, D_800A5DB8, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A6128 = { D_800A5FA0, D_800A5DDC, 0x3B, 7, 1073, 145, 1 };
FieldActorEntry D_800A613C = { D_800A5FA8, D_800A5E00, 0x3C, 8, 560, 240, 3 };
FieldActorEntry D_800A6150 = { D_800A5FB4, D_800A5E30, 0x3D, 9, 97, 242, 7 };
FieldActorEntry D_800A6164 = { D_800A5FBC, D_800A5E60, 0x3D, 9, 97, 242, 7 };
FieldActorEntry D_800A6178 = { D_800A5FC4, D_800A5E78, 0x3D, 9, 97, 242, 7 };
FieldActorEntry D_800A618C = { D_800A5FCC, D_800A5E90, 0x3D, 9, 97, 242, 7 };
FieldActorEntry D_800A61A0 = { D_800A5FD4, D_800A5ED8, 0x40, 0xA, 529, 201, 7 };
FieldActorEntry D_800A61B4 = { D_800A5FE0, D_800A5EF0, 0x9D, 0xB, 304, 328, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5FE8,
    &D_800A5FFC,
    &D_800A6010,
    &D_800A6024,
    &D_800A6038,
    &D_800A604C,
    &D_800A6060,
    &D_800A6074,
    &D_800A6088,
    &D_800A609C,
    &D_800A60B0,
    &D_800A60C4,
    &D_800A60D8,
    &D_800A60EC,
    &D_800A6100,
    &D_800A6114,
    &D_800A6128,
    &D_800A613C,
    &D_800A6150,
    &D_800A6164,
    &D_800A6178,
    &D_800A618C,
    &D_800A61A0,
    &D_800A61B4,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x225, 0x510, 0x88, 1, 0, 0, 0 },
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
    { 1260, D_800A5140, EVENT_TEXT(0x1B), NULL, func_800A4F38 },
    { 1261, D_800A51E0, EVENT_TEXT(0x1C), NULL, func_800A4F84 },
    { 9000, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
