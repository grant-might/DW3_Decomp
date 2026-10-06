#include "common.h"
#include "stgdglab.h"

/* Creates the panel's windows */
void STGDGLAB_createEntryListWindows(LabEntryList *panel, LabEntryListWindows *windows) {
    s32 i;
    TextWindow **items;

    windows->title = createTextWindow(panel->layer, 1, 0xAE, 0x15);
    for (i = 0; i < 3; i++) {
        windows->options[i] = createTextWindow(panel->layer, 1, 0xA7, i * 0xE + 0x31);
    }
    windows->unk10 = createTextWindow(panel->layer, 1, 0x5B, 0x6A);
    for (i = 0; i < 6; i++) {
        windows->values[i] = createTextWindow(panel->layer, 1, 0x7D, i * 0xE + 0x7F);
    }
    for (i = 0; i < 7; i++) {
        windows->values[i + 6] = createTextWindow(panel->layer, 1, 0xA7, i * 0xE + 0x7F);
    }
    windows->unk14 = createTextWindow(panel->layer, 1, 0xEB, 0x6A);
    windows->values[13] = createTextWindow(panel->layer, 1, 0x12D, 0x6A);
    for (i = 0; i < 6; i++) {
        windows->skills[i] = createTextWindow(panel->layer, 1, 0xC2, i * 0xE + 0x8B);
    }
    for (i = 0, items = panel->children; i < panel->childCount - 2; i++, items++) {
        if (*items != NULL) {
            (*items)->setDepth(*items, panel->depth - 1);
        }
    }
}

/* Shows the list of ids and the stats and skills of the one under the
   cursor; or hides the panel's windows */
void STGDGLAB_showEntryList(LabEntryList *panel, LabEntryListWindows *windows, s32 show) {
    PartnerTotals totals;
    PartnerEntry entry;
    DigimonData *data;
    Partner *partner;
    TextWindow **items;
    s16 *stats;
    s32 id;
    s32 value;
    s32 i;

    if (show) {
        if (panel->count == 0) {
            windows->title->setString(windows->title, FILE_CACHE.load(TEXT_FILE(TEXT_DIGI_LAB)), 0x1E);
        } else {
            windows->title->setString(windows->title, FILE_CACHE.load(TEXT_FILE(TEXT_DIGI_LAB)), 0x1F);
        }
        partner = &GAME.partners[panel->partner];
        for (i = 0; i < 3; i++) {
            id = panel->ids[panel->scroll + i];
            if (id < 3) {
                if (i == 0) {
                    windows->options[0]->setString(windows->options[0], FILE_CACHE.load(TEXT_FILE(TEXT_DIGI_LAB)), 0x1B);
                } else {
                    windows->options[i]->setVisible(windows->options[i], 0);
                }
            } else {
                windows->options[i]->setString(windows->options[i], FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)),
                                               GET_DIGIMON(id)->nameId);
                if (partner->battleDigivolve == id) {
                    windows->options[i]->setPalette(windows->options[i], 1);
                } else {
                    windows->options[i]->setPalette(windows->options[i], 0);
                }
            }
        }
        id = panel->ids[panel->scroll + panel->cursor];
        if (id != 0) {
            GAME.funcs.getPartnerEntry(panel->partner, id, &entry);
            GAME.funcs.computeStats(panel->partner, &totals);
            data = GET_DIGIMON(id);
            windows->unk10->setString(windows->unk10, FILE_CACHE.load(TEXT_FILE(TEXT_DIGIMON_NAMES)), data->nameId);
            windows->unk14->setString(windows->unk14, FILE_CACHE.load(TEXT_FILE(TEXT_DIGI_LAB)), 0x13);
            windows->values[13]->setNumber(windows->values[13], 0, entry.level);
            for (i = 0; i < 6; i++) {
                value = totals.fields.battle[i] + data->battleStats[i];
                if (value >= 1000) {
                    value = 999;
                }
                windows->values[i]->setNumber(windows->values[i], 0, value);
                if ((i == 0 && totals.fields.lowered[0] != 0) || (i == 1 && totals.fields.lowered[1] != 0) ||
                    (i == 4 && totals.fields.lowered[2] != 0)) {
                    windows->values[i]->setPalette(windows->values[i], 6);
                }
            }
            stats = totals.stats;
            for (i = 0; i < 7; i++) {
                value = stats[i + 12] + data->resistances[i];
                if (value >= 1000) {
                    value = 999;
                }
                windows->values[i + 6]->setNumber(windows->values[i + 6], 0, value);
            }
            for (i = 0; i < 6; i++) {
                if (entry.skills[i] != 0) {
                    windows->skills[i]->setString(windows->skills[i], FILE_CACHE.load(TEXT_FILE(TEXT_SKILL_NAMES)),
                                                  entry.skills[i] & SKILL_ID);
                    if (entry.skills[i] & SKILL_LAST) {
                        windows->skills[i]->setPalette(windows->skills[i], 3);
                    } else if (entry.skills[i] & 0x4000) {
                        windows->skills[i]->setPalette(windows->skills[i], 4);
                    } else {
                        windows->skills[i]->setPalette(windows->skills[i], 0);
                    }
                } else {
                    windows->skills[i]->setVisible(windows->skills[i], 0);
                }
            }
            for (i = 0; i < 14; i++) {
                windows->values[i]->setRightAlign(windows->values[i], 1);
            }
        } else {
            windows->unk10->setVisible(windows->unk10, 0);
            windows->unk14->setVisible(windows->unk14, 0);
            for (i = 0; i < 14; i++) {
                windows->values[i]->setVisible(windows->values[i], 0);
            }
        }
    } else {
        for (i = 0, items = panel->children; i < panel->childCount - 2; i++, items++) {
            if (*items != NULL) {
                (*items)->setVisible(*items, 0);
            }
        }
    }
}

