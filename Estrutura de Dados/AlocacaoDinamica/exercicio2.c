#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2){
	int *vetor3;
	int i, j;

	vetor3 = (int *) malloc((n1 + n2) * sizeof(int));

	for(i = 0; i < n1; i++)
		vetor3[i] = v1[i];

	for(i; i < n2 + n1; i++)
		vetor3[i] = v2[i - n2];

	return vetor3;
}

int main(){
	int vet1[3] = {12, 24, 36};
	int vet2[3] = {14, 28, 42}, i;
	int *vet3 = uniao(vet1, 3, vet2, 3);

	for(i = 0; i < 3 + 3; i++)
		printf("v3[%d] == %d\n", i, vet3[i]);
}
