#----------------------------------------------------#
#       Calculadora de Área Integrais Python
#           Autor: Erickson G. Müller
#           Data: 23-09-2024
#           Trabalho Aplicado Cálculo II
#----------------------------------------------------#           

import sympy

def somaRiemann(funcao, a, b, n):#Função 
    #---Declaração---#
    x = sympy.Symbol('x')#Atribui x à classe Symbol
    f = sympy.sympify(funcao)#"Traduz" o input função para linguagem matematica do sympy 
    #----------------#

    #----Cálculo-----#
    delta_x = (b - a) / n #Largura dos retângulos
    area = 0
    for i in range(n): #Loop que vai somando as áreas dos retângulos
        x_i = a + i * delta_x + delta_x / 2 #Ponto médio dos retângulos
        altura = f.subs(x, x_i)
        area += altura * delta_x #Área do retângulo da iteração (Base.Altura)
    #----------------#
    return area

#---MAIN---#

###Inputs
funcao = input("escreva a função f(x): ")
a = int(input("Insira o valor de a: ")) # Limite inferior
b = int(input("Insira o valor de b: ")) # Limite Superior
n = int(input("insira o valor de n: "))  # Número de retângulos (subintervalos)

#----Cálculo----#
aprox_area = somaRiemann(funcao, a, b, n)

#Resposta$
print("A área aproximada usando a Soma de Riemann é: {:.6f} unidades de área".format(aprox_area))
