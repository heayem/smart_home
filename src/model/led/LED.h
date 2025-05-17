#pragma once
#include <Arduino.h>

class LED {
public:
    LED(uint8_t pin);
    virtual ~LED();

    virtual void begin();
    virtual void on();
    virtual void off();
    virtual void toggle();
    virtual bool isOn() const;

protected:
    uint8_t _pin;
    bool _state = false;
};
