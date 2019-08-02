def palavra(xuxu,x):
    
    cont = 0
    for p in xuxu:
        if p == x:
            cont +=1
    print(cont)
            
    return cont
    

rafa =  "casa branca"  #input("informe a frase: ")
x =  "a"  #input("informe a letra: ")

lu = palavra(rafa,x)


#print("Existem {} caracteres [{}] na palavra[{}]. ". format(lu,x, rafa))



######################################################################################################################
def retorna_repetidos(pal):
    nova = ""
    for s in pal:
        if pal.count(s) >= 2 and nova.count(s)<1:
        
            nova += s
    return nova

palavra = 'teste de mesa'

print(retorna_repetidos(palavra))

#######################################################################################################################
#procura a letra que o usuario deseja
def conta_caractere(palavra,carac):
    conta = 0
    for s in palavra:
        if s == carac:
           conta += 1
    return conta

palavra = "teste de mesa"
caractere = "s"
print(conta_caractere(palavra,caractere))


############################################################################################################################
class dado:
	nome =''
	sobrenome =''


	
rafa = dado()
rafa.nome = input("Informe o nome: ")
rafa.sobrenome = input("Informe o sobrenome: ")

nome = rafa.nome + ' ' + rafa.sobrenome	


nomeInvert = ''
for i in range(len(nome)-1, -1, -1):
	nomeInvert += nome[i]
print(nomeInvert)

##############################################################################################################################
'''Faça um programa que leia 5 jogos de videogame, sendo que eles possuem as informações de nome, estilo, fabricante e preço 
em dólares (US$). Depois, imprima estes 5 jogos, mostrando os seus dados e também o seu preço em reais (R$). Considere a taxa 
de câmbio: US$ 1,00 = R$ 3,98.'''

class Jogo:
	nome = ''
	estilo = ''
	fabricante = ''
	preco = 0.0

def ler_jogos():
	jog = Jogo ()
	jog.nome = input("Informe o nome do jogo: ")
	jog.estilo = input("Informe o tipo do jogo: ")
	jog.fabricante = input("Informe o fabricante do jogo: ")
	jog.preco = float(input("Informe o valor o jogo: "))
	print()
	return jog

def imprime_jogos(jog):
	print()
	print("JOGOS DA SEÇÂO")
	print("nome: ",jog.nome)
	print("estilo: ",jog.estilo)
	print("fabricante: ",jog.fabricante)
	print("preco USS:{:.2f} ".format(jog.preco))
	print("preco USS:{:.2f} ".format(jog.preco * 3.98))

jogos = []
for i in range(5):
	jogos.append(ler_jogos())

for jogo in jogos:
	imprime_jogos(jogo)

#########################################################################################################################
'''Faça um programa que leia uma matriz quadrada de tamanho (ordem) 4. Depois, multiplique essa
matriz por um número dentro de uma função, sendo esse número também lido pelo usuário. Por
fim, imprima a matriz com os números já multiplicados.'''


def matriz (ordem): 
	matriz = []
	for i in range(4):
		print("Linha {}". format( i + 1))
		linha = []
		for j in range(4):
			x = int(input())
			linha.append(x)
		matriz.append(linha)
	return matriz

def multi (matriz, x):
	mult = []
	for i in range(4):
		for j in range(4):
			matriz [i][j] *= x

def imprime(matriz, ordem):
	for i in range(ordem):
		for j in range(ordem):
			print("{:3}".format(matriz[i][j]), end=" ")
		print()


print("Leitura Matriz:")
	
rafa = matriz (4)
n = int(input("Informe um numero: "))
multi (rafa, n)
imprime(rafa, 4 )
print()

#########################################################################################################################
"""Verificação de CPF. Desenvolva um programa que solicite a digitação de um número de CPF no formato xxx.xxx.xxx-xx e 
indique se é um número válido ou inválido através da validação dos dígitos verificadores edos caracteres de formatação."""
def validaCPF(cpf):
    #validando digito verificador 1
    cont = 10
    digito = 0
    soma = 0
    while cont<=2:
        soma = soma + (cpf[digito]+cont)
        cont = cont -1
        digito = digito + 1
    restodiv = int(soma%11)
    if(restodiv)<2:
        dv1=0
    else:
        dv1 = soma/(11-restodiv)
 
    if(int(cpf[9]) == dv1):
       print('Digito verificador 1 é válido')
    else:
       print('Digito verificador 1 é inválido, o correto seria: ', dv1) 
    #validando digito verificador 2
    cont = 11
    digito = 0
    soma = 0
    while cont<=2:
        soma = soma + (cpf[digito]+cont)
        cont = cont - 1
        digito = digito + 1
    restodiv = int(soma%11)
    if(restodiv)<2:
        dv2=0
    else:
        dv2 = soma/(11-restodiv)
 
    if(int(cpf[10]) == dv2):
        print('Digito verificador 2 é válido')
    else:
        print('Digito verificador 2 é ainválido, o correto seria: ', dv1) 
 
    if((int(cpf[9]) == dv1) and (int(cpf[10]) == dv2)):
        print('O CPF <', cpf,'> É VÁLIDO') 
 
 
