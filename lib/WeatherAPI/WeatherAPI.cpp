#include "WeatherAPI.h"

void fetch_data(APIValues& values) {
  //Check WiFi connection
  if (WiFi.status() == WL_CONNECTED) {
    //Create client
    HTTPClient http;

    Serial.print("\nMaking HTTP request to URL: ");
    Serial.println(server);

    sendRequest(http, values);

    //Close the connection
    http.end();
  }
  else {
    Serial.println("\nWiFi not connected.");
  }
}

void sendRequest(HTTPClient& http, APIValues& values) {
    //Send HTTP request
    int httpResponseCode = http.GET();
    Serial.print("HTTP response code: "); Serial.println(httpResponseCode);

    if (httpResponseCode == 200) {
      //Store the json data
      String result = http.getString();
      deserializeJson(doc, result);
      JsonObject obj = doc.as<JsonObject>();

      //Get your json data
      values.temp = obj["current"]["temp_c"];
      values.humid = obj["current"]["humidity"];
      values.press = obj["current"]["pressure_mb"];
    }
}