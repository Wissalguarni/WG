#ifndef POTENTIO_HPP
#define POTENTIO_HPP

#include <Arduino.h>
#include "Hardware/Hardware.hpp"
#include "Hardware/GroveLCD.hpp"

class Potentio : public Hardware {
private:
    int pin;
    GroveLCD* lcd;
public:
    Potentio();
    void init(int pin);
    int getChoice(int nbChoix);
};

#endif