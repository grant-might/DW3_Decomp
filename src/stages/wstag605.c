#include "common.h"
#include "stage.h"

/* Creates the event object of story progress 17 */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        if (GAME.progress == 0x11 && FLAGS_00.checkCondition(0x40A6, 1)) {
            children[0] = FIELDSTG_startEvent(0x1FF);
        }
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

/* Sets flag 0x8680 and moves the story to 0x12 */
void func_800A4D88(void) {
    FLAGS_00.applyAction(0x8680, 1);
    GAME.progress = 0x12;
}

void func_800A4DBC(void) {
    FLAGS_00.applyAction(0x40A6, 1);
    FLAGS_00.applyAction(0x7400, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xF7
#define EVENT_TEXT_FILE 0x13C
#define STAGE_FILE 0x475
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xEF)
#define EVENT_TEXT_FILE 0x143
#define STAGE_FILE 0x485
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1E800, 0x14000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x39;
    D_800990B4.music = 0x60E40000;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = stageBattles;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

void func_800A4D88();
extern Battle D_800A5030;
extern Battle D_800A503C;
extern Battle D_800A5048;
extern Battle D_800A5054;
extern Battle D_800A5060;
extern Battle D_800A506C;
extern Battle D_800A5078;
extern Battle D_800A5084;
extern Battle D_800A50B4;
extern Battle D_800A50C0;
extern Battle D_800A50CC;
extern Battle D_800A50D8;
extern Battle D_800A50E4;
extern Battle D_800A50F0;
extern Battle D_800A50FC;
extern Battle D_800A5108;
extern Battle D_800A5138;
extern Battle D_800A5144;
extern Battle D_800A5150;
extern Battle D_800A515C;
extern Battle D_800A5168;
extern Battle D_800A5174;
extern Battle D_800A5180;
extern Battle D_800A518C;
extern Battle D_800A51BC;
extern Battle D_800A51C8;
extern Battle D_800A51D4;
extern Battle D_800A51E0;
extern Battle D_800A51EC;
extern Battle D_800A51F8;
extern Battle D_800A5204;
extern Battle D_800A5210;
extern BattleList D_800A5090;
extern BattleList D_800A5114;
extern BattleList D_800A5198;
extern BattleList D_800A521C;
extern u16 D_800A52CC[];
extern u16 D_800A52D4[];
extern u16 D_800A52E0[];
extern u16 D_800A52EC[];
extern u16 D_800A5400[];
extern FieldTalk D_800A52F8[];
extern u16 D_800A5408[];
extern FieldTalk D_800A5310[];
extern u16 D_800A5410[];
extern FieldTalk D_800A5328[];
extern u16 D_800A5418[];
extern FieldTalk D_800A5340[];
extern u16 D_800A5420[];
extern FieldTalk D_800A5358[];
extern u16 D_800A5428[];
extern FieldTalk D_800A5370[];
extern u16 D_800A5430[];
extern FieldTalk D_800A5388[];
extern u16 D_800A5438[];
extern FieldTalk D_800A53A0[];
extern u16 D_800A5440[];
extern FieldTalk D_800A53B8[];
extern u16 D_800A5448[];
extern FieldTalk D_800A53E8[];
extern FieldActorEntry D_800A5450;
extern FieldActorEntry D_800A5464;
extern FieldActorEntry D_800A5478;
extern FieldActorEntry D_800A548C;
extern FieldActorEntry D_800A54A0;
extern FieldActorEntry D_800A54B4;
extern FieldActorEntry D_800A54C8;
extern FieldActorEntry D_800A54DC;
extern FieldActorEntry D_800A54F0;
extern FieldActorEntry D_800A5504;
extern s16 D_800A4F1C[];
extern s16 D_800A4FA0[];

s16 D_800A4F1C[] = {
    0x102, 2, 0x271, 0xC9, 5,
    0x100, 0x96, 0x291, 0xB9,
    0x101, 0x96, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0x96, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 4, 0x96, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A4FA0[] = {
    0x100, 2, 0x271, 0xC9,
    0x101, 2, 1, 5,
    0x100, 0x96, 0x291, 0xB9,
    0x101, 0x96, 1, 1,
    0x300, 0x78,
    0x200, 0, 1, 0x96, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 3, 0x96, 2,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x102, 2, 0x258, 0xD5, 1,
    0x300, 6,
    0x304, 0x24D, 1, 1, 7,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x6004\n");
#endif
Battle D_800A5030 = { 80, 12, 0x60080000 };
Battle D_800A503C = { 80, 12, 0x60080000 };
Battle D_800A5048 = { 80, 12, 0x60080000 };
Battle D_800A5054 = { 80, 12, 0x60080000 };
Battle D_800A5060 = { 75, 12, 0x60080000 };
Battle D_800A506C = { 75, 12, 0x60080000 };
Battle D_800A5078 = { 75, 12, 0x60080000 };
Battle D_800A5084 = { 75, 12, 0x60080000 };
BattleList D_800A5090 = {
    3,
    { &D_800A5030, &D_800A503C, &D_800A5048, &D_800A5054,
      &D_800A5060, &D_800A506C, &D_800A5078, &D_800A5084 },
};
Battle D_800A50B4 = { 0, 0, 0x60040000 };
Battle D_800A50C0 = { 0, 0, 0x60040000 };
Battle D_800A50CC = { 0, 0, 0x60040000 };
Battle D_800A50D8 = { 0, 0, 0x60040000 };
Battle D_800A50E4 = { 0, 0, 0x60040000 };
Battle D_800A50F0 = { 0, 0, 0x60040000 };
Battle D_800A50FC = { 0, 0, 0x60040000 };
Battle D_800A5108 = { 0, 0, 0x60040000 };
BattleList D_800A5114 = {
    0,
    { &D_800A50B4, &D_800A50C0, &D_800A50CC, &D_800A50D8,
      &D_800A50E4, &D_800A50F0, &D_800A50FC, &D_800A5108 },
};
Battle D_800A5138 = { 0, 0, 0x60040000 };
Battle D_800A5144 = { 0, 0, 0x60040000 };
Battle D_800A5150 = { 0, 0, 0x60040000 };
Battle D_800A515C = { 0, 0, 0x60040000 };
Battle D_800A5168 = { 0, 0, 0x60040000 };
Battle D_800A5174 = { 0, 0, 0x60040000 };
Battle D_800A5180 = { 0, 0, 0x60040000 };
Battle D_800A518C = { 0, 0, 0x60040000 };
BattleList D_800A5198 = {
    0,
    { &D_800A5138, &D_800A5144, &D_800A5150, &D_800A515C,
      &D_800A5168, &D_800A5174, &D_800A5180, &D_800A518C },
};
Battle D_800A51BC = { 7, 19, 0x60880000 };
Battle D_800A51C8 = { 311, 19, 0x60880000 };
Battle D_800A51D4 = { 0, 0, 0x60040000 };
Battle D_800A51E0 = { 0, 0, 0x60040000 };
Battle D_800A51EC = { 0, 0, 0x60040000 };
Battle D_800A51F8 = { 0, 0, 0x60040000 };
Battle D_800A5204 = { 0, 0, 0x60040000 };
Battle D_800A5210 = { 0, 0, 0x60040000 };
BattleList D_800A521C = {
    0,
    { &D_800A51BC, &D_800A51C8, &D_800A51D4, &D_800A51E0,
      &D_800A51EC, &D_800A51F8, &D_800A5204, &D_800A5210 },
};
FieldBattles stageBattles[] = {
    { 46, 0, 0, { &D_800A5090, &D_800A5114, &D_800A5198, &D_800A521C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16A, 0x100, 0xA8, 0, 0x150, 0x1F9 },
};
u16 D_800A52CC[] = { 0x1C25, 0, 0xFFFF };
u16 D_800A52D4[] = { 0x1C25, 1, 0xA04, 0, 0xFFFF };
u16 D_800A52E0[] = { 0x905E, 1, 0xA04, 1, 0xFFFF };
u16 D_800A52EC[] = { 0x1C25, 1, 0xA04, 1, 0xFFFF };
FieldTalk D_800A52F8[] = {
    { NULL, NULL, 0x14C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5310[] = {
    { NULL, NULL, 0x154 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5328[] = {
    { NULL, NULL, 0x14F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5340[] = {
    { NULL, NULL, 0x150 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5358[] = {
    { NULL, NULL, 0x151 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5370[] = {
    { NULL, NULL, 0x152 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5388[] = {
    { NULL, NULL, 0x153 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53A0[] = {
    { NULL, NULL, 0x14D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53B8[] = {
    { D_800A52CC, NULL, 0x14E },
    { D_800A52D4, D_800A52E0, 0x2FA },
    { D_800A52EC, NULL, 0x2FC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53E8[] = {
    { NULL, NULL, 0x2FC },
    { NULL, NULL, 0 },
};
u16 D_800A5400[] = { 0x600F, 1, 0xFFFF };
u16 D_800A5408[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5410[] = { 0x7017, 1, 0xFFFF };
u16 D_800A5418[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5420[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5428[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5430[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5438[] = { 0x6010, 1, 0xFFFF };
u16 D_800A5440[] = { 0x6011, 1, 0xFFFF };
u16 D_800A5448[] = { 0x6012, 1, 0xFFFF };
FieldActorEntry D_800A5450 = { D_800A5400, D_800A52F8, 0x96, 4, 657, 185, 1 };
FieldActorEntry D_800A5464 = { D_800A5408, D_800A5310, 0x96, 4, 657, 185, 1 };
FieldActorEntry D_800A5478 = { D_800A5410, D_800A5328, 0x96, 4, 657, 185, 1 };
FieldActorEntry D_800A548C = { D_800A5418, D_800A5340, 0x96, 4, 657, 185, 1 };
FieldActorEntry D_800A54A0 = { D_800A5420, D_800A5358, 0x96, 4, 657, 185, 1 };
FieldActorEntry D_800A54B4 = { D_800A5428, D_800A5370, 0x96, 4, 657, 185, 1 };
FieldActorEntry D_800A54C8 = { D_800A5430, D_800A5388, 0x96, 4, 657, 185, 1 };
FieldActorEntry D_800A54DC = { D_800A5438, D_800A53A0, 0x96, 4, 657, 185, 1 };
FieldActorEntry D_800A54F0 = { D_800A5440, D_800A53B8, 0x96, 4, 657, 185, 1 };
FieldActorEntry D_800A5504 = { D_800A5448, D_800A53E8, 0x96, 4, 657, 185, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A5450,
    &D_800A5464,
    &D_800A5478,
    &D_800A548C,
    &D_800A54A0,
    &D_800A54B4,
    &D_800A54C8,
    &D_800A54DC,
    &D_800A54F0,
    &D_800A5504,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x3A, 2, 0, 5, 8, 0, 639, 174, 0, 0 },
    { 1, 0, 0x40, 2, 0x3C, 2, 0, 5, 8, 0, 671, 160, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 5, 6, 0, 782, 501, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 5, 6, 0, 800, 478, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 5, 6, 0, 576, 480, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 5, 6, 0, 609, 493, 0, 0 },
    { 1, 0, 0x40, 6, 0x36, 2, 0, 5, 6, 0, 646, 507, 0, 0 },
    { 1, 0, 0x40, 6, 0x37, 2, 0, 0xB, 8, 0, 587, 71, 0, 0 },
    { 1, 0, 0x40, 6, 0x38, 2, 0, 0xB, 8, 0, 573, 142, 0, 0 },
    { 1, 0, 0x40, 6, 0x39, 2, 0, 0xB, 8, 0, 705, 96, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 2, 0, 0xB, 8, 0, 692, 116, 0, 0 },
    { 1, 0, 0x40, 6, 0x3C, 2, 0, 5, 8, 0, 709, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 0xB, 8, 0, 743, 144, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 5, 6, 0, 710, 359, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 5, 6, 0, 758, 383, 0, 0 },
    { 1, 0, 0x40, 6, 0x3E, 2, 0, 5, 6, 0, 854, 431, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 5, 6, 0, 32, 447, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 5, 6, 0, 416, 255, 0, 0 },
    { 1, 0, 0x40, 6, 0x3F, 2, 0, 5, 6, 0, 463, 231, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24D, 0x110, 0x8C, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24D, 0x3A8, 0xE4, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x24D, 0x468, 0xFC, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 510, D_800A4F1C, EVENT_TEXT(0x13), NULL, func_800A4DBC },
    { 511, D_800A4FA0, EVENT_TEXT(0x14), NULL, func_800A4D88 },
    { -1, NULL, 0, NULL, NULL },
};
