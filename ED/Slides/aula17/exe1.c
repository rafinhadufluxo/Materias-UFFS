#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct elemFila
{
    Item item;
    struct elemFila *proximo;
} ElemFila;

typedef struct
{
    ElemFila *primeiro;
    ElemFila *ultimo;
} Fila;

void liberaFila(Fila *fila)
{
    ElemFila *aux;
    while (fila->primeiro != NULL)
    {
        // Armazena o primeiro elemento da lista encadeada que representa a
        // fila e remove este primeiro elemento da lista
        aux = fila->primeiro;
        fila->primeiro = fila->primeiro->proximo;
        // Libera a memoria alocada para o elemento removido
        free(aux);
    }
    fila->ultimo = NULL;
}

int filaVazia(Fila *fila)
{
    return (fila->primeiro == NULL);
}

void inicializaFila(Fila *fila)
{
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

void removeFila(Fila *fila, Item *item)
{
    ElemFila *aux;
    // Verificar se a fila esta vazia!
    // Armazena o item a ser removido da fila
    *item = fila->primeiro->item;
    aux = fila->primeiro;
    if (fila->primeiro == fila->ultimo)
    {
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }
    else
    {
        fila->primeiro = fila->primeiro->proximo;
    }
    // Libera a memoria alocada para o elemento removido
    free(aux);
}

void insereFila(Fila *fila, Item item)
{
    ElemFila *aux;
    // Cria um novo elemento da lista encadeada que representa a fila e
    // armazena neste novo elemento o item a ser inserido na fila
    aux = malloc(sizeof(ElemFila));
    aux->item = item;
    aux->proximo = NULL;
    if (fila->primeiro == NULL)
    { // Se a fila esta vazia
        fila->primeiro = aux;
        fila->ultimo = aux;
    }
    else
    { // Se a fila nao esta vazia
        fila->ultimo->proximo = aux;
        fila->ultimo = aux;
    }
}


int qtdItensFila(Fila *f) {
    Fila fAux;
    Item item;
    int qtdItens;

    inicializaFila(&fAux);

    qtdItens = 0;
    while (filaVazia(f) == 0) { // Enquanto a fila nao esta vazia
        removeFila(f, &item);
        insereFila(&fAux, item);

        qtdItens++;
    }

    while (filaVazia(&fAux) == 0) { // Enquanto a fila nao esta vazia
        removeFila(&fAux, &item);
        insereFila(f, item);
    }

    liberaFila(&fAux); // Sem efeito se a fila ja esta vazia

    return qtdItens;
}
    
    


int main()
{
    Fila fila;
    Item item;
    inicializaFila(&fila);
    for (int i = 0; i < 10; i++)
    {
        item = i;
        printf("Inserindo na fila o item %d.\n", item);
        insereFila(&fila, item);//aqui
    }
    printf("** Quantidade de itens presentes na fila: %d **\n", qtdItensFila(&fila));

    while (filaVazia(&fila) == 0)
    { // Enquanto a fila nao esta vazia
        removeFila(&fila, &item);//aqui
        printf("Item %d removido da fila.\n", item);
    }
    

    liberaFila(&fila); // Sem efeito se a fila ja esta vazia
    return 0;
}



