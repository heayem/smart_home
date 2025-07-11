#include "MQTTService.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

WiFiClientSecure espSecureClient;
PubSubClient client(espSecureClient);

const char* mqttUsername = "hivemq.webclient.1747456168970";
const char* mqttPassword = "D?Z4!%5jCcv1b0S>iBgP";

extern void handleSerialLedCommand(const String &cmd); 

void callback(char* topic, byte* payload, unsigned int length) {
    String message;
    for (unsigned int i = 0; i < length; i++) {
        message += (char)payload[i];
    }
    Serial.printf("Received on topic %s: %s\n", topic, message.c_str());
    handleSerialLedCommand(message);

    if (strcmp(topic, "flutter/led") == 0) {
        if (message == "on") digitalWrite(2, HIGH);
        else if (message == "off") digitalWrite(2, LOW);
    }
}

void MQTTService::begin(const char* server, int port, const char* clientId) {
    espSecureClient.setInsecure();
    client.setServer(server, port);
    client.setCallback(callback);

    while (!client.connected()) {
        Serial.print("Connecting to MQTT... ");
        if (client.connect(clientId, mqttUsername, mqttPassword)) {
            Serial.println("connected!");
        } else {
            Serial.print("failed, rc=");
            Serial.println(client.state());
            delay(2000);
        }
    }
}

void MQTTService::subscribe(const char* topic) {
    client.subscribe(topic);
}

void MQTTService::loop() {
    if (!client.connected()) {
        Serial.println("MQTT disconnected, retrying...");
        begin("bf651860e15d4d2691514198dfecafb3.s1.eu.hivemq.cloud", 8883, "ESP32Client");
    }
    client.loop();
}

void MQTTService::publish(const char* topic, const char* payload) {
    client.publish(topic, payload);
}

bool MQTTService::isConnected() {
    return client.connected();
}
