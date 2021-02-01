#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int numero;
    char nome[30];
    struct item *prox;
} Item;

typedef struct fila {
    Item *primeiro;
    Item *ultimo;
    int qtdItens;
} Fila;

Fila *criaFila();
void liberaFila(Fila *f);
int estahVazia(Fila);
void enfileirar(Fila *f, int n, char nm[]);
void desenfileirar(Fila *f, char *nomeDesenfileirado, int *nDesenfileirado);
void mostrarFila(Fila *f);
int quantidadeFila(Fila *f);
void mostrarCaracteristicas(Fila *f);

int main(){
	Fila *aeroporto = criaFila();
	menuAeroporto(aeroporto);
	return 0;
}