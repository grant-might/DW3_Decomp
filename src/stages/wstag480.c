#include "common.h"
#include "stage.h"
void func_800A4E48();
extern StageTileFrame **D_800A5718[];

/* Plays a sequence of StageTileFrame animations on tile */
void func_800A4CBC(StageTile *tile, StageTileFrame **seqs, StageTileCursor *cur, s32 depth) {
    s32 dt;

    if (depth == 0) {
        dt = GFX.funcs.getFrameTime();
        if (dt > 4) {
            dt = 4;
        }
        cur->timer -= dt;
    }
    if (cur->timer <= 0) {
        if (seqs[cur->seq][cur->index].last) {
            cur->seq++;
            cur->index = 0;
            if (seqs[cur->seq] == NULL) {
                cur->seq = 0;
            }
        } else {
            cur->index++;
        }
        cur->timer += seqs[cur->seq][cur->index].duration;
        func_800A4CBC(tile, seqs, cur, depth + 1);
    }
    if (depth == 0) {
        tile->frame = seqs[cur->seq][cur->index].frame;
        tile->clutRow = seqs[cur->seq][cur->index].clutRow;
    }
}

/* Plays the sequences of the records with animations 1 to 5 */
void func_800A4E48(StageTileCursors *task) {
    StageTile *tile;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->cursors[0].seq = 0;
        task->cursors[0].index = 0;
        task->cursors[0].timer = D_800A5718[0][0][0].duration;
        task->cursors[1].seq = 0;
        task->cursors[1].index = 0;
        task->cursors[1].timer = D_800A5718[1][0][0].duration;
        task->cursors[2].seq = 0;
        task->cursors[2].index = 0;
        task->cursors[2].timer = D_800A5718[2][0][0].duration;
        task->cursors[3].seq = 0;
        task->cursors[3].index = 0;
        task->cursors[3].timer = D_800A5718[3][0][0].duration;
        task->cursors[4].seq = 0;
        task->cursors[4].index = 0;
        task->cursors[4].timer = D_800A5718[3][0][0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
            switch (tile->anim) {
            case 1:
                func_800A4CBC(tile, D_800A5718[0], &task->cursors[0], 0);
                break;
            case 2:
                func_800A4CBC(tile, D_800A5718[1], &task->cursors[1], 0);
                break;
            case 3:
                func_800A4CBC(tile, D_800A5718[2], &task->cursors[2], 0);
                break;
            case 4:
                func_800A4CBC(tile, D_800A5718[3], &task->cursors[3], 0);
                break;
            case 5:
                func_800A4CBC(tile, D_800A5718[4], &task->cursors[4], 0);
                break;
            }
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A5028(void) {
    return createTask(func_800A4E48, 0x78, 0);
}

/* Creates the stage's second object, and the event object of story progress 7 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[1] = func_800A5028();
        if (GAME.progress == 7 && FLAGS_00.checkCondition(0x4000, 1)) {
            children[0] = FIELDSTG_startEvent(0xAB);
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

void func_800A5150(void) {
    FLAGS_00.applyAction(0x4000, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A519C(void) {
    GAME.progress = 8;
}

/* the color the setup copies to D_800990B4.spriteColor */
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0 };

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x357
#define STAGE_ARCHIVE 0x628
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x366
#define STAGE_ARCHIVE 0x638
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x1F000, 0x34400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x11;
    D_800990B4.music = 0x60440000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(1, STAGE_FILE << 16 | 3);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 4);
    D_8009A70C.unk50(0);
    if (GAME.progress < 0xA) {
        D_800990B4.battles = &stageBattles[0];
    } else if (GAME.progress < 0x18) {
        D_800990B4.battles = &stageBattles[1];
    } else {
        D_800990B4.battles = &stageBattles[2];
    }
}

