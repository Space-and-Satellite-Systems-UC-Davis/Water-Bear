#include <Arduino.h>
#include "Arm/Arm.h"
#include "Comms/Comms.h"
#include "Odometry/Odometry.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Project Water Bear turning on!");

  bool hasCriticalFailure = false;

  if (!armInit()) {
    Serial.println("ARM CONNECTION FAILED");
    hasCriticalFailure = true;
  }

  if (!commsInit()) {
    Serial.println("COMMS CONNECTION FAILED");
    hasCriticalFailure = true;
  }

  if (hasCriticalFailure) {
    Serial.println("DETECTED CRTICAL ERROR, FREEZING SYSTEM");
    while(1);
  }

  xTaskCreate(
    vArmTask,
    "Arm",
    2048,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    vCommsTask,
    "Comms",
    2048,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    vOdometryTask,
    "Odometry",
    2048,
    NULL,
    1,
    NULL 
  );
  
}

void loop() {
  //Empty loop, all logic occuring in tasks
}
