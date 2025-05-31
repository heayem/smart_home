#include <Arduino.h>
#include "command/led/commands.h"
#include "controller/front_led/FrontLED.h"
#include "controller/behind_led/BehindLED.h"
#include "views/screens/TouchScreen.h"

void setup()
{
  Serial.begin(115200);

  // setup led
  setupFrontLED();
  setupBehindLED();

  // cmd controller led
  printCommandGuide();

  // touch screen
  initTouchScreen();
}

void loop()
{
  if (Serial.available())
  {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    handleSerialCommand(cmd);
  }

  handleTouch();
}
