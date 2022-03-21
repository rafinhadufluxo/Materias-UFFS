/*
 * Tarefa de laboratorio 08 - Avaliacao 1 - Parte 1 - Brinde FACE
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Axel Igor Aviloff
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char l1;
    char l2;
    char l3;
    char l4;
} Item;

typedef struct elemPilha {
    Item item;
    struct elemPilha *prox;
} ElemPilha;

typedef struct {
    ElemPilha *topo;
} Pilha;


void inserePilha(Pilha *pilha, Item item) {
    ElemPilha *aux;
    aux = malloc(sizeof(ElemPilha));
    aux->item = item;

    aux->prox = pilha->topo;
    pilha->topo = aux;

}

void removePilha(Pilha *pilha, Item *item) {
    ElemPilha *aux;

    *item = pilha->topo->item;

    if (pilha->topo != NULL) {
        aux = pilha->topo;
        pilha->topo = pilha->topo->prox;

    free(aux);
    }
}

void inicializaPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

void liberaPilha(Pilha *pilha) {
    ElemPilha *aux;

    while (pilha->topo != NULL) {
        aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(aux);
    }
}

int main() {
    int N, i;
    int qtdPontos = 0;
    char c1, c2, c3, c4;
    Item itemFace = {'F', 'A', 'C', 'E'};
    Item item;
    Item ultimoItem;
    Pilha P;
    
    inicializaPilha(&P);
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        // Pilha nunca vai ficar vazia!
        if (pilhaVazia(&P)) {
            inserePilha(&P, itemFace);
        }
        scanf(" %c %c %c %c", &item.l1, &item.l2, &item.l3, &item.l4);
        // Remove os 4 caracteres da pilha
        removePilha(&P, &ultimoItem);
        
        // Compara se os 4 caracteres retirados são iguais à entrada invertida
        if (ultimoItem.l1 == item.l4 && ultimoItem.l2 == item.l3 && ultimoItem.l3 == item.l2 && ultimoItem.l4 == item.l1) {
            qtdPontos++;
        } else {
            // Empilha novamente os caracteres retirados
            inserePilha(&P, ultimoItem);
            // Empilha os novos caracteres
            inserePilha(&P, item);

        }
    }
    printf("%d\n", qtdPontos);

    return 0;
}
