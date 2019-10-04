# -*- coding: utf-8 -*-

vert = input()
 
A, B, C = vert.split()
 
x = float(A)
y = float(B)
z = float(C)
     
listen = [x, y, z]
listen.sort(reverse=True)
a = listen[0]
b = listen[1]
c = listen[2]
     
if a >= (b + c):
    print("NAO FORMA TRIANGULO")
elif (a**2) == (b**2+c**2):
    print("TRIANGULO RETANGULO")
elif (a**2) > (b**2)+(c**2): 
    print("TRIANGULO OBTUSANGULO")
elif (a**2) < (b**2)+(c**2):
    print("TRIANGULO ACUTANGULO")
 
 
if a == b and a == c and b == c:
    print("TRIANGULO EQUILATERO")
elif a == b or a == c:
    print("TRIANGULO ISOSCELES")
elif b == a or b == c:
    print("TRIANGULO ISOSCELES")
