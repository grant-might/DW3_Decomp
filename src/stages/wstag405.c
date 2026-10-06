#include "common.h"
#include "stage.h"
extern AnimFrame D_800A52A8[];

#include "common/step_looping_animation.inc.c"

/* Sets the frame of the map objects with animation 1 */
void updateTileAnims(StageTileAnims *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->anims[0].index = 0;
        task->anims[0].timer = D_800A52A8[0].duration;
        break;
    case TASK_RUN:
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
            if (tile->anim == 1) {
                tile->frame = stepLoopingAnimation(&task->anims[0], D_800A52A8, 0);
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

/* Creates the event object of progress 4 when flag 0x400F is set and 0x4010 is not, and the stage helper task */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 4 && FLAGS_00.checkCondition(0x400F, 1) && FLAGS_00.checkCondition(0x4010, 0)) {
            children[0] = FIELDSTG_startEvent(0x3D);
        }
        children[1] = createTileAnims();
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

void func_800A4FB8(void) {
    FLAGS_00.applyAction(0x400F, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A5004(void) {
    FLAGS_00.applyAction(0x4010, 1);
    FLAGS_00.applyAction(0x8699, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x248
#define STAGE_ARCHIVE 0x3C9
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x257
#define STAGE_ARCHIVE 0x3D9
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x16B00, 0x44400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x2F;
    D_800990B4.music = 0x60BC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern Battle D_800A5334;
extern Battle D_800A5340;
extern Battle D_800A534C;
extern Battle D_800A5358;
extern Battle D_800A5364;
extern Battle D_800A5370;
extern Battle D_800A537C;
extern Battle D_800A5388;
extern Battle D_800A53B8;
extern Battle D_800A53C4;
extern Battle D_800A53D0;
extern Battle D_800A53DC;
extern Battle D_800A53E8;
extern Battle D_800A53F4;
extern Battle D_800A5400;
extern Battle D_800A540C;
extern Battle D_800A543C;
extern Battle D_800A5448;
extern Battle D_800A5454;
extern Battle D_800A5460;
extern Battle D_800A546C;
extern Battle D_800A5478;
extern Battle D_800A5484;
extern Battle D_800A5490;
extern Battle D_800A54C0;
extern Battle D_800A54CC;
extern Battle D_800A54D8;
extern Battle D_800A54E4;
extern Battle D_800A54F0;
extern Battle D_800A54FC;
extern Battle D_800A5508;
extern Battle D_800A5514;
extern BattleList D_800A5394;
extern BattleList D_800A5418;
extern BattleList D_800A549C;
extern BattleList D_800A5520;
extern u16 D_800A55F0[];
extern u16 D_800A55F8[];
extern u16 D_800A5600[];
extern u16 D_800A560C[];
extern u16 D_800A561C[];
extern u16 D_800A5630[];
extern u16 D_800A5638[];
extern u16 D_800A564C[];
extern u16 D_800A5654[];
extern u16 D_800A5660[];
extern u16 D_800A5668[];
extern u16 D_800A5670[];
extern u16 D_800A5678[];
extern u16 D_800A5684[];
extern u16 D_800A5694[];
extern u16 D_800A56A8[];
extern u16 D_800A56B0[];
extern u16 D_800A56C4[];
extern u16 D_800A56CC[];
extern u16 D_800A56D8[];
extern u16 D_800A56E0[];
extern u16 D_800A56E8[];
extern u16 D_800A56F4[];
extern u16 D_800A5704[];
extern u16 D_800A5920[];
extern FieldTalk D_800A5710[];
extern u16 D_800A5930[];
extern FieldTalk D_800A5758[];
extern u16 D_800A5940[];
extern FieldTalk D_800A577C[];
extern u16 D_800A594C[];
extern FieldTalk D_800A57C4[];
extern u16 D_800A5958[];
extern FieldTalk D_800A57E8[];
extern u16 D_800A5960[];
extern FieldTalk D_800A5818[];
extern u16 D_800A5968[];
extern FieldTalk D_800A5830[];
extern u16 D_800A5970[];
extern FieldTalk D_800A5848[];
extern u16 D_800A5978[];
extern FieldTalk D_800A5860[];
extern u16 D_800A5980[];
extern FieldTalk D_800A5878[];
extern u16 D_800A5988[];
extern FieldTalk D_800A5890[];
extern u16 D_800A5990[];
extern FieldTalk D_800A58A8[];
extern u16 D_800A5998[];
extern FieldTalk D_800A58C0[];
extern u16 D_800A59A0[];
extern FieldTalk D_800A58D8[];
extern u16 D_800A59A8[];
extern FieldTalk D_800A58F0[];
extern u16 D_800A59B0[];
extern FieldTalk D_800A5908[];
extern FieldActorEntry D_800A59B8;
extern FieldActorEntry D_800A59CC;
extern FieldActorEntry D_800A59E0;
extern FieldActorEntry D_800A59F4;
extern FieldActorEntry D_800A5A08;
extern FieldActorEntry D_800A5A1C;
extern FieldActorEntry D_800A5A30;
extern FieldActorEntry D_800A5A44;
extern FieldActorEntry D_800A5A58;
extern FieldActorEntry D_800A5A6C;
extern FieldActorEntry D_800A5A80;
extern FieldActorEntry D_800A5A94;
extern FieldActorEntry D_800A5AA8;
extern FieldActorEntry D_800A5ABC;
extern FieldActorEntry D_800A5AD0;
extern FieldActorEntry D_800A5AE4;
extern s16 D_800A5164[];
extern s16 D_800A5204[];

s16 D_800A5164[] = {
    0x600, 1, 2,
    0x102, 2, 0x37C, 0x153, 5,
    0x100, 0x5A, 0x39C, 0x143,
    0x101, 0x5A, 1, 1,
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
    0x200, 0, 2, 0x5A, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x5A, 0,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x1B6\n");
#endif
s16 D_800A5204[] = {
    0x600, 1, 2,
    0x100, 2, 0x37C, 0x153,
    0x101, 2, 1, 5,
    0x100, 0x5A, 0x39C, 0x143,
    0x101, 0x5A, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x5A, 0,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x5A, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x5A, 0,
    0x301,
    0x300, 0x3C,
    0,
};
AnimFrame D_800A52A8[] = {
    { 50, 8 }, { 51, 4 }, { 52, 8 }, { 53, 4 },
    { 54, 8 }, { 55, 4 }, { 56, 8 }, { 57, 16 },
    { 58, 4 }, { 59, 8 }, { 60, 4 }, { 61, 8 },
    { 62, 8 }, { 63, 12 }, { 64, 20 }, { 65, 4 },
    { 66, 8 }, { 67, 4 }, { 68, 8 }, { 69, 8 },
    { 70, 8 }, { 71, 8 }, { 72, 8 }, { 73, 4 },
    { 74, 8 }, { 75, 4 }, { 76, 8 }, { 77, 8 },
    { 78, 8 }, { 79, 8 }, { 80, 8 }, { 81, 12 },
    { 82, 8 }, { 83, 30 }, { 255, 0 },
};
Battle D_800A5334 = { 50, 4, 0x60080000 };
Battle D_800A5340 = { 50, 4, 0x60080000 };
Battle D_800A534C = { 50, 4, 0x60080000 };
Battle D_800A5358 = { 51, 4, 0x60080000 };
Battle D_800A5364 = { 51, 4, 0x60080000 };
Battle D_800A5370 = { 51, 4, 0x60080000 };
Battle D_800A537C = { 52, 4, 0x60080000 };
Battle D_800A5388 = { 52, 4, 0x60080000 };
BattleList D_800A5394 = {
    3,
    { &D_800A5334, &D_800A5340, &D_800A534C, &D_800A5358,
      &D_800A5364, &D_800A5370, &D_800A537C, &D_800A5388 },
};
Battle D_800A53B8 = { 51, 4, 0x60080000 };
Battle D_800A53C4 = { 51, 4, 0x60080000 };
Battle D_800A53D0 = { 51, 4, 0x60080000 };
Battle D_800A53DC = { 51, 4, 0x60080000 };
Battle D_800A53E8 = { 51, 4, 0x60080000 };
Battle D_800A53F4 = { 51, 4, 0x60080000 };
Battle D_800A5400 = { 51, 4, 0x60080000 };
Battle D_800A540C = { 51, 4, 0x60080000 };
BattleList D_800A5418 = {
    5,
    { &D_800A53B8, &D_800A53C4, &D_800A53D0, &D_800A53DC,
      &D_800A53E8, &D_800A53F4, &D_800A5400, &D_800A540C },
};
Battle D_800A543C = { 0, 0, 0x60040000 };
Battle D_800A5448 = { 0, 0, 0x60040000 };
Battle D_800A5454 = { 0, 0, 0x60040000 };
Battle D_800A5460 = { 0, 0, 0x60040000 };
Battle D_800A546C = { 0, 0, 0x60040000 };
Battle D_800A5478 = { 0, 0, 0x60040000 };
Battle D_800A5484 = { 0, 0, 0x60040000 };
Battle D_800A5490 = { 0, 0, 0x60040000 };
BattleList D_800A549C = {
    0,
    { &D_800A543C, &D_800A5448, &D_800A5454, &D_800A5460,
      &D_800A546C, &D_800A5478, &D_800A5484, &D_800A5490 },
};
Battle D_800A54C0 = { 2, 19, 0x60880000 };
Battle D_800A54CC = { 310, 19, 0x60880000 };
Battle D_800A54D8 = { 0, 0, 0x60040000 };
Battle D_800A54E4 = { 0, 0, 0x60040000 };
Battle D_800A54F0 = { 0, 0, 0x60040000 };
Battle D_800A54FC = { 0, 0, 0x60040000 };
Battle D_800A5508 = { 0, 0, 0x60040000 };
Battle D_800A5514 = { 0, 0, 0x60040000 };
BattleList D_800A5520 = {
    0,
    { &D_800A54C0, &D_800A54CC, &D_800A54D8, &D_800A54E4,
      &D_800A54F0, &D_800A54FC, &D_800A5508, &D_800A5514 },
};
FieldBattles stageBattles[] = {
    { 12, 0, 0, { &D_800A5394, &D_800A5418, &D_800A549C, &D_800A5520 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B4, 0x120, 0x1D0, 0x20, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1A0, 0x120, 0x180, 0x20, 0x150, 0x1FE },
    { 0x180, 0x100, 0x1AA, 0x148, 0x1A8, 0x48, 0x160, 0x1FE },
};
u16 D_800A55F0[] = { 0x1A2D, 0, 0xFFFF };
u16 D_800A55F8[] = { 0x1A2D, 1, 0xFFFF };
u16 D_800A5600[] = { 0x1A2D, 1, 0x702A, 0, 0xFFFF };
u16 D_800A560C[] = { 0x7025, 0, 0x1A2D, 1, 0x702A, 1, 0xFFFF };
u16 D_800A561C[] = { 0x7025, 1, 0x7027, 0, 0x1A2D, 1, 0x702A, 1, 0xFFFF };
u16 D_800A5630[] = { 0x600, 1, 0xFFFF };
u16 D_800A5638[] = { 0x7025, 1, 0x7027, 1, 0x1A2D, 1, 0x702A, 1, 0xFFFF };
u16 D_800A564C[] = { 0x700B, 0, 0xFFFF };
u16 D_800A5654[] = { 0x7031, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5660[] = { 0x700B, 1, 0xFFFF };
u16 D_800A5668[] = { 0x1A2D, 0, 0xFFFF };
u16 D_800A5670[] = { 0x1A2D, 1, 0xFFFF };
u16 D_800A5678[] = { 0x1A2D, 1, 0x702A, 0, 0xFFFF };
u16 D_800A5684[] = { 0x1A2D, 1, 0x702A, 1, 0x7025, 0, 0xFFFF };
u16 D_800A5694[] = { 0x1A2D, 1, 0x702A, 1, 0x7025, 1, 0x7027, 0, 0xFFFF };
u16 D_800A56A8[] = { 0x600, 1, 0xFFFF };
u16 D_800A56B0[] = { 0x1A2D, 1, 0x702A, 1, 0x7025, 1, 0x7027, 1, 0xFFFF };
u16 D_800A56C4[] = { 0x700B, 0, 0xFFFF };
u16 D_800A56CC[] = { 0x7031, 1, 0x7013, 1, 0xFFFF };
u16 D_800A56D8[] = { 0x700B, 1, 0xFFFF };
u16 D_800A56E0[] = { 0x1C10, 0, 0xFFFF };
u16 D_800A56E8[] = { 0x1C10, 1, 0x1C11, 0, 0xFFFF };
u16 D_800A56F4[] = { 0x902F, 1, 0x1C11, 1, 0xA01, 1, 0xFFFF };
u16 D_800A5704[] = { 0x1C10, 1, 0x1C11, 1, 0xFFFF };
FieldTalk D_800A5710[] = {
    { D_800A55F0, D_800A55F8, 0x2B2 },
    { D_800A5600, NULL, 0x2B7 },
    { D_800A560C, NULL, 0x2B8 },
    { D_800A561C, D_800A5630, 0x2B3 },
    { D_800A5638, NULL, 0x2BC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5758[] = {
    { D_800A564C, D_800A5654, 0x2B4 },
    { D_800A5660, NULL, 0x2B6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A577C[] = {
    { D_800A5668, D_800A5670, 0x2B2 },
    { D_800A5678, NULL, 0x2B7 },
    { D_800A5684, NULL, 0x2B8 },
    { D_800A5694, D_800A56A8, 0x2B3 },
    { D_800A56B0, NULL, 0x2BC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57C4[] = {
    { D_800A56C4, D_800A56CC, 0x2B4 },
    { D_800A56D8, NULL, 0x2B6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57E8[] = {
    { D_800A56E0, NULL, 0xF1 },
    { D_800A56E8, D_800A56F4, 0x2DD },
    { D_800A5704, NULL, 0x2DE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5818[] = {
    { NULL, NULL, 0x2E9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5830[] = {
    { NULL, NULL, 0x2F6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5848[] = {
    { NULL, NULL, 0x2F4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5860[] = {
    { NULL, NULL, 0x2EF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5878[] = {
    { NULL, NULL, 0x2F1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5890[] = {
    { NULL, NULL, 0x2F2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58A8[] = {
    { NULL, NULL, 0x2F7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C0[] = {
    { NULL, NULL, 0x2F5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58D8[] = {
    { NULL, NULL, 0x2F3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58F0[] = {
    { NULL, NULL, 0x2F0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5908[] = {
    { NULL, NULL, 0x2B5 },
    { NULL, NULL, 0 },
};
u16 D_800A5920[] = { 0x6004, 0, 0x8006, 0, 0x7022, 1, 0xFFFF };
u16 D_800A5930[] = { 0x7022, 1, 0x6004, 0, 0x8006, 1, 0xFFFF };
u16 D_800A5940[] = { 0x602B, 1, 0x8006, 0, 0xFFFF };
u16 D_800A594C[] = { 0x602B, 1, 0x8006, 1, 0xFFFF };
u16 D_800A5958[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5960[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5968[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5970[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5978[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5980[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5988[] = { 0x7017, 1, 0xFFFF };
u16 D_800A5990[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5998[] = { 0x6026, 1, 0xFFFF };
u16 D_800A59A0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A59A8[] = { 0x600E, 1, 0xFFFF };
u16 D_800A59B0[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A59B8 = { D_800A5920, D_800A5710, 0x2B, 4, 764, 1138, 1 };
FieldActorEntry D_800A59CC = { D_800A5930, D_800A5758, 0x2B, 4, 764, 1138, 1 };
FieldActorEntry D_800A59E0 = { D_800A5940, D_800A577C, 0x2B, 4, 764, 1138, 1 };
FieldActorEntry D_800A59F4 = { D_800A594C, D_800A57C4, 0x2B, 4, 764, 1138, 1 };
FieldActorEntry D_800A5A08 = { D_800A5958, D_800A57E8, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5A1C = { D_800A5960, D_800A5818, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5A30 = { D_800A5968, D_800A5830, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5A44 = { D_800A5970, D_800A5848, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5A58 = { D_800A5978, D_800A5860, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5A6C = { D_800A5980, D_800A5878, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5A80 = { D_800A5988, D_800A5890, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5A94 = { D_800A5990, D_800A58A8, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5AA8 = { D_800A5998, D_800A58C0, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5ABC = { D_800A59A0, D_800A58D8, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5AD0 = { D_800A59A8, D_800A58F0, 0x5A, 5, 924, 323, 1 };
FieldActorEntry D_800A5AE4 = { D_800A59B0, D_800A5908, 0x9D, 6, 764, 1138, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A59B8,
    &D_800A59CC,
    &D_800A59E0,
    &D_800A59F4,
    &D_800A5A08,
    &D_800A5A1C,
    &D_800A5A30,
    &D_800A5A44,
    &D_800A5A58,
    &D_800A5A6C,
    &D_800A5A80,
    &D_800A5A94,
    &D_800A5AA8,
    &D_800A5ABC,
    &D_800A5AD0,
    &D_800A5AE4,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 1, 0xE6, 2, 0x32, 0, 0, 0, 0, 0, 966, 364, 0, 0 },
    { 1, 0, 0x40, 2, 0x54, 2, 0, 2, 6, 0, 931, 293, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 179, 400, 0, 0 },
    { 1, 0, 0x40, 2, 1, 1, 1, 6, 8, 0, 602, 1071, 0, 0 },
    { 1, 0, 0xC8, 6, 7, 0, 0, 0, 0, 0, 745, 598, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 298, 442, 505, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x22A, 0x648, 0xD0, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 8, 0xF0, 0x4D8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 8, 0x100, 0x450, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x102, 0x420, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0xF2, 0x388, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x1D2, 0x4C8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x1C2, 0x460, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 0xF, 0x1AF, 0x428, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 0xF, 0x1BF, 0x330, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 0x16, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 9, 0x330, 0x208, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 9, 0x340, 0x170, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 60, D_800A5164, EVENT_TEXT(0), NULL, func_800A4FB8 },
    { 61, D_800A5204, EVENT_TEXT(1), NULL, func_800A5004 },
    { -1, NULL, 0, NULL, NULL },
};
