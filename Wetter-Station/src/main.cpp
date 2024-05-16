/*
 * @file main.cpp
 * @authors lostmia
 * @brief 
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#include "main.hpp"


API::Client api;
API::STATUS result;


void setup() 
{
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  api.begin();
  api.update_values();
  runServer();
}

void loop() 
{
  result = api.update_values();
  
  if (result == API::ERROR)
  {
    Serial.printf("There was an error getting the values!");
  }
  else
  {
    Serial.printf("Request succesfull!\n");
    Serial.printf("Air Pressure hPa: %f\n", api.air_pressure);
    Serial.printf("Rain amount mm: %f\n", api.rain_amount);
    Serial.printf("Rain duraction min : %f\n", api.rain_duration);
    Serial.printf("Air Temperature in C: %f\n", api.temperature);
    Serial.printf("Wind direction in degree: %f\n", api.wind_direction);
  }

  getValues();
  updateValues();
  delay(API_QUERY_DELAY);
}
