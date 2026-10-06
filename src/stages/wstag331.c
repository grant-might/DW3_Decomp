#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D4C(void) {
    FLAGS_00.applyAction(0x405C, 1);
}

void func_800A4D78(void) {
    FLAGS_00.applyAction(0x406A, 1);
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xE9
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x559
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define EVENT_TEXT_FILE 0x127
#define STAGE_FILE 0x569
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x49B00, 0x1E300};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 9;
    D_800990B4.music = 0x60240000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.battles = stageBattles;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

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
extern u16 D_800A5840[];
extern u16 D_800A5850[];
extern u16 D_800A5858[];
extern u16 D_800A5864[];
extern u16 D_800A586C[];
extern u16 D_800A5878[];
extern u16 D_800A5884[];
extern u16 D_800A588C[];
extern u16 D_800A5894[];
extern u16 D_800A58A0[];
extern u16 D_800A58B0[];
extern u16 D_800A58B8[];
extern u16 D_800A58CC[];
extern u16 D_800A58D8[];
extern u16 D_800A58EC[];
extern u16 D_800A58F4[];
extern u16 D_800A58FC[];
extern u16 D_800A5908[];
extern u16 D_800A5914[];
extern u16 D_800A5924[];
extern u16 D_800A5934[];
extern u16 D_800A593C[];
extern u16 D_800A5944[];
extern u16 D_800A5950[];
extern u16 D_800A5958[];
extern u16 D_800A5964[];
#if VERSION_US
extern u16 D_800A5D2C[];
#elif VERSION_EU
extern FieldTalk D_800A5D2C[];
#endif
extern FieldTalk D_800A596C[];
extern u16 D_800A5D34[];
extern u16 D_800A5D3C[];
extern FieldTalk D_800A5984[];
extern u16 D_800A5D44[];
extern FieldTalk D_800A599C[];
extern u16 D_800A5D50[];
extern FieldTalk D_800A59B4[];
extern u16 D_800A5D5C[];
extern FieldTalk D_800A59CC[];
extern u16 D_800A5D68[];
extern FieldTalk D_800A59E4[];
extern u16 D_800A5D74[];
extern FieldTalk D_800A59FC[];
extern u16 D_800A5D7C[];
extern FieldTalk D_800A5A14[];
extern u16 D_800A5D84[];
extern FieldTalk D_800A5A2C[];
extern u16 D_800A5D8C[];
extern FieldTalk D_800A5A44[];
extern u16 D_800A5D94[];
extern FieldTalk D_800A5A5C[];
extern u16 D_800A5DA0[];
extern FieldTalk D_800A5A74[];
extern u16 D_800A5DAC[];
extern FieldTalk D_800A5A8C[];
extern FieldTalk D_800A5AA4[];
extern u16 D_800A5DB4[];
extern FieldTalk D_800A5ABC[];
extern u16 D_800A5DC4[];
extern FieldTalk D_800A5AEC[];
extern u16 D_800A5DD0[];
extern FieldTalk D_800A5B04[];
extern u16 D_800A5DE4[];
extern FieldTalk D_800A5B4C[];
extern u16 D_800A5DF8[];
extern FieldTalk D_800A5B88[];
extern u16 D_800A5E00[];
extern FieldTalk D_800A5BA0[];
extern u16 D_800A5E08[];
extern FieldTalk D_800A5BC4[];
extern u16 D_800A5E10[];
extern FieldTalk D_800A5BDC[];
extern u16 D_800A5E1C[];
extern FieldTalk D_800A5BF4[];
extern u16 D_800A5E24[];
extern FieldTalk D_800A5C0C[];
extern u16 D_800A5E30[];
extern FieldTalk D_800A5C24[];
extern u16 D_800A5E38[];
extern FieldTalk D_800A5C3C[];
extern u16 D_800A5E44[];
extern FieldTalk D_800A5C54[];
extern u16 D_800A5E4C[];
extern FieldTalk D_800A5C6C[];
extern u16 D_800A5E58[];
extern FieldTalk D_800A5C84[];
extern u16 D_800A5E60[];
extern FieldTalk D_800A5C9C[];
extern u16 D_800A5E6C[];
extern FieldTalk D_800A5CB4[];
extern u16 D_800A5E74[];
extern FieldTalk D_800A5CCC[];
extern u16 D_800A5E80[];
extern FieldTalk D_800A5CE4[];
extern u16 D_800A5E88[];
extern FieldTalk D_800A5CFC[];
extern u16 D_800A5E90[];
extern FieldTalk D_800A5D14[];
extern FieldActorEntry D_800A5E98;
extern FieldActorEntry D_800A5EAC;
extern FieldActorEntry D_800A5EC0;
extern FieldActorEntry D_800A5ED4;
extern FieldActorEntry D_800A5EE8;
extern FieldActorEntry D_800A5EFC;
extern FieldActorEntry D_800A5F10;
extern FieldActorEntry D_800A5F24;
extern FieldActorEntry D_800A5F38;
extern FieldActorEntry D_800A5F4C;
extern FieldActorEntry D_800A5F60;
extern FieldActorEntry D_800A5F74;
extern FieldActorEntry D_800A5F88;
extern FieldActorEntry D_800A5F9C;
extern FieldActorEntry D_800A5FB0;
extern FieldActorEntry D_800A5FC4;
extern FieldActorEntry D_800A5FD8;
extern FieldActorEntry D_800A5FEC;
extern FieldActorEntry D_800A6000;
extern FieldActorEntry D_800A6014;
extern FieldActorEntry D_800A6028;
extern FieldActorEntry D_800A603C;
extern FieldActorEntry D_800A6050;
extern FieldActorEntry D_800A6064;
extern FieldActorEntry D_800A6078;
extern FieldActorEntry D_800A608C;
extern FieldActorEntry D_800A60A0;
extern FieldActorEntry D_800A60B4;
extern FieldActorEntry D_800A60C8;
extern FieldActorEntry D_800A60DC;
extern FieldActorEntry D_800A60F0;
extern FieldActorEntry D_800A6104;
extern FieldActorEntry D_800A6118;
extern FieldActorEntry D_800A612C;
extern FieldActorEntry D_800A6140;
extern FieldActorEntry D_800A6154;
extern s16 D_800A4F1C[];
void func_800A4D4C();
extern s16 D_800A50A4[];
void func_800A4D78();
extern u16 D_800A6F88[];

