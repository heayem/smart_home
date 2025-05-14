#include <Arduino.h>
#include "FrontLED.h"

const int frontLEDPin = 2; // GPIO2

void setupFrontLED() {
  pinMode(frontLEDPin, OUTPUT);
}

void turnOnFrontLED() {
  digitalWrite(frontLEDPin, HIGH);
  Serial.println("Front LED turned ON");
}

void turnOffFrontLED() {
  digitalWrite(frontLEDPin, LOW);
  Serial.println("Front LED turned OFF");
}
