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
    server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest* request) {
        Serial.println("ESP32 Web Server: New request received:");  // for debugging
        Serial.println("GET /temperature");                         // for debugging
        request->send(200, "text/plain", temperatureStr);
    });
    server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest* request) {
        Serial.println("ESP32 Web Server: New request received:");  // for debugging
        Serial.println("GET /humidity");                            // for debugging
        request->send(200, "text/plain", humidityStr);
    });
    server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest* request) {
        Serial.println("ESP32 Web Server: New request received:");  // for debugging
        Serial.println("GET /pressure");                            // for debugging
        request->send(200, "text/plain", pressureStr);
    });
    server.on("/windSpeed", HTTP_GET, [](AsyncWebServerRequest* request) {
        Serial.println("ESP32 Web Server: New request received:");  // for debugging
        Serial.println("GET /windSpeed");                           // for debugging
        request->send(200, "text/plain", windSpeedStr);
    });
    server.on("/windDirection", HTTP_GET, [](AsyncWebServerRequest* request) {
        Serial.println("ESP32 Web Server: New request received:");  // for debugging
        Serial.println("GET /windDirection");                       // for debugging
        request->send(200, "text/plain", windDirectionStr);
    });
    server.on("/rainAmount", HTTP_GET, [](AsyncWebServerRequest* request) {
        Serial.println("ESP32 Web Server: New request received:");  // for debugging
        Serial.println("GET /rainAmount");                          // for debugging
        request->send(200, "text/plain", rainAmountStr);
    });
    server.on("/rainDuration", HTTP_GET, [](AsyncWebServerRequest* request) {
        Serial.println("ESP32 Web Server: New request received:");  // for debugging
        Serial.println("GET /rainDuration");                        // for debugging
        request->send(200, "text/plain", rainDurationStr);
    });
    
  
}
