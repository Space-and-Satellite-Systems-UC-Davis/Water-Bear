#pragma once

#include "Arduino.h"

typedef enum {
    DRIVEBASE_IDLE,
    DRIVEBASE_MOVING,
    DRIVEBASE_ERROR
} DrivebaseState;

typedef struct {
    DrivebaseState state;
} DrivebaseContext;


void drivebaseInit(DrivebaseContext *ctx);
void vDrivebaseTask(void *param);
void drivebaseSetState(DrivebaseContext *ctx, DrivebaseState state);