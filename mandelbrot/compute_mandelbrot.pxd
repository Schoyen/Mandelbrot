cdef extern from "mandelbrot.h":
    void compute_mandelbrot(
        double x_min, double x_max, double y_min, double y_max,
        unsigned int num_x, unsigned int num_y, unsigned int max_escape_time,
        double divergence_criteria, int *divergence_steps);
