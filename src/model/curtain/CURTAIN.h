#pragma once
#include <Arduino.h>

class CURTAIN {
public:
    CURTAIN(uint8_t pin);
    virtual ~CURTAIN();

    virtual void begin();
    virtual void on();
    virtual void off();
    virtual void toggle();
    virtual bool isOn() const;

protected:
    uint8_t _pin;
    bool _state = false;
};
