#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>

// Globale Variablen für WiFi/MQTT-Konfiguration (werden aus der SD geladen)
extern String wifi_ssid;
extern String wifi_password;
extern String mqtt_server;

bool initStorage();
void loadGlobalConfig();
void loadWifiMqttConfig();

#endif // STORAGE_H
