#ifndef BUZZER_HPP
#define BUZZER_HPP

#include "Hardware.hpp"
#include <Arduino.h>  // nécessaire pour tone/noTone

class Buzzer : public Hardware {
private:
    int pin; // Pin du buzzer

public:
    Buzzer(int buzzerPin);
    void init();
    void beep(int frequency, int duration);
    void playMusic(int notes[],int durations[],int length);

};

#endif