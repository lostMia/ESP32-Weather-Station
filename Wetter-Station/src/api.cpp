/*
 * @file api.cpp
 * @authors lostmia
 * @brief 
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#include "api.hpp"

namespace API
{


STATUS Client::begin()
{
  bool result;
  
  result = _client.begin(API_QUERY);

  if (!result)
  {
    return ERROR;
  }
  return OK;
}

STATUS Client::update_values()
{
  String response;
  int response_code = _client.GET();

  if (response_code != 200) 
  {
    Serial.printf("HTTP GET failed, error code: %d \nerror: %s\nResponse: %s", response_code, _client.errorToString(response_code).c_str(), _client.getString().c_str());
    return ERROR;
  }

  response = _client.getString();
  int result = _parse_json(&response);

  _client.end();
  
  if (result != OK)
  {
    Serial.printf("Values from response could not be resolved\nResponse: %s", response.c_str());
    return ERROR;
  }

  return OK;
}

STATUS Client::_parse_json(String* presponse)
{
  String response = *presponse;
  JsonDocument response_json;
  DeserializationError error;

  error = deserializeJson(response_json, response);

  if (error) 
  {
    return ERROR;
  }

  JsonObject parameters = response_json["features"]
                          [0]
                          ["properties"]
                          ["parameters"];

  air_pressure = parameters["P"]["data"][0];
  humidity = parameters["RFAM"]["data"][0];
  rain_amount = parameters["RR"]["data"][0];
  rain_duration = parameters["RRM"]["data"][0];
  temperature = parameters["TL"]["data"][0];
  wind_direction = parameters["DD"]["data"][0];
  wind_speed_average = parameters["FFAM"]["data"][0];
  wind_speed_max = parameters["FFX"]["data"][0];
  sunshine_amount = parameters["SO"]["data"][0];

  return OK;
}

} // Namespace API
