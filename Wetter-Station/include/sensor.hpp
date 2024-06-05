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
#include <math.h>

#define DHTTYPE    DHT22     // DHT 22

namespace sens
{

class Sensor
{
private:
    DHT_Unified *_dht;
public:
    uint8_t _pin = 0;
    float _temperatureC = -1;
    float _temperatureF = -1;
    float _heat_indexC = -1;
    float _heat_indexF = -1;
    float _humidity = -1;
    float *_variables[5] = 
    {
        &_temperatureC, &_temperatureF, &_heat_indexC, &_heat_indexF, &_humidity
    };
    
    const String _parameter_strings[5] = 
    {
        "temperatureC", "temperatureF", "heat_indexC", "heat_indexF", "humidity"
    };

    Sensor(uint8_t pin);

    ~Sensor();

    void begin();
    void update_values();
    void calculate_heat_index();
};

} // namespace sens