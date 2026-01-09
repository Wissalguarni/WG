#include <Arduino.h>
#include "Hardware/GroveLED.hpp"

// Pin Grove LED (D7 = GPIO13)
const int LED_PIN = 13;

GroveLED led(LED_PIN);

void setup() {
    Serial.begin(115200);
    Serial.println("Testing GroveLED...");

    // Pas besoin d'init car init() est vide
}

void loop() {
    Serial.println("LED ON");
    led.ON();
    delay(1000);

    Serial.println("LED OFF");
    led.OFF();
    delay(1000);

    Serial.println("LED BLINK 500ms");
    led.blink(500); // clignote 1 fois (500ms HIGH + 500ms LOW)

    Serial.println("LED BLINK 200ms");
    led.blink(200); // clignote 1 fois (200ms HIGH + 200ms LOW)
}
