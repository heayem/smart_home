#pragma once
#include <Arduino.h>

/**
 * LED class represents a physical LED connected to a digital output pin on the board.
 *
 * It provides methods to control the LED, such as begin(), on(), off(), toggle(), and isOn().
 *
 * The begin() method initializes the LED by setting the pin as an output and turning the LED off.
 *
 * The on() method turns the LED on by setting the pin high.
 *
 * The off() method turns the LED off by setting the pin low.
 *
 * The toggle() method toggles the state of the LED.
 *
 * The isOn() method returns the current state of the LED.
 */
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

