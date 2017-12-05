import numpy as np
cimport numpy as np

def get_mandelbrot_set(double x_min, double x_max, double y_min, double y_max,
        unsigned int num_x, unsigned int num_y, unsigned int max_escape_time,
        double divergence_criteria):

    cdef np.ndarray[int, ndim=2, mode="c"] divergence_steps
    divergence_steps = np.zeros((num_x, num_y), dtype=np.int32)

    compute_mandelbrot(x_min, x_max, y_min, y_max, num_x, num_y,
        max_escape_time, divergence_criteria, &divergence_steps[0, 0])

    return divergence_steps
