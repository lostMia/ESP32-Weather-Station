/*
 * @file main.cpp
 * @authors Timeania, lostmia
 * @brief Main class for getting values from the internet and hosting a webserver.
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#include "main.hpp"

int count = 0;

API::Client api;
std::vector<std::unique_ptr<sens::Sensor>> sensors;
Web::Server server(WEBSERVER_PORT);

Status result;

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

  Serial.print("\n\n");

  for (uint8_t pin : SENSOR_PORTS) 
  {
    sensors.push_back(std::make_unique<sens::Sensor>(pin));
  }

  server.begin(&api, &sensors);
}

void loop() 
{
  server.serve();
}
