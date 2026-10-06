/* The first object of STGTRAIN.PRO. STGTRAIN.PRO
   was at least three objects: each one's jump tables are aligned to 8 from
   the start of its own rodata, and the tables at 0x8008251C and 0x800825E8
   (USA) each start right where the one before ends, 4 bytes past a multiple
   of 8, so each one starts a new object. Where each object's code starts is
   only known to be between the function with the last jump table of the
   object before and the one with its first: here at the training result's
   functions (stgtrain_2.c) and the session's (stgtrain_3.c). The data is
   with the objects that read it. */

#include "stgtrain.h"

/* Sets the sprite bank and where the sprites start in it */
void STGTRAIN_setSpriteBank(TrainSprite *sprite, TrainSpriteBank *bank, s32 offset) {
    sprite->bank = bank;
    sprite->bankOffset = offset;
    sprite->unk84 = bank->unk2;
    sprite->unk86 = bank->unk4;
}

/* Starts an animation from its first frame */
void STGTRAIN_setSpriteAnim(TrainSprite *sprite, TrainAnim *anim) {
    if (anim != NULL) {
        sprite->anim = anim;
        sprite->frame = 0;
        sprite->frameTime = 0;
        sprite->frameCount = anim->frameCount;
        sprite->flags = 0;
    }
}

/* Sets the layer and depth the sprite is drawn at */
void STGTRAIN_setSpriteLayer(TrainSprite *sprite, s32 layerId, s32 depth) {
    sprite->layerId = layerId;
    sprite->depth = depth;
}

/* Sets where the sprite is drawn */
void STGTRAIN_setSpritePos(TrainSprite *sprite, s32 x, s32 y) {
    sprite->x = x;
    sprite->y = y;
}

/* Sets where the sprite's image is in VRAM */
void STGTRAIN_setSpriteImagePos(TrainSprite *sprite, s32 x, s32 y) {
    sprite->imageX = x;
    sprite->imageY = y;
}

/* Sets where the sprite's CLUT is in VRAM */
void STGTRAIN_setSpriteClutPos(TrainSprite *sprite, s32 x, s32 y) {
    sprite->clutX = x;
    sprite->clutY = y;
}

/* Scales the sprite (0x1000 is its size), drawing it as quads */
void STGTRAIN_setSpriteScale(TrainSprite *sprite, s32 x, s32 y, s32 z) {
    sprite->scale.vx = x;
    sprite->scale.vy = y;
    sprite->scale.vz = z;
    sprite->transformed = 1;
}

/* Sets the point the sprite scales and turns about */
void STGTRAIN_setSpritePivot(TrainSprite *sprite, s32 x, s32 y) {
    sprite->pivotX = x;
    sprite->pivotY = y;
}

/* Turns the sprite, drawing it as quads */
void STGTRAIN_setSpriteRotation(TrainSprite *sprite, s16 x, s16 y, s16 z) {
    sprite->rotation.vx = x;
    sprite->rotation.vy = y;
    sprite->rotation.vz = z;
    sprite->transformed = 1;
}

/* Whether the animation has ended (the flags but for the pause) */
s32 STGTRAIN_getSpriteFlags(TrainSprite *sprite) {
    return sprite->flags & 0x7FFFFFFF;
}

/* Pauses the animation (paused) or plays it on */
void STGTRAIN_setSpritePaused(TrainSprite *sprite, s32 paused) {
    if (paused) {
        sprite->flags |= 0x80000000;
    } else {
        sprite->flags &= 0x7FFFFFFF;
    }
}

/*
 * The animated sprite's update: state 1 advances the animation, unless it
 * is paused, and draws the frame's sprite, its parts from the last to the
 * first, as sprites or, scaled and rotated about the pivot, as quads.
 * The match depends on frame holding the animation before its frames.
 */
