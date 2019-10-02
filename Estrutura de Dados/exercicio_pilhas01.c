#include <stdlib.h>
#include <stdio.h>

int main() {
    char pilha[30];
    int topo=-1;

    return 0;
}

void push(char *pilha, int *topo, char elem) {
    pilha[*topo] = elem;
    *topo = *topo+1;
};

char pop(char *pilha, int *topo) {
    pilha[*topo] = NULL;
    *topo = *topo-1;
}
