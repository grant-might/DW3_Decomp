/* The last object of STSTATUS.PRO (see ststatus.c), the mode's main task,
   the scroll bar and the helpers in STSTATUS_data: it has no rodata, so
   where its code starts is a guess. */

#include "ststatus.h"

void STSTATUS_moveMapCursor(StatusMapScreen *screen, s32 dx, s32 dy);
void STSTATUS_drawMapScreen(StatusMapScreen *screen);

/* Finds the area under the cursor and shows its name */
void STSTATUS_showMapArea(StatusMapScreen *screen, TextWindow **windows) {
    s32 wasHovering = screen->hovering;
    StatusMapSpot *spots;
    s32 spotX;
    s32 spotY;
    s32 x;
    s32 y;
    s32 i;

    screen->hovering = 0;
    x = screen->cursorX - screen->scrollX;
    y = screen->cursorY - screen->scrollY;
    spots = STSTATUS_data.spots;
    for (i = 1; i < 47; i++) {
        if (screen->visited[i - 1]) {
            spotX = spots[i].x;
            spotY = spots[i].y;
            if (spotX + 6 < x && x <= spotX + 0x12 && spotY + 6 < y && y <= spotY + 0x12) {
                screen->hovering = 1;
                screen->spot = i;
                break;
            }
        }
    }
    if (wasHovering != screen->hovering) {
        if (screen->hovering) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
#if VERSION_EU
            screen->hoverX = screen->cursorX;
#endif
            screen->hoverY = screen->cursorY;
        } else {
            windows[0]->setVisible(windows[0], 0);
        }
    }
    if (screen->hovering) {
        if (screen->hoverY < screen->height / 2) {
            windows[0]->setPos(windows[0], 0x10, 0xB9);
        } else {
            windows[0]->setPos(windows[0], 0x10, 0x19);
        }
        windows[0]->setString(windows[0], FILE_CACHE.load(screen->textFile), screen->spot);
    }
}

/* Moves the cursor, or the map when the cursor is in the middle */
void STSTATUS_moveMapCursor(StatusMapScreen *screen, s32 dx, s32 dy) {
    s32 middle;

    if (dx < 0) {
        if (screen->cursorX > 0xA0) {
            screen->cursorX -= screen->speedX;
            if (screen->cursorX < 0xA0) {
                screen->cursorX = 0xA0;
            }
        } else if (screen->cursorX < 0xA0) {
            screen->cursorX -= screen->speedX;
            if (screen->cursorX < 0x16) {
                screen->cursorX = 0x16;
            }
        } else {
            screen->scrollX += screen->speedX;
            if (screen->scrollX > 0) {
                screen->scrollX = 0;
                screen->cursorX = 0x9F;
            }
        }
    } else if (dx > 0) {
        if (screen->cursorX < 0xA0) {
            screen->cursorX += screen->speedX;
            if (screen->cursorX > 0xA0) {
                screen->cursorX = 0xA0;
            }
        } else if (screen->cursorX > 0xA0) {
            screen->cursorX += screen->speedX;
            if (screen->cursorX > 0x12A) {
                screen->cursorX = 0x12A;
            }
        } else {
            screen->scrollX -= screen->speedX;
            if (screen->scrollX < -0x48) {
                screen->scrollX = -0x48;
                screen->cursorX = 0xA1;
            }
        }
    }
    middle = screen->height / 2;
    if (dy < 0) {
        if (screen->cursorY > middle) {
            screen->cursorY -= screen->speedY;
            if (screen->cursorY < middle) {
                screen->cursorY = middle;
            }
        } else if (screen->cursorY < middle) {
            screen->cursorY -= screen->speedY;
            if (screen->cursorY < 0xF) {
                screen->cursorY = 0xF;
            }
        } else {
            screen->scrollY += screen->speedY;
            if (screen->scrollY > 0) {
                screen->scrollY = 0;
                screen->cursorY = middle - 1;
            }
        }
    } else if (dy > 0) {
        if (screen->cursorY < middle) {
            screen->cursorY += screen->speedY;
            if (screen->cursorY > middle) {
                screen->cursorY = middle;
            }
        } else if (screen->cursorY > middle) {
            screen->cursorY += screen->speedY;
            if (screen->cursorY > screen->height - screen->top - 0x1E) {
                screen->cursorY = screen->height - screen->top - 0x1E;
            }
        } else {
            screen->scrollY -= screen->speedY;
            if (screen->scrollY < -0x60) {
                screen->scrollY = -0x60;
                screen->cursorY = middle + 1;
            }
        }
    }
}

