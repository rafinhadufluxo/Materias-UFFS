/*Escreva um programa em C que lê da entrada padrão um inteiro n (1 6 n 6
10 6 ) seguido de n linhas, contendo cada uma uma cadeia de caracteres, e imprime as mesmas linhas
lidas, mas trocando as vogais:

exemplo de entrada:
3
rafa
arruda
linda

exemplo de saida:
r4f4
4rrvd4
l1nd4    */

#include<stdio.h>

#define MAX 1123456

int main(void) {
  int n, i;
  char str[MAX];
  scanf("%d\n", &n);
  while (n--) {
    fgets(str, MAX, stdin);
    for (i = 0; str[i] != '\n'; i++)
      switch(str[i]) {
      case 'a': case'A': str[i] = '4'; break;
      case 'e': case'E': str[i] = '3'; break;
      case 'i': case'I': str[i] = '1'; break;
      case 'o': case'O': str[i] = '0'; break;
      case 'u': case'U': str[i] = 'v'; break;
      }
    printf("%s", str);
  }
  return 0;
}

  
