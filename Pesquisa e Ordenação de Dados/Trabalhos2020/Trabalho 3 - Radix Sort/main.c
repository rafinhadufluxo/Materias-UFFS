/* 
 * Acadêmico: Axel Igor Aviloff
 * Disciplina: Pesquisa e Ordenação de Dados
 * Data: 02/04/2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 40

typedef struct {
    int codigo;
    char nome[TAM];
} Produto;

int buscaMax(Produto p[], int N) {
    int max = p[0].codigo;

    for (int i = 1; i < N; i++) {
        if (p[i].codigo > max) {
            max = p[i].codigo;
        }
    }

    return max;
}

void countingSort(Produto p[], int N, int pos) {
    int aux[N], digito, i;
    char aux2[10][TAM];
    int count[10] = {0};
    

    for (i = 0; i < N; i++) {
        digito = (p[i].codigo / pos) % 10;
        count[digito]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = N - 1; i >= 0; i--) {
        digito = (p[i].codigo / pos) % 10;
        aux[count[digito] - 1] = p[i].codigo;
        strcpy(aux2[count[digito] - 1], p[i].nome);
        count[digito]--;
    }

    for (i = 0; i < N; i++) {
        p[i].codigo = aux[i];
        strcpy(p[i].nome, aux2[i]);
    }

}

// Função principal do radixSort 
void radixSort(Produto p[], int N) {
    int max = buscaMax(p, N); // Encontra o maior código dos produtos
    for (int pos = 1; max / pos > 0; pos *= 10) {
        countingSort(p, N, pos);
    }
}

int main() {
    int i;
    int ids[10] = {123, 502, 103, 322, 654, 735, 923, 883, 111, 777};
    char nomes[10][TAM] = {{"Sucrilhos"}, {"Sorvete"}, {"Feijao"}, {"Arroz"}, {"Azeite"}, {"Cerveja"}, {"Refrigerante"}, {"Queijo"}, {"Presunto"}, {"Banana"}};

    Produto produtos[10];

    for (i = 0; i < 10; i++) {
        produtos[i].codigo = ids[i];
        strcpy(produtos[i].nome, nomes[i]);
    }

    // Antes do radixSort
    printf("ANTES DO RADIXSORT\n");
    for (i = 0; i < 10; i++) {
        printf("%d - %s\n", produtos[i].codigo, produtos[i].nome);
    }

    radixSort(produtos, 10);

    // Apos o radixSort
    printf("\nDEPOIS DO RADIXSORT\n");
    for (i = 0; i < 10; i++) {
        printf("%d - %s\n", produtos[i].codigo, produtos[i].nome);
    }

    return 0;
}