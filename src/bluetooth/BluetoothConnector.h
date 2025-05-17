#pragma once
#include <BluetoothSerial.h>

class BluetoothConnector {
public:
    void begin(const String& deviceName);
    void listen();
    void setCommandHandler(void (*handler)(const String&));

private:
    BluetoothSerial btSerial;
    void (*commandHandler)(const String&) = nullptr;
};
