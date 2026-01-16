#include "Hardware/Button.hpp"

Button::Button(int buttonPin, GroveLCD* lcdScreen) : pin(buttonPin), lcd(lcdScreen) {}

void Button::init() { // initialization of the button
    pinMode(pin, INPUT_PULLUP); //si appuyé = LOW
    lastState = this->isPressed();

}

bool Button::isPressed() { // check if button is pressed with simple debounce
    bool currentState = digitalRead(pin);

    if (lastState == HIGH && currentState == LOW) {
        lastState = currentState;
        delay(50); // anti-rebond simple
        return true;
    }
    lastState = currentState;
    return false;
}

