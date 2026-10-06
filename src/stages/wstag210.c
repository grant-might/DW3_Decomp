#include "common.h"
#define STAGE_TWEEN /* stageFuncs is a StageFuncs (stage.h) */
#include "stage.h"
void func_800A5C80();
void func_800A56B8();
void func_800A4D38();
extern s32 D_800A6DE8[];

/* The text file of the menus, which the versions number differently */
#if VERSION_US
#define MENU_TEXT 0x10C
#elif VERSION_EU
#define MENU_TEXT 0x112
#endif

/* A list of up to eight options that each open a message */
void func_800A4D38(StageListMenu *task, StageListMenuChildren *children) {
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
            drawer.draw(FILE_CACHE.getEntry(MENU_SPRITES), D_800A6DE8[task->count - 5], 0xA8, 0x18);
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

void *func_800A568C(void) {
    return createTask(func_800A4D38, 0x84, 0x28);
}

/* A two-option menu: creates the event object of the chosen option */
void func_800A56B8(StageMenu *task, StageMenuChildren *children) {
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
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x2)), j + 2);
                }
                children->cursor->setVisible(children->cursor, 1);
                children->title->setString(children->title, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x2)), 1);
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
            children->event = FIELDSTG_startEvent(task->cursor == 0 ? 0xD : 0xE);
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

void *func_800A5C54(void) {
    return createTask(func_800A56B8, 0x64, 0x14);
}

/* A two-option menu: creates the event object of the chosen option */
void func_800A5C80(StageMenu *task, StageMenuChildren *children) {
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
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x35)), j + 2);
                }
                children->cursor->setVisible(children->cursor, 1);
                children->title->setString(children->title, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x35)), 1);
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
            children->event = FIELDSTG_startEvent(task->cursor == 0 ? 0x3A : 0x5E7);
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

void *func_800A621C(void) {
    return createTask(func_800A5C80, 0x64, 0x14);
}

/* Creates the event object of the story so far, the first that applies */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        do {
            if (GAME.progress == 0xD && FLAGS_00.checkCondition(0x1C0B, 0)) {
                children[0] = FIELDSTG_startEvent(0x136);
                break;
            }
            if (GAME.progress == 0x17 && FLAGS_00.checkCondition(0x4050, 1)) {
                children[0] = FIELDSTG_startEvent(0x2AD);
                break;
            }
        } while (0);
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

void func_800A636C(void) {
    FLAGS_00.applyAction(0x4005, 1);
    FLAGS_00.applyAction(0x1C0B, 1);
}

/* Applies flag action 0x1C26 and sets the game progress to 24 */
void func_800A63B8(void) {
    FLAGS_00.applyAction(0x1C26, 0);
    GAME.progress = 24;
}

/* the color the setup copies to D_800990B4.spriteColor */
const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0 };

#if VERSION_US
#define STAGE_TEXT 0xCD
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x18D
#define STAGE_ARCHIVE 0x313
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xC5)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x19B
#define STAGE_ARCHIVE 0x322
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x11C00, 0x13400};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 5;
    D_800990B4.music = 0x60140000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x14 && GAME.progress < 0x18) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

#include "common/start_tween.inc.c"
#include "common/update_tween.inc.c"

