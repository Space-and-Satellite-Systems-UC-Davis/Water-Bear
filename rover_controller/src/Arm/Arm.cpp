#include "Arm.h"

bool armInit() {
    return uartInit(ARM_SERIAL, ARM_RX, ARM_TX);
}

void vArmTask(void* pvParameters) {

}
