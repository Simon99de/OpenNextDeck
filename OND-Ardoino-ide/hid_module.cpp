#include "hid_module.h"
#include "settings.h"
#include <Arduino.h>

#if HID_DRIVER_TYPE == ESP_TINYUSB
  #ifdef __has_include
    #if __has_include(<tusb.h>)
      #include <tusb.h>  // Verwende den offiziellen Header aus dem ESP32-S3 Arduino Core
    #else
      #error "tusb.h not found. Please update your ESP32 Arduino Core or adjust HID_DRIVER_TYPE."
    #endif
  #else
    #include <tusb.h>
  #endif
#elif HID_DRIVER_TYPE == TINYUSB
  #include <Adafruit_TinyUSB.h>
#endif

void initHID() {
#if HID_ENABLED && HID_KEYBOARD_ENABLED
  #if HID_DRIVER_TYPE == ESP_TINYUSB
    if (DEBUG_MODE) Serial.println("[HID] Initializing espTINYUSB...");
    tusb_init();
  #elif HID_DRIVER_TYPE == TINYUSB
    if (DEBUG_MODE) Serial.println("[HID] Initializing TINYUSB...");
    // Beispiel: Adafruit_TinyUSB_HID.begin();
  #else
    if (DEBUG_MODE) Serial.println("[HID] Using board default HID implementation.");
  #endif
#endif
}

void pollHID() {
  // Hier können HID-Ereignisse verarbeitet werden.
}

void HIDKeyboardPress(const char* keys) {
#if HID_ENABLED && HID_KEYBOARD_ENABLED
  uint8_t report[6] = {0};
  if (keys[0] != '\0') {
    // Dummy-Konvertierung: Verwende das erste Zeichen als HID-Code.
    // In einer echten Implementierung muss hier eine Umrechnung erfolgen.
    report[0] = keys[0];
  }
  #if HID_DRIVER_TYPE == ESP_TINYUSB
    if (DEBUG_MODE) {
      Serial.print("[HID] espTINYUSB - Sending keys: ");
      Serial.println(keys);
    }
    // Der Aufruf erwartet: report_id, modifier, keycode[6]
    tud_hid_keyboard_report(0, 0, report);
  #elif HID_DRIVER_TYPE == TINYUSB
    if (DEBUG_MODE) {
      Serial.print("[HID] TINYUSB - Sending keys: ");
      Serial.println(keys);
    }
    // Beispiel: Adafruit_TinyUSB_HID.keyboardReport(report, 6);
  #else
    if (DEBUG_MODE) {
      Serial.print("[HID] Board default HID - Keys: ");
      Serial.println(keys);
    }
  #endif
#endif
}
