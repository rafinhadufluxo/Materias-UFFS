valor = int(input("Digite o valor: "))
a= 0 
b= 1
print("{} {}". format(a,b), end='')
cont = 3
while cont <= valor:
    c = a + b
    print(" {}". format(c),end='')
    a = b
    b = c
    cont+=1

print(" FIM")
