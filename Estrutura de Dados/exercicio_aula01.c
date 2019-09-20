#include <stdlib.h>
#include <stdio.h>

int main() {
    int num_linhas, num_cols, cont, cont2, *linhas, *p;

    printf("Digite o número de linhas: ");
    if (scanf("%d", &num_linhas) == 1) {
        linhas = malloc(sizeof(int*)*num_linhas);

        for(cont = 0; cont < num_linhas; cont++) {
            printf("Digite o número de colunas da linha [%d]: ", cont);

            if (scanf("%d", &num_cols) == 1) {
                linhas[cont] = malloc(sizeof(int)*num_cols);
                p = linhas[cont];
                printf("%x | ", p);
                for(cont2 = 0; cont2 < num_cols; cont2++) {
                    p[cont2] = rand() % 100;
                    printf("%d ", p[cont2]);
                }
                printf("\n");

            } else {
                return 1;
            }
        }
    } else {
        return 1;
    }

    return 0;
}
