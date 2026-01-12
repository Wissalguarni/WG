#include "Game/SoloGame.hpp"
#include <Arduino.h>

SoloGame::SoloGame(Buzzer& buzzerObj)
    : finished(false), ledOn(false), bestTime(0), buzzer(buzzerObj) {}

// reset game state
void SoloGame::start() {
    finished = false;
    ledOn = false;

}

// countdown3…2…1…GO! with bips
void SoloGame::countdown(GroveLED& led, GroveLCD& lcd) {
    led.OFF();   // s'assurer qu'elle est éteinte au départ
    lcd.clear();

    for (int i = 3; i > 0; i--) {
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print(std::to_string(i));
        buzzer.beep(2500, 300);
        delay(700);
    }

    lcd.clear();
    lcd.print("GO!");
    buzzer.beep(3000, 500); // bip GO
    delay(200); // 
    led.ON();   // led on after bip
    ledOn = true;
}

long SoloGame::waitingTime(int pin) {
  randomSeed(analogRead(pin));   // initialise le hasard
  delaiAleatoire = random(1000, 5000); // délai aléatoire entre 1 et 5 secondes
  return delaiAleatoire;
}

void SoloGame::newBestTime(int currentTime) {
    if ( currentTime < bestTime) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("New Best Time!");
        lcd.setCursor(0, 1);
        lcd.print("Time: " + std::to_string(currentTime) + " ms");
        int winnerNotes[3] = {523, 659, 783};
        int winnerDur[3] = {200, 200, 400};
        buzzer.playMusic(winnerNotes, winnerDur, 3);
        delay(2000);
        bestTime = currentTime;
    } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Best Time:");
        lcd.setCursor(0, 1);
        lcd.print(std::to_string(bestTime) + " ms");
        int loserNotes[3] = {330, 294, 262};
        int loserDur[3] = {200, 200, 400};
        buzzer.playMusic(loserNotes, loserDur, 3);
        delay(2000);
    }
}

bool SoloGame::isFinished() const {
    return finished;
}

void SoloGame::inProgress(Button& p1, GroveLED& led) {
    if (p1.isPressed()) {
        finished = true;
        led.OFF();
        ledOn = false;
    } 
}

bool SoloGame::stop(){
    return finished;
}