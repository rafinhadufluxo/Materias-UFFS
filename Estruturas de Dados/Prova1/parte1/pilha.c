#include <stdio.h>
#include <stdlib.h>

typedef struct no_pilha{
    char caracter;
    struct no_pilha *ant;
} No_pilha;

typedef struct pilha{
    struct no_pilha *topo;
} Pilha;

void inicPilha(Pilha *pilha);
int empilha(Pilha *pilha, char caracter);
int pilhaVazia(Pilha *pilha);
char desempilha(Pilha *pilha);

int main(){
	int n, i, j, cont = 0, aux;
	Pilha *s = malloc(sizeof(Pilha));
	char v[] = { 'F', 'A', 'C', 'E' }, v2[4];

	inicPilha(s);

	for(i = 0; i < 4; i++)
		empilha(s, v[i]);

	scanf("%d", &n);
	

	for(i = 0; i < n; i++){
		scanf("%c %c %c %c", &v[0], &v[1], &v[2], &v[3]);
		
		for(j = 3; j >= 0; j--){
			v2[j] = desempilha(s);
		}

		aux = 0;

		for(j = 0; j < 4; j++){
			if(v[j] == v2[j]);
				aux++;
		}

		if(aux == 4) cont++;
    for(j = 0; j < 4; j++){
				empilha(s, v[j]);
    }
	}

	printf("%d\n", cont);

	return 0;
}

void inicPilha(Pilha *pilha){
    pilha->topo = NULL;
}

int pilhaVazia(Pilha *pilha){
    if(pilha->topo == NULL)
        return 1;
    else
        return 0;
}

int empilha(Pilha *pilha, char caracter){
    No_pilha *novo = malloc(sizeof(Pilha));
    novo->caracter = caracter;
    novo->ant = NULL;

    if(pilha->topo == NULL)
    {
        pilha->topo = novo;
        return 1;
    }
    else
    {
        novo->ant = pilha->topo;
        pilha->topo = novo;
        return 1;
    }

    return 0;
}

char desempilha(Pilha *pilha){
    No_pilha *aux;
    char topo;
    aux = pilha->topo;
    if(pilha->topo->ant != NULL)
        pilha->topo = pilha->topo->ant;
    else
        pilha->topo = NULL;
    topo = aux->caracter;
    return topo;
}