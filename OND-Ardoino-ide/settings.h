#ifndef SETTINGS_H
#define SETTINGS_H

// Board-Auswahl: Hier wird die Board-Datei angegeben. 
#define BOARD_FILE "board_matouch_esp32s3_4_3.h"

// Debug-Modus (Serial-Ausgaben)
#define DEBUG_MODE true

// Kernmodule
#define WIFI_ENABLED       false
#define BLUETOOTH_ENABLED  false
#define MQTT_ENABLED       false
#define HID_ENABLED        false
#define MIDI_ENABLED       false

#if HID_ENABLED
  #define HID_KEYBOARD_ENABLED true
  #define HID_MOUSE_ENABLED    false
#endif

#if MIDI_ENABLED
  #define MIDI_NOTES_ENABLED true
  #define MIDI_CC_ENABLED    true
#endif

// Accessory Manager (externe Komponenten)
#define ACCESSORY_MANAGER_ENABLED false
#if ACCESSORY_MANAGER_ENABLED
  #define ACC_BUZZER       false
  #define ACC_VIBRATOR     false
  #define ACC_BATTERY      false
  #define ACC_LIGHT_SENSOR false
#endif

// Icon Cache
#define ICON_CACHE_ENABLED false
#if ICON_CACHE_ENABLED
  #define ICON_SCALING_ENABLED true
#endif

// Kommunikationsschnittstellen: 0 = Disabled, 1 = Board default, 2 = USB, 3 = Bluetooth
#define HID_KEYBOARD_INTERFACE 3
#define MIDI_INTERFACE         2

// Wähle den HID-Treiber: 
// Mögliche Werte: TINYUSB, ESP_TINYUSB, BOARD_DEFAULT, etc.
#define HID_DRIVER_TYPE ESP_TINYUSB

#endif // SETTINGS_H
