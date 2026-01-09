#include <Arduino.h>
#include "Hardware/Buzzer.hpp"

const int BUZZER_PIN = 12; // D6 = GPIO12 (ESP8266)
Buzzer buzzer(BUZZER_PIN);

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("Buzzer test start");
    buzzer.init();

    // Single beep test
    buzzer.beep(1000, 500); // 1kHz, 500ms
    delay(1000);

    // Melody test
    // GAME OVER melody
     int gameOverNotes[] = { 392, 370, 349, 330, 294, 262, 0 };
     int gameOverDurations[] = { 300, 300, 300, 300, 400, 600, 400 };
     int gameOverLength = 7;

    buzzer.playMusic(gameOverNotes, gameOverDurations, gameOverLength);
}

void loop() {
    // nothing
}
