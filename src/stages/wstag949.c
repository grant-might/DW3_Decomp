#include "common.h"
#include "stage.h"
void func_800A5DE4();
extern s32 D_800A6174[][2];

/* Draws the 36 sprites of file 0x919 at their places, scrolling at 1/8 of the layer */
void func_800A5DE4(StageTask *task) {
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
            drawer.draw(FILE_CACHE.getEntry(0x9190000), 0, D_800A6174[i][0] + pos[0], D_800A6174[i][1] + pos[1]);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A5F38(void) {
    return createTask(func_800A5DE4, 0x50, 0);
}

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = func_800A5F38();
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

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x1BE;
    D_800990B4.sheetEntry = 0x9190000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x918;
    D_800990B4.start = (Vec2){0x1AF00, 0x3B400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xB;
    D_800990B4.music = 0x602C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, 0x9190002);
    D_8009A70C.setFile(1, 0x9190003);
    D_8009A70C.setFile(7, 0x9190004);
    D_8009A70C.setFile(4, 0x9190001);
    D_8009A70C.unk50(0);
}

extern u16 D_800A6334[];
extern u16 D_800A6340[];
extern u16 D_800A634C[];
extern u16 D_800A6358[];
extern u16 D_800A6368[];
extern u16 D_800A6374[];
extern u16 D_800A637C[];
extern u16 D_800A6388[];
extern u16 D_800A6390[];
extern u16 D_800A6398[];
extern u16 D_800A63A0[];
extern u16 D_800A63AC[];
extern u16 D_800A63B8[];
extern u16 D_800A63C4[];
extern u16 D_800A63CC[];
extern u16 D_800A63D8[];
extern u16 D_800A63E4[];
extern u16 D_800A64BC[];
extern FieldTalk D_800A63F0[];
extern u16 D_800A64C4[];
extern FieldTalk D_800A6408[];
extern FieldTalk D_800A6444[];
extern FieldTalk D_800A645C[];
extern FieldTalk D_800A648C[];
extern FieldActorEntry D_800A64CC;
extern FieldActorEntry D_800A64E0;
extern FieldActorEntry D_800A64F4;
extern FieldActorEntry D_800A6508;
extern FieldActorEntry D_800A651C;
extern Battle D_800A6678;
extern Battle D_800A6684;
extern Battle D_800A6690;
extern Battle D_800A669C;
extern Battle D_800A66A8;
extern Battle D_800A66B4;
extern Battle D_800A66C0;
extern Battle D_800A66CC;
extern Battle D_800A66FC;
extern Battle D_800A6708;
extern Battle D_800A6714;
extern Battle D_800A6720;
extern Battle D_800A672C;
extern Battle D_800A6738;
extern Battle D_800A6744;
extern Battle D_800A6750;
extern Battle D_800A6780;
extern Battle D_800A678C;
extern Battle D_800A6798;
extern Battle D_800A67A4;
extern Battle D_800A67B0;
extern Battle D_800A67BC;
extern Battle D_800A67C8;
extern Battle D_800A67D4;
extern Battle D_800A6804;
extern Battle D_800A6810;
extern Battle D_800A681C;
extern Battle D_800A6828;
extern Battle D_800A6834;
extern Battle D_800A6840;
extern Battle D_800A684C;
extern Battle D_800A6858;
extern BattleList D_800A66D8;
extern BattleList D_800A675C;
extern BattleList D_800A67E0;
extern BattleList D_800A6864;

