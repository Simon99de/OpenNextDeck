#include "network_module.h"
#include "settings.h"
#include "storage.h"  // enthält wifi_ssid, wifi_password, mqtt_server
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient mqttClient;  // Verwende den Default-Konstruktor

void initNetworkModule() {
#if WIFI_ENABLED && MQTT_ENABLED
  if (DEBUG_MODE) Serial.println("[NETWORK] Initializing WiFi...");
  WiFi.begin(wifi_ssid.c_str(), wifi_password.c_str());
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("[NETWORK] WiFi connected.");

  // Jetzt den Client setzen:
  mqttClient.setClient(espClient);
  mqttClient.setServer(mqtt_server.c_str(), 1883);

  if (mqttClient.connect("OpenNextDeck")) {
    Serial.println("[NETWORK] MQTT connected.");
  } else {
    Serial.println("[NETWORK] MQTT connection failed.");
  }
#endif
}

void pollNetworkModule() {
#if WIFI_ENABLED && MQTT_ENABLED
  mqttClient.loop();
#endif
}
