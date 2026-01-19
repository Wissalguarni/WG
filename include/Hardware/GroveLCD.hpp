#ifndef GroveLCD_HPP
#define GroveLCD_HPP

#include <Arduino.h>
#include "Hardware.hpp"
#include <Wire.h>
#include <rgb_lcd.h>
#include <string>
// GroveLCD class to handle Grove LCD functionalities

class GroveLCD : public Hardware {
private:
    rgb_lcd lcd;

public:
    GroveLCD();
    void init();
    void clear();
    void setCursor(int col, int row);
    void print(const std::string& message);
    void setBacklight(int r, int g, int b);
    void displayScore(int score1, int score2);
    void displayGameOver(int score1, int score2);
    void displayVainqueur (const std::string& vainqueur);
};

#endif