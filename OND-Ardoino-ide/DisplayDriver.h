#ifndef DISPLAYDRIVER_H
#define DISPLAYDRIVER_H

#include <stdint.h>

class DisplayDriver {
public:
  virtual void begin() = 0;
  virtual void fillScreen(uint16_t color) = 0;
  virtual void setCursor(int16_t x, int16_t y) = 0;
  virtual void setTextColor(uint16_t color) = 0;
  virtual void println(const char* text) = 0;
  virtual void fillCircle(int16_t x, int16_t y, int16_t radius, uint16_t color) = 0;
};

#endif // DISPLAYDRIVER_H