extern StageTileFrame D_800A5538[];
extern StageTileFrame D_800A5548[];
extern StageTileFrame D_800A5560[];
extern StageTileFrame D_800A5570[];
extern StageTileFrame D_800A5588[];
extern StageTileFrame D_800A5598[];
extern StageTileFrame D_800A55B0[];
extern StageTileFrame D_800A55C0[];
extern StageTileFrame D_800A55D8[];
extern StageTileFrame D_800A55E8[];
extern StageTileFrame *D_800A5600[];
extern StageTileFrame *D_800A5638[];
extern StageTileFrame *D_800A5670[];
extern StageTileFrame *D_800A56A8[];
extern StageTileFrame *D_800A56E0[];
extern Battle D_800A572C;
extern Battle D_800A5738;
extern Battle D_800A5744;
extern Battle D_800A5750;
extern Battle D_800A575C;
extern Battle D_800A5768;
extern Battle D_800A5774;
extern Battle D_800A5780;
extern Battle D_800A57B0;
extern Battle D_800A57BC;
extern Battle D_800A57C8;
extern Battle D_800A57D4;
extern Battle D_800A57E0;
extern Battle D_800A57EC;
extern Battle D_800A57F8;
extern Battle D_800A5804;
extern Battle D_800A5834;
extern Battle D_800A5840;
extern Battle D_800A584C;
extern Battle D_800A5858;
extern Battle D_800A5864;
extern Battle D_800A5870;
extern Battle D_800A587C;
extern Battle D_800A5888;
extern Battle D_800A58B8;
extern Battle D_800A58C4;
extern Battle D_800A58D0;
extern Battle D_800A58DC;
extern Battle D_800A58E8;
extern Battle D_800A58F4;
extern Battle D_800A5900;
extern Battle D_800A590C;
extern Battle D_800A593C;
extern Battle D_800A5948;
extern Battle D_800A5954;
extern Battle D_800A5960;
extern Battle D_800A596C;
extern Battle D_800A5978;
extern Battle D_800A5984;
extern Battle D_800A5990;
extern Battle D_800A59C0;
extern Battle D_800A59CC;
extern Battle D_800A59D8;
extern Battle D_800A59E4;
extern Battle D_800A59F0;
extern Battle D_800A59FC;
extern Battle D_800A5A08;
extern Battle D_800A5A14;
extern Battle D_800A5A44;
extern Battle D_800A5A50;
extern Battle D_800A5A5C;
extern Battle D_800A5A68;
extern Battle D_800A5A74;
extern Battle D_800A5A80;
extern Battle D_800A5A8C;
extern Battle D_800A5A98;
extern Battle D_800A5AC8;
extern Battle D_800A5AD4;
extern Battle D_800A5AE0;
extern Battle D_800A5AEC;
extern Battle D_800A5AF8;
extern Battle D_800A5B04;
extern Battle D_800A5B10;
extern Battle D_800A5B1C;
extern Battle D_800A5B4C;
extern Battle D_800A5B58;
extern Battle D_800A5B64;
extern Battle D_800A5B70;
extern Battle D_800A5B7C;
extern Battle D_800A5B88;
extern Battle D_800A5B94;
extern Battle D_800A5BA0;
extern Battle D_800A5BD0;
extern Battle D_800A5BDC;
extern Battle D_800A5BE8;
extern Battle D_800A5BF4;
extern Battle D_800A5C00;
extern Battle D_800A5C0C;
extern Battle D_800A5C18;
extern Battle D_800A5C24;
extern Battle D_800A5C54;
extern Battle D_800A5C60;
extern Battle D_800A5C6C;
extern Battle D_800A5C78;
extern Battle D_800A5C84;
extern Battle D_800A5C90;
extern Battle D_800A5C9C;
extern Battle D_800A5CA8;
extern Battle D_800A5CD8;
extern Battle D_800A5CE4;
extern Battle D_800A5CF0;
extern Battle D_800A5CFC;
extern Battle D_800A5D08;
extern Battle D_800A5D14;
extern Battle D_800A5D20;
extern Battle D_800A5D2C;
extern BattleList D_800A578C;
extern BattleList D_800A5810;
extern BattleList D_800A5894;
extern BattleList D_800A5918;
extern BattleList D_800A599C;
extern BattleList D_800A5A20;
extern BattleList D_800A5AA4;
extern BattleList D_800A5B28;
extern BattleList D_800A5BAC;
extern BattleList D_800A5C30;
extern BattleList D_800A5CB4;
extern BattleList D_800A5D38;
extern u16 D_800A5E20[];
extern u16 D_800A5E28[];
extern u16 D_800A5E30[];
extern u16 D_800A5E38[];
extern u16 D_800A5E40[];
extern u16 D_800A5E88[];
extern FieldTalk D_800A5E4C[];
extern FieldActorEntry D_800A5E90;
extern s16 D_800A5334[];
extern s16 D_800A53E4[];
extern s16 D_800A5460[];

