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


Status Client::begin()
{
  bool result;
  
  result = _client.begin(API_QUERY);

  if (!result)
  {
    return ERROR;
  }
  return OKAY;
}

Status Client::update_values()
{
  String response;
  int response_code = _client.GET();

  if (response_code != 200) 
  {
    Serial.printf("HTTP GET failed, error code: %d \nerror: %s\nResponse: %s\n", response_code, _client.errorToString(response_code).c_str(), _client.getString().c_str());
    return ERROR;
  }

  response = _client.getString();
  int result = _parse_json(&response);

  _client.end();
  
  if (result != OKAY)
  {
    Serial.printf("Values from response could not be resolved\nResponse: %s\n", response.c_str());
    return ERROR;
  }

  return OKAY;
}

Status Client::_parse_json(String* presponse)
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
  
  uint8_t count = 0;
  for (String parameter : parameter_strings)
  {
    *variables[count] = parameters[parameter]["data"][0];
    count++;
  }

  return OKAY;
}

} // Namespace API
