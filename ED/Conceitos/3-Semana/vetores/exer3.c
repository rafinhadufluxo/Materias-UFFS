#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, maior=0, menor=0;
    int N[5];

    printf("digite 5 numeros");
    printf("\n");

    for (a=0;a<5;a++){
      
      printf("nota %d : ", a);
      scanf("%d", &N[a]);

      if(a==0){

        maior=N[a];
        menor=N[a];

      }
      if(N[a]>maior){
        maior=N[a];
      }
      else{
        if(N[a]<menor){
            menor=N[a];
        }
      }
    }

    printf("\no maior valor é %d\n", maior);
    printf("\ne o menor valor é %d\n\n", menor);

    return 0;
}