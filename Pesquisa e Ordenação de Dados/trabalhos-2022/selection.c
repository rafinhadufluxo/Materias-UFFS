#include <stdio.h>
void swap(int *vet, int i, int j){
    int t = vet[i];
    vet[i] = vet[j];
    vet[j] = t;
}
//conjunto de elementos,pode-se selecionar o maior ou menor.
int main(){
    int i, j, menor, *vet, n;
    scanf("%d", &n);
    vet = malloc(n*sizeof(int));
    for(i = 0; i < n; i ++){
        scanf("%d", &vet[i]);
    }
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i; j < n; j++){
            if(vet[menor] > vet[j]){
                menor = j;
            }
            
        }
        if(i != menor){
                swap(vet, menor, i);
        }
    }
    for(i = 0; i < n; i ++){
        printf("\n%d\n", vet[i]);
    }
    return 0;
}