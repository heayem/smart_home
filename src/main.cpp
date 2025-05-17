#include <Arduino.h>
#include "command/led/commands.h"
// #include "network/WiFiConnector.h"
// #include "mqtt/MQTTService.h"
// #include "bluetooth/BluetoothConnector.h"


// WiFiConnector wifi("iphone", "12345678");
// MQTTService mqtt;
// BluetoothConnector bt;

void setup()
{
  Serial.begin(115200);
  printCommandGuide();

  // wifi.connect();
  // mqtt.begin();
  // bt.begin("ESP32_LED_BT");
  // bt.setCommandHandler(handleSerialCommand);
}

void loop()
{
  if (Serial.available())
  {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    handleSerialCommand(cmd);
  }

  // bt.listen();  
  // mqtt.loop();
}
