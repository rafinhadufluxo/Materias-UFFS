void swap(int *vet, int i, int j){
    int t = vet[i];
    vet[i] = vet[j];
    vet[j] = t;
}

void in_sort(int *vet, int i, int k){
        while(vet[i] > k && i > 0){
            vet[i+1] = vet[i];
            i = i-1;
            vet[i+1] = k;
        }
    }
