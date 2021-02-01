#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int id;
    char nome[41];
    double salario;
    Data *nascimento;
} Funcionario;

void imprimeData(Data data) {
    printf("Dia: %d\n", data.dia);
    printf("Mes: %d\n", data.mes);
    printf("Ano: %d\n", data.ano);
}

int main() {
    Funcionario funcionario;

    funcionario.nascimento = malloc(sizeof(Data));

    printf("Digite o dia: ");
    scanf("%d", &funcionario.nascimento->dia);

    printf("Digite o mes: ");
    scanf("%d", &funcionario.nascimento->mes);

    printf("Digite o ano: ");
    scanf("%d", &funcionario.nascimento->ano);

    imprimeData(*funcionario.nascimento);

    free(funcionario.nascimento);

    return 0;
}
