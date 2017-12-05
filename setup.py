from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

import numpy as np

sourcefiles = [
    "mandelbrot/compute_mandelbrot.pyx",
    "src/mandelbrot.c"
]

include_dirs = [
    np.get_include(),
    "include",
    "."
]

extensions = [
    Extension(
        name="compute_mandelbrot",
        sources=sourcefiles,
        include_dirs=include_dirs
    )
]

setup(
    name="Mandelbrot",
    version="0.1",
    description="Compute the Mandelbrot set",
    ext_modules=cythonize(extensions)
)
