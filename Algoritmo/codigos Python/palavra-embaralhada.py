'''Jogo da palavra embaralhada. Desenvolva um jogo em que o usuário tenha que adivinhar uma palavra que será mostrada com as 
letras embaralhadas. O programa terá uma lista de palavras lidas de um arquivo texto e escolherá uma aleatoriamente. O jogador terá 
seis tentativas para adivinhar a palavra. Ao final a palavra deve ser mostrada na tela, informando se o usuário ganhou ou perdeu o jogo'''

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