void STGDGLAB_closeEntryList(LabEntryList *panel) {
    LabEntryListWindows *windows = panel->children;

    STGDGLAB_data.funcs.startFade(&panel->fade, 0);
    STGDGLAB_showEntryList(panel, windows, 0);
    windows->cursor->setVisible(windows->cursor, 0);
    panel->substate++;
}

/* The panel's states: fades in, moves the cursor through the ids and
   scrolls the list; triangle closes it */
void STGDGLAB_runEntryList(LabEntryList *panel, LabEntryListWindows *windows) {
    s32 cursor;
    s32 scroll;

    switch (panel->substate) {
    case 0:
    default:
        STGDGLAB_data.funcs.startFade(&panel->fade, 1);
        panel->substate++;
        break;
    case 1:
        if (STGDGLAB_data.funcs.updateFade(&panel->fade)) {
            STGDGLAB_showEntryList(panel, windows, 1);
            windows->cursor->setVisible(windows->cursor, 1);
            if (panel->count >= 4) {
                windows->scrollBar = STGDGLAB_createScrollBar();
                windows->scrollBar->setX(windows->scrollBar, 0x122, 0xC);
                windows->scrollBar->setRange(windows->scrollBar, 0x35, 0x55);
                windows->scrollBar->setCount(windows->scrollBar, 3, panel->count);
                windows->scrollBar->setPos(windows->scrollBar, panel->cursor);
            }
            panel->substate++;
        }
        break;
    case 2:
        if (panel->count > 0) {
            cursor = panel->cursor;
            scroll = panel->scroll;
            if (PAD_PRESSED(PAD_UP) || PAD_REPEATED(PAD_UP)) {
                panel->cursor--;
                if (panel->cursor < 0) {
                    panel->cursor = 0;
                    panel->scroll--;
                    if (panel->scroll < 0) {
                        panel->scroll = 0;
                    }
                }
            } else if (PAD_PRESSED(PAD_DOWN) || PAD_REPEATED(PAD_DOWN)) {
                if (panel->count >= 3) {
                    panel->cursor++;
                    if (panel->cursor >= 3) {
                        panel->cursor = 2;
                        panel->scroll++;
                        if (panel->scroll > panel->count - 3) {
                            panel->scroll = panel->count - 3;
                        }
                    }
                } else {
                    panel->cursor++;
                    if (panel->cursor > panel->count - 1) {
                        panel->cursor = panel->count - 1;
                    }
                }
            }
#if VERSION_EU
            if (windows->scrollBar != NULL && scroll != panel->scroll) {
                windows->scrollBar->setPos(windows->scrollBar, panel->scroll);
            }
#endif
            if (cursor != panel->cursor || scroll != panel->scroll) {
                SOUND.playSound(SOUND_CURSOR);
                STGDGLAB_showEntryList(panel, windows, 1);
                windows->cursor->setPos(windows->cursor, 0x9A, panel->cursor * 0xE + 0x31);
#if VERSION_US
                if (windows->scrollBar != NULL) {
                    windows->scrollBar->setPos(windows->scrollBar, panel->cursor + panel->scroll);
                }
#endif
            }
        }
        if (panel->closable != 0 && PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            STGDGLAB_closeEntryList(panel);
            if (windows->scrollBar != NULL) {
                windows->scrollBar->state = TASK_KILL;
            }
        }
        break;
    case 3:
        if (STGDGLAB_data.funcs.updateFade(&panel->fade)) {
            panel->setState(panel, TASK_KILL);
        }
        break;
    case 4:
        windows->cursor->setVisible(windows->cursor, 0);
        break;
    case 5:
        windows->cursor->setVisible(windows->cursor, 1);
        panel->substate = 2;
        break;
    }
    panel->unk60.level = panel->unk70.level = panel->fade.level;
}

