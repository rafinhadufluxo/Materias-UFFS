#include <stdlib.h>
#include <stdio.h>
#define INICIAL 5

int main() {
    int *numeros, cont, cont_p, captura, teste, tamanho=INICIAL;

    numeros = (int *) calloc(tamanho, sizeof(int));

    if (numeros == NULL) {
        printf("Erro ao alocar memória! Encerrando...\n");
        exit(1);
    } else {
        for(cont = 0; cont <= tamanho; cont++) {
            printf("Digite valor para a posição [%d]: ", cont);
            teste = scanf("%d", &captura);

            if (teste == 0) {
                printf("Caractere digitado não é um número! Encerrando...\n");
                break;
            } else {
                if (cont == tamanho) {
                    tamanho += INICIAL;
                    numeros = (int *) realloc(numeros, tamanho*sizeof(int));
                    if (numeros == NULL) {
                        printf("Erro ao alocar memória! Encerrando...\n");
                        exit(1);
                    }
                }
                numeros[cont] = captura;
            }
        }
        for(cont_p = 0; cont_p < cont; cont_p++) {
            printf("%d\t", numeros[cont_p]);
        }
        free(numeros);
    }

    return 0;
}
