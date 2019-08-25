valor_parc=0
valor=float(input("Digite o valor do produto: "))
parcelas=int(input("Digite a quantidade de parcelas: "))

if parcelas == 1:
    if valor >= 300 and valor <= 500:
        valor_desc= valor/100*10
        valor=valor-valor_desc
        valor_parc = valor
    elif valor > 500:
        valor_desc= valor/100*25
        valor=valor-valor_desc
        valor_parc = valor


if parcelas == 2:
    valor = valor # preço não se altera
    valor_parc = valor/2

if parcelas == 3:
        if valor <= 1100:
            valor = valor*1.10
            valor_parc = valor/3
        elif valor > 1100:
            valor = valor*1.20
            valor_parc = valor/3

if parcelas == 4:
    valor = valor # preço não se altera
    valor_parc = valor/4

elif parcelas >= 5:
    valor = valor*1.25
    valor_parc = valor/5


print("O preço final é R$", "{:3.2f}".format(valor), "parcelado em", parcelas, "vez(es) de R$", "{:3.2f}".format(valor_parc))
