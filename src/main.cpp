#include <Arduino.h>
#include <Wire.h>

#include "Hardware/Button.hpp"
#include "Hardware/GroveLCD.hpp"

const int BUTTON_PIN = 14; // D5 = GPIO14 (ESP8266)
GroveLCD lcd;
Button button(BUTTON_PIN, &lcd);

void setup() {
    Serial.begin(115200);
    delay(1000);
    Wire.begin();   // I2C init
    lcd.init();     // LCD init

    lcd.setBacklight(0, 0, 255);
    lcd.print("LCD Ready");
    delay(1500);

    // This will display "Appuyez sur le bouton !" and WAIT
    button.init();

    // After button press
    lcd.setBacklight(0, 255, 0);
    lcd.clear();
    lcd.print("Init OK");
    delay(1000);

}

void loop() {
    if (button.isPressed()) {
        lcd.displayScore(1, 0);
        delay(1000);

        lcd.displayScore(1, 1);
        delay(1000);

        lcd.displayGameOver(1, 1);
        delay(2000);

        lcd.displayVainqueur("Joueur 1");
        delay(2000);
    }
}
