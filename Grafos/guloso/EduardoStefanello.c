#include <stdio.h>

void gulosoAdj1(int matriz[5][5], int menorCaminho[]){
    for (int i = 0; i < 5; menorCaminho[i] = 0, i++);

    int i = 0;
    for (int k = 1; k <= 5; k++) {
        menorCaminho[0] = 1;
        int menorAresta = 1000000;
        int colunaMenorAresta;
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] < menorAresta && matriz[i][j] > 0) {
                menorAresta = matriz[i][j];
                colunaMenorAresta = j;
            }
        }
        i = colunaMenorAresta;
        menorCaminho[k] = colunaMenorAresta + 1;
    }
}

void gulosoInc1(int matriz[5][8], int menorCaminho[]){
    for (int i = 0; i < 5; menorCaminho[i] = 0, i++);
    int i = 0;
    for (int k = 1; k <= 5; k++) {
        menorCaminho[0] = 1;
        int menorAresta = 1000000;
        int colunaMenorAresta;
        for (int j = 0; j < 8; j++) {
            if (matriz[i][j] < menorAresta && matriz[i][j] > 0) {
                menorAresta = matriz[i][j];
                colunaMenorAresta = j;
            }
        }
        for (int j = 0; j < 5; j++){
            if (matriz[j][colunaMenorAresta] != 0 && j != i){
                i = j;
                menorCaminho[k] = j + 1;
                break;
            }
        }
    }
}

void gulosoAdj2(int matriz[7][7], int menorCaminho[]){
    for (int i = 0; i < 7; menorCaminho[i] = 0, i++);

    int i = 0;
    for (int k = 1; k <= 7; k++) {
        menorCaminho[0] = 1;
        int menorAresta = 1000000;
        int colunaMenorAresta;
        for (int j = 0; j < 7; j++) {
            if (matriz[i][j] < menorAresta && matriz[i][j] > 0) {
                menorAresta = matriz[i][j];
                colunaMenorAresta = j;
            }
        }
        i = colunaMenorAresta;
        menorCaminho[k] = colunaMenorAresta + 1;
    }
}

void gulosoInc2(int matriz[7][9], int menorCaminho[]){
    for (int i = 0; i < 7; menorCaminho[i] = 0, i++);
    int i = 0;
    for (int k = 1; k <= 7; k++) {
        menorCaminho[0] = 1;
        int menorAresta = 1000000;
        int colunaMenorAresta;
        for (int j = 0; j < 9; j++) {
            if (matriz[i][j] < menorAresta && matriz[i][j] > 0) {
                menorAresta = matriz[i][j];
                colunaMenorAresta = j;
            }
        }
        for (int j = 0; j < 7; j++){
            if (matriz[j][colunaMenorAresta] != 0 && j != i){
                i = j;
                menorCaminho[k] = j + 1;
                break;
            }
        }
    }
}

int main(int argc, char const *argv[]) {

//  Matriz de Adjacência Exercício 1
    int matrizAdj1[5][5], menorCaminhoAdj1[5];
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) scanf("%d", &matrizAdj1[i][j]);
    gulosoAdj1(matrizAdj1, menorCaminhoAdj1);
    printf("Caminho Encontrado na Matriz de Adjacência do Exercício 1: ");
    for (size_t i = 0; i < 5; i++) printf("%d ", menorCaminhoAdj1[i]);
    printf("\n");

//  Matriz de Incidência Exercício 1
    int matrizInc1[5][8], menorCaminhoInc1[5];
    for (int i = 0; i < 5; i++) for (int j = 0; j < 8; j++) scanf("%d", &matrizInc1[i][j]);
    gulosoInc1(matrizInc1, menorCaminhoInc1);
    printf("Caminho Encontrado na Matriz de Incidência do Exercício 1: ");
    for (size_t i = 0; i < 5; i++) printf("%d ", menorCaminhoInc1[i]);
    printf("\n");

//  Matriz de Adjacência Exercício 2
    int matrizAdj2[7][7], menorCaminhoAdj2[7];
    for (int i = 0; i < 7; i++) for (int j = 0; j < 7; j++) scanf("%d", &matrizAdj2[i][j]);
    gulosoAdj2(matrizAdj2, menorCaminhoAdj2);
    printf("Caminho Encontrado na Matriz de Adjacência do Exercício 2: ");
    for (size_t i = 0; i < 7-3; i++) printf("%d ", menorCaminhoAdj2[i]);
    printf("\n");

//  Matriz de Incidência Exercício 1
    int matrizInc2[7][9], menorCaminhoInc2[5];
    for (int i = 0; i < 7; i++) for (int j = 0; j < 9; j++) scanf("%d", &matrizInc2[i][j]);
    gulosoInc2(matrizInc2, menorCaminhoInc2);
    printf("Caminho Encontrado na Matriz de Incidência do Exercício 1: ");
    for (size_t i = 0; i < 7-3; i++) printf("%d ", menorCaminhoInc2[i]);
    printf("\n");


    return 0;
}
