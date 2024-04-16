#pragma once

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

//WiFi
static const char* ssid = "UPC4539894";
static const char* password = "zE8pdfFsdben";

void checkWiFiConnectionTask(void*);
void handleRequests(AsyncWebServer&, String (*)(const String&));
