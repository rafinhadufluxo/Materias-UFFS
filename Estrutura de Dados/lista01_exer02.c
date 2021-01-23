#include <stdlib.h>
#include <stdio.h>

int* povoar_array_int(int *numeros, int *tamanho);
int* uniao(int *v1, int n1, int *v2, int n2);

int main () {
    int cont, n1, n2, *v1=NULL, *v2=NULL, *v3=NULL;

    printf("Povoar array v1.\n");
    v1 = povoar_array_int(v1, &n1);

    printf("Povoar array v2.\n");
    v2 = povoar_array_int(v2, &n2);

    printf("União de arrays v1 + v2 = v3.\n");
    v3 = uniao(v1, n1, v2, n2);

    for(cont = 0; cont < (n1+n2); cont++) {
        printf("%d ", v3[cont]);
    }

    return 0;
}

int* uniao(int *v1, int n1, int *v2, int n2) {
    int *v3, cont, tamanho=n1+n2;

    v3 = (int *) calloc(tamanho, sizeof(int));

    if (v3 == NULL) {
        printf("Erro ao alocar memória!\n");
    } else {
        for(cont = 0; cont < n1; cont++) {
            v3[cont] = v1[cont];
        }
        for(cont = 0; cont < n2; cont++) {
            v3[cont+n1] = v2[cont];
        }
    }

    free(v1);
    free(v2);
    return v3;
};

int* povoar_array_int(int *numeros, int *tamanho) {
    int cont, cont_p, captura, teste;
    *tamanho = 1;
    numeros = (int *) calloc(*tamanho, sizeof(int));

    printf("Digite quantos números desejar. Para finalizar digite uma letra.\n");

    if (numeros == NULL) {
        printf("Erro ao alocar memória! Finalizando...\n");
    } else {
        for(cont = 0; cont <= *tamanho; cont++) {
            printf("Digite valor para a posição [%d]: ", cont);
            teste = scanf("%d", &captura);
            getchar();

            if (teste == 0) {
                printf("Caractere digitado não é um número! Finalizando...\n");
                break;
            } else {
                if (cont == *tamanho) {
                    *tamanho = *tamanho + 1;
                    numeros = (int *) realloc(numeros, *tamanho*sizeof(int));
                    if (numeros == NULL) {
                        printf("Erro ao alocar memória! Finalizando...\n");
                        return numeros;
                    }
                }
                numeros[cont] = captura;
            }
        }
    }

    return numeros;
}
