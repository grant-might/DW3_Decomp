#include "common.h"
#include "stage.h"
extern AnimFrame D_800A521C[];
extern AnimFrame D_800A5250[];
extern AnimFrame D_800A5284[];

#include "common/step_looping_animation.inc.c"

void updateTileAnims(StageTileAnims *task) {
    s32 frames[3];
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A521C[0].duration;
        task->anims[1].index = 0;
        task->anims[1].timer = D_800A5250[0].duration;
        task->anims[2].index = 0;
        task->anims[2].timer = D_800A5284[0].duration;
        break;
    case TASK_RUN:
        tile = D_800990B4.objects;
        frames[0] = stepLoopingAnimation(&task->anims[0], D_800A521C, 0);
        frames[1] = stepLoopingAnimation(&task->anims[1], D_800A5250, 0);
        frames[2] = stepLoopingAnimation(&task->anims[2], D_800A5284, 0);
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

#include "common/copy_place_points.inc.c"

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = createTileAnims();
        copyPlacePoints(D_800990B4.slots, placePoints, GAME.unk44, GAME.unk46);
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

#if VERSION_US
#define STAGE_TEXT 0xDB
#define STAGE_FILE 0x48C
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define STAGE_FILE 0x49C
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x20900, 0x31B00};
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

extern StagePoint D_800A52B4;
extern StagePoint D_800A52C4;
extern StagePoint D_800A52D4;
extern StagePoint D_800A52E4;
extern StagePoint D_800A52FC;
extern StagePoint D_800A530C;
extern StagePoint D_800A531C;
extern StagePoint D_800A532C;
extern StagePoint D_800A5344;
extern StagePoint D_800A5354;
extern StagePoint D_800A5364;
extern StagePoint D_800A5374;
extern StagePoint D_800A538C;
extern StagePoint D_800A539C;
extern StagePoint D_800A53AC;
extern StagePoint D_800A53BC;
extern StagePoint D_800A53D4;
extern StagePoint D_800A53E4;
extern StagePoint D_800A53F4;
extern StagePoint D_800A5404;
extern StagePoint D_800A541C;
extern StagePoint D_800A542C;
extern StagePoint D_800A543C;
extern StagePoint D_800A544C;
extern StagePoint D_800A5464;
extern StagePoint D_800A5474;
extern StagePoint D_800A5484;
extern StagePoint D_800A5494;
extern StagePoint D_800A54AC;
extern StagePoint D_800A54BC;
extern StagePoint D_800A54CC;
extern StagePoint D_800A54DC;
extern StagePoints D_800A52F4;
extern StagePoints D_800A533C;
extern StagePoints D_800A5384;
extern StagePoints D_800A53CC;
extern StagePoints D_800A5414;
extern StagePoints D_800A545C;
extern StagePoints D_800A54A4;
extern StagePoints D_800A54EC;
extern StagePoints D_800A54F4;
extern Battle D_800A5524;
extern Battle D_800A5530;
extern Battle D_800A553C;
extern Battle D_800A5548;
extern Battle D_800A5554;
extern Battle D_800A5560;
extern Battle D_800A556C;
extern Battle D_800A5578;
extern Battle D_800A55A8;
extern Battle D_800A55B4;
extern Battle D_800A55C0;
extern Battle D_800A55CC;
extern Battle D_800A55D8;
extern Battle D_800A55E4;
extern Battle D_800A55F0;
extern Battle D_800A55FC;
extern Battle D_800A562C;
extern Battle D_800A5638;
extern Battle D_800A5644;
extern Battle D_800A5650;
extern Battle D_800A565C;
extern Battle D_800A5668;
extern Battle D_800A5674;
extern Battle D_800A5680;
extern Battle D_800A56B0;
extern Battle D_800A56BC;
extern Battle D_800A56C8;
extern Battle D_800A56D4;
extern Battle D_800A56E0;
extern Battle D_800A56EC;
extern Battle D_800A56F8;
extern Battle D_800A5704;
extern BattleList D_800A5584;
extern BattleList D_800A5608;
extern BattleList D_800A568C;
extern BattleList D_800A5710;
extern u16 D_800A5810[];
extern u16 D_800A5818[];
extern u16 D_800A5820[];
extern u16 D_800A582C[];
extern u16 D_800A583C[];
extern u16 D_800A5850[];
extern u16 D_800A5858[];
extern u16 D_800A586C[];
extern u16 D_800A5874[];
extern u16 D_800A5880[];
extern u16 D_800A5888[];
extern u16 D_800A5890[];
extern u16 D_800A5898[];
extern u16 D_800A58A4[];
extern u16 D_800A58B4[];
extern u16 D_800A58C8[];
extern u16 D_800A58D0[];
extern u16 D_800A58E4[];
extern u16 D_800A58EC[];
extern u16 D_800A58F8[];
extern u16 D_800A5900[];
extern u16 D_800A5908[];
extern u16 D_800A5910[];
extern u16 D_800A591C[];
extern u16 D_800A592C[];
extern u16 D_800A5940[];
extern u16 D_800A5948[];
extern u16 D_800A595C[];
extern u16 D_800A5964[];
extern u16 D_800A5970[];
extern u16 D_800A5B04[];
extern FieldTalk D_800A5978[];
extern u16 D_800A5B1C[];
extern FieldTalk D_800A59C0[];
extern u16 D_800A5B34[];
extern FieldTalk D_800A59E4[];
extern u16 D_800A5B4C[];
extern FieldTalk D_800A5A2C[];
extern u16 D_800A5B64[];
extern FieldTalk D_800A5A50[];
extern u16 D_800A5B74[];
extern FieldTalk D_800A5A68[];
extern u16 D_800A5B84[];
extern FieldTalk D_800A5A80[];
extern u16 D_800A5B94[];
extern FieldTalk D_800A5A98[];
extern u16 D_800A5BAC[];
extern FieldTalk D_800A5AE0[];
extern FieldActorEntry D_800A5BC4;
extern FieldActorEntry D_800A5BD8;
extern FieldActorEntry D_800A5BEC;
extern FieldActorEntry D_800A5C00;
extern FieldActorEntry D_800A5C14;
extern FieldActorEntry D_800A5C28;
extern FieldActorEntry D_800A5C3C;
extern FieldActorEntry D_800A5C50;
extern FieldActorEntry D_800A5C64;

