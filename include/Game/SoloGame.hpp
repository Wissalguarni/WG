#ifndef SOLOGAME_HPP
#define SOLOGAME_HPP

#include "Hardware/Button.hpp"
#include "Hardware/GroveLCD.hpp"
#include "Hardware/GroveLED.hpp"
#include "Hardware/Buzzer.hpp"
#include <Arduino.h>
#include <string>

class SoloGame {
private:
    bool finished;
    bool ledOn;

    Buzzer& buzzer;

public:
    SoloGame(Buzzer& buzzer);

    void start() ;
    void countdown(GroveLED& led, GroveLCD& lcd); // countdown 3..2..1..GO!
    void inProgress(Button& p1, GroveLED& led);// game in progress
    bool isFinished() const;// is the round finished?
    long waitingTime(int pin);
    bool stop(); 
};

#endif
