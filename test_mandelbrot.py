import numpy as np
from Mandelbrot import mandelbrot


size = 400
iterations = 100
col = mandelbrot(size, iterations)


import matplotlib.pyplot as plt

fig, ax = plt.subplots(1, 1, figsize=(10, 10))
ax.imshow(np.log(col), cmap=plt.cm.hot)
ax.set_axis_off()

plt.savefig('mandelbrot.png')
