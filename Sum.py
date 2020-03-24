'''
import sum
d = [-10., 2., 3.]
print(sum.our_function(d))
'''


import ctypes

_sum  = ctypes.CDLL('libsum.so')
_sum.our_function.argtypes = (ctypes.c_int, 
                              ctypes.POINTER(ctypes.c_longdouble))
_sum.our_function.restype = ctypes.c_longdouble

def our_function(numbers):
    global _sum
    num_numbers = len(numbers)
    array_type = ctypes.c_longdouble * num_numbers
    result = _sum.our_function(ctypes.c_int(num_numbers), 
                               array_type(*numbers))
    return float(result)

