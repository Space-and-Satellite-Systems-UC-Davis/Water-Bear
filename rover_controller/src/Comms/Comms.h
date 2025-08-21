#pragma once

#include "Arduino.h"
#include "Util/UARTUtil.h"

#define COMMS_TX 0
#define COMMS_RX 0
#define COMMS_SERIAL Serial1

bool commsInit();

void vCommsTask(void* pvParameters);