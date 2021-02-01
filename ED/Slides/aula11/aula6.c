#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char nome[50];
    float nota[3];
}Alunos;

int main()
{

    Alunos alunos[5];
    int i, maiornota1_indice= 0, maiormediageral_indice=0, menormediageral_indice=0;
    float maiornota1 = 0, mediageral[5], maiormediageral = 0, menormediageral=11;

    for (i = 0; i < 5; i++)
    {

        // printf("\n\nDigite a matricula do %do Aluno:\n", i + 1);
        scanf("%d\n", &alunos[i].matricula);
        // printf("Nome do %d Aluno:\n", i + 1);
        scanf("%s", alunos[i].nome); //fgets
        // printf("Nota 1:\n");
        scanf("%f", &alunos[i].nota[0]);
        // printf("Nota 2:\n");
        scanf("%f", &alunos[i].nota[1]);
        // printf("Nota 3:\n");
        scanf("%f", &alunos[i].nota[2]);

        mediageral[i] = ((alunos[i].nota[0] + alunos[i].nota[1] + alunos[i].nota[2])/3);

        if (maiornota1 < alunos[i].nota[0])
        {

            maiornota1 = alunos[i].nota[0];

            maiornota1_indice = i;
        }

        if (mediageral[i] > maiormediageral)
        {
            maiormediageral = mediageral[i];
            maiormediageral_indice = i;
        }
        
        if (mediageral[i] < menormediageral)
        {
            menormediageral = mediageral[i];
            menormediageral_indice = i;
        }
    };

    printf("\nAluno com maior Nota 1: %s\n", alunos[maiornota1_indice].nome);
    printf("\nAluno com maior media: %s\n", alunos[maiormediageral_indice].nome);
    printf("\nAluno com menor media: %s\n", alunos[menormediageral_indice].nome);

    int j = 0;
    for (j = 0; j < 5; j++)
    {

        if (mediageral[j] <= 6)
        {

            printf("\nAluno %s REPROVADO\n", alunos[j].nome);
        }
        else
        {
            printf("Aluno %s APROVADO\n", alunos[j].nome);
        }
    }

    
    return 0;
};