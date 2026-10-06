#include "game.h"
#include <libgs.h>

/* Small variables, addressed through $gp (see the Makefile) */
static s32 GFX_STARTED = 0;
static s32 FLIP_PENDING;
static CardDrawer *CARD_DRAWER;
static SpriteDrawer *SPRITE_DRAWER;
static TextTools *TEXT_TOOLS;
static TimLoader *TIM_LOADER;

void vsyncCallback(void) {
#if VERSION_US
    GFX.timeCounter += 0x100;
    GFX.frameTimeCounter += 0x100;
    GAME.playFrames += 0x100;
#elif VERSION_EU
    if (NTSC_MODE) {
        GFX.timeCounter += 0x100;
        GFX.frameTimeCounter += 0x100;
        GAME.playFrames += 0x100;
    } else {
        GFX.timeCounter += 0x133;
        GFX.frameTimeCounter += 0x133;
        GAME.playFrames += 0x133;
    }
#endif
    if (GFX.vsyncFunc != NULL) {
        GFX.vsyncFunc(GFX.vsyncArg);
    }
    if (FLIP_PENDING != 0) {
        GFX.dispBuffer = !GFX.dispBuffer;
        PutDispEnv(&GFX.disp[GFX.dispBuffer]);
    }
    SsSeqCalledTbyT();
    FLIP_PENDING = 0;
}

void startVSyncCallback(void) {
    VSyncCallback(vsyncCallback);
}

/*
 * Ends a frame: lets the layers run their draw callbacks, waits for the GPU
 * and for the vsync that shows the finished buffer, then sends every layer
 * of that buffer and clears the ones of the next.
 */
void drawFrame(s32 draw) {
    s32 i;
    Layer *layer;

    if (draw) {
        s32 j;

        for (j = 0; j < 30; j++) {
            layer = GFX.layers[j];
            if (layer != NULL) {
                if (layer->keepView != 0) {
                    layer->loadView(layer);
                }
                if (layer->keepLightMatrix != 0) {
                    layer->loadLightMatrix(layer);
                }
                layer->runCallbacks(layer);
            }
        }
    }
    DrawSync(0);
    FLIP_PENDING = 1;
    while (*(volatile s32 *)&FLIP_PENDING != 0) {
    }
    if (GFX.prim != 0) {
        for (i = 0; i < 30; i++) {
            if (GFX.layers[i] != NULL) {
                GFX.layers[i]->draw(GFX.layers[i]);
            }
        }
    }
    GFX.buffer = GFX.buffer == 0;
#if VERSION_US
    GFX.frameCounter += 0x100;
#elif VERSION_EU
    if (NTSC_MODE) {
        GFX.frameCounter += 0x100;
    } else {
        GFX.frameCounter += 0x133;
    }
#endif
    GFX.frameCount = GFX.frameCounter >> 8;
    GFX.time = GFX.timeCounter >> 8;
    GFX.frameTime = GFX.frameTimeCounter >> 8;
    GFX.frameTimeCounter &= 0xFF;
    GAME.funcs.updatePlayTime();
    GFX.prim = (s32)GFX.primBufs[GFX.buffer];
    for (i = 0; i < 30; i++) {
        if (GFX.layers[i] != NULL) {
            GFX.layers[i]->clearOt(GFX.layers[i]);
        }
    }
}

s32 getFrameCount(void) {
    return GFX.frameCount;
}

s32 getTime(void) {
    return GFX.time;
}

s32 getFrameTime(void) {
    return GFX.frameTime;
}

void resetGraphics(void) {
    s32 i;

    if (GFX_STARTED != 0) {
        for (i = 0; i < 30; i++) {
            if (GFX.layers[i] != NULL) {
                GFX.funcs.destroyLayer(GFX.layerIds[i]);
                i--;
            }
        }
        HEAP.zero(&GFX.prim, 0x18);
    } else {
        GFX.buffer = 1;
        GFX.dispBuffer = 0;
        GFX_STARTED = 1;
    }
}

void allocPrimBuffers(s32 size) {
    GFX.primBufSize = size;
    GFX.primBufs[0] = HEAP.allocHigh(size, 2);
    GFX.primBufs[1] = HEAP.allocHigh(size, 2);
    GFX.prim = (s32)GFX.primBufs[GFX.buffer];
}

s32 getPrim(void) {
    return GFX.prim;
}

void setPrim(s32 next) {
    GFX.prim = next;
}

void freePrimBuffers(void) {
    if (GFX.primBufs[0] != NULL) {
        HEAP.free(GFX.primBufs[0]);
    }
    if (GFX.primBufs[1] != NULL) {
        HEAP.free(GFX.primBufs[1]);
    }
    GFX.primBufs[0] = NULL;
    GFX.primBufs[1] = NULL;
}

void setDisplayMode(s32 w, s32 h, s32 hires, s32 interlace) {
    if (hires != 0) {
        if (interlace != 0) {
            SetDefDispEnv(&GFX.disp[0], 0, 0, 320, 480);
            GFX.disp[0].isinter = 1;
            GFX.disp[0].isrgb24 = 1;
            SetDefDispEnv(&GFX.disp[1], 480, 0, 320, 480);
            GFX.disp[1].isinter = 1;
            GFX.disp[1].isrgb24 = 1;
        } else {
            SetDefDispEnv(&GFX.disp[0], 0, 0, w, h);
            SetDefDispEnv(&GFX.disp[1], w, 0, w, h);
        }
    } else {
        SetDefDispEnv(&GFX.disp[0], 0, 0, w, h);
        SetDefDispEnv(&GFX.disp[1], 0, 256, w, h);
    }
#if VERSION_EU
    if (SHIFT_PAL_SCREEN) {
        GFX.disp[0].screen.y = 0x18;
        GFX.disp[1].screen.y = 0x18;
    }
#endif
    GsInit3D();
    SetGeomOffset(0, 0);
}

void setDisplayArea(s32 x, s32 y, s32 w, s32 h) {
    SetDefDispEnv(&GFX.disp[0], x, y, w, h);
    SetDefDispEnv(&GFX.disp[1], x, y, w, h);
}

Layer *getLayer(s32 id) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (GFX.layers[i] != NULL && GFX.layerIds[i] == id) {
            return GFX.layers[i];
        }
    }
    return NULL;
}

/* The slot of the layer with this id; id 0 finds a free slot */
s32 findLayerSlot(s32 id) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (id != 0) {
            if (GFX.layers[i] != NULL && GFX.layerIds[i] == id) {
                return i;
            }
        } else if (GFX.layers[i] == NULL) {
            return i;
        }
    }
    return -1;
}

void removeLayerSlot(s32 index) {
    for (; index < 29; index++) {
        GFX.layers[index] = GFX.layers[index + 1];
        GFX.layerIds[index] = GFX.layerIds[index + 1];
    }
}

void insertLayerSlot(s32 index, Layer *layer, s32 id) {
    s32 i;

    for (i = 29; i != index; i--) {
        GFX.layers[i] = GFX.layers[i - 1];
        GFX.layerIds[i] = GFX.layerIds[i - 1];
    }
    GFX.layers[index] = layer;
    GFX.layerIds[index] = id;
}

Layer *createLayer(RECT *rect, s32 otShift, s32 id) {
    DRAWENV env;
    s32 index = findLayerSlot(0);

    if (index != -1) {
        SetDefDrawEnv(&env, rect->x, rect->y, rect->w, rect->h);
        GFX.layerIds[index] = id;
        return GFX.layers[index] = newLayer(&env, otShift);
    }
    return NULL;
}

s32 destroyLayer(s32 id) {
    s32 index = findLayerSlot(id);
    Layer *layer;

    if (index != -1) {
        layer = GFX.layers[index];
        layer->free(layer);
        HEAP.free(GFX.layers[index]);
        removeLayerSlot(index);
        return 1;
    }
    return 0;
}

/* Moves a layer to the position of another one (plus delta) in the draw order */
void moveLayer(s32 id, s32 targetId, s32 delta) {
    s32 from = findLayerSlot(id);
    s32 to = findLayerSlot(targetId);
    s32 pos;
    Layer *layer;
    s32 layerId;

    if (from != -1 && to != -1) {
        pos = to + delta;
        layer = GFX.layers[from];
        layerId = GFX.layerIds[from];
        if (pos <= 0) {
            pos = 0;
        }
        removeLayerSlot(from);
        insertLayerSlot(pos, layer, layerId);
    }
}

void layerClearOt(Layer *layer) {
    ClearOTagR(layer->ot[GFX.buffer], layer->otLen);
}

/* Links every run of empty OT entries past itself, so the GPU skips it */
void layerSkipEmptyOt(Layer *layer) {
    u_long mask = 0xFFFFFF;
    u_long *ot = layer->ot[GFX.buffer];
    u_long *p = ot + layer->otLen - 1;
    u_long *q;

    while (p != ot) {
        q = p - 1;
        if ((*p & mask) == ((u_long)q & mask)) {
            while ((*q & mask) == ((u_long)(q - 1) & mask)) {
                q--;
            }
            *p = (u_long)q & mask;
        }
        p = q;
    }
}

void layerDraw(Layer *layer) {
    DRAWENV env = layer->env;
    DR_ENV *dr;
    u_long *ot;
    u_long *tag;

    env.ofs[0] = layer->offsetX;
    env.ofs[1] = layer->offsetY;
    layerSkipEmptyOt(layer);
    dr = (DR_ENV *)GFX.prim;
    ot = layer->ot[GFX.buffer] + layer->otLen;
    tag = ot - 1;
    if (GFX.buffer != 0) {
        env.clip.y += 256;
        env.ofs[1] += 256;
    }
    SetDrawEnv(dr, &env);
    addPrim(ot - 1, dr);
    dr++;
    GFX.prim = (s32)dr;
    DrawOTag(tag);
}

u_long *layerGetOtEntry(Layer *layer, s32 depth) {
    return layer->ot[GFX.buffer] + depth;
}

u_long *layerGetOtEntryZ(Layer *layer, s32 z) {
    s32 i = z >> (16 - layer->otShift);

    return layer->ot[GFX.buffer] + i;
}

u_long *layerGetOt(Layer *layer) {
    return layer->ot[GFX.buffer];
}

s32 layerGetOtShift(LayerView *layer) {
    return layer->otShift;
}

void layerSetBgColor(LayerView *layer, u8 r, u8 g, u8 b) {
    layer->bgR = r;
    layer->bgB = b;
    layer->bgG = g;
    if (r | g | b) {
        layer->isbg = 1;
    } else {
        layer->isbg = 0;
    }
}

void layerSetOffset(LayerView *layer, s16 x, s16 y) {
    layer->offsetX = x;
    layer->offsetY = y;
}

void layerGetScroll(LayerView *layer, Vec2 *out) {
    out->x = layer->scrollX >> 8;
    out->y = layer->scrollY >> 8;
}

void layerSetScroll(LayerView *layer, s32 x, s32 y) {
    layer->scrollX = x;
    layer->scrollY = y;
}

void layerAddScroll(LayerView *layer, s32 dx, s32 dy) {
    layer->scrollX += dx;
    layer->scrollY += dy;
}

void layerSetClipPos(LayerView *layer, s16 x, s16 y) {
    layer->x = x;
    layer->y = y;
}

void layerSetClipSize(LayerView *layer, s16 w, s16 h) {
    layer->w = w;
    layer->h = h;
}

void layerGetViewRect(LayerView *layer, Rect16 *rect) {
    rect->x = layer->x - layer->offsetX + (layer->scrollX >> 8);
    rect->y = layer->y - layer->offsetY + (layer->scrollY >> 8);
    rect->w = layer->w;
    rect->h = layer->h;
}

void layerFree(Layer *layer) {
    DrawSync(0);
    HEAP.free(layer->ot[0]);
    HEAP.free(layer->ot[1]);
    if (layer->callbackCap != 0) {
        HEAP.free(layer->callbacks);
    }
}

void layerResetCallbacks(LayerView *layer) {
    layer->callbacks->priority = 0x7FFFFFFF;
    layer->callbacks->param = 0;
    layer->callbacks->func = NULL;
    layer->callbacks->arg = 0;
    layer->callbacks->next = NULL;
    layer->callbackCount = 1;
}

void layerAllocCallbacks(LayerView *layer, s32 count) {
    layer->callbacks = HEAP.alloc(count * sizeof(DrawCallback), 2);
    layer->callbackCap = count;
    layerResetCallbacks(layer);
}

void layerAddSortedCallback(Layer *layer, s32 func, s32 arg, s32 priority, s32 param) {
    DrawCallback *cur;
    DrawCallback *prev;
    DrawCallback *e;
    s32 i;
    s32 cap;

    if (layer->callbackCount < layer->callbackCap) {
        cur = layer->callbacks;
        e = &cur[layer->callbackCount];
        e->func = func;
        e->arg = arg;
        e->priority = priority;
        e->param = param;
        prev = NULL;
        if (layer->callbackCount != 0) {
            cap = layer->callbackCap;
            for (i = 0; i < cap; i++) {
                if (cur->priority < priority) {
                    cur = prev;
                    break;
                }
                prev = cur;
                if (cur->next == NULL) {
                    break;
                }
                cur = cur->next;
            }
            if (cur->next == NULL) {
                cur->next = e;
                e->next = NULL;
            } else {
                e->next = cur->next;
                cur->next = e;
            }
        } else {
            e->next = NULL;
        }
        layer->callbackCount++;
    }
}

