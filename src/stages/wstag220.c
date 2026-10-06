#include "common.h"
#define STAGE_TWEEN /* stageFuncs is a StageFuncs (stage.h) */
#include "stage.h"
void func_800A58C8();
void func_800A5300();
void func_800A4D38();

/* The text file of the menus, which the versions number differently */
#if VERSION_US
#define MENU_TEXT 0x10C
#elif VERSION_EU
#define MENU_TEXT 0x112
#endif

/* A two-option menu: creates the event object of the chosen option */
void func_800A4D38(StageMenu *task, StageMenuChildren *children) {
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
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x36)), j + 2);
                }
                children->cursor->setVisible(children->cursor, 1);
                children->title->setString(children->title, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x36)), 1);
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
            children->event = FIELDSTG_startEvent(task->cursor == 0 ? 0x35 : 0x5E9);
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

void *func_800A52D4(void) {
    return createTask(func_800A4D38, 0x64, 0x14);
}

/* A two-option menu: creates the event object of the chosen option */
void func_800A5300(StageMenu *task, StageMenuChildren *children) {
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
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x37)), j + 2);
                }
                children->cursor->setVisible(children->cursor, 1);
                children->title->setString(children->title, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x37)), 1);
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
            children->event = FIELDSTG_startEvent(task->cursor == 0 ? 0x37 : 0x5EB);
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

void *func_800A589C(void) {
    return createTask(func_800A5300, 0x64, 0x14);
}

/* A two-option menu: creates the event object of the chosen option */
void func_800A58C8(StageMenu *task, StageMenuChildren *children) {
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
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x38)), j + 2);
                }
                children->cursor->setVisible(children->cursor, 1);
                children->title->setString(children->title, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x38)), 1);
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
            children->event = FIELDSTG_startEvent(task->cursor == 0 ? 0x38 : 0x5ED);
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

void *func_800A5E64(void) {
    return createTask(func_800A58C8, 0x64, 0x14);
}

#include "common/update_stage.inc.c"

#include "common/start_stage.inc.c"

/* the color the setup copies to D_800990B4.spriteColor */
const CVECTOR stageColor = { 0x54, 0x67, 0x96, 0 };

#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x18F
#define STAGE_ARCHIVE 0x2C7
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x19D
#define STAGE_ARCHIVE 0x2D6
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16 | 1;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x10200, 0x15700};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x33;
    D_800990B4.music = 0x60CC0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.spriteColor = stageColor;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16);
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

