#1.Faça um Programa que peça dois números e imprima o maior deles.
'''x = int(input())
y = int(input())
if x > y :
        print(x)
else:
        print(y)'''
##############################################################################
#2.Faça um Programa que peça um valor e mostre na tela se o valor é positivo
#ou negativo.

'''x = int(input())
if x > 0:
        print("Positivo")
else:
        print("negativo")'''
#############################################################################
#3.Faça um Programa que verifique se uma letra digitada é "F" ou "M". Conforme
#a letra escrever: F - Feminino, M - Masculino, Sexo Inválido.

'''x = input().upper()
if x == "M" or x == "F":
        print("AEEEEEEEEEE")
else:
        print("Sexo Inválido")'''
############################################################################
#4.Faça um Programa que verifique se uma letra digitada é vogal ou consoante.

'''x = input().upper()
if x == "A" or x == "E" or x == "I" or x == "O" or x == "U":
        print("VOGAL")
else:
        print("TCHAUUU")'''
#########################################################################################
'''5.Faça um programa para a leitura de duas notas parciais de um aluno. O programa deve
calcular a média alcançada por aluno e apresentar:
        o A mensagem "Aprovado", se a média alcançada for maior ou igual a sete;
        o A mensagem "Reprovado", se a média for menor do que sete;
        o A mensagem "Aprovado com Distinção", se a média for igual a dez.'''

# codigo principal
x = float(input())
y = float(input())

media = (x + y)/ 2
if media >= 10:
        print("Aprovado com Distinção")
elif media >= 7:
        print("Aprovado")
else:
        print("Reprovado")

#############################################################################################################
6.Faça um Programa que leia um número e exiba o dia correspondente da semana. (1-Domingo, 2- Segunda, etc.), se 
digitar outro valor deve aparecer valor inválido.
x = ["domingo", "segunda", "terça", "quarta", "quinta", "sexta", "sabado"]

num = int(input())
if num == 1 or num == 2 or num == 3 or num == 4 or num == 5 or num == 6 or num == 7:
        selecao = x [num -1]
        print(selecao)
else:
        print("INVALIDO")
##########################################################################################################################
#7.Faça um Programa que leia três números e mostre-os em ordem decrescente.
'''n = int(input())
rafa = []
for i in range(n):
        x = int(input())
        rafa.append(x)
rafa.sort() 
print(rafa)'''

#######################################################################################
'''8.Faça um Programa que pergunte em que turno você estuda. Peça para digitar M-matutino
ou V-Vespertino ou N- Noturno. Imprima a mensagem "Bom Dia!", "Boa Tarde!" ou "Boa Noite!"
ou "Valor Inválido!", conforme o caso.'''

#print("==== SIGLA ======")
#print('''        [M] matutino
#        [V] Vespertino
#        [N]Noturno''')
'''x = input("INFORME SEU PERIODO: ").upper()
if x == "V":
        print("Boa Tarde")
elif x == "M":
        print("Bom Dia!")
else:
        if x == "N":
                print("Boa Noite")
        else:
                print("Valor Inválido!")'''
###########################################################################################
'''9.Faça um Programa para leitura de três notas parciais de um aluno. O programa deve calcular
a média alcançada por aluno e presentar:
        a - A mensagem "Aprovado", se a média for maior ou igual a 7, com a respectiva média alcançada;
        b - A mensagem "Reprovado", se a média for menor do que 7, com a respectiva média alcançada;
        c- A mensagem "Aprovado com Distinção", se a média for igual a 10.'''

#codigo
'''x = float(input())
y = float(input())
z = float(input())
media = (x + y + z)/3
if media >= 10:
        print("Aprovado com Distinção")
elif media >= media:
        print("Reprovado")
else:
        print("Reprovado")'''