void layerAddCallback(LayerView *layer, void (*func)(s32, void *, s32), s32 arg) {
    DrawCallback *cb;

    if (layer->callbackCount < layer->callbackCap) {
        cb = &layer->callbacks[layer->callbackCount];
        cb->func = func;
        cb->arg = arg;
        cb->priority = 0;
        cb->param = 0;
        cb->next = NULL;
        if (layer->callbackCount != 0) {
            cb[-1].next = cb;
        }
        layer->callbackCount++;
    }
}

void layerRunCallbacks(LayerView *layer) {
    DrawCallback *cb;

    if (layer->callbackCount) {
        cb = layer->callbacks;
        do {
            if (cb->func != NULL) {
                cb->func(cb->arg, layer, cb->param);
            }
            cb = cb->next;
        } while (cb != NULL);
        layerResetCallbacks(layer);
    }
}

void layerSetKeepView(Layer *layer, s32 enable, s32 projection) {
    layer->keepView = enable;
    if (enable) {
        layer->projection = projection;
        layer->view[GFX.buffer] = GsWSMATRIX;
    }
}

void layerLoadView(Layer *layer) {
    func_80029598(layer->projection);
    GsWSMATRIX = layer->view[GFX.buffer];
}

void layerSetKeepLightMatrix(Layer *layer, s32 enable) {
    layer->keepLightMatrix = enable;
    if (enable) {
        layer->lightMatrix[GFX.buffer] = GsLIGHTWSMATRIX;
    }
}

void layerLoadLightMatrix(Layer *layer) {
    GsLIGHTWSMATRIX = layer->lightMatrix[GFX.buffer];
}

Layer *newLayer(DRAWENV *env, s32 otShift) {
    Layer *layer = HEAP.allocZeroed(0x16C, 2);

    layer->env = *env;
    layer->otShift = otShift;
    layer->otLen = OT_LENGTHS[otShift - 1];
    layer->ot[0] = HEAP.alloc(layer->otLen << 2, 2);
    layer->ot[1] = HEAP.alloc(layer->otLen << 2, 2);
    ClearOTagR(layer->ot[0], layer->otLen);
    ClearOTagR(layer->ot[1], layer->otLen);
    layer->setBgColor = layerSetBgColor;
    layer->draw = (void *)layerDraw;
    layer->clearOt = (void *)layerClearOt;
    layer->getOtEntry = (void *)layerGetOtEntry;
    layer->getOtEntryZ = layerGetOtEntryZ;
    layer->free = (void *)layerFree;
    layer->setClipPos = layerSetClipPos;
    layer->setClipSize = layerSetClipSize;
    layer->setOffset = layerSetOffset;
    layer->setScroll = layerSetScroll;
    layer->addScroll = layerAddScroll;
    layer->getScroll = layerGetScroll;
    layer->getViewRect = layerGetViewRect;
    layer->getOt = layerGetOt;
    layer->getOtShift = layerGetOtShift;
    layer->allocCallbacks = layerAllocCallbacks;
    layer->addSortedCallback = layerAddSortedCallback;
    layer->addCallback = layerAddCallback;
    layer->runCallbacks = (void *)layerRunCallbacks;
    layer->setKeepView = layerSetKeepView;
    layer->loadView = (void *)layerLoadView;
    layer->setKeepLightMatrix = layerSetKeepLightMatrix;
    layer->loadLightMatrix = (void *)layerLoadLightMatrix;
    return layer;
}

void bindCardDrawer(CardDrawer *obj) {
    CARD_DRAWER = obj;
}

void cardDrawerSetCard(s32 id) {
    s32 n;
    s32 i;
    if (id > 0) {
        n = id - 1;
        i = n >> 6;
        CARD_DRAWER->card = (CardImageHeader *)(FILE_CACHE.load(CARD_IMAGE_FILES[i]) + (n & 0x3F) * 0x62C);
    } else {
        CARD_DRAWER->card = (CardImageHeader *)FILE_CACHE.load(CARD_IMAGE_FILES[0]);
    }
}

void cardDrawerLoadImage(void) {
    TimLoader obj;

    initTimLoader(&obj);
    obj.setImagePos(CARD_DRAWER->imageX + CARD_DRAWER->cellX * 16, CARD_DRAWER->imageY + (CARD_DRAWER->cellY << 5));
    obj.setClutPos(CARD_DRAWER->clutX, CARD_DRAWER->clutY + CARD_DRAWER->cellX * CARD_DRAWER->clutStride + CARD_DRAWER->cellY);
    obj.load(CARD_DRAWER->card->tim);
}

void cardDrawerSetLayer(s32 id, s32 depth) {
    Layer *layer = GFX.funcs.getLayer(id);

    CARD_DRAWER->layer = layer;
    CARD_DRAWER->ot = layer->getOtEntry(layer, depth);
}

void cardDrawerSetImagePos(s32 x, s32 y) {
    CARD_DRAWER->imageX = x;
    CARD_DRAWER->imageY = y;
}

void cardDrawerSetClutPos(s32 x, s32 y) {
    CARD_DRAWER->clutX = x;
    CARD_DRAWER->clutY = y;
}

void cardDrawerSetCell(s32 x, s32 y) {
    CARD_DRAWER->cellX = x;
    CARD_DRAWER->cellY = y;
}

void cardDrawerSetClutStride(s32 stride) {
    CARD_DRAWER->clutStride = stride;
}

void cardDrawerSetSemiTrans(s32 on) {
    CARD_DRAWER->semiTrans = on;
}

void cardDrawerDraw(s32 x, s32 y) {
    SPRT *sprt = GFX.funcs.getPrim();
    SPRT *base = sprt;
    u8 *end;
    u16 tpage;
    u16 clut;

    clut = getClut(CARD_DRAWER->clutX, CARD_DRAWER->clutY + CARD_DRAWER->cellX * CARD_DRAWER->clutStride + CARD_DRAWER->cellY);
    tpage = (1 << 7) | (1 << 5) | ((CARD_DRAWER->imageY & 0x100) >> 4) | (((CARD_DRAWER->imageX + CARD_DRAWER->cellX * 16) & 0x3C0) >> 6) | ((CARD_DRAWER->imageY & 0x200) << 2);
    setSprt(sprt);
    if (CARD_DRAWER->semiTrans != 0) {
        setSemiTrans(sprt, 1);
    }
    setRGB0(sprt, 0x80, 0x80, 0x80);
    setXY0(sprt, x, y);
    setUV0(sprt, (CARD_DRAWER->cellX & 3) * 32, CARD_DRAWER->cellY * 32);
    setWH(sprt, 32, 32);
    sprt->clut = clut;
    addPrim(CARD_DRAWER->ot, sprt);
    sprt++;
    SetDrawTPage((DR_TPAGE *)sprt, 0, 1, tpage);
    end = (u8 *)base + 0x1C;
    /* addPrim, with the tag written through the start of the block */
    setaddr(base + 1, getaddr(CARD_DRAWER->ot));
    setaddr(CARD_DRAWER->ot, sprt);
    GFX.funcs.setPrim(end);
}

s32 cardDrawerGetKind(void) {
    return CARD_KINDS[CARD_DRAWER->card->kind];
}

void initCardDrawer(CardDrawer *obj) {
    HEAP.zero(obj, sizeof(CardDrawer));
    obj->setCard = cardDrawerSetCard;
    obj->loadImage = cardDrawerLoadImage;
    obj->setLayer = cardDrawerSetLayer;
    obj->setImagePos = cardDrawerSetImagePos;
    obj->setClutPos = cardDrawerSetClutPos;
    obj->setCell = cardDrawerSetCell;
    obj->setClutStride = cardDrawerSetClutStride;
    obj->setSemiTrans = cardDrawerSetSemiTrans;
    obj->draw = cardDrawerDraw;
    obj->getKind = cardDrawerGetKind;
    bindCardDrawer(obj);
    obj->clutStride = 8;
}

void bindSpriteDrawer(SpriteDrawer *obj) {
    SPRITE_DRAWER = obj;
}

void spriteDrawerSetTexture(s32 x, s32 y) {
    SPRITE_DRAWER->tpageX = x;
    SPRITE_DRAWER->tpageY = y;
    SPRITE_DRAWER->clutX = x;
    SPRITE_DRAWER->clutY = y;
}

void spriteDrawerSetAltClut(s32 x, s32 y) {
    SPRITE_DRAWER->altClutX = x;
    SPRITE_DRAWER->altClutY = y - 0x100;
}

void spriteDrawerSetClutRow(s32 row) {
    SPRITE_DRAWER->clutRow = row;
}

void spriteDrawerSetLayer(Layer *layer, s32 depth) {
    SPRITE_DRAWER->layer = layer;
    SPRITE_DRAWER->ot = layer->getOtEntry(layer, depth);
}

void spriteDrawerSetLayerId(s32 id, s32 depth) {
    spriteDrawerSetLayer(GFX.funcs.getLayer(id), depth);
}

/*
 * Draws frame `frame` of a sprite sheet (see SpritePart) at (x, y): as
 * sprites, changing the texture page between parts when needed, or as
 * textured quads when the drawer is scaled or rotated.
 */
void spriteDrawerDraw(s32 *sheet, s32 frame, s32 x, s32 y) {
    Vec2 scroll;
    SVECTOR out;
    SVECTOR in[4];
    SpritePart *parts;
    SpritePart *part;
    u8 *ids;
    s16 *p;
    void *prim;
    s32 transform;
    s32 count;
    s32 frameRow;
    s32 semi;
    s32 abr;
    s32 i;
    s32 k;
    u8 u;
    u8 v;

    transform = 0;
    ids = (u8 *)sheet + sheet[1];
    parts = (SpritePart *)((u8 *)sheet + sheet[0]);
    for (i = 0; ids[i] != frame; i++) {
    }
    p = (s16 *)((u8 *)sheet + sheet[i + 2]);
    /* rot.vx and rot.vy are tested as one word */
    if (SPRITE_DRAWER->scaleX != 0x1000 || SPRITE_DRAWER->scaleY != 0x1000 || SPRITE_DRAWER->scaleZ != 0x1000 ||
        *(s32 *)&SPRITE_DRAWER->rot.vx != 0 || SPRITE_DRAWER->rot.vz != 0) {
        transform = 1;
        if (SPRITE_DRAWER->transformDirty) {
            RotMatrixYXZ_gte(&SPRITE_DRAWER->rot, &SPRITE_DRAWER->matrix);
            ScaleMatrix(&SPRITE_DRAWER->matrix, (VECTOR *)&SPRITE_DRAWER->scaleX);
        }
    }
    count = *p++;
    frameRow = *p++;
    abr = *p++;
    if (abr == -1) {
        semi = 0;
        abr = 0;
    } else {
        semi = 1;
    }
    if (SPRITE_DRAWER->followScroll) {
        SPRITE_DRAWER->layer->getScroll(SPRITE_DRAWER->layer, &scroll);
    } else {
        scroll.x = 0;
        scroll.y = 0;
    }
    p += (count - 1) * 3;
    prim = GFX.funcs.getPrim();
    if (!transform) {
        u16 clut;
        u16 tpage;
        u16 prevTpage;

        tpage = 0;
        prevTpage = 0;
        for (i = 0; i < count; i++) {
            part = &parts[p[0]];
            clut = getClut((part->mode ? SPRITE_DRAWER->altClutX : SPRITE_DRAWER->clutX) + part->clutX,
                           (part->mode ? SPRITE_DRAWER->altClutY : SPRITE_DRAWER->clutY) + part->clutY + frameRow +
                               SPRITE_DRAWER->clutRow);
            tpage = getTPage(part->mode, abr, SPRITE_DRAWER->tpageX + (part->mode ? part->u / 2 : part->u / 4),
                             SPRITE_DRAWER->tpageY);
            if (i == 0) {
                prevTpage = tpage;
            }
            if (prevTpage != tpage) {
                SetDrawTPage(prim, 0, 1, prevTpage);
                addPrim(SPRITE_DRAWER->ot, prim);
                prim = (DR_TPAGE *)prim + 1;
                prevTpage = tpage;
            }
            *(CVECTOR *)&((SPRT *)prim)->r0 = SPRITE_DRAWER->color;
            setSprt((SPRT *)prim);
            if (semi) {
                setSemiTrans((SPRT *)prim, 1);
            }
            ((SPRT *)prim)->x0 = p[1] + x - scroll.x;
            ((SPRT *)prim)->y0 = p[2] + y - scroll.y;
            if (part->mode) {
                ((SPRT *)prim)->u0 = part->u & 0x7F;
            } else {
                ((SPRT *)prim)->u0 = part->u;
            }
            ((SPRT *)prim)->v0 = part->v;
            ((SPRT *)prim)->w = part->w;
            ((SPRT *)prim)->h = part->h;
            ((SPRT *)prim)->clut = clut;
            addPrim(SPRITE_DRAWER->ot, prim);
            prim = (SPRT *)prim + 1;
            p -= 3;
        }
        SetDrawTPage(prim, 0, 1, tpage);
        addPrim(SPRITE_DRAWER->ot, prim);
        prim = (DR_TPAGE *)prim + 1;
    } else {
        u16 clut;
        u16 tpage;

        for (i = 0; i < count; i++) {
            part = &parts[p[0]];
            clut = getClut((part->mode ? SPRITE_DRAWER->altClutX : SPRITE_DRAWER->clutX) + part->clutX,
                           (part->mode ? SPRITE_DRAWER->altClutY : SPRITE_DRAWER->clutY) + part->clutY + frameRow +
                               SPRITE_DRAWER->clutRow);
            tpage = getTPage(part->mode, abr, SPRITE_DRAWER->tpageX + (part->mode ? part->u / 2 : part->u / 4),
                             SPRITE_DRAWER->tpageY);
            *(CVECTOR *)&((POLY_FT4 *)prim)->r0 = SPRITE_DRAWER->color;
            setPolyFT4((POLY_FT4 *)prim);
            if (semi) {
                setSemiTrans((POLY_FT4 *)prim, 1);
            }
            in[0].vx = in[2].vx = p[1] + x - SPRITE_DRAWER->pivotX;
            in[1].vx = in[3].vx = in[0].vx + part->w;
            in[0].vy = in[1].vy = p[2] + y - SPRITE_DRAWER->pivotY;
            in[2].vy = in[3].vy = in[0].vy + part->h;
            in[0].vz = in[1].vz = in[2].vz = in[3].vz = 0;
            for (k = 0; k < 4; k++) {
                ApplyMatrixSV(&SPRITE_DRAWER->matrix, &in[k], &out);
                (&((POLY_FT4 *)prim)->x0)[k * 4] = out.vx - scroll.x + SPRITE_DRAWER->pivotX;
                (&((POLY_FT4 *)prim)->y0)[k * 4] = out.vy - scroll.y + SPRITE_DRAWER->pivotY;
            }
            if (part->mode) {
                u = part->u & 0x7F;
            } else {
                u = part->u;
            }
            ((POLY_FT4 *)prim)->u0 = ((POLY_FT4 *)prim)->u2 = u;
            ((POLY_FT4 *)prim)->u1 = ((POLY_FT4 *)prim)->u3 = u + part->w - 1;
            v = part->v;
            ((POLY_FT4 *)prim)->v0 = ((POLY_FT4 *)prim)->v1 = v;
            ((POLY_FT4 *)prim)->v2 = ((POLY_FT4 *)prim)->v3 = v + part->h - 1;
            ((POLY_FT4 *)prim)->tpage = tpage;
            ((POLY_FT4 *)prim)->clut = clut;
            addPrim(SPRITE_DRAWER->ot, prim);
            prim = (POLY_FT4 *)prim + 1;
            p -= 3;
        }
    }
    GFX.funcs.setPrim(prim);
}

