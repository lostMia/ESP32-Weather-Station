/*
 * @file webserver.hpp
 * @authors Timeania, lostmia
 * @brief Defines a Server class for interacting with the webserver.
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

#include "api.hpp"
#include "sensor.hpp"
#include "enums.hpp"

namespace Web
{

class Server
{
private:
    AsyncWebServer _server;
    
    void _add_to_variable_string(String* variable_string, String* parameter, float* value);
public:
    Server(uint16_t port) : _server(port) 
    {};

    void begin();
    void update_values(API::Client *client, sens::Sensor *sensor);
};

} // namespace Web