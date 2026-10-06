/*
 * The update of the stage's task (startStage) in the stages that only copy
 * the points of the place the player comes from (GAME.unk44 and unk46) to
 * their triggers (D_800990B4.slots), before the task moves on
 */
void updateStage(StageTask *task) {
    switch (task->state) {
    case TASK_INIT:
    default:
        copyPlacePoints(D_800990B4.slots, placePoints, GAME.unk44, GAME.unk46);
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}
