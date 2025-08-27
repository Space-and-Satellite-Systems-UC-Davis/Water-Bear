#include "Arm.h"

void armInit(ArmContext *ctx) {
    if (!uartInit(ARM_SERIAL, ARM_RX, ARM_TX)) {
        Serial.println("CRITICAL WARNING: ARM CONNECTION FAILED");
    }
    ctx->state = ARM_IDLE;
    xTaskCreate(vArmTask, "Arm", 2048, ctx, 1, NULL);
}

void vArmTask(void *pvParameters) {
    ArmContext *ctx = (ArmContext*)pvParameters;

}

void armSetState(ArmContext *ctx, ArmState state) {
    ctx->state = state;
}
