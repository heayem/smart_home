/**
 * This file contains functions for controlling the front LED.
 * It uses the LED class to create an instance of the front LED.
 * The setupFrontLED function initializes the front LED.
 * The turnOnFrontLED and turnOffFrontLED functions turn the front LED on and off, respectively.
 */
#include <Arduino.h>
#include "FrontLED.h"
#include "model/led/LED.h"

static LED frontLED(17);

/**
 * Initializes the front LED.
 */
void setupFrontLED()
{
    frontLED.begin();
    Serial.println("Front LED initialized");
}

/**
 * Turns on the front LED.
 */
void turnOnFrontLED()
{
    frontLED.on();
    Serial.println("Front LED turned ON");
}

/**
 * Turns off the front LED.
 */
void turnOffFrontLED()
{
    frontLED.off();
    Serial.println("Front LED turned OFF");
}
