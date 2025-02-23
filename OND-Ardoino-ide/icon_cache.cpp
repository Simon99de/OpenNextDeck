#include "icon_cache.h"
#include "modules.h"
#include <Arduino.h>
#include <SD.h>

void initIconCache() {
#if DO_ICON_CACHE
  if (DEBUG_MODE) Serial.println("[ICON] Initializing Icon Cache...");
#endif
}

void loadIcon(const char* iconName, int w, int h) {
#if DO_ICON_CACHE
  if (DEBUG_MODE) {
    Serial.print("[ICON] Loading icon: ");
    Serial.print(iconName);
    Serial.print(" (");
    Serial.print(w);
    Serial.print("x");
    Serial.print(h);
    Serial.println(")");
  }
  // Beispiel: Lade ein BMP-Bild aus /icons/ und skaliere es – Implementierung hängt von der Bibliothek ab.
#endif
}
