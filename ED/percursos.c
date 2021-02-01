/*
 * Tarefa de laboratorio 12 
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Rafa Arruda
 * Matricula: 1721101029
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct ArvoreBinaria
{
    int chave;
    struct ArvoreBinaria *esq;
    struct ArvoreBinaria *dir;
} NO;

/* declaração das funções utilizadas no código */
void PreOrdem(NO *raiz);
void EmOrdem(NO *raiz);
void PosOrdem(NO *raiz);
NO *insere(NO *no, int chave);

// Uma função para criar um novo nó na Árvore de Busca Binária
NO *novoNo(int item)
{
    NO *aux = (NO *)malloc(sizeof(NO));
    aux->chave = item;
    aux->esq = aux->dir = NULL;
    return aux;
}

/* função para imprimir a árvore em pré ordem (RAIZ, ESQ, DIR) */
void PreOrdem(NO *raiz)
{
    if (raiz != NULL)
    {
        printf("|%d|", raiz->chave);
        PreOrdem(raiz->esq);
        PreOrdem(raiz->dir);
    }
}

// Uma função para fazer o percurso EmOrdem na Árvore de Busca Binária
void EmOrdem(NO *raiz)
{
    if (raiz != NULL)
    {
        EmOrdem(raiz->esq);
        printf("|%d|", raiz->chave);
        EmOrdem(raiz->dir);
    }
}

/* função para imprimir a árvore em pós ordem (ESQ, DIR, RAIZ) */
void PosOrdem(NO *raiz)
{
    if (raiz != NULL)
    {
        PosOrdem(raiz->esq);
        PosOrdem(raiz->dir);
        printf("|%d|", raiz->chave);
    }
}

// Uma função para inserir um novo nó com uma dada chave  na Árvore de Busca Binária
NO *insere(NO *no, int chave)
{
    // Se a árvore estiver vazia, retorne um novo nó
    if (no == NULL)
        return novoNo(chave);

    // Caso contrário, volte pela árvore
    if (chave < no->chave)
        no->esq = insere(no->esq, chave);
    else if (chave > no->chave)
        no->dir = insere(no->dir, chave);

    // retorna o ponteiro do nó (inalterado)
    return no;
}

void libera(NO *raiz)
{
    if (raiz != NULL)
    {
        libera(raiz->esq);
        libera(raiz->dir);
        free(raiz);
        raiz = NULL;
        printf("0");
    }
}

int main()
{

    NO *raiz = NULL;
    int qtd, OP, n;
    scanf("%d", &qtd);
    for (int i = 0; i < qtd; i++)
    {
        scanf("%d", &OP);
        switch (OP)
        {
        case 1:
            raiz = NULL;
            break;
        case 2:
            scanf("%d", &n);
            raiz = insere(raiz, n);
            break;
        case 3:
            // pré-ordem
            PreOrdem(raiz);
            printf("\n");
            break;
        case 4:
            //in ordem
            EmOrdem(raiz);
            printf("\n");

            break;
        case 5:
            //pos ordem
            PosOrdem(raiz);
            printf("\n");

            break;
        case 6:
            libera(raiz);
            printf("\n");
            break;
        }
    };
}
