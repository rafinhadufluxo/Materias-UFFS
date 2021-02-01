#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_NOME 40

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct fucionario {
    int id;
    char nome[TAM_NOME+1];
    double salario;
    Data nascimento;
    struct funcionario *proximo;
} Funcionario;

typedef struct {
    Funcionario *head;
    Funcionario *tail;
    int qtdFuncionario;
} Lista;

int comparaListas(Funcionario *lista1, Funcionario *lista2) {
    Funcionario *aux1 = lista1, *aux2 = lista2;
    while (aux1 != NULL && aux2 != NULL) {
        if (aux1->id != aux2->id)
            return 0;
        else if (strcmp(aux1->nome, aux2->nome)) 
            return 0;
        else if (aux1->salario != aux2->salario)
            return 0;
        else if (aux1->nascimento.ano != aux2->nascimento.dia)
            return 0;
        else if (aux1->nascimento.mes != aux2->nascimento.mes)
            return 0;
        else if (aux1->nascimento.dia != aux2->nascimento.dia)
            return 0;
        else if (aux1->proximo != aux2->proximo)
            return 0;
        else {
            aux1 = aux1->proximo;
            aux2 = aux2->proximo;
        }
    }
    if (aux1 != NULL || aux2 != NULL)
        return 0;
    return 1;
}

Funcionario *funcionarioMaisVelho(Funcionario *head) {
    Funcionario *maisVelho = head;
    Funcionario *aux = head;
    int dia = aux->nascimento.dia, mes = aux->nascimento.mes, ano = aux->nascimento.ano;
    
    for (; aux != NULL; aux = aux->proximo) {
        if (aux->nascimento.ano < ano) {
            maisVelho = aux;
            ano = aux->nascimento.ano;
            mes = aux->nascimento.mes;
            dia = aux->nascimento.dia;
        } else if (aux->nascimento.ano > ano)
                continue;
        else {
            if (aux->nascimento.mes < mes) {
                maisVelho = aux;
                ano = aux->nascimento.ano;
                mes = aux->nascimento.mes;
                dia = aux->nascimento.dia;
            } else if (aux->nascimento.ano > mes)
                continue;
            else {
                if (aux->nascimento.dia < dia) {
                    maisVelho = aux;
                    ano = aux->nascimento.ano;
                    mes = aux->nascimento.mes;
                    dia = aux->nascimento.dia;
                } else
                    continue;
            }
        
        }
    }
    return maisVelho;
}

double menorSalario(Funcionario *head) {
    Funcionario *aux = head;
    double menorSalario = +INFINITY;

    while (aux != NULL) {
        if (aux->salario < menorSalario) {
            menorSalario = aux->salario;
        }
        aux = aux->proximo;
    }
    return menorSalario;
}

int quantidadeFuncionarios(Funcionario *head) {
    int contador = 0;
    Funcionario *aux = head;
    while (aux != NULL) {
        contador += 1;
        aux = aux->proximo;
    }
    return contador;
}

int main() {
    int N;
    Funcionario *aux;
    Lista lista;
    lista.head = NULL;
    lista.tail = NULL;
    lista.qtdFuncionario = 0;
    
    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        aux = malloc(sizeof(Funcionario));
        scanf("%d\n", &aux->id);
        fgets(aux->nome, sizeof(aux->nome), stdin);
        aux->nome[strcspn(aux->nome, "\n")] = '\0';
        scanf("%d", &aux->nascimento.dia);
        scanf("%d", &aux->nascimento.mes);
        scanf("%d", &aux->nascimento.ano);
        scanf("%lf", &aux->salario);
        aux->proximo = NULL;
        
        if (lista.head == NULL) {
            lista.head = aux;
            lista.tail = aux;
        } else {
            lista.tail->proximo = aux;
            lista.tail = aux;
        }
        lista.qtdFuncionario += 1;
        
    }

    printf("\nTodos os funcionarios\n");
    aux = lista.head;
    while (aux != NULL) {
        printf("%s\n", aux->nome);
        aux = aux->proximo;
    }

    printf("Menor salario: %.2lf\n", menorSalario(lista.head));
    
    printf("Funcionario mais velho: %s\n", funcionarioMaisVelho(lista.head)->nome);

    printf("Quantidade de funcionarios: %d\n", lista.qtdFuncionario);

    free(lista.head);
    free(lista.tail);

    return 0;

}       