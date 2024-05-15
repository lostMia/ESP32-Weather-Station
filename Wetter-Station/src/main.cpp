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

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_USERNAME);
  WiFi.begin(WIFI_USERNAME, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your code here
}
