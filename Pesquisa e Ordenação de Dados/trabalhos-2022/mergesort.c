// Merge Sort

#include<stdlib.h>
#include<stdio.h>

int printarray(int lista[], int count){
    for (int i = 0; i < count; i++){
        printf("%d\t", lista[i]);
    }
    printf("\n");
}

int * array(int count){
    int * lista = (int *) calloc (count, sizeof(int));
    for (int i = 0; i <= count; i++){
        lista[i] = rand() % 100;
    }
    return lista;
}

void merge(int lista[], int inicio, int meio, int fim){
    //criar listas auxiliares
    int iarray1 = meio - inicio + 1; //inicio de cada lista
    int iarray2 = fim - meio;
 
    int array1[iarray1], array2[iarray2];
    // dividindo a lista em 2
    for (int i = 0; i < iarray1; i++)
        array1[i] = lista[inicio + i];
    for (int j = 0; j < iarray2; j++)
        array2[j] = lista[meio + 1+ j];

    int i = 0, k = inicio, j=0;

    //juntar as 2 listas ordenadamente
    while (i < iarray1 && j < iarray2){
        if (array1[i] <= array2[j]){
            lista[k] = array1[i];
            i++;
        }
        else{
            lista[k] = array2[j];
            j++;
        }
        k++;
    }
    
    while (i < iarray1){
        lista[k] = array1[i];
        i++;
        k++;
    }
    
    while (j < iarray2){
        lista[k] = array2[j];
        j++;
        k++;
    }
}

void mergeSort(int lista[], int inicio, int fim){
if (inicio < fim){
    int meio = inicio+(fim-inicio)/2;

    mergeSort(lista, inicio, meio);
    mergeSort(lista, meio+1, fim);
    //teste array print por iteração
    //printarray(lista, fim+1);

    merge(lista, inicio, meio, fim);
    }
}

int main(){
    int count;

    printf("Digite a quantidade de números da lista: ");
    scanf("%d", &count);
    int * lista = array(count);

    printarray(lista, count);
    mergeSort(lista, 0, count - 1);
    printarray(lista, count);
    return 0;
}