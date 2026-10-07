#include "common.h"
#define STAGE_TWEEN /* stageFuncs is a StageFuncs (stage.h) */
#include "stage.h"
extern s32 D_800A7B64[];
extern s32 D_800A7B74[];

/* The text file of the menus */
#define MENU_TEXT 0x158

#include "common/update_stage.inc.c"

#include "common/start_stage.inc.c"

void setupStage(void) {
    FIELDSTG_state.textFile = LANGUAGE + 0xFD;
    FIELDSTG_state.mapFile = 0x1AE;
    FIELDSTG_state.sheetEntry = 0x8FD0000;
    FIELDSTG_state.objects = stageObjects;
    FIELDSTG_state.slots = stageSlots;
    FIELDSTG_state.imageFile = 0x8FC;
    FIELDSTG_state.start = (Vec2){0x1A400, 0xC800};
    FIELDSTG_state.images.actors = stageImages;
    FIELDSTG_state.soundBank = 8;
    FIELDSTG_state.music = MUSIC(8, 0);
    FIELDSTG_state.actors = stageActors;
    FIELDSTG_state.startDir = 0;
    FIELDSTG_state.events = stageEvents;
    FIELDSTG_map.setFile(0, 0x8FD0001);
    FIELDSTG_map.setFile(7, 0x8FD0002);
    FIELDSTG_map.setFirstMap(0);
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
            children->cursor->setPalette(children->cursor, PALETTE_GREY);
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
                children->cursor->setPalette(children->cursor, PALETTE_WHITE);
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
            children->cursor->setPalette(children->cursor, PALETTE_GREY);
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
                children->cursor->setPalette(children->cursor, PALETTE_WHITE);
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
u16 actor0Talk0Actions[] = { START_EVENT(0x73), 1, CODES_END };
u16 actor2Talk0Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 0, CODES_END };
u16 actor2Talk0Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 3), 0, CODES_END };
u16 actor2Talk1Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 1, CODES_END };
u16 actor2Talk1Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0x10), 0, FLAG(0, 3), 0, CODES_END };
u16 actor2Talk2Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 3), 0, CODES_END };
u16 actor2Talk2Actions[] = { FLAG(0, 3), 1, CODES_END };
u16 actor2Talk3Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 3), 1, CODES_END };
u16 actor2Talk3Actions[] = { CARD_BATTLE(0x24, 1), 1, CODES_END };
u16 actor4Talk0Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 0, CODES_END };
u16 actor4Talk0Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 1), 0, CODES_END };
u16 actor4Talk1Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 1, CODES_END };
u16 actor4Talk1Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0x10), 0, FLAG(0, 1), 0, CODES_END };
u16 actor4Talk2Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 1), 0, CODES_END };
u16 actor4Talk2Actions[] = { FLAG(0, 1), 1, CODES_END };
u16 actor4Talk3Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 1), 1, CODES_END };
u16 actor4Talk3Actions[] = { CARD_BATTLE(0x2D, 1), 1, CODES_END };
u16 actor6Talk0Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 0, CODES_END };
u16 actor6Talk0Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 2), 0, CODES_END };
u16 actor6Talk1Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 1, CODES_END };
u16 actor6Talk1Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0x10), 0, FLAG(0, 2), 0, CODES_END };
u16 actor6Talk2Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 2), 0, CODES_END };
u16 actor6Talk2Actions[] = { FLAG(0, 2), 1, CODES_END };
u16 actor6Talk3Conditions[] = { FLAG(0, 2), 1, FLAG(0, 0x11), 0, CODES_END };
u16 actor6Talk3Actions[] = { CARD_BATTLE(0x44, 1), 1, CODES_END };
u16 actor7Talk0Actions[] = { START_EVENT(0x72), 1, CODES_END };
u16 actor9Talk0Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 0, CODES_END };
u16 actor9Talk0Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0), 0, CODES_END };
u16 actor9Talk1Conditions[] = { FLAG(0, 0x11), 1, FLAG(0, 0x10), 1, CODES_END };
u16 actor9Talk1Actions[] = { FLAG(0, 0x11), 0, FLAG(0, 0), 0, FLAG(0, 0x10), 0, CODES_END };
u16 actor9Talk2Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 0), 0, CODES_END };
u16 actor9Talk2Actions[] = { FLAG(0, 0), 1, CODES_END };
u16 actor9Talk3Conditions[] = { FLAG(0, 0x11), 0, FLAG(0, 0), 1, CODES_END };
u16 actor9Talk3Actions[] = { CARD_BATTLE(0x34, 1), 1, CODES_END };
u16 actor10Talk0Actions[] = { 0x7A43, 1, CODES_END };
FieldTalk actor0Talks[] = {
    { NULL, actor0Talk0Actions, 0x43 },
    { NULL, NULL, 0 },
};
FieldTalk actor1Talks[] = {
    { NULL, NULL, 0x51 },
    { NULL, NULL, 0 },
};
FieldTalk actor2Talks[] = {
    { actor2Talk0Conditions, actor2Talk0Actions, 0x53 },
    { actor2Talk1Conditions, actor2Talk1Actions, 0x54 },
    { actor2Talk2Conditions, actor2Talk2Actions, 0x51 },
    { actor2Talk3Conditions, actor2Talk3Actions, 0x52 },
    { NULL, NULL, 0 },
};
FieldTalk actor3Talks[] = {
    { NULL, NULL, 0x49 },
    { NULL, NULL, 0 },
};
FieldTalk actor4Talks[] = {
    { actor4Talk0Conditions, actor4Talk0Actions, 0x4B },
    { actor4Talk1Conditions, actor4Talk1Actions, 0x4C },
    { actor4Talk2Conditions, actor4Talk2Actions, 0x49 },
    { actor4Talk3Conditions, actor4Talk3Actions, 0x4A },
    { NULL, NULL, 0 },
};
FieldTalk actor5Talks[] = {
    { NULL, NULL, 0x4D },
    { NULL, NULL, 0 },
};
FieldTalk actor6Talks[] = {
    { actor6Talk0Conditions, actor6Talk0Actions, 0x4F },
    { actor6Talk1Conditions, actor6Talk1Actions, 0x50 },
    { actor6Talk2Conditions, actor6Talk2Actions, 0x4D },
    { actor6Talk3Conditions, actor6Talk3Actions, 0x4E },
    { NULL, NULL, 0 },
};
FieldTalk actor7Talks[] = {
    { NULL, actor7Talk0Actions, 0x44 },
    { NULL, NULL, 0 },
};
FieldTalk actor8Talks[] = {
    { NULL, NULL, 0x45 },
    { NULL, NULL, 0 },
};
FieldTalk actor9Talks[] = {
    { actor9Talk0Conditions, actor9Talk0Actions, 0x47 },
    { actor9Talk1Conditions, actor9Talk1Actions, 0x48 },
    { actor9Talk2Conditions, actor9Talk2Actions, 0x45 },
    { actor9Talk3Conditions, actor9Talk3Actions, 0x46 },
    { NULL, NULL, 0 },
};
FieldTalk actor10Talks[] = {
    { NULL, actor10Talk0Actions, 0x42 },
    { NULL, NULL, 0 },
};
FieldTalk actor11Talks[] = {
    { NULL, NULL, 0x89 },
    { NULL, NULL, 0 },
};
u16 actor1Conditions[] = { ITEM(0, 0x192), 0, CODES_END };
u16 actor2Conditions[] = { ITEM(0, 0x192), 1, CODES_END };
u16 actor3Conditions[] = { ITEM(0, 0x192), 0, CODES_END };
u16 actor4Conditions[] = { ITEM(0, 0x192), 1, CODES_END };
u16 actor5Conditions[] = { ITEM(0, 0x192), 0, CODES_END };
u16 actor6Conditions[] = { ITEM(0, 0x192), 1, CODES_END };
u16 actor8Conditions[] = { ITEM(0, 0x192), 0, CODES_END };
u16 actor9Conditions[] = { ITEM(0, 0x192), 1, CODES_END };
u16 actor10Conditions[] = { ITEM(0, 0x192), 1, CODES_END };
u16 actor11Conditions[] = { ITEM(0, 0x192), 0, CODES_END };
FieldActorEntry actor0 = { NULL, actor0Talks, 0x2E, 4, 255, 176, 3 };
FieldActorEntry actor1 = { actor1Conditions, actor1Talks, 0x2F, 5, 173, 231, 7 };
FieldActorEntry actor2 = { actor2Conditions, actor2Talks, 0x2F, 5, 173, 231, 7 };
FieldActorEntry actor3 = { actor3Conditions, actor3Talks, 0x31, 6, 198, 219, 7 };
FieldActorEntry actor4 = { actor4Conditions, actor4Talks, 0x31, 6, 198, 219, 7 };
FieldActorEntry actor5 = { actor5Conditions, actor5Talks, 0x32, 7, 224, 257, 3 };
FieldActorEntry actor6 = { actor6Conditions, actor6Talks, 0x32, 7, 224, 257, 3 };
FieldActorEntry actor7 = { NULL, actor7Talks, 0x33, 8, 348, 147, 1 };
FieldActorEntry actor8 = { actor8Conditions, actor8Talks, 0x34, 9, 250, 244, 3 };
FieldActorEntry actor9 = { actor9Conditions, actor9Talks, 0x34, 9, 250, 244, 3 };
FieldActorEntry actor10 = { actor10Conditions, actor10Talks, 0xCE, 0xA, 379, 147, 7 };
FieldActorEntry actor11 = { actor11Conditions, actor11Talks, 0xCE, 0xA, 379, 147, 7 };
FieldActorEntry actor12 = { NULL, NULL, 0xDC, 0xB, 379, 163, 7 };
FieldActorEntry actor13 = { NULL, NULL, 0xE1, 0xC, 347, 158, 3 };
FieldActorEntry *stageActors[] = {
    &actor0,
    &actor1,
    &actor2,
    &actor3,
    &actor4,
    &actor5,
    &actor6,
    &actor7,
    &actor8,
    &actor9,
    &actor10,
    &actor11,
    &actor12,
    &actor13,
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
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 1, 0x271, 0x1F0, 0xA0, 7, 0, 0, 0 },
    { { { CODES_END, 0 }, { CODES_END, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
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
