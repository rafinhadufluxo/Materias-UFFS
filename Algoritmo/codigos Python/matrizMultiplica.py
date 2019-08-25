#############################
#matriz de multiplicação
'''matriz = []
n = int(input())
for i in range(4):
    linha = []
    print("LINHA {}". format(i +1))
    for j in range(3):
        x = int(input("INFORME UM NUMERO: "))
        linha.append(x)
    matriz.append(linha)

for i in range (4):
    for j in range(3):
        matriz [i][j] = matriz [i][j] * 2

#Imprime a matriz
for i in range(4):
	for j in range(3):
		print("{}". format(matriz[i][j]),end=' ')
    print()'''
##########################################
def mat():
    matriz = []
    for i in range(4):
        linha = []
        print("linha {}". format(i + 1))
        for j in range(3):
            x = int(input())
            linha.append(x)
        matriz.append(linha)
    return matriz

def imprimir_matriz(xxx):
    for l in xxx:
        for j in l:
            print(j,end=" ")
        print()
            
matriz = mat()

for i in range(4):
    for j in range(3):
        matriz[i][j] = matriz[i][j] * 2

imprimir_matriz(matriz)

#######################################
'''class dado():
    nome = ''
    idade = 0
    salario = 0.0
def fun(n):
    p = dado ()
    p.nome = input("informe o nome: ")
    p.idade = int(input("informe a idade: "))
    p.salario = float(input("Informe o salario: "))
    print()
    return p

def med(funcionario,n):
    media = 0
    soma = 0
    for i in funcionario:
        soma += i.salario
        media = soma/n
        return media

def imprimi(funcionario,media):
    for i in funcionario:
        if i.salario > media:
            print("NOME:", i.nome)
            print("IDADE: ", i.idade)
            print("SALARIO: ", i.salario)
            print("\n")

n = int(input("Informe a quantidade de funcionario:" ))
funcionario = []
for c in range(n):
    funcionario.append(fun(n))

media = med(funcionario,n)
imprimi(funcionario,media)'''
###############################
#primos gemeos
valor = -10
a = int(input())
b = int(input())
for num in range(a,b+1):
  primo = True
  for div in range(2,num):
    if num %div == 0:
      primo = False
      break
  if primo:
    if (num - valor == 2):
      print(valor,num)
    valor = num
###############################
7 de novembro de 2018
'''def cal_media(valor1,valor2):
  return ((valor1 +valor2)/2)

for i in range(2):
  nome = input()
  nota1 = float(input())
  nota2 = float(input())
  print(nome, "media", cal_media(nota1,nota2))'''

