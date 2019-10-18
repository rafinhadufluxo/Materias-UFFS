# coding=UTF-8

import sys, os, math, time

#################################################
BOLD = "\033[1m"
ERROR = "\033[91m"
END = "\033[0m"

#################################################
#Define a funcao a ser calculada
def funcao(x):
	try:
		return eval(funcao1)

	except (TypeError, NameError):
		return eval("math."+funcao1)
		
	else:
		print ERROR+"\nFunção mal definida ou inválida!\n"+END
		exit()

#################################################
#metodo dos trapezios		
def metodoTrapezio():
	#define os valores iniciais
	somatorio = 0.0
	operacoes = 0
	
	inicio = time.time()

	h = (b-a)/INTERVALOS

	for i in range(INTERVALOS):
		x0 = a+(h*i)
		x1 = a+(h*(i+1))
		somatorio += funcao(x0) + funcao(x1)
		operacoes += 2
	
	somatorio = somatorio*(h/2)
	operacoes += 3
	
	fim = time.time()
	print "\nIntegral:", BOLD+str(somatorio)+END, "\n"
	print "Intervalos:", BOLD+str(INTERVALOS)+END
	print "h:", BOLD+str(h)+END
	print "Operações:", BOLD+str(operacoes)+END
	print "Tempo:", BOLD+str(fim-inicio)[:5]+END, "segundos.\n"

#################################################
#metodo de simpson
def metodoSimpson(INTERVALOS):
	#define os valores iniciais
	somatorio = 0.0
	operacoes = 0
	
	inicio = time.time()

	#o numero de intervalos deve ser par
	if INTERVALOS%2 == 1:
		INTERVALOS += 1

	h = (b-a)/INTERVALOS

	for i in range(INTERVALOS):
		xi = a+(h*i)
		if i%2:
			somatorio += 4*funcao(xi)
		else:
			somatorio += 2*funcao(xi)
		operacoes += 2
	
	somatorio += funcao(a) + funcao(b)
	somatorio = somatorio*(h/3)
	operacoes += 3
	
	fim = time.time()
	print "\nIntegral:", BOLD+str(somatorio)+END, "\n"
	print "Intervalos:", BOLD+str(INTERVALOS)+END
	print "h:", BOLD+str(h)+END
	print "Operações:", BOLD+str(operacoes)+END
	print "Tempo:", BOLD+str(fim-inicio)[:5]+END, "segundos.\n"


######################
# Inicio de execução #
######################

#################################################
#Le e verifica os parametros passados
try:
	funcao1 = str(sys.argv[1])
	a = float(sys.argv[2])
	b = float(sys.argv[3])
	INTERVALOS = int(sys.argv[4])

except (IndexError, TypeError, NameError, ValueError):
	print ERROR+"\nParâmetros inválidos!\n"+END
	print BOLD+"Os parametros corretos são: <funcao a ser calculad entre aspas> <a> <b> <quant intervalos>\n"+END
	exit()


#################################################
#Le e verifica o input de opções
try:
	mensagemInicial = '''Olá! Escolha um dos métodos abaixo para calcular o valor aproximado da integral da função '''+funcao1+''' entre o intervalo '''+str(a)+''' e '''+str(b)+''':

	1 - Método dos Trapézios Repetidos
	2 - Método de Simpson Repetido
	3 - Comparativo entre 1 e 2
	
Método escolhido: '''

	if os.name == 'nt':
		os.system('CLS')
	else:
		os.system('clear')
	opcao = int(raw_input(mensagemInicial))

except (TypeError, NameError, ValueError):
	print ERROR+"\nOpção inválida!\n"+END
	exit()


#################################################
#opcao 1 -> metodo dos trapézios
if opcao==1:
	metodoTrapezio()

#################################################
#opcao 2 -> metodo de simpson
elif opcao==2:
	metodoSimpson(INTERVALOS)
	
#################################################
#opcao 3 -> comparativo
elif opcao==3:
	print BOLD+"\nMétodo dos Trapézios:"+END,
	metodoTrapezio()
	print "-----------------------------------------\n"
	print BOLD+"Método de Simpson:"+END,
	metodoSimpson(INTERVALOS)
	
else:
	print ERROR+"\nOpa! Não temos nenhum método com essa opção! :P\n"+END
