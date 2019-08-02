class dado ():
    nomepais = ''
    numvitoria = 0
    numempate = 0
    
def campeonato():
    p = dado()
    p.nomepais = input("informe o pais: ")
    p.numvitoria = int(input("Numero de vitoria: "))
    p.numempate = int(input("Numero de empate: "))
    print()
    return p

def med (paises,n):
    media = 0
    soma = 0
    for i in paises:
        soma += i.numvitoria
    media = soma /n
    return media

def imprimi(paises,media):
    for j in paises:
        if j.numvitoria > media:
            print("PAIS: ", j.nomepais)
            print("VITORIAS: ",j.numvitoria)
            print("EMPATE: ", j.numempate )

    
paises = []
rafa = paises
n = int(input())
for i in range(n):
    paises.append(campeonato())

media = med (paises,n)

imprimi(paises,media)
##############################################################################################################
'''class dados():
    nome = ''
    cpf = 0
    idade = 0
    nasc = 0
    rua = ''
    bairro = ''
    cidade = ''
    estado = ''

def pessoa():
    p = dados()
    p.nome = input("Informe o nome: ")
    p.cpf = int(input("Informe o CPF: "))
    p.idade = int(input("Informe a idade: "))
    p.nasc = int(input("Infome o nascimento: "))
    p.rua = input("Informe a rua: ")
    p.bairro = input("Informe o bairro: ")
    p.cidade = input("informe a cidade: ")
    p.estado = input("Informe o estado: ")
    print()
    return p

def imprimir(pessoas):
    for j in pessoas:
        print("NOME: ", j.nome)
        print("CPF: ", j.cpf)
        print("IDADE: ", j.idade)
        print("NASC: ", j.nasc)
        print("RUA: ", j.rua)
        print("BAIRR0: ", j.bairro)
        print("CIDADE: ", j.cidade)
        print("ESTADO: ", j.estado)
        print()

#codigo principal
pessoas = []
n = int(input("Informe o N: "))
for i in range(n):
    pessoas.append(pessoa())

imprimir(pessoas)'''

###############################################################################################################################
class Estadio:
    nome = ''
    capacidadepublico = 0
    recordpublico = 0

def ler_estadio():
    estadios = []
    for c in range (5):
        est = Estadio()
        print()
        est.nome = input("Informe o nome: ")
        est.capacidadepublico = int(input("Informe a capacidade: "))
        est.recordpublico = int(input("Informe o record: "))
        estadios.append(est)
        
    return estadios


def maior_capacidade (estadios):
    maiorEstado = Estadio ()
    for est in estadios:
        if est.capacidadepublico > maiorEstadio.capacidadepublico:
            maiorEstadio = est
    return maiorEstadio

def maior_publico (listat):
    maiorPublico = lista_est[0]
    for i in range(1,len(lista_est)):
        if lista_est[i].recordpublico > maiorPublico.recordpublico:
            maiorPublico = lista_est [i]
    return maiorPublico
            
def imprimi_estadio(est):
    print("Nome:", maiorCap.nome)
    print("Capacidade: ", maiorCap.capacidadepublico)
    print("Record: ", maiorCap.recordpublico)
    
#codigo principal
lista = ler_estadio()
maiorCap = maior_capacidade(lista)
maiorPub = maior_publico (lista)

print("\n Maior Estadio:")
imprimi_estadio(maiorCap)

print("\n Maior Publico:")
imprimi_estadio(maiorPub)


##################################################################################################################################
'''Crie uma função, sem retorno, que recebe como parâmetros uma struct com duas informações: idade e ano de nascimento de um
indivíduo. A função tem como objetivo verificar se a idade está atualizada a partir do ano de nascimento. Ou seja, a cada ano a
função deve ser executada para atualizar a idade dos indivíduos. A função deve calcular, a idade atual do indivíduo, imprimir esse
valor e alterar a variável da struct idade criada no programa principal.'''

class dado():
  nome = ''
  idade = 0
  nascimento = 0

def verifica_idade(idade, nasc):
  x = int(input("Informe o ano atual: "))
  soma = x - nasc
  if soma == idade:
    print("Idade e nascimento, corretos")
  else:
    print("Não está correto as informaçoes de idade e nasc")

nome = input("INFORME O NOME: ")
idade = int(input("INFORME A IDADE: "))
nasc = int(input("INFORME O NASCIMENTO: "))

verifica_idade(idade,nasc)


'''Faça um programa que possua uma estrutura Carro com os atributos: modelo, marca e ano de fabricação. Após, leia os valores para 
os 3 carros em uma função, retornando a lista com os 3 carros para o código principal.'''

class dado():
  nome = ''
  modelo = ''
  marca = ''
  ano = ''

def carro():
  car = dado()
  car.nome = input("INFORME O NOME: ")
  car.modelo = input("INFORME O MODELO: ")
  car.marca = input("INFORME A MARCA : ")
  car.ano = input("INFORME O ANO DA FAB: ")
  print()
  return car

