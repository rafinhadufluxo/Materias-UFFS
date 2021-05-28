import binascii
frase=input("informe a frase: ")
binascii.hexlify(bytes(frase, "utf-8"))
for c in frase:
    print("".join(hex(ord(c))[2:]))
