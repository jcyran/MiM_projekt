#ifndef WEATHERAPI_H
#define WEATHERAPI_H

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

//VARIABLES
//WiFi
const char* ssid = "UPC4539894";
const char* password = "zE8pdfFsdben";
//API server
String server = "https://api.weatherapi.com/v1/current.json?key=73bc8d93a7134662afb133233242303&q=Cracow";
//JSON document
JsonDocument doc;

float tempAPI, humidAPI, pressAPI;

void fetchData();

#endif