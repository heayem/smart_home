#pragma once
#include <Arduino.h>

/**
 * This class represents a physical curtain connected to a digital output pin on the board.
 *
 * It provides methods to control the curtain, such as begin(), on(), off(), toggle(), and isOn().
 *
 * The begin() method initializes the curtain by setting the pin as an output and turning the curtain off.
 *
 * The on() method turns the curtain on by setting the pin high.
 *
 * The off() method turns the curtain off by setting the pin low.
 *
 * The toggle() method toggles the state of the curtain.
 *
 * The isOn() method returns the current state of the curtain.
 */
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

