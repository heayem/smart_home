#include <Arduino.h>
#include "command/led/commands.h"
#include "network/WiFiConnector.h"
#include "mqtt/MQTTService.h"

WiFiConnector wifi("iphone", "12345678");
MQTTService mqtt;

void setup()
{
  Serial.begin(115200);
  wifi.connect();
  mqtt.begin();
}

void loop()
{
  if (Serial.available())
  {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    handleSerialCommand(cmd);
  }
  mqtt.loop(); // Add this if required by your MQTT library
}