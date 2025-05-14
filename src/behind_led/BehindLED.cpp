#include <Arduino.h>
#include "BehindLED.h"

const int behindLEDPin = 4; // GPIO4

void setupBehindLED() {
  pinMode(behindLEDPin, OUTPUT);
}

void turnOnBehindLED() {
  digitalWrite(behindLEDPin, HIGH);
  Serial.println("Behind LED turned ON");
}

void turnOffBehindLED() {
  digitalWrite(behindLEDPin, LOW);
  Serial.println("Behind LED turned OFF");
}
