/* The save list: the saves on a memory card, loading and saving them, and the
   errors */

#include "stgmcard.h"

/* Shows the line with the memory card's port number, or hides it */
void STGMCARD_showPort(MemCardSaves *saves, MemCardSavesWindows *win, s32 show) {
    if (show) {
        win->windows[4]->setString(win->windows[4], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x28);
        win->windows[4]->setNumber(win->windows[4], 1, saves->port + 1);
    } else {
        win->windows[4]->setVisible(win->windows[4], 0);
    }
}

/* Shows the error of the last card operation (saves->result, made an index of
   STGMCARD_errorTexts), hiding the choices, the cursor and the panel */
void STGMCARD_showError(MemCardSaves *saves, MemCardSavesWindows *win) {
    saves->substate = 100;
    saves->choice = 0;
    saves->result--;
    if (win->windows[1] != NULL) {
        win->windows[1]->setVisible(win->windows[1], 0);
    }
    if (win->windows[2] != NULL) {
        win->windows[2]->setVisible(win->windows[2], 0);
    }
    if (win->windows[3] != NULL) {
        win->windows[3]->setVisible(win->windows[3], 0);
    }
    if (win->cursor != NULL) {
        win->cursor->setVisible(win->cursor, 0);
    }
    if (win->panel != NULL) {
        win->panel->reset(win->panel);
    }
}

/* Hides the message and panel and closes the slot picker, then shows the error in
   saves->result */
void STGMCARD_closeMenuForError(MemCardSaves *saves, MemCardSavesWindows *win) {
    win->windows[1]->setVisible(win->windows[1], 0);
    win->panel->reset(win->panel);
    saves->substate = 90;
    saves->step = 100;
    win->menu->substate = 0;
}

/* Fills the details window with the selected save again (saves->refresh) */
void STGMCARD_refreshSaves(MemCardSaves *saves) {
    MemCardSavesWindows *win = saves->children;

    win->info->refresh(win->info);
}

/* Hides the save list's windows and ends it (TASK_DONE), which makes the main task fade
   out and leave the screen (saves->hide) */
void STGMCARD_hideSaves(MemCardSaves *saves) {
    MemCardSavesWindows *win = saves->children;

    if (win->windows[0] != NULL) {
        win->windows[0]->setVisible(win->windows[0], 0);
    }
    if (win->windows[4] != NULL) {
        win->windows[4]->setVisible(win->windows[4], 0);
    }
    if (win->windows[1] != NULL) {
        win->windows[1]->setVisible(win->windows[1], 0);
    }
    if (win->windows[2] != NULL) {
        win->windows[2]->setVisible(win->windows[2], 0);
    }
    if (win->windows[3] != NULL) {
        win->windows[3]->setVisible(win->windows[3], 0);
    }
    if (win->cursor != NULL) {
        win->cursor->setVisible(win->cursor, 0);
    }
    if (win->panel != NULL) {
        win->panel->reset(win->panel);
    }
    saves->setState(saves, TASK_DONE);
}

/*
 * The save list's states (saves->substate): picks the port, reads the card's
 * info section, lets the menu pick a slot, then loads or saves it. A failed
 * operation leaves its error in saves->result and goes to 100, which shows
 * STGMCARD_errorTexts[result] and can format the card (110) or create the save
 * file (120). 400 waits for the card and goes on to step.
 * Match depends on the separate variables: result lives across calls, status,
 * check, member and j each keep their own register.
 */
