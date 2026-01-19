#ifndef GROVE_LED_HPP
#define GROVE_LED_HPP

#include <Arduino.h>
#include "Hardware.hpp"
// GroveLED class to handle Grove LED functionalities

class GroveLED : public Hardware {
private:
    int pin;

public:
    GroveLED(int pin);
    void init() override {}; // no init needed for GroveLED
    void ON();// turn LED on
    void OFF();// turn LED off
    void blink(int period); // LED blinks with period in ms (blocking)
     ~GroveLED() {};
};

#endif