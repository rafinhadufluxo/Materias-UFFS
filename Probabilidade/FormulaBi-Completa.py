#Formula Binomial Completa, tendo calculo binomial e acumulativa

from math import factorial


def fact(n, x):
    return factorial(n)//(factorial(n-x)*factorial(x))

def binomial(n, x, p):
    q = 1 - p
    fatorialC = fact(n, x) #fatorial de combinaçaõ da N E X
    return fatorialC*(p ** x)*(q ** (n-x))

def binomial_acc(n, x, p): #calculo da acumulada
    i = 0
    acc = 0
    while (i <= x):
        acc += binomial(n, i, p) #chama a funcao  de binomial
        i += 1
    return acc

def main():
    n = int(input("Informe n: "))
    x = int(input("Informe x: "))
    pp = int(input("Informe p: "))

    p = (pp /100)

    #calculo da Formula
    proba = binomial_acc(n,x,p) #chamando a funcao
    rafa = binomial(n,x,p) #chamando a funcao
    print("\n")
    print(" A probabilidade Acumulativa é:  {:.4f}".format(proba))
    print(" Distruibuição Binomial é : {:.4f} \n". format(rafa))

print(" === Programando a Formula binomial === ")
print("\n")
if __name__ == '__main__':
    main()
