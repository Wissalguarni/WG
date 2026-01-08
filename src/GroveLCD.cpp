#include "Hardware/GroveLCD.hpp"
using namespace std;

GroveLCD::GroveLCD() {}

void GroveLCD::init() {
    lcd.begin(16, 2);          // LCD 16x2
    lcd.setRGB(255, 255, 255); // Backlight blanc
    lcd.clear();
}

void GroveLCD::clear() {
    lcd.clear();
}

void GroveLCD::setCursor(int col, int row) {
    lcd.setCursor(col, row);
}

void GroveLCD::print(const std::string& message) {
    lcd.print(message.c_str());
}

void GroveLCD::setBacklight(int r, int g, int b) {
    lcd.setRGB(r, g, b);
}

// Affiche le score
void GroveLCD::displayScore(int score1 , int score2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Joueur1:");
    lcd.print(score1);
    lcd.setCursor(0, 1);
    lcd.print("Joueur2:");
    lcd.print(score2);
}

void GroveLCD::displayGameOver(int score1, int score2) {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("GAME OVER");
    lcd.setCursor(0, 1);
    lcd.print(score1);
    lcd.setCursor(5, 1);
    lcd.print("-");
    lcd.setCursor(10, 1);
    lcd.print(score2);
}

void GroveLCD::displayVainqueur (const std::string& vainqueur) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Vainqueur:");
    lcd.setCursor(4, 1);
    lcd.print(vainqueur.c_str());
    lcd.setRGB(0, 255, 0);
}
