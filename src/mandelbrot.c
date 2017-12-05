#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "mandelbrot.h"

void compute_mandelbrot(double x_min, double x_max, double y_min, double y_max,
        unsigned int num_x, unsigned int num_y, unsigned int max_escape_time,
        double divergence_criteria, int *divergence_steps)
{
    double c_real, c_imag, z_real, z_imag, z_real_new, z_imag_new;
    unsigned int i, j, k;
    double dx, dy, divergence;

    dx = fabs(x_max - x_min)/(num_x - 1);
    dy = fabs(y_max - y_min)/(num_y - 1);

    divergence = divergence_criteria*divergence_criteria;


    for (j = 0; j < num_y; j++) {
        c_imag = y_min + j*dy;
        for (i = 0; i < num_x; i++) {
            c_real = x_min + i*dx;

            z_real = 0.0;
            z_imag = 0.0;
            z_real_new = 0.0;
            z_imag_new = 0.0;

            for (k = 1; k <= max_escape_time; k++) {
                z_real_new = z_real*z_real - z_imag*z_imag + c_real;
                z_imag_new = 2*z_real*z_imag + c_imag;

                z_real = z_real_new;
                z_imag = z_imag_new;

                if ((z_real*z_real + z_imag*z_imag) > divergence) {
                    break;
                }

                divergence_steps[i + j*num_x] = k;
            }
        }
    }
}
