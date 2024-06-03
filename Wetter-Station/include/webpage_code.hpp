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
    <h3>API Innsbruck Wetter Station</h3>
    <p>Luftdruck: <span id="pressure">Loading...</span> hPa</p>
    <p>Feuchtigkeit: <span id="humidity">Loading...</span> %</p>
    <p>Niederschlag: <span id="rain_amount">Loading...</span> mm</p>
    <p>Niederschlag dauer: <span id="rain_duration">Loading...</span> minuten</p>
    <p>Temperatur: <span id="temperature">Loading...</span> C</p>
    <p>Wind Richtung: <span id="wind_direction">Loading...</span> degrees</p>
    <p>Wind Durchschnittsgeschwindigkeit: <span id="wind_speed_average">Loading...</span> m/s</p>
    <p>Wind Maximalgeschwindigkeit: <span id="wind_speed_max">Loading...</span> m/s</p>
    <p>Sonnenschein: <span id="sunshine_amount">Loading...</span> sekunden</p>
    <h3>Sensordaten</h3>
    <div id="sensor-data-container">
        Loading data...
    </div>

    <script>
        function updateAPIData() {
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
            })
            .catch(error => console.error('Error fetching API Data!:', error));
        }
        
        async function updateSensorData() {
            try {
                const response = await fetch("/sensors");
                if (!response.ok) {
                    throw new Error(`HTTP error! status: ${response.status}`);
                }
                const data = await response.json();
                updateSensorUI(data);
            } catch (error) {
                console.error('Error fetching data:', error);
                document.getElementById("sensor-data-container").textContent = 'Error fetching data';
            }
        }

        function updateSensorUI(data) {
            const container = document.getElementById("data-container");
            container.innerHTML = ''; // Clear existing content

            data.forEach(sensor => {
                const div = document.createElement("div");
                div.className = "sensor-data";
                div.textContent = `Sensor ${sensor.id} - Temperature: ${sensor.temperature} °C, Humidity: ${sensor.humidity} %`;
                container.appendChild(div);
            });
        }

        updateSensorData();
        setInterval(updateSensorData, 1000);

        updateAPIData();
        setInterval(updateAPIData, 1000);
    </script>
</body>
</html>
)=====";
    
} // namespace Web