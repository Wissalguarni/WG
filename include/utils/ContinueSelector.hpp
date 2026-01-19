#ifndef CONTINUELECTOR_HPP
#define CONTINUESELECTOR_HPP

#include "Hardware/GroveLCD.hpp"
#include "Hardware/Button.hpp"
// Enum for game modes
enum Continue {
    YES,
    NO
};
// ContinueSelector class to handle continue selection
class ContinueSelector {
private:
    GroveLCD& lcd;          
    Button& validateButton; // button to validate selection
    int potPin;// potentiometer pin
    Continue currentChoice;// currently selected choice
    int lastPotValue;// to track changes

    void displayMenu();// display continue menu

public:
    ContinueSelector(GroveLCD& lcd, Button& button, int potPin);// constructor
    Continue selectContinue();// select continue mode
};

#endif