void STGMCARD_runSaves(MemCardSaves *saves, MemCardSavesWindows *win) {
    MemCardSave *save;
    s32 prev;
    s32 result;
    s32 j;
    s32 blocks;
    s32 ask;
    s32 i;
    s32 status;
    s32 member;
    s32 check;

    switch (saves->substate) {
    case 0:
    default:
        win->title->setDepth(win->title, 1);
        if (saves->screen->loading == 0) {
            win->title->setString(win->title, FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 1);
        } else {
            win->title->setString(win->title, FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0xE);
        }
        if (win->info == NULL) {
            win->info = STGMCARD_createInfo(saves);
        }
        saves->substate++;
    case 1:
        if (STGMCARD_funcs.updateLerp(&saves->slide[1]) != 0) {
            win->windows[0]->setVisible(win->windows[0], 0);
            if (saves->screen->loading == 0) {
                win->windows[4]->setString(win->windows[4], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 2);
            } else {
                win->windows[4]->setString(win->windows[4], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0xF);
            }
            win->windows[1]->setDepth(win->windows[1], 1);
            win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x1D);
            win->windows[2]->setString(win->windows[2], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 3);
            win->windows[2]->setNumber(win->windows[2], 1, 1);
            win->windows[3]->setString(win->windows[3], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 3);
            win->windows[3]->setNumber(win->windows[3], 1, 2);
            win->cursor->setVisible(win->cursor, 1);
            win->cursor->setPos(win->cursor, 0xC2, saves->port * 14 + 0xBD);
            saves->choosing = 1;
            saves->substate++;
        }
        win->title->setPos(win->title, saves->origin[0] + (s16)(saves->slide[0].value + 200), saves->origin[1] + (s16)(saves->slide[1].value + 9));
        break;
    case 2:
        prev = saves->port;
        if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
            saves->port = 0;
        } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
            saves->port = 1;
        }
        if (prev != saves->port) {
            win->cursor->setPos(win->cursor, 0xC2, saves->port * 14 + 0xBD);
            SOUND.playSound(SOUND_CURSOR);
        }
        if (PAD_PRESSED(PAD_CROSS)) {
            win->windows[0]->setString(win->windows[0], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 4);
            STGMCARD_showPort(saves, win, 1);
            win->windows[1]->setVisible(win->windows[1], 0);
            win->windows[2]->setVisible(win->windows[2], 0);
            win->windows[3]->setVisible(win->windows[3], 0);
            win->cursor->setVisible(win->cursor, 0);
            if (win->panel == NULL) {
                win->panel = STGMCARD_createPanel(0xCD, 0xC1, 0x62, 0xA);
            }
            win->panel->setTopColor(win->panel, 0x7F, 0x32, 0xF2);
            win->panel->setBottomColor(win->panel, 0xD1, 0x2F, 0xDE);
            saves->substate = 10;
            SOUND.playSound(SOUND_SELECT);
            saves->choosing = 0;
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            saves->hide(saves);
            saves->choosing = 0;
            saves->screen->step = 1;
        }
        break;
    case 10:
        if (win->panel->substate == 0) {
            win->panel->start(win->panel, 1, 0x4C);
        }
        status = saves->result = MEMCARD_SYSTEM.funcs.accept(saves->port);
        if (status != 0) {
            if (status == 1 || status - 1 == 3) {
                saves->substate++;
            } else {
                win->panel->start(win->panel, 2, 0x14);
                saves->substate += 2;
            }
        }
        break;
    case 11:
        status = saves->result = MEMCARD_SYSTEM.funcs.list(saves->port);
        if (status != 0) {
            win->panel->start(win->panel, 2, 0x14);
            saves->substate++;
        }
        break;
    case 12:
        if (win->panel->done != 0) {
            if (saves->result == 1) {
                saves->substate = 20;
            } else {
                STGMCARD_showError(saves, win);
            }
        }
        break;
    case 20:
        if (win->panel->done != 0) {
            win->windows[0]->setString(win->windows[0], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 5);
            STGMCARD_showPort(saves, win, 1);
            win->panel->reset(win->panel);
            win->panel->start(win->panel, 1, 0x4C);
            saves->substate++;
        }
    case 21:
        status = saves->result = MEMCARD_SYSTEM.funcs.read(saves->port, (u8 *)STGMCARD_funcs.infoBuf, sizeof(MemCardFile), 1);
        if (status != 0) {
            win->panel->start(win->panel, 2, 0x14);
            saves->substate++;
        }
        break;
    case 22:
        if (win->panel->done != 0) {
            if (saves->result == 1) {
                if (STGMCARD_funcs.infoBuf->magic != MEMCARD_FILE_MAGIC) {
                    HEAP.zero(STGMCARD_funcs.infoBuf, 0x44);
                    STGMCARD_funcs.infoBuf->magic = MEMCARD_FILE_MAGIC;
                    STGMCARD_funcs.infoBuf->version = MEMCARD_SAVE_VERSION;
                } else if (MEMCARD_SYSTEM.funcs.computeChecksum((u8 *)&STGMCARD_funcs.infoBuf->magic, sizeof(MemCardFile) - 4) & ~STGMCARD_funcs.infoBuf->checksum) {
                    saves->result = 9;
                    STGMCARD_showError(saves, win);
                    break;
                } else {
                    saves->file = *STGMCARD_funcs.infoBuf;
                    STGMCARD_funcs.lastSlot = STGMCARD_funcs.infoBuf->last;
                }
                win->windows[0]->setVisible(win->windows[0], 0);
                win->windows[4]->setVisible(win->windows[4], 0);
                win->panel->reset(win->panel);
                saves->substate = 30;
            } else {
                STGMCARD_showError(saves, win);
            }
        }
        break;
    case 30:
        win->windows[0]->setVisible(win->windows[0], 0);
        win->windows[4]->setVisible(win->windows[4], 0);
        if (win->menu->slid != 5) {
            win->menu->reset(win->menu);
        }
        if (win->info != NULL) {
            win->info->show(win->info);
        }
        saves->substate++;
        break;
    case 31:
        if (win->menu->substate == 0) {
            if (win->menu->slid == 0) {
                win->menu->slideInHeader(win->menu);
            } else if (win->menu->slid == 1) {
                win->menu->slideInSlots(win->menu);
            } else if (win->menu->slid == 2) {
                win->menu->startPick(win->menu, STGMCARD_funcs.lastSlot);
                saves->substate++;
            }
        }
        break;
    case 32:
        if (win->menu->substate == 6) {
            if (saves->screen->loading == 0) {
                win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 6);
            } else {
                win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x10);
            }
            win->info->drawing = 1;
            win->info->shown = 1;
            win->info->refresh(win->info);
            saves->nextSubstate(saves);
            win->menu->substate = 6;
        }
        break;
    case 33:
        if (win->menu->substate == 6) {
            if (PAD_PRESSED(PAD_CROSS)) {
                SOUND.playSound(SOUND_MENU_CONFIRM);
                saves->substate = 400;
                win->menu->substate = 0;
                if (saves->screen->loading == 0) {
                    if (STGMCARD_funcs.infoBuf->saves[STGMCARD_funcs.slot].name[0] != 0) {
                        saves->step = 40;
                        saves->choice = 0;
                        win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 7);
                        win->windows[2]->setString(win->windows[2], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x16);
                        win->windows[3]->setString(win->windows[3], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x17);
                        win->cursor->setVisible(win->cursor, 1);
                        saves->choosing = 1;
                        win->cursor->setPos(win->cursor, 0xC2, saves->choice * 14 + 0xBD);
                    } else {
                        saves->step = 50;
                    }
                } else {
                    saves->step = 70;
                }
            } else if (PAD_PRESSED(PAD_TRIANGLE)) {
                SOUND.playSound(SOUND_MENU_CANCEL);
                win->menu->substate = 0;
                saves->substate = 90;
                saves->step = 1;
            } else {
                status = MEMCARD_SYSTEM.funcs.check(saves->port);
                if (status != 0) {
                    if (status != 1) {
                        saves->result = status - 1;
                        STGMCARD_closeMenuForError(saves, win);
                    }
                }
            }
        }
        break;
    case 90:
        if (win->menu->substate == 0) {
            switch (win->menu->slid) {
            case 3:
                win->menu->slideOutHeader(win->menu);
                saves->substate = saves->step;
                saves->step = saves->counter;
                saves->counter = 0;
                break;
            case 2:
                win->info->hide(win->info);
                win->menu->slideOutSlots(win->menu);
                break;
            }
        }
        break;
    case 600:
        if (win->menu->substate == 0) {
            if (win->menu->slid == 2) {
                win->info->hide(win->info);
                win->menu->slideOutSlots(win->menu);
            } else if (win->menu->slid == 3) {
                win->menu->slideOutHeader(win->menu);
                saves->substate++;
            }
        }
        break;
    case 601:
        saves->hide(saves);
        break;
    case 70:
        if (STGMCARD_funcs.infoBuf->saves[STGMCARD_funcs.slot].name[0] == 0) {
            win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x18);
            saves->prompting = 1;
            saves->substate = 501;
            saves->step = 32;
            saves->backToPick = 1;
        } else {
            win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x11);
            win->panel->start(win->panel, 1, MEMCARD_LOAD_FRAMES);
            saves->substate++;
        }
        break;
    case 71:
        status = saves->result = MEMCARD_SYSTEM.funcs.read(saves->port, (u8 *)STGMCARD_funcs.dataBuf, sizeof(GameSave), STGMCARD_funcs.slot + 2);
        if (status != 0) {
            if (status == 1) {
                if (MEMCARD_SYSTEM.funcs.computeChecksum(&STGMCARD_funcs.dataBuf->unk0[4], sizeof(GameSave) - 4) & ~STGMCARD_funcs.dataBuf->unk0[0]) {
                    saves->result = 8;
                    STGMCARD_closeMenuForError(saves, win);
                } else if (STGMCARD_funcs.dataBuf->unk0[2] != MEMCARD_SAVE_VERSION && saves->screen->loading != 0) {
                    saves->result = 8;
                    STGMCARD_closeMenuForError(saves, win);
                } else {
                    *(GameSave *)&GAME = *(GameSave *)STGMCARD_funcs.dataBuf;
                    win->panel->start(win->panel, 2, 0x14);
                    saves->substate = 500;
                    win->menu->substate = 0;
                    saves->backToPick = 0;
                }
            } else {
                saves->result = status - 1;
                STGMCARD_closeMenuForError(saves, win);
            }
        }
        break;
    case 40:
        prev = saves->choice;
        if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
            saves->choice = 0;
        } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
            saves->choice = 1;
        }
        if (prev != saves->choice) {
            win->cursor->setPos(win->cursor, 0xC2, saves->choice * 14 + 0xBD);
            SOUND.playSound(SOUND_CURSOR);
        }
        if (PAD_PRESSED(PAD_CROSS)) {
            win->windows[2]->setVisible(win->windows[2], 0);
            win->windows[3]->setVisible(win->windows[3], 0);
            win->cursor->setVisible(win->cursor, 0);
            SOUND.playSound(SOUND_SELECT);
            /* match depends on the 400 going through status */
            status = 400;
            saves->choosing = 0;
            saves->substate = status;
            if (saves->choice == 0) {
                saves->step = 50;
            } else {
                saves->step = 32;
                win->menu->substate = 6;
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            win->windows[2]->setVisible(win->windows[2], 0);
            win->windows[3]->setVisible(win->windows[3], 0);
            win->cursor->setVisible(win->cursor, 0);
            SOUND.playSound(SOUND_MENU_CANCEL);
            saves->substate = 400;
            saves->choosing = 0;
            saves->step = 32;
            win->menu->substate = 6;
        } else {
            result = MEMCARD_SYSTEM.funcs.check(saves->port);
            if (result != 0) {
                if (result != 1) {
                    win->windows[2]->setVisible(win->windows[2], 0);
                    win->windows[3]->setVisible(win->windows[3], 0);
                    win->cursor->setVisible(win->cursor, 0);
                    saves->choosing = 0;
                    saves->result = result - 1;
                    STGMCARD_closeMenuForError(saves, win);
                }
            }
        }
        break;
    case 50:
        win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 8);
        win->panel->start(win->panel, 1, MEMCARD_SAVE_FRAMES);
        saves->substate++;
        break;
    case 51:
        save = &STGMCARD_funcs.infoBuf->saves[STGMCARD_funcs.slot];
        *(GameSave *)STGMCARD_funcs.dataBuf = *(GameSave *)&GAME;
        STGMCARD_funcs.dataBuf->unk0[0] = MEMCARD_SYSTEM.funcs.computeChecksum(&STGMCARD_funcs.dataBuf->unk0[4], sizeof(GameSave) - 4);
        STGMCARD_funcs.dataBuf->unk0[2] = MEMCARD_SAVE_VERSION;
        strcpy(save->name, STGMCARD_funcs.dataBuf->name);
        save->area = saves->screen->area;
        save->place = saves->screen->place;
        save->money = STGMCARD_funcs.dataBuf->money;
        save->time = *(PlayTime *)&STGMCARD_funcs.dataBuf->playFrames;
        for (i = 0; i < 3; i++) {
            member = GAME.funcs.getPartyMember(i);
            save->levels[i] = STGMCARD_funcs.dataBuf->partners[member].info.stats[STAT_LEVEL];
            save->partners[i] = STGMCARD_funcs.dataBuf->partners[member].unlocked;
        }
        STGMCARD_funcs.infoBuf->last = STGMCARD_funcs.slot;
        STGMCARD_funcs.infoBuf->checksum = MEMCARD_SYSTEM.funcs.computeChecksum((u8 *)&STGMCARD_funcs.infoBuf->magic, sizeof(MemCardFile) - 4);
        saves->substate++;
        break;
    case 52:
        status = saves->result = MEMCARD_SYSTEM.funcs.write(saves->port, (u8 *)STGMCARD_funcs.infoBuf, sizeof(MemCardFile), 1);
        if (status != 0) {
            if (status == 1) {
                saves->substate++;
            } else {
                saves->result = status - 1;
                STGMCARD_closeMenuForError(saves, win);
            }
        }
        break;
    case 53:
        status = saves->result = MEMCARD_SYSTEM.funcs.write(saves->port, (u8 *)STGMCARD_funcs.dataBuf, sizeof(GameSave), STGMCARD_funcs.slot + 2);
        if (status != 0) {
            if (status == 1) {
                win->panel->start(win->panel, 2, 0x14);
                saves->substate = 500;
            } else {
                saves->result = status - 1;
                STGMCARD_closeMenuForError(saves, win);
            }
        }
        break;
    case 500:
        if (win->panel->done != 0) {
            if (saves->screen->loading == 0) {
                saves->file = *STGMCARD_funcs.infoBuf;
                saves->refresh(saves);
                win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 9);
                saves->step = 32;
            } else {
                win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x12);
                saves->step = 400;
                saves->substate++;
            }
            saves->substate++;
            win->panel->reset(win->panel);
            saves->prompting = 1;
        }
        break;
    case 501:
        if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            saves->prompting = 0;
            saves->substate = saves->step;
            if (saves->screen->loading == 0) {
                saves->setStep(saves, 0);
                win->menu->substate = 6;
            } else {
                win->windows[1]->setVisible(win->windows[1], 0);
                saves->step = 600;
                if (saves->backToPick != 0) {
                    win->menu->substate = 6;
                } else {
                    win->menu->substate = 0;
                }
            }
        } else {
            check = MEMCARD_SYSTEM.funcs.check(saves->port);
            if (check != 0) {
                if (check != 1) {
                    saves->prompting = 0;
                    saves->result = 1;
                    STGMCARD_closeMenuForError(saves, win);
                }
            }
        }
        break;
    case 502:
        if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            saves->prompting = 0;
            saves->substate = saves->step;
            win->windows[1]->setVisible(win->windows[1], 0);
            saves->step = 600;
            win->menu->substate = 0;
        }
        break;
    case 100:
        win->windows[0]->setString(win->windows[0], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), STGMCARD_errorTexts[saves->result]);
        STGMCARD_showPort(saves, win, 1);
        if (saves->screen->loading == 0) {
            if (saves->result == 4) {
                saves->choice = 1;
                ask = 1;
            } else if (saves->result == 5) {
                if (MEMCARD.fileCount != 0) {
                    blocks = 0;
                    for (j = 0; j < MEMCARD.fileCount; j++) {
                        blocks += MEMCARD.files[j].size / 0x2000;
                    }
                    if (blocks + 4 >= 16) {
                        win->windows[0]->setVisible(win->windows[0], 0);
                        saves->result = 7;
                        saves->substate = 100;
                        break;
                    }
                }
                ask = 1;
            } else {
                saves->prompting = 1;
                ask = 0;
                if (saves->result == 7) {
                    win->windows[0]->setNumber(win->windows[0], 1, 4);
                }
            }
            if (ask) {
                if (saves->result == 4) {
                    win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x19);
                } else {
                    win->windows[1]->setString(win->windows[1], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x1A);
                }
                win->windows[2]->setString(win->windows[2], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x16);
                win->windows[3]->setString(win->windows[3], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x17);
                win->cursor->setVisible(win->cursor, 1);
                saves->choosing = 1;
                win->cursor->setPos(win->cursor, 0xC2, saves->choice * 14 + 0xBD);
            }
        } else {
            saves->prompting = 1;
        }
        saves->substate++;
        break;
    case 101:
        if (saves->screen->loading == 0 && (u32)(saves->result - 4) < 2) {
            prev = saves->choice;
            if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
                saves->choice = 0;
            } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
                saves->choice = 1;
            }
            if (prev != saves->choice) {
                SOUND.playSound(SOUND_CURSOR);
                win->cursor->setPos(win->cursor, 0xC2, saves->choice * 14 + 0xBD);
            }
            if (PAD_PRESSED(PAD_CROSS)) {
                SOUND.playSound(SOUND_SELECT);
                win->windows[0]->setVisible(win->windows[0], 0);
                win->windows[4]->setVisible(win->windows[4], 0);
                win->windows[1]->setVisible(win->windows[1], 0);
                win->windows[2]->setVisible(win->windows[2], 0);
                win->windows[3]->setVisible(win->windows[3], 0);
                win->cursor->setVisible(win->cursor, 0);
                saves->substate = 400;
                saves->choosing = 0;
                if (saves->result == 4) {
                    if (saves->choice == 0) {
                        saves->step = 110;
                        win->windows[0]->setString(win->windows[0], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x1E);
                        STGMCARD_showPort(saves, win, 1);
                        win->panel->start(win->panel, 1, 0x90);
                    } else {
                        saves->step = 1;
                        win->panel->reset(win->panel);
                    }
                } else if (saves->choice == 0) {
                    saves->step = 120;
                    win->windows[0]->setString(win->windows[0], FILE_CACHE.load(TEXT_FILE(TEXT_MEMORY_CARD)), 0x1F);
                    STGMCARD_showPort(saves, win, 1);
                    win->panel->start(win->panel, 1, 0x90);
                } else {
                    saves->step = 1;
                    win->panel->reset(win->panel);
                }
            } else if (PAD_PRESSED(PAD_TRIANGLE)) {
                SOUND.playSound(SOUND_MENU_CANCEL);
                win->windows[0]->setVisible(win->windows[0], 0);
                win->windows[4]->setVisible(win->windows[4], 0);
                win->windows[1]->setVisible(win->windows[1], 0);
                win->windows[2]->setVisible(win->windows[2], 0);
                win->windows[3]->setVisible(win->windows[3], 0);
                win->cursor->setVisible(win->cursor, 0);
                saves->substate = 400;
                saves->choosing = 0;
                saves->step = 1;
                win->panel->reset(win->panel);
            }
            status = MEMCARD_SYSTEM.funcs.check(saves->port);
            if (status != 0) {
                if (status != 1) {
                    saves->result = status;
                    saves->choosing = 0;
                    STGMCARD_showError(saves, win);
                }
            }
        } else if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            saves->substate = 400;
            saves->prompting = 0;
            saves->step = 1;
        }
        break;
    case 400:
        status = saves->result = MEMCARD_SYSTEM.funcs.check(saves->port);
        if (status != 0) {
            saves->substate++;
        }
        break;
    case 401:
        if (saves->result != 1) {
            STGMCARD_showError(saves, win);
        }
        saves->substate = saves->step;
        saves->step = saves->counter;
        saves->counter = 0;
        break;
    case 110:
        status = saves->result = MEMCARD_SYSTEM.funcs.format(saves->port);
        if (status != 0) {
            if (status == 1) {
                win->panel->start(win->panel, 2, 0x14);
                saves->substate++;
            } else {
                STGMCARD_showError(saves, win);
            }
        }
        break;
    case 111:
        if (win->panel->done != 0) {
            STGMCARD_showError(saves, win);
            saves->result = 5;
        }
        break;
    case 120:
        saves->substate = 121;
        break;
    case 121:
        status = saves->result = MEMCARD_SYSTEM.funcs.create(saves->port);
        if (status != 0) {
            if (status == 1) {
                saves->substate++;
            } else {
                STGMCARD_showError(saves, win);
            }
        }
        break;
    case 122:
        status = saves->result = MEMCARD_SYSTEM.funcs.write(saves->port, (u8 *)&MEMCARD.header, sizeof(CardHeader), 0);
        if (status != 0) {
            if (status == 1) {
                if ((u32)(MEMCARD.iconCount - 1) >= 3) {
                    saves->result = 3;
                    STGMCARD_showError(saves, win);
                } else {
                    MEMCARD.unk324 = 0;
                    saves->substate++;
                }
            } else {
                saves->result = 10;
                STGMCARD_showError(saves, win);
            }
        }
        break;
    case 123:
        status = saves->result = MEMCARD_SYSTEM.funcs.write(saves->port, (u8 *)MEMCARD.icons[MEMCARD.unk324], 0x80, (MEMCARD.unk324 * 0x80 + 0x80) << 8);
        if (status != 0) {
            if (status == 1) {
                MEMCARD.unk324++;
                if (MEMCARD.unk324 > MEMCARD.iconCount - 1) {
                    HEAP.zero(STGMCARD_funcs.infoBuf, sizeof(MemCardFile));
                    STGMCARD_funcs.infoBuf->magic = MEMCARD_FILE_MAGIC;
                    STGMCARD_funcs.infoBuf->version = MEMCARD_SAVE_VERSION;
                    STGMCARD_funcs.infoBuf->checksum = MEMCARD_SYSTEM.funcs.computeChecksum((u8 *)&STGMCARD_funcs.infoBuf->magic, sizeof(MemCardFile) - 4);
                    saves->file = *STGMCARD_funcs.infoBuf;
                    STGMCARD_funcs.lastSlot = STGMCARD_funcs.infoBuf->last;
                    saves->substate++;
                }
            } else {
                saves->result = 11;
                STGMCARD_showError(saves, win);
            }
        }
        break;
    case 124:
        status = saves->result = MEMCARD_SYSTEM.funcs.write(saves->port, (u8 *)STGMCARD_funcs.infoBuf, sizeof(MemCardFile), 1);
        if (status != 0) {
            win->panel->start(win->panel, 2, 0x14);
            saves->substate++;
        }
        break;
    case 125:
        if (win->panel->done != 0) {
            win->panel->reset(win->panel);
            if (saves->result == 1) {
                saves->substate = 30;
            } else {
                STGMCARD_showError(saves, win);
            }
        }
        break;
    }
}

