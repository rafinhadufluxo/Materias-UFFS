#include<stdio.h>
#include<string.h>

// contando string

int main(){
   char vet[20];
   int i ;
   int num_chars;

   fgets(vet,sizeof(vet),stdin);
   vet[strcspn(vet, "\n")] = '\0';

   num_chars = 0;
   // for (i=0; i<20 && vet[i] != '\0';i++)
   for(i = 0; i < 20; i++){
      if(vet[i] == '\0'){
         break;

      }

      num_chars ++;

   }

   printf("numeros de caracteres sao %d\n", num_chars);
   
   return 0;
}