#include "Hardware/GroveLCD.hpp"

GroveLCD::GroveLCD() {}

void GroveLCD::init() { // initialize the LCD
    lcd.begin(16, 2);          // LCD 16x2
    lcd.setRGB(255, 255, 255); // white backlight

    lcd.clear();
    lcd.print("FUN FUN GAMES");
    delay(2000);
    lcd.clear();
    lcd.print("Press the button");
    lcd.setCursor(0, 1);
    lcd.print("when led is on");
    delay(2000);
    lcd.clear();
    lcd.print("AS FAST AS");
    lcd.setCursor(0, 1);
    lcd.print("YOU CAN!");
}

void GroveLCD::clear() { // clear the LCD
    lcd.clear();
}

void GroveLCD::setCursor(int col, int row) { // set cursor position
    lcd.setCursor(col, row);
}

void GroveLCD::print(const std::string& message) { // print message on LCD
    lcd.print(message.c_str());
}

void GroveLCD::setBacklight(int r, int g, int b) { // set backlight color
    lcd.setRGB(r, g, b);
}

// Affiche le score
void GroveLCD::displayScore(int score1 , int score2) { //  display scores of two players
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Joueur1:");
    lcd.print(score1);
    lcd.setCursor(0, 1);
    lcd.print("Joueur2:");
    lcd.print(score2);
}

void GroveLCD::displayGameOver(int score1, int score2) { // display game over with scores
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

void GroveLCD::displayVainqueur (const std::string& vainqueur) { // display the winner
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Vainqueur:");
    lcd.setCursor(4, 1);
    lcd.print(vainqueur.c_str());
    lcd.setRGB(0, 255, 0);
}



