#include "Utils/ScoreManager.hpp"
#include <vector>
#include <algorithm>

ScoreManager::ScoreManager(int maxScores, GroveLCD& lcd,Buzzer& buzzer)
    : maxScores(maxScores), lcd(lcd), buzzer(buzzer), lastScore(-1) {}

void ScoreManager::addScore(int newScore) {
    

    lastScore = newScore;
    scores.push_back(newScore);

    // Tri croissant : meilleur = plus petit
    std::sort(scores.begin(), scores.end());

    if (scores.size() > maxScores) {
        scores.resize(maxScores);
    }
}

void ScoreManager::displayScores() {
    // Display the title first
    lcd.clear();                  // Clear the screen
    lcd.setCursor(0, 0);          // Set cursor to top-left
    lcd.print("High Scores:");    // Print the title

    delay(2000);                  // Wait 2 seconds so user can see the title

    // Clear the screen again to display the scores
    lcd.clear();

    // Display top 3 scores (or fewer if less than 3)
    for (size_t i = 0; i < scores.size() && i < 3; ++i) {
        lcd.setCursor(0, 0);      // Always start at top-left for each score
        lcd.print(std::to_string(i + 1));  // Print rank number
        lcd.print(": ");
        lcd.print(std::to_string(scores[i])); // Print score

        delay(2000);              // Wait 2 seconds before showing next score
        lcd.clear();              // Clear screen for next score
    }
}


int ScoreManager::getPosition(int score) {
    for (size_t i = 0; i < scores.size(); ++i) {
        if (scores[i] == score) {
            return i + 1;
        }
    }
    return -1;
}

bool ScoreManager::operator!() {
    if (scores.empty()) return false;
    return lastScore == scores.front();
}

void ScoreManager:: playloosermelody() {
    int looserNotes[3] = {330, 294, 262};
    int looserDur[3] = {200, 200, 400};
    buzzer.playMusic(looserNotes, looserDur, 3);
}
void ScoreManager:: playwinnerMelody() {
    int winnerNotes[3] = {523, 659, 783};
    int winnerDur[3] = {200, 200, 400};
    buzzer.playMusic(winnerNotes, winnerDur, 3);
}
void ScoreManager:: playagainMelody() {
    int againNotes[4] = {784, 659, 523, 659};
    int againDur[4] = {150, 150, 150, 300};
    buzzer.playMusic(againNotes, againDur, 4);
}