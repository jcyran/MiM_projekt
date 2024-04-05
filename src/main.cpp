#include <Arduino.h>
#include <WiFi.h>
#include "WebServer.h"
#include "bme280.h"

Adafruit_BME280 bme;
SensorValues sv;

AsyncWebServer server(80);

const uint32_t delayTime = 5000;


void weatherValuesTask(void*);
String processor(const String&);


void setup() {
  Serial.begin(9600);
  bme280Init(bme);
  if (!SPIFFS.begin(true)) {
      Serial.println("An Error has occurred while mounting SPIFFS");
      return;
  }

  xTaskCreatePinnedToCore(
      checkWiFiConnectionTask,
      "Check WiFi connection",
      4096,
      NULL,
      1,
      NULL,
      CONFIG_ARDUINO_RUNNING_CORE
  );

  while (WiFi.status() != WL_CONNECTED) delay(100);

  handleRequests(server, &processor);
  server.begin();

  xTaskCreate(
      weatherValuesTask,
      "Get weather values",
      8192,
      NULL,
      1,
      NULL
  );
}

void loop() {}


void weatherValuesTask(void *pv) {
    for (;;) {
        getSensorValues(bme, sv);

        vTaskDelay(delayTime / portTICK_PERIOD_MS);
    }
}

String processor(const String& var) {
    if (var == "TEMPERATURE") {
      std::string value = "";
      sprintf(&value[0], "%.1f ºC", sv.temp);

      return (String)value.c_str();
    }

    if (var == "HUMIDITY") {
      String value = (String)((int)sv.humid) + " &#37"; 
      return value;
    }

    if (var == "PRESSURE") {
      String value = (String)((int)sv.press / 100) + " hPa";
      return value;
    }

    return String();
}
