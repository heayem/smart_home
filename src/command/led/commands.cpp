#include <map>
#include "commands.h"
#include "controller/front_led/FrontLED.h"
#include "controller/behind_led/BehindLED.h"

static std::map<String, void (*)()> commandMap = {
    {"1", turnOnFrontLED},
    {"2", turnOffFrontLED},
    {"3", turnOnBehindLED},
    {"4", turnOffBehindLED},
};

void printCommandGuide()
{
    Serial.println("===== Available Commands =====");
    Serial.println("1: Turn ON Front LED");
    Serial.println("2: Turn OFF Front LED");
    Serial.println("3: Turn ON Behind LED");
    Serial.println("4: Turn OFF Behind LED");
    Serial.println("==============================");
    Serial.println("=>");
}

void handleSerialCommand(const String &command)
{

    auto it = commandMap.find(command);
    if (it != commandMap.end())
    {
        it->second();
    }
    else
    {
        Serial.println("Unknown command \n");
        printCommandGuide();
    }
}