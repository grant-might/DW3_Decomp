/* The fourth object of FIELDSTG.PRO (see fieldstg.c): its rodata starts at
   0x800825CC (USA). */

#include "fieldstg.h"

/* Stretches a box toward from-to along one axis. The match depends on each
   case having its own variables. */
void FIELDSTG_stretchBannerBox(AreaBanner *task, BannerBox *box) {
    switch (box->stretch) {
    case 1: {
        s32 start = box->pos.vx;
        s32 end = start + box->size.vx;
        s32 from = box->from;
        s32 to = box->to;
        s32 speed = box->speed;

        if (start < from) {
            start += speed;
            if (start > from) {
                start = from;
            }
        } else if (start > from) {
            start -= speed;
            if (start < from) {
                start = from;
            }
        }
        if (end < to) {
            end += speed;
            if (end > to) {
                end = to;
            }
        } else if (end > to) {
            end -= speed;
            if (end < to) {
                end = to;
            }
        }
        box->pos.vx = start;
        box->size.vx = end - start;
        if (start == from && end == to) {
            box->stretch = 0;
        }
        break;
    }
    case 2: {
        s32 start = box->pos.vy;
        s32 end = start + box->size.vy;
        s32 from = box->from;
        s32 to = box->to;
        s32 speed = box->speed;

        if (start < from) {
            start += speed;
            if (start > from) {
                start = from;
            }
        } else if (start > from) {
            start -= speed;
            if (start < from) {
                start = from;
            }
        }
        if (end < to) {
            end += speed;
            if (end > to) {
                end = to;
            }
        } else if (end > to) {
            end -= speed;
            if (end < to) {
                end = to;
            }
        }
        box->pos.vy = start;
        box->size.vy = end - start;
        if (start == from && end == to) {
            box->stretch = 0;
        }
        break;
    }
    }
}

void FIELDSTG_drawBannerBox(AreaBanner *task, u_long *ot, DVECTOR pos, DVECTOR size, s32 color) {
    POLY_F4 *poly = GFX.funcs.getPrim();

    setlen(poly, 5);
    *(s32 *)&poly->r0 = color;
    poly->code = 0x28;
    poly->x0 = pos.vx;
    poly->x1 = pos.vx + size.vx;
    poly->x2 = pos.vx;
    poly->x3 = pos.vx + size.vx;
    poly->y0 = pos.vy;
    poly->y1 = pos.vy;
    poly->y2 = pos.vy + size.vy;
    poly->y3 = pos.vy + size.vy;
    addPrim(ot, poly);
    GFX.funcs.setPrim(poly + 1);
}

/*
 * The area name banner: on state 0 it copies its ten boxes from FIELDSTG_bannerBoxes
 * and opens the area and place windows (func_80086D20); on state 1 the boxes
 * appear and stretch in turn until both windows have finished; on state 2
 * it closes the layer's clip from the top and the bottom.
 */
void FIELDSTG_updateBanner(AreaBanner *task, AreaNameWindows *windows) {
    Layer *layer;
    u_long *ot;
    s32 i;

    switch (task->state) {
    default:
    case 0:
        if (task->key1 != 0) {
            s32 j;

            for (j = 0; j < 10; j++) {
                task->boxes[j] = FIELDSTG_bannerBoxes[j];
            }
            func_80086D20((Task *)task, windows);
            task->nextState(task);
        } else {
            task->setState(task, 2);
        }
        break;
    case 1:
        switch (task->substate) {
        default:
        case 0:
            task->boxes[0].visible = 1;
            task->boxes[5].visible = 1;
            if (task->boxes[5].stretch != 0) {
                break;
            }
            task->nextSubstate(task);
        case 1:
            task->boxes[8].visible = 1;
            task->boxes[9].visible = 1;
            task->boxes[6].visible = 1;
            task->boxes[1].visible = 1;
            task->boxes[2].visible = 1;
            task->boxes[7].visible = 1;
            task->boxes[3].visible = 1;
            if (task->boxes[9].stretch != 0) {
                break;
            }
            task->nextSubstate(task);
        case 2:
            task->nextSubstate(task);
        case 3:
            task->boxes[4].visible = 1;
            if (task->boxes[4].stretch == 0) {
                task->nextSubstate(task);
            }
            break;
        case 4:
            if (windows->area->isFinished(windows->area) && windows->place->isFinished(windows->place)) {
                task->setState(task, 2);
            }
            break;
        }
        break;
    case 2:
        layer = GFX.funcs.getLayer(0x1003);
        /* the match depends on the empty case 0 */
        switch (task->substate) {
        case 0:
            break;
        case 1:
            task->step += GFX.funcs.getFrameTime();
            if (task->step < 60) {
                break;
            }
            task->nextSubstate(task);
        case 2:
            task->clip.w = 320;
            task->clip.x = 0;
            task->clip.y = 0;
            task->clip.h = 240;
            task->nextSubstate(task);
        case 3:
            task->clip.y += 8;
            task->clip.h -= 16;
            layer->setClipPos(layer, task->clip.x, task->clip.y);
            layer->setClipSize(layer, task->clip.w, task->clip.h);
            if (task->clip.h == 0) {
                task->setState(task, 3);
            }
            break;
        }
        break;
    case 3:
        D_800990B4.bannerShown = 0;
        break;
    }
    if (task->state >= 1 && task->state <= 2 && task->key1 != 0) {
        Layer *top = GFX.funcs.getLayer(0x1003);

        ot = (u_long *)top->getOtEntry(top, 1);
        for (i = 0; i < 10; i++) {
            if (task->boxes[i].visible) {
                FIELDSTG_stretchBannerBox(task, &task->boxes[i]);
                FIELDSTG_drawBannerBox(task, ot, task->boxes[i].pos, task->boxes[i].size, task->boxes[i].color);
            }
        }
    }
}

