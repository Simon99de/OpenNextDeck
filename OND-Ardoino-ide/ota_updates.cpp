#include "ota_updates.h"
#include "settings.h"
#include <Arduino.h>
#include <ArduinoOTA.h>

void initOTAUpdates() {
  if (DEBUG_MODE) Serial.println("[OTA] Initializing OTA Updates...");
  ArduinoOTA.setHostname("OpenNextDeck");
  ArduinoOTA.begin();
}

void pollOTAUpdates() {
  ArduinoOTA.handle();
}