void STGTRAIN_updateSprite(TrainSprite *sprite) {
    SVECTOR out;
    SVECTOR in[4];
    TrainAnimFrame *frame;
    u8 *p;
    TrainSpritePart *part;
    s32 n;
    s32 count;
    s32 i;
    s32 j;
    s32 k;
    s32 state;
    u16 info;
    u16 w;
    u16 h;
    u16 tpage;
    u16 prevTpage;
    u16 clut;
    s32 transform;
    u8 u;
    u8 v;
    s32 x;
    s32 y;
    union {
        void *ptr;
        SPRT *sprt;
        POLY_FT4 *ft4;
        DR_TPAGE *tpage;
    } prim;

    state = sprite->state;
    switch (state) {
    case 0:
    default:
        sprite->nextState(sprite);
        sprite->frameTime = GFX.funcs.getTime();
        break;
    case 1:
        if (sprite->bank == NULL) {
            break;
        }
        if (sprite->anim == NULL) {
            break;
        }
        frame = (TrainAnimFrame *)sprite->anim;
        frame = ((TrainAnim *)frame)->frames;
        frame += sprite->frame;
        if (sprite->flags >= 0 && GFX.funcs.getTime() - sprite->frameTime > frame->duration) {
            sprite->frameTime = GFX.funcs.getTime();
            if (++sprite->frame >= sprite->frameCount - 1) {
                sprite->frame = sprite->frameCount - 1;
                sprite->flags = 1;
            }
            frame = (TrainAnimFrame *)sprite->anim;
            frame = ((TrainAnim *)frame)->frames;
            frame += sprite->frame;
        }
        p = (u8 *)sprite->bank;
        p += sprite->bankOffset;
        count = frame->sprite;
        for (i = 0; i < count; i++) {
            n = *(s32 *)p;
            p += sizeof(s32);
            for (j = 0; j < n; j++) {
                p += sizeof(TrainSpritePart);
            }
        }
        tpage = 0;
        prevTpage = 0;
        transform = 0;
        if (sprite->transformed) {
            if (sprite->scale.vx == 0 && sprite->scale.vy == 0) {
                break;
            }
            if (sprite->scale.vx == 0x1000 && sprite->scale.vy == 0x1000) {
                sprite->transformed = 0;
            } else {
                transform = 1;
                RotMatrixYXZ_gte(&sprite->rotation, &sprite->matrix);
                ScaleMatrix(&sprite->matrix, &sprite->scale);
            }
        }
        sprite->layer = GFX.funcs.getLayer(sprite->layerId);
        sprite->ot = (u_long *)sprite->layer->getOtEntry(sprite->layer, sprite->depth);
        prim.ptr = GFX.funcs.getPrim();
        n = *(s32 *)p;
        p += sizeof(s32);
        for (i = 0; i < n; i++) {
            p += sizeof(TrainSpritePart);
        }
        part = (TrainSpritePart *)p;
        for (i = 0; i < n; i++) {
            part--;
            info = part->tpage;
            clut = getClut(sprite->clutX + (info & 0x1F) * 16, sprite->clutY + ((part->clut & 0x7FC0) >> 6));
            tpage = getTPage(info >> 7, info >> 5, sprite->imageX + (info & 0x1F) * 64, sprite->imageY);
            u = part->u;
            x = part->x;
            y = part->y;
            v = part->v;
            w = part->w;
            h = part->h;
            if (!transform) {
                if (i == 0) {
                    prevTpage = tpage;
                }
                if (prevTpage != tpage) {
                    SetDrawTPage(prim.tpage, 0, 1, prevTpage);
                    addPrim(sprite->ot, prim.ptr);
                    prim.tpage++;
                    prevTpage = tpage;
                }
                setSprt(prim.sprt);
                if ((s16)part->clut & 0x8000) {
                    setSemiTrans(prim.sprt, 1);
                }
                setRGB0(prim.sprt, 0x80, 0x80, 0x80);
                prim.sprt->x0 = x + (frame->x + sprite->x);
                prim.sprt->y0 = y + (frame->y + sprite->y);
                prim.sprt->u0 = u;
                prim.sprt->v0 = v;
                prim.sprt->w = w;
                prim.sprt->h = h;
                prim.sprt->clut = clut;
                addPrim(sprite->ot, prim.ptr);
                prim.sprt++;
            } else {
                setPolyFT4(prim.ft4);
                if ((s16)part->clut & 0x8000) {
                    setSemiTrans(prim.ft4, 1);
                }
                setRGB0(prim.ft4, 0x80, 0x80, 0x80);
                in[0].vx = in[2].vx = x + (frame->x + sprite->x) - sprite->pivotX;
                in[1].vx = in[3].vx = in[0].vx + w;
                in[0].vy = in[1].vy = y + (frame->y + sprite->y) - sprite->pivotY;
                in[2].vy = in[3].vy = in[0].vy + h;
                in[0].vz = in[1].vz = in[2].vz = in[3].vz = 0;
                for (k = 0; k < 4; k++) {
                    ApplyMatrixSV(&sprite->matrix, &in[k], &out);
                    (&prim.ft4->x0)[k * 4] = out.vx + sprite->pivotX;
                    (&prim.ft4->y0)[k * 4] = out.vy + sprite->pivotY;
                }
                prim.ft4->u0 = prim.ft4->u2 = u;
                prim.ft4->u1 = prim.ft4->u3 = w + u - 1;
                prim.ft4->v0 = prim.ft4->v1 = v;
                prim.ft4->v2 = prim.ft4->v3 = h + v - 1;
                prim.ft4->tpage = tpage;
                prim.ft4->clut = clut;
                addPrim(sprite->ot, prim.ptr);
                prim.ft4++;
            }
        }
        if (!transform) {
            SetDrawTPage(prim.tpage, 0, 1, tpage);
            addPrim(sprite->ot, prim.ptr);
            prim.tpage++;
        }
        GFX.funcs.setPrim(prim.ptr);
        break;
    case 2:
    case 3:
        break;
    }
}

/* Creates an animated sprite */
TrainSprite *STGTRAIN_createSprite(void) {
    TrainSprite *sprite = createTask(STGTRAIN_updateSprite, sizeof(TrainSprite), 0);
    sprite->setBank = STGTRAIN_setSpriteBank;
    sprite->setAnim = STGTRAIN_setSpriteAnim;
    sprite->setPos = STGTRAIN_setSpritePos;
    sprite->setImagePos = STGTRAIN_setSpriteImagePos;
    sprite->setLayer = STGTRAIN_setSpriteLayer;
    sprite->setClutPos = STGTRAIN_setSpriteClutPos;
    sprite->setScale = STGTRAIN_setSpriteScale;
    sprite->setPivot = STGTRAIN_setSpritePivot;
    sprite->setRotation = STGTRAIN_setSpriteRotation;
    sprite->getFlags = STGTRAIN_getSpriteFlags;
    sprite->setPaused = STGTRAIN_setSpritePaused;
    return sprite;
}

