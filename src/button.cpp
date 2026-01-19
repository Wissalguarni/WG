#include "Hardware/Button.hpp"

Button::Button(int buttonPin, GroveLCD* lcdScreen) : pin(buttonPin), lcd(lcdScreen) {}

void Button::init() { // initialization of the button
    pinMode(pin, INPUT_PULLUP); //if pin is not connected, it reads HIGH
    lastState = this->isPressed();

}

bool Button::isPressed() { // check if button is pressed 
    bool currentState = digitalRead(pin);

    if (lastState == HIGH && currentState == LOW) {
        lastState = currentState;
        delay(50); // antidebounce delay
        return true;
    }
    lastState = currentState;
    return false;
}

