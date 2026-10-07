/* The overlay's images and the files of its image sets; the panels' fades; the
   gym levels' trainings; and the third object's data, with the state all three
   objects share */

#include "stgtrain.h"

/* Loads the overlay's TIM archive into VRAM */
void STGTRAIN_loadImages(void) {
    TimLoader loader;

    initTimLoader(&loader);
    loader.setImagePos(0x240, 0x100);
    loader.loadArchive(FILE_CACHE.getEntry(STGTRAIN_FILE_IMAGES << 16));
}

#include "../menu_common/start_fade.inc.c"
#include "../menu_common/update_fade.inc.c"
#include "../menu_common/start_lerp.inc.c"
#include "../menu_common/update_lerp.inc.c"

/* Starts loading a file of STGTRAIN_files, unless it is the one loaded */
s32 STGTRAIN_requestFile(s32 index) {
    if (index < 0) {
        return 0;
    }
    if (index != STGTRAIN_state.fileIndex) {
        HEAP.zero(&STGTRAIN_state.data, 0x2D8);
        STGTRAIN_state.fileIndex = index;
        FILE_CACHE.request(STGTRAIN_files[index].file);
        STGTRAIN_state.data = NULL;
    }
    return 1;
}

/* The requested file, or NULL while it loads */
u8 *STGTRAIN_getFile(void) {
    if (FILE_CACHE.isLoading(STGTRAIN_files[STGTRAIN_state.fileIndex].file) == 0) {
        STGTRAIN_state.data = FILE_CACHE.load(STGTRAIN_files[STGTRAIN_state.fileIndex].file);
    }
    return STGTRAIN_state.data;
}

/* Frees the loaded file of STGTRAIN_files */
void STGTRAIN_freeFile(void) {
    if (STGTRAIN_state.fileIndex != -1) {
        FILE_CACHE.free(STGTRAIN_files[STGTRAIN_state.fileIndex].file);
    }
}

/* The set's sprite bank, and the two values after its offsets */
s32 STGTRAIN_readSetBank(TrainSetHeader *header, s32 set) {
    STGTRAIN_bankCursor.set = header;
    STGTRAIN_state.sets[set].bank = (TrainSpriteBank *)(STGTRAIN_state.data + header->bank);
    STGTRAIN_bankCursor.w += *STGTRAIN_bankCursor.w + 1;
    STGTRAIN_state.sets[set].bankOffset = *STGTRAIN_bankCursor.w++;
    STGTRAIN_state.sets[set].unkC = *STGTRAIN_bankCursor.w;
    return 1;
}

/* The set's animations */
s32 STGTRAIN_readSetAnims(TrainSetHeader *header, s32 set) {
    s32 i;

    STGTRAIN_animCursor.set = header;
    for (i = 0; i < 6; i++) {
        if (STGTRAIN_animCursor.set->anims[i] != 0) {
            STGTRAIN_state.sets[set].anims[i] = (TrainAnim *)(STGTRAIN_state.data + STGTRAIN_animCursor.set->anims[i]);
        } else {
            STGTRAIN_state.sets[set].anims[i] = NULL;
        }
    }
    return 1;
}

/* The images of a set: the rest of its offsets */
s32 STGTRAIN_readSetImages(TrainSetHeader *header, s32 set) {
    s32 i;

    STGTRAIN_imageCursor.set = header;
    STGTRAIN_state.sets[set].imageCount = header->count - 7;
    for (i = 0; i < STGTRAIN_state.sets[set].imageCount; i++) {
        STGTRAIN_state.sets[set].images[i] = STGTRAIN_state.data + STGTRAIN_imageCursor.set->images[i];
    }
    return 1;
}

/* Reads an image set of the loaded file */
s32 STGTRAIN_readSet(s32 set) {
    if (STGTRAIN_state.data != NULL && set < 9) {
        STGTRAIN_state.sets[set].id = set;
        STGTRAIN_setCursor.w = (s32 *)(STGTRAIN_state.data + set * 4);
        STGTRAIN_setCursor.w = (s32 *)(STGTRAIN_state.data + *STGTRAIN_setCursor.w);
        if (STGTRAIN_setCursor.set->count == 0) {
            return 0;
        }
        if (STGTRAIN_readSetBank(STGTRAIN_setCursor.set, set) == 0) {
            return 0;
        }
        if (STGTRAIN_readSetAnims(STGTRAIN_setCursor.set, set) != 0) {
            return STGTRAIN_readSetImages(STGTRAIN_setCursor.set, set) != 0;
        }
    }
    return 0;
}

/* Loads the images of a set into VRAM side by side, unpacking the
   run-length encoded ones ("RLEN") first */
