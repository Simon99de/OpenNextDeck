#include "modules.h"
#include "hid_module.h"
#include "midi_module.h"
#include "accessory_manager.h"
#include "icon_cache.h"

void initModules() {
  initHID();
  initMIDI();
  initAccessoryManager();
  initIconCache();
}

void pollModules() {
  pollHID();
  pollMIDI();
  pollAccessoryManager();
  // Icon Cache muss ggf. nicht gepollt werden.
}
