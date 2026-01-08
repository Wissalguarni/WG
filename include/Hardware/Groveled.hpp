#ifndef GROVE_LED_HPP
#define GROVE_LED_HPP

#include "Hardware/Hardware.hpp"
#include <Arduino.h>

class GroveLED : public Hardware{
private:
    int pin;

public:
    GroveLED(int pin);       // constructor
    void init() override;
    //void ON() override;
    //void OFF() override;
    //void blink(int period) override;
};

#endif