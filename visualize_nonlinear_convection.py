import numpy as np
import matplotlib.pyplot as plt
title = "1D Non-Linear Convection"
data = np.loadtxt(fname="input.dat",dtype=np.float64)
plt.plot(data[:,0],data[:,1],label="initial condition")

data = np.loadtxt(fname="output.dat",dtype=np.float64)
plt.plot(data[:,0],data[:,1],label="final condition")

plt.title(title)
plt.xlabel("space(x)")
plt.ylabel("magnitude(u)")
plt.legend()
plt.grid()


plt.show()

