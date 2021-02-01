#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int extraiDia(Data *data) {
    return data->dia;
}

int comparaDatas(Data *data1, Data *data2) {
    if (data1->ano < data2->ano) {
        return -1;
    }
    if (data1->ano > data2->ano) {
        return 1;
    }
    /* Deste ponto em diante, sabemos que data1->ano == data2->ano */

    if (data1->mes < data2->mes) {
        return -1;
    }
    if (data1->mes > data2->mes) {
        return 1;
    }
    /* Deste ponto em diante, sabemos que data1->ano == data2->ano e
     * data1->mes == data2->mes */

    if (data1->dia < data2->dia) {
        return -1;
    }
    if (data1->dia > data2->dia) {
        return 1;
    }
    /* Neste ponto, sabemos que data1->ano == data2->ano,
     * data1->mes == data2->mes e data1->dia == data2->dia */
    return 0;
}

int main() {
    Data *data1, *data2;
    int dia;
    int ret;

    data1 = malloc(sizeof(Data));
    data2 = malloc(sizeof(Data));

    printf("Digite o dia da primeira data: ");
    scanf("%d", &data1->dia);

    printf("Digite o mes da primeira data: ");
    scanf("%d", &data1->mes);

    printf("Digite o ano da primeira data: ");
    scanf("%d", &data1->ano);

    printf("Digite o dia da segunda data: ");
    scanf("%d", &data2->dia);

    printf("Digite o mes da segunda data: ");
    scanf("%d", &data2->mes);

    printf("Digite o ano da segunda data: ");
    scanf("%d", &data2->ano);

    dia = extraiDia(data1);
    printf("Dia da primeira data: %d\n", dia);

    dia = extraiDia(data2);
    printf("Dia da segunda data: %d\n", dia);

    ret = comparaDatas(data1, data2);
    if (ret < 0) {
        printf("A primeira data é anterior à segunda data.\n");
    }
    else if (ret > 0) {
        printf("A primeira data é posterior à segunda data.\n");
    }
    else {
        printf("A primeira data e a segunda data são iguais.\n");
    }

    free(data1);
    free(data2);

    return 0;
}
