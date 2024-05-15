/*
 * @file webserver.hpp
 * @authors Timeania
 * @brief 
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#pragma once


#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#define SERIAL_BAUDRATE 115200

void runServer();
void getValues();
void updateValues();

