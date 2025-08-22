#pragma once

#include "Arduino.h"
#include "Util/UARTUtil.h"

#define COMMS_TX 0
#define COMMS_RX 0
#define COMMS_SERIAL Serial1

typedef enum {
    COMMS_MANUAL_CONTROL,
    COMMS_AUTONOMOUS,
    COMMS_IDLE
} CommsState;

typedef struct {
    CommsState state;
} CommsContext;


void commsInit(CommsContext *ctx);
void vCommsTask(void *param);
void commsSetState(CommsContext *ctx, CommsState state);