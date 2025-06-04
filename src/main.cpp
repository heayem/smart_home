#include <Arduino.h>
#include "command/led/LedCommands.h"
#include "controller/front_led/FrontLED.h"
#include "controller/behind_led/BehindLED.h"
#include "controller/left_curtain/LeftCurtain.h"

#include "views/screens/TouchScreen.h"
#include "network/WiFiConnector.h"
#include "mqtt/MQTTService.h"

const char *SSID = "Wokwi-GUEST";
const char *PASSWORD = "";

const char *MQTT_SERVER = "bf651860e15d4d2691514198dfecafb3.s1.eu.hivemq.cloud";
const int MQTT_PORT = 8883;
const char *MQTT_CLIENT_ID = "ESP32Client";
const char *MQTT_TOPIC = "flutter/led";

WiFiConnector wifi(SSID, PASSWORD);

MQTTService mqtt;

void setup()
{
  Serial.begin(115200);

  wifi.connect();

  if (wifi.isConnected())
  {
    Serial.println("Connected and ready!");
    mqtt.begin(MQTT_SERVER, MQTT_PORT, MQTT_CLIENT_ID);
    mqtt.subscribe(MQTT_TOPIC);
  }
  else
  {
    Serial.println("Connection failed.");
  }

  setupFrontLED();
  setupBehindLED();
  setupLeftCurtain();
  printCommandGuide();
  initTouchScreen();
}

unsigned long lastSent = 0;
const unsigned long interval = 5000;

void loop()
{
  if (Serial.available())
  {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    handleSerialLedCommand(cmd);
  }

  handleTouch();

  mqtt.loop();

  // if (millis() - lastSent > interval)
  // {
  //   mqtt.publish(MQTT_TOPIC, "1");
  //   lastSent = millis();
  // }
}
