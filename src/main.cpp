#include <Arduino.h>

#include <Arduino.h>
#include "GroveLCD.hpp"
// TEST OF METHODS IN CLASS GroveLCD
GroveLCD lcd;

void setup() {
    lcd.init();

    lcd.setCursor(0, 0);
    lcd.displaymsg("Hello");

    lcd.setCursor(0, 1);
    lcd.displaymsg("TEST COMPLETE");
}

void loop() {
}