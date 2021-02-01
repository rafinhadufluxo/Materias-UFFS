#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define I_INFINITY 9999

typedef struct val
{
    int valor;
    struct val *proximo;
    struct val *anterior;
} ListaInt;

void menorValorLista(ListaInt *head)
{
    int maior = head->valor;
    ListaInt *aux = head;
    while (aux != NULL)
    {
        if (aux->valor < maior)
        {
            maior = aux->valor;
        }
        aux = aux->proximo;
    }
    printf("----------\n");
    printf("\nMenor valor da lista: %d", maior);
}

void trocaMaiorElemento(ListaInt *head)
{
    int maiorElemento = -I_INFINITY;
    int auxTroca;
    ListaInt *enderecoMaior, *tail, *aux;
    aux = head;
    while (aux != NULL)
    {
        if (aux->valor > maiorElemento)
        {
            maiorElemento = aux->valor;
            enderecoMaior = aux;
        }
        if (aux->proximo == NULL)
        {
            tail = aux;
        }
        aux = aux->proximo;
    }
    auxTroca = tail->valor;
    tail->valor = enderecoMaior->valor;
    enderecoMaior->valor = auxTroca;
}

int main()
{
    int n;
    ListaInt *head = NULL, *tail, *aux, *anterior;

    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        aux = malloc(sizeof(ListaInt));
        scanf("%d", &aux->valor);
        aux->proximo = NULL;
        aux->anterior = NULL;
        if (head == NULL)
        {
            tail = aux;
            head = aux;
        }
        else
        {
            aux->anterior = tail;
            tail->proximo = aux;
            tail = aux;
        }
    }

    menorValorLista(head); // procura o menor valores
    printf("\n");

    trocaMaiorElemento(head); // procura o maior elemento e coloca no final da lista
    printf("----------\n");
    aux = head;
    while (aux != NULL)
    {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }

    // Limpa a lista
    while (head != NULL)
    {
        anterior = head;
        head = head->proximo;
        free(anterior);
    }

    return 0;
}