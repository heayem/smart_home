#ifndef MQTT_SERVICE_H
#define MQTT_SERVICE_H

class MQTTService {
public:
    void begin();
    void loop();
    void publish(const char* topic, const char* payload);
};

#endif
