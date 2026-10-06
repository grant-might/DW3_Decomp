#include "common.h"
#define STAGE_TWEEN /* stageFuncs is a StageFuncs (stage.h) */
#include "stage.h"
void func_800A60D8();
void func_800A6A30();
extern s32 D_800A7B64[];
extern s32 D_800A7B74[];

/* The text file of the menus */
#define MENU_TEXT 0x158

#include "common/update_stage.inc.c"

#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x1AE;
    D_800990B4.sheetEntry = 0x8FD0000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x8FC;
    D_800990B4.start = (Vec2){0x1A400, 0xC800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 8;
    D_800990B4.music = 0x60200000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, 0x8FD0001);
    D_8009A70C.setFile(7, 0x8FD0002);
    D_8009A70C.unk50(0);
}

#include "common/start_tween.inc.c"
#include "common/update_tween.inc.c"

/* A list of up to eight options that each open a message */
void func_800A60D8(StageListMenu *task, StageListMenuChildren *children) {
    SpriteDrawer drawer;
    s32 prev;
    s32 i;
    s32 j;
    s32 k;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->tweens[0].duration = 10;
        task->tweens[1].duration = 10;
        for (i = 0; i < 8; i++) {
            children->options[i] = createTextWindow(0x1002, 1, 0xBD, 0x21 + i * 14);
            children->options[i]->setDepth(children->options[i], 1);
        }
        children->cursor = createCursor(0x1002, 1, 0xAF, 0x21);
        children->cursor->setVisible(children->cursor, 0);
        children->message = createTextWindow(0x1002, 1, 0x12, 0xB0);
        children->message->setLines(children->message, 3);
        task->count = 8;
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            stageFuncs.start(&task->tweens[0], 1);
            task->substate++;
            break;
        case 1:
            if (stageFuncs.update(&task->tweens[0])) {
                for (j = 0; j < task->count; j++) {
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x8)), j + 1);
                }
                children->cursor->setVisible(children->cursor, 1);
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
                if (task->cursor > task->count - 1) {
                    task->cursor = task->count - 1;
                }
            }
            if (prev != task->cursor) {
                SOUND.playSound(SOUND_CURSOR);
                children->cursor->setPos(children->cursor, 0xAF, task->cursor * 14 + 0x21);
                break;
            }
            if ((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_CROSS)) & 1) {
                SOUND.playSound(SOUND_SELECT);
                if (task->cursor == task->count - 1) {
                    task->substate = 10;
                } else {
                    task->substate++;
                }
            } else if ((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_TRIANGLE)) & 1) {
                SOUND.playSound(SOUND_MENU_CANCEL);
                task->substate = 10;
            }
            break;
        case 3:
            children->cursor->setStill(children->cursor, 1);
            children->cursor->setPalette(children->cursor, 7);
            stageFuncs.start(&task->tweens[1], 1);
            task->substate++;
            break;
        case 4:
            if (stageFuncs.update(&task->tweens[1])) {
                children->message->setString(children->message, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x8)), task->cursor + 9);
                children->message->setTypeDelay(children->message, 6);
                task->substate++;
            }
            break;
        case 5:
            if (children->message->isFinished(children->message)) {
                task->substate++;
            } else if (children->message->isWaitingForButton(children->message)) {
                if ((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_CROSS)) & 1) {
                    SOUND.playSound(SOUND_MENU_CONFIRM);
                    task->showArrow = 0;
                } else {
                    task->showArrow = 1;
                }
            } else if ((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_CROSS)) & 1) {
                children->message->showPage(children->message);
            }
            break;
        case 6:
            stageFuncs.start(&task->tweens[1], 0);
            children->message->setVisible(children->message, 0);
            task->substate++;
            break;
        case 7:
            if (stageFuncs.update(&task->tweens[1])) {
                children->cursor->setStill(children->cursor, 0);
                children->cursor->setPalette(children->cursor, 0);
                task->substate = 2;
            }
            break;
        case 10:
            for (k = 0; k < task->count; k++) {
                children->options[k]->setVisible(children->options[k], 0);
            }
            children->cursor->setVisible(children->cursor, 0);
            stageFuncs.start(&task->tweens[0], 0);
            task->substate++;
            break;
        case 11:
            if (stageFuncs.update(&task->tweens[0])) {
                task->state = TASK_KILL;
            }
            break;
        }
        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x1002, 2);
        drawer.setTexture(0x140, 0);
        drawer.setFollowScroll(0);
        if (task->showArrow) {
            if (GFX.funcs.getTime() - task->arrowTime >= 4) {
                task->arrowTime = GFX.funcs.getTime();
                if (++task->arrowFrame >= 5) {
                    task->arrowFrame = 0;
                }
            }
            drawer.setClutRow(task->arrowFrame);
            drawer.draw(FILE_CACHE.getEntry(MENU_SPRITES), 0xA, 0x124, 0xCD);
            drawer.setClutRow(0);
        }
        if (task->tweens[0].value != 0) {
            if (task->tweens[0].value != 0x1000) {
                drawer.setScale(task->tweens[0].value, 0x1000, 0x1000);
                drawer.setPivot(0x140, 0x56);
            }
            drawer.draw(FILE_CACHE.getEntry(MENU_SPRITES), D_800A7B64[task->count - 5], 0xA8, 0x18);
        }
        if (task->tweens[1].value != 0) {
            if (task->tweens[1].value != 0x1000) {
                drawer.setScale(task->tweens[1].value, 0x1000, 0x1000);
                drawer.setPivot(0x140, 0x56);
            }
            drawer.draw(FILE_CACHE.getEntry(MENU_SPRITES), 0x45, 0, 0xAC);
        }
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

