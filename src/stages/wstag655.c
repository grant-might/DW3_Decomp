#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 16 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 0x10 && FLAGS_00.checkCondition(0x403E, 1)) {
            children[0] = FIELDSTG_startEvent(0x1AF);
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
    FLAGS_00.applyAction(0x403E, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

/* Event: sets the progress to 17 and applies action 0x800B */
void func_800A4DE0(void) {
    GAME.progress = 0x11;
    FLAGS_00.applyAction(0x800B, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xDB
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x487
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xD3)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x497
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE + 1;
    D_800990B4.start = (Vec2){0x7900, 0xD000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x16;
    D_800990B4.music = 0x60580000;
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
}

void func_800A4DE0();
extern Battle D_800A5190;
extern Battle D_800A519C;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A5214;
extern Battle D_800A5220;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5298;
extern Battle D_800A52A4;
extern Battle D_800A52B0;
extern Battle D_800A52BC;
extern Battle D_800A52C8;
extern Battle D_800A52D4;
extern Battle D_800A52E0;
extern Battle D_800A52EC;
extern Battle D_800A531C;
extern Battle D_800A5328;
extern Battle D_800A5334;
extern Battle D_800A5340;
extern Battle D_800A534C;
extern Battle D_800A5358;
extern Battle D_800A5364;
extern Battle D_800A5370;
extern BattleList D_800A51F0;
extern BattleList D_800A5274;
extern BattleList D_800A52F8;
extern BattleList D_800A537C;
extern u16 D_800A542C[];
extern u16 D_800A5434[];
extern u16 D_800A543C[];
extern u16 D_800A54C8[];
extern FieldTalk D_800A5444[];
extern u16 D_800A54D0[];
extern FieldTalk D_800A545C[];
extern u16 D_800A54D8[];
extern FieldTalk D_800A5474[];
extern u16 D_800A54E0[];
extern FieldTalk D_800A548C[];
extern u16 D_800A54E8[];
extern FieldTalk D_800A54B0[];
extern FieldActorEntry D_800A54F0;
extern FieldActorEntry D_800A5504;
extern FieldActorEntry D_800A5518;
extern FieldActorEntry D_800A552C;
extern FieldActorEntry D_800A5540;
extern s16 D_800A4F3C[];
extern s16 D_800A503C[];

s16 D_800A4F3C[] = {
    0x102, 2, 0x183, 0x77, 5,
    0x100, 0x7A, 0x1A3, 0x67,
    0x101, 0x7A, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x101, 0x323, 0x325, 0x7A,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x7A,
    0x300, 0x1E,
    0x200, 0, 2, 0x7A, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x7A, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 5, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 6, 0x7A, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 1,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A503C[] = {
    0x100, 2, 0x183, 0x77,
    0x101, 2, 1, 5,
    0x100, 0x7A, 0x1A3, 0x67,
    0x101, 0x7A, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x7A, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x7A, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 5, 0x7A, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 7, 0x7A, 2,
    0x301,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 9, 0x7A, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 8, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 0xA, 0x7A, 2,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x103, 0xB7, 1,
    0x300, 6,
    0x304, 0x25B, 0x126, 0x96, 1,
    0,
};
Battle D_800A5190 = { 0, 0, 0x60040000 };
Battle D_800A519C = { 0, 0, 0x60040000 };
Battle D_800A51A8 = { 0, 0, 0x60040000 };
Battle D_800A51B4 = { 0, 0, 0x60040000 };
Battle D_800A51C0 = { 0, 0, 0x60040000 };
Battle D_800A51CC = { 0, 0, 0x60040000 };
Battle D_800A51D8 = { 0, 0, 0x60040000 };
Battle D_800A51E4 = { 0, 0, 0x60040000 };
BattleList D_800A51F0 = {
    3,
    { &D_800A5190, &D_800A519C, &D_800A51A8, &D_800A51B4,
      &D_800A51C0, &D_800A51CC, &D_800A51D8, &D_800A51E4 },
};
Battle D_800A5214 = { 0, 0, 0x60040000 };
Battle D_800A5220 = { 0, 0, 0x60040000 };
Battle D_800A522C = { 0, 0, 0x60040000 };
Battle D_800A5238 = { 0, 0, 0x60040000 };
Battle D_800A5244 = { 0, 0, 0x60040000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
BattleList D_800A5274 = {
    0,
    { &D_800A5214, &D_800A5220, &D_800A522C, &D_800A5238,
      &D_800A5244, &D_800A5250, &D_800A525C, &D_800A5268 },
};
Battle D_800A5298 = { 0, 0, 0x60040000 };
Battle D_800A52A4 = { 0, 0, 0x60040000 };
Battle D_800A52B0 = { 0, 0, 0x60040000 };
Battle D_800A52BC = { 0, 0, 0x60040000 };
Battle D_800A52C8 = { 0, 0, 0x60040000 };
Battle D_800A52D4 = { 0, 0, 0x60040000 };
Battle D_800A52E0 = { 0, 0, 0x60040000 };
Battle D_800A52EC = { 0, 0, 0x60040000 };
BattleList D_800A52F8 = {
    0,
    { &D_800A5298, &D_800A52A4, &D_800A52B0, &D_800A52BC,
      &D_800A52C8, &D_800A52D4, &D_800A52E0, &D_800A52EC },
};
Battle D_800A531C = { 6, 18, 0x608C0000 };
Battle D_800A5328 = { 0, 0, 0x60040000 };
Battle D_800A5334 = { 0, 0, 0x60040000 };
Battle D_800A5340 = { 0, 0, 0x60040000 };
Battle D_800A534C = { 0, 0, 0x60040000 };
Battle D_800A5358 = { 0, 0, 0x60040000 };
Battle D_800A5364 = { 0, 0, 0x60040000 };
Battle D_800A5370 = { 0, 0, 0x60040000 };
BattleList D_800A537C = {
    0,
    { &D_800A531C, &D_800A5328, &D_800A5334, &D_800A5340,
      &D_800A534C, &D_800A5358, &D_800A5364, &D_800A5370 },
};
FieldBattles stageBattles[] = {
    { 166, 0, 0, { &D_800A51F0, &D_800A5274, &D_800A52F8, &D_800A537C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16C, 0x100, 0xB0, 0, 0x150, 0x1FF },
};
u16 D_800A542C[] = { 0x800B, 0, 0xFFFF };
u16 D_800A5434[] = { 0x9044, 1, 0xFFFF };
u16 D_800A543C[] = { 0x800B, 1, 0xFFFF };
FieldTalk D_800A5444[] = {
    { NULL, NULL, 0x19 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A545C[] = {
    { NULL, NULL, 0x162 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5474[] = {
    { NULL, NULL, 0x164 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A548C[] = {
    { D_800A542C, D_800A5434, 0x163 },
    { D_800A543C, NULL, 0x308 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54B0[] = {
    { NULL, NULL, 0x162 },
    { NULL, NULL, 0 },
};
u16 D_800A54C8[] = { 0x600F, 1, 0xFFFF };
u16 D_800A54D0[] = { 0x6011, 1, 0xFFFF };
u16 D_800A54D8[] = { 0x7017, 1, 0xFFFF };
u16 D_800A54E0[] = { 0x6010, 1, 0xFFFF };
u16 D_800A54E8[] = { 0x6012, 1, 0xFFFF };
FieldActorEntry D_800A54F0 = { D_800A54C8, D_800A5444, 0x7A, 4, 419, 103, 1 };
FieldActorEntry D_800A5504 = { D_800A54D0, D_800A545C, 0x7A, 4, 419, 103, 1 };
FieldActorEntry D_800A5518 = { D_800A54D8, D_800A5474, 0x7A, 4, 419, 103, 1 };
FieldActorEntry D_800A552C = { D_800A54E0, D_800A548C, 0x7A, 4, 419, 103, 1 };
FieldActorEntry D_800A5540 = { D_800A54E8, D_800A54B0, 0x7A, 4, 419, 103, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A54F0,
    &D_800A5504,
    &D_800A5518,
    &D_800A552C,
    &D_800A5540,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0xFF, 6, 0x32, 2, 0, 2, 0xC, 0, 318, 266, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x25B, 0x126, 0x96, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0xEE, 0x138, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0xDC, 0x1A0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 430, D_800A4F3C, EVENT_TEXT(0x11), NULL, func_800A4D94 },
    { 431, D_800A503C, EVENT_TEXT(0x12), NULL, func_800A4DE0 },
    { -1, NULL, 0, NULL, NULL },
};
