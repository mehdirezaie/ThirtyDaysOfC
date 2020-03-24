

from numpy.ctypeslib import ndpointer
import ctypes



lib = ctypes.CDLL('mandelbrot.so')
lib.mandelbrot.restype = None
lib.mandelbrot.argtypes = (ctypes.c_int, 
                           ctypes.c_int,
                           ndpointer(ctypes.c_int))


#def mandelbrot():
#    lib = ctypes.CDLL('mandelbrot.so')
#    lib.mandelbrot.restype = None
#    lib.mandelbrot.argtypes = (ctypes.c_int, 
#                               ctypes.c_int,
#                               ndpointer(ctypes.c_int))
#
#    mandelbrot = lib.mandelbrot
#    return mandelbrot

def mandelbrot(size, iterations):
    global lib
    import  numpy as np
    col = np.empty((size, size), dtype=np.int32)
    #array_type = ctypes.c_int * size
    lib.mandelbrot(ctypes.c_int(size),
                   ctypes.c_int(iterations),
                   col)
    return col

