/*
 *
 *		Trabalho T1
 *	Pesquisa e Ordenação de Dados
 *	Erickson G. Müller
 *	Mat: 20230001178
 *	03 – Implemente a ordenação linear radix sort.
 *	Ordenação: Radix Sort
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


				/* 
	---Lista--- 
.Estrutura dos nodes da lista
..Sentinela da lista
...Append_to_List
				*/
				//Estrutura Lista
struct tlist{
	int valor;
	struct tlist* next;
};
typedef struct tlist nodelist;


struct listSent{
	nodelist *head, *tail;
};
typedef struct listSent list;

				//Operações Lista
///////////////////////////////////
void createList(list *sent){
//Função seta a variável sentinela, declarada na Main
	sent->head = NULL;
	sent->tail = NULL;
}
void appendtoList(list *sent, int i){
//Adiciona um node com o valor i à lista
	nodelist *aux;
	aux = (nodelist *)malloc(sizeof(nodelist));
	aux->valor = i;
	aux->next = NULL;

	if(sent->head==NULL){//Verifica se a lista é vazia
		sent->head = aux;
		sent->tail = aux;
	}
	else{
		sent->tail->next = aux;
		sent->tail = aux;
	}
}
void printList(list *sent){
//Imprimir a Lista
	nodelist *aux;
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		printf(" %d ", aux->valor);
	}
}
///////////////////////////////////


				/*
	---Fila--- 
.Estrutura dos nodes da fila
..Sentinela da fila
...Enqueue (direto da lista)

				*/
				// Estrutura Fila
struct tqueue{
	int valor; 
	struct tqueue *next;
};
typedef struct tqueue nodefila;

struct queueSent{
	nodefila *head;
	nodefila *tail;
};
typedef struct queueSent fila;
				//Operações Fila
///////////////////////////////////

void enQueue(nodelist *listVector, fila *fsent, int vectorLen){
//Função transforma um Vetor em Fila
	int i;
	nodefila *aux;
	fsent->head = NULL;//createFila()
	fsent->tail = NULL;//createFila()
	for(i=0;i<vectorLen;i++){//CALCULAR O TAMANHO DO VETOR
		aux = (nodefila *)malloc(sizeof(nodefila));
		aux->valor = listVector[i].valor;
		aux->next = NULL;
		if(fsent->head==NULL){//i=0
			fsent->head = aux;
		}
		else{
			fsent->tail->next = aux;
		}
		fsent->tail = aux;

	}
}
void printFila(fila *fsent){
//Imprimir Fila
	nodefila *aux;
	for(aux=fsent->head;aux!=NULL;aux=aux->next){
		printf(" %d ",aux->valor);
	}
}	

///////////////////////////////////
				//Operações Vetor
void generateVector(int randomMin, int randomMax, int *vector, int vectorLen){
//O vetor é gerado aleatóriamente
	int randomNumber;
	int i;
	for(i=0;i<vectorLen;i++){
		randomNumber = randomMin+rand() % (randomMax-randomMin+1);
		vector[i] = randomNumber;
	}
}
void vectorizeList(list *sent, nodelist *listVector){
//Transforma a Lista em Vetor
	listVector[0].valor = sent->head->valor;
	nodelist *aux;
	int i=0;
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		listVector[i].valor = aux->valor;
		listVector[i].next = aux->next;
		i++;
	}
}
void printVector(int *vector, int vectorLen){
//Imprimir vetor de ints, para testes, precisa indicar o comprimento
	int i;
	for(i=0;i<vectorLen;i++){
		printf(" %d ", vector[i]);
	}
}
void printNodeVector(nodelist *listVector, int vectorLen){
//Imprime o vetor de Nodes
	int i;
	for(i=0;i<vectorLen;i++){
		printf(" %d ", listVector[i].valor);
	}
}
///////////////////////////////////
					/*
	--Radix Sort--
					*/

void counting(nodelist *listVector, int vectorLen, int pos){
	nodelist aux[vectorLen];
	int count[10];
	int digit;
	int i;
	for(i=0;i<10;i++){//Inicializa o vetor count
		count[i]=0;
	}
	for(i=0;i<vectorLen;i++){//Conta os dígitos
		digit = (listVector[i].valor/pos)%10;
		count[digit]++;
	}
	for(i=1;i<10;i++){//Soma acumulada do vetor count
		count[i] = count[i]+count[i-1];
	}
	for(i=vectorLen-1;i>=0;i--){//Posiciona os nodos no vetor aux
		digit = (listVector[i].valor/pos)%10;
		count[digit]--;//Posição no aux
		aux[count[digit]] = listVector[i];
	}
	for(i=0;i<vectorLen;i++){//Passa o vetor aux para o vetor inicial
		listVector[i] = aux[i];
	}
}
int buscaMaior(nodelist *listVector, int vectorLen){
	int maior;
	int i;
	maior = 0;//Radix ordena a partir do 0
	for(i=0;i<vectorLen;i++){
		if(listVector[i].valor>maior){
			maior = listVector[i].valor;
		}
	}
	return maior;
}
void radixSort(nodelist *listVector, int vectorLen){
	int pos;
	int maior;//Maior valor do vetor de nodelist
	maior = buscaMaior(listVector, vectorLen);
	for(pos=1;maior/pos>0;pos=pos*10){//Chama o counting até o dígito de maior valor
		counting(listVector, vectorLen, pos);
	}
}

///////////////////////////////////

int main(){
	//Declarações
	int i;
	//
	int maxNum=200;//Número Máximo
	int vectorLen=20;//Comprimento do Vetor
	//
	int vector[vectorLen];//Vetor de ints
	nodelist listVector[vectorLen];//Vetor de nodelists
	fila fsent;//Sentinela da Fila
	list sent;//Sentinela da Lista
	
	//1-Criação do vetor
	generateVector(0, maxNum, vector, vectorLen);
	printf("\nVetor Inicial:\n"); //DEMONSTRAÇÃO
	printVector(vector, vectorLen);//DEMONSTRAÇÃO

	//2-Criação da Lista
	createList(&sent);	
	for(i=0;i<vectorLen;i++){
		// o loop está fora da função pois appendtoList não é uma função de transformar vetor em lista
		appendtoList(&sent,vector[i]);
	}
	printf("\nLista encadeada não ordenada:\n");//DEMONSTRAÇÃO
	printList(&sent);//DEMONSTRAÇÃO
	
	//3-Passar da Lista para o Vetor
	vectorizeList(&sent, listVector);//Transforma a Lista em Vetor
	
	//4-Ordenação do vetor
	radixSort(listVector, vectorLen);// Ordena o Vetor
	printf("\n Vetor ordenado:\n");//DEMONSTRAÇÃO
	printNodeVector(listVector,20);//DEMONSTRAÇÃO
	
	//5-Passar do Vetor para a Fila
	enQueue(listVector,&fsent,vectorLen);//Transforma o vetor em fila
	printf("\n Fila ordenada:\n");//DEMONSTRAÇÃO
	printFila(&fsent);///DEMONSTRAÇÃO

	return 0;
}
