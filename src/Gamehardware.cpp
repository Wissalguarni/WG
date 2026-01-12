#include "utils/GameHardware.hpp"
#include <Wire.h>

GameHardware::GameHardware(int ledPin, int button1Pin, int button2Pin, int potPin,int buzzerPin)
    : lcd(), 
      led(ledPin), 
      player1Button(button1Pin, &lcd), 
      player2Button(button2Pin, &lcd), 
      pot(potPin, &lcd) , 
      buzz(buzzerPin)
{};
void GameHardware::initAll() {
    Wire.begin();      
    lcd.init();
    led.init();
    player1Button.init();
    player2Button.init();
    pot.init();
    buzz.init();
}
