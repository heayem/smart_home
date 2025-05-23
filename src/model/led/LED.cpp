#include "LED.h"

LED::LED(uint8_t pin) : _pin(pin) {
    // Constructor, save pin to private variable
}

LED::~LED() {
    // Destructor, do nothing
}

void LED::begin() {
    // Initialize LED pin as output and turn off
    pinMode(_pin, OUTPUT);
    off();
}

void LED::on() {
    // Set pin high to turn on LED
    digitalWrite(_pin, HIGH);
    // Update state variable
    _state = true;
}

void LED::off() {
    // Set pin low to turn off LED
    digitalWrite(_pin, LOW);
    // Update state variable
    _state = false;
}

void LED::toggle() {
    // Toggle LED state
    isOn() ? off() : on();
}

bool LED::isOn() const {
    // Return current state
    return _state;
}

