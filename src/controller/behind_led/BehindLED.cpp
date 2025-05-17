#include <Arduino.h>
#include "BehindLED.h"
#include "model/led/LED.h"  
#include "mqtt/MQTTService.h"

extern MQTTService mqtt;

static LED behindLED(4);

void setupBehindLED() {
    behindLED.begin();
    Serial.println("Behind LED initialized");
}

void turnOnBehindLED() {
    behindLED.on();
    Serial.println("Behind LED turned ON");
    mqtt.publish("smart_home/behind_led", "on");
}

void turnOffBehindLED() {
    behindLED.off();
    Serial.println("Behind LED turned OFF");
    mqtt.publish("smart_home/behind_led", "off");
}
