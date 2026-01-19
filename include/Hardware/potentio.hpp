#ifndef POTENTIO_HPP
#define POTENTIO_HPP

#include <Arduino.h>
#include "Hardware/Hardware.hpp"
#include "Hardware/GroveLCD.hpp"
// Potentio class to handle potentiometer input
class Potentio : public Hardware {
private:
    int pin;// potentiometer pin number
    GroveLCD* lcd;// pointer to LCD for displaying messages

public:
    Potentio(int pin, GroveLCD* lcdScreen);// constructor
    void init() override;// initialize potentiometer
    int getChoice(int nbChoices);// get user choice from potentiometer
};

#endif
