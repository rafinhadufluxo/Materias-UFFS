/*
 * Tarefa de laboratorio 04 - Boas-vindas com "Bom dia", "Boa tarde" ou "Boa
 *                            noite"
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Rafa
 * Matricula: 1721101029
 *
 * Data:      30/09/2020
 *
 * Descricao: Este programa recebe como entrada uma hora e imprime uma
 *            mensagem de boas-vindas com "Bom dia", "Boa tarde" ou "Boa
 *            noite", dependendo da hora recebida.
 *
 * Entrada:   Uma hora (sem os minutos, como um numero entre 0 e 23).
 *
 * Saida:     Mensagem de boas-vindas com "Bom dia", "Boa tarde" ou "Boa
 *            noite", dependendo da hora recebida.
 *
 */


#include <stdio.h>
#include <math.h>

int main(){
    int x;
    scanf("%d", &x);

    if( x <= 11 ){
        printf("Bom dia, bem-vindo(a) ao curso de Estruturas de Dados!\n");
    }
    else if (x <= 12 || x <= 18){
        printf("Boa tarde, bem-vindo(a) ao curso de Estruturas de Dados!\n");

    }
    else{
        printf("Boa noite, bem-vindo(a) ao curso de Estruturas de Dados!\n");
    }

    return 0;
   

}