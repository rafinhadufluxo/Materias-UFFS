import numpy as np
from numpy import linalg
import numpy.polynomial.polynomial as poly
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Normal equation to curve fitting
def beta(A, f):
    # Normal equation a=(A^t*A)^-1 *(A^t) * f
    return ((np.linalg.inv((A.transpose()).dot(A))).dot(A.transpose())).dot(f)

def threshold(c, c_eval):
    return np.subtract(c, c_eval)

# Calculates R^2 for n points
def determination(c, c_eval, n):
    thsq = threshold(c, c_eval) ** 2
    sigmaup = thsq.sum()
    sigmalow = (c**2).sum() - (c.sum()/n)
    return 1 - sigmaup/sigmalow




# Example on linear linear curve fitting
#xi = np.array([1, 1.5, 2])
#yi = np.array([1.2, 1.3, 2.3])
# Important step: You need to create a matrix of x values,
#                  for a first degreee polynomial is a two column
#                  Vandermond matrix
# Creates a matrix of A = [1, x1]
#                         [1, x2]
#                         ...
#                         [1, xn]
#A = np.array([xi**1, xi**0]).transpose()

#a = beta(A, yi)
#x = np.linspace(0.5, 2.5)
#y_eval = np.polyval(a, xi)
#print(a)
#print(threshold(yi, y_eval))
#print(determination(yi, y_eval, 3))
#plt.plot(xi, yi, 'ro', x, np.polyval(a, x), 'b-')
#plt.grid()
#plt.show()

# Example on 3d polynomial equation

xi = np.array([0.56, 1, 2])
yi = np.array([0.5, 1, 2])
zi = np.array([1, 2, 4])

A = np.array([xi ** 2, yi**2]).transpose()
a = beta(A, zi)

def f(x, y, a):
    return a[0]*x**2 + a[1]*y**2

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(xi, yi, zi)
xx = np.linspace(0.5, 2)
yy = np.linspace(0.5, 2)
xx, yy = np.meshgrid(xx, yy)
zz = f(xx, yy, a)
ax.plot_surface(xx, yy, zz)
plt.show()
