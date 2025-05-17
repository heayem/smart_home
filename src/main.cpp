#include <Arduino.h>
#include "command/led/commands.h"
#include "network/WiFiConnector.h"

WiFiConnector wifi("iphone", "12345678");

void setup()
{
  Serial.begin(115200);
  wifi.connect();
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