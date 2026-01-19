#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Hardware.hpp"
#include "GroveLCD.hpp" 
#include <Arduino.h>
// Button class to handle button input
class Button : public Hardware {
private:
    int pin;           // button pin number
    bool lastState;    // last button state
    GroveLCD* lcd;     // pointer to LCD for displaying messages

public:
    Button(int buttonPin, GroveLCD* lcdScreen);
    void init();// initialize button
    bool isPressed();// check if button is pressed
};

#endif