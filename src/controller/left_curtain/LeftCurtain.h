#ifndef LEFT_CURTAIN_H
#define LEFT_CURTAIN_H

#include <Arduino.h>

/**
 * Initializes the left curtain stepper motor.
 */
void setupLeftCurtain();

/**
 * Opens the left curtain.
 */
void onLeftCurtain();

/**
 * Closes the left curtain.
 */
void offLeftCurtain();

/**
 * Check if the left curtain is open.
 */
bool isOnLeftCurtain();

/**
 * Sets the curtain to a specific open percentage (0-100).
 */
void setLeftCurtainLevel(uint8_t level);

/**
 * Gets the current open percentage of the curtain (0-100).
 */
uint8_t getLeftCurtainLevel();

/**
 * Toggles the curtain between open and closed.
 */
void toggleLeftCurtain();

#endif
