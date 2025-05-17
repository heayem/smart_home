#include "LED.h"

LED::LED(uint8_t pin) : _pin(pin) {}

LED::~LED() {}

void LED::begin() {
    pinMode(_pin, OUTPUT);
    off();
}

void LED::on() {
    digitalWrite(_pin, HIGH);
    _state = true;
}

void LED::off() {
    digitalWrite(_pin, LOW);
    _state = false;
}

void LED::toggle() {
    isOn() ? off() : on();
}

bool LED::isOn() const {
    return _state;
}
