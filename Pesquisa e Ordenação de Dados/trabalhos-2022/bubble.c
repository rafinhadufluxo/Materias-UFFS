#include <stdio.h>
void swap(int *vet, int i, int j){
    int t = vet[i];
    vet[i] = vet[j];
    vet[j] = t;
}
int main(){
    int n, *vet, i, j;
    scanf("%d", &n);

    vet = malloc(n*sizeof(int));
    
    for(i = 0; i < n; i ++){
        printf("\n");
        scanf("%d", &vet[i]);
    }

    for(i = 0; i < n; i ++){
        printf("%i\n", vet[i]);
    }
 
    for(i = n-1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(vet[j] > vet[j+1]){
                swap(vet, j, j+1);
            }
        }
    }
    for(i = 0; i < n; i ++){
        printf("%d\n", vet[i]);
    }


    return 0;
}