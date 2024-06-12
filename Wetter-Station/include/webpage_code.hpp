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
		    background-image: url('https://images.hdqwalls.com/wallpapers/cloud-view-from-flight-4k-16.jpg');
		    background-repeat: no-repeat;
  		    background-attachment: fixed;
  		    background-size: cover;
            color: white;
		    font-family: 'Tahoma', sans-serif;
        }

        .sensor-container,
        .data-container {
            display: flex;
            flex-direction: column;
            background-color: #22222250;
		    padding: 20px;
            margin: 20px;
            border: 3px solid #ffff70;
            border-radius: 20px;
        }
        
        .sensor-container {
            flex-direction: row;
            background-color: #22222250;
        }

        .title {
            padding: 5px;
            border: 3px dashed #ff8080;
            font-weight: bold;
            text-align: center;
        }

        .sensor {
            background-color: #22222250;
            margin: 20px;
		    padding: 10px;
            border: 3px solid #ff9966;
            border-radius: 10px;
        }
        .button {
            border-width: 10;
            border-color: rgb(0, 0, 0);
            background-color: #ff9966;
            color: rgb(0, 0, 0);
            padding: 14px 28px;
            font-size: 16px;
            cursor: pointer;
            text-align: center;
            position: relative;
        }
    </style>
</head>
<body>
    <h1>Wetter in Innsbruck</h1>
    <div>
        <div class="data-container">
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
        <div class="sensor-container" id="sensor-container"></div>
    </div>
    <script>
        function updateSensorData() {
            fetch("/sensors")
                .then(response => response.json())
                .then(data => {
                    const container = document.getElementById('sensor-container');
                    container.innerHTML = '';

                    data.forEach(sensor => {
                        const sensorDiv = document.createElement('div');
                        sensorDiv.className = 'sensor';
                        
                        const sensorTitle = document.createElement('div');
                        sensorTitle.className = 'title';
                        sensorTitle.textContent = `Sensor ${sensor.id}`;
                        sensorDiv.appendChild(sensorTitle);

                        const tempCP = document.createElement('p');
                        tempCP.id = `temperature-${sensor.pin}`;
                        tempCP.textContent = `Temperature: ${sensor.temperatureC} °C`;
                        sensorDiv.appendChild(tempCP);

                        const tempFP = document.createElement('p');
                        tempFP.textContent = `Temperature: ${sensor.temperatureF} °F`;
                        sensorDiv.appendChild(tempFP);

                        const heatCP = document.createElement('p');
                        heatCP.textContent = `Heatindex: ${sensor.heat_indexC} °C`;
                        sensorDiv.appendChild(heatCP);

                        const heatFP = document.createElement('p');
                        heatFP.textContent = `Heatindex ${sensor.heat_indexF} °F`;
                        sensorDiv.appendChild(heatFP);

                        const humP = document.createElement('p');
                        humP.textContent = `Humidity: ${sensor.humidity} %`;
                        sensorDiv.appendChild(humP);

                        container.appendChild(sensorDiv);
                    });
                })
                .catch(error => console.error('Error fetching sensor data:', error));
        }

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
        function movetoDoku() {
            window.location.href = "/doku";
        }
        updateSensorData();
        setInterval(updateSensorData, 500)
        updateAPIData();
        setInterval(updateAPIData, 1000);
    </script>
    <input type="submit" onClick="movetoDoku()" value="Dokumentation" class="button" />
</a>
</body>
</html>
)=====";
    
} // namespace Web