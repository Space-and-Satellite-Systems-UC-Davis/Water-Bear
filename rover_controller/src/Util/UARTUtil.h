#pragma once

#include "Arduino.h"

bool uartInit(HardwareSerial serialPort, int rx, int tx);
bool isConnected(HardwareSerial serialPort);
void writeMessage(uint8_t* buffer, int size);
bool readMessage(uint8_t* buffer, int size);
