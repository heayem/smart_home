#include <Arduino.h>
#include "FrontLED.h"
#include "model/led/LED.h"  
// #include "mqtt/MQTTService.h"

// extern MQTTService mqtt;

static LED frontLED(2);

void setupFrontLED() {
    frontLED.begin();
    Serial.println("Front LED initialized");
}

void turnOnFrontLED() {
    frontLED.on();
    Serial.println("Front LED turned ON");
    // mqtt.publish("smart_home/front_led", "on");
}

void turnOffFrontLED() {
    frontLED.off();
    Serial.println("Front LED turned OFF");
    // mqtt.publish("smart_home/front_led", "off");
}
