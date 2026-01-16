#include "Hardware/GroveLED.hpp"
#include <Arduino.h>

GroveLED::GroveLED(int pin) : pin(pin) { // constructor with pin initialization
	pinMode(pin, OUTPUT);
	OFF();
}

void GroveLED::ON() { // turn on the LED
	digitalWrite(pin, HIGH);
}

void GroveLED::OFF() { // turn off the LED
	digitalWrite(pin, LOW);
}

void GroveLED::blink(int period) { // LED blinks with period in ms (blocking)
	if (period <= 0) return;
	ON();
	delay(period / 2);
	OFF();
	delay(period / 2);
}