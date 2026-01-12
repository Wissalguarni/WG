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
        hw.lcd.print("First at 5");
        delay(2000);
        // Game loop
        while (!multiplayer.isGameOver()) {//while the game is not finished
            hw.lcd.clear();
            multiplayer.start();
            hw.lcd.print("Get ready...");
            long waitTime = multiplayer.waitingTime(D0); // get random wait time
            delay(waitTime); // wait for random time between 1 and 5 seconds
            hw.lcd.clear();
            hw.lcd.print("Press now!");
            hw.led.ON(); // turn on LED to signal players to press

            while (!multiplayer.isFinished()){
                multiplayer.inProgress(hw.player1Button, hw.player2Button, hw.led);//check buttons
                yield();
            }

            multiplayer.end();
            hw.lcd.clear();
            hw.led.OFF();
            hw.lcd.print("Point awarded!");
            delay(1000);
            hw.lcd.clear();
            hw.lcd.displayScore(multiplayer.getscoreplayer1(), multiplayer.getscoreplayer2());//display score
            delay(2000); 
        }

        hw.lcd.clear();
        hw.lcd.print("Game Over!");
        delay(2000);
        hw.lcd.clear();
        multiplayer.displayWinnerLoser(hw.lcd);

        // Reset game for next round
        multiplayer = MultiplayerGame(hw.buzz);

        delay(5000); // wait before returning to menu
    }
}

