#include <stdio.h>
#include <stdlib.h>
 
void AlterarVetor(int *vetor, int elementos)
{
    int i;
    
    if(vetor != NULL)
    {
       for(i = 0; i < elementos; i++)
       {
          *(vetor) = *(vetor) * 2; //ex: V[i] = V[i] * 2
          vetor++; //desloca o ponteiro para o próximo elemento
       } 
    }
}


int main()
{
    int v[10];
    int *p;
    int i, k;

    for(k = 0; k < 10; k++){
      // printf()
      scanf("%d", &v[k]);
    }

    p = v; //atribui o endereço do vetor
 
    AlterarVetor(p, 10);
 
    for(i = 0; i < 10; i++)// imprimindo valores multiplicados
    {
      printf("V[%d] = %d\r\n", i, *(p + i));
    }
 
    return 0;
}
 