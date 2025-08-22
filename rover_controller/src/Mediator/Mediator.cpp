#include "Mediator.h"

static DrivebaseContext drivebase;
static ArmContext arm;
static CommsContext comms;

static void vMediatorTask(void *pvParam) {
    armInit(&arm);
    drivebaseInit(&drivebase);
    commsInit(&comms);

    MediatorState systemState = IDLE;

    while(1) {
        switch (systemState) {
            case IDLE:
                break;
            case MANUAL:
                break;
            case AUTO:
                break;
            case REST:
                break;
        }
    }
}

void mediatorInit() {
    xTaskCreate(vMediatorTask, "Mediator", 2048, NULL, 1, NULL);
}
