#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

#include "Hardware/GroveLCD.hpp"
#include "Hardware/buzzer.hpp"
#include <exception>  // obligatoire pour std::exception
#include <string> 

// Exception pour un temps de réaction trop lent

class ScoreManager {
private:
    std::vector<int> scores;
    int maxScores;
    GroveLCD& lcd;
    int lastScore = -1;
    Buzzer& buzzer;

public:
    ScoreManager(int maxScores, GroveLCD& lcd,Buzzer& buzzer);

    void addScore(int newScore);
    void displayScores();
    int getPosition(int score);
    void playloosermelody();
    void playwinnerMelody();
    void playagainMelody();
    // TRUE si le dernier score est le MEILLEUR
    bool operator!();
};

#endif
