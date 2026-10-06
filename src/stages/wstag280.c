#include "common.h"
#define STAGE_TWEEN /* stageFuncs is a StageFuncs (stage.h) */
#include "stage.h"
void func_800A4CD4();

/* The text file of the menus, which the versions number differently */
#if VERSION_US
#define MENU_TEXT 0x10C
#elif VERSION_EU
#define MENU_TEXT 0x112
#endif

/* A two-option menu: creates the event object of the chosen option */
void func_800A4CD4(StageMenu *task, StageMenuChildren *children) {
    SpriteDrawer drawer;
    s32 prev;
    s32 i;
    s32 j;
    s32 k;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->tween.duration = 10;
        for (i = 0; i < 2; i++) {
            children->options[i] = createTextWindow(0x1002, 1, 0x1C, 0xBE + i * 14);
            children->options[i]->setDepth(children->options[i], 1);
        }
        children->cursor = createCursor(0x1002, 1, 0x12, 0xBE);
        children->cursor->setVisible(children->cursor, 0);
        children->title = createTextWindow(0x1002, 1, 0x12, 0xB0);
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            stageFuncs.start(&task->tween, 1);
            task->substate++;
            break;
        case 1:
            if (stageFuncs.update(&task->tween)) {
                for (j = 0; j < 2; j++) {
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x39)), j + 2);
                }
                children->cursor->setVisible(children->cursor, 1);
                children->title->setString(children->title, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x39)), 1);
                task->substate++;
            }
            break;
        case 2:
            prev = task->cursor;
            if (((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_UP)) & 1) ||
                ((PAD.getRepeated(0) >> PAD.getButtonBit(0, PAD_UP)) & 1)) {
                if (--task->cursor < 0) {
                    task->cursor = 0;
                }
            } else if (((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_DOWN)) & 1) ||
                       ((PAD.getRepeated(0) >> PAD.getButtonBit(0, PAD_DOWN)) & 1)) {
                task->cursor++;
                if (task->cursor > 1) {
                    task->cursor = 1;
                }
            }
            if (prev != task->cursor) {
                SOUND.playSound(SOUND_CURSOR);
                children->cursor->setPos(children->cursor, 0x12, task->cursor * 14 + 0xBE);
                break;
            }
            if ((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_CROSS)) & 1) {
                SOUND.playSound(SOUND_SELECT);
                task->substate = 10;
                task->step = 1;
            }
            break;
        case 3:
            children->event = FIELDSTG_startEvent(task->cursor == 0 ? 0x39 : 0x5F3);
            task->substate++;
            break;
        case 4:
            if (children->event == NULL) {
                task->state = TASK_KILL;
            }
            break;
        case 10:
            for (k = 0; k < 2; k++) {
                children->options[k]->setVisible(children->options[k], 0);
            }
            children->cursor->setVisible(children->cursor, 0);
            children->title->setVisible(children->title, 0);
            stageFuncs.start(&task->tween, 0);
            task->substate++;
            break;
        case 11:
            if (stageFuncs.update(&task->tween)) {
                if (task->step == 1) {
                    task->substate = 3;
                } else {
                    task->state = TASK_KILL;
                }
            }
            break;
        }
        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x1002, 2);
        drawer.setTexture(0x140, 0);
        drawer.setFollowScroll(0);
        if (task->tween.value != 0) {
            if (task->tween.value != 0x1000) {
                drawer.setScale(task->tween.value, 0x1000, 0x1000);
                drawer.setPivot(0, 0xC3);
            }
            drawer.draw(FILE_CACHE.getEntry(MENU_SPRITES), 0x45, 0, 0xAC);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A5270(void) {
    return createTask(func_800A4CD4, 0x64, 0x14);
}

/* Creates the event object while flags 0x7201, 0x8008 and 0x701A are clear */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (FLAGS_00.checkCondition(0x7201, 0) && FLAGS_00.checkCondition(0x8008, 0) && FLAGS_00.checkCondition(0x701A, 0)) {
            children[0] = FIELDSTG_startEvent(0x42);
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

#if VERSION_US
#define STAGE_TEXT 0xCD
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x1A5
#define STAGE_ARCHIVE 0x3C3
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xC5)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x1B3
#define STAGE_ARCHIVE 0x3D3
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x1BB00, 0xF400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 8;
    D_800990B4.music = 0x60200000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
}

