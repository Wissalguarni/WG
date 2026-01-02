#include "GroveLCD.hpp"

GroveLCD::GroveLCD() {}

void GroveLCD::init() {
    lcd.begin(16, 2);          // LCD 16x2
    lcd.setRGB(255, 255, 255); // Backlight blanc
    lcd.clear();
}

void GroveLCD::displaymsg(const char* msg) {
    lcd.print(msg);
}

void GroveLCD::clear() {
    lcd.clear();
}

void GroveLCD::setCursor(int col, int row) {
    lcd.setCursor(col, row);
}
