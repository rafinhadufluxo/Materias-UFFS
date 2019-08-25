###############################################

'01 -Tamanho de strings. Faça um programa que leia 2 strings e informe o conteúdo delas seguido do seu comprimento. Informe também se as duas strings possuem o mesmo comprimento e são iguais ou diferentes no conteúdo.'

s1 = "Brasil hexa 2006!"
s2 = "Brasil! hexa 2006!"
s11 = []
s22 = []
for letra in s1:
	s11.append(letra)
for letra in s2:
	s22.append(letra)
if(s11 == s22):
	print("Sao iguais!")
else:
	print("Sao diferentes!")

if (len(s1) == len(s2)):
	print("Possuem o mesmo tamanho!")
else:
	print("Nao possuem o mesmo tamanho!")

###################################################

'02-Nome ao contrário em maiúsculas. Faça um programa que permita ao usuário digitar o seu nome e em seguida mostre o nome do usuário de trás para frente utilizando somente letras maiúsculas. Dica: lembre−se que ao informar o nome o usuário pode digitar letras maiúsculas ou minúsculas.'
nome = ""
s = "" 

nome = input("Informe o nome:")

for letra in reversed(nome):
	s+=letra
print(s.upper())

#####################################################

'03- Nome na vertical. Faça um programa que solicite o nome do usuário e imprima-o na vertical.'
nome = input("Informe o nome: ")
#print("\n".join(nome))
for letra in nome:
	print(letra)

######################################################

'04 - Nome na vertical em escada. Modifique o programa anterior de forma a mostrar o nome em formato de escada'
#nome = input("Informe o nome: ")
nome= "ezequiel"
s = ""

for letra in nome:
		s+=letra
		print(s)

######################################################

'05 -  Nome na vertical em escada invertida. Altere o programa anterior de modo que a escada seja invertida.'
#nome = input("Informe o nome: ")

nome= "ezequiel"
s = ""
nome2 = ""
#h = ""
nome2 = nome
for letra in nome:
	s+=letra

for i in range (len(nome)):
	h = s[0:8-i:]
	print(h)
	
######################################################

'06 - Data por extenso. Faça um programa que solicite a data de nascimento (dd/mm/aaaa) do usuário e imprima a data com o nome do mês por extenso.'
dia = int(input("Informe o dia de nascimento: "))
mes = int(input("Informe o mes de nascimento: "))
ano = int(input("Informe o ano de nascimento: "))
m = "Janeiro Fev Março Abril Maio Jun Jul Agost Setem Out Nov Dez"
m2 = m.split()

print("Data de nascimento: %i/ %i/ %i"%(dia,mes,ano))
print("Voce nasceu em",dia,"de",m2[mes-1]," ",ano)

######################################################

'''07 -Conta espaços e vogain. Dado uma string com uma frase informada pelo usuário (incluindo espaços em branco), conte:

quantos espaços em branco exintem na frase.
quantas vezes aparecem as vogain a, e, i, o, u.'''

cont=0

dig = input("informe uma frase: ")
print("Ha '%i' espaços na frase.  "%(dig.count(" ")))

s = dig.count("a")+dig.count("e")+dig.count("i")+dig.count("o")+dig.count("u")
print("Ha '%i' vogais na frase.  "%(s))

######################################################

'08-Palíndromo. Um palíndromo é uma seqüência de caracteres cuja leitura é idêntica se feita da direita para esquerda ou vice−versa. Por exemplo: OSSO e OVO são palíndromos. Em textos mais complexos os espaços e pontuação são ignorados. A frase SUBI NO ONIBUS é o exemplo de uma frase palíndroma onde os espaços foram ignorados. Faça um programa que leia uma seqüência de caracteres, mostre−a e diga se é um palíndromo ou não.'
cct= ""
lf= []
cont=0
con2=[]
fc= ""

frase = input("Informe a frase: ").lower()
for letra in frase:
	if (letra != " "):
		fc+=letra
		lf.append(letra)
for i in lf[::-1]:
  	cct+=i
	
if(fc == cct):
	print("E uma palavra palíndroma!")
else:
	print("Nao e uma palavra palíndroma!")

#####################################################

'09 - Verificação de CPF. Desenvolva um programa que solicite a digitação de um número de CPF no formato xxx.xxx.xxx-xx e indique se é um número válido ou inválido através da validação dos dígitos verificadores edos caracteres de formatação.'



cpf = input("CPF(xxx.xxx.xxx-xx) :") #3 7 11


for letra in cpf:
	while(cpf[3] !=".") or (cpf[7] !=".") or (cpf[11] !="-"):
		cpf = input("O 'CPF' pricisa estar no formato (xxx.xxx.xxx-xx) :")

#####################################################

' 10 - Número por extenso. Escreva um programa que solicite ao usuário a digitação de um número até 99 e imprima-o na tela por extenso.'
l = "um dois tres quatro cinco seis sete oito nove dez"
l2 = l.split()
num = int(input("Informe um numero de '1' a '10':"))-1

print(l2[num])

#####################################################



#####################################################

# 12 - Valida e corrige número de telefone. Faça um programa que leia um número de telefone, e corrija o número no caso deste conter somente 7 dígitos, acrescentando o '3' na frente. O usuário pode informar o número com ou sem o traço separador.
tel = input("Informe o telefone: ")
ct="3"

if (len(tel) == 7):
 	print("Faltou um número ! irei incluir um '3' no inicio.")
 	for i in tel:
 		ct+=i
 	print(ct)
else:
	print("Número completo!")
	
###################################################

# 13 - Jogo da palavra embaralhada. Desenvolva um jogo em que o usuário tenha que adivinhar uma palavra que será mostrada com as letras embaralhadas. O programa terá uma lista de palavras lidas de um arquivo texto e escolherá uma aleatoriamente. O jogador terá seis tentativas para adivinhar a palavra. Ao final a palavra deve ser mostrada na tela, informando se o usuário ganhou ou perdeu o jogo
import random 

palavras = "continue palavras seis adivinhar aleatoriamente".split()
global palavras

pl = random.choice(palavras)
c = []
ct = ""
#pl = "seis"
rc = pl
erro = 0
flag = False

for letra in pl:
	c.append(letra)
	c.sort()
for letra in reversed(c):
	ct+=letra
print(" Adivinhe a palavra - %s - ."%(ct))

while(flag == False):
	resp = input("\nInforme a sua tentativa: ")
	if (resp == rc):
		flag = True
		print("\nVocê acertou !")
	else:
		print("\nVocê errou!")
		erro+=1
		if (erro == 7):
			flag = True
			print("\n \nTodas suas chances acabaram...")

#print(" Adivinhe a palavra",sorted(pl),".")
