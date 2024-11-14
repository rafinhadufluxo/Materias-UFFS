#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode{//Tarefa
	int id;
	char note[50];
	int deadline;
	int state;

	struct listNode *prev, *next;
};
typedef struct listNode node;

struct listSent{//Aponta para o início e o fim da lista
	node *head, *tail;
};
typedef struct listSent list;

void initList(list *sent){
	sent->head = NULL;
	sent->tail = NULL;
}

void addTask(list *sent, int i){//declarar a Task no main e alocar na função
	node *aux;
	aux = (node *)malloc(sizeof(node));
	aux->id = i;
	printf("Informe a Descrição da tarefa: ");
	scanf("%s",aux->note);
	printf("Informe o tempo para a conclusão da tarefa: ");
	scanf("%d",&aux->deadline);
	aux->state = 0;

	aux->next = aux->prev = NULL;

	if(sent->head==NULL){
		sent->head = aux;
		sent->tail = aux;
	}
	else{
		aux->prev = sent->tail;
		sent->tail->next = aux;
		sent->tail = aux;
	}
}
void finishTask(list *sent, int key){
	node *aux;
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		if(aux->id == key){
			aux->state = 1;
			return;
		}
	}
		printf("ID não encontrado\n");
}


void removeTask(list *sent, int key){
	node *aux;
	if(sent->head == sent->tail){//Caso a lista tenha apenas 1 item
		aux = sent->head;//declarar o aux
		if(aux->id == key){//checar se o ID bate
			aux = sent->head;
			sent->head = NULL;
			sent->tail = NULL;
			free(aux);
			return;
		}
	}
	for(aux=sent->head;aux!=NULL;aux=aux->next){//Procurar o ID = Key
		if(aux->id == key){
			if(aux == sent->head){
				sent->head = aux->next;
				sent->head->prev = NULL;
			}
			else{
				aux->prev->next = aux->next;
			}
			if(aux == sent->tail){
				sent->tail = aux->prev;
				sent->tail->next = NULL;
			}
			else{
				aux->next->prev = aux->prev;
			}
			free(aux);
			return;
		}
	}
		printf("ID não encontrado\n");
}

void printList(list *sent,int command){
	node *aux;
	if(command>3) return;
	if(command<0) return;
	if(command<=2){//Caso 1 ou 2 (Todas e Pendentes)
		for(aux=sent->head;aux!=NULL;aux=aux->next){
			if(aux->state == 0){
				printf("(%d) ",aux->id);
				printf("%dh - ",aux->deadline);
				printf("%s - ",aux->note);
				printf("PENDENTE\n");
			}
		}
	}
	if(command%2!=0){//Caso 1 ou 3 (Todas e Concluídas)
		for(aux=sent->head;aux!=NULL;aux=aux->next){
			if(aux->state == 1){
				printf("(%d) ",aux->id);
				printf("%dh - ",aux->deadline);
				printf("%s - ",aux->note);
				printf("CONCLUÍDA\n");
			}
		}
	}
}

// 		state = 0 (ATIVA)
// 		state = 1 (CONCLUÍDA)

void mainMenu(int command){
	printf("\nDigite 1 para chamar o menu ");
	scanf("%d",&command);

	if(command == 1){
		printf("\n-------Sistema de Gerenciamento de Tarefas v1.0-----------\n");
		printf("Digite o número:\n");
		printf("1 - Adicionar Tarefa\n");
		printf("2 - Visualizar Tarefas\n");
		printf("3 - Finalizar Tarefa\n");
		printf("4 - Remover Tarefa\n");
		printf("0 - Encerrar Programa\n");
	}
	else mainMenu(command);
	
}
int main(){
	list sent;
	int command=999;
	int i=0;
	int key;

	initList(&sent);

	while(command!=0){
		mainMenu(command);
		scanf("%d",&command);
		if(command == 1){//Adicionar
			i = i+1;
			addTask(&sent, i);
		}
		if(command == 2){//Visualizar
			printf("\n-----Modo de visualização-----\n");
			printf("1 - Todas as Tarefas\n");
			printf("2 - Tarefas Ativas\n");
			printf("3 - Tarefas Concluídas\n");
			scanf("%d",&command);
			printList(&sent,command);
			command = 999;
		}
		if(command == 3){//Concluir
			printf("\nInforme a ID da tarefa a ser finalizada\n");
			scanf("%d",&key);
			finishTask(&sent,key);
		}
		if(command == 4){//Remover
			printf("\nInforme a ID da tarefa a ser removida\n");
			scanf("%d",&key);
			removeTask(&sent,key);
		}
	}
	return 0;
}
