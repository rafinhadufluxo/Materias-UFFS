#Trabalho de PYTHON
#REGRAS DA QUESTÃO
#1- Ao iniciar, ele solicita ao usuário o valor total de dinheiro que pode ser retirado do cofre naquela
#execução do programa. Em seguida, o programa fica recebendo valores inteiros, que correspondem a retiradas de
#dinheiro do cofre. Cada vez que um número é informado, o programa mostra a saída das notas
#utilizadas e o quanto de dinheiro ainda pode ser retirado; depois, o programa volta a receber valores
#para uma nova retirada.Quando uma retirada com valor menor ou igual a R$ 0 for informado, o programa termina.
#Quando uma retirada é feita, o programa sempre deve fornecer o menor número possível de notas.
#Considere que podem ser fornecidas notas de R$ 100, R$ 50, R$ 20, R$ 10 e R$ 5.


print("============================")
print("      BRANCO PYTHON BR       ")
print("============================")
saldo = float(input("Informe o saldo do Cofre R$: "))#float
saque = int(input("Informe o valor do saque R$ "))
while saque > 0:
	if saldo >= saque:
		entrega_money = saque
		cem = cinq = vin = dez = cinco = 0

		while entrega_money >= 100:
			entrega_money-= 100
			cem += 1

		while entrega_money >= 50 and entrega_money < 100:
			entrega_money -= 50
			cinq += 1

		while entrega_money >= 20 and entrega_money < 50:
			entrega_money -= 20
			vin += 1

		while entrega_money >= 10 and entrega_money < 20:
			entrega_money -= 10
			dez += 1

		while entrega_money >= 5 and entrega_money < 10:
			entrega_money -= 5
			cinco += 1

		while entrega_money < 5 and entrega_money != 0:
			print("----> NÃO É POSSÍVEL SACAR ESTE VALOR ! <----")
			entrega_money = 0
			saque = cem = cinq = vin = dez = cinco = 0

		saldo = saldo - saque

		print('''NOTAS SACADAS DO PYTHON BR:
   R$ 100,00  – {}
   R$  50,00  – {}
   R$  20,00  – {}
   R$  10,00  – {}
   R$   5,00  – {}
VALOR  RESTANTE NO COFRE R$ {}'''.format(cem,cinq,vin,dez,cinco,saldo))
	else:
		print("----> NÃO É POSSÍVEL SACAR ESTE VALOR! <----")

	saque = int(input("INFORME O VALOR DO SAQUE R$ "))
print("============================")
print("   ENCERRANDO A OPERAÇÃO    ")
print("============================")