void *func_800A6A04(void) {
    return createTask(func_800A60D8, 0x84, 0x28);
}

/* A list of up to eight options that each open a message */
void func_800A6A30(StageListMenu *task, StageListMenuChildren *children) {
    SpriteDrawer drawer;
    s32 prev;
    s32 i;
    s32 j;
    s32 k;

    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        task->tweens[0].duration = 10;
        task->tweens[1].duration = 10;
        for (i = 0; i < 8; i++) {
            children->options[i] = createTextWindow(0x1002, 1, 0xBD, 0x21 + i * 14);
            children->options[i]->setDepth(children->options[i], 1);
        }
        children->cursor = createCursor(0x1002, 1, 0xAF, 0x21);
        children->cursor->setVisible(children->cursor, 0);
        children->message = createTextWindow(0x1002, 1, 0x12, 0xB0);
        children->message->setLines(children->message, 3);
        task->count = 8;
        break;
    case TASK_RUN:
        switch (task->substate) {
        case 0:
        default:
            stageFuncs.start(&task->tweens[0], 1);
            task->substate++;
            break;
        case 1:
            if (stageFuncs.update(&task->tweens[0])) {
                for (j = 0; j < task->count; j++) {
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x9)), j + 1);
                }
                children->cursor->setVisible(children->cursor, 1);
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
                if (task->cursor > task->count - 1) {
                    task->cursor = task->count - 1;
                }
            }
            if (prev != task->cursor) {
                SOUND.playSound(SOUND_CURSOR);
                children->cursor->setPos(children->cursor, 0xAF, task->cursor * 14 + 0x21);
                break;
            }
            if ((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_CROSS)) & 1) {
                SOUND.playSound(SOUND_SELECT);
                if (task->cursor == task->count - 1) {
                    task->substate = 10;
                } else {
                    task->substate++;
                }
            } else if ((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_TRIANGLE)) & 1) {
                SOUND.playSound(SOUND_MENU_CANCEL);
                task->substate = 10;
            }
            break;
        case 3:
            children->cursor->setStill(children->cursor, 1);
            children->cursor->setPalette(children->cursor, 7);
            stageFuncs.start(&task->tweens[1], 1);
            task->substate++;
            break;
        case 4:
            if (stageFuncs.update(&task->tweens[1])) {
                children->message->setString(children->message, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x9)), task->cursor + 9);
                children->message->setTypeDelay(children->message, 6);
                task->substate++;
            }
            break;
        case 5:
            if (children->message->isFinished(children->message)) {
                task->substate++;
            } else if (children->message->isWaitingForButton(children->message)) {
                if ((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_CROSS)) & 1) {
                    SOUND.playSound(SOUND_MENU_CONFIRM);
                    task->showArrow = 0;
                } else {
                    task->showArrow = 1;
                }
            } else if ((PAD.getPressed(0) >> PAD.getButtonBit(0, PAD_CROSS)) & 1) {
                children->message->showPage(children->message);
            }
            break;
        case 6:
            stageFuncs.start(&task->tweens[1], 0);
            children->message->setVisible(children->message, 0);
            task->substate++;
            break;
        case 7:
            if (stageFuncs.update(&task->tweens[1])) {
                children->cursor->setStill(children->cursor, 0);
                children->cursor->setPalette(children->cursor, 0);
                task->substate = 2;
            }
            break;
        case 10:
            for (k = 0; k < task->count; k++) {
                children->options[k]->setVisible(children->options[k], 0);
            }
            children->cursor->setVisible(children->cursor, 0);
            stageFuncs.start(&task->tweens[0], 0);
            task->substate++;
            break;
        case 11:
            if (stageFuncs.update(&task->tweens[0])) {
                task->state = TASK_KILL;
            }
            break;
        }
        initSpriteDrawer(&drawer);
        drawer.setLayerId(0x1002, 2);
        drawer.setTexture(0x140, 0);
        drawer.setFollowScroll(0);
        if (task->showArrow) {
            if (GFX.funcs.getTime() - task->arrowTime >= 4) {
                task->arrowTime = GFX.funcs.getTime();
                if (++task->arrowFrame >= 5) {
                    task->arrowFrame = 0;
                }
            }
            drawer.setClutRow(task->arrowFrame);
            drawer.draw(FILE_CACHE.getEntry(MENU_SPRITES), 0xA, 0x124, 0xCD);
            drawer.setClutRow(0);
        }
        if (task->tweens[0].value != 0) {
            if (task->tweens[0].value != 0x1000) {
                drawer.setScale(task->tweens[0].value, 0x1000, 0x1000);
                drawer.setPivot(0x140, 0x56);
            }
            drawer.draw(FILE_CACHE.getEntry(MENU_SPRITES), D_800A7B74[task->count - 5], 0xA8, 0x18);
        }
        if (task->tweens[1].value != 0) {
            if (task->tweens[1].value != 0x1000) {
                drawer.setScale(task->tweens[1].value, 0x1000, 0x1000);
                drawer.setPivot(0x140, 0x56);
            }
            drawer.draw(FILE_CACHE.getEntry(MENU_SPRITES), 0x45, 0, 0xAC);
        }
        break;
    case TASK_DONE:
        stageFuncs.start(&task->tweens[0], 1);
        stageFuncs.update(&task->tweens[0]);
        break;
    case TASK_KILL:
        break;
    }
}

