#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numeroMatricula;
    double IAA;
    char nome[10];
} Aluno;

int main() {
    Aluno aluno;

    printf("Digite o nome do aluno: ");
    fscanf(stdin, "%s", aluno.nome);
    printf("Digite o IAA: ");
    scanf("%lf", &aluno.IAA);
    printf("Digite o numero da matricula: ");
    scanf("%d", &aluno.numeroMatricula);

    FILE *fp = fopen("alunos.txt", "ab+");

    if (fp == NULL) {
        exit(1);
    }

    fwrite(&aluno, sizeof(Aluno), 1, fp);
    
    rewind(fp);

    while (fread(&aluno, sizeof(Aluno), 1, fp) == 1) {
        printf("Matricula: %d \nNome: %s\nIAA: %.2lf\n\n", aluno.numeroMatricula, aluno.nome, aluno.IAA);
        
    }

    fclose(fp);


    return 0;
}