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
	hashnode *curr;
	hashnode *nexT;
	curr = (hashnode *)malloc(sizeof(hashnode));
	curr->valor = k;
	curr->next = NULL;
	if (hashTable[id] == NULL){
		hashTable[id] = curr;
	}
	else{
		nexT = hashTable[id];
		// encontra o último da lista
		while (nexT->next != NULL){
			nexT = nexT->next;
		}
		nexT->next = curr;
	}
}
				/*
Função para Imprimir Tabela	 *
				 */
void printTable(hashnode **hashTable, int M){
	printf("ID | Table\n");
	
}
				/*
Função para Liberar		 *
Memória Alocada			*	
				 */
void freeMemory(hashnode **hashTable, int M){
	int i;
	hashnode *curr;
	hashnode *nexT;
	for(i=0;i<M;i++){
		curr = hashTable[i];
		while(nexT!=NULL){
			nexT = curr;
			curr = curr->next;
			free(nexT);
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
	char line[25];//Tamanho da linha
	while(fgets(line,25,text)){// Lê os 25 chars da linha
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
	int M = 25; //Tamanho da tabela Hash
		    //Não foi usado como atributo de hashTable
		    //pois é um valor fixado no problema
	hashnode *hashTable[M]; 
	initHashTable(hashTable, M);
	importData(hashTable, M);
	freeMemory(hashTable, M);
	return 0;
}
