#include "Comms.h"


void commsInit(CommsContext *ctx) {
    if (!uartInit(COMMS_SERIAL, COMMS_RX, COMMS_TX)) {
        Serial.println("CRITICAL WARNING: COMMS CONNECTION FAILED");
    }
    ctx->state = COMMS_IDLE;
    xTaskCreate(vCommsTask, "Comms", 2048, ctx, 1, NULL);
}

void vCommsTask(void *pvParameters) {
    uint8_t commsBuffer[128];
    int bytesRead = 0;
    while(1) {
        bytesRead = readMessage(commsBuffer, 128);
        
    }
}

void commsSetState(CommsContext *ctx, CommsState state) {
    ctx->state = state;
}