#include "common/start_tween.inc.c"
#include "common/update_tween.inc.c"

extern u16 D_800A58A0[];
extern u16 D_800A58A8[];
extern u16 D_800A58B0[];
extern u16 D_800A58B8[];
extern u16 D_800A58C4[];
extern u16 D_800A58CC[];
extern u16 D_800A58DC[];
extern u16 D_800A58E8[];
extern u16 D_800A58F8[];
extern u16 D_800A5900[];
extern u16 D_800A5908[];
extern u16 D_800A5914[];
extern u16 D_800A5920[];
extern u16 D_800A592C[];
extern u16 D_800A5934[];
extern u16 D_800A5940[];
extern u16 D_800A594C[];
extern u16 D_800A5E44[];
extern FieldTalk D_800A5958[];
extern u16 D_800A5E54[];
extern FieldTalk D_800A5970[];
extern u16 D_800A5E64[];
extern FieldTalk D_800A5988[];
extern u16 D_800A5E74[];
extern FieldTalk D_800A59A0[];
extern u16 D_800A5E84[];
extern FieldTalk D_800A59B8[];
extern u16 D_800A5E94[];
extern FieldTalk D_800A59D0[];
extern u16 D_800A5EA4[];
extern FieldTalk D_800A59E8[];
extern u16 D_800A5EB4[];
extern FieldTalk D_800A5A00[];
extern u16 D_800A5EC4[];
extern FieldTalk D_800A5A18[];
extern u16 D_800A5ECC[];
extern FieldTalk D_800A5A30[];
extern u16 D_800A5ED4[];
extern FieldTalk D_800A5A48[];
extern u16 D_800A5EDC[];
extern FieldTalk D_800A5A60[];
extern u16 D_800A5EE4[];
extern FieldTalk D_800A5A78[];
extern u16 D_800A5EEC[];
extern FieldTalk D_800A5A90[];
extern u16 D_800A5EF4[];
extern FieldTalk D_800A5AA8[];
extern u16 D_800A5EFC[];
extern FieldTalk D_800A5AC0[];
extern u16 D_800A5F04[];
extern FieldTalk D_800A5AD8[];
extern u16 D_800A5F0C[];
extern FieldTalk D_800A5AF0[];
extern u16 D_800A5F14[];
extern FieldTalk D_800A5B08[];
extern u16 D_800A5F1C[];
extern FieldTalk D_800A5B20[];
extern u16 D_800A5F24[];
extern FieldTalk D_800A5B38[];
extern u16 D_800A5F2C[];
extern FieldTalk D_800A5B50[];
extern u16 D_800A5F34[];
extern FieldTalk D_800A5B68[];
extern u16 D_800A5F3C[];
extern FieldTalk D_800A5B80[];
extern u16 D_800A5F44[];
extern FieldTalk D_800A5B98[];
extern u16 D_800A5F4C[];
extern FieldTalk D_800A5BB0[];
extern u16 D_800A5F54[];
extern FieldTalk D_800A5BC8[];
extern u16 D_800A5F5C[];
extern FieldTalk D_800A5BE0[];
extern u16 D_800A5F64[];
extern FieldTalk D_800A5BF8[];
extern u16 D_800A5F6C[];
extern FieldTalk D_800A5C10[];
extern u16 D_800A5F74[];
extern FieldTalk D_800A5C28[];
extern u16 D_800A5F7C[];
extern FieldTalk D_800A5C40[];
extern u16 D_800A5F84[];
extern FieldTalk D_800A5C58[];
extern u16 D_800A5F8C[];
extern FieldTalk D_800A5C70[];
extern u16 D_800A5F94[];
extern FieldTalk D_800A5C88[];
extern u16 D_800A5F9C[];
extern FieldTalk D_800A5CA0[];
extern u16 D_800A5FA4[];
extern FieldTalk D_800A5CB8[];
extern u16 D_800A5FAC[];
extern FieldTalk D_800A5CD0[];
extern u16 D_800A5FB4[];
extern FieldTalk D_800A5CE8[];
extern u16 D_800A5FBC[];
extern FieldTalk D_800A5D00[];
extern u16 D_800A5FC4[];
extern FieldTalk D_800A5D18[];
extern u16 D_800A5FCC[];
extern FieldTalk D_800A5D30[];
extern u16 D_800A5FD4[];
extern FieldTalk D_800A5D48[];
extern u16 D_800A5FDC[];
extern FieldTalk D_800A5D60[];
extern u16 D_800A5FE4[];
extern FieldTalk D_800A5D9C[];
extern u16 D_800A5FF0[];
extern FieldTalk D_800A5DCC[];
extern u16 D_800A5FFC[];
extern FieldTalk D_800A5DFC[];
extern u16 D_800A6008[];
extern FieldTalk D_800A5E14[];
extern u16 D_800A6014[];
extern FieldTalk D_800A5E2C[];
extern FieldActorEntry D_800A601C;
extern FieldActorEntry D_800A6030;
extern FieldActorEntry D_800A6044;
extern FieldActorEntry D_800A6058;
extern FieldActorEntry D_800A606C;
extern FieldActorEntry D_800A6080;
extern FieldActorEntry D_800A6094;
extern FieldActorEntry D_800A60A8;
extern FieldActorEntry D_800A60BC;
extern FieldActorEntry D_800A60D0;
extern FieldActorEntry D_800A60E4;
extern FieldActorEntry D_800A60F8;
extern FieldActorEntry D_800A610C;
extern FieldActorEntry D_800A6120;
extern FieldActorEntry D_800A6134;
extern FieldActorEntry D_800A6148;
extern FieldActorEntry D_800A615C;
extern FieldActorEntry D_800A6170;
extern FieldActorEntry D_800A6184;
extern FieldActorEntry D_800A6198;
extern FieldActorEntry D_800A61AC;
extern FieldActorEntry D_800A61C0;
extern FieldActorEntry D_800A61D4;
extern FieldActorEntry D_800A61E8;
extern FieldActorEntry D_800A61FC;
extern FieldActorEntry D_800A6210;
extern FieldActorEntry D_800A6224;
extern FieldActorEntry D_800A6238;
extern FieldActorEntry D_800A624C;
extern FieldActorEntry D_800A6260;
extern FieldActorEntry D_800A6274;
extern FieldActorEntry D_800A6288;
extern FieldActorEntry D_800A629C;
extern FieldActorEntry D_800A62B0;
extern FieldActorEntry D_800A62C4;
extern FieldActorEntry D_800A62D8;
extern FieldActorEntry D_800A62EC;
extern FieldActorEntry D_800A6300;
extern FieldActorEntry D_800A6314;
extern FieldActorEntry D_800A6328;
extern FieldActorEntry D_800A633C;
extern FieldActorEntry D_800A6350;
extern FieldActorEntry D_800A6364;
extern FieldActorEntry D_800A6378;
extern FieldActorEntry D_800A638C;
extern FieldActorEntry D_800A63A0;
extern FieldActorEntry D_800A63B4;
extern FieldActorEntry D_800A63C8;
extern FieldActorEntry D_800A63DC;
extern FieldActorEntry D_800A63F0;
extern s16 D_800A55A4[];
extern s16 D_800A5634[];
extern s16 D_800A56AC[];
extern s16 D_800A574C[];

