#pragma once
#include <Arduino.h>
#include <Stepper.h>

/**
 * Curtain control class using Stepper motor.
 */
class CURTAIN
{
public:
    CURTAIN(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, int stepsPerRev);
    virtual ~CURTAIN();

    virtual void begin();
    virtual void open();
    virtual void close();
    virtual void stop();
    virtual void toggle();
    virtual bool isOpen() const;
    virtual void setLevel(uint8_t level);
    virtual uint8_t getLevel() const;

protected:
    Stepper _stepper;
    int _stepsPerRev;
    bool _isOpen = false;
    uint8_t _level = 0;

    void moveToLevel(uint8_t targetLevel);
};
