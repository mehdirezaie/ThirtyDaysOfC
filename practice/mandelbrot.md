# Mandelbrot 
This note demonstrates how we can compile a code written in C for Python. The example is based on the IPython Interactive Computing and Visualization Cookbook, Second Edition (2018), by [Cyrille Rossant](https://ipython-books.github.io/54-wrapping-a-c-library-in-python-with-ctypes/)

* Step 1: have a C function. In this example, we cover Mandelbrot, the C code, [mandelbrot.c](https://github.com/mehdirezaie/ThirtyDaysOfC/blob/master/mandelbrot.c), is:

```C
#include "stdio.h"
#include "stdlib.h"

// function declaration
void mandelbrot(int size, int iterations, int *col);

void mandelbrot(int size, int iterations, int *col)
{
    // Variable declarations.
    int i, j, n, index;
    double cx, cy;
    double z0, z1, z0_tmp, z0_2, z1_2;

    // Loop within the grid.
    for (i = 0; i < size; i++)
    {
        cy = -1.5 + (double)i / size * 3;
        for (j = 0; j < size; j++)
        {
            // We initialize the loop of the system.
            cx = -2.0 + (double)j / size * 3;
            index = i * size + j;
            // Let's run the system.
            z0 = 0.0;
            z1 = 0.0;
            for (n = 0; n < iterations; n++)
            {
                z0_2 = z0 * z0;
                z1_2 = z1 * z1;
                if (z0_2 + z1_2 <= 100)
                {
                    // Update the system.
                    z0_tmp = z0_2 - z1_2 + cx;
                    z1 = 2 * z0 * z1 + cy;
                    z0 = z0_tmp;
                    col[index] = n;
                }
                else
                {
                    break;
                }
            }
        }
    }
}
```

* Step 2: compile the C code into a shared library with 
`$> gcc -shared -Wl,-soname,mandelbrot -o mandelbrot.so -fPIC mandelbrot.c`

* Step 3: write a wrapper object, MandelBrot defined in [Mandelbrot.py](https://github.com/mehdirezaie/ThirtyDaysOfC/blob/master/Mandelbrot.py) to access the library inside Python with Ctypes:
```Python
import ctypes
import numpy as np
from numpy.ctypeslib import ndpointer

class MandelBrot:
    
    def __init__(self):
        
        # path to the shared library
        self.lib = ctypes.CDLL(r'/home/medirz90/Downloads/github/ThirtyDaysOfC/mandelbrot.so')
        
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
```

* Step 4: Finally, you can import the MandelBrot object in Python with `>>> from Mandelbrot import MandelBrot`. You can run the following example, [test_mandelbrot.py](https://github.com/mehdirezaie/ThirtyDaysOfC/blob/master/test_mandelbrot.py) with `$> python test_mandelbrot.py`:

```Python
import numpy as np
import matplotlib.pyplot as plt

from time import time
from Mandelbrot import MandelBrot

def test():
    t0 = time()

    size = 400
    iterations = 100

    # call C
    MB = MandelBrot()
    col = MB(size, iterations)

    print('done in {:.2f} sec'.format(time()-t0))

    # plot
    fig, ax = plt.subplots(1, 1, figsize=(10, 10))
    ax.imshow(np.log(col), cmap=plt.cm.hot)
    ax.set_axis_off()
    plt.savefig('mandelbrot.png')
    
    return 0

if __name__ == '__main__':
    test()

```
Then, you will get the mandelbrot.png: 

<img src="https://github.com/mehdirezaie/ThirtyDaysOfC/blob/master/practice/mandelbrot.png" width=60%>
