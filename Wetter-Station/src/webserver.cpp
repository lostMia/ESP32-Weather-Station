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

Server::Server(uint16_t port) : _server(port)
{}

void Server::_add_to_json_string(String* variable_string, String* parameter, float* value)
{
  String parameter_string = *parameter;
  String value_string = String(*value, 2);

  *variable_string += "\"" + parameter_string + "\":" + value_string + ",";
}

void Server::_update_api_string()
{
  uint8_t count = 0;
  _api_data_string = "{";

  for (float *variable : _p_client->_variables)
  {
    _add_to_json_string(&_api_data_string, &_p_client->_parameter_strings[count], _p_client->_variables[count]);

    count++;
  }

  // Deletes the last ',' from the string.
  _api_data_string.remove(_api_data_string.length() - 1);
  _api_data_string += "}";
}

void Server::_update_sensor_string()
{ 
  JsonDocument json_doc;

  JsonArray array = json_doc.to<JsonArray>();

  uint8_t id = 0;
  for (auto &sensor : *_p_sensors) {
    JsonObject obj = array.add<JsonObject>();

    obj["id"] = id;
    obj["temperatureC"] = sensor->_temperatureC;
    obj["temperatureF"] = sensor->_temperatureF;
    obj["humidity"] = sensor->_humidity;
    obj["heat_index"] = sensor->_heat_index;

    id++;
  }

  serializeJson(json_doc, _sensor_data_string);
}

void Server::begin(API::Client *client, std::vector<std::unique_ptr<sens::Sensor>> *sensors) 
{
  _p_client = client;
  _p_sensors = sensors;

  client->begin();

  for (auto &sensor : *_p_sensors)
    sensor->begin();

  _server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) 
  {
    request->send_P(200, "text/html", webpage_HTML);
  });
  _server.on("/api", HTTP_GET, [this](AsyncWebServerRequest* request) 
  {
    request->send(200, "text/plain", _api_data_string.c_str());
  });
  _server.on("/sensors", HTTP_GET, [this](AsyncWebServerRequest* request) 
  {
    request->send(200, "text/plain", _sensor_data_string.c_str());
  });

  _server.begin();
}

void Server::serve()
{
  unsigned long current_time = millis();
  unsigned long last_api_update_time = current_time;
  unsigned long last_sensor_update_time =  current_time;

  while (true)
  {
    current_time = millis();

#ifndef DISABLE_API
    if (current_time - last_api_update_time > API_QUERY_DELAY)
    {
      last_api_update_time = current_time;

      _p_client->update_values();
      _update_api_string();
    }
#endif
    
    if (current_time - last_sensor_update_time > SENSOR_UPDATE_DELAY)
    {
      last_sensor_update_time = current_time;
      for (auto &sensor : *_p_sensors)
        sensor->update_values();

      _update_sensor_string();
    }
  }
}

} // namespace Web