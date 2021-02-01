#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct val
{
    int valor;
    struct val *proximo;
    struct val *anterior;
} ListaInt;

void maiorValorLista(ListaInt *head)
{
    int maior = head->valor;
    int menor = head->valor;
    ListaInt *aux = head;
    while (aux != NULL)
    {
        if (aux->valor > maior)
        {
            maior = aux->valor;
        }
        else if(aux->valor < menor){ 

                menor = aux->valor;
        }
        aux = aux->proximo;
    }
    printf("Maior valor da lista: %d\n", maior);
    printf("Menor valor da lista: %d\n", menor);
}

double mediaValoresLista(ListaInt *head)
{
    double soma = 0;
    int contador = 0;
    ListaInt *aux = head;
    while (aux != NULL)
    {
        soma = soma + aux->valor;
        contador++;
        aux = aux->proximo;
    }
    return (soma / contador);
}

ListaInt *copiaLista(ListaInt *tail)
{
    ListaInt *copiaTail = NULL, *copiaHead, *copiaAux, *aux;
    aux = tail;
    while (aux != NULL)
    {
        copiaAux = malloc(sizeof(ListaInt));
        copiaAux->valor = aux->valor;
        if (copiaTail == NULL)
        {
            copiaTail = copiaAux;
            copiaHead = copiaAux;
        }
        else
        {
            copiaAux->proximo = copiaHead;
            copiaHead->anterior = copiaAux;
            copiaHead = copiaAux;
        }
        aux = aux->anterior;
    }
    return copiaHead;
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

    maiorValorLista(head);

    printf("Media da lista: %.2lf\n", mediaValoresLista(head));

    // Limpa a lista
    while (head != NULL)
    {
        anterior = head;
        head = head->proximo;
        free(anterior);
    }

    return 0;
}