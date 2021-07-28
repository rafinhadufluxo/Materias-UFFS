# NOME = Rafaelle Arruda

print("======================")
print("= BANCO TOMORROWLAND = ")
print("======================")
# define uma lista com 5 elementos para guardar a quant., das cédulas de 100 a 5
qtd_cedulas = [0]*5
cedulas = [100, 50, 20, 10, 5]

saldo = int(input("Informe o saldo do cofre: "))
while(saldo < 0):
    saldo = int(input("Saldo não pode ser negativo!\nInforme o saldo do cofre: "))
while True:
    valor = int(input("Informe o valor do saque: "))
    while(valor > saldo):
      valor = int(input("\nNão é possível sacar este valor!"+
                        "\nInforme o valor do saque: "))
    # encerra o loop principal caso o valor de saque seja negativo ou zero
    if(valor <= 0):
        break
    # guarda o valor em uma variavel auxiliar
    valor_tmp = valor

    # varre a lista cedulas e vai calculando a quantidade necessaria de cada cedula,
    # enquanto diminui o valor, começando sempre da maior cedula possível.
    # A função len, retorna o valor de uma string.
    i = 0
    while i < len(cedulas):
        if valor_tmp > 0  and valor_tmp >= cedulas[i]:
            # conta a quantidade de cedulas usando divisão
            qtd_cedulas[i] = int(valor_tmp/cedulas[i])
            #atualiza o valor subtraindo a quantia de cedulas já contadas
            valor_tmp -= qtd_cedulas[i]*cedulas[i]
        else:
            # caso a cedula seja maior que o valor atual ou ele seja zero
            # a quantidade dessa cedula é zerada
            qtd_cedulas[i] = 0

        i+=1


    # garante que que todo o valor foi pago com as cedulas, caso contrario
    # não é possível sacar o valor por falta de cedulas
    if valor_tmp == 0:
        print("\nNotas sacadas: \n")

        # formata a saída das cedulas
        i = 0
        while i < len( qtd_cedulas):
            if qtd_cedulas[i] > 0:
                print('R$ ', cedulas[i], ' - ', qtd_cedulas[i])

            i+=1
        # atualiza o saldo
        saldo -= valor
        print("\nValor restante no cofre: R$ \n", saldo)
    else:
        print("\nNão é possível sacar este valor!\n")
print("")
print("Encerrando BANCO PYTHON BR")
#quando zerar o saldo do cofre, informe 0 para encerrar o programa.
