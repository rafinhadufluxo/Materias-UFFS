# coding=UTF-8

import sys, os, math, time

#define os valores iniciais
epsilon = 0.0001
a = 1
b = 2
contador = 0
iteracaoMaxima = 50
mensagemInicial = '''Ola, escolha um dos metodos abaixo para calcular a raiz da funcao e^(-xˆ2) - cos(x):

	1 - Metodo da Bissecao
	2 - Metodo da Falsa Posicao
	3 - Metodo do Ponto Fixo
	4 - Metodo de Newton
					
Metodo escolhido: '''

#Define a funcao a ser usada no programa
def funcao(x):
	return math.exp((0-(x*x))) - math.cos(x)

#Define a derivada da funcao a ser usada
def derivadaFuncao(x):
	return 2*(math.exp((0-(x*x)))) + math.sin(x)

#Define a funcao para ser usada no metodo do ponto fixo
def pontoFixo(x):
	return math.acos(math.exp((0-(x*x))))

#Utilizado no metodo da falsa posicao
def calculaMedio(a, b):
	return (a*funcao(b)-b*funcao(a))/(funcao(b)-funcao(a))


#Le e verifica o input dado pelo usuario
try :
	if os.name == 'nt':
		os.system('CLS')
	else:
		os.system('clear')
	opcao = int(raw_input(mensagemInicial))

except (TypeError, NameError, ValueError) :
	print '\nOpcao invalida!\n'
	exit()


#opcao 1 -> metodo da bissecao
if opcao==1:
	inicio = time.time()
	medio = (a+b)/2
		
	while (abs(funcao(medio)) > epsilon) and (contador < iteracaoMaxima):
		medio = (a+b)/2
		
		if funcao(medio)*funcao(a) < 0:
			b = float(medio)
		else:
			a = float(medio)
		
		contador = contador + 1
		
	fim = time.time()
	print "\nRaiz:", medio, "\nIteracoes:", contador, "\n", "Tempo decorrido:", str(fim-inicio)[:5]+" milisegundos\n"

#opcao 1 -> metodo da falsa posicao
elif opcao==2:
	inicio = time.time()
	medio = calculaMedio(a, b)
		
	while (abs(funcao(medio)) > epsilon) and (contador < iteracaoMaxima):
		medio = calculaMedio(a, b)
		
		if funcao(medio)*funcao(a) < 0:
			b = float(medio)
		else:
			a = float(medio)
		
		contador = contador + 1
	
	fim = time.time()
	print "\nRaiz:", medio, "\nIteracoes:", contador, "\n", "Tempo decorrido:", str(fim-inicio)[:5]+" milisegundos\n"

#opcao 3 -> metodo do ponto fixo
elif opcao==3:
	inicio = time.time()
	x = pontoFixo((a+b)/2)

	while (abs(funcao(x)) > epsilon) and (contador < iteracaoMaxima):
		x = pontoFixo(x)
		contador = contador + 1
		
	fim = time.time()
	print "\nRaiz:", x, "\nIteracoes:", contador, "\n", "Tempo decorrido:", str(fim-inicio)[:5]+" milisegundos\n"

#opcao 4 -> metodo de newton	
elif opcao==4:
	inicio = time.time()
	x = (a+b)/2 - (funcao((a+b)/2))/(derivadaFuncao((a+b)/2))

	while (abs(funcao(x)) > epsilon) and (contador < iteracaoMaxima):
		x = x - (funcao(x))/(derivadaFuncao(x))
		contador = contador + 1
		
	fim = time.time()
	print "\nRaiz:", x, "\nIteracoes:", contador, "\n", "Tempo decorrido:", str(fim-inicio)[:5]+" milisegundos\n"

else:
	print "\nOpa! Nao temos nenhum metodo com essa opcao! :P\n"
