#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

#include "Hardware/GroveLCD.hpp"
#include <vector>
#include <string>



class ScoreManager {
private:
    std::vector<int> scores;
    int maxScores;
    GroveLCD& lcd; 

public:

    ScoreManager(int maxScores, GroveLCD& lcd);
    void addScore(int newScore);
    void displayScores(GroveLCD& lcd);
    int getPosition(int score);


};

#endif 