extern u16 D_800A651C[];
extern u16 D_800A6524[];
extern u16 D_800A652C[];
extern u16 D_800A6538[];
extern u16 D_800A6540[];
extern u16 D_800A654C[];
extern u16 D_800A6554[];
extern u16 D_800A655C[];
extern u16 D_800A6564[];
extern u16 D_800A656C[];
extern u16 D_800A6574[];
extern u16 D_800A657C[];
extern u16 D_800A6584[];
extern u16 D_800A658C[];
extern u16 D_800A6594[];
extern u16 D_800A659C[];
extern u16 D_800A65A4[];
extern u16 D_800A65AC[];
extern u16 D_800A65B4[];
extern u16 D_800A65BC[];
extern u16 D_800A65C4[];
extern u16 D_800A65CC[];
extern u16 D_800A65D4[];
extern u16 D_800A65DC[];
extern u16 D_800A65E4[];
extern u16 D_800A65EC[];
extern u16 D_800A65F4[];
extern u16 D_800A6854[];
extern FieldTalk D_800A65FC[];
extern u16 D_800A6860[];
extern FieldTalk D_800A662C[];
extern u16 D_800A6868[];
extern FieldTalk D_800A6650[];
extern u16 D_800A6870[];
extern FieldTalk D_800A6674[];
extern u16 D_800A687C[];
extern FieldTalk D_800A6698[];
extern u16 D_800A6884[];
extern FieldTalk D_800A66B0[];
extern u16 D_800A688C[];
extern FieldTalk D_800A66C8[];
extern u16 D_800A6894[];
extern FieldTalk D_800A66E0[];
extern u16 D_800A689C[];
extern FieldTalk D_800A66F8[];
extern u16 D_800A68A4[];
extern FieldTalk D_800A6710[];
extern u16 D_800A68AC[];
extern FieldTalk D_800A6728[];
extern u16 D_800A68B4[];
extern FieldTalk D_800A6740[];
extern u16 D_800A68BC[];
extern FieldTalk D_800A6758[];
extern u16 D_800A68C4[];
extern FieldTalk D_800A6770[];
extern u16 D_800A68CC[];
extern FieldTalk D_800A6788[];
extern u16 D_800A68D4[];
extern FieldTalk D_800A67A0[];
extern u16 D_800A68DC[];
extern FieldTalk D_800A67B8[];
extern u16 D_800A68E8[];
extern FieldTalk D_800A67DC[];
extern u16 D_800A68F0[];
extern u16 D_800A68F8[];
extern u16 D_800A6900[];
extern u16 D_800A6908[];
extern u16 D_800A6910[];
extern u16 D_800A6918[];
extern u16 D_800A6920[];
extern FieldTalk D_800A67F4[];
extern u16 D_800A6928[];
extern FieldTalk D_800A680C[];
extern u16 D_800A6930[];
extern FieldTalk D_800A6824[];
extern u16 D_800A6938[];
extern u16 D_800A6940[];
extern FieldTalk D_800A683C[];
extern u16 D_800A6948[];
extern u16 D_800A6950[];
extern FieldActorEntry D_800A6958;
extern FieldActorEntry D_800A696C;
extern FieldActorEntry D_800A6980;
extern FieldActorEntry D_800A6994;
extern FieldActorEntry D_800A69A8;
extern FieldActorEntry D_800A69BC;
extern FieldActorEntry D_800A69D0;
extern FieldActorEntry D_800A69E4;
extern FieldActorEntry D_800A69F8;
extern FieldActorEntry D_800A6A0C;
extern FieldActorEntry D_800A6A20;
extern FieldActorEntry D_800A6A34;
extern FieldActorEntry D_800A6A48;
extern FieldActorEntry D_800A6A5C;
extern FieldActorEntry D_800A6A70;
extern FieldActorEntry D_800A6A84;
extern FieldActorEntry D_800A6A98;
extern FieldActorEntry D_800A6AAC;
extern FieldActorEntry D_800A6AC0;
extern FieldActorEntry D_800A6AD4;
extern FieldActorEntry D_800A6AE8;
extern FieldActorEntry D_800A6AFC;
extern FieldActorEntry D_800A6B10;
extern FieldActorEntry D_800A6B24;
extern FieldActorEntry D_800A6B38;
extern FieldActorEntry D_800A6B4C;
extern FieldActorEntry D_800A6B60;
extern FieldActorEntry D_800A6B74;
extern FieldActorEntry D_800A6B88;
extern FieldActorEntry D_800A6B9C;
extern FieldActorEntry D_800A6BB0;
extern s16 D_800A618C[];
extern s16 D_800A6214[];
extern s16 D_800A6294[];
extern s16 D_800A630C[];
extern s16 D_800A6394[];
extern s16 D_800A63AC[];
extern s16 D_800A63C4[];

