#include <Arduino.h>
#include "Hardware/GroveLCD.hpp"
#include "Hardware/Potentio.hpp"
#include <Wire.h>

const int POT_PIN = A0; // broche analogique ESP8266

GroveLCD lcd;
Potentio potentiometer(POT_PIN, &lcd);

void setup() {
    Serial.begin(115200);
    Wire.begin();
    lcd.init();

    potentiometer.init(); // affiche test puis valeur initiale
}

void loop() {
    int choice = potentiometer.getChoice(5);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(("Choice: " + String(choice)).c_str());

    delay(500);
}
