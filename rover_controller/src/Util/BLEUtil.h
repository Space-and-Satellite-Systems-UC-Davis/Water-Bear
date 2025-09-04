#ifndef BLE_SERVER_H
#define BLE_SERVER_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// UUIDs for the UART service and characteristics
#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

// // Global BLE objects
// extern BLEServer *pServer;
// extern BLECharacteristic *pTxCharacteristic;
// extern bool deviceConnected;
// extern bool oldDeviceConnected;
// extern uint8_t txValue;

// Server callback class
class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) override;
  void onDisconnect(BLEServer *pServer) override;
};

// Characteristic callback class
class MyCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) override;
};

// Function prototypes
void BLEInit();
void loop();

#endif // BLE_SERVER_H