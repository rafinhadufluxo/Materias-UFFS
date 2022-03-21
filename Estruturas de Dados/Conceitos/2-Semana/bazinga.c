/*
 * Tarefa de laboratorio 05 - Bazinga
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Rafaelle Arruda
 * Matricula: XXXX
 *
 * OBS: tive bastante diculdade nesse exercicio, porém que conseguir concluir 
 * graças as explicações do professor e de uma colega, consegui concluir tranquilamente
 *
 * 
 */

#include <stdio.h>

int main(){
    int i, n;
    char a1, b;
    scanf("%d\n", &n);

    for ( i = 1; i <= n; ++i){
        scanf("%c %c\n", &a1, &b);

        if((a1 == 't' && (b == 'a' || b =='l')) ||
            (a1 == 'l' && (b == 'a' || b == 's')) ||
            (a1 == 'a' && (b == 'e' || b == 's')) ||
            (a1 == 's' && (b == 'e' || b == 't')) ||
            (a1 == 'e' && (b == 'l' || b == 't'))

            ){
            printf("Caso #%d: Bazinga!\n", i);
        }
        else if (a1 == b){
            printf("Caso #%d: De novo!\n", i);
        }
        
        else{
    
            printf("Caso #%d: Raj trapaceou!\n", i);
        }
    }      
    return 0;
}