s16 D_800A55A4[] = {
    0x102, 2, 0x180, 0xB0, 3,
    0x101, 0x10B, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x300, 0x1E,
    0x200, 0, 1, 0x10B, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x338, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x10B, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 5, 0x10B, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5634[] = {
    0x100, 2, 0x218, 0xF4,
    0x101, 2, 1, 3,
    0x100, 0x2D, 0x1F6, 0xE4,
    0x101, 0x2D, 1, 7,
    0x300, 0x1E,
    0x102, 2, 0x210, 0xF1, 3,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 1, 0x2D, 0,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x102, 2, 0x22B, 0xFC, 7,
    0x300, 0x1E,
    0x304, 0x201, 0x180, 0xD8, 7,
    0,
};
s16 D_800A56AC[] = {
    0x102, 2, 0x14F, 0xD0, 3,
    0x100, 0x118, 0x131, 0xC1,
    0x101, 0x118, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0x118, 2,
    0x301,
    0x101, 0x118, 1, 7,
    0x300, 0x1E,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x168, 0xC4, 5,
    0x302, 2,
    0x101, 2, 1, 1,
    0x102, 0x118, 0x170, 0xE0, 7,
    0x302, 0x118,
    0x102, 2, 0x14F, 0xD0, 3,
    0x101, 0x118, 1, 3,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
s16 D_800A574C[] = {
    0x102, 2, 0x180, 0xB0, 3,
    0x101, 0x10B, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x300, 0x1E,
    0x200, 0, 1, 0x10B, 2,
    0x301,
    0x300, 0x1E,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x17A, 0xE0, 0x7A, 0x160, 0x1FF },
    { 0x140, 0x100, 0x158, 0x182, 0x60, 0x82, 0x170, 0x1FF },
    { 0x140, 0x100, 0x170, 0x17A, 0xC0, 0x7A, 0x160, 0x1FE },
    { 0x140, 0x100, 0x140, 0x182, 0, 0x82, 0x170, 0x1FE },
    { 0x140, 0x100, 0x160, 0x189, 0x80, 0x89, 0x140, 0x1FD },
    { 0x140, 0x100, 0x168, 0x189, 0xA0, 0x89, 0x150, 0x1FD },
    { 0x140, 0x100, 0x158, 0x1A2, 0x60, 0xA2, 0x160, 0x1FD },
    { 0x140, 0x100, 0x170, 0x1A2, 0xC0, 0xA2, 0x170, 0x1FD },
    { 0x140, 0x100, 0x148, 0x182, 0x20, 0x82, 0x140, 0x1FC },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x150, 0x182, 0x40, 0x82, 0x150, 0x1FC },
    { 0x140, 0x100, 0x160, 0x1A9, 0x80, 0xA9, 0x160, 0x1FC },
};
u16 D_800A58A0[] = { 0x9000, 1, 0xFFFF };
u16 D_800A58A8[] = { 0x1A05, 0, 0xFFFF };
u16 D_800A58B0[] = { 0x1A05, 1, 0xFFFF };
u16 D_800A58B8[] = { 0x1A05, 1, 0x7202, 0, 0xFFFF };
u16 D_800A58C4[] = { 0x9000, 1, 0xFFFF };
u16 D_800A58CC[] = { 0x1A05, 1, 0x7202, 1, 0x8008, 0, 0xFFFF };
u16 D_800A58DC[] = { 0x8008, 1, 0x7013, 1, 0xFFFF };
u16 D_800A58E8[] = { 0x1A05, 1, 0x7202, 1, 0x8008, 1, 0xFFFF };
u16 D_800A58F8[] = { 0x9000, 1, 0xFFFF };
u16 D_800A5900[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5908[] = { 0x8008, 1, 0, 0, 0xFFFF };
u16 D_800A5914[] = { 0x9022, 1, 0, 1, 0xFFFF };
u16 D_800A5920[] = { 0x8008, 1, 0, 1, 0xFFFF };
u16 D_800A592C[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5934[] = { 0, 0, 0x8008, 1, 0xFFFF };
u16 D_800A5940[] = { 0x9022, 1, 0, 1, 0xFFFF };
u16 D_800A594C[] = { 0x8008, 1, 0, 1, 0xFFFF };
FieldTalk D_800A5958[] = {
    { NULL, NULL, 0x8A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5970[] = {
    { NULL, NULL, 0x8A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5988[] = {
    { NULL, NULL, 0x8A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59A0[] = {
    { NULL, NULL, 0x8A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59B8[] = {
    { NULL, NULL, 0x8A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59D0[] = {
    { NULL, NULL, 0x8A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59E8[] = {
    { NULL, NULL, 0x8A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A00[] = {
    { NULL, NULL, 0x8A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A18[] = {
    { NULL, NULL, 0x469 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A30[] = {
    { NULL, NULL, 0x471 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A48[] = {
    { NULL, NULL, 0x46A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A60[] = {
    { NULL, NULL, 0x46B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A78[] = {
    { NULL, NULL, 0x46C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A90[] = {
    { NULL, NULL, 0x46D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AA8[] = {
    { NULL, NULL, 0x473 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AC0[] = {
    { NULL, NULL, 0x46E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AD8[] = {
    { NULL, NULL, 0x46F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AF0[] = {
    { NULL, NULL, 0x470 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B08[] = {
    { NULL, NULL, 0x474 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B20[] = {
    { NULL, NULL, 0x47C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B38[] = {
    { NULL, NULL, 0x475 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B50[] = {
    { NULL, NULL, 0x476 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B68[] = {
    { NULL, NULL, 0x477 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B80[] = {
    { NULL, NULL, 0x478 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B98[] = {
    { NULL, NULL, 0x47E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BB0[] = {
    { NULL, NULL, 0x47B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BC8[] = {
    { NULL, NULL, 0x479 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BE0[] = {
    { NULL, NULL, 0x47A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BF8[] = {
    { NULL, NULL, 0x45E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C10[] = {
    { NULL, NULL, 0x467 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C28[] = {
    { NULL, NULL, 0x45F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C40[] = {
    { NULL, NULL, 0x460 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C58[] = {
    { NULL, NULL, 0x461 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C70[] = {
    { NULL, NULL, 0x462 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C88[] = {
    { NULL, NULL, 0x468 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CA0[] = {
    { NULL, NULL, 0x463 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CB8[] = {
    { NULL, NULL, 0x465 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CD0[] = {
    { NULL, NULL, 0x464 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CE8[] = {
    { NULL, NULL, 0x8B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D00[] = {
    { NULL, NULL, 0x466 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D18[] = {
    { NULL, NULL, 0x472 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D30[] = {
    { NULL, NULL, 0x47D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D48[] = {
    { NULL, D_800A58A0, 0x138 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D60[] = {
    { D_800A58A8, D_800A58B0, 0x32 },
    { D_800A58B8, D_800A58C4, 0x138 },
    { D_800A58CC, D_800A58DC, 0x139 },
    { D_800A58E8, D_800A58F8, 0x138 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D9C[] = {
    { D_800A5900, NULL, 0xA3 },
    { D_800A5908, D_800A5914, 0xA2 },
    { D_800A5920, NULL, 0xA4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DCC[] = {
    { D_800A592C, NULL, 0xA3 },
    { D_800A5934, D_800A5940, 0xA2 },
    { D_800A594C, NULL, 0xA4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DFC[] = {
    { NULL, NULL, 0xA4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E14[] = {
    { NULL, NULL, 0xA4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E2C[] = {
    { NULL, NULL, 0xA5 },
    { NULL, NULL, 0 },
};
u16 D_800A5E44[] = { 0x7022, 1, 0x8008, 0, 0x7201, 0, 0xFFFF };
u16 D_800A5E54[] = { 0x8008, 1, 0x7022, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5E64[] = { 0x8008, 0, 0x602B, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5E74[] = { 0x8008, 1, 0x602B, 1, 0x7201, 0, 0xFFFF };
u16 D_800A5E84[] = { 0x7022, 1, 0x8008, 0, 0x7201, 1, 0xFFFF };
u16 D_800A5E94[] = { 0x7022, 1, 0x8008, 1, 0x7201, 1, 0xFFFF };
u16 D_800A5EA4[] = { 0x602B, 1, 0x8008, 0, 0x7201, 1, 0xFFFF };
u16 D_800A5EB4[] = { 0x602B, 1, 0x8008, 1, 0x7201, 1, 0xFFFF };
u16 D_800A5EC4[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5ECC[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5ED4[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5EDC[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5EE4[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5EEC[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5EF4[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5EFC[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5F04[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5F0C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5F14[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5F1C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5F24[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5F2C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5F34[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5F3C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5F44[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5F4C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5F54[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5F5C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5F64[] = { 0x6004, 1, 0xFFFF };
u16 D_800A5F6C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A5F74[] = { 0x7015, 1, 0xFFFF };
u16 D_800A5F7C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A5F84[] = { 0x600E, 1, 0xFFFF };
u16 D_800A5F8C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A5F94[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5F9C[] = { 0x6016, 1, 0xFFFF };
u16 D_800A5FA4[] = { 0x7019, 1, 0xFFFF };
u16 D_800A5FAC[] = { 0x7018, 1, 0xFFFF };
u16 D_800A5FB4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5FBC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5FC4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5FCC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5FD4[] = { 0x8008, 1, 0xFFFF };
u16 D_800A5FDC[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5FE4[] = { 0x7022, 1, 0x8008, 0, 0xFFFF };
u16 D_800A5FF0[] = { 0x602B, 1, 0x8008, 0, 0xFFFF };
u16 D_800A5FFC[] = { 0x8008, 1, 0x7022, 1, 0xFFFF };
u16 D_800A6008[] = { 0x8008, 1, 0x602B, 1, 0xFFFF };
u16 D_800A6014[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A601C = { D_800A5E44, D_800A5958, 0x2D, 4, 502, 228, 7 };
FieldActorEntry D_800A6030 = { D_800A5E54, D_800A5970, 0x2D, 4, 471, 245, 5 };
FieldActorEntry D_800A6044 = { D_800A5E64, D_800A5988, 0x2D, 4, 502, 228, 7 };
FieldActorEntry D_800A6058 = { D_800A5E74, D_800A59A0, 0x2D, 4, 471, 245, 5 };
FieldActorEntry D_800A606C = { D_800A5E84, D_800A59B8, 0x2D, 4, 471, 245, 5 };
FieldActorEntry D_800A6080 = { D_800A5E94, D_800A59D0, 0x2D, 4, 471, 245, 5 };
FieldActorEntry D_800A6094 = { D_800A5EA4, D_800A59E8, 0x2D, 4, 471, 245, 5 };
FieldActorEntry D_800A60A8 = { D_800A5EB4, D_800A5A00, 0x2D, 4, 471, 245, 5 };
FieldActorEntry D_800A60BC = { D_800A5EC4, D_800A5A18, 0x2E, 5, 352, 296, 5 };
FieldActorEntry D_800A60D0 = { D_800A5ECC, D_800A5A30, 0x2E, 5, 352, 296, 5 };
FieldActorEntry D_800A60E4 = { D_800A5ED4, D_800A5A48, 0x2E, 5, 352, 296, 5 };
FieldActorEntry D_800A60F8 = { D_800A5EDC, D_800A5A60, 0x2E, 5, 352, 296, 5 };
FieldActorEntry D_800A610C = { D_800A5EE4, D_800A5A78, 0x2E, 5, 352, 296, 5 };
FieldActorEntry D_800A6120 = { D_800A5EEC, D_800A5A90, 0x2E, 5, 352, 296, 5 };
FieldActorEntry D_800A6134 = { D_800A5EF4, D_800A5AA8, 0x2E, 5, 352, 296, 5 };
FieldActorEntry D_800A6148 = { D_800A5EFC, D_800A5AC0, 0x2E, 5, 352, 296, 5 };
FieldActorEntry D_800A615C = { D_800A5F04, D_800A5AD8, 0x2E, 5, 352, 296, 5 };
FieldActorEntry D_800A6170 = { D_800A5F0C, D_800A5AF0, 0x2E, 5, 352, 296, 5 };
FieldActorEntry D_800A6184 = { D_800A5F14, D_800A5B08, 0x33, 6, 216, 277, 7 };
FieldActorEntry D_800A6198 = { D_800A5F1C, D_800A5B20, 0x33, 6, 216, 277, 7 };
FieldActorEntry D_800A61AC = { D_800A5F24, D_800A5B38, 0x33, 6, 216, 277, 7 };
FieldActorEntry D_800A61C0 = { D_800A5F2C, D_800A5B50, 0x33, 6, 216, 277, 7 };
FieldActorEntry D_800A61D4 = { D_800A5F34, D_800A5B68, 0x33, 6, 216, 277, 7 };
FieldActorEntry D_800A61E8 = { D_800A5F3C, D_800A5B80, 0x33, 6, 216, 277, 7 };
FieldActorEntry D_800A61FC = { D_800A5F44, D_800A5B98, 0x33, 6, 216, 277, 7 };
FieldActorEntry D_800A6210 = { D_800A5F4C, D_800A5BB0, 0x33, 6, 216, 277, 7 };
FieldActorEntry D_800A6224 = { D_800A5F54, D_800A5BC8, 0x33, 6, 216, 277, 7 };
FieldActorEntry D_800A6238 = { D_800A5F5C, D_800A5BE0, 0x33, 6, 216, 277, 7 };
FieldActorEntry D_800A624C = { D_800A5F64, D_800A5BF8, 0x37, 7, 264, 301, 3 };
FieldActorEntry D_800A6260 = { D_800A5F6C, D_800A5C10, 0x37, 7, 264, 301, 3 };
FieldActorEntry D_800A6274 = { D_800A5F74, D_800A5C28, 0x37, 7, 264, 301, 3 };
FieldActorEntry D_800A6288 = { D_800A5F7C, D_800A5C40, 0x37, 7, 264, 301, 3 };
FieldActorEntry D_800A629C = { D_800A5F84, D_800A5C58, 0x37, 7, 264, 301, 3 };
FieldActorEntry D_800A62B0 = { D_800A5F8C, D_800A5C70, 0x37, 7, 264, 301, 3 };
FieldActorEntry D_800A62C4 = { D_800A5F94, D_800A5C88, 0x37, 7, 264, 301, 3 };
FieldActorEntry D_800A62D8 = { D_800A5F9C, D_800A5CA0, 0x37, 7, 264, 301, 3 };
FieldActorEntry D_800A62EC = { D_800A5FA4, D_800A5CB8, 0x37, 7, 264, 301, 3 };
FieldActorEntry D_800A6300 = { D_800A5FAC, D_800A5CD0, 0x37, 7, 264, 301, 3 };
FieldActorEntry D_800A6314 = { D_800A5FB4, D_800A5CE8, 0x9D, 8, 471, 245, 5 };
FieldActorEntry D_800A6328 = { D_800A5FBC, D_800A5D00, 0x9F, 9, 264, 301, 3 };
FieldActorEntry D_800A633C = { D_800A5FC4, D_800A5D18, 0xA0, 0xA, 352, 296, 5 };
FieldActorEntry D_800A6350 = { D_800A5FCC, D_800A5D30, 0xA1, 0xB, 216, 277, 7 };
FieldActorEntry D_800A6364 = { D_800A5FD4, D_800A5D48, 0x10B, 0xC, 353, 160, 7 };
FieldActorEntry D_800A6378 = { D_800A5FDC, D_800A5D60, 0x10B, 0xC, 353, 160, 7 };
FieldActorEntry D_800A638C = { NULL, NULL, 0x10C, 0xD, 360, 172, 7 };
FieldActorEntry D_800A63A0 = { D_800A5FE4, D_800A5D9C, 0x118, 0xE, 305, 193, 7 };
FieldActorEntry D_800A63B4 = { D_800A5FF0, D_800A5DCC, 0x118, 0xE, 305, 193, 7 };
FieldActorEntry D_800A63C8 = { D_800A5FFC, D_800A5DFC, 0x118, 0xE, 368, 224, 3 };
FieldActorEntry D_800A63DC = { D_800A6008, D_800A5E14, 0x118, 0xE, 368, 224, 3 };
FieldActorEntry D_800A63F0 = { D_800A6014, D_800A5E2C, 0x119, 0xF, 368, 224, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A601C,
    &D_800A6030,
    &D_800A6044,
    &D_800A6058,
    &D_800A606C,
    &D_800A6080,
    &D_800A6094,
    &D_800A60A8,
    &D_800A60BC,
    &D_800A60D0,
    &D_800A60E4,
    &D_800A60F8,
    &D_800A610C,
    &D_800A6120,
    &D_800A6134,
    &D_800A6148,
    &D_800A615C,
    &D_800A6170,
    &D_800A6184,
    &D_800A6198,
    &D_800A61AC,
    &D_800A61C0,
    &D_800A61D4,
    &D_800A61E8,
    &D_800A61FC,
    &D_800A6210,
    &D_800A6224,
    &D_800A6238,
    &D_800A624C,
    &D_800A6260,
    &D_800A6274,
    &D_800A6288,
    &D_800A629C,
    &D_800A62B0,
    &D_800A62C4,
    &D_800A62D8,
    &D_800A62EC,
    &D_800A6300,
    &D_800A6314,
    &D_800A6328,
    &D_800A633C,
    &D_800A6350,
    &D_800A6364,
    &D_800A6378,
    &D_800A638C,
    &D_800A63A0,
    &D_800A63B4,
    &D_800A63C8,
    &D_800A63DC,
    &D_800A63F0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0xA, 0, 0, 0, 0, 0, 93, 125, 0, 0 },
    { 1, 0, 0x40, 2, 0xB, 0, 0, 0, 0, 0, 126, 109, 0, 0 },
    { 1, 0, 0x40, 2, 0xC, 0, 0, 0, 0, 0, 158, 93, 0, 0 },
    { 1, 0, 0x40, 2, 0xD, 0, 0, 0, 0, 0, 235, 67, 0, 0 },
    { 1, 0, 0x40, 2, 0xE, 0, 0, 0, 0, 0, 282, 43, 0, 0 },
    { 1, 0, 0x40, 2, 0xF, 0, 0, 0, 0, 0, 379, 34, 0, 0 },
    { 1, 0, 0x40, 2, 0x10, 0, 0, 0, 0, 0, 403, 46, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 0, 0, 0, 0, 0, 427, 90, 0, 0 },
    { 1, 0, 0x40, 2, 0x12, 0, 0, 0, 0, 0, 463, 113, 0, 0 },
    { 1, 0, 0x40, 2, 0x13, 0, 0, 0, 0, 0, 482, 109, 0, 0 },
    { 1, 0, 0x40, 2, 0x14, 0, 0, 0, 0, 0, 503, 123, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 84, 130, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 116, 114, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 148, 98, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 272, 44, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 368, 36, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 417, 91, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 453, 113, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 473, 112, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 493, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 497, 124, 0, 0 },
    { 1, 0, 0x40, 6, 0x33, 2, 0, 1, 4, 0, 292, 104, 0, 0 },
    { 1, 0, 0x40, 6, 0x15, 0, 0, 0, 0, 0, 416, 59, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 224, 68, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 392, 48, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 2, 0, 1, 4, 0, 416, 60, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 208, 263, 288, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 384, 191, 217, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 320, 169, 184, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 304, 161, 174, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 336, 161, 174, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 288, 153, 166, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 352, 153, 166, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 272, 144, 158, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 368, 145, 158, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x201, 0x180, 0xD8, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x212, 0x92, 0x1A2, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 3, 0x110, 0xB8, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 3, 0x100, 0xF0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageFuncs stageFuncs = { setupStage, startTween, updateTween };
FieldEvent stageEvents[] = {
    { 57, D_800A55A4, EVENT_TEXT(0x11), NULL, NULL },
    { 66, D_800A5634, EVENT_TEXT(0x13), NULL, NULL },
    { 67, D_800A56AC, EVENT_TEXT(0x14), NULL, NULL },
    { 1522, NULL, EVENT_TEXT(0x39), func_800A5270, NULL },
    { 1523, D_800A574C, EVENT_TEXT(0x34), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
