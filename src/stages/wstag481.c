#include "common.h"
#include "stage.h"
void func_800A4E48();
extern StageTileFrame **D_800A5420[];

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
        task->cursors[0].timer = D_800A5420[0][0][0].duration;
        task->cursors[1].seq = 0;
        task->cursors[1].index = 0;
        task->cursors[1].timer = D_800A5420[1][0][0].duration;
        task->cursors[2].seq = 0;
        task->cursors[2].index = 0;
        task->cursors[2].timer = D_800A5420[2][0][0].duration;
        task->cursors[3].seq = 0;
        task->cursors[3].index = 0;
        task->cursors[3].timer = D_800A5420[3][0][0].duration;
        task->cursors[4].seq = 0;
        task->cursors[4].index = 0;
        task->cursors[4].timer = D_800A5420[3][0][0].duration;
        task->nextState(task);
        break;
    case TASK_RUN:
        for (tile = D_800990B4.objects; tile->unk2 != 0; tile++) {
            switch (tile->anim) {
            case 1:
                func_800A4CBC(tile, D_800A5420[0], &task->cursors[0], 0);
                break;
            case 2:
                func_800A4CBC(tile, D_800A5420[1], &task->cursors[1], 0);
                break;
            case 3:
                func_800A4CBC(tile, D_800A5420[2], &task->cursors[2], 0);
                break;
            case 4:
                func_800A4CBC(tile, D_800A5420[3], &task->cursors[3], 0);
                break;
            case 5:
                func_800A4CBC(tile, D_800A5420[4], &task->cursors[4], 0);
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

void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        children[0] = func_800A5028();
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

/* the color the setup copies to D_800990B4.spriteColor */
const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0 };

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x5EB
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x5FB
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x48600, 0xE600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x11;
    D_800990B4.music = 0x60440000;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(1, STAGE_FILE << 16 | 3);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 4);
    D_8009A70C.unk50(0);
}

extern StageTileFrame D_800A5240[];
extern StageTileFrame D_800A5250[];
extern StageTileFrame D_800A5268[];
extern StageTileFrame D_800A5278[];
extern StageTileFrame D_800A5290[];
extern StageTileFrame D_800A52A0[];
extern StageTileFrame D_800A52B8[];
extern StageTileFrame D_800A52C8[];
extern StageTileFrame D_800A52E0[];
extern StageTileFrame D_800A52F0[];
extern StageTileFrame *D_800A5308[];
extern StageTileFrame *D_800A5340[];
extern StageTileFrame *D_800A5378[];
extern StageTileFrame *D_800A53B0[];
extern StageTileFrame *D_800A53E8[];
extern Battle D_800A5434;
extern Battle D_800A5440;
extern Battle D_800A544C;
extern Battle D_800A5458;
extern Battle D_800A5464;
extern Battle D_800A5470;
extern Battle D_800A547C;
extern Battle D_800A5488;
extern Battle D_800A54B8;
extern Battle D_800A54C4;
extern Battle D_800A54D0;
extern Battle D_800A54DC;
extern Battle D_800A54E8;
extern Battle D_800A54F4;
extern Battle D_800A5500;
extern Battle D_800A550C;
extern Battle D_800A553C;
extern Battle D_800A5548;
extern Battle D_800A5554;
extern Battle D_800A5560;
extern Battle D_800A556C;
extern Battle D_800A5578;
extern Battle D_800A5584;
extern Battle D_800A5590;
extern Battle D_800A55C0;
extern Battle D_800A55CC;
extern Battle D_800A55D8;
extern Battle D_800A55E4;
extern Battle D_800A55F0;
extern Battle D_800A55FC;
extern Battle D_800A5608;
extern Battle D_800A5614;
extern BattleList D_800A5494;
extern BattleList D_800A5518;
extern BattleList D_800A559C;
extern BattleList D_800A5620;

