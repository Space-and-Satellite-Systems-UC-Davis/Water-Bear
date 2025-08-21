#include "UARTUtil.h"


bool uartInit(HardwareSerial serialPort, int rx, int tx) {
    serialPort.begin(115200, SERIAL_8N1 , rx, tx);

    int retry_max = 100;
    while (!isConnected(serialPort)) {
        retry_max -= 1;
        if (retry_max == 0) {
            return false;
        }
    }

    if (retry_max > 0) {
        return true;
    }  
}

void writeMessage(HardwareSerial serialPort, uint8_t* buffer, int size) {
    for (int i = 0; i < size; i++) {
        serialPort.write(buffer[i]);
    }
}

bool readMessage(HardwareSerial serialPort, uint8_t* buffer, int size) {
    if (serialPort.available()) {
        serialPort.readBytes(buffer, size);
        return true;
    }
    return false;
}

bool isConnected(HardwareSerial serialPort) {
    serialPort.write(500);
    delay(10);
    uint8_t buffer[1];
    if (serialPort.available()) {
        serialPort.read(buffer, 1);
        if (buffer[0] == 100) {
            return true;
        }
    }
    return false;
}

