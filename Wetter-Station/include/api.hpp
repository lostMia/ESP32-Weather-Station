/*
 * @file api.hpp
 * @authors lostmia
 * @brief 
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#pragma once

#define API_QUERY   "https://dataset.api.hub.geosphere.at" \
                    "/v1/station/current/" \
                    "tawes-v1-10min" \
                    "?parameters=P,RR,RRM,TL,DD" \
                    "&station_ids=11803" \
                    "&output_format=geojson"

#include <HTTPClient.h>
#include <ArduinoJson.h>

// This Namespace and all it's functions and classes are used for
// communication with the weather api, and getting its values from 
// the internet.
namespace API
{

// Return codes for the api.
enum STATUS
{
    OK = 0,
    ERROR = 1,
};

class Client
{
private:
    HTTPClient _client;

    uint8_t _parse_json(String* presponse);
public:
    // int16_t sunshine_amount = -1; // Amount of sunshine in Watt per square meter
    int16_t air_pressure = -1;    // Air pressure in hPa
    //int16_t humidity = -1;       // Humidity in %
    int16_t rain_amount = -1;     // Amount of rain in mm
    int16_t rain_duration = -1;   // Time of rain in min
    int16_t temperature = -1;     // Temperature of the air in °C
    int16_t wind_direction = -1;  // Direction of the wind in °
    //int16_t wind_speed = -1;      // Windspeed in m/s
                                  
     /**
     * @brief Initializes the client.
     * @returns 
     *          INVALID_URL when an invalid url to the api is given.
     */
    uint8_t begin();
    
    /**
    * @brief Sends a HTTP GET request to the API and 
    * updates internal client variables with the returned values.
    * @returns  
    *           ERROR when there was an error with the request.
    */
    uint8_t update_values();
    
};

}