/* The mode's root task: sets up the display and starts the screen */
void STGTRAIN_updateRoot(Task *task, Task **children) {
    RECT rect;
    Layer *layer;

    switch (task->state) {
    case TASK_INIT:
    default:
        GFX.funcs.reset();
        GFX.funcs.allocPrimBuffers(0x14000);
        GFX.funcs.setDisplayMode(0x140, 0xF0, 0, 0);
        rect.x = 0;
        rect.y = 0;
        rect.w = 0x140;
        rect.h = 0xF0;
        layer = GFX.funcs.createLayer(&rect, 3, 0x1000);
        layer->setBgColor(layer, 0, 0, 0);
        rect.x = 0x7B;
        rect.y = 0x53;
        rect.w = 0xA8;
        rect.h = 0x58;
        GFX.funcs.createLayer(&rect, 3, 0x1001);
        GFX.funcs.moveLayer(0x1001, 0x1000, 1);
        rect.x = 0;
        rect.y = 0;
        rect.w = 0x140;
        rect.h = 0xF0;
        GFX.funcs.createLayer(&rect, 3, 0x1002);
        GFX.funcs.moveLayer(0x1002, 0x1001, 1);
        children[0] = (Task *)STGTRAIN_createScreen();
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

/* The mode's entry point (MODE_ENTRY_POINTS): starts the root task */
Task *STGTRAIN_start(void) {
    return createTask(STGTRAIN_updateRoot, sizeof(Task), 4);
}

/* Creates the screen's text windows */
void STGTRAIN_createScreenWindows(TrainScreen *screen, TrainScreenWindows *win) {
    s32 i;

    win->name = createTextWindow(screen->layerId, 1, 0x33, 0x13);
    win->level[0] = createTextWindow(screen->layerId, 3, 0x33, 0x22);
    win->level[1] = createTextWindow(screen->layerId, 3, 0x50, 0x22);
    win->hp[0] = createTextWindow(screen->layerId, 3, 0x33, 0x2C);
    win->hp[1] = createTextWindow(screen->layerId, 3, 0x5D, 0x2C);
    win->hp[2] = createTextWindow(screen->layerId, 3, 0x80, 0x2C);
    win->mp[0] = createTextWindow(screen->layerId, 3, 0x33, 0x35);
    win->mp[1] = createTextWindow(screen->layerId, 3, 0x5D, 0x35);
    win->mp[2] = createTextWindow(screen->layerId, 3, 0x80, 0x35);
    win->slashes[0] = createTextWindow(screen->layerId, 3, 0x5F, 0x2C);
    win->slashes[1] = createTextWindow(screen->layerId, 3, 0x5F, 0x35);
    for (i = 0; i < 6; i++) {
        win->stats[i] = createTextWindow(screen->layerId, 1, 0x33, i * 0xE + 0x4F);
    }
    for (i = 0; i < 7; i++) {
        win->resistances[i] = createTextWindow(screen->layerId, 1, 0x5D, i * 0xE + 0x4F);
    }
    win->tp[0] = createTextWindow(screen->layerId, 1, 0x10, 0xBB);
    win->tp[1] = createTextWindow(screen->layerId, 1, 0x2C, 0xBB);
    win->unk68 = createTextWindow(screen->layerId, 1, 0xA1, 0x17);
    win->unk6C = createTextWindow(screen->layerId, 1, 0xAE, 0x49);
}

/* Shows or hides the selected partner's name, level, HP and MP */
void STGTRAIN_showVitals(TrainScreen *screen, TrainScreenWindows *win, s32 show) {
    PartnerTotals totals;
    PartnerStats *vitals;
    s32 partner;
    s32 i;

    if (show) {
        partner = GAME.funcs.getPartyMember(screen->partner);
        vitals = GAME.funcs.getPartnerStats(partner);
        GAME.funcs.computeStats(partner, &totals);
        win->name->setString(win->name, vitals, -1);
        win->level[0]->setString(win->level[0], FILE_CACHE.load(STGTRAIN_TEXT), 1);
        win->level[1]->setNumber(win->level[1], 0, totals.fields.level);
        win->level[1]->setRightAlign(win->level[1], 1);
        win->hp[0]->setString(win->hp[0], FILE_CACHE.load(STGTRAIN_TEXT), 2);
        win->hp[1]->setNumber(win->hp[1], 0, totals.fields.hp);
        win->hp[2]->setNumber(win->hp[2], 0, totals.fields.maxHp);
        for (i = 1; i < 3; i++) {
            win->hp[i]->setPalette(win->hp[i], 0);
            win->hp[i]->setRightAlign(win->hp[i], 1);
        }
        win->mp[0]->setString(win->mp[0], FILE_CACHE.load(STGTRAIN_TEXT), 3);
        win->mp[1]->setNumber(win->mp[1], 0, totals.fields.mp);
        win->mp[2]->setNumber(win->mp[2], 0, totals.fields.maxMp);
        for (i = 1; i < 3; i++) {
            win->mp[i]->setPalette(win->mp[i], 0);
            win->mp[i]->setRightAlign(win->mp[i], 1);
        }
        for (i = 0; i < 2; i++) {
            win->slashes[i]->setString(win->slashes[i], FILE_CACHE.load(STGTRAIN_TEXT), 0x43);
        }
    } else {
        win->name->setVisible(win->name, 0);
        for (i = 0; i < 2; i++) {
            win->level[i]->setVisible(win->level[i], 0);
            win->slashes[i]->setVisible(win->slashes[i], 0);
        }
        for (i = 0; i < 3; i++) {
            win->hp[i]->setVisible(win->hp[i], 0);
        }
        for (i = 0; i < 3; i++) {
            win->mp[i]->setVisible(win->mp[i], 0);
        }
    }
}

/* Shows or hides the selected partner's stats and resistances */
void STGTRAIN_showBattleStats(TrainScreen *screen, TrainScreenWindows *win, s32 show) {
    PartnerTotals totals;
    s32 i;

    if (show) {
        GAME.funcs.computeStats(GAME.funcs.getPartyMember(screen->partner), &totals);
        for (i = 0; i < 6; i++) {
            win->stats[i]->setNumber(win->stats[i], 0, totals.fields.battle[i]);
            win->stats[i]->setRightAlign(win->stats[i], 1);
            win->stats[i]->setPalette(win->stats[i], 0);
        }
        if (totals.fields.lowered[0] != 0) {
            win->stats[0]->setPalette(win->stats[0], 6);
        }
        if (totals.fields.lowered[1] != 0) {
            win->stats[1]->setPalette(win->stats[1], 6);
        }
        if (totals.fields.lowered[2] != 0) {
            win->stats[4]->setPalette(win->stats[4], 6);
        }
        for (i = 0; i < 7; i++) {
            win->resistances[i]->setNumber(win->resistances[i], 0, totals.fields.resist[i]);
            win->resistances[i]->setRightAlign(win->resistances[i], 1);
            win->resistances[i]->setPalette(win->resistances[i], 0);
        }
    } else {
        for (i = 0; i < 6; i++) {
            win->stats[i]->setVisible(win->stats[i], 0);
        }
        for (i = 0; i < 7; i++) {
            win->resistances[i]->setVisible(win->resistances[i], 0);
        }
    }
}

/* Shows or hides the selected partner's TP */
void STGTRAIN_showTp(TrainScreen *screen, TrainScreenWindows *win, s32 show) {
    PartnerTotals totals;
    s32 i;

    if (show) {
        GAME.funcs.computeStats(GAME.funcs.getPartyMember(screen->partner), &totals);
        win->tp[0]->setString(win->tp[0], FILE_CACHE.load(STGTRAIN_TEXT), 4);
        win->tp[1]->setNumber(win->tp[1], 0, totals.fields.tp);
        win->tp[1]->setRightAlign(win->tp[1], 1);
    } else {
        for (i = 0; i < 2; i++) {
            win->tp[i]->setVisible(win->tp[i], 0);
        }
    }
}

/*
 * Shows the selected partner's stats, in colour where they differ from
 * before (NULL: just shows them). The MP label is given win->mp[3] (that
 * is, slashes[0]) as its window, as in the original. The match depends on
 * the stats and resistances being read as *(totals.fields.battle + i).
 */
void STGTRAIN_showStatChanges(TrainScreen *screen, PartnerTotals *before) {
    TrainScreenWindows *win = screen->children;
    PartnerTotals totals;
    s32 partner;
    s32 i;

    if (before == NULL) {
        STGTRAIN_showVitals(screen, win, 1);
        STGTRAIN_showBattleStats(screen, win, 1);
        return;
    }
    partner = GAME.funcs.getPartyMember(screen->partner);
    GAME.funcs.getPartnerStats(partner);
    GAME.funcs.computeStats(partner, &totals);
    win->hp[0]->setString(win->hp[0], FILE_CACHE.load(STGTRAIN_TEXT), 2);
    win->hp[1]->setNumber(win->hp[1], 0, totals.fields.hp);
    win->hp[2]->setNumber(win->hp[2], 0, totals.fields.maxHp);
    for (i = 1; i < 3; i++) {
        win->hp[i]->setRightAlign(win->hp[i], 1);
    }
    if (before->fields.maxHp < totals.fields.maxHp) {
        win->hp[2]->setPalette(win->hp[2], 1);
    } else if (totals.fields.maxHp < before->fields.maxHp) {
        win->hp[2]->setPalette(win->hp[2], 5);
    } else {
        win->hp[2]->setPalette(win->hp[2], 0);
    }
    win->mp[0]->setString(win->mp[i], FILE_CACHE.load(STGTRAIN_TEXT), 3);
    win->mp[1]->setNumber(win->mp[1], 0, totals.fields.mp);
    win->mp[2]->setNumber(win->mp[2], 0, totals.fields.maxMp);
    for (i = 1; i < 3; i++) {
        win->mp[i]->setRightAlign(win->mp[i], 1);
    }
    if (before->fields.maxMp < totals.fields.maxMp) {
        win->mp[2]->setPalette(win->mp[2], 1);
    } else if (totals.fields.maxMp < before->fields.maxMp) {
        win->mp[2]->setPalette(win->mp[2], 5);
    } else {
        win->mp[2]->setPalette(win->mp[2], 0);
    }
    for (i = 0; i < 2; i++) {
        win->slashes[i]->setString(win->slashes[i], FILE_CACHE.load(STGTRAIN_TEXT), 0x43);
    }
    if (totals.fields.lowered[0] != 0) {
        win->stats[0]->setPalette(win->stats[0], 6);
    }
    if (totals.fields.lowered[1] != 0) {
        win->stats[1]->setPalette(win->stats[1], 6);
    }
    if (totals.fields.lowered[2] != 0) {
        win->stats[4]->setPalette(win->stats[4], 6);
    }
    for (i = 0; i < 6; i++) {
        win->stats[i]->setNumber(win->stats[i], 0, *(totals.fields.battle + i));
        win->stats[i]->setRightAlign(win->stats[i], 1);
        if (before->fields.battle[i] < *(totals.fields.battle + i)) {
            win->stats[i]->setPalette(win->stats[i], 1);
        } else if (*(totals.fields.battle + i) < before->fields.battle[i]) {
            win->stats[i]->setPalette(win->stats[i], 5);
        }
    }
    for (i = 0; i < 7; i++) {
        win->resistances[i]->setNumber(win->resistances[i], 0, *(totals.fields.resist + i));
        win->resistances[i]->setRightAlign(win->resistances[i], 1);
        if (before->fields.resist[i] < *(totals.fields.resist + i)) {
            win->resistances[i]->setPalette(win->resistances[i], 1);
        } else if (*(totals.fields.resist + i) < before->fields.resist[i]) {
            win->resistances[i]->setPalette(win->resistances[i], 5);
        }
    }
}

/* Draws the screen: the panels, the party's sprites and the sign */
void STGTRAIN_drawScreen(TrainScreen *screen) {
    SpriteDrawer sprite;
    s32 i;
    s32 partner;

    for (i = 0; i < screen->partyCount; i++) {
        if (GFX.funcs.getTime() - screen->anims[i].time >= 0xD) {
            screen->anims[i].time = GFX.funcs.getTime();
            screen->anims[i].frame++;
            partner = GAME.funcs.getPartyMember(i);
            if (screen->anims[i].frame >= 7 || STGTRAIN_waitAnims[partner][screen->anims[i].frame] == -1) {
                screen->anims[i].frame = 0;
            }
        }
    }
    partner = GAME.funcs.getPartyMember(screen->partner);
    if (GFX.funcs.getTime() - screen->time >= 0xD) {
        screen->time = GFX.funcs.getTime();
        screen->frame++;
        if (screen->frame >= 7 || STGTRAIN_waitAnims[partner][screen->frame] == -1) {
            screen->frame = 0;
        }
    }
    initSpriteDrawer(&sprite);
    sprite.setLayerId(screen->layerId, screen->depth);
    if (screen->panels[0].level != 0) {
        if (screen->panels[0].level != 0x1000) {
            sprite.setScale(screen->panels[0].level, 0x1000, 0x1000);
            sprite.setPivot(0, 0x2B);
        } else {
            sprite.setTexture(0x240, 0x100);
            sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), STGTRAIN_waitAnims[partner][screen->frame], 0x10, 0x16);
        }
        sprite.setTexture(0x140, 0);
        sprite.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 0xE, 0, 0xF);
        sprite.setTexture(0x240, 0x100);
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x1F, 0, 0xF);
    }
    if (screen->panels[1].level != 0) {
        if (screen->panels[1].level != 0x1000) {
            sprite.setScale(screen->panels[1].level, 0x1000, 0x1000);
            sprite.setPivot(0, 0x7F);
        }
        sprite.setTexture(0x140, 0);
        sprite.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 0xF, 0, 0x4B);
        sprite.setTexture(0x240, 0x100);
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x20, 0, 0x4B);
    }
    if (screen->panels[2].level != 0) {
        if (screen->panels[2].level != 0x1000) {
            sprite.setScale(screen->panels[2].level, 0x1000, 0x1000);
            sprite.setPivot(0, 0xC1);
        }
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x21, 0, 0xB6);
    }
    if (screen->panels[5].level != 0) {
        for (i = 0; i < screen->partyCount; i++) {
            if (screen->panels[5].level != 0x1000) {
                sprite.setScale(screen->panels[5].level, 0x1000, 0x1000);
                sprite.setPivot(i * 0x30 + 0xB4, 0x8A);
            }
            partner = GAME.funcs.getPartyMember(i);
            sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), STGTRAIN_waitAnims[partner][screen->anims[i].frame], i * 0x30 + 0xA4, 0x81);
        }
    }
    if (screen->cursorShown != 0) {
        if (GFX.funcs.getTime() - screen->cursorTime >= 0xB) {
            screen->cursorTime = GFX.funcs.getTime();
            screen->cursorClut++;
            if (screen->cursorClut >= 4) {
                screen->cursorClut = 0;
            }
        }
        sprite.setLayerId(screen->layerId, screen->depth - 2);
        sprite.setTexture(0x140, 0);
        sprite.setClutRow(screen->cursorClut);
        sprite.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 0xD, screen->partner * 0x30 + 0xA4, 0x65);
        sprite.setClutRow(0);
    }
    if (screen->panels[6].level != 0) {
        if (screen->panels[6].level != 0x1000) {
            sprite.setScale(screen->panels[6].level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0x8A);
        } else {
            sprite.setScale(0x1000, 0x1000, 0x1000);
        }
        sprite.setLayerId(screen->layerId, screen->depth - 1);
        sprite.setTexture(0x140, 0);
        sprite.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 0x10, 0x8F, 0x5F);
        sprite.setLayerId(screen->layerId, screen->depth);
        sprite.draw(FILE_CACHE.getEntry(FILE_MENU_SPRITES << 16), 0x11, 0x8F, 0x5F);
        sprite.setTexture(0x240, 0x100);
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x24, 0x8F, 0x5F);
    }
    if (screen->panels[3].level != 0) {
        if (screen->panels[3].level != 0x1000) {
            sprite.setScale(screen->panels[3].level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0x1D);
        } else {
            sprite.setScale(0x1000, 0x1000, 0x1000);
        }
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x27, 0x8F, 0xF);
    }
    if (screen->panels[4].level != 0) {
        if (screen->panels[4].level != 0x1000) {
            sprite.setScale(screen->panels[4].level, 0x1000, 0x1000);
            sprite.setPivot(0x140, 0x4E);
        }
        sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), 0x22, 0x92, 0x43);
    }
    initSpriteDrawer(&sprite);
    sprite.setLayerId(screen->layerId, 7);
    sprite.setTexture(0x240, 0x100);
    if (screen->signTick != 0) {
        screen->signPos++;
        screen->signPos = screen->signPos < 0x60 ? screen->signPos : 0;
        screen->signTick = 0;
    } else {
        screen->signTick = 1;
    }
    sprite.draw(FILE_CACHE.getEntry(STGTRAIN_SPRITES), screen->sign, screen->signPos, screen->signPos);
}

