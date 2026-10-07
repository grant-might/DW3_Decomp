#include "game.h"
#include <libgs.h>
#include <libetc.h>
#include <libsnd.h>

/* Small variables, addressed through $gp (see the Makefile) */
static TimLoader *TIM_LOADER;

/* Makes `obj` the TIM loader the methods work on */
void bindTimLoader(TimLoader *obj) {
    TIM_LOADER = obj;
}

/* TIM loader method: where in VRAM the next image goes */
void timLoaderSetImagePos(s32 x, s32 y) {
    TIM_LOADER->imageX = x;
    TIM_LOADER->imageY = y;
}

/* TIM loader method: where in VRAM the next CLUT goes */
void timLoaderSetClutPos(s32 x, s32 y) {
    TIM_LOADER->clutX = x;
    TIM_LOADER->clutY = y;
}

/* TIM loader method: sends a TIM's CLUT (4 and 8-bit images) and image to VRAM */
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

/*
 * TIM loader method: loads every TIM of an archive side by side, 0x40 halfwords apart, unpacking
 * the RLEN ones
 */
void timLoaderLoadArchive(s32 archive) {
    u8 *buf = HEAP.alloc(TIM_LOADER->bufferSize, MEM_MODE);
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

/* TIM loader method: the buffer that RLEN TIMs are unpacked to */
void timLoaderSetBufferSize(s32 size) {
    TIM_LOADER->bufferSize = size;
}

/* Clears a TIM loader, gives it its methods and binds it */
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
