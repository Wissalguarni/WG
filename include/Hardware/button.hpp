#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Hardware.hpp"
#include "GroveLCD.hpp" 
#include <Arduino.h>

class Button : public Hardware {
private:
    int pin;           // Pin du bouton
    bool lastState;    // état précédent
    GroveLCD* lcd;     // pointeur vers le LCD pour afficher les messages

public:
    Button(int buttonPin, GroveLCD* lcdScreen);
    void init();
    bool isPressed();
};

#endif
