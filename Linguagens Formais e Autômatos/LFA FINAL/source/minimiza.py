from .helpers import *

def eliminarInalcancaveis(afnd):
    visitados = set()

    def elimina(regra, estado):        # Utiliza uma dfs para remover recursivamente
        if estado in visitados:
            return
        
        visitados.add(estado)
        
        for chave in regra.keys():
            if chave == '*':
                continue
            for i in regra[chave]:
                elimina(afnd[i], i)

    elimina(afnd[0], 0)
    x = len(afnd)

    for i in range(x):
        if i not in visitados:      # Após a dfs estados não visitados são eliminados
            del afnd[i]


def eliminarInuteis(afnd):
    visitados = set()
    uteis = set()
    
    for rg in afnd:
        if '*' in afnd[rg].keys():
            uteis.add(rg)
    
    def elimina(regra, nRegra):     # Utiliza uma dfs para encontrar os estados inuteis
        if nRegra in uteis:
            return True
        
        visitados.add(nRegra)
        
        for chave in regra.keys():
            for rg in regra[chave]:
                if rg not in visitados:
                    if elimina(afnd[rg], rg):
                        return True
        return False

    aux = list(afnd.keys())
    
    for regra in aux:
        if elimina(afnd[regra], regra):
            uteis.add(regra)
        visitados = set()
    
    for regra in aux:
        if regra not in uteis:      # Após a dfs estados que não estão em uteis são eliminados
            del afnd[regra]
    
    for regra in afnd.keys():       # Transições para estados não uteis também são eliminados
        aux = list(afnd[regra].keys())
        for chave in aux:
            if chave == '*':
                continue
            
            for rg in afnd[regra][chave]:
                if rg not in uteis:
                    del afnd[regra][chave]
