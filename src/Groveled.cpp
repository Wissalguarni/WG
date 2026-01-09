#include "Hardware/GroveLED.hpp"
#include <Arduino.h>

GroveLED::GroveLED(int pin) : pin(pin) {
	pinMode(pin, OUTPUT);
	OFF();
}

void GroveLED::ON() {
	digitalWrite(pin, HIGH);
}

void GroveLED::OFF() {
	digitalWrite(pin, LOW);
}

void GroveLED::blink(int period) {
	if (period <= 0) return;
	ON();
	delay(period / 2);
	OFF();
	delay(period / 2);
}