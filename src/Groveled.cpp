#include "GroveLED.hpp"

GroveLED::GroveLED(int p) : pin(p) {}

void GroveLED::init() {
    pinMode(pin, OUTPUT);
    OFF();  // LED is off in the begining
}

void GroveLED::ON() {
    digitalWrite(pin, HIGH);
}

void GroveLED::OFF() {
    digitalWrite(pin, LOW);
}

void GroveLED::blink(int period) {
    ON();
    delay(period);
    OFF();
}
