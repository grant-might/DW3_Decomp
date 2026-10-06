#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

extern StageSlot D_800A544C[];
extern StageSlot D_800A54C4[];
#if VERSION_US
#define STAGE_TEXT 0xF7
#define STAGE_FILE 0x26A
#define STAGE_ARCHIVE 0x3CD
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define STAGE_FILE 0x279
#define STAGE_ARCHIVE 0x3DD
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x10800, 0xED00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x11;
    D_800990B4.music = 0x60440000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress < 0x1A) {
        D_800990B4.slots = D_800A544C;
    } else {
        D_800990B4.slots = D_800A54C4;
    }
}

extern Battle D_800A4E80;
extern Battle D_800A4E8C;
extern Battle D_800A4E98;
extern Battle D_800A4EA4;
extern Battle D_800A4EB0;
extern Battle D_800A4EBC;
extern Battle D_800A4EC8;
extern Battle D_800A4ED4;
extern Battle D_800A4F04;
extern Battle D_800A4F10;
extern Battle D_800A4F1C;
extern Battle D_800A4F28;
extern Battle D_800A4F34;
extern Battle D_800A4F40;
extern Battle D_800A4F4C;
extern Battle D_800A4F58;
extern Battle D_800A4F88;
extern Battle D_800A4F94;
extern Battle D_800A4FA0;
extern Battle D_800A4FAC;
extern Battle D_800A4FB8;
extern Battle D_800A4FC4;
extern Battle D_800A4FD0;
extern Battle D_800A4FDC;
extern Battle D_800A500C;
extern Battle D_800A5018;
extern Battle D_800A5024;
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern BattleList D_800A4EE0;
extern BattleList D_800A4F64;
extern BattleList D_800A4FE8;
extern BattleList D_800A506C;
extern u16 D_800A511C[];
extern u16 D_800A5144[];
extern FieldTalk D_800A512C[];
extern FieldActorEntry D_800A514C;

