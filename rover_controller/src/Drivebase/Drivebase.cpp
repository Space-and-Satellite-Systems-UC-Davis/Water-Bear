#include "Drivebase.h"

void drivebaseInit(DrivebaseContext *ctx) {
    ctx->state = DRIVEBASE_IDLE;
    xTaskCreate(vDrivebaseTask, "Drivebase", 2048, ctx, 1, NULL);
}

void vDrivebaseTask(void *param) {
    DrivebaseContext *ctx = (DrivebaseContext*)param;

}

void drivebaseSetState(DrivebaseContext *ctx, DrivebaseState state) {
     ctx->state = state;
}
