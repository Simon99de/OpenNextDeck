#include "touch_gestures.h"
#include "settings.h"
#include <Arduino.h>

void initTouchGestures() {
  if (DEBUG_MODE) Serial.println("[TOUCH GESTURES] Touch Gestures initialized.");
  // Implementiere hier ggf. Kalibrierung oder Gesture-Erkennung.
}

void pollTouchGestures() {
  // Überprüfe auf Swipe, Long-Press etc.
}
