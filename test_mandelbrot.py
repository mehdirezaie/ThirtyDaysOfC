
"""
    Example of MandelBrot testing

"""
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
