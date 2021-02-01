#include <stdio.h>

typedef struct
{
    double real;
    double imaginario;

} Complexo;

// falta tipo do retorno

Complexo criaComplexo(double real, double imaginario)
{
    Complexo complexo;

    complexo.real = real;
    complexo.imaginario = imaginario;

    return complexo;
}

Complexo somaComplexos(Complexo complexo1, Complexo complexo2)
{
    Complexo soma;

    soma.real = complexo1.real + complexo2.real;
    soma.imaginario = complexo1.imaginario + complexo2.imaginario;

    return soma;
}


int main() {
    double real, imaginario;
    Complexo complexo1, complexo2, soma;

    printf("Digite a parte real do primeiro numero complexo: ");
    scanf("%lf", &real);

    printf("Digite a parte imaginaria do primeiro numero complexo: ");
    scanf("%lf", &imaginario);

    complexo1 = criaComplexo(real, imaginario);

    printf("Digite a parte real do segundo numero complexo: ");
    scanf("%lf", &real);

    printf("Digite a parte imaginaria do segundo numero complexo: ");
    scanf("%lf", &imaginario);

    complexo2 = criaComplexo(real, imaginario);

    printf("Parte real do primeiro numero complexo: %lf\n", complexo1.real);
    printf("Parte imaginaria do primeiro numero complexo: %lf\n",
            complexo1.imaginario);

    printf("Parte real do segundo numero complexo: %lf\n", complexo2.real);
    printf("Parte imaginaria do segundo numero complexo: %lf\n",
            complexo2.imaginario);

    soma = somaComplexos(complexo1, complexo2);
    printf("Parte real da soma dos numeros complexos: %lf\n", soma.real);
    printf("Parte imaginaria da soma dos numeros complexos: %lf\n",
            soma.imaginario);

    return 0;
}
