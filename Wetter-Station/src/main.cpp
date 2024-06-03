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
Web::Server server(WEBSERVER_PORT);
sens::Sensor sensor;

Status result;

/*
Todo:
* Enable the input of multible Sensors on the esp
  * Use the ESP to scan for possibe 

*/


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
  server.begin();
  sensor.begin();
}

void loop() 
{
  if (count > 600)
  {
    result = api.update_values();

    if (result == ERROR)
    {
      Serial.printf("There was an error getting the values!");
    }
    count = 0;
  }
  count++;

  sensor.update_values();
  server.update_values(&api, &sensor);
  delay(1000);
}
