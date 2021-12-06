#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct node {
    Item item;
    struct node *proximo;
    struct node *anterior;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Deque;

void inicializaDeque(Deque *d) {
    d->head = NULL;
    d->tail = NULL;
}

void insereInicioDeque(Deque *d, Item item) {
    Node *aux = malloc(sizeof(Node));
    aux->item = item;
    aux->anterior = NULL;
    aux->proximo = NULL;
    
    if (d->head == NULL) {
        d->head = aux;
        d->tail = aux;
    } else {
        aux->proximo = d->head;
        d->head->anterior = aux;
        d->head = aux;
    }
}

void insereFimDeque(Deque *d, Item item) {
    Node *aux = malloc(sizeof(Node));
    aux->item = item;
    aux->anterior = NULL;
    aux->proximo = NULL;
    
    if (d->head == NULL) {
        d->head = aux;
        d->tail = aux;
    } else {
        aux->anterior = d->tail;
        d->tail->proximo = aux;
        d->tail = aux;
    }
}

void removeInicioDeque(Deque *d) {
    Item i;
    Node *aux = d->head;
    i = d->head->item;
    if (d->head == d->tail) {
        d->head = NULL;
        d->tail = NULL;
    } else {
        d->head = d->head->proximo;
        d->head->anterior = NULL;
    }
    printf("%d\n", i);
    free(aux);
}

void removeFimDeque(Deque *d) {
    Item i;
    Node *aux = d->tail;
    i = d->tail->item;
    if (d->head == d->tail) {
        d->head = NULL;
        d->tail = NULL;
    } else {
        d->tail = d->tail->anterior;
        d->tail->proximo = NULL;
    }
    printf("%d\n", i);
    free(aux);
}

void liberaDeque(Deque *d) {
    int qtd = 0;
    Node *aux;
    while (d->head != NULL) {
        qtd++;
        aux = d->head;
        d->head = d->head->proximo;
        free(aux);
    }
    d->tail = NULL;
    printf("%d\n", qtd);
}

int main() {
    Deque d;
    int N, i, O, I;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &O);
        if (O == 1) {
            inicializaDeque(&d);
        } else if (O == 2) {
            scanf("%d", &I);
            insereInicioDeque(&d, I);
        } else if (O == 3) {
            scanf("%d", &I);
            insereFimDeque(&d, I);
        } else if (O == 4) {
            removeInicioDeque(&d);
        } else if (O == 5) {
            removeFimDeque(&d);
        } else if (O == 6) {
            liberaDeque(&d);
        }
    }
    return 0;
}