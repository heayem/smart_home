#include "WiFiConnector.h"
#include <Arduino.h>

WiFiConnector::WiFiConnector(const char* ssid, const char* password)
    : _ssid(ssid), _password(password) {}

void WiFiConnector::connect() {
    WiFi.begin(_ssid, _password);
    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi connected!");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

bool WiFiConnector::isConnected() const {
    return WiFi.status() == WL_CONNECTED;
}
