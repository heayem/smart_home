#include "CURTAIN.h"

// Constructor, save pin to private variable
CURTAIN::CURTAIN(uint8_t pin) : _pin(pin) {}

// Destructor, no need to do anything
CURTAIN::~CURTAIN() {}

// Initialize curtain by setting pin as output and turning off
void CURTAIN::begin() {
    pinMode(_pin, OUTPUT);
    off();
}

// Turn curtain on by setting pin high
void CURTAIN::on() {
    digitalWrite(_pin, HIGH);
    _state = true;
}

// Turn curtain off by setting pin low
void CURTAIN::off() {
    digitalWrite(_pin, LOW);
    _state = false;
}

// Toggle curtain, if it's on, turn it off, if it's off, turn it on
void CURTAIN::toggle() {
    isOn() ? off() : on();
}

// Get current state of the curtain
bool CURTAIN::isOn() const {
    return _state;
}

