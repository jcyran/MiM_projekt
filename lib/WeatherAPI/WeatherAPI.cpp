#include "WeatherAPI.h"

void fetch_data() {
  //Check WiFi connection
  if (WiFi.status() == WL_CONNECTED) {
    //Create client
    HTTPClient http;

    Serial.print("\nMaking HTTP request to URL: ");
    Serial.println(server);

    sendRequest(http);

    //Close the connection
    http.end();
  }
  else {
    Serial.println("\nWiFi not connected.");
  }
}

void sendRequest(HTTPClient& http) {
    //Send HTTP request
    int httpResponseCode = http.GET();
    Serial.print("HTTP response code: "); Serial.println(httpResponseCode);

    if (httpResponseCode == 200) {
      //Store the json data
      String result = http.getString();
      deserializeJson(doc, result);
      JsonObject obj = doc.as<JsonObject>();

      //Get your json data
      tempAPI = obj["current"]["temp_c"];
      humidAPI = obj["current"]["humidity"];
      pressAPI = obj["current"]["pressure_mb"];

      Serial.print("Temperature: "); Serial.println(tempAPI);
      Serial.print("Humidity: "); Serial.println(humidAPI);
      Serial.print("Pressure: "); Serial.println(pressAPI);
    }
}