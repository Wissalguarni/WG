#ifndef CONTINUELECTOR_HPP
#define CONTINUESELECTOR_HPP

#include "Hardware/GroveLCD.hpp"
#include "Hardware/Button.hpp"
// Enum for game modes
enum Continue {
    YES,
    NO
};

class ContinueSelector {
private:
    GroveLCD& lcd;          
    Button& validateButton; // button to validate selection
    int potPin;// potentiometer pin
    Continue currentChoice;// currently selected choice
    int lastPotValue;// to track changes

    void displayMenu();

public:
    ContinueSelector(GroveLCD& lcd, Button& button, int potPin);// constructor
    Continue selectContinue();// select continue mode
};

#endif
