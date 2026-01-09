#include <Arduino.h>
#include "Hardware/GroveLCD.hpp"
#include "Hardware/LED.hpp"
#include "Hardware/button.hpp"
#include "Game/MultiplayerGame.hpp"
#include "Hardware/Groveled.hpp"
#include "Utils/GameSelector.hpp"
#include "Utils/GameHardware.hpp"
GameHardware hw(D7, D8, D5, A0, D6); // Initialize hardware with pin numbers
GameSelector selector(hw.lcd, hw.player1Button, A0); // Initialize game selector

void setup() {
    hw.initAll();
}
MultiplayerGame multiplayer(hw.buzz);

void loop() {
    GameMode mode = selector.selectMode();

    if (mode == MULTIPLAYER) {
        multiplayer.start();
        multiplayer.countdown(hw.led, hw.lcd);
        // Game loop
        while (!multiplayer.isFinished()) {//while the game is not finished
            multiplayer.inProgress(hw.player1Button, hw.player2Button, hw.led);//check buttons
        }

        hw.lcd.displayVainqueur(multiplayer.getWinner());//display winner
         delay(2000); // wait before showing score
        hw.lcd.displayScore(multiplayer.getscoreplayer1(), multiplayer.getscoreplayer2());//display score
         if (multiplayer.isGameOver()) {//if game over
            multiplayer.displayWinnerLoser(hw.lcd);
            delay(5000); // wait before returning to menu
            multiplayer.start(); // reset game
        }

        delay(5000); // wait before returning to menu
    }
}

