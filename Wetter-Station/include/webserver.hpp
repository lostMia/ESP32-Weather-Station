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
#include <ArduinoJson.h>
#include <vector>
#include <memory>

#include "api.hpp"
#include "sensor.hpp"
#include "enums.hpp"

//#define DEFINE_ME_IF_YOURE_GETTING_API_RATELIMITED

namespace Web
{

class Server
{
private:
    AsyncWebServer _server;
    String _api_data_string;
    String _sensor_data_string;
    API::Client *_p_client;
    std::vector<std::unique_ptr<sens::Sensor>> *_p_sensors;
    
    
    void _add_to_json_string(String* string, String* parameter, float* value);
    void _update_api_string();
    void _update_sensor_string();
public:
    Server(uint16_t port);

    void begin(API::Client *client, std::vector<std::unique_ptr<sens::Sensor>> *sensors);
    void update_values();
};

} // namespace Web