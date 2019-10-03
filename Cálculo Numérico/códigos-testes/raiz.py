import numpy as np

TOL = (10 ** (-3))

def f(x):
    return (x ** 3) - 5

def df(x):
    return 2*(x ** 2)

#   Interval gathered with plot
a = 1.5
b = 2

#   Recursive Bissection
def bissection_root(f, a, b, epsilon):
    fa = f(a)
    fb = f(b)
    x = (a+b)/2
    fx = f(x)

    while (np.sqrt(f(x)**2)):
        if(fx * fa < 0):
            return bissection_root(f, a, x, epsilon, counter+1)
        else:
            return bissection_root(f, x, b, epsilon, counter+1)

# Basic Secant Method
def secant_method(f, a, b, epsilon):
    x = ((a * f(b)) - (b * f(a)))  / (f(b) - f(a))

    while ( np.sqrt(f(x) ** 2) > epsilon):
        if f(x) * f(a) > 0:
            a = x
        else:
            b = x
        x = ((a * f(b)) - (b * f(a)))  / (f(b) - f(a))
    return x

#   The correct x is needed to be given
def newton_method(f, d, x, epsilon):
    while (np.sqrt(f(x) ** 2) > epsilon):
        x = x - (f(x)/d(x))
    return x
