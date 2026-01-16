#include "Hardware/Potentio.hpp"


Potentio::Potentio(int p, GroveLCD* lcdScreen) : pin(p), lcd(lcdScreen) {}

void Potentio::init() { // initialize potentiometer
    pinMode(pin, INPUT); 
    delay(6000); // wait for LCD to be ready
    lcd->clear();
    lcd->setCursor(0, 0);
    

    int choice = getChoice(2);
    lcd->clear();
    lcd->setCursor(0, 0);

    std::vector<std::string> options = {"Solo Mode", "Multiplayer"};
    std::string choiceStr = options[choice];

    //lcd->print(choiceStr);
}

int Potentio::getChoice(int nbChoices) { // get choice from potentiometer
    if (nbChoices <= 0) return 0;

    int value = analogRead(pin); // 0 → 1023
    int choice = map(value, 0, 1023, 0, nbChoices);

    if (choice >= nbChoices) choice = nbChoices - 1;

    return choice;
}
