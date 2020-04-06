'''
    Compute Pi with a C function in Python

    1. First, compile a shared library
        $> gcc -shared -o pi.so -fPIC pi.c

    2. Then, execute this script with
        $> python Pi.py
'''
import ctypes
import numpy as np


def pypi(npoints):
    ''' Python implementation of Pi calculator
    '''
    step = 1.0/npoints
    sum = 0

    for i in range(npoints):
        x = (i+0.5)*step
        sum = sum + 4.0/(1.0+x*x)

    return sum * step


class Pi:

    def __init__(self):
        self.lib = ctypes.CDLL(r'/Users/mehdi/github/ThirtyDaysOfC/pi.so')
        self.lib.pi.restype = ctypes.c_float
        self.lib.pi.argtypes = (ctypes.c_int, ) #_argtypes_ must be a sequence of types

    def __call__(self, npoints):
        return self.lib.pi(ctypes.c_int(npoints))


if __name__ == '__main__':
    from time import time

    # initialize the C Object
    pi = Pi()

    times = {'C':[],
            'Python':[]}

    np_grid = np.logspace(1, 7)
    for np_float in np_grid:

        npoints = int(np_float)

        t0 = time()
        pi_c = pi(npoints)
        t1 = time()
        pi_py = pypi(npoints)
        t2 = time()

        print((abs(pi_c - np.pi) < 1.0e6), (abs(pi_c - pi_py) < 1.0e6))

        #print('Pi (C) = %f in %f secs'%(pi_c, t1-t0))
        #print('Pi (Python) = %f in %f secs'%(pi_py, t2-t1))
        #print('C implmentation is %.1f times faster than Python'%((t2-t1)/(t1-t0)))

        times['C'].append(t1-t0)
        times['Python'].append(t2-t1)

    import matplotlib
    matplotlib.use('TKAgg')
    import matplotlib.pyplot as plt

    plt.figure()
    for language in ['C', 'Python']:
        plt.plot(np_grid, times[language], marker='o', label=language)

    plt.xscale('log')
    plt.yscale('log')
    plt.grid(ls=':', color='grey', alpha=0.5)

    plt.tick_params(direction='in', right=True,
                    top=True, which='both', axis='both')

    plt.xlabel('Nsteps', fontsize=14)
    plt.ylabel('time [sec]', fontsize=14)

    plt.legend(fontsize=14)
    #plt.show()
    plt.savefig('pi_c_vs_python.png',
                dpi=300, bbox_inches='tight')
