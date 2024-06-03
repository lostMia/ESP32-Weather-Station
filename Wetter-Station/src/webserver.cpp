/*
 * @file webserver.cpp
 * @authors Timeania, lostmia
 * @brief Defines a Server class for interacting with the webserver.
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#include "webserver.hpp"
#include "webpage_code.hpp"

namespace Web
{

void Server::_add_to_variable_string(String* variable_string, String* parameter, float* value)
{
  String parameter_string = *parameter;
  String value_string = String(*value, 2);
  *variable_string += "\"" + parameter_string + "\":" + value_string + ",";
}

void Server::begin() 
{
  _server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) 
  {
    request->send_P(200, "text/html", webpage_HTML);
  });
  _server.on("/data", HTTP_GET, [this](AsyncWebServerRequest* request) 
  {
    request->send(200, "text/plain", variable_string.c_str());
  });

  _server.begin();
}

void Server::update_values(API::Client *client, sens::Sensor *sensor) 
{
  uint8_t count = 0;
  variable_string = "{";

  for (float *variable : client->variables)
  {
    _add_to_variable_string(&variable_string, &client->parameter_strings[count], client->variables[count]);

    count++;
  }

  count = 0;
  for (float *variable : sensor->variables)
  {
    _add_to_variable_string(&variable_string, &sensor->parameter_strings[count], sensor->variables[count]);

    count++;
  }

  // Deletes the last ',' from the string.
  variable_string.remove(variable_string.length() - 1);
  variable_string += "}";
}

} // namespace Web