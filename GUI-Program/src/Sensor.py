# - - - - - - - - - - - -  Library imports  - - - - - - - - - - - - #

from tkinter import *

# - - - - - - - - - - - -  Library imports  - - - - - - - - - - - - #


# - - - - - - - - - - - -  File imports  - - - - - - - - - - - - #

from Config import *
from DataPlotter import DataPlotter

# - - - - - - - - - - - -  File imports  - - - - - - - - - - - - #

class Sensor():
    def __init__(self, window, sensor_id):
        self.sensor_id = sensor_id
        self.sensor_data = None
        self.window = window
        self.frame = Frame(window)
        self.frame.configure(bg=GRAPH_BACKGROUND_COLOR)
        self.plotters = [
            DataPlotter(self.frame, self.sensor_id, 'Temperature', '°C', 0),
            DataPlotter(self.frame, self.sensor_id, 'Humidity', '%', 1)                   
        ]
    
    def update(self, sensor_data):
        self.sensor_data = sensor_data
        
        if (self.sensor_data == []):
            return
        
        new_temperature = float(self.sensor_data['temperatureC'])
        new_humidity = float(self.sensor_data['humidity'])
        
        self.plotters[0].update(new_temperature)
        self.plotters[1].update(new_humidity)
    
        
    def draw(self):
        self.plotters[0].draw()
        self.plotters[1].draw()
        
        self.frame.pack()

