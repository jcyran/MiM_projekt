#pragma once

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

//API server
const char* server = "https://api.weatherapi.com/v1/current.json?key=73bc8d93a7134662afb133233242303&q=Cracow";
//JSON document
JsonDocument doc;

struct APIValues {
    float temp, humid, press;
};

void fetchData(APIValues&);
void sendRequest(HTTPClient&, APIValues&);