AnimFrame D_800A521C[] = {
    { 50, 8 }, { 51, 8 }, { 52, 8 }, { 53, 8 },
    { 54, 8 }, { 55, 8 }, { 56, 8 }, { 57, 8 },
    { 58, 8 }, { 59, 8 }, { 60, 8 }, { 82, 160 },
    { 255, 0 },
};
AnimFrame D_800A5250[] = {
    { 61, 8 }, { 62, 8 }, { 63, 8 }, { 64, 8 },
    { 65, 8 }, { 66, 8 }, { 67, 8 }, { 68, 8 },
    { 69, 8 }, { 70, 8 }, { 71, 8 }, { 82, 160 },
    { 255, 0 },
};
AnimFrame D_800A5284[] = {
    { 72, 8 }, { 73, 8 }, { 74, 8 }, { 75, 8 },
    { 76, 8 }, { 77, 8 }, { 78, 8 }, { 79, 8 },
    { 80, 8 }, { 81, 8 }, { 82, 160 }, { 255, 0 },
};
StagePoint D_800A52B4 = { 0x259, 1, 2, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A52C4 = { 0x259, 1, 3, 0x358, 252, 1, &D_800A52B4 };
StagePoint D_800A52D4 = { 0x259, 1, 1, 0x120, 0x100, 7, &D_800A52C4 };
StagePoint D_800A52E4 = { 0x257, 0, 0, 0x100, 0x278, 5, &D_800A52D4 };
StagePoints D_800A52F4 = { 1, 1, &D_800A52E4 };
StagePoint D_800A52FC = { 0x259, 1, 1, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A530C = { 0x259, 1, 4, 0x358, 252, 1, &D_800A52FC };
StagePoint D_800A531C = { 0x259, 1, 2, 0x120, 0x100, 7, &D_800A530C };
StagePoint D_800A532C = { 0x257, 0, 0, 0x100, 0x278, 5, &D_800A531C };
StagePoints D_800A533C = { 1, 2, &D_800A532C };
StagePoint D_800A5344 = { 0x259, 1, 3, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A5354 = { 0x259, 1, 5, 0x358, 252, 1, &D_800A5344 };
StagePoint D_800A5364 = { 0x259, 1, 4, 0x120, 0x100, 7, &D_800A5354 };
StagePoint D_800A5374 = { 0x259, 1, 1, 0x118, 0x2EC, 5, &D_800A5364 };
StagePoints D_800A5384 = { 1, 3, &D_800A5374 };
StagePoint D_800A538C = { 0x259, 1, 4, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A539C = { 0x259, 1, 6, 0x358, 252, 1, &D_800A538C };
StagePoint D_800A53AC = { 0x259, 1, 3, 0x120, 0x100, 7, &D_800A539C };
StagePoint D_800A53BC = { 0x259, 1, 2, 0x118, 0x2EC, 5, &D_800A53AC };
StagePoints D_800A53CC = { 1, 4, &D_800A53BC };
StagePoint D_800A53D4 = { 0x259, 1, 6, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A53E4 = { 0x259, 1, 7, 0x358, 252, 1, &D_800A53D4 };
StagePoint D_800A53F4 = { 0x259, 1, 5, 0x120, 0x100, 7, &D_800A53E4 };
StagePoint D_800A5404 = { 0x259, 1, 3, 0x118, 0x2EC, 5, &D_800A53F4 };
StagePoints D_800A5414 = { 1, 5, &D_800A5404 };
StagePoint D_800A541C = { 0x25A, 0, 0, 0x2F8, 0x244, 3, NULL };
StagePoint D_800A542C = { 0x259, 1, 8, 0x358, 252, 1, &D_800A541C };
StagePoint D_800A543C = { 0x259, 1, 6, 0x120, 0x100, 7, &D_800A542C };
StagePoint D_800A544C = { 0x259, 1, 4, 0x118, 0x2EC, 5, &D_800A543C };
StagePoints D_800A545C = { 1, 6, &D_800A544C };
StagePoint D_800A5464 = { 0x259, 1, 7, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A5474 = { 0x259, 1, 1, 0x358, 252, 1, &D_800A5464 };
StagePoint D_800A5484 = { 0x259, 1, 8, 0x120, 0x100, 7, &D_800A5474 };
StagePoint D_800A5494 = { 0x259, 1, 5, 0x118, 0x2EC, 5, &D_800A5484 };
StagePoints D_800A54A4 = { 1, 7, &D_800A5494 };
StagePoint D_800A54AC = { 0x259, 1, 8, 0x350, 0x2F8, 3, NULL };
StagePoint D_800A54BC = { 0x259, 1, 2, 0x358, 252, 1, &D_800A54AC };
StagePoint D_800A54CC = { 0x259, 1, 7, 0x120, 0x100, 7, &D_800A54BC };
StagePoint D_800A54DC = { 0x259, 1, 6, 0x118, 0x2EC, 5, &D_800A54CC };
StagePoints D_800A54EC = { 1, 8, &D_800A54DC };
StagePoints D_800A54F4 = { 0, 0, &D_800A52E4 };
StagePoints *placePoints[] = {
    &D_800A52F4, &D_800A533C, &D_800A5384, &D_800A53CC,
    &D_800A5414, &D_800A545C, &D_800A54A4, &D_800A54EC,
    &D_800A54F4, NULL,
};
Battle D_800A5524 = { 73, 5, 0x60080000 };
Battle D_800A5530 = { 73, 5, 0x60080000 };
Battle D_800A553C = { 73, 5, 0x60080000 };
Battle D_800A5548 = { 74, 5, 0x60080000 };
Battle D_800A5554 = { 74, 5, 0x60080000 };
Battle D_800A5560 = { 74, 5, 0x60080000 };
Battle D_800A556C = { 156, 5, 0x60080000 };
Battle D_800A5578 = { 156, 5, 0x60080000 };
BattleList D_800A5584 = {
    3,
    { &D_800A5524, &D_800A5530, &D_800A553C, &D_800A5548,
      &D_800A5554, &D_800A5560, &D_800A556C, &D_800A5578 },
};
Battle D_800A55A8 = { 0, 0, 0x60040000 };
Battle D_800A55B4 = { 0, 0, 0x60040000 };
Battle D_800A55C0 = { 0, 0, 0x60040000 };
Battle D_800A55CC = { 0, 0, 0x60040000 };
Battle D_800A55D8 = { 0, 0, 0x60040000 };
Battle D_800A55E4 = { 0, 0, 0x60040000 };
Battle D_800A55F0 = { 0, 0, 0x60040000 };
Battle D_800A55FC = { 0, 0, 0x60040000 };
BattleList D_800A5608 = {
    0,
    { &D_800A55A8, &D_800A55B4, &D_800A55C0, &D_800A55CC,
      &D_800A55D8, &D_800A55E4, &D_800A55F0, &D_800A55FC },
};
Battle D_800A562C = { 0, 0, 0x60040000 };
Battle D_800A5638 = { 0, 0, 0x60040000 };
Battle D_800A5644 = { 0, 0, 0x60040000 };
Battle D_800A5650 = { 0, 0, 0x60040000 };
Battle D_800A565C = { 0, 0, 0x60040000 };
Battle D_800A5668 = { 0, 0, 0x60040000 };
Battle D_800A5674 = { 0, 0, 0x60040000 };
Battle D_800A5680 = { 0, 0, 0x60040000 };
BattleList D_800A568C = {
    0,
    { &D_800A562C, &D_800A5638, &D_800A5644, &D_800A5650,
      &D_800A565C, &D_800A5668, &D_800A5674, &D_800A5680 },
};
Battle D_800A56B0 = { 0, 0, 0x60040000 };
Battle D_800A56BC = { 0, 0, 0x60040000 };
Battle D_800A56C8 = { 0, 0, 0x60040000 };
Battle D_800A56D4 = { 0, 0, 0x60040000 };
Battle D_800A56E0 = { 0, 0, 0x60040000 };
Battle D_800A56EC = { 0, 0, 0x60040000 };
Battle D_800A56F8 = { 0, 0, 0x60040000 };
Battle D_800A5704 = { 0, 0, 0x60040000 };
BattleList D_800A5710 = {
    0,
    { &D_800A56B0, &D_800A56BC, &D_800A56C8, &D_800A56D4,
      &D_800A56E0, &D_800A56EC, &D_800A56F8, &D_800A5704 },
};
FieldBattles stageBattles[] = {
    { 37, 0, 0, { &D_800A5584, &D_800A5608, &D_800A568C, &D_800A5710 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x160, 0xD8, 0x60, 0x170, 0x1FF },
    { 0x140, 0x100, 0x176, 0x188, 0xD8, 0x88, 0x140, 0x1FE },
    { 0x180, 0x100, 0x1B0, 0x188, 0x1C0, 0x88, 0x150, 0x1FE },
    { 0x180, 0x100, 0x188, 0x194, 0x120, 0x94, 0x160, 0x1FE },
    { 0x180, 0x100, 0x180, 0x19C, 0x100, 0x9C, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1B6, 0x100, 0x1D8, 0, 0x140, 0x1FD },
};
u16 D_800A5810[] = { 0x1A2F, 0, 0xFFFF };
u16 D_800A5818[] = { 0x1A2F, 1, 0xFFFF };
u16 D_800A5820[] = { 0x1A2F, 1, 0x702E, 0, 0xFFFF };
u16 D_800A582C[] = { 0x1A2F, 1, 0x702E, 1, 0x7027, 0, 0xFFFF };
u16 D_800A583C[] = { 0x1A2F, 1, 0x702E, 1, 0x7027, 1, 0x7029, 0, 0xFFFF };
u16 D_800A5850[] = { 0x604, 1, 0xFFFF };
u16 D_800A5858[] = { 0x1A2F, 1, 0x702E, 1, 0x7027, 1, 0x7029, 1, 0xFFFF };
u16 D_800A586C[] = { 0x7010, 0, 0xFFFF };
u16 D_800A5874[] = { 0x7037, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5880[] = { 0x7010, 1, 0xFFFF };
u16 D_800A5888[] = { 0x1A30, 0, 0xFFFF };
u16 D_800A5890[] = { 0x1A30, 1, 0xFFFF };
u16 D_800A5898[] = { 0x1A30, 1, 0x7030, 0, 0xFFFF };
u16 D_800A58A4[] = { 0x1A30, 1, 0x7030, 1, 0x7027, 0, 0xFFFF };
u16 D_800A58B4[] = { 0x1A30, 1, 0x7030, 1, 0x7027, 1, 0x7029, 0, 0xFFFF };
u16 D_800A58C8[] = { 0x605, 1, 0xFFFF };
u16 D_800A58D0[] = { 0x1A30, 1, 0x7030, 1, 0x7027, 1, 0x7029, 1, 0xFFFF };
u16 D_800A58E4[] = { 0x7012, 0, 0xFFFF };
u16 D_800A58EC[] = { 0x7039, 1, 0x7013, 1, 0xFFFF };
u16 D_800A58F8[] = { 0x7012, 1, 0xFFFF };
u16 D_800A5900[] = { 0x1A31, 0, 0xFFFF };
u16 D_800A5908[] = { 0x1A31, 1, 0xFFFF };
u16 D_800A5910[] = { 0x1A31, 1, 0x702F, 0, 0xFFFF };
u16 D_800A591C[] = { 0x1A31, 1, 0x702F, 1, 0x7027, 0, 0xFFFF };
u16 D_800A592C[] = { 0x1A31, 1, 0x702F, 1, 0x7027, 1, 0x7029, 0, 0xFFFF };
u16 D_800A5940[] = { 0x606, 1, 0xFFFF };
u16 D_800A5948[] = { 0x1A31, 1, 0x702F, 1, 0x7027, 1, 0x7029, 1, 0xFFFF };
u16 D_800A595C[] = { 0x7011, 0, 0xFFFF };
u16 D_800A5964[] = { 0x7038, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5970[] = { 0x7011, 1, 0xFFFF };
FieldTalk D_800A5978[] = {
    { D_800A5810, D_800A5818, 0x33D },
    { D_800A5820, NULL, 0x343 },
    { D_800A582C, NULL, 0x33E },
    { D_800A583C, D_800A5850, 0x33F },
    { D_800A5858, NULL, 0x344 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59C0[] = {
    { D_800A586C, D_800A5874, 0x340 },
    { D_800A5880, NULL, 0x342 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59E4[] = {
    { D_800A5888, D_800A5890, 0x345 },
    { D_800A5898, NULL, 0x34B },
    { D_800A58A4, NULL, 0x346 },
    { D_800A58B4, D_800A58C8, 0x347 },
    { D_800A58D0, NULL, 0x34C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A2C[] = {
    { D_800A58E4, D_800A58EC, 0x348 },
    { D_800A58F8, NULL, 0x34A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A50[] = {
    { NULL, NULL, 0x341 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A68[] = {
    { NULL, NULL, 0x349 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A80[] = {
    { NULL, NULL, 0x351 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A98[] = {
    { D_800A5900, D_800A5908, 0x34D },
    { D_800A5910, NULL, 0x353 },
    { D_800A591C, NULL, 0x34E },
    { D_800A592C, D_800A5940, 0x34F },
    { D_800A5948, NULL, 0x354 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AE0[] = {
    { D_800A595C, D_800A5964, 0x350 },
    { D_800A5970, NULL, 0x352 },
    { NULL, NULL, 0 },
};
u16 D_800A5B04[] = {
    0x7093, 1, 0x701A, 0, 0x8013, 0, 0x7E00, 1,
    0x7E1E, 1, 0xFFFF,
};
u16 D_800A5B1C[] = {
    0x7093, 1, 0x701A, 0, 0x8013, 1, 0x7E1E, 1,
    0x7E00, 1, 0xFFFF,
};
u16 D_800A5B34[] = {
    0x7093, 1, 0x701A, 0, 0x818B, 0, 0x7E21, 1,
    0x7E00, 1, 0xFFFF,
};
u16 D_800A5B4C[] = {
    0x7093, 1, 0x701A, 0, 0x818B, 1, 0x7E21, 1,
    0x7E00, 1, 0xFFFF,
};
u16 D_800A5B64[] = { 0x701A, 1, 0x7E1E, 1, 0x7E00, 1, 0xFFFF };
u16 D_800A5B74[] = { 0x701A, 1, 0x7E21, 1, 0x7E00, 1, 0xFFFF };
u16 D_800A5B84[] = { 0x701A, 1, 0x7E00, 1, 0x7E24, 1, 0xFFFF };
u16 D_800A5B94[] = {
    0x7093, 1, 0x701A, 0, 0x8168, 0, 0x7E24, 1,
    0x7E00, 1, 0xFFFF,
};
u16 D_800A5BAC[] = {
    0x7093, 1, 0x701A, 0, 0x8168, 1, 0x7E24, 1,
    0x7E00, 1, 0xFFFF,
};
FieldActorEntry D_800A5BC4 = { D_800A5B04, D_800A5978, 0x2B, 4, 480, 696, 7 };
FieldActorEntry D_800A5BD8 = { D_800A5B1C, D_800A59C0, 0x2B, 4, 480, 696, 7 };
FieldActorEntry D_800A5BEC = { D_800A5B34, D_800A59E4, 0x2C, 5, 800, 520, 1 };
FieldActorEntry D_800A5C00 = { D_800A5B4C, D_800A5A2C, 0x2C, 5, 800, 520, 1 };
FieldActorEntry D_800A5C14 = { D_800A5B64, D_800A5A50, 0x9D, 6, 480, 696, 7 };
FieldActorEntry D_800A5C28 = { D_800A5B74, D_800A5A68, 0x9E, 7, 800, 520, 1 };
FieldActorEntry D_800A5C3C = { D_800A5B84, D_800A5A80, 0x9F, 8, 408, 364, 7 };
FieldActorEntry D_800A5C50 = { D_800A5B94, D_800A5A98, 0xA3, 9, 408, 364, 7 };
FieldActorEntry D_800A5C64 = { D_800A5BAC, D_800A5AE0, 0xA3, 9, 408, 364, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5BC4,
    &D_800A5BD8,
    &D_800A5BEC,
    &D_800A5C00,
    &D_800A5C14,
    &D_800A5C28,
    &D_800A5C3C,
    &D_800A5C50,
    &D_800A5C64,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 3, 0xC8, 2, 0x48, 0, 0, 0, 0, 0, 50, 640, 0, 0 },
    { 1, 3, 0xC8, 2, 0x48, 0, 0, 0, 0, 0, 348, 103, 0, 0 },
    { 1, 3, 0xC8, 2, 0x48, 0, 0, 0, 0, 0, 369, 851, 0, 0 },
    { 1, 0, 0x40, 2, 7, 1, 7, 0xC, 4, 0, 570, 141, 0, 0 },
    { 1, 0, 0x40, 2, 7, 1, 7, 0xC, 4, 0, 906, 499, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 56, 957, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 92, 232, 0, 0 },
    { 1, 1, 0x40, 6, 0x32, 0, 0, 0, 0, 0, 113, 400, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 340, 812, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 891, 290, 0, 0 },
    { 1, 2, 0x40, 6, 0x3D, 0, 0, 0, 0, 0, 1096, 196, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 417, 278, 329, 0 },
    { 1, 0, 0x48, 4, 1, 0, 0, 0, 0, 0, 348, 278, 342, 0 },
    { 1, 0, 0x4A, 4, 2, 0, 0, 0, 0, 0, 529, 611, 680, 0 },
    { 1, 0, 0x5A, 4, 3, 0, 0, 0, 0, 0, 422, 570, 656, 0 },
    { 1, 0, 0x58, 4, 4, 0, 0, 0, 0, 0, 384, 635, 719, 0 },
    { 1, 0, 0x60, 4, 5, 0, 0, 0, 0, 0, 919, 519, 608, 0 },
    { 1, 0, 0x5E, 4, 6, 0, 0, 0, 0, 0, 583, 159, 248, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x258, 0x340, 0xF0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x258, 0x368, 0x2EC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x258, 0x128, 0x2F4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x258, 0x110, 0x108, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
