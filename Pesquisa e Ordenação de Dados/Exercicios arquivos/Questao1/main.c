#include <stdio.h>
#include <ctype.h>

/* Para compilar o programa, siga os passos seguinte:
* 1º Compile assim "gcc main.c", logo ira gerar um arquivo "a.out"
* 2º  para executar use este comando "./a.out < entrada.txt"
* 3º Pronto, ira parecer no terminal o resultado.
*/

int main(){
    
    FILE* ponteiro;
    char file[100] = { "entrada.txt" };
    char chave;

    ponteiro = fopen(file, "r");
    chave = fgetc(ponteiro);

    while (chave != EOF) {
        chave = toupper(chave);
        printf("%c", chave);
        chave = fgetc(ponteiro);
    }

    printf("\n");
    
    fclose(ponteiro);

    return 0;
}