#autor = Rafaelle Arruda
#GitHub = Mazarafa7

from math import factorial as fac

def binomial(n, x):
    try:
        binom = fac(n) // fac(x) // fac(n - x)
    except ValueError:
        binom = 0
    return binom


#Imprimir o triângulo do binômio
def pascal(m):
    for x in range(m + 1):
        print([binomial(n, x) for y in range(n + 1)])


def main():
    #input = raw_input(poderiamos usar !)
    n = int(input("Informe o valor N: "))
    x = int(input("Informe o valor X: "))
    p = int(input("Informe o valor P: "))

    #calculo de porcentagem
    q =((100 - p)/100)
    cal_p = (p /100)


    total = (((binomial(n, x)))*(cal_p**x)*(q**(n-x)))
    print("{0:.2f} %". format(float(total*100)))


#inicio do codigo
print(" === Programando a Formula binomial === ")
print("\n")
if __name__ == '__main__':
    main()
