#include "Hardware/Button.hpp"

Button::Button(int buttonPin, GroveLCD* lcdScreen) : pin(buttonPin), lcd(lcdScreen) {}

void Button::init() {
    pinMode(pin, INPUT_PULLUP); //si appuyé = LOW
    lastState = this->isPressed();

}

bool Button::isPressed() {
    bool currentState = digitalRead(pin);

    if (lastState == HIGH && currentState == LOW) {
        lastState = currentState;
        delay(50); // anti-rebond simple
        return true;
    }
    lastState = currentState;
    return false;
}

