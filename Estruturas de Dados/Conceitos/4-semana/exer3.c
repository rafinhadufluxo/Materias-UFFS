#include <stdio.h>

void ler(int N[10])
{
  int a;
  for (a = 0; a < 10; a++){
    // printf("nota %d : ", a);
    scanf("%d", &N[a]);
  }
}


void maiorMenor(int vet[10], int *maior, int *menor){
  int a;

  for (a = 0; a < 10; a++){
    if (a == 0){
      *maior = vet[a]; 
      *menor = vet[a];
    }

    if (vet[a] > *maior){
      *maior = vet[a];
    }
    else{
      if (vet[a] < *menor){
        *menor = vet[a];
      }
    }
  }
}

//INICIO DO CODIGO
int main(){
  int N[10], maior = 0, menor = 0;

  ler(N);
  maiorMenor(N, &maior, &menor);

  

  printf("\no maior valor é %d\n", maior);
  printf("\ne o menor valor é %d\n\n", menor);
  return 0;
}