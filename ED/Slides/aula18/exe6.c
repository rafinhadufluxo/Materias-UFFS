#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct filaNo{
    char *nome;
    int identificador;
    struct filaNo *proximo;
}FilaNo;

typedef struct fila{
    struct filaNo *inicio;
    struct filaNo *final;
}Fila;

Fila *cria(void) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->inicio = fila->final = NULL;
    return fila;
}

void filadeEspera(Fila *fila, char *nome, int identificador) {
    FilaNo *novo = (FilaNo *) malloc(sizeof(FilaNo));
    novo->nome = (char *) malloc(sizeof(char));
    strcpy(novo->nome, nome);
    novo->identificador = identificador;
    novo->proximo = NULL;
    if (!fila->inicio)
        fila->inicio = novo;
    else
        fila->final->proximo = novo;
    fila->final = novo;
}

void autorizar(Fila *fila) {
    fila->inicio = fila->inicio->proximo;
}

void listar(Fila *fila) {
    FilaNo *percorre = fila->inicio;
    while (percorre) {
        printf("Aviao %d\n", percorre->identificador);
        printf("Nome %s\n", percorre->nome);
        percorre = percorre->proximo;
    }
}

void listarPrimeiro(Fila *fila) {
    printf("Primeiro Aviaozinho\n");
    printf("Aviao %d\n", fila->inicio->identificador);
    printf("Nome %s\n", fila->inicio->nome);
}

int main(void) {
    Fila *fila = cria();
    filadeEspera(fila, "Aviaozinho1", 1);
    filadeEspera(fila, "Aviaozinho2", 2);
    filadeEspera(fila, "Aviaozinho3", 3);
    autorizar(fila);
    listarPrimeiro(fila);
    listar(fila);
    // system("pause");
}