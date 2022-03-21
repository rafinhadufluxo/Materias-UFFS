from sympy import *

var = symbols('var')
x = float(input("Velocidade da Barca: "))
y = float(input("Velocidade do Carro: "))

if y > x:

    t = (sqrt(40 ** 2 + (100 - var) ** 2) / x) + var / y
    t_derivate = diff(t, var)
    zerot_derivate = solve(t_derivate)
    # distancia da estação até a cidade
    distance_city_station = 100 - zerot_derivate[0]
    # distãncia total
    total_distance = sqrt(
        zerot_derivate[0] ** 2 + 40 ** 2) + distance_city_station
    print("Distância da estação até a cidade: %.2fkm" %
          (distance_city_station))
    print("Distância total da ilha até a cidade mais curta: %.2fkm" %
          (total_distance))
else:
    print("Entrada inválida (x>=y)")
