#include <Arduino.h>
#include "Hardware/GroveLCD.hpp"
#include "Hardware/LED.hpp"
#include "Hardware/button.hpp"
#include "Game/MultiplayerGame.hpp"
#include "Hardware/Groveled.hpp"
#include "Utils/GameSelector.hpp"
#include "Utils/GameHardware.hpp"
#include "Game/SoloGame.hpp"
#include "Utils/ContinueSelector.hpp"
#include "Utils/ScoreManager.hpp"

GameHardware hw(D7, D8, D5, A0, D6); // Initialize hardware with pin numbers
GameSelector selector(hw.lcd, hw.player1Button, A0); // Initialize game selector
ContinueSelector continueSelector(hw.lcd, hw.player1Button, A0); // Initialize continue selector
ScoreManager scoreManager(10, hw.lcd, hw.buzz); // Initialize score manager

void setup() {
    hw.initAll();
 
}


void loop() {
    GameMode mode = selector.selectMode();

    if (mode == MULTIPLAYER) {
        MultiplayerGame multiplayer(hw.buzz);
        multiplayer.start();
        multiplayer.countdown(hw.led, hw.lcd);
        hw.lcd.print("First at 5");
        delay(2000);
        // Game loop
        while (!multiplayer.isGameOver()) {//while the game is not finished
            hw.lcd.clear();
            multiplayer.start();
            hw.lcd.print("Get ready...");
            hw.lcd.clear();
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
        delay(5000); // wait before returning to menu
        
    } else if (mode == SINGLEPLAYER) {
        SoloGame solo(hw.buzz);
        solo.start();
        solo.countdown(hw.led, hw.lcd);
        delay(2000);
        while (!solo.isGameover ()) {//while the game is not finished
            //solo.countdown(hw.led, hw.lcd);
            hw.lcd.clear();
            solo.start();
            long startTime = 0;
            long waitTime = 0;
            long stopTime = 0;
             int position = 0;
            hw.lcd.print("Wait for it...");
            hw.led.OFF();
            waitTime = solo.waitingTime(D0); // get random wait time
            delay(waitTime); // wait for random time between 1 and 5 seconds
            hw.lcd.clear();
            startTime = millis();
            hw.lcd.print("Press now!");
            hw.led.ON(); // turn on LED to signal player to press

            while (!solo.isFinished()){
                solo.inProgress(hw.player1Button, hw.led);//check button
                yield();
                stopTime = millis()-startTime;
            }
            
            hw.lcd.clear();
            hw.led.OFF();
            if (stopTime <2000) {
                scoreManager.addScore(stopTime);
                delay(1000);
            
                 if (!scoreManager) {
                    hw.lcd.print("Best score !");
                    hw.lcd.setCursor(0, 1);
                    hw.lcd.print("Congrats!");
                    scoreManager.playwinnerMelody();
                    delay(2000);
                    hw.lcd.clear();
                }
                hw.lcd.print("Your Time:");
                hw.lcd.setCursor(0, 1);
                hw.lcd.print(std::to_string(stopTime));
                hw.lcd.print(" ms");
                delay(2000);
                hw.lcd.clear();
                hw.lcd.clear();
                hw.lcd.print("Your position:");
                hw.lcd.setCursor(0, 1);
                position = scoreManager.getPosition(stopTime);
                hw.lcd.print(std::to_string(position));
                scoreManager.displayScores();
                delay(2000);

            }else {
                hw.lcd.print("t nul");
                scoreManager.playloosermelody();
                delay(2000);
            }
            hw.lcd.clear();
            hw.lcd.print("Play again?");
            scoreManager.playagainMelody();
            delay(1000);
            Continue choose = continueSelector.selectContinue();
            if (choose == NO) {
                hw.lcd.clear();
                hw.lcd.print("Thanks for");
                hw.lcd.setCursor(0, 1);
                hw.lcd.print("playing!");
                delay(2000);
                solo.stop(); // exit the game loop
            }
            solo.stop();
        delay(2000); // wait before returning to menu
        }
    }
}

