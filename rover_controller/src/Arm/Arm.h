#pragma once

#include "Arduino.h"
#include "Util/UARTUtil.h"

#define ARM_TX 0 //TODO: get these actual values
#define ARM_RX 0 

#define ARM_SERIAL Serial2

bool armInit();
void vArmTask(void* pvParameters);