/* Moves the cursor faster while the pad is held; triangle closes */
void STSTATUS_runMapScreen(StatusMapScreen *screen, TextWindow **windows) {
    if (PAD_HELD(PAD_LEFT) || PAD_HELD(PAD_RIGHT)) {
        if (PAD_PRESSED(PAD_LEFT) || PAD_PRESSED(PAD_RIGHT)) {
            screen->speedX = 2;
        } else if (PAD_REPEATED(PAD_LEFT) || PAD_REPEATED(PAD_RIGHT)) {
            screen->speedX++;
            if (screen->speedX > 4) {
                screen->speedX = 4;
            }
        }
    } else {
        screen->speedX = 0;
    }
    if (PAD_HELD(PAD_UP) || PAD_HELD(PAD_DOWN)) {
        if (PAD_PRESSED(PAD_UP) || PAD_PRESSED(PAD_DOWN)) {
            screen->speedY = 2;
        } else if (PAD_REPEATED(PAD_UP) || PAD_REPEATED(PAD_DOWN)) {
            screen->speedY++;
            if (screen->speedY > 4) {
                screen->speedY = 4;
            }
        }
    } else {
        screen->speedY = 0;
    }
    if (PAD_HELD(PAD_LEFT)) {
        STSTATUS_moveMapCursor(screen, -1, 0);
    } else if (PAD_HELD(PAD_RIGHT)) {
        STSTATUS_moveMapCursor(screen, 1, 0);
    }
    if (PAD_HELD(PAD_UP)) {
        STSTATUS_moveMapCursor(screen, 0, -1);
    } else if (PAD_HELD(PAD_DOWN)) {
        STSTATUS_moveMapCursor(screen, 0, 1);
    }
    if (PAD_PRESSED(PAD_TRIANGLE)) {
        SOUND.playSound(SOUND_MENU_CANCEL);
        screen->state = TASK_KILL;
    }
}

/* Draws the map, the visited areas, the towns and the cursor */
void STSTATUS_drawMapScreen(StatusMapScreen *screen) {
    SpriteDrawer sprite;
    s32 *towns;
    s32 x;
    s32 frame;
    s32 i;

    if (screen->hovering) {
        initSpriteDrawer(&sprite);
        sprite.setLayerId(screen->layer, screen->depth - 2);
        sprite.setTexture(0x280, 0x100);
        if (screen->hoverY < screen->height / 2) {
            sprite.draw(FILE_CACHE.getEntry(FILE_STATUS_SPRITES << 16), 0x3B, 0, 0xB4);
        } else {
            sprite.draw(FILE_CACHE.getEntry(FILE_STATUS_SPRITES << 16), 0x3B, 0, 0x14);
        }
    }
    initSpriteDrawer(&sprite);
    if (screen->ready) {
        if (GFX.funcs.getTime() - screen->time >= 4) {
            screen->time = GFX.funcs.getTime();
            screen->cursorFrame++;
            if (screen->cursorFrame >= 4) {
                screen->cursorFrame = 0;
            }
            screen->homeFrame++;
            if (screen->homeFrame >= 3) {
                screen->homeFrame = 0;
            }
        }
        sprite.setTexture(0x300, 0x100);
        if (screen->hovering) {
            sprite.setLayerId(screen->layer, screen->depth);
            sprite.draw(FILE_CACHE.getEntry(screen->archive2), STSTATUS_cursorFrames[screen->cursorFrame] + 0x38,
                        STSTATUS_data.spots[screen->spot].x + 0xC + screen->scrollX,
                        STSTATUS_data.spots[screen->spot].y + 0xC + screen->scrollY + screen->top);
        } else {
            sprite.setLayerId(screen->layer, screen->depth - 1);
            sprite.draw(FILE_CACHE.getEntry(screen->archive2), STSTATUS_cursorFrames[screen->cursorFrame] + 0x32,
                        screen->cursorX, screen->cursorY + screen->top);
        }
        sprite.setLayerId(screen->layer, screen->depth - 2);
#if VERSION_EU
        if (screen->hovering) {
            x = screen->hoverX;
        } else {
            x = screen->cursorX;
        }
        /* the home mark faces the cursor */
        frame = 0x3B;
        if (x < screen->homeX + screen->scrollX) {
            frame = 0x35;
        }
#else
        frame = 0x35;
#endif
        sprite.draw(FILE_CACHE.getEntry(screen->archive2), frame + screen->homeFrame, screen->homeX + screen->scrollX,
                    screen->homeY + screen->scrollY + screen->top);
    }
    sprite.setLayerId(screen->layer, screen->depth - 1);
    if (screen->ready) {
        sprite.setTexture(0x300, 0x100);
        for (i = 1; i < 47; i++) {
            if (screen->visited[i - 1]) {
                sprite.draw(FILE_CACHE.getEntry(screen->archive2), STSTATUS_data.spots[i].sprite,
                            STSTATUS_data.spots[i].x + screen->scrollX,
                            STSTATUS_data.spots[i].y + screen->scrollY + screen->top);
            }
        }
    }
    sprite.setLayerId(screen->layer, screen->depth + 1);
    towns = STSTATUS_data.funcs.getList(screen->lateGame, screen->progress);
    if (GAME.progress < 7) {
        screen->progress = 0;
    } else if (GAME.progress < 0xF) {
        screen->progress = 1;
    } else if (GAME.progress < 0x1B) {
        screen->progress = 2;
    } else if (GAME.progress < 0x1E) {
        screen->progress = 3;
    } else {
        screen->progress = 4;
    }
    sprite.setTexture(0x380, 0x100);
    /* the match depends on indexing the list rather than walking a pointer */
    for (i = 0; towns[i] != 0; i++) {
        sprite.draw(FILE_CACHE.getEntry(screen->archive1), towns[i] - 1, STSTATUS_data.towns[towns[i]].x + screen->scrollX,
                    STSTATUS_data.towns[towns[i]].y + screen->scrollY + screen->top);
    }
    sprite.setTexture(0x280, 0);
    sprite.setAltClut(0x140, 0x100);
    sprite.draw(FILE_CACHE.getEntry(screen->archive), 0, screen->scrollX, screen->scrollY + screen->top);
}