StageTileFrame D_800A5240[] = {
    { 64, 10, 0, 0 }, { 64, 10, 1, 0 }, { 64, 10, 2, 0 }, { 64, 10, 1, 1 },
};
StageTileFrame D_800A5250[] = {
    { 65, 4, 2, 0 }, { 65, 4, 4, 0 }, { 65, 4, 6, 0 }, { 65, 4, 4, 0 },
    { 65, 4, 2, 0 }, { 65, 4, 0, 1 },
};
StageTileFrame D_800A5268[] = {
    { 66, 10, 0, 0 }, { 66, 10, 1, 0 }, { 66, 10, 2, 0 }, { 66, 10, 1, 1 },
};
StageTileFrame D_800A5278[] = {
    { 67, 4, 2, 0 }, { 67, 4, 4, 0 }, { 67, 4, 6, 0 }, { 67, 4, 4, 0 },
    { 67, 4, 2, 0 }, { 67, 4, 0, 1 },
};
StageTileFrame D_800A5290[] = {
    { 68, 10, 0, 0 }, { 68, 10, 1, 0 }, { 68, 10, 2, 0 }, { 68, 10, 1, 1 },
};
StageTileFrame D_800A52A0[] = {
    { 69, 4, 2, 0 }, { 69, 4, 4, 0 }, { 69, 4, 6, 0 }, { 69, 4, 4, 0 },
    { 69, 4, 2, 0 }, { 69, 4, 0, 1 },
};
StageTileFrame D_800A52B8[] = {
    { 70, 10, 0, 0 }, { 70, 10, 1, 0 }, { 70, 10, 2, 0 }, { 70, 10, 1, 1 },
};
StageTileFrame D_800A52C8[] = {
    { 71, 4, 2, 0 }, { 71, 4, 4, 0 }, { 71, 4, 6, 0 }, { 71, 4, 4, 0 },
    { 71, 4, 2, 0 }, { 71, 4, 0, 1 },
};
StageTileFrame D_800A52E0[] = {
    { 72, 10, 0, 0 }, { 72, 10, 1, 0 }, { 72, 10, 2, 0 }, { 72, 10, 1, 1 },
};
StageTileFrame D_800A52F0[] = {
    { 73, 4, 2, 0 }, { 73, 4, 4, 0 }, { 73, 4, 6, 0 }, { 73, 4, 4, 0 },
    { 73, 4, 2, 0 }, { 73, 4, 0, 1 },
};
StageTileFrame *D_800A5308[] = {
    D_800A5240, D_800A5240, D_800A5240, D_800A5240,
    D_800A5240, D_800A5240, D_800A5240, D_800A5240,
    D_800A5240, D_800A5240, D_800A5240, D_800A5240,
    D_800A5250, NULL,
};
StageTileFrame *D_800A5340[] = {
    D_800A5268, D_800A5268, D_800A5268, D_800A5268,
    D_800A5268, D_800A5268, D_800A5268, D_800A5268,
    D_800A5268, D_800A5268, D_800A5268, D_800A5268,
    D_800A5278, NULL,
};
StageTileFrame *D_800A5378[] = {
    D_800A5290, D_800A5290, D_800A5290, D_800A5290,
    D_800A5290, D_800A5290, D_800A5290, D_800A5290,
    D_800A5290, D_800A5290, D_800A5290, D_800A5290,
    D_800A52A0, NULL,
};
StageTileFrame *D_800A53B0[] = {
    D_800A52B8, D_800A52B8, D_800A52B8, D_800A52B8,
    D_800A52B8, D_800A52B8, D_800A52B8, D_800A52B8,
    D_800A52B8, D_800A52B8, D_800A52B8, D_800A52B8,
    D_800A52C8, NULL,
};
StageTileFrame *D_800A53E8[] = {
    D_800A52E0, D_800A52E0, D_800A52E0, D_800A52E0,
    D_800A52E0, D_800A52E0, D_800A52E0, D_800A52E0,
    D_800A52E0, D_800A52E0, D_800A52E0, D_800A52E0,
    D_800A52F0, NULL,
};
StageTileFrame **D_800A5420[] = {
    D_800A5308, D_800A5340, D_800A5378, D_800A53B0,
    D_800A53E8,
};
Battle D_800A5434 = { 107, 9, 0x60080000 };
Battle D_800A5440 = { 107, 9, 0x60080000 };
Battle D_800A544C = { 107, 9, 0x60080000 };
Battle D_800A5458 = { 107, 9, 0x60080000 };
Battle D_800A5464 = { 155, 9, 0x60080000 };
Battle D_800A5470 = { 155, 9, 0x60080000 };
Battle D_800A547C = { 155, 9, 0x60080000 };
Battle D_800A5488 = { 155, 9, 0x60080000 };
BattleList D_800A5494 = {
    4,
    { &D_800A5434, &D_800A5440, &D_800A544C, &D_800A5458,
      &D_800A5464, &D_800A5470, &D_800A547C, &D_800A5488 },
};
Battle D_800A54B8 = { 105, 8, 0x60080000 };
Battle D_800A54C4 = { 105, 8, 0x60080000 };
Battle D_800A54D0 = { 105, 8, 0x60080000 };
Battle D_800A54DC = { 105, 8, 0x60080000 };
Battle D_800A54E8 = { 159, 8, 0x60080000 };
Battle D_800A54F4 = { 159, 8, 0x60080000 };
Battle D_800A5500 = { 159, 8, 0x60080000 };
Battle D_800A550C = { 159, 8, 0x60080000 };
BattleList D_800A5518 = {
    2,
    { &D_800A54B8, &D_800A54C4, &D_800A54D0, &D_800A54DC,
      &D_800A54E8, &D_800A54F4, &D_800A5500, &D_800A550C },
};
Battle D_800A553C = { 0, 0, 0x60040000 };
Battle D_800A5548 = { 0, 0, 0x60040000 };
Battle D_800A5554 = { 0, 0, 0x60040000 };
Battle D_800A5560 = { 0, 0, 0x60040000 };
Battle D_800A556C = { 0, 0, 0x60040000 };
Battle D_800A5578 = { 0, 0, 0x60040000 };
Battle D_800A5584 = { 0, 0, 0x60040000 };
Battle D_800A5590 = { 0, 0, 0x60040000 };
BattleList D_800A559C = {
    0,
    { &D_800A553C, &D_800A5548, &D_800A5554, &D_800A5560,
      &D_800A556C, &D_800A5578, &D_800A5584, &D_800A5590 },
};
Battle D_800A55C0 = { 0, 0, 0x60040000 };
Battle D_800A55CC = { 0, 0, 0x60040000 };
Battle D_800A55D8 = { 0, 0, 0x60040000 };
Battle D_800A55E4 = { 331, 9, 0x60080000 };
Battle D_800A55F0 = { 332, 8, 0x60080000 };
Battle D_800A55FC = { 0, 0, 0x60040000 };
Battle D_800A5608 = { 177, 9, 0x60080000 };
Battle D_800A5614 = { 106, 8, 0x60080000 };
BattleList D_800A5620 = {
    0,
    { &D_800A55C0, &D_800A55CC, &D_800A55D8, &D_800A55E4,
      &D_800A55F0, &D_800A55FC, &D_800A5608, &D_800A5614 },
};
FieldBattles stageBattles[] = {
    { 74, 0, 0, { &D_800A5494, &D_800A5518, &D_800A559C, &D_800A5620 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
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
    { 1, 0, 0x80, 2, 0x1B, 0, 0, 0, 0, 0, 640, 640, 0, 0 },
    { 1, 0, 0x80, 2, 0x1C, 0, 0, 0, 0, 0, 1152, 640, 0, 0 },
    { 1, 0, 0x80, 2, 0x1D, 0, 0, 0, 0, 0, 1280, 640, 0, 0 },
    { 1, 0, 0x40, 2, 0, 0, 0, 0, 0, 0, 1125, 1033, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 200, 271, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 299, 546, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 379, 1321, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 388, 925, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 436, 759, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 565, 1172, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 653, 974, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 871, 170, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 883, 1267, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 885, 889, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 900, 760, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 1079, 128, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 1322, 546, 0, 0 },
    { 1, 0, 0x40, 6, 0x22, 1, 0x22, 0x31, 0xA, 0, 1341, 990, 0, 0 },
    { 1, 0, 0xFF, 6, 0x63, 0, 0, 0, 0, 0, 280, 280, 0, 0 },
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A8, 0x6C8, 0x1D4, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A2, 0x140, 0x350, 5, 0, 0, 0 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 3, 2 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x1A, 1 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x30, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFD8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x30, 0x28, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 6, 0, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 6, 1, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
