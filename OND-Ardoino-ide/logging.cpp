#include "logging.h"
#include "settings.h"
#include <Arduino.h>
#include <SD.h>

bool logToSD = false;  // Kann über eine Einstellung in settings.h gesteuert werden

void initLogging() {
  if (DEBUG_MODE) Serial.println("[LOG] Logging initialized.");
  // Beispiel: Falls SD verfügbar und gewünscht, logToSD aktivieren.
  // logToSD = true;  // (Anpassbar via Konfiguration)
}

void pollLogging() {
  // In einem echten Projekt könnten Logs periodisch in die SD-Karte geschrieben werden.
  // Hier ein Beispiel, das einfach nur Serial nutzt.
}
