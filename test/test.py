import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from pathlib import Path

grad_path = Path(__file__).parent.parent / "src/gradients.bin"
intercept_path = Path(__file__).parent.parent / "src/intercepts.bin"
save_path = Path(__file__).parent.parent / "animation.gif"
gradient = np.fromfile(grad_path, dtype=np.float32)
intercept = np.fromfile(intercept_path, dtype=np.float32)
print(gradient[:10], intercept[:10])
x = np.arange(10)

def animate(i):
    plt.cla()
    plt.plot(x, gradient[i]*x + intercept[i])


if __name__ == "__main__":
    fig, ax = plt.subplots()  # Create a figure and axis object
    ani = FuncAnimation(fig, animate, frames=100, interval=20)
    ani.save(save_path)
