#include <stdio.h>
#include <stdlib.h>

int main(){
	int *valor;
	int i, j;

	valor = (int *) malloc(5 * sizeof(int));

	for(i = 0, j = 0; scanf("%d", &valor[i]); i++, j++){
		if(j == 4){
			j = 0;
			valor = (int *) realloc(valor, (i + 5) * sizeof(int));
		}
	}

	for(j = 0; j < i; j++){
		printf("vetor[%d] = %d\n", j, valor[j]);
	}

	free(valor);
}
