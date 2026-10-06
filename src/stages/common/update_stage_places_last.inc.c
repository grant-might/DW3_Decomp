/*
 * As update_stage_places.inc.c, with the points copied after the task moves
 * on (seven stages)
 */
void updateStage(StageTask *task) {
    switch (task->state) {
    case TASK_INIT:
    default:
        task->nextState(task);
        copyPlacePoints(D_800990B4.slots, placePoints, GAME.unk44, GAME.unk46);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}
