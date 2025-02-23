#include "LovyanGFX_Driver.h"

LGFX_MaTouchS3::LGFX_MaTouchS3()
{
  // Konfiguration des parallelen Busses
  auto cfg = _bus_instance.config();
  cfg.port = 0;
  cfg.freq_write = 16000000;  // Schreibfrequenz – anpassen, falls nötig
  cfg.pin_wr  = 35;           // Beispiel: anpassen an deine Belegung
  cfg.pin_rd  = 48;           // Beispiel
  cfg.pin_rs  = 36;           // Beispiel

  // Datenleitungen (16 Bit)
  cfg.pin_d0 = 47;
  cfg.pin_d1 = 21;
  cfg.pin_d2 = 14;
  cfg.pin_d3 = 13;
  cfg.pin_d4 = 12;
  cfg.pin_d5 = 11;
  cfg.pin_d6 = 10;
  cfg.pin_d7 = 9;
  cfg.pin_d8 = 3;
  cfg.pin_d9 = 8;
  cfg.pin_d10 = 16;
  cfg.pin_d11 = 15;
  cfg.pin_d12 = 7;
  cfg.pin_d13 = 6;
  cfg.pin_d14 = 5;
  cfg.pin_d15 = 4;
  _bus_instance.config(cfg);

  // Panel-Konfiguration
  _panel_instance.setBus(&_bus_instance);
  auto cfg2 = _panel_instance.config();
  // Falls dein Panel keine dedizierte CS, RST oder BUSY benötigt, setze diese auf -1
  cfg2.pin_cs = -1;
  cfg2.pin_rst = -1;
  cfg2.pin_busy = -1;

  // Panel-Maße – passe diese an dein Display an (Beispielwerte: 320x480)
  cfg2.memory_width  = 320;
  cfg2.memory_height = 480;
  cfg2.panel_width   = 320;
  cfg2.panel_height  = 480;
  cfg2.offset_x      = 0;
  cfg2.offset_y      = 0;
  cfg2.offset_rotation = 0;
  cfg2.dummy_read_pixel = 8;
  cfg2.dummy_read_bits = 1;
  cfg2.readable      = true;
  cfg2.invert        = false;
  cfg2.rgb_order     = false;
  cfg2.dlen_16bit    = true;
  cfg2.bus_shared    = true;
  _panel_instance.config(cfg2);

  // Mit dieser Funktion wird das Panel dem übergeordneten LGFX_Device zugewiesen.
  setPanel(&_panel_instance);
}
