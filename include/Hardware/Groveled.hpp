#ifndef GROVE_LED_HPP
#define GROVE_LED_HPP

#include <Arduino.h>
#include "Hardware.hpp"

class GroveLED : public Hardware {
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