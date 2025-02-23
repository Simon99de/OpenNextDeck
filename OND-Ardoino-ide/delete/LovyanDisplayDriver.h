#ifndef LOVYANDISPLAYDRIVER_H
#define LOVYANDISPLAYDRIVER_H

#include "DisplayDriver.h"             // Deine abstrakte Schnittstelle (muss schon existieren)
#include "board_matouch_esp32s3_4_3.h"   // Diese Datei definiert z. B. die globale Instanz "lcd"
#include <LovyanGFX.hpp>               // LovyanGFX-Daten

class LovyanDisplayDriver : public DisplayDriver {
public:
  LovyanDisplayDriver() {}
  
  // Initialisiert das Display (LovyanGFX)
  virtual void begin() override {
    lcd.init();
    lcd.setRotation(1);
  }
  
  virtual void fillScreen(uint16_t color) override {
    lcd.fillScreen(color);
  }
  
  virtual void setCursor(int16_t x, int16_t y) override {
    lcd.setCursor(x, y);
  }
  
  virtual void setTextColor(uint16_t color) override {
    lcd.setTextColor(color);
  }
  
  virtual void println(const char* text) override {
    lcd.println(text);
  }
  
  virtual void fillCircle(int16_t x, int16_t y, int16_t radius, uint16_t color) override {
    lcd.fillCircle(x, y, radius, color);
  }
  
  // Falls du weitere Funktionen (z. B. print, drawRect, etc.) benötigst,
  // füge hier entsprechende Wrapper-Methoden hinzu.
};

#endif // LOVYANDISPLAYDRIVER_H
