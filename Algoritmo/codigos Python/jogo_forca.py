'''Desenvolva um jogo da forca. O programa terá uma lista de palavras lidas de um arquivo texto e escolherá uma aleatoriamente. 
O jogador poderá errar 6 vezes antes de ser enforcado.
     Digite uma letra: A
     -> Você errou pela 1ª vez. Tente de novo!
     Digite uma letra: O
          A palavra é: _ _ _ _ O'''

palavra = input("Digite a palavra secreta:").lower().strip()
for x in range(100):
     print()
digitadas = []
acertos = []
erros = 0
for i in range(7):# ele não vai até o 7, contando. Ele irá apenas até 6
     senha = ""
     for letra in palavra:
         senha += letra if letra in acertos else "."
     print(senha)
     if senha == palavra:
         print("Você acertou!")
         break
     tentativa = input("\nDigite uma letra:").lower().strip()
     if tentativa in digitadas:
         print("Você já tentou esta letra!")
         continue
     else:
         digitadas += tentativa
         if tentativa in palavra:
               acertos += tentativa
         else:
               erros += 1
               print("Você errou!")
     print("X==:==\nX  :   ")
     print("X  O   " if erros >= 1 else "X")
     linha2 = ""
     if erros == 2:
         linha2 = "  |   "
     elif erros == 3:
         linha2 = " \|   "
     elif erros >= 4:
         linha2 = " \|/ "
     print("X%s" % linha2)
     linha3 = ""
     if erros == 5:
         linha3 += " /     "
     elif erros >= 6:
         linha3 += " / \ "
     print("X%s" % linha3)
     print("X\n===========")
     if erros == 6:
         print("Enforcado!")
         break
