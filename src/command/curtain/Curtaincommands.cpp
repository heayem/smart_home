#include <map>
#include "CurtainCommands.h"
#include "controller/front_led/FrontLED.h"
#include "controller/behind_led/BehindLED.h"

/**
 * Map of available commands. Each command is associated with a function
 * that will be executed when the command is received.
 */
static std::map<String, void (*)()> commandMap = {
    {"1", turnOnFrontLED},
    {"2", turnOffFrontLED},
    {"3", turnOnBehindLED},
    {"4", turnOffBehindLED},
};

/**
 * Print the command guide to the serial console.
 */
void printCurtainCommandGuide()
{
    Serial.println("===== Available Commands =====");
    Serial.println("1: Turn ON Front LED");
    Serial.println("2: Turn OFF Front LED");
    Serial.println("3: Turn ON Behind LED");
    Serial.println("4: Turn OFF Behind LED");
    Serial.println("==============================");
    Serial.println("=>");
}

/**
 * Handle a serial command. If the command is found in the command map,
 * execute the associated function. Otherwise, print the command guide.
 *
 * @param command The command to handle.
 */
void handleSerialCurtainCommand(const String &command)
{
    auto it = commandMap.find(command);
    if (it != commandMap.end())
    {
        it->second(); // Execute the associated function
    }
    else
    {
        Serial.println("Unknown command \n");
        printCurtainCommandGuide(); // Print the command guide
    }
}