void spriteDrawerSetScale(s32 x, s32 y, s32 z) {
    SPRITE_DRAWER->scaleX = x;
    SPRITE_DRAWER->scaleY = y;
    SPRITE_DRAWER->scaleZ = z;
    SPRITE_DRAWER->transformDirty = 1;
}

void spriteDrawerSetRotation(s16 x, s16 y, s16 z) {
    SPRITE_DRAWER->rot.vx = x;
    SPRITE_DRAWER->rot.vy = y;
    SPRITE_DRAWER->rot.vz = z;
    SPRITE_DRAWER->transformDirty = 1;
}

void spriteDrawerSetPivot(s32 x, s32 y) {
    SPRITE_DRAWER->pivotX = x;
    SPRITE_DRAWER->pivotY = y;
}

void spriteDrawerSetFollowScroll(s32 on) {
    SPRITE_DRAWER->followScroll = on;
}

void spriteDrawerSetColor(CVECTOR *color) {
    SPRITE_DRAWER->color = *color;
}

void initSpriteDrawer(SpriteDrawer *obj) {
    HEAP.zero(obj, sizeof(SpriteDrawer));
    obj->scaleX = 0x1000;
    obj->scaleY = 0x1000;
    obj->scaleZ = 0x1000;
    obj->followScroll = 1;
    obj->color.b = 0x80;
    obj->color.g = 0x80;
    obj->color.r = 0x80;
    obj->setTexture = spriteDrawerSetTexture;
    obj->draw = spriteDrawerDraw;
    obj->setAltClut = spriteDrawerSetAltClut;
    obj->setLayerId = spriteDrawerSetLayerId;
    obj->setLayer = spriteDrawerSetLayer;
    obj->bind = bindSpriteDrawer;
    obj->setClutRow = spriteDrawerSetClutRow;
    obj->setScale = spriteDrawerSetScale;
    obj->setRotation = spriteDrawerSetRotation;
    obj->setPivot = spriteDrawerSetPivot;
    obj->setFollowScroll = spriteDrawerSetFollowScroll;
    obj->setColor = spriteDrawerSetColor;
    bindSpriteDrawer(obj);
}

void bindTextTools(TextTools *obj) {
    TEXT_TOOLS = obj;
}

char *getString(s32 *table, s32 index) {
    s32 count = table[0];

    if (index < 0 || count < index) {
        return NULL;
    }
    return (char *)table + table[index + 1];
}

s32 measureText(TextBuffer *text, TextStyle *style, s32 spacing) {
    s32 pos;
    s32 w;
    s32 max;
    s32 c;
    s32 op;
    s32 n;
    Glyph *g;
#if VERSION_US
    s32 len;
#endif

    if (text->data == NULL) {
        return 0;
    }
    pos = 0;
    w = 0;
    max = 0;
    while (pos < text->len) {
        c = ((s32 (*)())FONT.decode)(text->data + pos, (u8)text->sjis, style);
        switch (((u32)c >> 8) & 0xFF) {
        case 0:
            if ((s16)spacing != 0) {
                w += (s16)spacing;
            } else {
                w += ((Glyph *)style->glyphs)[(s16)c - 4].advance + ((Glyph *)style->glyphs)[(s16)c - 4].dx;
            }
            if (text->sjis != 0) {
                pos += 2;
            } else {
                pos += 1;
            }
            break;
        case 1:
            n = c & 0xFF;
            if (n <= style->iconCount && n > 0) {
                if ((s16)spacing != 0) {
                    w += (s16)spacing;
                } else {
                    w += ((Glyph *)style->icons)[n - 1].advance + ((Glyph *)style->icons)[n - 1].dx;
                }
            }
            pos += 2;
            break;
        case 2:
            op = text->data[pos + 1];
            switch (op) {
            case 1:
            case 3:
                if (max < w) {
                    max = w;
                }
                w = 0;
                break;
            case 5:
                w += measureText(&text[text->data[pos + 2]], style, (s16)spacing);
                break;
#if VERSION_US
            case 8:
                for (len = 0; (u8)GAME.name[len] != 0; len++) {
                }
                w += len * 11;
                break;
#endif
            }
            pos += FONT.codeLengths[op];
            break;
        case 3:
            if ((s16)spacing != 0) {
                w += (s16)spacing;
            } else {
                w += ((Glyph *)style->glyphs)->advance + ((Glyph *)style->glyphs)->dx;
            }
            if (text->sjis != 0) {
                pos += 2;
            } else {
                pos += 1;
            }
            break;
        case 4:
            if (max < w) {
                return w;
            }
            return max;
        }
    }
    if (max < w) {
        return w;
    }
    return max;
}

/* Swaps the bytes of a Shift-JIS code: the text has them big-endian */
#define SWAP16(x) ((((x) & 0xFF00) >> 8) | (((x) & 0xFF) << 8))

/*
 * Converts the string `text` to `buf`: mode 0 from font codes to Shift-JIS (a
 * code below 4 is followed by an icon's), mode 1 back. Not terminated.
 */
