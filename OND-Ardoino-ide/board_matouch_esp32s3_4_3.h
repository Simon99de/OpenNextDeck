#ifndef BOARD_MATOUCH_ESP32S3_4_3_H
#define BOARD_MATOUCH_ESP32S3_4_3_H

// Board-Fähigkeiten
#define BOARD_HAS_ACCESSORY_MANAGER true
#define BOARD_HAS_ICON_CACHE        true
#define BOARD_SUPPORTS_WIFI         true
#define BOARD_SUPPORTS_BLUETOOTH    true

// Verwende LovyanGFX v1
#define LGFX_USE_V1
// Wähle den Treiber: LOVYANGFX (d.h. LovyanGFX soll genutzt werden)
#define DISPLAY_DRIVER_TYPE LOVYANGFX

#include <LovyanGFX.hpp>
// Binde die LovyanGFX-Board-Datei ein – diese Datei enthält bereits alle Display‑Parameter 
// für das Makerfabs ESP32-S3 Parallel TFT with Touch 4.3"
#include <lgfx_user/LGFX_ESP32S3_RGB_MakerfabsParallelTFTwithTouch43.h>

// Board-spezifische Einstellungen (zur Information oder falls Du später noch Anpassungen brauchst)
#define BOARD_NAME             "MaTouch_ESP32S3_4.3"
#define BOARD_DISPLAY_WIDTH    800
#define BOARD_DISPLAY_HEIGHT   480

// SD Card (SPI) – passe diese Werte ggf. Deinem Schaltplan an
#define SD_CS         10
#define SD_MOSI       11
#define SD_SCK        12
#define SD_MISO       13

// Touch Panel (GT911 via I²C) – falls Du zusätzliche Touch-Einstellungen außerhalb der LovyanGFX-Datei brauchst
#define DISPLAY_TOUCH_TYPE GT911
#define TOUCH_I2C_SDA 33
#define TOUCH_I2C_SCL 34
#define TOUCH_INT     35
#define TOUCH_RST     36

// Debugging (UART) – falls benötigt
#define UART0_TXD     43
#define UART0_RXD     44

// Boot-Button
#define BOOT_BTN      0

// Globale Instanz des Displays – wird dann in Deinem Sketch verwendet:
extern LGFX lcd;

#endif // BOARD_MATOUCH_ESP32S3_4_3_H
