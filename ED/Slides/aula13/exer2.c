#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

struct funcionario
{
    int id;
    char nome[41];
    double salario;
    Data nascimento;
    struct funcionario *proximo;
};
typedef struct funcionario Funcionario;

void imprimeLista(Funcionario *lista)
{
    Funcionario *aux;
    if (lista == NULL)
    {
        printf("Lista vazia\n");
        return;
    }
    for (aux = lista; aux != NULL; aux = aux->proximo)
    {
        printf("Registro:\n\t id: %d, \n\t nome: %s, \n\t nasc: %d/%d/%d, \n\t salario: %lf\n\n", aux->id, aux->nome, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->salario);
    }
}

Funcionario *deletaElemento(Funcionario *lista, int key)
{
    Funcionario *aux, *anterior;
    for (aux = lista; aux != NULL; aux = aux->proximo)
    {
        if (aux->id == key)
        {
            if (aux == lista)
            {
                lista = lista->proximo;
                if (lista == NULL) //se isso acontecer é porq a lista ficou vazia, ela só tinha um elemento e esse foi excluido. Então retorn null;
                    return NULL;
            }
            else
            {
                printf("Exclui\n\n");
                anterior->proximo = aux->proximo;
            }
            free(aux);
            aux = anterior;
        }
        anterior = aux;
    }
    return lista;
}

/*Limpa toda a lista, da free em todos os endereços de memoria.*/
void limpaTodaLista(Funcionario *primeiro)
{
    Funcionario *aux;
    while (primeiro != NULL)
    {
        aux = primeiro;
        primeiro = primeiro->proximo;
        free(aux);
    }
}

int main()
{
    Funcionario *primeiro = NULL, *aux;
    int n, i;

    /*Lendo os valores*/
    printf("Digite o número de valores: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        aux = malloc(sizeof(Funcionario));
        printf("\nDigite o id: \n");
        scanf("%d%*c", &aux->id); //o %*c representa ler um caractere mas não gravar, só outra forma de eliminar o '\n', pois ele atrapalha o fgets

        printf("\nDigite o nome: ");
        fgets(aux->nome, sizeof(aux->nome), stdin);
        aux->nome[strcspn(aux->nome, "\n")] = '\0'; //Trocando o \n por \0;
        printf("\nDigite a data nascimento (formato dd/mm/yyyy): ");
        scanf("%d/%d/%d", &aux->nascimento.dia, &aux->nascimento.mes, &aux->nascimento.ano);
        printf("\nDigite o salario: ");
        scanf("%lf", &aux->salario);
        aux->proximo = NULL;

        if (primeiro == NULL)
        { //Ele é o primeiro
            primeiro = aux;
        }
        else
        { //faz o encadeamento
            aux->proximo = primeiro;
            primeiro = aux;
        }
    }
    /*Imprimindo a lista como a B pede*/
    imprimeLista(primeiro);

    printf("\nExcluindo elemento com id 2\n");
    primeiro = deletaElemento(primeiro, 2); //deletando o 2, poderia fazer um scanf para pedir o elemento a ser excluido.

    printf("\nImprimindo a lista após a exclusao: \n");
    /*Imprimindo a lista depois do delete*/
    imprimeLista(primeiro);

    /*Antes de acabar o programa podemos limpar nossa lista.*/
    limpaTodaLista(primeiro);

    printf("\nTerminamos!\n");

    return 0;
}