void convertText(void *buf, void *text, s32 mode) {
    u8 *dst = buf;
    u8 *src = text;
    s32 len;
    s32 i;
    s32 j;
    s32 n;
    s32 found;

    len = strlen(src);
    if (mode == 0) {
        n = 0;
        for (i = 0; i < len; i++) {
            if (src[i] >= 4) {
                for (j = 4; FONT_GLYPH_MAP[j].code != 0xFFFF; j++) {
                    if (FONT_GLYPH_MAP[j].index == src[i]) {
                        *(u16 *)&dst[n] = SWAP16(FONT_GLYPH_MAP[j].code);
                        n += 2;
                        break;
                    }
                }
            } else {
                for (j = 1; FONT_ICON_MAP[j].code != 0xFFFF; j++) {
                    if (FONT_ICON_MAP[j].index == src[i + 1]) {
                        *(u16 *)&dst[n] = SWAP16(FONT_ICON_MAP[j].code);
                        n += 2;
                        break;
                    }
                }
                i++;
            }
        }
    } else if (mode == 1) {
        len >>= 1;
        n = 0;
        for (i = 0; i < len; i++) {
            found = 0;
            for (j = 4; FONT_GLYPH_MAP[j].code != 0xFFFF; j++) {
                if (FONT_GLYPH_MAP[j].code == SWAP16(((s16 *)src)[i])) {
                    dst[n++] = FONT_GLYPH_MAP[j].index;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                for (j = 1; FONT_ICON_MAP[j].code != 0xFFFF; j++) {
                    if (FONT_ICON_MAP[j].code == SWAP16(((s16 *)src)[i])) {
                        dst[n++] = 1;
                        /* the glyph map's index, not the icon's */
                        dst[n++] = FONT_GLYPH_MAP[j].index;
                        break;
                    }
                }
            }
        }
    }
}

void initTextTools(TextTools *obj) {
    HEAP.zero(obj, sizeof(TextTools));
    obj->getString = getString;
    obj->measure = measureText;
    obj->convert = convertText;
    bindTextTools(obj);
}

void bindTimLoader(TimLoader *obj) {
    TIM_LOADER = obj;
}

void timLoaderSetImagePos(s32 x, s32 y) {
    TIM_LOADER->imageX = x;
    TIM_LOADER->imageY = y;
}

void timLoaderSetClutPos(s32 x, s32 y) {
    TIM_LOADER->clutX = x;
    TIM_LOADER->clutY = y;
}

void timLoaderLoad(u_long *tim) {
    RECT clut;
    RECT image;
    u_long *p = tim;
    s32 flag;
    s32 mode;
    s32 hasClut;

    p++;
    flag = *p++;
    hasClut = flag & 8;
    mode = flag & 7;
    if (hasClut) {
        switch (mode) {
        case 0:
        case 1:
            clut.x = TIM_LOADER->clutX;
            clut.y = TIM_LOADER->clutY;
            clut.w = ((u16 *)p)[4];
            clut.h = ((u16 *)p)[5];
            LoadImage(&clut, p + 3);
            break;
        }
        p = (u_long *)((u8 *)p + *p);
    }
    image.x = TIM_LOADER->imageX;
    image.y = TIM_LOADER->imageY;
    image.w = ((u16 *)p)[4];
    image.h = ((u16 *)p)[5];
    LoadImage(&image, p + 3);
    TIM_LOADER->w = image.w;
    TIM_LOADER->h = image.h;
}

void timLoaderLoadArchive(s32 archive) {
    u8 *buf = HEAP.alloc(TIM_LOADER->bufferSize, 2);
    s32 i;
    s32 compressed;
    u8 *data;
    u8 *src;
    u8 *dst;
    s32 c;
    s32 n;
    s32 k;

    for (i = 0;; i++) {
        data = FILE_CACHE.getArchiveEntry(i, archive);
        if (data == (u8 *)archive) {
            break;
        }
        src = data;
        compressed = *(u32 *)src == 0x4E454C52;
        dst = data;
        if (compressed) {
            dst = buf;
            src += 8;
            while ((c = *src) != 0) {
                if (c & 0x80) {
                    n = c & 0x7F;
                    src++;
                    for (k = 0; k < n; k++) {
                        *dst++ = *src;
                    }
                    src++;
                } else {
                    n = *src++;
                    for (k = 0; k < n; k++) {
                        *dst++ = *src++;
                    }
                }
            }
            dst = buf;
        }
        timLoaderLoad((u_long *)dst);
        DrawSync(0);
        TIM_LOADER->imageX += 0x40;
    }
    HEAP.free(buf);
}

void timLoaderSetBufferSize(s32 size) {
    TIM_LOADER->bufferSize = size;
}

void initTimLoader(TimLoader *obj) {
    HEAP.zero(obj, sizeof(TimLoader));
    obj->load = timLoaderLoad;
    obj->setClutPos = timLoaderSetClutPos;
    obj->setImagePos = timLoaderSetImagePos;
    obj->bind = bindTimLoader;
    obj->loadArchive = timLoaderLoadArchive;
    obj->setBufferSize = timLoaderSetBufferSize;
    bindTimLoader(obj);
    obj->bufferSize = 0xA800;
}

/* GFX: the graphics state and its methods (getPrim and setPrim, which keep the packet pointer as an
   int, cast to the pointers their callers see) */
GfxState GFX = {
    .funcs = {
        resetGraphics, allocPrimBuffers, (void *(*)(void))getPrim, (void (*)(void *))setPrim, freePrimBuffers,
        startVSyncCallback, drawFrame, createLayer, destroyLayer, setDisplayMode, setDisplayArea, getLayer,
        moveLayer, getFrameCount, getTime, getFrameTime,
    },
};

/* A layer's ordering table length, by its otShift - 1 */
s16 OT_LENGTHS[] = {
    0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000,
};

/* The card images, 64 cards to a file (cardDrawerSetCard) */
#if VERSION_US
s32 CARD_IMAGE_FILES[] = { 2023, 2024, 2025, 2026, 2027 };
#elif VERSION_EU
s32 CARD_IMAGE_FILES[] = { 2038, 2039, 2040, 2041, 2042 };
#endif

/* cardDrawerGetKind's kinds, by a card image's byte 3 */
s32 CARD_KINDS[] = { 0, 1, 1, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 0, 0 };

/* The font's Shift-JIS codes of its glyphs and icons, up to 0xFFFF */
GlyphMap FONT_GLYPH_MAP[] = {
    { 0x0000, 0 }, { 0x0001, 1 }, { 0x0002, 2 }, { 0x0003, 3 }, { 0x824F, 4 }, { 0x8250, 5 },
    { 0x8251, 6 }, { 0x8252, 7 }, { 0x8253, 8 }, { 0x8254, 9 }, { 0x8255, 10 }, { 0x8256, 11 },
    { 0x8257, 12 }, { 0x8258, 13 }, { 0x8260, 14 }, { 0x8261, 15 }, { 0x8262, 16 }, { 0x8263, 17 },
    { 0x8264, 18 }, { 0x8265, 19 }, { 0x8266, 20 }, { 0x8267, 21 }, { 0x8268, 22 }, { 0x8269, 23 },
    { 0x826A, 24 }, { 0x826B, 25 }, { 0x826C, 26 }, { 0x826D, 27 }, { 0x826E, 28 }, { 0x826F, 29 },
    { 0x8270, 30 }, { 0x8271, 31 }, { 0x8272, 32 }, { 0x8273, 33 }, { 0x8274, 34 }, { 0x8275, 35 },
    { 0x8276, 36 }, { 0x8277, 37 }, { 0x8278, 38 }, { 0x8279, 39 }, { 0x8281, 40 }, { 0x8282, 41 },
    { 0x8283, 42 }, { 0x8284, 43 }, { 0x8285, 44 }, { 0x8286, 45 }, { 0x8287, 46 }, { 0x8288, 47 },
    { 0x8289, 48 }, { 0x828A, 49 }, { 0x828B, 50 }, { 0x828C, 51 }, { 0x828D, 52 }, { 0x828E, 53 },
    { 0x828F, 54 }, { 0x8290, 55 }, { 0x8291, 56 }, { 0x8292, 57 }, { 0x8293, 58 }, { 0x8294, 59 },
    { 0x8295, 60 }, { 0x8296, 61 }, { 0x8297, 62 }, { 0x8298, 63 }, { 0x8299, 64 }, { 0x829A, 65 },
    { 0x829F, 66 }, { 0x82A0, 67 }, { 0x82A1, 68 }, { 0x82A2, 69 }, { 0x82A3, 70 }, { 0x82A4, 71 },
    { 0x82A5, 72 }, { 0x82A6, 73 }, { 0x82A7, 74 }, { 0x82A8, 75 }, { 0x82A9, 76 }, { 0x82AA, 77 },
    { 0x82AB, 78 }, { 0x82AC, 79 }, { 0x82AD, 80 }, { 0x82AE, 81 }, { 0x82AF, 82 }, { 0x82B0, 83 },
    { 0x82B1, 84 }, { 0x82B2, 85 }, { 0x82B3, 86 }, { 0x82B4, 87 }, { 0x82B5, 88 }, { 0x82B6, 89 },
    { 0x82B7, 90 }, { 0x82B8, 91 }, { 0x82B9, 92 }, { 0x82BA, 93 }, { 0x82BB, 94 }, { 0x82BC, 95 },
    { 0x82BD, 96 }, { 0x82BE, 97 }, { 0x82BF, 98 }, { 0x82C0, 99 }, { 0x82C1, 100 }, { 0x82C2, 101 },
    { 0x82C3, 102 }, { 0x82C4, 103 }, { 0x82C5, 104 }, { 0x82C6, 105 }, { 0x82C7, 106 }, { 0x82C8, 107 },
    { 0x82C9, 108 }, { 0x82CA, 109 }, { 0x82CB, 110 }, { 0x82CC, 111 }, { 0x82CD, 112 }, { 0x82CE, 113 },
    { 0x82CF, 114 }, { 0x82D0, 115 }, { 0x82D1, 116 }, { 0x82D2, 117 }, { 0x82D3, 118 }, { 0x82D4, 119 },
    { 0x82D5, 120 }, { 0x82D6, 121 }, { 0x82D7, 122 }, { 0x82D8, 123 }, { 0x82D9, 124 }, { 0x82DA, 125 },
    { 0x82DB, 126 }, { 0x82DC, 127 }, { 0x82DD, 128 }, { 0x82DE, 129 }, { 0x82DF, 130 }, { 0x82E0, 131 },
    { 0x82E1, 132 }, { 0x82E2, 133 }, { 0x82E3, 134 }, { 0x82E4, 135 }, { 0x82E5, 136 }, { 0x82E6, 137 },
    { 0x82E7, 138 }, { 0x82E8, 139 }, { 0x82E9, 140 }, { 0x82EA, 141 }, { 0x82EB, 142 }, { 0x82EC, 143 },
    { 0x82ED, 144 }, { 0x82F0, 145 }, { 0x82F1, 146 }, { 0x8340, 147 }, { 0x8341, 148 }, { 0x8342, 149 },
    { 0x8343, 150 }, { 0x8344, 151 }, { 0x8345, 152 }, { 0x8346, 153 }, { 0x8347, 154 }, { 0x8348, 155 },
    { 0x8349, 156 }, { 0x834A, 157 }, { 0x834B, 158 }, { 0x834C, 159 }, { 0x834D, 160 }, { 0x834E, 161 },
    { 0x834F, 162 }, { 0x8350, 163 }, { 0x8351, 164 }, { 0x8352, 165 }, { 0x8353, 166 }, { 0x8354, 167 },
    { 0x8355, 168 }, { 0x8356, 169 }, { 0x8357, 170 }, { 0x8358, 171 }, { 0x8359, 172 }, { 0x835A, 173 },
    { 0x835B, 174 }, { 0x835C, 175 }, { 0x835D, 176 }, { 0x835E, 177 }, { 0x835F, 178 }, { 0x8360, 179 },
    { 0x8361, 180 }, { 0x8362, 181 }, { 0x8363, 182 }, { 0x8364, 183 }, { 0x8365, 184 }, { 0x8366, 185 },
    { 0x8367, 186 }, { 0x8368, 187 }, { 0x8369, 188 }, { 0x836A, 189 }, { 0x836B, 190 }, { 0x836C, 191 },
    { 0x836D, 192 }, { 0x836E, 193 }, { 0x836F, 194 }, { 0x8370, 195 }, { 0x8371, 196 }, { 0x8372, 197 },
    { 0x8373, 198 }, { 0x8374, 199 }, { 0x8375, 200 }, { 0x8376, 201 }, { 0x8377, 202 }, { 0x8378, 203 },
    { 0x8379, 204 }, { 0x837A, 205 }, { 0x837B, 206 }, { 0x837C, 207 }, { 0x837D, 208 }, { 0x837E, 209 },
    { 0x8380, 210 }, { 0x8381, 211 }, { 0x8382, 212 }, { 0x8383, 213 }, { 0x8384, 214 }, { 0x8385, 215 },
    { 0x8386, 216 }, { 0x8387, 217 }, { 0x8388, 218 }, { 0x8389, 219 }, { 0x838A, 220 }, { 0x838B, 221 },
    { 0x838C, 222 }, { 0x838D, 223 }, { 0x838E, 224 }, { 0x838F, 225 }, { 0x8392, 226 }, { 0x8393, 227 },
    { 0x8394, 228 }, { 0x8145, 229 }, { 0x8148, 230 }, { 0x8149, 231 }, { 0x815B, 232 }, { 0x8160, 233 },
    { 0xFFFF, 0 },
};
GlyphMap FONT_ICON_MAP[] = {
    { 0x0000, 0 }, { 0x8140, 1 }, { 0x8141, 2 }, { 0x8142, 3 }, { 0x8143, 4 }, { 0x8144, 5 },
    { 0x8145, 6 }, { 0x8146, 7 }, { 0x8147, 8 }, { 0x8148, 9 }, { 0x8149, 10 }, { 0x814F, 11 },
    { 0x8151, 12 }, { 0x815B, 13 }, { 0x815C, 14 }, { 0x815E, 15 }, { 0x815F, 16 }, { 0x8160, 17 },
    { 0x8163, 18 }, { 0x8166, 19 }, { 0x8168, 20 }, { 0x8169, 21 }, { 0x816A, 22 }, { 0x8175, 23 },
    { 0x8176, 24 }, { 0x817B, 25 }, { 0x817C, 26 }, { 0x817E, 27 }, { 0x8181, 28 }, { 0x8183, 29 },
    { 0x8184, 30 }, { 0x8185, 31 }, { 0x8186, 32 }, { 0x8187, 33 }, { 0x8188, 34 }, { 0x8189, 35 },
    { 0x818A, 36 }, { 0x818E, 37 }, { 0x818F, 38 }, { 0x8190, 39 }, { 0x8191, 40 }, { 0x8192, 41 },
    { 0x8193, 42 }, { 0x8195, 43 }, { 0x8198, 44 }, { 0x8199, 45 }, { 0x819A, 46 }, { 0x819B, 47 },
    { 0x819C, 48 }, { 0x819F, 49 }, { 0x81A0, 50 }, { 0x81A1, 51 }, { 0x81A2, 52 }, { 0x81A3, 53 },
    { 0x81A5, 54 }, { 0x81A8, 55 }, { 0x81A9, 56 }, { 0x81AA, 57 }, { 0x81AB, 58 }, { 0x889F, 59 },
    { 0x88A0, 60 }, { 0x88A1, 61 }, { 0x88A2, 62 }, { 0x88A3, 63 }, { 0x88A4, 64 }, { 0x88A5, 65 },
    { 0x88A6, 66 }, { 0x88A7, 67 }, { 0x88A8, 68 }, { 0x88A9, 69 }, { 0x88AA, 70 }, { 0x88AB, 71 },
    { 0x88AC, 72 }, { 0x88AD, 73 }, { 0x88AE, 74 }, { 0x88AF, 75 }, { 0x88B0, 76 }, { 0x88B1, 77 },
    { 0x88B2, 78 }, { 0x88B3, 79 }, { 0x88B4, 80 }, { 0x88B5, 81 }, { 0x88B6, 82 }, { 0x88B7, 83 },
    { 0x88B8, 84 }, { 0x88B9, 85 }, { 0x88BA, 86 }, { 0x88BB, 87 }, { 0x88BC, 88 }, { 0x88BD, 89 },
    { 0x88BE, 90 }, { 0x88BF, 91 }, { 0x88C0, 92 }, { 0x88C1, 93 }, { 0x88C2, 94 }, { 0x88C3, 95 },
    { 0x88C4, 96 }, { 0x88C5, 97 }, { 0x88C6, 98 }, { 0x88C7, 99 }, { 0x88C8, 100 }, { 0x88C9, 101 },
    { 0x88CA, 102 }, { 0x88CB, 103 }, { 0x88CC, 104 }, { 0x88CD, 105 }, { 0x88CE, 106 }, { 0x88CF, 107 },
    { 0x88D0, 108 }, { 0x88D1, 109 }, { 0x88D2, 110 }, { 0x88D3, 111 }, { 0x88D4, 112 }, { 0x88D5, 113 },
    { 0x88D6, 114 }, { 0xFFFF, 0 },
};

/* Two empty glyphs that nothing reads */
Glyph FONT_UNUSED_GLYPH_0 = { 0xFF };
Glyph FONT_UNUSED_GLYPH_1 = { 0xFF };

/* The font's three sheets (FONT_STYLES), each with its glyphs and its icons */
Glyph FONT_GLYPHS_1[230] = {
#if VERSION_US
    { 1, 96, 18, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 104, 18, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 112, 18, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 120, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 128, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 136, 21, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 144, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 152, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 160, 21, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 168, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 176, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 184, 21, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 192, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 200, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 208, 21, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 216, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 224, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 232, 21, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 32, 63, 48, 232, 4, 12, 1, 0, 3, 12 }, { 1, 240, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 0, 30, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 8, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 16, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 24, 30, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 32, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 40, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 48, 30, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 56, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 64, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 72, 30, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 80, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 88, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 96, 30, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 104, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 112, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 120, 33, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 128, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 136, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 144, 33, 48, 232, 8, 12, 1, 0, 5, 12 },
    { 1, 152, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 160, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 168, 33, 48, 232, 8, 12, 1, 0, 5, 12 },
    { 1, 176, 33, 48, 232, 8, 12, 1, 1, 6, 12 }, { 1, 184, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 36, 63, 48, 232, 4, 12, 1, 0, 2, 12 },
    { 1, 40, 63, 48, 232, 4, 12, 1, 1, 4, 12 }, { 1, 192, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 44, 63, 48, 232, 4, 12, 1, 0, 3, 12 },
    { 1, 200, 33, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 208, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 216, 33, 48, 232, 8, 12, 1, 0, 5, 12 },
    { 1, 224, 33, 48, 232, 8, 12, 1, 1, 5, 12 }, { 1, 232, 33, 48, 232, 8, 12, 1, 1, 5, 12 }, { 1, 48, 63, 48, 232, 4, 12, 1, 0, 4, 12 },
    { 1, 240, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 52, 63, 48, 232, 4, 12, 1, 0, 4, 12 }, { 1, 0, 42, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 8, 42, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 16, 42, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 24, 42, 48, 232, 8, 12, 1, 0, 5, 12 },
    { 1, 32, 42, 48, 232, 8, 12, 1, 1, 5, 12 }, { 1, 40, 42, 48, 232, 8, 12, 1, 0, 5, 12 }, { 0, 216, 74, 48, 232, 12, 12, 2, 0, 8, 12 },
    { 0, 228, 74, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 240, 74, 48, 232, 12, 12, 2, 0, 8, 12 }, { 0, 0, 76, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 12, 76, 48, 232, 12, 12, 2, 0, 6, 12 }, { 0, 24, 76, 48, 232, 12, 12, 1, 0, 7, 12 }, { 0, 36, 76, 48, 232, 12, 12, 2, 0, 8, 12 },
    { 0, 48, 76, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 60, 76, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 156, 77, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 168, 77, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 72, 78, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 84, 84, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 96, 84, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 108, 84, 48, 232, 12, 12, 2, 0, 6, 12 }, { 0, 120, 84, 48, 232, 12, 12, 2, 0, 8, 12 },
    { 0, 132, 86, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 144, 86, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 180, 86, 48, 232, 12, 12, 1, 0, 8, 12 },
    { 0, 192, 86, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 204, 86, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 216, 86, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 228, 86, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 240, 86, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 0, 88, 48, 232, 12, 12, 1, 0, 8, 12 },
    { 0, 12, 88, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 24, 88, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 36, 88, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 48, 88, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 60, 88, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 156, 89, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 168, 89, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 72, 90, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 84, 96, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 96, 96, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 108, 96, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 120, 96, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 132, 98, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 144, 98, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 180, 98, 48, 232, 12, 12, 1, 0, 8, 12 },
    { 0, 192, 98, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 204, 98, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 216, 98, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 228, 98, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 240, 98, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 0, 100, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 12, 100, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 24, 100, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 36, 100, 48, 232, 12, 12, 1, 0, 11, 12 },
    { 0, 48, 100, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 60, 100, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 156, 101, 48, 232, 12, 12, 1, 0, 10, 9 },
    { 0, 168, 101, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 72, 102, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 84, 108, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 96, 108, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 108, 108, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 120, 108, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 132, 110, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 144, 110, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 180, 110, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 192, 110, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 204, 110, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 216, 110, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 228, 110, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 240, 110, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 0, 112, 48, 232, 12, 12, 2, 0, 8, 12 },
    { 0, 12, 112, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 24, 112, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 36, 112, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 48, 112, 48, 232, 12, 12, 2, 0, 8, 12 }, { 0, 60, 112, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 156, 113, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 168, 113, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 72, 114, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 84, 120, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 96, 120, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 108, 120, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 120, 120, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 132, 122, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 144, 122, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 180, 122, 48, 232, 12, 12, 2, 0, 8, 12 },
    { 0, 192, 122, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 204, 122, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 216, 122, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 228, 122, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 240, 122, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 0, 124, 48, 232, 12, 12, 2, 0, 7, 12 },
    { 0, 12, 124, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 24, 124, 48, 232, 12, 12, 2, 0, 8, 12 }, { 0, 36, 124, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 48, 124, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 60, 124, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 156, 125, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 168, 125, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 72, 126, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 84, 132, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 96, 132, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 108, 132, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 120, 132, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 132, 134, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 144, 134, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 180, 134, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 1, 116, 176, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 156, 176, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 128, 179, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 1, 140, 179, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 232, 83, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 0, 136, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 12, 136, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 24, 136, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 36, 136, 48, 232, 12, 12, 1, 0, 8, 12 },
    { 0, 48, 136, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 60, 136, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 156, 137, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 168, 137, 48, 232, 12, 12, 1, 0, 7, 12 }, { 0, 72, 138, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 84, 144, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 96, 144, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 108, 144, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 48, 42, 48, 232, 8, 12, 2, 0, 5, 12 },
    { 1, 56, 42, 48, 232, 8, 12, 2, 0, 6, 12 }, { 0, 120, 144, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 132, 146, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 144, 146, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 180, 146, 48, 232, 12, 12, 1, 0, 9, 12 }, { 1, 0, 84, 48, 232, 12, 12, 1, 0, 7, 12 },
    { 1, 12, 84, 48, 232, 12, 12, 1, 0, 9, 12 }, { 1, 204, 84, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 64, 160, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 1, 216, 84, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 0, 148, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 12, 148, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 24, 148, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 36, 148, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 48, 148, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 60, 148, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 156, 149, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 168, 149, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 72, 150, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 84, 156, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 96, 156, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 108, 156, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 120, 156, 48, 232, 12, 12, 1, 0, 7, 12 }, { 0, 132, 158, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 144, 158, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 180, 158, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 88, 69, 48, 232, 12, 12, 2, 0, 7, 12 },
    { 1, 100, 69, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 112, 71, 48, 232, 12, 12, 2, 0, 8, 12 }, { 1, 124, 71, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 1, 136, 71, 48, 232, 12, 12, 2, 0, 6, 12 }, { 0, 0, 160, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 12, 160, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 24, 160, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 36, 160, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 48, 160, 48, 232, 12, 12, 1, 0, 8, 12 },
    { 0, 60, 160, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 156, 161, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 168, 161, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 72, 162, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 84, 168, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 96, 168, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 1, 136, 9, 48, 232, 8, 12, 0, 0, 7, 12 }, { 1, 160, 9, 48, 232, 8, 12, 1, 0, 7, 12 }, { 0, 248, 56, 48, 232, 4, 12, 1, 0, 4, 12 },
    { 1, 176, 9, 48, 232, 8, 12, 2, 0, 5, 12 }, { 0, 96, 60, 48, 232, 12, 12, 1, 0, 6, 12 },
#elif VERSION_EU
    { 1, 96, 18, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 104, 18, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 112, 18, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 120, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 128, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 136, 21, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 144, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 152, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 160, 21, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 168, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 176, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 184, 21, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 192, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 200, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 208, 21, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 216, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 224, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 232, 21, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 32, 63, 48, 232, 4, 12, 1, 0, 3, 12 }, { 1, 240, 21, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 0, 30, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 8, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 16, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 24, 30, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 32, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 40, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 48, 30, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 56, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 64, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 72, 30, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 80, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 88, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 96, 30, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 104, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 112, 30, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 120, 33, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 128, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 136, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 144, 33, 48, 232, 8, 12, 1, 0, 5, 12 },
    { 1, 152, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 160, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 168, 33, 48, 232, 8, 12, 1, 0, 5, 12 },
    { 1, 176, 33, 48, 232, 8, 12, 1, 1, 6, 12 }, { 1, 184, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 36, 63, 48, 232, 4, 12, 1, 0, 2, 12 },
    { 1, 124, 185, 48, 232, 4, 12, 1, 1, 4, 12 }, { 1, 192, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 0, 248, 62, 48, 232, 4, 12, 1, 0, 3, 12 },
    { 1, 200, 33, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 208, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 216, 33, 48, 232, 8, 12, 1, 0, 5, 12 },
    { 1, 224, 33, 48, 232, 8, 12, 1, 1, 5, 12 }, { 1, 232, 33, 48, 232, 8, 12, 1, 1, 5, 12 }, { 1, 212, 120, 48, 232, 4, 12, 1, 0, 4, 12 },
    { 1, 240, 33, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 204, 71, 48, 232, 4, 12, 1, 0, 4, 12 }, { 1, 0, 42, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 8, 42, 48, 232, 8, 12, 1, 0, 5, 12 }, { 1, 16, 42, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 24, 42, 48, 232, 8, 12, 1, 0, 5, 12 },
    { 1, 32, 42, 48, 232, 8, 12, 1, 1, 5, 12 }, { 1, 40, 42, 48, 232, 8, 12, 1, 0, 5, 12 }, { 0, 216, 74, 48, 232, 12, 12, 2, 0, 8, 12 },
    { 0, 228, 74, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 240, 74, 48, 232, 12, 12, 2, 0, 8, 12 }, { 0, 0, 76, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 12, 76, 48, 232, 12, 12, 2, 0, 6, 12 }, { 0, 24, 76, 48, 232, 12, 12, 1, 0, 7, 12 }, { 0, 36, 76, 48, 232, 12, 12, 2, 0, 8, 12 },
    { 0, 48, 76, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 60, 76, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 156, 77, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 168, 77, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 72, 78, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 84, 84, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 96, 84, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 108, 84, 48, 232, 12, 12, 2, 0, 6, 12 }, { 0, 120, 84, 48, 232, 12, 12, 2, 0, 8, 12 },
    { 0, 132, 84, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 144, 86, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 180, 86, 48, 232, 12, 12, 1, 0, 8, 12 },
    { 0, 192, 86, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 204, 86, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 216, 86, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 228, 86, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 240, 86, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 0, 88, 48, 232, 12, 12, 1, 0, 8, 12 },
    { 0, 12, 88, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 24, 88, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 36, 88, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 48, 88, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 60, 88, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 156, 89, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 168, 89, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 72, 90, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 84, 96, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 96, 96, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 108, 96, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 120, 96, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 132, 96, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 144, 98, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 180, 98, 48, 232, 12, 12, 1, 0, 8, 12 },
    { 0, 192, 98, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 204, 98, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 216, 98, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 228, 98, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 240, 98, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 0, 100, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 12, 100, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 24, 100, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 36, 100, 48, 232, 12, 12, 1, 0, 11, 12 },
    { 0, 48, 100, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 60, 100, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 156, 101, 48, 232, 12, 12, 1, 0, 10, 9 },
    { 0, 168, 101, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 72, 102, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 84, 108, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 96, 108, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 108, 108, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 120, 108, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 132, 108, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 144, 110, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 180, 110, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 192, 110, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 204, 110, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 216, 110, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 228, 110, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 240, 110, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 0, 112, 48, 232, 12, 12, 2, 0, 8, 12 },
    { 0, 12, 112, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 24, 112, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 36, 112, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 48, 112, 48, 232, 12, 12, 2, 0, 8, 12 }, { 0, 60, 112, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 156, 113, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 168, 113, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 72, 114, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 84, 120, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 96, 120, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 108, 120, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 120, 120, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 132, 120, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 144, 122, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 180, 122, 48, 232, 12, 12, 2, 0, 8, 12 },
    { 0, 192, 122, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 204, 122, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 216, 122, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 228, 122, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 240, 122, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 0, 124, 48, 232, 12, 12, 2, 0, 7, 12 },
    { 0, 12, 124, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 24, 124, 48, 232, 12, 12, 2, 0, 8, 12 }, { 0, 36, 124, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 48, 124, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 60, 124, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 156, 125, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 168, 125, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 72, 126, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 84, 132, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 96, 132, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 108, 132, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 120, 132, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 132, 132, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 144, 134, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 180, 134, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 1, 88, 201, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 184, 83, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 220, 83, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 1, 208, 83, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 232, 83, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 0, 136, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 12, 136, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 24, 136, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 36, 136, 48, 232, 12, 12, 1, 0, 8, 12 },
    { 0, 48, 136, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 60, 136, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 156, 137, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 168, 137, 48, 232, 12, 12, 1, 0, 7, 12 }, { 0, 72, 138, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 84, 144, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 96, 144, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 108, 144, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 48, 42, 48, 232, 8, 12, 2, 0, 5, 12 },
    { 1, 56, 42, 48, 232, 8, 12, 2, 0, 6, 12 }, { 0, 120, 144, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 132, 144, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 144, 146, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 180, 146, 48, 232, 12, 12, 1, 0, 9, 12 }, { 1, 0, 87, 48, 232, 12, 12, 1, 0, 7, 12 },
    { 1, 12, 87, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 180, 170, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 88, 230, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 1, 208, 71, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 0, 148, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 12, 148, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 24, 148, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 36, 148, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 48, 148, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 60, 148, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 156, 149, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 168, 149, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 72, 150, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 84, 156, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 96, 156, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 108, 156, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 120, 156, 48, 232, 12, 12, 1, 0, 7, 12 }, { 0, 132, 156, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 0, 144, 158, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 180, 158, 48, 232, 12, 12, 1, 0, 10, 12 }, { 1, 196, 83, 48, 232, 12, 12, 2, 0, 7, 12 },
    { 1, 88, 242, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 24, 243, 48, 232, 12, 12, 2, 0, 8, 12 }, { 0, 36, 243, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 1, 212, 193, 48, 232, 12, 12, 2, 0, 6, 12 }, { 0, 0, 160, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 12, 160, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 24, 160, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 36, 160, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 48, 160, 48, 232, 12, 12, 1, 0, 8, 12 },
    { 0, 60, 160, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 156, 161, 48, 232, 12, 12, 2, 0, 7, 12 }, { 0, 168, 161, 48, 232, 12, 12, 1, 0, 9, 12 },
    { 0, 72, 162, 48, 232, 12, 12, 1, 0, 8, 12 }, { 0, 84, 168, 48, 232, 12, 12, 1, 0, 9, 12 }, { 0, 96, 168, 48, 232, 12, 12, 1, 0, 10, 12 },
    { 1, 136, 9, 48, 232, 8, 12, 0, 0, 7, 12 }, { 1, 160, 9, 48, 232, 8, 12, 1, 0, 7, 12 }, { 1, 200, 156, 48, 232, 4, 12, 1, 0, 4, 12 },
    { 1, 176, 9, 48, 232, 8, 12, 2, 0, 5, 12 }, { 0, 96, 60, 48, 232, 12, 12, 1, 0, 6, 12 },
#endif
};
Glyph FONT_ICONS_1[114] = {
#if VERSION_US
    { 0, 244, 20, 48, 232, 8, 12, 0, 0, 6, 12 }, { 0, 244, 32, 48, 232, 8, 12, 0, 0, 7, 12 }, { 0, 244, 44, 48, 232, 8, 12, 0, 0, 7, 12 },
    { 1, 120, 9, 48, 232, 8, 12, 0, 1, 7, 12 }, { 1, 128, 9, 48, 232, 8, 12, 0, 0, 7, 12 }, { 1, 136, 9, 48, 232, 8, 12, 0, 0, 7, 12 },
    { 1, 144, 9, 48, 232, 8, 12, 0, 0, 7, 12 }, { 1, 152, 9, 48, 232, 8, 12, 0, 1, 7, 12 }, { 1, 160, 9, 48, 232, 8, 12, 1, 0, 7, 12 },
    { 0, 248, 56, 48, 232, 4, 12, 1, 0, 4, 12 }, { 1, 248, 9, 48, 232, 4, 12, 1, 0, 4, 12 }, { 1, 168, 9, 48, 232, 8, 12, 2, 0, 7, 12 },
    { 1, 176, 9, 48, 232, 8, 12, 2, 0, 5, 12 }, { 1, 184, 9, 48, 232, 8, 12, 2, 0, 5, 12 }, { 1, 192, 9, 48, 232, 8, 12, 2, 0, 6, 12 },
    { 1, 200, 9, 48, 232, 8, 12, 2, 0, 6, 12 }, { 0, 96, 60, 48, 232, 12, 12, 1, 0, 6, 12 }, { 0, 108, 60, 48, 232, 12, 12, 1, 0, 12, 12 },
    { 1, 204, 129, 48, 232, 8, 12, 1, 0, 7, 12 }, { 1, 208, 9, 48, 232, 8, 12, 2, 0, 4, 12 }, { 1, 248, 21, 48, 232, 4, 12, 1, 0, 4, 12 },
    { 1, 248, 33, 48, 232, 4, 12, 1, 0, 4, 12 }, { 1, 248, 45, 48, 232, 4, 12, 1, 0, 4, 12 }, { 1, 248, 57, 48, 232, 4, 12, 1, 0, 4, 12 },
    { 1, 216, 9, 48, 232, 8, 12, 1, 0, 8, 12 }, { 1, 224, 9, 48, 232, 8, 12, 2, 0, 5, 12 }, { 1, 232, 9, 48, 232, 8, 12, 1, 0, 7, 12 },
    { 1, 240, 9, 48, 232, 8, 12, 1, 0, 7, 12 }, { 1, 0, 18, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 8, 18, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 16, 18, 48, 232, 8, 12, 0, 0, 7, 12 }, { 1, 24, 18, 48, 232, 8, 12, 0, 0, 7, 12 }, { 1, 32, 18, 48, 232, 8, 12, 0, 0, 7, 12 },
    { 1, 40, 18, 48, 232, 8, 12, 0, 0, 7, 12 }, { 0, 120, 60, 48, 232, 12, 12, 1, 0, 12, 12 }, { 0, 236, 62, 48, 232, 12, 12, 1, 0, 12, 12 },
    { 0, 144, 62, 48, 161, 12, 12, 1, 0, 12, 12 }, { 0, 188, 62, 48, 160, 12, 12, 1, 0, 12, 12 }, { 0, 200, 62, 48, 159, 12, 12, 1, 0, 12, 12 },
    { 0, 212, 62, 48, 158, 12, 12, 1, 0, 12, 12 }, { 0, 224, 62, 48, 157, 12, 12, 1, 0, 12, 12 }, { 1, 48, 18, 48, 232, 8, 12, 1, 0, 12, 12 },
    { 1, 56, 18, 48, 232, 8, 12, 1, 0, 8, 12 }, { 0, 156, 65, 48, 156, 12, 12, 1, 0, 12, 12 }, { 0, 168, 65, 48, 155, 12, 12, 1, 0, 12, 12 },
    { 0, 84, 72, 48, 154, 12, 12, 1, 0, 12, 12 }, { 0, 96, 72, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 108, 72, 48, 153, 12, 12, 1, 0, 12, 12 },
    { 0, 120, 72, 48, 152, 12, 12, 1, 0, 12, 12 }, { 0, 132, 74, 48, 232, 12, 12, 1, 0, 10, 12 }, { 0, 144, 74, 48, 151, 12, 12, 1, 0, 12, 12 },
    { 0, 180, 74, 48, 232, 12, 12, 1, 0, 11, 12 }, { 0, 192, 74, 48, 150, 12, 12, 1, 0, 12, 12 }, { 0, 204, 74, 48, 149, 12, 12, 1, 0, 12, 12 },
    { 1, 64, 18, 48, 232, 8, 12, 1, 0, 7, 12 }, { 1, 72, 18, 48, 232, 8, 12, 1, 0, 7, 12 }, { 1, 80, 18, 48, 232, 8, 12, 1, 0, 8, 12 },
    { 1, 88, 18, 48, 232, 8, 12, 1, 0, 8, 12 }, { 0, 140, 62, 48, 232, 4, 12, 0, 0, 4, 12 }, { 0, 132, 60, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 0, 108, 168, 48, 232, 8, 12, 0, 0, 5, 12 }, { 0, 116, 168, 48, 232, 8, 12, 0, 0, 6, 12 }, { 0, 124, 168, 48, 232, 8, 12, 0, 0, 7, 12 },
    { 0, 132, 170, 48, 232, 8, 12, 0, 0, 6, 12 }, { 0, 140, 170, 48, 232, 8, 12, 0, 0, 6, 12 }, { 0, 148, 170, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 0, 180, 170, 48, 232, 8, 12, 0, 0, 6, 12 }, { 0, 0, 172, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 192, 132, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 212, 133, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 220, 133, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 228, 133, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 172, 135, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 180, 135, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 128, 139, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 136, 139, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 144, 139, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 152, 139, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 160, 139, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 200, 141, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 56, 166, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 64, 172, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 72, 175, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 80, 175, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 80, 187, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 152, 188, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 160, 188, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 136, 191, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 144, 191, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 104, 193, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 204, 195, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 212, 195, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 220, 195, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 228, 195, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 236, 195, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 168, 197, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 176, 197, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 184, 197, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 192, 197, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 244, 197, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 80, 199, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 152, 200, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 160, 200, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 88, 201, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 96, 201, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 136, 203, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 144, 203, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 104, 205, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 200, 207, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 208, 207, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 216, 207, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 224, 207, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 232, 207, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 168, 209, 48, 232, 8, 12, 0, 0, 5, 12 },
#elif VERSION_EU
    { 0, 132, 60, 48, 232, 8, 12, 0, 0, 6, 12 }, { 0, 244, 32, 48, 232, 8, 12, 0, 0, 7, 12 }, { 0, 244, 44, 48, 232, 8, 12, 0, 0, 7, 12 },
    { 1, 120, 9, 48, 232, 8, 12, 0, 1, 7, 12 }, { 1, 128, 9, 48, 232, 8, 12, 0, 0, 7, 12 }, { 1, 136, 9, 48, 232, 8, 12, 0, 0, 7, 12 },
    { 1, 144, 9, 48, 232, 8, 12, 0, 0, 7, 12 }, { 1, 152, 9, 48, 232, 8, 12, 0, 1, 7, 12 }, { 1, 160, 9, 48, 232, 8, 12, 1, 0, 7, 12 },
    { 1, 200, 156, 48, 232, 4, 12, 1, 0, 4, 12 }, { 1, 60, 84, 48, 232, 4, 12, 1, 0, 4, 12 }, { 1, 168, 9, 48, 232, 8, 12, 2, 0, 7, 12 },
    { 1, 176, 9, 48, 232, 8, 12, 2, 0, 5, 12 }, { 1, 184, 9, 48, 232, 8, 12, 2, 0, 5, 12 }, { 1, 192, 9, 48, 232, 8, 12, 2, 0, 6, 12 },
    { 1, 200, 9, 48, 232, 8, 12, 2, 0, 6, 12 }, { 0, 96, 60, 48, 232, 12, 12, 1, 0, 6, 12 }, { 0, 108, 60, 48, 232, 12, 12, 1, 0, 12, 12 },
    { 1, 164, 205, 48, 232, 8, 12, 1, 0, 7, 12 }, { 1, 208, 9, 48, 232, 8, 12, 2, 0, 4, 12 }, { 1, 120, 83, 48, 232, 4, 12, 1, 0, 4, 12 },
    { 1, 248, 168, 48, 232, 4, 12, 1, 0, 4, 12 }, { 1, 28, 153, 48, 232, 4, 12, 1, 0, 4, 12 }, { 1, 28, 141, 48, 232, 4, 12, 1, 0, 4, 12 },
    { 1, 216, 9, 48, 232, 8, 12, 1, 0, 8, 12 }, { 1, 224, 9, 48, 232, 8, 12, 2, 0, 5, 12 }, { 1, 232, 9, 48, 224, 12, 12, 1, 0, 11, 12 },
    { 1, 8, 242, 48, 232, 8, 12, 1, 0, 7, 12 }, { 1, 0, 18, 48, 232, 8, 12, 1, 0, 6, 12 }, { 1, 8, 18, 48, 232, 8, 12, 1, 0, 6, 12 },
    { 1, 16, 18, 48, 232, 8, 12, 0, 0, 7, 12 }, { 1, 24, 18, 48, 232, 8, 12, 0, 0, 7, 12 }, { 1, 32, 18, 48, 232, 8, 12, 0, 0, 7, 12 },
    { 1, 40, 18, 48, 232, 8, 12, 0, 0, 7, 12 }, { 0, 120, 60, 48, 232, 12, 12, 1, 0, 12, 12 }, { 0, 236, 62, 48, 232, 12, 12, 1, 0, 12, 12 },
    { 0, 144, 62, 48, 153, 12, 12, 1, 0, 12, 12 }, { 0, 188, 62, 48, 152, 12, 12, 1, 0, 12, 12 }, { 0, 200, 62, 48, 151, 12, 12, 1, 0, 12, 12 },
    { 0, 212, 62, 48, 150, 12, 12, 1, 0, 12, 12 }, { 0, 224, 62, 48, 149, 12, 12, 1, 0, 12, 12 }, { 1, 48, 18, 48, 232, 8, 12, 1, 0, 12, 12 },
    { 1, 56, 18, 48, 232, 8, 12, 1, 0, 8, 12 }, { 0, 156, 65, 48, 148, 12, 12, 1, 0, 12, 12 }, { 0, 168, 65, 48, 147, 12, 12, 1, 0, 12, 12 },
    { 0, 84, 72, 48, 146, 12, 12, 1, 0, 12, 12 }, { 0, 96, 72, 48, 224, 12, 12, 1, 0, 11, 12 }, { 0, 108, 72, 48, 145, 12, 12, 1, 0, 12, 12 },
    { 0, 120, 72, 48, 144, 12, 12, 1, 0, 12, 12 }, { 0, 132, 72, 48, 224, 12, 12, 1, 0, 11, 12 }, { 0, 144, 74, 48, 143, 12, 12, 1, 0, 12, 12 },
    { 0, 180, 74, 48, 224, 12, 12, 1, 0, 11, 12 }, { 0, 192, 74, 48, 142, 12, 12, 1, 0, 12, 12 }, { 0, 204, 74, 48, 141, 12, 12, 1, 0, 12, 12 },
    { 1, 64, 18, 48, 232, 8, 12, 1, 0, 7, 12 }, { 1, 72, 18, 48, 232, 8, 12, 1, 0, 7, 12 }, { 1, 80, 18, 48, 232, 8, 12, 1, 0, 8, 12 },
    { 1, 88, 18, 48, 232, 8, 12, 1, 0, 8, 12 }, { 1, 200, 135, 48, 232, 4, 12, 0, 0, 4, 12 }, { 0, 56, 243, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 0, 108, 168, 48, 232, 8, 12, 0, 0, 5, 12 }, { 0, 116, 168, 48, 232, 8, 12, 0, 0, 6, 12 }, { 0, 124, 168, 48, 232, 8, 12, 0, 0, 7, 12 },
    { 0, 244, 20, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 40, 63, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 188, 205, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 244, 9, 48, 232, 8, 12, 0, 0, 6, 12 }, { 0, 0, 172, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 156, 201, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 128, 181, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 172, 205, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 196, 205, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 148, 201, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 196, 193, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 120, 241, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 0, 16, 172, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 120, 217, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 192, 156, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 0, 242, 48, 232, 8, 12, 0, 0, 6, 12 }, { 0, 64, 243, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 56, 166, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 180, 193, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 64, 175, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 80, 168, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 80, 180, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 56, 63, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 164, 151, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 16, 63, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 8, 63, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 72, 175, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 128, 193, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 164, 163, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 204, 205, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 192, 135, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 164, 139, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 16, 242, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 164, 193, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 180, 205, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 48, 63, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 120, 229, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 80, 192, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 120, 205, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 204, 193, 48, 232, 8, 12, 0, 0, 5, 12 }, { 1, 80, 234, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 80, 222, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 0, 63, 48, 232, 8, 12, 0, 0, 5, 12 }, { 0, 8, 172, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 24, 63, 48, 232, 8, 12, 0, 0, 6, 12 },
    { 1, 172, 193, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 188, 193, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 24, 242, 48, 232, 8, 12, 0, 0, 5, 12 },
    { 1, 204, 156, 48, 232, 8, 12, 0, 0, 6, 12 }, { 1, 204, 135, 48, 232, 8, 12, 0, 0, 6, 12 }, { 0, 48, 243, 48, 232, 8, 12, 0, 0, 5, 12 },
#endif
};
Glyph FONT_GLYPHS_2[230] = {
#if VERSION_US
    { 1, 88, 42, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 96, 42, 48, 224, 8, 9, 1, 0, 4, 10 }, { 1, 104, 42, 48, 224, 8, 9, 1, 0, 6, 10 },
    { 1, 112, 42, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 120, 45, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 128, 45, 48, 224, 8, 9, 1, 0, 6, 10 },
    { 1, 136, 45, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 144, 45, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 152, 45, 48, 224, 8, 9, 1, 0, 6, 10 },
    { 1, 160, 45, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 168, 45, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 176, 45, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 184, 45, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 192, 45, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 200, 45, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 208, 45, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 216, 45, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 224, 45, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 232, 45, 48, 224, 8, 9, 1, 0, 4, 10 }, { 1, 240, 45, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 64, 51, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 72, 51, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 80, 51, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 88, 51, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 96, 51, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 104, 51, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 112, 51, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 0, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 8, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 16, 54, 48, 224, 8, 9, 1, 0, 6, 10 },
    { 1, 24, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 32, 54, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 40, 54, 48, 224, 8, 9, 1, 0, 6, 10 },
    { 1, 48, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 56, 54, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 120, 54, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 128, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 136, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 144, 54, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 152, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 160, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 168, 54, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 176, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 184, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 192, 54, 48, 224, 8, 9, 0, 0, 3, 10 },
    { 1, 200, 54, 48, 224, 8, 9, 1, 1, 4, 10 }, { 1, 208, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 216, 54, 48, 224, 8, 9, 0, 0, 3, 10 },
    { 1, 224, 54, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 232, 54, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 240, 54, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 64, 60, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 72, 60, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 80, 60, 48, 224, 8, 9, 1, 0, 4, 10 },
    { 1, 88, 60, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 96, 60, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 104, 60, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 112, 60, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 0, 63, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 8, 63, 48, 224, 8, 9, 1, 0, 6, 10 },
    { 1, 16, 63, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 24, 63, 48, 224, 8, 9, 1, 0, 5, 10 }, { 0, 36, 172, 48, 224, 12, 9, 2, 0, 7, 10 },
    { 0, 48, 172, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 60, 172, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 156, 173, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 168, 173, 48, 224, 12, 9, 2, 0, 6, 10 }, { 0, 72, 174, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 84, 180, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 96, 180, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 108, 180, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 120, 180, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 24, 181, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 36, 181, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 48, 181, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 60, 181, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 132, 182, 48, 224, 12, 9, 2, 0, 5, 10 }, { 0, 144, 182, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 156, 182, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 168, 182, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 180, 182, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 72, 183, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 0, 184, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 12, 184, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 84, 189, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 96, 189, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 108, 189, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 120, 189, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 24, 190, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 36, 190, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 48, 190, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 60, 190, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 132, 191, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 144, 191, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 156, 191, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 168, 191, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 180, 191, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 72, 192, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 0, 193, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 12, 193, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 84, 198, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 96, 198, 48, 224, 12, 9, 2, 0, 7, 10 },
    { 0, 108, 198, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 120, 198, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 24, 199, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 36, 199, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 48, 199, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 60, 199, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 132, 200, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 144, 200, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 156, 200, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 168, 200, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 180, 200, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 72, 201, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 0, 202, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 12, 202, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 84, 207, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 96, 207, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 108, 207, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 120, 207, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 24, 208, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 36, 208, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 48, 208, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 60, 208, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 132, 209, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 144, 209, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 156, 209, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 168, 209, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 180, 209, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 72, 210, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 0, 211, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 12, 211, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 84, 216, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 96, 216, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 108, 216, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 120, 216, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 24, 217, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 36, 217, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 48, 217, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 60, 217, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 132, 218, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 144, 218, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 156, 218, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 168, 218, 48, 224, 12, 9, 2, 0, 7, 10 },
    { 0, 180, 218, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 72, 219, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 0, 220, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 12, 220, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 84, 225, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 96, 225, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 108, 225, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 120, 225, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 24, 226, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 36, 226, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 48, 226, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 60, 226, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 132, 227, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 144, 227, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 156, 227, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 168, 227, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 180, 227, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 72, 228, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 0, 229, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 12, 229, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 84, 234, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 96, 234, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 108, 234, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 120, 234, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 24, 235, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 36, 235, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 48, 235, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 60, 235, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 132, 236, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 144, 236, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 156, 236, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 168, 236, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 180, 236, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 72, 237, 48, 224, 12, 9, 2, 0, 7, 10 }, { 0, 0, 238, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 12, 238, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 84, 243, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 96, 243, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 108, 243, 48, 224, 12, 9, 2, 0, 6, 10 },
    { 0, 120, 243, 48, 224, 12, 9, 2, 0, 6, 10 }, { 0, 24, 244, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 36, 244, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 48, 244, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 60, 244, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 132, 245, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 0, 144, 245, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 156, 245, 48, 224, 12, 9, 2, 0, 9, 10 }, { 0, 168, 245, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 0, 180, 245, 48, 224, 12, 9, 2, 0, 8, 10 }, { 0, 72, 246, 48, 224, 12, 9, 2, 0, 8, 10 }, { 1, 0, 0, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 1, 12, 0, 48, 224, 12, 9, 2, 0, 8, 10 }, { 1, 24, 0, 48, 224, 12, 9, 2, 0, 9, 10 }, { 1, 36, 0, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 1, 48, 0, 48, 224, 12, 9, 2, 0, 9, 10 }, { 1, 60, 0, 48, 224, 12, 9, 2, 0, 9, 10 }, { 1, 72, 0, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 1, 84, 0, 48, 224, 12, 9, 2, 0, 9, 10 }, { 1, 96, 0, 48, 224, 12, 9, 2, 0, 9, 10 }, { 1, 108, 0, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 1, 120, 0, 48, 224, 12, 9, 2, 0, 8, 10 }, { 1, 132, 0, 48, 224, 12, 9, 2, 0, 7, 10 }, { 1, 144, 0, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 1, 156, 0, 48, 224, 12, 9, 2, 0, 8, 10 }, { 1, 168, 0, 48, 224, 12, 9, 2, 0, 9, 10 }, { 1, 180, 0, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 1, 192, 0, 48, 224, 12, 9, 2, 0, 9, 10 }, { 1, 204, 0, 48, 224, 12, 9, 2, 0, 8, 10 }, { 1, 216, 0, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 1, 228, 0, 48, 224, 12, 9, 2, 0, 6, 10 }, { 1, 240, 0, 48, 224, 12, 9, 2, 0, 8, 10 }, { 1, 0, 9, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 1, 12, 9, 48, 224, 12, 9, 2, 0, 7, 10 }, { 1, 24, 9, 48, 224, 12, 9, 2, 0, 9, 10 }, { 1, 36, 9, 48, 224, 12, 9, 2, 0, 7, 10 },
    { 1, 48, 9, 48, 224, 12, 9, 2, 0, 8, 10 }, { 1, 60, 9, 48, 224, 12, 9, 2, 0, 6, 10 }, { 1, 72, 9, 48, 224, 12, 9, 2, 0, 8, 10 },
    { 1, 84, 9, 48, 224, 12, 9, 2, 0, 7, 10 }, { 1, 96, 9, 48, 224, 12, 9, 2, 0, 8, 10 }, { 1, 108, 9, 48, 224, 12, 9, 2, 0, 9, 10 },
    { 1, 224, 63, 48, 224, 4, 9, 1, 0, 4, 10 }, { 0, 180, 65, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 228, 63, 48, 224, 4, 9, 1, 0, 4, 10 },
    { 1, 64, 42, 48, 224, 8, 9, 1, 0, 5, 10 }, { 0, 24, 172, 48, 224, 12, 9, 1, 0, 7, 10 },
#elif VERSION_EU
    { 1, 88, 42, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 96, 42, 48, 216, 8, 9, 1, 0, 4, 10 }, { 1, 104, 42, 48, 216, 8, 9, 1, 0, 6, 10 },
    { 1, 112, 42, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 120, 45, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 128, 45, 48, 216, 8, 9, 1, 0, 6, 10 },
    { 1, 136, 45, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 144, 45, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 152, 45, 48, 216, 8, 9, 1, 0, 6, 10 },
    { 1, 160, 45, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 168, 45, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 176, 45, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 184, 45, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 192, 45, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 200, 45, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 208, 45, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 216, 45, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 224, 45, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 232, 45, 48, 216, 8, 9, 1, 0, 4, 10 }, { 1, 240, 45, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 64, 51, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 72, 51, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 80, 51, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 88, 51, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 96, 51, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 104, 51, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 112, 51, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 0, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 8, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 16, 54, 48, 216, 8, 9, 1, 0, 6, 10 },
    { 1, 24, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 32, 54, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 40, 54, 48, 216, 8, 9, 1, 0, 6, 10 },
    { 1, 48, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 56, 54, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 120, 54, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 128, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 136, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 144, 54, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 152, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 160, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 168, 54, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 176, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 184, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 192, 54, 48, 216, 8, 9, 0, 0, 3, 10 },
    { 1, 200, 54, 48, 216, 8, 9, 1, 1, 4, 10 }, { 1, 208, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 216, 54, 48, 216, 8, 9, 0, 0, 3, 10 },
    { 1, 224, 54, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 232, 54, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 240, 54, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 64, 60, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 72, 60, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 80, 60, 48, 216, 8, 9, 1, 0, 4, 10 },
    { 1, 88, 60, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 96, 60, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 104, 60, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 112, 60, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 212, 141, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 244, 141, 48, 216, 8, 9, 1, 0, 6, 10 },
    { 1, 100, 196, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 236, 141, 48, 216, 8, 9, 1, 0, 5, 10 }, { 0, 36, 172, 48, 216, 12, 9, 2, 0, 7, 10 },
    { 0, 48, 172, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 60, 172, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 156, 173, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 168, 173, 48, 216, 12, 9, 2, 0, 6, 10 }, { 0, 72, 174, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 84, 180, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 96, 180, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 108, 180, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 120, 180, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 24, 181, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 36, 181, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 48, 181, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 60, 181, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 132, 177, 48, 216, 12, 9, 2, 0, 5, 10 }, { 0, 144, 182, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 156, 182, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 168, 182, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 180, 182, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 72, 183, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 0, 184, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 12, 184, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 84, 189, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 96, 189, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 108, 189, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 120, 189, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 24, 190, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 36, 190, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 48, 190, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 60, 190, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 132, 186, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 144, 191, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 156, 191, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 168, 191, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 180, 191, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 72, 192, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 0, 193, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 12, 193, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 84, 198, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 96, 198, 48, 216, 12, 9, 2, 0, 7, 10 },
    { 0, 108, 198, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 120, 198, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 24, 199, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 36, 199, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 48, 199, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 60, 199, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 132, 195, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 144, 200, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 156, 200, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 168, 200, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 180, 200, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 72, 201, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 0, 202, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 12, 202, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 84, 207, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 96, 207, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 108, 207, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 120, 207, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 24, 208, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 36, 208, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 48, 208, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 60, 208, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 132, 204, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 144, 209, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 156, 209, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 168, 209, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 180, 209, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 72, 210, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 0, 211, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 12, 211, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 84, 216, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 96, 216, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 108, 216, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 120, 216, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 24, 217, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 36, 217, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 48, 217, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 60, 217, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 132, 213, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 144, 218, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 156, 218, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 168, 218, 48, 216, 12, 9, 2, 0, 7, 10 },
    { 0, 180, 218, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 72, 219, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 0, 220, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 12, 220, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 84, 225, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 96, 225, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 108, 225, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 120, 225, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 24, 226, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 36, 226, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 48, 226, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 60, 226, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 132, 222, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 144, 227, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 156, 227, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 168, 227, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 180, 227, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 72, 228, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 0, 229, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 12, 229, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 84, 234, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 96, 234, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 108, 234, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 120, 234, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 132, 168, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 224, 184, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 188, 184, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 1, 212, 184, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 136, 198, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 144, 236, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 156, 236, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 168, 236, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 180, 236, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 72, 237, 48, 216, 12, 9, 2, 0, 7, 10 }, { 0, 0, 238, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 12, 238, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 1, 176, 184, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 220, 132, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 136, 207, 48, 216, 12, 9, 2, 0, 6, 10 },
    { 1, 108, 69, 48, 216, 12, 9, 2, 0, 6, 10 }, { 1, 164, 184, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 200, 184, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 1, 72, 69, 48, 216, 12, 9, 2, 0, 8, 10 }, { 1, 84, 69, 48, 216, 12, 9, 2, 0, 8, 10 }, { 1, 96, 69, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 0, 144, 245, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 156, 245, 48, 216, 12, 9, 2, 0, 9, 10 }, { 0, 168, 245, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 0, 180, 245, 48, 216, 12, 9, 2, 0, 8, 10 }, { 0, 72, 246, 48, 216, 12, 9, 2, 0, 8, 10 }, { 1, 0, 0, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 1, 12, 0, 48, 216, 12, 9, 2, 0, 8, 10 }, { 1, 24, 0, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 36, 0, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 1, 48, 0, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 60, 0, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 72, 0, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 1, 84, 0, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 96, 0, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 108, 0, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 1, 120, 0, 48, 216, 12, 9, 2, 0, 8, 10 }, { 1, 132, 0, 48, 216, 12, 9, 2, 0, 7, 10 }, { 1, 144, 0, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 1, 156, 0, 48, 216, 12, 9, 2, 0, 8, 10 }, { 1, 168, 0, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 180, 0, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 1, 192, 0, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 204, 0, 48, 216, 12, 9, 2, 0, 8, 10 }, { 1, 216, 0, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 1, 228, 0, 48, 216, 12, 9, 2, 0, 6, 10 }, { 1, 240, 0, 48, 216, 12, 9, 2, 0, 8, 10 }, { 1, 0, 9, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 1, 12, 9, 48, 216, 12, 9, 2, 0, 7, 10 }, { 1, 24, 9, 48, 216, 12, 9, 2, 0, 9, 10 }, { 1, 36, 9, 48, 216, 12, 9, 2, 0, 7, 10 },
    { 1, 48, 9, 48, 216, 12, 9, 2, 0, 8, 10 }, { 1, 60, 9, 48, 216, 12, 9, 2, 0, 6, 10 }, { 1, 72, 9, 48, 216, 12, 9, 2, 0, 8, 10 },
    { 1, 84, 9, 48, 216, 12, 9, 2, 0, 7, 10 }, { 1, 96, 9, 48, 216, 12, 9, 2, 0, 8, 10 }, { 1, 108, 9, 48, 216, 12, 9, 2, 0, 9, 10 },
    { 1, 60, 75, 48, 216, 4, 9, 1, 0, 4, 10 }, { 0, 180, 65, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 124, 176, 48, 216, 4, 9, 1, 0, 4, 10 },
    { 1, 64, 42, 48, 216, 8, 9, 1, 0, 5, 10 }, { 0, 24, 172, 48, 216, 12, 9, 1, 0, 7, 10 },
#endif
};
Glyph FONT_ICONS_2[114] = {
#if VERSION_US
    { 1, 216, 63, 48, 224, 4, 9, 0, 0, 4, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 220, 63, 48, 224, 4, 9, 1, 0, 4, 10 }, { 1, 224, 63, 48, 224, 4, 9, 1, 0, 4, 10 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 180, 65, 48, 224, 8, 9, 1, 0, 6, 10 },
    { 1, 228, 63, 48, 224, 4, 9, 1, 0, 4, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 64, 42, 48, 224, 8, 9, 1, 0, 5, 10 }, { 0, 208, 134, 48, 224, 8, 9, 1, 0, 5, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 24, 172, 48, 224, 12, 9, 1, 0, 7, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 248, 134, 48, 224, 4, 9, 1, 0, 4, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 72, 42, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 80, 42, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 200, 134, 48, 224, 8, 9, 1, 0, 5, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 188, 170, 48, 224, 4, 9, 1, 0, 2, 10 }, { 0, 216, 134, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 0, 224, 134, 48, 224, 8, 9, 1, 0, 5, 10 }, { 0, 232, 134, 48, 224, 8, 9, 1, 0, 5, 10 }, { 0, 240, 134, 48, 224, 8, 9, 1, 0, 6, 10 },
    { 0, 8, 172, 48, 224, 8, 9, 1, 0, 5, 10 }, { 0, 16, 172, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 188, 144, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 208, 145, 48, 224, 8, 9, 1, 0, 6, 10 }, { 1, 216, 145, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 224, 145, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 56, 178, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 176, 209, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 184, 209, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 192, 209, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 240, 209, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 80, 211, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 152, 212, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 160, 212, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 88, 213, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 96, 213, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 136, 215, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 144, 215, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 104, 217, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 176, 218, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 184, 218, 48, 224, 8, 9, 0, 0, 4, 10 },
    { 1, 192, 218, 48, 224, 8, 9, 1, 0, 4, 10 }, { 1, 240, 218, 48, 224, 8, 9, 1, 0, 3, 10 }, { 1, 200, 219, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 208, 219, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 216, 219, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 224, 219, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 232, 219, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 80, 220, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 152, 221, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 160, 221, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 168, 221, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 88, 222, 48, 224, 8, 9, 0, 0, 4, 10 },
    { 1, 96, 222, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 136, 224, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 144, 224, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 0, 225, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 8, 225, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 16, 225, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 24, 225, 48, 224, 8, 9, 1, 0, 3, 10 }, { 1, 104, 226, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 32, 227, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 40, 227, 48, 224, 8, 9, 0, 0, 4, 10 }, { 1, 48, 227, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 56, 227, 48, 224, 8, 9, 1, 0, 5, 10 },
    { 1, 64, 227, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 72, 227, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 176, 227, 48, 224, 8, 9, 0, 0, 4, 10 },
    { 1, 184, 227, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 192, 227, 48, 224, 8, 9, 1, 0, 5, 10 }, { 1, 228, 84, 48, 224, 4, 9, 1, 0, 3, 10 },
#elif VERSION_EU
    { 1, 28, 165, 48, 216, 4, 9, 0, 0, 4, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 28, 174, 48, 216, 4, 9, 1, 0, 4, 10 }, { 1, 60, 75, 48, 216, 4, 9, 1, 0, 4, 10 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 180, 65, 48, 216, 8, 9, 1, 0, 6, 10 },
    { 1, 124, 176, 48, 216, 4, 9, 1, 0, 4, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 64, 42, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 212, 132, 48, 216, 8, 9, 1, 0, 5, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 24, 172, 48, 216, 12, 9, 1, 0, 7, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 140, 62, 48, 216, 4, 9, 1, 0, 4, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 72, 42, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 80, 42, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 192, 147, 48, 216, 8, 9, 1, 0, 5, 10 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 200, 147, 48, 216, 4, 9, 1, 0, 2, 10 }, { 1, 112, 86, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 104, 86, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 212, 205, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 204, 147, 48, 216, 8, 9, 1, 0, 6, 10 },
    { 1, 48, 244, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 40, 244, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 220, 141, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 212, 159, 48, 216, 8, 9, 1, 0, 6, 10 }, { 1, 232, 132, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 172, 175, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 56, 178, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 80, 86, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 64, 69, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 64, 86, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 80, 246, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 80, 204, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 244, 150, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 236, 159, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 80, 213, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 136, 216, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 80, 159, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 128, 214, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 64, 244, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 164, 175, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 228, 159, 48, 216, 8, 9, 0, 0, 4, 10 },
    { 1, 96, 86, 48, 216, 8, 9, 1, 0, 4, 10 }, { 1, 236, 150, 48, 216, 8, 9, 1, 0, 3, 10 }, { 1, 228, 150, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 244, 111, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 220, 150, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 244, 159, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 228, 141, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 220, 205, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 72, 244, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 116, 196, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 180, 175, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 32, 244, 48, 216, 8, 9, 0, 0, 4, 10 },
    { 1, 56, 244, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 108, 196, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 72, 86, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 0, 225, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 8, 225, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 16, 225, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 24, 225, 48, 216, 8, 9, 1, 0, 3, 10 }, { 1, 212, 150, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 32, 227, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 40, 227, 48, 216, 8, 9, 0, 0, 4, 10 }, { 1, 48, 227, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 56, 227, 48, 216, 8, 9, 1, 0, 5, 10 },
    { 1, 64, 227, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 72, 227, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 88, 86, 48, 216, 8, 9, 0, 0, 4, 10 },
    { 1, 128, 205, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 220, 159, 48, 216, 8, 9, 1, 0, 5, 10 }, { 1, 188, 175, 48, 216, 4, 9, 1, 0, 3, 10 },
#endif
};
Glyph FONT_GLYPHS_3[230] = {
#if VERSION_US
    { 0, 8, 247, 48, 216, 8, 8, 1, 0, 6, 8 }, { 0, 16, 247, 48, 216, 8, 8, 1, 0, 6, 8 }, { 1, 56, 63, 48, 216, 8, 8, 1, 0, 6, 8 },
    { 1, 120, 63, 48, 216, 8, 8, 1, 0, 6, 8 }, { 1, 128, 63, 48, 216, 8, 8, 1, 0, 6, 8 }, { 1, 136, 63, 48, 216, 8, 8, 1, 0, 6, 8 },
    { 1, 144, 63, 48, 216, 8, 8, 1, 0, 6, 8 }, { 1, 152, 63, 48, 216, 8, 8, 1, 0, 6, 8 }, { 1, 160, 63, 48, 216, 8, 8, 1, 0, 6, 8 },
    { 1, 168, 63, 48, 216, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 232, 63, 48, 216, 8, 8, 1, 0, 6, 8 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 244, 71, 48, 216, 8, 8, 1, 0, 6, 8 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 176, 63, 48, 216, 8, 8, 1, 0, 6, 8 },
    { 1, 240, 63, 48, 216, 8, 8, 1, 0, 4, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 184, 63, 48, 216, 8, 8, 1, 0, 6, 8 }, { 1, 192, 63, 48, 216, 8, 8, 1, 0, 7, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 200, 63, 48, 216, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 244, 79, 48, 216, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 64, 69, 48, 216, 8, 8, 1, 0, 6, 8 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 208, 63, 48, 216, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 244, 87, 48, 216, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 236, 119, 48, 216, 8, 8, 0, 0, 7, 8 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 244, 119, 48, 216, 8, 8, 0, 0, 6, 8 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 204, 121, 48, 216, 8, 8, 0, 0, 7, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 72, 69, 48, 216, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#elif VERSION_EU
    { 0, 8, 247, 48, 208, 8, 8, 1, 0, 6, 8 }, { 0, 16, 247, 48, 208, 8, 8, 1, 0, 6, 8 }, { 0, 56, 235, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 120, 63, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 128, 63, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 136, 63, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 144, 63, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 152, 63, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 160, 63, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 168, 63, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 216, 168, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 232, 63, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 200, 168, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 192, 168, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 244, 71, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 232, 176, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 232, 168, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 176, 63, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 240, 63, 48, 208, 8, 8, 1, 0, 4, 8 }, { 1, 236, 208, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 244, 208, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 184, 63, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 192, 63, 48, 208, 8, 8, 1, 0, 7, 8 }, { 1, 224, 168, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 208, 168, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 200, 63, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 244, 200, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 244, 79, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 240, 168, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 224, 63, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 192, 176, 48, 208, 8, 8, 1, 0, 6, 8 }, { 0, 40, 235, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 240, 176, 48, 208, 8, 8, 1, 0, 7, 8 },
    { 1, 244, 87, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 200, 176, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 152, 213, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 208, 63, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 236, 200, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 224, 176, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 144, 216, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 64, 78, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 88, 78, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 216, 176, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 0, 234, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 8, 234, 48, 208, 8, 8, 1, 0, 4, 8 },
    { 1, 16, 234, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 24, 234, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 228, 213, 48, 208, 8, 8, 1, 0, 4, 8 },
    { 1, 96, 78, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 208, 176, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 32, 236, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 40, 236, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 48, 236, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 56, 236, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 64, 236, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 72, 236, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 104, 78, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 0, 64, 235, 48, 208, 8, 8, 1, 0, 6, 8 }, { 0, 48, 235, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 244, 103, 48, 208, 8, 8, 1, 0, 6, 8 },
    { 1, 112, 78, 48, 208, 8, 8, 1, 0, 6, 8 }, { 1, 216, 63, 48, 208, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 24, 235, 48, 208, 8, 8, 0, 0, 7, 8 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 32, 235, 48, 208, 8, 8, 0, 0, 6, 8 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 244, 95, 48, 208, 8, 8, 0, 0, 7, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 80, 78, 48, 208, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
};
Glyph FONT_ICONS_3[114] = {
#if VERSION_US
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 80, 69, 48, 216, 8, 8, 0, 0, 4, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 72, 69, 48, 216, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 247, 48, 216, 8, 8, 0, 0, 5, 8 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 192, 134, 48, 216, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#elif VERSION_EU
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 72, 78, 48, 208, 8, 8, 0, 0, 4, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 80, 78, 48, 208, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 247, 48, 208, 8, 8, 0, 0, 5, 8 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 228, 205, 48, 208, 8, 8, 1, 0, 6, 8 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
};
