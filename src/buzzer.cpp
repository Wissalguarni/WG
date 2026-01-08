#include "Hardware/buzzer.hpp"
using namespace std;

Buzzer::Buzzer(int buzzerPin) : pin(buzzerPin) {}

void Buzzer::init() {
    tone(pin, 500, 200);  
    delay(250);           
    noTone(pin);           
}

void Buzzer::beep(int frequency, int duration) {
    tone(pin, frequency, duration);
    delay(duration + 50); 
    noTone(pin);           
}


void Buzzer::playMusic(int notes[], int durations[], int length) {
    for (int i = 0; i < length; i++) {
        tone(pin, notes[i], durations[i]);
        delay(durations[i] + 50);
    }
    noTone(pin);
}
