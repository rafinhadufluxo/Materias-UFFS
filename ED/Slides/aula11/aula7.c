#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nome[50];
    float nota;
} Alunos;

int main()
{

    Alunos alunos[3];
    int i, j, x, k;
    int reprovados[3];
    int aprovados[3];
    float mediaFinal[3];
    int cont_aprov = 0;
    int cont_rep = 0;

    for (i = 0; i < 3; i++)
    {

        // printf("Digite a matricula do %dº Aluno:\n", i );
        scanf("%d\n", &alunos[i].matricula);

        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        // printf("Nota final:");
        scanf("%f", &alunos[i].nota);

        if (alunos[i].nota <= 5)
        {
            reprovados[cont_rep++] = i;
        }
        else
        {
           aprovados[cont_aprov++] = i;
        }
    }

    for (j = 0; j < cont_aprov; j++)
    {
        printf("Aluno da %s APROVADO \n", alunos[aprovados[j]].nome);
    }

    for (k = 0; k < cont_rep; k++)
    {
        printf("Aluno da %s REPROVADO\n", alunos[reprovados[k]].nome);
    }
    return 0;
};