def imprimi(carros):
  for i in carros:
    print("PROPRIETARIO: ", i.nome)
    print("MODELO: ", i.modelo)
    print("MARCA: ", i.marca)
    print("ANO DE FAB: ", i.ano)
    print()

carros = []
for i in range(3):
  carros.append(carro())#vai chamar a função e guardar suas informações num vetor.

imprimi(carros)#chamando a função pra imprimir a lista
################################################################################################################################

'''Um aluno de uma turma pode ser representado pelos seguintes dados: matrícula, nota 1 e nota 2. Faça um programa que leia 5 alunos, 
guardando seus dados em uma estrutura. Após ler cada aluno, chame a função media_aluno(aluno), sendo que ela recebe uma variável do 
tipo estrutura aluno e retorna a sua média ((nota 1+nota 2)/2), que deve ser impressa no código principal.'''

class Data: #Estrutura Data
	Matricula = 0
	nota1 = 0
	nota2 = 0

def media_aluno(aluno):
	return (aluno.n1 + aluno.n2) / 2
	

alunos = []
for c in range(2):
	aluno = Data()
	aluno.matricula = int(input("Informe o numero de matricula: "))
	aluno.n1 = float(input("Informe o N1: "))
	aluno.n2 = float(input("Informe o N1: "))
	alunos.append(aluno)
	
	media = media_aluno(aluno)
	print("O aluno {} possui média {:.2f}".format(aluno.matricula, media))
	print()
 /////////////////////////////////////////////////////////////////////////////////
 
 '''Faça um programa que leia os dados de 5 bandas de música (estrutura composta pelo nome da
banda, estilo musical e número de integrantes), armazenando-as em uma lista. Depois, leia um
número de 1 a 5, que corresponde a uma das bandas previamente lidas. A partir deste número,
imprima os dados da banda solicitada.'''

class Banda: #Estrutura 
	nome = ''
	estilo = ''
	integrantes = 0

bandas = []
for c in range(5):
	rafa = Banda()
	rafa.x = input("Nome da Banda: ")
	rafa.music = input("Informe o estilo musical: ")
	rafa.integ = int(input('Inform o numero de integrantes: '))
	bandas.append(rafa)
	print()


num = int(input("Informe um número de 1 a 5: "))	
selecao = bandas[num-1]

print()
print("Nome da banda:", selecao.nome)
print("Estilo da banda:", selecao.estilo)
print("Integrantes da banda:", selecao.integrantes)
/////////////////////////////////////////////////////////////////////////////////////////////

class Aluno:
	matricula = 0
	n1 = 0.0
	n2 = 0.0
	n3 = 0.0

def le_aluno():
	aluno = Aluno()
	aluno.matricula = int(input("Informe matrícula do aluno: "))
	aluno.n1 = float(input("Informe a nota 1 do aluno: "))
	aluno.n2 = float(input("Informe a nota 2 do aluno: "))
	aluno.n3 = float(input("Informe a nota 3 do aluno: "))
	return aluno

def imprime_turma(turma):
	for aluno in turma:
		print("\nAluno: ", aluno.matricula)
		print("Notas:", aluno.n1, aluno.n2, aluno.n3)

def calcula_media_aluno(aluno):
	soma = aluno.n1 + aluno.n2 + aluno.n3
	return soma / 3


#Código principal...
turma = []
for i in range(5):
	turma.append( le_aluno() ) #Função que lê a matrícula e 3 notas de um aluno, retornando-o
   
imprime_turma(turma) #Função que imprime os dados de todos os alunos
 
print()
for i in range(5):
	media = calcula_media_aluno(turma[i]) #Função que calcula e retorna média de um aluno
	print("Aluno: {} - Média: {:.1f}".format(turma[i].matricula, media))
//////////////////////////////////////////////////////////////////////////////////////////////////
#inverte nome
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

////////////////////////////////////////////////////////////////////////////////////////////////

class dado():
    nome = ''
    idade = 0
    salario = 0.0

def fun(n):
    p = dado ()
    
    p.nome = input("informe o nome: ")
    p.idade = int(input("informe a idade: "))
    p.salario = float(input("Informe o salario: "))
    print()
    return p

def med(funcionario,n):
    media = 0
    soma = 0
    for i in funcionario:
        soma += i.salario
    media = soma/n
    return media
        
def imprimi(funcionario,media):
    for i in funcionario:
        if i.salario > media:
            print("NOME:", i.nome)
            print("IDADE: ", i.idade)
            print("SALARIO: ", i.salario)
            print("\n")

n = int(input("Informe a quantidade de funcionario:" ))
funcionario = []
for c in range(n):
    funcionario.append(fun(n))

media = med(funcionario,n)
imprimi(funcionario,media)

