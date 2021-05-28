#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

typedef struct aluno_s{
    int matricula;
    char nome[TAM];
    int IAA;   
} aluno_t;


size_t gravar_registro( FILE * pf, char * nome, int iaa, int mat ){
    aluno_t a;
    strcpy( a.nome, nome );
    a.matricula = mat;
    a.IAA = iaa;

    return fwrite( &a, sizeof(aluno_t), 1, pf );
}


void ler_registro( FILE * pf, int mat ){
    aluno_t a;
    while( fread( &a, sizeof(aluno_t), 1, pf ) ){
        if( a.matricula == mat ){   
            printf( "Matricula: %d\n", a.matricula );
            printf( "Nome : %s\n", a.nome );
            printf( "IAA : %d \n", a.IAA );
            printf( "\n" );

            break;
        }
    }
}


int main( int argc, char ** argv ){
    FILE * arq = NULL;

    /* Abre arquivo para gravacao em modo binario... */
    arq = fopen( "registro.bin", "wb");

    if( !arq ){
        fprintf( stderr, "Erro ao abrir arquivo para gravacao.\n");
        return 0;
    }

    /* Cadastra 5 alunos... */
    gravar_registro( arq, "Lady Gaga", 65, 12345678 );
    gravar_registro( arq, "Beyouce Crazy", 43, 13579009 );
    gravar_registro( arq, "Justin Bieber", 80, 12468001 );
    gravar_registro( arq, "Fred Mercury", 77, 10001234 );
    gravar_registro( arq, "Ariana Grande", 43, 15050789 );

    /* Fecha arquivo...*/
    fclose(arq);

    /* Abre arquivo para leitura em modo binario... */
    arq = fopen( "registro.bin", "rb");

    if( !arq ){
        fprintf( stderr, "Erro ao abrir arquivo para leitura.\n");
        return 0;
    }

    /* Faz a leitura dos alunos pelo codigo de matricula  */
    ler_registro( arq, 12345678 );
    ler_registro( arq, 13579009 );
    ler_registro( arq, 12468001 );
    ler_registro( arq, 10001234 );
    ler_registro( arq, 15050789 );

    /* Fecha arquivo...*/
    fclose(arq);
    printf("\tTERMINADO!!\n");

    /* Sucesso */
    return 0;
}