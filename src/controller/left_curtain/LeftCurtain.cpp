#include "LeftCurtain.h"
#include "model/curtain/CURTAIN.h"

// Define stepper motor pins and steps per revolution
#define LEFT_CURTAIN_PIN1 32
#define LEFT_CURTAIN_PIN2 33
#define LEFT_CURTAIN_PIN3 34
#define LEFT_CURTAIN_PIN4 35
#define STEPS_PER_REV 200

// Create CURTAIN instance for the stepper motor
static CURTAIN leftCurtain(LEFT_CURTAIN_PIN1, LEFT_CURTAIN_PIN2, LEFT_CURTAIN_PIN3, LEFT_CURTAIN_PIN4, STEPS_PER_REV);

/**
 * Initializes the left curtain stepper motor.
 */
void setupLeftCurtain() {
    leftCurtain.begin();
}

/**
 * Opens the left curtain.
 */
void onLeftCurtain() {
    leftCurtain.open();
}

/**
 * Closes the left curtain.
 */
void offLeftCurtain() {
    leftCurtain.close();
}

/**
 * Checks if the curtain is open.
 */
bool isOnLeftCurtain() {
    return leftCurtain.isOpen();
}

/**
 * Gets the current open level (0–100).
 */
uint8_t getLeftCurtainLevel() {
    return leftCurtain.getLevel();
}

/**
 * Sets the curtain to the desired open level (0–100).
 */
void setLeftCurtainLevel(uint8_t level) {
    leftCurtain.setLevel(level);
}

/**
 * Toggles the curtain between open and closed.
 */
void toggleLeftCurtain() {
    leftCurtain.toggle();
}
