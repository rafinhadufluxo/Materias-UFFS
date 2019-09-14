#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void push(char saida[], int *topo){
	saida[*topo] = '\0';
	*topo -= 1;
}

void pop(char entrada, char saida[], int *topo){
	saida[*topo] = entrada;
	*topo += 1;
}

int main(){
	char entrada[MAX];
	char saida[MAX];

	int topo = 0, i, k;

	fgets(entrada, MAX, stdin);

	entrada[strlen(entrada) - 1] = '\0';

	i = 0;

	do{
		if(entrada[i] != ' ' && entrada[i] != '\0'){
			pop(entrada[i], saida, &topo);
		}
		
		else if(entrada[i] == ' ' || entrada[i] == '\0'){
			for(k = topo; k > 0; k--){
				printf("%c", saida[k - 1]);
				push(saida, &topo);
			}
		
			printf(" ");
		}
		
		i++;

	}while(entrada[i - 1] != '\0');
	
	printf("\n");
}