s32 STGTRAIN_loadSet(s32 set, s32 *pos) {
    TimLoader loader;
    s32 x;
    s32 y;
    s32 clutX;
    s32 clutY;
    u8 *buf;
    u8 *src;
    u8 *image;
    s32 i;
    s32 j;
    s32 n;
    u8 c;
    s32 magic;

    if (set != STGTRAIN_state.sets[set].id) {
        return 0;
    }
    x = pos[0];
    y = pos[1];
    clutX = pos[2];
    clutY = pos[3];
    initTimLoader(&loader);
    STGTRAIN_state.sets[set].imageY = y;
    buf = HEAP.alloc(0xA800, 2);
    for (i = 0; i < STGTRAIN_state.sets[set].imageCount; i++) {
        STGTRAIN_state.sets[set].imageX[i] = x + i * 0x40;
        loader.setImagePos(x + i * 0x40, y);
        src = STGTRAIN_state.sets[set].images[i];
        /* the match depends on the magic read before image is set: with
           the copy right after the load, cse puts the load in image */
        magic = *(s32 *)src;
        image = src;
        if (magic == 0x4E454C52) {
            /* and on image set before src moves on, or src + 8 is taken
               from image */
            image = buf;
            src += 8;
            while ((c = *src) != 0) {
                if (c & 0x80) {
                    n = c & 0x7F;
                    src++;
                    for (j = 0; j < n; j++) {
                        *image++ = *src;
                    }
                    src++;
                } else {
                    n = *src++;
                    for (j = 0; j < n; j++) {
                        *image++ = *src++;
                    }
                }
            }
            image = buf;
        }
        loader.setClutPos(clutX + *(s16 *)(image + 0xC), clutY);
        loader.load(image);
    }
    HEAP.free(buf);
    return 1;
}

/* The file of an entry of STGTRAIN_files */
s32 STGTRAIN_getFileId(s32 index) {
    return STGTRAIN_files[index].file;
}

/* Where the image of an entry of STGTRAIN_files goes (y << 16 | x) */
s32 STGTRAIN_getFilePos(s32 index) {
    return STGTRAIN_files[index].y << 16 | STGTRAIN_files[index].x;
}

/* An entry of STGTRAIN_files's unkC */
s32 STGTRAIN_getFileUnkC(s32 index) {
    return STGTRAIN_files[index].unkC;
}

/* The sprite bank of an image set */
TrainSpriteBank *STGTRAIN_getBank(s32 set) {
    return STGTRAIN_state.sets[set].bank;
}

/* Where an image set's sprites start in its bank */
s32 STGTRAIN_getBankOffset(s32 set) {
    return STGTRAIN_state.sets[set].bankOffset;
}

/* An image set's unkC */
s32 STGTRAIN_getSetUnkC(s32 set) {
    return STGTRAIN_state.sets[set].unkC;
}

/* An animation of an image set */
TrainAnim *STGTRAIN_getAnim(s32 set, s32 i) {
    return STGTRAIN_state.sets[set].anims[i];
}

/* The trainings of a gym level, counting them */
s32 *STGTRAIN_getGymTrainings(s32 index) {
    s32 i;

    if (index < 1 || index > 14) {
        index = 0;
    }
    STGTRAIN_state.tableCount = 0;
    for (i = 0; i < 16; i++) {
        if (STGTRAIN_gymTrainings[index][i][0] != 0) {
            STGTRAIN_state.tableCount++;
        }
    }
    return STGTRAIN_gymTrainings[index][0];
}

/* A training of a gym level, by its id */
s32 *STGTRAIN_findGymTraining(s32 index, s32 id) {
    s32 i;

    if (index < 1 || index > 14) {
        index = 0;
    }
    for (i = 0; i < 16; i++) {
        if (STGTRAIN_gymTrainings[index][i][0] == id) {
            return STGTRAIN_gymTrainings[index][i];
        }
    }
    return NULL;
}

/* The data: the rest of the overlay's, with the state all three objects
   share */
