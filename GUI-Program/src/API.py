# - - - - - - - - - - - -  Library imports  - - - - - - - - - - - - #

import requests
import json

# - - - - - - - - - - - -  Library imports  - - - - - - - - - - - - #


# - - - - - - - - - - - -  File imports  - - - - - - - - - - - - #

from Config import *

# - - - - - - - - - - - -  File imports  - - - - - - - - - - - - #


class APIManager():
    def __init__(self):
        self.api_data = None
        self.sensor_data = None

    def _get_api_data(self):
        response = requests.get(REST_API_URL +  API_DATA_SUFFIX)

        if response.status_code == 200:
            return json.loads(response.text)
        else:
            print(f"Error: {response.status_code}")
            return None

    def _get_sensor_data(self):
        response = requests.get(REST_API_URL +  SENSOR_DATA_SUFFIX)

        if response.status_code == 200:
            return json.loads(response.text)
        else:
            print(f"Error: {response.status_code}")
    
    def update(self):
        # The use of the API values from the server was removed in favor of 
        # improving the sensor functionality.
        #self.api_data = self._get_api_data()
        self.sensor_data = self._get_sensor_data()