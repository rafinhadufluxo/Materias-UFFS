# biblioteca sympy
from sympy import *

var = symbols('var')
x = float(input("Velocidade da Barca: "))
y = float(input("Velocidade do Carro: "))

if y > x:

    t = (sqrt(40 ** 2 + (100 - var) ** 2) / x) + var / y
    t_derivate = diff(t,var)
    
    zerot_derivate = solve(t_derivate)
    distance_city_station = 100 - zerot_derivate[0]
    total_distance = ((((distance_city_station - 100) * -1) - 100)**2) + (40**2) 
    print("Distância da estação até a cidade: %.2fkm" % ((distance_city_station - 100) * -1))
    print("Distância total da ilha até a cidade mais curta: %.2fkm" % (sqrt(total_distance) + ((distance_city_station - 100) * -1)))
else:
    print("Entrada inválida (x>=y)")
