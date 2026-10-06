#include "common.h"
#define STAGE_TWEEN /* stageFuncs is a StageFuncs (stage.h) */
#include "stage.h"
void func_800A52CC();
void func_800A4D04();

/* The text file of the menus, which the versions number differently */
#if VERSION_US
#define MENU_TEXT 0x11A
#elif VERSION_EU
#define MENU_TEXT 0x120
#endif

/* A two-option menu: creates the event object of the chosen option */
void func_800A4D04(StageMenu *task, StageMenuChildren *children) {
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
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x5)), j + 2);
                }
                children->cursor->setVisible(children->cursor, 1);
                children->title->setString(children->title, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x5)), 1);
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
            children->event = FIELDSTG_startEvent(task->cursor == 0 ? 0x3B : 0x5EF);
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

void *func_800A52A0(void) {
    return createTask(func_800A4D04, 0x64, 0x14);
}

/* A two-option menu: creates the event object of the chosen option */
void func_800A52CC(StageMenu *task, StageMenuChildren *children) {
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
                    children->options[j]->setString(children->options[j], FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x6)), j + 2);
                }
                children->cursor->setVisible(children->cursor, 1);
                children->title->setString(children->title, FILE_CACHE.getEntry(TEXT_ENTRY(MENU_TEXT, 0x6)), 1);
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
            children->event = FIELDSTG_startEvent(task->cursor == 0 ? 0x41 : 0x5F1);
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

void *func_800A5868(void) {
    return createTask(func_800A52CC, 0x64, 0x14);
}

#include "common/update_stage.inc.c"

#include "common/start_stage.inc.c"

/* Sets flags 0x8192, 0x1A1C and 0x40A1 */
void func_800A5938(void) {
    FLAGS_00.applyAction(0x8192, 1);
    FLAGS_00.applyAction(0x1A1C, 1);
    FLAGS_00.applyAction(0x40A1, 1);
}

#if VERSION_US
#define STAGE_TEXT 0xCD
#define EVENT_TEXT_FILE 0x119
#define STAGE_FILE 0x1A1
#define STAGE_ARCHIVE 0x3C2
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xC5)
#define EVENT_TEXT_FILE 0x120
#define STAGE_FILE 0x1AF
#define STAGE_ARCHIVE 0x3D2
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x1A400, 0xC800};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 8;
    D_800990B4.music = 0x60200000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

#include "common/start_tween.inc.c"
#include "common/update_tween.inc.c"

