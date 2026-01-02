#ifndef LCD_H
#define LCD_H

#include "Hardware.hpp"
class LCD: public Hardware {
 
    public:
       virtual void displaymsg(const char* msg)=0;//Displays msg on screen
       virtual void clear() = 0;
       virtual void setCursor(int col, int row)=0;//Places cursor
       virtual ~LCD() {};
};
#endif