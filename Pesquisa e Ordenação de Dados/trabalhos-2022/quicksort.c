// quick sort

#include<stdlib.h>
#include<stdio.h>

int * array(int count){
    int * lista = (int *) calloc (count, sizeof(int));
    for (int i = 0; i <= count; i++){
        lista[i] = rand() % 100;
    }
    return lista;
}

void printarray(int lista[], int count){
    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");
}

void quicksort(int lista[], int inicio, int fim){
    int pivo;
    if (inicio < fim){
        pivo = Particiona(lista, inicio, fim);

        quicksort(lista, inicio, pivo-1);
        quicksort(lista, pivo, fim);
    }
}

int Particiona(int lista[], int inicio, int fim){
    int aux;
    int pivo=fim, k=inicio;
    for (int i=inicio; i < fim; i++){
        if (lista[i] <= lista[pivo]){
            aux = lista[i];
            lista[i]= lista[k];
            lista[k]= aux;
            k++;
        }
    }
    if (lista[k] > lista[pivo]){
        aux = lista[pivo];
        lista[pivo] = lista[k];
        lista[k] = aux;
        pivo=k;
    }
    return pivo;
}

int main(){
    int count;

    printf("Digite a quantidade de números da lista: ");
    scanf("%d", &count);
    int * lista = array(count);

    printarray(lista, count);
    quicksort(lista, 0, count-1);
    printarray(lista, count);
    return 0;
}