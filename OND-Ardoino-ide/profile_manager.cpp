#include "profile_manager.h"
#include "settings.h"
#include <Arduino.h>
#include <SD.h>

String currentProfile = "Home";

void initProfileManager() {
  if (DEBUG_MODE) Serial.println("[PROFILE] Initializing Profile Manager...");
  // Setze Standardprofil auf "Home"
  currentProfile = "Home";
}

void pollProfileManager() {
  // Hier können Profilwechsel oder Statusaktualisierungen verarbeitet werden.
}
