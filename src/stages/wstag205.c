#include "common.h"
#include "stage.h"
void func_800A4CA8();
extern u8 *D_800A551C[];
extern StageSpriteSpot D_800A5540[];

/* The sprites, which the versions number differently */
#if VERSION_US
#define SPRITES 0x18B
#elif VERSION_EU
#define SPRITES 0x199
#endif

/* Plays the nine animations and draws the sprites of the table that are on screen */
void func_800A4CA8(StageSpriteField *task) {
    SpriteDrawer drawer;
    RECT rect;
    Layer *layer;
    s32 i;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        break;
    case TASK_RUN:
        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x1002, 0xA);
        drawer.setTexture(0x140, 0x100);
        drawer.setAltClut(0, 0x1F0);
        for (i = 0; i < 9; i++) {
            task->anims[i].timer += GFX.funcs.getFrameTime();
            for (;;) {
                if (D_800A551C[i][task->anims[i].index * 2] == 0) {
                    task->anims[i].index = 0;
                }
                if (D_800A551C[i][task->anims[i].index * 2 + 1] >= task->anims[i].timer) {
                    break;
                }
                task->anims[i].timer -= D_800A551C[i][task->anims[i].index * 2 + 1];
                task->anims[i].index++;
            }
            task->anims[i].frame = D_800A551C[i][task->anims[i].index * 2];
        }
        layer = GFX.funcs.getLayer(0x1002);
        layer->getViewRect(layer, &rect);
        rect.w += rect.x;
        rect.h += rect.y;
        for (i = 0;; i++) {
            s32 x, y;

            if (D_800A5540[i].x == 0) {
                break;
            }
            x = D_800A5540[i].x;
            y = D_800A5540[i].y;
            if (x < rect.x - 0x40 || rect.w + 0x40 < x || y < rect.y - 0x40 || rect.h + 0x40 < y) {
                continue;
            }
            if (!D_800A5540[i].flip) {
                drawer.setScale(0x1000, 0x1000, 0x1000);
            } else {
                drawer.setPivot(x, y);
                drawer.setScale(-0x1000, 0x1000, 0x1000);
            }
            drawer.draw(FILE_CACHE.getEntry(SPRITES << 16), task->anims[D_800A5540[i].anim].frame, x, y);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A4F74(void) {
    return createTask(func_800A4CA8, 0xC8, 0);
}

/* Creates the event object of progress 6 when flag 0x4006 is set and 0x4016 is not */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 6 && FLAGS_00.checkCondition(0x4006, 1) && FLAGS_00.checkCondition(0x4016, 0)) {
            children[0] = FIELDSTG_startEvent(0x65);
        }
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

