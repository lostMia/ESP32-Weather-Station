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


namespace sens{
    
    void Sensor::begin()
    {
        dht.begin();
    }
    void Sensor::update_values()
    {
        sensors_event_t event;
        // Get temperature event and print its value.
        dht.temperature().getEvent(&event);
        if (isnan(event.temperature)) {
            Serial.println(F("Error reading temperature!"));
        }
        else {
            Serial.print(F("Temperature: "));
            Serial.print(event.temperature);
            inner_temperature = event.temperature;
            Serial.println(F("°C"));
        }
        // Get humidity event and print its value.
        dht.humidity().getEvent(&event);
        if (isnan(event.relative_humidity)) {
            Serial.println(F("Error reading humidity!"));
        }
        else {
            Serial.print(F("Humidity: "));
            Serial.print(event.relative_humidity);
            inner_humidity = event.relative_humidity;
            Serial.println(F("%"));
        }
        calculateHeatIndex(inner_temperature, inner_humidity);
    }
    void Sensor::calculateHeatIndex(float temperatureC, float humidity) {
    // Convert temperature from Celsius to Fahrenheit
    float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

    // Calculate heat index in Fahrenheit using the formula
    float heatIndexF = -42.379 + 2.04901523 * temperatureF + 10.14333127 * humidity
                        - 0.22475541 * temperatureF * humidity - 0.00683783 * pow(temperatureF, 2)
                        - 0.05481717 * pow(humidity, 2) + 0.00122874 * pow(temperatureF, 2) * humidity
                        + 0.00085282 * temperatureF * pow(humidity, 2) - 0.00000199 * pow(temperatureF, 2) * pow(humidity, 2);

    // Convert heat index back to Celsius
    float heatIndexC = (heatIndexF - 32.0) * 5.0 / 9.0;
    inner_heat_index = heatIndexC;
    }
} // namespace sens