/* Draws the panel's frames, its scroll arrows and the icons of the skills
   of the id under the cursor */
void STGDGLAB_drawEntryList(LabEntryList *panel, LabEntryListWindows *windows) {
    SpriteDrawer sprite;
    PartnerEntry entry;
    s32 i;

    initSpriteDrawer(&sprite);
    sprite.setTexture(0x280, 0x100);
    sprite.setLayerId(panel->layer, panel->depth);
    if (panel->unk60.level != 0x1000) {
        sprite.setScale(panel->unk60.level, 0x1000, 0x1000);
        sprite.setPivot(0x140, 0x15);
    }
    sprite.draw(FILE_CACHE.getEntry(FILE_LAB_SPRITES << 16), 0x20, 0x92, 0xF);
    if (panel->unk70.level != 0x1000) {
        sprite.setScale(panel->unk70.level, 0x1000, 0x1000);
        sprite.setPivot(0x140, 0x45);
    } else {
        sprite.setScale(0x1000, 0x1000, 0x1000);
    }
    if (panel->unk70.level == 0x1000) {
        if (GFX.funcs.getTime() - panel->blinkTime >= 8) {
            panel->blinkTime = GFX.funcs.getTime();
            panel->blink = 1 - panel->blink;
        }
        if (panel->blink) {
            if (panel->scroll != 0) {
                sprite.draw(FILE_CACHE.getEntry(FILE_LAB_SPRITES << 16), 0x34, 0x123, 0x2D);
            }
            if (panel->scroll < panel->count - 3) {
                sprite.draw(FILE_CACHE.getEntry(FILE_LAB_SPRITES << 16), 0x35, 0x123, 0x55);
            }
        }
    }
    sprite.draw(FILE_CACHE.getEntry(FILE_LAB_SPRITES << 16), 0x22, 0x92, 0x2A);
    if (panel->count > 0) {
        if (panel->fade.level != 0x1000) {
            sprite.setScale(panel->unk70.level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0xA4);
        } else {
            sprite.setScale(0x1000, 0x1000, 0x1000);
        }
        sprite.draw(FILE_CACHE.getEntry(FILE_LAB_SPRITES << 16), 0x2A, 0x54, 0x64);
        sprite.setTexture(0x140, 0);
        sprite.setLayerId(panel->layer, panel->depth - 1);
        sprite.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 0x14, 0x5B, 0x7F);
        GAME.funcs.getPartnerEntry(panel->partner, panel->ids[panel->scroll + panel->cursor], &entry);
        for (i = 0; i < 6; i++) {
            if (entry.skills[i] != 0) {
                sprite.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16),
                            TECHS[(entry.skills[i] & SKILL_ID) - 1].icon + 0x37, 0xB4, i * 0xE + 0x8B);
            }
        }
    }
}

