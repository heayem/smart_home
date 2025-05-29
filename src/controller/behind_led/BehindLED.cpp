/**
 * This file contains functions for controlling the behind LED.
 * It uses the LED class to create an instance of the behind LED.
 * The setupBehindLED function initializes the behind LED.
 * The turnOnBehindLED and turnOffBehindLED functions turn the behind LED on and off, respectively.
 * The MQTTService class is used to publish the state of the behind LED to the MQTT broker.
 */
#include <Arduino.h>
#include "BehindLED.h"
#include "model/led/LED.h"  
// #include "mqtt/MQTTService.h"

// extern MQTTService mqtt;

static LED behindLED(4);

/**
 * Initializes the behind LED.
 */
void setupBehindLED() {
    behindLED.begin();
    Serial.println("Behind LED initialized");
}

/**
 * Turns on the behind LED.
 */
void turnOnBehindLED() {
    behindLED.on();
    Serial.println("Behind LED turned ON");
    // mqtt.publish("smart_home/behind_led", "on");
}

/**
 * Turns off the behind LED.
 */
void turnOffBehindLED() {
    behindLED.off();
    Serial.println("Behind LED turned OFF");
    // mqtt.publish("smart_home/behind_led", "off");
}



