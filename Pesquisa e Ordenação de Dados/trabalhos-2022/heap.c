void heapsort(int vet[], int n) {
	for(int i = n/2-1; i >= 0; i--){
        criaHeap(vet, n, i);
    }
    for(int j = n-1; j > 0; j--){
        int aux = vet[0];
        vet[0] = j;
        vet[j] = aux;
        criaHeap(vet, j, 0);
    } 
}

void criaHeap(int vet[], int n, int i) {
	int raiz = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;
    //se o filho esquerdo é maior que a raiz
    if(esq < n && vet[esq] > vet[raiz]){
        raiz = esq;
    }
    if(dir < n && vet[dir] > vet[raiz]){
        raiz = dir;
    }
    if(raiz != i){
        int aux = vet[i];
        vet[i] = vet[raiz];
        vet[raiz] = aux;
        criaHeap(vet, n, raiz);
    } 
}

int main() {
    int n, k, *vetor;
    printf("tamanho:\n");
	scanf("%d", &n);
    
    vetor = malloc(sizeof(int)*n);
    for(k = 0; k < n; k ++){
        scanf("%d", &vetor[k]);
    }
    
	heapsort(vetor, n);

	for (k = 0; k < n; k++) {
		printf("%d ", vetor[k]);
	}
	return 0;
}