Task *FIELDSTG_createBanner(s32 arg0) {
    Task *task = createTaskWithId(FIELDSTG_updateBanner, sizeof(AreaBanner), 8, 9);

    task->key1 = arg0;
    D_800990B4.bannerShown = 1;
    return task;
}

s32 FIELDSTG_stepBalloonAnim(Balloon *task) {
    task->time -= GFX.funcs.getFrameTime();
    if (task->time < 0) {
        task->frame += 2;
        if (FIELDSTG_triggerAnims[task->key2][task->frame] == 0xFF) {
            task->frame = 0;
        }
        task->time = FIELDSTG_triggerAnims[task->key2][task->frame + 1];
    }
    return FIELDSTG_triggerAnims[task->key2][task->frame];
}

void FIELDSTG_drawBalloon(Balloon *task) {
    SpriteDrawer sprite;
    Point pos;
    s32 frame;

    pos.x = task->actor->tile.x;
    pos.y = task->actor->tile.y - (task->actor->z >> 8);
    initSpriteDrawer(&sprite);
    sprite.setLayerId(0x1002, 1);
    sprite.setTexture(0x200, 0x100);
    if (task->substate == 2) {
        frame = FIELDSTG_stepBalloonAnim(task);
        sprite.draw(FILE_CACHE.getEntry(FIELD_SPRITES_FILE << 16), frame, pos.x, pos.y - 0x1B);
    }
    sprite.draw(FILE_CACHE.getEntry(FIELD_SPRITES_FILE << 16), task->pop >> 2, pos.x, pos.y - 0x1B);
}

void FIELDSTG_updateBalloon(Balloon *task) {
    switch (task->state) {
        default:
        case 0:
            if (task->actor == NULL) {
                task->actor = TASK_REGISTRY.funcs.find(5, -1, 0);
                if (task->actor == NULL) {
                    break;
                }
            }
            if (task->key1 == 0) {
                task->popStart = 0xC8;
                task->popOpen = 0xD4;
                task->popEnd = 0xDC;
            } else {
                task->popStart = 0x104;
                task->popOpen = 0x10C;
                task->popEnd = 0x114;
            }
            if (task->key2 != 1) {
                SOUND.playSound(0x40007);
            }
            task->nextState(task);
            /* fallthrough */
        case 1:
            if (D_800990B4.innOpen != 0) {
                break;
            }
            switch (task->substate) {
                default:
                case 0:
                    task->pop = task->popStart;
                    task->nextSubstate(task);
                    /* fallthrough */
                case 1:
                    task->pop += GFX.funcs.getFrameTime();
                    if (task->pop >= task->popOpen) {
                        task->pop = task->popOpen;
                        task->nextSubstate(task);
                    }
                    break;
                case 2:
                    break;
            }
            FIELDSTG_drawBalloon(task);
            break;
        case 2:
            task->pop += GFX.funcs.getFrameTime();
            if (task->pop >= task->popEnd) {
                task->pop = task->popEnd;
                task->setState(task, 3);
            }
            FIELDSTG_drawBalloon(task);
            break;
        case 3:
            break;
    }
}

Balloon *FIELDSTG_createBalloon(s32 kind, s32 anim, s32 id) {
    Balloon *task = createTaskWithId(FIELDSTG_updateBalloon, sizeof(Balloon), 0, id);
    task->key1 = kind;
    task->key2 = anim;
    return task;
}

void FIELDSTG_createPlayerBalloon(s32 id) {
    FIELDSTG_createBalloon(0, 0, id);
}

void FIELDSTG_balloonCommand(Balloon *task, s32 command, s32 id) {
    if (task != NULL) {
        switch (command) {
        case 0x325:
            task->key2 = 0;
            break;
        case 0x327:
            task->key2 = 1;
            break;
        case 0x326:
            task->setState(task, 2);
            break;
        }
        if (command == 0x325 || command == 0x327) {
            task->actor = TASK_REGISTRY.funcs.find(5, id, -1);
        }
    }
}