/* The training screen: opens the panels, picks the partner, runs the menu
   and the trainings, and closes everything when leaving */
void STGTRAIN_runScreen(TrainScreen *screen, TrainScreenWindows *win) {
    s32 i;
    s32 partner;

    switch (screen->substate) {
    case 0:
    default:
        STGTRAIN_state.startFade(&screen->panels[0], 1);
        STGTRAIN_state.startFade(&screen->panels[3], 1);
        screen->substate++;
        break;
    case 1:
        STGTRAIN_state.updateFade(&screen->panels[3]);
        if (STGTRAIN_state.updateFade(&screen->panels[0])) {
            STGTRAIN_showVitals(screen, win, 1);
            win->unk68->setString(win->unk68, FILE_CACHE.load(STGTRAIN_TEXT), 5);
            STGTRAIN_state.startFade(&screen->panels[1], 1);
            STGTRAIN_state.startFade(&screen->panels[4], 1);
            screen->substate++;
        }
        break;
    case 2:
        STGTRAIN_state.updateFade(&screen->panels[4]);
        if (STGTRAIN_state.updateFade(&screen->panels[1])) {
            STGTRAIN_showBattleStats(screen, win, 1);
            win->unk6C->setString(win->unk6C, FILE_CACHE.load(STGTRAIN_TEXT), 6);
            STGTRAIN_state.startFade(&screen->panels[2], 1);
            STGTRAIN_state.startFade(&screen->panels[6], 1);
            screen->substate++;
        }
        break;
    case 3:
        STGTRAIN_state.updateFade(&screen->panels[6]);
        if (STGTRAIN_state.updateFade(&screen->panels[2])) {
            STGTRAIN_showTp(screen, win, 1);
            STGTRAIN_state.startFade(&screen->panels[5], 1);
            screen->substate++;
        }
        break;
    case 4:
        if (STGTRAIN_state.updateFade(&screen->panels[5])) {
            screen->cursorShown = 1;
            screen->substate++;
        }
        break;
    case 5:
        partner = screen->partner;
        if (PAD_PRESSED(PAD_LEFT) || PAD_REPEATED(PAD_LEFT)) {
            screen->partner--;
            if (screen->partner < 0) {
                screen->partner = 0;
            }
        } else if (PAD_PRESSED(PAD_RIGHT) || PAD_REPEATED(PAD_RIGHT)) {
            screen->partner++;
            if (screen->partner > screen->partyCount - 1) {
                screen->partner = screen->partyCount - 1;
            }
        }
        if (partner != screen->partner) {
            SOUND.playSound(SOUND_MENU_MOVE);
            STGTRAIN_showVitals(screen, win, 1);
            STGTRAIN_showBattleStats(screen, win, 1);
            STGTRAIN_showTp(screen, win, 1);
            screen->frame = 0;
        } else if (PAD_PRESSED(PAD_CROSS)) {
            SOUND.playSound(SOUND_MENU_CONFIRM);
            screen->substate = 0x14;
            if (win->menu != NULL) {
                win->menu->state = TASK_KILL;
            }
        } else if (PAD_PRESSED(PAD_TRIANGLE)) {
            SOUND.playSound(SOUND_MENU_CANCEL);
            screen->substate = 0x32;
        }
        break;
    case 0xA:
        if (win->menu == NULL) {
            win->menu = STGTRAIN_createMenu(screen);
            screen->substate++;
        }
        break;
    case 0xB:
        if (win->menu == NULL) {
            screen->substate = 0x1E;
        } else if (win->menu->state == TASK_DONE) {
            screen->unk78 = 0;
            win->menu->state = TASK_KILL;
            screen->substate = 0x19;
        }
        break;
    case 0x14:
        screen->panels[5].level = 0;
        STGTRAIN_state.startFade(&screen->panels[6], 0);
        screen->cursorShown = 0;
        STGTRAIN_state.startFade(&screen->panels[4], 0);
        win->unk6C->setVisible(win->unk6C, 0);
        STGTRAIN_state.startFade(&screen->panels[3], 0);
        win->unk68->setVisible(win->unk68, 0);
        screen->substate++;
        break;
    case 0x15:
        STGTRAIN_state.updateFade(&screen->panels[6]);
        STGTRAIN_state.updateFade(&screen->panels[4]);
        if (STGTRAIN_state.updateFade(&screen->panels[3])) {
            screen->substate = 0xA;
        }
        break;
    case 0x19:
        STGTRAIN_state.startFade(&screen->panels[3], 1);
        screen->substate++;
        break;
    case 0x1A:
        if (STGTRAIN_state.updateFade(&screen->panels[3])) {
            win->unk68->setString(win->unk68, FILE_CACHE.load(STGTRAIN_TEXT), 5);
            STGTRAIN_state.startFade(&screen->panels[4], 1);
            screen->substate++;
        }
        break;
    case 0x1B:
        if (STGTRAIN_state.updateFade(&screen->panels[4])) {
            win->unk6C->setString(win->unk6C, FILE_CACHE.load(STGTRAIN_TEXT), 6);
            STGTRAIN_state.startFade(&screen->panels[6], 1);
            screen->substate++;
        }
        break;
    case 0x1C:
        if (STGTRAIN_state.updateFade(&screen->panels[6])) {
            STGTRAIN_state.startFade(&screen->panels[5], 1);
            screen->substate = 4;
        }
        break;
    case 0x1E:
        if (win->session == NULL) {
            win->session = STGTRAIN_createSession(screen);
            screen->substate++;
            STGTRAIN_state.requestFile(screen->unk78);
        }
        break;
    case 0x1F:
        if (win->session->substate == 0x23) {
            if (win->result != NULL) {
                win->result->state = TASK_KILL;
            } else {
                screen->substate = 0x23;
                STGTRAIN_showTp(screen, win, 1);
            }
        } else if (win->session->state == TASK_DONE) {
            win->session->state = TASK_KILL;
            screen->substate = 0xA;
        }
        break;
    case 0x23:
        if (STGTRAIN_state.getFile() != NULL && win->result == NULL) {
            win->result = STGTRAIN_createResult(screen, GAME.funcs.getPartyMember(screen->partner), screen->unk78);
            screen->substate++;
        }
        break;
    case 0x24:
        if (win->result == NULL) {
            win->session->finish(win->session);
            screen->substate++;
        }
        break;
    case 0x25:
        if (win->session == NULL) {
            STGTRAIN_showBattleStats(screen, win, 1);
            screen->substate = 0x19;
        }
        break;
    case 0x32:
        win->fade = STGTRAIN_createScreenFade();
        win->fade->start(win->fade, 0, 30);
        screen->panels[5].level = 0;
        for (i = 0; i < 3; i++) {
            STGTRAIN_state.startFade(&screen->panels[i], 0);
        }
        STGTRAIN_showVitals(screen, win, 0);
        STGTRAIN_showBattleStats(screen, win, 0);
        STGTRAIN_showTp(screen, win, 0);
        STGTRAIN_state.startFade(&screen->panels[6], 0);
        screen->cursorShown = 0;
        STGTRAIN_state.startFade(&screen->panels[4], 0);
        win->unk6C->setVisible(win->unk6C, 0);
        STGTRAIN_state.startFade(&screen->panels[3], 0);
        win->unk68->setVisible(win->unk68, 0);
        screen->substate++;
        break;
    case 0x33:
        for (i = 0; i < 3; i++) {
            STGTRAIN_state.updateFade(&screen->panels[i]);
        }
        STGTRAIN_state.updateFade(&screen->panels[6]);
        STGTRAIN_state.updateFade(&screen->panels[4]);
        if (STGTRAIN_state.updateFade(&screen->panels[3])) {
            screen->substate++;
        }
        break;
    case 0x34:
        if (win->fade->state == TASK_DONE) {
            screen->state = TASK_KILL;
        }
        break;
    }
}

