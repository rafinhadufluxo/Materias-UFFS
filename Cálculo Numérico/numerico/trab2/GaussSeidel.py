# coding=UTF-8

import sys, os

# valores iniciais do programa e da matriz
i = j = linhas = colunas = 0
matriz = []
mensagemInicial = "Por favor, digite o nome do arquivo que contem a matriz a ser lida:"
mensagemErro = "\nNão foi possível ler o arquivo!\n"
mensagemErroIvalida = "O arquivo não contem uma matriz válida!\n" 
mensagemErroNaoQuadrada = "\nO número de linhas difere do número de colunas, \nmude seu arquivo da matriz e tente novamente!\n"

# método para imprimir uma matriz bonitinha
def imprime(matriz):
	for i in range(linhas):
		print "|",
		for j in range(colunas):
			print matriz[i][j],
		print "|"	
	return ""
	
# metodo Gauss_Jacobi
def Gauss_Jacobi(matriz, vetor_b, iteracoes_Gauss_Jacobi, epsilon_Gauss_Jacobi):
	
	#valores iniciais (x0 pode ser qualquer coisa pois o método independe do ponto inicial)
	x0 = []
	vetor_x1 = []
	for i in range(linhas):
		x0.append(float(i)) 
		vetor_x1.append(float(i)) 
	vetor_x0 = x0
	loop = True
	iteracoes = 0
	
	print "Executando o método de Gauss-Seidel com:\nvetor resposta:", vetor_b, "\nvetor x inicial:", vetor_x0
	
	#iteracao sobre a matriz
	while loop:
		
		for i in range(linhas):
			somatorio = 0.0
			
			for j in range(colunas):
				if i != j:
					if i==1:
						somatorio -= matriz[i][j]*vetor_x1[j]
					else:
						somatorio -= matriz[i][j]*vetor_x0[j]

			vetor_x0[i] = (somatorio + vetor_b[i]) / matriz[i][i]
			
		for i in range(linhas): 
			if abs(vetor_x0[i] - vetor_x1[i-1]) < epsilon_Gauss_Jacobi:
				loop = False
			
		for i in range(linhas): 											
			vetor_x1[i] = vetor_x0[i]
			
		iteracoes += 1
		
		if iteracoes == iteracoes_Gauss_Jacobi:
			loop = False
	
	#imprime o resultado
	print "\nO vetor encontrado após", iteracoes, "iterações foi:\n"
	iteracoes = 0
	for i in vetor_x0:
		print "X"+str(iteracoes)+" =", i
		iteracoes += 1


######################
# Inicio de execução #
######################

# verifica e lê o arquivo da matriz
try:
	os.system('clear')
	file = open('./matriz.txt', 'r')
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
	vetor_b = []
	for i in range(linhas):
		soma = 0.0
		for j in range(colunas):
			matriz[i][j] = float(matriz[i][j])
			soma += matriz[i][j]
		vetor_b.append(soma)
		
			
except Exception:
	print mensagemErro + mensagemErroIvalida
	exit()

print "Olá! Este programa leu a seguinte matriz:\n", imprime(matriz)


Gauss_Jacobi(matriz, [1.0, 0.0], 4000, 1e-5)
