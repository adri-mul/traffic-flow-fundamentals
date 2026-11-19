import matplotlib.pyplot as plt
import argparse

parser = argparse.ArgumentParser(description="File names passed into script")
parser.add_argument(
    "files", 
    type=str, 
    nargs="*", 
    help="the argument must be a valid file path formatted as a string"
)

args = parser.parse_args()

# collected file arguments
files_to_plot: list[str] = args.files
print(f"recieved files: {files_to_plot}")

for file in files_to_plot:
    x_axis_header = "null header"
    y_axis_header = "null header"
    plot_points = []
    x_subplot = []
    with open(file) as fp:
        x_axis_header,y_axis_header = fp.readline().strip().split(",")
        lines = fp.readlines()
        plot_points = [float(data.strip().split(",")[1]) for data in lines]
        x_subplot = [float(data.strip().split(",")[0]) for data in lines]

    fig, axis = plt.subplots()
    axis.plot(x_subplot, plot_points)
    axis.set_xlim(100, 500)
    plt.ylabel(y_axis_header)
    plt.xlabel(x_axis_header)
    plt.show()