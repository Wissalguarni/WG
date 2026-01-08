#include "Hardware/Button.hpp"

Button::Button(int buttonPin, GroveLCD* lcdScreen) 
    : pin(buttonPin), lastState(false), lcd(lcdScreen) {}

void Button::init() {
    pinMode(pin, INPUT_PULLUP); //si appuyé = LOW
    lastState = this->isPressed();

    if (lcd) {
        lcd->clear();
        lcd->setCursor(0, 0);
        lcd->print("Appuyez sur le");
        lcd->setCursor(0, 1);
        lcd->print("bouton !");
    }while (!isPressed()) {
        delay(10);
    }

    if (lcd) {
        lcd->clear();
        lcd->setCursor(0, 0);
        lcd->print("Merci !");
    }
    delay(1000);
}

bool Button::isPressed() {
    bool currentState = digitalRead(pin);

    if (lastState == HIGH && currentState == LOW) {
        lastState = currentState;
        delay(50); // anti-rebond simple
        return true;
    }
    return false;
}
