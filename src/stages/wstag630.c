#include "common.h"
#include "stage.h"
extern AnimFrame D_800A50F8[];
extern AnimFrame D_800A512C[];
extern AnimFrame D_800A5160[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    s32 frames[3];
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A50F8[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A512C[0].duration;
        task->anims[2].index = 0;
        task->anims[2].timer = D_800A5160[0].duration;
        break;
    case TASK_RUN:
        tile = D_800990B4.objects;
        frames[0] = stepLoopingAnimation(&task->anims[0], D_800A50F8, 0);
        frames[1] = stepLoopingAnimation(&task->anims[1], D_800A512C, 0);
        frames[2] = stepLoopingAnimation(&task->anims[2], D_800A5160, 0);
        for (; tile->unk2 != 0; tile++) {
            switch (tile->anim) {
            case 1:
                tile->frame = frames[0];
                break;
            case 2:
                tile->frame = frames[1];
                break;
            case 3:
                tile->frame = frames[2];
                break;
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *createTileAnims(void) {
    return createTask(updateTileAnims, 0x5C, 0);
}

#include "common/update_stage_tile_anims.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x484
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x494
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1AF00, 0x11800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x38;
    D_800990B4.music = 0x60E00000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A5190;
extern Battle D_800A519C;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A5214;
extern Battle D_800A5220;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5298;
extern Battle D_800A52A4;
extern Battle D_800A52B0;
extern Battle D_800A52BC;
extern Battle D_800A52C8;
extern Battle D_800A52D4;
extern Battle D_800A52E0;
extern Battle D_800A52EC;
extern Battle D_800A531C;
extern Battle D_800A5328;
extern Battle D_800A5334;
extern Battle D_800A5340;
extern Battle D_800A534C;
extern Battle D_800A5358;
extern Battle D_800A5364;
extern Battle D_800A5370;
extern BattleList D_800A51F0;
extern BattleList D_800A5274;
extern BattleList D_800A52F8;
extern BattleList D_800A537C;
extern u16 D_800A543C[];
extern u16 D_800A5444[];
extern u16 D_800A544C[];
extern u16 D_800A5454[];
extern u16 D_800A545C[];
extern u16 D_800A5464[];
extern u16 D_800A546C[];
extern u16 D_800A5474[];
extern u16 D_800A547C[];
extern u16 D_800A5484[];
extern u16 D_800A548C[];
extern u16 D_800A5494[];
extern u16 D_800A549C[];
extern u16 D_800A54A4[];
extern u16 D_800A54AC[];
extern u16 D_800A54B4[];
extern u16 D_800A54BC[];
extern u16 D_800A54C4[];
extern u16 D_800A54CC[];
extern u16 D_800A54D4[];
extern u16 D_800A54DC[];
extern u16 D_800A54E4[];
extern u16 D_800A54EC[];
extern u16 D_800A54F4[];
extern u16 D_800A54FC[];
extern u16 D_800A5504[];
extern u16 D_800A5728[];
extern FieldTalk D_800A550C[];
extern u16 D_800A5730[];
extern FieldTalk D_800A5524[];
extern u16 D_800A5738[];
extern FieldTalk D_800A5548[];
extern u16 D_800A5740[];
extern FieldTalk D_800A5560[];
extern u16 D_800A5748[];
extern FieldTalk D_800A5578[];
extern u16 D_800A5750[];
extern FieldTalk D_800A5590[];
extern u16 D_800A5758[];
extern FieldTalk D_800A55A8[];
extern u16 D_800A5764[];
extern FieldTalk D_800A55C0[];
extern u16 D_800A576C[];
extern FieldTalk D_800A55D8[];
extern u16 D_800A577C[];
extern FieldTalk D_800A55F0[];
extern u16 D_800A5784[];
extern FieldTalk D_800A5614[];
extern u16 D_800A578C[];
extern FieldTalk D_800A562C[];
extern u16 D_800A5794[];
extern FieldTalk D_800A5650[];
extern u16 D_800A579C[];
extern FieldTalk D_800A5674[];
extern u16 D_800A57A4[];
extern FieldTalk D_800A5698[];
extern u16 D_800A57AC[];
extern FieldTalk D_800A56BC[];
extern u16 D_800A57B4[];
extern FieldTalk D_800A56E0[];
extern u16 D_800A57C4[];
extern FieldTalk D_800A5704[];
extern FieldActorEntry D_800A57CC;
extern FieldActorEntry D_800A57E0;
extern FieldActorEntry D_800A57F4;
extern FieldActorEntry D_800A5808;
extern FieldActorEntry D_800A581C;
extern FieldActorEntry D_800A5830;
extern FieldActorEntry D_800A5844;
extern FieldActorEntry D_800A5858;
extern FieldActorEntry D_800A586C;
extern FieldActorEntry D_800A5880;
extern FieldActorEntry D_800A5894;
extern FieldActorEntry D_800A58A8;
extern FieldActorEntry D_800A58BC;
extern FieldActorEntry D_800A58D0;
extern FieldActorEntry D_800A58E4;
extern FieldActorEntry D_800A58F8;
extern FieldActorEntry D_800A590C;
extern FieldActorEntry D_800A5920;

AnimFrame D_800A50F8[] = {
    { 50, 8 }, { 51, 8 }, { 52, 8 }, { 53, 8 },
    { 54, 8 }, { 55, 8 }, { 56, 8 }, { 57, 8 },
    { 58, 8 }, { 59, 8 }, { 60, 8 }, { 82, 160 },
    { 255, 0 },
};
AnimFrame D_800A512C[] = {
    { 61, 8 }, { 62, 8 }, { 63, 8 }, { 64, 8 },
    { 65, 8 }, { 66, 8 }, { 67, 8 }, { 68, 8 },
    { 69, 8 }, { 70, 8 }, { 71, 8 }, { 82, 160 },
    { 255, 0 },
};
AnimFrame D_800A5160[] = {
    { 72, 8 }, { 73, 8 }, { 74, 8 }, { 75, 8 },
    { 76, 8 }, { 77, 8 }, { 78, 8 }, { 79, 8 },
    { 80, 8 }, { 81, 8 }, { 82, 160 }, { 255, 0 },
};
Battle D_800A5190 = { 156, 5, 0x60080000 };
Battle D_800A519C = { 156, 5, 0x60080000 };
Battle D_800A51A8 = { 156, 5, 0x60080000 };
Battle D_800A51B4 = { 156, 5, 0x60080000 };
Battle D_800A51C0 = { 156, 5, 0x60080000 };
Battle D_800A51CC = { 156, 5, 0x60080000 };
Battle D_800A51D8 = { 156, 5, 0x60080000 };
Battle D_800A51E4 = { 156, 5, 0x60080000 };
BattleList D_800A51F0 = {
    3,
    { &D_800A5190, &D_800A519C, &D_800A51A8, &D_800A51B4,
      &D_800A51C0, &D_800A51CC, &D_800A51D8, &D_800A51E4 },
};
Battle D_800A5214 = { 0, 0, 0x60040000 };
Battle D_800A5220 = { 0, 0, 0x60040000 };
Battle D_800A522C = { 0, 0, 0x60040000 };
Battle D_800A5238 = { 0, 0, 0x60040000 };
Battle D_800A5244 = { 0, 0, 0x60040000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
BattleList D_800A5274 = {
    0,
    { &D_800A5214, &D_800A5220, &D_800A522C, &D_800A5238,
      &D_800A5244, &D_800A5250, &D_800A525C, &D_800A5268 },
};
Battle D_800A5298 = { 0, 0, 0x60040000 };
Battle D_800A52A4 = { 0, 0, 0x60040000 };
Battle D_800A52B0 = { 0, 0, 0x60040000 };
Battle D_800A52BC = { 0, 0, 0x60040000 };
Battle D_800A52C8 = { 0, 0, 0x60040000 };
Battle D_800A52D4 = { 0, 0, 0x60040000 };
Battle D_800A52E0 = { 0, 0, 0x60040000 };
Battle D_800A52EC = { 0, 0, 0x60040000 };
BattleList D_800A52F8 = {
    0,
    { &D_800A5298, &D_800A52A4, &D_800A52B0, &D_800A52BC,
      &D_800A52C8, &D_800A52D4, &D_800A52E0, &D_800A52EC },
};
Battle D_800A531C = { 0, 0, 0x60040000 };
Battle D_800A5328 = { 0, 0, 0x60040000 };
Battle D_800A5334 = { 0, 0, 0x60040000 };
Battle D_800A5340 = { 0, 0, 0x60040000 };
Battle D_800A534C = { 0, 0, 0x60040000 };
Battle D_800A5358 = { 0, 0, 0x60040000 };
Battle D_800A5364 = { 0, 0, 0x60040000 };
Battle D_800A5370 = { 0, 0, 0x60040000 };
BattleList D_800A537C = {
    0,
    { &D_800A531C, &D_800A5328, &D_800A5334, &D_800A5340,
      &D_800A534C, &D_800A5358, &D_800A5364, &D_800A5370 },
};
FieldBattles stageBattles[] = {
    { 36, 0, 0, { &D_800A51F0, &D_800A5274, &D_800A52F8, &D_800A537C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x188, 0x100, 0x120, 0, 0x170, 0x1FF },
    { 0x180, 0x100, 0x190, 0x100, 0x140, 0, 0x140, 0x1FE },
};
u16 D_800A543C[] = { 0x1C1C, 0, 0xFFFF };
u16 D_800A5444[] = { 0x1C1C, 1, 0xFFFF };
u16 D_800A544C[] = { 0, 0, 0xFFFF };
u16 D_800A5454[] = { 0, 1, 0xFFFF };
u16 D_800A545C[] = { 0, 1, 0xFFFF };
u16 D_800A5464[] = { 0, 0, 0xFFFF };
u16 D_800A546C[] = { 0, 1, 0xFFFF };
u16 D_800A5474[] = { 0, 1, 0xFFFF };
u16 D_800A547C[] = { 0, 0, 0xFFFF };
u16 D_800A5484[] = { 0, 1, 0xFFFF };
u16 D_800A548C[] = { 0, 1, 0xFFFF };
u16 D_800A5494[] = { 0, 0, 0xFFFF };
u16 D_800A549C[] = { 0, 1, 0xFFFF };
u16 D_800A54A4[] = { 0, 1, 0xFFFF };
u16 D_800A54AC[] = { 0, 0, 0xFFFF };
u16 D_800A54B4[] = { 0, 1, 0xFFFF };
u16 D_800A54BC[] = { 0, 1, 0xFFFF };
u16 D_800A54C4[] = { 0, 0, 0xFFFF };
u16 D_800A54CC[] = { 0, 1, 0xFFFF };
u16 D_800A54D4[] = { 0, 1, 0xFFFF };
u16 D_800A54DC[] = { 0, 0, 0xFFFF };
u16 D_800A54E4[] = { 0, 1, 0xFFFF };
u16 D_800A54EC[] = { 0, 1, 0xFFFF };
u16 D_800A54F4[] = { 0, 0, 0xFFFF };
u16 D_800A54FC[] = { 0, 1, 0xFFFF };
u16 D_800A5504[] = { 0, 1, 0xFFFF };
FieldTalk D_800A550C[] = {
    { NULL, NULL, 0x72 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5524[] = {
    { D_800A543C, NULL, 0x1B9 },
    { D_800A5444, NULL, 0x4A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5548[] = {
    { NULL, NULL, 0x1BD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5560[] = {
    { NULL, NULL, 0x1BC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5578[] = {
    { NULL, NULL, 0x1BB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5590[] = {
    { NULL, NULL, 0x1BA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A8[] = {
    { NULL, NULL, 0x1B9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55C0[] = {
    { NULL, NULL, 0x73 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55D8[] = {
    { NULL, NULL, 0x1AE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55F0[] = {
    { D_800A544C, D_800A5454, 0x1BF },
    { D_800A545C, NULL, 4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5614[] = {
    { NULL, NULL, 0x1C7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A562C[] = {
    { D_800A5464, D_800A546C, 0x1C6 },
    { D_800A5474, NULL, 4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5650[] = {
    { D_800A547C, D_800A5484, 0x1C5 },
    { D_800A548C, NULL, 4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5674[] = {
    { D_800A5494, D_800A549C, 0x1C4 },
    { D_800A54A4, NULL, 4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5698[] = {
    { D_800A54AC, D_800A54B4, 0x1C3 },
    { D_800A54BC, NULL, 4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56BC[] = {
    { D_800A54C4, D_800A54CC, 0x1C2 },
    { D_800A54D4, NULL, 4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56E0[] = {
    { D_800A54DC, D_800A54E4, 0x1C1 },
    { D_800A54EC, NULL, 4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5704[] = {
    { D_800A54F4, D_800A54FC, 0x1C0 },
    { D_800A5504, NULL, 4 },
    { NULL, NULL, 0 },
};
u16 D_800A5728[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5730[] = { 0x6014, 1, 0xFFFF };
u16 D_800A5738[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5740[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5748[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5750[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5758[] = { 0x7017, 1, 0x6014, 0, 0xFFFF };
u16 D_800A5764[] = { 0x6010, 1, 0xFFFF };
u16 D_800A576C[] = { 0x7016, 1, 0x6010, 0, 0x600F, 0, 0xFFFF };
u16 D_800A577C[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5784[] = { 0x602B, 1, 0xFFFF };
u16 D_800A578C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5794[] = { 0x6026, 1, 0xFFFF };
u16 D_800A579C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A57A4[] = { 0x7018, 1, 0xFFFF };
u16 D_800A57AC[] = { 0x7017, 1, 0xFFFF };
u16 D_800A57B4[] = { 0x600F, 0, 0x6010, 0, 0x7016, 1, 0xFFFF };
u16 D_800A57C4[] = { 0x6010, 1, 0xFFFF };
FieldActorEntry D_800A57CC = { D_800A5728, D_800A550C, 0x22, 4, 433, 280, 7 };
FieldActorEntry D_800A57E0 = { D_800A5730, D_800A5524, 0x22, 4, 433, 280, 7 };
FieldActorEntry D_800A57F4 = { D_800A5738, D_800A5548, 0x22, 4, 433, 280, 7 };
FieldActorEntry D_800A5808 = { D_800A5740, D_800A5560, 0x22, 4, 433, 280, 7 };
FieldActorEntry D_800A581C = { D_800A5748, D_800A5578, 0x22, 4, 433, 280, 7 };
FieldActorEntry D_800A5830 = { D_800A5750, D_800A5590, 0x22, 4, 433, 280, 7 };
FieldActorEntry D_800A5844 = { D_800A5758, D_800A55A8, 0x22, 4, 433, 280, 7 };
FieldActorEntry D_800A5858 = { D_800A5764, D_800A55C0, 0x22, 4, 433, 280, 7 };
FieldActorEntry D_800A586C = { D_800A576C, D_800A55D8, 0x22, 4, 433, 280, 7 };
FieldActorEntry D_800A5880 = { D_800A577C, D_800A55F0, 0x40, 5, 433, 537, 1 };
FieldActorEntry D_800A5894 = { D_800A5784, D_800A5614, 0x40, 5, 433, 537, 1 };
FieldActorEntry D_800A58A8 = { D_800A578C, D_800A562C, 0x40, 5, 433, 537, 1 };
FieldActorEntry D_800A58BC = { D_800A5794, D_800A5650, 0x40, 5, 433, 537, 1 };
FieldActorEntry D_800A58D0 = { D_800A579C, D_800A5674, 0x40, 5, 433, 537, 1 };
FieldActorEntry D_800A58E4 = { D_800A57A4, D_800A5698, 0x40, 5, 433, 537, 1 };
FieldActorEntry D_800A58F8 = { D_800A57AC, D_800A56BC, 0x40, 5, 433, 537, 1 };
FieldActorEntry D_800A590C = { D_800A57B4, D_800A56E0, 0x40, 5, 433, 537, 1 };
FieldActorEntry D_800A5920 = { D_800A57C4, D_800A5704, 0x40, 5, 433, 537, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A57CC,
    &D_800A57E0,
    &D_800A57F4,
    &D_800A5808,
    &D_800A581C,
    &D_800A5830,
    &D_800A5844,
    &D_800A5858,
    &D_800A586C,
    &D_800A5880,
    &D_800A5894,
    &D_800A58A8,
    &D_800A58BC,
    &D_800A58D0,
    &D_800A58E4,
    &D_800A58F8,
    &D_800A590C,
    &D_800A5920,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 3, 0x40, 2, 0x48, 0, 0, 0, 0, 0, 302, 396, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 120, 716, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 277, 632, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 342, 321, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 604, 413, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 726, 314, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 752, 174, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 772, 512, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 949, 77, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 541, 275, 326, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 364, 459, 509, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x248, 0x90, 0x540, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x258, 0x340, 0xF0, 1, 0, 1, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
