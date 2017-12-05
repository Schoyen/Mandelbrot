# Mandelbrot

This project demonstrates a simple setup combining Jupyter, Python, Cython and
C using calculation of the Mandelbrot set as an example.

## Installation
Currently we only use a "local installation" by compiling the source code into a
shared library which we output the directory `scripts/` along with the notebook.
To do this run:

```bash
python setup.py build_ext
```
