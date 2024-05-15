/*
 * @file webserver.cpp
 * @authors Timeania
 * @brief 
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#include "webpage.h"
#include "main.hpp"

AsyncWebServer server(80);

void runServer() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html);
  });

  server.begin();
}
void getValues(){
    float temperature = getTemperature();
    String temperatureStr = String(temperature, 2);
    float humidity = getHumidity();
    String humidityStr = String(humidity, 2);
    float pressure = getPressure();
    String pressureStr = String(pressure, 2);
    float windSpeed = getWindSpeed();
    String windSpeedStr = String(windSpeed, 2);
    float windDirection = getWindDirection();
    String windDirectionStr = String(windDirection, 2);
    float rainAmount = getRain();
    String rainAmountStr = String(rainAmount, 2);
    float rainDuration = getRainDuration();
    String rainDurationStr = String(rainDuration, 2);

}
void updateValues() {
    server.on("/data", HTTP_GET, [](AsyncWebServerRequest* request) {
        Serial.println("ESP32 Web Server: New request received:");  // for debugging
        Serial.println("GET /temperature");                         // for debugging
        request->send(200, "text/plain", temperatureStr);
    });

  
}
