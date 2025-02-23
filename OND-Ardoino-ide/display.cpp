#include "display.h"
#include "DisplayDriver.h"
#include "settings.h"
#include BOARD_FILE  // z.B. "board_matouch_esp32s3_4_3.h"
#include <Arduino.h>
#include <Wire.h>
#include <SD.h>

#ifndef BLUE
  #define BLUE 0x001F
#endif

// Touch-Controller (wie bisher)
#if DISPLAY_TOUCH_TYPE == FT6236G
  #if __has_include(<FT6236G.h>)
    #include <FT6236G.h>
    static FT6236G touchController;
  #elif __has_include(<GT911.h>)
    #warning "FT6236G.h not found, falling back to GT911."
    #undef DISPLAY_TOUCH_TYPE
    #define DISPLAY_TOUCH_TYPE GT911
    #include <GT911.h>
    static GT911 touchController(TOUCH_I2C_SDA, TOUCH_I2C_SCL, TOUCH_INT, TOUCH_RST);
  #else
    #warning "Neither FT6236G.h nor GT911.h found; using dummy touch controller."
    struct DummyTouch {
      bool begin() { return true; }
      bool touched() { return false; }
      bool getPoint(uint16_t &x, uint16_t &y) { return false; }
    };
    static DummyTouch touchController;
  #endif
#elif DISPLAY_TOUCH_TYPE == GT911
  #if __has_include(<GT911.h>)
    #include <GT911.h>
    static GT911 touchController(TOUCH_I2C_SDA, TOUCH_I2C_SCL, TOUCH_INT, TOUCH_RST);
  #else
    #warning "GT911.h not found; using dummy touch controller."
    struct DummyTouch {
      bool begin() { return true; }
      bool touched() { return false; }
      bool getPoint(uint16_t &x, uint16_t &y) { return false; }
    };
    static DummyTouch touchController;
  #endif
#else
  #error "Unsupported DISPLAY_TOUCH_TYPE defined in board file!"
#endif

// Das globale Display – wie in der Board-Datei deklariert
extern LGFX lcd;

void initDisplay() {
  Serial.println("[DISPLAY] Initializing display...");
  lcd.init();
  
  // I2C für Touch initialisieren
  Wire.begin();
  
  // Touch-Controller initialisieren
  if (!touchController.begin()) {
    Serial.println("[TOUCH] Touch initialization failed!");
  } else {
    Serial.println("[TOUCH] Touch initialized successfully.");
  }
}

void pollDisplay() {
#if DISPLAY_TOUCH_TYPE == FT6236G || DISPLAY_TOUCH_TYPE == GT911
  if (touchController.touched()) {
    uint16_t x, y;
    if (touchController.getPoint(x, y)) {
      int mappedX = map(x, 0, 4095, 0, lcd.width());
      int mappedY = map(y, 0, 4095, 0, lcd.height());
      lcd.fillCircle(mappedX, mappedY, 5, BLUE);
    }
  }
#endif
}

// ----- Grid-Konfiguration (16-Bit Farben) -----
// Standardwerte (falls kein Eintrag gefunden wird)
int gridRows = 3;
int gridCols = 5;
uint16_t backgroundColor = 0x0000;  // 16-Bit-Schwarz ("0000")
int buttonSpacing = 10;
bool swipeEnabled = true;
bool autoPageSave = true;
bool iconScaling = true;

// Diese Funktion liest einen Konfigurationswert aus einer Zeile im Format key=value.
// ACHTUNG: In Arduino's String-Klasse gibt trim() keinen Wert zurück, sondern ändert den String in-place!
String getConfigValue(const String &line, const String &key) {
  int pos = line.indexOf("=");
  if (pos > 0 && line.substring(0, pos) == key) {
    String s = line.substring(pos + 1);
    s.trim();
    return s;
  }
  return "";
}

