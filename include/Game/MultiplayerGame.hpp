#ifndef MULTIPLAYERGAME_HPP
#define MULTIPLAYERGAME_HPP

#include "Hardware/Button.hpp"
#include "Hardware/GroveLCD.hpp"
#include "Hardware/GroveLED.hpp"
#include "Hardware/Buzzer.hpp"
#include <Arduino.h>
#include <string>

class MultiplayerGame {
private:
    bool finished;
    bool ledOn;
    std::string winner;
    int scorePlayer1;
    int scorePlayer2;
    const int maxScore = 3;

    Buzzer& buzzer;

public:
    MultiplayerGame(Buzzer& buzzer);

    void start() ;
    void countdown(GroveLED& led, GroveLCD& lcd); // countdown 3..2..1..GO!
    void inProgress(Button& p1, Button& p2, GroveLED& led);// game in progress
    void end();
    bool isFinished() const;// is the round finished?
    std::string getWinner() const;
    int getscoreplayer1();// get player 1 score
    int getscoreplayer2() ;// get player 2 score
     void displayWinnerLoser(GroveLCD& lcd);// display winner and loser
     bool isGameOver() const;// is the game over (a player reached max score)?
};

#endif
