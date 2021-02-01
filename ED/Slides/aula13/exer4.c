#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

struct funcionario{
  int id;
  char nome[41];
  double salario;
  Data nascimento;
  struct funcionario *proximo;
  struct funcionario *anterior;
}; 
typedef struct funcionario Funcionario;

/*Imprime a lista apartir do primeiro elemento*/
void imprimeListaPrimeiro(Funcionario *primeiro){
	Funcionario *aux;
	printf("\nImprime a lista começando do primeiro.:\n");
	if (primeiro == NULL){
		printf("Lista vazia\n");
		return;
	}
	for (aux = primeiro; aux != NULL; aux = aux->proximo){
		printf("Registro:\n\t id: %d, \n\t nome: %s, \n\t nasc: %d/%d/%d, \n\t salario: %lf\n\n", aux->id, aux->nome, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->salario);
	}
}

/*Imprime a lista apartir do ultimo elemento*/
void imprimeListaUltimo(Funcionario *ultimo){
	Funcionario *aux;
	printf("\nImprime a lista começando do ultimo:\n");
	
	if (ultimo == NULL){
		printf("Lista vazia\n");
		return;
	}
	for (aux = ultimo; aux != NULL; aux = aux->anterior){
		printf("Registro:\n\t id: %d, \n\t nome: %s, \n\t nasc: %d/%d/%d, \n\t salario: %lf\n\n", aux->id, aux->nome, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->salario);
	}
}



Funcionario *deletaElemento(Funcionario *primeiro, Funcionario *ultimo, int key){
	Funcionario *aux, *anterior;
	for (aux = primeiro; aux != NULL; aux = aux->proximo){
		if (aux->id == key){
			if (aux == primeiro) {
                primeiro = primeiro->proximo;

				if (primeiro == NULL){//se isso acontecer é porq a lista ficou vazia, ela só tinha um elemento e esse foi excluido. Então retorn null;
					free(ultimo);
					ultimo = NULL;
					return NULL;
				}

				primeiro->anterior = NULL; //faz o anterior do novo primeiro ser null;

            } else if (aux == ultimo){
				ultimo = ultimo->anterior;
				ultimo->proximo = NULL;
			}else {
				anterior = aux->anterior;
				anterior->proximo = aux->proximo;
				aux->proximo->anterior = anterior;

            }
			free(aux);
		}
	}
	return primeiro; /*Ainda estamos retornando o primeiro*/
}

/*Limpa toda a lista, da free em todos os endereços de memoria.*/
void limpaTodaLista(Funcionario *primeiro){
	Funcionario *aux;
	while (primeiro != NULL){
		aux = primeiro;
		primeiro = primeiro->proximo;
		free(aux);
	}
}



int main(){
	Funcionario *primeiro = NULL, *aux, *ultimo;
	int n,i;

	/*Lendo os valores*/
	printf("Digite o número de valores: ");
	scanf("%d", &n);

	for (i=0; i<n; i++){
		 aux = malloc(sizeof(Funcionario));
		printf("\nDigite o id: \n");
        scanf("%d%*c", &aux->id); //o %*c representa ler um caractere mas não gravar, só outra forma de eliminar o '\n', pois ele atrapalha o fgets

		printf("\nDigite o nome: ");
        fgets(aux->nome, sizeof(aux->nome), stdin);
		aux->nome[strcspn(aux->nome, "\n")] = '\0'; //Trocando o \n por \0;
        printf("\nDigite a data nascimento (formato dd/mm/yyyy): ");
        scanf("%d/%d/%d", &aux->nascimento.dia, &aux->nascimento.mes, &aux->nascimento.ano);
        printf("\nDigite o salario: ");
        scanf("%lf", &aux->salario);
        aux->proximo = NULL;
		aux->anterior = NULL;

        if (primeiro == NULL){ //Ele é o primeiro
			primeiro=aux;
			ultimo = aux;
		}else{ //faz o encadeamento, inserindo o elemento no fim da lista
			aux->anterior = ultimo;
			ultimo->proximo = aux;
			ultimo = aux;
		}
		
	}
	/*Imprimindo a lista como a B pede*/
	imprimeListaPrimeiro(primeiro);
	imprimeListaUltimo(ultimo);


	printf("\nExcluindo elemento com id 2\n");
	primeiro = deletaElemento(primeiro, ultimo, 2); //deletando o 2, poderia fazer um scanf para pedir o elemento a ser excluido.
	/*Perceba que agora passamos o primeiro e o último elemento da lista, retornamos o primeiro, e o ultimo também será atualizado caso necessário já que é passado por referência.*/

	printf("\nImprimindo a lista após a exclusao: \n");
	/*Imprimindo a lista depois do delete*/
	imprimeListaPrimeiro(primeiro);

	/*Antes de acabar o programa podemos limpar nossa lista.*/
	limpaTodaLista(primeiro);

	printf("\nTerminamos!\n");


	return 0;
}