#############################################################################################################
10 - As Organizações Tabajara resolveram dar um aumento de salário aos seus colaboradores e lhe contraram para 
desenvolver o programa que calculará os reajustes. Faça um programa que recebe o salário de um colaborador e o 
reajuste segundo o seguinte critério, baseado no salário atual:
        o salários até R$ 280,00 (incluindo) : aumento de 20%
        o salários entre R$ 280,00 e R$ 700,00 : aumento de 15%
        o salários entre R$ 700,00 e R$ 1500,00 : aumento de 10%
        o salários de R$ 1500,00 em diante : aumento de 5% Após o aumento ser realizado, informe na tela:
        o O salário antes do reajuste;
        o O percentual de aumento aplicado;
        o O valor do aumento;
        o O novo salário, após o aumento

#codigo
salario = int(input())

if salario <= 280.00 :
	porcentagem = salario * (20/100)
	salario = salario + porcentagem
	print("Novo salario: {:.2f}". format(salario))
	print("Reajuste ganho: {:.2f}". format (porcentagem))
	print("Em percentual: 20 %")

elif salario <= 700.00 :
	porcentagem = salario * (15/100)
	salario = salario + porcentagem
	print("Novo salario: {:.2f}". format(salario))
	print("Reajuste ganho: {:.2f}". format (porcentagem))
	print("Em percentual: 20 %")

elif salario <= 1500.00   :
	porcentagem = salario * (10/100)
	salario = salario + porcentagem
	print("Novo salario: {:.2f}". format(salario))
	print("Reajuste ganho: {:.2f}". format (porcentagem))
	print("Em percentual: 20 %")

else:
	porcentagem = salario * (4/100)
	salario = salario + porcentagem
	print("Novo salario: {:.2f}". format(salario))
	print("Reajuste ganho: {:.2f}". format (porcentagem))
	print("Em percentual: 4 %")
##########################################################################################################################	
'''11-Faça um Programa que peça 2 números inteiros e um número real. Calcule e mostre:
    a.	o produto do dobro do primeiro com metade do segundo.
    b.	a soma do triplo do primeiro com o terceiro.
    c.	o terceiro elevado ao cubo
x = int(input())
y = int(input())
print("dobro do primeiro {}". format(x*2), end='')
print("| metade do segundo {}". format(y/2))
print("a soma do triplo do primeiro com o terceiro é {}.". format((x*3)+ (y*3)))
print("o terceiro elevado ao cubo é {}". format(((x*3)+ (y*3))*3))'''
#########################################################################################################

'''12- Faça um Programa que peça um número inteiro e determine se ele é par ou impar. Dica: utilize o
operador módulo (resto da divisão).'''

'''x = int(input())
if x % 2 == 0:
    print("par")
else:
    print("impar")'''
##########################################################################################################################
13 - Faça um Programa para um caixa eletrônico. O programa deverá perguntar ao usuário a valor do saque e depois 
informar quantas notas de cada valor serão fornecidas. As notas disponíveis serão as de 1, 5, 10, 50 e 100 reais. 
O valor mínimo é de 10 reais e o máximo de 600 reais. O programa não deve se preocupar com a quantidade de notas 
existentes na máquina.
 	- Exemplo 1: Para sacar a quantia de 256 reais, o programa fornece duas notas de 100, uma nota de 50, uma nota 
        de 5 e uma nota de 1;
	- Exemplo 2: Para sacar a quantia de 399 reais, o programa fornece três notas de 100, uma nota de 50, quatro 
         notas de 10, uma nota de 5 e quatro notas de 1.

##############################################################################################################################
14 - Faça um Programa que leia um número inteiro menor que 1000 e imprima a quantidade de centenas, dezenas e unidades do mesmo.
Observando os termos no plural a colocação do "e", da vírgula entre outros. Exemplo:
        o 326 = 3 centenas, 2 dezenas e 6 unidades
        o 12 = 1 dezena e 2 unidades Testar com: 326, 300, 100, 320, 310,305, 301, 101, 311, 111, 25, 20, 10, 21, 11, 1, 7 e 16

