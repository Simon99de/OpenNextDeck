#include "pc_interface.h"
#include "settings.h"
#include <Arduino.h>

void initPCInterface() {
  if (DEBUG_MODE) Serial.println("[PC INTERFACE] Initializing PC Interface...");
}

void pollPCInterface() {
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (DEBUG_MODE) {
      Serial.print("[PC INTERFACE] Received command: ");
      Serial.println(cmd);
    }
    if (cmd.equalsIgnoreCase("RESTART")) {
      ESP.restart();
    }
    // Weitere Befehle verarbeiten
  }
}
