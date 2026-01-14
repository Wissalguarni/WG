#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

#include "Hardware/GroveLCD.hpp"
#include <vector>
#include <string>
#include <exception>



// Exception pour un temps de réaction trop lent
class BadReactionTime : public std::exception {
public:
    const char* what() const noexcept {
        return "C'est catastrophique!";
    }
};


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
    bool operator!();


};

#endif 
