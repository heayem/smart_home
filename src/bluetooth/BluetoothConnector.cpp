#include "BluetoothConnector.h"

void BluetoothConnector::begin(const String& deviceName) {
    btSerial.begin(deviceName);
    Serial.println("Bluetooth started as: " + deviceName);
}

void BluetoothConnector::setCommandHandler(void (*handler)(const String&)) {
    commandHandler = handler;
}

void BluetoothConnector::listen() {
    if (btSerial.available()) {
        String cmd = btSerial.readStringUntil('\n');
        cmd.trim();
        if (commandHandler) {
            commandHandler(cmd);
        }
    }
}
