/*
 *
 * 		Trabalho T2
 * 	Pesquisa e Ordenação de Dados
 * 	Erickson G. Müller
 * 	Mat: 20230001178
 * 	Implementação de Tabela Hash
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
				/*
Estrutura dos Nodes		 *
				 */
struct tlist{
	int valor;
	struct tlist *next;
};
typedef struct tlist hashnode;

				/*
Função Hashing para calcular	 *
o index na tabela.		 *
				 */
int hashing(int k, int M){
	return k%M;//k mod M
}
				/*
Inicializa a tabela		 *
transforma tudo em NULL		 *
				 */
void initHashTable(hashnode **hashTable, int M){
	int i;
	for(i=0;i<M;i++){
		hashTable[i] = NULL;
	}
}

				/*
Função para inserir um valor	 *
na tabela.			 *
ENDEREÇAMENTO SEPARADO		 * 
				*/
void insertNode(hashnode **hashTable, int k, int M){
	int id;
       	id = hashing(k,M);//Calcula o id do valor
	hashnode *aux;
	hashnode *aux2;
	aux = (hashnode *)malloc(sizeof(hashnode));
	aux->valor = k;
	aux->next = NULL;
	if (hashTable[id] == NULL){
		hashTable[id] = aux;
	}
	else{
		aux2 = hashTable[id];
		// encontra o último da lista
		while (aux2->next != NULL){
			aux2 = aux2->next;
		}
		aux2->next = aux;
	}
}
				/*
Função para Imprimir Tabela	 *
				 */
void printTable(hashnode **hashTable, int M){
	int i;
	printf("ID | Table\n");
	for(i=0;i<M;i++){
		if(i<10) printf("0");
		printf("%d |", i);
		hashnode *curr = hashTable[i];
		while (curr != NULL) {
			printf(" %d ->", curr->valor);
			curr = curr->next;
		}
		printf(" NULL\n");
	}
}
				/*
Função para Liberar		 *
Memória Alocada			*	
				 */
void freeMemory(hashnode **hashTable, int M){
	int i;
	hashnode *aux;
	hashnode *aux2;
	for(i=0;i<M;i++){
		aux = hashTable[i];
		while(aux2!=NULL){
			aux2 = aux;
			aux = aux->next;
			free(aux2);
		}
		hashTable[i] = NULL;
	}
}
				/*
Função para ler o arquivo .txt	 *
e chamar a função insertNode	 *
				 *
				 */
void importData(hashnode **hashTable, int M){
	FILE *text = fopen("casos_de_teste.txt","r");//Lê o arquivo
	if(text == NULL){//Debugg
		printf("Renomear arquivo para casos_de_teste.txt\n");
		return;
	}
	char line[256];//Tamanho da linha
	while(fgets(line,256,text)){// Lê os 256 chars da linha
		char *item = strtok(line, ";");// Separa os números por; (token)
		while(item != NULL){
			int valor;	
			valor = atoi(item);//int(item)
			insertNode(hashTable, valor, M);
			item = strtok(NULL, ";");
		}
	}
	fclose(text);
}
				/*
Função Main			 *
				 */
int main(){
	int M = 23; //Tamanho da tabela Hash
		    //Não foi usado como atributo de hashTable
		    //pois é um valor fixado no problema
	hashnode *hashTable[M]; 
	initHashTable(hashTable, M);
	importData(hashTable, M);
	printTable(hashTable, M);
	freeMemory(hashTable, M);
	return 0;
}
