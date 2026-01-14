#include "Utils/ContinueSelector.hpp"
#include <Arduino.h>

ContinueSelector::ContinueSelector(GroveLCD& lcd, Button& button, int potPin)
    : lcd(lcd), validateButton(button), potPin(potPin),currentChoice(YES), lastPotValue(-1) {}

void ContinueSelector::displayMenu() {// display the menu on the LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(currentChoice == YES ? "> Yes" : "  Yes");
    lcd.setCursor(0, 1);
    lcd.print(currentChoice == NO ? "> No" : "  No");
}

Continue ContinueSelector::selectContinue() {// select continue mode
    displayMenu();

    while (true) {
        int potValue = analogRead(potPin);

        Continue newChoice = (potValue < 512) ? YES : NO;

        if (newChoice != currentChoice) {
            currentChoice = newChoice;
            displayMenu();
        }

        if (validateButton.isPressed()) { // note : plus de ->, maintenant .
            lcd.clear();
            delay(200); // anti-bounce
            return currentChoice;
        }

        delay(50);
    }
}
