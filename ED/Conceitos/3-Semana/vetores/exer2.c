#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, j,num[6];
   printf("Digite 6 numeros inteiros.\n");

   for(i=1; i<=5; i++) {
    printf("Digite o %d valor: ", i);
    scanf("%d", &num[i]);
   }

   printf("Resultado:\n");
   for(j=1; j<=5; j++) {
    printf("%d\n", num[j]);
   }
   return 0;
}