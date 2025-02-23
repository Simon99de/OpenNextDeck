#define LGFX_USE_DEBUG
#include <Arduino.h>
#include "settings.h"
#include "modules.h"
#include "storage.h"
#include "display.h"
#include "parser_button.h"
#include "logging.h"
#include "theme_manager.h"
#include "profile_manager.h"
//#include "network_module.h"
#include "touch_gestures.h"
//#include "ota_updates.h"
//#include "pc_interface.h"


// Da in der Board-Datei bereits "LGFX_MaTouch_ESP32S3_4_3 lcd" definiert wird,
// musst Du hier nicht erneut ein Display deklarieren.
//#define LGFX_USE_DEBUG
LGFX lcd;

//--------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  delay(1000);
  Serial.println("[INFO] OpenNextDeck starting...");

  if (!initStorage()) {
    Serial.println("[ERROR] Storage initialization failed!");
  } else {
    loadGlobalConfig();
    //loadWifiMqttConfig();
    Serial.println("[INFO] SD and Config loaded.");
  }
  
  Serial.println("[INFO] Initializing Display...");
  initDisplay();
  Serial.println("[INFO] Display initialized.");

  // Zeichne das Grid:
  drawGrid();
  Serial.println("[INFO] Grid drawn.");

  Serial.println("[INFO] Initializing Modules...");
  initModules();
  parseProfile("Home");
  initLogging();
  initThemeManager();
  initProfileManager();
  //initNetworkModule();
  initTouchGestures();
  //initOTAUpdates();
  //initPCInterface();
  Serial.print("[GRID] Hintergrundfarbe: 0x");
  Serial.println(backgroundColor, HEX);
  lcd.fillScreen(backgroundColor);

  Serial.println("[INFO] Setup complete.");
  drawGrid();
}

void loop() {
  pollModules();
  pollDisplay();
  pollLogging();
  pollThemeManager();
  pollProfileManager();
  //pollNetworkModule();
  pollTouchGestures();
  //pollOTAUpdates();
  //pollPCInterface();
  /*
  lcd.fillScreen(0x001F);
  delay(500);
  lcd.fillScreen(0x0000);
  delay(1000);
  lcd.fillScreen(0xF800);
  delay(500);
  lcd.fillScreen(0x07E0);
  delay(500);
  //*/
  delay(5);
}