void STGDGLAB_updateEntryList(LabEntryList *panel, LabEntryListWindows *windows) {
    s16 slots[4];
    s16 entries[44];
    s32 i;

    switch (panel->state) {
    case TASK_INIT:
    default:
        panel->nextState(panel);
        GAME.funcs.getPartnerSlots(panel->partner, slots);
        for (i = 0; i < 3; i++) {
            if (slots[i] < 3) {
                break;
            }
            panel->ids[panel->count] = slots[i];
            panel->count++;
        }
        if (panel->allEntries != 0) {
            GAME.funcs.listPartnerEntries(panel->partner, entries);
            for (i = 0; i < 44; i++) {
                if (entries[i] >= 3 && panel->ids[0] != entries[i] && panel->ids[1] != entries[i] &&
                    panel->ids[2] != entries[i]) {
                    panel->ids[panel->count] = entries[i];
                    panel->count++;
                }
            }
        }
        STGDGLAB_createEntryListWindows(panel, windows);
        windows->cursor = createCursor(panel->layer, panel->depth - 1, 0x9A, panel->cursor * 0xE + 0x31);
        windows->cursor->setVisible(windows->cursor, 0);
        panel->unk60.duration = 10;
        panel->unk70.duration = 10;
        panel->fade.duration = 10;
        break;
    case TASK_RUN:
        STGDGLAB_runEntryList(panel, windows);
        STGDGLAB_drawEntryList(panel, windows);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

LabEntryList *STGDGLAB_createEntryList(s32 partner, s32 allEntries, s32 closable) {
    LabEntryList *panel = createTask(STGDGLAB_updateEntryList, sizeof(LabEntryList), 0x70);

    panel->close = STGDGLAB_closeEntryList;
    panel->layer = 0x1000;
    panel->depth = 2;
    panel->allEntries = allEntries;
    panel->partner = partner;
    panel->closable = closable;
    return panel;
}

void STGDGLAB_runLab(Lab *lab, LabChildren *children) {
    switch (lab->substate) {
    case 0:
    default:
        if (children->menu == NULL) {
            children->menu = STGDGLAB_createMenu(lab);
        }
        lab->substate++;
        break;
    case 1:
        if (children->menu != NULL) {
            if (children->menu->picked != 0) {
                children->screen = STGDGLAB_screens[children->menu->choice](lab);
                lab->substate++;
            }
        } else {
            lab->substate = 3;
        }
        break;
    case 2:
        if (children->screen == NULL) {
            lab->substate = 1;
            children->menu->picked = 0;
        }
        break;
    case 3:
        if (children->fade->state == 2) {
            lab->setState(lab, TASK_KILL);
        }
        break;
    }
}

void STGDGLAB_packParty(Lab *lab) {
    s32 i;
    s32 j;

    lab->partyCount = 0;
    for (i = 0; i < 3; i++) {
        if (GAME.party[i] >= 0) {
            lab->partyCount++;
        }
    }
    for (i = 0; i < 3; i++) {
        if (GAME.party[i] < 0) {
            for (j = i; j < 3; j++) {
                if (GAME.party[j] >= 0) {
                    GAME.party[i] = GAME.party[j];
                    GAME.party[j] = -1;
                    break;
                }
            }
        }
    }
}

void STGDGLAB_updateLab(Lab *lab, LabChildren *children) {
    SpriteDrawer sprite;

    switch (lab->state) {
    case TASK_INIT:
    default:
        switch (lab->substate) {
        case 0:
        default:
            STGDGLAB_data.funcs.loadFiles();
            lab->substate++;
            break;
        case 1:
            if (STGDGLAB_data.funcs.filesLoading() == 0) {
                lab->nextState(lab);
                lab->unk5C = 3;
                STGDGLAB_packParty(lab);
            }
            break;
        }
        break;
    case TASK_RUN:
        STGDGLAB_runLab(lab, children);
        initSpriteDrawer(&sprite);
        sprite.setLayerId(lab->layer, 7);
        sprite.setTexture(0x280, 0x100);
        if (lab->blinkSkip != 0) {
            lab->blinkPos++;
            lab->blinkPos = lab->blinkPos < 0x60 ? lab->blinkPos : 0;
            lab->blinkSkip = 0;
        } else {
            lab->blinkSkip = 1;
        }
        sprite.draw(FILE_CACHE.getEntry(FILE_LAB_SPRITES << 16), 0x37, lab->blinkPos, lab->blinkPos);
        break;
    case TASK_DONE:
        break;
    case TASK_KILL:
        GAME.funcs.requestMode(GAME.fieldMode, 0);
        break;
    }
}

s32 STGDGLAB_openLabMenu(Lab *lab) {
    LabMenu *menu = ((LabChildren *)lab->children)->menu;

    if (menu != NULL && menu->state == TASK_RUN) {
        menu->open(menu);
        return 1;
    }
    return 0;
}

s32 STGDGLAB_closeLabMenu(Lab *lab) {
    LabMenu *menu = ((LabChildren *)lab->children)->menu;

    if (menu != NULL && menu->state == TASK_RUN) {
        menu->close(menu);
        return 1;
    }
    return 0;
}

s32 STGDGLAB_labMenuRunning(Lab *lab) {
    LabMenu *menu = ((LabChildren *)lab->children)->menu;

    if (menu != NULL && menu->state == TASK_RUN) {
        return 1;
    }
    return 0;
}

void STGDGLAB_fadeOutLab(Lab *lab) {
    LabChildren *children = lab->children;

    children->fade = STGDGLAB_createFader();
    children->fade->start(children->fade, 0, 0x1E);
}

Lab *STGDGLAB_createLab(void) {
    Lab *lab = createTask(STGDGLAB_updateLab, sizeof(Lab), sizeof(LabChildren));

    lab->openMenu = STGDGLAB_openLabMenu;
    lab->closeMenu = STGDGLAB_closeLabMenu;
    lab->menuOpen = STGDGLAB_labMenuRunning;
    lab->packParty = STGDGLAB_packParty;
    lab->fadeOut = STGDGLAB_fadeOutLab;
    lab->layer = 0x1000;
    return lab;
}

void STGDGLAB_loadFiles(void) {
    TimLoader loader;

    initTimLoader(&loader);
    loader.setImagePos(0x280, 0x100);
    loader.loadArchive(FILE_CACHE.getEntry((FILE_LAB_SPRITES + 1) << 16));
    loader.setImagePos(0x140, 0x100);
    loader.setClutPos(0x280, 0);
    loader.setBufferSize(0x10000);
    loader.loadArchive(FILE_CACHE.getEntry(((FILE_LAB_SPRITES + 1) << 16) + 2));
    FILE_CACHE.request(TEXT_FILE(TEXT_DIGI_LAB));
    FILE_CACHE.request(TEXT_FILE(TEXT_DIGIMON_NAMES));
    FILE_CACHE.request(TEXT_FILE(TEXT_DIGIMON_INFO));
    FILE_CACHE.request(TEXT_FILE(TEXT_SKILL_NAMES));
    FILE_CACHE.request(TEXT_FILE(TEXT_SKILL_INFO));
}

s32 STGDGLAB_filesLoading(void) {
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_DIGI_LAB)) != 0) {
        return 1;
    }
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_DIGIMON_NAMES)) != 0) {
        return 1;
    }
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_DIGIMON_INFO)) != 0) {
        return 1;
    }
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_SKILL_NAMES)) != 0) {
        return 1;
    }
    return FILE_CACHE.isLoading(TEXT_FILE(TEXT_SKILL_INFO)) != 0;
}

