#ifndef MODULES_H
#define MODULES_H

#include "settings.h"
#include BOARD_FILE  // z.B. board_matouch_esp32s3.h

// Wenn Board den Accessory Manager unterstützt:
#if BOARD_HAS_ACCESSORY_MANAGER && ACCESSORY_MANAGER_ENABLED
  #define DO_ACCESSORY true
#else
  #define DO_ACCESSORY false
#endif

#if BOARD_HAS_ICON_CACHE && ICON_CACHE_ENABLED
  #define DO_ICON_CACHE true
#else
  #define DO_ICON_CACHE false
#endif

void initModules();
void pollModules();

#endif // MODULES_H
