#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x6C9
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define EVENT_TEXT_FILE 0x14A
#define STAGE_FILE 0x6D8
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x25D00, 0x2F900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1A;
    D_800990B4.music = 0x60680000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress != 0x26 || FLAGS_00.checkCondition(0x1A0A, 0) != 0) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A4F08;
extern Battle D_800A4F14;
extern Battle D_800A4F20;
extern Battle D_800A4F2C;
extern Battle D_800A4F38;
extern Battle D_800A4F44;
extern Battle D_800A4F50;
extern Battle D_800A4F5C;
extern Battle D_800A4F8C;
extern Battle D_800A4F98;
extern Battle D_800A4FA4;
extern Battle D_800A4FB0;
extern Battle D_800A4FBC;
extern Battle D_800A4FC8;
extern Battle D_800A4FD4;
extern Battle D_800A4FE0;
extern Battle D_800A5010;
extern Battle D_800A501C;
extern Battle D_800A5028;
extern Battle D_800A5034;
extern Battle D_800A5040;
extern Battle D_800A504C;
extern Battle D_800A5058;
extern Battle D_800A5064;
extern Battle D_800A5094;
extern Battle D_800A50A0;
extern Battle D_800A50AC;
extern Battle D_800A50B8;
extern Battle D_800A50C4;
extern Battle D_800A50D0;
extern Battle D_800A50DC;
extern Battle D_800A50E8;
extern BattleList D_800A4F68;
extern BattleList D_800A4FEC;
extern BattleList D_800A5070;
extern BattleList D_800A50F4;
extern u16 D_800A5264[];
extern u16 D_800A526C[];
extern u16 D_800A5274[];
extern u16 D_800A527C[];
extern u16 D_800A5284[];
extern u16 D_800A528C[];
extern u16 D_800A529C[];
extern u16 D_800A52A8[];
extern u16 D_800A52B4[];
extern u16 D_800A52C0[];
extern u16 D_800A52C8[];
extern u16 D_800A52D4[];
extern u16 D_800A52DC[];
extern u16 D_800A52EC[];
extern u16 D_800A5300[];
extern u16 D_800A5308[];
extern u16 D_800A5320[];
extern u16 D_800A532C[];
extern u16 D_800A5348[];
extern u16 D_800A5368[];
extern u16 D_800A5388[];
extern u16 D_800A5390[];
extern u16 D_800A5398[];
extern u16 D_800A53A0[];
extern u16 D_800A53AC[];
extern u16 D_800A53BC[];
extern u16 D_800A53C8[];
extern u16 D_800A53DC[];
extern u16 D_800A53F0[];
extern u16 D_800A53F8[];
extern u16 D_800A5400[];
extern u16 D_800A5408[];
extern u16 D_800A5410[];
extern u16 D_800A5418[];
extern u16 D_800A5424[];
extern u16 D_800A5430[];
extern u16 D_800A543C[];
extern u16 D_800A5448[];
extern u16 D_800A5450[];
extern u16 D_800A545C[];
extern u16 D_800A5464[];
extern u16 D_800A5474[];
extern u16 D_800A5488[];
extern u16 D_800A5490[];
extern u16 D_800A54A8[];
extern u16 D_800A54B4[];
extern u16 D_800A54D0[];
extern u16 D_800A54F0[];
extern u16 D_800A5510[];
extern u16 D_800A5518[];
extern u16 D_800A5520[];
extern u16 D_800A5528[];
extern u16 D_800A5534[];
extern u16 D_800A5544[];
extern u16 D_800A5550[];
extern u16 D_800A5564[];
extern u16 D_800A5578[];
extern u16 D_800A5580[];
extern u16 D_800A5588[];
extern u16 D_800A5590[];
extern u16 D_800A5598[];
extern u16 D_800A55A0[];
extern u16 D_800A55AC[];
extern u16 D_800A55B4[];
extern u16 D_800A55BC[];
extern FieldTalk D_800A55C4[];
extern FieldTalk D_800A55DC[];
extern FieldTalk D_800A55F4[];
extern FieldTalk D_800A560C[];
extern FieldTalk D_800A5624[];
extern u16 D_800A5918[];
extern FieldTalk D_800A563C[];
extern u16 D_800A5920[];
extern FieldTalk D_800A5654[];
extern u16 D_800A592C[];
extern FieldTalk D_800A566C[];
extern u16 D_800A5938[];
extern FieldTalk D_800A5684[];
extern u16 D_800A5944[];
extern FieldTalk D_800A56FC[];
extern u16 D_800A594C[];
extern FieldTalk D_800A5744[];
extern u16 D_800A5954[];
extern FieldTalk D_800A5774[];
extern u16 D_800A5960[];
extern FieldTalk D_800A578C[];
extern u16 D_800A596C[];
extern FieldTalk D_800A5804[];
extern u16 D_800A5974[];
extern FieldTalk D_800A584C[];
extern u16 D_800A597C[];
extern FieldTalk D_800A587C[];
extern u16 D_800A5988[];
extern FieldTalk D_800A5894[];
extern u16 D_800A5994[];
extern FieldTalk D_800A58AC[];
extern u16 D_800A599C[];
extern FieldTalk D_800A58C4[];
extern u16 D_800A59A8[];
extern FieldTalk D_800A58DC[];
extern FieldTalk D_800A58F4[];
extern FieldActorEntry D_800A59B0;
extern FieldActorEntry D_800A59C4;
extern FieldActorEntry D_800A59D8;
extern FieldActorEntry D_800A59EC;
extern FieldActorEntry D_800A5A00;
extern FieldActorEntry D_800A5A14;
extern FieldActorEntry D_800A5A28;
extern FieldActorEntry D_800A5A3C;
extern FieldActorEntry D_800A5A50;
extern FieldActorEntry D_800A5A64;
extern FieldActorEntry D_800A5A78;
extern FieldActorEntry D_800A5A8C;
extern FieldActorEntry D_800A5AA0;
extern FieldActorEntry D_800A5AB4;
extern FieldActorEntry D_800A5AC8;
extern FieldActorEntry D_800A5ADC;
extern FieldActorEntry D_800A5AF0;
extern FieldActorEntry D_800A5B04;
extern FieldActorEntry D_800A5B18;
extern FieldActorEntry D_800A5B2C;
extern FieldActorEntry D_800A5B40;
extern s16 D_800A4E8C[];

