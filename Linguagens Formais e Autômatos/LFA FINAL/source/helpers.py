def unirEstados(automato, estados):
    # É feita a união de todos os estados do automato que estão na lista estados
    final = {} #simbolos e os estados acessíveis a partir dele, é atualizado a cada passagem pela função 
    def unir(estado):
        for e in estado:
            if e in final:
                final[e] = unirListas(final[e], estado[e])
            else:
                final.update({e: estado[e]})

    for estado in estados: # percorre os estados que precisam ser unidos, e adiciona as transições de cada simbolo para o dicionario final
        unir(automato[estado])
    return final


def unirListas(l1, l2):
    return l1 + list(set(l2) - set(l1))


def unirAutomatos(afd, afndTemp):
    mapaNovosEstados = {x: x + len(afd) for x in range(len(afndTemp))} # cria um dicionário, com as novas posições na afnd principal das regras do afnd
    aux = []

    if '&' in afd[0].keys():     # É criado uma nova regra S' que leva a regra S por epsilon transição
        afd[0]['&'].append(mapaNovosEstados[0])
    else:
        afd[0].update({'&': [mapaNovosEstados[0]]})
    
    for chave in afndTemp.keys(): #percorre os estados do afnd temporario
        for ch in afndTemp[chave].keys(): #percorre os simbolos/transições dos estados
            if ch == '*': # se for terminal, continua o loop
                continue
            aux = [] #lista auxiliar com os novos estados da afnd temporario
            for i in afndTemp[chave][ch]: # percorre os estados atingiveis pelo simbolo
                aux.append(mapaNovosEstados[i]) 
            afndTemp[chave][ch] = aux #atualiza os estados atingiveis da afnd temporaria, para os novos estados que serão criados na afnd principal
    
    for chave in afndTemp.keys():
        afd.update({mapaNovosEstados[chave] : afndTemp[chave]}) #cria os novos estados na afnd principal


def exibirAutomatoDeterministico(afnd, alfabeto):
    alfabeto.sort()
    print('     {}'.format('-----'*len(alfabeto)))
    print('     |', end='')
    for i in alfabeto:
        print('  {:2}|'.format(i), end='')
    print('\n     {}'.format('-----'*len(alfabeto)))
    for i in afnd.keys():
        if '*' in afnd[i].keys():
            print('*', end='')
        else:
            print(' ', end='')
        print('{:3}:|'.format(i), end='')
        for j in alfabeto:
            if j in afnd[i].keys():
                print(' {:2} |'.format(afnd[i][j][0]), end='')
            else:
                print(' {:2} |'.format('-'), end='')
        print('')
    print('     {}'.format('-----'*len(alfabeto)))
