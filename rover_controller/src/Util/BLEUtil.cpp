#include "BLEUtil.h"

// Global variable definitions
BLEServer *pServer = nullptr;
BLECharacteristic *pTxCharacteristic = nullptr;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint8_t txValue = 0;


// ------------------ Callback Implementations ------------------

void MyServerCallbacks::onConnect(BLEServer *pServer) {
  deviceConnected = true;
  Serial.println("Device connected");
}

void MyServerCallbacks::onDisconnect(BLEServer *pServer) {
  deviceConnected = false;
  Serial.println("Device disconnected");
}

void MyCallbacks::onWrite(BLECharacteristic *pCharacteristic) {
  std::string rxValue = pCharacteristic->getValue();

  if (rxValue.length() > 0) {
    Serial.println("*********");
    Serial.print("Received Value: ");
    for (char c : rxValue) {
      Serial.print(c);
    }
    Serial.println();
    Serial.println("*********");
  }
}

// ------------------  Setup & Loop ------------------

void BLEInit() {

  // Create the BLE Device
  BLEDevice::init("UART Service");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create TX Characteristic (Notify)
  pTxCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID_TX,
    BLECharacteristic::PROPERTY_NOTIFY
  );

  // Add descriptor for notifications
  pTxCharacteristic->addDescriptor(new BLE2902());

  // Create RX Characteristic (Write)
  BLECharacteristic *pRxCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID_RX,
    BLECharacteristic::PROPERTY_WRITE
  );
  pRxCharacteristic->setCallbacks(new MyCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection to notify...");
}


void BLESendBuffer(uint8_t* buffer, int size, int retries) {
    for (int i = 0; i < retries; i++) {
        if (deviceConnected) {
            pTxCharacteristic->setValue(buffer, size);
            pTxCharacteristic->notify();
        }
    }
}

void BLEReadBuffer(uint8_t* buffer, int size)

void BLEConnectionLoop() {
  // Handle disconnect/reconnect logic
  if (!deviceConnected && oldDeviceConnected) {
    delay(500); // give the BLE stack a chance
    pServer->startAdvertising();  
    oldDeviceConnected = false;
  }

  if (deviceConnected && !oldDeviceConnected) {
    oldDeviceConnected = true;
  }
}