void STGDGLAB_startFade(PanelAnim *fade, s32 fadeIn) {
    fade->active = 1;
    if (fadeIn != 0) {
        SOUND.playSound(SOUND_MENU_OPEN);
        fade->level = 0;
        fade->step = 0x1000 / fade->duration;
    } else {
        SOUND.playSound(SOUND_MENU_CLOSE);
        fade->level = 0x1000;
        fade->step = -((0x1000 / fade->duration) * 2);
    }
}

s32 STGDGLAB_updateFade(PanelAnim *fade) {
    if (fade->active == 0) {
        return 1;
    }
    fade->level += fade->step;
    if (fade->step > 0) {
        if (fade->level > 0x1000) {
            fade->level = 0x1000;
            fade->active = 0;
            return 1;
        }
    } else if (fade->level < 0) {
        fade->level = 0;
        fade->active = 0;
        return 1;
    }
    return 0;
}

void STGDGLAB_startLerp(LabLerp *lerp, s32 from, s32 to, s32 frames) {
    if (from != to) {
        lerp->duration = frames;
        lerp->fixed = from << 8;
        lerp->value = from;
        lerp->target = to;
        lerp->active = 1;
        lerp->step = ((to - from) << 8) / lerp->duration;
    }
}

s32 STGDGLAB_updateLerp(LabLerp *lerp) {
    if (lerp->active == 0) {
        return 1;
    }
    lerp->fixed += lerp->step;
    lerp->value = lerp->fixed >> 8;
    if (lerp->step > 0) {
        if (lerp->target < lerp->value) {
            lerp->value = lerp->target;
            lerp->active = 0;
            return 1;
        }
    } else if (lerp->value < lerp->target) {
        lerp->value = lerp->target;
        lerp->active = 0;
        return 1;
    }
    return 0;
}

s32 STGDGLAB_getItemSprite(s32 id) {
    s32 i;

    for (i = 0; STGDGLAB_entries[i].id != 0; i++) {
        if (STGDGLAB_entries[i].id == id) {
            return STGDGLAB_entries[i].sprite;
        }
    }
    return 0;
}

s32 func_8008EC48(s32 id) {
    s32 i;

    for (i = 0; STGDGLAB_entries[i].id != 0; i++) {
        if (STGDGLAB_entries[i].id == id) {
            return STGDGLAB_entries[i].b;
        }
    }
    return 0;
}