/* Draws the save list's sprites: the blinking cross button while a message
   waits for it, the list's frame and the box of the cursor's two choices */
void STGMCARD_drawSaves(MemCardSaves *saves) {
    SpriteDrawer sprite;

    initSpriteDrawer(&sprite);
    sprite.setLayerId(saves->layer, 2);
    sprite.setTexture(0x140, 0);
    if (saves->prompting != 0) {
        if ((GFX.funcs.getTime() - saves->blinkTime) / 3 != 0) {
            saves->blinkTime = GFX.funcs.getTime();
            saves->blinkFrame++;
            if (saves->blinkFrame >= 5) {
                saves->blinkFrame = 0;
            }
        }
        sprite.setClutRow(saves->blinkFrame);
        sprite.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 10, 294, 208);
    }
    sprite.setTexture(0x280, 0);
    sprite.setClutRow(0);
    sprite.draw(FILE_CACHE.getEntry(FILE_GMCARD_SHEET << 16), 33, saves->origin[0] + saves->slide[0].value, saves->origin[1] + saves->slide[1].value);
    if (saves->choosing != 0) {
        sprite.setLayerId(saves->layer, 1);
        sprite.draw(FILE_CACHE.getEntry(FILE_GMCARD_SHEET << 16), 29, 188, 185);
    }
}

