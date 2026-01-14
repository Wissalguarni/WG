#include "utils/ScoreManager.hpp"
#include <iostream>
#include <algorithm>

ScoreManager::ScoreManager(int maxScores, GroveLCD& lcd) : maxScores(maxScores), lcd(lcd) {}

void ScoreManager::addScore(int newScore) {
    scores.push_back(newScore);

    if (newScore > 1000) {
        throw BadReactionTime();
    }
    // Tri décroissant
    std::sort(scores.begin(), scores.end(), [](int a, int b) { return a > b; });

    // Limiter le nombre de scores
    if (scores.size() > maxScores) {
        scores.resize(maxScores);
    }
}

// Afficher les scores
void ScoreManager::displayScores(GroveLCD& lcd)  {
    lcd.clear();
    lcd.print("=== High Scores ===\n");
    lcd.setCursor(0, 1);
    for (size_t i = 0; i < 3; ++i) {
        lcd.print(std::to_string(i + 1)); 
        lcd.print("-");
        lcd.print(std::to_string(scores[i]));
    }

}

// Obtenir la position d'un score (1 = meilleur)
int ScoreManager::getPosition(int score){
    for (size_t i = 0; i < scores.size(); ++i) {
        if (scores[i] == score) {
            return static_cast<int>(i) + 1; // +1 car classement commence à 1
        }
    }
    return -1; // non trouvé
}

bool ScoreManager::operator!() {
    if (scores.empty()) return false; // pas de score → pas de best
    return scores.back() == scores.front(); 
}

