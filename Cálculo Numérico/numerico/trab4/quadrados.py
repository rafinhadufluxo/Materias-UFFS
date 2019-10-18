# coding=UTF-8

import sys, os, math
from fractions import Fraction

# valores iniciais do programa e da matriz
i = 0
j = 0
linhas = 0
colunas = 0
decimal = False
functions = []
matriz = []
DENOMINADOR = 999999
BOLD = "\033[1m"
ERROR = "\033[91m"
END = "\033[0m"
mensagemInicial = "Olá! Por favor, digite o nome do arquivo que contem a matriz de pontos a ser lida: "
mensagemErro = ERROR+"\nNão foi possível ler o arquivo!\n"+END
mensagemErroIvalida = ERROR+"O arquivo não contem uma matriz válida!\n"+END
mensagemErroFuncao = ERROR+"As funções digitadas são inválidas\n"+END

###################################################
# método para imprimir uma matriz 2D bonitinha
def imprime(matriz, decimal):

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
	print
	
###################################################
# define o somatorio de cada aij
def somatorio(i, j, functions):

	somatorio = 0.0

	# o try verifica se a funcao eval é valida
	try:
		for k in range(colunas):
			x = matriz[0][k]
			somatorio += ( eval(functions[j]) * eval(functions[i]) )
		
		return somatorio
		
	except NameError:
		print mensagemErroFuncao
		exit()
	
	

###################################################
# calcula a matriz relativa aos "alfas"i
def calcula_matriz(functions):
	
	# matriz do sistema linear
	matriz_SL = []
	
	for i in range(len(functions)):
		matriz_SL.append([])
		for j in range(len(functions)):
			matriz_SL[i].append( somatorio(i, j, functions) )
	
	return matriz_SL

###################################################
# calcula o vetor b do SL relativo aos "alfas"
def calcula_b(functions):
	
	vetor_b = []
	
	# o try verifica se a funcao eval é valida
	try:
		for i in range(len(functions)):
			somatorio = 0.0
			for k in range(len(matriz[0])):
				x = matriz[0][k]
				somatorio += ( matriz[1][k] * eval(functions[i]) )
			vetor_b.append(somatorio)
			
		return vetor_b
		
	except NameError:
		print mensagemErroFuncao
		exit()

###################################################	
# métodos para calcular o sistema LU
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
	for i in range(0, tam):
		l1[i] = l1[i] - fator*l2[i]
	return l1

def calcularLU(matrizA):
	dim = len(matrizA[0])
	tempA = matrizA[:]
	matrizL = initMatriz(linhas)

	for i in range(0, dim):
		matrizL[i][i] = 1

	for c in range(0, dim):
		for l in range(c+1, dim):
			tm = termoM(tempA, l, c)
			tempA[l] = linhaMenosLinha(tempA[l], tm, tempA[c])

			matrizL[l][c] = tm

	return (matrizL, tempA)

###################################################
# vetor y parcial do cálculo do SL
def calcularY(matriz, resolucaoY, vetor_b):

	for k in range(linhas):
		somatorio = 0.0
		for i in range(k):
			somatorio += matriz[k][i]*resolucaoY[i]
		resolucaoY.append( (vetor_b[k]-somatorio) / matriz[k][k] )
		
###################################################
# calcula o vetor final x solução do SL
def calcularX(matriz, resolucaoX, resolucaoY):
	
	for k in range(linhas):
		somatorio = 0.0
		for i in range(k):
			somatorio += matriz[linhas-k-1][linhas-i-1]*resolucaoX[i]
		resolucaoX.append( (resolucaoY[linhas-k-1]-somatorio) / matriz[linhas-k-1][linhas-k-1] )


######################
# Inicio de execução #
######################

# verifica e lê o arquivo da matriz
try:
	os.system('clear')
	# define o arquivo a ser lido
	file_name = str(raw_input(mensagemInicial))
	if file_name != "":
		file = open('./'+file_name, 'r')
	else:
		file = open('./matriz.txt', 'r')

	# trasforma o arquivo lido em uma matriz 2D
	for linha in file:
		linha = linha.strip().split(' ')
		matriz.append([])
		matriz[i] = linha
		i += 1
		
	linhas = len(matriz)
	for c in matriz[0]:
		colunas += 1
		
	file.close()
	
except Exception:
	print mensagemErro
	exit()

# transforma os valores lidos de string para float
try:
	for i in range(linhas):
		for j in range(colunas):
			matriz[i][j] = float(matriz[i][j])
			
except Exception:
	print mensagemErro + mensagemErroIvalida
	exit()

# imprime a matriz lida
print "Este programa leu a seguinte matriz de pontos para x e f(x):"
imprime(matriz, decimal)

# define se há linearização ou não
opcao = int(raw_input('''Digite qual caso se deseja calcular:
1 - Linear
2 - Hipérbole | linearização por z=1/y |
3 - Exponecial | linearização por z=ln(y) |
'''))

# seleciona qual o método a ser usado
if opcao == 1:

	# pede ao usuário que defina os g(x) da curva
	functions = str(raw_input("Digite o valores de g(x) usados no ajuste de curva separados somente por vírgulas: "+BOLD))
	functions = functions.strip().split(',')
	print END

elif opcao == 2:
	
	# nós definiremos a linearizaçao hiperbólica como y=1/y
	for i in range(colunas):
		matriz[1][i] = (1/matriz[1][i])
	
	functions = ['1','x']
	
	#imprime os pontos linearizados
	print "Este programa linearizou os seguintes pontos para x e f(x):"
	imprime(matriz, decimal)
	
elif opcao == 3:
	
	# nós definiremos a linearizaçao exponencial como y=ln(y)
	for i in range(colunas):
		matriz[1][i] = math.log(matriz[1][i])
	
	functions = ['1','x']
	
	# imprime os pontos linearizados
	print "Este programa linearizou os seguintes pontos para x e f(x):"
	imprime(matriz, decimal)

# calcula a matriz de "alfas" referente ao pontos
matriz_SL = calcula_matriz(functions)
print "A matriz do Sistema Linear de a(alfas) é:"
imprime(matriz_SL, decimal)

# a matriz a ser trabalhada agora é a do SL associado
linhas = len(matriz_SL)
for c in matriz[0]:
	colunas += 1

# resolve o SL associado
res = calcularLU(matriz_SL)

# vetor b relativo ao SL
vetor_b = calcula_b(functions)
print "O vetor b relativo ao Sistema Linear é:"
for i in vetor_b:
	print BOLD+str(i)+END
print

# cálculo final do SL
resolucaoY = []
calcularY(res[0], resolucaoY, vetor_b)

resolucaoX = []
calcularX(res[1], resolucaoX, resolucaoY)
resolucaoX.reverse()

# formata a resposta de acordo com o método escolhido
print "Resolvendo o Sistema Linear temos a curva:",
if opcao == 1:
	contador = 0
	for i in resolucaoX:
		if i >= 0.0 and contador != 0:
			i = "+ "+str(i)
		print BOLD+str(i)+functions[contador]+END,
		contador += 1
	print
	
elif opcao == 2:
	print BOLD+"(",
	if resolucaoX[1] > 0.0:
		print str(resolucaoX[0])+" + "+str(resolucaoX[1])+"x",
	else:
		print str(resolucaoX[0])+" "+str(resolucaoX[1])+"x",
	print ")^-1"+END
	
elif opcao == 3:
	print BOLD+str(math.exp(resolucaoX[0]))+" * "+str(math.exp(resolucaoX[1]))+"^x"+END

