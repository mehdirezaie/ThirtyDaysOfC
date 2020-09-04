'''
    Example of Mandelbrot
    written C wrapped for Python

    Step 1: compile C
    $> gcc -shared -Wl,-soname,mandelbrot -o mandelbrot.so -fPIC mandelbrot.c

    Step 2: Use the Object MandelBrot in this file to use

    example
    ---------
    $> MB = MandelBrot()
    $> result = MB(size, iterations)

'''
import ctypes
import numpy as np
from numpy.ctypeslib import ndpointer



class MandelBrot:
    
    def __init__(self):
        
        # path to the shared library
        #self.lib = ctypes.CDLL(r'/home/medirz90/Downloads/github/ThirtyDaysOfC/mandelbrot.so')
        self.lib = ctypes.CDLL(r'/Users/mehdi/github/ThirtyDaysOfC/mandelbrot.so')

        self.lib.mandelbrot.restype = None
        self.lib.mandelbrot.argtypes = (ctypes.c_int, 
                                   ctypes.c_int,
                                   ndpointer(ctypes.c_int))
    
    def __call__(self, size, iterations):
        
        # placeholder for the output
        col = np.empty((size, size), dtype=np.int32)
        
        self.lib.mandelbrot(ctypes.c_int(size),
                            ctypes.c_int(iterations),
                            col)
        return col
