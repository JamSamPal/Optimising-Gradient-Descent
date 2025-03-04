import numpy as np


def dump_to_file(coordinates, filename):
    coordinates.astype(np.float32).tofile(f"{filename}.bin")


def generate_lines(num_lines, num_points):
    x_coords = np.random.uniform(0,10, num_lines*num_points)
    y_coords = np.zeros(num_lines*num_points, dtype=np.float32)

    line_gradients = np.random.uniform(0,10, num_lines)
    line_offsets = np.random.uniform(0,10, num_lines)

    for i in range(num_lines):
        for j in range(num_points):
            y_coords[num_points*i + j] = line_gradients[i]*x_coords[num_points*i + j] + line_offsets[i]
            
    return x_coords, y_coords



def main():
    """
    Generate data for gd test.
    A series of lines of varying gradients.
    We will test to see how accurate we can get in a real-time gd
    """

    x_coords, y_coords = generate_lines(100, 1000)

    dump_to_file(x_coords, "x")
    dump_to_file(y_coords, "y")


if __name__ == "__main__":
    main()
