#ifndef GROVE_LED_HPP
#define GROVE_LED_HPP

#include "Hardware/Hardware.hpp"
#include <Arduino.h>

class GroveLED : public Hardware{
private:
    int pin;

public:
    GroveLED(int pin);
    void init() override {}; // no init needed for GroveLED
    void ON();
    void OFF();
    void blink(int period); // LED blinks with period in ms (blocking)
     ~GroveLED() {};
};

#endif