s16 D_800A618C[] = {
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 1, 0x24, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x338, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 0x20, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 7, 0x24, 2,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x3E0\n");
#endif
s16 D_800A6214[] = {
    0x102, 2, 0xBA, 0xF8, 5,
    0x100, 0x20, 0xDC, 0xE8,
    0x101, 0x20, 1, 1,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 5,
    0x300, 0x1E,
    0x200, 0, 1, 0x20, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x338, 2,
    0x300, 0x1E,
    0x200, 0, 2, 0x32D, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 3, 0x20, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A6294[] = {
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
s16 D_800A630C[] = {
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
    0x200, 0, 5, 2, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 6, 0x20, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A6394[] = {
    0x300, 0x3C,
    0x200, 0, 1, 0x24, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A63AC[] = {
    0x300, 0x3C,
    0x200, 0, 1, 0x20, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A63C4[] = {
    0x300, 0x3C,
    0x200, 0, 1, 0x20, 2,
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
    { 0x140, 0x100, 0x16E, 0x178, 0xB8, 0x78, 0x150, 0x1F7 },
    { 0x140, 0x100, 0x176, 0x178, 0xD8, 0x78, 0x160, 0x1F7 },
    { 0x140, 0x100, 0x140, 0x17E, 0, 0x7E, 0x170, 0x1F7 },
    { 0x140, 0x100, 0x160, 0x180, 0x80, 0x80, 0x150, 0x1F6 },
    { 0x140, 0x100, 0x148, 0x17E, 0x20, 0x7E, 0x160, 0x1F6 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0x140, 0x100, 0x150, 0x19E, 0x40, 0x9E, 0x170, 0x1F6 },
    { 0x140, 0x100, 0x158, 0x1A0, 0x60, 0xA0, 0x140, 0x1F5 },
    { 0x140, 0x100, 0x166, 0x1A0, 0x98, 0xA0, 0x150, 0x1F5 },
    { 0x140, 0x100, 0x16E, 0x1A0, 0xB8, 0xA0, 0x160, 0x1F5 },
    { 0x140, 0x100, 0x176, 0x1A0, 0xD8, 0xA0, 0x170, 0x1F5 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A651C[] = { 0x1A06, 0, 0xFFFF };
u16 D_800A6524[] = { 0x1A06, 1, 0xFFFF };
u16 D_800A652C[] = { 0x1A06, 1, 0x700D, 0, 0xFFFF };
u16 D_800A6538[] = { 0x9007, 1, 0xFFFF };
u16 D_800A6540[] = { 0x1A06, 1, 0x700D, 1, 0xFFFF };
u16 D_800A654C[] = { 0x9008, 1, 0xFFFF };
u16 D_800A6554[] = { 0x700D, 0, 0xFFFF };
u16 D_800A655C[] = { 0x9007, 1, 0xFFFF };
u16 D_800A6564[] = { 0x700D, 1, 0xFFFF };
u16 D_800A656C[] = { 0x9008, 1, 0xFFFF };
u16 D_800A6574[] = { 0x700D, 0, 0xFFFF };
u16 D_800A657C[] = { 0x9007, 1, 0xFFFF };
u16 D_800A6584[] = { 0x700D, 1, 0xFFFF };
u16 D_800A658C[] = { 0x9008, 1, 0xFFFF };
u16 D_800A6594[] = { 0x1A07, 0, 0xFFFF };
u16 D_800A659C[] = { 0x1A07, 1, 0xFFFF };
u16 D_800A65A4[] = { 0x1A07, 1, 0xFFFF };
u16 D_800A65AC[] = { 0x9005, 1, 0xFFFF };
u16 D_800A65B4[] = { 0x9005, 1, 0xFFFF };
u16 D_800A65BC[] = { 0x700D, 0, 0xFFFF };
u16 D_800A65C4[] = { 0x9005, 1, 0xFFFF };
u16 D_800A65CC[] = { 0x1A04, 0, 0xFFFF };
u16 D_800A65D4[] = { 0x1A04, 1, 0xFFFF };
u16 D_800A65DC[] = { 0x1A04, 1, 0xFFFF };
u16 D_800A65E4[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A65EC[] = { 0x7C00, 1, 0xFFFF };
u16 D_800A65F4[] = { 0x7C00, 1, 0xFFFF };
FieldTalk D_800A65FC[] = {
    { D_800A651C, D_800A6524, 2 },
    { D_800A652C, D_800A6538, 0x41F },
    { D_800A6540, D_800A654C, 0x41F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A662C[] = {
    { D_800A6554, D_800A655C, 0x424 },
    { D_800A6564, D_800A656C, 0x424 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6650[] = {
    { D_800A6574, D_800A657C, 0x41F },
    { D_800A6584, D_800A658C, 0x41F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6674[] = {
    { D_800A6594, D_800A659C, 3 },
    { D_800A65A4, D_800A65AC, 0x420 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6698[] = {
    { NULL, D_800A65B4, 0x425 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A66B0[] = {
    { D_800A65BC, D_800A65C4, 0x420 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A66C8[] = {
    { NULL, NULL, 1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A66E0[] = {
    { NULL, NULL, 0x198 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A66F8[] = {
    { NULL, NULL, 0x18F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6710[] = {
    { NULL, NULL, 0x190 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6728[] = {
    { NULL, NULL, 0x191 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6740[] = {
    { NULL, NULL, 0x192 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6758[] = {
    { NULL, NULL, 0x193 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6770[] = {
    { NULL, NULL, 0x194 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6788[] = {
    { NULL, NULL, 0x195 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A67A0[] = {
    { NULL, NULL, 0x196 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A67B8[] = {
    { D_800A65CC, D_800A65D4, 4 },
    { D_800A65DC, D_800A65E4, 0xF1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A67DC[] = {
    { NULL, D_800A65EC, 0x426 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A67F4[] = {
    { NULL, NULL, 0x421 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A680C[] = {
    { NULL, NULL, 0x422 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6824[] = {
    { NULL, D_800A65F4, 0x423 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A683C[] = {
    { NULL, NULL, 0x197 },
    { NULL, NULL, 0 },
};
u16 D_800A6854[] = { 0x7022, 1, 0x6016, 0, 0xFFFF };
u16 D_800A6860[] = { 0x6016, 1, 0xFFFF };
u16 D_800A6868[] = { 0x602B, 1, 0xFFFF };
u16 D_800A6870[] = { 0x6016, 0, 0x7022, 1, 0xFFFF };
u16 D_800A687C[] = { 0x6016, 1, 0xFFFF };
u16 D_800A6884[] = { 0x602B, 1, 0xFFFF };
u16 D_800A688C[] = { 0x6004, 1, 0xFFFF };
u16 D_800A6894[] = { 0x602B, 1, 0xFFFF };
u16 D_800A689C[] = { 0x7015, 1, 0xFFFF };
u16 D_800A68A4[] = { 0x600C, 1, 0xFFFF };
u16 D_800A68AC[] = { 0x600E, 1, 0xFFFF };
u16 D_800A68B4[] = { 0x7016, 1, 0xFFFF };
u16 D_800A68BC[] = { 0x6016, 1, 0xFFFF };
u16 D_800A68C4[] = { 0x7018, 1, 0xFFFF };
u16 D_800A68CC[] = { 0x7019, 1, 0xFFFF };
u16 D_800A68D4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A68DC[] = { 0x6016, 0, 0x7022, 1, 0xFFFF };
u16 D_800A68E8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A68F0[] = { 0x701E, 1, 0xFFFF };
u16 D_800A68F8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A6900[] = { 0x7022, 1, 0xFFFF };
u16 D_800A6908[] = { 0x602B, 1, 0xFFFF };
u16 D_800A6910[] = { 0x7022, 1, 0xFFFF };
u16 D_800A6918[] = { 0x602B, 1, 0xFFFF };
u16 D_800A6920[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6928[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6930[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6938[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6940[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6948[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6950[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A6958 = { D_800A6854, D_800A65FC, 0x20, 4, 187, 215, 1 };
FieldActorEntry D_800A696C = { D_800A6860, D_800A662C, 0x20, 4, 187, 215, 1 };
FieldActorEntry D_800A6980 = { D_800A6868, D_800A6650, 0x20, 4, 187, 215, 1 };
FieldActorEntry D_800A6994 = { D_800A6870, D_800A6674, 0x24, 5, 220, 232, 1 };
FieldActorEntry D_800A69A8 = { D_800A687C, D_800A6698, 0x24, 5, 220, 232, 1 };
FieldActorEntry D_800A69BC = { D_800A6884, D_800A66B0, 0x24, 5, 220, 232, 1 };
FieldActorEntry D_800A69D0 = { D_800A688C, D_800A66C8, 0x32, 6, 65, 263, 7 };
FieldActorEntry D_800A69E4 = { D_800A6894, D_800A66E0, 0x32, 6, 65, 263, 7 };
FieldActorEntry D_800A69F8 = { D_800A689C, D_800A66F8, 0x32, 6, 65, 263, 7 };
FieldActorEntry D_800A6A0C = { D_800A68A4, D_800A6710, 0x32, 6, 65, 263, 7 };
FieldActorEntry D_800A6A20 = { D_800A68AC, D_800A6728, 0x32, 6, 65, 263, 7 };
FieldActorEntry D_800A6A34 = { D_800A68B4, D_800A6740, 0x32, 6, 65, 263, 7 };
FieldActorEntry D_800A6A48 = { D_800A68BC, D_800A6758, 0x32, 6, 65, 263, 7 };
FieldActorEntry D_800A6A5C = { D_800A68C4, D_800A6770, 0x32, 6, 65, 263, 7 };
FieldActorEntry D_800A6A70 = { D_800A68CC, D_800A6788, 0x32, 6, 65, 263, 7 };
FieldActorEntry D_800A6A84 = { D_800A68D4, D_800A67A0, 0x32, 6, 65, 263, 7 };
FieldActorEntry D_800A6A98 = { D_800A68DC, D_800A67B8, 0x43, 7, 399, 248, 1 };
FieldActorEntry D_800A6AAC = { D_800A68E8, D_800A67DC, 0x43, 7, 399, 248, 1 };
FieldActorEntry D_800A6AC0 = { D_800A68F0, NULL, 0x59, 8, 300, 217, 5 };
FieldActorEntry D_800A6AD4 = { D_800A68F8, NULL, 0x59, 8, 300, 217, 5 };
FieldActorEntry D_800A6AE8 = { D_800A6900, NULL, 0x70, 9, 169, 224, 0 };
FieldActorEntry D_800A6AFC = { D_800A6908, NULL, 0x70, 9, 169, 224, 0 };
FieldActorEntry D_800A6B10 = { D_800A6910, NULL, 0x71, 0xA, 202, 241, 0 };
FieldActorEntry D_800A6B24 = { D_800A6918, NULL, 0x71, 0xA, 202, 241, 0 };
FieldActorEntry D_800A6B38 = { D_800A6920, D_800A67F4, 0x9D, 0xB, 187, 215, 1 };
FieldActorEntry D_800A6B4C = { D_800A6928, D_800A680C, 0x9E, 0xC, 220, 232, 1 };
FieldActorEntry D_800A6B60 = { D_800A6930, D_800A6824, 0x9F, 0xD, 399, 248, 1 };
FieldActorEntry D_800A6B74 = { D_800A6938, NULL, 0xA0, 0xE, 300, 217, 5 };
FieldActorEntry D_800A6B88 = { D_800A6940, D_800A683C, 0xA1, 0xF, 65, 263, 7 };
FieldActorEntry D_800A6B9C = { D_800A6948, NULL, 0x10E, 0x10, 169, 224, 0 };
FieldActorEntry D_800A6BB0 = { D_800A6950, NULL, 0x10F, 0x11, 202, 241, 0 };
FieldActorEntry *stageActors[] = {
    &D_800A6958,
    &D_800A696C,
    &D_800A6980,
    &D_800A6994,
    &D_800A69A8,
    &D_800A69BC,
    &D_800A69D0,
    &D_800A69E4,
    &D_800A69F8,
    &D_800A6A0C,
    &D_800A6A20,
    &D_800A6A34,
    &D_800A6A48,
    &D_800A6A5C,
    &D_800A6A70,
    &D_800A6A84,
    &D_800A6A98,
    &D_800A6AAC,
    &D_800A6AC0,
    &D_800A6AD4,
    &D_800A6AE8,
    &D_800A6AFC,
    &D_800A6B10,
    &D_800A6B24,
    &D_800A6B38,
    &D_800A6B4C,
    &D_800A6B60,
    &D_800A6B74,
    &D_800A6B88,
    &D_800A6B9C,
    &D_800A6BB0,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x203, 0x2C8, 0x24C, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x200, 0x410, 0x200, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageFuncs stageFuncs = { setupStage, startTween, updateTween };
FieldEvent stageEvents[] = {
    { 53, D_800A618C, EVENT_TEXT(0xD), NULL, NULL },
    { 54, D_800A6214, EVENT_TEXT(0xE), NULL, NULL },
    { 55, D_800A6294, EVENT_TEXT(0xF), NULL, NULL },
    { 56, D_800A630C, EVENT_TEXT(0x10), NULL, NULL },
    { 1512, NULL, EVENT_TEXT(0x36), func_800A52D4, NULL },
    { 1513, D_800A6394, EVENT_TEXT(0x31), NULL, NULL },
    { 1514, NULL, EVENT_TEXT(0x37), func_800A589C, NULL },
    { 1515, D_800A63AC, EVENT_TEXT(0x32), NULL, NULL },
    { 1516, NULL, EVENT_TEXT(0x38), func_800A5E64, NULL },
    { 1517, D_800A63C4, EVENT_TEXT(0x33), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