Battle D_800A4E80 = { 165, 6, 0x60080000 };
Battle D_800A4E8C = { 165, 6, 0x60080000 };
Battle D_800A4E98 = { 165, 6, 0x60080000 };
Battle D_800A4EA4 = { 165, 6, 0x60080000 };
Battle D_800A4EB0 = { 165, 6, 0x60080000 };
Battle D_800A4EBC = { 165, 6, 0x60080000 };
Battle D_800A4EC8 = { 165, 6, 0x60080000 };
Battle D_800A4ED4 = { 165, 6, 0x60080000 };
BattleList D_800A4EE0 = {
    5,
    { &D_800A4E80, &D_800A4E8C, &D_800A4E98, &D_800A4EA4,
      &D_800A4EB0, &D_800A4EBC, &D_800A4EC8, &D_800A4ED4 },
};
Battle D_800A4F04 = { 0, 6, 0x60080000 };
Battle D_800A4F10 = { 0, 6, 0x60080000 };
Battle D_800A4F1C = { 0, 6, 0x60080000 };
Battle D_800A4F28 = { 0, 6, 0x60080000 };
Battle D_800A4F34 = { 0, 6, 0x60080000 };
Battle D_800A4F40 = { 0, 6, 0x60080000 };
Battle D_800A4F4C = { 0, 6, 0x60080000 };
Battle D_800A4F58 = { 0, 6, 0x60080000 };
BattleList D_800A4F64 = {
    0,
    { &D_800A4F04, &D_800A4F10, &D_800A4F1C, &D_800A4F28,
      &D_800A4F34, &D_800A4F40, &D_800A4F4C, &D_800A4F58 },
};
Battle D_800A4F88 = { 0, 0, 0x60040000 };
Battle D_800A4F94 = { 0, 0, 0x60040000 };
Battle D_800A4FA0 = { 0, 0, 0x60040000 };
Battle D_800A4FAC = { 0, 0, 0x60040000 };
Battle D_800A4FB8 = { 0, 0, 0x60040000 };
Battle D_800A4FC4 = { 0, 0, 0x60040000 };
Battle D_800A4FD0 = { 0, 0, 0x60040000 };
Battle D_800A4FDC = { 0, 0, 0x60040000 };
BattleList D_800A4FE8 = {
    0,
    { &D_800A4F88, &D_800A4F94, &D_800A4FA0, &D_800A4FAC,
      &D_800A4FB8, &D_800A4FC4, &D_800A4FD0, &D_800A4FDC },
};
Battle D_800A500C = { 0, 0, 0x60040000 };
Battle D_800A5018 = { 0, 0, 0x60040000 };
Battle D_800A5024 = { 0, 0, 0x60040000 };
Battle D_800A5030 = { 0, 0, 0x60040000 };
Battle D_800A503C = { 0, 0, 0x60040000 };
Battle D_800A5048 = { 165, 6, 0x60080000 };
Battle D_800A5054 = { 0, 0, 0x60040000 };
Battle D_800A5060 = { 0, 0, 0x60040000 };
BattleList D_800A506C = {
    0,
    { &D_800A500C, &D_800A5018, &D_800A5024, &D_800A5030,
      &D_800A503C, &D_800A5048, &D_800A5054, &D_800A5060 },
};
FieldBattles stageBattles[] = {
    { 58, 0, 0, { &D_800A4EE0, &D_800A4F64, &D_800A4FE8, &D_800A506C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x150, 0x1FA },
};
u16 D_800A511C[] = { 0x205, 1, 0x822B, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A512C[] = {
    { NULL, D_800A511C, 0x16D },
    { NULL, NULL, 0 },
};
u16 D_800A5144[] = { 0x205, 0, 0xFFFF };
FieldActorEntry D_800A514C = { D_800A5144, D_800A512C, 0x21, 4, 671, 176, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A514C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x39, 2, 0, 3, 4, 0, 477, 371, 0, 0 },
    { 1, 0, 0x40, 2, 0x39, 2, 0, 3, 4, 0, 508, 386, 0, 0 },
    { 1, 0, 0x40, 2, 0x39, 2, 0, 3, 4, 0, 512, 353, 0, 0 },
    { 1, 0, 0x40, 2, 0x39, 2, 0, 3, 4, 0, 543, 368, 0, 0 },
    { 1, 0, 0x40, 2, 0x39, 2, 0, 3, 4, 0, 574, 419, 0, 0 },
    { 1, 0, 0x40, 2, 0x39, 2, 0, 3, 4, 0, 604, 434, 0, 0 },
    { 1, 0, 0x40, 2, 0x39, 2, 0, 3, 4, 0, 608, 401, 0, 0 },
    { 1, 0, 0x40, 2, 0x39, 2, 0, 3, 4, 0, 639, 416, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 438, 68, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 469, 367, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 500, 383, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 502, 120, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 504, 349, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 522, 110, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 535, 364, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 566, 415, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 596, 431, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 600, 397, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 631, 412, 0, 0 },
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 3, 4, 0, 822, 389, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x37, 6, 0, 788, 446, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 5, 6, 0, 768, 423, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 426, 82, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 446, 72, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 510, 124, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 530, 114, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 747, 433, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 830, 392, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 830, 475, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 3, 4, 0, 913, 433, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 418, 79, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 739, 430, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 822, 472, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 4, 0, 905, 430, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 2, 0, 3, 4, 0, 514, 60, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 3, 4, 0, 510, 56, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 3, 4, 0, 429, 28, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 3, 4, 0, 423, 20, 0, 0 },
    { 1, 0, 0x50, 4, 0, 0, 0, 0, 0, 0, 474, 362, 406, 0 },
    { 1, 0, 0x50, 4, 1, 0, 0, 0, 0, 0, 571, 410, 456, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot D_800A544C[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23C, 0x3C8, 0xC4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x243, 0x98, 0x8C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x221, 0xF0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x211, 0x158, 0, 0, 0, 0 },
    { { { 0xF, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
};
StageSlot D_800A54C4[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x23C, 0x3C8, 0xC4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x244, 0x98, 0x8C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x221, 0xF0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x211, 0x158, 0, 0, 0, 0 },
    { { { 0xF, 0 }, { 0xFFFF, 0 } }, 8, 0x2328, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 9000, NULL, 0, func_8008B258, NULL },
    { -1, NULL, 0, NULL, NULL },
};
