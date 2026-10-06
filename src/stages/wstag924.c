#include "common.h"
#define STAGE_TWEEN /* stageFuncs is a StageFuncs (stage.h) */
#include "stage.h"
void func_800A60FC();
void func_800A6A94();
extern s32 D_800A7A34[];
extern s32 D_800A7A44[];

/* The text file of the menus */
#define MENU_TEXT 0x158

#include "common/update_stage.inc.c"

#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0xFD;
    D_800990B4.mapFile = 0x19C;
    D_800990B4.sheetEntry = 0x8E70000;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x8E5;
    D_800990B4.start = (Vec2){0x10200, 0x15700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x33;
    D_800990B4.music = 0x60CC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, 0x8E70001);
    D_8009A70C.setFile(7, 0x8E70002);
    D_8009A70C.unk50(0);
}

#include "common/start_tween.inc.c"
#include "common/update_tween.inc.c"

/* A list of up to eight options that each open a message */
void func_800A60FC(StageListMenu *task, StageListMenuChildren *children) {
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
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x1)), j + 1);
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
                children->message->setString(children->message, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x1)), task->cursor + 9);
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
            drawer.draw(FILE_CACHE.getEntry(MENU_SPRITES), D_800A7A34[task->count - 5], 0xA8, 0x18);
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

void *func_800A6A68(void) {
    return createTask(func_800A60FC, 0x84, 0x28);
}

/* A list of up to eight options that each open a message */
void func_800A6A94(StageListMenu *task, StageListMenuChildren *children) {
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
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x2)), j + 1);
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
                children->message->setString(children->message, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x2)), task->cursor + 9);
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
            drawer.draw(FILE_CACHE.getEntry(MENU_SPRITES), D_800A7A44[task->count - 5], 0xA8, 0x18);
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

void *func_800A7400(void) {
    return createTask(func_800A6A94, 0x84, 0x28);
}