s16 D_800A4E8C[] = {
    0x102, 2, 0x4B0, 0x381, 5,
    0x100, 0x15, 0x4D1, 0x371,
    0x101, 0x15, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x15, 0,
    0x200, 0, 1, 0x32D, 0,
    0x301,
    0x300, 0x1E,
    0x101, 0x15, 0x36, 1,
    0x101, 0x32D, 0x375, 2,
    0x303, 0x15,
    0x101, 0x15, 0x37, 1,
    0x300, 0x5A,
    0x304, 0xC11, 0, 0, 0,
    0,
};
Battle D_800A4F08 = { 0, 0, 0x60040000 };
Battle D_800A4F14 = { 0, 0, 0x60040000 };
Battle D_800A4F20 = { 0, 0, 0x60040000 };
Battle D_800A4F2C = { 0, 0, 0x60040000 };
Battle D_800A4F38 = { 0, 0, 0x60040000 };
Battle D_800A4F44 = { 0, 0, 0x60040000 };
Battle D_800A4F50 = { 0, 0, 0x60040000 };
Battle D_800A4F5C = { 0, 0, 0x60040000 };
BattleList D_800A4F68 = {
    3,
    { &D_800A4F08, &D_800A4F14, &D_800A4F20, &D_800A4F2C,
      &D_800A4F38, &D_800A4F44, &D_800A4F50, &D_800A4F5C },
};
Battle D_800A4F8C = { 0, 0, 0x60040000 };
Battle D_800A4F98 = { 0, 0, 0x60040000 };
Battle D_800A4FA4 = { 0, 0, 0x60040000 };
Battle D_800A4FB0 = { 0, 0, 0x60040000 };
Battle D_800A4FBC = { 0, 0, 0x60040000 };
Battle D_800A4FC8 = { 0, 0, 0x60040000 };
Battle D_800A4FD4 = { 0, 0, 0x60040000 };
Battle D_800A4FE0 = { 0, 0, 0x60040000 };
BattleList D_800A4FEC = {
    0,
    { &D_800A4F8C, &D_800A4F98, &D_800A4FA4, &D_800A4FB0,
      &D_800A4FBC, &D_800A4FC8, &D_800A4FD4, &D_800A4FE0 },
};
Battle D_800A5010 = { 0, 0, 0x60040000 };
Battle D_800A501C = { 0, 0, 0x60040000 };
Battle D_800A5028 = { 0, 0, 0x60040000 };
Battle D_800A5034 = { 0, 0, 0x60040000 };
Battle D_800A5040 = { 0, 0, 0x60040000 };
Battle D_800A504C = { 0, 0, 0x60040000 };
Battle D_800A5058 = { 0, 0, 0x60040000 };
Battle D_800A5064 = { 0, 0, 0x60040000 };
BattleList D_800A5070 = {
    0,
    { &D_800A5010, &D_800A501C, &D_800A5028, &D_800A5034,
      &D_800A5040, &D_800A504C, &D_800A5058, &D_800A5064 },
};
Battle D_800A5094 = { 251, 18, 0x60080000 };
Battle D_800A50A0 = { 252, 18, 0x60080000 };
Battle D_800A50AC = { 299, 18, 0x600C0000 };
Battle D_800A50B8 = { 300, 18, 0x600C0000 };
Battle D_800A50C4 = { 0, 0, 0x60040000 };
Battle D_800A50D0 = { 0, 0, 0x60040000 };
Battle D_800A50DC = { 0, 0, 0x60040000 };
Battle D_800A50E8 = { 0, 0, 0x60040000 };
BattleList D_800A50F4 = {
    0,
    { &D_800A5094, &D_800A50A0, &D_800A50AC, &D_800A50B8,
      &D_800A50C4, &D_800A50D0, &D_800A50DC, &D_800A50E8 },
};
FieldBattles stageBattles[] = {
    { 164, 0, 0, { &D_800A4F68, &D_800A4FEC, &D_800A5070, &D_800A50F4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x176, 0x198, 0xD8, 0x98, 0x170, 0x1FB },
    { 0x140, 0x100, 0x170, 0x100, 0xC0, 0, 0x160, 0x1FA },
    { 0x140, 0x100, 0x168, 0x158, 0xA0, 0x58, 0x170, 0x1FA },
    { 0x140, 0x100, 0x170, 0x158, 0xC0, 0x58, 0x150, 0x1F9 },
    { 0x140, 0x100, 0x16E, 0x130, 0xB8, 0x30, 0x160, 0x1F9 },
    { 0x140, 0x100, 0x168, 0x134, 0xA0, 0x34, 0x170, 0x1F9 },
    { 0x140, 0x100, 0x160, 0x134, 0x80, 0x34, 0x150, 0x1F8 },
    { 0x140, 0x100, 0x140, 0x154, 0, 0x54, 0x160, 0x1F8 },
    { 0x140, 0x100, 0x148, 0x160, 0x20, 0x60, 0x170, 0x1F8 },
    { 0x140, 0x100, 0x150, 0x164, 0x40, 0x64, 0x150, 0x1F7 },
    { 0x140, 0x100, 0x166, 0x1A0, 0x98, 0xA0, 0x160, 0x1F7 },
    { 0x140, 0x100, 0x140, 0x1A4, 0, 0xA4, 0x170, 0x1F7 },
    { 0x140, 0x100, 0x156, 0x134, 0x58, 0x34, 0x150, 0x1F6 },
};
u16 D_800A5264[] = { 0x7A30, 1, 0xFFFF };
u16 D_800A526C[] = { 0x9018, 1, 0xFFFF };
u16 D_800A5274[] = { 0x7A1D, 1, 0xFFFF };
u16 D_800A527C[] = { 0x7A1C, 1, 0xFFFF };
u16 D_800A5284[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A528C[] = { 0x253, 1, 0x8B18, 1, 0x7013, 1, 0xFFFF };
u16 D_800A529C[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A52A8[] = { 0x10, 0, 0x11, 0, 0xFFFF };
u16 D_800A52B4[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A52C0[] = { 0x11, 0, 0xFFFF };
u16 D_800A52C8[] = { 0, 0, 0x11, 0, 0xFFFF };
u16 D_800A52D4[] = { 0, 1, 0xFFFF };
u16 D_800A52DC[] = { 0x7208, 0, 0, 1, 0x11, 0, 0xFFFF };
u16 D_800A52EC[] = { 0x720A, 0, 0x7208, 1, 0, 1, 0x11, 0, 0xFFFF };
u16 D_800A5300[] = { 0x7644, 1, 0xFFFF };
u16 D_800A5308[] = {
    0xE3B, 0, 0x720A, 1, 0x7208, 1, 0, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A5320[] = { 0x7401, 1, 0xE3B, 1, 0xFFFF };
u16 D_800A532C[] = {
    0x8014, 0, 0xE3B, 1, 0x720A, 1, 0x7208, 1,
    0, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5348[] = {
    0x720B, 0, 0x8014, 1, 0xE3B, 1, 0x720A, 1,
    0x7208, 1, 0, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5368[] = {
    0x720B, 1, 0x8014, 1, 0xE3B, 1, 0x720A, 1,
    0x7208, 1, 0, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5388[] = { 0x7844, 1, 0xFFFF };
u16 D_800A5390[] = { 1, 0, 0xFFFF };
u16 D_800A5398[] = { 1, 1, 0xFFFF };
u16 D_800A53A0[] = { 1, 1, 0x720B, 0, 0xFFFF };
u16 D_800A53AC[] = { 1, 1, 0x720B, 1, 0xE59, 0, 0xFFFF };
u16 D_800A53BC[] = { 0x7401, 1, 0xE59, 1, 0xFFFF };
u16 D_800A53C8[] = { 1, 1, 0x720B, 1, 0xE59, 1, 0x720D, 0, 0xFFFF };
u16 D_800A53DC[] = { 1, 1, 0x720B, 1, 0xE59, 1, 0x720D, 1, 0xFFFF };
u16 D_800A53F0[] = { 0x7844, 1, 0xFFFF };
u16 D_800A53F8[] = { 0x11, 0, 0xFFFF };
u16 D_800A5400[] = { 0x10, 0, 0xFFFF };
u16 D_800A5408[] = { 0x11, 0, 0xFFFF };
u16 D_800A5410[] = { 0x10, 1, 0xFFFF };
u16 D_800A5418[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5424[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5430[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A543C[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5448[] = { 0x11, 0, 0xFFFF };
u16 D_800A5450[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A545C[] = { 1, 1, 0xFFFF };
u16 D_800A5464[] = { 0x7208, 0, 1, 1, 0x11, 0, 0xFFFF };
u16 D_800A5474[] = { 0x720A, 0, 0x7208, 1, 1, 1, 0x11, 0, 0xFFFF };
u16 D_800A5488[] = { 0x7643, 1, 0xFFFF };
u16 D_800A5490[] = {
    0xE3A, 0, 0x720A, 1, 0x7208, 1, 1, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A54A8[] = { 0x7400, 1, 0xE3A, 1, 0xFFFF };
u16 D_800A54B4[] = {
    0x8014, 0, 0xE3A, 1, 0x720A, 1, 0x7208, 1,
    1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A54D0[] = {
    0x720B, 0, 0x8014, 1, 0xE3A, 1, 0x720A, 1,
    0x7208, 1, 1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A54F0[] = {
    0x720B, 1, 0x8014, 1, 0xE3A, 1, 0x720A, 1,
    0x7208, 1, 1, 1, 0x11, 0, 0xFFFF,
};
u16 D_800A5510[] = { 0x7843, 1, 0xFFFF };
u16 D_800A5518[] = { 0, 0, 0xFFFF };
u16 D_800A5520[] = { 0, 1, 0xFFFF };
u16 D_800A5528[] = { 0, 1, 0x720B, 0, 0xFFFF };
u16 D_800A5534[] = { 0, 1, 0x720B, 1, 0xE58, 0, 0xFFFF };
u16 D_800A5544[] = { 0x7400, 1, 0xE58, 1, 0xFFFF };
u16 D_800A5550[] = { 0, 1, 0x720B, 1, 0xE58, 1, 0x720D, 0, 0xFFFF };
u16 D_800A5564[] = { 0, 1, 0x720B, 1, 0xE58, 1, 0x720D, 1, 0xFFFF };
u16 D_800A5578[] = { 0x7843, 1, 0xFFFF };
u16 D_800A5580[] = { 0x11, 0, 0xFFFF };
u16 D_800A5588[] = { 0x10, 0, 0xFFFF };
u16 D_800A5590[] = { 0x11, 0, 0xFFFF };
u16 D_800A5598[] = { 0x10, 1, 0xFFFF };
u16 D_800A55A0[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A55AC[] = { 0x8192, 0, 0xFFFF };
u16 D_800A55B4[] = { 0x8192, 1, 0xFFFF };
u16 D_800A55BC[] = { 0x7A4A, 1, 0xFFFF };
FieldTalk D_800A55C4[] = {
    { NULL, D_800A5264, 0x1A3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55DC[] = {
    { NULL, D_800A526C, 0x1A2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55F4[] = {
    { NULL, D_800A5274, 0x1A8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A560C[] = {
    { NULL, D_800A527C, 0x1A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5624[] = {
    { NULL, D_800A5284, 0x1A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A563C[] = {
    { NULL, D_800A528C, 0x16B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5654[] = {
    { NULL, NULL, 0x179 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A566C[] = {
    { NULL, NULL, 0x17B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5684[] = {
    { D_800A529C, D_800A52A8, 0x183 },
    { D_800A52B4, D_800A52C0, 0x182 },
    { D_800A52C8, D_800A52D4, 0x185 },
    { D_800A52DC, NULL, 0x187 },
    { D_800A52EC, D_800A5300, 0x188 },
    { D_800A5308, D_800A5320, 0x186 },
    { D_800A532C, NULL, 0x181 },
    { D_800A5348, NULL, 0x17D },
    { D_800A5368, D_800A5388, 0x136 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56FC[] = {
    { D_800A5390, D_800A5398, 0x133 },
    { D_800A53A0, NULL, 0x135 },
    { D_800A53AC, D_800A53BC, 0x134 },
    { D_800A53C8, NULL, 0x12F },
    { D_800A53DC, D_800A53F0, 0x136 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5744[] = {
    { D_800A53F8, NULL, 0x205 },
    { D_800A5400, D_800A5408, 0x130 },
    { D_800A5410, D_800A5418, 0x131 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5774[] = {
    { NULL, NULL, 0x132 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A578C[] = {
    { D_800A5424, D_800A5430, 0x183 },
    { D_800A543C, D_800A5448, 0x182 },
    { D_800A5450, D_800A545C, 0x17D },
    { D_800A5464, NULL, 0x17E },
    { D_800A5474, D_800A5488, 0x17F },
    { D_800A5490, D_800A54A8, 0x180 },
    { D_800A54B4, NULL, 0x181 },
    { D_800A54D0, NULL, 0x17E },
    { D_800A54F0, D_800A5510, 0x12D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5804[] = {
    { D_800A5518, D_800A5520, 0x185 },
    { D_800A5528, NULL, 0x187 },
    { D_800A5534, D_800A5544, 0x186 },
    { D_800A5550, NULL, 0x181 },
    { D_800A5564, D_800A5578, 0x188 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A584C[] = {
    { D_800A5580, NULL, 0x206 },
    { D_800A5588, D_800A5590, 0x182 },
    { D_800A5598, D_800A55A0, 0x183 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A587C[] = {
    { NULL, NULL, 0x184 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5894[] = {
    { NULL, NULL, 0x17A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58AC[] = {
    { NULL, NULL, 0x17A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C4[] = {
    { NULL, NULL, 0x17C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58DC[] = {
    { NULL, NULL, 0x17C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58F4[] = {
    { D_800A55AC, NULL, 0x20D },
    { D_800A55B4, D_800A55BC, 0x1A7 },
    { NULL, NULL, 0 },
};
u16 D_800A5918[] = { 0x253, 0, 0xFFFF };
u16 D_800A5920[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A592C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5938[] = { 0x8192, 1, 0x7019, 1, 0xFFFF };
u16 D_800A5944[] = { 0x602B, 1, 0xFFFF };
u16 D_800A594C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5954[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5960[] = { 0x8192, 1, 0x7019, 1, 0xFFFF };
u16 D_800A596C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5974[] = { 0x602B, 1, 0xFFFF };
u16 D_800A597C[] = { 0x8192, 0, 0x7019, 1, 0xFFFF };
u16 D_800A5988[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5994[] = { 0x701A, 1, 0xFFFF };
u16 D_800A599C[] = { 0x701E, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A59A8[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A59B0 = { NULL, D_800A55C4, 0x14, 4, 1073, 798, 1 };
FieldActorEntry D_800A59C4 = { NULL, D_800A55DC, 0x15, 5, 1233, 881, 1 };
FieldActorEntry D_800A59D8 = { NULL, D_800A55F4, 0x16, 6, 705, 597, 1 };
FieldActorEntry D_800A59EC = { NULL, D_800A560C, 0x17, 7, 626, 557, 1 };
FieldActorEntry D_800A5A00 = { NULL, D_800A5624, 0x18, 8, 1283, 541, 1 };
FieldActorEntry D_800A5A14 = { D_800A5918, D_800A563C, 0x21, 9, 1041, 881, 1 };
FieldActorEntry D_800A5A28 = { D_800A5920, D_800A5654, 0x25, 0xA, 593, 702, 1 };
FieldActorEntry D_800A5A3C = { D_800A592C, D_800A566C, 0x26, 0xB, 745, 777, 1 };
FieldActorEntry D_800A5A50 = { D_800A5938, D_800A5684, 0x45, 0xC, 290, 490, 7 };
FieldActorEntry D_800A5A64 = { D_800A5944, D_800A56FC, 0x45, 0xC, 290, 490, 7 };
FieldActorEntry D_800A5A78 = { D_800A594C, D_800A5744, 0x45, 0xC, 290, 490, 7 };
FieldActorEntry D_800A5A8C = { D_800A5954, D_800A5774, 0x45, 0xC, 290, 490, 7 };
FieldActorEntry D_800A5AA0 = { D_800A5960, D_800A578C, 0x46, 0xD, 721, 256, 7 };
FieldActorEntry D_800A5AB4 = { D_800A596C, D_800A5804, 0x46, 0xD, 721, 256, 7 };
FieldActorEntry D_800A5AC8 = { D_800A5974, D_800A584C, 0x46, 0xD, 721, 256, 7 };
FieldActorEntry D_800A5ADC = { D_800A597C, D_800A587C, 0x46, 0xD, 721, 256, 7 };
FieldActorEntry D_800A5AF0 = { D_800A5988, D_800A5894, 0x9D, 0xE, 593, 702, 1 };
FieldActorEntry D_800A5B04 = { D_800A5994, D_800A58AC, 0x9D, 0xE, 593, 702, 1 };
FieldActorEntry D_800A5B18 = { D_800A599C, D_800A58C4, 0x9E, 0xF, 745, 777, 1 };
FieldActorEntry D_800A5B2C = { D_800A59A8, D_800A58DC, 0x9E, 0xF, 745, 777, 1 };
FieldActorEntry D_800A5B40 = { NULL, D_800A58F4, 0xCE, 0x10, 1041, 657, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A59B0,
    &D_800A59C4,
    &D_800A59D8,
    &D_800A59EC,
    &D_800A5A00,
    &D_800A5A14,
    &D_800A5A28,
    &D_800A5A3C,
    &D_800A5A50,
    &D_800A5A64,
    &D_800A5A78,
    &D_800A5A8C,
    &D_800A5AA0,
    &D_800A5AB4,
    &D_800A5AC8,
    &D_800A5ADC,
    &D_800A5AF0,
    &D_800A5B04,
    &D_800A5B18,
    &D_800A5B2C,
    &D_800A5B40,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 1273, 492, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 0xB, 6, 0, 1277, 496, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 1, 0x34, 0x3B, 6, 0, 1184, 497, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 3, 6, 0, 1180, 483, 0, 0 },
    { 1, 0, 0x40, 6, 3, 0, 0, 0, 0, 0, 1272, 754, 0, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 325, 419, 441, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 388, 386, 410, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 1104, 797, 832, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D5, 0x344, 0x196, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D5, 0x318, 0x264, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2D5, 0x404, 0x1F6, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 5, 0x49E, 0x2F0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 5, 0x48F, 0x348, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1241, D_800A4E8C, EVENT_TEXT(7), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
