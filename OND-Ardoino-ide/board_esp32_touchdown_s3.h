#ifndef BOARD_ESP32_TOUCHDOWN_S3_H
#define BOARD_ESP32_TOUCHDOWN_S3_H

/******************************************************************************
 * board_esp32_touchdown_s3.h
 *
 * Board configuration for the ESP32-TouchDown-S3 Board.
 *
 * Features:
 * - ESP32-S3 WROOM N8R8, 16MB Flash, 8MB PSRAM, 8MB Quad SPI Flash
 * - 4.3" TFT with ILI9488 in 8-bit parallel mode
 * - Capacitive Touch via FT6236G (FT62*6 family, using the FT6236G class)
 * - SD Card Slot, Dual USB, etc.
 *
 * Required libraries:
 *  - Arduino_GFX_Library
 *  - (Für Touch) Eine FT6236G-kompatible Bibliothek (z.B. FT6236G von einem Drittanbieter)
 *  - SD, WiFi, ArduinoOTA, PubSubClient, FortySevenEffects MIDI Library, espTINYUSB
 *
 * Please adjust the following pin assignments according to your board documentation.
 ****************************************************************************/

#define BOARD_NAME "ESP32_TouchDown_S3"

// Display resolution
#define BOARD_DISPLAY_WIDTH 480
#define BOARD_DISPLAY_HEIGHT 272

// Parallel TFT (8-bit parallel mode)
// (Beispielwerte – bitte anpassen!)
#define LCD_PCLK      42
#define LCD_HSYNC     39
#define LCD_VSYNC     41
#define LCD_DE        40

// Data bus for ILI9488 (8-bit)
#define LCD_D0        45
#define LCD_D1        48
#define LCD_D2        47
#define LCD_D3        21
#define LCD_D4        14
#define LCD_D5        5
#define LCD_D6        6
#define LCD_D7        7

// SD Card (SPI)
#define SD_CS         10
#define SD_MOSI       11
#define SD_SCK        12
#define SD_MISO       13

// Touch Controller (FT6236G capacitive touch)
// Setze DISPLAY_TOUCH_TYPE hier auf FT6236G statt FT62X
#define DISPLAY_TOUCH_TYPE FT6236G
// Beispielhafte Pin-Zuordnungen (passen ggf. an)
#define TOUCH_I2C_SDA 33
#define TOUCH_I2C_SCL 34
// Falls der Touch-Controller Interrupt/Reset-Pins benötigt:
#define TOUCH_INT     17
#define TOUCH_RST     -1  // Falls nicht verwendet

// UART (USB-C to Serial)
#define UART0_TXD     43
#define UART0_RXD     44

// Boot Button
#define BOOT_BTN      0

// Accessory Manager pins
#define BUZZER_PIN    25
#define VIBRATOR_PIN  26

// Board capabilities
#define BOARD_HAS_ACCESSORY_MANAGER true
#define BOARD_HAS_ICON_CACHE        true
#define BOARD_SUPPORTS_WIFI         true
#define BOARD_SUPPORTS_BLUETOOTH    true

// --- Driver/Library Selection ---
#define DISPLAY_DRIVER_TYPE ARDUINO_GFX
#define HID_DRIVER_TYPE       ESP_TINYUSB
#define MIDI_DRIVER_TYPE      FORTYSEVEN_EFFECTS

#endif // BOARD_ESP32_TOUCHDOWN_S3_H
