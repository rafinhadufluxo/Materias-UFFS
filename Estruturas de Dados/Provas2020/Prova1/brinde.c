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

typedef char Item;

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
    Item c1a, c2a, c3a, c4a;
    Pilha P;
    
    inicializaPilha(&P);
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        // Pilha nunca vai ficar vazia!
        if (pilhaVazia(&P)) {
            inserePilha(&P, 'E');
            inserePilha(&P, 'C');
            inserePilha(&P, 'A');
            inserePilha(&P, 'F');
        }
        scanf(" %c %c %c %c", &c1, &c2, &c3, &c4);
        // Remove os 4 caracteres da pilha
        removePilha(&P, &c1a);
        removePilha(&P, &c2a);
        removePilha(&P, &c3a);
        removePilha(&P, &c4a);
        
        // Compara se os 4 caracteres retirados são iguais à entrada invertida
        if (c1a == c4 && c2a == c3 && c3a == c2 && c4a == c1) {
            qtdPontos++;
        } else {
            // Empilha novamente os caracteres retirados
            inserePilha(&P, c4a);
            inserePilha(&P, c3a);
            inserePilha(&P, c2a);
            inserePilha(&P, c1a);
            
            // Empilha os novos caracteres
            inserePilha(&P, c4);
            inserePilha(&P, c3);
            inserePilha(&P, c2);
            inserePilha(&P, c1);

        }
    }
    printf("%d\n", qtdPontos);

    return 0;
}
