#include "Hardware/potentio.hpp"

GroveLCD lcd;

Potentio::Potentio(){};

void Potentio::init(int pin) {
    pinMode(pin, INPUT); 
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("test potentio");
    delay(1000);
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print(std::to_string(getChoice(5)));
}

int Potentio::getChoice(int nbChoices) {
    if (nbChoices <= 0) {
        return 0;
    }
    int value = analogRead(pin); // 0 → 1023
    int choice = map(value, 0, 1023, 0, nbChoices);
    if (choice >= nbChoices) {
        choice = nbChoices - 1;
    }
    return choice;
}