/*
 * @file sensor.cpp
 * @authors Timeania, lostmia
 * @brief Defines a Sensor class for interacting with the Sensor.
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#include "sensor.hpp"


namespace sens
{

    Sensor::Sensor(uint8_t pin)
    {
        _pin = pin;
    }
   
    Sensor::~Sensor()
    {
        if (_dht)
            delete _dht;
    }

    void Sensor::begin()
    {
        _dht = new DHT_Unified(_pin, DHTTYPE);
        _dht->begin();
    }

    void Sensor::update_values()
    {
        sensors_event_t event;
        bool invalid_numbers = false;

        // Get temperature event and print its value.
        _dht->temperature().getEvent(&event);
        
        if (isnan(event.temperature)) 
        {
            invalid_numbers = true;
            Serial.println(F("Error reading temperature!"));
        }
        else 
        {
            Serial.print(F("Temperature: "));
            Serial.print(event.temperature);
            Serial.println(F("°C"));
            _temperatureC = event.temperature;
        }

        // Get humidity event and print its value.
        _dht->humidity().getEvent(&event);

        if (isnan(event.relative_humidity)) 
        {
            invalid_numbers = true;
            Serial.println(F("Error reading humidity!"));
        }
        else 
        {
            Serial.print(F("Humidity: "));
            Serial.print(event.relative_humidity);
            Serial.println(F("%"));
            _humidity = event.relative_humidity;
        }

        if (invalid_numbers)
            return;

        calculateHeatIndex();
    }

    void Sensor::calculateHeatIndex()
    {
        // Convert temperature from Celsius to Fahrenheit
        _temperatureF = (_temperatureC * 9.0 / 5.0) + 32.0;

        // Calculate heat index in Fahrenheit using the formula
        float heatIndexF = -42.379 + 2.04901523 * _temperatureF + 10.14333127 * _humidity
                            - 0.22475541 * _temperatureF * _humidity - 0.00683783 * pow(_temperatureF, 2)
                            - 0.05481717 * pow(_humidity, 2) + 0.00122874 * pow(_temperatureF, 2) * _humidity
                            + 0.00085282 * _temperatureF * pow(_humidity, 2) - 0.00000199 * pow(_temperatureF, 2) * pow(_humidity, 2);

        // Convert heat index back to Celsius
        _heat_index = (heatIndexF - 32.0) * 5.0 / 9.0;
    }

} // namespace sens