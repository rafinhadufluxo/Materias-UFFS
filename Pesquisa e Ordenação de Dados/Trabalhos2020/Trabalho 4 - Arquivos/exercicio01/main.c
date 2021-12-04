#include <stdio.h>
#include <ctype.h>

int main() {

    char c;
    FILE *fp1 = fopen("letras_minusculas.txt", "r");
    FILE *fp2 = fopen("letras_maiusculas.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        exit(1);
    }

    while ((c = fgetc(fp1)) != EOF) {
        fputc(toupper(c), fp2);
    }

    fclose(fp1);
    fclose(fp2);




    return 0;
}