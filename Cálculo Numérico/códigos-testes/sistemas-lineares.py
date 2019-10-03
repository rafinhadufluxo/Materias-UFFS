#   Jacobi and Gauss-seidel methods

import numpy as np
from numpy import linalg as LA

TOL = 10 ** -2

#Calculates error as norm of xk-xi to infinity divided by norm of xk to infinity
def relative_error(xk, xi):
    return (LA.norm(xk - xi, np.inf) / LA.norm(xk, np.inf))

# Does Gauss-Seidel algorithm in matricial form
# It is x^k+1 = (L+D)^-1 x (b - U*x^k)
# Where D is diagonal matrix
# L is the lower triangle matrix
# U is the upper triangle matrix
# b is the independent term
# A is the coefficient matrix
# x is the vector for unkown terms
# k is the iteration
def gauss_seidel_matricial(A, xi, b, epsilon):
    L = np.tril(A, -1)
    D = np.diag(np.diag(A))
    U = np.triu(A, 1)
    
    
    xk = np.dot(LA.inv(L + D), (b - np.dot(U, xi)))
    
    halt_condition = LA.norm(xk - xi)
    Er = relative_error(xk, xi)
    
    i = 0
    while Er > epsilon:
        xk = np.dot(LA.inv(L + D), (b - np.dot(U, xi)))

        if i == 1000:
            break
        i = i + 1
        Er = relative_error(xk, xi)
        xi = xk
    return xk

# Does Jacobi with the matricial form
#It is x^k+1 = D^-1 * (b - M*x^k) where 
# A is the  coefficient matrix
# D is  the diagonal matrix
# M is the  A - D
# b is the vector of independent terms
# x is the vector of unknown terms
# k is the number of iteration
def jacobi_matricial(A, xi, b, epsilon):
    D = np.diag(np.diag(A))
    M = A - D

    xk = np.dot(LA.inv(D), (b - np.dot(M, xi)))

    Er = relative_error(xk, xi)
    i = 0
    while Er > epsilon:
        xk = np.dot(LA.inv(D), (b - np.dot(M, xi)))
        if i == 1000:
            break
        Er = relative_error(xk, xi)
        xi = xk
        i = i+1

    return xk    

A = np.array([[3, 1], [2, 2]])
xi = np.array([0, 0])
b = np.array([4, 2])

xgs = gauss_seidel_matricial(A, xi, b, TOL)
print(xgs)

print("\n")

xj = jacobi_matricial(A, xi, b, TOL)
print(xj)
