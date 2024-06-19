# - - - - - - - - - - - -  File imports  - - - - - - - - - - - - #

from Config import *
from Sensor import Sensor

# - - - - - - - - - - - -  File imports  - - - - - - - - - - - - #

class DataManager():
    def __init__(self, window):
        self.sensor_count = 0
        self.sensors = []
        self.window = window
    
    def update(self, api_data, sensor_data):
        self.api_data = api_data
        self.sensor_data = sensor_data
        
        self._update_api()
        self._update_sensors()

        self._draw()
        
    def _update_api(self):
        pass

    def _update_sensors(self):
        sensor_data_len = len(self.sensor_data)

        # Loop through each entry in the sensor_data
        for i in range(sensor_data_len):
            # Extract the sensor ID from the current sensor data
            sensor_id = self.sensor_data[i]['id']
            
            # Check if the sensor ID is already in the self.sensors list
            sensor_exists = any(sensor.sensor_id == sensor_id for sensor in self.sensors)
            
            # If the sensor is not in the list, add it to the list
            if not sensor_exists:
                self.sensors.append(Sensor(self.window, sensor_id))
                  
        # update all the sensors we have data for
        for data in self.sensor_data:
            sensor_id = data['id']

            for sensor in self.sensors:
                if sensor.sensor_id == sensor_id:
                    sensor.update(data)
                    break

    def _draw_api(self):
        pass
        
    def _draw(self):
        for sensor in self.sensors:
            sensor.draw()
        
        self._draw_api()

