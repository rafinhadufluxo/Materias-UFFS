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

int qtdElementos(Funcionario *cabeca) // quantos elementos a lista possui.
{
    int qtd = 0;
    while (cabeca != NULL)
    {
        cabeca = cabeca->proximo;
        qtd++;
    }
    return qtd;
}

void menorSalarioLista(Funcionario *primeiro)
{
    int menor = primeiro->salario;
    Funcionario *aux = primeiro;
    while (aux != NULL)
    {
        if (aux->salario < menor)
        {
            menor = aux->salario;
        }
        aux = aux->proximo;
    }
    printf("menor salario desta lista e: %d\n", menor);
}

void funcionarioVelho(struct funcionario *primeiro)
{

    int i,count, menor = 0;
    int maior_ano = 0;
    for (i = 0; i < 5; i++)
    {
        if (primeiro[i].nascimento.ano > menor)
        {
            maior_ano = primeiro[i].nascimento.ano;
            count = i;
        }
    }
    printf("Nome: %s\n", primeiro[count].nome);
    printf("Maior salario: %d\n", maior_ano);
}

int main()
{
    Funcionario *primeiro, *aux;
    int i, qtd = 0;
    int menorSal = 0;

    // primeiro = malloc(sizeof(Funcionario));
    // snprintf(primeiro->nome, sizeof(Funcionario), "%s", "Nome do primeiro");
    // primeiro->id = 1;
    // primeiro->salario = 240.75 * 5;
    // primeiro->nascimento.dia = 12;
    // primeiro->nascimento.mes = 12;
    // primeiro->nascimento.ano = 9090;
    // primeiro->proximo = NULL;

    for (i = 0; i < 5; i++)
    {
        aux = malloc(sizeof(Funcionario));
        snprintf(aux->nome, sizeof(Funcionario), "%s %d", "Fulaninho", i);
        aux->id = i + 1;
        aux->salario = 240.75 * i;
        aux->nascimento.dia = (12 + i) % 28;
        aux->nascimento.mes = (i % 12) + 1;
        aux->nascimento.ano = 2020 * i;
        aux->proximo = NULL;

        // encadeamento
        aux->proximo = primeiro;
        primeiro = aux;
    }

    imprimeLista(primeiro);
    qtd = qtdElementos(primeiro);

    printf("\nO numero de elementos da lista é %d\n", qtd);

    menorSalarioLista(primeiro);
    funcionarioVelho(primeiro);

    while (primeiro != NULL)
    {
        aux = primeiro;
        primeiro = primeiro->proximo;
        // printf("Liberando %s\n", aux->nome);
        free(aux);
    }

    return 0;
}