#####################################################################################################################################
15 - Faça um Programa para uma loja de tintas. O programa deverá pedir o tamanho em metros quadrados da área a ser pintada. Considere 
que a cobertura da tinta é de 1 litro para cada 6 metros quadrados e que a tinta é vendida em latas de 18 litros, que custam R$ 80,00 
ou em galões de 3,6 litros, que custam R$ 25,00.
        o Informe ao usuário as quantidades de tinta a serem compradas e os respectivos preços em 3 situações:
        o comprar apenas latas de 18 litros;
        o comprar apenas galões de 3,6 litros;
        o misturar latas e galões, de forma que o preço seja o menor. Acrescente 10% de folga e sempre arredonde os valores para cima, 
        isto é, considere latas cheias.
####################################################################################################################################
16 -Faça um programa que peça o tamanho de um arquivo para download (em MB) e a velocidade de um link de Internet (em Mbps), 
calcule e informe o tempo aproximado de download do arquivo usando este link (em minutos).

######################################################################################################################################

Faça um Programa que peça a temperatura em graus Celsius, transforme e mostre em graus Farenheit
c = float(input("Informe a temperatura em ºC:" ))
f = ((9 * c)/5) +32
print("Temperatura em {} ºC, corresponde em {} *f!". format(c, f))

###########################################################################################################################
Faça um Programa que peça 2 números inteiros e um número real. 
 Calcule e mostre: 
 a. o produto do dobro do primeiro com metade do segundo 
 b. a soma do triplo do primeiro com o terceiro
 c. o terceiro elevado ao cubo.
 '''

n1 = int(input('1º Número inteiro: '))
n2 = int(input('2º Número inteiro: '))
n3 = float(input('Número real: '))

print ('Soma:', ((2*n1) * (n2/2)))
print ('Produto:', (3 * n1) + n3)
print ('Cubo:', n3**3)
###########################################################################################################################
Tendo como dados de entrada a altura de uma pessoa, construa um algoritmo que calcule seu peso ideal, usando a seguinte 
fórmula: (72.7*altura) - 58 

altura = float(input('Altura:'))
print ('Peso ideal:', (72.7*altura) - 58)
###########################################################################################################################
Tendo como dados de entrada a altura e o sexo de uma pessoa, construa um algoritmo que calcule seu 
peso ideal, utilizando as seguintes fórmulas: Para homens: (72.7*h) - 58 Para mulheres: (62.1*h) - 44.7 (h = altura)
Peça o peso da pessoa e informe se ela está dentro, acima ou abaixo do peso. 


sexo = int(input('Escolha: 1- Sexo Masculino / 2- Sexo Feminino: '))
h = float(input('Altura:'))
peso = float(input('Peso:'))

peso_ideal = (72.7*h) - 58 if sexo == 1 else (62.1*h) - 44.7

if peso < peso_ideal:
	print('Abaixo do peso ideal!')
elif peso == peso_ideal:
	print('Dentro do peso ideal!')
else:
	print('Acima do peso ideal!')
print ('Peso: %.2f / Peso ideal: %.2f' %(peso, peso_ideal))


#exemplo de código da condição da linha 11 mais detalhado
'''if sexo == 1:
	peso_ideal = (72.7*h) - 58