void func_800A50B4(void) {
    FLAGS_00.applyAction(0x4006, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

void func_800A5100(void) {
    FLAGS_00.applyAction(0x4016, 1);
}

const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x18B
#define STAGE_ARCHIVE 0x2B4
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x199
#define STAGE_ARCHIVE 0x2C3
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x2DC00, 0xF200};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 4;
    D_800990B4.music = 0x60100000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
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

extern u8 D_800A54C4[];
extern u8 D_800A54CC[];
extern u8 D_800A54D4[];
extern u8 D_800A54DC[];
extern u8 D_800A54E8[];
extern u8 D_800A54F0[];
extern u8 D_800A54FC[];
extern u8 D_800A5508[];
extern u8 D_800A5510[];
extern Battle D_800A5878;
extern Battle D_800A5884;
extern Battle D_800A5890;
extern Battle D_800A589C;
extern Battle D_800A58A8;
extern Battle D_800A58B4;
extern Battle D_800A58C0;
extern Battle D_800A58CC;
extern Battle D_800A58FC;
extern Battle D_800A5908;
extern Battle D_800A5914;
extern Battle D_800A5920;
extern Battle D_800A592C;
extern Battle D_800A5938;
extern Battle D_800A5944;
extern Battle D_800A5950;
extern Battle D_800A5980;
extern Battle D_800A598C;
extern Battle D_800A5998;
extern Battle D_800A59A4;
extern Battle D_800A59B0;
extern Battle D_800A59BC;
extern Battle D_800A59C8;
extern Battle D_800A59D4;
extern Battle D_800A5A04;
extern Battle D_800A5A10;
extern Battle D_800A5A1C;
extern Battle D_800A5A28;
extern Battle D_800A5A34;
extern Battle D_800A5A40;
extern Battle D_800A5A4C;
extern Battle D_800A5A58;
extern BattleList D_800A58D8;
extern BattleList D_800A595C;
extern BattleList D_800A59E0;
extern BattleList D_800A5A64;
extern u16 D_800A5B74[];
extern u16 D_800A5B84[];
extern u16 D_800A5D9C[];
extern FieldTalk D_800A5B8C[];
extern u16 D_800A5DA4[];
extern FieldTalk D_800A5BA4[];
extern u16 D_800A5DAC[];
extern FieldTalk D_800A5BBC[];
extern u16 D_800A5DB4[];
extern FieldTalk D_800A5BD4[];
extern u16 D_800A5DBC[];
extern FieldTalk D_800A5BEC[];
extern u16 D_800A5DC4[];
extern FieldTalk D_800A5C04[];
extern u16 D_800A5DCC[];
extern FieldTalk D_800A5C1C[];
extern u16 D_800A5DD4[];
extern FieldTalk D_800A5C34[];
extern u16 D_800A5DDC[];
extern FieldTalk D_800A5C4C[];
extern u16 D_800A5DE4[];
extern FieldTalk D_800A5C64[];
extern u16 D_800A5DEC[];
extern FieldTalk D_800A5C7C[];
extern u16 D_800A5DF4[];
extern FieldTalk D_800A5C94[];
extern u16 D_800A5DFC[];
extern FieldTalk D_800A5CAC[];
extern u16 D_800A5E04[];
extern FieldTalk D_800A5CC4[];
extern u16 D_800A5E0C[];
extern FieldTalk D_800A5CDC[];
extern u16 D_800A5E14[];
extern FieldTalk D_800A5CF4[];
extern u16 D_800A5E1C[];
extern FieldTalk D_800A5D0C[];
extern u16 D_800A5E24[];
extern FieldTalk D_800A5D24[];
extern u16 D_800A5E2C[];
extern FieldTalk D_800A5D3C[];
extern u16 D_800A5E34[];
extern u16 D_800A5E40[];
extern FieldTalk D_800A5D54[];
extern u16 D_800A5E50[];
extern FieldTalk D_800A5D6C[];
extern u16 D_800A5E58[];
extern FieldTalk D_800A5D84[];
extern FieldActorEntry D_800A5E60;
extern FieldActorEntry D_800A5E74;
extern FieldActorEntry D_800A5E88;
extern FieldActorEntry D_800A5E9C;
extern FieldActorEntry D_800A5EB0;
extern FieldActorEntry D_800A5EC4;
extern FieldActorEntry D_800A5ED8;
extern FieldActorEntry D_800A5EEC;
extern FieldActorEntry D_800A5F00;
extern FieldActorEntry D_800A5F14;
extern FieldActorEntry D_800A5F28;
extern FieldActorEntry D_800A5F3C;
extern FieldActorEntry D_800A5F50;
extern FieldActorEntry D_800A5F64;
extern FieldActorEntry D_800A5F78;
extern FieldActorEntry D_800A5F8C;
extern FieldActorEntry D_800A5FA0;
extern FieldActorEntry D_800A5FB4;
extern FieldActorEntry D_800A5FC8;
extern FieldActorEntry D_800A5FDC;
extern FieldActorEntry D_800A5FF0;
extern FieldActorEntry D_800A6004;
extern FieldActorEntry D_800A6018;
extern s16 D_800A528C[];
extern s16 D_800A53E4[];

s16 D_800A528C[] = {
    0x600, 1, 2,
    0x102, 2, 0x28F, 0x11F, 5,
    0x100, 0x66, 0x317, 0xDC,
    0x101, 0x66, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x102, 2, 0x2CF, 0x101, 5,
    0x302, 2,
    0x101, 0x323, 0x325, 0x66,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x66,
    0x300, 0x1E,
    0x600, 0, 0x66,
    0x200, 0, 1, 0x66, 2,
    0x101, 0x66, 1, 1,
    0x301,
    0x102, 0x66, 0x2EF, 0xF0, 1,
    0x302, 0x66,
    0x101, 0x66, 1, 1,
    0x300, 0x1E,
    0x600, 0, 2,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x66, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x66, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 7, 0x66, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 0x66, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A53E4[] = {
    0x100, 2, 0x2CF, 0x101,
    0x101, 2, 1, 5,
    0x100, 0x66, 0x2EF, 0xF0,
    0x101, 0x66, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 2, 0x66, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x66, 2,
    0x301,
    0x300, 0x1E,
    0x102, 0x66, 0x2CF, 0xF0, 2,
    0x302, 0x66,
    0x101, 2, 1, 3,
    0x102, 0x66, 0x2BF, 0xF8, 1,
    0x302, 0x66,
    0x101, 2, 1, 1,
    0x102, 0x66, 0x22E, 0x13F, 1,
    0x302, 0x66,
    0x200, 0, 5, 2, 1,
    0x100, 0x66, 0, 0,
    0x101, 0x66, 1, 0,
    0x301,
    0x300, 0x1E,
    0,
};
u8 D_800A54C4[] = {
    0x32, 0x0A, 0x33, 0x0A, 0x34, 0x0A, 0x00, 0x00,
};
u8 D_800A54CC[] = {
    0x35, 0x0A, 0x36, 0x0A, 0x37, 0x0A, 0x00, 0x00,
};
u8 D_800A54D4[] = {
    0x38, 0x0A, 0x39, 0x0A, 0x3A, 0x0A, 0x00, 0x00,
};
u8 D_800A54DC[] = {
    72, 6, 73, 6, 74, 6, 75, 6,
    0, 0, 0, 0,
};
u8 D_800A54E8[] = {
    62, 6, 63, 6, 64, 6, 0, 0,
};
u8 D_800A54F0[] = {
    80, 4, 81, 4, 82, 4, 83, 4,
    0, 0, 0, 0,
};
u8 D_800A54FC[] = {
    76, 6, 77, 6, 78, 6, 79, 6,
    0, 0, 0, 0,
};
u8 D_800A5508[] = {
    65, 6, 66, 6, 67, 6, 0, 0,
};
u8 D_800A5510[] = {
    84, 4, 85, 4, 86, 4, 87, 4,
    0, 0, 0, 0,
};
u8 *D_800A551C[] = {
    D_800A54C4,
    D_800A54CC,
    D_800A54D4,
    D_800A54DC,
    D_800A54E8,
    D_800A54F0,
    D_800A54FC,
    D_800A5508,
    D_800A5510,
};
StageSpriteSpot D_800A5540[] = {
    { 40, 0x1A5, 0, 0 },
    { 56, 0x173, 0, 0 },
    { 143, 0x106, 0, 0 },
    { 0x126, 0x157, 0, 0 },
    { 0x17D, 98, 0, 0 },
    { 0x27C, 0x1AA, 0, 0 },
    { 0x29F, 0x19B, 0, 0 },
    { 0x2E7, 0x18A, 0, 0 },
    { 0x36E, 0x1A8, 0, 0 },
    { 0x4C2, 0x123, 0, 0 },
    { 0x50D, 0x110, 0, 0 },
    { 0x4AA, 0x12F, 0, 0 },
    { 0x4C0, 0x166, 0, 0 },
    { 0x46C, 0x177, 0, 0 },
    { 0x4FE, 0x15E, 0, 0 },
    { 0x50C, 0x163, 0, 0 },
    { 0x4B3, 0x1E9, 0, 0 },
    { 0x455, 0x1F5, 0, 0 },
    { 0x462, 0x1CA, 0, 0 },
    { 0x3D1, 0x1C7, 0, 0 },
    { 0x347, 0x18F, 0, 0 },
    { 0x31F, 0x191, 0, 0 },
    { 0x22B, 229, 0, 0 },
    { 0x1E8, 0x105, 0, 0 },
    { 0x255, 0x1AB, 0, 0 },
    { 0x20F, 0x1CF, 0, 0 },
    { 0x1AE, 0x12A, 0, 0 },
    { 0x177, 0x145, 0, 0 },
    { 0x533, 0x18E, 0, 0 },
    { 0x4E5, 0x1A5, 0, 0 },
    { 8, 0x17D, 1, 0 },
    { 31, 0x17B, 1, 0 },
    { 64, 0x19E, 1, 0 },
    { 87, 0x19C, 1, 0 },
    { 125, 0x107, 1, 0 },
    { 0x114, 0x158, 1, 0 },
    { 0x120, 0x161, 1, 0 },
    { 0x1A9, 62, 1, 0 },
    { 0x1C9, 0x124, 1, 0 },
    { 0x269, 0x1A9, 1, 0 },
    { 0x277, 141, 1, 0 },
    { 0x2B7, 0x194, 1, 0 },
    { 0x2CE, 0x192, 1, 0 },
    { 0x35C, 0x1A9, 1, 0 },
    { 0x364, 0x1D2, 1, 0 },
    { 0x3E3, 192, 1, 0 },
    { 0x4D7, 0x11A, 1, 0 },
    { 0x48E, 0x13D, 1, 0 },
    { 0x4F0, 0x116, 1, 0 },
    { 0x475, 0x14B, 1, 0 },
    { 0x4A5, 0x171, 1, 0 },
    { 0x48E, 0x170, 1, 0 },
    { 0x52F, 0x156, 1, 0 },
    { 0x516, 0x155, 1, 0 },
    { 0x47F, 0x1E7, 1, 0 },
    { 0x470, 0x1E4, 1, 0 },
    { 0x3EB, 0x1BC, 1, 0 },
    { 0x3CC, 0x1D5, 1, 0 },
    { 0x315, 0x186, 1, 0 },
    { 0x32F, 0x192, 1, 0 },
    { 0x20A, 252, 1, 0 },
    { 0x1F9, 0x105, 1, 0 },
    { 0x222, 0x1D0, 1, 0 },
    { 0x227, 0x1C5, 1, 0 },
    { 0x196, 0x12F, 1, 0 },
    { 0x180, 0x13E, 1, 0 },
    { 0x51A, 0x19E, 1, 0 },
    { 0x503, 0x198, 1, 0 },
    { 34, 0x16F, 2, 0 },
    { 50, 0x19D, 2, 0 },
    { 90, 0x190, 2, 0 },
    { 137, 0x110, 2, 0 },
    { 0x179, 107, 2, 0 },
    { 0x19A, 59, 2, 0 },
    { 0x1BC, 0x122, 2, 0 },
    { 0x230, 0x1C4, 2, 0 },
    { 0x26A, 139, 2, 0 },
    { 0x2A9, 0x193, 2, 0 },
    { 0x2D1, 0x186, 2, 0 },
    { 0x357, 0x1D0, 2, 0 },
    { 0x368, 0x1B2, 2, 0 },
    { 0x3D6, 190, 2, 0 },
    { 0x4F7, 0x11D, 2, 0 },
    { 0x45B, 0x151, 2, 0 },
    { 0x4AF, 0x162, 2, 0 },
    { 0x478, 0x169, 2, 0 },
    { 0x528, 0x145, 2, 0 },
    { 0x521, 0x164, 2, 0 },
    { 0x494, 0x1E7, 2, 0 },
    { 0x466, 0x1F5, 2, 0 },
    { 0x3F3, 0x1C3, 2, 0 },
    { 0x3E1, 0x1D0, 2, 0 },
    { 0x330, 0x186, 2, 0 },
    { 0x304, 0x191, 2, 0 },
    { 0x21A, 252, 2, 0 },
    { 0x21F, 243, 2, 0 },
    { 0x246, 0x1B5, 2, 0 },
    { 0x240, 0x1C4, 2, 0 },
    { 0x182, 0x135, 2, 0 },
    { 0x17A, 0x14C, 2, 0 },
    { 0x517, 0x194, 2, 0 },
    { 0x4F5, 0x195, 2, 0 },
    { 37, 0x109, 3, 0 },
    { 77, 0x11D, 3, 0 },
    { 117, 0x132, 3, 0 },
    { 157, 0x146, 3, 0 },
    { 197, 0x159, 3, 0 },
    { 237, 0x16C, 3, 0 },
    { 0x115, 0x181, 3, 0 },
    { 0x1DF, 0x1E6, 3, 0 },
    { 0x206, 0x1F9, 3, 0 },
    { 36, 0x124, 4, 0 },
    { 76, 0x138, 4, 0 },
    { 116, 0x14D, 4, 0 },
    { 156, 0x161, 4, 0 },
    { 196, 0x174, 4, 0 },
    { 236, 0x187, 4, 0 },
    { 0x1DE, 0x203, 4, 0 },
    { 0x205, 0x214, 4, 0 },
    { 0x266, 92, 4, 1 },
    { 28, 0x153, 5, 0 },
    { 68, 0x167, 5, 0 },
    { 108, 0x17C, 5, 0 },
    { 148, 0x190, 5, 0 },
    { 188, 0x1A3, 5, 0 },
    { 228, 0x1B6, 5, 0 },
    { 0x1D5, 0x232, 5, 0 },
    { 0x1FD, 0x244, 5, 0 },
    { 0x26D, 124, 5, 1 },
    { 0x3AE, 206, 6, 0 },
    { 0x1D5, 110, 6, 1 },
    { 0x3AF, 255, 7, 0 },
    { 0x1D5, 137, 7, 1 },
    { 0x3EC, 164, 8, 0 },
    { 0x196, 48, 8, 1 },
    { 0x1DC, 160, 8, 1 },
    { 0, 0, 0, 0 },
};
Battle D_800A5878 = { 0, 0, 0x60040000 };
Battle D_800A5884 = { 0, 0, 0x60040000 };
Battle D_800A5890 = { 0, 0, 0x60040000 };
Battle D_800A589C = { 0, 0, 0x60040000 };
Battle D_800A58A8 = { 0, 0, 0x60040000 };
Battle D_800A58B4 = { 0, 0, 0x60040000 };
Battle D_800A58C0 = { 0, 0, 0x60040000 };
Battle D_800A58CC = { 0, 0, 0x60040000 };
BattleList D_800A58D8 = {
    3,
    { &D_800A5878, &D_800A5884, &D_800A5890, &D_800A589C,
      &D_800A58A8, &D_800A58B4, &D_800A58C0, &D_800A58CC },
};
Battle D_800A58FC = { 0, 0, 0x60040000 };
Battle D_800A5908 = { 0, 0, 0x60040000 };
Battle D_800A5914 = { 0, 0, 0x60040000 };
Battle D_800A5920 = { 0, 0, 0x60040000 };
Battle D_800A592C = { 0, 0, 0x60040000 };
Battle D_800A5938 = { 0, 0, 0x60040000 };
Battle D_800A5944 = { 0, 0, 0x60040000 };
Battle D_800A5950 = { 0, 0, 0x60040000 };
BattleList D_800A595C = {
    0,
    { &D_800A58FC, &D_800A5908, &D_800A5914, &D_800A5920,
      &D_800A592C, &D_800A5938, &D_800A5944, &D_800A5950 },
};
Battle D_800A5980 = { 0, 0, 0x60040000 };
Battle D_800A598C = { 0, 0, 0x60040000 };
Battle D_800A5998 = { 0, 0, 0x60040000 };
Battle D_800A59A4 = { 0, 0, 0x60040000 };
Battle D_800A59B0 = { 0, 0, 0x60040000 };
Battle D_800A59BC = { 0, 0, 0x60040000 };
Battle D_800A59C8 = { 0, 0, 0x60040000 };
Battle D_800A59D4 = { 0, 0, 0x60040000 };
BattleList D_800A59E0 = {
    0,
    { &D_800A5980, &D_800A598C, &D_800A5998, &D_800A59A4,
      &D_800A59B0, &D_800A59BC, &D_800A59C8, &D_800A59D4 },
};
Battle D_800A5A04 = { 263, 18, 0x608C0000 };
Battle D_800A5A10 = { 0, 0, 0x60040000 };
Battle D_800A5A1C = { 0, 0, 0x60040000 };
Battle D_800A5A28 = { 0, 0, 0x60040000 };
Battle D_800A5A34 = { 0, 0, 0x60040000 };
Battle D_800A5A40 = { 0, 0, 0x60040000 };
Battle D_800A5A4C = { 0, 0, 0x60040000 };
Battle D_800A5A58 = { 0, 0, 0x60040000 };
BattleList D_800A5A64 = {
    0,
    { &D_800A5A04, &D_800A5A10, &D_800A5A1C, &D_800A5A28,
      &D_800A5A34, &D_800A5A40, &D_800A5A4C, &D_800A5A58 },
};
FieldBattles stageBattles[] = {
    { 168, 0, 0, { &D_800A58D8, &D_800A595C, &D_800A59E0, &D_800A5A64 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x168, 0x184, 0xA0, 0x84, 0x150, 0x1FF },
    { 0x180, 0x100, 0x180, 0x144, 0x100, 0x44, 0x160, 0x1FF },
    { 0x180, 0x100, 0x188, 0x144, 0x120, 0x44, 0x170, 0x1FF },
    { 0x180, 0x100, 0x1B2, 0x1CA, 0x1C8, 0xCA, 0x140, 0x1FE },
    { 0x180, 0x100, 0x190, 0x148, 0x140, 0x48, 0x150, 0x1FE },
    { 0x1C0, 0x100, 0x1EA, 0x118, 0x2A8, 0x18, 0x160, 0x1FE },
    { 0x1C0, 0x100, 0x1F2, 0x118, 0x2C8, 0x18, 0x170, 0x1FE },
};
u16 D_800A5B74[] = { 0x206, 1, 0x846C, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5B84[] = { 0x1A19, 1, 0xFFFF };
FieldTalk D_800A5B8C[] = {
    { NULL, D_800A5B74, 0x44C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BA4[] = {
    { NULL, NULL, 0x2DB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BBC[] = {
    { NULL, NULL, 0x2DC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BD4[] = {
    { NULL, NULL, 0x2DD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BEC[] = {
    { NULL, NULL, 0x2DE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C04[] = {
    { NULL, NULL, 0x2E4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C1C[] = {
    { NULL, NULL, 0x2E0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C34[] = {
    { NULL, NULL, 0x2E1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C4C[] = {
    { NULL, NULL, 0x2E2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C64[] = {
    { NULL, NULL, 0x1A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C7C[] = {
    { NULL, NULL, 0x1B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C94[] = {
    { NULL, NULL, 0x2E5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CAC[] = {
    { NULL, NULL, 0x2E7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CC4[] = {
    { NULL, NULL, 0x2E6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CDC[] = {
    { NULL, NULL, 0x2E8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CF4[] = {
    { NULL, NULL, 0x2EE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D0C[] = {
    { NULL, NULL, 0x2EA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D24[] = {
    { NULL, NULL, 0x2EB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D3C[] = {
    { NULL, NULL, 0x2EC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D54[] = {
    { NULL, D_800A5B84, 0x50 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D6C[] = {
    { NULL, NULL, 0x2E3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D84[] = {
    { NULL, NULL, 0x2ED },
    { NULL, NULL, 0 },
};
u16 D_800A5D9C[] = { 0x206, 0, 0xFFFF };
u16 D_800A5DA4[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5DAC[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5DB4[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5DBC[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5DC4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5DCC[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5DD4[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5DDC[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5DE4[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5DEC[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5DF4[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5DFC[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5E04[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5E0C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5E14[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5E1C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5E24[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5E2C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5E34[] = { 0x6006, 1, 0x4016, 0, 0xFFFF };
u16 D_800A5E40[] = { 0x6008, 1, 0x1A18, 1, 0x1A19, 0, 0xFFFF };
u16 D_800A5E50[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E58[] = { 0x7005, 1, 0xFFFF };
FieldActorEntry D_800A5E60 = { D_800A5D9C, D_800A5B8C, 0x21, 4, 304, 160, 1 };
FieldActorEntry D_800A5E74 = { D_800A5DA4, D_800A5BA4, 0x25, 5, 736, 184, 1 };
FieldActorEntry D_800A5E88 = { D_800A5DAC, D_800A5BBC, 0x25, 5, 736, 184, 1 };
FieldActorEntry D_800A5E9C = { D_800A5DB4, D_800A5BD4, 0x25, 5, 736, 184, 1 };
FieldActorEntry D_800A5EB0 = { D_800A5DBC, D_800A5BEC, 0x25, 5, 736, 184, 1 };
FieldActorEntry D_800A5EC4 = { D_800A5DC4, D_800A5C04, 0x25, 5, 736, 184, 1 };
FieldActorEntry D_800A5ED8 = { D_800A5DCC, D_800A5C1C, 0x25, 5, 736, 184, 1 };
FieldActorEntry D_800A5EEC = { D_800A5DD4, D_800A5C34, 0x25, 5, 736, 184, 1 };
FieldActorEntry D_800A5F00 = { D_800A5DDC, D_800A5C4C, 0x25, 5, 736, 184, 1 };
FieldActorEntry D_800A5F14 = { D_800A5DE4, D_800A5C64, 0x25, 5, 736, 184, 1 };
FieldActorEntry D_800A5F28 = { D_800A5DEC, D_800A5C7C, 0x26, 6, 848, 240, 1 };
FieldActorEntry D_800A5F3C = { D_800A5DF4, D_800A5C94, 0x26, 6, 848, 240, 1 };
FieldActorEntry D_800A5F50 = { D_800A5DFC, D_800A5CAC, 0x26, 6, 848, 240, 1 };
FieldActorEntry D_800A5F64 = { D_800A5E04, D_800A5CC4, 0x26, 6, 848, 240, 1 };
FieldActorEntry D_800A5F78 = { D_800A5E0C, D_800A5CDC, 0x26, 6, 848, 240, 1 };
FieldActorEntry D_800A5F8C = { D_800A5E14, D_800A5CF4, 0x26, 6, 848, 240, 1 };
FieldActorEntry D_800A5FA0 = { D_800A5E1C, D_800A5D0C, 0x26, 6, 848, 240, 1 };
FieldActorEntry D_800A5FB4 = { D_800A5E24, D_800A5D24, 0x26, 6, 848, 240, 1 };
FieldActorEntry D_800A5FC8 = { D_800A5E2C, D_800A5D3C, 0x26, 6, 848, 240, 1 };
FieldActorEntry D_800A5FDC = { D_800A5E34, NULL, 0x66, 7, 792, 221, 1 };
FieldActorEntry D_800A5FF0 = { D_800A5E40, D_800A5D54, 0x72, 8, 1144, 405, 1 };
FieldActorEntry D_800A6004 = { D_800A5E50, D_800A5D6C, 0x9D, 9, 736, 184, 1 };
FieldActorEntry D_800A6018 = { D_800A5E58, D_800A5D84, 0x9E, 0xA, 848, 240, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5E60,
    &D_800A5E74,
    &D_800A5E88,
    &D_800A5E9C,
    &D_800A5EB0,
    &D_800A5EC4,
    &D_800A5ED8,
    &D_800A5EEC,
    &D_800A5F00,
    &D_800A5F14,
    &D_800A5F28,
    &D_800A5F3C,
    &D_800A5F50,
    &D_800A5F64,
    &D_800A5F78,
    &D_800A5F8C,
    &D_800A5FA0,
    &D_800A5FB4,
    &D_800A5FC8,
    &D_800A5FDC,
    &D_800A5FF0,
    &D_800A6004,
    &D_800A6018,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x80, 2, 0, 0, 0, 0, 0, 0, 384, 384, 0, 0 },
    { 1, 0, 0x40, 2, 1, 0, 0, 0, 0, 0, 128, 475, 0, 0 },
    { 1, 0, 0x40, 2, 2, 0, 0, 0, 0, 0, 240, 499, 0, 0 },
    { 1, 0, 0x40, 2, 3, 0, 0, 0, 0, 0, 252, 384, 0, 0 },
    { 1, 0, 0x80, 2, 4, 0, 0, 0, 0, 0, 512, 307, 0, 0 },
    { 1, 0, 0x40, 2, 5, 0, 0, 0, 0, 0, 496, 371, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 248, 352, 0, 0 },
    { 1, 0, 0x40, 2, 0x10, 0, 0, 0, 0, 0, 104, 512, 0, 0 },
    { 1, 0, 0x80, 2, 7, 0, 0, 0, 0, 0, 896, 128, 0, 0 },
    { 1, 0, 0x80, 2, 8, 0, 0, 0, 0, 0, 256, 384, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 8, 460, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 11, 459, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 22, 447, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 142, 254, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 344, 345, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 410, 192, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 417, 596, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 507, 261, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 606, 427, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 680, 401, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 712, 393, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x34, 0xA, 0, 985, 188, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 37, 451, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 357, 335, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 444, 299, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 457, 287, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 540, 244, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 554, 453, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 782, 396, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 817, 391, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 942, 475, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 990, 449, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1109, 334, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1122, 488, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 1, 0x35, 0x37, 0xA, 0, 1250, 276, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 102, 206, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 113, 248, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 416, 303, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 422, 57, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 574, 418, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 633, 141, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 654, 397, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 887, 427, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 928, 444, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1034, 516, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 1, 0x38, 0x3A, 0xA, 0, 1181, 488, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 168, 451, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 392, 601, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 440, 70, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 440, 555, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 510, 455, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 1085, 507, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 44, 434, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 381, 116, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 397, 206, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 415, 603, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 479, 284, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 541, 258, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 545, 250, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 555, 460, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 711, 403, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 781, 404, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 843, 392, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 977, 194, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 985, 457, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1114, 365, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1144, 486, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 1218, 456, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 30, 340, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 70, 360, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 110, 380, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 150, 400, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 190, 420, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 470, 560, 0, 0 },
    { 1, 0, 0x40, 6, 0x50, 1, 0x50, 0x53, 4, 0, 510, 580, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 1, 0x58, 0x5B, 4, 0, 585, 125, 0, 0 },
    { 1, 0, 0x40, 6, 0x5C, 1, 0x5C, 0x5F, 4, 0, 363, 49, 0, 0 },
    { 1, 0, 0x40, 6, 0x5C, 1, 0x5C, 0x5F, 4, 0, 435, 161, 0, 0 },
    { 1, 0, 0x40, 6, 0x54, 1, 0x54, 0x57, 4, 0, 1009, 162, 0, 0 },
    { 1, 0x64, 0x80, 6, 9, 0, 0, 0, 0, 0, 758, 96, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2F, 1, 0x2F, 0x31, 6, 0, 943, 296, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x2F, 1, 0x2F, 0x31, 6, 0, 1019, 140, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x42, 1, 0x42, 0x44, 6, 0, 582, 78, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x45, 1, 0x45, 0x47, 6, 0, 358, 18, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 37, 267, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 77, 287, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 117, 307, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 157, 327, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 196, 347, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 236, 367, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 276, 387, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 477, 487, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x48, 1, 0x48, 0x4B, 6, 0, 517, 507, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x50, 1, 0x50, 0x53, 4, 0, 230, 440, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x60, 1, 0x60, 0x63, 6, 0, 422, 110, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4C, 1, 0x4C, 0x4F, 6, 0, 942, 205, 0, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 224, 177, 200, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 600, 214, 273, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 1046, 371, 407, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 1062, 315, 337, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 902, 275, 295, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 846, 177, 226, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0x7007, 0 }, { 0xFFFF, 0 } }, 1, 0x200, 0x60, 0x31C, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x21D, 0x5E2, 0xE0, 1, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E1, 0x1D0, 0x154, 7, 0, 2, 1 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E1, 0xE0, 0x110, 7, 0, 2, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x110, 0x100, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0x120, 0xC8, 0, 0, 0, 0 },
    { { { 0x6006, 1 }, { 0x4006, 0 } }, 8, 0x64, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 100, D_800A528C, EVENT_TEXT(0x15), NULL, func_800A50B4 },
    { 101, D_800A53E4, EVENT_TEXT(0x16), NULL, func_800A5100 },
    { -1, NULL, 0, NULL, NULL },
};
