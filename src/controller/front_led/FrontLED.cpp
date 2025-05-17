#include <Arduino.h>
#include "FrontLED.h"
#include "model/led/LED.h"  

static LED frontLED(2);

void setupFrontLED() {
    frontLED.begin();
    Serial.println("Front LED initialized");
}

void turnOnFrontLED() {
    frontLED.on();
    Serial.println("Front LED turned ON");
}

void turnOffFrontLED() {
    frontLED.off();
    Serial.println("Front LED turned OFF");
}
