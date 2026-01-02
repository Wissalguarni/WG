#ifndef GROVE_LCD_HPP
#define GROVE_LCD_HPP

#include "LCD.hpp"
#include <Wire.h>
#include "rgb_lcd.h"

class GroveLCD : public LCD {
private:
    rgb_lcd lcd;

public:
    GroveLCD();
    void init() override;
    void displaymsg(const char* msg) override;
    void clear() override;
    void setCursor(int col, int row) override;//Places cursor
};

#endif
