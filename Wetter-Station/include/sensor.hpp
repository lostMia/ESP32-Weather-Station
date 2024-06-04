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
    float _humidity = -1;
    float _heat_index = -1;
    float *_variables[4] = 
    {
        &_temperatureC, &_temperatureF, &_humidity, &_heat_index
    };
    
    String _parameter_strings[4] = 
    {
        "temperatureC", "temperatureF", "humidity", "heat_index"
    };

    Sensor(uint8_t pin);

    ~Sensor();

    void begin();
    void update_values();
    void calculateHeatIndex();

};

} // namespace sens