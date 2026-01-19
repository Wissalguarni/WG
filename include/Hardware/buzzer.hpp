#ifndef BUZZER_HPP
#define BUZZER_HPP

#include "Hardware.hpp"
#include <Arduino.h>  // nécessaire pour tone/noTone
// Buzzer class to handle buzzer functionalities
class Buzzer : public Hardware {
private:
    int pin; // buzzer pin number

public:
    Buzzer(int buzzerPin);// constructor
    void init();// initialize buzzer
    void beep(int frequency, int duration);// play a beep sound
    void playMusic(int notes[],int durations[],int length);// play a sequence of notes

};

#endif