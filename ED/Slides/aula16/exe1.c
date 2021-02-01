#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct elemPilha
{
    Item item;
    struct elemPilha *proximo;
} ElemPilha;

typedef struct
{
    ElemPilha *topo;
} Pilha;

void inserePilha(Pilha *pilha, Item item)
{
    ElemPilha *aux;
    // Cria um novo elemento da lista encadeada que representa a pilha e
    // armazena neste novo elemento o item a ser inserido na pilha
    aux = malloc(sizeof(ElemPilha));
    aux->item = item;
    // Insere o novo elemento no inicio da lista encadeada que representa a
    // pilha
    aux->proximo = pilha->topo;
    pilha->topo = aux;
}

void removePilha(Pilha *pilha, Item *item)
{
    ElemPilha *aux;
    // Verificar se a pilha esta vazia!
    // Armazena o item a ser removido da pilha
    *item = pilha->topo->item; // ATENCAO: Depende da definicao do tipo do item
    // Armazena o primeiro elemento da lista encadeada que representa a pilha
    // e remove este primeiro elemento da lista
    aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    // Libera a memoria alocada para o elemento removido
    free(aux);
}
void inicializaPilha(Pilha *pilha)
{
    pilha->topo = NULL;
}
int pilhaVazia(Pilha *pilha)
{
    return (pilha->topo == NULL);
}
void liberaPilha(Pilha *pilha)
{
    ElemPilha *aux;
    while (pilha->topo != NULL)
    {
        // Armazena o primeiro elemento da lista encadeada que representa a
        // pilha e remove este primeiro elemento da lista
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        // Libera a memoria alocada para o elemento removido
        free(aux);
    }
}

int main()
{
    Pilha pilha;
    Item item;
    inicializaPilha(&pilha);
    for (int i = 0; i < 10; i++)
    {
        item = i;
        printf("Inserindo na pilha o item %d.\n", item);
        inserePilha(&pilha, item);
    }

    while (pilhaVazia(&pilha) == 0)
    {
        removePilha(&pilha, &item);
        printf("Item %d removido da pilha.\n", item);
    }

    liberaPilha(&pilha); // Sem efeito se a pilha ja estiver vazia
    return 0;
}