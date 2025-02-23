#include "storage.h"
#include "settings.h"
#include BOARD_FILE
#include <Arduino.h>
#include <SD.h>

String wifi_ssid = "";
String wifi_password = "";
String mqtt_server = "";

bool initStorage() {
  if (DEBUG_MODE) Serial.println("[STORAGE] Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("[STORAGE] SD card initialization failed!");
    return false;
  }
  Serial.println("[STORAGE] SD card initialized.");
  return true;
}

void loadGlobalConfig() {
  if (DEBUG_MODE) Serial.println("[STORAGE] Loading global configuration...");
  File configFile = SD.open("/config/config.txt");
  if (configFile) {
    while (configFile.available()) {
      String line = configFile.readStringUntil('\n');
      line.trim();
      if (line.length() > 0) {
        Serial.print("[CONFIG] ");
        Serial.println(line);
      }
    }
    configFile.close();
  } else {
    Serial.println("[STORAGE] config.txt not found!");
  }
}

void loadWifiMqttConfig() {
  if (DEBUG_MODE) Serial.println("[STORAGE] Loading WiFi/MQTT configuration from SD...");
  File configFile = SD.open("/config/wifi_mqtt.txt");
  if (configFile) {
    while (configFile.available()) {
      String line = configFile.readStringUntil('\n');
      line.trim();
      if (line.startsWith("ssid=")) {
        wifi_ssid = line.substring(5);
      } else if (line.startsWith("password=")) {
        wifi_password = line.substring(9);
      } else if (line.startsWith("mqtt_server=")) {
        mqtt_server = line.substring(12);
      }
    }
    configFile.close();
    if (DEBUG_MODE) {
      Serial.print("[STORAGE] WiFi SSID: ");
      Serial.println(wifi_ssid);
      Serial.print("[STORAGE] WiFi Password: ");
      Serial.println(wifi_password);
      Serial.print("[STORAGE] MQTT Server: ");
      Serial.println(mqtt_server);
    }
  } else {
    Serial.println("[STORAGE] wifi_mqtt.txt not found!");
  }
}
