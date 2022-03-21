/*
 * Tarefa de laboratorio 07 - Armazenando e imprimindo informacoes sobre nomes
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Rafaelle Arruda
 * Matricula: 1721101029
 *
 */


#include <stdio.h>
#include <string.h>

int main() {
    char student[50][40];
    int N;
    scanf("%d ",&N);
    
    for (int i = 0; i < N; i++) {
      
        fgets(student[i], sizeof(student[i]), stdin);
        student[i][strcspn(student[i], "\n")] = '\0';
    }

   
    
    int x;
    scanf("%d ",&x);

    for (int i = 0; i < x; i++) {
        int index;

        // scanf("%d ",&index);
        
        char name;

        scanf("%d %c", &index,&name);
        
        if (name == 'p') {
            printf("%c\n", student[index][0]);
        } else {
            for (int j = 0; j < 40; j++) {
                if (student[index][j] == ' ') {
                    printf("%c\n", student[index][j+1]);
                    break;
                }
            }
        }
    }

    return 0;
}