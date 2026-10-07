/* The data of STDWTITL's first object: the screen's rectangles, the logo's
   and the glints' frames, the movies, and the menu's cursor and sprites */

#include "stdwtitl.h"

/* not used */
s32 STDWTITL_unused[3] = {0};

RECT STDWTITL_screenRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

/* The sprite frames of the logo's two animations; -1 ends each */
s16 STDWTITL_logoFrames[2][13] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -1},
    {0, 1, 2, 3, 4, 5, 6, 7, -1},
};

s32 STDWTITL_movieWidth = 0;
s32 STDWTITL_movieHeight = 0;
RECT STDWTITL_vramRect = {0, 0, 1024, 512};

/* Each movie's file, the frame it ends on and the game mode after it */
MovieInfo STDWTITL_movies[] = {
#if VERSION_US
    {0x7E5, 0x6F0, 0xE00}, {0x7DB, 0x1D1, 0x207}, {0x7E3, 0x166, 0x26D},
    {0x7DC, 0x3C0, 0x216}, {0x7DD, 0x231, 0x272}, {0x7DE, 0x294, 0x288},
    {0x7DF, 0xE0, 0x288},  {0x7E0, 0x151, 0x2DE}, {0x7E1, 0x1B2, 0x600},
    {0x7E4, 0x28F, 0xE0B}, {0x894, 0x671, 0x2D7}, {0xC0, 0x671, 0x2D7},
    {0xBF, 0x671, 0x2D7},
#elif VERSION_EU
    {0x94C, 0x6F0, 0xE00}, {0x7F4, 0x6F0, 0xE00}, {0x7EA, 0x1D1, 0x207},
    {0x7F2, 0x166, 0x26D}, {0x7EB, 0x3C0, 0x216}, {0x7EC, 0x231, 0x272},
    {0x7ED, 0x294, 0x288}, {0x7EE, 0xE0, 0x288},  {0x7EF, 0x151, 0x2DE},
    {0x7F0, 0x1B2, 0x600}, {0x7F3, 0x28F, 0xE0C}, {0x8A5, 0x671, 0x2D7},
    {0x817, 0x671, 0x2D7}, {0x816, 0x671, 0x2D7},
#endif
};

s16 STDWTITL_glintAltFrames[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
s16 STDWTITL_glintFrames[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1,
};

Point STDWTITL_menuCursorPositions[] = {{79, 154}, {79, 174}, {79, 166}};

#if VERSION_EU
u8 STDWTITL_menuSprites[][4] = {
    {8, 9, 10}, {8, 9, 10}, {8, 9, 10}, {17, 18, 19},
    {11, 12, 13}, {20, 21, 22}, {14, 15, 16},
};
#endif
