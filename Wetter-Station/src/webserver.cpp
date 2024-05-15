/*
 * @file webserver.cpp
 * @authors Timeania
 * @brief 
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#include "webserver.hpp"
String temperatureStr;
String humidityStr;
String pressureStr;
String windSpeedStr;
String windDirectionStr;
AsyncWebServer server(80);
//Just for testing purposes
float getTemperature() {
  // YOUR SENSOR IMPLEMENTATION HERE
  // simulate the temperature value
  float temp_x100 = random(0, 10000);  // a ramdom value from 0 to 10000
  return temp_x100 / 100;              // return the simulated temperature value from 0 to 100 in float
}

float getHumidity() {
  // YOUR SENSOR IMPLEMENTATION HERE
  // simulate the humidity value
  float hum_x100 = random(0, 10000);  // a ramdom value from 0 to 10000
  return hum_x100 / 100;              // return the simulated humidity value from 0 to 100 in float
}

float getPressure() {
  // YOUR SENSOR IMPLEMENTATION HERE
  // simulate the pressure value
  float press_x100 = random(0, 10000);  // a ramdom value from 0 to 10000
  return press_x100 / 100;              // return the simulated pressure value from 0 to 100 in float
}

float getWindSpeed() {
  // YOUR SENSOR IMPLEMENTATION HERE
  // simulate the wind speed value
  float ws_x100 = random(0, 10000);  // a ramdom value from 0 to 10000
  return ws_x100 / 100;              // return the simulated wind speed value from 0 to 100 in float
}

float getWindDirection() {
  // YOUR SENSOR IMPLEMENTATION HERE
  // simulate the wind direction value
  float wd_x100 = random(0, 10000);  // a ramdom value from 0 to 10000
  return wd_x100 / 100;              // return the simulated wind direction value from 0 to 100 in float
}


void runServer() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", webpage_HTML);
  });

  server.begin();
}
void getValues(){
    float temperature = getTemperature();
    temperatureStr = String(temperature, 2);
    float humidity = getHumidity();
    humidityStr = String(humidity, 2);
    float pressure = getPressure();
    pressureStr = String(pressure, 2);
    float windSpeed = getWindSpeed();
    windSpeedStr = String(windSpeed, 2);
    float windDirection = getWindDirection();
    windDirectionStr = String(windDirection, 2);
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
    server.on("/ff", HTTP_GET, [](AsyncWebServerRequest* request) {
        Serial.println("ESP32 Web Server: New request received:");  // for debugging
        Serial.println("GET /ff");                           // for debugging
        request->send(200, "text/plain", windSpeedStr);
    });
    server.on("/dd", HTTP_GET, [](AsyncWebServerRequest* request) {
        Serial.println("ESP32 Web Server: New request received:");  // for debugging
        Serial.println("GET /dd");                           // for debugging
        request->send(200, "text/plain", windDirectionStr);
    });
}
