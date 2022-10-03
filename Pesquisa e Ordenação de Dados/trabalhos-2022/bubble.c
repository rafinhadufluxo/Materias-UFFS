#include <stdio.h>

int main(){
    int n, *vet, i, j;
    scanf("%d", &n);

    vet = malloc(n*sizeof(int));
    
    for(i = 0; i < n; i ++){
        printf("i: \n");
        scanf("%d", &vet[i]);
    }

    for(i = 0; i < n; i ++){
        printf("i: %i\n", vet[i]);
    }
 
    for(i = n-1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(vet[j] > vet[j+1]){
                printf("non ecxiste\n");
                swap(vet, j, j+1);
            }
        }
    }
    for(i = 0; i < n; i ++){
        printf("r: %d\n", vet[i]);
    }


    return 0;
}