/* The training screen's update: loads its files, then runs the menu */
void STGTRAIN_updateScreen(TrainScreen *screen, TrainScreenWindows *win) {
    s32 i;

    switch (screen->state) {
    case TASK_INIT:
    default:
        switch (screen->substate) {
        case 0:
        default:
            STGTRAIN_state.loadImages();
            FILE_CACHE.request(STGTRAIN_TEXT);
            SOUND.loadBank(0x21);
            screen->substate++;
            break;
        case 1:
            if (FILE_CACHE.isLoading(STGTRAIN_TEXT) == 0) {
                screen->nextState(screen);
                STGTRAIN_createScreenWindows(screen, win);
                for (i = 0; i < 3; i++) {
                    if (GAME.funcs.getPartyMember(i) != -1) {
                        screen->partyCount++;
                    }
                }
                for (i = 2; i >= 0; i--) {
                    screen->panels[i].duration = 10;
                }
                screen->panels[3].duration = 10;
                screen->panels[4].duration = 10;
                screen->panels[6].duration = 10;
                screen->panels[5].duration = 8;
                screen->setState(screen, TASK_DONE);
            }
            break;
        }
        break;
    case TASK_RUN:
        STGTRAIN_runScreen(screen, win);
        STGTRAIN_drawScreen(screen);
        break;
    case TASK_DONE:
        if (SOUND.isLoading() == 0) {
            SOUND.playSound(0x60840002);
            screen->setState(screen, TASK_RUN);
        }
        break;
    case TASK_KILL:
        SOUND.stopSound(0x60840002);
        GAME.funcs.requestMode(GAME.fieldMode, 0);
        break;
    }
}

