/*********************************************************************
 * @file  Apllication.cpp
 * @author <Wissal GUARNI Florian GOYHENEIX>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"


Application::Application()
:hw(D7, D8, D5, A0, D6),
  selector(hw.lcd, hw.player1Button, A0),
  continueSelector(hw.lcd, hw.player1Button, A0),
  scoreManager(10, hw.lcd, hw.buzz)
{
    
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init()
{
    //initialize all hardware
    hw.initAll();
}


void Application::run(void){
GameMode mode = selector.selectMode(); // let user select game mode

    if (mode == MULTIPLAYER) { // multiplayer mode
        MultiplayerGame multiplayer(hw.buzz);// initialize multiplayer game
        multiplayer.start();// start the game
        multiplayer.countdown(hw.led, hw.lcd);// countdown before starting
        hw.lcd.clear();// clear LCD
        hw.lcd.print("First at 5");// display goal
        delay(2000);// wait before starting
        // Game loop
        while (!multiplayer.isGameOver()) {//while the game is not finished
            hw.lcd.clear();// clear LCD
            multiplayer.start();// start a new round
            hw.lcd.print("Get ready...");// prompt players to get ready
            hw.lcd.clear();// clear LCD
            hw.lcd.print("Wait for it...");// prompt players to wait
            long waitTime = multiplayer.waitingTime(D0); // get random wait time
            delay(waitTime); // wait for random time between 1 and 5 seconds
            hw.lcd.clear();
            hw.lcd.print("Press now!");// prompt players to press
            hw.led.ON(); // turn on LED to signal players to press

            while (!multiplayer.isFinished()){ // until a player presses
                multiplayer.inProgress(hw.player1Button, hw.player2Button, hw.led);//check buttons
                yield();
            }

            multiplayer.end();// end the round
            hw.lcd.clear();// clear LCD
            hw.led.OFF();
            hw.lcd.print("Point awarded!");// notify point awarded
            delay(1000);
            hw.lcd.clear();
            hw.lcd.displayScore(multiplayer.getscoreplayer1(), multiplayer.getscoreplayer2());//display score
            delay(2000); 
        }

        hw.lcd.clear();
        hw.lcd.print("Game Over!");// notify game over
        delay(2000);
        hw.lcd.clear();
        multiplayer.displayWinnerLoser(hw.lcd); // display winner and loser
        delay(2000); // wait before returning to menu
        
    } else if (mode == SINGLEPLAYER) { // single player mode
        SoloGame solo(hw.buzz);
        solo.start();
        solo.countdown(hw.led, hw.lcd);
        delay(2000);
        while (!solo.isGameover ()) {//while the game is not finished
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

            while (!solo.isFinished()){ // until the player presses
                solo.inProgress(hw.player1Button, hw.led);//check button
                yield();
                stopTime = millis()-startTime;
            }
            
            hw.lcd.clear();
            hw.led.OFF();
            if (stopTime <2000) {
                scoreManager.addScore(stopTime);// add score
                delay(1000);
            
                 if (!scoreManager) {
                    hw.lcd.print("Best score !");// best score
                    hw.lcd.setCursor(0, 1);
                    hw.lcd.print("Congrats!");// congratulate player
                    scoreManager.playwinnerMelody();// play winner melody
                    delay(2000);
                    hw.lcd.clear();
                }
                hw.lcd.print("Your Time:");// display time
                hw.lcd.setCursor(0, 1);
                hw.lcd.print(std::to_string(stopTime));
                hw.lcd.print(" ms");
                delay(2000);
                hw.lcd.clear();
                hw.lcd.print("Your position:");// display position
                hw.lcd.setCursor(0, 1);
                position = scoreManager.getPosition(stopTime);
                hw.lcd.print(std::to_string(position));
                delay(2000);
                hw.lcd.clear();
                scoreManager.displayScores();
                delay(2000);

            }else {
                hw.lcd.print("Wake up!!!"); // too slow
                scoreManager.playloosermelody();
                delay(2000);
            }
            hw.lcd.clear();
            hw.lcd.print("Play again?");
            scoreManager.playagainMelody();
            delay(1000);
            solo.start(); // reset for next round
            Continue choose = continueSelector.selectContinue(); // ask to continue
            if (choose == NO) {
                hw.lcd.clear();
                hw.lcd.print("Thanks for");
                hw.lcd.setCursor(0, 1);
                hw.lcd.print("playing!");
                delay(2000);
                solo.stop(); // exit the game loop
            }
            //solo.stop();
        delay(2000); // wait before returning to menu
        }
    }
}