extern u16 D_800A74FC[];
extern u16 D_800A7504[];
extern u16 D_800A750C[];
extern FieldTalk D_800A7514[];
extern FieldTalk D_800A752C[];
extern FieldTalk D_800A7544[];
extern FieldTalk D_800A755C[];
extern FieldActorEntry D_800A7574;
extern FieldActorEntry D_800A7588;
extern FieldActorEntry D_800A759C;
extern FieldActorEntry D_800A75B0;
extern FieldActorEntry D_800A75C4;
extern FieldActorEntry D_800A75D8;
extern FieldActorEntry D_800A75EC;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x166, 0x178, 0x98, 0x78, 0x150, 0x1F8 },
    { 0x140, 0x100, 0x16E, 0x178, 0xB8, 0x78, 0x160, 0x1F8 },
    { 0x140, 0x100, 0x176, 0x178, 0xD8, 0x78, 0x170, 0x1F8 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x152, 0x166, 0x48, 0x66, 0x150, 0x1F7 },
    { 0x140, 0x100, 0x140, 0x17E, 0, 0x7E, 0x160, 0x1F7 },
};
u16 D_800A74FC[] = { 0x906E, 1, 0xFFFF };
u16 D_800A7504[] = { 0x906D, 1, 0xFFFF };
u16 D_800A750C[] = { 0x7C00, 1, 0xFFFF };
FieldTalk D_800A7514[] = {
    { NULL, D_800A74FC, 0x23 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A752C[] = {
    { NULL, D_800A7504, 0x22 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7544[] = {
    { NULL, D_800A750C, 0x24 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A755C[] = {
    { NULL, NULL, 0x25 },
    { NULL, NULL, 0 },
};
FieldActorEntry D_800A7574 = { NULL, D_800A7514, 0x20, 4, 220, 232, 1 };
FieldActorEntry D_800A7588 = { NULL, D_800A752C, 0x24, 5, 187, 215, 1 };
FieldActorEntry D_800A759C = { NULL, NULL, 0x59, 6, 300, 217, 5 };
FieldActorEntry D_800A75B0 = { NULL, NULL, 0x70, 7, 202, 241, 1 };
FieldActorEntry D_800A75C4 = { NULL, NULL, 0x71, 8, 169, 224, 1 };
FieldActorEntry D_800A75D8 = { NULL, D_800A7544, 0xFE, 9, 399, 248, 1 };
FieldActorEntry D_800A75EC = { NULL, D_800A755C, 0x177, 0xA, 65, 263, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A7574,
    &D_800A7588,
    &D_800A759C,
    &D_800A75B0,
    &D_800A75C4,
    &D_800A75D8,
    &D_800A75EC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x45, 2, 0, 2, 0xA, 0, 376, 237, 0, 0 },
    { 1, 0, 0x40, 2, 5, 0, 0, 0, 0, 0, 368, 277, 0, 0 },
    { 1, 0, 0x40, 2, 6, 0, 0, 0, 0, 0, 0, 204, 0, 0 },
    { 1, 0, 0x40, 2, 0x46, 2, 0, 1, 4, 0, 38, 197, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 110, 341, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 198, 149, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 221, 148, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 235, 149, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 249, 297, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 271, 168, 0, 0 },
    { 1, 0, 0x40, 6, 0x1F, 1, 0x1F, 0x24, 8, 0, 398, 350, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 102, 333, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 200, 134, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 213, 145, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 242, 167, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 248, 230, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 254, 280, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 265, 153, 0, 0 },
    { 1, 0, 0x40, 6, 0x25, 1, 0x25, 0x2A, 8, 0, 391, 343, 0, 0 },
    { 1, 0, 0x40, 6, 0x2B, 0, 0, 0, 0, 0, 213, 151, 0, 0 },
    { 1, 0, 0x40, 6, 0x2B, 0, 0, 0, 0, 0, 248, 286, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 0, 0, 0, 0, 0, 104, 328, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 0, 0, 0, 0, 0, 197, 141, 0, 0 },
    { 1, 0, 0x40, 6, 0x2C, 0, 0, 0, 0, 0, 264, 158, 0, 0 },
    { 1, 0, 0x40, 6, 0x2D, 0, 0, 0, 0, 0, 236, 159, 0, 0 },
    { 1, 0, 0x40, 6, 0x2D, 0, 0, 0, 0, 0, 391, 343, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x39, 0xE, 0, 318, 172, 0, 0 },
    { 1, 0, 0x40, 6, 0x2F, 1, 0x2F, 0x31, 4, 0, 305, 193, 0, 0 },
    { 1, 0, 0x40, 6, 0x3B, 1, 0x3B, 0x3F, 8, 0, 354, 209, 0, 0 },
    { 1, 0, 0x40, 6, 0x40, 2, 0, 9, 8, 0, 336, 217, 0, 0 },
    { 1, 0, 0x40, 6, 0x41, 2, 0, 2, 0x10, 0, 328, 232, 0, 0 },
    { 1, 0x64, 0x40, 6, 2, 0, 0, 0, 0, 0, 79, 186, 0, 0 },
    { 1, 0, 0x40, 6, 0x42, 2, 0, 2, 6, 0, 136, 185, 0, 0 },
    { 1, 0, 0x40, 6, 0x43, 2, 0, 2, 0x10, 0, 306, 231, 0, 0 },
    { 1, 0, 0x40, 6, 0x44, 2, 0, 2, 0xA, 0, 321, 223, 0, 0 },
    { 1, 0, 0x40, 6, 0x47, 2, 0, 1, 4, 0, 140, 123, 0, 0 },
    { 1, 0, 0x40, 6, 0x48, 2, 0, 1, 4, 0, 307, 122, 0, 0 },
    { 1, 0, 0x40, 6, 0x49, 2, 0, 1, 4, 0, 346, 144, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 273, 297, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x56, 1, 0x56, 0x58, 0xA, 0, 215, 300, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x56, 1, 0x56, 0x58, 0xA, 0, 368, 358, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x59, 1, 0x59, 0x5B, 0xA, 0, 92, 347, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x59, 1, 0x59, 0x5B, 0xA, 0, 135, 312, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x59, 1, 0x59, 0x5B, 0xA, 0, 150, 375, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x59, 1, 0x59, 0x5B, 0xA, 0, 418, 326, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 143, 287, 340, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 326, 288, 340, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 398, 240, 263, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 33, 201, 239, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x273, 0x2C8, 0x24C, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x270, 0x410, 0x200, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageFuncs stageFuncs = { setupStage, startTween, updateTween };
#define EVENT_TEXT_FILE 0x158
FieldEvent stageEvents[] = {
    { 1602, NULL, EVENT_TEXT(1), func_800A6A68, NULL },
    { 1604, NULL, EVENT_TEXT(2), func_800A7400, NULL },
    { -1, NULL, 0, NULL, NULL },
};
s32 D_800A7A34[] = {
    28, 27, 25, 36,
};
s32 D_800A7A44[] = {
    28, 27, 25, 36,
};
