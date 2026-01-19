#include "Utils/GameSelector.hpp"
#include <Arduino.h>

GameSelector::GameSelector(GroveLCD& lcd, Button& button, int potPin)
    : lcd(lcd), validateButton(button), potPin(potPin), currentMode(SINGLEPLAYER), lastPotValue(-1) {}

void GameSelector::displayMenu() {// display the menu on the LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(currentMode == SINGLEPLAYER ? "> Solo" : "  Solo");
    lcd.setCursor(0, 1);
    lcd.print(currentMode == MULTIPLAYER ? "> Multi" : "  Multi");
}

GameMode GameSelector::selectMode() {// select game mode
    displayMenu();

    while (true) {
        int potValue = analogRead(potPin);

        GameMode newMode = (potValue < 512) ? SINGLEPLAYER : MULTIPLAYER;

        if (newMode != currentMode) {
            currentMode = newMode;
            displayMenu();
        }

        if (validateButton.isPressed()) { 
            lcd.clear();
            delay(200); // anti-bounce
            return currentMode;
        }

        delay(50);
    }
}
