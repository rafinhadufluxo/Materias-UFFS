#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

node* init() {
    return NULL;
};

int empty_queue(int size) {
    if (size == 0) {
        return 1;
    }
    return 0;
};

int full_queue(int size, int max) {
    if (size == max) {
        return 1;
    }
    return 0;
};

node * push(node *current, int value) {
    node *next;
    next = (node *) malloc(1*sizeof(node));
    if (next != NULL) {
        next->num = value;
        next->prox = NULL;
        if (current != NULL)
            current->prox = next;
    }
    return next;
};

node * pop(node *head) {
    node *new_head;
    new_head = head->prox;
    free(head);
    return new_head;
};

void print_queue(node *head) {
    node *test=NULL;
    test = head;
    do {
        printf("[%x] = %d, ", test, test->num);
        test = test->prox;
    } while (test != NULL);
    printf("\n");
};
