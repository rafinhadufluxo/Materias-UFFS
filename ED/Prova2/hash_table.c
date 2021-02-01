/*
 * Tarefa de laboratorio 13 - Avaliacao 2 - Parte 1 - Tabelas Hash!
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Rafa Arruda
 * Matricula: 1721101029
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


typedef struct no
{
    struct no *prox;
    int info;
} Node;

typedef struct
{
    Node *first;
    Node *last;

} Hash;



void imprimindoTUDO(Node *first, int x)
{
    Node *aux = first;
    printf("%d -> ", x);
    // 0 ->
    while (aux != NULL)
    {
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
    printf("\\");
    printf("\n");
}

void inserindo(Hash *Tabela, int x, int y)
{
    Node *aux = (Node *)malloc(sizeof(Node));
    aux->info = y;
    aux->prox = NULL;
    if (Tabela[x].first == NULL)
    {
        Tabela[x].first = aux;
    }
    else
    {
        Tabela[x].last->prox = aux;
    }
    Tabela[x].last = aux;
}

void inicializandoValor(Hash *Tabela, int n)
{
    int i = 0;
    while (i < n)
    {
        Tabela[i].first = NULL;
        Tabela[i].last = NULL;
        i++;
    }
}

// tentei implementar a parte de free, porém que nao deu tempo! (Sorry)
// void libera(Hash *Tabela)
// {
//     if (Tabela[i] != NULL)
//     {
//         libera(firsh->esq);
//         libera(last->dir);
//         free(Tabela);
//         Tabela = NULL;
//
//     }
// }

int main()
{
    Hash Tabela[200];
    int chave, numero, n, vai, i, j,r;

    scanf("%d", &n);

    for (j = 0; j < n; j++)
    {
        scanf("%d %d", &chave, &numero);
        inicializandoValor(Tabela, chave);

        // for (i = 0; i < numero; i++)
        i = 0;
        while(i < numero)
        {
            scanf("%d", &vai);
            inserindo(Tabela, vai % chave, vai);
            
        }

        r = 0;
        while (r < chave)
        {
            imprimindoTUDO(Tabela[r].first, r);
            r++;
        }

        if (j + 1 < n)
        {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}