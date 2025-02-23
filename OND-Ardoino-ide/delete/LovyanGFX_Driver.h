#ifndef LOVYANGFX_DRIVER_H
#define LOVYANGFX_DRIVER_H

#include <LovyanGFX.hpp>

// Hier wählst du den passenden Panel-Treiber aus.
// Im folgenden Beispiel wird Panel_ILI9488 verwendet – bei deinem Board (HX8664/HX8264) 
// könnte ggf. ein anderer Panel-Treiber nötig sein.
class LGFX_MaTouchS3 : public lgfx::LGFX_Device
{
  private:
    lgfx::Bus_Parallel16 _bus_instance;
    lgfx::Panel_ILI9488 _panel_instance;

  public:
    LGFX_MaTouchS3();
};

#endif // LOVYANGFX_DRIVER_H