/* The main menu's screens */
Task *(*STGDGLAB_screens[])(Lab *lab) = {
    STGDGLAB_createPartyScreen, STGDGLAB_createSlotScreen, STGDGLAB_createRecipeScreen,
};
/* The partners' animation frames, -1 ends */
LabAnim STGDGLAB_partnerAnims[] = {
    { { 7, 8, 9, 10, 9, 8, -1 } },
    { { 14, 15, 16, 15, -1, -1, -1 } },
    { { 11, 12, 13, 12, -1, -1, -1 } },
    { { 3, 4, 5, 6, 5, 4, -1 } },
    { { 25, 26, 27, 28, 27, 26, -1 } },
    { { 0, 1, 2, 1, -1, -1, -1 } },
    { { 17, 18, 19, 20, 19, 18, -1 } },
    { { 21, 22, 23, 24, 23, 22, -1 } },
};
/* Where the windows go: string, x and y */
s32 STGDGLAB_layout[] = {
    21, 51, 38, 22,
    51, 48, 23, 95,
    48, 14, 51, 57,
    23, 95, 57, 18,
    80, 38, 18, 93,
    48, 18, 128, 48,
    18, 93, 57, 18,
    128, 57, -1, 51,
    23,
};
/* The items of the recipes, up to id 0: their sprite (STGDGLAB_getItemSprite) and
   func_8008EC48's value */
LabEntry STGDGLAB_entries[] = {
    { 0x017F, 0x0002, 0x010C },
    { 0x0181, 0x0004, 0x011D },
    { 0x0180, 0x0003, 0x0114 },
    { 0x0003, 0x0001, 0x012A },
    { 0x0091, 0x0007, 0x012B },
    { 0x016E, 0x0000, 0x012C },
    { 0x0175, 0x0005, 0x0115 },
    { 0x001F, 0x0006, 0x010D },
    { 0x0005, 0x0022, 0x0127 },
    { 0x0006, 0x001D, 0x0132 },
    { 0x000C, 0x0023, 0x0125 },
    { 0x0013, 0x0017, 0x011C },
    { 0x0014, 0x000B, 0x010A },
    { 0x001A, 0x0028, 0x0131 },
    { 0x001B, 0x0025, 0x0108 },
    { 0x0038, 0x0021, 0x0135 },
    { 0x003B, 0x0010, 0x0123 },
    { 0x0042, 0x001E, 0x0130 },
    { 0x0090, 0x000F, 0x0119 },
    { 0x0094, 0x0013, 0x0121 },
    { 0x0096, 0x002A, 0x011E },
    { 0x0097, 0x0019, 0x012D },
    { 0x00C4, 0x0026, 0x0117 },
    { 0x00D3, 0x000C, 0x0105 },
    { 0x00D5, 0x0024, 0x0102 },
    { 0x00D6, 0x000D, 0x0134 },
    { 0x00E6, 0x0018, 0x0118 },
    { 0x00EA, 0x000E, 0x0106 },
    { 0x00FE, 0x0012, 0x0124 },
    { 0x0103, 0x0011, 0x0129 },
    { 0x0104, 0x0016, 0x010B },
    { 0x010B, 0x0029, 0x0133 },
    { 0x0167, 0x0014, 0x0120 },
    { 0x016F, 0x0008, 0x0128 },
    { 0x0170, 0x0009, 0x0126 },
    { 0x0171, 0x000A, 0x011F },
    { 0x0174, 0x0027, 0x0122 },
    { 0x0176, 0x001A, 0x0112 },
    { 0x0177, 0x001B, 0x0110 },
    { 0x0178, 0x001C, 0x010F },
    { 0x0179, 0x0020, 0x012F },
    { 0x017A, 0x001F, 0x012E },
    { 0x017D, 0x0015, 0x0100 },
    { 0x0182, 0x0031, 0x0109 },
    { 0x0183, 0x002B, 0x0113 },
    { 0x0184, 0x002E, 0x011B },
    { 0x0185, 0x0032, 0x0107 },
    { 0x0186, 0x002C, 0x0111 },
    { 0x0187, 0x002F, 0x011A },
    { 0x0188, 0x0033, 0x0101 },
    { 0x0189, 0x002D, 0x010E },
    { 0x018A, 0x0030, 0x0116 },
    { 0x0000, 0x0000, 0x0000 },
};
/* The recipes of each table (STGDGLAB_data.recipes), by row and column: a
   count, then the items */
