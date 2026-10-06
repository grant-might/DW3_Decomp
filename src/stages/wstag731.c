#include "common.h"
#include "stage.h"
extern AnimFrame D_800A50A0[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;
    s32 frame;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A50A0[0].duration;
        break;
    case TASK_RUN:
        tile = D_800990B4.objects;
        frame = stepLoopingAnimation(&task->anims[0], D_800A50A0, 0);
        for (; tile->unk2 != 0; tile++) {
            if (tile->anim == 1) {
                tile->frame = frame;
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *createTileAnims(void) {
    return createTask(updateTileAnims, 0x54, 0);
}

#include "common/update_stage_tile_anims.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6B8
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6C7
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xCE00, 0xDD00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 8;
    D_800990B4.music = 0x60200000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A513C[];
extern u16 D_800A5144[];
extern u16 D_800A514C[];
extern u16 D_800A5158[];
extern u16 D_800A5160[];
extern u16 D_800A5170[];
extern u16 D_800A5180[];
extern u16 D_800A5194[];
extern u16 D_800A519C[];
extern u16 D_800A51A8[];
extern u16 D_800A51B0[];
extern u16 D_800A51C0[];
extern u16 D_800A51D0[];
extern u16 D_800A51E4[];
extern u16 D_800A51EC[];
extern u16 D_800A51F8[];
extern u16 D_800A5200[];
extern u16 D_800A5210[];
extern u16 D_800A5220[];
extern u16 D_800A5234[];
extern u16 D_800A523C[];
extern u16 D_800A5248[];
extern u16 D_800A5250[];
extern u16 D_800A5260[];
extern u16 D_800A5270[];
extern u16 D_800A5284[];
extern u16 D_800A528C[];
extern u16 D_800A5298[];
extern u16 D_800A52A0[];
extern u16 D_800A52B0[];
extern u16 D_800A52C0[];
extern FieldTalk D_800A52D4[];
extern u16 D_800A54A8[];
extern FieldTalk D_800A52EC[];
extern u16 D_800A54B4[];
extern FieldTalk D_800A5304[];
extern u16 D_800A54C0[];
extern FieldTalk D_800A5340[];
extern u16 D_800A54D0[];
extern FieldTalk D_800A5358[];
extern u16 D_800A54E0[];
extern FieldTalk D_800A5394[];
extern u16 D_800A54F4[];
extern FieldTalk D_800A53AC[];
extern u16 D_800A5508[];
extern FieldTalk D_800A53E8[];
extern u16 D_800A5520[];
extern FieldTalk D_800A5400[];
extern u16 D_800A5538[];
extern FieldTalk D_800A543C[];
extern u16 D_800A5554[];
extern FieldTalk D_800A5454[];
extern u16 D_800A5570[];
extern FieldTalk D_800A5490[];
extern FieldActorEntry D_800A5588;
extern FieldActorEntry D_800A559C;
extern FieldActorEntry D_800A55B0;
extern FieldActorEntry D_800A55C4;
extern FieldActorEntry D_800A55D8;
extern FieldActorEntry D_800A55EC;
extern FieldActorEntry D_800A5600;
extern FieldActorEntry D_800A5614;
extern FieldActorEntry D_800A5628;
extern FieldActorEntry D_800A563C;
extern FieldActorEntry D_800A5650;
extern FieldActorEntry D_800A5664;
extern s16 D_800A502C[];

s16 D_800A502C[] = {
    0x102, 2, 0x1AD, 0xCE, 5,
    0x100, 0x15, 0x1CD, 0xBE,
    0x101, 0x15, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 3,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 3,
    0x300, 0x5A,
    0x304, 0xC10, 0, 0, 0,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x350\n");
#endif
AnimFrame D_800A50A0[] = {
    { 53, 8 }, { 54, 8 }, { 55, 8 }, { 56, 4 },
    { 57, 40 }, { 58, 8 }, { 255, 0 },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x172, 0x13C, 0xC8, 0x3C, 0x170, 0x1FC },
    { 0x140, 0x100, 0x160, 0x1D4, 0x80, 0xD4, 0x150, 0x1FB },
};
u16 D_800A513C[] = { 0x9016, 1, 0xFFFF };
u16 D_800A5144[] = { 0x869C, 1, 0xFFFF };
u16 D_800A514C[] = { 0x869C, 0, 0, 0, 0xFFFF };
u16 D_800A5158[] = { 0, 1, 0xFFFF };
u16 D_800A5160[] = { 0x869C, 0, 0, 1, 0x8498, 0, 0xFFFF };
u16 D_800A5170[] = { 0x869C, 0, 0, 1, 0x8498, 1, 0xFFFF };
u16 D_800A5180[] = { 0x869C, 1, 0x869B, 0, 0x8498, 0, 0x7013, 1, 0xFFFF };
u16 D_800A5194[] = { 0x8690, 1, 0xFFFF };
u16 D_800A519C[] = { 0x8690, 0, 1, 0, 0xFFFF };
u16 D_800A51A8[] = { 1, 1, 0xFFFF };
u16 D_800A51B0[] = { 0x8690, 0, 1, 1, 0x848C, 0, 0xFFFF };
u16 D_800A51C0[] = { 0x8690, 0, 1, 1, 0x848C, 1, 0xFFFF };
u16 D_800A51D0[] = { 0x8690, 1, 0x868F, 0, 0x848C, 0, 0x7013, 1, 0xFFFF };
u16 D_800A51E4[] = { 0x8677, 1, 0xFFFF };
u16 D_800A51EC[] = { 0x8677, 0, 2, 0, 0xFFFF };
u16 D_800A51F8[] = { 2, 1, 0xFFFF };
u16 D_800A5200[] = { 0x8677, 0, 2, 1, 0x8473, 0, 0xFFFF };
u16 D_800A5210[] = { 0x8677, 0, 2, 1, 0x8473, 1, 0xFFFF };
u16 D_800A5220[] = { 0x8677, 1, 0x8676, 0, 0x8473, 0, 0x7013, 1, 0xFFFF };
u16 D_800A5234[] = { 0x8683, 1, 0xFFFF };
u16 D_800A523C[] = { 0x8683, 0, 3, 0, 0xFFFF };
u16 D_800A5248[] = { 3, 1, 0xFFFF };
u16 D_800A5250[] = { 0x8683, 0, 3, 1, 0x847F, 0, 0xFFFF };
u16 D_800A5260[] = { 0x8683, 0, 3, 1, 0x847F, 1, 0xFFFF };
u16 D_800A5270[] = { 0x8683, 1, 0x8682, 0, 0x847F, 0, 0x7013, 1, 0xFFFF };
u16 D_800A5284[] = { 0x8669, 1, 0xFFFF };
u16 D_800A528C[] = { 0x8669, 0, 4, 0, 0xFFFF };
u16 D_800A5298[] = { 4, 1, 0xFFFF };
u16 D_800A52A0[] = { 0x8669, 0, 4, 1, 0x8465, 0, 0xFFFF };
u16 D_800A52B0[] = { 0x8669, 0, 4, 1, 0x8465, 1, 0xFFFF };
u16 D_800A52C0[] = { 0x8669, 1, 0x8668, 0, 0x8465, 0, 0x7013, 1, 0xFFFF };
FieldTalk D_800A52D4[] = {
    { NULL, D_800A513C, 0x2CF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52EC[] = {
    { NULL, NULL, 0x2D1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5304[] = {
    { D_800A5144, NULL, 0x30A },
    { D_800A514C, D_800A5158, 0x30B },
    { D_800A5160, NULL, 0x30C },
    { D_800A5170, D_800A5180, 0x30D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5340[] = {
    { NULL, NULL, 0x316 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5358[] = {
    { D_800A5194, NULL, 0x30E },
    { D_800A519C, D_800A51A8, 0x30F },
    { D_800A51B0, NULL, 0x310 },
    { D_800A51C0, D_800A51D0, 0x311 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5394[] = {
    { NULL, NULL, 0x317 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53AC[] = {
    { D_800A51E4, NULL, 0x312 },
    { D_800A51EC, D_800A51F8, 0x313 },
    { D_800A5200, NULL, 0x314 },
    { D_800A5210, D_800A5220, 0x315 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53E8[] = {
    { NULL, NULL, 0x318 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5400[] = {
    { D_800A5234, NULL, 0x319 },
    { D_800A523C, D_800A5248, 0x31A },
    { D_800A5250, NULL, 0x31B },
    { D_800A5260, D_800A5270, 0x31C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A543C[] = {
    { NULL, NULL, 0x31D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5454[] = {
    { D_800A5284, NULL, 0x31F },
    { D_800A528C, D_800A5298, 0x320 },
    { D_800A52A0, NULL, 0x321 },
    { D_800A52B0, D_800A52C0, 0x322 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5490[] = {
    { NULL, NULL, 0x31E },
    { NULL, NULL, 0 },
};
u16 D_800A54A8[] = { 0x869B, 0, 0x869C, 0, 0xFFFF };
u16 D_800A54B4[] = { 0x869B, 1, 0x869C, 0, 0xFFFF };
u16 D_800A54C0[] = { 0x868F, 0, 0x869C, 1, 0x8690, 0, 0xFFFF };
u16 D_800A54D0[] = { 0x869C, 1, 0x868F, 1, 0x8690, 0, 0xFFFF };
u16 D_800A54E0[] = { 0x869C, 1, 0x8690, 1, 0x8676, 0, 0x8677, 0, 0xFFFF };
u16 D_800A54F4[] = { 0x869C, 1, 0x8690, 1, 0x8676, 1, 0x8677, 0, 0xFFFF };
u16 D_800A5508[] = {
    0x869C, 1, 0x8690, 1, 0x8677, 1, 0x8682, 0,
    0x8683, 0, 0xFFFF,
};
u16 D_800A5520[] = {
    0x869C, 1, 0x8690, 1, 0x8677, 1, 0x8682, 1,
    0x8683, 0, 0xFFFF,
};
u16 D_800A5538[] = {
    0x8668, 0, 0x869C, 1, 0x8690, 1, 0x8677, 1,
    0x8683, 1, 0x8669, 0, 0xFFFF,
};
u16 D_800A5554[] = {
    0x869C, 1, 0x8690, 1, 0x8677, 1, 0x8683, 1,
    0x8668, 1, 0x8669, 0, 0xFFFF,
};
u16 D_800A5570[] = {
    0x869C, 1, 0x8690, 1, 0x8677, 1, 0x8683, 1,
    0x8669, 1, 0xFFFF,
};
FieldActorEntry D_800A5588 = { NULL, D_800A52D4, 0x15, 4, 461, 190, 1 };
FieldActorEntry D_800A559C = { D_800A54A8, D_800A52EC, 0xC1, 5, 304, 176, 1 };
FieldActorEntry D_800A55B0 = { D_800A54B4, D_800A5304, 0xC1, 5, 304, 176, 1 };
FieldActorEntry D_800A55C4 = { D_800A54C0, D_800A5340, 0xC1, 5, 304, 176, 1 };
FieldActorEntry D_800A55D8 = { D_800A54D0, D_800A5358, 0xC1, 5, 304, 176, 1 };
FieldActorEntry D_800A55EC = { D_800A54E0, D_800A5394, 0xC1, 5, 304, 176, 1 };
FieldActorEntry D_800A5600 = { D_800A54F4, D_800A53AC, 0xC1, 5, 304, 176, 1 };
FieldActorEntry D_800A5614 = { D_800A5508, D_800A53E8, 0xC1, 5, 304, 176, 1 };
FieldActorEntry D_800A5628 = { D_800A5520, D_800A5400, 0xC1, 5, 304, 176, 1 };
FieldActorEntry D_800A563C = { D_800A5538, D_800A543C, 0xC1, 5, 304, 176, 1 };
FieldActorEntry D_800A5650 = { D_800A5554, D_800A5454, 0xC1, 5, 304, 176, 1 };
FieldActorEntry D_800A5664 = { D_800A5570, D_800A5490, 0xC1, 5, 304, 176, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5588,
    &D_800A559C,
    &D_800A55B0,
    &D_800A55C4,
    &D_800A55D8,
    &D_800A55EC,
    &D_800A5600,
    &D_800A5614,
    &D_800A5628,
    &D_800A563C,
    &D_800A5650,
    &D_800A5664,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x34, 2, 0, 5, 6, 0, 124, 112, 0, 0 },
    { 1, 0, 0x40, 2, 0x34, 2, 0, 5, 6, 0, 187, 83, 0, 0 },
    { 1, 0, 0x40, 2, 0x41, 2, 0, 3, 6, 0, 470, 34, 0, 0 },
    { 1, 0, 0x56, 2, 1, 0, 0, 0, 0, 0, 335, 60, 0, 0 },
    { 1, 1, 0x80, 6, 0x35, 0, 0, 0, 0, 0, 518, 136, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 284, 28, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 286, 62, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 313, 43, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 315, 77, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 342, 57, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 3, 6, 0, 345, 92, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 289, 26, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 291, 60, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 317, 40, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 319, 74, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 346, 54, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 348, 89, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 312, 144, 195, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D0, 0x318, 0xAC, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1236, D_800A502C, EVENT_TEXT(5), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
