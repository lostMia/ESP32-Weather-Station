
# - - - - - - - - - - - -  Library imports  - - - - - - - - - - - - #

from tkinter import *
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg     

# - - - - - - - - - - - -  Library imports  - - - - - - - - - - - - #


# - - - - - - - - - - - -  File imports  - - - - - - - - - - - - #

from Config import *

# - - - - - - - - - - - -  File imports  - - - - - - - - - - - - #


class DataPlotter():
    box_style = dict(facecolor=FRAME_BACKGROUND_COLOR, pad=8, alpha=0.8) 

    def __init__(self, root, sensor_id, name, unit, col):
        self.usage_list = []
        self.x_values = [ 30 ]

        self.sensor_id = sensor_id
        self.measurement_name = name
        self.measurement_unit = unit
        self.col = col
        self.frame = Frame(root)
        self.frame.configure(bg=FRAME_BACKGROUND_COLOR)

        self.figure = Figure(figsize=(5, 3), dpi=70)
        self.figure.patch.set_facecolor(WINDOW_BACKGROUND_COLOR)
        self.plot = self.figure.add_subplot(1, 1, 1)
        self.plot.tick_params(axis=BOTH, colors='#FFFFFF')  
        self.canvas = FigureCanvasTkAgg(self.figure, master=self.frame)
        self.widget = self.canvas.get_tk_widget()

        self.title_label = Label(self.frame, text=f'{self.measurement_name} from Sensor {self.sensor_id}', font=('Arial', 12, 'bold'), bg=WINDOW_BACKGROUND_COLOR, fg='#FFFFFF', padx=20)
        self.title_label.place(anchor=NW, x=10, y=10)

        self.widget.pack(side=TOP, padx=10, pady=35)
        self.frame.grid(column=self.col, row=0, padx=20, pady=20)

    def update(self, new_value):
        if not self.usage_list:
            self.usage_list.append(new_value)
        elif len(self.usage_list) < MAX_HISTORY_LENGTH:
            self.usage_list.append(new_value)
            self.x_values.append(self.x_values[-1] - 1)
        else:
            self.usage_list.pop(0)
            self.usage_list.append(new_value)

    def draw(self):
        self.plot.cla()
        self.plot.plot(self.x_values, self.usage_list, 'o-', color=GRAPH_FOREGROUND_COLOR, linewidth=2)
        self.plot.axis([MAX_HISTORY_LENGTH, 1, min(self.usage_list) - 5, max(self.usage_list) + 5])
        self.plot.grid(color=GRID_COLOR, linestyle='--')
        self.plot.set_facecolor(GRAPH_BACKGROUND_COLOR)
        self.plot.set_axisbelow(True)
        self.plot.set_ylabel(f'{self.measurement_name} in {self.measurement_unit}', color='#FFFFFF', bbox=self.box_style, labelpad=-328)

        self.canvas.draw()
 