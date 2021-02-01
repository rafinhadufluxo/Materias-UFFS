#include <stdio.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

int extraiDia(Data data) {
    return data.dia;
}

int comparaDatas(Data data1, Data data2) {
    if (data1.ano < data2.ano) {
        return -1;
    }
    if (data1.ano > data2.ano) {
        return 1;
    }
    /* Daqui em diante, data1.ano == data2.ano */

    if (data1.mes < data2.mes) {
        return -1;
    }
    if (data1.mes > data2.mes) {
        return 1;
    }
    /* Daqui em diante, data1.ano == data2.ano e data1.mes == data2.mes */

    if (data1.dia < data2.dia) {
        return -1;
    }
    if (data1.dia > data2.dia) {
        return 1;
    }
    /* Neste ponto, data1.ano == data2.ano, data1.mes == data2.mes e
       data1.dia == data2.dia */
    return 0;
}

int main() {
    Data d1, d2;
    int dia;

    printf("Digite o dia: ");
    scanf("%d", &d1.dia);

    printf("Digite o mes: ");
    scanf("%d", &d1.mes);

    printf("Digite o ano: ");
    scanf("%d", &d1.ano);

    printf("Digite o dia: ");
    scanf("%d", &d2.dia);

    printf("Digite o mes: ");
    scanf("%d", &d2.mes);

    printf("Digite o ano: ");
    scanf("%d", &d2.ano);

    dia = extraiDia(d1);
    printf("Dia da data: %d\n", dia);

    int ret = comparaDatas(d1, d2);
    if (ret == -1) {
        printf("A primeira data é anterior à segunda data\n");
    }
    else if (ret == 1) {
        printf("A primeira data é posterior à segunda data\n");
    }
    else /* ret == 0 */ {
        printf("A primeira data é igual à segunda data\n");
    }

    return 0;
}