void func_800A5938();
extern u16 D_800A6144[];
extern u16 D_800A614C[];
extern u16 D_800A6154[];
extern u16 D_800A615C[];
extern u16 D_800A616C[];
extern u16 D_800A6178[];
extern u16 D_800A6188[];
extern u16 D_800A6190[];
extern u16 D_800A61A0[];
extern u16 D_800A61A8[];
extern u16 D_800A61BC[];
extern u16 D_800A61D4[];
extern u16 D_800A61DC[];
extern u16 D_800A61F4[];
extern u16 D_800A61FC[];
extern u16 D_800A6204[];
extern u16 D_800A6210[];
extern u16 D_800A6218[];
extern u16 D_800A6224[];
extern u16 D_800A6230[];
extern u16 D_800A6238[];
extern u16 D_800A6240[];
extern u16 D_800A624C[];
extern u16 D_800A625C[];
extern u16 D_800A6264[];
extern u16 D_800A6274[];
extern u16 D_800A627C[];
extern u16 D_800A6284[];
extern u16 D_800A628C[];
extern u16 D_800A6298[];
extern u16 D_800A62A8[];
extern u16 D_800A62B0[];
extern u16 D_800A62C0[];
extern u16 D_800A62C8[];
extern u16 D_800A62D0[];
extern u16 D_800A62E0[];
extern u16 D_800A62EC[];
extern u16 D_800A62FC[];
extern u16 D_800A6304[];
extern u16 D_800A6314[];
extern u16 D_800A631C[];
extern u16 D_800A6330[];
extern u16 D_800A6348[];
extern u16 D_800A6350[];
extern u16 D_800A6368[];
extern u16 D_800A6370[];
extern u16 D_800A6378[];
extern u16 D_800A6384[];
extern u16 D_800A638C[];
extern u16 D_800A6398[];
extern u16 D_800A63A4[];
extern u16 D_800A63AC[];
extern u16 D_800A63B4[];
extern u16 D_800A63C0[];
extern u16 D_800A63D0[];
extern u16 D_800A63D8[];
extern u16 D_800A63E8[];
extern u16 D_800A63F0[];
extern u16 D_800A63F8[];
extern u16 D_800A6400[];
extern u16 D_800A640C[];
extern u16 D_800A641C[];
extern u16 D_800A6424[];
extern u16 D_800A6434[];
extern u16 D_800A643C[];
extern u16 D_800A6444[];
extern u16 D_800A644C[];
extern u16 D_800A6454[];
extern u16 D_800A6464[];
extern u16 D_800A6470[];
extern u16 D_800A6480[];
extern u16 D_800A6488[];
extern u16 D_800A6498[];
extern u16 D_800A64A0[];
extern u16 D_800A64B4[];
extern u16 D_800A64CC[];
extern u16 D_800A64D4[];
extern u16 D_800A64EC[];
extern u16 D_800A64F4[];
extern u16 D_800A64FC[];
extern u16 D_800A6508[];
extern u16 D_800A6510[];
extern u16 D_800A651C[];
extern u16 D_800A6528[];
extern u16 D_800A6530[];
extern u16 D_800A6538[];
extern u16 D_800A6544[];
extern u16 D_800A6554[];
extern u16 D_800A655C[];
extern u16 D_800A656C[];
extern u16 D_800A6574[];
extern u16 D_800A657C[];
extern u16 D_800A6584[];
extern u16 D_800A6590[];
extern u16 D_800A65A0[];
extern u16 D_800A65A8[];
extern u16 D_800A65B8[];
extern u16 D_800A65C0[];
extern u16 D_800A65C8[];
extern u16 D_800A65D8[];
extern u16 D_800A65E4[];
extern u16 D_800A65F4[];
extern u16 D_800A65FC[];
extern u16 D_800A660C[];
extern u16 D_800A6614[];
extern u16 D_800A6628[];
extern u16 D_800A6640[];
extern u16 D_800A6648[];
extern u16 D_800A6660[];
extern u16 D_800A6668[];
extern u16 D_800A6670[];
extern u16 D_800A6678[];
extern u16 D_800A6684[];
extern u16 D_800A6694[];
extern u16 D_800A669C[];
extern u16 D_800A66AC[];
extern u16 D_800A66B4[];
extern u16 D_800A66BC[];
extern u16 D_800A66C4[];
extern u16 D_800A66D0[];
extern u16 D_800A66E0[];
extern u16 D_800A66E8[];
extern u16 D_800A66F8[];
extern u16 D_800A6700[];
extern u16 D_800A6708[];
extern u16 D_800A6714[];
extern u16 D_800A671C[];
extern u16 D_800A6728[];
extern u16 D_800A6734[];
extern u16 D_800A673C[];
extern u16 D_800A6748[];
extern u16 D_800A6758[];
extern u16 D_800A6760[];
extern u16 D_800A6770[];
extern u16 D_800A6778[];
extern u16 D_800A6780[];
extern u16 D_800A678C[];
extern u16 D_800A679C[];
extern u16 D_800A67A4[];
extern u16 D_800A67B4[];
extern u16 D_800A67BC[];
extern u16 D_800A67C4[];
extern u16 D_800A67D0[];
extern u16 D_800A67E0[];
extern u16 D_800A67E8[];
extern u16 D_800A67F8[];
extern u16 D_800A6800[];
extern u16 D_800A6808[];
extern u16 D_800A6814[];
extern u16 D_800A6824[];
extern u16 D_800A682C[];
extern u16 D_800A683C[];
extern u16 D_800A6844[];
extern u16 D_800A6850[];
extern u16 D_800A6858[];
extern u16 D_800A6864[];
extern u16 D_800A686C[];
extern u16 D_800A6874[];
extern u16 D_800A687C[];
extern u16 D_800A6884[];
extern u16 D_800A688C[];
extern u16 D_800A6894[];
extern u16 D_800A689C[];
extern u16 D_800A68A4[];
extern u16 D_800A68AC[];
extern u16 D_800A68B8[];
extern u16 D_800A68C0[];
extern u16 D_800A68C8[];
extern u16 D_800A68D0[];
extern u16 D_800A68D8[];
extern u16 D_800A68E0[];
extern u16 D_800A68E8[];
extern u16 D_800A68F0[];
extern u16 D_800A68F8[];
extern u16 D_800A6904[];
extern u16 D_800A6FCC[];
extern FieldTalk D_800A690C[];
extern u16 D_800A6FD4[];
extern FieldTalk D_800A6924[];
extern u16 D_800A6FDC[];
extern FieldTalk D_800A693C[];
extern u16 D_800A6FE4[];
extern FieldTalk D_800A699C[];
extern u16 D_800A6FF0[];
extern FieldTalk D_800A69CC[];
extern u16 D_800A6FFC[];
extern FieldTalk D_800A6A08[];
extern u16 D_800A7008[];
extern FieldTalk D_800A6A44[];
extern u16 D_800A7014[];
extern FieldTalk D_800A6A5C[];
extern u16 D_800A701C[];
extern FieldTalk D_800A6ABC[];
extern u16 D_800A7028[];
extern FieldTalk D_800A6AEC[];
extern u16 D_800A7034[];
extern FieldTalk D_800A6B28[];
extern u16 D_800A7040[];
extern FieldTalk D_800A6B64[];
extern u16 D_800A704C[];
extern FieldTalk D_800A6B7C[];
extern u16 D_800A7054[];
extern FieldTalk D_800A6B94[];
extern u16 D_800A705C[];
extern FieldTalk D_800A6BAC[];
extern u16 D_800A7064[];
extern FieldTalk D_800A6C0C[];
extern u16 D_800A7070[];
extern FieldTalk D_800A6C3C[];
extern u16 D_800A707C[];
extern FieldTalk D_800A6C78[];
extern u16 D_800A7088[];
extern FieldTalk D_800A6CB4[];
extern u16 D_800A7094[];
extern FieldTalk D_800A6CCC[];
extern u16 D_800A709C[];
extern FieldTalk D_800A6D2C[];
extern u16 D_800A70A8[];
extern FieldTalk D_800A6D68[];
extern u16 D_800A70B4[];
extern FieldTalk D_800A6DA4[];
extern u16 D_800A70C0[];
extern FieldTalk D_800A6DD4[];
extern u16 D_800A70CC[];
extern FieldTalk D_800A6DEC[];
extern u16 D_800A70D4[];
extern FieldTalk D_800A6E04[];
extern u16 D_800A70DC[];
extern FieldTalk D_800A6E40[];
extern u16 D_800A70E4[];
extern FieldTalk D_800A6E7C[];
extern u16 D_800A70EC[];
extern FieldTalk D_800A6EB8[];
extern u16 D_800A70F4[];
extern FieldTalk D_800A6EF4[];
extern u16 D_800A70FC[];
extern FieldTalk D_800A6F0C[];
extern u16 D_800A7108[];
extern FieldTalk D_800A6F90[];
extern u16 D_800A7118[];
extern FieldTalk D_800A6FB4[];
extern u16 D_800A7124[];
extern u16 D_800A712C[];
extern FieldActorEntry D_800A7134;
extern FieldActorEntry D_800A7148;
extern FieldActorEntry D_800A715C;
extern FieldActorEntry D_800A7170;
extern FieldActorEntry D_800A7184;
extern FieldActorEntry D_800A7198;
extern FieldActorEntry D_800A71AC;
extern FieldActorEntry D_800A71C0;
extern FieldActorEntry D_800A71D4;
extern FieldActorEntry D_800A71E8;
extern FieldActorEntry D_800A71FC;
extern FieldActorEntry D_800A7210;
extern FieldActorEntry D_800A7224;
extern FieldActorEntry D_800A7238;
extern FieldActorEntry D_800A724C;
extern FieldActorEntry D_800A7260;
extern FieldActorEntry D_800A7274;
extern FieldActorEntry D_800A7288;
extern FieldActorEntry D_800A729C;
extern FieldActorEntry D_800A72B0;
extern FieldActorEntry D_800A72C4;
extern FieldActorEntry D_800A72D8;
extern FieldActorEntry D_800A72EC;
extern FieldActorEntry D_800A7300;
extern FieldActorEntry D_800A7314;
extern FieldActorEntry D_800A7328;
extern FieldActorEntry D_800A733C;
extern FieldActorEntry D_800A7350;
extern FieldActorEntry D_800A7364;
extern FieldActorEntry D_800A7378;
extern FieldActorEntry D_800A738C;
extern FieldActorEntry D_800A73A0;
extern FieldActorEntry D_800A73B4;
extern FieldActorEntry D_800A73C8;
extern FieldActorEntry D_800A73DC;
extern FieldActorEntry D_800A73F0;
extern s16 D_800A5B84[];
extern s16 D_800A5C2C[];
extern s16 D_800A5CC8[];
extern s16 D_800A5F8C[];
extern s16 D_800A5FA4[];

