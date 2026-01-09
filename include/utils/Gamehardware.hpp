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
    GroveLCD lcd;
    GroveLED led;
    Button player1Button;
    Button player2Button;
    Potentio pot;
    Buzzer buzz;
    GameHardware(int ledPin, int button1Pin, int button2Pin, int potPin,int buzzerPin);
    void initAll(); // initialize all hardware
};

#endif