/* Creates the training screen */
TrainScreen *STGTRAIN_createScreen(void) {
    TrainScreen *screen = createTask(STGTRAIN_updateScreen, sizeof(TrainScreen), 0x80);
    s32 sign;

    screen->showStats = STGTRAIN_showStatChanges;
    screen->layerId = 0x1000;
    screen->depth = 6;
    /* the gym's sign, by the stage the player came from */
    switch (GAME.funcs.getPrevMode()) {
    case 0x23D: /* South Cape */
        sign = 0x2E;
        break;
    case 0x24B: /* North Wind Wasteland East */
        sign = 0x2F;
        break;
    case 0x267: /* the Legendary Gym */
        sign = 0x30;
        break;
    case 0x28C: /* Central Park, in Amaterasu */
        sign = 0x31;
        break;
    case 0x2AA: /* South Cape, in Amaterasu */
        sign = 0x32;
        break;
    case 0x2B5: /* North Wind Wasteland East, in Amaterasu */
        sign = 0x33;
        break;
    case 0x2CF: /* the Legendary Gym, in Amaterasu */
        sign = 0x34;
        break;
    case 0x21D: /* Central Park */
    default:
        sign = 0x2D;
        break;
    }
    screen->sign = sign;
    return screen;
}

/* Starts darkening the screen (fadeIn 0) or brightening it, over duration
   frames */
