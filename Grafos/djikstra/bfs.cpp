#include <iostream>
#include <stdlib.h>
#include <queue>
#include <list>
#include <vector>

#define TAMANHO 21

using namespace std;

typedef struct matrizBfs {
    int visitado, anterior;
} matrizBfs;

void inicia(matrizBfs info[]){
    for (size_t i = 0; i < TAMANHO; i++) {
        info[i].anterior = -1;
        info[i].visitado =  0;
    }
}

void conta(matrizBfs info[], int indice) {
    if(info[indice].anterior > 0){
        conta(info, info[indice].anterior);
    }
    if(info[indice].anterior == 0){
        printf("%c ", info[indice].anterior + 65);
    }
    if(indice == 20) printf("%c ", indice + 70);
    else printf("%c ", indice + 65);
    return;
}

void bfs(matrizBfs info[], vector <int> bfsadjacencia[], int inicio){
    queue <int> bfsqueue;
    bfsqueue.push(inicio);

    while (!bfsqueue.empty()) {     //enquanto a fila não estiver vazia
        int i = bfsqueue.front();   //pega o primeiro da fila
        bfsqueue.pop();             //tira da fila
        for (size_t j = 0; j < bfsadjacencia[i].size(); j++) {  //percorre todas as adjacências dele
            if (info[bfsadjacencia[i][j]].visitado == 0){       //se a adjacência não foi visitada
                info[bfsadjacencia[i][j]].visitado = 1;         //marca como visitada
                info[bfsadjacencia[i][j]].anterior = i;         //seta qual é o vértice anterior a ela
                bfsqueue.push(bfsadjacencia[i][j]);             //coloca ela na fila
            }
        }
     }
}

void popula(vector <int> bfsadjacencia[]);

int main(int argc, char const *argv[]) {

    vector <int> bfsadjacencia[TAMANHO];
    matrizBfs info[TAMANHO];
    inicia(info);

    //Construção do grafo:
    popula(bfsadjacencia);

    bfs(info, bfsadjacencia, 0);
    info[0].anterior = -1;

    printf("Vértice | Anterior | Menor Caminho\n");
    for (int i = 0; i < TAMANHO; i++) {
        if(i == 20) printf("%7c | %5c    | ", i + 70, info[i].anterior + 70);
        else printf("%7c | %5c    | ", i + 65, info[i].anterior + 65);
        conta(info, i);
        printf("\n");
    }

    return 0;
}

void popula(vector <int> bfsadjacencia[]){
    bfsadjacencia[ 0 ].push_back( 1 );
    bfsadjacencia[ 0 ].push_back( 10 );
    bfsadjacencia[ 1 ].push_back( 0 );
    bfsadjacencia[ 1 ].push_back( 2 );
    bfsadjacencia[ 1 ].push_back( 3 );
    bfsadjacencia[ 2 ].push_back( 1 );
    bfsadjacencia[ 2 ].push_back( 4 );
    bfsadjacencia[ 3 ].push_back( 1 );
    bfsadjacencia[ 3 ].push_back( 4 );
    bfsadjacencia[ 3 ].push_back( 11 );
    bfsadjacencia[ 4 ].push_back( 2 );
    bfsadjacencia[ 4 ].push_back( 3 );
    bfsadjacencia[ 4 ].push_back( 5 );
    bfsadjacencia[ 4 ].push_back( 6 );
    bfsadjacencia[ 5 ].push_back( 4 );
    bfsadjacencia[ 5 ].push_back( 7 );
    bfsadjacencia[ 6 ].push_back( 4 );
    bfsadjacencia[ 6 ].push_back( 8 );
    bfsadjacencia[ 7 ].push_back( 5 );
    bfsadjacencia[ 7 ].push_back( 8 );
    bfsadjacencia[ 7 ].push_back( 9 );
    bfsadjacencia[ 8 ].push_back( 6 );
    bfsadjacencia[ 8 ].push_back( 7 );
    bfsadjacencia[ 8 ].push_back( 9 );
    bfsadjacencia[ 9 ].push_back( 7 );
    bfsadjacencia[ 9 ].push_back( 8 );
    bfsadjacencia[ 9 ].push_back( 20 );
    bfsadjacencia[ 10 ].push_back( 0 );
    bfsadjacencia[ 10 ].push_back( 11 );
    bfsadjacencia[ 10 ].push_back( 12 );
    bfsadjacencia[ 10 ].push_back( 13 );
    bfsadjacencia[ 11 ].push_back( 3 );
    bfsadjacencia[ 11 ].push_back( 10 );
    bfsadjacencia[ 11 ].push_back( 14 );
    bfsadjacencia[ 12 ].push_back( 10 );
    bfsadjacencia[ 12 ].push_back( 14 );
    bfsadjacencia[ 13 ].push_back( 10 );
    bfsadjacencia[ 13 ].push_back( 14 );
    bfsadjacencia[ 14 ].push_back( 11 );
    bfsadjacencia[ 14 ].push_back( 12 );
    bfsadjacencia[ 14 ].push_back( 13 );
    bfsadjacencia[ 14 ].push_back( 15 );
    bfsadjacencia[ 14 ].push_back( 17 );
    bfsadjacencia[ 15 ].push_back( 14 );
    bfsadjacencia[ 15 ].push_back( 16 );
    bfsadjacencia[ 16 ].push_back( 15 );
    bfsadjacencia[ 16 ].push_back( 17 );
    bfsadjacencia[ 16 ].push_back( 18 );
    bfsadjacencia[ 16 ].push_back( 19 );
    bfsadjacencia[ 17 ].push_back( 14 );
    bfsadjacencia[ 17 ].push_back( 16 );
    bfsadjacencia[ 18 ].push_back( 16 );
    bfsadjacencia[ 18 ].push_back( 19 );
    bfsadjacencia[ 18 ].push_back( 20 );
    bfsadjacencia[ 19 ].push_back( 16 );
    bfsadjacencia[ 19 ].push_back( 18 );
    bfsadjacencia[ 19 ].push_back( 20 );
    bfsadjacencia[ 20 ].push_back( 9 );
    bfsadjacencia[ 20 ].push_back( 18 );
    bfsadjacencia[ 20 ].push_back( 19 );
}
