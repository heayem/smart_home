#include <Arduino.h>
#include "../src/front_led/FrontLED.h"
#include "../src/behind_led/BehindLED.h"

void setup()
{
  Serial.begin(115200);
  setupFrontLED();
  setupBehindLED();

  Serial.println("Enter: 1 'front on', 2 'front off', 3 'behind on', or 4 'behind off'");
}

void loop()
{
  if (Serial.available())
  {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "1")
    {
      turnOnFrontLED();
    }
    else if (command == "2")
    {
      turnOffFrontLED();
    }
    else if (command == "3")
    {
      turnOnBehindLED();
    }
    else if (command == "4")
    {
      turnOffBehindLED();
    }
    else
    {
      Serial.println("Unknown command");
    }
  }
}
