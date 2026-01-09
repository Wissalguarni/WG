#ifndef GAMESELECTOR_HPP
#define GAMESELECTOR_HPP

#include "Hardware/GroveLCD.hpp"
#include "Hardware/Button.hpp"
// Enum for game modes
enum GameMode {
    SINGLEPLAYER,
    MULTIPLAYER
};

class GameSelector {
private:
    GroveLCD& lcd;          
    Button& validateButton; // button to validate selection
    int potPin;// potentiometer pin
    GameMode currentMode;// currently selected mode
    int lastPotValue;// to track changes

    void displayMenu();

public:
    GameSelector(GroveLCD& lcd, Button& button, int potPin);// constructor
    GameMode selectMode();// select game mode
};

#endif
