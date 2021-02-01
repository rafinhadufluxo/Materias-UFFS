#include <stdio.h>
#include <string.h>

int main()
{
    int vet[6];
    int par[6]; 
    int i,j;

    for (i = 0; i < 6; i++)
    {
       //lendo os valores 1 à 6
        scanf("%d", &vet[i]);

        // verifica se é par
        if(vet[i]%2 == 0){
           par[i] = vet[i];
        }
    }

    for ( j = 0; j < 6; j++)
    {
        if(par[j] != '\0'){

            printf("numero par %d\n", par[j]);
        }
       
    }
    
}