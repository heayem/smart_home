#ifndef MQTT_SERVICE_H
#define MQTT_SERVICE_H

class MQTTService {
public:
    void begin(const char* server, int port, const char* clientId);
    void subscribe(const char* topic);
    void loop();
    void publish(const char* topic, const char* payload);
    bool isConnected();
};

#endif
