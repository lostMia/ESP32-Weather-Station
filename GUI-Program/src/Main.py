# - - - - - - - - - - - -  Library imports  - - - - - - - - - - - - #

from tkinter import *
from tkinter import ttk
import platform

# - - - - - - - - - - - -  Library imports  - - - - - - - - - - - - #


# - - - - - - - - - - - -  File imports  - - - - - - - - - - - - #

from Config import *
from DataManager import DataManager
from API import APIManager

# - - - - - - - - - - - -  File imports  - - - - - - - - - - - - #


class WeatherApp():
    def __init__(self):
        self.window = Tk()
        self.window.title(WINDOW_TITLE)
        self.window.geometry(WINDOW_SIZE)    
        self.window.configure(bg=WINDOW_BACKGROUND_COLOR)
        self.window.resizable(0, 0)

        if (platform.system() == "Windows"):
            self.window.iconbitmap(ICON_FILENAME)

        self.style = ttk.Style()
        self.set_styles()
        
        self.api = APIManager()
        self.data_manager = DataManager(self.window)

    def set_styles(self):
        self.style.theme_use('alt')
        self.style.configure("taskmgr.Horizontal.TProgressbar", foreground=GRAPH_FOREGROUND_COLOR, background=GRAPH_FOREGROUND_COLOR, troughcolor=WINDOW_BACKGROUND_COLOR, bordercolor='grey')
        self.style.configure("taskmgr.Treeview", foreground=WINDOW_BACKGROUND_COLOR, background=WINDOW_BACKGROUND_COLOR, fieldbackground=WINDOW_BACKGROUND_COLOR, font=('Arial', 10), rowheight=20)
        self.style.configure("taskmgr.Treeview.Heading", foreground='white', background=WINDOW_BACKGROUND_COLOR, font=('Arial', 11, 'bold'))
        self.style.configure("taskmgr.Entry", foreground='white', background=WINDOW_BACKGROUND_COLOR, font=('Arial', 11, 'bold'))

    def update(self):
        self.update_values()

        self.window.after(UPDATE_INTERVAL_SECONDS * 1000, self.update)

    def update_values(self):
        self.api.update()
        self.data_manager.update(self.api.api_data, self.api.sensor_data)

    def mainloop(self):
        self.update()
        self.window.mainloop()


if __name__ == '__main__':
    weather_app = WeatherApp()
    weather_app.mainloop()
