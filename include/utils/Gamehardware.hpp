#ifndef GAMEHARDWARE_H
#define GAMEHARDWARE_H

#include "Hardware/GroveLCD.hpp"
#include "Hardware/GroveLED.hpp"
#include "Hardware/Button.hpp"
#include "Hardware/Potentio.hpp"
#include "Hardware/buzzer.hpp"
// class that encapsulates all game hardware
class GameHardware {
public:
    GroveLCD lcd;// Grove LCD
    GroveLED led;// Grove LED
    Button player1Button;// Player 1 button
    Button player2Button;// Player 2 button
    Potentio pot;// Potentiometer
    Buzzer buzz;// Buzzer
    GameHardware(int ledPin, int button1Pin, int button2Pin, int potPin,int buzzerPin);// constructor
    void initAll(); // initialize all hardware
};

#endif