/* The map screen's update */
void STSTATUS_updateMapScreen(StatusMapScreen *screen, TextWindow **windows) {
    s32 area;

    switch (screen->state) {
    case TASK_INIT:
    default:
        switch (screen->substate) {
        case 0:
        default:
            if (FILE_CACHE.isLoading(screen->textFile) == 0) {
                screen->substate++;
            }
            break;
        case 1:
            windows[0] = createTextWindow(screen->layer, 1, 0x14, 0x16);
            windows[0]->setLines(windows[0], 2);
            screen->fade.duration = 10;
            STSTATUS_areaFuncs.getVisitedAreas(screen->visited);
            area = STSTATUS_areaFuncs.getArea() + 1;
            screen->homeX = STSTATUS_data.spots[area].x + 0xC;
            screen->homeY = STSTATUS_data.spots[area].y + 0xC;
            screen->speedX = 1;
            screen->speedY = 1;
            while (screen->homeX + screen->scrollX != screen->cursorX) {
                STSTATUS_moveMapCursor(screen, 1, 0);
            }
            while (screen->homeY + screen->scrollY != screen->cursorY) {
                STSTATUS_moveMapCursor(screen, 0, 1);
            }
            screen->speedX = 0;
            screen->speedY = 0;
            screen->ready = 1;
            screen->nextState(screen);
            break;
        }
        break;
    case TASK_RUN:
        STSTATUS_runMapScreen(screen, windows);
        STSTATUS_showMapArea(screen, windows);
        STSTATUS_drawMapScreen(screen);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

Task *STSTATUS_createMapScreen(FieldMenuScreen *menu, s32 extra) {
    StatusMapScreen *screen = createTask(STSTATUS_updateMapScreen, sizeof(StatusMapScreen), 4);

    screen->layer = 0x1000;
    screen->depth = 5;
    screen->menu = menu;
    screen->lateGame = STSTATUS_areaFuncs.isLateGame();
    if (screen->lateGame == 0) {
        screen->archive = FILE_STATUS_BG << 16;
        screen->archive1 = (FILE_STATUS_BG << 16) + 1;
        screen->archive2 = (FILE_STATUS_BG << 16) + 2;
        screen->textFile = TEXT_FILE(TEXT_ASUKA_MAP);
        screen->file = FILE_STATUS_BG;
    } else {
        screen->archive = (FILE_STATUS_BG + 2) << 16;
        screen->archive1 = ((FILE_STATUS_BG + 2) << 16) + 1;
        screen->archive2 = ((FILE_STATUS_BG + 2) << 16) + 2;
        screen->textFile = TEXT_FILE(TEXT_AMATERASU_MAP);
        screen->file = FILE_STATUS_BG + 2;
    }
    FILE_CACHE.request(screen->textFile);
    screen->height = 0xF0;
    screen->top = 0x10;
    return (Task *)screen;
}

void STSTATUS_setScrollBarX(ScrollBar *bar, s32 x, s32 width) {
    bar->x = x;
    bar->width = width;
}

void STSTATUS_setScrollBarRange(ScrollBar *bar, s32 top, s32 bottom) {
    bar->top = top;
    bar->bottom = bottom;
    bar->hasRange = 1;
}

void STSTATUS_setScrollBarCount(ScrollBar *bar, s32 pageSize, s32 count) {
    bar->pageSize = pageSize;
    bar->count = count;
    bar->hasCount = 1;
}

void STSTATUS_setScrollBarPos(ScrollBar *bar, s32 pos) {
    bar->pos = pos;
}

void STSTATUS_updateScrollBar(ScrollBar *bar) {
    Layer *layer;
    u_long *ot;
    POLY_F4 *poly;
    s32 range;
#if VERSION_US
    s32 pages;
#endif

    switch (bar->state) {
    case TASK_INIT:
    default:
        if (bar->hasRange != 0 && bar->hasCount != 0) {
#if VERSION_US
            bar->nextState(bar);
            pages = bar->count / bar->pageSize + (bar->count % bar->pageSize != 0);
            range = (bar->bottom - bar->top) << 8;
            bar->size = range / pages;
            bar->posStep = range / bar->count;
#elif VERSION_EU
            /* the European version sizes the thumb for the visible items */
            range = (bar->bottom - bar->top) << 8;
            bar->size = range / bar->count * bar->pageSize;
            bar->posStep = range / bar->count;
            bar->nextState(bar);
#endif
        }
        break;
    case TASK_RUN:
        layer = GFX.funcs.getLayer(bar->layer);
        ot = (u_long *)layer->getOtEntry(layer, bar->depth);
        poly = GFX.funcs.getPrim();
        if (bar->pos < bar->count - 1) {
            bar->y = bar->top + ((bar->pos * bar->posStep) >> 8);
            if (bar->bottom - (bar->size >> 8) < bar->y) {
                bar->y = bar->bottom - (bar->size >> 8);
            }
        } else {
            bar->y = bar->bottom - (bar->size >> 8);
        }
        setlen(poly, 5);
        poly->code = 0x28;
        poly->r0 = poly->g0 = poly->b0 = 0xFF;
        poly->x0 = poly->x2 = bar->x;
        poly->x1 = poly->x3 = bar->x + bar->width;
        poly->y0 = poly->y1 = bar->y;
        poly->y2 = poly->y3 = bar->y + (bar->size >> 8);
        addPrim(ot, poly);
        GFX.funcs.setPrim(poly + 1);
        break;
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

ScrollBar *STSTATUS_createScrollBar(void) {
    ScrollBar *bar = createTask(STSTATUS_updateScrollBar, sizeof(ScrollBar), 0);

    bar->setX = STSTATUS_setScrollBarX;
    bar->setRange = STSTATUS_setScrollBarRange;
    bar->setCount = STSTATUS_setScrollBarCount;
    bar->setPos = STSTATUS_setScrollBarPos;
    bar->layer = 0x1000;
    bar->depth = 0;
    return bar;
}

void STSTATUS_runScreens(FieldMenuScreen *menu, FieldMenuScreenChildren *children) {
    Task *(*open)(FieldMenuScreen *, s32);

    switch (menu->substate) {
    case 0:
    default:
        open = STSTATUS_screens[FIELD_MENU_CHOICE.extra][FIELD_MENU_CHOICE.option];
        if (open != NULL) {
            children->screen = open(menu, FIELD_MENU_CHOICE.extra);
        } else {
            children->screen = STSTATUS_createItemScreen(menu, FIELD_MENU_CHOICE.extra);
        }
        menu->substate++;
        break;
    case 1:
        if (children->screen == NULL) {
            children->fieldMenu = createFieldMenu(menu->layer, FIELD_MENU_CHOICE.option);
            menu->setState(menu, 2);
        }
        break;
    }
}

void STSTATUS_drawBlink(FieldMenuScreen *menu) {
    SpriteDrawer sprite;

    initSpriteDrawer(&sprite);
    sprite.setLayerId(menu->layer, 7);
    sprite.setTexture(0x280, 0x100);
    if (menu->blinkSkip != 0) {
        menu->blinkPos++;
        menu->blinkPos = menu->blinkPos < 0x60 ? menu->blinkPos : 0;
        menu->blinkSkip = 0;
    } else {
        menu->blinkSkip = 1;
    }
    sprite.draw(FILE_CACHE.getEntry(FILE_STATUS_SPRITES << 16), 0x1D, menu->blinkPos, menu->blinkPos);
}

void STSTATUS_updateMenu(FieldMenuScreen *menu, FieldMenuScreenChildren *children) {
    TimLoader loader;

    switch (menu->state) {
    case TASK_INIT:
    default:
        switch (menu->substate) {
        case 0:
        default:
            STSTATUS_data.funcs.loadFiles();
            menu->substate++;
            break;
        case 1:
            if (STSTATUS_data.funcs.filesLoading() == 0 && FILE_CACHE.isLoading(menu->bgFile) == 0 &&
                FILE_CACHE.isLoading(menu->bgFile2) == 0) {
                initTimLoader(&loader);
                loader.setImagePos(0x380, 0x100);
                loader.loadArchive(FILE_CACHE.getEntry(menu->bgArchive1));
                loader.setImagePos(0x300, 0x100);
                loader.loadArchive(FILE_CACHE.getEntry(menu->bgArchive2));
                loader.setImagePos(0x280, 0);
                loader.setClutPos(0x140, 0x100);
                loader.loadArchive(FILE_CACHE.getEntry(menu->bgArchive));
                menu->nextState(menu);
            }
            break;
        }
        break;
    case TASK_RUN:
        STSTATUS_runScreens(menu, children);
        STSTATUS_drawBlink(menu);
        break;
    case TASK_DONE:
        if (children->fieldMenu == NULL) {
            menu->state = TASK_RUN;
        }
        STSTATUS_drawBlink(menu);
        break;
    case TASK_KILL:
        break;
    }
}

FieldMenuScreen *STSTATUS_createMenu(void) {
    FieldMenuScreen *menu = createTask(STSTATUS_updateMenu, sizeof(FieldMenuScreen), sizeof(FieldMenuScreenChildren));

    menu->layer = 0x1000;
    menu->lateGame = STSTATUS_areaFuncs.isLateGame();
    if (menu->lateGame == 0) {
        menu->bgArchive = (FILE_STATUS_BG + 1) << 16;
        menu->bgFile = FILE_STATUS_BG + 1;
        menu->bgArchive1 = ((FILE_STATUS_BG + 1) << 16) + 1;
        menu->bgArchive2 = ((FILE_STATUS_BG + 1) << 16) + 2;
        menu->bgFile2 = FILE_STATUS_BG;
    } else {
        menu->bgArchive = (FILE_STATUS_BG + 3) << 16;
        menu->bgFile = FILE_STATUS_BG + 3;
        menu->bgArchive1 = ((FILE_STATUS_BG + 3) << 16) + 1;
        menu->bgArchive2 = ((FILE_STATUS_BG + 3) << 16) + 2;
        menu->bgFile2 = FILE_STATUS_BG + 2;
    }
    FILE_CACHE.request(menu->bgFile);
    FILE_CACHE.request(menu->bgFile2);
    return menu;
}

void STSTATUS_loadFiles(void) {
    TimLoader loader;

    initTimLoader(&loader);
    loader.setImagePos(0x280, 0x100);
    loader.loadArchive(FILE_CACHE.getEntry((FILE_STATUS_SPRITES + 1) << 16));
    FILE_CACHE.request(TEXT_FILE(TEXT_STATUS));
    FILE_CACHE.request(TEXT_FILE(TEXT_ITEM_NAMES));
    FILE_CACHE.request(TEXT_FILE(TEXT_ITEM_INFO));
    FILE_CACHE.request(TEXT_FILE(TEXT_DIGIMON_NAMES));
    FILE_CACHE.request(TEXT_FILE(TEXT_DIGIMON_INFO));
    FILE_CACHE.request(TEXT_FILE(TEXT_SKILL_NAMES));
    FILE_CACHE.request(TEXT_FILE(TEXT_SKILL_INFO));
}

s32 STSTATUS_filesLoading(void) {
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_STATUS)) != 0) {
        return 1;
    }
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_ITEM_NAMES)) != 0) {
        return 1;
    }
    if (FILE_CACHE.isLoading(TEXT_FILE(TEXT_ITEM_INFO)) != 0) {
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

void STSTATUS_startFade(PanelAnim *fade, s32 fadeIn) {
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

s32 STSTATUS_updateFade(PanelAnim *fade) {
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

void STSTATUS_startLerp(StatusLerp *lerp, s32 from, s32 to, s32 frames) {
    if (from != to) {
        SOUND.playSound(SOUND_MENU_OPEN);
        lerp->duration = frames;
        lerp->fixed = from << 8;
        lerp->value = from;
        lerp->target = to;
        lerp->active = 1;
        lerp->step = ((to - from) << 8) / lerp->duration;
    }
}

s32 STSTATUS_updateLerp(StatusLerp *lerp) {
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

s32 *STSTATUS_getTowns(s32 list, s32 index) {
    return STSTATUS_townLists[list][index];
}

s32 STSTATUS_listItems(s32 list, u16 *out) {
    if (list < 5) {
        return ITEM_FUNCS->list(list, out);
    }
    switch (list) {
    case 5:
    default:
        return STSTATUS_listEquipItems(out);
    case 6:
        return STSTATUS_listItemsOfKind(4, out);
    case 7:
        return STSTATUS_listItemsOfKind(5, out);
    }
}

/* The items whose kind (data[2]) is one of STSTATUS_equipKinds's four */
s32 STSTATUS_listEquipItems(u16 *out) {
    s32 i;
    s32 j;
    s32 count;
    u8 *data;

    STSTATUS_data.itemCount = ITEM_FUNCS->list(2, (u16 *)STSTATUS_data.items);
    STSTATUS_data.item2Count = ITEM_FUNCS->list(3, (u16 *)STSTATUS_data.items2);
    count = 0;
    for (i = 0; i < STSTATUS_data.itemCount; i++) {
        data = GET_ITEM[0](STSTATUS_data.items[i])->data;
        for (j = 0; j < 4; j++) {
            if (data[2] == STSTATUS_equipKinds[j]) {
                out[count++] = STSTATUS_data.items[i];
            }
        }
    }
    for (i = 0; i < STSTATUS_data.item2Count; i++) {
        data = GET_ITEM[0](STSTATUS_data.items2[i])->data;
        for (j = 0; j < 4; j++) {
            if (data[2] == STSTATUS_equipKinds[j]) {
                out[count++] = STSTATUS_data.items2[i];
            }
        }
    }
    return count;
}

/* The items of one kind (data[2]) */
s32 STSTATUS_listItemsOfKind(s32 kind, u16 *out) {
    s32 i;
    s32 count;

    STSTATUS_data.itemCount = ITEM_FUNCS->list(2, (u16 *)STSTATUS_data.items);
    STSTATUS_data.item2Count = ITEM_FUNCS->list(3, (u16 *)STSTATUS_data.items2);
    count = 0;
    for (i = 0; i < STSTATUS_data.itemCount; i++) {
        if (GET_ITEM[0](STSTATUS_data.items[i])->data[2] == kind) {
            out[count++] = STSTATUS_data.items[i];
        }
    }
    for (i = 0; i < STSTATUS_data.item2Count; i++) {
        if (GET_ITEM[0](STSTATUS_data.items2[i])->data[2] == kind) {
            out[count++] = STSTATUS_data.items2[i];
        }
    }
    return count;
}

/* Whether a partner can put an item in an equipment slot (-1: none): data[4]
   has a bit per partner; data[2] 1 can't go in slot 3, nor 2 in slot 2 */
s32 STSTATUS_canEquip(s32 partner, s32 slot, s32 item) {
    u8 *data;

    if (item != -1) {
        data = GET_ITEM[0](item)->data;
        if (!((data[4] >> partner) & 1)) {
            return 0;
        }
        if (data[2] == 1) {
            if (slot == 3) {
                return 0;
            }
        } else if (data[2] == 2) {
            if (slot == 2) {
                return 0;
            }
        }
    }
    return 1;
}

/* Puts an item in a partner's equipment slot (0 or less: empties it), moving
   the counts between GAME.items and GAME.equippedItems. Kind 7 takes slots 2
   and 3; kind 8 replaces one in slots 4 and 5 with the same data[3] */
void STSTATUS_equip(s32 partner, s32 slot, s32 item) {
    PartnerStats *stats = GAME.funcs.getPartnerStats(partner);
    s16 *equip;
    s16 *pair;
    u8 *data;
    s32 group;
    s32 old;
    s32 i;
    s32 id = item; /* the match depends on this copy and on *(stats->equip + slot) */

    old = *(stats->equip + slot);
    if (old != 0) {
        GAME.equippedItems[old]--;
        GAME.items[old]++;
        data = GET_ITEM[0](old)->data;
        if (data[2] == 7) {
            stats->equip[2] = 0;
            stats->equip[3] = 0;
        } else {
            *(stats->equip + slot) = 0;
        }
    }
    if (id > 0) {
        data = GET_ITEM[0](id)->data;
        if (data[2] == 7) {
            pair = &stats->equip[2];
            if (stats->equip[2] == 0) {
                pair = NULL;
                if (stats->equip[3] != 0) {
                    pair = &stats->equip[3];
                }
            }
            if (pair != NULL) {
                GAME.equippedItems[*pair]--;
                GAME.items[*pair]++;
                *pair = 0;
            }
        } else if (data[2] == 8) {
            group = data[3];
            for (i = 0; i < 2; i++) {
                equip = &stats->equip[i + 4];
                if (*equip != 0) {
                    data = GET_ITEM[0](*equip)->data;
                    if (data[3] == group) {
                        GAME.equippedItems[*equip]--;
                        GAME.items[*equip]++;
                        *equip = 0;
                    }
                }
            }
        }
        GAME.equippedItems[id]++;
        GAME.items[id]--;
        data = GET_ITEM[0](id)->data;
        if (data[2] == 7) {
            stats->equip[2] = id;
            stats->equip[3] = id;
        } else {
            *(stats->equip + slot) = id;
        }
    }
}

s32 STSTATUS_isLateGame(void) {
    if (GAME.fieldMode >= 0x2D7) {
        return -1;
    }
    return GAME.fieldMode >= 0x270;
}

s32 STSTATUS_getArea(void) {
    return STSTATUS_mapAreas[(u8)GAME.fieldMode] & 0x7F;
}

void STSTATUS_getVisitedAreas(s32 *out) {
    s32 first;
    s32 last;
    s32 i;
    s32 area;
    s32 found;

    if (STSTATUS_isLateGame() == 0) {
        first = 0x200;
        last = 0x26F;
    } else {
        first = 0x270;
        last = 0x2D6;
    }
    for (i = first; i <= last; i++) {
        area = STSTATUS_mapAreas[i & 0xFF] & 0x7F;
        found = FLAGS_00.checkCondition((i & 0xFF) | 0x2000, 1);
        if (found == 1) {
            out[area] = found;
        }
    }
}

/* The map cursor's frames */
s32 STSTATUS_cursorFrames[] = {
    0, 1, 2, 1,
};

/* The field menu's screens, by FIELD_MENU_CHOICE */
Task *(*STSTATUS_screens[2][7])(FieldMenuScreen *menu, s32 extra) = {
    { STSTATUS_createItemScreen, STSTATUS_createSortScreen, STSTATUS_createMapScreen, STSTATUS_createTechScreen, STSTATUS_createStatusScreen, STSTATUS_createDemoScreen, NULL },
    { STSTATUS_createItemScreen, STSTATUS_createSortScreen, STSTATUS_createMapScreen, STSTATUS_createTechScreen, STSTATUS_createStatusScreen, STSTATUS_createCardScreen, STSTATUS_createDemoScreen },
};
/* The partners' portrait animations */
StatusAnim STSTATUS_partnerAnims[] = {
    { { 7, 8, 9, 10, 9, 8, -1 } },
    { { 14, 15, 16, 15, -1, -1, -1 } },
    { { 11, 12, 13, 12, -1, -1, -1 } },
    { { 3, 4, 5, 6, 5, 4, -1 } },
    { { 25, 26, 27, 28, 27, 26, -1 } },
    { { 0, 1, 2, 1, -1, -1, -1 } },
    { { 17, 18, 19, 20, 19, 18, -1 } },
    { { 21, 22, 23, 24, 23, 22, -1 } },
};
/* Where the screens' windows go, and their strings */
WindowPos STSTATUS_layout[] = {
    { 12, 55, 0, 19, 0 },
    { 1, 16, 0, 28, 0 },
    { 2, 16, 0, 37, 0 },
    { 4, 61, 0, 37, 0 },
    { 3, 16, 0, 46, 0 },
    { 4, 61, 0, 46, 0 },
    { 13, 44, 0, 28, 0 },
    { 14, 59, 0, 37, 0 },
    { 14, 94, 0, 37, 0 },
    { 14, 59, 0, 46, 0 },
    { 14, 94, 0, 46, 0 },
    { 14, 152, 0, 19, 0 },
    { 14, 20, 0, 198, 0 },
    { 3, 265, 0, 212, 0 },
    { 14, 300, 0, 212, 0 },
    { 22, 189, 0, 49, 0 },
};
/* The map's areas (STSTATUS_mapAreas), from 1 */
StatusMapSpot STSTATUS_spots[] = {
    { 0, 0, 0 },
    { 1, 60, 53 },
    { 2, 100, 59 },
    { 3, 126, 74 },
    { 4, 174, 79 },
    { 4, 208, 61 },
    { 5, 209, 36 },
    { 6, 288, 52 },
    { 7, 59, 98 },
    { 8, 116, 102 },
    { 9, 149, 104 },
    { 10, 204, 85 },
    { 10, 251, 152 },
    { 10, 253, 220 },
    { 11, 259, 99 },
    { 12, 303, 115 },
    { 13, 340, 105 },
    { 14, 57, 123 },
    { 15, 162, 138 },
    { 15, 158, 223 },
    { 16, 186, 119 },
    { 17, 251, 126 },
    { 17, 224, 127 },
    { 18, 279, 130 },
    { 19, 304, 141 },
    { 20, 330, 130 },
    { 21, 60, 169 },
    { 22, 122, 162 },
    { 22, 109, 205 },
    { 22, 89, 163 },
    { 23, 185, 143 },
    { 24, 332, 153 },
    { 24, 294, 190 },
    { 25, 199, 167 },
    { 26, 47, 199 },
    { 27, 72, 213 },
    { 28, 185, 221 },
    { 29, 265, 194 },
    { 30, 319, 234 },
    { 31, 35, 254 },
    { 32, 69, 248 },
    { 33, 191, 247 },
    { 34, 224, 227 },
    { 35, 297, 215 },
    { 35, 276, 233 },
    { 36, 296, 253 },
    { 37, 225, 253 },
};
/* Where the map's towns are, from 1 */
StatusMapPoint STSTATUS_towns[] = {
    { 0, 0 },
    { 171, 65 },
    { 154, 123 },
    { 230, 104 },
    { 182, 174 },
    { 286, 129 },
    { 285, 56 },
    { 316, 133 },
    { 262, 161 },
    { 249, 193 },
    { 253, 251 },
    { 172, 221 },
    { 160, 221 },
    { 21, 242 },
    { 25, 160 },
    { 67, 151 },
    { 30, 106 },
    { 32, 45 },
    { 114, 78 },
    { 55, 34 },
    { 128, 88 },
    { 165, 43 },
    { 198, 36 },
};
/* The towns the map shows at each stage of the game, up to 0 */
s32 STSTATUS_townList0[] = {
    1, 2, 3, 4,
    5, 7, 0,
};
s32 STSTATUS_townList1[] = {
    1, 2, 3, 4,
    5, 7, 8, 9,
    10, 11, 12, 0,
};
s32 STSTATUS_townList2[] = {
    1, 2, 3, 4,
    5, 7, 8, 9,
    10, 11, 12, 6,
    13, 14, 15, 16,
    17, 0,
};
s32 STSTATUS_townList3[] = {
    1, 2, 3, 4,
    5, 7, 8, 9,
    10, 11, 12, 6,
    13, 14, 15, 16,
    17, 18, 19, 20,
    21, 22, 0,
};
s32 STSTATUS_noTowns = 0;
/* The towns the map shows, by STSTATUS_isLateGame and GAME.progress */
s32 *STSTATUS_townLists[][5] = {
    { STSTATUS_townList0, STSTATUS_townList1, STSTATUS_townList2, STSTATUS_townList2, STSTATUS_townList3 },
    { &STSTATUS_noTowns, &STSTATUS_noTowns, &STSTATUS_noTowns, STSTATUS_townList2, STSTATUS_townList3 },
};
StatusData STSTATUS_data = {
    STSTATUS_partnerAnims,
    STSTATUS_layout,
    STSTATUS_spots,
    STSTATUS_towns,
    { 0 },
    0,
    { 0 },
    0,
    {
        STSTATUS_loadFiles, STSTATUS_filesLoading, STSTATUS_startFade, STSTATUS_updateFade, STSTATUS_startLerp,
        STSTATUS_updateLerp, STSTATUS_getTowns, STSTATUS_listItems, STSTATUS_canEquip, STSTATUS_equip,
    },
};
/* The item kinds (data[2]) of item list 5 */
u8 STSTATUS_equipKinds[] = {
    0x01, 0x02, 0x03, 0x07,
};
/* The map's area of each field map, by GAME.fieldMode's low byte (bit 7
   marks the late game's maps, 0x70 on; 0xFF: none) */
u8 STSTATUS_mapAreas[] = {
    0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
    0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
    0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
    0x13, 0x13, 0x13, 0x13, 0x13, 0x1D, 0x15, 0x20,
    0x11, 0x14, 0x14, 0x0B, 0x0B, 0x0D, 0x0D, 0x16,
    0x06, 0x17, 0x18, 0x0F, 0x1E, 0x1E, 0x0E, 0x0E,
    0x0E, 0x0E, 0x1F, 0x2A, 0x2A, 0x25, 0x25, 0x2B,
    0x0C, 0x24, 0x2C, 0x2D, 0x28, 0x12, 0x29, 0x29,
    0x29, 0x29, 0x23, 0x23, 0x23, 0x23, 0x23, 0x1B,
    0x22, 0x19, 0x1C, 0x1A, 0x10, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x22,
    0x27, 0x27, 0x26, 0x26, 0x26, 0x21, 0x21, 0x21,
    0x21, 0x09, 0x03, 0x0A, 0x04, 0x02, 0x01, 0x00,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x05, 0x05,
    0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93,
    0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93,
    0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93,
    0x93, 0x93, 0x93, 0x93, 0x9D, 0x95, 0xA0, 0x91,
    0x94, 0x94, 0x8B, 0x8B, 0x8D, 0x8D, 0x96, 0x86,
    0x97, 0x98, 0x8F, 0x9E, 0x8E, 0x8E, 0x8E, 0x8E,
    0x9F, 0xAA, 0xAA, 0xA5, 0xAB, 0x8C, 0xA4, 0xAC,
    0xAD, 0xA8, 0x92, 0xA9, 0xA9, 0xA9, 0xA9, 0xA3,
    0xA3, 0x9B, 0xA2, 0x99, 0x9C, 0x9A, 0x90, 0x87,
    0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87,
    0xA2, 0xA7, 0xA7, 0xA6, 0xA6, 0xA6, 0xA1, 0xA1,
    0xA1, 0x89, 0x83, 0x8A, 0x84, 0x82, 0x81, 0x80,
    0x88, 0x88, 0x88, 0x88, 0x88, 0x85, 0x85, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
};
/* Where the game is */
StatusAreaFuncs STSTATUS_areaFuncs = {
    STSTATUS_isLateGame,
    STSTATUS_getArea,
    STSTATUS_getVisitedAreas,
};
