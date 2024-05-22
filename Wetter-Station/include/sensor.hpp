/*
 * @file sensor.cpp
 * @authors Timeania, lostmia
 * @brief Defines a Sensor class for interacting with the Sensor.
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/
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
    void begin();
    void update_values();
};

} // namespace sens