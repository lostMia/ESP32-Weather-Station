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
	    * {
		font-family: 'Tahoma', sans-serif;
	    }

            body {
		background-image: url('https://images.hdqwalls.com/wallpapers/cloud-view-from-flight-4k-16.jpg');
		background-repeat: no-repeat;
  		background-attachment: fixed;
  		background-size: cover;
                color: white;
            }

            div {
                background-color: #22222250;
		padding: 10px 10px 10px 10px;
            }
        </style>
</head>
<body>
    <h1>ESP32 Wetter</h1>
    <div>
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
    </div>	
    <h3>Sensordaten</h3>
    <div>
    	<div id="sensor_data">
        	Loading data...
    	</div>
    </div>
    <script>
        function updateAPIData() {
            fetch("/api")
                .then(response => response.json())
                .then(data => {
                    document.getElementById("pressure").textContent = data.P;
                    document.getElementById("humidity").textContent = data.RFAM;
                    document.getElementById("rain_amount").textContent = data.RR;
                    document.getElementById("rain_duration").textContent = data.RRM;
                    document.getElementById("temperature").textContent = data.TL;
                    document.getElementById("wind_direction").textContent = data.DD;
                    document.getElementById("wind_speed_average").textContent = data.FFAM;
                    document.getElementById("wind_speed_max").textContent = data.FFX;
                    document.getElementById("sunshine_amount").textContent = data.SO;
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
                console.error('Error fetching Sensor Data!:', error);
                document.getElementById("sensor_data").textContent = 'Error fetching Sensor Data';
            }
        }

        function updateSensorUI(data) {
            const container = document.getElementById("sensor_data");
            container.innerHTML = ''; // Clear existing content

            data.forEach(sensor => {
                const div = document.createElement("div");
                div.className = "sensor-data";
                div.textContent = `Sensor ${sensor.id}\nTemperature C: ${sensor.temperatureC} °C\nTemperature F: ${sensor.temperatureF} °F\nHumidity: ${sensor.humidity} %\nHeat Index C ${sensor.heat_index} °C`;
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