/* the points each intensity of a training costs */
s32 STGTRAIN_intensityCosts[] = {
    1, 5, 10,
};
/* The trainings of each gym level, by STGTRAIN_findGymTraining: {id, ?}, 0 ends */
s32 STGTRAIN_gymTrainings[14][16][2] = {
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {0, 0}, {0, 0}, {0, 0}, {0, 0},
        {0, 0}, {0, 0}, {0, 0}, {0, 0},
    },
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {8, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {0, 0}, {0, 0}, {0, 0},
    },
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {8, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {12, 0x3000E}, {0, 0}, {0, 0},
    },
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {8, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {8, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {20, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {17, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {20, 0x5000A}, {9, 0x1000B},
        {10, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {19, 0x20009}, {8, 0x5000A}, {9, 0x1000B},
        {22, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {17, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {19, 0x20009}, {20, 0x5000A}, {9, 0x1000B},
        {22, 0x4000C}, {11, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {8, 0x5000A}, {21, 0x1000B},
        {10, 0x4000C}, {23, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {17, 5}, {0, 0}, {0, 0}, {0, 0},
        {6, 0x100008}, {7, 0x20009}, {20, 0x5000A}, {21, 0x1000B},
        {10, 0x4000C}, {23, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {5, 5}, {0, 0}, {0, 0}, {0, 0},
        {18, 0x100008}, {19, 0x20009}, {8, 0x5000A}, {21, 0x1000B},
        {22, 0x4000C}, {23, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {17, 5}, {0, 0}, {0, 0}, {0, 0},
        {18, 0x100008}, {19, 0x20009}, {20, 0x5000A}, {21, 0x1000B},
        {22, 0x4000C}, {23, 0xF000D}, {12, 0x3000E}, {0, 0},
    },
    {
        {13, 1}, {14, 2}, {15, 3}, {16, 4},
        {17, 5}, {0, 0}, {0, 0}, {0, 0},
        {18, 0x100008}, {19, 0x20009}, {20, 0x5000A}, {21, 0x1000B},
        {22, 0x4000C}, {23, 0xF000D}, {24, 0x3000E}, {0, 0},
    },
};
/* The trainings: their name and description in the text file, and the
   frames of their icon */
TrainInfo STGTRAIN_trainings[] = {
    {0, 0, {0, 0, 0, 0}},
    {19, 43, {0, 1, 2, 3}},
    {20, 44, {4, 5, 6, 7}},
    {21, 45, {8, 9, 10, 11}},
    {22, 46, {12, 13, 14, 15}},
    {23, 47, {16, 17, 18, 19}},
    {29, 53, {20, 21, 22, 23}},
    {30, 54, {24, 25, 26, 27}},
    {31, 55, {28, 29, 30, 31}},
    {32, 56, {32, 33, 34, 35}},
    {33, 57, {36, 37, 38, 39}},
    {34, 58, {40, 41, 42, 43}},
    {35, 59, {95, 96, 97, 98}},
    {24, 48, {45, 46, 47, 48}},
    {25, 49, {49, 50, 51, 52}},
    {26, 50, {53, 54, 55, 56}},
    {27, 51, {57, 58, 59, 60}},
    {28, 52, {61, 62, 63, 64}},
    {36, 60, {65, 66, 67, 68}},
    {37, 61, {71, 72, 73, 74}},
    {38, 62, {75, 76, 77, 78}},
    {39, 63, {79, 80, 81, 82}},
    {40, 64, {83, 84, 85, 86}},
    {41, 65, {87, 88, 89, 90}},
    {42, 66, {91, 92, 93, 94}},
};
/* the discs number their files differently */
#if VERSION_US
TrainFile STGTRAIN_files[] = {
    {591, 82, 31, 0},
    {591, 82, 31, 0},
    {1070, 79, 31, 0},
    {625, 78, 27, 0},
    {626, 79, 24, 1},
    {627, 79, 31, 0},
    {628, 79, 31, 0},
    {755, 79, 31, 0},
    {756, 81, 31, 1},
    {1071, 79, 31, 0},
    {629, 47, 35, 1},
    {630, 79, 31, 0},
    {757, 79, 31, 1},
    {591, 82, 31, 0},
    {1070, 79, 31, 0},
    {625, 78, 27, 0},
    {626, 79, 24, 1},
    {627, 79, 31, 0},
    {628, 79, 31, 0},
    {755, 79, 31, 0},
    {756, 81, 31, 1},
    {1071, 79, 31, 0},
    {629, 47, 35, 1},
    {630, 79, 31, 0},
    {757, 79, 31, 1},
};
#elif VERSION_EU
TrainFile STGTRAIN_files[] = {
    {606, 82, 31, 0},
    {606, 82, 31, 0},
    {1086, 79, 31, 0},
    {640, 78, 27, 0},
    {641, 79, 24, 1},
    {642, 79, 31, 0},
    {643, 79, 31, 0},
    {770, 79, 31, 0},
    {771, 81, 31, 1},
    {1087, 79, 31, 0},
    {644, 47, 35, 1},
    {645, 79, 31, 0},
    {772, 79, 31, 1},
    {606, 82, 31, 0},
    {1086, 79, 31, 0},
    {640, 78, 27, 0},
    {641, 79, 24, 1},
    {642, 79, 31, 0},
    {643, 79, 31, 0},
    {770, 79, 31, 0},
    {771, 81, 31, 1},
    {1087, 79, 31, 0},
    {644, 47, 35, 1},
    {645, 79, 31, 0},
    {772, 79, 31, 1},
};
#endif
TrainState STGTRAIN_state = {
    0, NULL, 0, {{0}}, STGTRAIN_trainings,
    STGTRAIN_loadImages, STGTRAIN_startFade, STGTRAIN_updateFade, STGTRAIN_startLerp,
    STGTRAIN_updateLerp, STGTRAIN_requestFile, STGTRAIN_getFile, STGTRAIN_freeFile,
    STGTRAIN_readSet, STGTRAIN_loadSet, STGTRAIN_getFileId, STGTRAIN_getFilePos,
    STGTRAIN_getFileUnkC, STGTRAIN_getBank, STGTRAIN_getBankOffset, STGTRAIN_getSetUnkC,
    STGTRAIN_getAnim, STGTRAIN_getGymTrainings, STGTRAIN_findGymTraining,
};
TrainCursor STGTRAIN_bankCursor = {NULL};
TrainCursor STGTRAIN_animCursor = {NULL};
TrainCursor STGTRAIN_imageCursor = {NULL};
TrainCursor STGTRAIN_setCursor = {NULL};