s32 D_800A6174[][2] = {
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
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16A, 0x100, 0xA8, 0, 0x140, 0x1FF },
    { 0x140, 0x100, 0x15A, 0x100, 0x68, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x150, 0x100, 0x40, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x162, 0x100, 0x88, 0, 0x170, 0x1FF },
};
u16 D_800A6334[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A6340[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A634C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6358[] = { 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A6368[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6374[] = { 0, 1, 0xFFFF };
u16 D_800A637C[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A6388[] = { 0x7842, 1, 0xFFFF };
u16 D_800A6390[] = { 0x7C01, 1, 0xFFFF };
u16 D_800A6398[] = { 0x7096, 0, 0xFFFF };
u16 D_800A63A0[] = { 0x7096, 1, 0x100E, 0, 0xFFFF };
u16 D_800A63AC[] = { 0x7400, 1, 0x100E, 1, 0xFFFF };
u16 D_800A63B8[] = { 0x7096, 1, 0x100E, 1, 0xFFFF };
u16 D_800A63C4[] = { 0x7096, 0, 0xFFFF };
u16 D_800A63CC[] = { 0x7096, 1, 0x100F, 0, 0xFFFF };
u16 D_800A63D8[] = { 0x100F, 1, 0x7401, 1, 0xFFFF };
u16 D_800A63E4[] = { 0x7096, 1, 0x100F, 1, 0xFFFF };
FieldTalk D_800A63F0[] = {
    { NULL, NULL, 0x39 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6408[] = {
    { D_800A6334, D_800A6340, 0x3B },
    { D_800A634C, D_800A6358, 0x3C },
    { D_800A6368, D_800A6374, 0x39 },
    { D_800A637C, D_800A6388, 0x3A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6444[] = {
    { NULL, D_800A6390, 0x87 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A645C[] = {
    { D_800A6398, NULL, 0x81 },
    { D_800A63A0, D_800A63AC, 0x82 },
    { D_800A63B8, NULL, 0x83 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A648C[] = {
    { D_800A63C4, NULL, 0x84 },
    { D_800A63CC, D_800A63D8, 0x85 },
    { D_800A63E4, NULL, 0x86 },
    { NULL, NULL, 0 },
};
u16 D_800A64BC[] = { 0x8192, 0, 0xFFFF };
u16 D_800A64C4[] = { 0x8192, 1, 0xFFFF };
FieldActorEntry D_800A64CC = { D_800A64BC, D_800A63F0, 0x39, 4, 320, 344, 7 };
FieldActorEntry D_800A64E0 = { D_800A64C4, D_800A6408, 0x39, 4, 320, 344, 7 };
FieldActorEntry D_800A64F4 = { NULL, D_800A6444, 0x3D, 5, 97, 242, 1 };
FieldActorEntry D_800A6508 = { NULL, D_800A645C, 0x90, 6, 1073, 145, 1 };
FieldActorEntry D_800A651C = { NULL, D_800A648C, 0x91, 7, 520, 220, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A64CC,
    &D_800A64E0,
    &D_800A64F4,
    &D_800A6508,
    &D_800A651C,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 9000, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
Battle D_800A6678 = { 46, 7, 0x60080000 };
Battle D_800A6684 = { 46, 7, 0x60080000 };
Battle D_800A6690 = { 150, 7, 0x60080000 };
Battle D_800A669C = { 150, 7, 0x60080000 };
Battle D_800A66A8 = { 96, 7, 0x60080000 };
Battle D_800A66B4 = { 96, 7, 0x60080000 };
Battle D_800A66C0 = { 97, 7, 0x60080000 };
Battle D_800A66CC = { 97, 7, 0x60080000 };
BattleList D_800A66D8 = {
    3,
    { &D_800A6678, &D_800A6684, &D_800A6690, &D_800A669C,
      &D_800A66A8, &D_800A66B4, &D_800A66C0, &D_800A66CC },
};
Battle D_800A66FC = { 0, 0, 0x60040000 };
Battle D_800A6708 = { 0, 0, 0x60040000 };
Battle D_800A6714 = { 0, 0, 0x60040000 };
Battle D_800A6720 = { 0, 0, 0x60040000 };
Battle D_800A672C = { 0, 0, 0x60040000 };
Battle D_800A6738 = { 0, 0, 0x60040000 };
Battle D_800A6744 = { 0, 0, 0x60040000 };
Battle D_800A6750 = { 0, 0, 0x60040000 };
BattleList D_800A675C = {
    0,
    { &D_800A66FC, &D_800A6708, &D_800A6714, &D_800A6720,
      &D_800A672C, &D_800A6738, &D_800A6744, &D_800A6750 },
};
Battle D_800A6780 = { 0, 0, 0x60040000 };
Battle D_800A678C = { 0, 0, 0x60040000 };
Battle D_800A6798 = { 0, 0, 0x60040000 };
Battle D_800A67A4 = { 0, 0, 0x60040000 };
Battle D_800A67B0 = { 0, 0, 0x60040000 };
Battle D_800A67BC = { 0, 0, 0x60040000 };
Battle D_800A67C8 = { 0, 0, 0x60040000 };
Battle D_800A67D4 = { 0, 0, 0x60040000 };
BattleList D_800A67E0 = {
    0,
    { &D_800A6780, &D_800A678C, &D_800A6798, &D_800A67A4,
      &D_800A67B0, &D_800A67BC, &D_800A67C8, &D_800A67D4 },
};
Battle D_800A6804 = { 306, 18, 0x608C0000 };
Battle D_800A6810 = { 307, 18, 0x608C0000 };
Battle D_800A681C = { 0, 0, 0x60040000 };
Battle D_800A6828 = { 0, 0, 0x60040000 };
Battle D_800A6834 = { 0, 0, 0x60040000 };
Battle D_800A6840 = { 0, 0, 0x60040000 };
Battle D_800A684C = { 0, 0, 0x60040000 };
Battle D_800A6858 = { 0, 0, 0x60040000 };
BattleList D_800A6864 = {
    0,
    { &D_800A6804, &D_800A6810, &D_800A681C, &D_800A6828,
      &D_800A6834, &D_800A6840, &D_800A684C, &D_800A6858 },
};
FieldBattles stageBattles[] = {
    { 387, 0, 0, { &D_800A66D8, &D_800A675C, &D_800A67E0, &D_800A6864 } },
};
