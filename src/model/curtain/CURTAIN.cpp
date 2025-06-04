#include "CURTAIN.h"

CURTAIN::CURTAIN(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, int stepsPerRev)
  : _stepper(stepsPerRev, pin1, pin3, pin2, pin4), _stepsPerRev(stepsPerRev) {}

CURTAIN::~CURTAIN() {}

void CURTAIN::begin() {
  _stepper.setSpeed(60);  // RPM
}

void CURTAIN::open() {
  moveToLevel(100);
  _isOpen = true;
}

void CURTAIN::close() {
  moveToLevel(0);
  _isOpen = false;
}

void CURTAIN::toggle() {
  _isOpen ? close() : open();
}

bool CURTAIN::isOpen() const {
  return _isOpen;
}

void CURTAIN::setLevel(uint8_t level) {
  if (level > 100) level = 100;
  moveToLevel(level);
}

uint8_t CURTAIN::getLevel() const {
  return _level;
}

void CURTAIN::moveToLevel(uint8_t targetLevel) {
  int targetSteps = map(targetLevel, 0, 100, 0, _stepsPerRev);
  int currentSteps = map(_level, 0, 100, 0, _stepsPerRev);
  int stepDiff = targetSteps - currentSteps;

  _stepper.step(stepDiff);
  _level = targetLevel;
}

void CURTAIN::stop() {
  // Placeholder - Stepper does not require stopping logic like DC motors
}
