#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 15 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0xF && FLAGS_00.checkCondition(0x401E, 1)) {
            children[0] = FIELDSTG_startEvent(0x19B);
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

void func_800A4D94(void) {
    FLAGS_00.applyAction(0x4017, 1);
}

void func_800A4DC0(void) {
    FLAGS_00.applyAction(0x401A, 1);
}

/* Event: applies actions 0x401E, 0x1C26 and 0x7400 */
void func_800A4DEC(void) {
    FLAGS_00.applyAction(0x401E, 1);
    FLAGS_00.applyAction(0x1C26, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x4A0
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x4B0
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x17000, 0x1E000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x3D;
    D_800990B4.music = 0x60F40000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress >= 0xF && GAME.progress < 0x18) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

void func_800A4DEC();
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
extern Battle D_800A534C;
extern Battle D_800A5358;
extern Battle D_800A5364;
extern Battle D_800A5370;
extern Battle D_800A537C;
extern Battle D_800A5388;
extern Battle D_800A5394;
extern Battle D_800A53A0;
extern BattleList D_800A5220;
extern BattleList D_800A52A4;
extern BattleList D_800A5328;
extern BattleList D_800A53AC;
extern u16 D_800A558C[];
extern u16 D_800A55A0[];
extern u16 D_800A55A8[];
extern u16 D_800A55BC[];
extern u16 D_800A55C4[];
extern u16 D_800A55CC[];
extern u16 D_800A55D8[];
extern u16 D_800A55E0[];
extern u16 D_800A55E8[];
extern u16 D_800A55F0[];
extern u16 D_800A55F8[];
extern u16 D_800A5604[];
extern u16 D_800A560C[];
extern u16 D_800A5614[];
extern u16 D_800A561C[];
extern u16 D_800A5624[];
extern u16 D_800A562C[];
extern u16 D_800A5634[];
extern u16 D_800A5AB0[];
extern FieldTalk D_800A563C[];
extern u16 D_800A5AB8[];
extern FieldTalk D_800A5654[];
extern u16 D_800A5AC0[];
extern FieldTalk D_800A566C[];
extern u16 D_800A5AC8[];
extern FieldTalk D_800A5684[];
extern u16 D_800A5AD0[];
extern FieldTalk D_800A569C[];
extern u16 D_800A5AD8[];
extern FieldTalk D_800A56B4[];
extern u16 D_800A5AE0[];
extern FieldTalk D_800A56CC[];
extern u16 D_800A5AE8[];
extern FieldTalk D_800A56E4[];
extern u16 D_800A5AF0[];
extern FieldTalk D_800A56FC[];
extern u16 D_800A5AF8[];
extern FieldTalk D_800A5714[];
extern u16 D_800A5B00[];
extern FieldTalk D_800A572C[];
extern u16 D_800A5B08[];
extern FieldTalk D_800A5744[];
extern u16 D_800A5B10[];
extern FieldTalk D_800A575C[];
extern u16 D_800A5B18[];
extern FieldTalk D_800A5774[];
extern u16 D_800A5B20[];
extern FieldTalk D_800A578C[];
extern u16 D_800A5B28[];
extern FieldTalk D_800A57A4[];
extern u16 D_800A5B30[];
extern FieldTalk D_800A57BC[];
extern u16 D_800A5B38[];
extern FieldTalk D_800A57D4[];
extern u16 D_800A5B40[];
extern FieldTalk D_800A57EC[];
extern u16 D_800A5B48[];
extern FieldTalk D_800A5804[];
extern u16 D_800A5B50[];
extern FieldTalk D_800A581C[];
extern u16 D_800A5B5C[];
extern FieldTalk D_800A5834[];
extern u16 D_800A5B68[];
extern FieldTalk D_800A584C[];
extern u16 D_800A5B70[];
extern FieldTalk D_800A5864[];
extern u16 D_800A5B78[];
extern FieldTalk D_800A587C[];
extern u16 D_800A5B80[];
extern FieldTalk D_800A5894[];
extern u16 D_800A5B88[];
extern FieldTalk D_800A58AC[];
extern u16 D_800A5B90[];
extern FieldTalk D_800A58C4[];
extern u16 D_800A5B98[];
extern FieldTalk D_800A58DC[];
extern u16 D_800A5BA0[];
extern FieldTalk D_800A58F4[];
extern u16 D_800A5BA8[];
extern FieldTalk D_800A590C[];
extern u16 D_800A5BB0[];
extern FieldTalk D_800A5924[];
extern u16 D_800A5BB8[];
extern FieldTalk D_800A593C[];
extern u16 D_800A5BC0[];
extern u16 D_800A5BC8[];
extern FieldTalk D_800A5984[];
extern u16 D_800A5BD0[];
extern FieldTalk D_800A599C[];
extern u16 D_800A5BD8[];
extern FieldTalk D_800A59B4[];
extern u16 D_800A5BE0[];
extern FieldTalk D_800A59CC[];
extern u16 D_800A5BE8[];
extern FieldTalk D_800A59E4[];
extern u16 D_800A5BF0[];
extern FieldTalk D_800A59FC[];
extern u16 D_800A5BFC[];
extern FieldTalk D_800A5A50[];
extern u16 D_800A5C08[];
extern FieldTalk D_800A5A68[];
extern u16 D_800A5C10[];
extern FieldTalk D_800A5A80[];
extern u16 D_800A5C1C[];
extern FieldTalk D_800A5A98[];
extern FieldActorEntry D_800A5C28;
extern FieldActorEntry D_800A5C3C;
extern FieldActorEntry D_800A5C50;
extern FieldActorEntry D_800A5C64;
extern FieldActorEntry D_800A5C78;
extern FieldActorEntry D_800A5C8C;
extern FieldActorEntry D_800A5CA0;
extern FieldActorEntry D_800A5CB4;
extern FieldActorEntry D_800A5CC8;
extern FieldActorEntry D_800A5CDC;
extern FieldActorEntry D_800A5CF0;
extern FieldActorEntry D_800A5D04;
extern FieldActorEntry D_800A5D18;
extern FieldActorEntry D_800A5D2C;
extern FieldActorEntry D_800A5D40;
extern FieldActorEntry D_800A5D54;
extern FieldActorEntry D_800A5D68;
extern FieldActorEntry D_800A5D7C;
extern FieldActorEntry D_800A5D90;
extern FieldActorEntry D_800A5DA4;
extern FieldActorEntry D_800A5DB8;
extern FieldActorEntry D_800A5DCC;
extern FieldActorEntry D_800A5DE0;
extern FieldActorEntry D_800A5DF4;
extern FieldActorEntry D_800A5E08;
extern FieldActorEntry D_800A5E1C;
extern FieldActorEntry D_800A5E30;
extern FieldActorEntry D_800A5E44;
extern FieldActorEntry D_800A5E58;
extern FieldActorEntry D_800A5E6C;
extern FieldActorEntry D_800A5E80;
extern FieldActorEntry D_800A5E94;
extern FieldActorEntry D_800A5EA8;
extern FieldActorEntry D_800A5EBC;
extern FieldActorEntry D_800A5ED0;
extern FieldActorEntry D_800A5EE4;
extern FieldActorEntry D_800A5EF8;
extern FieldActorEntry D_800A5F0C;
extern FieldActorEntry D_800A5F20;
extern FieldActorEntry D_800A5F34;
extern FieldActorEntry D_800A5F48;
extern FieldActorEntry D_800A5F5C;
extern FieldActorEntry D_800A5F70;
extern FieldActorEntry D_800A5F84;
extern s16 D_800A4F94[];
extern s16 D_800A4FF4[];
extern s16 D_800A5058[];
extern s16 D_800A50F8[];

s16 D_800A4F94[] = {
    0x102, 2, 0x1E9, 0x16D, 5,
    0x100, 0x133, 0x1F9, 0x165,
    0x101, 0x133, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 0x133, 2,
    0x301,
    0x300, 0x1E,
    0x102, 0x133, 0x219, 0x175, 7,
    0x302, 0x133,
    0x101, 0x133, 1, 3,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0xA622\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x1F9\n");
#endif
s16 D_800A4FF4[] = {
    0x600, 0, 2,
    0x102, 2, 0x27F, 0x141, 7,
    0x100, 0x4A, 0x29F, 0x151,
    0x101, 0x4A, 1, 3,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x200, 0, 1, 0x4A, 1,
    0x301,
    0x300, 0x1E,
    0x102, 0x4A, 0x2BF, 0x161, 7,
    0x302, 0x4A,
    0x101, 0x4A, 1, 3,
    0x300, 0x1E,
    0,
};
s16 D_800A5058[] = {
    0x600, 1, 2,
    0x102, 2, 0x181, 0xBA, 3,
    0x100, 0x98, 0x161, 0xAA,
    0x101, 0x98, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 6,
    0x300, 0x1E,
    0x200, 0, 1, 0x98, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x98, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
s16 D_800A50F8[] = {
    0x600, 1, 2,
    0x100, 2, 0x181, 0xBA,
    0x101, 2, 1, 3,
    0x100, 0x98, 0x161, 0xAA,
    0x101, 0x98, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0x98, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0x98, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 3,
    0x101, 2, 7, 3,
    0x301,
    0x300, 0x1E,
    0x102, 0x98, 0x181, 0x9A, 1,
    0x302, 0x98,
    0x101, 0x98, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x141, 0x9A, 3,
    0x302, 2,
    0x600, 1, 2,
    0x102, 2, 0x101, 0x7A, 3,
    0x304, 0x25F, 0x64, 0x64, 0,
    0,
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
Battle D_800A52C8 = { 0, 0, 0x60040000 };
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
Battle D_800A534C = { 5, 18, 0x608C0000 };
Battle D_800A5358 = { 303, 18, 0x608C0000 };
Battle D_800A5364 = { 0, 0, 0x60040000 };
Battle D_800A5370 = { 0, 0, 0x60040000 };
Battle D_800A537C = { 0, 0, 0x60040000 };
Battle D_800A5388 = { 0, 0, 0x60040000 };
Battle D_800A5394 = { 0, 0, 0x60040000 };
Battle D_800A53A0 = { 0, 0, 0x60040000 };
BattleList D_800A53AC = {
    0,
    { &D_800A534C, &D_800A5358, &D_800A5364, &D_800A5370,
      &D_800A537C, &D_800A5388, &D_800A5394, &D_800A53A0 },
};
FieldBattles stageBattles[] = {
    { 139, 0, 0, { &D_800A5220, &D_800A52A4, &D_800A5328, &D_800A53AC } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x19C, 0x128, 0x170, 0x28, 0x160, 0x1FE },
    { 0x180, 0x100, 0x18A, 0x128, 0x128, 0x28, 0x170, 0x1FE },
    { 0x180, 0x100, 0x1A4, 0x128, 0x190, 0x28, 0x140, 0x1FD },
    { 0x180, 0x100, 0x1AC, 0x128, 0x1B0, 0x28, 0x150, 0x1FD },
    { 0x180, 0x100, 0x1B4, 0x128, 0x1D0, 0x28, 0x160, 0x1FD },
    { 0x180, 0x100, 0x192, 0x148, 0x148, 0x48, 0x170, 0x1FD },
    { 0x180, 0x100, 0x180, 0x150, 0x100, 0x50, 0x140, 0x1FC },
    { 0x180, 0x100, 0x19A, 0x150, 0x168, 0x50, 0x150, 0x1FC },
    { 0x180, 0x100, 0x1AA, 0x150, 0x1A8, 0x50, 0x170, 0x1FC },
    { 0x180, 0x100, 0x1B2, 0x150, 0x1C8, 0x50, 0x140, 0x1FB },
    { 0x180, 0x100, 0x188, 0x158, 0x120, 0x58, 0x150, 0x1FB },
    { 0x180, 0x100, 0x190, 0x170, 0x140, 0x70, 0x160, 0x1FB },
    { 0x140, 0x100, 0x158, 0x186, 0x60, 0x86, 0x170, 0x1FB },
    { 0x180, 0x100, 0x1A0, 0x178, 0x180, 0x78, 0x140, 0x1FA },
    { 0x180, 0x100, 0x1A8, 0x178, 0x1A0, 0x78, 0x150, 0x1FA },
    { 0x180, 0x100, 0x188, 0x180, 0x120, 0x80, 0x160, 0x1FA },
    { 0x180, 0x100, 0x1B0, 0x180, 0x1C0, 0x80, 0x170, 0x1FA },
    { 0x140, 0x100, 0x16E, 0x1A0, 0xB8, 0xA0, 0x140, 0x1F9 },
    { 0x180, 0x100, 0x180, 0x178, 0x100, 0x78, 0x150, 0x1F9 },
    { 0x180, 0x100, 0x198, 0x178, 0x160, 0x78, 0x160, 0x1F9 },
};
u16 D_800A558C[] = { 0x7020, 1, 0x6020, 0, 0x6021, 0, 5, 0, 0xFFFF };
u16 D_800A55A0[] = { 5, 1, 0xFFFF };
u16 D_800A55A8[] = { 0x7020, 1, 0x6020, 0, 0x6021, 0, 5, 1, 0xFFFF };
u16 D_800A55BC[] = { 0x6020, 1, 0xFFFF };
u16 D_800A55C4[] = { 0x6021, 1, 0xFFFF };
u16 D_800A55CC[] = { 0x7019, 1, 0x7020, 0, 0xFFFF };
u16 D_800A55D8[] = { 0x7018, 1, 0xFFFF };
u16 D_800A55E0[] = { 0x7A3F, 1, 0xFFFF };
u16 D_800A55E8[] = { 0x7020, 1, 0xFFFF };
u16 D_800A55F0[] = { 0x7A40, 1, 0xFFFF };
u16 D_800A55F8[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A5604[] = { 0x7A40, 1, 0xFFFF };
u16 D_800A560C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5614[] = { 0x7A41, 1, 0xFFFF };
u16 D_800A561C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5624[] = { 0x7A41, 1, 0xFFFF };
u16 D_800A562C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5634[] = { 0x7A41, 1, 0xFFFF };
FieldTalk D_800A563C[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5654[] = {
    { NULL, NULL, 0xCF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A566C[] = {
    { NULL, NULL, 0xC5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5684[] = {
    { NULL, NULL, 0xC0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A569C[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56B4[] = {
    { NULL, NULL, 0xC1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56CC[] = {
    { NULL, NULL, 0xC6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56E4[] = {
    { NULL, NULL, 0xD0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56FC[] = {
    { NULL, NULL, 0xBD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5714[] = {
    { NULL, NULL, 0xD1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A572C[] = {
    { NULL, NULL, 0xC7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5744[] = {
    { NULL, NULL, 0xC2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A575C[] = {
    { NULL, NULL, 0xBE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5774[] = {
    { NULL, NULL, 0xD2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A578C[] = {
    { NULL, NULL, 0xC3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57A4[] = {
    { NULL, NULL, 0xC8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57BC[] = {
    { NULL, NULL, 0x157 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57D4[] = {
    { NULL, NULL, 0x158 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57EC[] = {
    { NULL, NULL, 0xB7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5804[] = {
    { NULL, NULL, 0x15A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A581C[] = {
    { NULL, NULL, 0x156 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5834[] = {
    { NULL, NULL, 0x156 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A584C[] = {
    { NULL, NULL, 0x16E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5864[] = {
    { NULL, NULL, 0x16E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A587C[] = {
    { NULL, NULL, 0x16E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5894[] = {
    { NULL, NULL, 0x16E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58AC[] = {
    { NULL, NULL, 0x16E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58C4[] = {
    { NULL, NULL, 0x16E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58DC[] = {
    { NULL, NULL, 0x16E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58F4[] = {
    { NULL, NULL, 0xBA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A590C[] = {
    { NULL, NULL, 0xCE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5924[] = {
    { NULL, NULL, 0xC4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A593C[] = {
    { D_800A558C, D_800A55A0, 0xBF },
    { D_800A55A8, NULL, 7 },
    { D_800A55BC, NULL, 0xBF },
    { D_800A55C4, NULL, 0xBF },
    { D_800A55CC, NULL, 0xBF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5984[] = {
    { NULL, NULL, 0xC9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A599C[] = {
    { NULL, NULL, 0xCB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59B4[] = {
    { NULL, NULL, 0xCC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59CC[] = {
    { NULL, NULL, 0xCD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59E4[] = {
    { NULL, NULL, 0xCA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59FC[] = {
    { D_800A55D8, D_800A55E0, 1 },
    { D_800A55E8, D_800A55F0, 1 },
    { D_800A55F8, D_800A5604, 1 },
    { D_800A560C, D_800A5614, 1 },
    { D_800A561C, D_800A5624, 1 },
    { D_800A562C, D_800A5634, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A50[] = {
    { NULL, NULL, 0x174 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A68[] = {
    { NULL, NULL, 0x15B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A80[] = {
    { NULL, NULL, 0x159 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A98[] = {
    { NULL, NULL, 0x159 },
    { NULL, NULL, 0 },
};
u16 D_800A5AB0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5AB8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5AC0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5AC8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5AD0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5AD8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5AE0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5AE8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5AF0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5AF8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5B00[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5B08[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5B10[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5B18[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5B20[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5B28[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5B30[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5B38[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5B40[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5B48[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5B50[] = { 0x600F, 1, 0x401A, 0, 0xFFFF };
u16 D_800A5B5C[] = { 0x600F, 1, 0x401A, 1, 0xFFFF };
u16 D_800A5B68[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5B70[] = { 0x601B, 1, 0xFFFF };
u16 D_800A5B78[] = { 0x601C, 1, 0xFFFF };
u16 D_800A5B80[] = { 0x601D, 1, 0xFFFF };
u16 D_800A5B88[] = { 0x601E, 1, 0xFFFF };
u16 D_800A5B90[] = { 0x601F, 1, 0xFFFF };
u16 D_800A5B98[] = { 0x6020, 1, 0xFFFF };
u16 D_800A5BA0[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5BA8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5BB0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5BB8[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5BC0[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5BC8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5BD0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5BD8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5BE0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5BE8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5BF0[] = { 0x7008, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5BFC[] = { 0x7008, 1, 0x8192, 0, 0xFFFF };
u16 D_800A5C08[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5C10[] = { 0x600F, 1, 0x4017, 0, 0xFFFF };
u16 D_800A5C1C[] = { 0x600F, 1, 0x4017, 1, 0xFFFF };
FieldActorEntry D_800A5C28 = { D_800A5AB0, D_800A563C, 0x20, 4, 296, 445, 7 };
FieldActorEntry D_800A5C3C = { D_800A5AB8, D_800A5654, 0x20, 4, 344, 446, 1 };
FieldActorEntry D_800A5C50 = { D_800A5AC0, D_800A566C, 0x20, 4, 296, 445, 7 };
FieldActorEntry D_800A5C64 = { D_800A5AC8, D_800A5684, 0x20, 4, 296, 445, 7 };
FieldActorEntry D_800A5C78 = { D_800A5AD0, D_800A569C, 0x25, 5, 345, 470, 3 };
FieldActorEntry D_800A5C8C = { D_800A5AD8, D_800A56B4, 0x25, 5, 345, 470, 3 };
FieldActorEntry D_800A5CA0 = { D_800A5AE0, D_800A56CC, 0x25, 5, 345, 470, 3 };
FieldActorEntry D_800A5CB4 = { D_800A5AE8, D_800A56E4, 0x25, 5, 345, 470, 3 };
FieldActorEntry D_800A5CC8 = { D_800A5AF0, D_800A56FC, 0x2F, 6, 297, 470, 5 };
FieldActorEntry D_800A5CDC = { D_800A5AF8, D_800A5714, 0x2F, 6, 384, 152, 7 };
FieldActorEntry D_800A5CF0 = { D_800A5B00, D_800A572C, 0x2F, 6, 297, 470, 5 };
FieldActorEntry D_800A5D04 = { D_800A5B08, D_800A5744, 0x2F, 6, 297, 470, 5 };
FieldActorEntry D_800A5D18 = { D_800A5B10, D_800A575C, 0x30, 7, 344, 446, 1 };
FieldActorEntry D_800A5D2C = { D_800A5B18, D_800A5774, 0x30, 7, 296, 445, 7 };
FieldActorEntry D_800A5D40 = { D_800A5B20, D_800A578C, 0x30, 7, 344, 446, 1 };
FieldActorEntry D_800A5D54 = { D_800A5B28, D_800A57A4, 0x30, 7, 344, 446, 1 };
FieldActorEntry D_800A5D68 = { D_800A5B30, D_800A57BC, 0x45, 8, 345, 470, 3 };
FieldActorEntry D_800A5D7C = { D_800A5B38, D_800A57D4, 0x46, 9, 297, 470, 5 };
FieldActorEntry D_800A5D90 = { D_800A5B40, D_800A57EC, 0x47, 0xA, 296, 445, 7 };
FieldActorEntry D_800A5DA4 = { D_800A5B48, D_800A5804, 0x48, 0xB, 344, 446, 1 };
FieldActorEntry D_800A5DB8 = { D_800A5B50, D_800A581C, 0x4A, 0xC, 671, 337, 3 };
FieldActorEntry D_800A5DCC = { D_800A5B5C, D_800A5834, 0x4A, 0xC, 703, 353, 3 };
FieldActorEntry D_800A5DE0 = { D_800A5B68, D_800A584C, 0x66, 0xD, 408, 484, 3 };
FieldActorEntry D_800A5DF4 = { D_800A5B70, D_800A5864, 0x66, 0xD, 408, 484, 3 };
FieldActorEntry D_800A5E08 = { D_800A5B78, D_800A587C, 0x66, 0xD, 408, 484, 3 };
FieldActorEntry D_800A5E1C = { D_800A5B80, D_800A5894, 0x66, 0xD, 408, 484, 3 };
FieldActorEntry D_800A5E30 = { D_800A5B88, D_800A58AC, 0x66, 0xD, 408, 484, 3 };
FieldActorEntry D_800A5E44 = { D_800A5B90, D_800A58C4, 0x66, 0xD, 408, 484, 3 };
FieldActorEntry D_800A5E58 = { D_800A5B98, D_800A58DC, 0x66, 0xD, 408, 484, 3 };
FieldActorEntry D_800A5E6C = { D_800A5BA0, D_800A58F4, 0x7A, 0xE, 320, 154, 7 };
FieldActorEntry D_800A5E80 = { D_800A5BA8, D_800A590C, 0x7A, 0xE, 320, 154, 7 };
FieldActorEntry D_800A5E94 = { D_800A5BB0, D_800A5924, 0x7A, 0xE, 320, 154, 7 };
FieldActorEntry D_800A5EA8 = { D_800A5BB8, D_800A593C, 0x7A, 0xE, 320, 154, 7 };
FieldActorEntry D_800A5EBC = { D_800A5BC0, NULL, 0x98, 0xF, 353, 170, 7 };
FieldActorEntry D_800A5ED0 = { D_800A5BC8, D_800A5984, 0x9D, 0x10, 320, 154, 7 };
FieldActorEntry D_800A5EE4 = { D_800A5BD0, D_800A599C, 0x9E, 0x11, 345, 470, 3 };
FieldActorEntry D_800A5EF8 = { D_800A5BD8, D_800A59B4, 0x9F, 0x12, 297, 470, 5 };
FieldActorEntry D_800A5F0C = { D_800A5BE0, D_800A59CC, 0xA0, 0x13, 344, 446, 1 };
FieldActorEntry D_800A5F20 = { D_800A5BE8, D_800A59E4, 0xA1, 0x14, 296, 445, 7 };
FieldActorEntry D_800A5F34 = { D_800A5BF0, D_800A59FC, 0xCE, 0x15, 509, 563, 3 };
FieldActorEntry D_800A5F48 = { D_800A5BFC, D_800A5A50, 0xCE, 0x15, 509, 563, 3 };
FieldActorEntry D_800A5F5C = { D_800A5C08, D_800A5A68, 0x132, 0x16, 544, 504, 1 };
FieldActorEntry D_800A5F70 = { D_800A5C10, D_800A5A80, 0x133, 0x17, 505, 357, 1 };
FieldActorEntry D_800A5F84 = { D_800A5C1C, D_800A5A98, 0x133, 0x17, 537, 373, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A5C28,
    &D_800A5C3C,
    &D_800A5C50,
    &D_800A5C64,
    &D_800A5C78,
    &D_800A5C8C,
    &D_800A5CA0,
    &D_800A5CB4,
    &D_800A5CC8,
    &D_800A5CDC,
    &D_800A5CF0,
    &D_800A5D04,
    &D_800A5D18,
    &D_800A5D2C,
    &D_800A5D40,
    &D_800A5D54,
    &D_800A5D68,
    &D_800A5D7C,
    &D_800A5D90,
    &D_800A5DA4,
    &D_800A5DB8,
    &D_800A5DCC,
    &D_800A5DE0,
    &D_800A5DF4,
    &D_800A5E08,
    &D_800A5E1C,
    &D_800A5E30,
    &D_800A5E44,
    &D_800A5E58,
    &D_800A5E6C,
    &D_800A5E80,
    &D_800A5E94,
    &D_800A5EA8,
    &D_800A5EBC,
    &D_800A5ED0,
    &D_800A5EE4,
    &D_800A5EF8,
    &D_800A5F0C,
    &D_800A5F20,
    &D_800A5F34,
    &D_800A5F48,
    &D_800A5F5C,
    &D_800A5F70,
    &D_800A5F84,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x50, 2, 0x2F, 0, 0, 0, 0, 0, 718, 505, 0, 0 },
    { 1, 0, 0x50, 2, 0x2F, 0, 0, 0, 0, 0, 815, 456, 0, 0 },
    { 1, 0, 0x40, 2, 0x30, 2, 0, 1, 0xA, 0, 625, 376, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x35, 0xA, 0, 719, 451, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 1, 0x32, 0x35, 0xA, 0, 815, 343, 0, 0 },
    { 1, 0, 0x40, 2, 0x3E, 1, 0x3E, 0x47, 6, 0, 637, 147, 0, 0 },
    { 1, 0, 0x40, 2, 0x48, 1, 0x48, 0x51, 6, 0, 769, 352, 0, 0 },
    { 1, 0, 0x50, 6, 0x2E, 0, 0, 0, 0, 0, 182, 516, 0, 0 },
    { 1, 0, 0x40, 6, 0x30, 2, 0, 1, 0xA, 0, 157, 372, 0, 0 },
    { 1, 0, 0x40, 6, 0x30, 2, 0, 1, 0xA, 0, 213, 344, 0, 0 },
    { 1, 0, 0x40, 6, 0x30, 2, 0, 1, 0xA, 0, 221, 194, 0, 0 },
    { 1, 0, 0x40, 6, 0x30, 2, 0, 1, 0xA, 0, 549, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x30, 2, 0, 1, 0xA, 0, 742, 201, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x35, 0xA, 0, 182, 460, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 1, 0x36, 0x39, 8, 0, 91, 349, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 1, 0x3A, 0x3D, 8, 0, 447, 275, 0, 0 },
    { 1, 0, 0x40, 6, 0x52, 1, 0x52, 0x5B, 6, 0, 487, 434, 0, 0 },
    { 1, 0, 0x40, 6, 0x5C, 1, 0x5C, 0x5F, 0xA, 0, 661, 151, 0, 0 },
    { 1, 0, 0x40, 6, 0x5C, 1, 0x5C, 0x5F, 0xA, 0, 780, 357, 0, 0 },
    { 1, 0, 0x40, 6, 0x60, 1, 0x60, 0x63, 0xA, 0, 504, 449, 0, 0 },
    { 1, 0, 0x40, 6, 3, 0, 0, 0, 0, 0, 285, 98, 0, 0 },
    { 1, 0, 0x58, 4, 0, 0, 0, 0, 0, 0, 249, 99, 171, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 287, 425, 455, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 511, 525, 552, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 4, 5, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x25D, 0x46C, 0xAA, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x260, 0xA8, 0xA4, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x2C0, 0x100, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x2B0, 0x148, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x210, 0x118, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x200, 0x160, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x1C0, 0x180, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x1B0, 0x1C8, 0, 0, 0, 0 },
    { { { 0x600F, 1 }, { 0x4017, 0 } }, 8, 0x186, 0, 0, 0, 0, 0, 0 },
    { { { 0x600F, 1 }, { 0x401A, 0 } }, 8, 0x190, 0, 0, 0, 0, 0, 0 },
    { { { 0x600F, 1 }, { 0x401E, 0 } }, 8, 0x19A, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 390, D_800A4F94, EVENT_TEXT(0xC), NULL, func_800A4D94 },
    { 400, D_800A4FF4, EVENT_TEXT(0xD), NULL, func_800A4DC0 },
    { 410, D_800A5058, EVENT_TEXT(0), NULL, func_800A4DEC },
    { 411, D_800A50F8, EVENT_TEXT(1), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