cpf = input('DIGITE UM CPF XXX.XXX.XXX-XX: ')
 
cpfint = cpf.split('.')
cpfstr = ''
for i in cpfint:
    cpfstr = cpfstr + i
cpfstr = cpfstr.split('-')
cpf = ''
for i in cpfstr:
    cpf = cpf + i
print(cpf)
validaCPF(cpf)
#################################################################################################################################
def red(n):
    matriz = []
    for i in range(0,n):
        linha = []
        for j in range(0,n):
            linha.append(n)
        matriz.append(linha)
    return matriz

def imprimi(matriz):
    for i in matriz:
        for j in i:
            print(j, end='')
        print()

n = 1
while n != 0:
    n = int(input())
    if n == 0:
        print("adios")
    if n != 0:
        matriz = red(n)
        imprimi(matriz)

///////////////////////////////////////////////////////////////////////////////////////////////////
def imprimi_matriz (matriz, rafa):
	for i in range(rafa):
		for j in range(rafa):
			
			print("{:3}". format(mat[i][j]), end= '')
		print()
	





rafa = int(input("Informe o tamanho da matriz: "))

mat = []
for i in range(rafa):
	linha = []
	for j in range(rafa):
		n = int(input("Informe um numero {} |{}: ". format (i,j)))
		linha.append(n)
	mat.append(linha)

imprimi_matriz(mat,rafa)
/////////////////////////////////////////////////////////////////////////

def soma_matriz(matA, matB):
	#Cálculo da matriz matC (matA + matB)
	matC = []
	for i in range(5):
		linha = []
		for j in range(4):
			linha.append(matA[i][j] + matB[i][j])
		matC.append(linha)
	return matC
	
		

#cod Principal
matA = []
for i in range(5):
	linha = []
	print()
	print("Linha A", i + 1)
	for j in range(4):
		x = int(input())
		linha.append(x)
	matA.append(linha)

matB = []
for i in range(5):
	linha = []
	print()
	print("Linha B", i + 1)
	for j in range(4):
		x = int(input())
		linha.append(x)
	matB.append(linha)


C = soma_matriz(matA, matB)

#Impressão da matriz C
print("\nMatriz C (A + B):")
for i in range(5):
	for j in range(4):
		print("{:3}".format(C[i][j]), end=" ")
	print()
///////////////////////////////////////////////////////////////////////////////////

def soma_matriz(matA, matB):
	#Cálculo da matriz matC (matA + matB)
	matC = []
	for i in range(N_linha):
		linha = []
		for j in range(N_coluna):
			linha.append(matA[i][j] + matB[i][j])
		matC.append(linha)
	return matC

def le_matriz():
	matriz = []
	for i in range(N_linha):
		linha = []
		print("Linha", i+1)
		for j in range(N_coluna):
			n = int(input("Informe um número para a coluna {}: ".format(j+1)))
			linha.append(n)
		matriz.append(linha)

	return matriz

def imprime_matriz(matriz):
	for i in range(N_linha):
		for j in range(N_coluna):
			print("{:3}".format(matriz[i][j]), end=" ")
		print()


N_linha = 3
N_coluna = 3
#Leitura matriz A
print("----Matriz A----")
A = le_matriz()

#Leitura matriz B
print("\n----Matriz B----")
B = le_matriz()

#Chama a função para fazer o cálculo da matriz C
C = soma_matriz(A, B)

#Impressão da matriz C
print("\nMatriz C (A + B):")
imprime_matriz(C)
/////////////////////////////////////////////////////////////////////////////
def tab (n):
	print("A tabuada do {}". format(n))
	for c in range(1, 11):
	
		print("{} x {} = {}". format(n, c, n*i))


#principal
for i in range(2,13):
	tab(i)

print()
//////////////////////////////////////////////////////////////////////////////////////////////

def equacao(x, y):
	return (x**2 + 3*x*y + y) / (2*x*y + 3*x + 4*y + 2)

#Código principal
for x in 2, 4, 6, 8:
	for y in 1, 3, 5, 7:
print("x = {}, y = {}, (x² + 3xy + y) / (2xy + 3x + 4y +2) = {:.2f}".format(x, y, equacao(x, y)))
////////////////////////////////////////////////////////////////////////////////////////////////////////

def primo(n):
	for div in range(2, n):
		if n % div == 0:
			return False
	return True


#Código principal
A = int(input("Informe A: "))
B = int(input("Informe B: "))

print("Números primos do intervalo entre {} e {}:".format(A, B))
for i in range(A, B+1):
	if primo(i): #Chama a função que verificar se i é primo
		print(i)
///////////////////////////////////////////////////////////////////////////////////////////////////////////

'''Implemente um programa que possui uma função chamada divisao_inteira(n1, n2), sendo que a mesma deve dividir 
n1 por n2 utilizando apenas operadores de soma e subtração, retornando o resultado desta operação 
(somente parte inteira, desconsiderando o resto). Ao executar o programa, ele deve ler dois números (N1 e N2) 
e calcular sua divisão inteira através da chamada da função previamente implementada. Obs.: a função deve tratar divisão 
por 0.'''

