#pragma once

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

//WiFi
static const char* ssid = "MiM_projekt";
static const char* password = "projektmim";

void checkWiFiConnectionTask(void*);
void handleRequests(AsyncWebServer&, String (*)(const String&));
