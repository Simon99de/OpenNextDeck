#include "accessory_manager.h"
#include "modules.h"
#include "settings.h"
#include <Arduino.h>

void initAccessoryManager() {
#if DO_ACCESSORY
  if (DEBUG_MODE) Serial.println("[ACC] Initializing Accessory Manager...");
  #if ACC_BUZZER
    pinMode(5, OUTPUT);  // Beispiel: Buzzer an GPIO5 – passe an, falls nötig
    if (DEBUG_MODE) Serial.println("[ACC] Buzzer enabled.");
  #endif
  #if ACC_VIBRATOR
    pinMode(6, OUTPUT);  // Beispiel: Vibrator an GPIO6
    if (DEBUG_MODE) Serial.println("[ACC] Vibrator enabled.");
  #endif
#endif
}

void pollAccessoryManager() {
  // Hier könnten z.B. Status von Sensoren überprüft oder Ausgänge aktualisiert werden
}
