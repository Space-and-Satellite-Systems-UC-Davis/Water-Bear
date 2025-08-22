#include <Arduino.h>
#include "Mediator/Mediator.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Project Water Bear turning on!");

  mediatorInit();
  
}

void loop() {
  //Empty loop, all logic occuring in tasks
}
