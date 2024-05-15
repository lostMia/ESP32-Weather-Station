/*
 * @file webpage_code.h
 * @authors Timeania
 * @brief 
 * @version 0.1.0
 * @date 2024-05-15
 *
 * Copyright Deimo Elektronik GmbH (c) 2024
*/
#pragma once
#define WEBPAGE_H

const char* webpage_HTML = R"=====(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Wetter</title>
</head>
<body>
    <h1>ESP32 Wetter</h1>
    <p>Temperatur: <span id="temp">Loading...</span> &#8451;</p>
    <p>Luftfeuchtigkeit: <span id="humid">Loading...</span> &#37;</p>
    <p>Windgeschwindigkeit: <span id="ff">Loading...</span> m/s</p>
    <p>Windrichtung <span id="dd">Loading...</span> &#176;</p>
    <p>Luftdruck: <span id="press">Loading...</span> hPa</p>
    <script>
        function updateTemp() {
            fetch("/temperature")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("temp").textContent = data.temp;
                });
        }
        updateTemp();
        setInterval(updateTemp, 5000);
        function updateHumid() {
            fetch("/humidity")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("humid").textContent = data.humid;
                });
        }
        updateHumid();
        setInterval(updateHumid, 5000);
        function updateFF() {
            fetch("/windSpeed")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("ff").textContent = data.ff;
                });
        }
        updateFF();
        setInterval(updateFF, 5000);
        function updateDD() {
            fetch("/windDirection")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("dd").textContent = data.dd;
                });
        }
        updateDD();
        setInterval(updateDD, 5000);
        function updatePress() {
            fetch("/pressure")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("press").textContent = data.press;
                });
        }
        updatePress();
        setInterval(updatePress, 5000);
    </script>

</body>
</html>
)=====";