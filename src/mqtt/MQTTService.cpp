#include "MQTTService.h"
#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
    String message;
    for (int i = 0; i < length; i++) {
        message += (char)payload[i];
    }
    Serial.printf("Received on topic %s: %s\n", topic, message.c_str());

    if (message == "on") {
        digitalWrite(2, HIGH);
    } else if (message == "off") {
        digitalWrite(2, LOW);
    }
}

void MQTTService::begin() {
    client.setServer("bf651860e15d4d2691514198dfecafb3.s1.eu.hivemq.cloud", 1883);  
    client.setCallback(callback);
}

void MQTTService::loop() {
    if (!client.connected()) {
        while (!client.connected()) {
            Serial.print("Connecting to MQTT...");
            if (client.connect("ESP32Client")) {
                Serial.println("connected");
                client.subscribe("flutter/led");
            } else {
                Serial.print("failed, rc=");
                Serial.println(client.state());
                delay(2000);
            }
        }
    }
    client.loop();
}

void MQTTService::publish(const char* topic, const char* payload) {
    client.publish(topic, payload);
}
