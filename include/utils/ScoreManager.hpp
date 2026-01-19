#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

#include "Hardware/GroveLCD.hpp"
#include "Hardware/buzzer.hpp"
#include <exception>  // obligatoire pour std::exception
#include <string> 

// ScoreManager class to handle scores

class ScoreManager {
private:
    std::vector<int> scores;
    int maxScores;
    GroveLCD& lcd;
    int lastScore = -1;
    Buzzer& buzzer;

public:
    ScoreManager(int maxScores, GroveLCD& lcd,Buzzer& buzzer);//constructor

    void addScore(int newScore);// add a new score
    void displayScores();// display top scores on LCD
    int getPosition(int score);// get position of a score
    void playloosermelody();// play looser melody
    void playwinnerMelody();// play winner melody
    void playagainMelody();// play again melody
    bool operator!();// TRUE if last score is best
};

#endif
