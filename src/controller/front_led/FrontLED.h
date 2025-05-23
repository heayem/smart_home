/**
 * This file contains functions for controlling the front LED.
 * It uses the LED class to create an instance of the front LED.
 * The setupFrontLED function initializes the front LED.
 * The turnOnFrontLED and turnOffFrontLED functions turn the front LED on and off, respectively.
 * The MQTTService class is used to publish the state of the front LED to the MQTT broker.
 */
#ifndef FRONT_LED_H
#define FRONT_LED_H

/**
 * Initializes the front LED.
 */
void setupFrontLED();

/**
 * Turns on the front LED.
 */
void turnOnFrontLED();

/**
 * Turns off the front LED.
 */
void turnOffFrontLED();

#endif