void *func_800A739C(void) {
    return createTask(func_800A6A30, 0x84, 0x28);
}

extern u16 D_800A74B8[];
extern u16 D_800A74C0[];
extern u16 D_800A74CC[];
extern u16 D_800A74D8[];
extern u16 D_800A74E4[];
extern u16 D_800A74F4[];
extern u16 D_800A7500[];
extern u16 D_800A7508[];
extern u16 D_800A7514[];
extern u16 D_800A751C[];
extern u16 D_800A7528[];
extern u16 D_800A7534[];
extern u16 D_800A7540[];
extern u16 D_800A7550[];
extern u16 D_800A755C[];
extern u16 D_800A7564[];
extern u16 D_800A7570[];
extern u16 D_800A7578[];
extern u16 D_800A7584[];
extern u16 D_800A7590[];
extern u16 D_800A759C[];
extern u16 D_800A75AC[];
extern u16 D_800A75B8[];
extern u16 D_800A75C0[];
extern u16 D_800A75CC[];
extern u16 D_800A75D4[];
extern u16 D_800A75DC[];
extern u16 D_800A75E8[];
extern u16 D_800A75F4[];
extern u16 D_800A7600[];
extern u16 D_800A7610[];
extern u16 D_800A761C[];
extern u16 D_800A7624[];
extern u16 D_800A7630[];
extern u16 D_800A7638[];
extern FieldTalk D_800A7640[];
extern u16 D_800A77F0[];
extern FieldTalk D_800A7658[];
extern u16 D_800A77F8[];
extern FieldTalk D_800A7670[];
extern u16 D_800A7800[];
extern FieldTalk D_800A76AC[];
extern u16 D_800A7808[];
extern FieldTalk D_800A76C4[];
extern u16 D_800A7810[];
extern FieldTalk D_800A7700[];
extern u16 D_800A7818[];
extern FieldTalk D_800A7718[];
extern FieldTalk D_800A7754[];
extern u16 D_800A7820[];
extern FieldTalk D_800A776C[];
extern u16 D_800A7828[];
extern FieldTalk D_800A7784[];
extern u16 D_800A7830[];
extern FieldTalk D_800A77C0[];
extern u16 D_800A7838[];
extern FieldTalk D_800A77D8[];
extern FieldActorEntry D_800A7840;
extern FieldActorEntry D_800A7854;
extern FieldActorEntry D_800A7868;
extern FieldActorEntry D_800A787C;
extern FieldActorEntry D_800A7890;
extern FieldActorEntry D_800A78A4;
extern FieldActorEntry D_800A78B8;
extern FieldActorEntry D_800A78CC;
extern FieldActorEntry D_800A78E0;
extern FieldActorEntry D_800A78F4;
extern FieldActorEntry D_800A7908;
extern FieldActorEntry D_800A791C;
extern FieldActorEntry D_800A7930;
extern FieldActorEntry D_800A7944;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x1D8, 0, 0xD8, 0x160, 0x1FB },
    { 0x180, 0x100, 0x1B0, 0x159, 0x1C0, 0x59, 0x170, 0x1FB },
    { 0x180, 0x100, 0x1A0, 0x15D, 0x180, 0x5D, 0x150, 0x1FA },
    { 0x180, 0x100, 0x1A8, 0x15D, 0x1A0, 0x5D, 0x160, 0x1FA },
    { 0x180, 0x100, 0x190, 0x171, 0x140, 0x71, 0x170, 0x1FA },
    { 0x180, 0x100, 0x198, 0x171, 0x160, 0x71, 0x140, 0x1F9 },
    { 0x180, 0x100, 0x1B4, 0x100, 0x1D0, 0, 0x150, 0x1F9 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A74B8[] = { 0x9073, 1, 0xFFFF };
u16 D_800A74C0[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A74CC[] = { 0x11, 0, 3, 0, 0xFFFF };
u16 D_800A74D8[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A74E4[] = { 0x11, 0, 0x10, 0, 3, 0, 0xFFFF };
u16 D_800A74F4[] = { 0x11, 0, 3, 0, 0xFFFF };
u16 D_800A7500[] = { 3, 1, 0xFFFF };
u16 D_800A7508[] = { 0x11, 0, 3, 1, 0xFFFF };
u16 D_800A7514[] = { 0x7824, 1, 0xFFFF };
u16 D_800A751C[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A7528[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A7534[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A7540[] = { 0x11, 0, 0x10, 0, 1, 0, 0xFFFF };
u16 D_800A7550[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A755C[] = { 1, 1, 0xFFFF };
u16 D_800A7564[] = { 0x11, 0, 1, 1, 0xFFFF };
u16 D_800A7570[] = { 0x782D, 1, 0xFFFF };
u16 D_800A7578[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A7584[] = { 0x11, 0, 2, 0, 0xFFFF };
u16 D_800A7590[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A759C[] = { 0x11, 0, 0x10, 0, 2, 0, 0xFFFF };
u16 D_800A75AC[] = { 0x11, 0, 2, 0, 0xFFFF };
u16 D_800A75B8[] = { 2, 1, 0xFFFF };
u16 D_800A75C0[] = { 2, 1, 0x11, 0, 0xFFFF };
u16 D_800A75CC[] = { 0x7844, 1, 0xFFFF };
u16 D_800A75D4[] = { 0x9072, 1, 0xFFFF };
u16 D_800A75DC[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A75E8[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A75F4[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A7600[] = { 0x11, 0, 0, 0, 0x10, 0, 0xFFFF };
u16 D_800A7610[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A761C[] = { 0, 1, 0xFFFF };
u16 D_800A7624[] = { 0x11, 0, 0, 1, 0xFFFF };
u16 D_800A7630[] = { 0x7834, 1, 0xFFFF };
u16 D_800A7638[] = { 0x7A43, 1, 0xFFFF };
FieldTalk D_800A7640[] = {
    { NULL, D_800A74B8, 0x43 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7658[] = {
    { NULL, NULL, 0x51 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7670[] = {
    { D_800A74C0, D_800A74CC, 0x53 },
    { D_800A74D8, D_800A74E4, 0x54 },
    { D_800A74F4, D_800A7500, 0x51 },
    { D_800A7508, D_800A7514, 0x52 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A76AC[] = {
    { NULL, NULL, 0x49 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A76C4[] = {
    { D_800A751C, D_800A7528, 0x4B },
    { D_800A7534, D_800A7540, 0x4C },
    { D_800A7550, D_800A755C, 0x49 },
    { D_800A7564, D_800A7570, 0x4A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7700[] = {
    { NULL, NULL, 0x4D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7718[] = {
    { D_800A7578, D_800A7584, 0x4F },
    { D_800A7590, D_800A759C, 0x50 },
    { D_800A75AC, D_800A75B8, 0x4D },
    { D_800A75C0, D_800A75CC, 0x4E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7754[] = {
    { NULL, D_800A75D4, 0x44 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A776C[] = {
    { NULL, NULL, 0x45 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7784[] = {
    { D_800A75DC, D_800A75E8, 0x47 },
    { D_800A75F4, D_800A7600, 0x48 },
    { D_800A7610, D_800A761C, 0x45 },
    { D_800A7624, D_800A7630, 0x46 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A77C0[] = {
    { NULL, D_800A7638, 0x42 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A77D8[] = {
    { NULL, NULL, 0x89 },
    { NULL, NULL, 0 },
};
u16 D_800A77F0[] = { 0x8192, 0, 0xFFFF };
u16 D_800A77F8[] = { 0x8192, 1, 0xFFFF };
u16 D_800A7800[] = { 0x8192, 0, 0xFFFF };
u16 D_800A7808[] = { 0x8192, 1, 0xFFFF };
u16 D_800A7810[] = { 0x8192, 0, 0xFFFF };
u16 D_800A7818[] = { 0x8192, 1, 0xFFFF };
u16 D_800A7820[] = { 0x8192, 0, 0xFFFF };
u16 D_800A7828[] = { 0x8192, 1, 0xFFFF };
u16 D_800A7830[] = { 0x8192, 1, 0xFFFF };
u16 D_800A7838[] = { 0x8192, 0, 0xFFFF };
FieldActorEntry D_800A7840 = { NULL, D_800A7640, 0x2E, 4, 255, 176, 3 };
FieldActorEntry D_800A7854 = { D_800A77F0, D_800A7658, 0x2F, 5, 173, 231, 7 };
FieldActorEntry D_800A7868 = { D_800A77F8, D_800A7670, 0x2F, 5, 173, 231, 7 };
FieldActorEntry D_800A787C = { D_800A7800, D_800A76AC, 0x31, 6, 198, 219, 7 };
FieldActorEntry D_800A7890 = { D_800A7808, D_800A76C4, 0x31, 6, 198, 219, 7 };
FieldActorEntry D_800A78A4 = { D_800A7810, D_800A7700, 0x32, 7, 224, 257, 3 };
FieldActorEntry D_800A78B8 = { D_800A7818, D_800A7718, 0x32, 7, 224, 257, 3 };
FieldActorEntry D_800A78CC = { NULL, D_800A7754, 0x33, 8, 348, 147, 1 };
FieldActorEntry D_800A78E0 = { D_800A7820, D_800A776C, 0x34, 9, 250, 244, 3 };
FieldActorEntry D_800A78F4 = { D_800A7828, D_800A7784, 0x34, 9, 250, 244, 3 };
FieldActorEntry D_800A7908 = { D_800A7830, D_800A77C0, 0xCE, 0xA, 379, 147, 7 };
FieldActorEntry D_800A791C = { D_800A7838, D_800A77D8, 0xCE, 0xA, 379, 147, 7 };
FieldActorEntry D_800A7930 = { NULL, NULL, 0xDC, 0xB, 379, 163, 7 };
FieldActorEntry D_800A7944 = { NULL, NULL, 0xE1, 0xC, 347, 158, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A7840,
    &D_800A7854,
    &D_800A7868,
    &D_800A787C,
    &D_800A7890,
    &D_800A78A4,
    &D_800A78B8,
    &D_800A78CC,
    &D_800A78E0,
    &D_800A78F4,
    &D_800A7908,
    &D_800A791C,
    &D_800A7930,
    &D_800A7944,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x3B, 2, 0, 5, 8, 0, 428, 75, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 3, 8, 0, 65, 176, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 8, 0, 425, 67, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x39, 8, 0, 428, 75, 0, 0 },
    { 1, 0, 0x40, 4, 0x3C, 2, 0, 3, 8, 0, 470, 149, 176, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 86, 239, 258, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 160, 220, 248, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 192, 204, 232, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 320, 201, 231, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 291, 185, 209, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 352, 147, 168, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 371, 140, 160, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 336, 139, 160, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 385, 131, 153, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 320, 131, 153, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 401, 123, 144, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 304, 117, 144, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 464, 149, 176, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x271, 0x1F0, 0xA0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageFuncs stageFuncs = { setupStage, startTween, updateTween };
#define EVENT_TEXT_FILE 0x158
FieldEvent stageEvents[] = {
    { 1616, NULL, EVENT_TEXT(8), func_800A6A04, NULL },
    { 1618, NULL, EVENT_TEXT(9), func_800A739C, NULL },
    { -1, NULL, 0, NULL, NULL },
};
s32 D_800A7B64[] = {
    28, 27, 25, 36,
};
s32 D_800A7B74[] = {
    28, 27, 25, 36,
};
