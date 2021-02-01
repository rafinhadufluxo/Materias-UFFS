#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct num
{
    int valor;
    struct num *proximo;

} ListaInt;

ListaInt *constroiLista(int n, int *v)
{
    ListaInt *primeiro = NULL, *aux;

    int i;
    for (i = n - 1; i >= 0; i--)
    {
        aux = malloc(sizeof(ListaInt));
        aux->valor = v[i];
        aux->proximo = primeiro;
        primeiro = aux;
    }
    return primeiro;
}

int imprimeLista(ListaInt *primeiro)
{
    ListaInt *aux;
    for (aux = primeiro; aux != NULL; aux = aux->proximo)
    {
        printf(" %d ", aux->valor);
    }
    printf("\n");
}

int main()
{
    int vetor[4] = {1, 21, 4, 6};
    ListaInt *primeiro, *aux;

    primeiro = constroiLista(4, vetor);

    imprimeLista(primeiro);

    return 0;
}