// Liest die Standard-Konfiguration aus /config/theme.txt
void loadDefaultGridConfig() {
  File file = SD.open("/config/theme.txt");
  if (!file) {
    Serial.println("[GRID] config/theme.txt nicht gefunden. Standardwerte werden verwendet.");
    return;
  }
  while (file.available()) {
    String line = file.readStringUntil('\n');
    line.trim();
    if (line.startsWith("grid_layout=")) {
      String value = getConfigValue(line, "grid_layout");
      int xPos = value.indexOf("x");
      if (xPos > 0) {
        gridRows = value.substring(0, xPos).toInt();
        gridCols = value.substring(xPos + 1).toInt();
      }
    } else if (line.startsWith("background_color=")) {
      String value = getConfigValue(line, "background_color");
      // Hier erwartet der Benutzer einen 4-stelligen Hexwert (z.B. "0000" für Schwarz)
      backgroundColor = (uint16_t) strtoul(value.c_str(), NULL, 16);
    } else if (line.startsWith("button_spacing=")) {
      buttonSpacing = getConfigValue(line, "button_spacing").toInt();
    } else if (line.startsWith("swipe_enabled=")) {
      swipeEnabled = (getConfigValue(line, "swipe_enabled").toInt() != 0);
    } else if (line.startsWith("auto_page_save=")) {
      autoPageSave = (getConfigValue(line, "auto_page_save").toInt() != 0);
    } else if (line.startsWith("icon_scaling=")) {
      iconScaling = (getConfigValue(line, "icon_scaling").toInt() != 0);
    }
  }
  file.close();
  Serial.print("[GRID] Default Grid-Konfiguration: ");
  Serial.print(gridRows);
  Serial.print("x");
  Serial.print(gridCols);
  Serial.print(", BG Color: 0x");
  Serial.print(backgroundColor, HEX);
  Serial.print(", Spacing: ");
  Serial.println(buttonSpacing);
}

// Überschreibt Standardwerte, falls im aktuellen Profil eine grid.txt existiert
void loadProfileGridConfig(const String &profileName) {
  String path = "/profiles/" + profileName + "/grid.txt";
  File file = SD.open(path);
  if (!file) {
    Serial.print("[GRID] Kein alternatives Grid in ");
    Serial.print(path);
    Serial.println(" gefunden.");
    return;
  }
  Serial.print("[GRID] Lade Grid-Konfiguration aus ");
  Serial.println(path);
  while (file.available()) {
    String line = file.readStringUntil('\n');
    line.trim();
    if (line.startsWith("grid_layout=")) {
      String value = getConfigValue(line, "grid_layout");
      int xPos = value.indexOf("x");
      if (xPos > 0) {
        gridRows = value.substring(0, xPos).toInt();
        gridCols = value.substring(xPos + 1).toInt();
      }
    } else if (line.startsWith("background_color=")) {
      String value = getConfigValue(line, "background_color");
      backgroundColor = (uint16_t) strtoul(value.c_str(), NULL, 16);
    } else if (line.startsWith("button_spacing=")) {
      buttonSpacing = getConfigValue(line, "button_spacing").toInt();
    } else if (line.startsWith("swipe_enabled=")) {
      swipeEnabled = (getConfigValue(line, "swipe_enabled").toInt() != 0);
    }
  }
  file.close();
  Serial.print("[GRID] Profil Grid-Konfiguration: ");
  Serial.print(gridRows);
  Serial.print("x");
  Serial.print(gridCols);
  Serial.print(", Spacing: ");
  Serial.println(buttonSpacing);
}

// Zeichnet das Grid – die Zellen sind quadratisch und zentriert
void drawGrid() {
  int totalWidth = lcd.width();
  int totalHeight = lcd.height();
  
  // Hintergrund füllen
  lcd.fillScreen(backgroundColor);
  
  // Berechne den verfügbaren Platz unter Berücksichtigung der Button-Abstände
  int availableWidth  = totalWidth - (gridCols + 1) * buttonSpacing;
  int availableHeight = totalHeight - (gridRows + 1) * buttonSpacing;
  
  // Zellgröße (quadratisch) als Minimum der beiden Dimensionen
  int cellSize = min(availableWidth / gridCols, availableHeight / gridRows);
  
  // Berechne zusätzliche Ränder, damit das Grid zentriert wird
  int marginX = (totalWidth - (gridCols * cellSize + (gridCols + 1) * buttonSpacing)) / 2;
  int marginY = (totalHeight - (gridRows * cellSize + (gridRows + 1) * buttonSpacing)) / 2;
  
  Serial.print("[GRID] Zeichne Grid: ");
  Serial.print(gridRows);
  Serial.print(" Zeilen, ");
  Serial.print(gridCols);
  Serial.println(" Spalten");
  
  // Zeichne für jede Zelle einen Rahmen (hier in Weiß, 0xFFFF)
  for (int row = 0; row < gridRows; row++) {
    for (int col = 0; col < gridCols; col++) {
      int x = marginX + buttonSpacing + col * (cellSize + buttonSpacing);
      int y = marginY + buttonSpacing + row * (cellSize + buttonSpacing);
      lcd.drawRect(x, y, cellSize, cellSize, 0xFFFF);
    }
  }
}