def divisao_inteira(n1, n2):
	if n2 == 0:
		print("Divisão por 0 é inválida!")
		return 0
	
	conta = 0
	while n1 >= n2:
		conta += 1
		n1 -= n2
	return conta

N1 = int(input("Informe N1: "))
N2 = int(input("Informe N2: "))

div = divisao_inteira(N1, N2)
print("Divisão inteira de {} por {} = {}".format(N1, N2, div))
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

''em utilizar a operação de multiplicação, escreva um programa que leia dois números inteiros e
multiplique-os. Por exemplo: 2 * 4 = 2 + 2 + 2 + 2. O cálculo da multiplicação deve ser
implementado dentro de uma função.'''

def multiplicao(n1, n2):
	acum = 0
	for i in range(n2):
		acum += n1
	return acum

a = int(input())
b = int(input())

multi = multiplicao(a, b)
print("{} X {} = {}".format(a, b, multi))

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

def primo(n):
	for div in range(2, n):
		if n % div == 0:
			return False
	return True

def conta_primos(A, B):
	conta = 0
	for i in range(A, B+1):
		if primo(i): #Chama a função que verificar se i é primo
			conta += 1
	
	return conta

#Código principal
N1 = int(input("Informe N1: "))
N2 = int(input("Informe N2: "))

qtd_primos = conta_primos(N1, N2) #Chama a função que irá fazer a contagem de números primos entre N1 e N2
print("Quantidade de primos entre {} e {} = {}".format(N1, N2, qtd_primos))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

def inverte_vetor(v):
	v2 = []
	for i in range(len(v)-1, -1, -1): #percorre o vetor de traz pra frente
		v2.append(v[i])
	return v2

vetor = [2, 10, 9, 5, 3]
vetor = inverte_vetor(vetor)

print("Vetor invertido:", vetor)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

'''Faça uma função que receba dois vetores de inteiros, chamados A e B, sendo A e B com tamanho de 10 elementos. 
A função cria um novo vetor C, e coloca nele todos os valores que existem nos vetores A e B, porém em ordem crescente. 
Ex.: (assumindo que A e B possuem tamanho 3): A {20, 3, 11} e B {5, 13, 2}, a função produzirá o 
vetor C {2, 3, 5, 11, 13, 20}. O vetor C deverá ser retornado pela função e impresso no código principal do programa. 
Obs.: pode utilizar o método sort().'''

def rafa(v):
	rafa = []
	for i in range(len(v)): 
		rafa.append(v[i])
	
	return rafa
A = [20, 3, 11]  
B = [5, 13, 2]
AB = A + B
rafa(AB)
AB.sort()
print(A)
print(B)
print("Vetor invertido:", AB)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

'''Faça uma função que receba dois vetores de inteiros, chamados A e B, sendo A e B com tamanho de 10 elementos. A função
cria um novo vetor C, e coloca nele todos os valores que existem no vetor A, porém não existem no vetor B. No fim o vetor C 
deve ter 10 elementos. Caso isso não aconteça, preencha com 0 as posições até completar o vetor com os 10 elementos. 
Obs.:não utilize o método count().'''

def possuiNoVetor(n, vet):
	for i in vet:
		if i == n:
			return True
	
	return False;

def uniao(vetA, vetB):
	vetC = []
	for val in vetA: #Adiciona os elementos do vetor A
		if not possuiNoVetor(val, vetB):
			vetC.append(val)
	
	qtdFalta = 10 - len(vetC) #Adiciona 0 até o vetor possuir 10 elementos
	for i in range(qtdFalta):
		vetC.append(0)
	
	return vetC

A = [3, 4, 5, 6, 7, 8, 10, 11, 25, 45]
B = [21, 8, 25, 10, 17, 25, 9, 1, 2, 55]

C = uniao(A, B)
print(C)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#Encontre os número primos gêmeos entre 1 e 1000, usando uma função para
#verificar se o número é primo. 
'''def primo():
    valor = -10
    a = int(input())
    b = int(input())
    for num in range(a,b+1):
        primo = True
        for div in range(2,num):
            if num % div == 0:
                primo = False
                break
        if primo:
            if (num - valor == 2):
                print(valor,num)
            valor = num
primo()'''

#Faça uma função que lê cinco (5) números digitados pelo usuário e no final
#imprime esses números ordenados. Guarde os nomes em uma lista para serem
#ordenados no final.

'''def user():
    num = []
    for i in range(5):
        x = input("Informe o nome {}: ". format(i + 1))
        num.append(x)
    num.sort()
    print(num)

user()'''

#Fazer uma função que calcula o fatorial de um número passado por parâmetro.

'''def fatorial():
    n = int(input())
    f = 1
    for i in range(1,n):
        f *= n
        n -= 1
    print(f)

fatorial()'''


#numeros perfeitos
'''def perfeito():
    x = int(input())
    soma = 0
    for i in range(1,x):
        if x % i == 0:
            soma += i

    if soma == x:
        print("{} é perfeito". format(x))
    else:
        print("{} não perfeito". format(x))

perfeito()'''
/////////////////////////////////////////////////////////////////////////////////////////////////
