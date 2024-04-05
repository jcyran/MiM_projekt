#include "WebServer.h"

void checkWiFiConnectionTask(void* pv) {
    for (;;) {
      if (WiFi.status() == WL_CONNECTED) {
          Serial.println("WiFi connected.");
          vTaskDelay(30000 / portTICK_PERIOD_MS);
          continue;
      }

      WiFi.mode(WIFI_STA); //Station mode
      //Connect to WiFi
      WiFi.begin(ssid, password);
      Serial.print("Connecting to WiFi");

      //Wait for connection
      while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        vTaskDelay(1000 / portTICK_PERIOD_MS);
      }

      //Print out WiFi information
      Serial.print("\nConnected to SSID: ");
      Serial.println(ssid);
      Serial.print("IP: ");
      Serial.println(WiFi.localIP());
    }
}

void handleRequests(AsyncWebServer& server, String (*processor)(const String&)) {
  server.on("/", HTTP_GET, [processor](AsyncWebServerRequest* request) {
    request->send(SPIFFS, "/index.html", "text/html", false, processor);
  });

  server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send(SPIFFS, "/styles.css", "text/css");
  });

  server.on("/general.css", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send(SPIFFS, "/general.css", "text/css");
  });

  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send(SPIFFS, "/script.js", "text/javascript");
  });

  server.begin();
}
