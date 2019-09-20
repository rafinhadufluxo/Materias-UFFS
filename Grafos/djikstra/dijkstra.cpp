#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

#define TAMANHO 7

typedef struct matrizDijkstra {
    short   visitado;
    int     custo;
    int     anterior;
} matrizDijkstra;

int menor(matrizDijkstra info[], int *terminou) {
    int menorCusto = 1000;
    int menorIndice;

    size_t i;
    for (i = 0; i < TAMANHO; i++) if(info[i].visitado == 0) break;
    if (i == TAMANHO) {
        *terminou = 1;
        return 0;
    }

    for (i = 0; i < TAMANHO; i++)
        if(info[i].custo < menorCusto && info[i].visitado == 0){
            menorCusto = info[i].custo;
            menorIndice = i;
        }
    return menorIndice;
}

void inicializa(matrizDijkstra info[]) {
    for (size_t i = 0; i < TAMANHO; i++) {
        info[i].visitado = 00;
        info[i].custo = 10000;
        info[i].anterior = -1;
    }
}

void conta(matrizDijkstra info[], int indice) {
    if(info[indice].anterior > 0){
        conta(info, info[indice].anterior);
    }
    if(info[indice].anterior == 0){
        printf("%c ", info[indice].anterior + 65);
    }
    printf("%c ", indice + 65);
    return;
}

void dijkstra(int matriz[TAMANHO][TAMANHO], matrizDijkstra info[], int vertice) {
    // marcar vértice como visitado
    info[vertice].visitado = 1;

    //percorrer para registrar custo e vértice anterior
    for (size_t i = 0; i < TAMANHO; i++)
        if(matriz[vertice][i] > 0 && info[i].visitado == 0 && info[vertice].custo + matriz[vertice][i] < info[i].custo){
            info[i].custo = matriz[vertice][i] + info[vertice].custo;
            info[i].anterior = vertice;
        }

    // repetir o processo para o menor filho não visitado
    int parar = 0, proximo = menor(info, &parar);
    if(!parar) dijkstra(matriz, info, proximo);
}

int main(int argc, char const *argv[]) {

    int matrizAdjacencia[TAMANHO][TAMANHO] = {  0, 7, 0,  5,   0,  0,  0,
                                                7, 0, 8,  9,   7,  0,  0,
                                                0, 8, 0,  0,   5,  0,  0,
                                                5, 9, 0,  0,  15, 80,  0,
                                                0, 7, 5, 15,   0,  8,  9,
                                                0, 0, 0,  80,  8,  0, 11,  
                                                0, 0, 0,  0,   9, 11,  0};
    matrizDijkstra matrizInfo[TAMANHO];

    inicializa(matrizInfo);

    matrizInfo[0].custo = 0;
    dijkstra(matrizAdjacencia, matrizInfo, 0);

    printf("Vértice | Custo | Anterior | Menor Caminho\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%7c | %5d | %5c    | ", i + 65, matrizInfo[i].custo, matrizInfo[i].anterior + 65);
        conta(matrizInfo, i);
        printf("\n");
    }

    return 0;
}