s16 D_800A5334[] = {
    0x102, 2, 0x138, 0x335, 3,
    0x100, 0x85, 0x118, 0x325,
    0x101, 0x85, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0x85,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x85,
    0x300, 0x1E,
    0x200, 0, 1, 0x85, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x85, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
s16 D_800A53E4[] = {
    0x100, 2, 0x138, 0x335,
    0x101, 2, 1, 3,
    0x100, 0x85, 0x118, 0x325,
    0x101, 0x85, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0x85, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x85, 2,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x138, 0x354, 0,
    0x302, 2,
    0x102, 2, 0x158, 0x364, 7,
    0x300, 6,
    0x304, 0x234, 0x130, 0x360, 5,
    0,
};
s16 D_800A5460[] = {
    0x600, 0, 2,
    0x102, 2, 0x138, 0x335, 3,
    0x100, 0x85, 0x118, 0x325,
    0x101, 0x85, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 2, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0x85, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 3,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0x85,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x85,
    0x300, 0x1E,
    0x200, 0, 4, 0x85, 0,
    0x301,
    0x300, 0x3C,
    0x200, 0, 6, 0x85, 0,
    0x301,
    0x101, 0x85, 1, 3,
    0x300, 0x1E,
    0x102, 0x85, 0x80, 0x2D9, 3,
    0x302, 0x85,
    0x200, 0, 5, 2, 3,
    0x100, 0x85, 0, 0,
    0x101, 0x85, 1, 0,
    0x301,
    0x300, 0x1E,
    0,
};
StageTileFrame D_800A5538[] = {
    { 64, 10, 0, 0 }, { 64, 10, 1, 0 }, { 64, 10, 2, 0 }, { 64, 10, 1, 1 },
};
StageTileFrame D_800A5548[] = {
    { 65, 4, 2, 0 }, { 65, 4, 4, 0 }, { 65, 4, 6, 0 }, { 65, 4, 4, 0 },
    { 65, 4, 2, 0 }, { 65, 4, 0, 1 },
};
StageTileFrame D_800A5560[] = {
    { 66, 10, 0, 0 }, { 66, 10, 1, 0 }, { 66, 10, 2, 0 }, { 66, 10, 1, 1 },
};
StageTileFrame D_800A5570[] = {
    { 67, 4, 2, 0 }, { 67, 4, 4, 0 }, { 67, 4, 6, 0 }, { 67, 4, 4, 0 },
    { 67, 4, 2, 0 }, { 67, 4, 0, 1 },
};
StageTileFrame D_800A5588[] = {
    { 68, 10, 0, 0 }, { 68, 10, 1, 0 }, { 68, 10, 2, 0 }, { 68, 10, 1, 1 },
};
StageTileFrame D_800A5598[] = {
    { 69, 4, 2, 0 }, { 69, 4, 4, 0 }, { 69, 4, 6, 0 }, { 69, 4, 4, 0 },
    { 69, 4, 2, 0 }, { 69, 4, 0, 1 },
};
StageTileFrame D_800A55B0[] = {
    { 70, 10, 0, 0 }, { 70, 10, 1, 0 }, { 70, 10, 2, 0 }, { 70, 10, 1, 1 },
};
StageTileFrame D_800A55C0[] = {
    { 71, 4, 2, 0 }, { 71, 4, 4, 0 }, { 71, 4, 6, 0 }, { 71, 4, 4, 0 },
    { 71, 4, 2, 0 }, { 71, 4, 0, 1 },
};
StageTileFrame D_800A55D8[] = {
    { 72, 10, 0, 0 }, { 72, 10, 1, 0 }, { 72, 10, 2, 0 }, { 72, 10, 1, 1 },
};
StageTileFrame D_800A55E8[] = {
    { 73, 4, 2, 0 }, { 73, 4, 4, 0 }, { 73, 4, 6, 0 }, { 73, 4, 4, 0 },
    { 73, 4, 2, 0 }, { 73, 4, 0, 1 },
};
StageTileFrame *D_800A5600[] = {
    D_800A5538, D_800A5538, D_800A5538, D_800A5538,
    D_800A5538, D_800A5538, D_800A5538, D_800A5538,
    D_800A5538, D_800A5538, D_800A5538, D_800A5538,
    D_800A5548, NULL,
};
StageTileFrame *D_800A5638[] = {
    D_800A5560, D_800A5560, D_800A5560, D_800A5560,
    D_800A5560, D_800A5560, D_800A5560, D_800A5560,
    D_800A5560, D_800A5560, D_800A5560, D_800A5560,
    D_800A5570, NULL,
};
StageTileFrame *D_800A5670[] = {
    D_800A5588, D_800A5588, D_800A5588, D_800A5588,
    D_800A5588, D_800A5588, D_800A5588, D_800A5588,
    D_800A5588, D_800A5588, D_800A5588, D_800A5588,
    D_800A5598, NULL,
};
StageTileFrame *D_800A56A8[] = {
    D_800A55B0, D_800A55B0, D_800A55B0, D_800A55B0,
    D_800A55B0, D_800A55B0, D_800A55B0, D_800A55B0,
    D_800A55B0, D_800A55B0, D_800A55B0, D_800A55B0,
    D_800A55C0, NULL,
};
StageTileFrame *D_800A56E0[] = {
    D_800A55D8, D_800A55D8, D_800A55D8, D_800A55D8,
    D_800A55D8, D_800A55D8, D_800A55D8, D_800A55D8,
    D_800A55D8, D_800A55D8, D_800A55D8, D_800A55D8,
    D_800A55E8, NULL,
};
StageTileFrame **D_800A5718[] = {
    D_800A5600, D_800A5638, D_800A5670, D_800A56A8,
    D_800A56E0,
};
Battle D_800A572C = { 91, 9, 0x60080000 };
Battle D_800A5738 = { 91, 9, 0x60080000 };
Battle D_800A5744 = { 91, 9, 0x60080000 };
Battle D_800A5750 = { 91, 9, 0x60080000 };
Battle D_800A575C = { 91, 9, 0x60080000 };
Battle D_800A5768 = { 91, 9, 0x60080000 };
Battle D_800A5774 = { 91, 9, 0x60080000 };
Battle D_800A5780 = { 91, 9, 0x60080000 };
BattleList D_800A578C = {
    4,
    { &D_800A572C, &D_800A5738, &D_800A5744, &D_800A5750,
      &D_800A575C, &D_800A5768, &D_800A5774, &D_800A5780 },
};
Battle D_800A57B0 = { 147, 8, 0x60080000 };
Battle D_800A57BC = { 147, 8, 0x60080000 };
Battle D_800A57C8 = { 54, 8, 0x60080000 };
Battle D_800A57D4 = { 54, 8, 0x60080000 };
Battle D_800A57E0 = { 91, 8, 0x60080000 };
Battle D_800A57EC = { 91, 8, 0x60080000 };
Battle D_800A57F8 = { 91, 8, 0x60080000 };
Battle D_800A5804 = { 91, 8, 0x60080000 };
BattleList D_800A5810 = {
    1,
    { &D_800A57B0, &D_800A57BC, &D_800A57C8, &D_800A57D4,
      &D_800A57E0, &D_800A57EC, &D_800A57F8, &D_800A5804 },
};
Battle D_800A5834 = { 0, 0, 0x60040000 };
Battle D_800A5840 = { 0, 0, 0x60040000 };
Battle D_800A584C = { 0, 0, 0x60040000 };
Battle D_800A5858 = { 0, 0, 0x60040000 };
Battle D_800A5864 = { 0, 0, 0x60040000 };
Battle D_800A5870 = { 0, 0, 0x60040000 };
Battle D_800A587C = { 0, 0, 0x60040000 };
Battle D_800A5888 = { 0, 0, 0x60040000 };
BattleList D_800A5894 = {
    0,
    { &D_800A5834, &D_800A5840, &D_800A584C, &D_800A5858,
      &D_800A5864, &D_800A5870, &D_800A587C, &D_800A5888 },
};
Battle D_800A58B8 = { 11, 19, 0x60880000 };
Battle D_800A58C4 = { 0, 0, 0x60040000 };
Battle D_800A58D0 = { 0, 0, 0x60040000 };
Battle D_800A58DC = { 329, 8, 0x60080000 };
Battle D_800A58E8 = { 328, 8, 0x60080000 };
Battle D_800A58F4 = { 0, 0, 0x60040000 };
Battle D_800A5900 = { 48, 8, 0x60080000 };
Battle D_800A590C = { 66, 8, 0x60080000 };
BattleList D_800A5918 = {
    0,
    { &D_800A58B8, &D_800A58C4, &D_800A58D0, &D_800A58DC,
      &D_800A58E8, &D_800A58F4, &D_800A5900, &D_800A590C },
};
Battle D_800A593C = { 38, 9, 0x60080000 };
Battle D_800A5948 = { 38, 9, 0x60080000 };
Battle D_800A5954 = { 38, 9, 0x60080000 };
Battle D_800A5960 = { 38, 9, 0x60080000 };
Battle D_800A596C = { 55, 9, 0x60080000 };
Battle D_800A5978 = { 55, 9, 0x60080000 };
Battle D_800A5984 = { 55, 9, 0x60080000 };
Battle D_800A5990 = { 55, 9, 0x60080000 };
BattleList D_800A599C = {
    3,
    { &D_800A593C, &D_800A5948, &D_800A5954, &D_800A5960,
      &D_800A596C, &D_800A5978, &D_800A5984, &D_800A5990 },
};
Battle D_800A59C0 = { 53, 8, 0x60080000 };
Battle D_800A59CC = { 53, 8, 0x60080000 };
Battle D_800A59D8 = { 53, 8, 0x60080000 };
Battle D_800A59E4 = { 147, 8, 0x60080000 };
Battle D_800A59F0 = { 147, 8, 0x60080000 };
Battle D_800A59FC = { 147, 8, 0x60080000 };
Battle D_800A5A08 = { 54, 8, 0x60080000 };
Battle D_800A5A14 = { 54, 8, 0x60080000 };
BattleList D_800A5A20 = {
    2,
    { &D_800A59C0, &D_800A59CC, &D_800A59D8, &D_800A59E4,
      &D_800A59F0, &D_800A59FC, &D_800A5A08, &D_800A5A14 },
};
Battle D_800A5A44 = { 0, 0, 0x60040000 };
Battle D_800A5A50 = { 0, 0, 0x60040000 };
Battle D_800A5A5C = { 0, 0, 0x60040000 };
Battle D_800A5A68 = { 0, 0, 0x60040000 };
Battle D_800A5A74 = { 0, 0, 0x60040000 };
Battle D_800A5A80 = { 0, 0, 0x60040000 };
Battle D_800A5A8C = { 0, 0, 0x60040000 };
Battle D_800A5A98 = { 0, 0, 0x60040000 };
BattleList D_800A5AA4 = {
    0,
    { &D_800A5A44, &D_800A5A50, &D_800A5A5C, &D_800A5A68,
      &D_800A5A74, &D_800A5A80, &D_800A5A8C, &D_800A5A98 },
};
Battle D_800A5AC8 = { 0, 0, 0x60040000 };
Battle D_800A5AD4 = { 0, 0, 0x60040000 };
Battle D_800A5AE0 = { 0, 0, 0x60040000 };
Battle D_800A5AEC = { 329, 9, 0x60080000 };
Battle D_800A5AF8 = { 328, 8, 0x60080000 };
Battle D_800A5B04 = { 0, 0, 0x60040000 };
Battle D_800A5B10 = { 48, 9, 0x60080000 };
Battle D_800A5B1C = { 66, 8, 0x60080000 };
BattleList D_800A5B28 = {
    0,
    { &D_800A5AC8, &D_800A5AD4, &D_800A5AE0, &D_800A5AEC,
      &D_800A5AF8, &D_800A5B04, &D_800A5B10, &D_800A5B1C },
};
Battle D_800A5B4C = { 38, 9, 0x60080000 };
Battle D_800A5B58 = { 55, 9, 0x60080000 };
Battle D_800A5B64 = { 56, 9, 0x60080000 };
Battle D_800A5B70 = { 56, 9, 0x60080000 };
Battle D_800A5B7C = { 56, 9, 0x60080000 };
Battle D_800A5B88 = { 56, 9, 0x60080000 };
Battle D_800A5B94 = { 56, 9, 0x60080000 };
Battle D_800A5BA0 = { 56, 9, 0x60080000 };
BattleList D_800A5BAC = {
    3,
    { &D_800A5B4C, &D_800A5B58, &D_800A5B64, &D_800A5B70,
      &D_800A5B7C, &D_800A5B88, &D_800A5B94, &D_800A5BA0 },
};
Battle D_800A5BD0 = { 53, 8, 0x60080000 };
Battle D_800A5BDC = { 147, 8, 0x60080000 };
Battle D_800A5BE8 = { 60, 8, 0x60080000 };
Battle D_800A5BF4 = { 60, 8, 0x60080000 };
Battle D_800A5C00 = { 60, 8, 0x60080000 };
Battle D_800A5C0C = { 60, 8, 0x60080000 };
Battle D_800A5C18 = { 60, 8, 0x60080000 };
Battle D_800A5C24 = { 60, 8, 0x60080000 };
BattleList D_800A5C30 = {
    2,
    { &D_800A5BD0, &D_800A5BDC, &D_800A5BE8, &D_800A5BF4,
      &D_800A5C00, &D_800A5C0C, &D_800A5C18, &D_800A5C24 },
};
Battle D_800A5C54 = { 0, 0, 0x60040000 };
Battle D_800A5C60 = { 0, 0, 0x60040000 };
Battle D_800A5C6C = { 0, 0, 0x60040000 };
Battle D_800A5C78 = { 0, 0, 0x60040000 };
Battle D_800A5C84 = { 0, 0, 0x60040000 };
Battle D_800A5C90 = { 0, 0, 0x60040000 };
Battle D_800A5C9C = { 0, 0, 0x60040000 };
Battle D_800A5CA8 = { 0, 0, 0x60040000 };
BattleList D_800A5CB4 = {
    0,
    { &D_800A5C54, &D_800A5C60, &D_800A5C6C, &D_800A5C78,
      &D_800A5C84, &D_800A5C90, &D_800A5C9C, &D_800A5CA8 },
};
Battle D_800A5CD8 = { 0, 0, 0x60040000 };
Battle D_800A5CE4 = { 0, 0, 0x60040000 };
Battle D_800A5CF0 = { 0, 0, 0x60040000 };
Battle D_800A5CFC = { 329, 9, 0x60080000 };
Battle D_800A5D08 = { 328, 8, 0x60080000 };
Battle D_800A5D14 = { 0, 0, 0x60040000 };
Battle D_800A5D20 = { 48, 9, 0x60080000 };
Battle D_800A5D2C = { 66, 8, 0x60080000 };
BattleList D_800A5D38 = {
    0,
    { &D_800A5CD8, &D_800A5CE4, &D_800A5CF0, &D_800A5CFC,
      &D_800A5D08, &D_800A5D14, &D_800A5D20, &D_800A5D2C },
};
FieldBattles stageBattles[] = {
    { 17, 0, 0, { &D_800A578C, &D_800A5810, &D_800A5894, &D_800A5918 } },
    { 18, 1, 0, { &D_800A599C, &D_800A5A20, &D_800A5AA4, &D_800A5B28 } },
    { 56, 2, 0, { &D_800A5BAC, &D_800A5C30, &D_800A5CB4, &D_800A5D38 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x170, 0x100, 0xC0, 0, 0x160, 0x1FA },
};
u16 D_800A5E20[] = { 0x6007, 1, 0xFFFF };
u16 D_800A5E28[] = { 0x6008, 1, 0xFFFF };
u16 D_800A5E30[] = { 0x6009, 1, 0xFFFF };
u16 D_800A5E38[] = { 0x600A, 1, 0xFFFF };
u16 D_800A5E40[] = { 0x1C09, 1, 0x901F, 1, 0xFFFF };
FieldTalk D_800A5E4C[] = {
    { D_800A5E20, NULL, 0x245 },
    { D_800A5E28, NULL, 0x245 },
    { D_800A5E30, NULL, 0x246 },
    { D_800A5E38, D_800A5E40, 0x247 },
    { NULL, NULL, 0 },
};
u16 D_800A5E88[] = { 0x1C09, 0, 0xFFFF };
FieldActorEntry D_800A5E90 = { D_800A5E88, D_800A5E4C, 0x85, 4, 280, 805, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A5E90,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 1, 0x40, 2, 0x40, 0, 0, 0, 0, 0, 310, 197, 0, 0 },
    { 1, 2, 0x40, 2, 0x42, 0, 0, 0, 0, 0, 381, 208, 0, 0 },
    { 1, 3, 0x40, 2, 0x44, 0, 0, 0, 0, 0, 416, 204, 0, 0 },
    { 1, 5, 0x40, 2, 0x48, 0, 0, 0, 0, 0, 464, 258, 0, 0 },
    { 1, 4, 0x40, 2, 0x46, 0, 0, 0, 0, 0, 468, 206, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x37, 8, 0, 191, 408, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x37, 8, 0, 564, 488, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x37, 8, 0, 594, 498, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x37, 8, 0, 724, 120, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x37, 8, 0, 772, 419, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x37, 8, 0, 804, 410, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x37, 8, 0, 901, 541, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 977, 774, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 986, 772, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 995, 783, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 1010, 771, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 1017, 771, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 1024, 784, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 1047, 799, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 1057, 791, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 1066, 796, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 1081, 795, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 1088, 789, 0, 0 },
    { 1, 0, 0x40, 2, 0x38, 1, 0x38, 0x3D, 8, 0, 1096, 796, 0, 0 },
    { 1, 0, 0x40, 2, 0x3E, 2, 0, 0xF, 6, 0, 79, 617, 0, 0 },
    { 1, 0, 0x40, 2, 0x3E, 2, 0, 0xF, 6, 0, 262, 882, 0, 0 },
    { 1, 0, 0x40, 2, 0x3E, 2, 0, 0xF, 6, 0, 431, 638, 0, 0 },
    { 1, 0, 0x40, 2, 0x3E, 2, 0, 0xF, 6, 0, 702, 664, 0, 0 },
    { 1, 0, 0x40, 2, 0x3E, 2, 0, 0xF, 6, 0, 931, 679, 0, 0 },
    { 1, 0, 0x40, 2, 0x3E, 2, 0, 0xF, 6, 0, 1151, 642, 0, 0 },
    { 1, 0, 0x40, 2, 0x3E, 2, 0, 0xF, 6, 0, 1293, 701, 0, 0 },
    { 1, 0, 0x40, 2, 0x3F, 2, 0, 0xF, 6, 0, 707, 1103, 0, 0 },
    { 1, 0, 0x40, 2, 0x3F, 2, 0, 0xF, 6, 0, 732, 964, 0, 0 },
    { 1, 0, 0x40, 2, 0x3F, 2, 0, 0xF, 6, 0, 1051, 956, 0, 0 },
    { 1, 0, 0x40, 2, 0x3F, 2, 0, 0xF, 6, 0, 1076, 1132, 0, 0 },
    { 1, 0, 0x40, 2, 0x3F, 2, 0, 0xF, 6, 0, 1290, 929, 0, 0 },
    { 1, 0, 0x40, 2, 0x4B, 1, 0x4B, 0x56, 0x10, 0, 871, 187, 0, 0 },
    { 1, 0, 0x40, 2, 0x57, 1, 0x57, 0x62, 0x10, 0, 256, 462, 0, 0 },
    { 1, 0, 0xFF, 2, 0x1A, 0, 0, 0, 0, 0, 1280, 250, 0, 0 },
    { 1, 0, 0x80, 2, 0x2D, 0, 0, 0, 0, 0, 640, 640, 0, 0 },
    { 1, 0, 0xFF, 2, 0x4A, 0, 0, 0, 0, 0, 1152, 640, 0, 0 },
    { 1, 0, 0x40, 2, 0, 1, 0, 5, 8, 0, 1127, 1030, 0, 0 },
    { 1, 0, 0x40, 6, 0x1B, 1, 0x1B, 0x1D, 0xA, 0, 548, 1332, 0, 0 },
    { 1, 0, 0x40, 6, 0x1B, 1, 0x1B, 0x1D, 0xA, 0, 718, 1206, 0, 0 },
    { 1, 0, 0x40, 6, 0x1B, 1, 0x1B, 0x1D, 0xA, 0, 1060, 992, 0, 0 },
    { 1, 0, 0x40, 6, 0x1B, 1, 0x1B, 0x1D, 0xA, 0, 1185, 379, 0, 0 },
    { 1, 0, 0x40, 6, 0x1B, 1, 0x1B, 0x1D, 0xA, 0, 1201, 1022, 0, 0 },
    { 1, 0, 0x40, 6, 0x1E, 1, 0x1E, 0x20, 0xA, 0, 308, 945, 0, 0 },
    { 1, 0, 0x40, 6, 0x1E, 1, 0x1E, 0x20, 0xA, 0, 399, 792, 0, 0 },
    { 1, 0, 0x40, 6, 0x1E, 1, 0x1E, 0x20, 0xA, 0, 716, 561, 0, 0 },
    { 1, 0, 0x40, 6, 0x1E, 1, 0x1E, 0x20, 0xA, 0, 733, 801, 0, 0 },
    { 1, 0, 0x40, 6, 0x1E, 1, 0x1E, 0x20, 0xA, 0, 774, 561, 0, 0 },
    { 1, 0, 0x40, 6, 0x1E, 1, 0x1E, 0x20, 0xA, 0, 778, 921, 0, 0 },
    { 1, 0, 0x40, 6, 0x1E, 1, 0x1E, 0x20, 0xA, 0, 1397, 1163, 0, 0 },
    { 1, 0, 0x40, 6, 0x21, 1, 0x21, 0x23, 0xA, 0, 807, 1209, 0, 0 },
    { 1, 0, 0x40, 6, 0x21, 1, 0x21, 0x23, 0xA, 0, 849, 1138, 0, 0 },
    { 1, 0, 0x40, 6, 0x21, 1, 0x21, 0x23, 0xA, 0, 1038, 926, 0, 0 },
    { 1, 0, 0x40, 6, 0x21, 1, 0x21, 0x23, 0xA, 0, 1111, 887, 0, 0 },
    { 1, 0, 0x40, 6, 0x21, 1, 0x21, 0x23, 0xA, 0, 1208, 1014, 0, 0 },
    { 1, 0, 0x40, 6, 0x21, 1, 0x21, 0x23, 0xA, 0, 1294, 541, 0, 0 },
    { 1, 0, 0x40, 6, 0x21, 1, 0x21, 0x23, 0xA, 0, 1343, 315, 0, 0 },
    { 1, 0, 0x40, 6, 0x21, 1, 0x21, 0x23, 0xA, 0, 1377, 734, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 190, 620, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 256, 1260, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 271, 861, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 354, 1089, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 467, 1200, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 544, 925, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 550, 1203, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 582, 1143, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 884, 148, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 923, 1263, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 1068, 1156, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 1221, 1220, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 189, 608, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 272, 404, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 383, 545, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 507, 1100, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 647, 505, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 743, 998, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 806, 518, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 858, 817, 0, 0 },
    { 1, 0, 0x40, 6, 0x24, 1, 0x24, 0x26, 0xA, 0, 961, 743, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 265, 1270, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 337, 461, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 388, 555, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 599, 726, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 658, 358, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 660, 285, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 714, 1139, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 765, 97, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 809, 222, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 874, 1029, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 893, 157, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 928, 871, 0, 0 },
    { 1, 0, 0x40, 6, 0x27, 1, 0x27, 0x29, 0xA, 0, 1225, 216, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 429, 1292, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 508, 1256, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 601, 1307, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 609, 1298, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 740, 1203, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 827, 1044, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 839, 1046, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 904, 1256, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 957, 1156, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 959, 1149, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1020, 810, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1028, 1041, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1044, 1105, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1064, 919, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1065, 831, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1110, 1001, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1155, 1152, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1168, 747, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1172, 739, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1183, 385, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1184, 749, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1224, 1022, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1273, 1198, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1357, 1139, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1378, 723, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1399, 723, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1428, 1151, 0, 0 },
    { 1, 0, 0x40, 6, 0x2A, 1, 0x2A, 0x2C, 0xA, 0, 1508, 1083, 0, 0 },
    { 1, 0, 0xFF, 6, 0x63, 0, 0, 0, 0, 0, 280, 280, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 31, 277, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 59, 658, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 215, 936, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 258, 235, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 277, 1117, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 293, 769, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 321, 1004, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 329, 1232, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 336, 615, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 349, 501, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 426, 720, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 444, 1104, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 478, 1313, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 500, 1150, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 516, 860, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 522, 188, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 546, 1010, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 592, 274, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 627, 1062, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 628, 1190, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 647, 1284, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 658, 794, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 675, 223, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 675, 500, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 689, 925, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 695, 359, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 752, 518, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 765, 187, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 768, 1184, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 787, 97, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 819, 1001, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 831, 586, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 863, 772, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 909, 1064, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 928, 561, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 951, 1243, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 996, 869, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 996, 869, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1010, 95, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1012, 1165, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1077, 1061, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1121, 928, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1126, 178, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1136, 400, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1155, 305, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1210, 1101, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1247, 712, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1319, 451, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1354, 1028, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1362, 347, 0, 0 },
    { 1, 0, 0x40, 0xA, 6, 1, 6, 9, 0xA, 0, 1396, 620, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 64, 753, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 144, 413, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 146, 568, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 193, 175, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 218, 836, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 257, 1190, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 261, 651, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 274, 1049, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 410, 1279, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 424, 842, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 425, 1235, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 449, 1160, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 460, 932, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 475, 1012, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 493, 701, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 660, 735, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 725, 327, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 728, 1128, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 732, 984, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 976, 249, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 1007, 556, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 1083, 1286, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 1087, 762, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 1190, 127, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 1232, 1060, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 1352, 221, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 1453, 531, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2E, 1, 0x2E, 0x31, 0xA, 0, 1478, 397, 0, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 1041, 566, 603, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 1133, 585, 596, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 862, 659, 666, 0 },
    { 1, 0, 0x80, 4, 0xD, 0, 0, 0, 0, 0, 1022, 313, 367, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 693, 475, 479, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 661, 583, 589, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 1029, 891, 899, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 1011, 936, 945, 0 },
    { 1, 0, 0x40, 4, 0x12, 0, 0, 0, 0, 0, 321, 1025, 1031, 0 },
    { 1, 0, 0x40, 4, 0x13, 0, 0, 0, 0, 0, 821, 1047, 1057, 0 },
    { 1, 0, 0x40, 4, 0x14, 0, 0, 0, 0, 0, 261, 1055, 1060, 0 },
    { 1, 0, 0x40, 4, 0x15, 0, 0, 0, 0, 0, 612, 1088, 1097, 0 },
    { 1, 0, 0x40, 4, 0x16, 0, 0, 0, 0, 0, 993, 1122, 1127, 0 },
    { 1, 0, 0x40, 4, 0x17, 0, 0, 0, 0, 0, 804, 1152, 1160, 0 },
    { 1, 0, 0x40, 4, 0x18, 0, 0, 0, 0, 0, 401, 1225, 1231, 0 },
    { 1, 0, 0x40, 4, 0x19, 0, 0, 0, 0, 0, 608, 1249, 1255, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 496, 807, 807, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 528, 951, 951, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 560, 743, 743, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 577, 359, 359, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 607, 768, 768, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 704, 847, 847, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 800, 847, 847, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1072, 471, 471, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1120, 447, 447, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1136, 487, 487, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1152, 527, 527, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1175, 441, 441, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1184, 559, 559, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1200, 471, 471, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1248, 495, 495, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1303, 605, 605, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1312, 431, 431, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1344, 623, 623, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23B, 0x6C8, 0x1D4, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x234, 0x140, 0x350, 5, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 3, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E9, 0xB0, 0xF8, 7, 0, 0xE, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x30, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFD8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x30, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x6007, 1 }, { 0xFFFF, 0 } }, 8, 0xAA, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 6, 0, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 6, 1, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 170, D_800A5334, EVENT_TEXT(8), NULL, func_800A5150 },
    { 171, D_800A53E4, EVENT_TEXT(9), NULL, func_800A519C },
    { 240, D_800A5460, EVENT_TEXT(0xF), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
