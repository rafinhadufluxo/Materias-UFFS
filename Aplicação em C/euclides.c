/*Todo número racional positivo pode ser expresso de forma única como uma
fração irredutível. Escreva um programa em C que leia um número racional q na forma decimal com
exatas 3 casas decimais e imprima o mesmo número na forma de uma fração irredutível. Considere
que 0 < q 6 10 6 e que o separador das casas decimais é o ponto (.), não a vírgula (,). Imprima a fração
numa única linha, separando o numerador do denominador apenas por uma barra (/). Não se esqueça
de finalizar a linha da saída com uma quebra de linha (’\n’). Por exemplo, se seu programa ler:
14.750
deverá imprimir:
59/4        */


#include<stdio.h>

int euclides(int a, int b) {
  if (b == 0) return a;
  return euclides(b, a % b);
}

int main(void) {
  int a, b, num, den, mdc;
  scanf("%d.%d", &a, &b);
  num = a * 1000 + b; den = 1000;
  mdc = euclides(num, den);
  num /= mdc; den /= mdc;
  printf("%d/%d\n", num, den);
  return 0;
}
