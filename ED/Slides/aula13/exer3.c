#include <stdio.h>
#include <stdlib.h>

typedef struct num
{
    int valor ;
    struct num *proximo;
    
    
} ListaInt;


ListaInt *constroiLista(int n, int *v){
    ListaInt *primeiro= NULL, *aux ;

    int i;
    for(i= n-1; i>= 0; i--){
        aux = malloc(sizeof(ListaInt));
        aux-> valor = v[i];
        aux-> proximo = primeiro;
        primeiro = aux;
    }
    return primeiro;

}

int main(){
    int vetor [5] = {1,2,3,4,5};
    ListaInt *primeiro, *aux;

    primeiro = constroiLista(5, vetor);

    for (aux = primeiro; aux != NULL; aux = aux->proximo)
    {
       printf("%d," ,aux->valor);
    }
    
    return 0;
}