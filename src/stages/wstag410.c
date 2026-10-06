#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

void func_800A4D4C(void) {
    GAME.progress = 6;
}

const CVECTOR stageColor = { 0x80, 0x80, 0x80, 0x00 };
#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x38D
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x39D
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x26F00, 0xA800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xE;
    D_800990B4.music = 0x60380000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

extern Battle D_800A513C;
extern Battle D_800A5148;
extern Battle D_800A5154;
extern Battle D_800A5160;
extern Battle D_800A516C;
extern Battle D_800A5178;
extern Battle D_800A5184;
extern Battle D_800A5190;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A51F0;
extern Battle D_800A51FC;
extern Battle D_800A5208;
extern Battle D_800A5214;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5274;
extern Battle D_800A5280;
extern Battle D_800A528C;
extern Battle D_800A5298;
extern Battle D_800A52C8;
extern Battle D_800A52D4;
extern Battle D_800A52E0;
extern Battle D_800A52EC;
extern Battle D_800A52F8;
extern Battle D_800A5304;
extern Battle D_800A5310;
extern Battle D_800A531C;
extern BattleList D_800A519C;
extern BattleList D_800A5220;
extern BattleList D_800A52A4;
extern BattleList D_800A5328;
extern u16 D_800A53F8[];
extern u16 D_800A5400[];
extern u16 D_800A5408[];
extern u16 D_800A5414[];
extern u16 D_800A5424[];
extern u16 D_800A542C[];
extern u16 D_800A5440[];
extern u16 D_800A544C[];
extern u16 D_800A5464[];
extern u16 D_800A5480[];
extern u16 D_800A549C[];
extern u16 D_800A54A4[];
extern u16 D_800A54AC[];
extern u16 D_800A54B8[];
extern u16 D_800A54C0[];
extern u16 D_800A54CC[];
extern u16 D_800A54D8[];
extern u16 D_800A54E0[];
extern u16 D_800A54E8[];
extern u16 D_800A54F4[];
extern u16 D_800A5504[];
extern u16 D_800A550C[];
extern u16 D_800A5520[];
extern u16 D_800A552C[];
extern u16 D_800A5544[];
extern u16 D_800A5560[];
extern u16 D_800A557C[];
extern u16 D_800A5584[];
extern u16 D_800A558C[];
extern u16 D_800A5594[];
extern u16 D_800A55A0[];
extern u16 D_800A55B0[];
extern u16 D_800A55B8[];
extern u16 D_800A55CC[];
extern u16 D_800A55D8[];
extern u16 D_800A55F0[];
extern u16 D_800A560C[];
extern u16 D_800A5628[];
extern u16 D_800A5630[];
extern u16 D_800A5638[];
extern u16 D_800A5640[];
extern u16 D_800A564C[];
extern u16 D_800A565C[];
extern u16 D_800A566C[];
extern u16 D_800A567C[];
extern u16 D_800A5684[];
extern u16 D_800A568C[];
extern u16 D_800A5698[];
extern u16 D_800A56A8[];
extern u16 D_800A56B0[];
extern u16 D_800A56C4[];
extern u16 D_800A56CC[];
extern u16 D_800A56E4[];
extern u16 D_800A5700[];
extern u16 D_800A571C[];
extern u16 D_800A5940[];
extern FieldTalk D_800A5724[];
extern u16 D_800A5950[];
extern FieldTalk D_800A5784[];
extern u16 D_800A5960[];
extern FieldTalk D_800A57B4[];
extern u16 D_800A5970[];
extern FieldTalk D_800A5814[];
extern u16 D_800A5980[];
extern FieldTalk D_800A5874[];
extern u16 D_800A5990[];
extern FieldTalk D_800A588C[];
extern u16 D_800A5998[];
extern FieldTalk D_800A58C8[];
extern u16 D_800A59A0[];
extern FieldTalk D_800A58E0[];
extern FieldActorEntry D_800A59A8;
extern FieldActorEntry D_800A59BC;
extern FieldActorEntry D_800A59D0;
extern FieldActorEntry D_800A59E4;
extern FieldActorEntry D_800A59F8;
extern FieldActorEntry D_800A5A0C;
extern FieldActorEntry D_800A5A20;
extern FieldActorEntry D_800A5A34;
extern s16 D_800A4EA0[];
extern s16 D_800A4F44[];
extern s16 D_800A5010[];
extern s16 D_800A50C0[];

