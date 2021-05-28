#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int insertionsort(int *vet, int n) { 
    int i, aux, j;
    for (int i = 0; i < n; i++){
        int aux = vet[i];
        int j = i - 1;

        while(j >= 0 ){
            
            if(vet[j] > aux){
                vet[j + 1] = vet[j];
                j--;
               
            } else {
                break;
            }
        }
        vet[j + 1] = aux;
    }
}

void selectionsort(int *v, int n){
    int aux;
    for(int i = 0; i<=n-2; i++){
        aux = i;
        for(int j = i+1; j <= n-1; j++){
            if(v[aux] > v[j]){
                aux = j;
            }
        } 
        if (aux != i){
            int aux_selection = v[i];
            v[i] = v[aux];
            v[aux] = aux_selection; 
        }
    }
}

void bubblesort(int *vet, int n){
    int flag;
    for(int i = n-1; i>=1; i--){
        flag = 0;
        for(int j = 0; j<=i-1; j++){
            if (vet[j] > vet[j+1]){  
                vet[j] = vet[j+1];
                flag = 1;
            }
           
        }
        if (flag == 0){
            break;
        }
    }
}

void VetorCrescente (int *vet , int n) {
    for (int i = 0; i < n; i++) 
        vet[i] = i+1;

}

void VetorDecrescente (int *vet , int n) {
    int j = n;
    for (int i = 0; i < n; i++) 
        vet[i] = j;
        j--;
}

void VetorAleatorio (int *vet, int n, int num) {
    int i;
    for (i = 0; i < n; i++)
        vet[i] = rand() % num;
    

    
}

void chooseOptions (int option, int *vet, int n, int num) {
    if (option == 1) 
        VetorCrescente(vet, n);
        
    if (option == 2) 
        VetorDecrescente(vet, n);
        
    if (option == 3)
        VetorAleatorio(vet, n, num);
        
}



int main(){
    int n;
    int value = 1000000;
    clock_t start,end;
    double Tempo;
    int method,optionVet;
    

    printf("\n");
    printf("\t Informe o método de ordenção para usar?\n\n\t\t1 - BubbleSort\n\t\t2 - InsertionSort\n\t\t3 - SelectionSort\n");
    scanf("%d", &method);
    printf("\nDigite  o tamanho do vetor a ser usado?\n");
    scanf("%d", &n);
    printf("\n");
    
    int vet[n];
    printf("Informe o tipo de vetor.\n1 - Crescente\n2 - Decrescente\n3 - Aleatorio\n");
    scanf("%d", &optionVet);
    printf("\n");

    chooseOptions (optionVet, vet, n, value);

    if (method == 1) {
        
        start = clock();
        bubblesort(vet, n);  
    }
    else if (method == 2) {
    
        start = clock();
        insertionsort(vet, n);
    }
    else if (method == 3) {
        
        start = clock();
        selectionsort (vet, n);
    }
    
    end = clock();

    printf("\nTempo gasto da funçao escolhida 😅 😅");
   

    Tempo = ((double)end - start)/CLOCKS_PER_SEC;
    
    printf("\nTempo(s): %lf\n",Tempo);
    printf("Tempo(ms) %lf\n",Tempo*1000);
}