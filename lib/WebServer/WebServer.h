#pragma once

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

//WiFi
static const char* ssid = "UPCA7F9126";
static const char* password = "Bd7fnxhutcpf";

void checkWiFiConnectionTask(void*);
void handleRequests(AsyncWebServer&, String (*)(const String&));
