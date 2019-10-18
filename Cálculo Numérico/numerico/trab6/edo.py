# coding=UTF-8

import sys, os, math

#################################################
BOLD = "\033[1m"
ERROR = "\033[91m"
END = "\033[0m"

#################################################
#define a funcao da ED a ser calculada
def ed(x, y):
	try:
		return eval(funcao)

	except (TypeError, NameError):
		return eval("math."+funcao)
		
	else:
		print ERROR+"\nFunção mal definida ou inválida!\n"+END
		exit()

#################################################
#metodo de Euler		
def euler(xk, yk, k, h):
	
	for i in range(k):
		yant = yk
		yk = yk + ( h * ed(xk, yk) )

	#calcula o erro e retorna
	return yk

#################################################
#metodo de R-K de 2 ordem
def rk2(xk, yk, k, h, a1, a2, b1, b2):

	if (a1+a2 == 1.0) and (a2*b1 == 0.5) and (a2*b2 == 0.5):
		for i in range(k):
			
			yant = yk

			yk = yk + ( a1*h*ed(xk, yk) ) + ( a2*h*ed( (xk+(b1*h)), (yk+(b2*h*ed(xk, yk))) ) )

		#calcula o erro e retorna
		return yk
		
	else:
		return ERROR+"Os valores de a1, a2, b1 e b2 são inválidos"+END
		
		
#################################################
#metodo de R-K de 4 ordem
def rk4(xk, yk, k, h, a1, a2, b1, b2):

	if (a1+a2 == 1.0) and (a2*b1 == 0.5) and (a2*b2 == 0.5):
	
		for i in range(k):
			k1 = h*ed(xk, yk)
			k2 = h*ed(xk+(h/2.0), yk+(k1/2.0))
			k3 = h*ed(xk+(h/2.0), yk+(k2/2.0))
			k4 = h*ed(xk+h, yk+k3)
			
			yant = yk

			yk = yk + ( (1.0/6.0) * (k1+(2.0*k2)+(2.0*k3)+k4) )
			
		#calcula o erro e retorna
		return yk
		
	else:
		return ERROR+"Os valores de a1, a2, b1 e b2 são inválidos"+END

#################################################
#error
def erro(x, yk, exata):
	exata = eval("math."+exata)
	return math.fabs(yk-exata)/math.fabs(exata)
	


######################
# Inicio de execução #
######################

#################################################
#Le e verifica os parametros passados
try:

	if os.name == 'nt':
		os.system('CLS')
	else:
		os.system('clear')

	funcao = str(sys.argv[1])
	x0 = float(sys.argv[2])
	y0 = float(sys.argv[3])
	y = float(sys.argv[4])
	h = float(sys.argv[5])
	a1 = float(sys.argv[6])
	a2 = float(sys.argv[7])
	b1 = float(sys.argv[8])
	b2 = float(sys.argv[9])
	exata = str(sys.argv[10])

except (IndexError, TypeError, NameError, ValueError):
	print BOLD+ERROR+"\nParâmetros inválidos!\n"+END
	print BOLD+"Os parâmetros corretos são: python trab6.py \"<f(x,y)>\" <x0> <y0> <x final> <h> <a1> <a2> <b1> <b2> \"<f'(x) - resposta exata>\"\n"+END
	exit()

#calcula o numero de iterações baseado no intervalo
k=int(y/h)

#################################################
#roda o método de euler e runge-kutta
euler = euler(x0, y0, k, h)
erroeuler = str(erro(y, euler, exata))

rungekutta2 = rk2(x0, y0, k, h, a1, a2, b1, b2)
errork2 = str(erro(y, rungekutta2, exata))

rungekutta4 = rk4(x0, y0, k, h, a1, a2, b1, b2)
errork4 = str(erro(y, rungekutta4, exata))


print "Xn  |  Y-Euler  |  Erro(Euler)"
print BOLD+str(y), euler, erroeuler, END
print "------------------------------"
print "Xn  |  Y-Runge-Kutta 2   |  Erro(Runge-Kutta 2)"
print BOLD+str(y), rungekutta2, errork2, END
print "------------------------------"
print "Xn  |  Y-Runge-Kutta 4   |  Erro(Runge-Kutta 4)"
print BOLD+str(y), rungekutta4, errork4, END
print

