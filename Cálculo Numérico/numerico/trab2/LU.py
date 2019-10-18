# coding=UTF-8

import sys, os, time
from fractions import Fraction

# valores iniciais do programa e da matriz
i = 0
j = 0
linhas = 0
colunas = 0
decimal = False
DENOMINADOR = 999999
matriz = []
vetor_b = [1, 2]
BOLD = "\033[1m"
ERROR = "\033[91m"
END = "\033[0m"
mensagemInicial = "Olá! Por favor, digite o nome do arquivo que contem a matriz de pontos a ser lida: "
mensagemErro = ERROR+"\nNão foi possível ler o arquivo!\n"+END
mensagemErroIvalida = ERROR+"O arquivo não contem uma matriz válida!\n"+END
mensagemErroNaoQuadrada = ERROR+"\nO número de linhas difere do número de colunas, \nmude seu arquivo da matriz e tente novamente!\n"+END

# método para imprimir uma matriz bonitinha
def imprime(matriz):

	align = "<"
	maximo = 0
	
	for i in range(len(matriz)):
		for j in range(len(matriz[i])):
			if len(str(matriz[i][j])) > maximo:
				maximo = len(str(matriz[i][j]))
	
	for i in range(len(matriz)):
		for j in range(len(matriz[i])):
			if decimal:
				print BOLD+'{0:{align}{width}}'.format(Fraction.from_float(matriz[i][j]).limit_denominator(DENOMINADOR), width=maximo, align=align)+END,
			else:
				print BOLD+'{0:{align}{width}}'.format(matriz[i][j], width=maximo, align=align)+END,
		print


def initMatriz(dim):
	m = []
	for i in range (0, dim):
		m.append([])
		for j in range(0, dim):
			m[i].append(0)
	return m


def termoM(matriz, l, c):
	m = matriz[l][c] / float(matriz[c][c])
	return m


def linhaMenosLinha(l1, fator, l2):
	tam = len(l1)
	for i in range(0,tam):
		l1[i] = l1[i] - fator*l2[i]
	return l1


def calcularLU(matrizA):
	dim = len(matrizA[0])
	tempA = matrizA[:]
	matrizL = initMatriz(linhas)

	for i in range(0,dim):
		matrizL[i][i] = 1

	for c in range(0,dim):
		for l in range(c+1, dim):
			tm = termoM(tempA, l, c)
			tempA[l] = linhaMenosLinha(tempA[l], tm, tempA[c])

			matrizL[l][c] = tm

	return (matrizL, tempA)


def calcularY(matriz, resolucaoY, vetor_b):

	for k in range(linhas):
		somatorio = 0.0
		for i in range(k):
			somatorio += matriz[k][i]*resolucaoY[i]
			
		resolucaoY.append( (vetor_b[k]-somatorio) / matriz[k][k] )


def calcularX(matriz, resolucaoX, resolucaoY):
	
	for k in range(linhas):
		somatorio = 0.0
		for i in range(k):
			somatorio += matriz[linhas-k-1][linhas-i-1]*resolucaoX[i]
		resolucaoX.append( (resolucaoY[linhas-k-1]-somatorio) / matriz[linhas-k-1][linhas-k-1] )
		
	resolucaoX.reverse()


######################
# Inicio de execução #
######################

# verifica e lê o arquivo da matriz
try:
	os.system('clear')
	file_name = str(raw_input(mensagemInicial))
	if file_name != "":
		file = open('./'+file_name, 'r')
	else:
		vetor_b = []
		file_name = "matrizHilbert.txt"
		file = open('./'+file_name, 'r')
	#Trasforma o arquivo lido em uma matriz 2D
	for linha in file:
		linha = linha.strip().split(' ')
		matriz.append([])
		matriz[i] = linha
		i += 1
		
	file.close()
	
except Exception:
	print mensagemErro + mensagemErroIvalida
	exit()


# conta o número de linhas e colunas e verifica se é quadrada
colunas = len(matriz)
for c in matriz[0]:
	linhas += 1

if linhas != colunas:
	print mensagemErro + mensagemErroNaoQuadrada
	exit()

# transforma os valores lidos de string para float
try:
	for i in range(linhas):
		soma = 0.0
		for j in range(colunas):
			matriz[i][j] = float(matriz[i][j])
			soma += matriz[i][j]
		if file_name == "matrizHilbert.txt":
			vetor_b.append(soma)
			
except Exception:
	print mensagemErro + mensagemErroIvalida
	exit()

print "Este programa leu a seguinte matriz do arquivo", file_name , ":"
imprime(matriz)

#inicio do cálculo da matriz LU
inicio = time.time()
res = calcularLU(matriz)

print "\nMatriz L:"
imprime(res[0])

print "\nMatriz U:"
imprime(res[1])

#calculo do vetor Y
resolucaoY = []
print "\nVetor y:"
calcularY(res[0], resolucaoY, vetor_b)
for i in resolucaoY:
	print BOLD+str(Fraction.from_float(i).limit_denominator(DENOMINADOR))+END,

#calculo do vetor X
resolucaoX = []
print "\n\nVetor x:"
calcularX(res[1], resolucaoX, resolucaoY)

#fim dos calculos
fim = time.time()

#imprime o resultado e um relatorio
maximo = 0.0
valor = 0.0
contador = 0
for i in resolucaoX:
	if abs(1-i)>=maximo:
		maximo = abs(1-i)
		valor = i
		posicao = contador
	contador += 1
	print BOLD+str(Fraction.from_float(i).limit_denominator(DENOMINADOR))+END,

print BOLD+"\n\nValor delta máximo divergente de 1:",
if maximo == 0.0:
	print Fraction.from_float(maximo).limit_denominator(DENOMINADOR)
else:
	print Fraction.from_float(maximo).limit_denominator(DENOMINADOR), "no valor X"+str(posicao), "=", str(valor)

print "\nTempo de cálculo:",
if (fim-inicio) > 60.0:
	if (fim-inicio) > 3600.0:
		print str((fim-inicio)/3600.0)[0:5], "horas"
	else:
		print str((fim-inicio)/60.0)[0:5], "minutos"
else:
	print str(fim-inicio)[0:5], "segundos"

print END
