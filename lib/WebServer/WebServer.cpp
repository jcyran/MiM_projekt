#include "WebServer.h"

void WiFiInit() {
  WiFi.mode(WIFI_STA); //Station mode
  //Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ");

  //Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }

  //Print out WiFi information
  Serial.print("\nConnected to SSID: ");
  Serial.println(ssid);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}