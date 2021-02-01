/*
 * Tarefa de laboratorio 06 - Greve
 *
 * GEX605 AB 2020/1
 *
 * Nome: Rafaelle larisa de Arruda
 * Matricula: 1721101029
 *
 */

#include <stdio.h>
#include <math.h>

int main() {
  int i,n,x, count=0, mave=0;
  char c;
  
  
  scanf("%d", &n);
  for (i = 1; i <= n; i++){
    scanf(" %c %d\n", &c, &x);
  

    if( c == 'G')
      count += x;

    else
      mave += x;   

  }

  if(mave < count){
    printf("NAO VAI TER CORTE, VAI TER LUTA!\n");
  
  }else{
   printf("A greve vai parar.\n");
  }

  return 0;
}
