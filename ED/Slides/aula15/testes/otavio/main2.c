#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Selection Sort -- Faz o ordenamento do menor pro maior

typedef struct produto{ //Cria um produto 
    int codigo;
    char nome[20];
    float preco;
} tp_produto;

typedef struct nodo{ //Define os nodos com uma referencia do produto
    tp_produto info;
    struct nodo *next;
    struct nodo *prev;
} tp_nodo;

typedef struct lista{ //Cria a lista com os nodos dentro
    int nItens;
    tp_nodo *first;
    tp_nodo *last;
} tp_lista;

tp_lista* push(tp_lista *lista){ // Adiciona um item
    system("cls || clear");
    tp_nodo* nuevo = malloc(sizeof(tp_nodo));
    printf("Digiteo Codigo: ");
    scanf("%d", &(nuevo->info).codigo);
    printf("Digite o Nome: ");
    getchar();
    fgets((nuevo->info).nome,20,stdin);
    printf("Digite o Valor: ");
    scanf("%f", &((nuevo->info).preco));
    getchar();
    // Acima pega os dados do produto

    if(lista->nItens==0){ // Se a lista está vazia
        lista->first=nuevo;
        lista->last=nuevo;
        nuevo->next=NULL;
        nuevo->prev=NULL;
    }
    else{ // Se não estiver, adiciona como primeiro elemento da lista
        lista->first->prev= nuevo;
        nuevo->next =lista->first;
        nuevo->prev =NULL;
        lista->first=nuevo;
    }
    lista->nItens++;
    return  lista;
}

tp_lista* pop(tp_lista *lista){ // Remove um item da lista
    if(lista->nItens==0){
        printf("Lista vazia\n");
        return lista;
    }
    int i;
    printf("A lista possui %d elementos\n", lista->nItens);
    printf("Digite o item que deseja remover: ");
    scanf("%d", &i);
    tp_nodo *p;
    p=lista->first;
    int cont=0;
    for(p;p!=NULL;p=p->next){ // Percorre a lista até achar o item que deseja remover
        cont++;
        if(cont==i)
            break; 
    }
    if(p==lista->first){ // Se for o primeiro
        lista->first=p->prev;
        (p->prev)->next=NULL;
        lista->nItens--;
    }
    if(p==lista->last){ // Se for o ultimo
        lista->last=p->next;
        (p->next)->prev=NULL;
        lista->nItens--;
    }
    else{ // Se estiver no meio
        p->prev->next=p->next;
        p->next->prev=p->prev;
        lista->nItens--;
    }
    free(p); // F ;-;
}

void imprime(tp_lista *lista){ // Printa a lista 
    tp_nodo *p;
    p=lista->first;
    system("clear");
    if(lista->nItens==0){
        printf("Lista vazia\n");
    }
    else {
        for(p;p!=NULL;p=p->next){
        printf("Codigo do produto: %d\n", (p->info).codigo);
		printf("Nome: %s", (p->info).nome);
		printf("Preco: %.2f", ((p->info).preco));
		printf("\n\n");
        }
    }
}

tp_lista* sort(tp_lista* lista){ // Aqui a mágica acontece // Ordenação
	tp_nodo *p, *i, *ultimo, *proximo;		// pronteiros auxiliares
	int codigo,cont;
	for(p=(lista->first)->next; p!=NULL; p=p->next){ // Percorre a lista
		//p=p->next;
		codigo=(p->info).codigo; // Pega o codigo do ponteiro                  
		i=p->prev; 
		cont=0;
		ultimo=NULL;
		while(i!=NULL && ((i->info).codigo) > codigo){
			ultimo=i;
			i=i->prev;
			cont=1;
		}
		if(cont==1){
			if(p->next!=NULL){
				(p->next)->prev=p->prev;
			}
			if(p->prev!=NULL){
				(p->prev)->next=p->next;
			}
			if(i==NULL){
				ultimo->prev=p;
				lista->first=p;
				p->next=ultimo;
				p->prev=i;
			}
			else{
				p->prev=i;
				p->next=i->next;
				i->next=p;
				(p->next)->prev=p;	// Eu n lembro como fiz isso, só sei que funciona kkkk
			}
		}
	}
}


int main(){
    tp_lista *lista = malloc(sizeof(tp_lista));
    int x;
    lista->first=NULL;
    lista->last=NULL;
    lista->nItens=0;
    do{
        printf("-----------------");
        printf("\nMenu\n\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Imprime\n");
				printf("4 - Sort\n");
        printf("0 - Sair\n");
        printf("-----------------\n");
        scanf("%d", &x);

        switch(x){
            case 1: lista= push(lista); break;
            case 2: lista = pop(lista); break;
            case 3: imprime (lista); break;
	    			case 4: sort (lista); break;

        }
    }while(x!=0);
}
