# aula de 28 de novembro de 2018(UFFS SALA)
1 -Faça um programa que leia números inteiros para uma  matriz 4x4. Em seguida, calcule a média dos 
elementos dessa matriz.

'''mat = []
soma = som = 0
for i in range(4):
    print("LINHA {}". format(i +1))
    linha = []
    for j in range(4):
        x = int(input())
        som += 1
        soma += x
        linha.append(x)
    mat.append(linha)

for i in range(4):
    for j in range(4):
        print(mat[i][j],end=' ')
    print()
print("\n")
print("A media é: {}". format(soma/som))'''
###################################################################################################################

2 -Faça um programa igual ao anterior, porém escreva  os elementos da diagonal principal e em seguida, 
imprima a soma deles.

'''mat = []
soma = som = 0
for i in range(4):
    print("LINHA {}". format(i +1))
    linha = []
    for j in range(4):
        x = int(input())
        linha.append(x)
    mat.append(linha)

for i in range(4):
    for j in range(4):
        print(mat[i][j],end=' ')
    print()

soma = 0
for i in range(4):
    for j in range(4):
        if i == j:
            soma += mat [i][j]
print("A soma da diagonal: ", soma)'''
#######################################################################################################################

3- Faça um programa que leia valores e preencha uma  matriz 3x3 com valores inteiros entre 0 e 10, inclusive 
(notas de alunos) e indique:
          ○Quantas vezes a nota 9 aparece na matriz.
          ○ Quantas vezes aparece cada nota?
###################################################################################################################
4 -Faça um programa que receba uma matriz 5x5 e calcule a média dos elementos abaixo da diagonal  principal

mat = []
soma = som = 0
for i in range(5):
    print("LINHA {}". format(i +1))
    linha = []
    for j in range(5):
        x = int(input())
        linha.append(x)
    mat.append(linha)

for i in range(5):
    for j in range(5):
        print(mat[i][j],end=' ')
    print()

soma = 0
for i in range(5):
    for j in range(5):
        if i == j:
            soma += mat [i][j]
            
print("A media da diagonal: {} ". format(soma/len(mat)))
###############################################################################################################
5- Faça um algoritmo que calcule a média dos elementos  da diagonal secundária de uma matriz 10 X 10 de 
números.

mat = []
soma = som = 0
for i in range(5):
    print("LINHA {}". format(i +1))
    linha = []
    for j in range(5):
        x = int(input())
        linha.append(x)
    mat.append(linha)

for i in range(5):
    for j in range(5):
        print(mat[i][j],end=' ')
    print()

somaDiagonalSec = 0
for i in range(5):
    for j in range(5):
        if i+j == N-1:
			somaDiagonalSec += matriz[i][j]
print("A soma da diagonal: {} ". format(soma/len(mat)))
########################################################################################################################
6 - Faça um algoritmo que leia uma matriz 20x20 de  números e some cada uma das linhas, armazenando o  resultado da soma 
em um vetor. A seguir, multiplique  cada elemento pela soma da sua linha. Mostre a matriz  resultante.
########################################################################################################################
#coisas PC 2018, segue baixo
n = int(input("Digite a ordem: "))
for i in range(n+1):
    espaco = n - i
    j = i
    print(" " * espaco + " {}".format(j) * i)  
#############################################################
'''maior = -99999
#cont = 0
for i in range(10):
    x = int(input())
    if x == maior:
        cont += 1
    if x > maior:
        maior = x
        cont = 1

print("{} é o numero maior". format(maior))

###########################################################

'''n = int(input())#usuario digita
soma = 0
for i in range(1,n):
    if n%i == 0:
        soma +=i
if soma == n:
    print("{} eh perfeito". format(n))
else:
    print("{} nao eh perfeito". format(n))

############################################################
N = int(input())

for z in range(N):
    x = int(input())
    soma = 0
    for i in range(1,x):
        if x%i == 0:        
            soma += i
    if soma == x:
        print ("{} eh perfeito". format(x))
    else:
        print ("{} nao eh perfeito". format(x))


##########################################################
x = int(input())#numeros primos
soma = 0
for i in range(2,x):
  if x%i == 0:
    soma += 1
if soma > 1:
  print("NAO PRIMO")
else:
  print("PRIMO")
##########################################################
mini = 0  #teste de mesa
maxi = 4
while mini < maxi:
  mini += 1
  s = mini + maxi
  s -= 1
  j = 3
  while j > 0:
    if s <= 7:
      break
    s += 1
    j = j - 1
  if s % 2 == 1:
    print (s)
###########################################################
n = int(input())
for i in range(n+1):
  espaco = n - i
  
  print(" " * espaco + "{} ". format(i)*i)
#########################################################

n=int(input())
num2 = n
resto = 0
fatorial = 0



while(n>0):
  resto=n%10
  i=1
  fact = 1
  while(i<=resto):
    fact*=i
    i+=1
  
  fatorial += fact  
  n//=10
print(fatorial)
print(num2)  
if(num2==fatorial):
  print("é um numero forte")
else:
  print("não é um numero forte")
######################################################
i = 5 #teste de mesa
def p1(x):
    global i
    x = x + i
    print(x)
def p2(x):
    x = x *2
    print(x)

a = 10
b = 5
p1(a)
p2(b)
print(a,i)

###################################################################
tri = int(input()) 
count = 1

while (count <= tri):
    print((tri- count) * " ", end = "")

    line = 1
    while (line <= count):
        print(line, end = "")
        line += 1

    line = count
    while (line > 1):
        print(line - 1, end = "")
        line -= 1

    
    count+= 1
    print()
#################################################################



