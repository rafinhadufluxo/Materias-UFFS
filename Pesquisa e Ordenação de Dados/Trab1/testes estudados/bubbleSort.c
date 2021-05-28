#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5000

void bubbleVec(int vector[]){
    for(int i = MAX - 1; i >= 1; i--){
        for(int j = 0; j < i; j++){ 
            if(vector[j] > vector[j + 1]){
                int aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
		}
	}
}


void Decrescente(int vetor[]){
    for (int i = 0; i < MAX - 1; i++){
        for (int j = i; j < MAX - 1; j++){

            if (vetor[i] < vetor[j]){
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}


void Crescente(int vetor[]){
    for (int i=0;i<MAX; i++){
        for(int j=i+1;j<MAX;j++){
            if (vetor[i]>vetor[j]){
                int temp = vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=temp;
            }
        }
	}
}


void mostrarVetor(int vetor[])
{
    for (int i = 0; i < MAX - 1; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int vectorSelect[MAX];
    clock_t start, finish;
    double tempo[3];

    int vectorDecrescente[MAX], vectorCrescente[MAX];
    

    printf("Valores desordenados:\n"); 
    for(int i = 0; i < MAX; i++){
        int random = rand() % 10000;
        vectorSelect[i] = random;
        i == MAX - 1 ? printf("%d.\n\n\n", random): printf("%d, ", random);
    }

    printf("Valores Decrescente:\n");
    for(int j = 0; j < MAX; j++){
        int random = rand() % 5000;
        vectorDecrescente[j] = random;
    }

    Decrescente(vectorDecrescente); // adicionando numa função para deixar decrescente
    mostrarVetor(vectorDecrescente); //mostra valores aleatorio em decrescente
    

    printf("\nValores Crescente:\n");
    for(int n = 0; n < MAX; n++){
        int random = rand() % 5000;
        vectorCrescente[n] = random;
    }

    Crescente(vectorCrescente); // adicionando numa função para deixar crescente
    mostrarVetor(vectorCrescente); //mostra valores aleatorio em crescente
    

    
    printf("\n\n-----------------------------------------------------------------------");
    printf("\n\t\t\t=== Metodo Bubble  ===\n");
    
    start = clock();
    bubbleVec(vectorCrescente);
    finish = clock();
    //printf("Ordem Crescente\n");
    // for (int i =0; i < MAX; i++) 
    //     printf("%d ",  vectorCrescente[i]);
    // printf("\n\n");
    tempo[0] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

    start = clock();
    bubbleVec(vectorDecrescente);
    finish = clock();
    // printf("Ordem Decrescente\n");
    // for (int k =0; k < MAX; k++) 
    //     printf("%d ",  vectorDecrescente[k]);
    // printf("\n\n");
    tempo[1] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

    start = clock();
    bubbleVec(vectorSelect);
    finish = clock();
    // printf("Ordem Aleatoria\n");
    // for (int r =0; r < MAX; r++) 
    //     printf("%d ",  vectorSelect[r]);
    // printf("\n\n");
    tempo[2] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;


    printf("\n");
    printf("\nTempo gasto por cada função:\n");
    printf("Bubble Sort Crescente:    %.5lf ms\n", tempo[0]);
    printf("Bubble Sort  Decrescente:    %.5lf ms\n", tempo[1]);
    printf("Bubble Sort Aleatorio:    %.5lf ms\n", tempo[2]);
    printf("\n");

    return 0;
}