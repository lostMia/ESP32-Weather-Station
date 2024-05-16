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
                    "?parameters=P,RR,RRM,TL,DD,FFX,FFAM,RFAM,SO" \
                    "&station_ids=11035" \
                    "&output_format=geojson"

#define API_QUERY_DELAY 60 * 10  // Wait 10 minutes between every request

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

    STATUS _parse_json(String* presponse);
public:
    float air_pressure = -1;    // Air pressure in hPa
    float humidity = -1;        // Air humidity in % 
    float rain_amount = -1;     // Amount of rain in mm
    float rain_duration = -1;   // Time of rain in min
    float temperature = -1;     // Temperature of the air in °C
    float wind_direction = -1;  // Direction of the wind in °
    float wind_speed_average = -1;   // Average wind speed in m/s
    float wind_speed_max = -1;  // Maximum wind speed in m/s
    float sunshine_amount = -1; // Amount of sunshine in seconds 
    //time_t last_updated_time;   // The time that the values were last updated.
                                  
     /**
     * @brief Initializes the client.
     * @returns 
     *          INVALID_URL when an invalid url to the api is given.
     */
    STATUS begin();
    
    /**
    * @brief Sends a HTTP GET request to the API and 
    * updates internal client variables with the returned values.
    * @returns  
    *           ERROR when there was an error with the request.
    */
    STATUS update_values();
    
};

}