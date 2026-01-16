#include "Hardware/buzzer.hpp"
using namespace std;

Buzzer::Buzzer(int buzzerPin) : pin(buzzerPin) {}

void Buzzer::init() {
    int notes[] = {262, 294, 330, 349};       // Do, Ré, Mi, Fa
    int durations[] = {200, 200, 200, 200};  // durée de chaque note
    playMusic(notes, durations, 4);
}

void Buzzer::beep(int frequency, int duration) { // Beep simple
    tone(pin, frequency, duration);
    delay(duration + 50); 
    noTone(pin);           
}


void Buzzer::playMusic(int notes[], int durations[], int length) { // play a sequence of notes
    for (int i = 0; i < length; i++) {
        tone(pin, notes[i], durations[i]);
        delay(durations[i] + 50);
    }
    noTone(pin);
}