void STGTRAIN_startScreenFade(ScreenFade *task, s32 fadeIn, s32 duration) {
    task->setState(task, TASK_RUN);
    task->substate = 1;
    task->fadeIn = fadeIn;
    if (fadeIn == 0) {
        task->level = 0;
        task->levelStep = 0xFF00 / duration;
    } else {
        task->level = 0xFF00;
        task->levelStep = -(0xFF00 / duration);
    }
}

/* Darkens the whole screen by the fade's level, with a subtractive rectangle */
void STGTRAIN_drawScreenFade(ScreenFade *task) {
    Layer *layer = GFX.funcs.getLayer(task->layerId);
    u_long *ot = (u_long *)layer->getOtEntry(layer, task->depth);
    POLY_F4 *poly = GFX.funcs.getPrim();
    DR_TPAGE *mode;

    setlen(poly, 5);
    poly->code = 0x2A;
    poly->r0 = poly->g0 = poly->b0 = task->level >> 8;
    poly->x0 = poly->x2 = 0;
    poly->x1 = poly->x3 = 320;
    poly->y0 = poly->y1 = 0;
    poly->y2 = poly->y3 = 256;
    addPrim(ot, poly);
    mode = (DR_TPAGE *)(poly + 1);
    setlen(mode, 1);
    mode->code[0] = 0xE1000245;
    addPrim(ot, mode);
    GFX.funcs.setPrim(mode + 1);
}

