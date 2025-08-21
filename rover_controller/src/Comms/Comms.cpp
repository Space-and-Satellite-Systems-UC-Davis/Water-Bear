#include "Comms.h"


bool commsInit() {
    return uartInit(COMMS_SERIAL, COMMS_RX, COMMS_TX);
}

void vCommsTask(void* pvParameters) {
    
}