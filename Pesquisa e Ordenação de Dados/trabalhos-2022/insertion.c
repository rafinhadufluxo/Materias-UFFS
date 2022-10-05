#include <stdio.h>

int main(){
    int n, i, j, k, *vet;
    scanf("%d", &n);
    
    printf("\n");

    vet = malloc(sizeof(int)*n);

    for(i = 0; i < n; i ++){
        scanf("%d", &vet[i]);
    }
    for(i = 0; i < n; i++){
        k = vet[i];
        j = i - 1;

        while(j >= 0 && vet[j] > k){
            vet[j+1] = vet[j];
            j = j -1;
        }
        vet[j+1] = k;
    }
    printf("\n");
    for (i = 0; i < n; i++){
        
        printf("%d\n",vet[i]);
    }
    return 0;
}