#include <Arduino.h>
#include "BehindLED.h"
#include "model/led/LED.h"  

static LED behindLED(4);

void setupBehindLED() {
    behindLED.begin();
    Serial.println("Behind LED initialized");
}

void turnOnBehindLED() {
    behindLED.on();
    Serial.println("Behind LED turned ON");
}

void turnOffBehindLED() {
    behindLED.off();
    Serial.println("Behind LED turned OFF");
}
