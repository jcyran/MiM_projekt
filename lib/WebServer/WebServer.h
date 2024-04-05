#pragma once

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

//WiFi
static const char* ssid = "your_ssid";
static const char* password = "your_password";

void checkWiFiConnectionTask(void*);
void handleRequests(AsyncWebServer&, String (*)(const String&));
