from re import findall as find, match, split #biblioteca de expressões regulares
from .helpers import *

def gerarAfndToken(afnd, token, alfabeto):
    if not afnd:
        afnd.update({len(afnd): {}}) #gera o afnd com o index == (tamanho atual da afnd = 0, 1, 2, 3 -- Criando assim as regras), transição 0 é a inicial
    
    tokenInicial = True #primeiro caracter inicial, o que vai guiar para as próximas regras
    
    for tk in token: # percorre a string do token 
        if tk not in alfabeto: # se o caracter ainda não estiver no alfabeto aceito
            alfabeto.append(tk) # adiciona no alfabeto da linguagem
        
        if tokenInicial:   # Token inicial vai para o primeiro estado do automato
            mapeado = afnd[0] # 'ponteiro' para o estado inicial

            if tk in mapeado.keys():
                mapeado[tk].append(len(afnd)) #caso já exista uma regra com esse simbolo, adiciona uma transição para um novo estado para essa regra
            else:
                mapeado.update({tk : [len(afnd)]})
            tokenInicial = False
        else:
            afnd.update({len(afnd) : {tk: [len(afnd) + 1]}}) # cria um novo estado, que irá levar para o próximo a partir do simbolo
    
    afnd.update({len(afnd) : {'*': [1]}}) # quando chega ao final do token, o novo estado criado é final

def gerarAfndGramatica(afnd, gramatica, alfabeto):
    if not afnd: #se não tiver palavras reservadas, cria o afnd
        afnd.update({0: {}})
    
    afndTemporario = {}
    mapaRegras = {}
    
    for regra in gramatica: #percorre as produções da gramática
        simbolos = find(r'(\w*<\w+>|\w+|&)', regra) # quebra em regra e suas produções
        
        if simbolos[0] in mapaRegras.keys():     # Verifica se a regra já foi criada
            indiceRegra = mapaRegras[simbolos[0]] 
        else:
            indiceRegra = len(afndTemporario) #indice da regra
            afndTemporario.update({indiceRegra : {}}) #cria um novo estado do automato temporario
            mapaRegras.update({simbolos[0]: indiceRegra}) #mapeia a regra, relacionando-a com o indice do novo estado criado no automato

        for simbolo in simbolos[1:]: #percorre as produções da regra
            terminal = find(r'^\w+', simbolo) 
            naoTerminal = find(r'<\w+>', simbolo) 
            terminal = '&' if not terminal else terminal[0] #caso nao ache simbolo terminal, cria um epsilon transição

            if terminal not in alfabeto: #caso o caracter nao esteja no alfabeto
                alfabeto.append(terminal) #adiciona ao alfabeto da gramática

            if not naoTerminal:       # produção sem não terminal, gera uma regra que tem transição para um estado terminal
                rg = afndTemporario[indiceRegra] #ponteiro para o estado correspondente a regra sendo lida

                if terminal in rg.keys(): #se ja existir esse terminal no estado
                    rg[terminal].append(len(afndTemporario)) #acrescenta nova transição no simbolo
                else:
                    rg.update({terminal : [len(afndTemporario)]}) #cria um novo simbolo no estado

                afndTemporario.update({len(afndTemporario): {'*':[1]}}) #cria um novo estado/regra terminal
            else:
                naoTerminal = naoTerminal[0]

                if naoTerminal in mapaRegras.keys(): #caso a regra ja tenha sido mapeada
                    rg = mapaRegras[naoTerminal] #armazena o indice do estado do automato correspondente a regra lida
                else: # se nao estiver mapeada, cria um novo estado no automato
                    rg = len(afndTemporario) #indice do novo estado
                    mapaRegras.update({naoTerminal: rg}) #mapeia a regra, relacionando-a com o indice do novo estado criado no automato
                    afndTemporario.update({rg: {}}) #cria um novo estado do automato temporario
                
                mp = afndTemporario[indiceRegra] #ponteiro para o estado do automato corresponde a regra sendo lida
                
                if terminal in mp.keys(): #caso o simbolo ja esteja no estado do automato
                    mp[terminal].append(rg) #cria a transição para o estado do referente ao nao terminal
                else:
                    mp.update({terminal: [rg]}) #acrescenta mais uma transição para o simbolo ja existente

    unirAutomatos(afnd, afndTemporario)
