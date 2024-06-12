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

const char* doku_HTML = 
R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">
    <title>API Dokumentation</title>
    <style>
        body {
            background-image: url('https://images.hdqwalls.com/wallpapers/cloud-view-from-flight-4k-16.jpg');
            background-repeat: no-repeat;
            background-attachment: fixed;
            background-size: cover;
            color: white;
            font-family: 'Tahoma', sans-serif;
        }
        .title {
                padding: 5px;
                border: 3px dashed #ff8080;
                font-weight: bold;
                text-align: center;
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
    <script>
        function movetoHome() {
            window.location.href = "/";
        }
    </script>
    <h1 class="title">API Dokumentation</h1>
    <h2>GET /api</h2>
    <p>Erhalten sie die aktuellen wetterdaten der Wetterstation Innsbruck Universität.</p>
    <p>Die Daten werden in einem JSON Format zurückgegeben.</p>
    <p>Es werden Luftdruck(P), Luftfeuchtigkeit(RFAM), Niederschlagsmenge(RR), Niederschlagsdauer(RRM) Temperatur(TL), Windrichtung(DD), Durchschnittliche Windgeschwindigkeit(FFAM), Maximale Windgeschwindigkeit(FFX) und Sonnenschein dauer(SO) zurückgegeben.</p>
    <p>Beispiel:</p>
    <p>{"P":992.40,"RFAM":59.00,"RR":0.00,"RRM":0.00,"TL":16.50,"DD":308.00,"FFAM":1.50,"FFX":2.70,"SO":0.00}</p>
    <h2>GET /sensors</h2>
    <p>Erhalten sie die aktuellen Sensordaten der and den ESP angeschlossenen Sensoren.</p>
    <p>Die Daten werden in einem JSON Format zurückgegeben.</p>
    <p>Es werden die Temperatur in Celsius(temperatureC), die Temperatur in Fahrenheit(temperatureF), der Hitzeindex in Celsius und Fahrenheit(heat_indexC, heat_indexF), die Luftfeuchtigkeit in Prozent(humidity) und die ID des sensors beginnent mit 0 (id) zurückgegeben</p>
    <p>Beispiel bei einem sensor:</p>
    <p>[{"temperatureC":"21.60","temperatureF":"70.88","heat_indexC":"24.92","heat_indexF":"76.85","humidity":"50.40","id":0}]</p>
    <p>Beispiel bei zwei Sensoren:</p>
    <p>[{"temperatureC":"21.70","temperatureF":"71.06","heat_indexC":"24.92","heat_indexF":"76.85","humidity":"50.40","id":0},{"temperatureC":"21.70","temperatureF":"71.06","heat_indexC":"24.92","heat_indexF":"76.86","humidity":"50.20","id":1}]</p>
    
    <input type="submit" onClick="movetoHome()" value="Zurück" class="button" />

</body>
)=====";
}