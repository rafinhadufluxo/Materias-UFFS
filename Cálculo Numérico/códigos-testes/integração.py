import numpy as np

#   Trapezoidal rule
#   Let 'f' be the function, 
#   'a' and 'b' be the upper and lower limits
#   'n' be the subinterval
#   returns the y aproximation
def comp_trapezoidal(f, a, b, n):
    h = (b-a)/n
    x = np.linspace(a,b,num=n+1)
    y = h*(f(x[0]) + f(x[n]))/2
    i = 1
    while i != n:
        y = y + h*f(x[i])
        i = i + 1
    return y

#   Simpson's 1/3 rule
#   Same parameters of the function Trapezoidal
def oneThird_simp(f, a, b, n):
    # Note: The subinterval value must be odd
    # so, maybe 2*n adjustment is needed to converge in entire algo
    h = (b-a)/n
    x = np.linspace(a, b, num=n+1)
    y = f(x[0])
    
    m = int(n/2)

    for i in range(0, m):
        j = 2*i+1
        y = y + 4*(f(x[j]))
    
    for i in range(1, m):
        j = 2*i
        y = y + 2*(f(x[j]))

    y = y + f(x[n])
    y = h*y/3

    return y

#   Simpson's 3/8 rule
#   same parameters of the function above
def threeOctave_simp(f, a, b, n):
    #Note: the subinterval must be n mod 3 = 0
    #so maybe 3*n adjustment is needed to converge in entire algo
    h = (b-a)/n
    x = np.linspace(a, b, num=n+1)
    y = f(x[0])

    for i in range(1, n):
        if(i % 3 == 0):
            y = y + 2*(f(x[i]))
        else:
            y = y + 3*(f(x[i]))

    y = y + (f(x[n]))
    y = h*y*3/8
    return y

def f(x):
    return x ** 3 + x + 1

n = np.array([6, 12, 24, 30])

a = 0
b = 2

for i in range(4):
    print("Number of subintervals: " + str(n[i]))
    print("Composite trapezoidal: " + str(comp_trapezoidal(f, a, b, n[i])))
    print("Composite 1/3 Simpson's Rule: " + str(oneThird_simp(f, a, b, n[i])))
    print("Composite 3/8 Simpson's Rule: " + str(threeOctave_simp(f, a, b, n[i])))
    print()
