#pragma once

#include "Arduino.h"
#include "Util/UARTUtil.h"

#define ARM_TX 0 //TODO: get these actual values
#define ARM_RX 0 

#define ARM_SERIAL Serial2

typedef enum {
    ARM_IDLE,
    ARM_STOW,
    ARM_FULL_EXTEND
} ArmState;

typedef struct {
    ArmState state;
} ArmContext;


void armInit(ArmContext *ctx);
void vArmTask(void *param);
void armSetState(ArmContext *ctx, ArmState state);