s16 D_800A5B84[] = {
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 1, 0x33, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x338, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x33, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 5, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 6, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 2, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 8, 0x33, 2,
    0x301,
    0x300, 0x1E,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x4644\n");
#elif VERSION_EU
__asm__(".section .data\n\t.half 0x104\n");
#endif
s16 D_800A5C2C[] = {
    0x102, 2, 0x117, 0xBD, 3,
    0x101, 0x2D, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 1, 0x2D, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x338, 2,
    0x300, 0x1E,
    0x200, 0, 2, 2, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 3, 0x2D, 4,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 4,
    0x301,
    0x300, 0x1E,
    0x101, 0x32D, 0x339, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 5, 0x2D, 2,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0x300, 0x1E,
    0,
};
s16 D_800A5CC8[] = {
    0x102, 2, 0x19B, 0xA3, 3,
    0x101, 0x2F, 1, 7,
    0x101, 0x32, 1, 7,
    0x101, 0x34, 1, 3,
    0x101, 0x37, 1, 3,
    0x101, 0xCE, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x200, 0, 1, 0xCE, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 3, 0xCE, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 4, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0xCE,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0xCE,
    0x300, 0x1E,
    0x200, 0, 5, 0xCE, 2,
    0x301,
    0x300, 0x1E,
    0x601, 0, 0xD0, 0xE1,
    0x300, 0x96,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0x34,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0x34,
    0x300, 0x1E,
    0x200, 0, 6, 0x34, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 0x34, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 8, 0x2F, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 9, 0x34, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xA, 0x2F, 2,
    0x301,
    0x300, 0x1E,
    0x200, 1, 0xC, 0x2F, 2,
    0x200, 0, 0xB, 0x34, 1,
    0x301,
    0x101, 0x323, 0x325, 0x34,
    0x300, 0x5A,
    0x101, 0x323, 0x326, 0x34,
    0x300, 0x1E,
    0x200, 0, 0xD, 0x34, 1,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0xE, 0x2F, 2,
    0x301,
    0x300, 0x1E,
    0x101, 0x323, 0x327, 0x34,
    0x300, 0xB4,
    0x200, 0, 0xF, 0x32, 0,
    0x301,
    0x101, 0x323, 0x326, 0x34,
    0x101, 0x324, 0x325, 0x37,
    0x300, 0x5A,
    0x101, 0x324, 0x326, 0x37,
    0x300, 0x1E,
    0x200, 0, 0x10, 0x37, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x11, 0x32, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x12, 0x37, 2,
    0x301,
    0x101, 0x323, 0x327, 0x37,
    0x300, 0x1E,
    0x200, 0, 0x13, 0x32, 0,
    0x301,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x37,
    0x300, 0x1E,
    0x200, 0, 0x14, 0x37, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x15, 0x32, 0,
    0x301,
    0x600, 0, 2,
    0x300, 0x5A,
    0x200, 0, 0x16, 0xCE, 2,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 0x17, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 0x18, 0xCE, 2,
    0x301,
    0x300, 0x1E,
    0x200, 0, 0x19, 2, 1,
    0x101, 2, 7, 3,
    0x301,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x200, 0, 0x1A, 0xCE, 2,
    0x301,
    0x300, 0x1E,
    0x101, 2, 1, 7,
    0x300, 0x1E,
    0,
};
s16 D_800A5F8C[] = {
    0x300, 0x3C,
    0x200, 0, 1, 0x33, 2,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A5FA4[] = {
    0x102, 2, 0x117, 0xBD, 3,
    0x101, 0x2D, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x300, 0x1E,
    0x300, 0x1E,
    0x200, 0, 1, 0x2D, 2,
    0x301,
    0x101, 2, 1, 7,
    0x300, 0x1E,
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
    { 0x180, 0x100, 0x1B8, 0x159, 0x1E0, 0x59, 0x160, 0x1FB },
    { 0x180, 0x100, 0x1B0, 0x159, 0x1C0, 0x59, 0x170, 0x1FB },
    { 0x180, 0x100, 0x1A0, 0x15D, 0x180, 0x5D, 0x150, 0x1FA },
    { 0x180, 0x100, 0x1A8, 0x15D, 0x1A0, 0x5D, 0x160, 0x1FA },
    { 0x180, 0x100, 0x190, 0x171, 0x140, 0x71, 0x170, 0x1FA },
    { 0x180, 0x100, 0x198, 0x171, 0x160, 0x71, 0x140, 0x1F9 },
    { 0x140, 0x100, 0x140, 0x1D8, 0, 0xD8, 0x150, 0x1F9 },
    { 0x180, 0x100, 0x180, 0x172, 0x100, 0x72, 0x160, 0x1F9 },
    { 0x180, 0x100, 0x188, 0x172, 0x120, 0x72, 0x170, 0x1F9 },
    { 0x180, 0x100, 0x1B0, 0x181, 0x1C0, 0x81, 0x140, 0x1F8 },
    { 0x180, 0x100, 0x1A0, 0x185, 0x180, 0x85, 0x150, 0x1F8 },
    { 0x180, 0x100, 0x1A8, 0x185, 0x1A0, 0x85, 0x160, 0x1F8 },
    { 0x180, 0x100, 0x1B4, 0x100, 0x1D0, 0, 0x170, 0x1F8 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A6144[] = { 0x901C, 1, 0xFFFF };
u16 D_800A614C[] = { 0x901C, 1, 0xFFFF };
u16 D_800A6154[] = { 0x8192, 0, 0xFFFF };
u16 D_800A615C[] = { 0x8192, 1, 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A616C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A6178[] = { 0x8192, 1, 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A6188[] = { 0x11, 0, 0xFFFF };
u16 D_800A6190[] = { 2, 0, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A61A0[] = { 2, 1, 0xFFFF };
u16 D_800A61A8[] = { 2, 1, 0x7200, 0, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A61BC[] = {
    0x7204, 0, 0x7200, 1, 2, 1, 0x8192, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A61D4[] = { 0x7603, 1, 0xFFFF };
u16 D_800A61DC[] = {
    2, 1, 0x7200, 1, 0x7204, 1, 0x8192, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A61F4[] = { 0x7803, 1, 0xFFFF };
u16 D_800A61FC[] = { 0x11, 0, 0xFFFF };
u16 D_800A6204[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A6210[] = { 0x11, 0, 0xFFFF };
u16 D_800A6218[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6224[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A6230[] = { 2, 0, 0xFFFF };
u16 D_800A6238[] = { 2, 1, 0xFFFF };
u16 D_800A6240[] = { 2, 1, 0x7200, 0, 0xFFFF };
u16 D_800A624C[] = { 2, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A625C[] = { 0x7603, 1, 0xFFFF };
u16 D_800A6264[] = { 2, 1, 0x7200, 1, 0x7204, 1, 0xFFFF };
u16 D_800A6274[] = { 0x7803, 1, 0xFFFF };
u16 D_800A627C[] = { 2, 0, 0xFFFF };
u16 D_800A6284[] = { 2, 1, 0xFFFF };
u16 D_800A628C[] = { 2, 1, 0x7200, 0, 0xFFFF };
u16 D_800A6298[] = { 2, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A62A8[] = { 0x7603, 1, 0xFFFF };
u16 D_800A62B0[] = { 2, 1, 0x7200, 1, 0x7204, 1, 0xFFFF };
u16 D_800A62C0[] = { 0x7803, 1, 0xFFFF };
u16 D_800A62C8[] = { 0x8192, 0, 0xFFFF };
u16 D_800A62D0[] = { 0x8192, 1, 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A62E0[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A62EC[] = { 0x8192, 1, 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A62FC[] = { 0x11, 0, 0xFFFF };
u16 D_800A6304[] = { 3, 0, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A6314[] = { 3, 1, 0xFFFF };
u16 D_800A631C[] = { 3, 1, 0x7200, 0, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A6330[] = {
    3, 1, 0x7200, 1, 0x7204, 0, 0x8192, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A6348[] = { 0x7604, 1, 0xFFFF };
u16 D_800A6350[] = {
    3, 1, 0x7200, 1, 0x7204, 1, 0x8192, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A6368[] = { 0x7804, 1, 0xFFFF };
u16 D_800A6370[] = { 0x11, 0, 0xFFFF };
u16 D_800A6378[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A6384[] = { 0x11, 0, 0xFFFF };
u16 D_800A638C[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A6398[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A63A4[] = { 3, 0, 0xFFFF };
u16 D_800A63AC[] = { 3, 1, 0xFFFF };
u16 D_800A63B4[] = { 0x7200, 0, 3, 1, 0xFFFF };
u16 D_800A63C0[] = { 3, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A63D0[] = { 0x7604, 1, 0xFFFF };
u16 D_800A63D8[] = { 0x7204, 1, 3, 1, 0x7200, 1, 0xFFFF };
u16 D_800A63E8[] = { 0x7804, 1, 0xFFFF };
u16 D_800A63F0[] = { 3, 0, 0xFFFF };
u16 D_800A63F8[] = { 3, 1, 0xFFFF };
u16 D_800A6400[] = { 3, 1, 0x7200, 0, 0xFFFF };
u16 D_800A640C[] = { 3, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A641C[] = { 0x7604, 1, 0xFFFF };
u16 D_800A6424[] = { 3, 1, 0x7200, 1, 0x7204, 1, 0xFFFF };
u16 D_800A6434[] = { 0x7804, 1, 0xFFFF };
u16 D_800A643C[] = { 0x901B, 1, 0xFFFF };
u16 D_800A6444[] = { 0x901B, 1, 0xFFFF };
u16 D_800A644C[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6454[] = { 0x8192, 1, 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A6464[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A6470[] = { 0x8192, 1, 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A6480[] = { 0x11, 0, 0xFFFF };
u16 D_800A6488[] = { 0, 0, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A6498[] = { 0, 1, 0xFFFF };
u16 D_800A64A0[] = { 0, 1, 0x7200, 0, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A64B4[] = {
    0, 1, 0x7204, 0, 0x7200, 1, 0x8192, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A64CC[] = { 0x7601, 1, 0xFFFF };
u16 D_800A64D4[] = {
    0x7200, 1, 0, 1, 0x7204, 1, 0x8192, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A64EC[] = { 0x7801, 1, 0xFFFF };
u16 D_800A64F4[] = { 0x11, 0, 0xFFFF };
u16 D_800A64FC[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A6508[] = { 0x11, 0, 0xFFFF };
u16 D_800A6510[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A651C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A6528[] = { 0, 0, 0xFFFF };
u16 D_800A6530[] = { 0, 1, 0xFFFF };
u16 D_800A6538[] = { 0, 1, 0x7200, 0, 0xFFFF };
u16 D_800A6544[] = { 0, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A6554[] = { 0x7601, 1, 0xFFFF };
u16 D_800A655C[] = { 0, 1, 0x7200, 1, 0x7204, 1, 0xFFFF };
u16 D_800A656C[] = { 0x7801, 1, 0xFFFF };
u16 D_800A6574[] = { 0, 0, 0xFFFF };
u16 D_800A657C[] = { 0, 1, 0xFFFF };
u16 D_800A6584[] = { 0, 1, 0x7200, 0, 0xFFFF };
u16 D_800A6590[] = { 0, 1, 0x7204, 0, 0x7200, 1, 0xFFFF };
u16 D_800A65A0[] = { 0x7601, 1, 0xFFFF };
u16 D_800A65A8[] = { 0, 1, 0x7200, 1, 0x7204, 1, 0xFFFF };
u16 D_800A65B8[] = { 0x7801, 1, 0xFFFF };
u16 D_800A65C0[] = { 0x8192, 0, 0xFFFF };
u16 D_800A65C8[] = { 0x8192, 1, 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A65D8[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A65E4[] = { 0x8192, 1, 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A65F4[] = { 0x11, 0, 0xFFFF };
u16 D_800A65FC[] = { 1, 0, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A660C[] = { 1, 1, 0xFFFF };
u16 D_800A6614[] = { 1, 1, 0x7200, 0, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A6628[] = {
    1, 1, 0x7200, 1, 0x7204, 0, 0x8192, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A6640[] = { 0x7602, 1, 0xFFFF };
u16 D_800A6648[] = {
    1, 1, 0x7200, 1, 0x7204, 1, 0x8192, 1,
    0x11, 0, 0xFFFF,
};
u16 D_800A6660[] = { 0x7802, 1, 0xFFFF };
u16 D_800A6668[] = { 1, 0, 0xFFFF };
u16 D_800A6670[] = { 1, 1, 0xFFFF };
u16 D_800A6678[] = { 1, 1, 0x7200, 0, 0xFFFF };
u16 D_800A6684[] = { 1, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A6694[] = { 0x7602, 1, 0xFFFF };
u16 D_800A669C[] = { 1, 1, 0x7200, 1, 0x7204, 1, 0xFFFF };
u16 D_800A66AC[] = { 0x7802, 1, 0xFFFF };
u16 D_800A66B4[] = { 1, 0, 0xFFFF };
u16 D_800A66BC[] = { 1, 1, 0xFFFF };
u16 D_800A66C4[] = { 1, 1, 0x7200, 0, 0xFFFF };
u16 D_800A66D0[] = { 1, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A66E0[] = { 0x7602, 1, 0xFFFF };
u16 D_800A66E8[] = { 1, 1, 0x7204, 1, 0x7200, 1, 0xFFFF };
u16 D_800A66F8[] = { 0x7802, 1, 0xFFFF };
u16 D_800A6700[] = { 0x11, 0, 0xFFFF };
u16 D_800A6708[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A6714[] = { 0x11, 0, 0xFFFF };
u16 D_800A671C[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A6728[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A6734[] = { 2, 0, 0xFFFF };
u16 D_800A673C[] = { 2, 1, 0x7200, 0, 0xFFFF };
u16 D_800A6748[] = { 2, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A6758[] = { 0x7603, 1, 0xFFFF };
u16 D_800A6760[] = { 2, 1, 0x7200, 1, 0x7204, 1, 0xFFFF };
u16 D_800A6770[] = { 0x7803, 1, 0xFFFF };
u16 D_800A6778[] = { 0, 0, 0xFFFF };
u16 D_800A6780[] = { 0, 1, 0x7200, 0, 0xFFFF };
u16 D_800A678C[] = { 0, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A679C[] = { 0x7601, 1, 0xFFFF };
u16 D_800A67A4[] = { 0, 1, 0x7200, 1, 0x7204, 1, 0xFFFF };
u16 D_800A67B4[] = { 0x7801, 1, 0xFFFF };
u16 D_800A67BC[] = { 3, 0, 0xFFFF };
u16 D_800A67C4[] = { 3, 1, 0x7200, 0, 0xFFFF };
u16 D_800A67D0[] = { 3, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A67E0[] = { 0x7604, 1, 0xFFFF };
u16 D_800A67E8[] = { 3, 1, 0x7200, 1, 0x7204, 1, 0xFFFF };
u16 D_800A67F8[] = { 0x7804, 1, 0xFFFF };
u16 D_800A6800[] = { 1, 0, 0xFFFF };
u16 D_800A6808[] = { 1, 1, 0x7200, 0, 0xFFFF };
u16 D_800A6814[] = { 1, 1, 0x7200, 1, 0x7204, 0, 0xFFFF };
u16 D_800A6824[] = { 0x7602, 1, 0xFFFF };
u16 D_800A682C[] = { 1, 1, 0x7200, 1, 0x7204, 1, 0xFFFF };
u16 D_800A683C[] = { 0x7802, 1, 0xFFFF };
u16 D_800A6844[] = { 0x6004, 1, 0x1A1C, 0, 0xFFFF };
u16 D_800A6850[] = { 0x1A1C, 1, 0xFFFF };
u16 D_800A6858[] = { 0x6004, 1, 0x1A1C, 1, 0xFFFF };
u16 D_800A6864[] = { 0x7A31, 1, 0xFFFF };
u16 D_800A686C[] = { 0x7015, 1, 0xFFFF };
u16 D_800A6874[] = { 0x7A31, 1, 0xFFFF };
u16 D_800A687C[] = { 0x703E, 1, 0xFFFF };
u16 D_800A6884[] = { 0x7A32, 1, 0xFFFF };
u16 D_800A688C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A6894[] = { 0x7A33, 1, 0xFFFF };
u16 D_800A689C[] = { 0x7020, 1, 0xFFFF };
u16 D_800A68A4[] = { 0x7A34, 1, 0xFFFF };
u16 D_800A68AC[] = { 0x7021, 1, 0x6026, 0, 0xFFFF };
u16 D_800A68B8[] = { 0x7A35, 1, 0xFFFF };
u16 D_800A68C0[] = { 0x6026, 1, 0xFFFF };
u16 D_800A68C8[] = { 0x7A36, 1, 0xFFFF };
u16 D_800A68D0[] = { 0x701A, 1, 0xFFFF };
u16 D_800A68D8[] = { 0x7A36, 1, 0xFFFF };
u16 D_800A68E0[] = { 0x602B, 1, 0xFFFF };
u16 D_800A68E8[] = { 0x7A36, 1, 0xFFFF };
u16 D_800A68F0[] = { 0x8192, 0, 0xFFFF };
u16 D_800A68F8[] = { 0x1C48, 1, 0x905C, 1, 0xFFFF };
u16 D_800A6904[] = { 0x8192, 1, 0xFFFF };
FieldTalk D_800A690C[] = {
    { NULL, D_800A6144, 0x248 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6924[] = {
    { NULL, D_800A614C, 0x31 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A693C[] = {
    { D_800A6154, NULL, 0x41D },
    { D_800A615C, D_800A616C, 0x97 },
    { D_800A6178, D_800A6188, 0x96 },
    { D_800A6190, D_800A61A0, 0x7A },
    { D_800A61A8, NULL, 0x7C },
    { D_800A61BC, D_800A61D4, 0x7D },
    { D_800A61DC, D_800A61F4, 0x7E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A699C[] = {
    { D_800A61FC, NULL, 0x7A },
    { D_800A6204, D_800A6210, 0x96 },
    { D_800A6218, D_800A6224, 0x97 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A69CC[] = {
    { D_800A6230, D_800A6238, 0x7B },
    { D_800A6240, NULL, 0x7C },
    { D_800A624C, D_800A625C, 0x7D },
    { D_800A6264, D_800A6274, 0x7E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6A08[] = {
    { D_800A627C, D_800A6284, 0x93 },
    { D_800A628C, NULL, 0x7C },
    { D_800A6298, D_800A62A8, 0x7D },
    { D_800A62B0, D_800A62C0, 0x7E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6A44[] = {
    { NULL, NULL, 0x41D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6A5C[] = {
    { D_800A62C8, NULL, 0x41E },
    { D_800A62D0, D_800A62E0, 0xA1 },
    { D_800A62EC, D_800A62FC, 0xA0 },
    { D_800A6304, D_800A6314, 0x98 },
    { D_800A631C, NULL, 0x9D },
    { D_800A6330, D_800A6348, 0x9E },
    { D_800A6350, D_800A6368, 0x9F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6ABC[] = {
    { D_800A6370, NULL, 0x98 },
    { D_800A6378, D_800A6384, 0xA0 },
    { D_800A638C, D_800A6398, 0xA1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6AEC[] = {
    { D_800A63A4, D_800A63AC, 0x99 },
    { D_800A63B4, NULL, 0x9D },
    { D_800A63C0, D_800A63D0, 0x9E },
    { D_800A63D8, D_800A63E8, 0x9F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6B28[] = {
    { D_800A63F0, D_800A63F8, 0x9A },
    { D_800A6400, NULL, 0x9D },
    { D_800A640C, D_800A641C, 0x9E },
    { D_800A6424, D_800A6434, 0x9F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6B64[] = {
    { NULL, NULL, 0x41E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6B7C[] = {
    { NULL, D_800A643C, 0x30 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6B94[] = {
    { NULL, D_800A6444, 0x30 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6BAC[] = {
    { D_800A644C, NULL, 0x41B },
    { D_800A6454, D_800A6464, 0x88 },
    { D_800A6470, D_800A6480, 0x87 },
    { D_800A6488, D_800A6498, 0x70 },
    { D_800A64A0, NULL, 0x72 },
    { D_800A64B4, D_800A64CC, 0x73 },
    { D_800A64D4, D_800A64EC, 0x74 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6C0C[] = {
    { D_800A64F4, NULL, 0x70 },
    { D_800A64FC, D_800A6508, 0x87 },
    { D_800A6510, D_800A651C, 0x88 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6C3C[] = {
    { D_800A6528, D_800A6530, 0x71 },
    { D_800A6538, NULL, 0x72 },
    { D_800A6544, D_800A6554, 0x73 },
    { D_800A655C, D_800A656C, 0x74 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6C78[] = {
    { D_800A6574, D_800A657C, 0x84 },
    { D_800A6584, NULL, 0x72 },
    { D_800A6590, D_800A65A0, 0x73 },
    { D_800A65A8, D_800A65B8, 0x74 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6CB4[] = {
    { NULL, NULL, 0x41B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6CCC[] = {
    { D_800A65C0, NULL, 0x41C },
    { D_800A65C8, D_800A65D8, 0x92 },
    { D_800A65E4, D_800A65F4, 0x91 },
    { D_800A65FC, D_800A660C, 0x75 },
    { D_800A6614, NULL, 0x77 },
    { D_800A6628, D_800A6640, 0x78 },
    { D_800A6648, D_800A6660, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6D2C[] = {
    { D_800A6668, D_800A6670, 0x76 },
    { D_800A6678, NULL, 0x77 },
    { D_800A6684, D_800A6694, 0x78 },
    { D_800A669C, D_800A66AC, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6D68[] = {
    { D_800A66B4, D_800A66BC, 0x8D },
    { D_800A66C4, NULL, 0x77 },
    { D_800A66D0, D_800A66E0, 0x78 },
    { D_800A66E8, D_800A66F8, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6DA4[] = {
    { D_800A6700, NULL, 0x75 },
    { D_800A6708, D_800A6714, 0x91 },
    { D_800A671C, D_800A6728, 0x92 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6DD4[] = {
    { NULL, NULL, 0x41C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6DEC[] = {
    { NULL, NULL, 0x251 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6E04[] = {
    { D_800A6734, NULL, 0x94 },
    { D_800A673C, NULL, 0x7C },
    { D_800A6748, D_800A6758, 0x7D },
    { D_800A6760, D_800A6770, 0x7E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6E40[] = {
    { D_800A6778, NULL, 0x85 },
    { D_800A6780, NULL, 0x72 },
    { D_800A678C, D_800A679C, 0x73 },
    { D_800A67A4, D_800A67B4, 0x74 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6E7C[] = {
    { D_800A67BC, NULL, 0x9B },
    { D_800A67C4, NULL, 0x9D },
    { D_800A67D0, D_800A67E0, 0x9E },
    { D_800A67E8, D_800A67F8, 0x9F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6EB8[] = {
    { D_800A6800, NULL, 0x8F },
    { D_800A6808, NULL, 0x77 },
    { D_800A6814, D_800A6824, 0x78 },
    { D_800A682C, D_800A683C, 0x79 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6EF4[] = {
    { NULL, NULL, 0x247 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6F0C[] = {
    { D_800A6844, D_800A6850, 0x2F },
    { D_800A6858, D_800A6864, 0x2A5 },
    { D_800A686C, D_800A6874, 0x2A5 },
    { D_800A687C, D_800A6884, 0x2A5 },
    { D_800A688C, D_800A6894, 0x2A5 },
    { D_800A689C, D_800A68A4, 0x2A5 },
    { D_800A68AC, D_800A68B8, 0x2A5 },
    { D_800A68C0, D_800A68C8, 0x2A5 },
    { D_800A68D0, D_800A68D8, 0x2A5 },
    { D_800A68E0, D_800A68E8, 0x2A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6F90[] = {
    { D_800A68F0, D_800A68F8, 0x63 },
    { D_800A6904, NULL, 0x64 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6FB4[] = {
    { NULL, NULL, 0x4A2 },
    { NULL, NULL, 0 },
};
u16 D_800A6FCC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A6FD4[] = { 0x7022, 1, 0xFFFF };
u16 D_800A6FDC[] = { 0x7022, 1, 0xFFFF };
u16 D_800A6FE4[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6FF0[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6FFC[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A7008[] = { 0x8192, 0, 0x602B, 1, 0xFFFF };
u16 D_800A7014[] = { 0x7022, 1, 0xFFFF };
u16 D_800A701C[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A7028[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A7034[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A7040[] = { 0x8192, 0, 0x602B, 1, 0xFFFF };
u16 D_800A704C[] = { 0x7022, 1, 0xFFFF };
u16 D_800A7054[] = { 0x602B, 1, 0xFFFF };
u16 D_800A705C[] = { 0x7022, 1, 0xFFFF };
u16 D_800A7064[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A7070[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A707C[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A7088[] = { 0x8192, 0, 0x602B, 1, 0xFFFF };
u16 D_800A7094[] = { 0x7022, 1, 0xFFFF };
u16 D_800A709C[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A70A8[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A70B4[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A70C0[] = { 0x8192, 0, 0x602B, 1, 0xFFFF };
u16 D_800A70CC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A70D4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A70DC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A70E4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A70EC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A70F4[] = { 0x701A, 1, 0xFFFF };
u16 D_800A70FC[] = { 0x8192, 1, 0x7009, 1, 0xFFFF };
u16 D_800A7108[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A7118[] = { 0x8192, 0, 0x701A, 1, 0xFFFF };
u16 D_800A7124[] = { 0x7022, 1, 0xFFFF };
u16 D_800A712C[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A7134 = { D_800A6FCC, D_800A690C, 0x2D, 4, 255, 176, 3 };
FieldActorEntry D_800A7148 = { D_800A6FD4, D_800A6924, 0x2D, 4, 255, 176, 3 };
FieldActorEntry D_800A715C = { D_800A6FDC, D_800A693C, 0x2F, 5, 198, 219, 7 };
FieldActorEntry D_800A7170 = { D_800A6FE4, D_800A699C, 0x2F, 5, 198, 219, 7 };
FieldActorEntry D_800A7184 = { D_800A6FF0, D_800A69CC, 0x2F, 5, 198, 219, 7 };
FieldActorEntry D_800A7198 = { D_800A6FFC, D_800A6A08, 0x2F, 5, 198, 219, 7 };
FieldActorEntry D_800A71AC = { D_800A7008, D_800A6A44, 0x2F, 5, 198, 219, 7 };
FieldActorEntry D_800A71C0 = { D_800A7014, D_800A6A5C, 0x32, 6, 173, 231, 7 };
FieldActorEntry D_800A71D4 = { D_800A701C, D_800A6ABC, 0x32, 6, 173, 231, 7 };
FieldActorEntry D_800A71E8 = { D_800A7028, D_800A6AEC, 0x32, 6, 173, 231, 7 };
FieldActorEntry D_800A71FC = { D_800A7034, D_800A6B28, 0x32, 6, 173, 231, 7 };
FieldActorEntry D_800A7210 = { D_800A7040, D_800A6B64, 0x32, 6, 173, 231, 7 };
FieldActorEntry D_800A7224 = { D_800A704C, D_800A6B7C, 0x33, 7, 348, 147, 1 };
FieldActorEntry D_800A7238 = { D_800A7054, D_800A6B94, 0x33, 7, 348, 147, 1 };
FieldActorEntry D_800A724C = { D_800A705C, D_800A6BAC, 0x34, 8, 250, 244, 3 };
FieldActorEntry D_800A7260 = { D_800A7064, D_800A6C0C, 0x34, 8, 250, 244, 3 };
FieldActorEntry D_800A7274 = { D_800A7070, D_800A6C3C, 0x34, 8, 250, 244, 3 };
FieldActorEntry D_800A7288 = { D_800A707C, D_800A6C78, 0x34, 8, 250, 244, 3 };
FieldActorEntry D_800A729C = { D_800A7088, D_800A6CB4, 0x34, 8, 250, 244, 3 };
FieldActorEntry D_800A72B0 = { D_800A7094, D_800A6CCC, 0x37, 9, 224, 257, 3 };
FieldActorEntry D_800A72C4 = { D_800A709C, D_800A6D2C, 0x37, 9, 224, 257, 3 };
FieldActorEntry D_800A72D8 = { D_800A70A8, D_800A6D68, 0x37, 9, 224, 257, 3 };
FieldActorEntry D_800A72EC = { D_800A70B4, D_800A6DA4, 0x37, 9, 224, 257, 3 };
FieldActorEntry D_800A7300 = { D_800A70C0, D_800A6DD4, 0x37, 9, 224, 257, 3 };
FieldActorEntry D_800A7314 = { D_800A70CC, D_800A6DEC, 0x9D, 0xA, 348, 147, 1 };
FieldActorEntry D_800A7328 = { D_800A70D4, D_800A6E04, 0x9E, 0xB, 198, 219, 7 };
FieldActorEntry D_800A733C = { D_800A70DC, D_800A6E40, 0x9F, 0xC, 250, 244, 3 };
FieldActorEntry D_800A7350 = { D_800A70E4, D_800A6E7C, 0xA0, 0xD, 173, 231, 7 };
FieldActorEntry D_800A7364 = { D_800A70EC, D_800A6EB8, 0xA1, 0xE, 224, 257, 3 };
FieldActorEntry D_800A7378 = { D_800A70F4, D_800A6EF4, 0xA2, 0xF, 255, 176, 3 };
FieldActorEntry D_800A738C = { D_800A70FC, D_800A6F0C, 0xCE, 0x10, 379, 147, 7 };
FieldActorEntry D_800A73A0 = { D_800A7108, D_800A6F90, 0xCE, 0x10, 379, 147, 7 };
FieldActorEntry D_800A73B4 = { D_800A7118, D_800A6FB4, 0xCE, 0x10, 379, 147, 7 };
FieldActorEntry D_800A73C8 = { NULL, NULL, 0xDC, 0x11, 379, 163, 7 };
FieldActorEntry D_800A73DC = { D_800A7124, NULL, 0xE1, 0x12, 347, 158, 1 };
FieldActorEntry D_800A73F0 = { D_800A712C, NULL, 0x10E, 0x13, 347, 158, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A7134,
    &D_800A7148,
    &D_800A715C,
    &D_800A7170,
    &D_800A7184,
    &D_800A7198,
    &D_800A71AC,
    &D_800A71C0,
    &D_800A71D4,
    &D_800A71E8,
    &D_800A71FC,
    &D_800A7210,
    &D_800A7224,
    &D_800A7238,
    &D_800A724C,
    &D_800A7260,
    &D_800A7274,
    &D_800A7288,
    &D_800A729C,
    &D_800A72B0,
    &D_800A72C4,
    &D_800A72D8,
    &D_800A72EC,
    &D_800A7300,
    &D_800A7314,
    &D_800A7328,
    &D_800A733C,
    &D_800A7350,
    &D_800A7364,
    &D_800A7378,
    &D_800A738C,
    &D_800A73A0,
    &D_800A73B4,
    &D_800A73C8,
    &D_800A73DC,
    &D_800A73F0,
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
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x201, 0x1F0, 0xA0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageFuncs stageFuncs = { setupStage, startTween, updateTween };
FieldEvent stageEvents[] = {
    { 59, D_800A5B84, EVENT_TEXT(0), NULL, NULL },
    { 65, D_800A5C2C, EVENT_TEXT(1), NULL, NULL },
    { 1415, D_800A5CC8, EVENT_TEXT(2), NULL, func_800A5938 },
    { 1518, NULL, EVENT_TEXT(5), func_800A52A0, NULL },
    { 1519, D_800A5F8C, EVENT_TEXT(3), NULL, NULL },
    { 1520, NULL, EVENT_TEXT(6), func_800A5868, NULL },
    { 1521, D_800A5FA4, EVENT_TEXT(4), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
