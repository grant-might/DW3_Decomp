#ifndef STDGNAME_H
#define STDGNAME_H

/* STDGNAME.PRO: the screen where the partners are renamed. Its modules are
   in src/stdgname/, and the functions below are by module, in the order they
   link. */

/* The overlay's NameEntry and the name entry's files (name_entry.h) */
#define NAME_ENTRY_HAS_UNK98 1
#define NAME_ENTRY_HAS_HIDE 0
#define NAME_ENTRY_SPRITES STDGNAME_KEY_SPRITES
#define NAME_ENTRY_FILE_KEYBOARD STDGNAME_FILE_KEYBOARD
#include "name_entry.h"

/* The name of this overlay's copy of a function of src/menu_common/ */
#define OVL_NAME(name) STDGNAME_##name

/* The screen's files: the discs number them differently */
#if VERSION_US
#define STDGNAME_FILE_SPRITES 0x279
#define STDGNAME_FILE_IMAGES 0x27A
#define STDGNAME_FILE_KEYBOARD 0x762
#define STDGNAME_FILE_KEY_SPRITES 0x761
#elif VERSION_EU
#define STDGNAME_FILE_SPRITES 0x288
#define STDGNAME_FILE_IMAGES 0x289
#define STDGNAME_FILE_KEYBOARD 0x771
#define STDGNAME_FILE_KEY_SPRITES 0x770
#endif
#define STDGNAME_SPRITES (STDGNAME_FILE_SPRITES << 16) /* sprite bank */
#define STDGNAME_KEY_SPRITES (STDGNAME_FILE_KEY_SPRITES << 16) /* the keyboard's and partners' sprites */

/* Where a window of the partner menu goes, and its text */
typedef struct MenuWindow {
    /* 0x0 */ s32 text;
    /* 0x4 */ s32 x;
    /* 0x8 */ s32 y;
} MenuWindow;

struct ScreenTask;

/* A sprite of the partner menu, that opens by scaling */
typedef struct MenuSprite {
    /* 0x00 */ s32 sprite; /* -1 ends the list */
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ s32 pivotX;
    /* 0x14 */ s32 pivotY;
    /* 0x18 */ s32 vertical;
} MenuSprite;

typedef struct MenuSlot {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ s32 pivotX;
    /* 0xC */ s32 pivotY;
} MenuSlot;

/* A partner's animation in the partner menu */
typedef struct MenuAnim {
    /* 0x0 */ s32 frame;
    /* 0x4 */ s32 time;
} MenuAnim;

/* The partner menu */
typedef struct MenuTask {
    TASK_HEADER(MenuTask);
    /* 0x50 */ struct ScreenTask *screen;
    /* 0x54 */ s32 layer;
    /* 0x58 */ s32 cursorClut;
    /* 0x5C */ MenuAnim anims[3];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ s32 partyCount;
    /* 0x7C */ s32 titleClut;
    /* 0x80 */ PanelAnim tweens[6];
} MenuTask;

typedef struct ScreenChildren {
    /* 0x0 */ MenuTask *menu;
    /* 0x4 */ NameEntry *name;
    /* 0x8 */ ScreenFade *fade;
    /* 0xC */ Task *unkC; /* never set: the screen waits on it in TASK_DONE */
} ScreenChildren;

/* The screen's controller */
typedef struct ScreenTask {
    TASK_HEADER(ScreenTask);
    /* 0x50 */ s32 layer;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 scroll;
    /* 0x5C */ s32 tick;
    /* 0x60 */ s32 choice;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ void (*fadeOut)(struct ScreenTask *task);
} ScreenTask;

typedef struct ScreenFuncs {
    /* 0x00 */ TextStyle *style;
    /* 0x04 */ s32 partner;
    /* 0x08 */ void (*loadFiles)(void);
    /* 0x0C */ s32 (*isLoading)(void);
    /* 0x10 */ void (*startFade)(PanelAnim *fade, s32 fadeIn);
    /* 0x14 */ s32 (*updateFade)(PanelAnim *fade);
} ScreenFuncs;

/* STDGNAME's data (data/stdgname.c) */
extern NameKeyboard STDGNAME_keyboard;
extern TextStyle STDGNAME_nameStyle;
extern s32 STDGNAME_nameAnims[];
extern BigKey STDGNAME_bigKeys[];
extern s32 STDGNAME_keyArrowCluts[];
extern KeyTabs STDGNAME_keyPages[];
extern KeyPage STDGNAME_keyChars[];
/* the keyboard of language 0, three pages (only the European version uses it) */
extern KeyTabs STDGNAME_keyPagesJp[];
extern KeyPage STDGNAME_keyCharsJp[];
extern MenuSprite STDGNAME_menuSprites[];
extern MenuSlot STDGNAME_menuSlots[];
extern MenuWindow STDGNAME_menuWindows[];
extern s32 STDGNAME_menuAnims[][7];
extern ScreenFuncs STDGNAME_funcs;
extern TextStyle STDGNAME_menuStyle;

/* stdgname.c */
void STDGNAME_updateScene(Task *task, void **children);
Task *STDGNAME_start(void);
void STDGNAME_startFader(ScreenFade *task, s32 fadeIn, s32 duration);
void STDGNAME_drawFader(ScreenFade *task);
void STDGNAME_updateFader(ScreenFade *task);
ScreenFade *STDGNAME_createFader(void);

/* name_entry.c */
void STDGNAME_startTween(PanelAnim *fade, s32 fadeIn);
s32 STDGNAME_updateTween(PanelAnim *fade);
void STDGNAME_createNameWindows(NameEntry *task, NameEntryWindows *windows);
void STDGNAME_showNameWindows(NameEntry *task, NameEntryWindows *windows, s32 show);
void STDGNAME_drawKeyboard(NameEntry *task);
void STDGNAME_updateKeyboard(NameEntry *task, NameEntryWindows *windows);
void STDGNAME_updateNameEntry(NameEntry *task, NameEntryWindows *windows);
void STDGNAME_setNameVram(NameEntry *task, s32 x, s32 y);
void STDGNAME_setName(NameEntry *task, char *name);
void STDGNAME_getName(NameEntry *task, char *out);
void STDGNAME_closeNameEntry(NameEntry *task);
NameEntry *STDGNAME_createNameEntry(char *name, s32 partner);

/* menu.c */
void STDGNAME_showMenuWindow(MenuTask *task, TextWindow **window, s32 index, s32 show);
void STDGNAME_drawMenu(MenuTask *task, TextWindow **windows);
s32 STDGNAME_runMenu(MenuTask *task, TextWindow **windows);
void STDGNAME_updateMenu(MenuTask *task, TextWindow **windows);
MenuTask *STDGNAME_createMenu(ScreenTask *screen);

/* screen.c */
void STDGNAME_stepScreen(ScreenTask *task, ScreenChildren *children);
void STDGNAME_drawBackground(ScreenTask *task);
void STDGNAME_updateScreen(ScreenTask *task, ScreenChildren *children);
void STDGNAME_fadeOutScreen(ScreenTask *task);
ScreenTask *STDGNAME_createScreen(void);
void STDGNAME_loadFiles(void);
s32 STDGNAME_filesLoading(void);
void STDGNAME_startFade(PanelAnim *fade, s32 fadeIn);
s32 STDGNAME_updateFade(PanelAnim *fade);

#endif /* STDGNAME_H */
