/*
 * @file sensor.cpp
 * @authors Timeania, lostmia
 * @brief Defines a Sensor class for interacting with the Sensor.
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#pragma once

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4 

#define DHTTYPE    DHT22     // DHT 22
namespace sens
{

class Sensor
{
private:
    DHT_Unified dht{DHTPIN, DHTTYPE};
public:
    float inner_temperature = -1;
    float inner_humidity = -1;
    float inner_heat_index = -1;
    float *variables[3] = 
    {
        &inner_temperature, &inner_humidity, &inner_heat_index
    };

    String parameter_strings[3] = 
    {"inner_temp", "inner_hum", "inner_heat_index"};

    void begin();
    void update_values();
    void calculateHeatIndex(float temperatureC, float humidity);

};

} // namespace sens