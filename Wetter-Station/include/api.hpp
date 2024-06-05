/*
 * @file api.hpp
 * @authors lostmia
 * @brief Defines a Client class used for interacting with the weather API.
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#pragma once

#define API_QUERY   "https://dataset.api.hub.geosphere.at" \
                    "/v1/station/current/" \
                    "tawes-v1-10min" \
                    "?parameters=P,RR,RRM,TL,DD,FFX,FFAM,RFAM,SO" \
                    "&station_ids=11035" \
                    "&output_format=geojson"


#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "enums.hpp"

// This Namespace and all it's functions and classes are used for
// communication with the weather api, and getting its values from 
// the internet.
namespace API
{

class Client
{
private:
    HTTPClient _client;

    Status _parse_json(String* presponse);
public:
    float _air_pressure = -1;    // Air pressure in hPa
    float _humidity = -1;        // Air humidity in % 
    float _rain_amount = -1;     // Amount of rain in mm
    float _rain_duration = -1;   // Time of rain in min
    float _temperature = -1;     // Temperature of the air in °C
    float _wind_direction = -1;  // Direction of the wind in °
    float _wind_speed_average = -1;   // Average wind speed in m/s
    float _wind_speed_max = -1;  // Maximum wind speed in m/s
    float _sunshine_amount = -1; // Amount of sunshine in seconds 
    float *_variables[9]  =      // Pointers to all the Variables in order.
    {    
        &_air_pressure, &_humidity, &_rain_amount, &_rain_duration,
        &_temperature, &_wind_direction, &_wind_speed_average, 
        &_wind_speed_max, &_sunshine_amount
    };
    String _parameter_strings[9] =      // Pointers to all parameter strings in order.
    {
        "P", "RFAM", "RR", "RRM", "TL", "DD", "FFAM", "FFX", "SO"
    };
                                  
     /**
     * @brief Initializes the client.
     * @returns 
     *          INVALID_URL when an invalid url to the api is given.
     */
    Status begin();
    
    /**
    * @brief Sends a HTTP GET request to the API and 
    * updates internal client variables with the returned values.
    * @returns  
    *           ERROR when there was an error with the request.
    */
    Status update_values();
};

} // nampespace API