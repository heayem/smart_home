#include "CURTAIN.h"

CURTAIN::CURTAIN(uint8_t pin) : _pin(pin) {}

CURTAIN::~CURTAIN() {}

void CURTAIN::begin() {
    pinMode(_pin, OUTPUT);
    off();
}

void CURTAIN::on() {
    digitalWrite(_pin, HIGH);
    _state = true;
}

void CURTAIN::off() {
    digitalWrite(_pin, LOW);
    _state = false;
}

void CURTAIN::toggle() {
    isOn() ? off() : on();
}

bool CURTAIN::isOn() const {
    return _state;
}
