#include <Arduino.h>
#include "Hardware/GroveLCD.hpp"
// TEST OF METHODS IN CLASS GroveLCD
GroveLCD lcd;

void setup() {
    lcd.init();

    lcd.setCursor(0, 0);
    lcd.print("Hello");

    lcd.setCursor(0, 1);
    lcd.print("TEST COMPLETE");
}

void loop() {
}