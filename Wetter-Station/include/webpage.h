#ifndef WEBPAGE_H
#define WEBPAGE_H

const char* webpage = R"=====(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Temperatur</title>
</head>
<body>
    <h1>ESP32 Temperatur</h1>
    <p>Temperatur: <span id="temp">Loading...</span> &#8451;</p>
    <p>Luftfeuchtigkeit: <span id="humid">Loading...</span> &#37;</p>
    <p>Windgeschwindigkeit: <span id="ff">Loading...</span> m/s</p>
    <p>Windrichtung <span id="dd">Loading...</span> &#176;</p>
    <p>Luftdruck: <span id="press">Loading...</span> hPa</p>
    <script>
        function updateData() {
            fetch("/data")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("temp").textContent = data.temp;
                    document.getElementById("humid").textContent = data.humid;
                    document.getElementById("ff").textContent = data.ff;
                    document.getElementById("dd").textContent = data.dd;
                    document.getElementById("press").textContent = data.press;
                });
        }
        updateData();
        setInterval(updateData, 5000);
    </script>
</body>
</html>
)=====";
#endif