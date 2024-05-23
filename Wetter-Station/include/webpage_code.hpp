/*
 * @file webpage_code.h
 * @authors Timeania, lostmia
 * @brief Defines the HTML code for the webpage to be hosted.
 * @version 0.1.0
 * @date 2024-05-21
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/

#pragma once

namespace Web
{

const char* webpage_HTML = 
R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">
    <title>ESP32 Wetter</title>
    <style>
            body {
                background-color: #222222;
                color: white;
            }
        </style>
</head>
<body>
    <h1>ESP32 Wetter</h1>
    <p>Luftdruck: <span id="pressure">Loading...</span> hPa</p>
    <p>Feuchtigkeit: <span id="humidity">Loading...</span> %</p>
    <p>Niederschlag: <span id="rain_amount">Loading...</span> mm</p>
    <p>Niederschlag dauer: <span id="rain_duration">Loading...</span> minuten</p>
    <p>Temperatur: <span id="temperature">Loading...</span> C</p>
    <p>Wind Richtung: <span id="wind_direction">Loading...</span> degrees</p>
    <p>Wind Durchschnittsgeschwindigkeit: <span id="wind_speed_average">Loading...</span> m/s</p>
    <p>Wind Maximalgeschwindigkeit: <span id="wind_speed_max">Loading...</span> m/s</p>
    <p>Sonnenschein: <span id="sunshine_amount">Loading...</span> sekunden</p>

    <script>
        function updateData() {
            fetch("/data")
                .then(response => response.json())
                .then(data => {
                    document.getElementById("pressure").textContent = data.P + " hPa";
                    document.getElementById("humidity").textContent = data.RFAM + " %";
                    document.getElementById("rain_amount").textContent = data.RR + " mm";
                    document.getElementById("rain_duration").textContent = data.RRM + " min";
                    document.getElementById("temperature").textContent = data.TL + " °C";
                    document.getElementById("wind_direction").textContent = data.DD + " degrees";
                    document.getElementById("wind_speed_average").textContent = data.FFAM + " m/s";
                    document.getElementById("wind_speed_max").textContent = data.FFX + " m/s";
                    document.getElementById("sunshine_amount").textContent = data.SO + " seconds";
                    document.getElementById("inner_temp").textContent = data.inner_temp + " C";
                    document.getElementById("inner_hum").textContent = data.inner_hum + " %";
                    document.getElementById("inner_heat_index").textContent = data.inner_heat_index + " C";
                })
                .catch(error => console.error('Error fetching data:', error));
        }

        updateData();
        setInterval(updateData, 5000);
    </script>
    <h1>Wetter im Raum (oda so keine ahnung wie i des sonsch nennen soll])</h1>
    <p>Innentemperatur: <span id="inner_temp">Loading...</span> C</p>
    <p>Luftfeuchtigkeit: <span id="inner_hum">Loading...</span> %</p>
    <p>Hitzeindex: <span id="inner_heat_index">Loading...</span> C</p>
</body>
</html>
)=====";
    
} // namespace Web