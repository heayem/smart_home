#include <map>
#include "commands.h"
#include "controller/front_led/FrontLED.h"
#include "controller/behind_led/BehindLED.h"

static std::map<String, void(*)()> commandMap = {
    {"1", turnOnFrontLED},
    {"2", turnOffFrontLED},
    {"3", turnOnBehindLED},
    {"4", turnOffBehindLED},
};

void handleSerialCommand(const String& command) {
    auto it = commandMap.find(command);
    if (it != commandMap.end()) {
        it->second();
    } else {
        Serial.println("Unknown command");
    }
}