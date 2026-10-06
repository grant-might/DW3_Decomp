/*
 * Starts the menu stage's tween (stageFuncs.start) with its sound: up, from
 * 0 to 0x1000 over its duration, or down, twice as fast
 */
void startTween(StageTween *tween, s32 up) {
    tween->active = 1;
    if (up) {
        SOUND.playSound(SOUND_MENU_OPEN);
        tween->step = 0x1000 / tween->duration;
        tween->value = 0;
    } else {
        SOUND.playSound(SOUND_MENU_CLOSE);
        tween->value = 0x1000;
        tween->step = -(0x1000 / tween->duration * 2);
    }
}
