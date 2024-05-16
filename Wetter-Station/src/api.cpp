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


uint8_t Client::begin()
{
  bool result;
  
  result = _client.begin(API_QUERY);

  if (!result)
  {
    return ERROR;
  }
  return OK;
}

uint8_t Client::update_values()
{
  String response = "";
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
    Serial.printf("Values from response could not be resolved\nResponse: %s", response);
    return ERROR;
  }

  return OK;
}

uint8_t Client::_parse_json(String* presponse)
{
  String response = *presponse;
  uint16_t response_length = response.length();

  DynamicJsonDocument response_json(response_length);
  DeserializationError error = deserializeJson(response_json, response);

  if (error) 
  {
    return ERROR;
  }

  JsonArray parameters = response_json["features"]["properties"]["parameters"].as<JsonArray>();
  uint8_t index = 0;

  // Parameters are always returned in the order we specify them in the url,
  // therefore we can simply loop through them.
  for (JsonObject parameter : parameters)
  {
    JsonArray data = parameter["data"].as<JsonArray>();

    int value = data[0].as<uint16_t>();
    
    switch(index)
    {
      case 0:
        air_pressure = data;
        break;
      case 1:
        rain_amount = data;
        break;
      case 2:
        rain_duration  = data;
        break;
      case 3:
        temperature = data;
        break;
      case 4:
        wind_direction = data;
        break;
    }
    index++;
  }

  return OK;
}

} // Namespace API
