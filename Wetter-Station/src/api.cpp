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
  int response_code = _client.GET();

  if (response_code != 200) 
  {
    Serial.printf("HTTP GET failed, error code: %d \nerror: %s\nResponse: %s", response_code, _client.errorToString(response_code).c_str(), _client.getString().c_str());
    return ERROR;
  }

  String response = _client.getString();
  Serial.println("Response:");
  Serial.println(response);

  _client.end();

  return OK;
}

uint8_t Client::_parse_json(String& response)
{
  // Todo::
  // Update internal values by extracting them from the json.

  return 0;
}

}