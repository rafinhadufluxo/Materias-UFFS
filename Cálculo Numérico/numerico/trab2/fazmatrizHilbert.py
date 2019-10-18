# coding=UTF-8

import sys, os

os.system('rm matrizHilbert.txt')
open('./matrizHilbert.txt', 'w')

# Padrão de linhas NxN
total = 5

# Número de linhas e colunas da matriz desejada
if len(sys.argv) == 2:
	try :
		total = int(sys.argv[1])
	
	except (TypeError, NameError, ValueError) :
		print '\nValor inválido!'
		print 'Execute conforme o seguinte modelo:\npython fazmatrizHilbert.py <número de linhas>\n'
		exit()
else:
	
	print "Nenhum número de linhas definido. Padrão de "+str(total)+" variáveis definido.\n"
	

f = open('./matrizHilbert.txt','r+')

for i in range(1, total+1):
	for j in range(1, total+1):
		a = str(float((1.0)/(i+j-1)))
		f.write(a)
		f.write(' ')
		
	f.write('\n')
