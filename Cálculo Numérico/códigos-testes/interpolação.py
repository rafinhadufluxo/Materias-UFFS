import numpy as np

# Linear Interpolation
# Let x0, x1, y0 and y1 the values of an f(x)
# The linear polynom is given by the formula:
# P(x) = yo + [(y1 - y0)/(x1 - x0)] * (x - x0)
def linear_interpolation(x0, x1, y0, y1, x):
    px = y0 + (((y1 -y0)/(x1 -x0)) * (x - x0))
    return px

# Lagrange Interpolation
# Let m be the cardinal of known points, x the vector of given
# horizontal axis and y the vector of given vertical axis
# and z the value of the point to be interpolated
# Let G be the matrix of differences
# G.diag = prod(x - xi) where i is the all the x vector
# G.linei = prod(xj - xi) where j != i
# The Lagrange formula is given by the
# P(x)->m = G.diag * summation(i = 0 -> m, yi/Glinei)
def lagrange_interpolation(m, x, y, z):
    r = 0
    for i in range(m):
        c = 1
        d = 1
        
        for j in range(m):
            if i != j:
                c = c *(z - x[j])
                d = d *(x[i] - x[j])

        r = r + y[i] * c/d

    return r

# Newton divided diff interpolation
# Let m be the cardinal known points, x the vector of
# given horizontal axis and y the vector of given vertical axis
# and z the value of point to be interpolated
# Let dely[m, i] the vector of the differences calculated
# by the i iterator
# Formula is:
# Pn(x) = y0 + summation[i=1 -> n, del[i]y0] * prod[j=0 -> i-1, (x - xj)]
def newton_interpolation(m, x, y, z):
    dely = np.zeros(m)
    for i in range(m):
        dely[i] = y[i]

    # Constructions of the divided differences
    k = 1
    while k < m-1:
        j = m
        while j < k + 1:
            dely[i] = (dely[i] - dely[i-1])/(x[i] - x[i-k])
            j = j - 1
        k = k + 1
    # Horner's Rule
    r = dely[m-1]
    i = m - 1
    while i > 1:
        r = r * (z - x[i]) + dely[i]
        i = i - 1

    return r

# Newton gregory interpolation
# Let m be the cardinal known points, x the vector of
# given horizontal axis and y the vector of given vertical axis
# and z the value of point to be interpolated
# Let dely[m, i] the vector of the (finites)differences calculated
# by the i iterator
# Formula is:
# Pn(x) = y0 + summation[i=1 -> n, del[i]y0] * prod[j=0 -> i-1, (x - xj)]
def gregory_newton_interpolation(m, x, y, z):
    dely = np.zeros(m)
    for i in range(m):
        dely[i] = y[i]

    # Constructions of the finite differences
    k = 1
    while k < m-1:
        j = m
        while j < k + 1:
            dely[i] = (dely[i] - dely[i-1])
            j = j - 1
        k = k + 1
    
    # Horner's Rule
    u = (z - x[1])/(x[2] -x[1])
    r = dely[m-1]

    i = m - 1
    while i > 1:
        r = r * (u - i + 1)/i + dely[i]
        i = i - 1
    return r