else:
	peso_ideal = (62.1*h) - 44.7'''


###########################################################################################################################

faça uma programa que converta metros por centimentos!

cm = float(input("Informe o Metros:" )) #convertendo Metros para cm!
soma = nota1 * 100
print("{} metros, é {:.0f} cm" . format(nota1, soma))

###########################################################################################################################
Faça um programa que peça o raio de um circulo, calcule e mostre sua area.

raio = int(input("Informe o raio de um circulo: "))
calculo = 3.14 * (raio**2)
print("A area do circulo é: ", calculo)
#################################################################################################################################

Faça um programa que calcule a aréa de um quadrado, em seguida mostre o dobro desta aréa para o usuario.

quadrado = int(input("Informe o lado do quadrado: "))
soma = quadrado**2
dobro = soma * 2 #quando fala em dobro, é tudo divido por 2.
print("A areá do quadrado é {} cm, entretanto o dobro da sua areá é de {}". format (soma,dobro))
###################################################################################################################################

Faça um Programa que pergunte quanto você ganha por hora e o número de horas trabalhadas no mês. Calcule e mostre o total do seu 
salário no referido mês.

ganhaHora = int(input("Quanto voce ganha por hora: "))
horatrab = int(input("Informe o numero de horas trabalhada: "))

soma = ganhaHora *horatrab

print("Você receberá neste mês R$ {}". format(soma))
#####################################################################################################################################

Faça um Prograa que peça a temperatura em graus Farenheit, transforme e mostre a temperatura em graus Celsius. o C = (5 * (F-32) / 9).

f = float(input("Informe a temperatura em Farenheit:" ))
C = (5 * (f - 32) / 9)
print("Temperatura em {}F, corresponde em {}ºC!". format(f, C))
##################################################################################################################################
João Papo-de-Pescador, homem de bem, comprou um microcomputador para controlar o rendimento diário de seu trabalho. Toda vez que 
ele traz um peso de peixes maior que o estabelecido pelo regulamento de pesca do estado de São Paulo (50 quilos) deve pagar uma multa 
de R$ 4,00 por quilo excedente. João precisa que você faça um programa que leia a variável peso (peso de peixes) e verifique se há 
excesso. Se houver, gravar na variável excesso e na variável multa o valor da multa que João deverá pagar. Caso contrário mostrar tais 
variáveis com o conteúdo ZERO.

pPescados = int(input('Digito o numero de peixes pescados: '))

if pPescados > 50:
    pExedidos = pPescados - 50
    multa = pExedidos * 4.00
    print ('Você exedeu',pExedidos,'do numero permitido de peixes\n    O valor de sua multa é de R$',multa) #não coube na linha
else:
    print('Você não execeu o limite de peixes pescados')
    
#################################################################################################################################
Faça um Programa que pergunte quanto você ganha por hora e o número de horas trabalhadas no mês. 
Calcule e mostre o total do seu salário no referido mês, sabendo-se que são descontados 11% para o Imposto de Renda, 8% para 
o INSS e 5% para o sindicato, faça um programa que nos dê:
      salário bruto.
          a.	quanto pagou ao INSS.
          b.	quanto pagou ao sindicato.
          c.	o salário líquido.
          d.	calcule os descontos e o salário líquido, conforme a tabela abaixo:
          e.	+ Salário Bruto : R$
          f.	- IR (11%) : R$
          g.	- INSS (8%) : R$
          h.	- Sindicato ( 5%) : R$
              = Salário Liquido : R$

Obs.: Salário Bruto - Descontos = Salário Líquido.

#codigo da resposta
dim = int(input("quanto recebe por dia: "))
hora = int(input("quantas horas trabalhadas: "))
salario = dim * hora

imposto = (11/100.0) * salario
inss = (8/100.0) * salario
sindicato = (5/100.0) * salario


desc = imposto + inss + sindicato
salarioL = salario - desc


print("Imposto de renda: " , imposto)
print("INSS: ", inss)
print("Sindicato: ", sindicato)

print('Seu salario bruto {}'. format(salario))
print("Com desconto, o salario liquido é {}". format(salarioL))

##################################################################################################################################
Faça um programa para uma loja de tintas. O programa deverá pedir o tamanho em metros quadrados da área a ser pintada. 
Considere que a cobertura da tinta é de 1 litro para cada 3 metros quadrados e que a tinta é vendida em latas de 18 litros, que 
custam R$ 80,00. Informe ao usuário a quantidades de latas de tinta a serem compradas e o preço total.

tamanho = int(input('Tamanho em metros quadrados: '))
litros = tamanho / 3 

# 18 x 3 = 54

if tamanho % 54 == 0:
	latas = tamanho / 54
else: 
	latas = int(tamanho / 54) + 1

preco = latas * 80
print ('%d latas' %latas)
print ('R$ %.2f' %preco)
#####################################################################################################################