#if VERSION_US
LabRecipe STGDGLAB_recipes0[] = {
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 3, 0x005, 0x00C, 0x0D5, 0, 0 },
    { 3, 0, 0x01A, 0x10B, 0x096, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0x01B, 0x0C4, 0x174, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 3, 0x0EA, 0x090, 0x03B, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 4, 0x006, 0x042, 0x17A, 0x179, 0 },
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
};
LabRecipe STGDGLAB_recipes1[] = {
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0x01B, 0x0C4, 0x174, 0, 0 },
    { 4, 0x006, 0x042, 0x17A, 0x179, 0 },
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 3, 0x0EA, 0x090, 0x03B, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x005, 0x00C, 0x0D5, 0, 0 },
    { 3, 0, 0x01A, 0x10B, 0x096, 0 },
    { 3, 0, 0x182, 0x185, 0x188, 0 },
    { 0, 0, 0, 0, 0, 0 },
};
LabRecipe STGDGLAB_recipes2[] = {
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0, 0x01B, 0x0C4, 0x174, 0 },
    { 1, 0, 0x038, 0, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 3, 0, 0x0EA, 0x090, 0x03B, 0 },
    { 3, 0, 0x176, 0x177, 0x178, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x005, 0x00C, 0x0D5, 0, 0 },
    { 3, 0, 0x01A, 0x10B, 0x096, 0 },
    { 4, 0, 0x006, 0x042, 0x17A, 0x179 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0, 0x16F, 0x170, 0x171, 0 },
    { 3, 0, 0x184, 0x187, 0x18A, 0 },
};
LabRecipe STGDGLAB_recipes3[] = {
    { 3, 0x005, 0x00C, 0x0D5, 0, 0 },
    { 3, 0, 0x01A, 0x10B, 0x096, 0 },
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x01B, 0x0C4, 0x174, 0, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 1, 0, 0x038, 0, 0, 0 },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 3, 0, 0x0EA, 0x090, 0x03B, 0 },
    { 4, 0, 0x006, 0x042, 0x17A, 0x179 },
};
LabRecipe STGDGLAB_recipes4[] = {
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0, 0x01B, 0x0C4, 0x174, 0 },
    { 4, 0, 0x006, 0x042, 0x17A, 0x179 },
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 3, 0x005, 0x00C, 0x0D5, 0, 0 },
    { 3, 0, 0x01A, 0x10B, 0x096, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 3, 0, 0x0EA, 0x090, 0x03B, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
};
LabRecipe STGDGLAB_recipes5[] = {
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 3, 0x01B, 0x0C4, 0x174, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 3, 0x0EA, 0x090, 0x03B, 0, 0 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0x005, 0x00C, 0x0D5, 0, 0 },
    { 3, 0, 0x01A, 0x10B, 0x096, 0 },
    { 4, 0x006, 0x042, 0x17A, 0x179, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
};
LabRecipe STGDGLAB_recipes6[] = {
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0x0EA, 0x090, 0x03B, 0, 0 },
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0x01B, 0x0C4, 0x174, 0, 0 },
    { 4, 0x006, 0x042, 0x17A, 0x179, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x005, 0x00C, 0x0D5, 0, 0 },
    { 3, 0, 0x01A, 0x10B, 0x096, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
};
LabRecipe STGDGLAB_recipes7[] = {
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 3, 0x0EA, 0x090, 0x03B, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0x005, 0x00C, 0x0D5, 0, 0 },
    { 3, 0, 0x01A, 0x10B, 0x096, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 3, 0, 0x01B, 0x0C4, 0x174, 0 },
    { 3, 0, 0x16F, 0x170, 0x171, 0 },
    { 4, 0, 0x006, 0x042, 0x17A, 0x179 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
};
#elif VERSION_EU
LabRecipe STGDGLAB_recipes0[] = {
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 4, 0x005, 0x00C, 0x0D5, 0x096, 0 },
    { 2, 0, 0x01A, 0x10B, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0x01B, 0x0C4, 0x174, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 3, 0x0EA, 0x090, 0x03B, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 4, 0x006, 0x042, 0x17A, 0x179, 0 },
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
};
LabRecipe STGDGLAB_recipes1[] = {
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0x01B, 0x0C4, 0x174, 0, 0 },
    { 4, 0x006, 0x042, 0x17A, 0x179, 0 },
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 3, 0x0EA, 0x090, 0x03B, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 4, 0x005, 0x00C, 0x0D5, 0x096, 0 },
    { 2, 0, 0x01A, 0x10B, 0, 0 },
    { 3, 0, 0x182, 0x185, 0x188, 0 },
    { 0, 0, 0, 0, 0, 0 },
};
LabRecipe STGDGLAB_recipes2[] = {
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0, 0x01B, 0x0C4, 0x174, 0 },
    { 1, 0, 0x038, 0, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 3, 0, 0x0EA, 0x090, 0x03B, 0 },
    { 3, 0, 0x176, 0x177, 0x178, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 4, 0x005, 0x00C, 0x0D5, 0x096, 0 },
    { 2, 0, 0x01A, 0x10B, 0, 0 },
    { 4, 0, 0x006, 0x042, 0x17A, 0x179 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0, 0x16F, 0x170, 0x171, 0 },
    { 3, 0, 0x184, 0x187, 0x18A, 0 },
};
LabRecipe STGDGLAB_recipes3[] = {
    { 4, 0x005, 0x00C, 0x0D5, 0x096, 0 },
    { 2, 0, 0x01A, 0x10B, 0, 0 },
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x01B, 0x0C4, 0x174, 0, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 1, 0, 0x038, 0, 0, 0 },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 3, 0, 0x0EA, 0x090, 0x03B, 0 },
    { 4, 0, 0x006, 0x042, 0x17A, 0x179 },
};
LabRecipe STGDGLAB_recipes4[] = {
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0, 0x01B, 0x0C4, 0x174, 0 },
    { 4, 0, 0x006, 0x042, 0x17A, 0x179 },
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 4, 0x005, 0x00C, 0x0D5, 0x096, 0 },
    { 2, 0, 0x01A, 0x10B, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 3, 0, 0x0EA, 0x090, 0x03B, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
};
LabRecipe STGDGLAB_recipes5[] = {
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 3, 0x01B, 0x0C4, 0x174, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 3, 0x0EA, 0x090, 0x03B, 0, 0 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 4, 0x005, 0x00C, 0x0D5, 0x096, 0 },
    { 2, 0, 0x01A, 0x10B, 0, 0 },
    { 4, 0x006, 0x042, 0x17A, 0x179, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
};
LabRecipe STGDGLAB_recipes6[] = {
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 3, 0x0EA, 0x090, 0x03B, 0, 0 },
    { 3, 0x16F, 0x170, 0x171, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0x01B, 0x0C4, 0x174, 0, 0 },
    { 4, 0x006, 0x042, 0x17A, 0x179, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 4, 0x005, 0x00C, 0x0D5, 0x096, 0 },
    { 2, 0, 0x01A, 0x10B, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
};
LabRecipe STGDGLAB_recipes7[] = {
    { 3, 0x014, 0x0D3, 0x0D6, 0, 0 },
    { 1, 0x038, 0, 0, 0, 0 },
    { 3, 0x0EA, 0x090, 0x03B, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 4, 0x104, 0x013, 0, 0x0E6, 0x097 },
    { 4, 0x005, 0x00C, 0x0D5, 0x096, 0 },
    { 2, 0, 0x01A, 0x10B, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 3, 0x183, 0x186, 0x189, 0, 0 },
    { 3, 0, 0x01B, 0x0C4, 0x174, 0 },
    { 3, 0, 0x16F, 0x170, 0x171, 0 },
    { 4, 0, 0x006, 0x042, 0x17A, 0x179 },
    { 3, 0x176, 0x177, 0x178, 0, 0 },
    { 3, 0x182, 0x185, 0x188, 0, 0 },
    { 5, 0x103, 0x0FE, 0x094, 0x167, 0x17D },
    { 3, 0x184, 0x187, 0x18A, 0, 0 },
};
#endif
LabData STGDGLAB_data = {
    STGDGLAB_partnerAnims,
    STGDGLAB_layout,
    {
        STGDGLAB_recipes0, STGDGLAB_recipes1, STGDGLAB_recipes2, STGDGLAB_recipes3,
        STGDGLAB_recipes4, STGDGLAB_recipes5, STGDGLAB_recipes6, STGDGLAB_recipes7,
    },
    {
        STGDGLAB_loadFiles, STGDGLAB_filesLoading, STGDGLAB_startFade, STGDGLAB_updateFade,
        STGDGLAB_startLerp, STGDGLAB_updateLerp, STGDGLAB_getItemSprite, func_8008EC48,
    },
};
