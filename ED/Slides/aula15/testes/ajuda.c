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
    if (head != NULL) // É sempre bom checar se o ponteiro não veio nulo para evitar acessar valores inválidos
    {
    // int menor = +I_INFINITY; // Por se tratar do menor valor, podemos usar outra abordagem
    int menor = head->valor; // Podemos usar o primeiro valor da lista como o menor

    int auxTroca;
    ListaInt *aux = head->proximo; // Como usei o valor do primeiro elemento, eu posso começar do segundo
    ListaInt *tail; //*enderecoMaior; // Como irei procurar o menor elemento na lista, alterei o nome da variável para melhor compreensão
    ListaInt *enderecoMenor = head;

  	// print("Menor da Lista antes do loop"); // Nome incorreto da função
    // printf("Menor da Lista antes do loop");

    while (aux != NULL)
    {
        if (aux->valor < menor)
        {
            menor = aux->valor;
            enderecoMenor = aux;
        }
        aux = aux->proximo;
    }

    // auxTroca = tail->valor;
    /*
    tail->valor = enderecoMaior->valor; // Aqui está seu erro! Neste ponto da função a variável enderecoMaior não foi inicializada nem alterada
                                        // Ou seja, seu valor é lixo da memória, resultando em erro quando tentamos acessar
    */

    // Lógica para inverter o menor valor com o primeiro
    auxTroca = head->valor;
    head->valor = enderecoMenor->valor;
    enderecoMenor->valor = auxTroca;

    // printf("----------\n");
    // printf("\nMenor valor da lista: %d", menor);
    }
    
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
    // aux = head;
    // while (aux != NULL)
    // {
    //     printf("%d\n", aux->valor);
    //     aux = aux->proximo;
    // }
    // printf("\n");

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