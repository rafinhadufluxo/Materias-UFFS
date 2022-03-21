/*
 * Tarefa de laboratorio 08 - Avaliacao 1 - Parte 2 - Deque
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Rafa Arruda
 * Matricula: 1721101029
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
    struct Node *prev;
} node_s;


typedef struct Deque
{
    struct Node *head;
    struct Node *tail;
} deque_s;


int is_empty(deque_s *dq)
{
    return dq->head == NULL;
}

void inicializaDeque(deque_s *dq)
{
    dq->head = 0;
    dq->tail = 0;
}

void insereFimDeque(deque_s *dq, int info)
{
    node_s *aux = (node_s *)malloc(sizeof(node_s));
    aux->info = info;
    aux->next = aux->prev = NULL;
    if (is_empty(dq))
        dq->head = aux;
    else
    {
        dq->tail->next = aux;
        aux->prev = dq->tail;
    }
    dq->tail = aux;
}

void insereInicioDeque(deque_s *dq, int info)
{
    node_s *aux = (node_s *)malloc(sizeof(node_s));
    aux->info = info;
    aux->next = aux->prev = NULL;
    if (is_empty(dq))
        dq->tail = aux;
    else
        dq->head->prev = aux;
    aux->next = dq->head;
    dq->head = aux;
}

// void imprimeDireitaEsquerda(deque_s *dq)
// {

//     node_s *current = dq->head;
//     while (current != NULL)
//     {
//         printf("Informacao: %d\n", current->info);
//         current = current->next;
//     }
// }
// void imprimeEsquerdaDireita(deque_s *dq)
// {

//     node_s *current = dq->tail;
//     while (current != NULL)
//     {
//         printf("Informacao: %d\n", current->info);
//         current = current->prev;
//     }
// }

void removeInicioDeque(deque_s *dq)
{

    node_s *aux = dq->head;
    dq->head = dq->head->next;

    if (dq->head == NULL)
        dq->tail = NULL;
    else
        dq->head->prev = NULL;
    printf("%d\n", aux->info);
    free(aux);
}

void removeFimDeque(deque_s *dq)
{

    node_s *aux = dq->tail;
    dq->tail = dq->tail->prev;

    if (dq->tail == NULL)
        dq->head = NULL;
    else
        dq->tail->next = NULL;
    printf("%d\n", aux->info);
    free(aux);
}

void liberaDeque(deque_s *dq)
{
    int cont = 0;
    node_s *current = dq->tail;
    while (current != NULL)
    {
        cont++;
        current = current->prev;
    }
    printf("%d\n", cont);

    dq->tail = NULL;
    while (dq->head != NULL)
    {
        node_s *aux = dq->head;
        dq->head = dq->head->next;
        free(aux);
    }
}

int main()
{
    deque_s dq;

    int qtd, op, data;
    scanf("%d", &qtd);
    for (int i = 0; i < qtd; i++)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            inicializaDeque(&dq);
            break;
        case 2:
            scanf("%d", &data);
            insereInicioDeque(&dq, data);
            break;
        case 3:
            scanf("%d", &data);
            insereFimDeque(&dq, data);
            break;
        case 4:
            removeInicioDeque(&dq);
            break;
        case 5:
            removeFimDeque(&dq);
            break;
        case 6:
            liberaDeque(&dq);
            break;
        }
    };
}