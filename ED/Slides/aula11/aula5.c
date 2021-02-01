#include <stdio.h>

typedef struct
{
    float x;
    float y;
    float z;
} Vetor;

Vetor somaVet(Vetor vet_r3[2])
{
    /////////////////////////////////////////////////////////
    Vetor soma;

    soma.x = vet_r3[0].x + vet_r3[1].x;

    soma.y = vet_r3[0].y + vet_r3[1].y;

    soma.z = vet_r3[0].z + vet_r3[1].z;

    return soma;
}

int main()
{
    Vetor vet_r3[2];
    int i;
    Vetor soma;
    

    for (i = 0; i < 2; i++)
    {

        printf("Digite o valor de X: ");

        scanf("%f", &vet_r3[i].x);

        printf("Digite o valor de Y: ");

        scanf("%f", &vet_r3[i].y);

        printf("Digite o valor de Z: ");

        scanf("%f", &vet_r3[i].z);
    }
    soma = somaVet(vet_r3);

    printf("A soma  X deu: %f \n", soma.x);
    printf("A soma  y deu: %f \n", soma.y);
    printf("A soma  z deu: %f \n", soma.z);

}