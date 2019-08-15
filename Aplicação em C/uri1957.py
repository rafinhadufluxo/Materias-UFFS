# -*- coding: utf-8 -*-

#questão 1957
n = int(input())
r = []

while n > 0:
    r.append(n % 16)
    n = n // 16

for i in range(len(r)-1,-1,-1):
    print("%X"%r[i],end="")
print()