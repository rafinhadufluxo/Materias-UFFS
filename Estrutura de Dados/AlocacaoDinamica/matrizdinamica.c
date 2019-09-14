#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j, colunas, k;
	printf("Digite o numero de linhas: ");
	scanf("%d", &i);
	int *vetcoluna[i];

	for(j = 0; j < i; j++){
		printf("Digite o número de colunas para linha [%d]: ", j);
		scanf("%d", &colunas);
		vetcoluna[j] = (int *) malloc((colunas + 1) * sizeof(int));
		for(k = 0; k < colunas; k++)
			scanf("%d", &vetcoluna[j][k]);
		vetcoluna[j][k] = -1997;
	}

	for(j = 0; j < i; j++){
		for(k = 0; vetcoluna[j][k] != -1997; k++)
			printf("%d ", vetcoluna[j][k]);
		printf("\n");
		free(vetcoluna[j]);
	}

	free(vetcoluna);

	return 0;
}