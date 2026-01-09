#include "Game/MultiplayerGame.hpp"
#include <Arduino.h>

MultiplayerGame::MultiplayerGame(Buzzer& buzzerObj)
    : finished(false), ledOn(false), scorePlayer1(0), scorePlayer2(0), buzzer(buzzerObj) {}

// reset game state
void MultiplayerGame::start() {
    finished = false;
    ledOn = false;

}

// countdown3…2…1…GO! with bips
void MultiplayerGame::countdown(GroveLED& led, GroveLCD& lcd) {
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
};


// compare button states to update scores
void MultiplayerGame::inProgress(Button& p1, Button& p2, GroveLED& led) {
    if (p1.isPressed()) {
        scorePlayer1++;
        finished = true;
        led.OFF();
        ledOn = false;
    } else if (p2.isPressed()) {
        scorePlayer2++;
        finished = true;
        led.OFF();
        ledOn = false;
    }
}

// end the round
void MultiplayerGame::end() {
    finished = true;
    ledOn = false;
}

// is the round finished?
bool MultiplayerGame::isFinished() const {
    return finished;
}

// Is the game over (a player reached max score)?
bool MultiplayerGame::isGameOver() const {
    return (scorePlayer1 >= 5 || scorePlayer2 >= 5);
}



// get the winner as string
std::string MultiplayerGame::getWinner() const {
    if (scorePlayer1 > scorePlayer2) return "Player 1";
    else if (scorePlayer2 > scorePlayer1) return "Player 2";
    else return "Draw";
}

int MultiplayerGame::getscoreplayer1() {
    return scorePlayer1;
}

int MultiplayerGame::getscoreplayer2() {
    return scorePlayer2;
}

// Display winner and loser with sounds
void MultiplayerGame::displayWinnerLoser(GroveLCD& lcd) {
    lcd.clear();

    if(scorePlayer1 > scorePlayer2) {
        // --- Winner P1 ---
        lcd.setCursor(0, 0);
        lcd.print("Winner: joueur1");
        int winnerNotes[3] = {523, 659, 783};
        int winnerDur[3] = {200, 200, 400};
        buzzer.playMusic(winnerNotes, winnerDur, 3);

        delay(500);

        // --- Loser P2 ---
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Loser: joueur2");
        int loserNotes[3] = {330, 294, 262};
        int loserDur[3] = {200, 200, 400};
        buzzer.playMusic(loserNotes, loserDur, 3);

    } else if(scorePlayer2 > scorePlayer1) {
        // --- Winner P2 ---
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Winner: joueur2");
        int winnerNotes[3] = {523, 659, 783};
        int winnerDur[3] = {200, 200, 400};
        buzzer.playMusic(winnerNotes, winnerDur, 3);

        delay(500);

        // --- Loser P1 ---
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Loser: joueur1");
        int loserNotes[3] = {330, 294, 262};
        int loserDur[3] = {200, 200, 400};
        buzzer.playMusic(loserNotes, loserDur, 3);

    } else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Draw!");
    }
}


