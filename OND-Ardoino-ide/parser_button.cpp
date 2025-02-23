#include "parser_button.h"
#include <Arduino.h>
#include "settings.h"
#include <SD.h>  // SD.h hinzufügen, damit der Typ File bekannt ist

void parseProfile(const char* profileName) {
  if (DEBUG_MODE) {
    Serial.print("[PARSER] Parsing profile: ");
    Serial.println(profileName);
  }
  String path = "/profiles/";
  path += profileName;
  path += "/grid.txt";
  
  File gridFile = SD.open(path);
  if (gridFile) {
    while (gridFile.available()) {
      String line = gridFile.readStringUntil('\n');
      line.trim();
      if (line.length() > 0) {
        Serial.print("[PARSER] ");
        Serial.println(line);
      }
    }
    gridFile.close();
  } else {
    Serial.print("[PARSER] Profile file not found: ");
    Serial.println(path);
  }
}
