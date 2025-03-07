import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from pathlib import Path

grad_path = Path(__file__).parent.parent / "src/gradients.csv"
intercept_path = Path(__file__).parent.parent / "src/intercepts.csv"
save_path = Path(__file__).parent.parent / "animation.gif"

gradient = pd.read_csv(str(grad_path), header=None)
intercept = pd.read_csv(str(intercept_path), header=None)

x = np.arange(10)
def animate(i):
    plt.cla()
    plt.plot(x, gradient.iloc[i][0]*x + intercept.iloc[i][0])


if __name__ == "__main__":
    fig, ax = plt.subplots()
    ani = FuncAnimation(fig, animate, frames=400, interval=500)
    ani.save(save_path)
