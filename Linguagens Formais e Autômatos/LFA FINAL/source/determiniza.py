from .helpers import *


def eliminarEpsilonTransicoes(afnd):
    epsilon = []

    for chave in afnd.keys(): #mapeia os estados que possuem epsilon transição
        if '&' in afnd[chave]:
            epsilon.append(chave)

    def copiarRegras(regras, nRegra):  # Recursivamente copia regras que são acessadas por uma epsilon transição
        if nRegra not in epsilon:
            return  # Caso não tenha epsilon transições na regra
        
        epsilon.remove(nRegra) 
        
        for regra in regras['&']: #percorre os estados que são acessíveis por epsilon transição
            chaves = afnd[regra].keys() #salva os simbolos dos estados atingidos por epsilon transição
            
            if '&' in chaves: #caso os estados atingidos tenham epsilon transição, remove recursivamente
                copiarRegras(afnd[regra], regra)
                regras['&'] = unirListas(regras['&'], afnd[regra]['&'])
        
        # une as transições de cada simbolo dos estados atingidos por epsilon transição, com as regras do estado que tem epsilon transição
        afnd[nRegra] = unirEstados(afnd, regras['&'] + [nRegra]) 

    epAux = epsilon.copy()
    
    for ep in epAux:
        copiarRegras(afnd[ep], ep) #copia as regras dos estados atingidos por epsilon transição, para o estado que tinha epsilon transição
    
    for ep in epAux:
        del afnd[ep]['&'] #apaga as regras dos estados que tenham epsilon transição


def determinizar(afnd):
    mpRgs = {}
    visitados = set()

    def determiniza(regra, nReg):  # Recursivamente determiniza o automato
        if nReg in visitados: 
            return
        visitados.add(nReg) 
        chaves = list(regra.keys()) 

        for chave in chaves:
            if len(regra[chave]) > 1: #se a regra tiver mais que uma transição
                regra[chave].sort()
                nRg = str(regra[chave])  # É gerada uma nova regra que será mapeada no mpReg
                
                if nRg not in mpRgs.keys(): 
                    nEst = len(afnd)  # Novo estado que será mapeado pela variavel nRg
                    mpRgs.update({nRg: nEst})
                    afnd.update({len(afnd): unirEstados(afnd, regra[chave])})
                    determiniza(afnd[nEst], nEst) # determiniza os novos estados criados
                
                regra.update({chave: [mpRgs[nRg]]}) # atualiza a regra que tinha mais que uma transição, para o novo estado criado

    i, t = 0, len(afnd)
    while i < t:
        determiniza(afnd[i], i)
        i, t = i + 1, len(afnd)  # Cada nova regra criada também deve ser determinizada
