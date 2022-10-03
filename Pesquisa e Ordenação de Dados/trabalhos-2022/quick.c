#include <stdio.h>
int partition(int *vet, int i, int f){
    int pv = vet[f];
    int j = i;
    for(j = i; j <= f;){
        if(vet[j] <= pv){
            vet[j] = vet[i];
            vet[i] = vet[j];
            j = j+1;
        }   
    }
    vet[i] = vet[f];
    vet[f] = vet[i];
    return j;
}
int quick(int *vet, int i, int f){
    i = 0;
    if(i < f){
        int p = partition(*vet, i, f);
        quick(*vet, i, f);
        quick(*vet, p+1, f);
    }
}
int main(){
    int n, *vet, i, j, f, p;
    scanf("%d", &n);

    vet = malloc(n*sizeof(int));
    
    for(i = 0; i < n; i ++){
        printf("i: \n");
        scanf("%d", &vet[i]);
    }
    f = vet[n-1];
    quick(*vet, i, f);
    
    for(int k = 0; i<n; i++){
        printf("%d\n",vet[i]);
    }
    return 0;
}
    