s16 D_800A4F1C[] = {
    0x102, 2, 0x514, 0x184, 5,
    0x100, 0xC, 0x460, 0x200,
    0x101, 0xC, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 2,
    0x301,
    0x300, 0x1E,
    0x102, 0xC, 0x4A6, 0x1DC, 5,
    0x302, 0xC,
    0x200, 0, 2, 0xC, 2,
    0x101, 0xC, 0x42, 7,
    0x301,
    0x102, 0xC, 0x4B6, 0x1D4, 5,
    0x302, 0xC,
    0x102, 0xC, 0x4F4, 0x194, 5,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 2, 1, 1,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 4, 0xC, 1,
    0x101, 0xC, 7, 5,
    0x301,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 6, 0xC, 1,
    0x101, 0xC, 7, 5,
    0x301,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x200, 0, 7, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 8, 0xC, 1,
    0x101, 0xC, 7, 5,
    0x301,
    0x101, 0xC, 1, 5,
    0x300, 0x1E,
    0x200, 0, 9, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x304, 0x272, 0x2DA, 0xEC, 4,
    0,
};
s16 D_800A50A4[] = {
    0x102, 2, 0x572, 0x142, 5,
#if VERSION_US
    0x100, 0xB, 0x5A8, 0xEC,
    0x101, 0xB, 1, 7,
#endif
    0x100, 0xB2, 0x5A8, 0xEC,
    0x101, 0xB2, 1, 7,
    0x100, 0x13D, 0x5C0, 0xE0,
    0x101, 0x13D, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 0x14, 2, 1,
    0x301,
    0x300, 0x1E,
#if VERSION_EU
    0x600, 0, 0xB2,
    0x101, 0xB2, 1, 1,
    0x101, 0x13D, 1, 1,
    0x101, 0x323, 0x325, 0xB2,
    0x300, 0x3C,
#endif
    0x102, 2, 0x5C0, 0xF8, 5,
#if VERSION_US
    0x101, 0xB, 1, 0,
#endif
    0x101, 0xB2, 1, 0,
#if VERSION_US
    0x101, 0x323, 0x325, 0xB,
    0x300, 0x3C,
    0x101, 0xB, 1, 7,
#elif VERSION_EU
    0x101, 0x323, 0x326, 0xB2,
    0x302, 2,
    0x101, 2, 1, 3,
#endif
    0x101, 0xB2, 1, 7,
    0x101, 0x13D, 1, 0,
#if VERSION_US
    0x101, 0x323, 0x326, 0xB,
#endif
    0x300, 0x1E,
#if VERSION_US
    0x200, 0, 1, 0xB, 0,
#elif VERSION_EU
    0x200, 0, 1, 0xB2, 0,
#endif
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x15, 0x13D, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
#if VERSION_US
    0x200, 0, 3, 0xB, 0,
    0x101, 0xB, 0xC, 7,
#elif VERSION_EU
    0x200, 0, 3, 0xB2, 0,
#endif
    0x301,
#if VERSION_US
    0x101, 0xB, 1, 7,
#endif
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
#if VERSION_US
    0x200, 0, 5, 0xB, 0,
#elif VERSION_EU
    0x200, 0, 5, 0xB2, 0,
#endif
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
#if VERSION_US
    0x200, 0, 7, 0xB, 0,
#elif VERSION_EU
    0x200, 0, 7, 0xB2, 0,
#endif
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x12, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x300, 0x1E,
#if VERSION_US
    0x200, 0, 0x13, 0xB, 0,
#elif VERSION_EU
    0x200, 0, 0x13, 0xB2, 0,
#endif
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
#if VERSION_US
    0x200, 0, 0xA, 0xB, 0,
#elif VERSION_EU
    0x200, 0, 0xA, 0xB2, 0,
#endif
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x101, 0x323, 0x327, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 2, 1, 3,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 0xB, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
#if VERSION_US
    0x600, 0, 0xB,
#elif VERSION_EU
    0x600, 0, 0xB2,
#endif
    0x102, 2, 0x5E0, 0xE8, 5,
#if VERSION_US
    0x101, 0xB, 1, 6,
#endif
    0x101, 0xB2, 1, 6,
    0x101, 0x13D, 1, 7,
#if VERSION_US
    0x101, 0x323, 0x325, 0xB,
#elif VERSION_EU
    0x101, 0x323, 0x325, 0xB2,
#endif
    0x302, 2,
#if VERSION_US
    0x200, 0, 0xC, 0xB, 0,
#elif VERSION_EU
    0x200, 0, 0xC, 0xB2, 0,
#endif
    0x101, 2, 1, 5,
    0x101, 0x323, 0x326, 0xB,
    0x301,
    0x101, 2, 1, 2,
    0x300, 0x1E,
    0x200, 0, 0xD, 2, 0,
    0x101, 2, 7, 2,
    0x301,
    0x101, 2, 1, 2,
    0x300, 0x1E,
#if VERSION_US
    0x101, 0x323, 0x327, 0xB,
#elif VERSION_EU
    0x101, 0x323, 0x327, 0xB2,
#endif
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0xB,
    0x300, 0x1E,
#if VERSION_US
    0x200, 0, 0xE, 0xB, 1,
#elif VERSION_EU
    0x200, 0, 0xE, 0xB2, 1,
#endif
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xF, 2, 2,
    0x101, 2, 7, 2,
    0x301,
    0x101, 2, 1, 2,
    0x300, 0x1E,
    0x102, 2, 0x678, 0x9C, 5,
#if VERSION_US
    0x101, 0xB, 1, 5,
#endif
    0x101, 0xB2, 1, 5,
    0x101, 0x13D, 1, 5,
    0x300, 0x5A,
    0x200, 1, 0x16, 0x13D, 0,
#if VERSION_US
    0x200, 0, 0x10, 0xB, 1,
#elif VERSION_EU
    0x200, 0, 0x10, 0xB2, 1,
#endif
    0x301,
    0x300, 0x1E,
#if VERSION_US
    0x200, 0, 0x11, 0xB, 1,
#elif VERSION_EU
    0x200, 0, 0x11, 0xB2, 1,
#endif
    0x301,
#if VERSION_US
    0x101, 0xB, 1, 7,
#endif
    0x101, 0xB2, 1, 7,
    0x101, 0x13D, 1, 1,
    0x300, 0x1E,
#if VERSION_US
    0x200, 0, 0x17, 0xB, 3,
#elif VERSION_EU
    0x200, 0, 0x17, 0xB2, 3,
#endif
    0x301,
    0x300, 0x1E,
    0x304, 0x2D7, 1, 1, 0,
    0,
};
Battle D_800A5434 = { 127, 1, 0x60080000 };
Battle D_800A5440 = { 127, 1, 0x60080000 };
Battle D_800A544C = { 127, 1, 0x60080000 };
Battle D_800A5458 = { 127, 1, 0x60080000 };
Battle D_800A5464 = { 126, 1, 0x60080000 };
Battle D_800A5470 = { 126, 1, 0x60080000 };
Battle D_800A547C = { 126, 1, 0x60080000 };
Battle D_800A5488 = { 126, 1, 0x60080000 };
BattleList D_800A5494 = {
    3,
    { &D_800A5434, &D_800A5440, &D_800A544C, &D_800A5458,
      &D_800A5464, &D_800A5470, &D_800A547C, &D_800A5488 },
};
Battle D_800A54B8 = { 127, 1, 0x60080000 };
Battle D_800A54C4 = { 127, 1, 0x60080000 };
Battle D_800A54D0 = { 127, 1, 0x60080000 };
Battle D_800A54DC = { 127, 1, 0x60080000 };
Battle D_800A54E8 = { 126, 1, 0x60080000 };
Battle D_800A54F4 = { 126, 1, 0x60080000 };
Battle D_800A5500 = { 126, 1, 0x60080000 };
Battle D_800A550C = { 126, 1, 0x60080000 };
BattleList D_800A5518 = {
    1,
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
Battle D_800A55C0 = { 224, 1, 0x60080000 };
Battle D_800A55CC = { 272, 1, 0x600C0000 };
Battle D_800A55D8 = { 0, 0, 0x60040000 };
Battle D_800A55E4 = { 329, 1, 0x60080000 };
Battle D_800A55F0 = { 330, 8, 0x60080000 };
Battle D_800A55FC = { 0, 0, 0x60040000 };
Battle D_800A5608 = { 93, 1, 0x60080000 };
Battle D_800A5614 = { 180, 8, 0x60080000 };
BattleList D_800A5620 = {
    0,
    { &D_800A55C0, &D_800A55CC, &D_800A55D8, &D_800A55E4,
      &D_800A55F0, &D_800A55FC, &D_800A5608, &D_800A5614 },
};
FieldBattles stageBattles[] = {
    { 92, 0, 0, { &D_800A5494, &D_800A5518, &D_800A559C, &D_800A5620 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
#if VERSION_US
    { 0x180, 0x100, 0x180, 0x128, 0x100, 0x28, 0x150, 0x1FF },
#endif
    { 0x180, 0x100, 0x188, 0x128, 0x120, 0x28, 0x160, 0x1FF },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x174, 0x180, 0xD0, 0x80, 0x140, 0x1FE },
    { 0x140, 0x100, 0x16A, 0x1B0, 0xA8, 0xB0, 0x150, 0x1FE },
    { 0x140, 0x100, 0x178, 0x120, 0xE0, 0x20, 0x160, 0x1FE },
    { 0x180, 0x100, 0x190, 0x128, 0x140, 0x28, 0x170, 0x1FE },
    { 0x180, 0x100, 0x188, 0x100, 0x120, 0, 0x150, 0x1FD },
    { 0x180, 0x100, 0x190, 0x100, 0x140, 0, 0x160, 0x1FD },
    { 0x180, 0x100, 0x198, 0x100, 0x160, 0, 0x170, 0x1FD },
    { 0x180, 0x100, 0x1A0, 0x100, 0x180, 0, 0x140, 0x1FC },
    { 0x180, 0x100, 0x198, 0x128, 0x160, 0x28, 0x150, 0x1FC },
    { 0x180, 0x100, 0x1A0, 0x128, 0x180, 0x28, 0x160, 0x1FC },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x180, 0x100, 0x1A8, 0x100, 0x1A0, 0, 0x170, 0x1FC },
    { 0x180, 0x100, 0x1B0, 0x100, 0x1C0, 0, 0x140, 0x1FB },
    { 0x180, 0x100, 0x1A8, 0x128, 0x1A0, 0x28, 0x150, 0x1FB },
    { 0x180, 0x100, 0x1B0, 0x128, 0x1C0, 0x28, 0x160, 0x1FB },
    { 0x180, 0x100, 0x180, 0x148, 0x100, 0x48, 0x170, 0x1FB },
    { 0x180, 0x100, 0x188, 0x148, 0x120, 0x48, 0x140, 0x1FA },
    { 0x180, 0x100, 0x190, 0x148, 0x140, 0x48, 0x150, 0x1FA },
    { 0x180, 0x100, 0x198, 0x148, 0x160, 0x48, 0x160, 0x1FA },
    { 0x180, 0x100, 0x1A0, 0x148, 0x180, 0x48, 0x170, 0x1FA },
    { 0x180, 0x100, 0x1A8, 0x148, 0x1A0, 0x48, 0x140, 0x1F9 },
};
u16 D_800A5840[] = { 0x21D, 1, 0x822C, 1, 0x7013, 1, 0xFFFF };
u16 D_800A5850[] = { 0x11, 0, 0xFFFF };
u16 D_800A5858[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5864[] = { 0x11, 0, 0xFFFF };
u16 D_800A586C[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5878[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5884[] = { 0, 0, 0xFFFF };
u16 D_800A588C[] = { 0, 1, 0xFFFF };
u16 D_800A5894[] = { 0, 1, 0x7209, 0, 0xFFFF };
u16 D_800A58A0[] = { 0, 1, 0x7209, 1, 0x720B, 0, 0xFFFF };
u16 D_800A58B0[] = { 0x7622, 1, 0xFFFF };
u16 D_800A58B8[] = { 0, 1, 0x7209, 1, 0x720B, 1, 0xE1B, 0, 0xFFFF };
u16 D_800A58CC[] = { 0x7400, 1, 0xE1B, 1, 0xFFFF };
u16 D_800A58D8[] = { 0, 1, 0x7209, 1, 0x720B, 1, 0xE1B, 1, 0xFFFF };
u16 D_800A58EC[] = { 0, 0, 0xFFFF };
u16 D_800A58F4[] = { 0, 1, 0xFFFF };
u16 D_800A58FC[] = { 0, 1, 0xE3C, 0, 0xFFFF };
u16 D_800A5908[] = { 0x7400, 1, 0xE3C, 1, 0xFFFF };
u16 D_800A5914[] = { 0, 1, 0xE3C, 1, 0x720D, 0, 0xFFFF };
u16 D_800A5924[] = { 0, 1, 0xE3C, 1, 0x720D, 1, 0xFFFF };
u16 D_800A5934[] = { 0x7822, 1, 0xFFFF };
u16 D_800A593C[] = { 0x940D, 1, 0xFFFF };
u16 D_800A5944[] = { 0x8028, 1, 0x8029, 0, 0xFFFF };
u16 D_800A5950[] = { 0x9407, 1, 0xFFFF };
u16 D_800A5958[] = { 0x8028, 1, 0x8029, 1, 0xFFFF };
u16 D_800A5964[] = { 0x9408, 1, 0xFFFF };
FieldTalk D_800A596C[] = {
#if VERSION_US
    { NULL, NULL, 0x39A },
#elif VERSION_EU
    { NULL, D_800A5840, 0x17D },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A5984[] = {
#if VERSION_US
    { NULL, D_800A5840, 0x17D },
#elif VERSION_EU
    { NULL, NULL, 0x21 },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A599C[] = {
#if VERSION_US
    { NULL, NULL, 0x21 },
#elif VERSION_EU
    { NULL, NULL, 0x24 },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A59B4[] = {
#if VERSION_US
    { NULL, NULL, 0x24 },
#elif VERSION_EU
    { NULL, NULL, 0x1B },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A59CC[] = {
#if VERSION_US
    { NULL, NULL, 0x1B },
#elif VERSION_EU
    { NULL, NULL, 0x1E },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A59E4[] = {
#if VERSION_US
    { NULL, NULL, 0x1E },
#elif VERSION_EU
    { NULL, NULL, 0x26 },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A59FC[] = {
#if VERSION_US
    { NULL, NULL, 0x26 },
#elif VERSION_EU
    { NULL, NULL, 0x2A },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A14[] = {
#if VERSION_US
    { NULL, NULL, 0x2A },
#elif VERSION_EU
    { NULL, NULL, 0x28 },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A2C[] = {
#if VERSION_US
    { NULL, NULL, 0x28 },
#elif VERSION_EU
    { NULL, NULL, 0x29 },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A44[] = {
#if VERSION_US
    { NULL, NULL, 0x29 },
#elif VERSION_EU
    { NULL, NULL, 0x15 },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A5C[] = {
#if VERSION_US
    { NULL, NULL, 0x15 },
#elif VERSION_EU
    { NULL, NULL, 0x18 },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A74[] = {
#if VERSION_US
    { NULL, NULL, 0x18 },
#elif VERSION_EU
    { NULL, NULL, 0x27 },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A8C[] = {
#if VERSION_US
    { NULL, NULL, 0x27 },
#elif VERSION_EU
    { NULL, NULL, 0x13 },
#endif
    { NULL, NULL, 0 },
};
#if VERSION_US
FieldTalk D_800A5AA4[] = {
    { NULL, NULL, 0x13 },
    { NULL, NULL, 0 },
};
#endif
FieldTalk D_800A5ABC[] = {
    { D_800A5850, NULL, 0x248 },
    { D_800A5858, D_800A5864, 0x249 },
    { D_800A586C, D_800A5878, 0x24A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AEC[] = {
    { NULL, NULL, 0x24B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B04[] = {
    { D_800A5884, D_800A588C, 0x244 },
    { D_800A5894, NULL, 0x245 },
    { D_800A58A0, D_800A58B0, 0x246 },
    { D_800A58B8, D_800A58CC, 0x247 },
    { D_800A58D8, NULL, 0x248 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B4C[] = {
    { D_800A58EC, D_800A58F4, 0x24C },
    { D_800A58FC, D_800A5908, 0x24D },
    { D_800A5914, NULL, 0x24E },
    { D_800A5924, D_800A5934, 0x24F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B88[] = {
    { NULL, D_800A593C, 0x2D8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BA0[] = {
    { D_800A5944, D_800A5950, 0x2D8 },
    { D_800A5958, D_800A5964, 0x2D8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BC4[] = {
    { NULL, NULL, 0x22 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BDC[] = {
    { NULL, NULL, 0x20 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BF4[] = {
    { NULL, NULL, 0x25 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C0C[] = {
    { NULL, NULL, 0x23 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C24[] = {
    { NULL, NULL, 0x16 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C3C[] = {
    { NULL, NULL, 0x14 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C54[] = {
    { NULL, NULL, 0x19 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C6C[] = {
    { NULL, NULL, 0x17 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C84[] = {
    { NULL, NULL, 0x1F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C9C[] = {
    { NULL, NULL, 0x1D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CB4[] = {
    { NULL, NULL, 0x1C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CCC[] = {
    { NULL, NULL, 0x1A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CE4[] = {
#if VERSION_US
    { NULL, NULL, 0x346 },
#elif VERSION_EU
    { NULL, NULL, 0x39A },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CFC[] = {
#if VERSION_US
    { NULL, NULL, 0x347 },
#elif VERSION_EU
    { NULL, NULL, 0x346 },
#endif
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D14[] = {
    { NULL, NULL, 0x347 },
    { NULL, NULL, 0 },
};
#if VERSION_US
u16 D_800A5D2C[] = { 0x6027, 1, 0xFFFF };
#elif VERSION_EU
FieldTalk D_800A5D2C[] = {
    { NULL, NULL, 0x347 },
    { NULL, NULL, 0 },
};
#endif
u16 D_800A5D34[] = { 0x6024, 1, 0xFFFF };
u16 D_800A5D3C[] = { 0x21D, 0, 0xFFFF };
u16 D_800A5D44[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5D50[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5D5C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5D68[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5D74[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5D7C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5D84[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5D8C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5D94[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5DA0[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5DAC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5DB4[] = { 0x8192, 1, 0x11, 1, 0x7004, 1, 0xFFFF };
u16 D_800A5DC4[] = { 0x8192, 0, 0x7004, 1, 0xFFFF };
u16 D_800A5DD0[] = { 0x11, 0, 0x8192, 1, 0x7004, 1, 0x8014, 0, 0xFFFF };
u16 D_800A5DE4[] = { 0x7004, 1, 0x11, 0, 0x8192, 1, 0x8014, 1, 0xFFFF };
u16 D_800A5DF8[] = { 0x802A, 1, 0xFFFF };
u16 D_800A5E00[] = { 0x802A, 0, 0xFFFF };
u16 D_800A5E08[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E10[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5E1C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E24[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5E30[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E38[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5E44[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E4C[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5E58[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E60[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
u16 D_800A5E6C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5E74[] = { 0x1A0A, 0, 0x701E, 1, 0xFFFF };
#if VERSION_EU
u16 D_800A6F88[] = { 0x6027, 1, 0xFFFF };
#endif
u16 D_800A5E80[] = { 0x6028, 1, 0xFFFF };
u16 D_800A5E88[] = { 0x6028, 1, 0xFFFF };
u16 D_800A5E90[] = { 0x6027, 1, 0xFFFF };
#if VERSION_US
FieldActorEntry D_800A5E98 = { D_800A5D2C, D_800A596C, 0xB, 4, 1448, 236, 7 };
#elif VERSION_EU
FieldActorEntry D_800A5E98 = { D_800A5D34, NULL, 0xC, 4, 0, 0, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5EAC = { D_800A5D34, NULL, 0xC, 5, 0, 0, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5EAC = { D_800A5D3C, D_800A596C, 0x21, 5, 737, 954, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5EC0 = { D_800A5D3C, D_800A5984, 0x21, 6, 737, 954, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5EC0 = { D_800A5D44, D_800A5984, 0x25, 6, 1072, 665, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5ED4 = { D_800A5D44, D_800A599C, 0x25, 7, 1072, 665, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5ED4 = { D_800A5D50, D_800A599C, 0x26, 7, 864, 577, 5 };
#endif
#if VERSION_US
FieldActorEntry D_800A5EE8 = { D_800A5D50, D_800A59B4, 0x26, 8, 864, 577, 5 };
#elif VERSION_EU
FieldActorEntry D_800A5EE8 = { D_800A5D5C, D_800A59B4, 0x2D, 8, 688, 633, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5EFC = { D_800A5D5C, D_800A59CC, 0x2D, 9, 688, 633, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5EFC = { D_800A5D68, D_800A59CC, 0x2E, 9, 913, 233, 3 };
#endif
#if VERSION_US
FieldActorEntry D_800A5F10 = { D_800A5D68, D_800A59E4, 0x2E, 0xA, 913, 233, 3 };
#elif VERSION_EU
FieldActorEntry D_800A5F10 = { D_800A5D74, D_800A59E4, 0x30, 0xA, 401, 785, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5F24 = { D_800A5D74, D_800A59FC, 0x30, 0xB, 401, 785, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5F24 = { D_800A5D7C, D_800A59FC, 0x31, 0xB, 545, 385, 7 };
#endif
#if VERSION_US
FieldActorEntry D_800A5F38 = { D_800A5D7C, D_800A5A14, 0x31, 0xC, 545, 385, 7 };
#elif VERSION_EU
FieldActorEntry D_800A5F38 = { D_800A5D84, D_800A5A14, 0x34, 0xC, 560, 728, 7 };
#endif
#if VERSION_US
FieldActorEntry D_800A5F4C = { D_800A5D84, D_800A5A2C, 0x34, 0xD, 560, 728, 7 };
#elif VERSION_EU
FieldActorEntry D_800A5F4C = { D_800A5D8C, D_800A5A2C, 0x38, 0xD, 864, 577, 5 };
#endif
#if VERSION_US
FieldActorEntry D_800A5F60 = { D_800A5D8C, D_800A5A44, 0x38, 0xE, 864, 577, 5 };
#elif VERSION_EU
FieldActorEntry D_800A5F60 = { D_800A5D94, D_800A5A44, 0x39, 0xE, 560, 728, 7 };
#endif
#if VERSION_US
FieldActorEntry D_800A5F74 = { D_800A5D94, D_800A5A5C, 0x39, 0xF, 560, 728, 7 };
#elif VERSION_EU
FieldActorEntry D_800A5F74 = { D_800A5DA0, D_800A5A5C, 0x3A, 0xF, 401, 785, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5F88 = { D_800A5DA0, D_800A5A74, 0x3A, 0x10, 401, 785, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5F88 = { D_800A5DAC, D_800A5A74, 0x3A, 0xF, 1072, 665, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5F9C = { D_800A5DAC, D_800A5A8C, 0x3A, 0x10, 1072, 665, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5F9C = { NULL, D_800A5A8C, 0x3F, 0x10, 961, 681, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5FB0 = { NULL, D_800A5AA4, 0x3F, 0x11, 961, 681, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5FB0 = { D_800A5DB4, D_800A5ABC, 0x45, 0x11, 1152, 793, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5FC4 = { D_800A5DB4, D_800A5ABC, 0x45, 0x12, 1152, 793, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5FC4 = { D_800A5DC4, D_800A5AEC, 0x45, 0x11, 1152, 793, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5FD8 = { D_800A5DC4, D_800A5AEC, 0x45, 0x12, 1152, 793, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5FD8 = { D_800A5DD0, D_800A5B04, 0x45, 0x11, 1152, 793, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A5FEC = { D_800A5DD0, D_800A5B04, 0x45, 0x12, 1152, 793, 1 };
#elif VERSION_EU
FieldActorEntry D_800A5FEC = { D_800A5DE4, D_800A5B4C, 0x45, 0x11, 1152, 793, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A6000 = { D_800A5DE4, D_800A5B4C, 0x45, 0x12, 1152, 793, 1 };
#elif VERSION_EU
FieldActorEntry D_800A6000 = { D_800A5DF8, D_800A5B88, 0x89, 0x12, 923, 374, 7 };
#endif
#if VERSION_US
FieldActorEntry D_800A6014 = { D_800A5DF8, D_800A5B88, 0x89, 0x13, 923, 374, 7 };
#elif VERSION_EU
FieldActorEntry D_800A6014 = { D_800A5E00, D_800A5BA0, 0x89, 0x12, 923, 374, 7 };
#endif
#if VERSION_US
FieldActorEntry D_800A6028 = { D_800A5E00, D_800A5BA0, 0x89, 0x13, 923, 374, 7 };
#elif VERSION_EU
FieldActorEntry D_800A6028 = { D_800A5E08, D_800A5BC4, 0x9D, 0x13, 1072, 665, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A603C = { D_800A5E08, D_800A5BC4, 0x9D, 0x14, 1072, 665, 1 };
#elif VERSION_EU
FieldActorEntry D_800A603C = { D_800A5E10, D_800A5BDC, 0x9D, 0x13, 1072, 665, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A6050 = { D_800A5E10, D_800A5BDC, 0x9D, 0x14, 1072, 665, 1 };
#elif VERSION_EU
FieldActorEntry D_800A6050 = { D_800A5E1C, D_800A5BF4, 0x9E, 0x14, 864, 577, 5 };
#endif
#if VERSION_US
FieldActorEntry D_800A6064 = { D_800A5E1C, D_800A5BF4, 0x9E, 0x15, 864, 577, 5 };
#elif VERSION_EU
FieldActorEntry D_800A6064 = { D_800A5E24, D_800A5C0C, 0x9E, 0x14, 864, 577, 5 };
#endif
#if VERSION_US
FieldActorEntry D_800A6078 = { D_800A5E24, D_800A5C0C, 0x9E, 0x15, 864, 577, 5 };
#elif VERSION_EU
FieldActorEntry D_800A6078 = { D_800A5E30, D_800A5C24, 0x9F, 0x15, 560, 728, 7 };
#endif
#if VERSION_US
FieldActorEntry D_800A608C = { D_800A5E30, D_800A5C24, 0x9F, 0x16, 560, 728, 7 };
#elif VERSION_EU
FieldActorEntry D_800A608C = { D_800A5E38, D_800A5C3C, 0x9F, 0x15, 560, 728, 7 };
#endif
#if VERSION_US
FieldActorEntry D_800A60A0 = { D_800A5E38, D_800A5C3C, 0x9F, 0x16, 560, 728, 7 };
#elif VERSION_EU
FieldActorEntry D_800A60A0 = { D_800A5E44, D_800A5C54, 0xA0, 0x16, 401, 785, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A60B4 = { D_800A5E44, D_800A5C54, 0xA0, 0x17, 401, 785, 1 };
#elif VERSION_EU
FieldActorEntry D_800A60B4 = { D_800A5E4C, D_800A5C6C, 0xA0, 0x16, 401, 785, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A60C8 = { D_800A5E4C, D_800A5C6C, 0xA0, 0x17, 401, 785, 1 };
#elif VERSION_EU
FieldActorEntry D_800A60C8 = { D_800A5E58, D_800A5C84, 0xA1, 0x17, 913, 233, 3 };
#endif
#if VERSION_US
FieldActorEntry D_800A60DC = { D_800A5E58, D_800A5C84, 0xA1, 0x18, 913, 233, 3 };
#elif VERSION_EU
FieldActorEntry D_800A60DC = { D_800A5E60, D_800A5C9C, 0xA1, 0x17, 913, 233, 3 };
#endif
#if VERSION_US
FieldActorEntry D_800A60F0 = { D_800A5E60, D_800A5C9C, 0xA1, 0x18, 913, 233, 3 };
#elif VERSION_EU
FieldActorEntry D_800A60F0 = { D_800A5E6C, D_800A5CB4, 0xA2, 0x18, 688, 633, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A6104 = { D_800A5E6C, D_800A5CB4, 0xA2, 0x19, 688, 633, 1 };
#elif VERSION_EU
FieldActorEntry D_800A6104 = { D_800A5E74, D_800A5CCC, 0xA2, 0x18, 688, 633, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A6118 = { D_800A5E74, D_800A5CCC, 0xA2, 0x19, 688, 633, 1 };
#elif VERSION_EU
FieldActorEntry D_800A6118 = { D_800A6F88, D_800A5CE4, 0xB2, 0x19, 1448, 236, 7 };
#endif
#if VERSION_US
FieldActorEntry D_800A612C = { D_800A5E80, D_800A5CE4, 0xB2, 0x1A, 1110, 595, 1 };
#elif VERSION_EU
FieldActorEntry D_800A612C = { D_800A5E80, D_800A5CFC, 0xB2, 0x19, 1110, 595, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A6140 = { D_800A5E88, D_800A5CFC, 0x13D, 0x1B, 1088, 584, 1 };
#elif VERSION_EU
FieldActorEntry D_800A6140 = { D_800A5E88, D_800A5D14, 0x13D, 0x1A, 1088, 584, 1 };
#endif
#if VERSION_US
FieldActorEntry D_800A6154 = { D_800A5E90, D_800A5D14, 0x13D, 0x1B, 1472, 224, 1 };
#elif VERSION_EU
FieldActorEntry D_800A6154 = { D_800A5E90, D_800A5D2C, 0x13D, 0x1A, 1472, 224, 1 };
#endif
FieldActorEntry *stageActors[] = {
    &D_800A5E98,
    &D_800A5EAC,
    &D_800A5EC0,
    &D_800A5ED4,
    &D_800A5EE8,
    &D_800A5EFC,
    &D_800A5F10,
    &D_800A5F24,
    &D_800A5F38,
    &D_800A5F4C,
    &D_800A5F60,
    &D_800A5F74,
    &D_800A5F88,
    &D_800A5F9C,
    &D_800A5FB0,
    &D_800A5FC4,
    &D_800A5FD8,
    &D_800A5FEC,
    &D_800A6000,
    &D_800A6014,
    &D_800A6028,
    &D_800A603C,
    &D_800A6050,
    &D_800A6064,
    &D_800A6078,
    &D_800A608C,
    &D_800A60A0,
    &D_800A60B4,
    &D_800A60C8,
    &D_800A60DC,
    &D_800A60F0,
    &D_800A6104,
    &D_800A6118,
    &D_800A612C,
    &D_800A6140,
    &D_800A6154,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 787, 422, 0, 0 },
    { 1, 0, 0x40, 2, 9, 0, 0, 0, 0, 0, 200, 248, 0, 0 },
    { 1, 0, 0x40, 2, 9, 0, 0, 0, 0, 0, 408, 880, 0, 0 },
    { 1, 0, 0x40, 2, 9, 0, 0, 0, 0, 0, 1320, 887, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 51, 661, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 159, 547, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1084, 1101, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1091, 247, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 1, 0x2C, 0x3B, 0xA, 0, 1517, 432, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 92, 596, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 226, 835, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 532, 1050, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 590, 68, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 881, 481, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 913, 1106, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1108, 362, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 1, 0x3C, 0x46, 0xA, 0, 1357, 486, 0, 0 },
    { 1, 0, 0x72, 4, 0, 0, 0, 0, 0, 0, 765, 572, 665, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 951, 632, 679, 0 },
    { 1, 0, 0x7D, 4, 2, 0, 0, 0, 0, 0, 816, 122, 245, 0 },
    { 1, 0, 0x7D, 4, 3, 0, 0, 0, 0, 0, 800, 114, 238, 0 },
    { 1, 0, 0x7D, 4, 4, 0, 0, 0, 0, 0, 784, 106, 230, 0 },
    { 1, 0, 0x7D, 4, 5, 0, 0, 0, 0, 0, 767, 99, 223, 0 },
    { 1, 0, 0x46, 4, 0xF, 0, 0, 0, 0, 0, 1224, 424, 484, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 243, 754, 754, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 266, 606, 606, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 275, 778, 778, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 314, 630, 630, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 338, 538, 538, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 363, 654, 654, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 410, 678, 678, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 483, 930, 930, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 531, 906, 906, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 547, 674, 674, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 579, 882, 882, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 595, 650, 650, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 626, 474, 474, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 627, 858, 858, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 643, 994, 994, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 667, 454, 454, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 691, 490, 490, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 723, 826, 826, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 771, 802, 802, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 787, 938, 938, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 819, 778, 778, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 835, 194, 194, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 835, 914, 914, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 883, 890, 890, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 883, 938, 938, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 931, 914, 914, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 979, 378, 378, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 979, 890, 890, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1027, 402, 402, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1075, 426, 426, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1314, 642, 642, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1315, 690, 690, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1315, 738, 738, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1363, 570, 570, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1363, 618, 618, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1363, 666, 666, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1363, 714, 714, 0 },
    { 1, 0xFF, 0x64, 4, 0x38, 0, 0, 0, 0, 0, 1363, 762, 762, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x272, 0x100, 0x1E0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28D, 0x7C, 0x7E, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28E, 0x30A, 0x98, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x28F, 0x4AC, 0x326, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x2CE, 0x124, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0x2DF, 0xF0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x324, 0x170, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x333, 0x11A, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E5, 0x240, 0x120, 1, 0, 0xB, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 0x1C, 1 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 3, 4 },
    { { { 0x7094, 1 }, { 0xFFFF, 0 } }, 9, 0x2E8, 0x240, 0xD0, 1, 0, 8, 2 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x60, 0xFFF0, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x30, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0x40, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFB0, 0x10, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0xFFE8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0, 0xFFD8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFE0, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0x30, 0x28, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFD0, 0xFFF8, 0, 0, 0, 0, 0 },
    { { { 0x8005, 1 }, { 0xFFFF, 0 } }, 7, 0xFFC0, 0x14, 0, 0, 0, 0, 0 },
    { { { 0x6024, 1 }, { 0x405C, 0 } }, 8, 0x398, 0, 0, 0, 0, 0, 0 },
    { { { 0x6027, 1 }, { 0x406A, 0 } }, 8, 0x3CA, 0, 0, 0, 0, 0, 0 },
    { { { 0x7093, 1 }, { 0xFFFF, 0 } }, 0xA, 0x2E5, 0x240, 0x120, 1, 0, 0xB, 1 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 920, D_800A4F1C, EVENT_TEXT(0xE), NULL, func_800A4D4C },
    { 970, D_800A50A4, EVENT_TEXT(0x16), NULL, func_800A4D78 },
    { -1, NULL, 0, NULL, NULL },
};
