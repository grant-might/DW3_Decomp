#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xFE
#define STAGE_FILE 0x73E
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xF6)
#define STAGE_FILE 0x74E
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xFB00, 0xED00};
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
}

extern Battle D_800A4E54;
extern Battle D_800A4E60;
extern Battle D_800A4E6C;
extern Battle D_800A4E78;
extern Battle D_800A4E84;
extern Battle D_800A4E90;
extern Battle D_800A4E9C;
extern Battle D_800A4EA8;
extern Battle D_800A4ED8;
extern Battle D_800A4EE4;
extern Battle D_800A4EF0;
extern Battle D_800A4EFC;
extern Battle D_800A4F08;
extern Battle D_800A4F14;
extern Battle D_800A4F20;
extern Battle D_800A4F2C;
extern Battle D_800A4F5C;
extern Battle D_800A4F68;
extern Battle D_800A4F74;
extern Battle D_800A4F80;
extern Battle D_800A4F8C;
extern Battle D_800A4F98;
extern Battle D_800A4FA4;
extern Battle D_800A4FB0;
extern Battle D_800A4FE0;
extern Battle D_800A4FEC;
extern Battle D_800A4FF8;
extern Battle D_800A5004;
extern Battle D_800A5010;
extern Battle D_800A501C;
extern Battle D_800A5028;
extern Battle D_800A5034;
extern BattleList D_800A4EB4;
extern BattleList D_800A4F38;
extern BattleList D_800A4FBC;
extern BattleList D_800A5040;
extern u16 D_800A5110[];
extern u16 D_800A5198[];
extern FieldTalk D_800A5120[];
extern u16 D_800A51A0[];
extern FieldTalk D_800A5138[];
extern u16 D_800A51A8[];
extern FieldTalk D_800A5150[];
extern u16 D_800A51B0[];
extern FieldTalk D_800A5168[];
extern u16 D_800A51B8[];
extern FieldTalk D_800A5180[];
extern FieldActorEntry D_800A51C0;
extern FieldActorEntry D_800A51D4;
extern FieldActorEntry D_800A51E8;
extern FieldActorEntry D_800A51FC;
extern FieldActorEntry D_800A5210;

Battle D_800A4E54 = { 166, 6, 0x60080000 };
Battle D_800A4E60 = { 166, 6, 0x60080000 };
Battle D_800A4E6C = { 166, 6, 0x60080000 };
Battle D_800A4E78 = { 166, 6, 0x60080000 };
Battle D_800A4E84 = { 166, 6, 0x60080000 };
Battle D_800A4E90 = { 166, 6, 0x60080000 };
Battle D_800A4E9C = { 166, 6, 0x60080000 };
Battle D_800A4EA8 = { 166, 6, 0x60080000 };
BattleList D_800A4EB4 = {
    5,
    { &D_800A4E54, &D_800A4E60, &D_800A4E6C, &D_800A4E78,
      &D_800A4E84, &D_800A4E90, &D_800A4E9C, &D_800A4EA8 },
};
Battle D_800A4ED8 = { 0, 6, 0x60080000 };
Battle D_800A4EE4 = { 0, 6, 0x60080000 };
Battle D_800A4EF0 = { 0, 6, 0x60080000 };
Battle D_800A4EFC = { 0, 6, 0x60080000 };
Battle D_800A4F08 = { 0, 6, 0x60080000 };
Battle D_800A4F14 = { 0, 6, 0x60080000 };
Battle D_800A4F20 = { 0, 6, 0x60080000 };
Battle D_800A4F2C = { 0, 6, 0x60080000 };
BattleList D_800A4F38 = {
    0,
    { &D_800A4ED8, &D_800A4EE4, &D_800A4EF0, &D_800A4EFC,
      &D_800A4F08, &D_800A4F14, &D_800A4F20, &D_800A4F2C },
};
Battle D_800A4F5C = { 0, 0, 0x60040000 };
Battle D_800A4F68 = { 0, 0, 0x60040000 };
Battle D_800A4F74 = { 0, 0, 0x60040000 };
Battle D_800A4F80 = { 0, 0, 0x60040000 };
Battle D_800A4F8C = { 0, 0, 0x60040000 };
Battle D_800A4F98 = { 0, 0, 0x60040000 };
Battle D_800A4FA4 = { 0, 0, 0x60040000 };
Battle D_800A4FB0 = { 0, 0, 0x60040000 };
BattleList D_800A4FBC = {
    0,
    { &D_800A4F5C, &D_800A4F68, &D_800A4F74, &D_800A4F80,
      &D_800A4F8C, &D_800A4F98, &D_800A4FA4, &D_800A4FB0 },
};
Battle D_800A4FE0 = { 0, 0, 0x60040000 };
Battle D_800A4FEC = { 0, 0, 0x60040000 };
Battle D_800A4FF8 = { 0, 0, 0x60040000 };
Battle D_800A5004 = { 0, 0, 0x60040000 };
Battle D_800A5010 = { 0, 0, 0x60040000 };
Battle D_800A501C = { 166, 6, 0x60080000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
BattleList D_800A5040 = {
    0,
    { &D_800A4FE0, &D_800A4FEC, &D_800A4FF8, &D_800A5004,
      &D_800A5010, &D_800A501C, &D_800A5028, &D_800A5034 },
};
FieldBattles stageBattles[] = {
    { 79, 0, 0, { &D_800A4EB4, &D_800A4F38, &D_800A4FBC, &D_800A5040 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x150, 0x1FA },
    { 0x140, 0x100, 0x168, 0x140, 0xA0, 0x40, 0x160, 0x1FA },
    { 0x140, 0x100, 0x140, 0x15D, 0, 0x5D, 0x170, 0x1FA },
};
u16 D_800A5110[] = { 0x21E, 1, 0x822B, 1, 0x7013, 1, 0xFFFF };
FieldTalk D_800A5120[] = {
    { NULL, D_800A5110, 0x17E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5138[] = {
    { NULL, NULL, 0xB1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5150[] = {
    { NULL, NULL, 0xB3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5168[] = {
    { NULL, NULL, 0xB4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5180[] = {
    { NULL, NULL, 0xB2 },
    { NULL, NULL, 0 },
};
u16 D_800A5198[] = { 0x21E, 0, 0xFFFF };
u16 D_800A51A0[] = { 0x701D, 1, 0xFFFF };
u16 D_800A51A8[] = { 0x6025, 1, 0xFFFF };
u16 D_800A51B0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A51B8[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A51C0 = { D_800A5198, D_800A5120, 0x21, 4, 671, 176, 1 };
FieldActorEntry D_800A51D4 = { D_800A51A0, D_800A5138, 0x45, 5, 402, 153, 5 };
FieldActorEntry D_800A51E8 = { D_800A51A8, D_800A5150, 0x45, 5, 402, 153, 5 };
FieldActorEntry D_800A51FC = { D_800A51B0, D_800A5168, 0x45, 5, 402, 153, 5 };
FieldActorEntry D_800A5210 = { D_800A51B8, D_800A5180, 0x9D, 6, 402, 153, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A51C0,
    &D_800A51D4,
    &D_800A51E8,
    &D_800A51FC,
    &D_800A5210,
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
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2A9, 0x3C8, 0xC4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2B0, 0x98, 0x8C, 7, 0, 0, 0 },
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
