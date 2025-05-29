#include <Arduino.h>
#include "command/led/commands.h"
#include "controller/front_led/FrontLED.h"
#include "controller/behind_led/BehindLED.h"

void setup()
{
  Serial.begin(115200);
  setupFrontLED();    
  setupBehindLED();
  printCommandGuide();
}

void loop()
{

  if (Serial.available())
  {

    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    handleSerialCommand(cmd);
  }
}