void func_800A63B8();
extern Battle D_800A6DF8;
extern Battle D_800A6E04;
extern Battle D_800A6E10;
extern Battle D_800A6E1C;
extern Battle D_800A6E28;
extern Battle D_800A6E34;
extern Battle D_800A6E40;
extern Battle D_800A6E4C;
extern Battle D_800A6E7C;
extern Battle D_800A6E88;
extern Battle D_800A6E94;
extern Battle D_800A6EA0;
extern Battle D_800A6EAC;
extern Battle D_800A6EB8;
extern Battle D_800A6EC4;
extern Battle D_800A6ED0;
extern Battle D_800A6F00;
extern Battle D_800A6F0C;
extern Battle D_800A6F18;
extern Battle D_800A6F24;
extern Battle D_800A6F30;
extern Battle D_800A6F3C;
extern Battle D_800A6F48;
extern Battle D_800A6F54;
extern Battle D_800A6F84;
extern Battle D_800A6F90;
extern Battle D_800A6F9C;
extern Battle D_800A6FA8;
extern Battle D_800A6FB4;
extern Battle D_800A6FC0;
extern Battle D_800A6FCC;
extern Battle D_800A6FD8;
extern BattleList D_800A6E58;
extern BattleList D_800A6EDC;
extern BattleList D_800A6F60;
extern BattleList D_800A6FE4;
extern u16 D_800A7214[];
extern u16 D_800A721C[];
extern u16 D_800A7224[];
extern u16 D_800A722C[];
extern u16 D_800A7234[];
extern u16 D_800A723C[];
extern u16 D_800A7244[];
extern u16 D_800A724C[];
extern u16 D_800A7254[];
extern u16 D_800A725C[];
extern u16 D_800A7264[];
extern u16 D_800A726C[];
extern u16 D_800A7274[];
extern u16 D_800A727C[];
extern u16 D_800A7284[];
extern u16 D_800A728C[];
extern u16 D_800A7294[];
extern u16 D_800A7A58[];
extern FieldTalk D_800A729C[];
extern u16 D_800A7A60[];
extern FieldTalk D_800A72C0[];
extern u16 D_800A7A6C[];
extern FieldTalk D_800A72D8[];
extern u16 D_800A7A74[];
extern FieldTalk D_800A72F0[];
extern u16 D_800A7A7C[];
extern FieldTalk D_800A7308[];
extern u16 D_800A7A84[];
extern FieldTalk D_800A732C[];
extern u16 D_800A7A90[];
extern FieldTalk D_800A7344[];
extern u16 D_800A7A98[];
extern FieldTalk D_800A735C[];
extern u16 D_800A7AA0[];
extern FieldTalk D_800A7374[];
extern u16 D_800A7AA8[];
extern FieldTalk D_800A738C[];
extern u16 D_800A7AB0[];
extern FieldTalk D_800A73A4[];
extern u16 D_800A7AB8[];
extern FieldTalk D_800A73BC[];
extern u16 D_800A7AC0[];
extern FieldTalk D_800A73D4[];
extern u16 D_800A7AC8[];
extern FieldTalk D_800A73EC[];
extern u16 D_800A7AD0[];
extern FieldTalk D_800A7404[];
extern u16 D_800A7AD8[];
extern FieldTalk D_800A741C[];
extern u16 D_800A7AE0[];
extern FieldTalk D_800A7434[];
extern u16 D_800A7AE8[];
extern FieldTalk D_800A744C[];
extern u16 D_800A7AF0[];
extern FieldTalk D_800A7464[];
extern u16 D_800A7AF8[];
extern FieldTalk D_800A747C[];
extern u16 D_800A7B00[];
extern u16 D_800A7B08[];
extern FieldTalk D_800A7494[];
extern u16 D_800A7B10[];
extern FieldTalk D_800A74AC[];
extern u16 D_800A7B18[];
extern FieldTalk D_800A74C4[];
extern u16 D_800A7B20[];
extern FieldTalk D_800A74DC[];
extern u16 D_800A7B2C[];
extern FieldTalk D_800A74F4[];
extern u16 D_800A7B34[];
extern FieldTalk D_800A750C[];
extern u16 D_800A7B3C[];
extern FieldTalk D_800A7524[];
extern u16 D_800A7B44[];
extern FieldTalk D_800A753C[];
extern u16 D_800A7B4C[];
extern FieldTalk D_800A7554[];
extern u16 D_800A7B54[];
extern FieldTalk D_800A756C[];
extern u16 D_800A7B5C[];
extern FieldTalk D_800A7584[];
extern u16 D_800A7B64[];
extern FieldTalk D_800A759C[];
extern u16 D_800A7B6C[];
extern FieldTalk D_800A75B4[];
extern u16 D_800A7B74[];
extern FieldTalk D_800A75CC[];
extern u16 D_800A7B7C[];
extern FieldTalk D_800A75E4[];
extern u16 D_800A7B84[];
extern FieldTalk D_800A75FC[];
extern u16 D_800A7B8C[];
extern FieldTalk D_800A7614[];
extern u16 D_800A7B94[];
extern FieldTalk D_800A762C[];
extern u16 D_800A7B9C[];
extern u16 D_800A7BA4[];
extern FieldTalk D_800A7644[];
extern u16 D_800A7BAC[];
extern FieldTalk D_800A765C[];
extern u16 D_800A7BB4[];
extern FieldTalk D_800A7674[];
extern u16 D_800A7BBC[];
extern FieldTalk D_800A768C[];
extern u16 D_800A7BC4[];
extern FieldTalk D_800A76A4[];
extern u16 D_800A7BCC[];
extern FieldTalk D_800A76BC[];
extern u16 D_800A7BD4[];
extern FieldTalk D_800A76D4[];
extern u16 D_800A7BDC[];
extern FieldTalk D_800A76EC[];
extern u16 D_800A7BE4[];
extern FieldTalk D_800A7704[];
extern u16 D_800A7BEC[];
extern FieldTalk D_800A771C[];
extern u16 D_800A7BF4[];
extern FieldTalk D_800A7734[];
extern u16 D_800A7BFC[];
extern FieldTalk D_800A774C[];
extern u16 D_800A7C04[];
extern FieldTalk D_800A7764[];
extern u16 D_800A7C0C[];
extern FieldTalk D_800A777C[];
extern u16 D_800A7C14[];
extern FieldTalk D_800A7794[];
extern u16 D_800A7C1C[];
extern u16 D_800A7C24[];
extern FieldTalk D_800A77AC[];
extern u16 D_800A7C2C[];
extern FieldTalk D_800A77C4[];
extern u16 D_800A7C34[];
extern FieldTalk D_800A77DC[];
extern u16 D_800A7C3C[];
extern FieldTalk D_800A77F4[];
extern u16 D_800A7C44[];
extern FieldTalk D_800A780C[];
extern u16 D_800A7C4C[];
extern FieldTalk D_800A7824[];
extern u16 D_800A7C54[];
extern FieldTalk D_800A783C[];
extern u16 D_800A7C5C[];
extern FieldTalk D_800A7854[];
extern u16 D_800A7C64[];
extern FieldTalk D_800A786C[];
extern u16 D_800A7C6C[];
extern u16 D_800A7C74[];
extern u16 D_800A7C80[];
extern u16 D_800A7C8C[];
extern u16 D_800A7C98[];
extern u16 D_800A7CA0[];
extern u16 D_800A7CAC[];
extern u16 D_800A7CB4[];
extern FieldTalk D_800A7884[];
extern u16 D_800A7CBC[];
extern FieldTalk D_800A789C[];
extern u16 D_800A7CC4[];
extern FieldTalk D_800A78B4[];
extern u16 D_800A7CCC[];
extern FieldTalk D_800A78CC[];
extern u16 D_800A7CD4[];
extern FieldTalk D_800A78E4[];
extern u16 D_800A7CDC[];
extern FieldTalk D_800A78FC[];
extern u16 D_800A7CE4[];
extern FieldTalk D_800A7914[];
extern u16 D_800A7CF4[];
extern u16 D_800A7D00[];
extern FieldTalk D_800A7938[];
extern u16 D_800A7D08[];
extern FieldTalk D_800A7950[];
extern u16 D_800A7D10[];
extern u16 D_800A7D18[];
extern u16 D_800A7D20[];
extern u16 D_800A7D28[];
extern FieldTalk D_800A7968[];
extern u16 D_800A7D30[];
extern FieldTalk D_800A7980[];
extern u16 D_800A7D38[];
extern FieldTalk D_800A7998[];
extern u16 D_800A7D40[];
extern FieldTalk D_800A79B0[];
extern u16 D_800A7D48[];
extern FieldTalk D_800A79C8[];
extern u16 D_800A7D50[];
extern FieldTalk D_800A79E0[];
extern u16 D_800A7D58[];
extern FieldTalk D_800A79F8[];
extern u16 D_800A7D60[];
extern FieldTalk D_800A7A10[];
extern u16 D_800A7D68[];
extern FieldTalk D_800A7A28[];
extern u16 D_800A7D70[];
extern FieldTalk D_800A7A40[];
extern u16 D_800A7D78[];
extern FieldActorEntry D_800A7D80;
extern FieldActorEntry D_800A7D94;
extern FieldActorEntry D_800A7DA8;
extern FieldActorEntry D_800A7DBC;
extern FieldActorEntry D_800A7DD0;
extern FieldActorEntry D_800A7DE4;
extern FieldActorEntry D_800A7DF8;
extern FieldActorEntry D_800A7E0C;
extern FieldActorEntry D_800A7E20;
extern FieldActorEntry D_800A7E34;
extern FieldActorEntry D_800A7E48;
extern FieldActorEntry D_800A7E5C;
extern FieldActorEntry D_800A7E70;
extern FieldActorEntry D_800A7E84;
extern FieldActorEntry D_800A7E98;
extern FieldActorEntry D_800A7EAC;
extern FieldActorEntry D_800A7EC0;
extern FieldActorEntry D_800A7ED4;
extern FieldActorEntry D_800A7EE8;
extern FieldActorEntry D_800A7EFC;
extern FieldActorEntry D_800A7F10;
extern FieldActorEntry D_800A7F24;
extern FieldActorEntry D_800A7F38;
extern FieldActorEntry D_800A7F4C;
extern FieldActorEntry D_800A7F60;
extern FieldActorEntry D_800A7F74;
extern FieldActorEntry D_800A7F88;
extern FieldActorEntry D_800A7F9C;
extern FieldActorEntry D_800A7FB0;
extern FieldActorEntry D_800A7FC4;
extern FieldActorEntry D_800A7FD8;
extern FieldActorEntry D_800A7FEC;
extern FieldActorEntry D_800A8000;
extern FieldActorEntry D_800A8014;
extern FieldActorEntry D_800A8028;
extern FieldActorEntry D_800A803C;
extern FieldActorEntry D_800A8050;
extern FieldActorEntry D_800A8064;
extern FieldActorEntry D_800A8078;
extern FieldActorEntry D_800A808C;
extern FieldActorEntry D_800A80A0;
extern FieldActorEntry D_800A80B4;
extern FieldActorEntry D_800A80C8;
extern FieldActorEntry D_800A80DC;
extern FieldActorEntry D_800A80F0;
extern FieldActorEntry D_800A8104;
extern FieldActorEntry D_800A8118;
extern FieldActorEntry D_800A812C;
extern FieldActorEntry D_800A8140;
extern FieldActorEntry D_800A8154;
extern FieldActorEntry D_800A8168;
extern FieldActorEntry D_800A817C;
extern FieldActorEntry D_800A8190;
extern FieldActorEntry D_800A81A4;
extern FieldActorEntry D_800A81B8;
extern FieldActorEntry D_800A81CC;
extern FieldActorEntry D_800A81E0;
extern FieldActorEntry D_800A81F4;
extern FieldActorEntry D_800A8208;
extern FieldActorEntry D_800A821C;
extern FieldActorEntry D_800A8230;
extern FieldActorEntry D_800A8244;
extern FieldActorEntry D_800A8258;
extern FieldActorEntry D_800A826C;
extern FieldActorEntry D_800A8280;
extern FieldActorEntry D_800A8294;
extern FieldActorEntry D_800A82A8;
extern FieldActorEntry D_800A82BC;
extern FieldActorEntry D_800A82D0;
extern FieldActorEntry D_800A82E4;
extern FieldActorEntry D_800A82F8;
extern FieldActorEntry D_800A830C;
extern FieldActorEntry D_800A8320;
extern FieldActorEntry D_800A8334;
extern FieldActorEntry D_800A8348;
extern FieldActorEntry D_800A835C;
extern FieldActorEntry D_800A8370;
extern FieldActorEntry D_800A8384;
extern FieldActorEntry D_800A8398;
extern FieldActorEntry D_800A83AC;
extern FieldActorEntry D_800A83C0;
extern FieldActorEntry D_800A83D4;
extern FieldActorEntry D_800A83E8;
extern FieldActorEntry D_800A83FC;
extern FieldActorEntry D_800A8410;
extern FieldActorEntry D_800A8424;
extern FieldActorEntry D_800A8438;
extern FieldActorEntry D_800A844C;
extern FieldActorEntry D_800A8460;
extern FieldActorEntry D_800A8474;
extern FieldActorEntry D_800A8488;
extern FieldActorEntry D_800A849C;
extern FieldActorEntry D_800A84B0;
extern FieldActorEntry D_800A84C4;
extern FieldActorEntry D_800A84D8;
extern FieldActorEntry D_800A84EC;
extern s16 D_800A6650[];
extern s16 D_800A66A8[];
extern s16 D_800A6724[];
extern s16 D_800A6788[];
extern s16 D_800A67F4[];
extern s16 D_800A686C[];
extern s16 D_800A69EC[];
extern s16 D_800A6A48[];
extern s16 D_800A6AA4[];
extern s16 D_800A6DD0[];

