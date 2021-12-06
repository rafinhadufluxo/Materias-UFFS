/*
 * Autor: Axel Igor Aviloff
 * Proposta: Calcular o tempo de execução do algoritmo de ordenação BubbleSort em casos distintos
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Troca os valores no BubbleSort
void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

// Algoritmo BubbleSorte otimizado com flag
void bubbleSortFlag(int A[], int N) {
    int flag = 1;
    int i, j;
    for (i = 0; i < N - 1 && flag == 1; i++) {
        flag = 0; 
        for (j = 0; j < N - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                troca(&A[j], &A[j+1]);
                flag = 1; 
            }
        }
    }
}

void mostraTempo(int A[], int N, clock_t inicio, clock_t fim, double diferencaTempo) {
    inicio = clock();

    bubbleSortFlag(A, N);

    fim = clock();

    diferencaTempo = ((double) fim - inicio)/CLOCKS_PER_SEC;

    printf("\n\t\t%lf segundos\n", diferencaTempo);

}

void resultadoDezMil(clock_t inicio, clock_t fim, double diferencaTempo) {
    int dezMilCrescente[10000];
    int dezMilDecrescente[10000];
    int dezMilAleatorio[10000];
    int i;

    for (i = 0; i < 10000; i++) {
        dezMilCrescente[i] = i;
        dezMilDecrescente[i] = 9999 - i;
        dezMilAleatorio[i] = rand() % 10000;
    }
    printf("TAMANHO DO VETOR: 10000\n");
    
    printf("\n\tCrescente");
    mostraTempo(dezMilCrescente, 10000, inicio, fim, diferencaTempo);
    printf("\n\tDecrescente");
    mostraTempo(dezMilDecrescente, 10000, inicio, fim, diferencaTempo);
    printf("\n\tAleatorio");
    mostraTempo(dezMilAleatorio, 10000, inicio, fim, diferencaTempo);


}

void resultadoCinquentaMil(clock_t inicio, clock_t fim, double diferencaTempo) {
    int cinquentaMilCrescente[50000];
    int cinquentaMilDecrescente[50000];
    int cinquentaMilAleatorio[50000];
    int i;

    for (i = 0; i < 50000; i++) {
        cinquentaMilCrescente[i] = i;
        cinquentaMilDecrescente[i] = 49999-i;
        cinquentaMilAleatorio[i] = rand() % 50000;
    }

    printf("\n\nTAMANHO DO VETOR: 50000\n");

    printf("\n\tCrescente");
    mostraTempo(cinquentaMilCrescente, 50000, inicio, fim, diferencaTempo);
    printf("\n\tDecrescente");
    mostraTempo(cinquentaMilDecrescente, 50000, inicio, fim, diferencaTempo);
    printf("\n\tAleatorio");
    mostraTempo(cinquentaMilAleatorio, 50000, inicio, fim, diferencaTempo);

}

void resultadoCemMil(clock_t inicio, clock_t fim, double diferencaTempo) {
    int cemMilCrescente[100000];
    int cemMilDecrescente[100000];
    int cemMilAleatorio[100000];
    int i;

    for (i = 0; i < 100000; i++) {
        cemMilCrescente[i] = i;
        cemMilDecrescente[i] = 99999-i;
        cemMilAleatorio[i] = rand() % 100000;
    }

    printf("\n\nTAMANHO DO VETOR: 100000\n");

    printf("\n\tCrescente");
    mostraTempo(cemMilCrescente, 100000, inicio, fim, diferencaTempo);
    printf("\n\tDecrescente");
    mostraTempo(cemMilDecrescente, 100000, inicio, fim, diferencaTempo);
    printf("\n\tAleatorio");
    mostraTempo(cemMilAleatorio, 100000, inicio, fim, diferencaTempo);

}

int main() {
    clock_t inicio, fim;
    double diferencaTempo;
    
    printf("BUBBLE SORT\n\n");

    srand(time(0));

    resultadoDezMil(inicio, fim, diferencaTempo);

    resultadoCinquentaMil(inicio, fim, diferencaTempo);
    
    resultadoCemMil(inicio, fim, diferencaTempo);



    return 0;


}