/* The screen fade's task: once started, moves the level to black or back and
   draws it */
void STGTRAIN_updateScreenFade(ScreenFade *task) {
    switch (task->state) {
    case 0:
    default:
        task->nextState(task);
        break;
    case 1:
        if (task->substate == 0) {
            break;
        }
        task->level += task->levelStep;
        if (task->fadeIn == 0) {
            if (task->level > 0xFF00) {
                task->level = 0xFF00;
                task->state = 2;
            }
        } else if (task->level < 0) {
            task->level = 0;
            task->state = 2;
        }
        /* fallthrough */
    case 2:
        STGTRAIN_drawScreenFade(task);
        break;
    case 3:
        break;
    }
}

/* Creates the screen fade, on layer 0x1000 at depth 6 */
ScreenFade *STGTRAIN_createScreenFade(void) {
    ScreenFade *task = createTask(STGTRAIN_updateScreenFade, sizeof(ScreenFade), 0);

    task->start = STGTRAIN_startScreenFade;
    task->layerId = 0x1000;
    task->depth = 6;
    return task;
}

/* The partners' sprites while they wait, by partner: -1 ends a loop */
s32 STGTRAIN_waitAnims[8][7] = {
    {7, 8, 9, 10, 9, 8, -1},
    {14, 15, 16, 15, -1, -1, -1},
    {11, 12, 13, 12, -1, -1, -1},
    {3, 4, 5, 6, 5, 4, -1},
    {25, 26, 27, 28, 27, 26, -1},
    {0, 1, 2, 1, -1, -1, -1},
    {17, 18, 19, 20, 19, 18, -1},
    {21, 22, 23, 24, 23, 22, -1},
};
