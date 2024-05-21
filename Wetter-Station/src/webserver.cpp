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

void Server::begin() 
{
  _server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) 
  {
    request->send_P(200, "text/html", webpage_HTML);
  });

  _server.begin();
}

void Server::update_values(API::Client *client) 
{
  uint8_t count = 0;
  for (float *variable : client->variables)
  {
    String variable_string = String(*variable, 2);
    String parameter_string = "/" + client->parameter_strings[count];

    _server.on(parameter_string.c_str(), HTTP_GET, [variable_string](AsyncWebServerRequest* request) 
    {
        request->send(200, "text/plain", variable_string);
    });

    count++;
  }
}

} // namespace Web