s16 D_800A4EA0[] = {
    0x102, 2, 0x1DE, 0x140, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 0,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x20E, 0x128, 5,
    0x300, 0x1E,
    0x304, 0x22A, 0xD0, 0x2FC, 7,
    0,
};
s16 D_800A4F44[] = {
    0x102, 2, 0x1DE, 0x140, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 0x323, 0x327, 2,
    0x300, 0x78,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 0x324, 0x325, 2,
    0x300, 0x78,
    0x101, 0x324, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x1FF, 0x130, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0,
};
s16 D_800A5010[] = {
    0x102, 2, 0x1DE, 0x140, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 2, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x338, 2,
    0x300, 0x3C,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 2, 2, 2,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x1EF, 0x139, 5,
    0x302, 2,
    0x102, 2, 0x19F, 0x111, 3,
    0x302, 2,
    0x102, 2, 0x13F, 0x141, 1,
    0x300, 0x3C,
    0x304, 0x22D, 0x114, 0x157, 1,
    0,
};
s16 D_800A50C0[] = {
    0x102, 2, 0x1DE, 0x140, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x101, 0x32D, 0x338, 2,
    0x300, 0x78,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 4,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x102, 2, 0x18E, 0x118, 3,
    0x302, 2,
    0x102, 2, 0x14E, 0x138, 1,
    0x300, 0x3C,
    0x304, 0x232, 0x1C0, 0xD0, 1,
    0,
};
Battle D_800A513C = { 0, 0, 0x60040000 };
Battle D_800A5148 = { 0, 0, 0x60040000 };
Battle D_800A5154 = { 0, 0, 0x60040000 };
Battle D_800A5160 = { 0, 0, 0x60040000 };
Battle D_800A516C = { 0, 0, 0x60040000 };
Battle D_800A5178 = { 0, 0, 0x60040000 };
Battle D_800A5184 = { 0, 0, 0x60040000 };
Battle D_800A5190 = { 0, 0, 0x60040000 };
BattleList D_800A519C = {
    3,
    { &D_800A513C, &D_800A5148, &D_800A5154, &D_800A5160,
      &D_800A516C, &D_800A5178, &D_800A5184, &D_800A5190 },
};
Battle D_800A51C0 = { 0, 0, 0x60040000 };
Battle D_800A51CC = { 0, 0, 0x60040000 };
Battle D_800A51D8 = { 0, 0, 0x60040000 };
Battle D_800A51E4 = { 0, 0, 0x60040000 };
Battle D_800A51F0 = { 0, 0, 0x60040000 };
Battle D_800A51FC = { 0, 0, 0x60040000 };
Battle D_800A5208 = { 0, 0, 0x60040000 };
Battle D_800A5214 = { 0, 0, 0x60040000 };
BattleList D_800A5220 = {
    0,
    { &D_800A51C0, &D_800A51CC, &D_800A51D8, &D_800A51E4,
      &D_800A51F0, &D_800A51FC, &D_800A5208, &D_800A5214 },
};
Battle D_800A5244 = { 0, 0, 0x60040000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
Battle D_800A5274 = { 0, 0, 0x60040000 };
Battle D_800A5280 = { 0, 0, 0x60040000 };
Battle D_800A528C = { 0, 0, 0x60040000 };
Battle D_800A5298 = { 0, 0, 0x60040000 };
BattleList D_800A52A4 = {
    0,
    { &D_800A5244, &D_800A5250, &D_800A525C, &D_800A5268,
      &D_800A5274, &D_800A5280, &D_800A528C, &D_800A5298 },
};
Battle D_800A52C8 = { 208, 20, 0x600C0000 };
Battle D_800A52D4 = { 0, 0, 0x60040000 };
Battle D_800A52E0 = { 0, 0, 0x60040000 };
Battle D_800A52EC = { 0, 0, 0x60040000 };
Battle D_800A52F8 = { 0, 0, 0x60040000 };
Battle D_800A5304 = { 0, 0, 0x60040000 };
Battle D_800A5310 = { 0, 0, 0x60040000 };
Battle D_800A531C = { 0, 0, 0x60040000 };
BattleList D_800A5328 = {
    0,
    { &D_800A52C8, &D_800A52D4, &D_800A52E0, &D_800A52EC,
      &D_800A52F8, &D_800A5304, &D_800A5310, &D_800A531C },
};
FieldBattles stageBattles[] = {
    { 154, 0, 0, { &D_800A519C, &D_800A5220, &D_800A52A4, &D_800A5328 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x170, 0x1FF },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x174, 0x128, 0xD0, 0x28, 0x160, 0x1FE },
};
u16 D_800A53F8[] = { 0, 0, 0xFFFF };
u16 D_800A5400[] = { 0, 1, 0xFFFF };
u16 D_800A5408[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5414[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A5424[] = { 0x7612, 1, 0xFFFF };
u16 D_800A542C[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE08, 0, 0xFFFF };
u16 D_800A5440[] = { 0xE08, 1, 0x7400, 1, 0xFFFF };
u16 D_800A544C[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0x8012, 0,
    0xE08, 1, 0xFFFF,
};
u16 D_800A5464[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0x8012, 1,
    0x7205, 0, 0xE08, 1, 0xFFFF,
};
u16 D_800A5480[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE08, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A549C[] = { 0x7812, 1, 0xFFFF };
u16 D_800A54A4[] = { 0x11, 0, 0xFFFF };
u16 D_800A54AC[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A54B8[] = { 0x11, 0, 0xFFFF };
u16 D_800A54C0[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A54CC[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A54D8[] = { 0, 0, 0xFFFF };
u16 D_800A54E0[] = { 0, 1, 0xFFFF };
u16 D_800A54E8[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A54F4[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A5504[] = { 0x7612, 1, 0xFFFF };
u16 D_800A550C[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE08, 0, 0xFFFF };
u16 D_800A5520[] = { 0x7400, 1, 0xE08, 1, 0xFFFF };
u16 D_800A552C[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0x8012, 0,
    0xE08, 1, 0xFFFF,
};
u16 D_800A5544[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE08, 1,
    0x8012, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A5560[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE08, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A557C[] = { 0x7812, 1, 0xFFFF };
u16 D_800A5584[] = { 0, 0, 0xFFFF };
u16 D_800A558C[] = { 0, 1, 0xFFFF };
u16 D_800A5594[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A55A0[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A55B0[] = { 0x7612, 1, 0xFFFF };
u16 D_800A55B8[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE08, 0, 0xFFFF };
u16 D_800A55CC[] = { 0x7400, 1, 0xE08, 1, 0xFFFF };
u16 D_800A55D8[] = {
    0x8012, 0, 0, 1, 0x7201, 1, 0x7203, 1,
    0xE08, 1, 0xFFFF,
};
u16 D_800A55F0[] = {
    0xE08, 1, 0x8012, 1, 0x7205, 0, 0, 1,
    0x7201, 1, 0x7203, 1, 0xFFFF,
};
u16 D_800A560C[] = {
    0x8012, 1, 0x7205, 1, 0xE08, 1, 0, 1,
    0x7201, 1, 0x7203, 1, 0xFFFF,
};
u16 D_800A5628[] = { 0x7812, 1, 0xFFFF };
u16 D_800A5630[] = { 0x818E, 1, 0xFFFF };
u16 D_800A5638[] = { 0x900A, 1, 0xFFFF };
u16 D_800A5640[] = { 0x818E, 0, 0x818F, 0, 0xFFFF };
u16 D_800A564C[] = { 0x818E, 0, 0x818F, 1, 0x1C50, 0, 0xFFFF };
u16 D_800A565C[] = { 0x1C46, 1, 0x9009, 1, 0x1C50, 1, 0xFFFF };
u16 D_800A566C[] = { 0x818F, 1, 0x818E, 0, 0x1C50, 1, 0xFFFF };
u16 D_800A567C[] = { 0x905F, 1, 0xFFFF };
u16 D_800A5684[] = { 0, 0, 0xFFFF };
u16 D_800A568C[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5698[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A56A8[] = { 0x7612, 1, 0xFFFF };
u16 D_800A56B0[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE08, 0, 0xFFFF };
u16 D_800A56C4[] = { 0xE08, 1, 0xFFFF };
u16 D_800A56CC[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE08, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A56E4[] = {
    0, 1, 0x7203, 1, 0x8012, 1, 0x7201, 1,
    0xE08, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A5700[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE08, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A571C[] = { 0x7812, 1, 0xFFFF };
FieldTalk D_800A5724[] = {
    { D_800A53F8, D_800A5400, 0x5E },
    { D_800A5408, NULL, 0x63 },
    { D_800A5414, D_800A5424, 0x64 },
    { D_800A542C, D_800A5440, 0x65 },
    { D_800A544C, NULL, 0x66 },
    { D_800A5464, NULL, 0x67 },
    { D_800A5480, D_800A549C, 0x7A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5784[] = {
    { D_800A54A4, NULL, 0x5E },
    { D_800A54AC, D_800A54B8, 0x68 },
    { D_800A54C0, D_800A54CC, 0x69 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57B4[] = {
    { D_800A54D8, D_800A54E0, 0x5F },
    { D_800A54E8, NULL, 0x63 },
    { D_800A54F4, D_800A5504, 0x64 },
    { D_800A550C, D_800A5520, 0x65 },
    { D_800A552C, NULL, 0x66 },
    { D_800A5544, NULL, 0x67 },
    { D_800A5560, D_800A557C, 0x7A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5814[] = {
    { D_800A5584, D_800A558C, 0x60 },
    { D_800A5594, NULL, 0x63 },
    { D_800A55A0, D_800A55B0, 0x64 },
    { D_800A55B8, D_800A55CC, 0x65 },
    { D_800A55D8, NULL, 0x66 },
    { D_800A55F0, NULL, 0x67 },
    { D_800A560C, D_800A5628, 0x7A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5874[] = {
    { NULL, NULL, 0x276 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A588C[] = {
    { D_800A5630, D_800A5638, 0x32A },
    { D_800A5640, NULL, 0x2E3 },
    { D_800A564C, D_800A565C, 0x2E4 },
    { D_800A566C, NULL, 0x2E3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C8[] = {
    { NULL, D_800A567C, 0x2E5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58E0[] = {
    { D_800A5684, NULL, 0x61 },
    { D_800A568C, NULL, 0x61 },
    { D_800A5698, D_800A56A8, 0x61 },
    { D_800A56B0, D_800A56C4, 0x61 },
    { D_800A56CC, NULL, 0x61 },
    { D_800A56E4, NULL, 0x61 },
    { D_800A5700, D_800A571C, 0x61 },
    { NULL, NULL, 0 },
};
u16 D_800A5940[] = { 0x7003, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5950[] = { 0x7009, 1, 0x11, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5960[] = { 0x7004, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5970[] = { 0x6026, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A5980[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A5990[] = { 0x6006, 1, 0xFFFF };
u16 D_800A5998[] = { 0x7014, 1, 0xFFFF };
u16 D_800A59A0[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A59A8 = { D_800A5940, D_800A5724, 0x30, 4, 624, 152, 7 };
FieldActorEntry D_800A59BC = { D_800A5950, D_800A5784, 0x30, 4, 624, 152, 7 };
FieldActorEntry D_800A59D0 = { D_800A5960, D_800A57B4, 0x30, 4, 624, 152, 7 };
FieldActorEntry D_800A59E4 = { D_800A5970, D_800A5814, 0x30, 4, 624, 152, 7 };
FieldActorEntry D_800A59F8 = { D_800A5980, D_800A5874, 0x30, 4, 624, 152, 7 };
FieldActorEntry D_800A5A0C = { D_800A5990, D_800A588C, 0x3F, 5, 463, 328, 5 };
FieldActorEntry D_800A5A20 = { D_800A5998, D_800A58C8, 0x3F, 5, 463, 328, 5 };
FieldActorEntry D_800A5A34 = { D_800A59A0, D_800A58E0, 0x9D, 6, 624, 152, 7 };
FieldActorEntry *stageActors[] = {
    &D_800A59A8,
    &D_800A59BC,
    &D_800A59D0,
    &D_800A59E4,
    &D_800A59F8,
    &D_800A5A0C,
    &D_800A5A20,
    &D_800A5A34,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x80, 2, 0, 0, 0, 0, 0, 0, 218, 322, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 6, 0, 429, 308, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 674, 320, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 1, 0x34, 0x39, 4, 0, 776, 392, 0, 0 },
    { 1, 0, 0x80, 6, 1, 0, 0, 0, 0, 0, 219, 367, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x22A, 0xD0, 0x2FC, 7, 0, 0, 0 },
    { { { 0x6005, 1 }, { 0xFFFF, 0 } }, 8, 0x5A, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 90, D_800A4EA0, EVENT_TEXT(0x1D), NULL, func_800A4D4C },
    { 140, D_800A4F44, EVENT_TEXT(0x1E), NULL, NULL },
    { 142, D_800A5010, EVENT_TEXT(0x1F), NULL, NULL },
    { 143, D_800A50C0, EVENT_TEXT(0x20), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
