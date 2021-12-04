/*
 * Tarefa de laboratorio 14 - Reconstruindo uma arvore binaria
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Axel Igor Aviloff
 *
 */
// Ferramentas utilizadas para a resolução desse exercício: https://exame.com/wp-content/uploads/2016/09/size_960_16_9_20151019-26684-fibyjo.jpg
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char chave;
    struct node *esq, *dir;
} Node;

Node *inicializarArvore() {
    Node *raiz = NULL;
    return raiz;
}

void imprimeEmOrdem(Node *raiz) {
    if (raiz != NULL) {
        imprimeEmOrdem(raiz->esq);
        printf("%c", raiz->chave);
        imprimeEmOrdem(raiz->dir);
    }
}

void imprimePreOrdem(Node *raiz) {
    if (raiz != NULL) {
        printf("%c", raiz->chave);
        imprimePreOrdem(raiz->esq);
        imprimePreOrdem(raiz->dir);
    }
}

void ImprimePosOrdem(Node *raiz) {
    if (raiz != NULL) {
        ImprimePosOrdem(raiz->esq);
        ImprimePosOrdem(raiz->dir);
        printf("%c", raiz->chave);
    }
}

void liberaArvore(Node *raiz) {
    if (raiz != NULL) {
        printf("0");
        liberaArvore(raiz->esq);
        liberaArvore(raiz->dir);
        free(raiz);
    }
}

Node *reconstruirArvore(Node *raiz, char *preordemExtendido, int *indice, int N) {
    Node *novoNode;
    
    novoNode = malloc(sizeof(Node));
    novoNode->esq = inicializarArvore();
    novoNode->dir = inicializarArvore();

    novoNode->chave = preordemExtendido[*indice];
    *indice += 1;
    char sesq = preordemExtendido[*indice];
    *indice += 1;
    char sdir = preordemExtendido[*indice];
    *indice += 1;

    if (sesq == '1') {
        novoNode->esq = reconstruirArvore(novoNode->esq, preordemExtendido, indice, N);
    }

    if (sdir == '1') {
        novoNode->dir = reconstruirArvore(novoNode->dir, preordemExtendido, indice, N);
    }

    return novoNode;
}

int main() {

    int N, indice = 0;

    Node *raiz = inicializarArvore();

    scanf("%d", &N);
    scanf("\n");

    char str[(N * 3) + 1];

    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    raiz = reconstruirArvore(raiz, str, &indice, N);

    imprimeEmOrdem(raiz);
    printf("\n");

    ImprimePosOrdem(raiz);
    printf("\n");

    liberaArvore(raiz);
    printf("\n");

    return 0;
}
