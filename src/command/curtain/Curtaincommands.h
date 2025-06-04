// This header file declares functions for handling serial commands and printing command guides.
#include <Arduino.h>

// Processes a given command string and executes the corresponding function.
void handleSerialCurtainCommand(const String& command);

// Outputs the list of available commands to the serial interface.
void printCurtainCommandGuide();
