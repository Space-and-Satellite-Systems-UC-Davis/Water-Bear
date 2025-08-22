#pragma once

#include "Arduino.h"
#include "Comms/Comms.h"
#include "Drivebase/Drivebase.h"
#include "Arm/Arm.h"

typedef enum {
    IDLE,
    MANUAL,
    AUTO,
    REST
} MediatorState;

void mediatorInit();