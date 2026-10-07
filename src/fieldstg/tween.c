/* The questions' panel opens and closes as the menus' panels do, with
   their code */

#include "fieldstg.h"

#define START_FADE OVL_NAME(startTween)
#include "../menu_common/start_fade.inc.c"
#define UPDATE_FADE OVL_NAME(updateTween)
#include "../menu_common/update_fade.inc.c"
