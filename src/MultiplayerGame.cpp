#include "MultiplayerGame.hpp"
#include <Arduino.h>

#define Player1_BUTTON 1
#define Player2_BUTTON 2
#define LED_PIN 3

MultiplayerGame::MultiplayerGame(){
     ledON=false;
     gamefinished=false;
};
