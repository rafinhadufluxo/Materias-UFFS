#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
    int codigo;
    char nome[20];
    float preco;
} tp_produto;

typedef struct nodo{
    tp_produto info;
    struct nodo *next;
    struct nodo *prev;
} tp_nodo;

typedef struct lista{
    int nItens;
    tp_nodo *first;
    tp_nodo *last;
} tp_lista;

tp_lista* push(tp_lista *lista){
    system("cls || clear");
    tp_nodo* nuevo = malloc(sizeof(tp_nodo));
    printf("Digite el Codego: ");
    scanf("%d", &(nuevo->info).codigo);
    printf("Digite el Nombre: ");
    getchar();
    fgets((nuevo->info).nome,20,stdin);
    printf("Digite el Valor: ");
    scanf("%f", &((nuevo->info).preco));
    getchar();

    if(lista->nItens==0){
        lista->first=nuevo;
        lista->last=nuevo;
        nuevo->next=NULL;
        nuevo->prev=NULL;
    }
    else{
        lista->first->prev= nuevo;
        nuevo->next =lista->first;
        nuevo->prev =NULL;
        lista->first=nuevo;
    }
    lista->nItens++;
    return  lista;
}

tp_lista* pop(tp_lista *lista){
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
    for(p;p!=NULL;p=p->next){
        cont++;
        if(cont==i)
            break; 
    }
    if(p=lista->first){
        lista->first=p->prev;
        (p->prev)->next=NULL;
        lista->nItens--;
    }
    if(p=lista->last){
        lista->last=p->next;
        (p->next)->prev=NULL;
        lista->nItens--;
    }
    else{
        p->prev->next=p->next;
        p->next->prev=p->prev;
        lista->nItens--;
    }
    free(p);
}

void imprime(tp_lista *lista){
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
        printf("0 - Sair\n");
        printf("-----------------\n");
        scanf("%d", &x);

        switch(x){
            case 1: lista= push(lista); break;
            case 2: lista = pop(lista); break;
            case 3: imprime (lista); break;

        }
    }while(x!=0);
}