/* The save list's task: creates its windows, then runs it */
void STGMCARD_updateSaves(MemCardSaves *saves, MemCardSavesWindows *win) {
    switch (saves->state) {
    case TASK_INIT:
    default:
        saves->nextState(saves);
        saves->origin[0] = 5;
        saves->origin[1] = 89;
        STGMCARD_funcs.startLerp(&saves->slide[1], 151, 0, 10);
        win->title = createTextWindow(saves->layer, 1, saves->origin[0] + 200, saves->origin[1] + (s16)(saves->slide[1].value + 9));
        win->windows[4] = createTextWindow(saves->layer, 1, saves->origin[0] + 15, saves->origin[1] + 24);
        win->windows[0] = createTextWindow(saves->layer, 1, saves->origin[0] + 15, saves->origin[1] + 40);
        win->windows[0]->setLines(win->windows[0], 5);
        win->windows[0]->setDepth(win->windows[0], 1);
        win->windows[1] = createTextWindow(saves->layer, 1, saves->origin[0] + 15, saves->origin[1] + 103);
        win->windows[1]->setLines(win->windows[1], 2);
        win->windows[2] = createTextWindow(saves->layer, 1, 207, 189);
        win->windows[3] = createTextWindow(saves->layer, 1, 207, 203);
        win->cursor = createCursor(saves->layer, 0, 207, 189);
        win->cursor->setVisible(win->cursor, 0);
        win->menu = STGMCARD_createMenu(saves);
        break;
    case TASK_RUN:
        STGMCARD_runSaves(saves, win);
        STGMCARD_drawSaves(saves);
        break;
    case TASK_DONE:
        switch (saves->substate) {
        case 0:
        default:
            win->title->setVisible(win->title, 0);
            saves->substate++;
            break;
        case 1:
            break;
        }
        STGMCARD_drawSaves(saves);
        break;
    case TASK_KILL:
        break;
    }
}

/* Creates the save list (task) of the main task */
MemCardSaves *STGMCARD_createSaves(MemCardScreen *screen) {
    MemCardSaves *saves = createTask(STGMCARD_updateSaves, sizeof(MemCardSaves), sizeof(MemCardSavesWindows));

    saves->refresh = STGMCARD_refreshSaves;
    saves->hide = STGMCARD_hideSaves;
    saves->screen = screen;
    saves->layer = SCREEN_LAYER;
    return saves;
}
