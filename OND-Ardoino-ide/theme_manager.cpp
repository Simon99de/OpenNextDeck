#include "theme_manager.h"
#include "settings.h"
#include <Arduino.h>
#include <SD.h>

String currentTheme = "default";

void initThemeManager() {
  if (DEBUG_MODE) Serial.println("[THEME] Initializing Theme Manager...");
  File themeFile = SD.open("/config/theme.txt");
  if (themeFile) {
    currentTheme = themeFile.readStringUntil('\n');
    currentTheme.trim();
    themeFile.close();
    if (DEBUG_MODE) {
      Serial.print("[THEME] Loaded theme: ");
      Serial.println(currentTheme);
    }
  } else {
    if (DEBUG_MODE) Serial.println("[THEME] theme.txt not found. Using default.");
  }
}

void pollThemeManager() {
  // Dynamische Theme-Updates ggf. verarbeiten.
}
