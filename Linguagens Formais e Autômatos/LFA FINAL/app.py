from source.afnd import *
from source.minimiza import *
from source.determiniza import *
from source.helpers import *

afd = {}
alfabeto = []
gramatica = []

entrada = open("entrada.txt", "r") #abre o arquivo de entrada
entradaString = entrada.read() #salva em uma string o conteudo do arquivo de entrada
entradaLista = entradaString.split('\n') #quebra a string em uma lista, usando a quebra de linha como separador

#para separar os tokens da gramática, é usado uma linha vazia, que também serve para identificar duas gramáticas diferentes e o fim do arquivo

listaAuxiliar = entradaLista.copy() #faz uma cópia da lista para podermos trabalhar com ela, removendo cada posição lida

for tokenLido in listaAuxiliar:
    if not tokenLido: #terminou de ler os tokens
        entradaLista.remove(tokenLido) #remove da lista de entrada
        break 
    gerarAfndToken(afd, tokenLido, alfabeto) #adiciona ao afnd as regras de produção para o token lido
    entradaLista.remove(tokenLido) #remove da lista de entrada
    # print(tokenLido) if e else//

listaAuxiliar = entradaLista.copy() #agora na lista de entrada, temos apenas as gramáticas para serem lidas

while entradaLista:
    for regraGramaticaLida in listaAuxiliar:    
        if not regraGramaticaLida: #após ler todas as regras da gramática, une as regras da gramática com as dos tokens
            gerarAfndGramatica(afd, gramatica, alfabeto) 
            gramatica.clear() 
            entradaLista.remove(regraGramaticaLida)
        else:
            gramatica.append(regraGramaticaLida) 
            entradaLista.remove(regraGramaticaLida)

eliminarEpsilonTransicoes(afd)
determinizar(afd)
print('Automato finito deterministico:')
exibirAutomatoDeterministico(afd, alfabeto)
eliminarInalcancaveis(afd)
print('\n Após eliminar inalcançáveis:')
exibirAutomatoDeterministico(afd, alfabeto)
eliminarInuteis(afd)
print('\n Após eliminar inúteis:')
exibirAutomatoDeterministico(afd, alfabeto)