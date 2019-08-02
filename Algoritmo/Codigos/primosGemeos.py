valor = -10
a = int(input())
b = int(input())
for num in range(a,b+1):
    primo = True
    for div in range(2,num):
        if num%div == 0:
            primo = False
            break
    if primo:
        if(num-valor == 2):
            print(valor,num)
        valor = num
