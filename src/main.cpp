#include <Arduino.h>

#include <Arduino.h>
#include "Hardware/GroveLCD.hpp"
// TEST OF METHODS IN CLASS GroveLCD
GroveLCD myLCD;  // Create an instance of your LCD class

void setup() {
    Serial.begin(115200);           // For debugging
    myLCD.init();                  // Initialize the LCD (if you have a begin/init method)
    Serial.println("LCD Test Starting");
   myLCD.setBacklight(255, 255, 255); // White
    delay(500);

    // Test displaying scores
    myLCD.displayScore(3, 5);
    delay(2000);

    // Test displaying game over screen
    myLCD.displayGameOver(3, 5);
    delay(2000);

    // Test displaying winner
    myLCD.displayVainqueur("Player 1");
    delay(2000);
}

void loop() {
    // Nothing needed in loop for a simple LCD test
}