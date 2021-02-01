#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Pull(char *pilha, int *topo);
void Push(char valor, char *pilha, int *topo);

int main() {
    

    char pilha[100], aux, saida[100];
    int topo = -1, i = 0;

    do {
        aux = getchar();

        if (aux != ' ' && aux != '.') {
            Push(aux, pilha, &topo);
        } else {
            while (topo > -1)  {
                saida[i++] = Pull(pilha, &topo);
            }
        saida[i++] = ' ';
        }
        if (aux == ' ') aux = '-';

    } while (aux != '.');

    saida[strlen(saida) -1] = '\0';
    saida[i] = '\0';

    printf("\n%s\n", saida);

    return 0;
}

char Pull(char *pilha, int *topo) {
        if (*topo == -1)
            printf("Pilha vazia!\n");
        else {
            *topo -= 1;
            return pilha[*topo +1];
        }
}

void Push(char valor, char *pilha, int *topo) {
        if (*topo == 100)
            printf("Pilha cheia!\n");
        else {
            *topo += 1;
            pilha[*topo] = valor;
        }
}