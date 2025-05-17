#ifndef WIFI_CONNECTOR_H
#define WIFI_CONNECTOR_H

#include <WiFi.h> // Use <ESP8266WiFi.h> for ESP8266

class WiFiConnector {
public:
    WiFiConnector(const char* ssid, const char* password);
    void connect();
    bool isConnected() const;

private:
    const char* _ssid;
    const char* _password;
};

#endif
