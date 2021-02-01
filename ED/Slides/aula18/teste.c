#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//=============================================
typedef struct Aviao
{
    int id;
    char name[100];
    float combustivel;
    char carga[100];
} Aviao;
//=============================================
//Procedimento que imprime Aviao
void print_aviao(Aviao x)
{
    printf("\nCodigo: %d | Nome: %s | Combustivel: %f | Carga: %s", x.id, x.name, x.combustivel, x.carga);
}
//=============================================
//Função que cria nova Aviao
Aviao new_aviao()
{
    Aviao p;
    printf("\nDigite o nome do Aviao:\n");
    scanf("%[^\n]s\n", &p.name);
    fflush(stdin);
    printf("\nDigite a combustivel do Aviao:\n");
    scanf("%f", &p.combustivel);
    printf("\nDigite a carga do Aviao:\n");
    scanf("%[^\n]s\n", &p.carga);
    fflush(stdin);
    return p;
}

typedef struct Celula
{
    struct Celula *prox;
    Aviao Data;
} Celula;
typedef struct Fila
{
    Celula *start;
    Celula *end;
    int TAM;
} Fila;
//=============================================
bool create_queue(Fila *queue)
{
    Celula *cell = (Celula *)malloc(sizeof(Celula));
    if (cell == NULL)
    {
        return false;
    }
    cell->prox = NULL;
    queue->start = cell;
    queue->end = cell;
    queue->TAM = 0;
    return true;
}
//=============================================
bool enqueue(Fila *queue, Aviao x)
{
    Celula *cell = (Celula *)malloc(sizeof(Celula));
    if (cell == NULL)
    {
        return false;
    }
    cell->prox = NULL;
    cell->Data = x;
    queue->end = cell;
    queue->end->prox = cell;
}
//=============================================
void print_queue(Fila *queue)
{
    Celula *aux = queue->start->prox;
    while (aux != NULL)
    {
        print_aviao(aux->Data);
        aux = aux->prox;
    }
}
//=============================================
Aviao dequeue(Fila *queue)
{
    Celula *tmp = queue->start;
    queue->start = queue->start->prox;
    free(tmp);
    queue->TAM--;
    return queue->start->Data;
}
//=============================================
bool enqueue_priority(Fila *queue, Aviao x)
{
    Celula *aux = (Celula *)malloc(sizeof(Celula));
    if (aux == NULL)
    {
        return false;
    }
    aux->prox = NULL;
    aux->Data = x;
    Celula *ant = queue->start;
    while (ant->prox != NULL && ant->prox->Data.combustivel <= 150) 
    {
        ant = ant->prox;
    }
    aux->prox = ant->prox;
    ant->prox = aux;
    if (aux->prox == NULL)
    {
        queue->end = aux;
    }
    queue->TAM++;
    return true;
}
//=============================================
Fila clone_queue(Fila *queue, Fila *clone)
{
    Fila aux;
    create_queue(&aux);
    Aviao tmp = dequeue(queue);
    while (tmp.id != NULL)
    {
        enqueue(&aux, tmp);
        tmp = dequeue(queue);
    }
    tmp = dequeue(&aux);
    while (tmp.id != NULL)
    {
        enqueue(clone, tmp);
        enqueue(queue, tmp);
        tmp = dequeue(queue);
    }
    return *clone;
}
//=============================================
Fila concatenar_queue(Fila *queue, Fila *queue2)
{
    //queue [0,1,2,3,4] //queue2 [0,1,2,3,4]
    Fila aux, concatenada;
    create_queue(&aux);
    Aviao tmp = dequeue(queue);
    while (tmp.id != NULL)
    {
        //aux [0,1,2,3,4]
        //queue [NULL]
        enqueue(&aux, tmp);
        tmp = dequeue(queue);
    }
    tmp = dequeue(queue2);
    while (tmp.id != NULL)
    {
        //aux [0,1,2,3,4,0,1,2,3,4]
        //queue [0,1,2,3,4]
        enqueue(&aux, tmp);
        enqueue(queue, tmp);
        tmp = dequeue(queue);
    }
    tmp = dequeue(&aux);
    while (tmp.id != NULL)
    {
        //concatenada [0,1,2,3,4,0,1,2,3,4]
        //aux [NULL]
        enqueue(&concatenada, tmp);
        tmp = dequeue(queue);
    }
    return concatenada;
}
//=============================================
void invert_queue(Fila *queue)
{
    int tam = queue->TAM;
    Aviao *tmp = (Aviao *)malloc(sizeof(Aviao));
    // queue [0,1,2,3,4]
    for (int i = 0; i < tam; i++)
    {
        tmp[i] = dequeue(queue);
        // tmp [0,1,2,3,4]
        // queue [ NULL ]
    }
    for (int i = tam - 1; i > 0; i++)
    {
        // queue[4,3,2,1,0]
        // tmp [NULL]
        enqueue(queue, tmp[i]);
    }
}
//=============================================
int menu()
{
    int op;
    printf("\n---------- LISTA DE PESSOAS ----------\n");
    printf("1 - Adicionar aviao\n");
    printf("2 - Lista numero de avioes\n");
    printf("3 - Listar todos os avioes\n");
    printf("4 - Autorizar decolagem\n");
    printf("5 - Listar caracteristicas do primeiro aviao\n");
    printf("6 - Inserir aviao em prioridade de combustivel(150L)\n"); 
    printf("0 - Sair\n");
    scanf("%d", &op);

    return op;
}
//=============================================
int main()
{
    Fila aux;
    Fila aeroporto;
    Aviao aviao;
    Aviao a_aux;
    int op;
    create_queue(&aeroporto);
    create_queue(&aux);
    do
    {
        op = menu();
        int id;
        switch (op)
        {
        case 1:
            a_aux = new_aviao();
            a_aux.id = aeroporto.TAM + 1;
            enqueue(&aeroporto, a_aux);
            break;

        case 2:
            printf("O numero de avioes na fila eh:%d", aeroporto.TAM);
            break;

        case 3:
            print_queue(&aeroporto);
            break;

        case 4:
            printf("Decolagem autorizada\n");
            printf("Aviao saindo...\n");
            a_aux = dequeue(&aeroporto);
            print_aviao(a_aux);
            break;

        case 5:
            printf("Listando caracteristicas do primeiro aviao\n");
            print_aviao(aeroporto.start->Data);
            break;

        case 6:
            printf("Adicionando aviao em prioridade\n");
            a_aux = new_aviao();
            enqueue_priority(&aeroporto,a_aux);
            break;

        case 0:
            return 0;
            break;

        default:
            break;
        }

    } while (op != 0);
    return 0;
}