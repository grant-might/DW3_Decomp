#include "game.h"
#include "field_map.h"

/* Sets the play time to zero */
void resetPlayTime(void) {
    GAME.playTimeMaxed = 0;
    GAME.playSeconds = 0;
    GAME.playMinutes = 0;
    GAME.playHours = 0;
    GAME.playFrames = 0;
}

/* Turns the vsync-counted frames into seconds, minutes and hours, stopping at 999:59:59 */
void updatePlayTime(void) {
    if ((GAME.playFrames >> 8) >= 60) {
        GAME.playFrames &= 0xFF;
        if (++GAME.playSeconds >= 60) {
            GAME.playSeconds = 0;
            if (++GAME.playMinutes >= 60) {
                GAME.playMinutes = 0;
                if (++GAME.playHours >= 1000) {
                    GAME.playHours = 999;
                    GAME.playMinutes = 59;
                    GAME.playSeconds = 59;
                    GAME.playTimeMaxed = 1;
                }
            }
        }
    }
}