s16 D_800A6650[] = {
    0x600, 1, 2,
    0x102, 2, 0x160, 0x110, 5,
    0x100, 0x20, 0x180, 0xFF,
    0x101, 0x20, 1, 1,
    0x100, 0x24, 0x1B2, 0xF7,
    0x101, 0x24, 1, 7,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 0x20, 0,
    0x301,
    0x304, 0x204, 0x160, 0x110, 5,
    0,
};
s16 D_800A66A8[] = {
    0x600, 1, 2,
    0x102, 2, 0x160, 0x110, 5,
    0x100, 0x20, 0x180, 0xFF,
    0x101, 0x20, 1, 1,
    0x100, 0x24, 0x1B2, 0xF7,
    0x101, 0x24, 1, 7,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 0x20, 0,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 2, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x150, 0x118, 1,
    0x302, 2,
    0,
};
s16 D_800A6724[] = {
    0x600, 1, 2,
    0x101, 2, 1, 1,
    0x101, 0x323, 0x325, 2,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 2, 0xB2, 0x167, 5,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 2, 2,
    0x301,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x5DE0\n");
#endif
s16 D_800A6788[] = {
    0x600, 1, 2,
    0x101, 2, 1, 7,
    0x101, 0x323, 0x325, 2,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x102, 2, 0x27F, 0x22D, 3,
    0x302, 2,
    0x101, 2, 1, 3,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 1, 2, 2,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_EU
__asm__(".section .data\n\t.half 0x4A5F\n");
#endif
s16 D_800A67F4[] = {
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 1, 0x20, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x338, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x20, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 5, 0x20, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A686C[] = {
    0x600, 1, 0x6A,
    0x100, 0x20, 0x180, 0xFF,
    0x101, 0x20, 1, 1,
    0x100, 0x24, 0x1B2, 0xF7,
    0x101, 0x24, 1, 7,
    0x100, 0x2D, 0x29F, 0x178,
    0x101, 0x2D, 1, 7,
    0x100, 0x31, 0x178, 0xD5,
    0x101, 0x31, 1, 7,
    0x100, 0x36, 0x217, 0x133,
    0x101, 0x36, 1, 1,
    0x100, 0x37, 0x148, 0x104,
    0x101, 0x37, 1, 6,
    0x100, 0x41, 0x122, 0x159,
    0x101, 0x41, 1, 5,
    0x100, 0x6A, 0x13D, 0x137,
    0x101, 0x6A, 1, 3,
    0x100, 0x6B, 0x11D, 0x127,
    0x101, 0x6B, 1, 7,
    0x300, 0x78,
    0x200, 0, 1, 0x6A, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 0x6B, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x6A, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0x6B, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 0x6A, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 0x6B, 0,
    0x301,
    0x600, 0, 0x6B,
    0x101, 0x6B, 1, 3,
    0x300, 0x1E,
    0x101, 0x6A, 1, 4,
    0x102, 0x6B, 0x11D, 0xD8, 4,
    0x302, 0x6B,
    0x102, 0x6B, 0x14A, 0xC4, 5,
    0x302, 0x6B,
    0x101, 0x32D, 0x34F, 0x6B,
    0x300, 0xC,
    0x102, 0x6B, 0x18A, 0xA4, 5,
    0x302, 0x6B,
    0x101, 0x32D, 0x355, 0x6B,
    0x300, 0x1E,
    0x600, 0, 0x6A,
    0x100, 0x6B, 0, 0,
    0x101, 0x6B, 1, 0,
    0x300, 0x1E,
    0x200, 0, 7, 0x6A, 0,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A69EC[] = {
    0x600, 1, 0x6A,
    0x101, 0x6A, 1, 1,
    0x101, 0x323, 0x325, 0x6A,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x6A,
    0x300, 0x1E,
    0x102, 0x6A, 0xE8, 0x14C, 5,
    0x302, 0x6A,
    0x101, 0x6A, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 0x6A, 3,
    0x301,
    0x101, 0x6A, 1, 5,
    0x300, 0x1E,
    0,
};
s16 D_800A6A48[] = {
    0x600, 1, 0x6A,
    0x101, 0x6A, 1, 7,
    0x101, 0x323, 0x325, 0x6A,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x6A,
    0x300, 0x1E,
    0x102, 0x6A, 0x268, 0x21C, 3,
    0x302, 0x6A,
    0x101, 0x6A, 1, 3,
    0x300, 0x1E,
    0x200, 0, 1, 0x6A, 1,
    0x301,
    0x101, 0x6A, 1, 3,
    0x300, 0x1E,
    0,
};
s16 D_800A6AA4[] = {
    0x100, 2, 0x18A, 0xA4,
    0x101, 2, 1, 1,
    0x101, 0x32D, 0x34F, 2,
    0x300, 0x1E,
    0x102, 2, 0x14A, 0xC4, 1,
    0x100, 0xB3, 0x18A, 0xA4,
    0x101, 0xB3, 1, 1,
    0x302, 2,
    0x102, 2, 0x12A, 0xD4, 5,
    0x102, 0xB3, 0x14A, 0xC4, 1,
    0x302, 0xB3,
    0x101, 2, 1, 5,
    0x101, 0xB3, 1, 1,
    0x101, 0x32D, 0x355, 2,
    0x300, 6,
    0x102, 2, 0x11A, 0xDC, 1,
    0x102, 0xB3, 0x13A, 0xCC, 1,
    0x302, 2,
    0x101, 2, 1, 5,
    0x101, 0xB3, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 2, 1,
    0x101, 2, 7, 5,
    0x301,
    0x102, 2, 0x11A, 0xFC, 4,
    0x300, 0xC,
    0x200, 0, 2, 0xB3, 2,
    0x102, 0xB3, 0x11A, 0xDC, 0,
    0x301,
    0x101, 2, 1, 4,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 3, 2, 1,
    0x101, 2, 7, 4,
    0x301,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x101, 0x323, 0x327, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 4, 0xB3, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 1,
    0x101, 2, 7, 4,
    0x301,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x200, 0, 6, 0xB3, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 1,
    0x101, 2, 7, 4,
    0x301,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x200, 0, 8, 0xB3, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 2, 1,
    0x301,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x101, 0x323, 0x327, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 2,
    0x300, 0x3C,
    0x101, 0x323, 0x325, 2,
    0x300, 0x3C,
    0x101, 2, 1, 4,
    0x101, 0x323, 0x326, 2,
    0x300, 0x1E,
    0x200, 0, 0xA, 2, 1,
    0x101, 2, 7, 4,
    0x301,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0xB3,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0xB3,
    0x300, 0x1E,
    0x101, 0xB3, 1, 0,
    0x302, 0xB3,
    0x300, 0x1E,
    0x200, 0, 0xB, 0xB3, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xC, 2, 1,
    0x101, 2, 7, 4,
    0x301,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x200, 0, 0xD, 0xB3, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xE, 2, 1,
    0x101, 2, 7, 4,
    0x301,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x200, 0, 0xF, 0xB3, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x10, 2, 1,
    0x101, 2, 7, 4,
    0x301,
    0x101, 2, 1, 4,
    0x300, 0x1E,
    0x200, 0, 0x11, 0xB3, 2,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 0,
    0x101, 0xB3, 1, 5,
    0x300, 0x1E,
    0x102, 2, 0x11A, 0x130, 0,
    0x102, 0xB3, 0x14A, 0xC4, 5,
    0x302, 2,
    0x102, 2, 0x9A, 0x170, 1,
    0x102, 0xB3, 0x18A, 0xA4, 5,
    0x101, 0x32D, 0x34F, 2,
    0x300, 0xC,
    0x304, 0x200, 0x3E8, 0xEC, 1,
    0,
};
s16 D_800A6DD0[] = {
    0x300, 0x3C,
    0x200, 0, 1, 0x20, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s32 D_800A6DE8[] = {
    28, 27, 25, 36,
};
Battle D_800A6DF8 = { 0, 0, 0x60040000 };
Battle D_800A6E04 = { 0, 0, 0x60040000 };
Battle D_800A6E10 = { 0, 0, 0x60040000 };
Battle D_800A6E1C = { 0, 0, 0x60040000 };
Battle D_800A6E28 = { 0, 0, 0x60040000 };
Battle D_800A6E34 = { 0, 0, 0x60040000 };
Battle D_800A6E40 = { 0, 0, 0x60040000 };
Battle D_800A6E4C = { 0, 0, 0x60040000 };
BattleList D_800A6E58 = {
    0,
    { &D_800A6DF8, &D_800A6E04, &D_800A6E10, &D_800A6E1C,
      &D_800A6E28, &D_800A6E34, &D_800A6E40, &D_800A6E4C },
};
Battle D_800A6E7C = { 0, 0, 0x60040000 };
Battle D_800A6E88 = { 0, 0, 0x60040000 };
Battle D_800A6E94 = { 0, 0, 0x60040000 };
Battle D_800A6EA0 = { 0, 0, 0x60040000 };
Battle D_800A6EAC = { 0, 0, 0x60040000 };
Battle D_800A6EB8 = { 0, 0, 0x60040000 };
Battle D_800A6EC4 = { 0, 0, 0x60040000 };
Battle D_800A6ED0 = { 0, 0, 0x60040000 };
BattleList D_800A6EDC = {
    0,
    { &D_800A6E7C, &D_800A6E88, &D_800A6E94, &D_800A6EA0,
      &D_800A6EAC, &D_800A6EB8, &D_800A6EC4, &D_800A6ED0 },
};
Battle D_800A6F00 = { 0, 0, 0x60040000 };
Battle D_800A6F0C = { 0, 0, 0x60040000 };
Battle D_800A6F18 = { 0, 0, 0x60040000 };
Battle D_800A6F24 = { 0, 0, 0x60040000 };
Battle D_800A6F30 = { 0, 0, 0x60040000 };
Battle D_800A6F3C = { 0, 0, 0x60040000 };
Battle D_800A6F48 = { 0, 0, 0x60040000 };
Battle D_800A6F54 = { 0, 0, 0x60040000 };
BattleList D_800A6F60 = {
    0,
    { &D_800A6F00, &D_800A6F0C, &D_800A6F18, &D_800A6F24,
      &D_800A6F30, &D_800A6F3C, &D_800A6F48, &D_800A6F54 },
};
Battle D_800A6F84 = { 188, 15, 0x60080000 };
Battle D_800A6F90 = { 0, 0, 0x60040000 };
Battle D_800A6F9C = { 0, 0, 0x60040000 };
Battle D_800A6FA8 = { 0, 0, 0x60040000 };
Battle D_800A6FB4 = { 0, 0, 0x60040000 };
Battle D_800A6FC0 = { 0, 0, 0x60040000 };
Battle D_800A6FCC = { 0, 0, 0x60040000 };
Battle D_800A6FD8 = { 0, 0, 0x60040000 };
BattleList D_800A6FE4 = {
    0,
    { &D_800A6F84, &D_800A6F90, &D_800A6F9C, &D_800A6FA8,
      &D_800A6FB4, &D_800A6FC0, &D_800A6FCC, &D_800A6FD8 },
};
FieldBattles stageBattles[] = {
    { 132, 0, 0, { &D_800A6E58, &D_800A6EDC, &D_800A6F60, &D_800A6FE4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B4, 0x100, 0x1D0, 0, 0x170, 0x1F8 },
    { 0x1C0, 0x100, 0x1E8, 0x16E, 0x2A0, 0x6E, 0x140, 0x1F7 },
    { 0x140, 0x100, 0x178, 0x139, 0xE0, 0x39, 0x150, 0x1F7 },
    { 0x180, 0x100, 0x1B6, 0x1B9, 0x1D8, 0xB9, 0x160, 0x1F7 },
    { 0x1C0, 0x100, 0x1E0, 0x16E, 0x280, 0x6E, 0x170, 0x1F7 },
    { 0x1C0, 0x100, 0x1C0, 0x16E, 0x200, 0x6E, 0x140, 0x1F6 },
    { 0x180, 0x100, 0x1A0, 0x1A0, 0x180, 0xA0, 0x150, 0x1F6 },
    { 0x180, 0x100, 0x1A0, 0x1C8, 0x180, 0xC8, 0x160, 0x1F6 },
    { 0x1C0, 0x100, 0x1D8, 0x16E, 0x260, 0x6E, 0x170, 0x1F6 },
    { 0x1C0, 0x100, 0x1C8, 0x16E, 0x220, 0x6E, 0x140, 0x1F5 },
    { 0x1C0, 0x100, 0x1C8, 0x196, 0x220, 0x96, 0x160, 0x1F5 },
    { 0x1C0, 0x100, 0x1E8, 0x1B6, 0x2A0, 0xB6, 0x170, 0x1F5 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x1C0, 0x100, 0x1D0, 0x196, 0x240, 0x96, 0x140, 0x1F4 },
    { 0x1C0, 0x100, 0x1D8, 0x196, 0x260, 0x96, 0x150, 0x1F4 },
    { 0x1C0, 0x100, 0x1E0, 0x196, 0x280, 0x96, 0x160, 0x1F4 },
    { 0x140, 0x100, 0x170, 0x139, 0xC0, 0x39, 0x170, 0x1F4 },
    { 0x1C0, 0x100, 0x1C0, 0x1B6, 0x200, 0xB6, 0x150, 0x1F3 },
    { 0x1C0, 0x100, 0x1C8, 0x1B6, 0x220, 0xB6, 0x160, 0x1F3 },
    { 0x1C0, 0x100, 0x1D0, 0x1B6, 0x240, 0xB6, 0x170, 0x1F3 },
    { 0x1C0, 0x100, 0x1D8, 0x1B6, 0x260, 0xB6, 0x140, 0x1F2 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x168, 0x139, 0xA0, 0x39, 0x150, 0x1F2 },
};
u16 D_800A7214[] = { 0x1A00, 0, 0xFFFF };
u16 D_800A721C[] = { 0x1A00, 1, 0xFFFF };
u16 D_800A7224[] = { 0x1A00, 1, 0xFFFF };
u16 D_800A722C[] = { 0x9004, 1, 0xFFFF };
u16 D_800A7234[] = { 0x901A, 1, 0xFFFF };
u16 D_800A723C[] = { 0x901A, 1, 0xFFFF };
u16 D_800A7244[] = { 0x901A, 1, 0xFFFF };
u16 D_800A724C[] = { 0x1A00, 0, 0xFFFF };
u16 D_800A7254[] = { 0x1A00, 1, 0xFFFF };
u16 D_800A725C[] = { 0x1A00, 1, 0xFFFF };
u16 D_800A7264[] = { 0x9003, 1, 0xFFFF };
u16 D_800A726C[] = { 0x9003, 1, 0xFFFF };
u16 D_800A7274[] = { 0x9003, 1, 0xFFFF };
u16 D_800A727C[] = { 0x9003, 0, 0xFFFF };
u16 D_800A7284[] = { 0x1A16, 0, 0xFFFF };
u16 D_800A728C[] = { 0x1A16, 1, 0xFFFF };
u16 D_800A7294[] = { 0x1A16, 1, 0xFFFF };
FieldTalk D_800A729C[] = {
    { D_800A7214, D_800A721C, 0x67 },
    { D_800A7224, D_800A722C, 0x486 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A72C0[] = {
    { NULL, D_800A7234, 0x67 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A72D8[] = {
    { NULL, D_800A723C, 0x429 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A72F0[] = {
    { NULL, D_800A7244, 0x42B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7308[] = {
    { D_800A724C, D_800A7254, 0x66 },
    { D_800A725C, D_800A7264, 0x34 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A732C[] = {
    { NULL, D_800A726C, 0x34 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7344[] = {
    { NULL, D_800A7274, 0x35 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A735C[] = {
    { NULL, D_800A727C, 0x37 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7374[] = {
    { NULL, NULL, 0x11 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A738C[] = {
    { NULL, NULL, 0x149 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A73A4[] = {
    { NULL, NULL, 0x1A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A73BC[] = {
    { NULL, NULL, 0x1A6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A73D4[] = {
    { NULL, NULL, 0x1A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A73EC[] = {
    { NULL, NULL, 0x1A7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7404[] = {
    { NULL, NULL, 0x1A8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A741C[] = {
    { NULL, NULL, 0x1A9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7434[] = {
    { NULL, NULL, 0x1AE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A744C[] = {
    { NULL, NULL, 0x1AA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7464[] = {
    { NULL, NULL, 0x1AB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A747C[] = {
    { NULL, NULL, 0x1AC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7494[] = {
    { NULL, NULL, 0xE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A74AC[] = {
    { NULL, NULL, 0x148 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A74C4[] = {
    { NULL, NULL, 0x199 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A74DC[] = {
    { NULL, NULL, 0x10 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A74F4[] = {
    { NULL, NULL, 0x147 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A750C[] = {
    { NULL, NULL, 0x18E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7524[] = {
    { NULL, NULL, 0xD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A753C[] = {
    { NULL, NULL, 0x14B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7554[] = {
    { NULL, NULL, 0x1BA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A756C[] = {
    { NULL, NULL, 0x1BC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7584[] = {
    { NULL, NULL, 0x1BB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A759C[] = {
    { NULL, NULL, 0x1BD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A75B4[] = {
    { NULL, NULL, 0x1BE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A75CC[] = {
    { NULL, NULL, 0x1BF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A75E4[] = {
    { NULL, NULL, 0x1C4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A75FC[] = {
    { NULL, NULL, 0x1C0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7614[] = {
    { NULL, NULL, 0x1C1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A762C[] = {
    { NULL, NULL, 0x1C2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7644[] = {
    { NULL, NULL, 0xF0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A765C[] = {
    { NULL, NULL, 0x14C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7674[] = {
    { NULL, NULL, 0x1C5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A768C[] = {
    { NULL, NULL, 0xEF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A76A4[] = {
    { NULL, NULL, 0x14A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A76BC[] = {
    { NULL, NULL, 0x1AF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A76D4[] = {
    { NULL, NULL, 0x1D1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A76EC[] = {
    { NULL, NULL, 0x1D3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7704[] = {
    { NULL, NULL, 0x1D4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A771C[] = {
    { NULL, NULL, 0x1D2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7734[] = {
    { NULL, NULL, 0x1D5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A774C[] = {
    { NULL, NULL, 0x1DA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7764[] = {
    { NULL, NULL, 0x1D6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A777C[] = {
    { NULL, NULL, 0x1D7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7794[] = {
    { NULL, NULL, 0x1D8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A77AC[] = {
    { NULL, NULL, 0x1DE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A77C4[] = {
    { NULL, NULL, 0x1DF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A77DC[] = {
    { NULL, NULL, 0x1DD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A77F4[] = {
    { NULL, NULL, 0x1DC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A780C[] = {
    { NULL, NULL, 0x1E0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7824[] = {
    { NULL, NULL, 0x1E5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A783C[] = {
    { NULL, NULL, 0x1E1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7854[] = {
    { NULL, NULL, 0x1E2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A786C[] = {
    { NULL, NULL, 0x1E3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7884[] = {
    { NULL, NULL, 0x42A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A789C[] = {
    { NULL, NULL, 0x36 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A78B4[] = {
    { NULL, NULL, 0x1AD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A78CC[] = {
    { NULL, NULL, 0x1C3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A78E4[] = {
    { NULL, NULL, 0x1D9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A78FC[] = {
    { NULL, NULL, 0x1E4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7914[] = {
    { D_800A7284, D_800A728C, 0x4F },
    { D_800A7294, NULL, 0x488 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7938[] = {
    { NULL, NULL, 0x2A4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7950[] = {
    { NULL, NULL, 0x2A3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7968[] = {
    { NULL, NULL, 0x38 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7980[] = {
    { NULL, NULL, 0x3A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7998[] = {
    { NULL, NULL, 0x3B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A79B0[] = {
    { NULL, NULL, 0x39 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A79C8[] = {
    { NULL, NULL, 0x3C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A79E0[] = {
    { NULL, NULL, 0x3D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A79F8[] = {
    { NULL, NULL, 0x41 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7A10[] = {
    { NULL, NULL, 0x3E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7A28[] = {
    { NULL, NULL, 0x3F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7A40[] = {
    { NULL, NULL, 0x40 },
    { NULL, NULL, 0 },
};
u16 D_800A7A58[] = { 0x6002, 1, 0xFFFF };
u16 D_800A7A60[] = { 0x7022, 1, 0x6016, 0, 0xFFFF };
u16 D_800A7A6C[] = { 0x6016, 1, 0xFFFF };
u16 D_800A7A74[] = { 0x602B, 1, 0xFFFF };
u16 D_800A7A7C[] = { 0x6002, 1, 0xFFFF };
u16 D_800A7A84[] = { 0x7022, 1, 0x6016, 0, 0xFFFF };
u16 D_800A7A90[] = { 0x6016, 1, 0xFFFF };
u16 D_800A7A98[] = { 0x602B, 1, 0xFFFF };
u16 D_800A7AA0[] = { 0x6002, 1, 0xFFFF };
u16 D_800A7AA8[] = { 0x6004, 1, 0xFFFF };
u16 D_800A7AB0[] = { 0x7015, 1, 0xFFFF };
u16 D_800A7AB8[] = { 0x600D, 1, 0xFFFF };
u16 D_800A7AC0[] = { 0x600C, 1, 0xFFFF };
u16 D_800A7AC8[] = { 0x600E, 1, 0xFFFF };
u16 D_800A7AD0[] = { 0x7016, 1, 0xFFFF };
u16 D_800A7AD8[] = { 0x6016, 1, 0xFFFF };
u16 D_800A7AE0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A7AE8[] = { 0x7018, 1, 0xFFFF };
u16 D_800A7AF0[] = { 0x7019, 1, 0xFFFF };
u16 D_800A7AF8[] = { 0x6026, 1, 0xFFFF };
u16 D_800A7B00[] = { 0x6017, 1, 0xFFFF };
u16 D_800A7B08[] = { 0x6002, 1, 0xFFFF };
u16 D_800A7B10[] = { 0x6004, 1, 0xFFFF };
u16 D_800A7B18[] = { 0x7015, 1, 0xFFFF };
u16 D_800A7B20[] = { 0x6002, 1, 0x8000, 0, 0xFFFF };
u16 D_800A7B2C[] = { 0x6004, 1, 0xFFFF };
u16 D_800A7B34[] = { 0x7015, 1, 0xFFFF };
u16 D_800A7B3C[] = { 0x6002, 1, 0xFFFF };
u16 D_800A7B44[] = { 0x6004, 1, 0xFFFF };
u16 D_800A7B4C[] = { 0x7015, 1, 0xFFFF };
u16 D_800A7B54[] = { 0x600D, 1, 0xFFFF };
u16 D_800A7B5C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A7B64[] = { 0x600E, 1, 0xFFFF };
u16 D_800A7B6C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A7B74[] = { 0x6016, 1, 0xFFFF };
u16 D_800A7B7C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A7B84[] = { 0x7018, 1, 0xFFFF };
u16 D_800A7B8C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A7B94[] = { 0x6026, 1, 0xFFFF };
u16 D_800A7B9C[] = { 0x6017, 1, 0xFFFF };
u16 D_800A7BA4[] = { 0x6002, 1, 0xFFFF };
u16 D_800A7BAC[] = { 0x6004, 1, 0xFFFF };
u16 D_800A7BB4[] = { 0x7015, 1, 0xFFFF };
u16 D_800A7BBC[] = { 0x6002, 1, 0xFFFF };
u16 D_800A7BC4[] = { 0x6004, 1, 0xFFFF };
u16 D_800A7BCC[] = { 0x7015, 1, 0xFFFF };
u16 D_800A7BD4[] = { 0x600C, 1, 0xFFFF };
u16 D_800A7BDC[] = { 0x600E, 1, 0xFFFF };
u16 D_800A7BE4[] = { 0x7016, 1, 0xFFFF };
u16 D_800A7BEC[] = { 0x600D, 1, 0xFFFF };
u16 D_800A7BF4[] = { 0x6016, 1, 0xFFFF };
u16 D_800A7BFC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A7C04[] = { 0x7018, 1, 0xFFFF };
u16 D_800A7C0C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A7C14[] = { 0x6026, 1, 0xFFFF };
u16 D_800A7C1C[] = { 0x6017, 1, 0xFFFF };
u16 D_800A7C24[] = { 0x600E, 1, 0xFFFF };
u16 D_800A7C2C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A7C34[] = { 0x600D, 1, 0xFFFF };
u16 D_800A7C3C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A7C44[] = { 0x6016, 1, 0xFFFF };
u16 D_800A7C4C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A7C54[] = { 0x7018, 1, 0xFFFF };
u16 D_800A7C5C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A7C64[] = { 0x6026, 1, 0xFFFF };
u16 D_800A7C6C[] = { 0x6017, 1, 0xFFFF };
u16 D_800A7C74[] = { 0x600D, 1, 0x1C0D, 0, 0xFFFF };
u16 D_800A7C80[] = { 0x600D, 1, 0x1C0D, 0, 0xFFFF };
u16 D_800A7C8C[] = { 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A7C98[] = { 0x6002, 1, 0xFFFF };
u16 D_800A7CA0[] = { 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A7CAC[] = { 0x6002, 1, 0xFFFF };
u16 D_800A7CB4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A7CBC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A7CC4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A7CCC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A7CD4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A7CDC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A7CE4[] = { 0x1A15, 1, 0x600C, 1, 0x800F, 0, 0xFFFF };
u16 D_800A7CF4[] = { 0x600D, 1, 0x1C0D, 1, 0xFFFF };
u16 D_800A7D00[] = { 0x6004, 1, 0xFFFF };
u16 D_800A7D08[] = { 0x6004, 1, 0xFFFF };
u16 D_800A7D10[] = { 0x6017, 1, 0xFFFF };
u16 D_800A7D18[] = { 0x701A, 1, 0xFFFF };
u16 D_800A7D20[] = { 0x701A, 1, 0xFFFF };
u16 D_800A7D28[] = { 0x600C, 1, 0xFFFF };
u16 D_800A7D30[] = { 0x600E, 1, 0xFFFF };
u16 D_800A7D38[] = { 0x7016, 1, 0xFFFF };
u16 D_800A7D40[] = { 0x600D, 1, 0xFFFF };
u16 D_800A7D48[] = { 0x6016, 1, 0xFFFF };
u16 D_800A7D50[] = { 0x7018, 1, 0xFFFF };
u16 D_800A7D58[] = { 0x602B, 1, 0xFFFF };
u16 D_800A7D60[] = { 0x7019, 1, 0xFFFF };
u16 D_800A7D68[] = { 0x6026, 1, 0xFFFF };
u16 D_800A7D70[] = { 0x701A, 1, 0xFFFF };
u16 D_800A7D78[] = { 0x6017, 1, 0xFFFF };
FieldActorEntry D_800A7D80 = { D_800A7A58, D_800A729C, 0x20, 4, 384, 255, 1 };
FieldActorEntry D_800A7D94 = { D_800A7A60, D_800A72C0, 0x20, 4, 384, 255, 1 };
FieldActorEntry D_800A7DA8 = { D_800A7A6C, D_800A72D8, 0x20, 4, 384, 255, 1 };
FieldActorEntry D_800A7DBC = { D_800A7A74, D_800A72F0, 0x20, 4, 384, 255, 1 };
FieldActorEntry D_800A7DD0 = { D_800A7A7C, D_800A7308, 0x24, 5, 434, 247, 7 };
FieldActorEntry D_800A7DE4 = { D_800A7A84, D_800A732C, 0x24, 5, 434, 247, 7 };
FieldActorEntry D_800A7DF8 = { D_800A7A90, D_800A7344, 0x24, 5, 434, 247, 7 };
FieldActorEntry D_800A7E0C = { D_800A7A98, D_800A735C, 0x24, 5, 434, 247, 7 };
FieldActorEntry D_800A7E20 = { D_800A7AA0, D_800A7374, 0x2D, 6, 684, 363, 7 };
FieldActorEntry D_800A7E34 = { D_800A7AA8, D_800A738C, 0x2D, 6, 684, 363, 7 };
FieldActorEntry D_800A7E48 = { D_800A7AB0, D_800A73A4, 0x2D, 6, 684, 363, 7 };
FieldActorEntry D_800A7E5C = { D_800A7AB8, D_800A73BC, 0x2D, 6, 684, 363, 7 };
FieldActorEntry D_800A7E70 = { D_800A7AC0, D_800A73D4, 0x2D, 6, 529, 505, 5 };
FieldActorEntry D_800A7E84 = { D_800A7AC8, D_800A73EC, 0x2D, 6, 529, 505, 7 };
FieldActorEntry D_800A7E98 = { D_800A7AD0, D_800A7404, 0x2D, 6, 529, 505, 7 };
FieldActorEntry D_800A7EAC = { D_800A7AD8, D_800A741C, 0x2D, 6, 529, 505, 7 };
FieldActorEntry D_800A7EC0 = { D_800A7AE0, D_800A7434, 0x2D, 6, 305, 353, 7 };
FieldActorEntry D_800A7ED4 = { D_800A7AE8, D_800A744C, 0x2D, 6, 529, 505, 7 };
FieldActorEntry D_800A7EE8 = { D_800A7AF0, D_800A7464, 0x2D, 6, 529, 505, 7 };
FieldActorEntry D_800A7EFC = { D_800A7AF8, D_800A747C, 0x2D, 6, 529, 505, 7 };
FieldActorEntry D_800A7F10 = { D_800A7B00, NULL, 0x2D, 6, 529, 505, 7 };
FieldActorEntry D_800A7F24 = { D_800A7B08, D_800A7494, 0x2E, 7, 391, 359, 1 };
FieldActorEntry D_800A7F38 = { D_800A7B10, D_800A74AC, 0x2E, 7, 391, 359, 1 };
FieldActorEntry D_800A7F4C = { D_800A7B18, D_800A74C4, 0x2E, 7, 391, 359, 1 };
FieldActorEntry D_800A7F60 = { D_800A7B20, D_800A74DC, 0x2F, 8, 617, 501, 1 };
FieldActorEntry D_800A7F74 = { D_800A7B2C, D_800A74F4, 0x2F, 8, 617, 501, 1 };
FieldActorEntry D_800A7F88 = { D_800A7B34, D_800A750C, 0x2F, 8, 617, 501, 1 };
FieldActorEntry D_800A7F9C = { D_800A7B3C, D_800A7524, 0x31, 9, 361, 221, 7 };
FieldActorEntry D_800A7FB0 = { D_800A7B44, D_800A753C, 0x31, 9, 361, 221, 7 };
FieldActorEntry D_800A7FC4 = { D_800A7B4C, D_800A7554, 0x31, 9, 361, 221, 7 };
FieldActorEntry D_800A7FD8 = { D_800A7B54, D_800A756C, 0x31, 9, 361, 221, 7 };
FieldActorEntry D_800A7FEC = { D_800A7B5C, D_800A7584, 0x31, 9, 193, 257, 7 };
FieldActorEntry D_800A8000 = { D_800A7B64, D_800A759C, 0x31, 9, 193, 257, 7 };
FieldActorEntry D_800A8014 = { D_800A7B6C, D_800A75B4, 0x31, 9, 193, 257, 7 };
FieldActorEntry D_800A8028 = { D_800A7B74, D_800A75CC, 0x31, 9, 193, 257, 7 };
FieldActorEntry D_800A803C = { D_800A7B7C, D_800A75E4, 0x31, 9, 391, 359, 7 };
FieldActorEntry D_800A8050 = { D_800A7B84, D_800A75FC, 0x31, 9, 193, 257, 7 };
FieldActorEntry D_800A8064 = { D_800A7B8C, D_800A7614, 0x31, 9, 193, 257, 7 };
FieldActorEntry D_800A8078 = { D_800A7B94, D_800A762C, 0x31, 9, 193, 257, 7 };
FieldActorEntry D_800A808C = { D_800A7B9C, NULL, 0x31, 9, 193, 257, 7 };
FieldActorEntry D_800A80A0 = { D_800A7BA4, D_800A7644, 0x33, 0xA, 529, 505, 7 };
FieldActorEntry D_800A80B4 = { D_800A7BAC, D_800A765C, 0x33, 0xA, 529, 505, 7 };
FieldActorEntry D_800A80C8 = { D_800A7BB4, D_800A7674, 0x33, 0xA, 529, 505, 7 };
FieldActorEntry D_800A80DC = { D_800A7BBC, D_800A768C, 0x34, 0xB, 193, 257, 7 };
FieldActorEntry D_800A80F0 = { D_800A7BC4, D_800A76A4, 0x34, 0xB, 193, 257, 7 };
FieldActorEntry D_800A8104 = { D_800A7BCC, D_800A76BC, 0x34, 0xB, 193, 257, 7 };
FieldActorEntry D_800A8118 = { D_800A7BD4, D_800A76D4, 0x36, 0xC, 535, 307, 1 };
FieldActorEntry D_800A812C = { D_800A7BDC, D_800A76EC, 0x36, 0xC, 535, 307, 1 };
FieldActorEntry D_800A8140 = { D_800A7BE4, D_800A7704, 0x36, 0xC, 535, 307, 1 };
FieldActorEntry D_800A8154 = { D_800A7BEC, D_800A771C, 0x36, 0xC, 535, 307, 1 };
FieldActorEntry D_800A8168 = { D_800A7BF4, D_800A7734, 0x36, 0xC, 535, 307, 1 };
FieldActorEntry D_800A817C = { D_800A7BFC, D_800A774C, 0x36, 0xC, 193, 257, 7 };
FieldActorEntry D_800A8190 = { D_800A7C04, D_800A7764, 0x36, 0xC, 535, 307, 1 };
FieldActorEntry D_800A81A4 = { D_800A7C0C, D_800A777C, 0x36, 0xC, 535, 307, 1 };
FieldActorEntry D_800A81B8 = { D_800A7C14, D_800A7794, 0x36, 0xC, 535, 307, 1 };
FieldActorEntry D_800A81CC = { D_800A7C1C, NULL, 0x36, 0xC, 535, 307, 1 };
FieldActorEntry D_800A81E0 = { D_800A7C24, D_800A77AC, 0x37, 0xD, 328, 260, 6 };
FieldActorEntry D_800A81F4 = { D_800A7C2C, D_800A77C4, 0x37, 0xD, 328, 260, 6 };
FieldActorEntry D_800A8208 = { D_800A7C34, D_800A77DC, 0x37, 0xD, 328, 260, 6 };
FieldActorEntry D_800A821C = { D_800A7C3C, D_800A77F4, 0x37, 0xD, 328, 260, 6 };
FieldActorEntry D_800A8230 = { D_800A7C44, D_800A780C, 0x37, 0xD, 328, 260, 6 };
FieldActorEntry D_800A8244 = { D_800A7C4C, D_800A7824, 0x37, 0xD, 684, 363, 3 };
FieldActorEntry D_800A8258 = { D_800A7C54, D_800A783C, 0x37, 0xD, 328, 260, 6 };
FieldActorEntry D_800A826C = { D_800A7C5C, D_800A7854, 0x37, 0xD, 328, 260, 6 };
FieldActorEntry D_800A8280 = { D_800A7C64, D_800A786C, 0x37, 0xD, 328, 260, 6 };
FieldActorEntry D_800A8294 = { D_800A7C6C, NULL, 0x37, 0xD, 328, 260, 6 };
FieldActorEntry D_800A82A8 = { D_800A7C74, NULL, 0x6A, 0xE, 0, 0, 1 };
FieldActorEntry D_800A82BC = { D_800A7C80, NULL, 0x6B, 0xF, 0, 0, 1 };
FieldActorEntry D_800A82D0 = { D_800A7C8C, NULL, 0x70, 0x10, 360, 268, 1 };
FieldActorEntry D_800A82E4 = { D_800A7C98, NULL, 0x70, 0x10, 360, 268, 1 };
FieldActorEntry D_800A82F8 = { D_800A7CA0, NULL, 0x71, 0x11, 450, 254, 7 };
FieldActorEntry D_800A830C = { D_800A7CAC, NULL, 0x71, 0x11, 450, 254, 7 };
FieldActorEntry D_800A8320 = { D_800A7CB4, D_800A7884, 0x9D, 0x12, 384, 255, 1 };
FieldActorEntry D_800A8334 = { D_800A7CBC, D_800A789C, 0x9E, 0x13, 434, 247, 7 };
FieldActorEntry D_800A8348 = { D_800A7CC4, D_800A78B4, 0x9F, 0x14, 529, 505, 7 };
FieldActorEntry D_800A835C = { D_800A7CCC, D_800A78CC, 0xA0, 0x15, 193, 257, 7 };
FieldActorEntry D_800A8370 = { D_800A7CD4, D_800A78E4, 0xA2, 0x16, 535, 307, 1 };
FieldActorEntry D_800A8384 = { D_800A7CDC, D_800A78FC, 0xAE, 0x17, 328, 260, 6 };
FieldActorEntry D_800A8398 = { D_800A7CE4, D_800A7914, 0xB2, 0x18, 285, 295, 5 };
FieldActorEntry D_800A83AC = { D_800A7CF4, NULL, 0xB2, 0x18, 0, 0, 1 };
FieldActorEntry D_800A83C0 = { D_800A7D00, D_800A7938, 0xB2, 0x18, 285, 295, 7 };
FieldActorEntry D_800A83D4 = { D_800A7D08, D_800A7950, 0xB3, 0x19, 308, 305, 3 };
FieldActorEntry D_800A83E8 = { D_800A7D10, NULL, 0xB3, 0x19, 0, 0, 1 };
FieldActorEntry D_800A83FC = { D_800A7D18, NULL, 0x10E, 0x1A, 360, 268, 1 };
FieldActorEntry D_800A8410 = { D_800A7D20, NULL, 0x10F, 0x1B, 450, 254, 7 };
FieldActorEntry D_800A8424 = { D_800A7D28, D_800A7968, 0x175, 0x1C, 305, 353, 5 };
FieldActorEntry D_800A8438 = { D_800A7D30, D_800A7980, 0x175, 0x1C, 305, 353, 5 };
FieldActorEntry D_800A844C = { D_800A7D38, D_800A7998, 0x175, 0x1C, 305, 353, 5 };
FieldActorEntry D_800A8460 = { D_800A7D40, D_800A79B0, 0x175, 0x1C, 305, 353, 5 };
FieldActorEntry D_800A8474 = { D_800A7D48, D_800A79C8, 0x175, 0x1C, 305, 353, 5 };
FieldActorEntry D_800A8488 = { D_800A7D50, D_800A79E0, 0x175, 0x1C, 305, 353, 5 };
FieldActorEntry D_800A849C = { D_800A7D58, D_800A79F8, 0x175, 0x1C, 617, 501, 5 };
FieldActorEntry D_800A84B0 = { D_800A7D60, D_800A7A10, 0x175, 0x1C, 305, 353, 5 };
FieldActorEntry D_800A84C4 = { D_800A7D68, D_800A7A28, 0x175, 0x1C, 305, 353, 5 };
FieldActorEntry D_800A84D8 = { D_800A7D70, D_800A7A40, 0x175, 0x1C, 305, 353, 5 };
FieldActorEntry D_800A84EC = { D_800A7D78, NULL, 0x175, 0x1C, 305, 353, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A7D80,
    &D_800A7D94,
    &D_800A7DA8,
    &D_800A7DBC,
    &D_800A7DD0,
    &D_800A7DE4,
    &D_800A7DF8,
    &D_800A7E0C,
    &D_800A7E20,
    &D_800A7E34,
    &D_800A7E48,
    &D_800A7E5C,
    &D_800A7E70,
    &D_800A7E84,
    &D_800A7E98,
    &D_800A7EAC,
    &D_800A7EC0,
    &D_800A7ED4,
    &D_800A7EE8,
    &D_800A7EFC,
    &D_800A7F10,
    &D_800A7F24,
    &D_800A7F38,
    &D_800A7F4C,
    &D_800A7F60,
    &D_800A7F74,
    &D_800A7F88,
    &D_800A7F9C,
    &D_800A7FB0,
    &D_800A7FC4,
    &D_800A7FD8,
    &D_800A7FEC,
    &D_800A8000,
    &D_800A8014,
    &D_800A8028,
    &D_800A803C,
    &D_800A8050,
    &D_800A8064,
    &D_800A8078,
    &D_800A808C,
    &D_800A80A0,
    &D_800A80B4,
    &D_800A80C8,
    &D_800A80DC,
    &D_800A80F0,
    &D_800A8104,
    &D_800A8118,
    &D_800A812C,
    &D_800A8140,
    &D_800A8154,
    &D_800A8168,
    &D_800A817C,
    &D_800A8190,
    &D_800A81A4,
    &D_800A81B8,
    &D_800A81CC,
    &D_800A81E0,
    &D_800A81F4,
    &D_800A8208,
    &D_800A821C,
    &D_800A8230,
    &D_800A8244,
    &D_800A8258,
    &D_800A826C,
    &D_800A8280,
    &D_800A8294,
    &D_800A82A8,
    &D_800A82BC,
    &D_800A82D0,
    &D_800A82E4,
    &D_800A82F8,
    &D_800A830C,
    &D_800A8320,
    &D_800A8334,
    &D_800A8348,
    &D_800A835C,
    &D_800A8370,
    &D_800A8384,
    &D_800A8398,
    &D_800A83AC,
    &D_800A83C0,
    &D_800A83D4,
    &D_800A83E8,
    &D_800A83FC,
    &D_800A8410,
    &D_800A8424,
    &D_800A8438,
    &D_800A844C,
    &D_800A8460,
    &D_800A8474,
    &D_800A8488,
    &D_800A849C,
    &D_800A84B0,
    &D_800A84C4,
    &D_800A84D8,
    &D_800A84EC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x36, 2, 0, 1, 4, 0, 243, 69, 0, 0 },
    { 1, 0, 0x40, 2, 0x37, 2, 0, 1, 4, 0, 802, 278, 0, 0 },
    { 1, 0, 0x40, 2, 0x33, 2, 0, 1, 4, 0, 457, 129, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 0x16, 0, 339, 212, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 0x16, 0, 372, 196, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 0x16, 0, 403, 244, 0, 0 },
    { 1, 0, 0x40, 2, 0x32, 2, 0, 3, 0x16, 0, 435, 228, 0, 0 },
    { 1, 0, 0x40, 2, 0x55, 2, 0, 7, 0x12, 0, 386, 117, 0, 0 },
    { 1, 0, 0x40, 2, 0x55, 2, 0, 7, 0x12, 0, 546, 197, 0, 0 },
    { 1, 0, 0x40, 2, 0x55, 2, 0, 7, 0x12, 0, 674, 197, 0, 0 },
    { 1, 0, 0x40, 2, 0x56, 2, 0, 7, 0x12, 0, 573, 209, 0, 0 },
    { 1, 0, 0x40, 2, 0x56, 2, 0, 7, 0x12, 0, 613, 209, 0, 0 },
    { 1, 0, 0x40, 2, 0x57, 2, 0, 7, 0x12, 0, 151, 129, 0, 0 },
    { 1, 0, 0x40, 2, 0x57, 2, 0, 7, 0x12, 0, 411, 111, 0, 0 },
    { 1, 0, 0x40, 2, 0x57, 2, 0, 7, 0x12, 0, 649, 200, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 10, 105, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 42, 121, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 74, 137, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 290, 69, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 322, 85, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 354, 101, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 482, 165, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 514, 181, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 706, 213, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 738, 229, 0, 0 },
    { 1, 0, 0x40, 6, 0x55, 2, 0, 7, 0x12, 0, 770, 245, 0, 0 },
    { 1, 0, 0x40, 6, 0x57, 2, 0, 7, 0x12, 0, 119, 145, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 135, 232, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 155, 222, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 175, 212, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 195, 202, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 215, 192, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 235, 182, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 255, 172, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 275, 162, 0, 0 },
    { 1, 0, 0x40, 6, 0x58, 2, 0, 7, 0x12, 0, 295, 152, 0, 0 },
    { 1, 0x66, 0x40, 6, 4, 0, 0, 0, 0, 0, 335, 141, 0, 0 },
    { 1, 0x65, 0x40, 6, 5, 0, 0, 0, 0, 0, 511, 229, 0, 0 },
    { 1, 0x64, 0x40, 6, 6, 0, 0, 0, 0, 0, 736, 326, 0, 0 },
    { 1, 0, 0x40, 6, 0x34, 2, 0, 3, 4, 0, 114, 179, 0, 0 },
    { 1, 0, 0x40, 6, 0x35, 2, 0, 3, 4, 0, 264, 130, 0, 0 },
    { 1, 0, 0x40, 6, 0x59, 2, 0, 3, 4, 0, 429, 176, 0, 0 },
    { 1, 0, 0x40, 6, 0x51, 1, 0x51, 0x54, 8, 0, 585, 335, 0, 0 },
    { 1, 0, 0x40, 6, 0x4D, 1, 0x4D, 0x50, 8, 0, 585, 335, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x38, 1, 0x38, 0x3A, 0xA, 0, 28, 519, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x38, 1, 0x38, 0x3A, 0xA, 0, 81, 492, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x38, 1, 0x38, 0x3A, 0xA, 0, 183, 442, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x38, 1, 0x38, 0x3A, 0xA, 0, 237, 424, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x38, 1, 0x38, 0x3A, 0xA, 0, 656, 492, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x38, 1, 0x38, 0x3A, 0xA, 0, 752, 431, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 55, 506, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 100, 493, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 151, 461, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 202, 445, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 296, 424, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3B, 1, 0x3B, 0x3D, 0xA, 0, 657, 504, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 259, 428, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 366, 433, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 582, 411, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 661, 442, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 674, 537, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 694, 538, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x3E, 1, 0x3E, 0x40, 0xA, 0, 778, 417, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x41, 1, 0x41, 0x43, 0xA, 0, 449, 517, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x41, 1, 0x41, 0x43, 0xA, 0, 501, 544, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x41, 1, 0x41, 0x43, 0xA, 0, 530, 355, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x41, 1, 0x41, 0x43, 0xA, 0, 546, 354, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x41, 1, 0x41, 0x43, 0xA, 0, 636, 592, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x41, 1, 0x41, 0x43, 0xA, 0, 659, 600, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x44, 1, 0x44, 0x46, 0xA, 0, 87, 303, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x44, 1, 0x44, 0x46, 0xA, 0, 130, 322, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x44, 1, 0x44, 0x46, 0xA, 0, 682, 614, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x49, 0xA, 0, 61, 292, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x49, 0xA, 0, 113, 328, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x49, 0xA, 0, 474, 531, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x47, 1, 0x47, 0x49, 0xA, 0, 529, 554, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 437, 427, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 455, 421, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 608, 405, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 626, 396, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 654, 525, 0, 0 },
    { 1, 0, 0x40, 0xA, 0x4A, 1, 0x4A, 0x4C, 0xA, 0, 691, 424, 0, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 144, 110, 160, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 359, 148, 193, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 535, 236, 281, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 759, 332, 376, 0 },
    { 1, 0, 0x50, 4, 7, 0, 0, 0, 0, 0, 441, 345, 450, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 464, 444, 496, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 595, 442, 478, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 384, 259, 279, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 401, 250, 271, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 368, 251, 270, 0 },
    { 1, 0, 0x40, 4, 0xD, 0, 0, 0, 0, 0, 417, 243, 264, 0 },
    { 1, 0, 0x40, 4, 0xE, 0, 0, 0, 0, 0, 352, 242, 262, 0 },
    { 1, 0, 0x40, 4, 0xF, 0, 0, 0, 0, 0, 433, 233, 255, 0 },
    { 1, 0, 0x40, 4, 0x10, 0, 0, 0, 0, 0, 336, 229, 255, 0 },
    { 1, 0, 0x40, 4, 0x11, 0, 0, 0, 0, 0, 449, 227, 247, 0 },
    { 1, 0, 0x40, 4, 0x12, 0, 0, 0, 0, 0, 320, 227, 247, 0 },
    { 1, 0, 0x40, 4, 0x13, 0, 0, 0, 0, 0, 337, 219, 240, 0 },
    { 1, 0, 0x40, 4, 0x14, 0, 0, 0, 0, 0, 353, 208, 231, 0 },
    { 1, 0, 0x40, 4, 0x15, 0, 0, 0, 0, 0, 369, 203, 223, 0 },
    { 1, 0, 0x40, 4, 0x16, 0, 0, 0, 0, 0, 385, 192, 215, 0 },
    { 1, 0, 0x40, 4, 0x17, 0, 0, 0, 0, 0, 401, 187, 207, 0 },
    { 1, 0, 0x40, 4, 0x18, 0, 0, 0, 0, 0, 499, 317, 334, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x200, 0x3E8, 0xEC, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x206, 0x70, 0xF0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x207, 0x58, 0x1CC, 5, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x208, 0x69, 0x134, 5, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x214, 0x1F8, 0x2BC, 5, 0x66, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x217, 0x1D8, 0x1D4, 3, 0, 0, 0 },
    { { { 0x6002, 1 }, { 0xFFFF, 0 } }, 8, 0x14, 0, 0, 0, 0, 0, 0 },
    { { { 0x6002, 1 }, { 0xFFFF, 0 } }, 8, 0x1E, 0, 0, 0, 0, 0, 0 },
    { { { 0x600D, 1 }, { 0xFFFF, 0 } }, 8, 0x140, 0, 0, 0, 0, 0, 0 },
    { { { 0x600D, 1 }, { 0xFFFF, 0 } }, 8, 0x14A, 0, 0, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageFuncs stageFuncs = { setupStage, startTween, updateTween };
FieldEvent stageEvents[] = {
    { 8, NULL, EVENT_TEXT(1), func_800A568C, NULL },
    { 9, NULL, EVENT_TEXT(2), func_800A5C54, NULL },
    { 13, D_800A6650, EVENT_TEXT(6), NULL, NULL },
    { 14, D_800A66A8, EVENT_TEXT(7), NULL, NULL },
    { 20, D_800A6724, EVENT_TEXT(8), NULL, NULL },
    { 30, D_800A6788, EVENT_TEXT(9), NULL, NULL },
    { 58, D_800A67F4, EVENT_TEXT(0x12), NULL, NULL },
    { 310, D_800A686C, EVENT_TEXT(0x1C), NULL, func_800A636C },
    { 320, D_800A69EC, EVENT_TEXT(0x1D), NULL, NULL },
    { 330, D_800A6A48, EVENT_TEXT(0x1E), NULL, NULL },
    { 685, D_800A6AA4, EVENT_TEXT(0x22), NULL, func_800A63B8 },
    { 1510, NULL, EVENT_TEXT(0x35), func_800A621C, NULL },
    { 1511, D_800A6DD0, EVENT_TEXT(0x30), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
