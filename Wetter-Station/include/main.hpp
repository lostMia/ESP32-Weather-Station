/*
 * @file main.hpp
 * @authors lostmia
 * @brief 
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <credentials.hpp> 
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <vector>

#include "webserver.hpp"
#include "api.hpp"
#include "sensor.hpp"
#include "enums.hpp"

#ifndef WIFI_PASSWORD
'The Variable "WIFI_PASSWORD" is not set! You can do this by creating'
'a credentials.hpp file in the include directory and defining the variable there!'
#endif

#ifndef WIFI_SSID
'The Variable "WIFI_SSID" is not set! You can do this by creating'
'a credentials.hpp file in the include directory and defining the variable there!'
#endif

#define SERIAL_BAUDRATE 115200

#define WEBSERVER_PORT 80

#define SENSOR_PORTS { 4, 5 }

