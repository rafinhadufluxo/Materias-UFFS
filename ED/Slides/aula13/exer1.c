#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct funcionario
{
    int id;
    char nome[41];
    double salario;
    Data nascimento;
    struct funcionario *proximo;
} Funcionario;

void imprimeLista(Funcionario *primeiro)
{
    Funcionario *aux;

    for (aux = primeiro; aux != NULL; aux = aux->proximo)
    {
        printf("REGISTRO  ID: %d \n nome:%s\n nascimento: %d/%d/%d\n salario:%lf\n",
               aux->id, aux->nome, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->salario);
    }
}

int main()
{
    Funcionario *primeiro, *aux;
    int i;

    primeiro = malloc(sizeof(Funcionario));
    snprintf(primeiro->nome, sizeof(Funcionario), "%s", "Nome do primeiro");
    primeiro->id = 1;
    primeiro->salario = 240.75;
    primeiro->nascimento.dia = 12;
    primeiro->nascimento.dia = 12;
    primeiro->nascimento.dia = 2020;
    primeiro->proximo = NULL;

    for (i = 1; i < 5; i++)
    {
        aux = malloc(sizeof(Funcionario));
        snprintf(aux->nome, sizeof(Funcionario), "%s %d", "Fulaninho", i);
        aux->id = i + 1;
        aux->salario = 240.75 * i;
        aux->nascimento.dia = (12 + i) % 28;
        aux->nascimento.mes = (i % 12) + 1;
        aux->nascimento.ano = 2020;
        aux->proximo = NULL;

        // encadeamento
        aux->proximo = primeiro;
        primeiro = aux;
    }
    imprimeLista(primeiro);
    
    while (primeiro != NULL)
    {
        aux = primeiro;
        primeiro = primeiro ->proximo;
        printf("Liberando %s\n", aux->nome);
        free(aux);
    }
    
    return 0;
}