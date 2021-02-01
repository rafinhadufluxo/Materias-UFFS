#include <stdio.h>
#include <stdlib.h>

struct lista2
{
    int info;
    struct lista2 *ant;
    struct lista2 *prox;
};
typedef struct lista2 Lista2;

/* inserção no início - Recebe como parametro a lista e o valor inteiro a ser inserido no início da lista */
Lista2 *insere(Lista2 *l, int v)
{

    /* Cria um novo elemento na lista com */
    Lista2 *novo = (Lista2 *)malloc(sizeof(Lista2));

    /* Preenche o campo info do novo elemento criado com o valor inteiro */
    novo->info = v;
    /* O novo elemento aponta para o inicio da lista. Lembre que a lista na verdade é um ponteiro para o primeiro elemento, assim o novo elemento ao ser incluido no   inicio   da lista deve apontar para o proximo que é o inicio da lista, ou seja, aquele que era o primeiro elemento da lista anteriormente */
    novo->prox = l;

    /* Como o novo elemento é inserido no inicio da lista, não há elemento anterior. Por isso, armazena a constante NULL no ponteiro que aponta para o elemento anterior*/
    novo->ant = NULL;

    /* verifica se lista não está vazia */
    if (l != NULL)
        l->ant = novo;

    return novo;
}

/* função consutla: consulta os elementos da lista */
void consulta(Lista2 *l)
{
    Lista2 *p;
    for (p = l; p != NULL; p = p->prox)
        printf("\n Valor %d ", p->info);
}

/* função busca: busca um elemento na lista */
Lista2 *busca(Lista2 *l, int v)
{
    Lista2 *p;
    for (p = l; p != NULL; p = p->prox)
        if (p->info == v)
            return p;

    return NULL;
    /* não achou o elemento */
}

/* função retira: retira elemento da lista */
Lista2 *excluir(Lista2 *l, int v)
{
    /* Busca o elemento a ser removido da lista */
    Lista2 *p = busca(l, v);
    /* se não achou o elemento: retorna lista inalterada */
    if (p == NULL)
        return l;

    /* se o elemento a ser retirado da lista for o primeiro elemento da lista entao o primeiro elemento da lista sera o proximo elemento */
    if (l == p)
    {
        p->prox->ant = NULL;
        l = p->prox;
    }
    else
        /* se o elemento a ser retirado da lista nao for o primeiro da lista entao o elemento anterior deve apontar para o elemento que esta sendo apontado pelo    elemento a ser retirado */
        p->ant->prox = p->prox;

    /* Se o elemento a ser retirado nao for o ultimo, entao o proximo elemento deve apontar para o elemento anterior ao elemento a ser retirado */
    if (p->prox != NULL)
        p->prox->ant = p->ant;

    /* Efetivamente remove o elemento da memoria. Note que o elemento já não faz mais parte da lista pois nao e mais referenciado na lista */
    free(p);

    /* Retorna a lista atualizada */
    return l;
}

/* função que verifica o estado da lista: retorno 1 se vazia ou 0 se não vazia*/
int lista_vazia(Lista2 *lista)
{
    if (lista == NULL)
        return 1;
    else
        return 0;
}

/*função responsável por criar a lista*/
Lista2 *cria(void)
{
    return NULL;
}

int main()
{
    /* Variaveis para opcao do menu, para o elemento a ser excluido e para o elemento a ser localizado pela busca */
    int op, vremover, vbuscar, v;

    /* Variavel para apontar para o primeiro elemento da lista */
    Lista2 *lista;

    /* Cria a lista inicialmente vazia */
    lista = cria();

    /* Enquanto o usuario nao escolher a opcao 5 para sair do programa, as opções escolhidas sao executadas */
    while (op != 5)
    {

        /* Imprime o menu principal do programa */
        system("cls");
        printf("\nPrograma Para Manipulacao de Listas Duplamente Encadeada");
        printf("\n1 - Inserir no Final da Lista");
        printf("\n2 - Visualizar Lista");
        printf("\n3 - Buscar Elemento na Lista");
        printf("\n4 - Excluir Elemento");
        printf("\n5 - Sair do Programa");

        /* Le a opcao do usuario */
        printf("\nEntre com a Opcao Desejada: ");
        scanf("%i", &op);

        /* Conforme a opção escolhida execuca a funcao solicitada que pode ser para inserir, listar, buscar ou remover um elemento da lista */
        switch (op)
        {
        case 1:

            printf("\n Entre com o valor: ");
            scanf("%d", &v);
            lista = insere(lista, v);
            break;
        case 2:
            consulta(lista);
            break;
        case 3:
            printf("Entre com o valor que se deseja buscar: ");
            scanf("%d", &vbuscar);
            busca(lista, vbuscar);
            break;
        case 4:
            printf("Entre com o valor que deseja remover: ");
            scanf("%i", &vremover);
            lista = excluir(lista, vremover);
            break;
        case 5:
            exit(1);
        }
    }
}