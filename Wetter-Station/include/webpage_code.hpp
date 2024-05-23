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
        function updatePressure() {
            fetch("/P")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("pressure").textContent = data;
                });
        }

        function updateHumidity() {
            fetch("/RFAM")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("humidity").textContent = data;
                });
        }

        function updateRainAmount() {
            fetch("/RR")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("rain_amount").textContent = data;
                });
        }

        function updateRainDuration() {
            fetch("/RRM")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("rain_duration").textContent = data;
                });
        }

        function updateTemperature() {
            fetch("/TL")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("temperature").textContent = data;
                });
        }

        function updateWindDirection() {
            fetch("/DD")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("wind_direction").textContent = data;
                });
        }

        function updateWindSpeedAverage() {
            fetch("/FFAM")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("wind_speed_average").textContent = data;
                });
        }

        function updateWindSpeedMax() {
            fetch("/FFX")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("wind_speed_max").textContent = data;
                });
        }

        function updateSunshineAmount() {
            fetch("/SO")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("sunshine_amount").textContent = data;
                });
        }

        function startUpdating(updateFunction, interval) {
            updateFunction();
            setInterval(updateFunction, interval);
        }

        startUpdating(updatePressure, 5000);
        startUpdating(updateHumidity, 5000);
        startUpdating(updateRainAmount, 5000);
        startUpdating(updateRainDuration, 5000);
        startUpdating(updateTemperature, 5000);
        startUpdating(updateWindDirection, 5000);
        startUpdating(updateWindSpeedAverage, 5000);
        startUpdating(updateWindSpeedMax, 5000);
        startUpdating(updateSunshineAmount, 5000);
    </script>
    <h1>Wetter im Raum (oda so keine ahnung wie i des sonsch nennen soll])</h1>
    <p>Innentemperatur: <span id="inner_temp">Loading...</span> C</p>
    <p>Luftfeuchtigkeit: <span id="inner_hum">Loading...</span> %</p>
    <p>Hitzeindex: <span id="inner_heat_index">Loading...</span> C</p>
</body>
</html>
)=====";
    
} // namespace Web